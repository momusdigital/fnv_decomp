
// src/gamebryo2.2/corelibs/niparticle/nipsysmeshupdatemodifier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysmeshupdatemodifier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202530;

// @fnv 0x00c21720
void* __cdecl FUN_00c21720()
{
    return &g_01202530;
}

class CloningProcess;
class NiPSysModifier
{
  public:
    virtual void ProcessClone(class CloningProcess&);
};
class NiAVObject
{
  public:
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
    virtual void ProcessClone(class CloningProcess&);
};
class NiPSysMeshUpdateModifier : public NiPSysModifier
{
  public:
    char _pad[0x18];
    class NiAVObject** m_ppkMeshes;
    unsigned short m_usPad;
    unsigned short m_usNumMeshes;
    void FUN_00c20f30(class CloningProcess&);
};
// Calls the base modifier's ProcessClone, then clones each non-null mesh in m_ppkMeshes up to m_usNumMeshes.
// @fnv 0x00c20f30
void NiPSysMeshUpdateModifier::FUN_00c20f30(class CloningProcess& kCloning)
{
    NiPSysModifier::ProcessClone(kCloning);
    unsigned int ui;
    NiAVObject* pkMesh;
    for (ui = 0; ui < m_usNumMeshes; ui++)
    {
        pkMesh = m_ppkMeshes[ui];
        if (pkMesh)
            pkMesh->ProcessClone(kCloning);
    }
}

namespace fnv_00c20f80 {
struct NiStream
{
    int _d;
};
struct NiAVObject
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
struct Holder31670
{
    bool FUN_00c31670(NiStream&);
};
struct NiPSysMeshUpdateModifier
{
    char _pad[0x1c];
    NiAVObject** m_ppkMeshes;
    char _pad2[2];
    unsigned short m_usElementCount;
    bool FUN_00c20f80(NiStream&);
};
// @fnv 0x00c20f80
bool NiPSysMeshUpdateModifier::FUN_00c20f80(NiStream& kStream)
{
    if (!((Holder31670*)this)->FUN_00c31670(kStream))
        return false;
    unsigned int ui;
    NiAVObject* pkMesh;
    for (ui = 0; ui < m_usElementCount; ui++)
    {
        pkMesh = m_ppkMeshes[ui];
        if (pkMesh)
            pkMesh->RegisterStreamables(kStream);
    }
    return true;
}
}  // namespace fnv_00c20f80

extern int DAT_0101fbcc;
void __cdecl FUN_004b0220(void*);
struct Holder31750
{
    void FUN_00c31750();
};
void __cdecl _delete(void*, unsigned int);
struct Unk21730
{
    char _0[0x18];
    void* a;
    void* b;
    char _1[8];
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x00c21730
void* Unk21730::DestroyIfFlagged(unsigned int auiFlags)
{
    void* tmp = b;
    a = &DAT_0101fbcc;
    FUN_004b0220(tmp);
    ((Holder31750*)this)->FUN_00c31750();
    if (auiFlags & 1)
        _delete(this, 0x28);
    return this;
}

namespace fnv_00c21840 {
char* __cdecl _FUN_00a7d330(void*);
struct StrArr
{
    char _pad0[8];
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short _pad1;
    unsigned short m_usGrow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct BaseMod
{
    void FUN_00c319e0(StrArr*);
};
struct NiPSysMeshUpdateModifier : BaseMod
{
    void AppendString(StrArr*);
};
// Calls the base handler, then appends the string returned by _FUN_00a7d330(g_01202530) to pkStrings, growing it if full.
// @fnv 0x00c21840
void NiPSysMeshUpdateModifier::AppendString(StrArr* pkStrings)
{
    FUN_00c319e0(pkStrings);
    char* pcStr = _FUN_00a7d330(g_01202530);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMax)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrow);
    pkStrings->SetAt(uiSize, pcStr);
}
}  // namespace fnv_00c21840

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct NiRefObject
{
    virtual void v00();
    virtual void DeleteThis();
    volatile long refCount;
};
struct NiPointer
{
    NiRefObject* ptr;
    explicit NiPointer(NiRefObject* p) : ptr(p)
    {
        if (p)
        {
            InterlockedIncrement(&p->refCount);
            if (!InterlockedDecrement(&p->refCount))
                p->DeleteThis();
        }
    }
};
struct RefArray
{
    void* unk00;
    NiRefObject** entries;
    unsigned short capacity;
    unsigned short size;
    unsigned short count;
    NiPointer PopBack();
};

// Removes and returns the last entry of the array, decrementing the count and releasing the slot's reference.
// @fnv 0x00c20fd0
NiPointer RefArray::PopBack()
{
    if (!size)
        return NiPointer(0);
    NiRefObject* object = entries[--size];
    if (object)
        InterlockedIncrement(&object->refCount);
    NiRefObject** slot = entries + size;
    NiRefObject* old = *slot;
    if (old)
    {
        if (!InterlockedDecrement(&old->refCount))
            old->DeleteThis();
        *slot = 0;
    }
    const bool& x = object != 0;
    if (x)
        --count;
    return NiPointer(object);
}

class FUN_00c212b0_ref
{
  public:
    virtual void v00();
    virtual void v01();
    long m_iRefCount;
};

class FUN_00c212b0_src
{
  public:
    void* FUN_00a5d680();
};

class FUN_00c212b0_item
{
  public:
    char unk00[8];
    unsigned short m_usElementCount;
    void FUN_004b0310(unsigned int, void**);
};

class FUN_00c212b0_cls
{
  public:
    char unk00[0x8c];
    FUN_00c212b0_item** m_ppItems;
    char unk90[2];
    unsigned short m_usNumMeshes;
    void FUN_00c212b0(unsigned int a1, FUN_00c212b0_src* a2);
};

// @fnv 0x00c212b0
void FUN_00c212b0_cls::FUN_00c212b0(unsigned int uiIndex, FUN_00c212b0_src* pSource)
{
    if (uiIndex < m_usNumMeshes && m_ppItems[uiIndex] != 0)
    {
        FUN_00c212b0_item* item = m_ppItems[uiIndex];
        unsigned int i = 0;
        if (i < item->m_usElementCount)
        {
            do
            {
                FUN_00c212b0_ref* p = (FUN_00c212b0_ref*)pSource->FUN_00a5d680();
                void* out = p;
                if (p != 0)
                {
                    InterlockedIncrement(&p->m_iRefCount);
                }
                item->FUN_004b0310(i, &out);
                if (p != 0)
                {
                    if (InterlockedDecrement(&p->m_iRefCount) == 0)
                    {
                        p->v01();
                    }
                }
                ++i;
            } while (i < item->m_usElementCount);
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
struct CloneHandle;
struct MeshObject
{
    virtual void OnBeginDestroy();
    virtual void Destroy();
    volatile long refCount;
    CloneHandle __thiscall PopBack() throw();
};
struct CloneHandle
{
    MeshObject* pointer;
    ~CloneHandle() throw()
    {
        if (pointer)
        {
            MeshObject* oldObject = pointer;
            if (InterlockedDecrement(&oldObject->refCount) == 0)
            {
                oldObject->Destroy();
            }
        }
    }
    void Clear()
    {
        if (pointer)
        {
            MeshObject* oldObject = pointer;
            if (InterlockedDecrement(&oldObject->refCount) == 0)
            {
                oldObject->Destroy();
            }
            pointer = 0;
        }
    }
    CloneHandle& __thiscall FUN_006e5cc0(const CloneHandle& other) throw();
};
struct MeshLookup
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
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    MeshObject** meshes;
    unsigned short unk90;
    unsigned short meshCount;
    void __thiscall GetMeshHandle(unsigned int index, CloneHandle* result);
};
// If index is within meshCount and meshes[index] is non-null, assigns a clone handle of that mesh to result; otherwise clears result.
// @fnv 0x00c21340
void MeshLookup::GetMeshHandle(unsigned int index, CloneHandle* result)
{
    if (index >= meshCount)
    {
        result->Clear();
        return;
    }
    if (meshes[index] == 0)
    {
        result->Clear();
        return;
    }
    result->FUN_006e5cc0(meshes[index]->PopBack());
}

class C217F0Object
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem);

    virtual ~C217F0Object();
};

class C217F0ModifierBase : public C217F0Object
{
  public:
    C217F0ModifierBase() throw();
    virtual ~C217F0ModifierBase();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

template <class T> class C217F0Array
{
  public:
    C217F0Array(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = new T[m_usMaxSize];
        else
            m_pBase = 0;
    }
    virtual ~C217F0Array();

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

template <class T> class C217F0PrimitiveArray : public C217F0Array<T>
{
  public:
    C217F0PrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) throw()
        : C217F0Array<T>(uiMaxSize, uiGrowBy)
    {}
    virtual ~C217F0PrimitiveArray();
};

class C217F0Element;

class C217F0Modifier : public C217F0ModifierBase
{
  public:
    C217F0Modifier() throw()
    {}
    virtual ~C217F0Modifier();

    static C217F0Object* CreateModifier();

    C217F0PrimitiveArray<C217F0Element*> m_kElements;
};

// Allocates and returns a new C217F0Modifier object.
// @fnv 0x00c217f0
C217F0Object* C217F0Modifier::CreateModifier()
{
    return new C217F0Modifier;
}

class BC21890CloningProcess;

class BC21890ChildArray
{
  public:
    __forceinline BC21890ChildArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
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

    static void** Allocate(unsigned int ItemUpdateArray) throw();
    virtual ~BC21890ChildArray();

    void** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class BC21890ObjectArray : public BC21890ChildArray
{
  public:
    __forceinline BC21890ObjectArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : BC21890ChildArray(uiMaxSize, uiGrowBy)
    {}
    virtual ~BC21890ObjectArray();
};

class BC21890AVObject
{
  public:
    static void* operator new(unsigned int uiSize);

    BC21890AVObject() throw();
    virtual ~BC21890AVObject();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class BC21890Node : public BC21890AVObject
{
  public:
    __forceinline BC21890Node()
    {}
    virtual ~BC21890Node();

    void CopyMemberData(BC21890Node* pkDest, BC21890CloningProcess& kCloning);
    BC21890Node* CreateClone(BC21890CloningProcess& kCloning);

    BC21890ObjectArray m_kChildList;
};

// @fnv 0x00c21890
BC21890Node* BC21890Node::CreateClone(BC21890CloningProcess& kCloning)
{
    BC21890Node* pkClone = new BC21890Node;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

__declspec(dllimport) __declspec(nothrow) long __stdcall InterlockedIncrement(volatile long* p);
__declspec(dllimport) __declspec(nothrow) long __stdcall InterlockedDecrement(volatile long* p);

class MyRefObject
{
  public:
    virtual ~MyRefObject() throw();
    __declspec(nothrow) virtual void DeleteThis() throw();
    volatile long m_uiRefCount;
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

template <class T> class NiPtr
{
  public:
    NiPtr(T* p = 0) throw() : m_pObject(p)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPtr(const NiPtr& o) throw() : m_pObject(o.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPtr() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPtr& operator=(const NiPtr& o) throw()
    {
        if (m_pObject != o.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = o.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    NiPtr& operator=(T* p) throw()
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    bool operator==(const NiPtr& o) const throw()
    {
        return m_pObject == o.m_pObject;
    }
    bool operator!=(const NiPtr& o) const throw()
    {
        return m_pObject != o.m_pObject;
    }
    T* m_pObject;
};

class MyMeshObj : public MyRefObject
{
};
typedef NiPtr<MyMeshObj> MyMeshObjPtr;

class MyMeshPtrArray
{
  public:
    virtual ~MyMeshPtrArray() throw();
    MyMeshObjPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned int GetSize() const throw()
    {
        return m_usSize;
    }
    const MyMeshObjPtr& GetAt(unsigned int i) const throw()
    {
        return m_pBase[i];
    }
    __declspec(nothrow) void SetAt(unsigned int i, const MyMeshObjPtr& e) throw()
    {
        static const MyMeshObjPtr nil;
        if (i >= m_usSize)
        {
            m_usSize = (unsigned short)(i + 1);
            if (e != nil)
                ++m_usESize;
        }
        else if (e != nil)
        {
            if (m_pBase[i] == nil)
                ++m_usESize;
        }
        else
        {
            if (m_pBase[i] != nil)
                --m_usESize;
        }
        m_pBase[i] = e;
    }
    __declspec(nothrow) void SetSize(unsigned int n) throw();
    unsigned int SetAtGrow(unsigned int i, const MyMeshObjPtr& e) throw()
    {
        if (i >= m_usMaxSize)
            SetSize(i + m_usGrowBy);
        SetAt(i, e);
        return i;
    }
};

class MyMeshUpdateMod
{
  public:
    virtual ~MyMeshUpdateMod() throw();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    MyMeshPtrArray m_kSceneObjects;
    void SetMeshAt(unsigned int uiIndex, MyMeshObj* pkMesh, MyMeshObjPtr& spOld);
};

// Stores pkMesh at uiIndex in the mesh pointer array, returning the previous entry in spOld (or null when growing).
// @fnv 0x00c215d0
void MyMeshUpdateMod::SetMeshAt(unsigned int uiIndex, MyMeshObj* pkMesh, MyMeshObjPtr& spOld)
{
    if (uiIndex < m_kSceneObjects.GetSize())
    {
        MyMeshObjPtr spPrev = m_kSceneObjects.GetAt(uiIndex);
        m_kSceneObjects.SetAt(uiIndex, pkMesh);
        spOld = spPrev;
    }
    else
    {
        m_kSceneObjects.SetAtGrow(uiIndex, pkMesh);
        spOld = 0;
    }
}

struct BinaryStream
{
    void* unk00;
    unsigned int offset;
    void* unk08;
    unsigned int(__cdecl* write)(BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    __forceinline unsigned int WriteData(const void* data, unsigned int size)
    {
        unsigned int elementSize = 4;
        return write(this, data, size, &elementSize, 1);
    }
};
struct StreamSlot
{
    BinaryStream* stream;
};
class NiStream
{
  public:
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
    virtual void RegisterObject(NiAVObject*);
    BinaryStream* GetBinaryStream()
    {
        return reinterpret_cast<StreamSlot*>(reinterpret_cast<unsigned char*>(this) + 0x250)->stream;
    }
};
class MeshUpdateStreamWriter : public NiPSysMeshUpdateModifier
{
  public:
    void FUN_00c31950(NiStream*);
    void WriteMeshUpdate(NiStream*);
};
// Writes the mesh count to the stream, then registers each mesh object with the stream.
// @fnv 0x00c211c0
void MeshUpdateStreamWriter::WriteMeshUpdate(NiStream* stream)
{
    FUN_00c31950(stream);
    unsigned int meshCount = m_usNumMeshes;
    BinaryStream* binary = stream->GetBinaryStream();
    binary->offset += binary->WriteData(&meshCount, 4);
    for (unsigned int i = 0; i < meshCount; ++i)
        stream->RegisterObject(m_ppkMeshes[i]);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct ReferenceSource
{
    unsigned int FUN_00a63460();
    NiRefObject* FUN_00a63430();
};
struct ReferenceArray
{
    void FUN_0060bef0(unsigned int count);
    void FUN_004b0310(unsigned int index, NiRefObject** pointer);
};
struct ReferenceContainer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ReferenceArray array;
    void FUN_00c31650(ReferenceSource* source);
    void CopyReferencesFromSource(ReferenceSource* source);
};
// Resizes the array to the source's count, then copies each referenced object into the array while adjusting its reference count.
// @fnv 0x00c214c0
void ReferenceContainer::CopyReferencesFromSource(ReferenceSource* source)
{
    FUN_00c31650(source);
    unsigned int count = source->FUN_00a63460();
    ReferenceArray* array = &this->array;
    array->FUN_0060bef0(count);
    for (unsigned int index = 0; index < count; ++index)
    {
        NiRefObject* object = source->FUN_00a63430();
        NiRefObject* handle = object;
        if (object != 0)
            InterlockedIncrement(&object->refCount);
        array->FUN_004b0310(index, &handle);
        if (object != 0 && InterlockedDecrement(&object->refCount) == 0)
            object->DeleteThis();
    }
}

class NiObjectC212
{
  public:
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
    virtual bool IsEqual(NiObjectC212* pkObject);
};

class NiPSysModifierC212 : public NiObjectC212
{
  public:
    int unk04, unk08, unk0C, unk10, unk14;
    bool FUN_00c31830(NiObjectC212* pkObject);
};

template <class T> class NiTPrimitiveArrayC212
{
  public:
    virtual ~NiTPrimitiveArrayC212();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    unsigned int GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
};

class NiPSysMeshUpdateModifierC212 : public NiPSysModifierC212
{
  public:
    NiTPrimitiveArrayC212<NiObjectC212*> m_kSceneObjects;

    bool FUN_00c21230(NiObjectC212* pkObject);
};

// Compares m_kSceneObjects with pkObject's m_kSceneObjects, returning true only if both arrays have the same size and each element is equal.
// @fnv 0x00c21230
bool NiPSysMeshUpdateModifierC212::FUN_00c21230(NiObjectC212* pkObject)
{
    if (!FUN_00c31830(pkObject))
    {
        return false;
    }

    NiPSysMeshUpdateModifierC212* pkDest = (NiPSysMeshUpdateModifierC212*)pkObject;

    if (m_kSceneObjects.GetSize() != pkDest->m_kSceneObjects.GetSize())
    {
        return false;
    }

    for (unsigned int ui = 0; ui < m_kSceneObjects.GetSize(); ui++)
    {
        NiObjectC212* pkMesh = m_kSceneObjects.GetAt(ui);
        NiObjectC212* pkDestMesh = (ui < pkDest->m_kSceneObjects.GetSize()) ? pkDest->m_kSceneObjects.GetAt(ui) : 0;
        if ((pkMesh && !pkDestMesh) || (!pkMesh && pkDestMesh) ||
            (pkMesh && pkDestMesh && !pkMesh->IsEqual(pkDestMesh)))
        {
            return false;
        }
    }

    return true;
}

#include <math.h>
struct MeshNiPoint3
{
    float x;
    float y;
    float z;
};
struct MeshNiMatrix3
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    void MakeAxisAngleRotation(float fAngleDifference, float x, float y, float z);
};
struct MeshUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    bool byte06;
    bool bUpdateGeomorphs;
    bool bUpdateShadowScene;
};
class MeshAVObject
{
  public:
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
    virtual void UpdateDownwardPass(MeshUpdateData& kData, unsigned int uiFlags);
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
    MeshNiMatrix3 m_kRotate;
    MeshNiPoint3 m_kTranslate;
    float m_fScale;
};
struct MeshParticleInfo
{
    int unk00;
    int unk04;
    int unk08;
    float m_fXValue;
    int unk10;
    int unk14;
    int unk18;
};
struct MeshSystem
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
    MeshAVObject** m_ppkMeshes;
};
struct MeshPSysData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    MeshNiPoint3* m_pkVertex;
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
    unsigned short unk52;
    float* m_pfSizes;
    int unk58;
    float* m_pfRotationAngles;
    MeshNiPoint3* m_pkRotationAxes;
    int unk64;
    int unk68;
    int unk6C;
    MeshParticleInfo* m_pkParticleInfo;
    int unk74;
    int unk78;
    MeshSystem* m_pkSystem;
};

// For each active vertex, copies position and scale to its mesh, optionally sets rotation, then calls UpdateDownwardPass.
// @fnv 0x00c21080
void __stdcall FUN_00c21080(float fTime, MeshPSysData* pkData)
{
    float* pfRotationAngles = pkData->m_pfRotationAngles;
    MeshNiPoint3* pkRotationAxes = pkData->m_pkRotationAxes;
    for (unsigned short i = 0; i < pkData->m_usActiveVertices; i++)
    {
        MeshParticleInfo* pkInfo = &pkData->m_pkParticleInfo[i];
        MeshAVObject* pkMesh = pkData->m_pkSystem->m_ppkMeshes[i];
        pkMesh->m_kTranslate = pkData->m_pkVertex[i];
        if (pfRotationAngles && pkRotationAxes)
        {
            MeshNiMatrix3 kRot;
            kRot.MakeAxisAngleRotation(pfRotationAngles[i], pkRotationAxes[i].x, pkRotationAxes[i].y,
                                       pkRotationAxes[i].z);
            pkMesh->m_kRotate = kRot;
        }
        float fSize = pkData->m_pfSizes[i];
        pkMesh->m_fScale = (float)fabs(fSize * pkData->m_pfRadii[i]);
        MeshUpdateData kUpdate;
        kUpdate.fTime = pkInfo->m_fXValue;
        kUpdate.m_bUpdateEnabled = true;
        kUpdate.bIsMultiThreaded = false;
        kUpdate.byte06 = false;
        kUpdate.bUpdateGeomorphs = false;
        kUpdate.bUpdateShadowScene = false;
        pkMesh->UpdateDownwardPass(kUpdate, 0);
    }
}

extern int(__stdcall* DAT_00fdf1c0)(void*);
extern int(__stdcall* DAT_00fdf1c4)(void*);

class Mesh_c21
{
  public:
    virtual void w00();
    virtual void Destroy();
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void SetTarget(void* pkTarget);
    volatile long m_lRefCount;
    int m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    unsigned int m_uiValue1;
};

class Src_c21
{
  public:
    Mesh_c21* FUN_00a5d680();
};

class Sink_c21
{
  public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s0a();
    virtual void s0b();
    virtual void s0c();
    virtual void s0d();
    virtual void s0e();
    virtual void s0f();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s1a();
    virtual void s1b();
    virtual void s1c();
    virtual void s1d();
    virtual void s1e();
    virtual void s1f();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s2a();
    virtual void s2b();
    virtual void s2c();
    virtual void s2d();
    virtual void s2e();
    virtual void s2f();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s3a();
    virtual void s3b();
    virtual void s3c();
    virtual void s3d();
    virtual void Attach(unsigned int uiIndex, Mesh_c21* pkMesh);
};

struct Entry_c21
{
    int m_00, m_04, m_08, m_0c, m_10, m_14;
    unsigned short m_usIndex;
    unsigned short m_1a;
};

void __cdecl StartControllersRecursive(Mesh_c21* pkMesh, float fTime);

struct Lk2_c21
{
    __declspec(noalias) void GetMeshHandle(unsigned int index, CloneHandle* result);
};
class FUN_00c21400_cls
{
  public:
    int m_00, m_04, m_08, m_0c;
    char* m_10;
    int m_14, m_18;
    Src_c21** m_1c;
    unsigned short m_20;
    unsigned short m_usElementCount;
    void AttachMesh(MeshLookup* pkLookup, unsigned short usIndex);
};

// Looks up or clones a mesh by usIndex, sets its m_uiValue1 flag, starts controllers, attaches it to the sink, and releases the reference.
// @fnv 0x00c21400
void FUN_00c21400_cls::AttachMesh(MeshLookup* pkLookup, unsigned short usIndex)
{
    unsigned short usMesh = ((Entry_c21*)pkLookup->unk70)[usIndex].m_usIndex;
    if (usMesh >= m_usElementCount)
        usMesh = m_usElementCount - 1;
    Mesh_c21* pkOut = 0;
    ((Lk2_c21*)pkLookup)->GetMeshHandle(usMesh, (CloneHandle*)&pkOut);
    if (!pkOut)
    {
        Mesh_c21* pkClone = m_1c[usMesh]->FUN_00a5d680();
        if (pkClone)
        {
            pkOut = pkClone;
            DAT_00fdf1c0((void*)&pkClone->m_lRefCount);
        }
    }
    Mesh_c21* pkMesh = pkOut;
    pkMesh->m_uiValue1 |= 1;
    StartControllersRecursive(pkMesh, 0.0f);
    ((Sink_c21*)pkLookup->unk7c)->Attach(usIndex, pkMesh);
    pkMesh->SetTarget(m_10 + 0x9c);
    if (DAT_00fdf1c4((void*)&pkMesh->m_lRefCount) == 0)
        pkMesh->Destroy();
}

extern "C" void _ReadWriteBarrier();
class NiCloningProcess_c217;
struct S_c21770_Slot
{
    MyMeshObj* m_pObject;
};
class S_c21770_Obj : public MyMeshObj
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
    virtual MyMeshObj* MakeClone(NiCloningProcess_c217& kCloning) throw();
};
struct OldSlot
{
    MyMeshObj* m_pObject;
    OldSlot() : m_pObject(0)
    {}
    ~OldSlot()
    {
        MyMeshObj* p = *(MyMeshObj* volatile*)&m_pObject;
        if (p)
        {
            if (InterlockedDecrement(&p->m_uiRefCount) == 0)
                p->DeleteThis();
        }
    }
};
class S_c21770_Mod
{
  public:
    virtual ~S_c21770_Mod() throw();
    int unk04, unk08, unk0C, unk10, unk14;
    MyMeshPtrArray m_kSceneObjects;
    void FUN_00c31780(S_c21770_Mod* pkDest, NiCloningProcess_c217& kCloning) throw();
    void SetMeshAt(unsigned int uiIndex, MyMeshObj* pkMesh, OldSlot& spOld) throw();
    void CloneInto(S_c21770_Mod* pkDest, NiCloningProcess_c217& kCloning);
};
// Calls FUN_00c31780 on pkDest, then clones each non-null entry of m_kSceneObjects via MakeClone and stores it in pkDest with SetMeshAt.
// @fnv 0x00c21770
void S_c21770_Mod::CloneInto(S_c21770_Mod* pkDest, NiCloningProcess_c217& kCloning)
{
    FUN_00c31780(pkDest, kCloning);
    for (unsigned int ui = 0; ui < m_kSceneObjects.GetSize(); ui++)
    {
        MyMeshObj* pkMesh = m_kSceneObjects.GetAt(ui).m_pObject;
        if (pkMesh)
        {
            MyMeshObj* pkClone = ((S_c21770_Obj*)pkMesh)->MakeClone(kCloning);
            OldSlot spOld;
            (*(S_c21770_Mod* volatile*)&pkDest)->SetMeshAt(ui, pkClone, spOld);
        }
    }
}

struct C21550LinkBase
{
    void FUN_00a89af0(NiStream& stream);
};

struct C21550StreamView
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int unk10, unk14, unk18, unk1C;
    unsigned int unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C;
    unsigned int unk50, unk54, unk58, unk5C;
    unsigned int unk60, unk64, unk68, unk6C;
    unsigned int unk70, unk74, unk78, unk7C;
    unsigned int unk80, unk84, unk88, unk8C;
    unsigned int unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC;
    unsigned int unkB0, unkB4, unkB8, unkBC;
    unsigned int unkC0, unkC4, unkC8, unkCC;
    unsigned int unkD0, unkD4;
    unsigned int fileVersion;
};

struct C21550PoolData : MeshPSysData
{
    unsigned char fillPoolsOnLoad;
    unsigned int unk84, unk88, unk8C;
    unsigned short unk90;
    unsigned short generationCount;
    void ResizeChildren(unsigned int count);
};

struct C21550ParticleSystem : MeshSystem
{
    unsigned int unkA4, unkA8, unkAC, unkB0, unkB4;
    C21550PoolData* modelData;
};

class C21550PostLink : public NiPSysMeshUpdateModifierC212
{
  public:
    void PostLinkObject(NiStream& stream);
};

// @fnv 0x00c21550
void C21550PostLink::PostLinkObject(NiStream& stream)
{
    reinterpret_cast<C21550LinkBase*>(this)->FUN_00a89af0(stream);
    C21550StreamView* streamView = reinterpret_cast<C21550StreamView*>(&stream);
    if (streamView->fileVersion <= 0x0A010000)
    {
        unsigned int count = m_kSceneObjects.m_usSize;
        C21550PoolData* data = reinterpret_cast<C21550ParticleSystem*>(unk10)->modelData;
        data->ResizeChildren(count);
        return;
    }
    C21550PoolData* data = reinterpret_cast<C21550ParticleSystem*>(unk10)->modelData;
    if (data->fillPoolsOnLoad == 0)
        return;
    unsigned int index = 0;
    if (0 < data->generationCount)
    {
        do
        {
            if (index < m_kSceneObjects.m_usMaxSize)
            {
                NiObjectC212* mesh = m_kSceneObjects.m_pBase[index];
                if (mesh != 0)
                {
                    reinterpret_cast<FUN_00c212b0_cls*>(data)->FUN_00c212b0(index,
                                                                            reinterpret_cast<FUN_00c212b0_src*>(mesh));
                }
            }
            index++;
        } while (index < data->generationCount);
    }
}


// src/unmapped/nitarray_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/unmapped/nitarray.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct NiD3DShaderFactory
{
    void UpdateShaderMaterialCache(void*);
    void ApplyDirtyMaterial(void*);
};
struct NiD3DRenderState
{
    void FUN_00e87980(void*);
};
struct FUN_009ba5f0_shell
{
    void SetChildObject(int);
};
struct FUN_00c89c80_obj
{
    void CopyFromSource(unsigned int uiMaxSize);
};
struct MemoryManager
{
    void* Allocate(unsigned int auiSize) throw();
};
extern MemoryManager DAT_011f6238;
struct KeyPair
{
    void* m_pFirst;
    void* m_pSecond;

    static void* operator new(unsigned int auiSize) throw()
    {
        return DAT_011f6238.Allocate(auiSize);
    }

    KeyPair(void* apFirst, void* apSecond) throw() : m_pFirst(apFirst), m_pSecond(apSecond)
    {}
};
struct FUN_00a41520_cls
{
    int unk00;
    int unk04;
    unsigned short m_uCapacity;
    unsigned short m_uCount;
    unsigned short m_u0c;
    unsigned short m_uGrowStep;

    int FindPairIndex(void* apFirst, void* apSecond);
    void FUN_00a90180(unsigned int auiNewSize);
    void FUN_00ba3aa0(unsigned int auiIndex, KeyPair** appEntry);

    bool FUN_00a41520(void* apFirst, void* apSecond);
};
struct MM
{
    void __thiscall Deallocate(void*);
};
extern MM g_memoryManager;
class NiNode;
template <class T> struct NiPointer
{
    T* ptr;
    ~NiPointer();
    static void __cdecl operator delete[](void* memory)
    {
        g_memoryManager.Deallocate(memory);
    }
};
void __cdecl DeleteNiNodePointerArray(NiPointer<NiNode>* buffer);
void* __cdecl FUN_00aa1070(unsigned int auiSize);
void __cdecl FUN_00aa10f0(void* apMemory);
struct S_Interface
{
    static KeyPair** Allocate(unsigned int auiCount)
    {
        return (KeyPair**)FUN_00aa1070(sizeof(KeyPair*) * auiCount);
    }
};
struct C89CD0Target
{
    void process(void* arg);
};
struct C89CD0Holder
{
    int unk00;
    int unk04;
    C89CD0Target* m_pkTarget;

    void ProcessTarget(void* arg);
};
struct Target
{
    void FUN_00c89bf0(void* apArg);
};
struct FUN_00c89cf0_cls
{
    int unk00;
    int unk04;
    Target* m_pFlagTarget;

    void DispatchToTarget(void* apArg);
};

struct RefHolder
{
    void* m_pObject;
    RefHolder(const RefHolder& apOther);
    ~RefHolder();
    operator void*() const;
};

struct RefList
{
    unsigned int GetSize() const;
    RefHolder& GetAt(unsigned int auiIndex);
    unsigned int Add(const RefHolder& apRef);
};

// @fnv 0x00869420
void __cdecl FUN_00869420(RefList* apSource, RefList* apTarget)
{
    for (unsigned int i = 0; i < apSource->GetSize(); i = i + 1)
    {
        RefHolder spRef(apSource->GetAt(i));
        if (spRef)
        {
            apTarget->Add(spRef);
        }
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

class NiRefObjectA47
{
  public:
    virtual ~NiRefObjectA47();
    virtual void DeleteThis();

    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }

    long m_uiRefCount;
};

template <class T> class NiPointerA47
{
  public:
    NiPointerA47(T* pObject = 0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerA47()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPointerA47& operator=(const NiPointerA47& ptr)
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
    NiPointerA47& operator=(T* pObject)
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
    bool operator!=(const NiPointerA47& ptr) const
    {
        return m_pObject != ptr.m_pObject;
    }

    T* m_pObject;
};

typedef NiPointerA47<NiRefObjectA47> NiObjectPtrA47;

NiObjectPtrA47* __cdecl FUN_00c1d790(unsigned int auiCount);
void __cdecl ReleaseObjectArray(NiObjectPtrA47* pkArray);

class NiTObjectArrayA47
{
  public:
    virtual ~NiTObjectArrayA47();

    NiObjectPtrA47* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_0060bef0(unsigned int uiMaxSize);
};

// @fnv 0x0060bef0
void NiTObjectArrayA47::FUN_0060bef0(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != NiObjectPtrA47(0))
            {
                m_pBase[i] = NiObjectPtrA47(0);
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    NiObjectPtrA47* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = FUN_00c1d790(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = NiObjectPtrA47(0);
    }
    else
    {
        m_pBase = 0;
    }
    ReleaseObjectArray(pSaveBase);
}

namespace fnv_009a5a70 {
struct ItemList
{
    unsigned int GetCount();
    void QueryItem(void** result);
};
struct SpawnedObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    SpawnedObject();
    ~SpawnedObject();
    void Fill(void* item);
    void Attach(ItemList* list);
};
struct FUN_009a5a70_cls
{
    void Dispatch(void* item, SpawnedObject* object);
    void FUN_009a5a70(ItemList* list);
};
// @fnv 0x009a5a70
void FUN_009a5a70_cls::FUN_009a5a70(ItemList* list)
{
    unsigned int count = list->GetCount();
    for (unsigned int index = 0; index < count; ++index)
    {
        bool failed = false;
        SpawnedObject* object = new SpawnedObject;
        void* output;
        list->QueryItem(&output);
        object->Fill(output);
        object->Attach(list);
        if (output == 0)
            failed = true;
        if (!failed)
            Dispatch(output, object);
        else
            delete object;
    }
}
}  // namespace fnv_009a5a70

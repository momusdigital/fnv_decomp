
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiD3DShaderFactory
{
    void UpdateShaderMaterialCache(void*);
    void FUN_00e94050(void*);
};

struct NiD3DRenderState
{
    void FUN_00e87980(void*);
};

// Forwards p to the shader factory at offset 0xf8, then passes the pointer at 0x10f8 to its second method.
// @fnv 0x00e87980
void NiD3DRenderState::FUN_00e87980(void* apData)
{
    ((NiD3DShaderFactory*)((char*)this + 0xf8))->UpdateShaderMaterialCache(apData);
    ((NiD3DShaderFactory*)((char*)this + 0xf8))->FUN_00e94050(*(void**)((char*)this + 0x10f8));
}

struct FUN_009ba5f0_shell
{
    void SetChildObject(int);
};

struct FUN_00c89c80_obj
{
    void CopyFromSource(unsigned int uiMaxSize);
};

// @fnv 0x00c89c80
void FUN_00c89c80_obj::CopyFromSource(unsigned int pDest)
{
    if (this && *(void**)((char*)this + 8))
    {
        void* p = *(void**)((char*)this + 8);
        ((FUN_009ba5f0_shell*)pDest)->SetChildObject(*(int*)((char*)p + 0xc));
        *(int*)((char*)pDest + 0xc) = *(int*)((char*)p + 0x14);
        *(int*)((char*)pDest + 0x10) = *(int*)((char*)p + 0x18);
        *(unsigned int*)((char*)pDest + 8) = *(unsigned char*)((char*)p + 0x1c);
    }
    else
    {
        ((FUN_009ba5f0_shell*)pDest)->SetChildObject(0);
        *(int*)((char*)pDest + 0xc) = 0;
        *(int*)((char*)pDest + 0x10) = 0;
    }
}

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

// @fnv 0x00a41520
bool FUN_00a41520_cls::FUN_00a41520(void* apFirst, void* apSecond)
{
    if (FindPairIndex(apFirst, apSecond) == -1)
    {
        KeyPair* pEntry = new KeyPair(apFirst, apSecond);

        unsigned int ItemUpdateArray = m_uCount;
        if (ItemUpdateArray >= m_uCapacity)
            FUN_00a90180(m_uGrowStep + ItemUpdateArray);

        FUN_00ba3aa0(ItemUpdateArray, &pEntry);
    }
    return false;
}

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
// Deletes the array of NiPointer<NiNode> objects pointed to by buffer when buffer is non-null.
// @fnv 0x00b7ce30
void __cdecl DeleteNiNodePointerArray(NiPointer<NiNode>* pNodePointerArray)
{
    if (pNodePointerArray)
        delete[] pNodePointerArray;
}

void* __cdecl FUN_00aa1070(unsigned int auiSize);
void __cdecl FUN_00aa10f0(void* apMemory);

struct S_Interface
{
    static KeyPair** Allocate(unsigned int auiCount)
    {
        return (KeyPair**)FUN_00aa1070(sizeof(KeyPair*) * auiCount);
    }
};

// Resizes the key-pair array to auiNewSize, clearing dropped entries, reallocating, copying old entries and freeing the old buffer.
// @fnv 0x00a90180
void FUN_00a41520_cls::FUN_00a90180(unsigned int auiNewSize)
{
    if (auiNewSize == m_uCapacity)
        return;

    if (auiNewSize < m_uCount)
    {
        for (unsigned short i = (unsigned short)auiNewSize; i < m_uCount; i++)
        {
            if (((KeyPair**)unk04)[i] != 0)
            {
                ((KeyPair**)unk04)[i] = 0;
                m_u0c += 0xffff;
            }
        }
        m_uCount = (unsigned short)auiNewSize;
    }

    KeyPair** oldEntries = (KeyPair**)unk04;
    m_uCapacity = (unsigned short)auiNewSize;

    if (auiNewSize > 0)
    {
        unk04 = (int)S_Interface::Allocate(m_uCapacity);

        for (unsigned short i = 0; i < m_uCount; i++)
            ((KeyPair**)unk04)[i] = oldEntries[i];

        for (unsigned short j = m_uCount; j < m_uCapacity; j++)
            ((KeyPair**)unk04)[j] = 0;
    }
    else
    {
        unk04 = 0;
    }

    FUN_00aa10f0(oldEntries);
}

// Stores the entry pointer at the given index, growing the count and adjusting the non-null entry counter when the slot's nullness changes.
// @fnv 0x00ba3aa0
void FUN_00a41520_cls::FUN_00ba3aa0(unsigned int auiIndex, KeyPair** appEntry)
{
    if (auiIndex >= m_uCount)
    {
        m_uCount = (unsigned short)(auiIndex + 1);
        if (*appEntry != 0)
        {
            m_u0c++;
        }
    }
    else
    {
        if (*appEntry != 0)
        {
            KeyPair** pEntries = (KeyPair**)unk04;
            if (pEntries[auiIndex] == 0)
            {
                m_u0c++;
            }
        }
        else
        {
            KeyPair** pEntries = (KeyPair**)unk04;
            if (pEntries[auiIndex] != 0)
            {
                unsigned short minusOne = 0xffff;
                m_u0c += minusOne;
            }
        }
    }
    KeyPair** store = (KeyPair**)unk04;
    store[auiIndex] = *appEntry;
}

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

// @fnv 0x00c89cd0
void C89CD0Holder::ProcessTarget(void* arg)
{
    C89CD0Holder* pkHolder = this;
    if (pkHolder)
    {
        C89CD0Target* pkTarget = pkHolder->m_pkTarget;
        if (pkTarget)
            pkTarget->process(arg);
    }
}

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

// @fnv 0x00c89cf0
void FUN_00c89cf0_cls::DispatchToTarget(void* apArg)
{
    if (this != 0)
    {
        if (m_pFlagTarget != 0)
            m_pFlagTarget->FUN_00c89bf0(apArg);
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

    void FUN_00a47770(unsigned int uiMaxSize);
};

// Resizes the object array to uiMaxSize, releasing surplus elements and reallocating m_pBase while preserving existing entries.
// @fnv 0x00a47770
void NiTObjectArrayA47::FUN_00a47770(unsigned int uiMaxSize)
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
                m_pBase[i] = 0;
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
            m_pBase[i] = 0;
    }
    else
    {
        m_pBase = 0;
    }
    ReleaseObjectArray(pSaveBase);
}

extern char* DAT_0109b220;
extern long DAT_011f4400;
void __cdecl RemoveGlobalConstant(char** name);

struct S_00e87690_Str
{
    char* h;
    S_00e87690_Str(const S_00e87690_Str& o) throw()
    {
        if (o.h != DAT_0109b220)
            InterlockedIncrement((long*)(o.h - 8));
        h = o.h;
    }
    ~S_00e87690_Str() throw()
    {
        if (h != DAT_0109b220)
            InterlockedDecrement((long*)(h - 8));
    }
};

struct S_00e87690_Obj
{
    virtual void v0() throw();
    virtual void v1() throw();
    long refs;
    int unk08;
    S_00e87690_Str name;
    int unk10;
    unsigned int flags;
};

struct S_00e87690_Com
{
    virtual long __stdcall v0() throw();
    virtual long __stdcall v1() throw();
    virtual long __stdcall Release() throw();
};

void __cdecl DeleteNiNodePointerArray(void* buffer) throw();

struct S_00e87690_Arr
{
    virtual void v0() throw();
    S_00e87690_Obj** data;
    unsigned short maxSize;
    unsigned short size;
    unsigned short esize;
    unsigned short grow;
    void FUN_00b799c0() throw();
    ~S_00e87690_Arr() throw()
    {
        DeleteNiNodePointerArray(data);
    }
};

struct S_00e87690_Base
{
    virtual ~S_00e87690_Base() throw()
    {
        InterlockedDecrement(&DAT_011f4400);
    }
    long refs;
    int unk08;
};

struct FUN_00e87690 : S_00e87690_Base
{
    S_00e87690_Arr a1;
    S_00e87690_Arr a2;
    int unk2c;
    int unk30;
    int unk34;
    S_00e87690_Com* unk38;
    int unk3c;
    int unk40;
    virtual ~FUN_00e87690() throw();
};

// Walks a1 and a2 entries, adjusting refcounts and calling RemoveGlobalConstant on the name for flag type 4, then clears unk3c, releases unk38 and zeros unk40.
// @fnv 0x00e87690
FUN_00e87690::~FUN_00e87690() throw()
{
    for (unsigned int i = 0; i < a1.maxSize; i++)
    {
        S_00e87690_Obj* p = a1.data[i];
        if (p)
        {
            InterlockedIncrement(&p->refs);
            if ((p->flags & 0xf0000000) == 0x40000000)
            {
                S_00e87690_Str k(p->name);
                RemoveGlobalConstant(&k.h);
            }
            if (!InterlockedDecrement(&p->refs))
                p->v1();
        }
    }
    a1.FUN_00b799c0();
    for (unsigned int i = 0; i < a2.maxSize; i++)
    {
        S_00e87690_Obj* p = a2.data[i];
        if (p)
        {
            InterlockedIncrement(&p->refs);
            if ((p->flags & 0xf0000000) == 0x40000000)
                RemoveGlobalConstant(&p->name.h);
            if (!InterlockedDecrement(&p->refs))
                p->v1();
        }
    }
    a2.FUN_00b799c0();
    unk3c = 0;
    if (unk38)
        unk38->Release();
    unk38 = 0;
    unk40 = 0;
}

struct NiRefObj
{
    virtual void v00();
    virtual void v04();
    long m_iObjectReferenceCount;
};

struct FUN_00e87800_obj
{
    int FUN_00e87800(NiRefObj** appObj);
};

struct FUN_00e878c0_cls
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
    int m_34;

    int InsertEntry(NiRefObj* apObj);
};

// Holds a reference on apObj while calling FUN_00e87800 on the sub-object at unk0c; sets m_34 to 0x30 if it returns -1, and returns m_34.
// @fnv 0x00e878c0
int FUN_00e878c0_cls::InsertEntry(NiRefObj* apObj)
{
    NiRefObj* pObj = apObj;
    *(NiRefObj* volatile*)&apObj = pObj;
    if (pObj != 0)
    {
        InterlockedIncrement(&pObj->m_iObjectReferenceCount);
    }
    FUN_00e87800_obj* sub = (FUN_00e87800_obj*)&unk0c;
    bool failed = sub->FUN_00e87800(&apObj) == -1;
    if (pObj != 0 && InterlockedDecrement(&pObj->m_iObjectReferenceCount) == 0)
    {
        pObj->v04();
    }
    if (failed)
    {
        m_34 = 0x30;
    }
    return m_34;
}

namespace fnv_00e87920 {
struct NiRefObj
{
    virtual void v00();
    virtual void v04();
    long m_iObjectReferenceCount;
};

struct FUN_00e87800_obj
{
    int FUN_00e87800(NiRefObj** appObj);
};

struct FUN_00e87920_cls
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
    int m_34;

    int FUN_00e87920(NiRefObj* apObj);
};

// Holds a reference on apObj while calling FUN_00e87800 on the sub-object at unk1c; sets m_34 to 0x30 if it returns -1, and returns m_34.
// @fnv 0x00e87920
int FUN_00e87920_cls::FUN_00e87920(NiRefObj* apObj)
{
    NiRefObj* pObj = apObj;
    *(NiRefObj* volatile*)&apObj = pObj;
    if (pObj != 0)
    {
        InterlockedIncrement(&pObj->m_iObjectReferenceCount);
    }
    FUN_00e87800_obj* sub = (FUN_00e87800_obj*)&unk1c;
    bool failed = sub->FUN_00e87800(&apObj) == -1;
    if (pObj != 0 && InterlockedDecrement(&pObj->m_iObjectReferenceCount) == 0)
    {
        pObj->v04();
    }
    if (failed)
    {
        m_34 = 0x30;
    }
    return m_34;
}
}  // namespace fnv_00e87920

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);

struct NiPoint2
{
    float x;
    float y;
};

struct TextureMapTransform
{
    int unk00;
    int unk04;
    float unk08;
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

    static void* operator new(size_t size) throw()
    {
        return DAT_011f6238.Allocate(size);
    }
    TextureMapTransform(const NiPoint2& kTranslate, float m_fRotation, const NiPoint2& kScale,
                       const NiPoint2& kTargetCenter, int eMethod) throw();

    NiPoint2 GetTranslate() const
    {
        return *(NiPoint2*)((char*)this + 0);
    }
    float GetRotate() const
    {
        return *(float*)((char*)this + 8);
    }
    NiPoint2 GetScale() const
    {
        return *(NiPoint2*)((char*)this + 0xc);
    }
    NiPoint2 GetNavMeshData() const
    {
        return *(NiPoint2*)((char*)this + 0x14);
    }
    int GetTransformMethod() const
    {
        return *(int*)((char*)this + 0x44);
    }
};

struct NiTexturePtr
{
    void* m_pObject;
    NiTexturePtr() : m_pObject(0)
    {}
    NiTexturePtr(const NiTexturePtr& kPtr) : m_pObject(kPtr.m_pObject)
    {
        if (m_pObject)
            InterlockedIncrement((long volatile*)((char*)m_pObject + 4));
    }
};

struct NiTexturingProperty
{
    struct Map
    {
        virtual ~Map();
        unsigned short m_usFlags;
        NiTexturePtr m_spTexture;
        TextureMapTransform* m_pTextureTransform;

        Map(const Map& kMap) throw();
    };
};

// Copy-constructs a NiTexturingProperty::Map, copying flags and texture, and deep-copying the texture transform if present.
// @fnv 0x00a6a8b0
NiTexturingProperty::Map::Map(const Map& kMap) throw() : m_usFlags(kMap.m_usFlags), m_spTexture(kMap.m_spTexture)
{
    if (kMap.m_pTextureTransform)
    {
        m_pTextureTransform =
            new TextureMapTransform(kMap.m_pTextureTransform->GetTranslate(), kMap.m_pTextureTransform->GetRotate(),
                                   kMap.m_pTextureTransform->GetScale(), kMap.m_pTextureTransform->GetNavMeshData(),
                                   kMap.m_pTextureTransform->GetTransformMethod());
    }
    else
    {
        m_pTextureTransform = 0;
    }
}

#include <string.h>
void __cdecl FUN_00ec61c0(void* apDst, int aiValue, unsigned int auiSize);

struct FUN_004eba20
{
    FUN_004eba20();
    virtual ~FUN_004eba20();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

struct RefObject;
template <class T> struct RefPtr
{
    T* m_pObject;
    RefPtr(T* p = 0) : m_pObject(p)
    {
        if (m_pObject)
            AcquireReference();
    }
    ~RefPtr();
    void AcquireReference();
};

template <class T> struct TArray
{
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    TArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
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
    virtual ~TArray();
};

template <class T> struct TObjectArray : TArray<T>
{
    TObjectArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) : TArray<T>(uiMaxSize, uiGrowBy)
    {}
    virtual ~TObjectArray();
};
template <class T> struct TPrimitiveArray : TArray<T>
{
    TPrimitiveArray(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1) : TArray<T>(uiMaxSize, uiGrowBy)
    {}
    virtual ~TPrimitiveArray();
};

template <class T> struct TFixedArray
{
    unsigned int m_uiSize;
    T* m_pData;
    int unk0c;
    TFixedArray(unsigned int uiSize) : m_uiSize(uiSize), unk0c(0)
    {
        m_pData = (T*)FUN_00aa1070(uiSize * sizeof(T));
        FUN_00ec61c0(m_pData, 0, m_uiSize * sizeof(T));
    }
    virtual ~TFixedArray();
};
template <class T> struct RenderStateGroup : TFixedArray<T>
{
    RenderStateGroup() : TFixedArray<T>(0x25)
    {}
    virtual ~RenderStateGroup();
};

struct ColorA
{
    float r, g, b, a;
    ColorA(float fR = 0.0f, float fG = 0.0f, float fB = 0.0f, float fA = 0.0f) : r(fR), g(fG), b(fB), a(fA)
    {}
};

struct FUN_00b8a9e0 : FUN_004eba20
{
    int m_24;
    int m_28;
    ColorA m_kFogTint;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    RefPtr<RefObject> m_4c;
    RefPtr<RefObject> m_50;
    bool m_abFlags[3];
    TObjectArray<RefObject*> m_58;
    TPrimitiveArray<int> m_68;
    RenderStateGroup<int> m_78;

    FUN_00b8a9e0();
    virtual ~FUN_00b8a9e0();
};

// Zero-initializes m_24, m_28, m_3c, m_40, m_44, m_48 and the m_abFlags array; other members use their default constructors.
// @fnv 0x00b8a9e0
FUN_00b8a9e0::FUN_00b8a9e0() : m_24(0), m_28(0), m_3c(0), m_40(0), m_44(0), m_48(0)
{
    memset(m_abFlags, 0, sizeof(m_abFlags));
}

#include <windows.h>
struct S_00c1e9a0_RefObject
{
    virtual void v0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement((LONG*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((LONG*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> struct S_00c1e9a0_Ptr
{
    T* m_pObject;
    S_00c1e9a0_Ptr(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~S_00c1e9a0_Ptr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    S_00c1e9a0_Ptr& operator=(const S_00c1e9a0_Ptr& ptr)
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
    S_00c1e9a0_Ptr& operator=(T* pObject)
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
    bool operator!=(const S_00c1e9a0_Ptr& ptr) const
    {
        return m_pObject != ptr.m_pObject;
    }
};

typedef S_00c1e9a0_Ptr<S_00c1e9a0_RefObject> S_00c1e9a0_RefPtr;

S_00c1e9a0_RefPtr* FUN_00c1d740(unsigned int ItemUpdateArray);
void ReleaseObjectArray(S_00c1e9a0_RefPtr* pBase);

struct S_00c1e9a0_Array
{
    virtual ~S_00c1e9a0_Array();
    S_00c1e9a0_RefPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00c1e9a0(unsigned int uiMaxSize);
};

// Sets the array capacity to uiMaxSize, clearing entries past it, copying entries into a new buffer from FUN_00c1d740 and releasing the old buffer.
// @fnv 0x00c1e9a0
void S_00c1e9a0_Array::FUN_00c1e9a0(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != S_00c1e9a0_RefPtr(0))
            {
                m_pBase[i] = (S_00c1e9a0_RefObject*)0;
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    S_00c1e9a0_RefPtr* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = FUN_00c1d740(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = (S_00c1e9a0_RefObject*)0;
    }
    else
    {
        m_pBase = 0;
    }
    ReleaseObjectArray(pSaveBase);
}

void __cdecl FUN_00aa1460(void* apSelf, unsigned int auiSize);
void __cdecl RemoveGlobalConstant(void** appRef);

struct FUN_00e7de30_cls
{
    void FUN_00e7de30();
};

struct FUN_00e891f0_cls
{
    void FUN_00e891f0();
    void ClearFields();
};

struct GlobalRefOwner
{
    void FindOrAdd(void* apRef);
};
extern GlobalRefOwner* DAT_0126f6cc;

struct RefHolder
{
    int unk00;
    int unk04;
    void* m_08;
};

struct FUN_00e7ecd0_cls
{
    int unk00;
    int m_04;
    void* m_08;
    int m_0c;
    FUN_00e891f0_cls* m_10;
    int m_14;
    RefHolder* m_18;
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
    unsigned short m_5c;
    unsigned char m_5e;
    unsigned char m_5f;

    void FUN_00e7ecd0();
};

// If m_5f is 0, calls FUN_00e7de30 then FUN_00aa1460(this, 0x68); otherwise resets m_10, m_18 and other fields and passes this to DAT_0126f6cc->FindOrAdd.
// @fnv 0x00e7ecd0
void FUN_00e7ecd0_cls::FUN_00e7ecd0()
{
    void* ref;

    if (m_5f == 0)
    {
        ((FUN_00e7de30_cls*)this)->FUN_00e7de30();
        FUN_00aa1460(this, 0x68);
        return;
    }

    FUN_00e891f0_cls* obj = m_10;
    m_08 = 0;
    obj->FUN_00e891f0();
    m_10->ClearFields();

    RefHolder* holder = m_18;
    if (holder != 0)
    {
        if (holder->m_08 != DAT_0109b220)
        {
            InterlockedIncrement((LONG*)((char*)holder->m_08 - 8));
        }
        ref = holder->m_08;
        RemoveGlobalConstant(&ref);
        if (ref != DAT_0109b220)
        {
            InterlockedDecrement((LONG*)((char*)ref - 8));
        }
    }

    m_18 = 0;
    m_04 = 0;
    m_0c = 0;
    m_5c = 0;
    m_14 = 0;
    m_5e = 0;

    ref = this;
    DAT_0126f6cc->FindOrAdd(&ref);
}

struct S_00e87510_RefObject
{
    virtual ~S_00e87510_RefObject() throw();
    virtual void DeleteThis() throw();

    void IncRefCount() throw()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }

    LONG m_uiRefCount;
};

struct S_00e87510_Ptr
{
    S_00e87510_RefObject* m_pObject;

    S_00e87510_Ptr(S_00e87510_RefObject* pObject = 0) throw() : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~S_00e87510_Ptr() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    S_00e87510_Ptr& operator=(const S_00e87510_Ptr& ptr) throw()
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
    bool operator!=(const S_00e87510_Ptr& ptr) const
    {
        return m_pObject != ptr.m_pObject;
    }
};

S_00e87510_Ptr* AllocateGOArray(unsigned int auiCount);
void __cdecl DeleteNiNodePointerArray(S_00e87510_Ptr* pArray);

struct S_00e87510_Array
{
    int unk00;
    S_00e87510_Ptr* m_pBase;     // 04
    unsigned short m_usMaxSize;  // 08
    unsigned short m_usSize;     // 0a
    unsigned short m_usESize;    // 0c
    unsigned short m_usGrowBy;   // 0e

    void Resize(unsigned int uiMaxSize);
};

// Resizes the array to uiMaxSize, clearing excess elements and reallocating the backing pointer array while preserving existing entries.
// @fnv 0x00e87510
void S_00e87510_Array::Resize(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_usMaxSize)
        return;

    unsigned short i;
    if (uiMaxSize < m_usSize)
    {
        for (i = (unsigned short)uiMaxSize; i < m_usSize; i++)
        {
            if (m_pBase[i] != S_00e87510_Ptr(0))
            {
                m_pBase[i] = S_00e87510_Ptr(0);
                m_usESize--;
            }
        }
        m_usSize = (unsigned short)uiMaxSize;
    }

    S_00e87510_Ptr* pSaveBase = m_pBase;
    m_usMaxSize = (unsigned short)uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = AllocateGOArray(m_usMaxSize);
        for (i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
        for (i = m_usSize; i < m_usMaxSize; i++)
            m_pBase[i] = S_00e87510_Ptr(0);
    }
    else
    {
        m_pBase = 0;
    }

    DeleteNiNodePointerArray(pSaveBase);
}

struct S_00e98aa0_RefObj
{
    virtual ~S_00e98aa0_RefObj();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((LONG*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((LONG*)&m_uiRefCount))
            DeleteThis();
    }
};

template <class T> struct S_00e98aa0_Ptr
{
    T* m_pObject;
    S_00e98aa0_Ptr& operator=(T* pObject)
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
};

struct S_00e98aa0_Holder
{
    S_00e98aa0_Ptr<S_00e98aa0_RefObj> m_sp0;
    S_00e98aa0_Ptr<S_00e98aa0_RefObj> m_sp4;
    void SetObject(S_00e98aa0_RefObj* p);
};

// Assigns p to m_sp0 and null to m_sp4 through the reference-counting pointer assignment.
// @fnv 0x00e98aa0
void S_00e98aa0_Holder::SetObject(S_00e98aa0_RefObj* apRefObj)
{
    m_sp0 = apRefObj;
    m_sp4 = 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

class NiRefObjectX
{
  public:
    virtual ~NiRefObjectX();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement((long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    unsigned int m_uiRefCount;
};

template <class T> class NiPtrX
{
  public:
    NiPtrX(T* pObject = (T*)0)
    {
        m_pObject = pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPtrX(const NiPtrX& ptr)
    {
        m_pObject = ptr.m_pObject;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPtrX()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    NiPtrX& operator=(const NiPtrX& ptr)
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
    bool operator==(const NiPtrX& ptr) const
    {
        return m_pObject == ptr.m_pObject;
    }
    T* m_pObject;
};

typedef NiPtrX<NiRefObjectX> ElemPtr;

class NiTArrayX
{
  public:
    virtual ~NiTArrayX();
    ElemPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_00c1e9a0(unsigned int uiMaxSize);
    void Set(unsigned int uiIndex, const ElemPtr& element);

    unsigned int SetAtGrow(unsigned int uiIndex, const ElemPtr& element)
    {
        if (uiIndex >= m_usMaxSize)
            FUN_00c1e9a0(uiIndex + m_usGrowBy);
        Set(uiIndex, element);
        return uiIndex;
    }

    unsigned int FUN_00c1f360(const ElemPtr& element);
};

// @fnv 0x00c1f360
unsigned int NiTArrayX::FUN_00c1f360(const ElemPtr& element)
{
    if (element == ElemPtr(0))
        return (unsigned int)~0;

    for (unsigned short i = 0; i < m_usSize; i++)
    {
        if (m_pBase[i] == ElemPtr(0))
        {
            m_pBase[i] = element;
            m_usESize++;
            return i;
        }
    }

    return SetAtGrow(m_usSize, element);
}

struct MaterialDeviceView;

struct MaterialDeviceMethods
{
    void* QueryInterface;
    void* AddRef;
    void* Release;
    void* TestCooperativeLevel;
    void* GetAvailableTextureMem;
    void* EvictManagedResources;
    void* GetDirect3D;
    void* GetDeviceCaps;
    void* GetDisplayMode;
    void* GetCreationParameters;
    void* SetCursorProperties;
    void* SetCursorPosition;
    void* ShowCursor;
    void* CreateAdditionalSwapChain;
    void* GetSwapChain;
    void* GetNumberOfSwapChains;
    void* Reset;
    void* Present;
    void* GetBackBuffer;
    void* GetRasterStatus;
    void* SetDialogBoxMode;
    void* SetGammaRamp;
    void* GetGammaRamp;
    void* CreateTexture;
    void* CreateVolumeTexture;
    void* CreateCubeTexture;
    void* CreateVertexBuffer;
    void* CreateIndexBuffer;
    void* CreateRenderTarget;
    void* CreateDepthStencilSurface;
    void* UpdateSurface;
    void* UpdateTexture;
    void* GetRenderTargetData;
    void* GetFrontBufferData;
    void* StretchRect;
    void* ColorFill;
    void* CreateOffscreenPlainSurface;
    void* SetRenderTarget;
    void* GetRenderTarget;
    void* SetDepthStencilSurface;
    void* GetDepthStencilSurface;
    void* BeginScene;
    void* EndScene;
    void* Clear;
    void* SetTransform;
    void* GetTransform;
    void* MultiplyTransform;
    void* SetViewport;
    void* GetViewport;
    long(__stdcall* SetMaterial)(MaterialDeviceView* device, const void* material);
};

struct MaterialDeviceView
{
    MaterialDeviceMethods* methods;
};

struct MaterialUploadState
{
    void* currentMaterial;
    bool dirty;
    void FUN_00e94050(MaterialDeviceView* device);
};

// @fnv 0x00e94050
void MaterialUploadState::FUN_00e94050(MaterialDeviceView* device)
{
    if (dirty)
    {
        dirty = false;
        device->methods->SetMaterial(device, currentMaterial);
    }
}

struct ShaderConstantEntryArray
{
    int unk00;
    ElemPtr* data;
    unsigned short capacity;
    unsigned short count;
    unsigned short effective;
    unsigned short grow;

    void Resize(unsigned int newCapacity);
    void FUN_00e86f40(unsigned int index, void* element);
    unsigned int FUN_00e87800(const ElemPtr& element);
};

// Stores element in the first null slot, else grows the array if full and appends it, returning its index; returns -1 for a null element.
// @fnv 0x00e87800
unsigned int ShaderConstantEntryArray::FUN_00e87800(const ElemPtr& element)
{
    if (element == ElemPtr(0))
        return 0xffffffff;
    for (unsigned short i = 0; i < count; ++i)
    {
        if (data[i] == ElemPtr(0))
        {
            data[i] = element;
            ++effective;
            return i;
        }
    }
    unsigned int oldCount = count;
    if (oldCount >= capacity)
        Resize(grow + oldCount);
    FUN_00e86f40(oldCount, (void*)&element);
    return oldCount;
}

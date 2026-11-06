
// src/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C"
{
    extern const void* g_011f4100;
}

// @fnv 0x00a56c00
const void* __cdecl FUN_00a56c00()
{
    return &g_011f4100;
}

struct NiGeomMorpherUpdateTask;
extern int DAT_011a9414;
extern int DAT_011a941c;
extern NiGeomMorpherUpdateTask** DAT_011a940c;
extern int DAT_011f4180;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct FreeStore
{
    void FUN_00a56e60(int);
};
// @fnv 0x00a56f90
NiGeomMorpherUpdateTask* __cdecl PopMorpherUpdateTask()
{
    EnterCriticalSection((void*)&DAT_011f4180);
    if (DAT_011a9414 == 0)
    {
        ((FreeStore*)&DAT_011a940c)->FUN_00a56e60(DAT_011a941c);
        DAT_011a941c *= 2;
    }
    NiGeomMorpherUpdateTask* pkTask = DAT_011a940c[0];
    DAT_011a9414--;
    DAT_011a940c[0] = DAT_011a940c[DAT_011a9414];
    LeaveCriticalSection((void*)&DAT_011f4180);
    return pkTask;
}

extern unsigned char DAT_011f5b08;
struct FakeGeo
{
    int __vt;
    unsigned int m_ref;
};
struct MorphController
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void MorphFunc() = 0;
};
struct BaseTask
{
    virtual void w00() = 0;
    virtual void w01() = 0;
    virtual void w02() = 0;
    virtual void w03() = 0;
    virtual void w04() = 0;
    virtual void w05() = 0;
    virtual void w06() = 0;
    virtual void w07() = 0;
    virtual void w08() = 0;
    virtual void w09() = 0;
    virtual void w10() = 0;
    virtual void w11() = 0;
    virtual void w12() = 0;
    virtual void w13() = 0;
    virtual void w14() = 0;
    virtual void w15() = 0;
    virtual void w16() = 0;
    virtual void w17() = 0;
    virtual void w18() = 0;
    virtual void w19() = 0;
    virtual void w20() = 0;
    virtual void w21() = 0;
    virtual void w22() = 0;
    virtual void w23() = 0;
    virtual void w24() = 0;
    virtual void w25() = 0;
    virtual void w26() = 0;
    virtual void w27() = 0;
    virtual void w28() = 0;
    virtual void w29() = 0;
    virtual void w30() = 0;
    virtual void w31() = 0;
    virtual void w32() = 0;
    virtual void w33() = 0;
    virtual void w34() = 0;
    virtual void w35() = 0;
    virtual void w36() = 0;
    virtual void Tail() = 0;
};
struct NiGeomMorpherUpdateTask : BaseTask
{
    int _pad[2];
    MorphController* m_pkMorphController;
    FakeGeo* m_spReferencedObject;
    void DoTask();
};
// If the global flag is clear and the geometry's reference count exceeds one, calls MorphFunc on the morph controller, then Tail.
// @fnv 0x00a56bb0
void NiGeomMorpherUpdateTask::DoTask()
{
    if (!DAT_011f5b08 && m_spReferencedObject->m_ref > 1)
        m_pkMorphController->MorphFunc();
    Tail();
}

struct NiRefObject
{
    virtual ~NiRefObject();
    virtual void Unk_04();
    int m_ref;
};
extern int(__stdcall* DAT_00fdf1c4)(void*);
extern int DAT_01069674;
struct S_00a56c10
{
    int _00;
    int _04;
    int _08;
    NiRefObject* _0C;
    NiRefObject* _10;
    void ReleaseRefObjects();
};
// Releases the two NiRefObject pointers via DAT_00fdf1c4 and, when the refcount reaches zero, calls their Unk_04, then resets the vtable and destroys the base.
// @fnv 0x00a56c10
void S_00a56c10::ReleaseRefObjects()
{
    int(__stdcall * f)(void*) = DAT_00fdf1c4;
    NiRefObject* p = _10;
    if (p)
    {
        if (f(&p->m_ref) == 0)
            p->Unk_04();
    }
    p = _0C;
    if (p)
    {
        if (f(&p->m_ref) == 0)
            p->Unk_04();
    }
    *(void**)this = &DAT_01069674;
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
}

extern int(__stdcall* DAT_00fdf1c0)(void*);

struct S_00a56c60 : S_00a56c10
{
    void SetRefObjects(NiRefObject* nextFirst, NiRefObject* nextSecond);
};

// @fnv 0x00a56c60
void S_00a56c60::SetRefObjects(NiRefObject* nextFirst, NiRefObject* nextSecond)
{
    int(__stdcall * decrement)(void*) = DAT_00fdf1c4;
    NiRefObject* previous = _0C;
    if (previous != nextFirst)
    {
        if (previous != 0)
        {
            if (decrement(&previous->m_ref) == 0)
                previous->Unk_04();
        }
        _0C = nextFirst;
        if (nextFirst != 0)
            DAT_00fdf1c0(&nextFirst->m_ref);
    }

    previous = _10;
    if (previous != nextSecond)
    {
        if (previous != 0)
        {
            if (decrement(&previous->m_ref) == 0)
                previous->Unk_04();
        }
        _10 = nextSecond;
        if (nextSecond != 0)
            DAT_00fdf1c0(&nextSecond->m_ref);
    }
}

extern "C" void __cdecl FUN_00aa1460(void* apMemory, unsigned int aiSize);
extern "C" void __cdecl FUN_00aa1490(void* apMemory, unsigned int aiSize);

class NiObject_00a56d40
{
  public:
    void FUN_00a5d3d0(void);
};

struct FUN_00a56d40_cls
{
    int m_vptr00;
    int unk04;
    int unk08;
    NiRefObject* m_0c;
    NiRefObject* m_10;

    FUN_00a56d40_cls* Destroy(unsigned char acFlags);
};

// @fnv 0x00a56d40
FUN_00a56d40_cls* FUN_00a56d40_cls::Destroy(unsigned char acFlags)
{
    if (acFlags & 2)
    {
        char* base = (char*)this - 4;
        int i = *(int*)base;
        FUN_00a56d40_cls* p = (FUN_00a56d40_cls*)((char*)this + i * 20);
        i = i - 1;
        if (i >= 0)
        {
            do
            {
                p = (FUN_00a56d40_cls*)((char*)p - 20);
                NiRefObject* a = p->m_10;
                if (a != 0 && DAT_00fdf1c4(&a->m_ref) == 0)
                {
                    a->Unk_04();
                }
                NiRefObject* b = p->m_0c;
                if (b != 0 && DAT_00fdf1c4(&b->m_ref) == 0)
                {
                    b->Unk_04();
                }
                p->m_vptr00 = (int)&DAT_01069674;
                ((NiObject_00a56d40*)p)->FUN_00a5d3d0();
            } while (--i >= 0);
        }
        if (acFlags & 1)
        {
            FUN_00aa1490(base, 0x14);
        }
        return (FUN_00a56d40_cls*)base;
    }

    ((S_00a56c10*)this)->ReleaseRefObjects();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x14);
    }
    return this;
}

class A56DF0Heap
{
  public:
    void Deallocate(void* pvMem);
};

extern A56DF0Heap g_kA56DF0Heap;

void operator delete(void* pvMem)
{
    g_kA56DF0Heap.Deallocate(pvMem);
}

class A56DF0Entry
{
  public:
    virtual ~A56DF0Entry();
};

class A56DF0Cache
{
  public:
    void Shutdown(bool bFree);
};

struct A56DF0Registry
{
    ~A56DF0Registry()
    {
        delete[] m_pkEntryArray;
        if (m_pkCache)
            m_pkCache->Shutdown(true);
    }

    A56DF0Entry* m_pkEntryArray;
    int unk04;
    A56DF0Cache* m_pkCache;
};

extern int DAT_011a9414;
extern A56DF0Registry* DAT_011a9418;
extern int DAT_011a941c;
extern int DAT_011a9420;

// Clears DAT_011a9414, deletes the registry at DAT_011a9418, and copies DAT_011a9420 into DAT_011a941c.
// @fnv 0x00a56df0
void ResetRegistry()
{
    DAT_011a9414 = 0;
    delete DAT_011a9418;
    DAT_011a941c = DAT_011a9420;
}

struct S_00a56f10;
struct S_00a56f10_List
{
    void FindOrAdd(S_00a56f10** pItem);
};
struct S_00a56f10 : S_00a56c10
{
    bool ReleaseReferences();
};

// @fnv 0x00a56f10
bool S_00a56f10::ReleaseReferences()
{
    int(__stdcall * dec)(void*) = DAT_00fdf1c4;
    NiRefObject* a = _0C;
    if (a)
    {
        if (!dec(&a->m_ref))
            a->Unk_04();
        _0C = 0;
    }
    NiRefObject* b = _10;
    if (b)
    {
        if (!dec(&b->m_ref))
            b->Unk_04();
        _10 = 0;
    }
    EnterCriticalSection(&DAT_011f4180);
    S_00a56f10* self = this;
    reinterpret_cast<S_00a56f10_List*>(&DAT_011a940c)->FindOrAdd(&self);
    LeaveCriticalSection(&DAT_011f4180);
    return true;
}

class MemoryManager;
extern MemoryManager g_memoryManager;

class FUN_00a5e3a0_Helper
{
  public:
    void* FUN_00aa3e40(unsigned int uiSize);
};

NiGeomMorpherUpdateTask* __cdecl FUN_00a56ce0(unsigned int ItemUpdateArray) throw();

struct TaskBlock
{
    NiGeomMorpherUpdateTask* m_pkTasks;
    unsigned int m_uiCount;
    TaskBlock* m_pkNext;

    TaskBlock(unsigned int ItemUpdateArray) : m_uiCount(ItemUpdateArray), m_pkNext(0)
    {
        if (ItemUpdateArray > 0)
            m_pkTasks = FUN_00a56ce0(ItemUpdateArray);
        else
            m_pkTasks = 0;
    }
    NiGeomMorpherUpdateTask* GetAt(unsigned int i)
    {
        return i >= m_uiCount ? 0 : &m_pkTasks[i];
    }

    static void* operator new(unsigned int uiSize)
    {
        return ((FUN_00a5e3a0_Helper*)&g_memoryManager)->FUN_00aa3e40(uiSize);
    }
    static void operator delete(void*, int, int);
};

class NiStreamLinkIDSet
{
  public:
    NiGeomMorpherUpdateTask** m_ppkFree;
    unsigned int m_uiCapacity;
    unsigned int m_uiSize;
    TaskBlock* m_pkBlocks;

    void Realloc(unsigned int uiNewCapacity);

    void Add(NiGeomMorpherUpdateTask* pkTask)
    {
        if (m_uiSize == m_uiCapacity)
            Realloc(m_uiCapacity > 0 ? m_uiCapacity * 2 : 1);
        m_ppkFree[m_uiSize++] = pkTask;
    }

    void FUN_00a56e60(unsigned int ItemUpdateArray);
};

// @fnv 0x00a56e60
void NiStreamLinkIDSet::FUN_00a56e60(unsigned int uiTaskCount)
{
    TaskBlock* pkBlock = new TaskBlock(uiTaskCount);
    for (unsigned int i = 0; i < uiTaskCount; i++)
        Add(pkBlock->GetAt(i));
    pkBlock->m_pkNext = m_pkBlocks;
    m_pkBlocks = pkBlock;
}

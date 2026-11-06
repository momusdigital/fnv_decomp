
// src/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nigeommorpherupdatetask.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C"
{
    extern const void* g_011f4100;
}
const void* __cdecl FUN_00a56c00();
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
NiGeomMorpherUpdateTask* __cdecl PopMorpherUpdateTask();
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
extern int(__stdcall* DAT_00fdf1c0)(void*);
struct S_00a56c60 : S_00a56c10
{
    void SetRefObjects(NiRefObject* nextFirst, NiRefObject* nextSecond);
};
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
void ResetRegistry();
struct S_00a56f10;
struct S_00a56f10_List
{
    void FindOrAdd(S_00a56f10** pItem);
};
struct S_00a56f10 : S_00a56c10
{
    bool ReleaseReferences();
};
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

struct S_00a56ce0_HeapX
{
    void* FUN_00aa3e40(unsigned int n);
};
extern S_00a56ce0_HeapX DAT_011f6238;
extern "C" void* __cdecl FUN_00aa1420(unsigned int n);

struct MorphTaskArr
{
    void* vptr;
    int _pad[2];
    void* m_pkMorphController;
    void* m_spReferencedObject;

    MorphTaskArr();
    ~MorphTaskArr();

    static void* operator new[](size_t size, unsigned int count);
};

inline void* MorphTaskArr::operator new[](size_t size, unsigned int count)
{
    if (count == 0)
        return DAT_011f6238.FUN_00aa3e40(4);
    return FUN_00aa1420(size);
}

// @fnv 0x00a56ce0
NiGeomMorpherUpdateTask* __cdecl FUN_00a56ce0(unsigned int ItemUpdateArray) throw()
{
    return (NiGeomMorpherUpdateTask*)(new (ItemUpdateArray) MorphTaskArr[ItemUpdateArray]);
}

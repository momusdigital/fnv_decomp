// fallout/misc/garbagecollector.cpp: GarbageCollector (22 functions)

#include "garbagecollector_packet.h"
#include "original_garbagecollector.h"

const char kGarbageCollectorRemoveLabel[] = "GarbageCollector::Remove(TESObjectREFR)";

// Locks the garbage collector, removes the reference from both garbage lists if present, then unlocks it.
// @fnv 0x00868270
void GarbageCollector::Remove(TESObjectREFR* reference)
{
    LockGarbageCollector(kGarbageCollectorRemoveLabel, true);
    unsigned int size = ms_kReferencesQueuedForRemoval.GetSize();
    for (unsigned int index = 0; index < size; ++index)
    {
        if (ms_kReferencesQueuedForRemoval.GetAt(index) == reference)
        {
            ms_kReferencesQueuedForRemoval.RemoveAtAndFill(index);
            break;
        }
    }
    size = ObjectGarbageB.GetSize();
    for (unsigned int index = 0; index < size; ++index)
    {
        if (ObjectGarbageB.GetAt(index) == reference)
        {
            ObjectGarbageB.RemoveAtAndFill(index);
            break;
        }
    }
    UnlockGarbageCollector(true);
}

// @fnv 0x0040fc90
void GarbageCollector::QueryCurrentThread(bool)
{
    GetCurrentThreadId();
}

const char kGarbageCollectorClearTempEffectsLabel[] = "GarbageCollector::ClearTempEffects()";
// @fnv 0x00868d10
void GarbageCollector::ClearTempEffects()
{
    if (g_011de828.GetSize() && g_modelLoader->FUN_00868250())
    {
        LockGarbageCollector(kGarbageCollectorClearTempEffectsLabel, true);
        g_011de828.RemoveAll();
        g_modelLoader->FUN_004aaf10();
        UnlockGarbageCollector(true);
    }
}

const char kGarbageCollectorUpdateLabel[] = "GarbageCollector::Update()";
// @fnv 0x00868850
void GarbageCollector::Update()
{
    LockGarbageCollector(kGarbageCollectorUpdateLabel, true);
    struct QueueBudget
    {
        unsigned int multiplier;
        unsigned int size;
        unsigned int remaining;
    } budget;
    budget.size = 0;
    budget.remaining = 0;
    budget.multiplier = 1;
    if (FUN_00446ef0()->FUN_00878360())
        budget.multiplier = 2;
    if (g_011de808.GetSize())
    {
        if (g_modelLoader->FUN_00868250())
        {
            budget.size = g_011de808.GetSize();
            budget.remaining = budget.multiplier * 10;
            while (budget.size && budget.remaining)
            {
                --budget.size;
                --budget.remaining;
                GarbageCollectorDeleteA* object = g_011de808.GetAt(budget.size);
                g_011de808.RemoveAt(budget.size);
                delete object;
            }
            g_modelLoader->FUN_004aaf10();
        }
    }
    else if (g_011de910.GetSize())
    {
        if (g_modelLoader->FUN_00868250())
        {
            budget.size = g_011de910.GetSize();
            budget.remaining = budget.multiplier * 10;
            while (budget.size && budget.remaining)
            {
                --budget.size;
                --budget.remaining;
                GarbageCollectorDeleteB* object = g_011de910.GetAt(budget.size);
                g_011de910.RemoveAt(budget.size);
                delete object;
            }
            g_modelLoader->FUN_004aaf10();
        }
    }
    else if (g_011de838.GetSize())
    {
        ForEachNavMesh(&g_011de838, &g_011de910);
        g_011de838.RemoveAll();
    }
    else if (g_011de888.GetSize())
    {
        budget.size = g_011de888.GetSize();
        budget.remaining = budget.multiplier * 10;
        while (budget.size && budget.remaining)
        {
            --budget.size;
            --budget.remaining;
            GarbageCollectorObjectPtr object = g_011de888.RemoveAt(budget.size);
            if (object.FUN_0052aa80(0))
                object.object->RemoveGarbageMark();
        }
    }
    else if (g_011de848.GetSize())
    {
        FUN_00869420(&g_011de848, &g_011de888);
        g_011de848.RemoveAll();
    }
    else if (ms_kReferencesQueuedForRemoval.GetSize())
    {
        if (g_modelLoader->FUN_00868250())
        {
            budget.size = ms_kReferencesQueuedForRemoval.GetSize();
            budget.remaining = budget.multiplier * 20;
            unsigned int special = 1;
            while (budget.size && budget.remaining && special)
            {
                --budget.size;
                --budget.remaining;
                TESObjectREFR* object = ms_kReferencesQueuedForRemoval.GetAt(0);
                if (object->vfn_100() || object->FUN_00564d80())
                    --special;
                delete object;
            }
            g_modelLoader->FUN_004aaf10();
        }
    }
    else if (ObjectGarbageB.GetSize())
    {
        ForEachNavMesh(&ObjectGarbageB, &ms_kReferencesQueuedForRemoval);
        reinterpret_cast<NiTPrimitiveArray_unsigned_int_*>(&ObjectGarbageB)->RemoveAll();
    }
    else if (g_011de924.GetSize())
    {
        budget.size = g_011de924.GetSize();
        budget.remaining = budget.multiplier * 5;
        while (budget.size && budget.remaining)
        {
            --budget.size;
            --budget.remaining;
            g_011de924.GetAt(0)->debug.FUN_00401970();
            g_011de924.Remove(0, true);
        }
    }
    else if (g_011de898.GetSize())
    {
        CopyNonNullElements(&g_011de898, &g_011de924);
        g_011de898.Clear(true);
    }
    UnlockGarbageCollector(true);
}

struct NavMeshPtr
{
    operator NavMesh*() const;
    NavMesh* FUN_00458b50();
};
struct TwoPointerRecord
{
    TwoPointerRecord(unsigned int, const char*);
    ~TwoPointerRecord();
    unsigned int id;
    unsigned int startTime;
};
extern __declspec(thread) bool DAT_tlsFlag;

// @fnv 0x00868790
void __cdecl AddNavMeshToGarbageCollector(NavMeshPtr& apNavMesh)
{
    TwoPointerRecord tempAutoEvent(0x20, "GarbageCollector::Add(NavMeshPtr)");
    ((NavMesh*)apNavMesh)->debug.FUN_0040f6e0();
    if (DAT_tlsFlag)
    {
        NavMesh* mesh = apNavMesh.FUN_00458b50();
        g_011de924.Add(mesh);
    }
    else
    {
        NavMesh* mesh = apNavMesh.FUN_00458b50();
        g_011de898.Add(mesh);
    }
}

struct Flt
{
    operator unsigned int() const;
};
bool __cdecl FUN_00867f70();
bool __cdecl HasFlags(int);
bool __cdecl BSSpinLockGlobalTryLock();
void __cdecl FUN_00452530();
void FUN_00869560(void*, void*);
extern GlobalObject_00869db0 g_011de858;
extern bool DAT_011de958;
extern __declspec(thread) bool bCollecting;

// @fnv 0x00868d70
void FUN_00868d70(bool abTryLock)
{
    if (DAT_011de958)
        return;
    bool bLocked = true;
    if (abTryLock)
        bLocked = FUN_00867f70();
    else
        LockGarbageCollector("GarbageCollector::ClearAll()", true);
    if (bLocked)
    {
        DAT_011de958 = true;
        bool bWasCollecting = bCollecting;
        bCollecting = false;
        if (!HasFlags(0x10) && BSSpinLockGlobalTryLock())
        {
            g_011de828.RemoveAll();
            FUN_00452530();
        }
        if (!HasFlags(8) && g_modelLoader->FUN_00868250())
        {
            unsigned int icount = g_011de808.GetSize();
            for (unsigned int i = 0; i < icount; i++)
            {
                GarbageCollectorDeleteA* pobject = g_011de808.GetAt(i);
                delete pobject;
            }
            g_011de808.RemoveAll();
            g_modelLoader->FUN_004aaf10();
        }
        if (!HasFlags(4) && g_modelLoader->FUN_00868250())
        {
            unsigned int icount = g_011de910.GetSize();
            for (unsigned int i = 0; i < icount; i++)
            {
                GarbageCollectorDeleteB* pobject = g_011de910.GetAt(i);
                delete pobject;
            }
            g_011de910.RemoveAll();
            g_modelLoader->FUN_004aaf10();
        }
        if (!HasFlags(2))
        {
            for (unsigned int i = 0; i < g_011de888.GetSize(); i++)
            {
                if ((const Flt&)g_011de888.GetAt(i))
                    g_011de888.GetAt(i).object->RemoveGarbageMark();
            }
            g_011de888.RemoveAll();
        }
        if (!HasFlags(1) && g_modelLoader->FUN_00868250())
        {
            while (GarbageCollector::ms_kReferencesQueuedForRemoval.GetSize())
            {
                TESObjectREFR* pref = GarbageCollector::ms_kReferencesQueuedForRemoval.GetAt(0);
                delete pref;
            }
            ((NiTPrimitiveArray_unsigned_int_*)&GarbageCollector::ms_kReferencesQueuedForRemoval)->RemoveAll();
            g_modelLoader->FUN_004aaf10();
        }
        if (!HasFlags(0x20))
        {
            for (unsigned int i = 0; i < g_011de924.GetSize(); i++)
                g_011de924.GetAt(i)->debug.FUN_00401970();
            g_011de924.Clear(true);
        }
        bCollecting = bWasCollecting;
        if (bCollecting)
        {
            ForEachNavMesh(&GarbageCollector::ObjectGarbageB, &GarbageCollector::ms_kReferencesQueuedForRemoval);
            ((NiTPrimitiveArray_unsigned_int_*)&GarbageCollector::ObjectGarbageB)->RemoveAll();
            FUN_00869420(&g_011de848, &g_011de888);
            g_011de848.RemoveAll();
            ForEachNavMesh(&g_011de838, &g_011de910);
            g_011de838.RemoveAll();
            FUN_00869560(&g_011de858, &g_011de828);
            g_011de858.RemoveAll();
            CopyNonNullElements(&g_011de898, &g_011de924);
            g_011de898.Clear(true);
        }
        DAT_011de958 = false;
        UnlockGarbageCollector(true);
    }
}

struct RecursiveSpinLock
{
    void __thiscall Lock(const char*);
};

struct GlobalObject_0096a2d0
{
    void __thiscall Lock(const char*);
};

extern GlobalObject_0096a2d0 g_011de8e0;

// @fnv 0x00867f50
void __cdecl LockGlobalObject(const char* apLabel)
{
    g_011de8e0.Lock(apLabel);
}

namespace fnv_00867f70 {
struct RecursiveSpinLock
{
    bool TryLock();
};
extern RecursiveSpinLock g_011de8e0;
// @fnv 0x00867f70
bool __cdecl FUN_00867f70()
{
    return g_011de8e0.TryLock();
}
}  // namespace fnv_00867f70

namespace fnv_00867f80 {
struct RecursiveSpinLock
{
    void Unlock();
};

struct GlobalObject_0096a2d0
{
    RecursiveSpinLock lock;
};

extern GlobalObject_0096a2d0 g_011de8e0;

// @fnv 0x00867f80
void FUN_00867f80()
{
    g_011de8e0.lock.Unlock();
}
}  // namespace fnv_00867f80

struct FUN_00868210_shell
{
    int m_00;
    unsigned char m_04;
    void ClearBitsAndUnlockGC();
};

extern int DAT_011de804;

// If m_04 is zero, clears the bits of m_00 in DAT_011de804, then unlocks the garbage collector.
// @fnv 0x00868210
void FUN_00868210_shell::ClearBitsAndUnlockGC()
{
    if (m_04 == 0)
    {
        DAT_011de804 = ~m_00 & DAT_011de804;
    }
    UnlockGarbageCollector(false);
}

void __cdecl FUN_00868770(int* a, int b);

struct FUN_00868740_shell
{
    void FUN_00868740();
};

// @fnv 0x00868740
void FUN_00868740_shell::FUN_00868740()
{
    FUN_00868770(reinterpret_cast<int*>(this) + 1, *(reinterpret_cast<int*>(this) + 1) | 0x40000000);
}

struct FUN_008681c0_shell
{
    int m_00;
    unsigned char m_04;
    FUN_008681c0_shell* __thiscall InitFlags(int, const char*);
};
// Stores a in m_00, locks the garbage collector with b, sets m_04 from the overlap of DAT_011de804 and a, then ORs a into DAT_011de804.
// @fnv 0x008681c0
FUN_008681c0_shell* __thiscall FUN_008681c0_shell::InitFlags(int aiFlags, const char* apName)
{
    m_00 = aiFlags;
    LockGarbageCollector(apName, 0);
    m_04 = (DAT_011de804 & aiFlags) != 0;
    DAT_011de804 |= aiFlags;
    return this;
}

struct S_00868ce0
{
    int m_00;
    int m_04;
    void __thiscall FUN_00868ce0();
};
// Clears bit 30 of m_04 and passes the result to FUN_00868770 along with the address of m_04.
// @fnv 0x00868ce0
void __thiscall S_00868ce0::FUN_00868ce0()
{
    FUN_00868770(&m_04, m_04 & 0xBFFFFFFF);
}

struct FUN_008693c0_shell
{
    unsigned char _00[10];
    unsigned short m_0A;
    void __thiscall FUN_00869640(int a, int b);
    void __thiscall FUN_008693c0(int a);
};
// Forwards the value to FUN_00869640 together with the field at offset 0x0A.
// @fnv 0x008693c0
void __thiscall FUN_008693c0_shell::FUN_008693c0(int aiValue)
{
    FUN_00869640(m_0A, aiValue);
}

struct Caller008693c0
{
    void __thiscall FUN_008693c0(NavMesh**);
};
// Iterates over apArray's elements, and for each non-null NavMesh calls apObj->FUN_008693c0 with a pointer to it.
// @fnv 0x008694c0
void __cdecl ForEachNavMesh(GlobalObject_004aff00* apArray, Caller008693c0* apObj)
{
    unsigned int i;
    for (i = 0; i < apArray->GetSize(); i++)
    {
        NavMesh* cur;
        cur = ((GlobalObject_00869f00*)apArray)->GetAt(i);
        if (cur != 0)
        {
            apObj->FUN_008693c0(&cur);
        }
    }
}

struct ProxyArray
{
    NavMesh*& __thiscall FUN_006a7ad0(unsigned int);
};
// Iterates over a's elements, retrieves each NavMesh via FUN_006a7ad0, and adds the non-null ones to b.
// @fnv 0x00869510
void CopyNonNullElements(GlobalObject_00869f00* apSource, GlobalObject_00869f00* apDest)
{
    unsigned int i;
    for (i = 0; i < apSource->GetSize(); i++)
    {
        NavMesh* v;
        v = ((ProxyArray*)apSource)->FUN_006a7ad0(i);
        if (v)
            apDest->Add(v);
    }
}

struct FUN_0050f5a0_struct
{
    void FUN_0050f5a0();
};
struct FUN_00572160_shell
{
    void FUN_00572160();
};
// @fnv 0x00572160
void FUN_00572160_shell::FUN_00572160()
{
    unsigned int i;
    unsigned int count = ((GlobalObject_004aff00*)((char*)this + 0x9c))->GetSize();
    for (i = 0; i < count; ++i)
    {
        unsigned int effect = (Flt&)((GlobalObject_00869f00*)((char*)this + 0x9c))->GetAt(i);
        if (effect)
            ((FUN_0050f5a0_struct*)effect)->FUN_0050f5a0();
    }
    ((GlobalObject_004aff00*)((char*)this + 0x9c))->RemoveAll();
}

extern void(__stdcall* DAT_00fdf0e4)(void*, void*);
// @fnv 0x00868770
void __cdecl FUN_00868770(int* a, int b)
{
    DAT_00fdf0e4(a, (void*)b);
}

struct GO
{
    int m_00;
    GO(int);
    ~GO();
};
struct FUN_008693f0_Class
{
    void FUN_008693f0(int);
};
// Constructs a GO from ai and passes it to FUN_008693f0 on g_011de828 or g_011de858 depending on DAT_tlsFlag.
// @fnv 0x00868490
void __cdecl FUN_00868490(int aiEffect)
{
    TwoPointerRecord e(0x10, "GarbageCollector::Add(BSTempEffect)");
    if (DAT_tlsFlag)
    {
        GO p(aiEffect);
        ((FUN_008693f0_Class*)&g_011de828)->FUN_008693f0((int)&p);
    }
    else
    {
        GO p(aiEffect);
        ((FUN_008693f0_Class*)&g_011de858)->FUN_008693f0((int)&p);
    }
}

struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

// @fnv 0x00868560
void __cdecl FUN_00868560(GarbageCollectorDeleteB* apObject)
{
    TwoPointerRecord autoEvent(4, "GarbageCollector::Add(BipedAnim)");

    if (!DAT_tlsFlag || (g_BGSSaveLoadGame != 0 && g_BGSSaveLoadGame->FUN_0042ce10()))
    {
        if (g_modelLoader->FUN_00868250())
        {
            delete apObject;
            g_modelLoader->FUN_004aaf10();
        }
        else
        {
            reinterpret_cast<FUN_008693c0_shell*>(&g_011de838)->FUN_008693c0(reinterpret_cast<int>(&apObject));
        }
    }
    else
    {
        reinterpret_cast<FUN_008693c0_shell*>(&g_011de910)->FUN_008693c0(reinterpret_cast<int>(&apObject));
    }
}

extern GlobalObject_004aff00 g_011de848;
extern GlobalObject_004aff00 g_011de888;

template <> class NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >
{
  public:
    unsigned int Add(const NiPointer<NiAVObject>& object);
};

// Calls FUN_00868740 on apObject if non-null, then adds it to one of two global NiTArray lists depending on bCollecting.
// @fnv 0x00868660
void FUN_00868660(NiAVObject* apObject)
{
    TwoPointerRecord autoEvent(2, "GarbageCollector::Add(NiAVObject)");

    if (apObject)
    {
        reinterpret_cast<FUN_00868740_shell*>(apObject)->FUN_00868740();
    }

    if (bCollecting)
    {
        GO object(reinterpret_cast<int>(apObject));
        reinterpret_cast<NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >*>(&g_011de888)
            ->Add(reinterpret_cast<const NiPointer<NiAVObject>&>(object));
    }
    else
    {
        GO object(reinterpret_cast<int>(apObject));
        reinterpret_cast<NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > >*>(&g_011de848)
            ->Add(reinterpret_cast<const NiPointer<NiAVObject>&>(object));
    }
}

struct AnimationManager
{
    void FUN_0048fef0(float);
};
struct TimeController
{
};
struct SceneObject
{
    TimeController* FUN_00a5c570(const void*);
    void FUN_00a5c480(TimeController*);
};
struct AnimationObject
{
    void ShutdownAllAnimIdles();
    AnimationManager* FUN_00496940();
    SceneObject* FUN_005585e0();
};
struct AnimationLoader
{
    void CancelReplacementKFList(AnimationObject*);
};
struct AnimationQueue
{
    void FUN_008693c0(AnimationObject**);
};
extern int DAT_011f36bc;
extern int g_011f36e4;
// @fnv 0x00868330
void AddAnimationToGarbageCollector(AnimationObject* object)
{
    TwoPointerRecord event(8, "GarbageCollector::Add(Animation)");
    object->ShutdownAllAnimIdles();
    if (object->FUN_00496940())
        object->FUN_00496940()->FUN_0048fef0(0.0f);
    SceneObject* pRoot = object->FUN_005585e0();
    if (pRoot)
    {
        TimeController* controller = pRoot->FUN_00a5c570(&DAT_011f36bc);
        if (controller)
            pRoot->FUN_00a5c480(controller);
        controller = pRoot->FUN_00a5c570(&g_011f36e4);
        if (controller)
            pRoot->FUN_00a5c480(controller);
    }
    ((AnimationLoader*)g_modelLoader)->CancelReplacementKFList(object);
    if (!DAT_tlsFlag || (g_BGSSaveLoadGame && g_BGSSaveLoadGame->FUN_0042ce10()))
    {
        delete (GarbageCollectorDeleteA*)object;
    }
    else
    {
        ((AnimationQueue*)&g_011de808)->FUN_008693c0(&object);
    }
}

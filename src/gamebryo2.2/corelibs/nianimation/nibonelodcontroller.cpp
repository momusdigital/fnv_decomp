
// src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl _NiFreeAlias(void*);
extern int DAT_0109a2a4;

struct FUN_00a543f0_shell
{
    void* m_kPointA;
    void* m_ptr;
    void FUN_00a543f0();
};

// @fnv 0x00a543f0
void FUN_00a543f0_shell::FUN_00a543f0()
{
    void* p = m_ptr;
    m_kPointA = &DAT_0109a2a4;
    _NiFreeAlias(p);
}

struct GlobalObjectO2_00a7b610
{
};

extern GlobalObjectO2_00a7b610 g_011f405c;

// @fnv 0x00a55120
GlobalObjectO2_00a7b610* __cdecl FUN_00a55120()
{
    return &g_011f405c;
}

struct NiTMapBaseStub
{
    void RemoveAll();
};
extern int DAT_0109a264;
extern int DAT_0109a284;
struct P03MM
{
    void Deallocate(void*);
};
extern P03MM g_memoryManager;
struct FUN_00a54370_shell : NiTMapBaseStub
{
    void* m_kPointA;
    void* m_auiShapeKeys;
    void* m_ptr;
    FUN_00a54370_shell* FUN_00a54370(bool);
};
// Resets the two map bases, frees m_ptr, and optionally deallocates the object via g_memoryManager, returning this.
// @fnv 0x00a54370
FUN_00a54370_shell* FUN_00a54370_shell::FUN_00a54370(bool abFree)
{
    m_kPointA = &DAT_0109a284;
    RemoveAll();
    m_kPointA = &DAT_0109a264;
    RemoveAll();
    _NiFreeAlias(m_ptr);
    if (abFree & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct NiStreamLinkIDSet
{
    void* m_kPointA;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;
    void Realloc(unsigned int);
};

struct NiStreamLinkIDSetShell
{
    void AppendLinkID(unsigned int* value);
};

// Grows the set's storage when full, then stores the given value at the end and increments the count.
// @fnv 0x00a543b0
void NiStreamLinkIDSetShell::AppendLinkID(unsigned int* value)
{
    NiStreamLinkIDSet* set = reinterpret_cast<NiStreamLinkIDSet*>(this);
    if (set->m_pRayCursor == set->m_uiItemCount)
    {
        unsigned int size = set->m_uiItemCount;
        if (size > 0)
            size *= 2;
        else
            size = 1;
        set->Realloc(size);
    }
    unsigned int* puiData = reinterpret_cast<unsigned int*>(set->m_kPointA);
    puiData[set->m_pRayCursor] = *value;
    set->m_pRayCursor++;
}

namespace fnv_00a54410 {
extern int DAT_0109a2ac;
struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00a54410_shell
{
    void* m_kPointA;
    void* m_ptr;
    void* FreeAndMaybeDeallocate(unsigned int);
};
// @fnv 0x00a54410
void* FUN_00a54410_shell::FreeAndMaybeDeallocate(unsigned int flags)
{
    void* tmp = m_ptr;
    m_kPointA = (void*)&DAT_0109a2ac;
    _NiFreeAlias(tmp);
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}
}  // namespace fnv_00a54410

struct CloningProcess;
struct NiObject
{
};
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct NiBoneLODController : public NiObject
{
    char m_auiShapeKeys[0x34];
    int m_iLOD;
    unsigned int m_uiNumLODs;
    NiBoneLODController* FUN_00a550b0();
    void FUN_00a6cfe0(NiBoneLODController*, CloningProcess*);
    NiBoneLODController* CreateClone(CloningProcess&);
};
// @fnv 0x00a552c0
NiBoneLODController* NiBoneLODController::CreateClone(CloningProcess& kCloning)
{
    NiBoneLODController* pkObject = static_cast<NiBoneLODController*>(BSFadeNode::operator new(0x68));
    if (pkObject)
        pkObject = pkObject->FUN_00a550b0();
    else
        pkObject = 0;
    FUN_00a6cfe0(pkObject, &kCloning);
    pkObject->m_iLOD = m_iLOD;
    pkObject->m_uiNumLODs = m_uiNumLODs;
    return pkObject;
}

namespace fnv_00a553f0 {
extern int DAT_0109a2ac;
extern int DAT_0109a2d4;
struct S55190
{
    void ClearEntries();
};
struct S6D290
{
    void FUN_00a6d290();
};
void _delete(void*, unsigned int);
struct NiBoneLODController
{
    void* FUN_00a553f0(unsigned int);
};
// @fnv 0x00a553f0
void* NiBoneLODController::FUN_00a553f0(unsigned int flags)
{
    *(void**)this = (void*)&DAT_0109a2d4;
    ((S55190*)this)->ClearEntries();
    _NiFreeAlias(*(void**)((char*)this + 0x5c));
    void* p1 = *(void**)((char*)this + 0x50);
    *(void**)((char*)this + 0x4c) = (void*)&DAT_0109a2ac;
    _NiFreeAlias(p1);
    void* p2 = *(void**)((char*)this + 0x40);
    *(void**)((char*)this + 0x3c) = (void*)&DAT_0109a2a4;
    _NiFreeAlias(p2);
    ((S6D290*)this)->FUN_00a6d290();
    if (flags & 1)
        _delete(this, 0x68);
    return this;
}
}  // namespace fnv_00a553f0

namespace fnv_00a54340 {
struct NiStream;
struct NiObject
{
    virtual void LinkObject(NiStream&);
};
struct NiBoneLODController : NiObject
{
    unsigned char _pad[0x30];
    int m_iLOD;
    void FUN_00a541f0(int);
    void FUN_00a54340(NiStream&);
};
// Calls NiObject::LinkObject, saves m_iLOD, sets m_iLOD to -1, then passes the saved value to FUN_00a541f0.
// @fnv 0x00a54340
void NiBoneLODController::FUN_00a54340(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    int iLOD = m_iLOD;
    m_iLOD = -1;
    FUN_00a541f0(iLOD);
}
}  // namespace fnv_00a54340

namespace fnv_00a55130 {
struct NiRTTI
{
    const char* m_pcName;
    NiRTTI* m_pBaseRTTI;
};
extern NiRTTI DAT_011f4428;
struct TargetObj
{
    virtual void f0();
    virtual void f1();
    virtual NiRTTI* GetRTTI() const;
};
struct NiBoneLODController
{
    char _pad[0x2c];
    TargetObj* m_target;
    bool IsTargetOfType() const;
};
// Checks whether m_target's RTTI chain contains DAT_011f4428, returning false if m_target or its RTTI is null.
// @fnv 0x00a55130
bool NiBoneLODController::IsTargetOfType() const
{
    TargetObj* pkTarget = m_target;
    if (!pkTarget)
        return false;
    NiRTTI* pkRTTI = pkTarget->GetRTTI();
    if (!pkRTTI)
        return false;
    do
    {
        if (pkRTTI == &DAT_011f4428)
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    } while (pkRTTI);
    return false;
}
}  // namespace fnv_00a55130

namespace fnv_00a55160 {
struct NiUpdateData
{
};
extern int DAT_011a90c4;
struct NiBoneLODController
{
    char _pad[0x34];
    int m_iLOD;
    int m_uiNumLODs;
    void FUN_00a541f0(int);
    void UpdateLOD(NiUpdateData&);
};
// Clamps the global LOD value to the controller's LOD count and, if it differs from the current LOD, applies it via FUN_00a541f0.
// @fnv 0x00a55160
void NiBoneLODController::UpdateLOD(NiUpdateData& UpdateData)
{
    int iNewLOD = DAT_011a90c4;
    if (iNewLOD == -1)
        return;
    if (iNewLOD == m_iLOD)
        return;
    if (iNewLOD > m_uiNumLODs)
        iNewLOD = m_uiNumLODs - 1;
    if (iNewLOD == m_iLOD)
        return;
    FUN_00a541f0(iNewLOD);
}
}  // namespace fnv_00a55160

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

// @fnv 0x00a55300
NiBoneLODController* CreateBoneLODController()
{
    NiBoneLODController* p = (NiBoneLODController*)A51BF0Base::operator new(0x68);
    if (p)
        return p->FUN_00a550b0();
    return 0;
}

class NiStream;

class NiObjectA53
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual void unkv10();
    virtual void unkv14();
    virtual void unkv18();
    virtual void unkv1C();
    virtual void unkv20();
    virtual void unkv24();
    virtual void unkv28();
    virtual void unkv2C();
    virtual void unkv30();
    virtual void unkv34();
    virtual void unkv38();
    virtual void unkv3C();
    virtual void unkv40();
    virtual void unkv44();
    virtual void unkv48();
    virtual void unkv4C();
    virtual void unkv50();
    virtual bool RegisterStreamables(NiStream& kStream);
};

template <class T> class NiPointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

class NiSkinInstance : public NiObjectA53
{
};

class NiTriBasedGeom;

class GeometrySkinInstancePair
{
  public:
    NiTriBasedGeom* m_pkGeom;
    NiPointer<NiSkinInstance> m_spInstance;
};

template <class T> class NiTPrimitiveSet
{
  public:
    unsigned int GetSize() const
    {
        return m_uiAllocatedCapacity;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }

    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};

typedef NiTPrimitiveSet<GeometrySkinInstancePair*> SkinInfoSet;

template <class T> class NiTPrimitiveArray
{
  public:
    unsigned short GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }

    void* m_vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class NiTimeController : public NiObjectA53
{
  public:
    bool RegisterStreamables(NiStream& kStream);

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
};

class NiBoneLODControllerA53 : public NiTimeController
{
  public:
    bool FUN_00a53d00(NiStream& kStream);

    int m_iLOD;
    unsigned int m_uiNumLODs;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    NiTPrimitiveArray<SkinInfoSet*> m_kSkinInfoSets;
};

// Calls the base RegisterStreamables, then registers the skin instance of every skin info in each LOD skin info set, returning false if the base call fails.
// @fnv 0x00a53d00
bool NiBoneLODControllerA53::FUN_00a53d00(NiStream& kStream)
{
    if (!NiTimeController::RegisterStreamables(kStream))
        return false;

    for (unsigned int ui = 0; ui < m_kSkinInfoSets.GetSize(); ui++)
    {
        SkinInfoSet* pkSkinInfoSet = m_kSkinInfoSets.GetAt(ui);
        if (pkSkinInfoSet)
        {
            for (unsigned int uj = 0; uj < pkSkinInfoSet->GetSize(); uj++)
            {
                GeometrySkinInstancePair* pkSkinInfo = pkSkinInfoSet->GetAt(uj);
                if (pkSkinInfo->m_spInstance)
                    pkSkinInfo->m_spInstance->RegisterStreamables(kStream);
            }
        }
    }

    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct RefObject
{
    virtual void UnknownVirtual();
    virtual void Destroy();
    volatile long referenceCount;
};
struct LODNode
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    volatile unsigned int stateFlags;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int unknown90;
    unsigned int unknown94;
    unsigned int unknown98;
    unsigned int unknown9c;
    unsigned int unknowna0;
    unsigned int unknowna4;
    unsigned int unknowna8;
    unsigned int unknownac;
    unsigned int unknownb0;
    unsigned int unknownb4;
    unsigned int unknownb8;
    RefObject* volatile activeReference;
};
struct NodeCollection
{
    LODNode** elements;
    unsigned int capacity;
    unsigned int count;
};
struct LinkPair
{
    LODNode* node;
    RefObject* reference;
};
struct PairCollection
{
    LinkPair** elements;
    unsigned int capacity;
    unsigned int count;
};
struct LODManager : NiBoneLODController
{
    void* unknown3c;
    NodeCollection** nodeGroups;
    unsigned short unknown44;
    unsigned short groupCount;
    void* unknown48;
    void* unknown4c;
    PairCollection** linkGroups;
    void* unknown54;
    void* unknown58;
    LODNode** defaultNodes;
    unsigned int unknown60;
    unsigned int defaultNodeCount;
    bool FUN_00a541f0(int desiredLOD);
};
// Switches the LOD level: toggles stateFlags on group and default nodes, updates link-group references, and stores the new LOD if it differs and is valid.
// @fnv 0x00a541f0
bool LODManager::FUN_00a541f0(int desiredLOD)
{
    if (m_uiNumLODs > 0 && m_iLOD != desiredLOD &&
        (desiredLOD == -1 || (desiredLOD > -1 && (unsigned int)desiredLOD < m_uiNumLODs)))
    {

        bool enableFollowing = false;
        for (unsigned int groupIndex = 0; groupIndex < groupCount; ++groupIndex)
        {
            NodeCollection* group = nodeGroups[groupIndex];
            if (group)
            {
                if (groupIndex == (unsigned int)desiredLOD)
                    enableFollowing = true;
                for (unsigned int i = 0; i < group->count; ++i)
                {
                    LODNode* node = group->elements[i];
                    if (enableFollowing)
                        node->stateFlags |= 2;
                    else
                        node->stateFlags &= ~2u;
                }
            }
        }

        for (unsigned int i = 0; i < defaultNodeCount; ++i)
        {
            LODNode* node = defaultNodes[i];
            node->stateFlags = (node->stateFlags & ~2u) | 1u;
        }

        if (desiredLOD != -1)
        {
            PairCollection* group = linkGroups[desiredLOD];
            if (group)
            {
                for (unsigned int i = 0; i < group->count; ++i)
                {
                    LODNode* node = group->elements[i]->node;
                    node->stateFlags = (node->stateFlags & ~1u) | 2u;
                    RefObject* newRef = group->elements[i]->reference;
                    RefObject* oldRef = node->activeReference;
                    if (oldRef != newRef)
                    {
                        if (oldRef && InterlockedDecrement(&oldRef->referenceCount) == 0)
                            oldRef->Destroy();
                        node->activeReference = newRef;
                        if (newRef)
                            InterlockedIncrement(&newRef->referenceCount);
                    }
                }
            }
        }

        m_iLOD = desiredLOD;
        return true;
    }
    return false;
}

struct MemoryAllocator
{
    void FUN_00aa4060(void* object);
};
extern MemoryAllocator g_011f6238;
extern "C" void __cdecl FUN_00aa10f0(void* object);
extern "C" long __declspec(dllimport) __stdcall InterlockedDecrement(volatile long* addend);

struct RefCounter
{
    virtual void Keep();
    virtual void Release();
    volatile long count;
};

struct FirstEntry
{
    void* allocation;
};

struct NestedEntry
{
    void* object;
    RefCounter* reference;
};
struct EntryGroup
{
    NestedEntry** objects;
    unsigned int reserved;
    unsigned int count;
};

struct FUN_00a55190_owner
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
    FirstEntry** smallEntries;
    unsigned short unk44;
    unsigned short smallCount;
    unsigned short smallCapacity;
    unsigned short unk4a;
    unsigned int unk4c;
    EntryGroup** largeEntries;
    unsigned short unk54;
    unsigned short largeCount;
    unsigned short largeCapacity;
    unsigned short unk5a;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int current;

    void ClearEntries();
};

// Frees every small and large entry, nulls the entry arrays, resets their counts and capacities, and clears current.
// @fnv 0x00a55190
void FUN_00a55190_owner::ClearEntries()
{
    for (unsigned int i = 0; i < smallCount; ++i)
    {
        FirstEntry* entry = smallEntries[i];
        if (entry)
        {
            FUN_00aa10f0(entry->allocation);
            g_011f6238.FUN_00aa4060(entry);
        }
    }
    for (unsigned short i = 0; i < smallCount; ++i)
        smallEntries[i] = 0;
    smallCount = 0;
    smallCapacity = 0;

    for (unsigned int i = 0; i < largeCount; ++i)
    {
        EntryGroup* group = largeEntries[i];
        if (group)
        {
            for (unsigned int j = 0; j < group->count; ++j)
            {
                NestedEntry* object = group->objects[j];
                if (object)
                {
                    RefCounter* reference = object->reference;
                    if (reference && InterlockedDecrement(&reference->count) == 0)
                        reference->Release();
                    g_011f6238.FUN_00aa4060(object);
                }
            }
            FUN_00aa10f0(group->objects);
            g_011f6238.FUN_00aa4060(group);
        }
    }
    for (unsigned short i = 0; i < largeCount; ++i)
        largeEntries[i] = 0;
    largeCount = 0;
    largeCapacity = 0;
    *(volatile unsigned int*)&current = 0;
}

class BA55320StringArray
{
  public:
    virtual ~BA55320StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcA55320ClassName;

char* __cdecl FUN_00a7d330(const char* pcString);
char* __cdecl A55320GetViewerStringInt(const char* pcPrefix, int iValue);
char* __cdecl A55320GetViewerStringUInt(const char* pcPrefix, unsigned int uiValue);

class A55320Object
{
  public:
    void* m_pVtbl;
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
    int m_iLOD;
    unsigned int m_uiNumLODs;

    void AppendViewerStrings(BA55320StringArray* pkStrings);
};

// Appends the class name and formatted m_iLOD and m_uiNumLODs strings to pkStrings.
// @fnv 0x00a55320
void A55320Object::AppendViewerStrings(BA55320StringArray* pkStrings)
{
    pkStrings->Add(FUN_00a7d330(g_pcA55320ClassName));
    pkStrings->Add(A55320GetViewerStringInt("m_iLOD", m_iLOD));
    pkStrings->Add(A55320GetViewerStringUInt("m_uiNumLODs", m_uiNumLODs));
}

class EqObject
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual void unkv10();
    virtual void unkv14();
    virtual void unkv18();
    virtual void unkv1C();
    virtual void unkv20();
    virtual void unkv24();
    virtual void unkv28();
    virtual void unkv2C();
    virtual void unkv30();
    virtual void unkv34();
    virtual void unkv38();
    virtual void unkv3C();
    virtual void unkv40();
    virtual void unkv44();
    virtual void unkv48();
    virtual void unkv4C();
    virtual void unkv50();
    virtual void unkv54();
    virtual void unkv58();
    virtual bool IsEqual(EqObject* pkObject);
};
template <class T> class EqPointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
struct EqSkinInfo
{
    EqObject* m_pkGeom;
    EqPointer<EqObject> m_spInstance;
};
template <class T> class EqPrimitiveSet
{
  public:
    unsigned int GetSize() const
    {
        return m_uiAllocatedCapacity;
    }
    T& GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }

    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};
template <class T> class EqPrimitiveArray
{
  public:
    unsigned short GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }

    void* m_vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
typedef EqPrimitiveSet<EqObject*> EqNodeSet;
typedef EqPrimitiveSet<EqSkinInfo*> EqSkinInfoSet;
class EqTimeController : public EqObject
{
  public:
    bool BaseIsEqual(EqObject* pkObject);

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
};
class EqBoneLODController : public EqTimeController
{
  public:
    bool FUN_00a53ea0(EqObject* pkObject);

    int m_iLOD;
    unsigned int m_uiNumLODs;
    EqPrimitiveArray<EqNodeSet*> m_kBoneSetArray;
    EqPrimitiveArray<EqSkinInfoSet*> m_kSkinInfoSets;
    EqPrimitiveSet<EqObject*> m_kShapeArray;
};

// Compares LOD, LOD counts, node/skin/shape sets and their elements against pkObject after BaseIsEqual, returning false on any mismatch.
// @fnv 0x00a53ea0
bool EqBoneLODController::FUN_00a53ea0(EqObject* pkObject)
{
    if (!BaseIsEqual(pkObject))
        return false;

    EqBoneLODController* pkDest = (EqBoneLODController*)pkObject;

    if (m_iLOD != pkDest->m_iLOD || m_uiNumLODs != pkDest->m_uiNumLODs ||
        m_kBoneSetArray.GetSize() != pkDest->m_kBoneSetArray.GetSize() ||
        m_kSkinInfoSets.GetSize() != pkDest->m_kSkinInfoSets.GetSize() ||
        m_kShapeArray.GetSize() != pkDest->m_kShapeArray.GetSize())
    {
        return false;
    }

    unsigned int ui;
    for (ui = 0; ui < m_kBoneSetArray.GetSize(); ui++)
    {
        EqNodeSet* pkSet = m_kBoneSetArray.GetAt(ui);
        EqNodeSet* pkDestSet = pkDest->m_kBoneSetArray.GetAt(ui);
        if ((pkSet && !pkDestSet) || (!pkSet && pkDestSet))
            return false;
        if (pkSet && pkDestSet)
        {
            if (pkSet->GetSize() != pkDestSet->GetSize())
                return false;
            for (unsigned int uj = 0; uj < pkSet->GetSize(); uj++)
            {
                if (!pkSet->GetAt(uj)->IsEqual(pkDestSet->GetAt(uj)))
                    return false;
            }
        }
    }

    for (ui = 0; ui < m_kSkinInfoSets.GetSize(); ui++)
    {
        EqSkinInfoSet* pkSet = m_kSkinInfoSets.GetAt(ui);
        EqSkinInfoSet* pkDestSet = pkDest->m_kSkinInfoSets.GetAt(ui);
        if ((pkSet && !pkDestSet) || (!pkSet && pkDestSet))
            return false;
        if (pkSet && pkDestSet)
        {
            if (pkSet->GetSize() != pkDestSet->GetSize())
                return false;
            for (unsigned int uj = 0; uj < pkSet->GetSize(); uj++)
            {
                EqSkinInfo* pkInfo = pkSet->GetAt(uj);
                EqSkinInfo* pkDestInfo = pkDestSet->GetAt(uj);
                if (!pkInfo->m_pkGeom->IsEqual(pkDestInfo->m_pkGeom))
                    return false;
                if (!pkInfo->m_spInstance->IsEqual(pkDestInfo->m_spInstance))
                    return false;
            }
        }
    }

    for (ui = 0; ui < m_kShapeArray.GetSize(); ui++)
    {
        if (!m_kShapeArray.GetAt(ui)->IsEqual(pkDest->m_kShapeArray.GetAt(ui)))
            return false;
    }

    return true;
}

void* __cdecl FUN_00aa1070(unsigned int);
void __cdecl FUN_00aa10f0(void*);
struct StreamBinary
{
    unsigned int unknown;
    unsigned int position;
    unsigned int(__cdecl* read)(StreamBinary*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* data, unsigned int size)
    {
        unsigned int amount = read(this, data, size, &size, 1);
        position += amount;
        return amount;
    }
};
struct LODStream
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
    int unk0d8;
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
    StreamBinary* binary;
    void FUN_00a645b0();
    void Read32(void* data)
    {
        StreamBinary* file = binary;
        file->Read(data, 4);
    }
};
struct LODPool
{
    void* FUN_00aa3e40(unsigned int);
};
extern LODPool DAT_011f6238;
template <class T> struct LinkGroup
{
    T* data;
    unsigned int capacity;
    unsigned int count;
    static void* operator new(unsigned int size)
    {
        return DAT_011f6238.FUN_00aa3e40(size);
    }
    LinkGroup() : data(0), capacity(0), count(0)
    {}
    void Reserve(unsigned int size)
    {
        if (size != capacity)
        {
            T* replacement;
            if (size > 0)
            {
                replacement = (T*)FUN_00aa1070(size * sizeof(T));
                for (unsigned int i = 0; i < count; i++)
                    replacement[i] = data[i];
            }
            else
                replacement = 0;
            FUN_00aa10f0(data);
            data = replacement;
            capacity = size;
        }
    }
    void Add(T const& element)
    {
        if (count == capacity)
            Reserve(capacity > 0 ? capacity * 2 : 1);
        data[count] = element;
        count++;
    }
};
struct LinkSkinInfo
{
    void* object;
    void* skin;
    static void* operator new(unsigned int size)
    {
        return DAT_011f6238.FUN_00aa3e40(size);
    }
    LinkSkinInfo() : skin(0)
    {}
};
template <class T> struct LinkGroupArray
{
    void* vtable;
    LinkGroup<T>** data;
    unsigned short capacity, size, used, growBy;
    void FUN_00a90180(unsigned int);
    __forceinline void SetAt(unsigned int index, LinkGroup<T>* const& group)
    {
        if (index >= capacity)
            FUN_00a90180(index + growBy);
        if (index >= size)
        {
            size = (unsigned short)(index + 1);
            if (group)
                used++;
        }
        else
        {
            if (group)
            {
                if (!data[index])
                    used++;
            }
            else if (data[index])
                used--;
        }
        data[index] = group;
    }
};
struct BoneLODLoader
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
    int currentLOD;
    unsigned int lodCount;
    LinkGroupArray<void*> nodeGroups;
    LinkGroupArray<LinkSkinInfo*> skinGroups;
    LinkGroup<void*> extraLinks;
    void FUN_00a6d5e0(LODStream*);
    void ReadFromStream(LODStream*);
};
// Reads the current LOD, LOD count, node groups, skin groups and extra links from the stream, building the group arrays.
// @fnv 0x00a54c40
void BoneLODLoader::ReadFromStream(LODStream* stream)
{
    unsigned int i;
    FUN_00a6d5e0(stream);
    stream->Read32(&currentLOD);
    stream->Read32(&lodCount);
    unsigned int nodeCount = 0;
    stream->Read32(&nodeCount);
    for (i = 0; i < nodeCount; i++)
    {
        LinkGroup<void*>* group = new LinkGroup<void*>;
        nodeGroups.SetAt(i, group);
        unsigned int childCount = 0;
        stream->Read32(&childCount);
        for (unsigned int j = 0; j < childCount; j++)
        {
            void* object = this;
            group->Add(object);
            stream->FUN_00a645b0();
        }
    }
    unsigned int skinCount = 0;
    stream->Read32(&skinCount);
    for (i = 0; i < skinCount; i++)
    {
        LinkGroup<LinkSkinInfo*>* group = new LinkGroup<LinkSkinInfo*>;
        skinGroups.SetAt(i, group);
        unsigned int childCount = 0;
        stream->Read32(&childCount);
        for (unsigned int j = 0; j < childCount; j++)
        {
            LinkSkinInfo* info = new LinkSkinInfo;
            group->Add(info);
            stream->FUN_00a645b0();
            stream->FUN_00a645b0();
        }
    }
    unsigned int extraCount = 0;
    stream->Read32(&extraCount);
    for (i = 0; i < extraCount; i++)
    {
        void* object = this;
        extraLinks.Add(object);
        stream->FUN_00a645b0();
    }
}

namespace fnv_00a549d0 {
struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
template <class T> inline void SerializeValue(NiBinaryStream& binstream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    binstream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}
struct NiStream
{
    virtual void unknownV00();
    virtual void unknownV04();
    virtual void unknownV08();
    virtual void unknownV0c();
    virtual void unknownV10();
    virtual void unknownV14();
    virtual void unknownV18();
    virtual void unknownV1c();
    virtual void unknownV20();
    virtual void unknownV24();
    virtual void unknownV28();
    virtual void unknownV2c();
    virtual void SaveLink(void* object);
    unsigned int unknown004;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    unsigned int unknown018;
    unsigned int unknown01c;
    unsigned int unknown020;
    unsigned int unknown024;
    unsigned int unknown028;
    unsigned int unknown02c;
    unsigned int unknown030;
    unsigned int unknown034;
    unsigned int unknown038;
    unsigned int unknown03c;
    unsigned int unknown040;
    unsigned int unknown044;
    unsigned int unknown048;
    unsigned int unknown04c;
    unsigned int unknown050;
    unsigned int unknown054;
    unsigned int unknown058;
    unsigned int unknown05c;
    unsigned int unknown060;
    unsigned int unknown064;
    unsigned int unknown068;
    unsigned int unknown06c;
    unsigned int unknown070;
    unsigned int unknown074;
    unsigned int unknown078;
    unsigned int unknown07c;
    unsigned int unknown080;
    unsigned int unknown084;
    unsigned int unknown088;
    unsigned int unknown08c;
    unsigned int unknown090;
    unsigned int unknown094;
    unsigned int unknown098;
    unsigned int unknown09c;
    unsigned int unknown0a0;
    unsigned int unknown0a4;
    unsigned int unknown0a8;
    unsigned int unknown0ac;
    unsigned int unknown0b0;
    unsigned int unknown0b4;
    unsigned int unknown0b8;
    unsigned int unknown0bc;
    unsigned int unknown0c0;
    unsigned int unknown0c4;
    unsigned int unknown0c8;
    unsigned int unknown0cc;
    unsigned int unknown0d0;
    unsigned int unknown0d4;
    unsigned int unknown0d8;
    unsigned int unknown0dc;
    unsigned int unknown0e0;
    unsigned int unknown0e4;
    unsigned int unknown0e8;
    unsigned int unknown0ec;
    unsigned int unknown0f0;
    unsigned int unknown0f4;
    unsigned int unknown0f8;
    unsigned int unknown0fc;
    unsigned int unknown100;
    unsigned int unknown104;
    unsigned int unknown108;
    unsigned int unknown10c;
    unsigned int unknown110;
    unsigned int unknown114;
    unsigned int unknown118;
    unsigned int unknown11c;
    unsigned int unknown120;
    unsigned int unknown124;
    unsigned int unknown128;
    unsigned int unknown12c;
    unsigned int unknown130;
    unsigned int unknown134;
    unsigned int unknown138;
    unsigned int unknown13c;
    unsigned int unknown140;
    unsigned int unknown144;
    unsigned int unknown148;
    unsigned int unknown14c;
    unsigned int unknown150;
    unsigned int unknown154;
    unsigned int unknown158;
    unsigned int unknown15c;
    unsigned int unknown160;
    unsigned int unknown164;
    unsigned int unknown168;
    unsigned int unknown16c;
    unsigned int unknown170;
    unsigned int unknown174;
    unsigned int unknown178;
    unsigned int unknown17c;
    unsigned int unknown180;
    unsigned int unknown184;
    unsigned int unknown188;
    unsigned int unknown18c;
    unsigned int unknown190;
    unsigned int unknown194;
    unsigned int unknown198;
    unsigned int unknown19c;
    unsigned int unknown1a0;
    unsigned int unknown1a4;
    unsigned int unknown1a8;
    unsigned int unknown1ac;
    unsigned int unknown1b0;
    unsigned int unknown1b4;
    unsigned int unknown1b8;
    unsigned int unknown1bc;
    unsigned int unknown1c0;
    unsigned int unknown1c4;
    unsigned int unknown1c8;
    unsigned int unknown1cc;
    unsigned int unknown1d0;
    unsigned int unknown1d4;
    unsigned int unknown1d8;
    unsigned int unknown1dc;
    unsigned int unknown1e0;
    unsigned int unknown1e4;
    unsigned int unknown1e8;
    unsigned int unknown1ec;
    unsigned int unknown1f0;
    unsigned int unknown1f4;
    unsigned int unknown1f8;
    unsigned int unknown1fc;
    unsigned int unknown200;
    unsigned int unknown204;
    unsigned int unknown208;
    unsigned int unknown20c;
    unsigned int unknown210;
    unsigned int unknown214;
    unsigned int unknown218;
    unsigned int unknown21c;
    unsigned int unknown220;
    unsigned int unknown224;
    unsigned int unknown228;
    unsigned int unknown22c;
    unsigned int unknown230;
    unsigned int unknown234;
    unsigned int unknown238;
    unsigned int unknown23c;
    unsigned int unknown240;
    unsigned int unknown244;
    unsigned int unknown248;
    unsigned int unknown24c;
    NiBinaryStream* output;
};
struct BaseHack : NiTimeController
{
    virtual void FUN_00a6d730(NiStream& stream);
};
struct BoneLODSerializer : BaseHack
{
    int lod;
    unsigned int lodCount;
    NiTPrimitiveArray<NodeCollection*> nodes;
    NiTPrimitiveArray<PairCollection*> skins;
    NodeCollection defaultNodes;
    virtual void SaveBinary(NiStream& stream);
};
template <class T> inline void SaveStream(NiStream& kStream, const T& value)
{
    SerializeValue(*kStream.output, value);
}
// Serializes the LOD level, node groups, skin groups, and default nodes of a bone LOD entry to the stream.
// @fnv 0x00a549d0
void BoneLODSerializer::SaveBinary(NiStream& stream)
{
    BaseHack::FUN_00a6d730(stream);
    SaveStream(stream, lod);
    SaveStream(stream, lodCount);
    {
        unsigned int uiNumNodeGroups = nodes.GetSize();
        SaveStream(stream, uiNumNodeGroups);
    }
    unsigned int i;
    for (i = 0; i < nodes.GetSize(); i++)
    {
        NodeCollection* pkSet = nodes.GetAt(i);
        if (pkSet)
        {
            unsigned int uiElementCount = pkSet->count;
            SaveStream(stream, uiElementCount);
            for (unsigned int j = 0; j < pkSet->count; j++)
                stream.SaveLink(pkSet->elements[j]);
        }
        else
        {
            unsigned int uiElementCount = 0;
            SaveStream(stream, uiElementCount);
        }
    }
    {
        unsigned int uiNumSkinGroups = skins.GetSize();
        SaveStream(stream, uiNumSkinGroups);
    }
    for (i = 0; i < skins.GetSize(); i++)
    {
        PairCollection* pkSet = skins.GetAt(i);
        if (pkSet)
        {
            unsigned int uiElementCount = pkSet->count;
            SaveStream(stream, uiElementCount);
            for (unsigned int j = 0; j < pkSet->count; j++)
            {
                LinkPair* pkPair = pkSet->elements[j];
                stream.SaveLink(pkPair->node);
                stream.SaveLink(pkPair->reference);
            }
        }
        else
        {
            unsigned int uiElementCount = 0;
            SaveStream(stream, uiElementCount);
        }
    }
    {
        unsigned int uiNumDefaultNodes = defaultNodes.count;
        SaveStream(stream, uiNumDefaultNodes);
    }
    for (i = 0; i < defaultNodes.count; i++)
        stream.SaveLink(defaultNodes.elements[i]);
}
}  // namespace fnv_00a549d0

namespace a550 {
class FUN_00a6d220
{
  public:
    FUN_00a6d220() throw();
    virtual void unk00();
    char unk04[0x30];
};
}
template <class T> class NiTMallocInterfaceA55
{
  public:
    static T* Allocate(unsigned int auiCount) throw();
};
template <class T, class TAlloc> class NiTArrayA55
{
  public:
    NiTArrayA55(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = TAlloc::Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~NiTArrayA55();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
template <class T> class NiTPrimitiveArrayA55 : public NiTArrayA55<T, NiTMallocInterfaceA55<T> >
{
  public:
    NiTPrimitiveArrayA55(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : NiTArrayA55<T, NiTMallocInterfaceA55<T> >(uiMaxSize, uiGrowBy)
    {}
};
template <class T> class NiTPrimitiveSetA55
{
  public:
    NiTPrimitiveSetA55(unsigned int uiInitialSize = 0)
    {
        if (uiInitialSize > 0)
            m_pBase = NiTMallocInterfaceA55<T>::Allocate(uiInitialSize);
        else
            m_pBase = 0;
        m_uiElementCount = uiInitialSize;
        m_uiAllocatedCapacity = 0;
    }
    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};
class NiNodeA55;
class SkinInfoA55;
class NiGeometryA55;
class FUN_00a550b0 : public a550::FUN_00a6d220
{
  public:
    FUN_00a550b0();
    int m_iLOD;
    unsigned int m_uiNumLODs;
    NiTPrimitiveArrayA55<NiTPrimitiveSetA55<NiNodeA55*>*> m_kNodeArray;
    NiTPrimitiveArrayA55<NiTPrimitiveSetA55<SkinInfoA55*>*> m_kSkinInfoSets;
    NiTPrimitiveSetA55<NiGeometryA55*> m_kShaderSet;
};
// Default constructor that initializes m_iLOD to -1 and m_uiNumLODs to 0.
// @fnv 0x00a550b0
FUN_00a550b0::FUN_00a550b0() : m_iLOD(-1), m_uiNumLODs(0)
{}

struct A54440Remap;
struct RefObject;
struct A54440Clonable
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual RefObject* MakeClone(A54440Remap* remap);
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void ProcessClone(A54440Remap* remap);
};
struct A54440Manager;
struct A54440Remap;
struct A54440HashItem
{
    A54440HashItem* next;
    void* source;
    void* replacement;
};
struct A54440Hash
{
    virtual void Unused();
    virtual unsigned int BucketFor(void* source);
    virtual bool Equals(void* source, void* key);
    unsigned int reserved;
    A54440HashItem** buckets;
    __declspec(noinline) bool FUN_00a53c30(A54440Manager* source, A54440Manager** out);
};
struct A54440Remap
{
    A54440Hash* map;
};
struct A54440Heap : MemoryAllocator
{
    void* FUN_00aa3e40(unsigned int bytes);
};
void* __cdecl FUN_00aa1070(unsigned int);
struct A54440PointerGroup
{
    static void* operator new(unsigned int bytes)
    {
        return ((A54440Heap*)&g_011f6238)->FUN_00aa3e40(bytes);
    }
    A54440PointerGroup() : elements(0), capacity(0), count(0)
    {}
    void** elements;
    unsigned int capacity;
    unsigned int count;
    void FUN_00a311e0(unsigned int nextCapacity);
    void Append(void* item)
    {
        if (count == capacity)
            FUN_00a311e0(capacity > 0 ? capacity * 2 : 1);
        elements[count++] = item;
    }
};
struct A54440Link
{
    void* data;
    RefObject* ref;
};
struct A54440GrowGroup
{
    void** elements;
    unsigned int capacity;
    unsigned int count;
    __forceinline void Append(void* item)
    {
        if (count == capacity)
        {
            unsigned int newCapacity = 2 * (capacity);
            if (!(capacity > 0))
                newCapacity = 1;
            if (newCapacity != capacity)
            {
                void** newData;
                if (newCapacity > 0)
                {
                    newData = (void**)FUN_00aa1070(newCapacity * 4);
                    for (unsigned int j = 0; j < count; j++)
                        newData[j] = elements[j];
                }
                else
                    newData = 0;
                FUN_00aa10f0(elements);
                elements = newData;
                capacity = newCapacity;
            }
        }
        elements[(count)++] = item;
    }
};
struct A54440LinkGroup
{
    static void* operator new(unsigned int bytes)
    {
        return ((A54440Heap*)&g_011f6238)->FUN_00aa3e40(bytes);
    }
    A54440LinkGroup() : entries(0), capacity(0), count(0)
    {}
    __forceinline void Append(A54440Link* item)
    {
        if (count == capacity)
        {
            unsigned int newCapacity = 2 * (capacity);
            if (!(capacity > 0))
                newCapacity = 1;
            if (newCapacity != capacity)
            {
                A54440Link** newData;
                if (newCapacity > 0)
                {
                    newData = (A54440Link**)FUN_00aa1070(newCapacity * 4);
                    for (unsigned int j = 0; j < count; j++)
                        newData[j] = entries[j];
                }
                else
                    newData = 0;
                FUN_00aa10f0(entries);
                entries = newData;
                capacity = newCapacity;
            }
        }
        entries[(count)++] = item;
    }
    A54440Link** entries;
    unsigned int capacity;
    unsigned int count;
};
struct A54440Array
{
    void* vtable;
    void** elements;
    unsigned short capacity;
    unsigned short count;
    unsigned short elementSize;
    unsigned short growBy;
    void FUN_00a90180(unsigned int);
    void FUN_00ba3aa0(unsigned int, void* const*);
    void SetCloneGroup(unsigned int index, void* const& ptr)
    {
        if (index >= capacity)
            FUN_00a90180(index + growBy);
        FUN_00ba3aa0(index, &ptr);
    }
    __forceinline void SetAtGrow(unsigned int index, void* value)
    {
        if (index >= capacity)
            FUN_00a90180(index + growBy);
        if (index >= count)
        {
            count = (unsigned short)(index + 1);
            if (value)
                ++elementSize;
        }
        else
        {
            if (value)
            {
                if (!elements[index])
                    ++elementSize;
            }
            else if (elements[index])
                --elementSize;
        }
        elements[index] = value;
    }
};
struct A54440Manager
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
    int currentLOD;
    unsigned int numLODs;
    A54440Array groups;
    A54440Array links;
    A54440GrowGroup defaults;
    void FUN_00a6d0c0(A54440Remap* source);
    bool FUN_00a541f0(int newLOD);
    void CloneFrom(A54440Remap* source);
};
struct A54440RefSlots
{
    void* vtable;
    volatile long referenceCount;
};
static A54440HashItem* A54440Find(A54440Hash* hash, void* key)
{
    for (A54440HashItem* item = hash->buckets[hash->BucketFor(key)]; item; item = item->next)
    {
        if (hash->Equals(key, item->source))
            return item;
    }
    return 0;
}
static void* A54440Map(A54440Hash* hash, void* key)
{
    A54440HashItem* item = A54440Find(hash, key);
    return item ? item->replacement : key;
}
struct A54440SourceLink
{
    static void* operator new(unsigned int bytes)
    {
        return ((A54440Heap*)&g_011f6238)->FUN_00aa3e40(bytes);
    }
    A54440SourceLink() : ref(0)
    {}
    void* source;
    RefObject* ref;
};
typedef RefObject*(__thiscall* A54440CopyRef)(RefObject*, A54440Remap*);
typedef void(__thiscall* A54440FinishRef)(RefObject*, A54440Remap*);
static RefObject* A54440Copy(RefObject* ref, A54440Remap* ctx)
{
    return ((A54440Clonable*)ref)->MakeClone(ctx);
}
static void A54440Finish(RefObject* ref, A54440Remap* ctx)
{
    ((A54440Clonable*)ref)->ProcessClone(ctx);
}

__declspec(noinline) bool A54440Hash::FUN_00a53c30(A54440Manager* source, A54440Manager** out)
{
    A54440HashItem* item = A54440Find(this, source);
    if (item)
    {
        *out = (A54440Manager*)item->replacement;
        return true;
    }
    return false;
}

static __forceinline bool A54440Lookup(A54440Hash* hash, void* key, void*& replacement)
{
    A54440HashItem* entry = A54440Find(hash, key);
    if (entry)
    {
        replacement = entry->replacement;
        return true;
    }
    return false;
}

__declspec(noinline) void A54440Array::FUN_00ba3aa0(unsigned int index, void* const* pvalue)
{
    void* value = *pvalue;
    if (index >= count)
    {
        count = (unsigned short)(index + 1);
        if (value)
            ++elementSize;
    }
    else
    {
        if (value)
        {
            if (!elements[index])
                ++elementSize;
        }
        else if (elements[index])
            --elementSize;
    }
    elements[index] = value;
}

struct A54440CloneWork
{
    A54440Manager* clone;
    union
    {
        unsigned int boneIndex;
        A54440SourceLink* skinSource;
    };
    union
    {
        void* boneValue;
        unsigned int skinIndex;
    };
    union
    {
        A54440Array* boneArray;
        A54440LinkGroup* skinSet;
    };
};

// Copies this manager's groups, links, and defaults into its mapped clone, applying mapped references where available.
// @fnv 0x00a54440
void A54440Manager::CloneFrom(A54440Remap* remap)
{
    unsigned int i;
    FUN_00a6d0c0(remap);
    A54440CloneWork work;
    remap->map->FUN_00a53c30(this, &work.clone);
    i = 0;
    if (i < groups.count)
    {
        work.boneArray = &work.clone->groups;
        do
        {
            A54440PointerGroup* boneSource = (A54440PointerGroup*)groups.elements[i];
            if (boneSource)
            {
                A54440PointerGroup* dst = new A54440PointerGroup;
                work.boneValue = dst;
                work.boneArray->SetCloneGroup(i, work.boneValue);
                for (work.boneIndex = 0; work.boneIndex < boneSource->count; work.boneIndex++)
                {
                    void* item = boneSource->elements[work.boneIndex];
                    A54440HashItem* entry = A54440Find(remap->map, item);
                    if (entry)
                        dst->Append(entry->replacement);
                    else
                        dst->Append(item);
                }
            }
            else
            {
                work.boneValue = 0;
                work.boneArray->SetCloneGroup(i, work.boneValue);
            }
        } while (++i < groups.count);
    }
    for (i = 0; i < links.count; i++)
    {
        work.skinSet = (A54440LinkGroup*)links.elements[i];
        if (work.skinSet)
        {
            A54440LinkGroup* dst = new A54440LinkGroup;
            work.clone->links.SetAtGrow(i, dst);
            for (work.skinIndex = 0; work.skinIndex < work.skinSet->count; work.skinIndex++)
            {
                work.skinSource = (A54440SourceLink*)work.skinSet->entries[work.skinIndex];
                A54440SourceLink* skinCopy = new A54440SourceLink;
                dst->Append((A54440Link*)skinCopy);
                void* mapped;
                if (A54440Lookup(remap->map, work.skinSource->source, mapped))
                    skinCopy->source = mapped;
                else
                    skinCopy->source = work.skinSource->source;
                RefObject* newRef = A54440Copy(work.skinSource->ref, remap);
                if (skinCopy->ref != newRef)
                {
                    RefObject* oldRef = skinCopy->ref;
                    if (oldRef)
                    {
                        if (InterlockedDecrement(&oldRef->referenceCount) == 0)
                            oldRef->Destroy();
                    }
                    skinCopy->ref = newRef;
                    if (newRef)
                        InterlockedIncrement(&newRef->referenceCount);
                }
                A54440Finish(work.skinSource->ref, remap);
            }
        }
        else
        {
            work.clone->links.SetAtGrow(i, 0);
        }
    }

    for (i = 0; i < defaults.count; i++)
    {
        void* node = defaults.elements[i];
        A54440HashItem* entry = A54440Find(remap->map, node);
        if (entry)
            work.clone->defaults.Append(entry->replacement);
        else
            work.clone->defaults.Append(node);
    }
    int lod = work.clone->currentLOD;
    work.clone->currentLOD = -1;
    work.clone->FUN_00a541f0(lod);
}

namespace fnv_00a53d70 {
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct NiStream
{
    void* GetLoadedObject();
};

struct NiRefObject
{
    virtual ~NiRefObject();
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

struct NiTriBasedGeom;
struct NiNode;
struct NiSkinInstance : NiRefObject
{
};

template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer& operator=(T* p)
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
};

template <class T> struct NiTPrimitiveSet
{
    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    unsigned int GetSize() const
    {
        return m_uiAllocatedCapacity;
    }
    T GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    void ReplaceAt(unsigned int i, T e)
    {
        if (i >= m_uiAllocatedCapacity)
            return;
        m_pBase[i] = e;
    }
};

template <class T> struct NiTArrayStub
{
    void* vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned short GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
};

struct GeometrySkinInstancePair
{
    NiTriBasedGeom* m_pkGeom;
    NiPointer<NiSkinInstance> m_spInstance;
};

struct NiTimeControllerStub
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
    void LinkObject(NiStream& kStream);
};

struct BoneLODCtrl : NiTimeControllerStub
{
    int m_iLOD;
    unsigned int m_uiNumLODs;
    NiTArrayStub<NiTPrimitiveSet<NiNode*>*> m_kBoneSetArray;
    NiTArrayStub<NiTPrimitiveSet<GeometrySkinInstancePair*>*> m_kSkinInfoSets;
    NiTPrimitiveSet<NiTriBasedGeom*> m_kShapeGroups;
    void FUN_00a53d70(NiStream& kStream);
};

// Calls the base LinkObject, then loads objects into bone sets, skin pair fields, and shape groups.
// @fnv 0x00a53d70
void BoneLODCtrl::FUN_00a53d70(NiStream& kStream)
{
    NiTimeControllerStub::LinkObject(kStream);

    unsigned int i;
    for (i = 0; i < m_kBoneSetArray.GetSize(); i++)
    {
        NiTPrimitiveSet<NiNode*>* pkBones = m_kBoneSetArray.GetAt(i);
        if (pkBones)
        {
            for (unsigned int j = 0; j < pkBones->GetSize(); j++)
                pkBones->ReplaceAt(j, (NiNode*)kStream.GetLoadedObject());
        }
    }

    for (i = 0; i < m_kSkinInfoSets.GetSize(); i++)
    {
        NiTPrimitiveSet<GeometrySkinInstancePair*>* pkSkins = m_kSkinInfoSets.GetAt(i);
        if (pkSkins)
        {
            for (unsigned int j = 0; j < pkSkins->GetSize(); j++)
            {
                GeometrySkinInstancePair* pkInfo = pkSkins->GetAt(j);
                pkInfo->m_pkGeom = (NiTriBasedGeom*)kStream.GetLoadedObject();
                pkInfo->m_spInstance = (NiSkinInstance*)kStream.GetLoadedObject();
            }
        }
    }

    for (i = 0; i < m_kShapeGroups.GetSize(); i++)
        m_kShapeGroups.ReplaceAt(i, (NiTriBasedGeom*)kStream.GetLoadedObject());
}
}  // namespace fnv_00a53d70

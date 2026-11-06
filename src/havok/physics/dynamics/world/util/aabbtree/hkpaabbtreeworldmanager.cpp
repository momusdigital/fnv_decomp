
// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl Deallocate(void*);
extern "C" void* DAT_010ccf7c;

struct FUN_00d08330 {
    void* m_p;
    FUN_00d08330(char);
};

// @fnv 0x00d08330
FUN_00d08330::FUN_00d08330(char acFlags)
{
    m_p = &DAT_010ccf7c;
    if (acFlags & 1)
        Deallocate(this);
}

extern int DAT_010ccf8c;
extern void __cdecl Deallocate(void*);

struct FUN_00d08350 {
    void* m_p;
    void* __thiscall Set(void* arg);
};

// Stores the address of DAT_010ccf8c into m_p and, if arg's low bit is set, deallocates self before returning it.
// @fnv 0x00d08350
void* __thiscall FUN_00d08350::Set(void* arg)
{
    void* self = this;
    m_p = &DAT_010ccf8c;
    if ((int)arg & 1)
        Deallocate(self);
    return self;
}

struct FUN_00d083a0_class {
    void __thiscall setWorkingBuffer(int a);
};

// @fnv 0x00d083a0
void __thiscall FUN_00d083a0_class::setWorkingBuffer(int aiValue)
{
    *(int*)((char*)this + 0x30) = aiValue;
    *(int*)((char*)this + 0x34) = (*(int*)((char*)this + 0x38) << 4) + aiValue;
}

struct FUN_00d08ff0_t {
    int a;
    int b;
    int c;
    int d;
    void FUN_00d08ac0(int);
    void FUN_00d08b90(int);
};
void FUN_00d08ac0(FUN_00d08ff0_t* self, int arg);
void FUN_00d08b90(FUN_00d08ff0_t* self, int arg);
// Clears self->b, then calls FUN_00d08ac0 and FUN_00d08b90 with self and arg.
// @fnv 0x00d08ff0
void FUN_00d08ff0(FUN_00d08ff0_t* self, int arg)
{
    self->b = 0;
    FUN_00d08ac0(self, arg);
    FUN_00d08b90(self, arg);
}

extern int DAT_010ccfac;
void __cdecl Deallocate(void*);
struct FUN_00d0a150 {
    int* p;
    FUN_00d0a150(bool b);
};
// @fnv 0x00d0a150
FUN_00d0a150::FUN_00d0a150(bool abFree)
{
    p = &DAT_010ccfac;
    if (abFree & 1) Deallocate(this);
}

extern int DAT_010ccfa0;
extern int DAT_010ccfac;
extern "C" void __cdecl Deallocate(void*);

struct FUN_00d0a1a0 {
    int* a;
    int* b;
    int __thiscall Init(int p);
};

// Sets a and b to the addresses of two globals, frees this if p has bit 0 set, and returns this.
// @fnv 0x00d0a1a0
int __thiscall FUN_00d0a1a0::Init(int aiFlags)
{
    b = &DAT_010ccfac;
    a = &DAT_010ccfa0;
    if (aiFlags & 1)
        Deallocate(this);
    return (int)this;
}

// @fnv 0x00d08390
int __fastcall FUN_00d08390(void* self, int, int value)
{
    *(int**)((char*)self + 0x38) = (int*)value;
    return value << 5;
}

struct HashEntryTable { void clear(); };
struct FUN_00d08550_Class {
    void __thiscall FUN_00d08550();
};
// @fnv 0x00d08550
void __thiscall FUN_00d08550_Class::FUN_00d08550()
{
    ((char*)this)[0x69] = 0;
    ((HashEntryTable*)((char*)this + 0x50))->clear();
}

struct FUN_00d08560_class {
    void __thiscall FUN_00d08560();
};
// @fnv 0x00d08560
void __thiscall FUN_00d08560_class::FUN_00d08560()
{
    *(int*)((char*)this + 0x48) = 0;
    *(char*)((char*)this + 0x2c) = 0;
    *(char*)((char*)this + 0x69) = 0;
}

struct FUN_00d08940_class {
    void __thiscall FUN_00d08940(void* arg);
};

struct FUN_00d08a40_class {
    char pad0[8];
    char m_flag8;
    char pad9[0x43];
    char m_4c;
    char m_4d;
    void __thiscall ProcessFlaggedEntries(void* arg);
};

// If m_flag8 is set, sets m_4d to 1 and m_4c to 0, then iterates the entries in arg and calls FUN_00d08940 on each whose byte at offset 0x28 equals 1.
// @fnv 0x00d08a40
void FUN_00d08a40_class::ProcessFlaggedEntries(void* arg)
{
    if (m_flag8)
    {
        int i;
        m_4d = 1;
        m_4c = 0;
        int* p = (int*)arg;
        for (i = 0; i < p[0x4c/4]; i++)
        {
            char* e = (char*)((int*)p[0x48/4])[i];
            e += 0x10;
            if (e[0x18] == 1)
                ((FUN_00d08940_class*)((char*)this - 0x1c))->FUN_00d08940(e);
        }
    }
}

struct FUN_00cd2a00_class {
    void __thiscall FUN_00cd2a00();
};

// @fnv 0x00d083e0
void __stdcall FUN_00d083e0(void* arg)
{
    FUN_00cd2a00_class* p = reinterpret_cast<FUN_00cd2a00_class*>(
        reinterpret_cast<char*>(arg) + reinterpret_cast<signed char*>(arg)[0x10]);
    p->FUN_00cd2a00();
}

struct FUN_00d08a90_class {
    void __thiscall FUN_00d08a90(void* arg);
};
// @fnv 0x00d08a90
void FUN_00d08a90_class::FUN_00d08a90(void* arg)
{
    if (((char*)this)[4]) {
        arg = (char*)arg + 0x10;
        ((char*)this)[0x49] = 1;
        ((char*)this)[0x48] = 0;
        ((FUN_00d08940_class*)((char*)this - 0x20))->FUN_00d08940(arg);
    }
}

struct FUN_00d08fb0_Class {
    char pad[0x54];
    char m_54;
    char m_55;
    void __thiscall FUN_00d08fb0(char* arg);
    void __thiscall FUN_00d08c90(char* arg);
};
// @fnv 0x00d08fb0
void __thiscall FUN_00d08fb0_Class::FUN_00d08fb0(char* arg)
{
    arg += 0x10;
    m_55 = 1;
    m_54 = 0;
    ((FUN_00d08fb0_Class*)((char*)this - 0x14))->FUN_00d08c90(arg);
}

void __cdecl FUN_00d08c90(void* self, int a);
struct FUN_00d08fd0_class {
    char pad[0x50];
    char m_50;
    char m_51;
    void __thiscall FUN_00d08fd0(int a);
    void __thiscall FUN_00d08c90(int a);
};
// @fnv 0x00d08fd0
void __thiscall FUN_00d08fd0_class::FUN_00d08fd0(int a)
{
    m_51 = 1;
    m_50 = 0;
    ((FUN_00d08fd0_class*)((char*)this - 0x18))->FUN_00d08c90(a + 0x10);
}

void __cdecl Deallocate(void*);
struct FUN_00d0a130 {
    void* p;
    void* __thiscall Set(char b);
};
// @fnv 0x00d0a130
void* FUN_00d0a130::Set(char abFree)
{
    p = &DAT_010ccfa0;
    if (abFree & 1)
        Deallocate(this);
    return this;
}

// add ecx,-0x14; jmp FUN_00d08570 : override in Derived forwards to the primary base's virtual.
struct PrimaryBase
{
    virtual void FUN_00d08570();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d089c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
    virtual void FUN_00d089c0();
};

Derived::Derived()
{
}

// @fnv 0x00d089c0
void Derived::FUN_00d089c0()
{
    this->PrimaryBase::FUN_00d08570();
}

namespace fnv_00d089d0 {
// add ecx,-0x14; jmp FUN_00d08570 : Derived's override forwards to the primary base's virtual.
struct PrimaryBase
{
    virtual void FUN_00d08570();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d089d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
    virtual void FUN_00d089d0();
};

Derived::Derived()
{
}

// @fnv 0x00d089d0
void Derived::FUN_00d089d0()
{
    this->PrimaryBase::FUN_00d08570();
}
}  // namespace fnv_00d089d0

namespace fnv_00d089e0 {
struct Base {
    void __thiscall FUN_00d08570();
};

struct Derived {
    void __thiscall FUN_00d089e0();
};

// @fnv 0x00d089e0
void __thiscall Derived::FUN_00d089e0()
{
    ((Base*)((char*)this - 0x18))->FUN_00d08570();
}
}  // namespace fnv_00d089e0

struct FUN_00d0a1f0_Class {
    void __thiscall FUN_00d0a1f0(unsigned char value);
};

// @fnv 0x00d0a1f0
void __thiscall FUN_00d0a1f0_Class::FUN_00d0a1f0(unsigned char value) {
    *reinterpret_cast<unsigned char*>(reinterpret_cast<int>(this) + 0x68) = value;
}

// Empty function that takes an int argument and does nothing.
// @fnv 0x00d08380
void __stdcall FUN_00d08380(int) {
}

struct FUN_00cd29f0_cls {
    void FUN_00cd29f0(int iValue);
};

struct FUN_00d08400_cls {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    signed char m_targetOffset;
};

// @fnv 0x00d08400
void __cdecl DispatchToOffsetTarget(FUN_00d08400_cls* pkObject, unsigned short usValue)
{
    reinterpret_cast<FUN_00cd29f0_cls*>(reinterpret_cast<char*>(pkObject) + pkObject->m_targetOffset)->FUN_00cd29f0(usValue);
}

struct __declspec(align(16)) hkVector4D084 {
    float x, y, z, w;
};

struct hkpWorldRayCastInputD084 {
    hkVector4D084 m_vFrom;
    hkVector4D084 m_vTo;
    bool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
};

struct hkpShapeRayCastOutputD084 {
    hkVector4D084 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_pad18;
    int m_pad1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    hkpShapeRayCastOutputD084()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = 0xffffffff;
        m_uiShapeKeyIndex = 0;
    }
};

struct hkpWorldRayCastOutputD084 : public hkpShapeRayCastOutputD084 {
    const void* m_pRootCollidable;

    hkpWorldRayCastOutputD084() { m_pRootCollidable = 0; }
};

struct hkpRayHitCollectorD084;

class hkpRayShapeCollectionFilterD084 {
public:
    virtual ~hkpRayShapeCollectionFilterD084() throw();
};

class hkpRayCollidableFilterD084 {
public:
    virtual ~hkpRayCollidableFilterD084() throw();
};

class hkpCollidableCollidableFilterD084 {
public:
    virtual ~hkpCollidableCollidableFilterD084() throw();
};

class hkpShapeCollectionFilterD084 {
public:
    virtual ~hkpShapeCollectionFilterD084() throw();
};

class hkReferencedObjectD084 {
public:
    virtual ~hkReferencedObjectD084() throw();
    int m_usMemSizeAndFlags;
};

class hkpCollisionFilterD084 : public hkReferencedObjectD084, public hkpCollidableCollidableFilterD084, public hkpShapeCollectionFilterD084, public hkpRayShapeCollectionFilterD084, public hkpRayCollidableFilterD084 {
};

class hkpRayCastCollectorBaseD084 {
public:
    virtual void CollectRayHit() throw();
};

class hkpTreeCastCallbackD084 {
public:
    virtual float processLeaf() throw();
};

class FUN_00d9a040 : public hkpRayCastCollectorBaseD084, public hkpTreeCastCallbackD084 {
public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
    int m_1c;

    FUN_00d9a040() throw();
};

class hkpBroadPhaseCastCollectorD084 {
public:
    virtual void ReleaseCollector() throw();
};

class hkpWorldRayCasterD084 : public hkpBroadPhaseCastCollectorD084 {
public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
};

struct hkBoolD084 {
    char m_cBooleanValue;
    hkBoolD084(bool b) { m_cBooleanValue = (char)b; }
};

hkBoolD084 __cdecl FUN_00d98ca0(void* pkBroadPhase, const hkVector4D084& kFrom, const hkVector4D084& kTo, hkpWorldRayCasterD084* pkCaster) throw();
void __cdecl FUN_00d1bd00(void* pkTree, const hkVector4D084& kFrom, const hkVector4D084& kTo, hkpTreeCastCallbackD084* pkCaster, float fEarlyOut) throw();

class hkpRayCastQueryD084 {
public:
    int m_00;
    int m_04;
    int m_08;
    void* m_iValueAt40;
    void* m_pJobSemaphore;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    bool m_useTree;

    void CastRay(const hkpWorldRayCastInputD084& kInput, const hkpCollisionFilterD084* pkFilter, hkpRayHitCollectorD084* pkCollector) const throw();
};

// @fnv 0x00d08420
void hkpRayCastQueryD084::CastRay(const hkpWorldRayCastInputD084& kInput, const hkpCollisionFilterD084* pkFilter, hkpRayHitCollectorD084* pkCollector) const throw()
{
    FUN_00d9a040 kTreeCaster;
    kTreeCaster.m_pRayCastInput = &kInput;
    kTreeCaster.m_kCollector = pkCollector;
    kTreeCaster.m_iFilter = pkFilter;
    kTreeCaster.m_shapeFilter = pkFilter;
    hkpWorldRayCastOutputD084 kTreeOutput;
    kTreeCaster.m_pRayCastOutput = &kTreeOutput;

    if (m_pJobSemaphore) {
        hkpWorldRayCasterD084 kCaster;
        kCaster.m_pRayCastInput = &kInput;
        kCaster.m_kCollector = pkCollector;
        kCaster.m_iFilter = pkFilter;
        kCaster.m_shapeFilter = pkFilter;
        hkpWorldRayCastOutputD084 kOutput;
        kCaster.m_pRayCastOutput = &kOutput;
        FUN_00d98ca0(m_pJobSemaphore, kInput.m_vFrom, kInput.m_vTo, &kCaster);
    }
    if (m_useTree)
        FUN_00d1bd00(m_iValueAt40, kInput.m_vFrom, kInput.m_vTo, &kTreeCaster, 1.0f);
}

template <class T>
class hkArrayD085 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i) {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

class hkBroadPhaseD085 {
public:
    void FUN_00d9c7d0(unsigned short id);
};

struct hkCollidableD085 {
    int unk00;
};

struct hkEntityD085 {
    int unk00[4];
    hkCollidableD085 m_kCollidable;
};

class hkHandlerD085 {
public:
    int unk00[3];
    hkBroadPhaseD085* m_pJobSemaphore;
    int unk10[5];
    bool m_enabled;
    char unk25[0x1f];
    hkArrayD085<hkCollidableD085*> m_kCollidables;

    unsigned short FUN_00d083e0(hkCollidableD085* c);
    void FUN_00d08570(hkEntityD085* entity);
};

// @fnv 0x00d08570
void hkHandlerD085::FUN_00d08570(hkEntityD085* entity)
{
    hkCollidableD085* c = &entity->m_kCollidable;
    if (m_enabled) {
        unsigned short id = FUN_00d083e0(c);
        int i = m_kCollidables.indexOf(c);
        if (i == -1) {
            if (id != 0xffff)
                m_pJobSemaphore->FUN_00d9c7d0(id);
        } else {
            m_kCollidables.removeAt(i);
        }
    }
}

struct PlaceTagD088 {};
inline void* operator new(unsigned int, void* p, PlaceTagD088) throw() { __assume(p != 0); return p; }
inline void operator delete(void*, void*, PlaceTagD088) throw() {}

template <class T>
struct hkArrayD088 {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void pushBackUnchecked(const T& e)
    {
        new (&m_data[m_iElementCount], PlaceTagD088()) T(e);
        m_iElementCount++;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

struct hkBoolRetD088 {
    char m_cBooleanValue;
    hkBoolRetD088() throw() {}
};

class hkpEntityD088 {
public:
    hkBoolRetD088 FUN_00c9bff0() const throw();
};

struct hkpCollidableD088 {
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    signed char m_iOwnerOffset;
    char m_pad11[3];
    unsigned int m_iOwnerObjectOffset;
    char m_type;

    hkpEntityD088* getOwner() const { return (hkpEntityD088*)((char*)this + m_iOwnerOffset); }
};

class hkpEntityListD088 {
public:
    char m_pad00[0x44];
    hkArrayD088<hkpCollidableD088*> m_kCollidables;
    char m_pad50[0xc];
    bool m_checkAll;
    char m_pad5d[3];
    int m_currentIndex;
    int m_maxChecksPerCall;

    __forceinline void checkCollidable(int i, hkArrayD088<hkpCollidableD088*>& kInactive)
    {
        hkpCollidableD088* pkCollidable = m_kCollidables.m_data[i];
        if (pkCollidable->m_type == 1) {
            hkpEntityD088* pkEntity = pkCollidable->getOwner();
            if (pkEntity && !pkEntity->FUN_00c9bff0().m_cBooleanValue) {
                kInactive.pushBackUnchecked(m_kCollidables.m_data[i]);
                m_kCollidables.removeAt(i);
            }
        }
    }

    bool CheckCollidables(hkArrayD088<hkpCollidableD088*>& kInactive) throw();
};

// Moves inactive collidables from the list into kInactive, checking all entries when m_checkAll is set or up to m_maxChecksPerCall entries otherwise.
// @fnv 0x00d08800
bool hkpEntityListD088::CheckCollidables(hkArrayD088<hkpCollidableD088*>& kInactive) throw()
{
    if (m_checkAll) {
        for (int i = m_kCollidables.m_iElementCount - 1; i >= 0; i--)
            checkCollidable(i, kInactive);
        return true;
    }

    m_currentIndex = (m_currentIndex < m_kCollidables.m_iElementCount - 1) ? m_currentIndex : m_kCollidables.m_iElementCount - 1;
    int iNumChecked = 0;
    for (int j = 0; j < m_maxChecksPerCall; j++) {
        int i = m_currentIndex--;
        if (i < 0) {
            m_currentIndex = m_kCollidables.m_iElementCount;
            break;
        }
        checkCollidable(i, kInactive);
        iNumChecked++;
    }
    return iNumChecked == m_kCollidables.m_iElementCount;
}

struct hkObjectE02;
struct hkLoaderE02 {
    int Get(char const* name, hkObjectE02** out);
};
struct Router {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
};
Router* __cdecl _FNV_e03300_arena();
struct Sink {
    void FUN_00cb1870(void*, int, int);
};
struct FUN_00d08940_shell {
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
    hkLoaderE02 loader;
    void FUN_00d08940(char const* name);
};
// Looks up name via loader.Get and, on success, passes the arena router's e field and name to the sink at offset 0x50.
// @fnv 0x00d08940
void FUN_00d08940_shell::FUN_00d08940(char const* name)
{
    hkObjectE02* obj;
    if (loader.Get(name, &obj)) {
        Router* router = _FNV_e03300_arena();
        reinterpret_cast<Sink*>(reinterpret_cast<char*>(this) + 0x50)->FUN_00cb1870(
            reinterpret_cast<void*>(router->e), reinterpret_cast<int>(name), 1);
    }
}

struct FUN_00d9a4d0_class {
    void __thiscall GetEntryOffset(unsigned int value);
};
struct FUN_00d08c70_class {
    int unk00;
    int unk04;
    int unk08;
    FUN_00d9a4d0_class* unk0C;
    void __thiscall FUN_00d08c70(void* arg);
};
// Calls FUN_00d083e0 with arg to get a word, then passes it to the method at unk0C + 0x1c.
// @fnv 0x00d08c70
void FUN_00d08c70_class::FUN_00d08c70(void* arg)
{
    typedef unsigned short (__stdcall *FunctionReturningWord)(void*);
    unsigned int value = ((FunctionReturningWord)&FUN_00d083e0)(arg);
    ((FUN_00d9a4d0_class*)((char*)unk0C + 0x1c))->GetEntryOffset(value);
}

class hkMemoryAllocatorD08C;

struct hkMemoryRouterD08C {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD08C* m_pStreamAllocator;
    hkMemoryAllocatorD08C& heap() { return *m_pStreamAllocator; }
};
extern "C" hkMemoryRouterD08C& __cdecl FUN_00c85750();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T>
__forceinline void constructWithCopyD08C(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayD08C {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorD08C& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyD08C(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpEntityD08C;

void __cdecl DispatchToOffsetTarget(hkpEntityD08C* pkEntity, int iFlags);

class hkpEntityListD08C {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    bool m_enabled;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    hkArrayD08C<hkpEntityD08C*> m_kActorEntries;

    void FUN_00d08c90(hkpEntityD08C* pkEntity);
};

// If the list is enabled, applies flags 0xffff to pkEntity and appends it to the entity array.
// @fnv 0x00d08c90
void hkpEntityListD08C::FUN_00d08c90(hkpEntityD08C* pkEntity)
{
    if (m_enabled) {
        DispatchToOffsetTarget(pkEntity, 0xffff);
        m_kActorEntries.AddBack(pkEntity);
    }
}

namespace fnv_00d08cf0 {
struct IAllocator {
    virtual void unk00();
    virtual void* allocate(unsigned int size);
};

struct BSAudio {
    int unk00; int unk04; int unk08; int unk0c;
    IAllocator* allocator;
};

extern "C" BSAudio* __cdecl FUN_00c85750();

struct MyArray {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    MyArray() : m_data(0), m_iElementCount(0), m_iCapacityState((int)0x80000000) {}
};

struct MyMapBase {
    void* m_table;
    int m_iCapacityFlags;
    int m_iPairCount;
    MyMapBase() : m_table(0), m_iCapacityFlags(0), m_iPairCount(-1) {}
    void __thiscall EnsureCapacity(IAllocator* allocator, int type);
};

struct Semaphore {
    void* handle;
    void* __thiscall Create(int initial, int max);
};

struct Class0xd9c180 {
    void* __thiscall FUN_00d9c180(void* v1, void* v2, void* v3);
};

struct ListenerManager {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74;
    char* unk78;

    void __thiscall FUN_00c93820(void* listener);
    void __thiscall FUN_00c93860(void* listener);
    void __thiscall FUN_00c938a0(void* listener);
    void __thiscall FUN_00c93920(void* listener);
};

struct MyBase1
{
    virtual void FUN_00d08570();
    virtual void vfunc1_1();
    virtual void vfunc1_2();
    virtual void vfunc1_3();
    virtual void vfunc1_4();
    virtual void vfunc1_5();
    virtual void vfunc1_6();
    short unk04;
    short unk06;
    int unk08;
    void* unk0C;
    int unk10;
    MyBase1() {
        this->unk0C = 0;
        this->unk10 = 0;
        this->unk06 = 1;
    }
};

struct MyBase2
{
    virtual void FUN_00d089c0();
    virtual void vfunc2_1();
    virtual void vfunc2_2();
    virtual void vfunc2_3();
    virtual void vfunc2_4();
    virtual void vfunc2_5();
};

struct MyBase3
{
    virtual void FUN_00d089e0();
    virtual void vfunc3_1();
    virtual void vfunc3_2();
    virtual void vfunc3_3();
};

struct MyBase4
{
    virtual void vfunc4_0();
    virtual void vfunc4_1();
    virtual void vfunc4_2();
    virtual void vfunc4_3();
};

struct MyBase5
{
    virtual void vfunc5_0();
    virtual void vfunc5_1();
    virtual void vfunc5_2();
    virtual void vfunc5_3();
};

struct FUN_00d08cf0 : MyBase1, MyBase2, MyBase3, MyBase4, MyBase5
{
    char unk24;
    char unk25;
    char unk26;
    char unk27;
    ListenerManager* unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    void* unk3c;
    float unk40;
    MyArray unk44;
    MyMapBase unk50;
    char unk5c;
    char unk5d;
    char unk5e;
    char unk5f;
    int unk60;
    int unk64;
    char unk68;
    char unk69;
    char unk6a;
    char unk6b;
    void* unk6c;

    FUN_00d08cf0(ListenerManager* a1, int a2, float a3);
    virtual void FUN_00d08570();
    virtual void FUN_00d089c0();
    virtual void FUN_00d089e0();
    virtual void vfunc4_0();
    virtual void vfunc5_0();

    void __thiscall FUN_00d08560();
};

// @fnv 0x00d08cf0
FUN_00d08cf0::FUN_00d08cf0(ListenerManager* apListenerManager, int a2, float afValue)
    : unk28(apListenerManager)
{
    BSAudio* audio = FUN_00c85750();
    this->unk50.EnsureCapacity(audio->allocator, 0);
    this->unk30 = 0;
    this->unk34 = 0;
    BSAudio* pAudio = FUN_00c85750();
    this->unk3c = pAudio->allocator->allocate(0x10);
    BSAudio* audio3 = FUN_00c85750();
    void* pSemaphore = audio3->allocator->allocate(4);
    if (pSemaphore) {
        pSemaphore = ((Semaphore*)pSemaphore)->Create(0, 1000);
    } else {
        pSemaphore = 0;
    }
    this->unk6c = pSemaphore;
    __declspec(align(16)) float fValue = afValue;
    this->unk40 = fValue;
    this->unk08 = 1;
    this->unk10 = 0;
    this->unk0C = 0;
    if (a2 == 0) {
        this->unk24 = 1;
    } else if (a2 == 1) {
        this->unk24 = 0;
    }
    this->unk28->FUN_00c93820((MyBase2*)this);
    this->unk28->FUN_00c93860((MyBase3*)this);
    this->unk28->FUN_00c938a0((MyBase4*)this);
    this->unk28->FUN_00c93920((MyBase5*)this);
    if (this->unk24) {
        char* edi = this->unk28->unk78 + 0x20;
        BSAudio* audio4 = FUN_00c85750();
        void* pObj = audio4->allocator->allocate(0x80);
        if (pObj) {
            pObj = ((Class0xd9c180*)pObj)->FUN_00d9c180(edi, edi + 0x10, edi + 0x20);
        } else {
            pObj = 0;
        }
        this->unk0C = pObj;
    }
    this->unk5c = 0;
    this->unk68 = 0;
    this->unk60 = 0;
    this->unk64 = 0x1e;
    this->FUN_00d08560();
}
}  // namespace fnv_00d08cf0

class hkObjD099 {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    void* m_28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    void* m_48;

    void FUN_00d094a0(int* p, void* a, void* b, void* c, void* d);
    void FUN_00d099a0(void* a, void* c, void* d);
};

// @fnv 0x00d099a0
void hkObjD099::FUN_00d099a0(void* a, void* c, void* d)
{
    if (m_48)
        FUN_00d094a0(&m_10, a, m_28, c, d);
}

struct FUN_00d0a1e0_class {
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
    char unk68;
    char __thiscall FUN_00d0a1e0();
};
// @fnv 0x00d0a1e0
char __thiscall FUN_00d0a1e0_class::FUN_00d0a1e0() {
    return unk68;
}

namespace fnv_00d0a240 {
struct FnvCpu_FUN_00d0a240_CpuAllocator {
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d0a240_CpuAllocatorHolder {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d0a240_CpuAllocator* allocator;
};
FnvCpu_FUN_00d0a240_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d0a240_CpuObject {
    unsigned int unk00;
    unsigned short size;
    void Destructor();
    FnvCpu_FUN_00d0a240_CpuObject* FUN_00d0a240(unsigned int flags);
};
// @fnv 0x00d0a240
FnvCpu_FUN_00d0a240_CpuObject* FnvCpu_FUN_00d0a240_CpuObject::FUN_00d0a240(unsigned int flags)
{
    Destructor();
    if (flags & 1) {
        FnvCpu_FUN_00d0a240_CpuAllocatorHolder* pAllocatorHolder = FUN_00c85750();
        pAllocatorHolder->allocator->Invoke(this, size);
    }
    return this;
}
}  // namespace fnv_00d0a240

extern int DAT_010ccfcc;
extern int DAT_010ccfe0;
extern int DAT_010ccfec;
extern float DAT_0104da4c;
__declspec(align(16)) struct S00d08740_coll {
    int m_00;
    int m_04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int m_24;
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
    float m_80;
    void FUN_00d984b0(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
    void FUN_00d9a2a0(void* a0, void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
};
struct S00d08740_cls {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    char m_24;
    char m_25;
    char m_26;
    char m_27;
    void Collect(void* kFrom, void* kTo, void* pkRoot, void* pkFilter, void* pkShapeFilter, void* pkOutput, void* pkCollector);
};
// If m_10 or m_24 is set, builds a local S00d08740_coll with DAT_0104da4c and calls FUN_00d984b0 or FUN_00d9a2a0 with the given pointers.
// @fnv 0x00d08740
void S00d08740_cls::Collect(void* kFrom, void* kTo, void* pkRoot, void* pkFilter, void* pkShapeFilter, void* pkOutput, void* pkCollector)
{
    if (m_10) {
        S00d08740_coll kCollector;
        kCollector.m_00 = (int)&DAT_010ccfcc;
        kCollector.m_24 = 0;
        kCollector.m_80 = DAT_0104da4c;
        kCollector.FUN_00d984b0(m_10, kFrom, kTo, pkRoot, pkFilter, pkShapeFilter, pkOutput, pkCollector);
    }
    if (m_24) {
        S00d08740_coll kCollector;
        kCollector.m_00 = (int)&DAT_010ccfec;
        kCollector.m_04 = (int)&DAT_010ccfe0;
        kCollector.m_24 = 0;
        kCollector.m_80 = DAT_0104da4c;
        kCollector.FUN_00d9a2a0(m_0c, kFrom, kTo, pkRoot, pkFilter, pkShapeFilter, pkOutput, pkCollector);
    }
}

class hkMemoryAllocatorD089;

struct hkMemoryRouterD089 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD089* m_pStreamAllocator;
    hkMemoryAllocatorD089& heap() { return *m_pStreamAllocator; }
};

namespace fnvc_adapt { extern "C" hkMemoryRouterD089* __cdecl FUN_00c85750(); }

enum hkResultD089 { HK_SUCCESS = 0, HK_FAILURE = 1 };

class hkMapBaseD089 {
public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkResultD089 LookupBucketValue(unsigned int key, unsigned int* out) const;
    int FUN_00cb1870(hkMemoryAllocatorD089& alloc, unsigned int key, unsigned int val);
};

class OwnerD089 {
public:
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
    hkMapBaseD089 m_map;

    void FUN_00d08980(unsigned int key);
};

// Looks up key in m_map and, if the lookup fails, calls FUN_00cb1870 on the map with key and -1.
// @fnv 0x00d08980
void OwnerD089::FUN_00d08980(unsigned int key)
{
    unsigned int dummy;
    if (m_map.LookupBucketValue(key, &dummy) != HK_SUCCESS)
        m_map.FUN_00cb1870(fnvc_adapt::FUN_00c85750()->heap(), key, (unsigned int)-1);
}

struct hkpCollidableD08 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_broadPhaseId;
    signed char m_cBroadPhaseType;
};

struct hkpEntityD08 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkpCollidableD08 m_kCollidable;
};

struct hkpSimulationIslandD08 {
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
    hkpEntityD08** m_kActorEntries;
    int m_iActorEntryCount;
};

class hkpPrimaryD08 {
public:
    virtual ~hkpPrimaryD08();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

class hkpIslandListenerD08 {
public:
    virtual void islandAddedCallback(hkpSimulationIslandD08* island);
    virtual void FUN_00d089f0(hkpSimulationIslandD08* island);
};

class TrackerD08 : public hkpPrimaryD08, public hkpIslandListenerD08 {
public:
    int unk20;
    bool m_enabled;
    char unk25;
    short unk26;
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
    bool m_dirty;
    bool m_needsUpdate;

    void FUN_00d08980(hkpCollidableD08* collidable);
    virtual void FUN_00d089f0(hkpSimulationIslandD08* island);
};

// When enabled, marks the tracker for update and calls FUN_00d08980 on each broad-phase-type-1 collidable in the island's actor entries.
// @fnv 0x00d089f0
void TrackerD08::FUN_00d089f0(hkpSimulationIslandD08* island)
{
    if (m_enabled) {
        m_needsUpdate = true;
        m_dirty = false;
        for (int i = 0; i < island->m_iActorEntryCount; i++) {
            hkpCollidableD08* collidable = &island->m_kActorEntries[i]->m_kCollidable;
            if (collidable->m_cBroadPhaseType == 1)
                FUN_00d08980(collidable);
        }
    }
}

namespace fnv_00d08e80 {
extern "C" void* DAT_010cd078;
extern "C" void* DAT_010cd05c;
extern "C" void* DAT_010cd044;
extern "C" void* DAT_010cd034;
extern "C" void* DAT_010cd024;
extern "C" void* DAT_010ccf7c;
extern int DAT_0104de10;
extern int DAT_0102e388;
extern int DAT_0104e3d0;
extern "C" void* DAT_0102f13c;

struct Hk_d08e80_Alloc {
    virtual void func0() = 0;
    virtual void func1() = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;
    virtual void func3() = 0;
    virtual void ReturnMemory(void* p, int numBytes) = 0;
};

struct Hk_d08e80_Mem {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Hk_d08e80_Alloc* m_alloc;
    Hk_d08e80_Alloc& heap() { return *m_alloc; }
};

namespace fnvc_adapt { Hk_d08e80_Mem* __cdecl FUN_00c85750(); }

struct Cls_00c917a0 { void __thiscall FUN_00c917a0(void*); };
struct Cls_00c917f0 { void __thiscall FUN_00c917f0(void*); };
struct Cls_00c91840 { void __thiscall RemovePointer(void*); };
struct Cls_00c918e0 { void __thiscall ClearValue(void*); };
struct Cls_00d97850 { void __thiscall ClearBuffers(); };
struct Cls_00d04370 { void __thiscall FUN_00d04370(); };
struct Cls_00cb1a90 { void __thiscall ProcessArgument(Hk_d08e80_Alloc*); };
struct Cls_00a29680 { void __thiscall FUN_00a29680(); };

struct Virt_d08e80 {
    virtual ~Virt_d08e80();
};

struct Arr_d08e80 {
    void* m_data;
    int m_iElementCount;
    int m_capFlags;
    ~Arr_d08e80() {
        Hk_d08e80_Alloc& a = fnvc_adapt::FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0) {
            a.ReturnMemory(m_data, (m_capFlags & 0x3fffffff) * 4);
        }
        m_data = 0;
        m_capFlags = 0x80000000;
    }
    void destroy() { this->~Arr_d08e80(); }
};

struct Tgt_d08e80 {
    void* vtbl00;
    int unk04;
    int unk08;
    Virt_d08e80* unk0C;
    Cls_00d97850* unk10;
    void* vtbl14;
    void* vtbl18;
    void* vtbl1C;
    void* vtbl20;
    int unk24;
    void* unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    void* unk3C;
    int unk40;
    Arr_d08e80 m_aiIndexedValues;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    Cls_00d04370* unk6C;

    void Destructor();
};

// Destroys the object by releasing heap blocks, clearing buffers, and resetting vtable pointers to their initial values.
// @fnv 0x00d08e80
void Tgt_d08e80::Destructor()
{
    vtbl00 = &DAT_010cd078;
    vtbl14 = &DAT_010cd05c;
    vtbl18 = &DAT_010cd044;
    vtbl1C = &DAT_010cd034;
    vtbl20 = &DAT_010cd024;

    ((Cls_00c917a0*)unk28)->FUN_00c917a0(&vtbl14);
    ((Cls_00c917f0*)unk28)->FUN_00c917f0(&vtbl18);
    ((Cls_00c91840*)unk28)->RemovePointer(&vtbl1C);
    ((Cls_00c918e0*)unk28)->ClearValue(&vtbl20);

    if (unk0C) {
        delete unk0C;
    }

    Cls_00d97850* p10 = unk10;
    if (p10) {
        p10->ClearBuffers();
        fnvc_adapt::FUN_00c85750()->heap().ReleaseBlock(p10, 0x50);
    }

    void* pBlock3C = unk3C;
    fnvc_adapt::FUN_00c85750()->heap().ReleaseBlock(pBlock3C, 0x10);

    Cls_00d04370* pBlock6C = unk6C;
    if (pBlock6C) {
        pBlock6C->FUN_00d04370();
        fnvc_adapt::FUN_00c85750()->heap().ReleaseBlock(pBlock6C, 4);
    }

    ((Cls_00cb1a90*)&unk50)->ProcessArgument(fnvc_adapt::FUN_00c85750()->m_alloc);
    ((Cls_00a29680*)&unk50)->FUN_00a29680();

    m_aiIndexedValues.destroy();

    vtbl20 = &DAT_010ccf7c;
    vtbl1C = (void*)&DAT_0104de10;
    vtbl00 = (void*)&DAT_0102e388;
    vtbl18 = (void*)&DAT_0104e3d0;
    vtbl14 = (void*)&DAT_0102f13c;
}
}  // namespace fnv_00d08e80

extern int DAT_010ccfcc;
extern float DAT_0104da4c;
__declspec(align(16)) struct S00d0a490_Obj {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    float m_80;
    int m_84;
    int m_88;
    int m_8c;
    int FUN_00d984b0(int, int, int, int, int, int, int, int);
};
struct S00d0a490_cls {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int __thiscall CallSubroutine(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
};
// Initialises a local S00d0a490_Obj with DAT_010ccfcc and DAT_0104da4c, then calls FUN_00d984b0 with m_10 and the seven arguments.
// @fnv 0x00d0a490
int S00d0a490_cls::CallSubroutine(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    S00d0a490_Obj o;
    o.m_00 = (int)&DAT_010ccfcc;
    o.m_80 = DAT_0104da4c;
    o.m_24 = 0;
    return o.FUN_00d984b0(m_10, a0, a1, a2, a3, a4, a5, a6);
}

// @fnv 0x00d083c0
void __cdecl FUN_00d083c0()
{
}

struct hkpEntityB90 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_kCollidable;
};
struct hkpSimulationIslandB90 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44;
    hkArrayD08C<hkpEntityB90*> m_kActorEntries;
};
struct hkpWorldB90 {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkpSimulationIslandB90* m_pFixedIsland;
    hkpEntityB90* m_pFixedRigidBody;
    int unk28, unk2C, unk30;
    hkArrayD08C<hkpSimulationIslandB90*> m_kActiveSimulationIslands;
};

// Appends pointers to the m_kCollidable field of every active and fixed island actor, except the fixed rigid body, into out.
// @fnv 0x00d08b90
void __cdecl FUN_00d08b90(hkArrayD08C<int*>& out, hkpWorldB90* world)
{
    const hkArrayD08C<hkpSimulationIslandB90*>& islands = world->m_kActiveSimulationIslands;
    for (int i = 0; i < islands.m_iElementCount; i++) {
        for (int j = 0; j < islands.m_data[i]->m_kActorEntries.m_iElementCount; j++)
            out.AddBack(&islands.m_data[i]->m_kActorEntries.m_data[j]->m_kCollidable);
    }
    hkpSimulationIslandB90* fixedIsland = world->m_pFixedIsland;
    hkpEntityB90* fixedBody = world->m_pFixedRigidBody;
    for (int k = 0; k < fixedIsland->m_kActorEntries.m_iElementCount; k++) {
        hkpEntityB90* body = fixedIsland->m_kActorEntries.m_data[k];
        if (body != fixedBody)
            out.AddBack(&body->m_kCollidable);
    }
}

extern unsigned int DAT_0126835c;
extern char DAT_010cd234[];
extern char DAT_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
struct MonitorEvent { const char* tag; unsigned int time; unsigned int extra; };
struct MonitorStream { int unk00; MonitorEvent* current; int unk08; MonitorEvent* end; };
struct UpdateOwner {
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
    bool initialized;
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
    bool dirty;
    void FUN_00d09df0(void*, void*);
    void FUN_00d099d0(void*, void*);
    void updateFromWorld(void*, void*);
};
// Records a monitor event, calls FUN_00d09df0 on first update or FUN_00d099d0 otherwise, sets dirty, and records a closing monitor event.
// @fnv 0x00d0a060
void UpdateOwner::updateFromWorld(void* a, void* b) {
    void* (__stdcall *getTls)(unsigned long) = TlsGetValue;
    MonitorStream* stream = (MonitorStream*)getTls(DAT_0126835c);
    MonitorEvent* event = stream->current;
    if (event < stream->end) {
        event->tag = DAT_010cd234;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        event->time = stamp;
        stream->current = event + 1;
    }
    dirty = true;
    if (!initialized) {
        FUN_00d09df0(a,b);
        initialized = true;
        MonitorStream* tail = (MonitorStream*)getTls(DAT_0126835c);
        MonitorEvent* e = tail->current;
        if (e < tail->end) {
            e->tag = DAT_010c41f8;
            _ReadWriteBarrier();
            volatile unsigned int stamp = (unsigned int)__rdtsc();
            e->time = stamp;
            tail->current = e + 1;
        }
        return;
    }
    FUN_00d099d0(a,b);
    MonitorStream* tail = (MonitorStream*)getTls(DAT_0126835c);
    MonitorEvent* e = tail->current;
    if (e < tail->end) {
        e->tag = DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        e->time = stamp;
        tail->current = e + 1;
    }
}

namespace fnv_00d0a1d0 {
// sub ecx,4; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (4).
struct PrimaryBase
{
    virtual void FUN_00d0a1d0();
};

struct SecondaryBase
{
    virtual void FUN_00d0a1d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0a1d0
    virtual void FUN_00d0a1d0();
};

Derived::Derived()
{
}
}  // namespace fnv_00d0a1d0

// FUN_00d0a200 : MSVC this-adjusting thunk  (sub ecx, 0x14 ; jmp <impl>)
struct A1_00d0a200 {
    A1_00d0a200();
    virtual void FUN_00d0a200();
    char pad[0x10];
};
struct A2_00d0a200 {
    A2_00d0a200();
    virtual void FUN_00d0a200();
};
struct Own_00d0a200 : A1_00d0a200, A2_00d0a200 {
    Own_00d0a200();
    virtual void key_fn();
// @fnv 0x00d0a200
    void FUN_00d0a200();
};
Own_00d0a200::Own_00d0a200() { }
void Own_00d0a200::key_fn() { }
Own_00d0a200* make_00d0a200() { static Own_00d0a200 o; return &o; }

namespace fnv_00d0a210 {
// sub ecx,0x18; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x18).
struct PrimaryBase
{
    virtual void FUN_00d0a210();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondaryBase
{
    virtual void FUN_00d0a210();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0a210
    virtual void FUN_00d0a210();
};

Derived::Derived()
{
}
}  // namespace fnv_00d0a210

namespace fnv_00d0a220 {
// sub ecx,0x1c; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x1c).
struct PrimaryBase
{
    virtual void FUN_00d0a220();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct SecondaryBase
{
    virtual void FUN_00d0a220();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0a220
    virtual void FUN_00d0a220();
};

Derived::Derived()
{
}
}  // namespace fnv_00d0a220

// Adjustor thunk: the secondary-base (+0x20) vtable entry for an override defined on the derived class.

class D0A230Primary {
public:
    virtual void FUN_00d0a230();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class D0A230Secondary {
public:
    virtual void FUN_00d0a230();
};

class D0A230Listener : public D0A230Primary, public D0A230Secondary {
public:
    D0A230Listener();
// @fnv 0x00d0a230
    virtual void FUN_00d0a230();
};

D0A230Listener::D0A230Listener()
{
}

namespace fnv_00d085e0 {
extern "C" void _ReadWriteBarrier();

extern "C" unsigned long DAT_0126835c;
extern "C" char str_010cd014[], str_010cd004[], str_010ccff4[], str_01076f38[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long index);
extern "C" unsigned __int64 __rdtsc();
struct MyBool0 { int m_v; MyBool0(bool b) { m_v = (int)b; } };
__declspec(noalias) void __cdecl bpv(void*, void*, const hkVector4D084&, const hkVector4D084&, hkpWorldRayCasterD084*) throw();
union Scratch { volatile unsigned int tick; unsigned int result; Scratch() {} };
struct OtherObject { int unk00, unk04, unk08, unk0c, unk10, unk14; };
struct Trace16 { const char* eventName; unsigned int time; unsigned int unk08; const char* category; };
struct Trace12 { const char* eventName; unsigned int time; unsigned int unk08; };
struct TLSBuffer { int unk00; unsigned char* current; int unk08; unsigned char* finish; };
struct FUN_00d085e0_class {
    int unk00, unk04, unk08;
    void* arg0c;
    void* arg10;
    int unk14, unk18, unk1c, unk20;
    char flag24;
    void __thiscall castRay(const hkpWorldRayCastInputD084& input, const OtherObject* b, hkpWorldRayCastOutputD084* c);
};

// Performs a broad-phase ray cast via bpv and an optional tree cast, recording trace events to a TLS buffer.
// @fnv 0x00d085e0
void FUN_00d085e0_class::castRay(const hkpWorldRayCastInputD084& input, const OtherObject* apFilters, hkpWorldRayCastOutputD084* apRayCastOutput)
{
    Scratch scratch;
    class FUN_00d9a040 ctx;
    ctx.m_pRayCastOutput = apRayCastOutput;
    ctx.m_pRayCastInput = &input;
    if (apFilters) {
        const_cast<const hkpRayCollidableFilterD084* volatile&>(ctx.m_iFilter) = (const hkpRayCollidableFilterD084*) &apFilters->unk14;
        const_cast<const hkpRayShapeCollectionFilterD084* volatile&>(ctx.m_shapeFilter) = (const hkpRayShapeCollectionFilterD084*) &apFilters->unk10;
    } else {
        const_cast<const hkpRayCollidableFilterD084* volatile&>(ctx.m_iFilter) = (const hkpRayCollidableFilterD084*) 0;
        const_cast<const hkpRayShapeCollectionFilterD084* volatile&>(ctx.m_shapeFilter) = (const hkpRayShapeCollectionFilterD084*) 0;
    }
    TLSBuffer* pTlsBuffer = (TLSBuffer*)TlsGetValue(DAT_0126835c);
    volatile Trace16* e = (Trace16*)pTlsBuffer->current;
    if ((unsigned char*)e < pTlsBuffer->finish) {
        e->eventName = str_010cd014;
        e->category = str_010cd004;
        _ReadWriteBarrier();
        scratch.tick = (unsigned int)__rdtsc(); e->time = scratch.tick;
        pTlsBuffer->current = (unsigned char*)(e + 1);
    }

    void* tls = arg10;
    if (tls) {
        hkpWorldRayCasterD084 broadPhase;
        broadPhase.m_kCollector = 0;
        broadPhase.m_pRayCastOutput = apRayCastOutput;
        broadPhase.m_pRayCastInput = &input;
        if (apFilters) {
            const_cast<const hkpRayCollidableFilterD084* volatile&>(broadPhase.m_iFilter) = (const hkpRayCollidableFilterD084*) &apFilters->unk14;
            const_cast<const hkpRayShapeCollectionFilterD084* volatile&>(broadPhase.m_shapeFilter) = (const hkpRayShapeCollectionFilterD084*) &apFilters->unk10;
        } else {
            const_cast<const hkpRayCollidableFilterD084* volatile&>(broadPhase.m_iFilter) = (const hkpRayCollidableFilterD084*) 0;
            const_cast<const hkpRayShapeCollectionFilterD084* volatile&>(broadPhase.m_shapeFilter) = (const hkpRayShapeCollectionFilterD084*) 0;
        }
        bpv(&scratch.result, tls, input.m_vFrom, input.m_vTo, &broadPhase);
    }
    pTlsBuffer = (TLSBuffer*)TlsGetValue(DAT_0126835c);
    volatile Trace12* p = (Trace12*)pTlsBuffer->current;
    if ((unsigned char*)p < pTlsBuffer->finish) {
        p->eventName = str_010ccff4;
        _ReadWriteBarrier();
        scratch.tick = (unsigned int)__rdtsc(); p->time = scratch.tick;
        pTlsBuffer->current = (unsigned char*)(p + 1);
    }
    if (flag24) {
        FUN_00d1bd00(arg0c, input.m_vFrom, input.m_vTo, static_cast<hkpTreeCastCallbackD084*>(&ctx), 1.0f);
    }
    pTlsBuffer = (TLSBuffer*)TlsGetValue(DAT_0126835c);
    volatile Trace12* pTrace12 = (Trace12*)pTlsBuffer->current;
    if ((unsigned char*)pTrace12 < pTlsBuffer->finish) {
        pTrace12->eventName = str_01076f38;
        _ReadWriteBarrier();
        scratch.tick = (unsigned int)__rdtsc(); pTrace12->time = scratch.tick;
        pTlsBuffer->current = (unsigned char*)(pTrace12 + 1);
    }
}
}  // namespace fnv_00d085e0

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern const char str_010cd130[];
extern const char str_010cd124[];
extern const char str_010cd11c[];
extern const char str_010cd104[];
extern const char str_010cd0fc[];
extern const char str_010cd0f4[];
extern const char str_010cd0e0[];
extern const char str_010cd0d0[];
extern const char str_010cd0c4[];
extern const char str_01076f38[];
extern const char str_010cd0b8[];

struct S00d094a0_Cmd { const char* m_name; unsigned m_uiCommandId; int m_08; const char* m_detail; };
struct S00d094a0_Stream { char* m_00; char* m_kRayEnd; char* m_08; char* m_capEnd; };

union CountPhase { volatile unsigned ticks; int bytes; };
union StreamPhase { S00d094a0_Stream* stream; int capacity; };
struct CapPair {StreamPhase pointer;int capacity2;};
__forceinline void S00d094a0_beginList(const char* name, const char* detail)
{
    S00d094a0_Stream* t = (S00d094a0_Stream*)TlsGetValue(DAT_0126835c);
    S00d094a0_Cmd* p = (S00d094a0_Cmd*)t->m_kRayEnd;
    if ((char*)p < t->m_capEnd) {
        p->m_name = name;
        p->m_detail = detail;
        _ReadWriteBarrier();
        unsigned stamp;
        __asm {
            rdtsc
            mov dword ptr[stamp], eax
        }
        p->m_uiCommandId = stamp;
        t->m_kRayEnd = (char*)p + 16;
    }
}
__forceinline void S00d094a0_timer(const char* name)
{
    S00d094a0_Stream* t = (S00d094a0_Stream*)TlsGetValue(DAT_0126835c);
    S00d094a0_Cmd* p = (S00d094a0_Cmd*)t->m_kRayEnd;
    if ((char*)p < t->m_capEnd) {
        p->m_name = name;
        _ReadWriteBarrier();
        unsigned stamp;
        __asm {
            rdtsc
            mov dword ptr[stamp], eax
        }
        p->m_uiCommandId = stamp;
        t->m_kRayEnd = (char*)p + 12;
    }
}

struct S00d094a0_Alloc {
    virtual void f00();
    virtual void* AllocateMemoryBlock(int);
    virtual void f08();
    virtual void* AllocateBufferWithSize(int&);
    virtual void ReturnMemory(void*, int);
    template<class T> __forceinline T* elements(int& count) {int bytes=count*4; void* p=AllocateBufferWithSize(bytes);count=bytes/4;return (T*)p;}

};
__forceinline S00d094a0_Alloc& S00d094a0_heap() { return *(S00d094a0_Alloc*)&FUN_00c85750().heap(); }

__forceinline void* reserveExternal(void*& data, int& capacity, int& bytes, int n) {
    S00d094a0_Alloc& a = S00d094a0_heap();
    bytes=n*4;
    void* p=a.AllocateBufferWithSize(bytes);
    int amount=bytes/4;
    data=p;
    capacity=amount;
    if(!capacity) capacity=0x80000000;
    return p;
}
struct __declspec(align(16)) S00d094a0_Vec { float x, y, z, w; };
struct __declspec(align(16)) S00d094a0_Desc {
    int m_uiItemCount; char m_04; char m_isMt; short m_06; int m_08; int m_0c;
    S00d094a0_Vec m_kMinimumCorner;
    S00d094a0_Vec m_kMaximumCorner;
    void FUN_00d976d0();
};
struct S00d094a0_Tree {
    void* m_00; int m_04; int m_08; int m_0c; int m_10; int m_14; int m_18; void* m_1c;
    int total() const { return m_14 + m_18; }
    void FUN_00d978d0(S00d094a0_Desc*);
    S00d094a0_Tree* Init(S00d094a0_Desc*);
};
struct S00d094a0_Shape {
    virtual void f00(); virtual void f04(); virtual void f08(); virtual void f0c();
    virtual void f10(); virtual void f14(); virtual void f18(); virtual void f1c();
    virtual void f20(); virtual void f24(); virtual void f28(); virtual void f2c();
    virtual void f30(); virtual void f34(); virtual void f38(); virtual void f3c();
    virtual void getAabb(S00d094a0_Vec*, S00d094a0_Vec*);
};
struct S00d094a0_Input { void** m_00; int m_04; };
struct S00d094a0_Ctx {
    int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c; int u30; int u34; int u38; int u3c;
    int u40; int u44; int u48; int u4c; int u50; int u54;
    S00d094a0_Shape* m_pCollisionShape;
    int u5c; int u60; int u64; int u68; int u6c; int u70; int u74;
    void* m_78;
};
struct S00d094a0_Job;
struct S00d094a0_Queue { void FUN_00d04b50(S00d094a0_Job*, int); void FUN_00d051b0(); };
struct S00d094a0_Sync {
    virtual void f00(); virtual void f04(); virtual void f08();
    virtual void signal(S00d094a0_Queue*, int); virtual void wait();
};
struct S00d094a0_Helper { int FUN_00d04380(); };
struct S00d094a0_JobHead {
    __declspec(align(16)) char m_00;
    char m_01; char m_02;
    short m_04; short m_06;
    S00d094a0_JobHead() {}
    __forceinline S00d094a0_JobHead(char kind, char sub, short size, char spu)
        : m_00(sub), m_01(kind), m_02(spu), m_04(size), m_06(-1) {}
};
struct S00d094a0_QueryJob : S00d094a0_JobHead {
    void* m_10; int* m_14; int* m_18; void* m_1c;
    S00d094a0_QueryJob() {}
    __forceinline S00d094a0_QueryJob(char sub, short size)
        : S00d094a0_JobHead(3,sub,size,0), m_10(0), m_18(0) {
        m_02=1; m_14=0;
    }
};
struct S00d094a0_DistJob : S00d094a0_QueryJob {
    void* m_20; void* m_24; void* m_28; void* m_2c;
    void* m_30; void* m_34;
    int m_38; int m_3c; int m_40;
    S00d094a0_DistJob() {}
    __forceinline S00d094a0_DistJob(int* header) : S00d094a0_QueryJob(3,0x50),m_30(0) { m_14=header; }
};
struct S00d094a0_Job : S00d094a0_DistJob {
    void** m_50;
    S00d094a0_Job() {}
    __forceinline void init(int* header,S00d094a0_Ctx* ctx) { m_06=-1; m_14=header; m_04=0x60; m_1c=ctx->m_78; m_01=3; m_18=0; m_02=1; m_00=6; m_30=0; }
    __forceinline S00d094a0_Job(int* header,S00d094a0_Ctx* ctx) : S00d094a0_DistJob(header) {
        m_00=6; m_04=0x60; m_1c=ctx->m_78;
    }
};
struct __declspec(align(16)) S00d094a0_Build {
    S00d094a0_Desc desc;
    int m_30; int m_uiItemCount; void* m_buf1; void* m_buf2;
    S00d094a0_Job job;
};
struct S00d094a0_Fallback {
    int m_00; int m_04; int m_08;
    void InitWalker(S00d094a0_Input*, S00d094a0_Ctx*);
    int getNumPrimitives();
};
void __cdecl FUN_00d9d950(S00d094a0_Tree*, int, void*, void*);
void __cdecl FillAabbArray(S00d094a0_Fallback*, int, int, void*);
void __cdecl DrawIfCountPositive(void**, S00d094a0_Tree*);

struct S00d094a0_Owner {
    int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c;
    void* m_30; void* m_34; int u38; int* m_3c;
    int u40; int u44; int u48; int u4c; int u50; int u54; int u58; int u5c;
    int u60; int u64; int u68;
    S00d094a0_Helper* m_6c;
    void FUN_00d094a0(S00d094a0_Tree** tree, S00d094a0_Input* input, S00d094a0_Ctx* ctx, S00d094a0_Queue* queue, S00d094a0_Sync* sync);
};


template<class T> struct TempArray {
    T* data; int size; int flags;
    __forceinline TempArray(int count) {
        S00d094a0_Alloc& heap=S00d094a0_heap();
        T* pointer=count?heap.elements<T>(count):0;
        int cap=count?count:0x80000000;
        data=pointer;size=count;flags=cap;
    }
    __forceinline void release() {S00d094a0_Alloc& heap=S00d094a0_heap(); if(!(flags&0x80000000))heap.ReturnMemory(data,(flags&0x3fffffff)*sizeof(T));}
    __forceinline T* begin(){return data;}
};

// @fnv 0x00d094a0
void S00d094a0_Owner::FUN_00d094a0(S00d094a0_Tree** tree, S00d094a0_Input* input, S00d094a0_Ctx* ctx, S00d094a0_Queue* queue, S00d094a0_Sync* sync) {
    if(sync && queue && input->m_04>=32) {
        S00d094a0_beginList(str_010cd130,str_010cd124);
        const int count=input->m_04;
        S00d094a0_Desc desc;
        desc.FUN_00d976d0(); desc.m_uiItemCount=count;desc.m_isMt=1;
        ctx->m_pCollisionShape->getAabb(&desc.m_kMinimumCorner,&desc.m_kMaximumCorner);
        if(*tree)(*tree)->FUN_00d978d0(&desc);
        else {S00d094a0_Tree* p=(S00d094a0_Tree*)S00d094a0_heap().AllocateMemoryBlock(0x50);*tree=p?p->Init(&desc):0;}
        *m_3c=4;
        TempArray<int> arrayA(4);
        TempArray<int> arrayB(4);
        S00d094a0_Job task(m_3c,ctx);
        task.m_10=m_6c;task.m_50=input->m_00;
        task.m_20=m_30;task.m_24=m_34;
        task.m_30=arrayA.begin();task.m_34=arrayB.begin();
        task.m_38=(*tree)->m_10;task.m_28=(*tree)->m_00;
        task.m_3c=(*tree)->total();task.m_2c=(*tree)->m_1c;task.m_40=(*tree)->m_18;
        S00d094a0_timer(str_010cd11c);
        S00d094a0_beginList(str_010cd104,str_010cd0fc);
        queue->FUN_00d04b50(&task,0);
        S00d094a0_timer(str_010cd0f4);
        sync->signal(queue,3);queue->FUN_00d051b0();
        S00d094a0_timer(str_010cd0e0);
        sync->wait();S00d094a0_timer(str_010cd0d0);
        m_6c->FUN_00d04380();S00d094a0_timer(str_010cd0c4);
        FUN_00d9d950(*tree,count,task.m_30,task.m_34);
        S00d094a0_timer(str_01076f38);S00d094a0_timer(str_010cd0b8);S00d094a0_timer(str_01076f38);
        arrayB.release();arrayA.release();
    } else {
        S00d094a0_Fallback fallback;fallback.InitWalker(input,ctx);
        const int count=fallback.getNumPrimitives();
        S00d094a0_Desc desc;desc.FUN_00d976d0();desc.m_uiItemCount=count;desc.m_isMt=0;
        ctx->m_pCollisionShape->getAabb(&desc.m_kMinimumCorner,&desc.m_kMaximumCorner);
        if(*tree)(*tree)->FUN_00d978d0(&desc);
        else {S00d094a0_Tree* p=(S00d094a0_Tree*)S00d094a0_heap().AllocateMemoryBlock(0x50);*tree=p?p->Init(&desc):0;}
        FillAabbArray(&fallback,0,count,m_30);DrawIfCountPositive(&m_30,*tree);
    }
}

namespace fnv_00d0a170 {
class hkMemoryAllocatorD0A1 {
public:
    virtual ~hkMemoryAllocatorD0A1() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD0A1 {
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD0A1* m_pStreamAllocator;

    hkMemoryAllocatorD0A1& heap() { return *m_pStreamAllocator; }
};

extern "C" hkMemoryRouterD0A1& __cdecl FUN_00c85750() throw();

class hkKdTreeCastCollector {
public:
    virtual ~hkKdTreeCastCollector() throw() {}
};

class CollectorD0A1 : public hkKdTreeCastCollector {
public:
    int unk04, unk08, unk0C, unk10, unk14;

    static void operator delete(void* p)
    {
        FUN_00c85750().heap().ReleaseBlock(p, sizeof(CollectorD0A1));
    }
    CollectorD0A1* FUN_00d0a170(unsigned int uiFlags);
};

// Destroys the hkKdTreeCastCollector base and, when uiFlags has bit 0 set, frees the CollectorD0A1 object via operator delete.
// @fnv 0x00d0a170
CollectorD0A1* CollectorD0A1::FUN_00d0a170(unsigned int uiFlags)
{
    this->hkKdTreeCastCollector::~hkKdTreeCastCollector();
    if (uiFlags & 1)
        CollectorD0A1::operator delete(this);
    return this;
}
}  // namespace fnv_00d0a170

namespace fnv_00d0b0d0 {
class hkMemoryAllocatorD0B0 {
public:
    virtual ~hkMemoryAllocatorD0B0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void unk08() throw();
    virtual void unk0C() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD0B0 {
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD0B0* m_pStreamAllocator;

    hkMemoryAllocatorD0B0& heap() { return *m_pStreamAllocator; }
};


extern "C" hkMemoryRouterD0B0& __cdecl FUN_00c85750() throw();

template <class T>
class hkArrayD0B0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD0B0() throw()
    {
        hkMemoryAllocatorD0B0& kAlloc = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReleaseBlock(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkD0B0 {
    class hkBaseObject {
    public:
        virtual ~hkBaseObject() throw() {}
    };

    class hkReferencedObject : public hkBaseObject {
    public:
        unsigned short m_usMemSizeAndFlags;
        short m_sReferenceCount;
        void FUN_00c905b0() throw();
    };
}

class hkpWorldPostSimulationListener {
public:
    virtual ~hkpWorldPostSimulationListener() throw() {}
};

namespace hkD0B0 {
    class ListenerD0B0 : public hkReferencedObject, public hkpWorldPostSimulationListener {
    };

    struct Elem12D0B0 {
        int unk00, unk04, unk08;
    };

    struct Elem16D0B0 {
        int unk00, unk04, unk08, unk0C;
    };
}

class FUN_00d0b0d0 {
public:
    ~FUN_00d0b0d0();

    hkD0B0::ListenerD0B0 m_kListener;
    int unk0C, unk10;
    hkArrayD0B0<hkD0B0::Elem12D0B0> m_kFirst;
    hkArrayD0B0<hkD0B0::Elem16D0B0> m_kSecond;
    hkArrayD0B0<hkD0B0::Elem12D0B0> m_kThird;
};

// Destroys the FUN_00d0b0d0 object, allowing member destructors to run.
// @fnv 0x00d0b0d0
FUN_00d0b0d0::~FUN_00d0b0d0()
{
}
}  // namespace fnv_00d0b0d0

inline void* operator new(unsigned int, void* location) { return location; }
struct Target {
    int unk00;
};

struct Item1 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Target m_target;
};

struct Item2 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Target m_target;
};

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_alloc;
};

void ResizeAudioStream(void* alloc, void* array, int elemSize);

template <typename T>
struct hkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(AllocHolder* h, T val) {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff)) {
            ResizeAudioStream(h->m_alloc, this, sizeof(T));
        }
        T* slot = m_data + m_iElementCount;
        __assume(slot != 0);
        new (slot) T(val);
        ++m_iElementCount;
    }
};

struct SubStruct1 {
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
    hkArray<Item1*> m_items;
};

struct Container {
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
    hkArray<SubStruct1*> m_array1;
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
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    hkArray<Item2*> m_array2;
};

// Gathers Target pointers from m_array1 items and m_array2 entries into out, skipping m_array2 entries whose m_target.unk00 is zero.
// @fnv 0x00d08ac0
void FUN_00d08ac0(hkArray<Target*>* out, int containerHandle) {
    Container* c = reinterpret_cast<Container*>(containerHandle);
    for (containerHandle = 0; containerHandle < c->m_array1.m_iElementCount; containerHandle++) {
        for (int j = 0; j < c->m_array1.m_data[containerHandle]->m_items.m_iElementCount; j++) {
            out->AddBack((AllocHolder*)&FUN_00c85750(), &c->m_array1.m_data[containerHandle]->m_items.m_data[j]->m_target);
        }
    }
    for (int k = 0; k < c->m_array2.m_iElementCount; k++) {
        if (c->m_array2.m_data[k]->m_target.unk00) {
            out->AddBack((AllocHolder*)&FUN_00c85750(), &c->m_array2.m_data[k]->m_target);
        }
    }
}

struct MarkerBuf {
    int unk0;
    int* m_cursor;
    int unk8;
    int* m_kRayEnd;
};
extern int DAT_00fdf044;
extern unsigned int DAT_0126835c;
extern char DAT_010cd224;
extern char DAT_010cd154;
extern char DAT_010cd14c;
extern char DAT_010cd140;
extern char DAT_010cd214;
extern char DAT_01076f38;

struct D9bed0Cls {
    void __thiscall FUN_00d9bed0();
};
struct D09020Cls {
    void __thiscall FUN_00d09020(int* p, void* a, void* b);
};
struct ActiveTreeBuilder {
    void __thiscall FUN_00d099a0(void* entries, void* queue, void* pool);
};
struct TreeCleanMarker {
    void __thiscall FUN_00d08550();
};
struct AllocV {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void __thiscall ReleaseBlock(void* p, int bytes);
};

struct TempArr {
    int* m_data;
    int m_iElementCount;
    int m_capFlags;
    void destroy()
    {
        hkMemoryAllocatorD08C& a = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0)
            ((AllocV&)a).ReleaseBlock(m_data, (m_capFlags & 0x3fffffff) * 4);
    }
};

struct EntListSelf {
    int unk00;
    int unk04;
    int unk08;
    D9bed0Cls* m_0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    bool m_enabled;
    int m_28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    hkpEntityD08C** m_entData;
    int m_entSize;
    int m_entCap;

    void __thiscall FUN_00d09df0(void* p1, void* p2);
};

static __forceinline void mark16(MarkerBuf* buf, char* name, char* name2, volatile unsigned int* stampOut)
{
    int* cur = buf->m_cursor;
    if (cur < buf->m_kRayEnd) {
        cur[0] = (int)name;
        cur[3] = (int)name2;
        _ReadWriteBarrier();
        *stampOut = (unsigned int)__rdtsc();
        cur[1] = (int)*stampOut;
        buf->m_cursor = cur + 4;
    }
}
static __forceinline void mark12(MarkerBuf* buf, char* name, volatile unsigned int* stampOut)
{
    int* cur = buf->m_cursor;
    if (cur < buf->m_kRayEnd) {
        cur[0] = (int)name;
        _ReadWriteBarrier();
        *stampOut = (unsigned int)__rdtsc();
        cur[1] = (int)*stampOut;
        buf->m_cursor = cur + 3;
    }
}

// Builds the active tree for this entity list, dispatching to targets and optionally updating the tree with the provided parameters.
// @fnv 0x00d09df0
void __thiscall EntListSelf::FUN_00d09df0(void* p1, void* p2)
{
    volatile unsigned int stamp;
    MarkerBuf* (__stdcall *getBuf)(int) = (MarkerBuf* (__stdcall *)(int))DAT_00fdf044;
    TempArr arr;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_capFlags = (int)0x80000000;

    mark16(getBuf(DAT_0126835c), "LtActiveTree", &DAT_010cd154, &stamp);

    m_entSize = 0;
    FUN_00d08ac0((FUN_00d08ff0_t*)&m_entData, m_28);
    if (!m_enabled)
        FUN_00d08b90((FUN_00d08ff0_t*)&m_entData, m_28);

    for (int i = 0; i < m_entSize; i++)
        DispatchToOffsetTarget(m_entData[i], 0xffff);

    mark12(getBuf(DAT_0126835c), &DAT_010cd14c, &stamp);
    mark12(getBuf(DAT_0126835c), &DAT_010cd140, &stamp);

    ((ActiveTreeBuilder*)this)->FUN_00d099a0(&m_entData, p1, p2);

    mark12(getBuf(DAT_0126835c), &DAT_01076f38, &stamp);

    if (m_enabled) {
        mark16(getBuf(DAT_0126835c), &DAT_010cd214, &DAT_010cd154, &stamp);
        arr.m_iElementCount = 0;
        FUN_00d08b90((FUN_00d08ff0_t*)&arr, m_28);
        mark12(getBuf(DAT_0126835c), &DAT_010cd14c, &stamp);
        m_0c->FUN_00d9bed0();
        mark12(getBuf(DAT_0126835c), &DAT_010cd140, &stamp);
        ((D09020Cls*)this)->FUN_00d09020((int*)&arr, p1, p2);
        mark12(getBuf(DAT_0126835c), &DAT_01076f38, (volatile unsigned int*)&p2);
    }

    ((TreeCleanMarker*)this)->FUN_00d08550();

    arr.destroy();
}

namespace RaycasterRework {

class FUN_00d9a040 : public hkpRayCastCollectorBaseD084,
                     public hkpTreeCastCallbackD084 {
public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
    float m_fEarlyOutHitFraction;

    FUN_00d9a040() throw();
};

// Default constructor that nulls all hkpRayCast pointers and sets m_fEarlyOutHitFraction to 1.0f.
// @fnv 0x00d9a040
FUN_00d9a040::FUN_00d9a040() throw()
    : m_pRayCastInput(0), m_iFilter(0), m_shapeFilter(0), m_pRayCastOutput(0),
      m_kCollector(0), m_fEarlyOutHitFraction(1.0f)
{
}

}

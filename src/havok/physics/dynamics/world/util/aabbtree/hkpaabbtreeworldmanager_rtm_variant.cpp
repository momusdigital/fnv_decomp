// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl Deallocate(void*);
extern "C" void* DAT_010ccf7c;
struct FUN_00d08330 {
    void* m_p;
    FUN_00d08330(char);
};
extern int DAT_010ccf8c;
extern void __cdecl Deallocate(void*);
struct FUN_00d08350 {
    void* m_p;
    void* __thiscall Set(void* arg);
};
struct FUN_00d083a0_class {
    void __thiscall setWorkingBuffer(int a);
};
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
void FUN_00d08ff0(FUN_00d08ff0_t* self, int arg);
extern int DAT_010ccfac;
void __cdecl Deallocate(void*);
struct FUN_00d0a150 {
    int* p;
    FUN_00d0a150(bool b);
};
extern int DAT_010ccfa0;
extern int DAT_010ccfac;
extern "C" void __cdecl Deallocate(void*);
struct FUN_00d0a1a0 {
    int* a;
    int* b;
    int __thiscall Init(int p);
};
int __fastcall FUN_00d08390(void* self, int, int value);
struct HashEntryTable { void clear(); };
struct FUN_00d08550_Class {
    void __thiscall FUN_00d08550();
};
struct FUN_00d08560_class {
    void __thiscall FUN_00d08560();
};
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
struct FUN_00cd2a00_class {
    void __thiscall FUN_00cd2a00();
};
void __stdcall FUN_00d083e0(void* arg);
struct FUN_00d08a90_class {
    void __thiscall FUN_00d08a90(void* arg);
};
struct FUN_00d08fb0_Class {
    char pad[0x54];
    char m_54;
    char m_55;
    void __thiscall FUN_00d08fb0(char* arg);
    void __thiscall FUN_00d08c90(char* arg);
};
void __cdecl FUN_00d08c90(void* self, int a);
struct FUN_00d08fd0_class {
    char pad[0x50];
    char m_50;
    char m_51;
    void __thiscall FUN_00d08fd0(int a);
    void __thiscall FUN_00d08c90(int a);
};
void __cdecl Deallocate(void*);
struct FUN_00d0a130 {
    void* p;
    void* __thiscall Set(char b);
};
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
struct FUN_00d0a1f0_Class {
    void __thiscall FUN_00d0a1f0(unsigned char value);
};
void __stdcall FUN_00d08380(int);
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
void __cdecl DispatchToOffsetTarget(FUN_00d08400_cls* pkObject, unsigned short usValue);
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
void __cdecl FUN_00d083c0();
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
void __cdecl FUN_00d08b90(hkArrayD08C<int*>& out, hkpWorldB90* world);
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
void FUN_00d08ac0(hkArray<Target*>* out, int containerHandle);
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

// @fnv 0x00d9a040
FUN_00d9a040::FUN_00d9a040() throw()
    : m_pRayCastInput(0), m_iFilter(0), m_shapeFilter(0), m_pRayCastOutput(0),
      m_kCollector(0), m_fEarlyOutHitFraction(1.0f)
{
}

}

struct FloatPtr {float* p; FloatPtr(float* q):p(q){} };
#include <xmmintrin.h>
struct Scalar {
 __m128 value;
 Scalar(float f) { value=_mm_load_ss(&f); }
 Scalar(__m128 v) { value=v; }
 __m128 spread() const { return _mm_shuffle_ps(value,value,0); }
 operator float() const { float f;_mm_store_ss(&f,value);return f; }
};
struct __declspec(align(16)) Vector {
 union { __m128 value; float x; };
 void set(__m128 a) { value=a; }
 __m128 get() const { return value; }
 void interpolate(const Vector& a,const Vector& b,const Scalar& scale);
 void add(const Vector& a,const Vector& b) { value=_mm_add_ps(a.value,b.value); }
 void sub(const Vector& a,const Vector& b) { value=_mm_sub_ps(a.value,b.value); }
 void scale(const Scalar& s) { value=_mm_mul_ps(s.spread(),value); }
};
struct Triple { Vector avg,mid,half; };
struct Pair { Vector low,high; };
struct Vertex { __m128 value; float unk10; float unk14; };
struct MatrixData {int f00,f04,f08,f0c,f10,f14;int f18,f1c;__m128 a,b,c;};
struct Transform {int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c; __m128 m_vTranslation;};
struct Obj;
struct Engine {
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
 virtual void f4(); virtual void f5(); virtual void f6();
 virtual void getBounds(Transform* transform, float value, Pair* out);
 int unk04,unk08,unk0c;
};
struct Obj {Engine* m_eng;int unk04;Transform* m_kMotionTransform;};
struct CollectorState {
 void* unk00;
 Vertex* m_pVertex;
 void* m_arg4;
 void* volatile m_arg7;
 void* m_arg8;
 Obj* m_obj;
 int m_18;
 int unk1c;
 int f20,f24; union { int f28bits; float f28; }; int f2c,f30,f34,f38,f3c;
 __m128 m40,m50,m60,m70;
 float f80,f84;
 float* m_88;
 void __thiscall FUN_00d984b0(int arg1, Obj* arg2, Vertex* arg3, void* arg4, MatrixData* arg5, FloatPtr arg6, void* volatile arg7, void* volatile arg8);
};
extern "C" const __m128 DAT_010ec7f0={1,1,1,1};
extern "C" const float DAT_01016248=0.5f;
inline void Vector::interpolate(const Vector& a,const Vector& b,const Scalar& scale) {
 __m128 weight=scale.spread();
 __m128 opposite=_mm_sub_ps(DAT_010ec7f0,weight);
 value=_mm_add_ps(_mm_mul_ps(opposite,a.value),_mm_mul_ps(b.value,weight));
}
__declspec(noalias) void __cdecl FUN_00df2750(void* output, int arg1, Triple* mid, CollectorState* self, float f);
// @fnv 0x00d984b0
void CollectorState::FUN_00d984b0(int arg1, Obj* arg2, Vertex* arg3, void* arg4, MatrixData* arg5, FloatPtr arg6, void* volatile arg7, void* volatile arg8)
{
    m_arg7=arg7;
    m_arg8=arg8;
    m_arg4=arg4;
    m_pVertex=arg3;
    m_obj=arg2;
    m_18=arg2->m_eng->unk0c;
    f20=arg5->f00; f24=arg5->f04; f28bits=arg5->f08; f2c=arg5->f0c; f30=arg5->f10; f34=arg5->f14;
    m40=arg5->a; m50=arg5->b; m60=arg5->c;
    m_88=arg6.p;
    struct Metrics {float distance,radius;}; Metrics metrics;
    metrics.radius = arg3->unk14;
    Vector diff;
    m70=_mm_sub_ps(arg3->value,arg2->m_kMotionTransform->m_vTranslation);
    diff.set(m70);
    __m128 sq=_mm_mul_ps(m70,m70);
    __m128 y=_mm_shuffle_ps(sq,sq,0x55);
    __m128 z=_mm_shuffle_ps(sq,sq,0xaa);
    __m128 sum;
    sum = _mm_add_ss(z,_mm_add_ss(y,sq));
    __m128 root=_mm_sqrt_ss(sum);
    _mm_store_ss(&metrics.distance,root);f84=metrics.distance;
    Pair out;
    f28=metrics.radius;
    arg2->m_eng->getBounds(arg2->m_kMotionTransform,arg3->unk14,&out);

    Pair* box=&out;
    Triple temp;
    temp.avg.interpolate(box->low,box->high,Scalar(DAT_01016248));
    temp.mid.add(temp.avg,diff);
    temp.half.sub(box->high,box->low);
    temp.half.scale(Scalar(DAT_01016248));
    f80=arg3->unk10;
    unsigned char result;
    FUN_00df2750(&result,arg1,&temp,this,*arg6.p);
}

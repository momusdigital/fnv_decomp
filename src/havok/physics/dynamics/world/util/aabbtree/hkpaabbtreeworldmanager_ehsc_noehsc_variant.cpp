// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


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

struct PEv { const char* name; unsigned tick; unsigned extra; };
struct PLEv : PEv { const char* first; };
struct PCEv { const char* name; float value; };
struct ProfileStream {
    int unk00;
    PEv* cursor;
    int unk08;
    PEv* end;
    void begin(const char* name, const char* first) {
        PLEv* event = (PLEv*)cursor;
        if (event < (PLEv*)end) {
            event->name = name;
            event->first = first;
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            event->tick = ticks;
            cursor = (PEv*)(event + 1);
        }
    }
    void timerT(const char* name) {
        PEv* event = cursor;
        if (event < end) {
            event->name = name;
            unsigned int ticks;
            __asm {
                rdtsc
                mov dword ptr[ticks], eax
            }
            event->tick = ticks;
            cursor = event + 1;
        }
    }
    void count(const char* name, float value) {
        PCEv* event = (PCEv*)cursor;
        if (event < (PCEv*)end) {
            event->name = name;
            event->value = value;
            cursor = (PEv*)(event + 1);
        }
    }
};

extern "C" void* DAT_00fdf044;
struct MemoryAllocator {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void release(void*, int);
};
struct ScratchAllocator { char* current; int unk04; int unk08; int unk0c; MemoryAllocator* allocator; };
struct Node;
struct NodeArrayBase {
    Node** data;
    int size;
    int capacity;
    NodeArrayBase() : data(0), size(0), capacity(0x80000000) {}
    Node*& operator[](int index) { return data[index]; }
    int GetLogicalSize() const { return size; }
    void clear() { size=0; }
    void pushBackUnchecked(Node* const& value) { data[size]=value; ++size; }
    void removeAt(int index) { --size; if (size!=index) data[index]=data[size]; }
    void ClearAndRelease(MemoryAllocator& alloc) {
        clear();
        if ((capacity&0x80000000)==0) alloc.release(data,(capacity&0x3fffffff)*4);
        data=0;
        capacity=0x80000000;
    }
};
struct NodeHeapArray : NodeArrayBase {
    ~NodeHeapArray() { ClearAndRelease(*((ScratchAllocator*)&FUN_00c85750())->allocator); }
};
struct NodeArray : NodeHeapArray {
    char* saved;
    NodeArray(int count) {
        ScratchAllocator* allocator=(ScratchAllocator*)&FUN_00c85750();
        char* memory=allocator->current;
        allocator->current+=(count*4+127)&~127;
        data=(Node**)memory;
        capacity=count|0x80000000;
        saved=memory;
    }
    ~NodeArray() {
        if (saved==(char*)data) clear();
        ((ScratchAllocator*)&FUN_00c85750())->current=saved;
    }
};
struct __declspec(align(16)) Bounds { float minX,minY,minZ,minW,maxX,maxY,maxZ,maxW; };
struct Shape {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6();
    virtual void getBounds(void*, float, Bounds*);
};
struct Node {
    Shape* shape;
    int unk04;
    void* transform;
    int unk0c; signed char ownerOffset; unsigned char unk11; unsigned short unk12; unsigned int tag;
    unsigned char active;
 void getBounds(Bounds& bounds) const { shape->getBounds(transform, 0.0f, &bounds); }
};
struct Tree {
    unsigned short FUN_00d9c610(Bounds*, Node*);
    void FUN_00d9c7d0(unsigned short);
};
struct ScanToken;
struct ByteTruth {
    char value;
    ByteTruth(bool x) : value((char)x) {}
    operator bool() const { return value != 0; }
};
struct TablePair { unsigned long key; unsigned long value; };
struct MapStorage {
    TablePair* elem; int numElems; int hashMod;
    ScanToken* first() const {
        int index=0;
        for (; index <= hashMod; ++index) if (elem[index].key != (unsigned long)-1) break;
        return (ScanToken*)(unsigned long)index;
    }
    ScanToken* next(ScanToken* token) const {
        int index=(int)(unsigned long)token+1;
        for (; index <= hashMod; ++index) if (elem[index].key != (unsigned long)-1) break;
        return (ScanToken*)(unsigned long)index;
    }
    ByteTruth valid(ScanToken* token) const { return (int)(unsigned long)token <= hashMod; }
    unsigned long key(ScanToken* token) const { return elem[(int)(unsigned long)token].key; }
    unsigned long value(ScanToken* token) const { return elem[(int)(unsigned long)token].value; }
};
struct EntryMap {
    MapStorage table;
    ScanToken* GetFirstIterator() const { return table.first(); }
    ScanToken* getNext(ScanToken* token) const { return table.next(token); }
    ByteTruth isValid(ScanToken* token) const { return table.valid(token); }
    Node* GetIteratorKey(ScanToken* token) const { return (Node*)table.key(token); }
    int getValue(ScanToken* token) const { return (int)table.value(token); }
};
void __cdecl DispatchToOffsetTarget(Node*, unsigned short);
struct ArrayHeader { int a; int b; int c; };
struct UpdateState {
    int unk00; int unk04; int unk08; Tree* tree;
    FUN_00d08ff0_t gather;
    int unk20;
    unsigned char incremental;
    int gatherMode;
    int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40;
    NodeHeapArray nodes;
    EntryMap entries;
    unsigned char fullScan; int scanStart; int scanLimit;
    unsigned char unk68; unsigned char dirty;
    __declspec(noinline) bool CheckCollidables(NodeArrayBase&);
    unsigned short FUN_00d083e0(Node*);
    bool isActive(int& value, Node* node) { unsigned short id = FUN_00d083e0(node); return value == 1 && id != 0xffff; }
    void FUN_00d08c90(Node*);
    void FUN_00d099a0(NodeArrayBase&, int, int);
    void FUN_00d094a0(FUN_00d08ff0_t*, NodeArrayBase&, int, int, int);
    void FUN_00d099d0(int, int);
};
struct CommandTimingEntry {
    const char* m_pCommandName; unsigned m_uiStartTicks; unsigned m_uiEndTicks;
    __forceinline void setTime() {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        m_uiStartTicks = ticks;
    }
};
struct TimedNameRecord : CommandTimingEntry { const char* m_pFirst; };
struct CommandFilterEntry { const char* m_pCommandName; float m_uiFilterValue; };
struct MonitorStreamD099 {
    char* m_kRayStart; char* m_kRayEnd; char* m_pRayCursor; char* m_pCurrentCommand;
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }
    char* GetStreamEnd() { return m_kRayEnd; }
    void setEnd(char* e) { m_kRayEnd = e; }
    static MonitorStreamD099& GetMonitorStream() { return *(MonitorStreamD099*)TlsGetValue(DAT_0126835c); }
};
static __forceinline void hkTimerBeginList(const char* name, const char* first) {
    MonitorStreamD099& mStream = MonitorStreamD099::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        TimedNameRecord* h = (TimedNameRecord*)mStream.GetStreamEnd();
        h->m_pCommandName = name;
        h->m_pFirst = first;
        h->setTime();
        mStream.setEnd((char*)(h + 1));
    }
}
static __forceinline void hkTimerSplit(const char* name) {
    MonitorStreamD099& mStream = MonitorStreamD099::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        CommandTimingEntry* h = (CommandTimingEntry*)mStream.GetStreamEnd();
        h->m_pCommandName = name;
        h->setTime();
        mStream.setEnd((char*)(h + 1));
    }
}
static __forceinline void hkAddValue(const char* name, float value) {
    MonitorStreamD099& mStream = MonitorStreamD099::GetMonitorStream();
    if (mStream.memoryAvailable()) {
        CommandFilterEntry* h = (CommandFilterEntry*)mStream.GetStreamEnd();
        h->m_pCommandName = name;
        h->m_uiFilterValue = value;
        mStream.setEnd((char*)(h + 1));
    }
}
// @fnv 0x00d099d0
void UpdateState::FUN_00d099d0(int arg1, int arg2) {
    NodeArray inactive(nodes.GetLogicalSize());
    bool changed = false;
    if (incremental) {
        hkTimerBeginList("LtIncrementalBuild", "StClear Tree");
        hkTimerSplit("StFind Inactivated");
        if (dirty) {
            changed = CheckCollidables(inactive);
            hkTimerSplit("StUpdate Inactive Tree");
            Tree* t = tree;
            for (int i=0;i<inactive.GetLogicalSize();++i) {
                    Node* node = inactive[i];
                    Bounds bounds;
                    node->getBounds(bounds);
                    hkAddValue("MiNum of Added Nodes", 1.0f);
                    DispatchToOffsetTarget(inactive[i], t->FUN_00d9c610(&bounds, node));
            }
            dirty = false;
        }
        hkTimerSplit("StFind Activated");
        Tree* currentTree = tree;
        for (ScanToken* it = entries.GetFirstIterator(); entries.isValid(it); it = entries.getNext(it)) {
            Node* node = entries.GetIteratorKey(it);
            int state = entries.getValue(it);
            if (isActive(state, node) && node->active == 1) {
                hkAddValue("MiNum of Removed Nodes", 1.0f);
                currentTree->FUN_00d9c7d0(FUN_00d083e0(node));
                FUN_00d08c90(node);
            }
        }
        hkTimerSplit("StUpdate Active");
        FUN_00d099a0(nodes, arg1, arg2);
        hkTimerSplit("lt");
    } else {
        hkTimerBeginList("LtDynamicBuild", "StGather");
        nodes.clear();
        FUN_00d08ff0((FUN_00d08ff0_t*)&nodes, gatherMode);
        hkTimerSplit("StClear");
        hkTimerSplit("StRebuild");
        FUN_00d094a0(&gather, nodes, gatherMode, arg1, arg2);
        hkTimerSplit("lt");
    }
    ((FUN_00d08550_Class*)this)->FUN_00d08550();
    if (changed) dirty = true;
}

struct BodyOwner {
    hkBoolRetD088 FUN_00c9bff0() const;
};
static __forceinline BodyOwner* getBodyOwner(Node* node) {
    return node->active==1 ? (BodyOwner*)((char*)node+node->ownerOffset) : 0;
}
__declspec(noinline) bool UpdateState::CheckCollidables(NodeArrayBase& output) {
    if (fullScan) {
        for (int index=nodes.GetLogicalSize()-1;index>=0;--index) {
            BodyOwner* owner=getBodyOwner(nodes[index]);
            if (owner) {
                bool active=owner->FUN_00c9bff0().m_cBooleanValue!=0;
                if (!active) {
                    output.pushBackUnchecked(nodes[index]);
                    nodes.removeAt(index);
                }
            }
        }
        return true;
    } else {
        int last=nodes.GetLogicalSize()-1;
        scanStart=scanStart<last?scanStart:last;
        int scanned=0;
        for (int count=0;count<scanLimit;++count) {
            int index=scanStart--;
            if (index<0) {scanStart=nodes.GetLogicalSize(); break;}
            BodyOwner* owner=getBodyOwner(nodes[index]);
            if (owner) {
                bool active=owner->FUN_00c9bff0().m_cBooleanValue!=0;
                if (!active) {
                    output.pushBackUnchecked(nodes[index]);
                    nodes.removeAt(index);
                }
            }
            ++scanned;
        }
        return scanned==nodes.GetLogicalSize();
    }
}

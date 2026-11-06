
// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-30 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/aabbtree/hkpaabbtreeworldmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl Deallocate(void*);
extern "C" void* DAT_010ccf7c;
struct FUN_00d08330
{
    void* m_p;
    FUN_00d08330(char);
};
extern int DAT_010ccf8c;
extern void __cdecl Deallocate(void*);
struct FUN_00d08350
{
    void* m_p;
    void* __thiscall Set(void* arg);
};
struct FUN_00d083a0_class
{
    void __thiscall setWorkingBuffer(int a);
};
struct FUN_00d08ff0_t
{
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
struct FUN_00d0a150
{
    int* p;
    FUN_00d0a150(bool b);
};
extern int DAT_010ccfa0;
extern int DAT_010ccfac;
extern "C" void __cdecl Deallocate(void*);
struct FUN_00d0a1a0
{
    int* a;
    int* b;
    int __thiscall Init(int p);
};
int __fastcall FUN_00d08390(void* self, int, int value);
struct HashEntryTable
{
    void clear();
};
struct FUN_00d08550_Class
{
    void __thiscall FUN_00d08550();
};
struct FUN_00d08560_class
{
    void __thiscall FUN_00d08560();
};
struct FUN_00d08940_class
{
    void __thiscall FUN_00d08940(void* arg);
};
struct FUN_00d08a40_class
{
    char pad0[8];
    char m_flag8;
    char pad9[0x43];
    char m_4c;
    char m_4d;
    void __thiscall ProcessFlaggedEntries(void* arg);
};
struct FUN_00cd2a00_class
{
    void __thiscall FUN_00cd2a00();
};
void __stdcall FUN_00d083e0(void* arg);
struct FUN_00d08a90_class
{
    void __thiscall FUN_00d08a90(void* arg);
};
struct FUN_00d08fb0_Class
{
    char pad[0x54];
    char m_54;
    char m_55;
    void __thiscall FUN_00d08fb0(char* arg);
    void __thiscall FUN_00d08c90(char* arg);
};
void __cdecl FUN_00d08c90(void* self, int a);
struct FUN_00d08fd0_class
{
    char pad[0x50];
    char m_50;
    char m_51;
    void __thiscall FUN_00d08fd0(int a);
    void __thiscall FUN_00d08c90(int a);
};
void __cdecl Deallocate(void*);
struct FUN_00d0a130
{
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
{}
struct FUN_00d0a1f0_Class
{
    void __thiscall FUN_00d0a1f0(unsigned char value);
};
void __stdcall FUN_00d08380(int);
struct FUN_00cd29f0_cls
{
    void FUN_00cd29f0(int iValue);
};
struct FUN_00d08400_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    signed char m_targetOffset;
};
void __cdecl DispatchToOffsetTarget(FUN_00d08400_cls* pkObject, unsigned short usValue);
struct __declspec(align(16)) hkVector4D084
{
    float x, y, z, w;
};
struct hkpWorldRayCastInputD084
{
    hkVector4D084 m_vFrom;
    hkVector4D084 m_vTo;
    bool m_bEnableShapeCollectionFilter;
    unsigned int m_uiFilterInfo;
};
struct hkpShapeRayCastOutputD084
{
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
struct hkpWorldRayCastOutputD084 : public hkpShapeRayCastOutputD084
{
    const void* m_pRootCollidable;

    hkpWorldRayCastOutputD084()
    {
        m_pRootCollidable = 0;
    }
};
struct hkpRayHitCollectorD084;
class hkpRayShapeCollectionFilterD084
{
  public:
    virtual ~hkpRayShapeCollectionFilterD084() throw();
};
class hkpRayCollidableFilterD084
{
  public:
    virtual ~hkpRayCollidableFilterD084() throw();
};
class hkpCollidableCollidableFilterD084
{
  public:
    virtual ~hkpCollidableCollidableFilterD084() throw();
};
class hkpShapeCollectionFilterD084
{
  public:
    virtual ~hkpShapeCollectionFilterD084() throw();
};
class hkReferencedObjectD084
{
  public:
    virtual ~hkReferencedObjectD084() throw();
    int m_usMemSizeAndFlags;
};
class hkpCollisionFilterD084 : public hkReferencedObjectD084,
                               public hkpCollidableCollidableFilterD084,
                               public hkpShapeCollectionFilterD084,
                               public hkpRayShapeCollectionFilterD084,
                               public hkpRayCollidableFilterD084
{
};
class hkpRayCastCollectorBaseD084
{
  public:
    virtual void CollectRayHit() throw();
};
class hkpTreeCastCallbackD084
{
  public:
    virtual float processLeaf() throw();
};
class FUN_00d9a040 : public hkpRayCastCollectorBaseD084, public hkpTreeCastCallbackD084
{
  public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
    int m_1c;

    FUN_00d9a040() throw();
};
class hkpBroadPhaseCastCollectorD084
{
  public:
    virtual void ReleaseCollector() throw();
};
class hkpWorldRayCasterD084 : public hkpBroadPhaseCastCollectorD084
{
  public:
    const hkpWorldRayCastInputD084* m_pRayCastInput;
    const hkpRayCollidableFilterD084* m_iFilter;
    const hkpRayShapeCollectionFilterD084* m_shapeFilter;
    hkpWorldRayCastOutputD084* m_pRayCastOutput;
    hkpRayHitCollectorD084* m_kCollector;
};
struct hkBoolD084
{
    char m_cBooleanValue;
    hkBoolD084(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
hkBoolD084 __cdecl FUN_00d98ca0(void* pkBroadPhase, const hkVector4D084& kFrom, const hkVector4D084& kTo,
                                hkpWorldRayCasterD084* pkCaster) throw();
void __cdecl FUN_00d1bd00(void* pkTree, const hkVector4D084& kFrom, const hkVector4D084& kTo,
                          hkpTreeCastCallbackD084* pkCaster, float fEarlyOut) throw();
class hkpRayCastQueryD084
{
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

    void CastRay(const hkpWorldRayCastInputD084& kInput, const hkpCollisionFilterD084* pkFilter,
                 hkpRayHitCollectorD084* pkCollector) const throw();
};
template <class T> class hkArrayD085
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
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
class hkBroadPhaseD085
{
  public:
    void FUN_00d9c7d0(unsigned short id);
};
struct hkCollidableD085
{
    int unk00;
};
struct hkEntityD085
{
    int unk00[4];
    hkCollidableD085 m_kCollidable;
};
class hkHandlerD085
{
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
struct PlaceTagD088
{
};
inline void* operator new(unsigned int, void* p, PlaceTagD088) throw()
{
    __assume(p != 0);
    return p;
}
inline void operator delete(void*, void*, PlaceTagD088) throw()
{}
template <class T> struct hkArrayD088
{
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
struct hkBoolRetD088
{
    char m_cBooleanValue;
    hkBoolRetD088() throw()
    {}
};
class hkpEntityD088
{
  public:
    hkBoolRetD088 FUN_00c9bff0() const throw();
};
struct hkpCollidableD088
{
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const void* m_parent;
    signed char m_iOwnerOffset;
    char m_pad11[3];
    unsigned int m_iOwnerObjectOffset;
    char m_type;

    hkpEntityD088* getOwner() const
    {
        return (hkpEntityD088*)((char*)this + m_iOwnerOffset);
    }
};
class hkpEntityListD088
{
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
        if (pkCollidable->m_type == 1)
        {
            hkpEntityD088* pkEntity = pkCollidable->getOwner();
            if (pkEntity && !pkEntity->FUN_00c9bff0().m_cBooleanValue)
            {
                kInactive.pushBackUnchecked(m_kCollidables.m_data[i]);
                m_kCollidables.removeAt(i);
            }
        }
    }

    bool CheckCollidables(hkArrayD088<hkpCollidableD088*>& kInactive) throw();
};
struct hkObjectE02;
struct hkLoaderE02
{
    int Get(char const* name, hkObjectE02** out);
};
struct Router
{
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
struct Sink
{
    void FUN_00cb1870(void*, int, int);
};
struct FUN_00d08940_shell
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
    hkLoaderE02 loader;
    void FUN_00d08940(char const* name);
};
struct FUN_00d9a4d0_class
{
    void __thiscall GetEntryOffset(unsigned int value);
};
struct FUN_00d08c70_class
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d9a4d0_class* unk0C;
    void __thiscall FUN_00d08c70(void* arg);
};
class hkMemoryAllocatorD08C;
struct hkMemoryRouterD08C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD08C* m_pStreamAllocator;
    hkMemoryAllocatorD08C& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD08C& __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);
template <class T> __forceinline void constructWithCopyD08C(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <class T> class hkArrayD08C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
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
class hkpEntityListD08C
{
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
class hkObjD099
{
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
struct FUN_00d0a1e0_class
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
    char unk68;
    char __thiscall FUN_00d0a1e0();
};
extern int DAT_010ccfcc;
extern int DAT_010ccfe0;
extern int DAT_010ccfec;
extern float DAT_0104da4c;
__declspec(align(16)) struct S00d08740_coll
{
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
struct S00d08740_cls
{
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
    void Collect(void* kFrom, void* kTo, void* pkRoot, void* pkFilter, void* pkShapeFilter, void* pkOutput,
                 void* pkCollector);
};
class hkMemoryAllocatorD089;
struct hkMemoryRouterD089
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD089* m_pStreamAllocator;
    hkMemoryAllocatorD089& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace fnvc_adapt {
extern "C" hkMemoryRouterD089* __cdecl FUN_00c85750();
}
enum hkResultD089
{
    HK_SUCCESS = 0,
    HK_FAILURE = 1
};
class hkMapBaseD089
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkResultD089 LookupBucketValue(unsigned int key, unsigned int* out) const;
    int FUN_00cb1870(hkMemoryAllocatorD089& alloc, unsigned int key, unsigned int val);
};
class OwnerD089
{
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
struct hkpCollidableD08
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_broadPhaseId;
    signed char m_cBroadPhaseType;
};
struct hkpEntityD08
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkpCollidableD08 m_kCollidable;
};
struct hkpSimulationIslandD08
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
    hkpEntityD08** m_kActorEntries;
    int m_iActorEntryCount;
};
class hkpPrimaryD08
{
  public:
    virtual ~hkpPrimaryD08();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
class hkpIslandListenerD08
{
  public:
    virtual void islandAddedCallback(hkpSimulationIslandD08* island);
    virtual void FUN_00d089f0(hkpSimulationIslandD08* island);
};
class TrackerD08 : public hkpPrimaryD08, public hkpIslandListenerD08
{
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
__declspec(align(16)) struct S00d0a490_Obj
{
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
struct S00d0a490_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int __thiscall CallSubroutine(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
};
void __cdecl FUN_00d083c0();
struct hkpEntityB90
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_kCollidable;
};
struct hkpSimulationIslandB90
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44;
    hkArrayD08C<hkpEntityB90*> m_kActorEntries;
};
struct hkpWorldB90
{
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
struct MonitorEvent
{
    const char* tag;
    unsigned int time;
    unsigned int extra;
};
struct MonitorStream
{
    int unk00;
    MonitorEvent* current;
    int unk08;
    MonitorEvent* end;
};
struct UpdateOwner
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
struct A1_00d0a200
{
    A1_00d0a200();
    virtual void FUN_00d0a200();
    char pad[0x10];
};
struct A2_00d0a200
{
    A2_00d0a200();
    virtual void FUN_00d0a200();
};
struct Own_00d0a200 : A1_00d0a200, A2_00d0a200
{
    Own_00d0a200();
    virtual void key_fn();
// @fnv 0x00d0a200
    void FUN_00d0a200();
};
Own_00d0a200::Own_00d0a200()
{}
void Own_00d0a200::key_fn()
{}
Own_00d0a200* make_00d0a200()
{
    static Own_00d0a200 o;
    return &o;
}
// Adjustor thunk: the secondary-base (+0x20) vtable entry for an override defined on the derived class.
class D0A230Primary
{
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
class D0A230Secondary
{
  public:
    virtual void FUN_00d0a230();
};
class D0A230Listener : public D0A230Primary, public D0A230Secondary
{
  public:
    D0A230Listener();
// @fnv 0x00d0a230
    virtual void FUN_00d0a230();
};
D0A230Listener::D0A230Listener()
{}

#include <xmmintrin.h>
extern const float DAT_01011d78;
extern const __m128 DAT_010c7170;

class hkMemoryAllocatorD08C
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int numBytes);
};

void __cdecl FUN_00c908c0(hkMemoryAllocatorD08C* alloc, void* arr, int newCap, int elemSize);

struct S00d09020_Vec
{
    __m128 m_vComponents;
    void mul(const S00d09020_Vec& b)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, b.m_vComponents);
    }
    void mulR(const S00d09020_Vec& b)
    {
        m_vComponents = _mm_mul_ps(b.m_vComponents, m_vComponents);
    }
    void sub(const S00d09020_Vec& b)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, b.m_vComponents);
    }
    void SetProduct(const S00d09020_Vec& a, const S00d09020_Vec& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct S00d09020_Aabb
{
    S00d09020_Vec m_kMinimumCorner;
    S00d09020_Vec m_kMaximumCorner;
};

struct S00d09020_Shape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void getAabb(int a, float tol, S00d09020_Aabb* out);
};

struct S00d09020_Elem
{
    S00d09020_Shape* m_pCollisionShape;
    int unk04;
    int m_08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    unsigned int m_kMinimumCorner[4];
    unsigned int m_kMaximumCorner[4];
};

struct S00d09020_Arg
{
    S00d09020_Elem** m_data;
    int m_iElementCount;
};

template <class T> struct S00d09020_Arr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S00d09020_Arr() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~S00d09020_Arr()
    {
        hkMemoryAllocatorD08C& a = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void reserve(int n)
    {
        hkMemoryAllocatorD08C& a = FUN_00c85750().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int c = cap * 2;
            FUN_00c908c0(&a, this, n < c ? c : n, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

template <class T> struct S00d09020_Local : public S00d09020_Arr<T>
{
    T* m_pStackAllocation;
    S00d09020_Local(int n)
    {
        hkMemoryRouterD08C& r = FUN_00c85750();
        char* top = (char*)r.m_00;
        r.m_00 = (int)(top + ((n * sizeof(T) + 0x7f) & ~0x7f));
        this->m_data = (T*)top;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = (T*)top;
    }
    ~S00d09020_Local()
    {
        T* mem = m_pStackAllocation;
        if (mem == this->m_data)
            this->m_iElementCount = 0;
        FUN_00c85750().m_00 = (int)mem;
    }
};

struct S00d09020_Builder
{
    void FUN_00d9ce50(S00d09020_Aabb* aabbs, S00d09020_Elem** elems, int n, S00d09020_Arr<unsigned short>* out);
};

struct D090Rows
{
    S00d09020_Vec m_offset;
    S00d09020_Vec m_unused;
    S00d09020_Vec m_vScale;
};
struct D090Phase
{
    S00d09020_Vec m_pHeadNode;
    S00d09020_Vec m_iSecondInteger;
    D090Rows m_rows;
};
struct S00d09020_Inner
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74;
    D090Phase* m_78;
};

__forceinline void S00d09020_trace(const char* tag, volatile unsigned int& ticks)
{
    MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0126835c);
    MonitorEvent* e = s->current;
    if (e < s->end)
    {
        e->tag = tag;
        _ReadWriteBarrier();
        ticks = (unsigned int)__rdtsc();
        e->time = ticks;
        s->current = (MonitorEvent*)((char*)e + 12);
    }
}

__forceinline void S00d09020_set(S00d09020_Vec& v, float x, float y, float z, float w)
{
    v.m_vComponents = _mm_setr_ps(x, y, z, w);
}

struct S00d09020_This
{
    int unk00;
    int unk04;
    int unk08;
    S00d09020_Builder* m_builder;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    S00d09020_Inner* m_inner;
    void FUN_00d09020(S00d09020_Arg* arg, int p2, int p3);
};

// @fnv 0x00d09020
void S00d09020_This::FUN_00d09020(S00d09020_Arg* arg, int p2, int p3)
{
    union BuilderTime
    {
        S00d09020_Builder* ptr;
        volatile unsigned int tick;
    } builder;
    builder.ptr = m_builder;
    volatile unsigned int timestamp;
    int n = arg->m_iElementCount;

    S00d09020_Local<S00d09020_Aabb> aabbs(n);
    aabbs.SetSizeAndGrow(n);
    S00d09020_Local<S00d09020_Elem*> elems(n);
    elems.SetSizeAndGrow(n);

    {
        MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0126835c);
        MonitorEvent* e = s->current;
        if (e < s->end)
        {
            e->tag = "Ttprepare";
            _ReadWriteBarrier();
            timestamp = (unsigned int)__rdtsc();
            e->time = timestamp;
            s->current = e + 1;
        }
    }
    const D090Rows& xf = m_inner->m_78->m_rows;
    for (int i = 0; i < n; i++)
    {
        const unsigned int* q = arg->m_data[i]->m_kMinimumCorner;
        S00d09020_Aabb* base = aabbs.m_data;
        if (q[0] <= q[4])
        {
            S00d09020_Aabb* out = &base[i];
            S00d09020_Vec retained;
            S00d09020_set(retained, (float)q[0], (float)q[1], (float)q[2], 0.0f);
            out->m_kMinimumCorner.m_vComponents = retained.m_vComponents;
            S00d09020_set(out->m_kMaximumCorner, (float)q[4], (float)q[5], (float)q[6], 0.0f);
            __m128 scale = xf.m_vScale.m_vComponents;
            __m128 t = _mm_shuffle_ps(scale, _mm_unpackhi_ps(scale, DAT_010c7170), 0xc4);
            __m128 r = _mm_rcp_ps(t);
            __m128 inv = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, t), r));
            __m128 product = inv;
            product = _mm_mul_ps(product, retained.m_vComponents);
            out->m_kMinimumCorner.m_vComponents = product;
            S00d09020_Vec* hi = (S00d09020_Vec*)out + 1;
            hi->m_vComponents = _mm_mul_ps(hi->m_vComponents, inv);
            out->m_kMinimumCorner.m_vComponents =
                _mm_sub_ps(_mm_load_ps((const float*)&out->m_kMinimumCorner), xf.m_offset.m_vComponents);
            out->m_kMaximumCorner.sub(xf.m_offset);
        }
        else
        {
            arg->m_data[i]->m_pCollisionShape->getAabb(arg->m_data[i]->m_08, 0.0f, &base[i]);
        }
        elems.m_data[i] = arg->m_data[i];
    }
    {
        MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0126835c);
        MonitorEvent* e = s->current;
        if (e < s->end)
        {
            e->tag = DAT_010c41f8;
            _ReadWriteBarrier();
            timestamp = (unsigned int)__rdtsc();
            e->time = timestamp;
            s->current = e + 1;
        }
    }

    S00d09020_Arr<unsigned short> ids;
    {
        MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0126835c);
        MonitorEvent* e = s->current;
        if (e < s->end)
        {
            e->tag = "Ttbuild";
            _ReadWriteBarrier();
            timestamp = (unsigned int)__rdtsc();
            e->time = timestamp;
            s->current = e + 1;
        }
    }
    if (n > 0)
        builder.ptr->FUN_00d9ce50(aabbs.m_data, elems.m_data, n, &ids);
    {
        MonitorStream* s = (MonitorStream*)TlsGetValue(DAT_0126835c);
        MonitorEvent* e = s->current;
        if (e < s->end)
        {
            e->tag = DAT_010c41f8;
            _ReadWriteBarrier();
            builder.tick = (unsigned int)__rdtsc();
            e->time = builder.tick;
            s->current = e + 1;
        }
    }

    for (int j = 0; j < n; j++)
        DispatchToOffsetTarget((FUN_00d08400_cls*)arg->m_data[j], ids.m_data[j]);
}

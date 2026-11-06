
// src/havok/physics/dynamics/world/util/kdtree/hkpkdtreeworldmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/kdtree/hkpkdtreeworldmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkpKdTreeWorldManager
{
    int m_kPointA;
    int m_kPointB;
    char m_iThirdValue;
    char m_iFourthElementInteger;
    char m_usTrailingValue;
    char m_f;
    char m_g;
    char m_h;
    void __thiscall FUN_00d0a2b0(void* p);
};

// @fnv 0x00d0a2b0
void __thiscall hkpKdTreeWorldManager::FUN_00d0a2b0(void* p)
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x10))
        m_iThirdValue = 1;
}

// @fnv 0x00d0ad90
void __fastcall setUpToDate(char* self, int unused, char flag)
{
    self[0x20] = flag == 0;
}

struct FUN_00d0a270_StandIn
{
    void __thiscall FUN_00d0a270(int);
};

struct FUN_00d0a340_StandIn
{
    int m_kPointA;
    int m_kPointB;
    char m_iThirdValue;
    char m_iFourthElementInteger;
    char m_usTrailingValue;
    char m_f;
    char m_g;
    char m_h;

    void __thiscall SetFlagOrForward(int);
};

// @fnv 0x00d0a340
void __thiscall FUN_00d0a340_StandIn::SetFlagOrForward(int arg)
{
    if (m_h == 0)
    {
        m_g = 1;
        return;
    }

    return reinterpret_cast<FUN_00d0a270_StandIn*>(reinterpret_cast<char*>(this) - 0x14)->FUN_00d0a270(arg);
}

struct FUN_00c917a0_shell
{
    void FUN_00c917a0(void*);
};

struct FUN_00c917f0_shell
{
    void FUN_00c917f0(void*);
};

struct FUN_00d97850_shell
{
    void ClearBuffers();
};

void* __cdecl _D1A0E0GetMemoryRouter();

extern int DAT_010cd278;
extern int DAT_010cd25c;
extern int DAT_010cd244;
extern int _DAT_0102e388;
extern int DAT_0104e3d0;
extern int $SG5957;

struct FUN_00d0a4f0
{
    void* m_ppVirtualMethodTable;  // +0x00
    char pad[0x0c];  // +0x04..0x0f
    void* m_ptr10;   // +0x10
    void* m_ptr14;   // +0x14
    void* m_ptr18;   // +0x18
    void* m_ptr1c;   // +0x1c
    ~FUN_00d0a4f0();
};

// @fnv 0x00d0a4f0
FUN_00d0a4f0::~FUN_00d0a4f0()
{
    *(int*)this = (int)&DAT_010cd278;
    *(int*)((char*)this + 0x14) = (int)&DAT_010cd25c;
    *(int*)((char*)this + 0x18) = (int)&DAT_010cd244;

    ((FUN_00c917a0_shell*)*(void**)((char*)this + 0x1c))->FUN_00c917a0((char*)this + 0x14);
    ((FUN_00c917f0_shell*)*(void**)((char*)this + 0x1c))->FUN_00c917f0((char*)this + 0x18);

    void* p = *(void**)((char*)this + 0x10);
    if (p)
    {
        ((FUN_00d97850_shell*)p)->ClearBuffers();
        void* router = _D1A0E0GetMemoryRouter();
        void* mgr = *(void**)((char*)router + 0x10);
        void** vtbl = *(void***)mgr;
        void(__thiscall * fn)(void*, void*, int) = *(void(__thiscall**)(void*, void*, int))(vtbl + 2);
        fn(mgr, p, 0x50);
    }

    *(int*)this = (int)&_DAT_0102e388;
    *(int*)((char*)this + 0x18) = (int)&DAT_0104e3d0;
    *(int*)((char*)this + 0x14) = (int)&$SG5957;
}

struct FUN_00d0a290_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char unk0B;
    unsigned char m_flag0C;

    void SetFlag0C(int unused);
};

// @fnv 0x00d0a290
void FUN_00d0a290_cls::SetFlag0C(int unused)
{
    m_flag0C = 1;
}

struct FUN_00d0ad80_This
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char unk20;
};

class FUN_00d0ad80_Class : public FUN_00d0ad80_This
{
  public:
    bool __thiscall isUpToDate();
};

// @fnv 0x00d0ad80
bool FUN_00d0ad80_Class::isUpToDate()
{
    return this->unk20 == '\0';
}

struct FUN_00d0a360_Arg
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct FUN_00d0a360_Owner
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;

    void __thiscall HandleArg(int arg);
};

// If the argument's field at offset 0x10 is nonzero, sets unk08 when unk09 is zero, otherwise calls FUN_00d0a270 on the object 0x18 bytes before this.
// @fnv 0x00d0a360
void __thiscall FUN_00d0a360_Owner::HandleArg(int arg)
{
    FUN_00d0a360_Arg* p = reinterpret_cast<FUN_00d0a360_Arg*>(arg);
    if (p->unk10 != 0)
    {
        if (unk09 == 0)
        {
            unk08 = 1;
        }
        else
        {
            reinterpret_cast<FUN_00d0a270_StandIn*>(reinterpret_cast<char*>(this) - 0x18)->FUN_00d0a270(arg);
        }
    }
}

template <typename T> inline void D0A6A0_constructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; ++i)
    {
        p[i] = t;
    }
}

struct D0A6A0_Entity;

struct D0A6A0_EntityArray
{
    D0A6A0_Entity** m_data;
    int m_iElementCount;
};

struct D0A6A0_Collidable
{
    int unk00;
};

struct D0A6A0_Entity
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D0A6A0_Collidable m_kCollidable;
};

struct D0A6A0_Island
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
    D0A6A0_Entity** m_kActorEntries;
    int m_iActorEntryCount;
};

struct D0A6A0_IslandArray
{
    D0A6A0_Island** m_data;
    int m_iElementCount;
};

struct D0A6A0_Broadphase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual int GetBroadphaseType();
};

struct D0A6A0_World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    D0A6A0_Island* m_pFixedIsland;
    D0A6A0_Entity* m_pFixedRigidBody;
    D0A6A0_IslandArray m_activeIslands;
    int unk30;
    D0A6A0_IslandArray m_inactiveIslands;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    D0A6A0_Broadphase* m_pJobSemaphore;
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
    D0A6A0_EntityArray m_kPhantoms;
};

struct D0A6A0_Allocator;
void FUN_00c908c0(D0A6A0_Allocator& alloc, void* arr, int numElem, int sizeElem);

struct D0A6A0_CollidableArray
{
    D0A6A0_Collidable** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void reserve(D0A6A0_Allocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, 4);
        }
    }
    void pushBackUnchecked(D0A6A0_Collidable* c)
    {
        D0A6A0_constructWithCopy<D0A6A0_Collidable*>(m_data + m_iElementCount, 1, c);
        m_iElementCount++;
    }
};

struct D0A6A0_Allocator;

struct D0A6A0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D0A6A0_Allocator* m_pStreamAllocator;

    D0A6A0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

D0A6A0_Router& FUN_00c85750();

struct D0A6A0_Manager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    D0A6A0_World* m_pOwningWorld;

    void CollectCollidables(D0A6A0_CollidableArray& out);
};

// @fnv 0x00d0a6a0
void D0A6A0_Manager::CollectCollidables(D0A6A0_CollidableArray& aCollidables)
{
    aCollidables.m_iElementCount = 0;
    int n = m_pOwningWorld->m_pJobSemaphore->GetBroadphaseType();
    aCollidables.reserve(FUN_00c85750().heap(), n);

    {
        D0A6A0_IslandArray& islands = m_pOwningWorld->m_activeIslands;
        for (int i = 0; i < islands.m_iElementCount; i++)
        {
            for (int j = 0; j < islands.m_data[i]->m_iActorEntryCount; j++)
            {
                aCollidables.pushBackUnchecked(&islands.m_data[i]->m_kActorEntries[j]->m_kCollidable);
            }
        }
    }
    {
        D0A6A0_IslandArray& islands = m_pOwningWorld->m_inactiveIslands;
        for (int i = 0; i < islands.m_iElementCount; i++)
        {
            for (int j = 0; j < islands.m_data[i]->m_iActorEntryCount; j++)
            {
                aCollidables.pushBackUnchecked(&islands.m_data[i]->m_kActorEntries[j]->m_kCollidable);
            }
        }
    }
    {
        D0A6A0_EntityArray& phantoms = m_pOwningWorld->m_kPhantoms;
        for (int i = 0; i < phantoms.m_iElementCount; i++)
        {
            D0A6A0_Collidable* c = &phantoms.m_data[i]->m_kCollidable;
            if (c->unk00 != 0)
            {
                aCollidables.pushBackUnchecked(c);
            }
        }
    }
    {
        D0A6A0_Island* pFixedIsland = m_pOwningWorld->m_pFixedIsland;
        D0A6A0_Entity* fixedBody = m_pOwningWorld->m_pFixedRigidBody;
        for (int i = 0; i < pFixedIsland->m_iActorEntryCount; i++)
        {
            D0A6A0_Entity* pEntity = pFixedIsland->m_kActorEntries[i];
            if (pEntity != fixedBody)
            {
                aCollidables.pushBackUnchecked(&pEntity->m_kCollidable);
            }
        }
    }
}

struct FUN_00d0ac40_Owner
{
    void FUN_00d0a810(int a, int b, int c, int d);
    void FUN_00d0a560(int a, int b);
    void FUN_00d0ac40(int a, int b, int c, int d);
};
// Calls FUN_00d0a810 with all four arguments when c and d are both nonzero, otherwise calls FUN_00d0a560 with a and b.
// @fnv 0x00d0ac40
void FUN_00d0ac40_Owner::FUN_00d0ac40(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    if (aiArg3 && aiArg4)
    {
        FUN_00d0a810(aiArg1, aiArg2, aiArg3, aiArg4);
    }
    else
    {
        FUN_00d0a560(aiArg1, aiArg2);
    }
}

namespace fnv_00d0adc0 {
class hkMemoryAllocatorD0A
{
  public:
    virtual ~hkMemoryAllocatorD0A() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD0A
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD0A* m_pStreamAllocator;

    hkMemoryAllocatorD0A& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterD0A& __cdecl FUN_00c85750() throw();

class hkObjD0AD : public FUN_00d0a4f0
{
  public:
    hkObjD0AD* FUN_00d0adc0(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkObjD0AD*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

// Runs the base destructor, and if bit 0 of uiFlags is set, frees this object through the heap allocator; returns this.
// @fnv 0x00d0adc0
hkObjD0AD* hkObjD0AD::FUN_00d0adc0(unsigned int uiFlags) throw()
{
    this->FUN_00d0a4f0::~FUN_00d0a4f0();
    if (uiFlags & 1)
        hkObjD0AD::operator delete(this);
    return this;
}
}  // namespace fnv_00d0adc0

namespace fnv_00d9d800 {
struct BSAudioVtbl
{
    virtual void unk00();
    virtual int unk04(int size);
};

struct BSAudio
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    BSAudioVtbl* unk10;
};

BSAudio* __cdecl FUN_00c85750();

// Calls FUN_00c85750 twice and stores the result of unk10->unk04(index * 16) into out[0] and out[1].
// @fnv 0x00d9d800
void __cdecl GetAudioPair(int* paiOut, int index)
{
    BSAudio* a = FUN_00c85750();
    paiOut[0] = a->unk10->unk04(index * 16);
    BSAudio* b = FUN_00c85750();
    paiOut[1] = b->unk10->unk04(index * 16);
}
}  // namespace fnv_00d9d800

struct hkResultD0A3
{
    int m_pClassEnum;
    hkResultD0A3()
    {}
};

struct hkBase0D0A3
{
    int unk00[4];
};
struct hkBaseBD0A3
{
    int unk00;
};
struct hkBaseAD0A3
{
    int unk00;
};

class hkPhantomD0A3 : public hkBase0D0A3, public hkBaseBD0A3, public hkBaseAD0A3
{
};

struct hkInputD0A3
{
    int unk00[4];
    int m_10;
};

class hkCollectorD0A3
{
  public:
    hkCollectorD0A3(hkInputD0A3* input, hkPhantomD0A3* phantom, int filter)
    {
        m_iFilter = filter;
        m_bHasHit = 0;
        m_pRayCastInput = input;
        m_kPointA = phantom;
        m_kPointB = phantom;
    }
    virtual void AddHit(void* hit);

    hkInputD0A3* m_pRayCastInput;
    hkBaseAD0A3* m_kPointA;
    hkBaseBD0A3* m_kPointB;
    int m_iFilter;
    int m_bHasHit;
};

hkResultD0A3 __cdecl FUN_00d98ca0(void* world, hkInputD0A3* input, int* inputBody, hkCollectorD0A3* collector);

class hkQueryD0A3
{
  public:
    int unk00[4];
    void* m_pOwningWorld;

    void RayCast(hkInputD0A3* input, hkPhantomD0A3* phantom, int filter);
};

// Creates a collector with the given input, phantom and filter, then calls FUN_00d98ca0 on m_pOwningWorld to perform the ray cast.
// @fnv 0x00d0a390
void hkQueryD0A3::RayCast(hkInputD0A3* input, hkPhantomD0A3* phantom, int filter)
{
    hkCollectorD0A3 collector(input, phantom, filter);
    FUN_00d98ca0(m_pOwningWorld, input, &input->m_10, &collector);
}

struct __declspec(align(16)) hkVector4D0A4
{
    float x, y, z, w;
};

struct hkBoolD0A4
{
    hkBoolD0A4()
    {}
    char m_cBooleanValue;
};

struct __declspec(align(16)) RayCastOutputD0A4
{
    RayCastOutputD0A4()
    {
        m_fHitFraction = 1.0f;
        m_iExtraInfo = -1;
        m_uiShapeKeys[0] = -1;
        m_uiShapeKeyIndex = 0;
        m_pRootCollidable = 0;
    }
    hkVector4D0A4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int unk18;
    int unk1c;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4c;
    const void* m_pRootCollidable;
};

struct QueryFilterD0A4
{
    int m_iFilter;
};
struct CdBodyD0A4
{
    int m_kCollisionBody;
};
struct QueryOwnerD0A4
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct QueryD0A4 : QueryOwnerD0A4, CdBodyD0A4, QueryFilterD0A4
{
};

struct RayInputD0A4
{
    hkVector4D0A4 m_vFrom;
    hkVector4D0A4 m_vTo;
};

class RayCollectorD0A4
{
  public:
    RayCollectorD0A4(const RayInputD0A4* pkInput, QueryD0A4* pkQuery, int iUser, RayCastOutputD0A4* pkOutput)
    {
        m_pkInput = pkInput;
        m_iUser = iUser;
        m_pkFilter = pkQuery;
        m_pkBody = pkQuery;
        m_pkOutput = pkOutput;
    }
    virtual void CollectRayHit();
    const RayInputD0A4* m_pkInput;
    QueryFilterD0A4* m_pkFilter;
    CdBodyD0A4* m_pkBody;
    RayCastOutputD0A4* m_pkOutput;
    int m_iUser;
};

hkBoolD0A4 __cdecl FUN_00d98ca0(void* pkShape, const RayInputD0A4* pkInput, const hkVector4D0A4* pkTo,
                                RayCollectorD0A4* pkCollector);

struct RayCasterD0A4
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pkShape;
    void CastRay(const RayInputD0A4* pkInput, QueryD0A4* pkQuery, int iUser);
};

// Creates a RayCollectorD0A4 and RayCastOutputD0A4, then calls FUN_00d98ca0 to cast a ray against m_pkShape using pkInput and pkQuery.
// @fnv 0x00d0a400
void RayCasterD0A4::CastRay(const RayInputD0A4* pkInput, QueryD0A4* pkQuery, int iUser)
{
    RayCollectorD0A4 kCollector(pkInput, pkQuery, iUser, 0);
    RayCastOutputD0A4 kOutput;
    kCollector.m_pkOutput = &kOutput;
    FUN_00d98ca0(m_pkShape, pkInput, &pkInput->m_vTo, &kCollector);
}

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern const char str_010cd2d8[];
extern const char str_010cd2cc[];
extern const char str_010cd2c0[];
extern const char str_01076f38[];
struct D0AMon
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pFreeList;
};
struct D0ATimer12
{
    const char* m_name;
    unsigned int m_ticks;
    unsigned int unk08;
};
struct D0ATimer16
{
    const char* m_name;
    unsigned int m_ticks;
    unsigned int unk08;
    const char* m_name2;
};
struct D0ARange
{
    void* m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
};
struct D0AHeap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void bufDealloc(void* p, int bytes);
};
struct D0ARouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    D0AHeap* m_pStreamAllocator;
};
namespace fnvc_adapt {
D0ARouter* __cdecl FUN_00c85750();
}
struct D0ASub
{
    int unk00;
};
struct D0AObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    D0ASub m_sub;
    int unk14;
    int unk18;
    int unk1c;
    char m_flag;
    void CollectCollidables(D0ARange*);
    void FUN_00d0ac40(D0ASub*, D0ARange*, int, int);
    void CollectAndProcessCollidables(int a, int b);
};
// Records timing markers, collects collidables into a range, processes them via FUN_00d0ac40, and frees the result buffer if it was heap-allocated.
// @fnv 0x00d0ac70
void D0AObj::CollectAndProcessCollidables(int a, int b)
{
    {
        D0AMon* mon = (D0AMon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_pFreeList)
        {
            volatile unsigned int ticks;
            D0ATimer16* t = (D0ATimer16*)pos;
            t->m_name = str_010cd2d8;
            t->m_name2 = str_010cd2cc;
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            t->m_ticks = ticks;
            mon->m_kRayEnd = pos + sizeof(D0ATimer16);
        }
    }
    D0ARange r;
    r.m_kPointA = 0;
    r.m_kPointB = 0;
    r.m_iThirdValue = (int)0x80000000;
    CollectCollidables(&r);
    {
        D0AMon* mon = (D0AMon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_pFreeList)
        {
            volatile unsigned int ticks;
            D0ATimer12* t = (D0ATimer12*)pos;
            t->m_name = str_010cd2c0;
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            t->m_ticks = ticks;
            mon->m_kRayEnd = pos + sizeof(D0ATimer12);
        }
    }
    FUN_00d0ac40(&m_sub, &r, a, b);
    m_flag = 0;
    {
        D0AMon* mon = (D0AMon*)TlsGetValue(DAT_0126835c);
        char* pos = mon->m_kRayEnd;
        if (pos < mon->m_pFreeList)
        {
            volatile unsigned int ticks;
            D0ATimer12* t = (D0ATimer12*)pos;
            t->m_name = str_01076f38;
            _ReadWriteBarrier();
            ticks = (unsigned int)__rdtsc();
            t->m_ticks = ticks;
            mon->m_kRayEnd = pos + sizeof(D0ATimer12);
        }
    }
    D0ARouter* router = fnvc_adapt::FUN_00c85750();
    D0AHeap* heap = router->m_pStreamAllocator;
    int cap = r.m_iThirdValue;
    r.m_kPointB = 0;
    if ((cap & 0x80000000) == 0)
        heap->bufDealloc(r.m_kPointA, (cap & 0x3fffffff) * 4);
}

class hkReferencedObjectD0A
{
  public:
    hkReferencedObjectD0A() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectD0A() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00d0a2d0;

class hkpActionD0A : public hkReferencedObjectD0A
{
  public:
    hkpActionD0A() throw() : m_pCurrentSimulationIsland(0), m_ulUserData(0)
    {}
    virtual ~hkpActionD0A() throw();

    FUN_00d0a2d0* m_pOwningWorld;
    void* m_pCurrentSimulationIsland;
    unsigned int m_ulUserData;
};

class hkpEntityListenerD0A
{
  public:
    virtual ~hkpEntityListenerD0A() throw();
};

class WorldD0A;

class hkpPhantomListenerD0A
{
  public:
    virtual ~hkpPhantomListenerD0A() throw();
};

class WorldHolderD0A
{
  public:
    WorldHolderD0A(WorldD0A* pkWorld) throw() : m_pkWorld(pkWorld)
    {}

    WorldD0A* m_pkWorld;
};

class WorldD0A
{
  public:
    void FUN_00c93820(hkpEntityListenerD0A* pkListener);
    void FUN_00c93860(hkpPhantomListenerD0A* pkListener);
};

class FUN_00d0a2d0 : public WorldD0A
{
};

class ListenerMgrD0A : public hkpActionD0A, public hkpEntityListenerD0A, public hkpPhantomListenerD0A
{
  public:
    ListenerMgrD0A(FUN_00d0a2d0* pkWorld, bool bFlag) throw();
    virtual ~ListenerMgrD0A() throw();

    WorldD0A* m_pkWorld;
    bool m_bModifierActive;
    bool m_bFlag;
};

// @fnv 0x00d0a2d0
ListenerMgrD0A::ListenerMgrD0A(FUN_00d0a2d0* pkWorld, bool bFlag) throw()
    : m_pkWorld(pkWorld), m_bModifierActive(true), m_bFlag(bFlag)
{
    *(FUN_00d0a2d0* volatile*)&m_pOwningWorld = 0;
    m_pkWorld->FUN_00c93820(this);
    m_pkWorld->FUN_00c93860(this);
}

namespace fnv_00d0a560 {
struct Iface_d0a560A
{
    virtual void slot0();
    virtual int slot1(int n);
    virtual void slot2(void* p, int n);
};

struct S00d0a560_IfaceB
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16(void* a, void* b);
};

struct BSAudio
{
    Iface_d0a560A& heap()
    {
        return *unk10;
    }
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Iface_d0a560A* unk10;
};

namespace fnvc_adapt {
BSAudio* __cdecl FUN_00c85750(void);
}

struct FUN_00d9df50_Obj
{
    int unk00;
    void InitWalker(int a1, void* a2);
};

struct FUN_00d9e000_Obj
{
    int unk00;
    int unk04;
    int getNumPrimitives();
};

struct FUN_00d976d0_Obj
{
    void FUN_00d976d0();
};

struct FUN_00d97850_Obj
{
    void ClearBuffers();
};

struct FUN_00d97970_Obj
{
    int Init(void* p);
};

struct S00d0a560_Holder
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
    S00d0a560_IfaceB* unk58;
};

struct __declspec(align(16)) S00d0a560_Scratch
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct __declspec(align(16)) S00d0a560_S30
{
    int unk00;
    char unk04;
    char unk05;
    short unk06;
    int unk08;
    int unk0C;
};

struct S00d0a560_Combo
{
    FUN_00d9e000_Obj a;
    FUN_00d9df50_Obj b;
};

struct __declspec(align(16)) S00d0a560_Frame
{
    int unk10;
    int unk14;
    volatile unsigned int tk;
    FUN_00d9e000_Obj l1c;
    FUN_00d9e000_Obj s24;
    S00d0a560_S30 s30;
    S00d0a560_Scratch s44;
    S00d0a560_Scratch s50;
};

struct S00d0a560_Timer
{
    int name;
    unsigned int tick;
    int unk08;
};

struct S00d0a560_TimerBuf
{
    int unk00;
    S00d0a560_Timer* cur;
    int unk08;
    S00d0a560_Timer* end;
};

extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern int str_010cd2a4;
extern int str_010c41f8;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

void __cdecl GetAudioPair(void* out, int n);
void __cdecl FreeBufferPair(void* out, int n);
void __cdecl DrawIfCountPositive(void* p, int v);
void __cdecl FillAabbArray(void* p, int a, int b, int c);

struct S00d0a560_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    S00d0a560_Holder* unk1C;

    void __thiscall FUN_00d0a560(int* out, int ch);
};

// Frees the object at *out, builds a new one via Init, then calls GetAudioPair, FillAabbArray, DrawIfCountPositive and FreeBufferPair between two timer records.
// @fnv 0x00d0a560
void S00d0a560_Owner::FUN_00d0a560(int* out, int ch)
{
    S00d0a560_Frame f;
    ((FUN_00d9df50_Obj*)&f.s24)->InitWalker(ch, unk1C);
    FUN_00d97850_Obj* v = (FUN_00d97850_Obj*)*out;
    if (v != 0)
    {
        v->ClearBuffers();
        fnvc_adapt::FUN_00c85750()->heap().slot2(v, 0x50);
    }
    int t2 = f.s24.getNumPrimitives();
    ((FUN_00d976d0_Obj*)&f.s30)->FUN_00d976d0();
    unk1C->unk58->slot16(&f.s44, &f.s50);
    f.s30.unk00 = t2;
    f.s30.unk05 = 0;
    FUN_00d97970_Obj* p = (FUN_00d97970_Obj*)fnvc_adapt::FUN_00c85750()->heap().slot1(0x50);
    *out = p ? p->Init(&f.s30) : 0;
    S00d0a560_TimerBuf* pTimerBuf = (S00d0a560_TimerBuf*)TlsGetValue(DAT_0126835c);
    S00d0a560_Timer* c = pTimerBuf->cur;
    if (c < pTimerBuf->end)
    {
        c->name = (int)&str_010cd2a4;
        _ReadWriteBarrier();
        f.tk = (unsigned int)__rdtsc();
        c->tick = f.tk;
        pTimerBuf->cur = c + 1;
    }
    GetAudioPair(&f.l1c, t2);
    FillAabbArray(&f.s24, 0, t2, f.l1c.unk00);
    DrawIfCountPositive(&f.l1c, *out);
    FreeBufferPair(&f.l1c, t2);
    pTimerBuf = (S00d0a560_TimerBuf*)TlsGetValue(DAT_0126835c);
    c = pTimerBuf->cur;
    if (c < pTimerBuf->end)
    {
        c->name = (int)&str_010c41f8;
        _ReadWriteBarrier();
        f.tk = (unsigned int)__rdtsc();
        c->tick = f.tk;
        pTimerBuf->cur = c + 1;
    }
}
}  // namespace fnv_00d0a560

// sub ecx,0x14; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x14).
struct PrimaryBase
{
    virtual void FUN_00d0ada0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_00d0ada0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0ada0
    virtual void FUN_00d0ada0();
};

Derived::Derived()
{}

struct ThunkPrim
{
    virtual void FUN_00d0adb0();
    int p04;
    int p08;
    int p0C;
    int p10;
    int p14;
};

struct ThunkSec
{
    virtual void FUN_00d0adb0();
};

struct ThunkOwner : ThunkPrim, ThunkSec
{
// @fnv 0x00d0adb0
    virtual void FUN_00d0adb0();
};

static ThunkOwner g_thunk;

struct __declspec(align(16)) FourFloatVector
{
    float x, y, z, w;
};

struct Allocator
{
    __forceinline Allocator* same()
    {
        return this;
    }
    virtual void ReportDiagnostic();
    virtual void* allocate(int bytes);
    virtual void freeBlock(void* block, int bytes);
    virtual void* allocateBuffer(int& bytes);
    virtual void freeBuffer(void* block, int bytes);
    int* allocArray(int& bytes, int n)
    {
        return static_cast<int*>(allocateBuffer(bytes = n * 4));
    }
    void freeArray(int*& data, int& cap)
    {
        if ((cap & 0x80000000) == 0)
            freeBuffer(data, (cap & 0x3fffffff) * 4);
    }
};
struct Router
{
    int field00, field04, field08;
    Allocator* stack;
    Allocator* heap;
};
__forceinline Router* getRouter()
{
    return reinterpret_cast<Router*>(&::FUN_00c85750());
}
struct TreeInfo
{
    int count;
    unsigned char mode, enabled;
    short field06;
    int field08, field0c;
    FourFloatVector minimum, maximum;
    void FUN_00d976d0();
};
struct Tree
{
    void* nodes;
    int field04, field08, field0c;
    int* indices;
    int size, extra, root;
    int total() const
    {
        return extra + size;
    }
    void ClearBuffers();
    Tree* Init(TreeInfo*);
};
struct Bounds
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void getBounds(FourFloatVector*, FourFloatVector*);
};
struct World
{
    int field00, field04, field08, field0c, field10, field14, field18, field1c;
    int field20, field24, field28, field2c, field30, field34, field38, field3c;
    int field40, field44, field48, field4c, field50, field54;
    Bounds* bounds;
    int field5c, field60, field64, field68, field6c, field70, field74;
    void* context;
};
struct Input
{
    void* objects;
    int count;
};
struct Scratch
{
    void* first;
    void* second;
};
void __cdecl GetAudioPair(Scratch*, int);
void __cdecl FreeBufferPair(Scratch*, int);
void __cdecl FUN_00d9d950(Tree*, int, int*, int*);
struct Counter
{
    int value;
};
struct Semaphore
{
    void* handle;
    Semaphore* Create(int, int);
    void FUN_00d04370();
    void FUN_00d04380();
};
struct BuildJob
{
    unsigned char type, subtype, cpu;
    unsigned char field03;
    short bytes, affinity;
    int field08, field0c;
    Semaphore* volatile semaphore;
    Counter* counter;
    int field18;
    void* context;
    void* scratchFirst;
    void* scratchSecond;
    void* nodes;
    int root;
    int* volatile first;
    int* second;
    int* indices;
    int totalSize, extra;
    int field44, field48, field4c;
    void* objects;
    int field54, field58, field5c;
};
struct Queue
{
    void FUN_00d04b50(BuildJob*, int);
    void FUN_00d051b0();
};
struct Workers
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void start(Queue*, int);
    virtual void wait();
};
struct TimerRecord
{
    const char* name;
    unsigned int clock;
    int field08;
    const char* object;
};
struct TimerStream
{
    int field00;
    char* current;
    char* begin;
    char* end;
};
extern const char str_010cd104[];
extern const char str_010cd0fc[];
extern const char str_010cd0f4[];
extern const char str_010cd0e0[];
extern const char str_010cd0d0[];
extern const char str_010cd0c4[];
inline void timerEvent(const char* name)
{
    TimerStream* stream = static_cast<TimerStream*>(TlsGetValue(DAT_0126835c));
    TimerRecord* record = reinterpret_cast<TimerRecord*>(stream->current);
    if (stream->current < stream->end)
    {
        record->name = name;
        _ReadWriteBarrier();
        volatile unsigned int tick = (unsigned int)__rdtsc();
        record->clock = tick;
        stream->current = reinterpret_cast<char*>(record) + 12;
    }
}
struct IntBuffer
{
    int* data;
    int capacity;
    void allocate(int count)
    {
        int bytes = count * 4;
        data = static_cast<int*>(getRouter()->stack->allocateBuffer(bytes));
        capacity = bytes / 4;
        if (capacity == 0)
            capacity = 0x80000000;
    }
    void release()
    {
        Allocator* allocator = getRouter()->stack;
        if (capacity >= 0)
            allocator->freeBuffer(data, (capacity & 0x3fffffff) * 4);
    }
};
__forceinline int* AllocateBufferWithSize(int& bytes, int n)
{
    return static_cast<int*>(getRouter()->stack->allocArray(bytes, n));
}
__forceinline void bufCap(int& cap, int bytes)
{
    cap = bytes / 4;
    if (cap == 0)
        cap = 0x80000000;
}
__forceinline void ReturnMemory(int*& data, int& cap)
{
    getRouter()->stack->freeArray(data, cap);
}
struct Manager
{
    int field00, field04, field08, field0c, field10, field14, field18;
    World* world;
    void FUN_00d0a810(Tree**, Input*, Queue*, Workers*);
};
// @fnv 0x00d0a810
void Manager::FUN_00d0a810(Tree** tree, Input* input, Queue* queue, Workers* workers)
{
    Tree* oldTree = *tree;
    if (oldTree)
    {
        oldTree->ClearBuffers();
        getRouter()->heap->freeBlock(oldTree, 0x50);
    }
    struct Frame
    {
        TreeInfo job;
        BuildJob info;
    } f;
    TreeInfo& job = f.job;
    BuildJob& info = f.info;
    struct Early
    {
        Scratch scratch;
        int secondCap;
        int* secondData;
        int firstCap;
        int secondBytes;
        int firstBytes;
        char* volatile rec30;
    } early;
    struct Tail
    {
        volatile int count;
        Counter* volatile counter;
        int* volatile firstData;
    } tail;
    int count = input->count;
    tail.count = count;
    job.FUN_00d976d0();
    job.count = count;
    job.enabled = 1;
    world->bounds->getBounds(&job.minimum, &job.maximum);
    void* storage = getRouter()->heap->allocate(0x50);
    *tree = storage ? static_cast<Tree*>(storage)->Init(&job) : 0;
    Scratch& scratch = early.scratch;
    GetAudioPair(&scratch, count);
    Counter* counter = static_cast<Counter*>(getRouter()->heap->allocate(16));
    tail.counter = counter;
    counter->value = 4;
    Allocator* __restrict firstAllocator = getRouter()->stack->same();
    int* firstData = firstAllocator->allocArray(early.firstBytes, 4);
    tail.firstData = firstData;
    bufCap(early.firstCap, early.firstBytes);
    Allocator* __restrict secondAllocator = getRouter()->stack->same();
    early.secondData = secondAllocator->allocArray(early.secondBytes, 4);
    bufCap(early.secondCap, early.secondBytes);
    Semaphore* semaphore;
    storage = getRouter()->heap->allocate(4);
    if (storage)
        semaphore = static_cast<Semaphore*>(storage)->Create(0, 1000);
    else
        semaphore = 0;
    info.affinity = -1;
    info.semaphore = 0;
    info.first = 0;
    info.field18 = 0;
    info.subtype = 3;
    info.cpu = 1;
    info.counter = counter;
    info.type = 6;
    info.bytes = 0x60;
    info.context = world->context;
    info.objects = input->objects;
    info.scratchFirst = scratch.first;
    info.first = firstData;
    info.semaphore = semaphore;
    info.scratchSecond = scratch.second;
    info.second = early.secondData;
    info.indices = (*tree)->indices;
    info.nodes = (*tree)->nodes;
    info.totalSize = (*tree)->total();
    info.root = (*tree)->root;
    info.extra = (*tree)->extra;
    {
        TimerStream* stream = static_cast<TimerStream*>(TlsGetValue(DAT_0126835c));
        TimerRecord* record = reinterpret_cast<TimerRecord*>(stream->current);
        if (stream->current < stream->end)
        {
            record->name = str_010cd104;
            record->object = str_010cd0fc;
            _ReadWriteBarrier();
            volatile unsigned int tick = (unsigned int)__rdtsc();
            record->clock = tick;
            stream->current = reinterpret_cast<char*>(record) + 16;
        }
    }
    queue->FUN_00d04b50(&info, 0);
    timerEvent(str_010cd0f4);
    workers->start(queue, 3);
    queue->FUN_00d051b0();
    {
        TimerStream* stream = static_cast<TimerStream*>(TlsGetValue(DAT_0126835c));
        char* cur = stream->current;
        early.rec30 = cur;
        if (cur < stream->end)
        {
            reinterpret_cast<TimerRecord*>(cur)->name = str_010cd0e0;
            _ReadWriteBarrier();
            volatile unsigned int tick = (unsigned int)__rdtsc();
            char* r = early.rec30;
            reinterpret_cast<TimerRecord*>(r)->clock = tick;
            stream->current = r + 12;
        }
    }
    workers->wait();
    timerEvent(str_010cd0d0);
    semaphore->FUN_00d04380();
    timerEvent(str_010cd0c4);
    int count2;
    FUN_00d9d950(*tree, count2 = const_cast<const int&>(tail.count), info.first, info.second);
    timerEvent(str_01076f38);
    FreeBufferPair(&scratch, count2);
    getRouter()->heap->freeBlock(const_cast<Counter* const&>(tail.counter), 16);
    if (semaphore)
    {
        semaphore->FUN_00d04370();
        getRouter()->heap->freeBlock(semaphore, 4);
    }
    ReturnMemory(early.secondData, early.secondCap);
    ReturnMemory(const_cast<int*&>(tail.firstData), early.firstCap);
}

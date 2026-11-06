
// src/fallout/ai/actor_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/fallout/ai/actor.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include "Actor.h"

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; };
struct __declspec(align(16)) BlendQuat {
    float x, y, z, w;
    BlendQuat& operator=(const BlendQuat& other) { *(__m128*)&x=*(const __m128*)&other.x; return *this; }
    void __thiscall FUN_00cb2850(const BlendQuat&, const BlendQuat&, float);
};
struct BlendTransform { BlendQuat rotation; BlendQuat translation; BlendQuat scale; };
struct BlendSkeleton {
    int unk000;
    int unk004;
    int unk008;
    BlendTransform* transforms;
    BlendTransform* getTransforms() { return transforms; }
    int unk010;
    int unk014;
    int unk018;
    int count;
    int unk020;
    void* mapping;
    void* getMapping() { return mapping; }
};
struct BlendPose {
    int unk000;
    int unk004;
    int unk008;
    int count;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    BlendSkeleton* skeleton;
    void __thiscall FUN_00ce18f0(BlendTransform*, void*);
};
struct BlendArray {
    int unk00; unsigned short* data; unsigned int size;
    int find(unsigned short value) const {
        for (unsigned int i=0; i<size; ++i) {
            if (data && data[i]==value) return i;
        }
        return -1;
    }
};
struct BlendRagdoll {
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
    BlendArray bones;
};
struct BlendState { int unk00,unk04,unk08,unk0c; int source,dest; BlendRagdoll* ragdoll; };
struct BlendAccess {
    int* __thiscall FUN_00cda8d0();
    int* __thiscall FUN_00cda4b0();
    int* __thiscall FUN_00cdb290();
    void __thiscall FUN_00cd9fe0();
    int sourceValue() {return *FUN_00cda8d0();}
    int valueA() {return *FUN_00cda4b0();}
    int valueB() {return *FUN_00cdb290();}
};
struct BlendAllocator { char* top; };
extern BlendAllocator* __cdecl FUN_00c85750();
extern __int64 __cdecl FUN_00aa4d80();
extern void __cdecl FUN_00cddef0(int, BlendTransform*, BlendTransform*, BlendTransform*);
extern void __cdecl CallWithGlobal(int, BlendTransform*, void*, BlendTransform*);
extern void __cdecl FUN_00ce3a00(int, int, int, BlendTransform*, int);
struct BlendBuffer {
    BlendTransform* data; int size;
    static BlendTransform* allocate(int n) {
        BlendAllocator* a=FUN_00c85750();
        BlendTransform* result=(BlendTransform*)a->top;
        int bytes=(n*(int)sizeof(BlendTransform)+127)&~127;
        a->top = a->top + bytes;
        return result;
    }
    BlendBuffer(int n) { data=allocate(n); }
    ~BlendBuffer() { FUN_00c85750()->top=(char*)data; }
};
struct BlendController {
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
    BlendPose* pose;
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
    BlendAccess* access;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    float blend;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    BlendState* state;
    BlendState* GetReferenceTimeStep() {return state;}
    __int64 start;

    __int64 duration;

    void __thiscall FUN_00c7b6a0(int);
    void __thiscall FUN_00c7c870();
};
// @fnv 0x00c7c870
void BlendController::FUN_00c7c870() {
    BlendController* self=this;
    if (FUN_00aa4d80()-self->start > self->duration) {
        self->FUN_00c7b6a0(0);
    } else {
    BlendSkeleton* skeleton=self->pose->skeleton;
    int count=skeleton->count;
    BlendBuffer a(count);
    BlendTransform* aData=a.data;
    {
        BlendBuffer b(count);
        BlendTransform* bData=b.data;
        self->pose->FUN_00ce18f0(bData,&self->unk010);
        FUN_00cddef0(count,skeleton->getTransforms(),bData,aData);
    }
    BlendBuffer c(count);
    BlendTransform* cData=c.data;
    BlendBuffer d(count);
    BlendTransform* dData=d.data;
    CallWithGlobal(count,skeleton->getTransforms(),skeleton->getMapping(),dData);
    int mappedCount=(int)skeleton->getMapping();
    FUN_00ce3a00(self->GetReferenceTimeStep()->source,self->access->sourceValue(),mappedCount,dData,2);
    FUN_00cddef0(count,skeleton->getTransforms(),dData,cData);
    int poseCount=self->pose->count;
    for(int i=0;i<poseCount;++i) {
        int index=self->GetReferenceTimeStep()->ragdoll->bones.find((unsigned short)i);
        if(index!=-1) {
            __declspec(align(16)) char components[sizeof(BlendQuat)];
            BlendQuat& q=*(BlendQuat*)components;
            q.FUN_00cb2850(aData[i].translation,cData[i].translation,self->blend);
            cData[i].translation=q;
        }
    }
    CallWithGlobal(count,skeleton->getTransforms(),cData,dData);
    int v=self->access->valueA();
    int w=self->access->valueB();
    FUN_00ce3a00(self->GetReferenceTimeStep()->dest,(int)dData,w,(BlendTransform*)v,2);
    self->access->FUN_00cd9fe0();
    }
}

union __declspec(align(16)) PackedVector { __m128 vector; unsigned char lanes[16]; };
struct InternedHeader { long references; unsigned int length; };


// Interned names and intrusive scene-object references.
char* __cdecl FUN_00a5b690(const char*);
extern char* DAT_0109b220;
__declspec(dllimport) long __stdcall InterlockedIncrement(long*);
__declspec(dllimport) long __stdcall InterlockedDecrement(long*);
void* __cdecl FUN_00aa13e0(unsigned int);

__forceinline void RetainString(char* text) {
    if (text != DAT_0109b220) { InternedHeader& header = *((InternedHeader*)text - 1); InterlockedIncrement(&header.references); }
}
__forceinline void ReleaseString(char* text) {
    if (text != DAT_0109b220) InterlockedDecrement(&((InternedHeader*)text - 1)->references);
}
struct MatrixTransform;
void __cdecl FUN_00c74dd0(void*, const MatrixTransform*);
struct BoneTransformData;
struct FUN_00a5d3a0 {
    virtual void Reserved();
    virtual void Destroy();
    long references;
    FUN_00a5d3a0();
};
typedef FUN_00a5d3a0 RefBase;
struct CachedScene : RefBase {
    __forceinline BoneTransformData* GetSkeleton() { return skeleton; }
    __forceinline void ApplyTransform(const MatrixTransform&);
    __forceinline void ApplyFinalTransform(const MatrixTransform&);
    __forceinline void ApplyTransformPointer(const MatrixTransform*);
    BoneTransformData* skeleton;
    BoneTransformData* animation;
    void* sourceAnimation;
    void* sourceSkeleton;
    int reserved18;
    int flags;
    CachedScene() {
        skeleton = 0; animation = 0; sourceAnimation = 0; sourceSkeleton = 0; flags = 0;
    }
    virtual void Reserved();
    virtual void Destroy();
    __forceinline static void* operator new(unsigned int n) { return FUN_00aa13e0(n); }
    static void operator delete(void*);
};
struct SceneRef {
    CachedScene* p;
    SceneRef(CachedScene* v) : p(v) { if (p) InterlockedIncrement(&p->references); }
    SceneRef(const SceneRef& r) : p(r.p) { if(p) InterlockedIncrement(&p->references); }
    ~SceneRef() { if(p && !InterlockedDecrement(&p->references)) p->Destroy(); }
};
__forceinline void AssignScene(CachedScene*& slot, CachedScene* created) {
    CachedScene* previous = slot;
    if (previous != created) {
        if (previous && !InterlockedDecrement(&previous->references)) previous->Destroy();
        slot = created;
        if (created) InterlockedIncrement(&created->references);
    }
}
struct CacheManager {
    void FUN_00e92760(char*, CachedScene**);
    void InsertOrAssign(char*, SceneRef);
};
extern CacheManager DAT_011b0300;

struct Allocator {
    virtual void Reserved();
    virtual void* Allocate(unsigned int);
    virtual void Reserved8();
    virtual void ReservedC();
    virtual void* Resize(void*, unsigned int);
};
struct MemoryRouter {
    char* top;
    int FunctionAtSlot4, VirtualFunction8, reservedC;
    Allocator* allocator;
    __forceinline Allocator& AllocatorInstance() { return *allocator; }
};
__forceinline MemoryRouter* GetRouter() { return (MemoryRouter*)FUN_00c85750(); }
struct ArrayStorage {
    void* data;
    int size;
    int capacity;
    __forceinline ArrayStorage() : data(0), size(0), capacity(0x80000000) {}
    __forceinline ~ArrayStorage() {
        Allocator& a = GetRouter()->AllocatorInstance();
        size = 0;
        if ((capacity & 0x80000000) == 0) a.Resize(data, (capacity & 0x3fffffff) * 4);
        data = 0; capacity = 0x80000000;
    }
};
struct ScratchArray : ArrayStorage {
    char* saved;
    __forceinline ScratchArray() {
        MemoryRouter* m = GetRouter();
        char* p = m->top;
        m->top = p + 0x100;
        data = p; capacity = 0x80000040; saved = p;
    }
    __forceinline ~ScratchArray() {
        char* original = saved;
        bool owned = original != data;
        if (!owned) size = 0;
        GetRouter()->top = original;
    }
};
struct MatrixTransform {
    float rotation[3][3];
    float x, y, z;
    float scale;
    void FUN_00a86bf0();
    void FUN_00cb2d90(void*);
    MatrixTransform FUN_0062c250(const MatrixTransform&) const;
};
struct __declspec(align(16)) PoseState {
    BoneTransformData* animation;
    BoneTransformData* skeleton;
    int reserved08;
    float blend, weight;
    void* transforms; int transformCount, transformCapacity;
    void* positions; int positionCount, positionCapacity;
    void* rotations; int rotationCount, rotationCapacity;
    unsigned char localValid, active, reserved3a, reserved3b;
    int reserved3c, reserved40, reserved44, reserved48;
    float scale, inverseScale;
    __forceinline PoseState() throw() { FUN_00c7bfd0(); }
    __forceinline ~PoseState() { FUN_00c7c2b0(); }
    void FUN_00c7bfd0() throw();
    void FUN_00c7c2b0();
};
struct PoseBuffer {
    int reserved00, reserved04, reserved08, reserved0c;
    int VirtualFunction10, reserved14, reserved18, reserved1c;
    int reserved20, VirtualFunction24, VirtualFunction28, reserved2c;
    PackedVector translation, rotation, scale;
    unsigned char valid;
    unsigned char reserved61, reserved62, reserved63;
    int reserved64, reserved68, reserved6c;
    PoseBuffer() { FUN_00ce5310(); }
    ~PoseBuffer() { FUN_00ce5370(); }
    void FUN_00ce5310();
    void FUN_00ce5370();
};
struct FUN_00ce4a20 {
    int reserved0;
    unsigned short allocationSize;
    unsigned short FunctionAtSlot6;
    int VirtualFunction8, reservedC, VirtualFunction10, reserved14, reserved18, reserved1c;
    int reserved20, VirtualFunction24, VirtualFunction28, reserved2c;
    int reserved30, reserved34, reserved38, reserved3c;
    int reserved40, reserved44, reserved48, reserved4c;
    int reserved50, reserved54, reserved58, reserved5c;
    int reserved60, reserved64, reserved68, reserved6c;
    int reserved70, reserved74, reserved78, reserved7c;
    FUN_00ce4a20(PoseBuffer* p);
    __forceinline static void* operator new(unsigned int n) { FUN_00ce4a20* p = (FUN_00ce4a20*)GetRouter()->AllocatorInstance().Allocate(n); p->allocationSize = (unsigned short)n; return p; }
    static void operator delete(void*);
};
typedef FUN_00ce4a20 PoseSource;
struct BoneLock { unsigned char value;
    __forceinline BoneLock& operator=(bool b) { value = b; return *this; }
};
struct BoneName { const char* taggedName; BoneLock locked; unsigned char FunctionAtSlot5, FunctionAtSlot6, VirtualFunction7;
    __forceinline const char* Name() const { return (const char*)((unsigned int)taggedName & ~1u); }
};
struct BoneTransformData {
    int reserved0, FunctionAtSlot4, VirtualFunction8, reservedC, VirtualFunction10, reserved14;
    BoneName* bones;
    int boneCount;
    int reserved20;
    void* transform;
    int VirtualFunction28, reserved2c, reserved30;
    MatrixTransform localTransform;
    __forceinline void* GetTransform() { return transform; }
    __forceinline BoneName* GetBones() { return bones; }
    __forceinline BoneName& GetBone(int i) { BoneName* p = &bones[i]; return *p; }
    __forceinline MatrixTransform& GetLocalTransform() { return localTransform; }
};
__forceinline void CachedScene::ApplyTransform(const MatrixTransform& value) { FUN_00c74dd0(skeleton->transform, &value); }
__forceinline void CachedScene::ApplyTransformPointer(const MatrixTransform* value) { FUN_00c74dd0(skeleton->transform, value); }
__forceinline void CachedScene::ApplyFinalTransform(const MatrixTransform& value) { FUN_00c74dd0(GetSkeleton()->GetTransform(), &value); }
struct InputScene {
    int reserved0, FunctionAtSlot4;
    BoneTransformData* skeleton;
    int reservedC;
    void* extra;
    __forceinline BoneTransformData* GetSkeleton() { return skeleton; }
};
struct Argument { int reserved0, FunctionAtSlot4; char* name; };
struct TransformSource {
    int reserved0, FunctionAtSlot4, VirtualFunction8, reservedC;
    int VirtualFunction10, reserved14, reserved18, reserved1c;
    PackedVector basis;
    PackedVector quaternion;
};
struct __declspec(align(16)) Conversion {
    PackedVector rotation;
    PackedVector translation;
    PackedVector scale;
    PackedVector quaternion;
    void FUN_00cb2d90(void*);
};
union TemporaryPoseWork {
    Conversion converted;
    MatrixTransform result;
};
struct ExtraView { TransformSource* FUN_00653290(void*); };
extern int DAT_012683c8;
struct FUN_00cdb400 {
    float* values;
    int reserved04, reserved08, reserved0c, VirtualFunction10, reserved14, reserved18, reserved1c;
    int reserved20, VirtualFunction24, VirtualFunction28, reserved2c, reserved30, reserved34, reserved38, reserved3c;
    int reserved40, reserved44;
    FUN_00cdb400(void* p);
    __forceinline static void* operator new(unsigned int n) { return GetRouter()->AllocatorInstance().Allocate(n); }
    static void operator delete(void*);
};
typedef FUN_00cdb400 SkinState;
int __cdecl ApplyToCollisionBodies(BoneTransformData*, ArrayStorage*, ArrayStorage*);
int __cdecl FUN_00cea030(ArrayStorage*, ArrayStorage*);
BoneTransformData* __cdecl FUN_00ceb2c0(ArrayStorage*, ArrayStorage*);
void __cdecl FUN_00c74dd0(void*, const MatrixTransform*);
void __cdecl FUN_00624ad0(MatrixTransform*, const void*);
void* __cdecl FUN_00cea810(BoneTransformData*, ArrayStorage*, ArrayStorage*);
int __cdecl FUN_00ec7750(const char*, const char*);
void __cdecl createMapping(PoseState*, PoseBuffer*, PoseBuffer*);
InputScene* __cdecl FUN_00c802d0(Argument*);
extern float DAT_01267c7c, DAT_01267c88, DAT_01267c94, DAT_01267ca0;
extern float DAT_01267cac, DAT_01267cb8, DAT_01267cc4, DAT_01267cd0;
extern float DAT_01267cdc, DAT_01267ce8, DAT_01267cf4, DAT_01267d00;

struct SceneOwner {
    float rotation[3][3];
    float x, y, z;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    unsigned char unk40;
    unsigned char unk41;
    unsigned char initialized;
    unsigned char unk43;
    void* unk44;
    void* skin;
    SkinState* state;
    int reserved50, reserved54;
    void* skeletonHandle;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15C;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16C;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17C;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18C;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19C;
    void* unk1A0;
    void* unk1A4;
    void* unk1A8;
    void* unk1AC;
    void* unk1B0;
    void* unk1B4;
    void* unk1B8;
    void* unk1BC;
    void* unk1C0;
    void* unk1C4;
    void* unk1C8;
    void* unk1CC;
    void* unk1D0;
    void* unk1D4;
    void* unk1D8;
    void* unk1DC;
    void* unk1E0;
    void* unk1E4;
    void* unk1E8;
    void* unk1EC;
    void* unk1F0;
    void* unk1F4;
    void* unk1F8;
    void* unk1FC;
    void* unk200;
    void* unk204;
    void* unk208;
    void* unk20C;
    void* unk210;
    unsigned char mode;
    unsigned char unk215;
    unsigned char unk216;
    unsigned char unk217;
    void* unk218;
    void* unk21C;
    void* unk220;
    void* unk224;
    void* unk228;
    void* unk22C;
    void* unk230;
    void* unk234;
    void* unk238;
    void* unk23C;
    void* unk240;
    void* unk244;
    void* unk248;
    void* unk24C;
    void* unk250;
    void* unk254;
    void* unk258;
    void* unk25C;
    void* unk260;
    void* unk264;
    void* unk268;
    void* unk26C;
    void* unk270;
    void* unk274;
    void* unk278;
    void* unk27C;
    void* unk280;
    void* unk284;
    void* unk288;
    void* unk28C;
    void* unk290;
    void* unk294;
    char* name;
    CachedScene* cached;
    int reserved2a8, reserved2ac, reserved2b0, reserved2b4;
    int headBone;
    __forceinline CachedScene* GetCached() { return cached; }
    __forceinline char* GetName() { return name; }
    void FUN_00c7e9a0(Argument*, const char*);
    void FUN_00c7e3b0();
    unsigned char FUN_00c75460();
    void FUN_00c79e20();
};

// @fnv 0x00c7e9a0
void SceneOwner::FUN_00c7e9a0(Argument* sourceInput, const char* requestedName) {
    char* old = name;
    if (old != requestedName) {
        name = FUN_00a5b690(requestedName);
        ReleaseString(old);
    }
    if (!requestedName) {
        char* inherited = sourceInput->name;
        if (name != inherited) {
            RetainString(inherited);
            char* previous = name;
            ReleaseString(previous);
            name = inherited;
        }
    }
    CachedScene** cacheSlot = &cached;
    DAT_011b0300.FUN_00e92760(GetName(), cacheSlot);
    CachedScene* found = *cacheSlot;
    if (!found) {
        AssignScene(*cacheSlot, new CachedScene);
        DAT_011b0300.InsertOrAssign(GetName(), SceneRef(*cacheSlot));
    }
    if (FUN_00c802d0(sourceInput)) {
        InputScene* scene = FUN_00c802d0(sourceInput);
        skeletonHandle = scene->GetSkeleton()->GetBones();
        ScratchArray first;
        ScratchArray second;
        ApplyToCollisionBodies(scene->GetSkeleton(), &first, &second);
        if (FUN_00cea030(&first, &second) != 1) {
            CachedScene* entry = *cacheSlot;
            if (!entry->skeleton) {
                entry->skeleton = FUN_00ceb2c0(&first, &second);
                (*cacheSlot)->ApplyTransform(scene->GetSkeleton()->GetLocalTransform());
                TransformSource* source;
                if (!scene->extra) source = 0;
                else source = ((ExtraView*)scene->extra)->FUN_00653290(&DAT_012683c8);
                MatrixTransform transform;
                transform.FUN_00a86bf0();
                if (source) {
                    Conversion converted;
                    converted.quaternion.vector = source->quaternion.vector;
                    converted.FUN_00cb2d90(&source->basis);
                    FUN_00624ad0(&transform, &converted);
                }
                MatrixTransform copied;
                copied = scene->GetSkeleton()->GetLocalTransform().FUN_0062c250(transform);
                (*cacheSlot)->ApplyTransformPointer(&copied);
            }
            if (cached->skeleton) {
                skin = FUN_00cea810(GetCached()->skeleton, &first, &second);
                BoneTransformData* skeleton = GetCached()->skeleton;
                for (int bone = 0; bone < skeleton->boneCount; ++bone) {
                    const char* boneName = skeleton->GetBone(bone).Name();
                    if (FUN_00ec7750(boneName, "Head")) headBone = bone;
                }
                if (skin) {
                    state = new SkinState(skin);
                    float* values = state->values;
                    values[0] = DAT_01267c7c; values[1] = DAT_01267c88;
                    values[2] = DAT_01267c94; values[3] = DAT_01267ca0;
                    values[4] = DAT_01267cac; values[5] = DAT_01267cb8;
                    values[6] = DAT_01267cc4; values[7] = DAT_01267cd0;
                    values[8] = DAT_01267cdc; values[9] = DAT_01267ce8;
                    values[10] = DAT_01267cf4; values[11] = DAT_01267d00;
                    initialized = 1;
                    mode = FUN_00c75460();
                }
            }
            FUN_00c7e3b0();
            if (!(*cacheSlot)->sourceAnimation && !(*cacheSlot)->sourceSkeleton) {
                (*cacheSlot)->animation->bones->locked = false;
                GetCached()->skeleton->bones->locked = false;
                PoseBuffer animationPose;
                PoseBuffer skeletonPose;
                {
                    PoseState pose;
                    pose.animation = (*cacheSlot)->animation;
                    pose.skeleton = (*cacheSlot)->skeleton;
                    pose.active = 0;
                    createMapping(&pose, &animationPose, &skeletonPose);
                }
                FUN_00c79e20();
                GetCached()->sourceAnimation = new PoseSource(&animationPose);
                GetCached()->sourceSkeleton = new PoseSource(&skeletonPose);
            }
        }
    }
}

namespace VectorHardware {
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned char m128_u8[16];
};
extern "C" __m128 _mm_sub_ps(__m128,__m128);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_and_ps(__m128,__m128);
extern "C" __m128 _mm_cmple_ps(__m128,__m128);
extern "C" int _mm_movemask_ps(__m128);
}
typedef VectorHardware::__m128 VectorBits;
using VectorHardware::_mm_sub_ps;
using VectorHardware::_mm_set_ps1;
using VectorHardware::_mm_and_ps;
using VectorHardware::_mm_cmple_ps;
using VectorHardware::_mm_movemask_ps;
template<class T> class OwnedCell {
    T stored;
public:
    __forceinline OwnedCell() {}
    __forceinline OwnedCell(T value) : stored(value) {}
    __forceinline void operator=(T value) { stored=value; }
    __forceinline T val() const { return stored; }
    __forceinline T operator->() const { return stored; }
    __forceinline operator T() const { return val(); }
};
struct ReferenceView {
    virtual ~ReferenceView();
    unsigned short allocationFlags;
    unsigned short references;
};
template<class T> class PointerView {
    T* value;
public:
    T* get() const { return value; }
};
extern BlendAllocator* FUN_00c85750();
extern float DAT_011b02e8;
extern float DAT_011ac39c;
extern const float DAT_01017d00;

extern __int64 FUN_00aa4d80();
struct ScratchAllocator {
    char* current;
    char* allocate(int n) { int numBytes=(n+127)&~127; char* p=current; char* next=p+numBytes; current=next; return p; }
};
extern char FUN_00c8cce0(int*);
extern "C" void* __cdecl FUN_00cb1280(void*,int,unsigned int);
struct Clock {
    __int64 start;
    __int64 duration;
    void FUN_00448e30(float);
    void begin(float f) { start=FUN_00aa4d80(); duration=(__int64)(DAT_011ac39c*f); }
};
struct IndexArray {
    unsigned int unk000;
    unsigned short* data;
    unsigned int count;
    int find(unsigned short v) { for(unsigned int i=0;i<count;++i) if(data && data[i]==v) return i; return -1; }
};
struct Selection {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    IndexArray indices;
    int find(unsigned short v) { return indices.find(v); }
};
struct SelectionHolder {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    Selection* selection;
};
struct BroadHandle { unsigned int id; };
struct TypedHandle : BroadHandle {
    unsigned char type,ownerOffset;
    unsigned short objectGroup;
    unsigned short flags;
    char m_ucObjectQualityType;
    unsigned char unused0b;
};
struct CollisionBodyView {
    void* shape;
    unsigned int shapeKey;
    void* motionState;
    CollisionBodyView* parent;
};
struct ColliderView : CollisionBodyView {
    TypedHandle handle;
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
    const TypedHandle* getBroadPhaseHandle() const { return &handle; }
    TypedHandle* getBroadPhaseHandle() { return &handle; }
};
struct LinkedColliderView : ColliderView {
    void* collisionEntries;
    int collisionCount,collisionCapacity;
};
struct WorldView : ReferenceView {
    void* world;
    unsigned int userData;
    LinkedColliderView collidable;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    const LinkedColliderView* getCollidable() const { return &collidable; }
    LinkedColliderView* getCollidableRw() { return &collidable; }
};
extern const VectorBits DAT_01017d10;
class VectorValue;
class ComparisonValue {
    VectorBits lanes;
    friend class VectorValue;
public:
    enum Required { All=15 };
    __forceinline int all(Required required) const { return (_mm_movemask_ps(lanes)&required)==required; }
};
class VectorValue {
    VectorBits q;
public:
    __forceinline VectorValue() {}
    __forceinline VectorValue(const VectorValue& other) { q=other.q; }
    __forceinline VectorValue(const VectorBits& v) { q=v; }
    operator VectorBits() const { return q; }
    __forceinline void operator=(const VectorBits& v) { q=v; }

    __forceinline void operator=(const VectorValue& other) { q=other.q; }
    __forceinline void difference(const VectorValue& left,const VectorValue& right) { q=_mm_sub_ps(left.q,right.q); }
    __forceinline void absolute(const VectorValue& value) { q=_mm_and_ps(value.q,DAT_01017d10); }
    __forceinline void splat(float value) { q=_mm_set_ps1(value); }
    __forceinline ComparisonValue lessEqual(const VectorValue& value) const { ComparisonValue result; result.lanes=_mm_cmple_ps(q,value.q); return result; }
    __forceinline int equal(const VectorValue& value,float epsilon=0.001f) const {
        VectorValue delta; delta.difference(*this,value); delta.absolute(delta);
        VectorValue tolerance; tolerance.splat(epsilon);
        return delta.lessEqual(tolerance).all(ComparisonValue::All);
    }
};

enum MotionKind { KindInvalid=0,KindDynamic=1,KindSphere=2,KindBox=3,KindKeyframed=4,KindFixed=5,KindThin=6,KindCharacter=7,KindMax=8 };
enum QualityKind { QualityInvalid=-1,QualityFixed=0,QualityKeyframed=1,QualityDebris=2,QualityMoving=4 };
enum ActivationMode { LeaveInactive=0,ActivateNow=1 };
enum FilterMode { UpdateFull=0,UpdatePartial=1 };
template<class E,class S> class EnumCell {
    S stored;
public:
    EnumCell() {}
    EnumCell(E value) : stored((S)value) {}
    operator E() const { return (E)stored; }
    void operator=(E value) { stored=(S)value; }
};
struct MotionView : ReferenceView {
    virtual void unused04();
    virtual void unused08();
    virtual void unused0c();
    virtual void unused10();
    virtual void unused14();
    virtual void unused18();
    virtual void unused1c();
    virtual void unused20();
    virtual void unused24();
    virtual void unused28();
    virtual void unused2c();
    virtual void unused30();
    virtual void unused34();
    virtual void unused38();
    virtual void unused3c();
    virtual void SetTranslationalVelocity(const VectorValue&);
    virtual void SetRotationalVelocity(const VectorValue&);
    EnumCell<MotionKind,unsigned char> kind;
    unsigned char flags0,flags1,flags2;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    VectorValue linearVelocity;
    VectorValue angularVelocity;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;

    MotionView();
    MotionKind getType() const { return kind; }
    const VectorValue& getLinearVelocity() const { return linearVelocity; }
    const VectorValue& getAngularVelocity() const { return angularVelocity; }
};
struct KeyframedMotionView : MotionView { KeyframedMotionView(); };
struct MaximumMotionView : KeyframedMotionView {
    MaximumMotionView() : KeyframedMotionView() {}
private:
    MaximumMotionView(const MaximumMotionView&);
    void operator=(const MaximumMotionView&);
};
struct EntityView : WorldView {
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    MaximumMotionView m_pMotionState;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    void FUN_00c9c1d0();
    MotionView* getMotion() { return &m_pMotionState; }
};
struct BodyView : EntityView {
    MotionKind getMotionType() const { return m_pMotionState.getType(); }
    QualityKind getQualityType() const { return (QualityKind)getCollidable()->getBroadPhaseHandle()->m_ucObjectQualityType; }
    void setQualityType(QualityKind value) { getCollidableRw()->getBroadPhaseHandle()->m_ucObjectQualityType=(char)value; }
    const VectorValue& getLinearVelocity() const { return m_pMotionState.getLinearVelocity(); }
    const VectorValue& getAngularVelocity() const { return m_pMotionState.getAngularVelocity(); }
    void FUN_00ca8420(MotionKind,ActivationMode,FilterMode);
    void FUN_00ca8630(bool);
};
template<class T> __forceinline T* AddBytes(T* p,int bytes) { return (T*)((char*)p+bytes); }
__forceinline int ByteDistance(const void* from,const void* to) { return (int)((const char*)to-(const char*)from); }
struct StackView {
    OwnedCell<char*> next;
    OwnedCell<void*> start;
    OwnedCell<void*> end;
    StackView();
    __forceinline int freeBytes() const { return ByteDistance(next,end); }
    __forceinline ~StackView() {}
    __forceinline void* allocate(int bytes,const char* label=0) {
        if(bytes>freeBytes()) {}
        char* saved=next;
        next=AddBytes(saved,bytes);
        return saved;
    }
    __forceinline void release(void* saved) { next=(char*)saved; }
};
struct RouterView {
    StackView area;
    static RouterView& FUN_00c85750();
    __forceinline StackView& stack() { return area; }
};
template<class T> __forceinline T* AllocateView(int n,const char* label=0) {
    RouterView& memory=RouterView::FUN_00c85750();
    return (T*)memory.stack().allocate((n*(int)sizeof(T)+127)&~127,label);
}
template<class T> __forceinline void ReleaseView(T* p) { RouterView::FUN_00c85750().stack().release(p); }
struct FixedBuffer {
protected:
    OwnedCell<VectorValue*> data;
    int debugSize;
    __forceinline FixedBuffer() {}
public:
    __forceinline VectorValue* begin() { return data; }
    __forceinline VectorValue& operator[](int i) { return data[i]; }
};
struct BufferView : FixedBuffer {
    __forceinline BufferView(int n) { data=AllocateView<VectorValue>(n); }
    __forceinline ~BufferView() { ReleaseView(data.val()); }
};
template<class T> struct BoneArrayView {
    T* data; int length,capacity;
    const T& operator[](int i) const { return data[i]; }
    int GetLogicalSize() const { return length; }
};
struct SkeletonView {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14;
    BoneArrayView<void*> m_kBones;
};
template<class T> struct SavedReference {
    T* pointer;
    T* operator->() const { return pointer; }
};
struct RagdollView {
    unsigned int unk00,unk04;
    BoneArrayView<BodyView*> bodyArray;
    BoneArrayView<void*> constraints;
    BoneArrayView<int> indices;
    SavedReference<const SkeletonView> skeleton;
    int getNumBones() const { return skeleton->m_kBones.GetLogicalSize(); }
    BodyView* getRigidBodyOfBone(int i) const { int index=indices[i]; return index<0 ? 0 : bodyArray[index]; }
};
struct Controller {
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    RagdollView* bodies;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned char unk28c;
    bool enabled;
    bool active;
    unsigned char unk28f;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    PointerView<SelectionHolder> selection;
    Clock timer;
    void FUN_00c7a230(bool);
    void FUN_00c7b6a0(bool active);
};
__forceinline void UpdateLinear(BodyView* body,const VectorValue& value) {
    if(!value.equal(body->getLinearVelocity())) {
        body->FUN_00c9c1d0();
        body->getMotion()->SetTranslationalVelocity(value);
    }
}
__forceinline void UpdateAngular(BodyView* body,const VectorValue& value) {
    if(!value.equal(body->getAngularVelocity())) {
        body->FUN_00c9c1d0();
        body->getMotion()->SetRotationalVelocity(value);
    }
}

// @fnv 0x00c7b6a0
void Controller::FUN_00c7b6a0(bool enable) {
    if (!enabled) return;
    if (!enable && !active) return;
    if (active && enable) { timer.FUN_00448e30(DAT_011b02e8); return; }
    FUN_00c7a230(enable);
    if (enable) timer.begin(DAT_011b02e8); else timer.duration=0;
    int count=bodies->getNumBones();
    BufferView positions(count);
    BufferView rotations(count);
    FUN_00cb1280(positions.begin(),0,count*16);
    FUN_00cb1280(rotations.begin(),0,count*16);
    for(int i=0;i<count;++i) {
        BodyView* body=(BodyView*)bodies->getRigidBodyOfBone(i);
        {
            if(body) {
                int kind=body->getMotionType();
                if(FUN_00c8cce0(&kind)) { positions[i]=body->getLinearVelocity(); rotations[i]=body->getAngularVelocity(); }
            }
        }
    }
    for(int i=0;i<count;++i) {
        BodyView* body=(BodyView*)bodies->getRigidBodyOfBone(i);
        {
            if(body) {
                if(selection.get()->selection->find((unsigned short)i)!=-1) {
                    if(enable) {
                        if(body->getMotionType()==4 || body->getQualityType()!=4) {
                            body->FUN_00ca8420(KindDynamic,ActivateNow,UpdateFull); body->setQualityType((QualityKind)4); body->FUN_00ca8630(false);
                        }
                    } else {
                        if(body->getMotionType()!=4 || body->getQualityType()!=1) {
                            body->FUN_00ca8420(KindKeyframed,ActivateNow,UpdateFull); body->setQualityType((QualityKind)1); body->FUN_00ca8630(true);
                        }
                    }
                }
                UpdateLinear(body,positions[i]);
                UpdateAngular(body,rotations[i]);
            }
        }
    }
    active=enable;
}

inline void* operator new(unsigned int, void* p) { return p; }
inline void operator delete(void*,void*) {}
extern "C" __m128 _mm_setr_ps(float, float, float, float);
struct Heap { virtual void Unused(); virtual void* Allocate(unsigned); };
struct Context { int unk00, unk04, unk08, unk0c; Heap* heap; };
extern void* __cdecl FUN_00c74ea0(unsigned);
extern void __cdecl FUN_00c74dd0(void*, void*);
extern float DAT_01050c98, DAT_01050c48, DAT_01011d78, DAT_01012068;
extern void* UNK_010c4dec;
static __forceinline void* AllocateBuffer(unsigned n) { Context* context=(Context*)(void*)FUN_00c85750(); Heap* heap=context->heap; return (heap->Allocate)(n); }
static __forceinline int Maximum(int first,int second) { return first >= second ? first : second; }
struct SmallMember { unsigned data; __forceinline SmallMember() { FUN_00cb0a60(); } __forceinline ~SmallMember() { FUN_00cb0c00(); } void FUN_00cb0a60(); void FUN_00cb0c00(); };
struct Entry { SmallMember member; unsigned char enabled; __forceinline Entry():enabled(0) {} };
extern void __cdecl FUN_00c908c0(Heap&, void*, int, unsigned);
struct __declspec(align(16)) Transform { __m128 x,y,z; };
struct S7de60_IsPod {}; struct S7de60_IsClass {};
template<class T> struct S7de60_PodTrait { typedef S7de60_IsPod type; };
template<> struct S7de60_PodTrait<Entry> { typedef S7de60_IsClass type; };
struct S7de60_ArrayUtil {
    template<class T> static __forceinline void construct(T* t, int n, S7de60_IsPod) {}
    template<class T> static __forceinline void construct(T* t, int n, S7de60_IsClass) { for(int i=0;i<n;++i) new (t+i) T; }
    template<class T> static __forceinline void constructWithCopy(T* t, int n, const T& c, S7de60_IsPod) { for(int i=0;i<n;++i) t[i]=c; }
    template<class T> static __forceinline void destruct(T* t, int n, S7de60_IsPod) {}
    template<class T> static __forceinline void destruct(T* t, int n, S7de60_IsClass) { for(int i=0;i<n;++i) t[i].~T(); }
};
struct S7de60_Router { __forceinline Heap& heap() { return *((Context*)this)->heap; } };
struct S7de60_HeapAlloc { __forceinline Heap& get(const void*) { return ((S7de60_Router*)(void*)FUN_00c85750())->heap(); } };
template<class T> struct ArrayBase {
    T* data; int count; int capacity;
    __forceinline ArrayBase():data(0),count(0),capacity(0x80000000) {}
    __forceinline int GetLogicalSize() const { return count; }
    __forceinline int getCapacity() const { return capacity & 0x3fffffff; }
    __forceinline void _reserveExactly(Heap& alloc, int n) { if(getCapacity()<n) { FUN_00c908c0(alloc,this,n,sizeof(T)); } }
    __forceinline void GrowArrayCapacity(Heap& alloc, int n) {
        const int cap=getCapacity();
        if(cap<n) { int cap2=2*cap; int newSize=(n<cap2)?cap2:n; FUN_00c908c0(alloc,this,newSize,sizeof(T)); }
    }
    __forceinline void _setSize(Heap& alloc, int n) {
        GrowArrayCapacity(alloc,n);
        S7de60_ArrayUtil::destruct(data+n,count-n,typename S7de60_PodTrait<T>::type());
        S7de60_ArrayUtil::construct(data+count,n-count,typename S7de60_PodTrait<T>::type());
        count=n;
    }
    __forceinline void _setSize(Heap& alloc, int n, const T& fill) {
        GrowArrayCapacity(alloc,n);
        S7de60_ArrayUtil::destruct(data+n,count-n,typename S7de60_PodTrait<T>::type());
        S7de60_ArrayUtil::constructWithCopy(data+count,n-count,fill,typename S7de60_PodTrait<T>::type());
        count=n;
    }
};
template<class T> struct DynamicArray : ArrayBase<T> {
    ~DynamicArray();
    __forceinline void Reserve(int n) { ArrayBase<T>::_reserveExactly(S7de60_HeapAlloc().get(this),n); }
    __forceinline void Resize(int n) { ArrayBase<T>::_setSize(S7de60_HeapAlloc().get(this),n); }
    __forceinline void ResizeEntries(int n) { Resize(n); }
    __forceinline void ResizeInts(int n, const T& value) { ArrayBase<T>::_setSize(S7de60_HeapAlloc().get(this),n,value); }
};
struct SourceBase {
    unsigned short size,version;
    __forceinline SourceBase():version(1) {}
    virtual ~SourceBase();
};
struct LocalFrameRecord { void* frame; int bone; };
struct SourceBuffer : SourceBase {
    SmallMember member;
    DynamicArray<short> points; DynamicArray<Entry> indices; DynamicArray<Transform> vertices; DynamicArray<SmallMember> transforms; DynamicArray<LocalFrameRecord> extra;
    static __forceinline void* operator new(unsigned n) { SourceBuffer* p=(SourceBuffer*)AllocateBuffer(n); p->size=(unsigned short)n; return p; }
    static void operator delete(void*);
    __forceinline SourceBuffer() {}
};
struct PoseSync91 {
    unsigned char value;
    __forceinline PoseSync91(bool v):value((unsigned char)v) {}
    __forceinline operator bool() const { return value!=0; }
};
struct CloneBuffer {
    SourceBuffer* original;
    DynamicArray<Transform> positions,normals; DynamicArray<int> triangles;
    PoseSync91 enabled,modified; unsigned short flags;
    DynamicArray<float> remap;
    static __forceinline void* operator new(unsigned n) { return AllocateBuffer(n); }
    static void operator delete(void*);
    __forceinline CloneBuffer(SourceBuffer* p):original(p),enabled(0),modified(0) {
        int count=original->indices.count;
        normals.Resize(count);
        positions.Resize(count);
        triangles.Resize(count);
        const int sizeRoundedUp=(original->transforms.GetLogicalSize()+3)&~3;
        remap.Reserve(sizeRoundedUp);
        remap.ResizeInts(original->transforms.count,0.0f);
    }
    void FUN_00cda110(); void FUN_00cda340();
};
struct __declspec(align(16)) Vec4 { __m128 value; __forceinline Vec4& operator=(const Vec4& rhs) { value=rhs.value; return *this; } };
struct Root {
    SourceBuffer* src; __forceinline void SetSource(SourceBuffer* p) { src=p; } int unk04,unk08,unk0c;
    Vec4 a,b;
    static __forceinline void* operator new(unsigned n) { return FUN_00c74ea0(n); }
    __forceinline Root():src(0) {}
};
struct Owner { int unk00,unk04,unk08,unk0c,unk10,unk14,unk18; Root* root; __forceinline void SetRoot(Root* p) { root=p; } };
union Vec128 { __m128 value; char bytes[16]; };
struct FramePoint { float x,y,z; };
struct FrameState { FramePoint rotation[3]; FramePoint point; float scale; void FUN_00a86bf0(); };
struct __declspec(align(16)) LookBoneParams91 {
    CloneBuffer* pose;
    short bone,parent;
    float maxAngle;
    Vec4 forwardLocal,forwardParent,previousRotation;
    bool limitRotation,active;
    float deadHeading,deadPitch;
};
template<class T> struct SharedObject91 {
    T* object;
    __forceinline T* operator->() const { T* result=object; return result; }
};
struct RenderNode {
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
    int unk34;
    int unk38;
    int unk3c;
    unsigned short unk40; bool active; unsigned char unk43;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    CloneBuffer* buffer;
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
    int unk80;
    int unk84;
    CloneBuffer* input;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    bool success; unsigned char unkb1; unsigned short unkb2;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    LookBoneParams91 boneParams[2];
    bool create; unsigned char unk191; unsigned short unk192;
    int state;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    SharedObject91<Owner> owner;
    __forceinline Owner* GetOwner() { Owner* result=owner.operator->(); return result; }
    bool FUN_00c79340(CloneBuffer*,const char*,int);
    bool FUN_00c7de60(const char* item);
};
// @fnv 0x00c7de60
bool RenderNode::FUN_00c7de60(const char* item) {
    bool ok=active;
    if(ok) {
    ok=FUN_00c79340(input,item,1);
    if(ok) {
        state=1;
        if(create) {
            if(!owner->root) {
                owner->SetRoot(new Root);
                owner->root->src=new SourceBuffer;
                owner->root->src->indices.ResizeEntries(2);
                owner->root->src->points.Resize(2);
                owner->root->src->vertices.Resize(2);
                ((short*)owner->root->src->points.data)[0]=-1;
                ((short*)owner->root->src->points.data)[1]=0;
                FrameState frame;
                frame.FUN_00a86bf0();
                FUN_00c74dd0(owner->root->src->vertices.data,&frame);
                frame.point.x=DAT_01050c98; frame.point.y=DAT_01050c48; frame.point.z=0;
                FUN_00c74dd0(owner->root->src->vertices.data+1,&frame);
                owner->root->a=boneParams[1].forwardParent;
                owner->root->b=boneParams[1].forwardLocal;
            }
            CloneBuffer* clone=new CloneBuffer(owner->root->src);
            buffer=clone;
            clone->FUN_00cda110();
            buffer->FUN_00cda340();
            Vec128 unit; unit.value=_mm_setr_ps(DAT_01011d78,DAT_01012068,DAT_01011d78,DAT_01011d78);
            boneParams[0].bone=1;
            boneParams[0].forwardLocal.value=unit.value;
            boneParams[0].forwardParent.value=boneParams[0].forwardLocal.value;
            boneParams[0].parent=0;
            boneParams[0].pose=buffer;
            state=0;
        }
    }
    success=ok;
    }
    return ok;
}

struct C74Matrix3 {
    float m_afEntries[3][3];
};

struct C74Transform {
    C74Matrix3 m_kOrientation;
    float m_TranslateX;
    float m_TranslateY;
    float m_TranslateZ;
    float m_fScale;
};

struct C74NiQuaternion {
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    void FromRotationMatrix(const C74Matrix3& kRot);
};

struct C74Vector4 {
    VectorBits m_vComponents;
    float& operator()(int i) { return m_vComponents.m128_f32[i]; }
};

struct C74Quaternion {
    float m_vec[4];
    void set(float x, float y, float z, float w) { m_vec[0] = x; m_vec[1] = y; m_vec[2] = z; m_vec[3] = w; }
    void normalize();
};

struct C74QsTransform {
    C74Vector4 m_vTranslation;
    C74Quaternion m_rotation;
    C74Vector4 m_vScale;
};

extern float DAT_01267c20;

// @fnv 0x00c74dd0
C74QsTransform* FUN_00c74dd0(C74QsTransform* out, const C74Transform* in)
{
    C74NiQuaternion q;
    q.FromRotationMatrix(in->m_kOrientation);
    out->m_rotation.set(q.m_fVectorY, q.m_fVectorZ, q.m_fScalarPart, q.m_fVectorX);
    out->m_rotation.normalize();
    C74Vector4 t;
    t(0) = in->m_TranslateX * DAT_01267c20;
    t(1) = in->m_TranslateY * DAT_01267c20;
    t(2) = in->m_TranslateZ * DAT_01267c20;
    t(3) = 0.0f;
    out->m_vTranslation.m_vComponents = t.m_vComponents;
    out->m_vScale.m_vComponents = _mm_set_ps1(in->m_fScale);
    return out;
}

namespace EntryHardware {
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    PackedVector storage;
    struct { float x,y,z,w; };
};
extern "C" __m128 _mm_setr_ps(float,float,float,float);
}

extern int DAT_011f49e0;
extern double DAT_010c4dd0;
extern double DAT_010c4dc8;
extern float DAT_01011d78;
extern float DAT_01012068;
extern float DAT_01267d90;
struct InputName { char* key; };
struct FNVInput { int unk00; InputName* objects; unsigned count; InputName& at(unsigned i) { return objects[i]; } };

struct StringHeader { long references; unsigned length; void release() { InterlockedDecrement(&references); } };
struct ResourceName {
    char* key;
    ResourceName(InputName const& raw) { if (!raw.key) key=DAT_0109b220; else key=FUN_00a5b690(raw.key); }
    ~ResourceName() { if (key != DAT_0109b220) { StringHeader* header=reinterpret_cast<StringHeader*>(key)-1; header->release(); } }
};
struct __declspec(align(16)) Scratch {
    int owner;
    short first, second, third, unk0a;
    int unk0c;
    EntryHardware::__m128 axisA, axisB, axisC, axisD;
    float strength, f54, f58, f5c, f60, f64, f68, threshold, radius;
    bool flag;
    void __thiscall FUN_00cd8920();
};
struct GameForm {
    GameForm* getLinked();
    GameForm* getChildNamed();
    struct VTable;
    typedef int (__fastcall *TypeQuery)(GameForm*,VTable*);
    struct VTable { void* f0; void* f1; void* f2; TypeQuery canUse; };
    struct NativeQuery { virtual void f0(); virtual void f1(); virtual void f2(); virtual int __fastcall queryType(VTable*)=0; };
    VTable* vtable;
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
    struct Children { GameForm** data; unsigned short capacity,count; GameForm* get() const { return data[0]; } } children;
};
struct Material { int unk00,unk04; int name; };
struct Resource { int unk00,unk04; Material* material; };
struct Runtime { int unk00,unk04,unk08,unk0c; Allocator* allocator; Allocator& heap() { return *allocator; } };
struct IndexedRecord { void __thiscall FUN_00c905b0(); };
struct FUN_00cd8820 : IndexedRecord {
    int vtable;
    unsigned short size, references;
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
    FUN_00cd8820(Scratch const&);
    static __forceinline void* operator new(size_t);
    static void operator delete(void*);
};
struct RagdollEntry {
    IndexedRecord* record;
    float value;
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
    short mapped,unkc2;
    int unkc4,unkc8,unkcc;
    static void* operator new(size_t, void* p) { return p; }
    RagdollEntry() : record(0), value(0.0f), mapped(-1) {}
};
struct EntryArray { RagdollEntry* data; int count,capacity; void resize(int); RagdollEntry& operator[](unsigned i) { return data[i]; } };
struct MappingEntry { short source,target; int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c; };
struct Mapping { int unk00,unk04,unk08,unk0c,unk10,unk14; MappingEntry* data; int count; };
struct Table { int unk00,unk04,unk08; int owner; Mapping* mapping; };
struct Geo { float unk00, expansion; };
struct ParticleTable {
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
    short unk40; unsigned char enabled,unk43;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    void* context;
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
    unsigned char unk21c,unk21d,unk21e,complete;
    int unk220;
    int unk224;
    int unk228;
    EntryArray entries;
    int unk238;
    int unk23c;
    int unk240;
    float radius;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    Table* table;
    void* getContext() { return context; }
    void __thiscall FUN_00c7c3a0(FNVInput* incoming);
    bool __thiscall FUN_00c77ac0(Scratch*, FNVInput*);
    Geo* __thiscall FUN_00c75180(GameForm*);
};

extern GameForm* __cdecl FUN_00c4b470(void*, ResourceName const&, int);
static __forceinline Runtime* GetEntryRuntime() { return reinterpret_cast<Runtime*>(FUN_00c85750()); }
extern "C" void __cdecl FUN_00c908c0(Allocator*, EntryArray*, int, unsigned);
extern "C" Resource* __cdecl FUN_00c802d0(GameForm*);
extern "C" short __cdecl FindIndexByKey(int,int,int);
__forceinline void* FUN_00cd8820::operator new(size_t bytes) {
    void* ptr=GetEntryRuntime()->heap().Allocate(bytes);
    static_cast<FUN_00cd8820*>(ptr)->size=(unsigned short)bytes;
    return ptr;
}
__forceinline GameForm* GameForm::getLinked() {
    if (vtable->canUse(this,vtable) && children.count>0) return children.get(); return 0;
}
__forceinline GameForm* GameForm::getChildNamed() { NativeQuery* query=reinterpret_cast<NativeQuery*>(this); if(query->queryType(vtable) && children.count>0) return children.get(); return 0; }
static __forceinline int const& materialName(Resource* resource) {
    return resource ? resource->material->name : DAT_011f49e0;
}
__forceinline void EntryArray::resize(int size) {
    Allocator& allocator=GetEntryRuntime()->heap();
    int cap=capacity & 0x3fffffff;
    if (cap<size) {
        cap*=2;
        if (size>=cap) cap=size;
        FUN_00c908c0(&allocator,this,cap,sizeof(RagdollEntry));
    }
    int extra=size-count;
    RagdollEntry* dest=data+count;
    for (int k=0;k<extra;++k) new (dest+k) RagdollEntry;
    count=size;
}
// @fnv 0x00c7c3a0
void __thiscall ParticleTable::FUN_00c7c3a0(FNVInput* incoming) {
    FNVInput* input=incoming;
    unsigned count=incoming->count;
    if (!count || !enabled) return;
    Scratch scratch;
    scratch.FUN_00cd8920();
    bool ready=FUN_00c77ac0(&scratch,incoming);
    Table* ownerTable=table;
    int owner=ownerTable->owner;
    if (!ready) return;
    scratch.owner=owner;
    scratch.axisC=EntryHardware::_mm_setr_ps(DAT_01011d78,DAT_01011d78,DAT_01012068,DAT_01011d78);
    scratch.axisD=scratch.axisC;
    scratch.strength=DAT_01267d90;
    entries.resize(count);
    for (unsigned i=0;i<count;++i) {
        GameForm* actor;
        {
            ResourceName name(input->at(i));
            actor=FUN_00c4b470(getContext(),name,1);
        }
        GameForm* linked=actor ? actor->getChildNamed():0;
        GameForm* nested=linked ? linked->getLinked():0;
        Resource* pActorResource=actor ? FUN_00c802d0(actor):0;
        Resource* secondResource=linked ? FUN_00c802d0(linked):0;
        Resource* thirdResource=nested ? FUN_00c802d0(nested):0;
        Geo* geo=FUN_00c75180(nested);
        float expansion=geo ? geo->expansion:0.0f;
        scratch.threshold=(float)(expansion+DAT_010c4dd0);
        scratch.radius=(float)(expansion+DAT_010c4dc8);
        radius=scratch.radius;
        int first=materialName(pActorResource);
        int second=materialName(secondResource);
        int third=materialName(thirdResource);
        if (second && third && pActorResource!=secondResource && pActorResource!=thirdResource && thirdResource!=secondResource) {
            scratch.first=FindIndexByKey(owner,first,0);
            scratch.second=FindIndexByKey(owner,second,0);
            scratch.third=FindIndexByKey(owner,third,0);
            if (scratch.first!=-1 && scratch.second!=-1 && scratch.third!=-1)
                entries[i].record=new FUN_00cd8820(scratch);
        }
        if (table->mapping) {
            for (int j=0;j<table->mapping->count;++j) {
                MappingEntry* mapped=&table->mapping->data[j];
                if (mapped->source==scratch.third) entries[i].mapped=mapped->target;
            }
        }
    }
    bool success=true;
    for (unsigned j=0;j<count && success;++j) {
        if (!entries[j].record) success=false;
    }
    if (!success) {
        for (unsigned j=0;j<count;++j) {
            IndexedRecord* record=entries[j].record;
            if (record) record->FUN_00c905b0();
        }
        entries.count=0;
    }
    complete=success;
}

extern "C" __m128 _mm_mul_ps(__m128,__m128);
extern "C" __m128 _mm_shuffle_ps(__m128,__m128,int);
extern "C" __m128 _mm_add_ss(__m128,__m128);
extern "C" void _mm_store_ss(float*,__m128);
struct VectorStorage {protected:__m128 value; __forceinline VectorStorage(){} __forceinline VectorStorage(const __m128& v):value(v){} };
struct VecLane:private VectorStorage {
private:
public:
 __forceinline VecLane() {}
 __forceinline VecLane(const VecLane& rhs):VectorStorage(rhs.value) {}
 __forceinline void operator=(const VecLane& rhs) { setRaw(rhs.getRaw()); }
 __forceinline void operator=(const __m128& rhs) { value=rhs; }
 __forceinline __m128 getRaw() const{return value;}
 __forceinline void setRaw(__m128 v){value=v;}
 __forceinline operator __m128() const { return getRaw(); }
};
struct QuatLane {VecLane value; __forceinline void operator=(const QuatLane& rhs) {value=rhs.value;} };
struct Transform48 {VecLane translation; QuatLane rotation; VecLane scale;};
template<class T> struct FieldStorage {protected:T value; __forceinline FieldStorage(){} __forceinline FieldStorage(T v):value(v){} };
template<class T> class MemberValue:private FieldStorage<T> {
public:
 __forceinline MemberValue() {}
 __forceinline MemberValue(T p):FieldStorage<T>(p) {}
 __forceinline void operator=(T p) {value=p;}
 __forceinline T val() const {return value;}
 __forceinline operator T() const {return val();}
 __forceinline T operator->() const {return val();}
};
struct TempAllocator {
 virtual void v0();virtual void v4();virtual void v8();
 virtual void* Allocate(int&);
 virtual void Free(void*,int);
 template<class T> __forceinline T* allocateItems(int& n) {int bytes=n*(int)sizeof(T);void* p=Allocate(bytes);n=bytes/(int)sizeof(T);return (T*)p;}
 template<class T> __forceinline void freeItems(T* p,int n) {Free(p,n*sizeof(T));}
};
struct ArenaStack {
 MemberValue<void*> next;
 MemberValue<void*> start;
 MemberValue<void*> end;
 __forceinline int freeBytes() const {return (int)((char*)end.val()-(char*)next.val());}
 __forceinline void* allocate(int bytes,const char* tag) {
  if(bytes>freeBytes()) {}
  void* old=next;
  next=(char*)old+bytes;
  return old;
 }
 __forceinline void release(void* p) {next=p;}
};
struct ScratchState {ArenaStack arena;int unk0c;TempAllocator* allocator;
 __forceinline TempAllocator& heap() {return *allocator;}
 __forceinline ArenaStack& stack() {return arena;}
};
__forceinline ScratchState& getRouter() {return *(ScratchState*)FUN_00c85750();}
template<class T> __forceinline T* allocateScratch(int n,const char* tag=0) {
 ScratchState& a=getRouter();
 return (T*)a.stack().allocate((n*(int)sizeof(T)+127)&~127,tag);
}
template<class T> __forceinline void freeScratch(T* p) {getRouter().stack().release((void*)p);}
template<class T> struct RagdollUpdateFixedBuffer {
 MemberValue<T*> data;int debugSize;
 __forceinline RagdollUpdateFixedBuffer() {}
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline T* begin() {return data;}
 __forceinline const T* begin() const {return data;}
};
template<class T> struct LocalBuffer:RagdollUpdateFixedBuffer<T> {
 __forceinline LocalBuffer(int n,const char* tag=0) {data=allocateScratch<T>(n,tag);}
 __forceinline ~LocalBuffer() {freeScratch(data.val());}
};
typedef LocalBuffer<Transform48> ScratchTransforms;
template<class T> struct OwnedBase {
 T* data;int size,capacity;
 __forceinline OwnedBase():data(0),size(0),capacity(0x80000000) {}
 __forceinline void setOwned(T* p,int n,int cap) {data=p;size=n;capacity=cap;}
 __forceinline T* begin() {return data;}
 __forceinline void clearFree(TempAllocator& a) {size=0;if(!(capacity&0x80000000)) a.freeItems(data,capacity&0x3fffffff);data=0;capacity=0x80000000;}
};
struct HeapPolicy {template<class T> __forceinline TempAllocator& get(T*) {return getRouter().heap();}};
template<class T,class P=HeapPolicy> struct OwnedBuffer:OwnedBase<T> {
 __forceinline OwnedBuffer(int n) {TempAllocator& a=P().get(this);T* p=n?a.allocateItems<T>(n):0;int cap=n?n:0x80000000;setOwned(p,n,cap);}
 __forceinline ~OwnedBuffer() {clearFree(P().get(this));}
};
typedef OwnedBuffer<int> IntBuffer;
struct LaneScalar {
 PackedVector storage;
 __forceinline LaneScalar(const __m128& v){storage.vector=v;}
 __forceinline operator float() const {float v;_mm_store_ss(&v,storage.vector);return v;}
};
struct VelocityVector {
 __m128 value;
 __forceinline LaneScalar dot(const VelocityVector& r) const {
  __m128 m=_mm_mul_ps(value,r.value);
  __m128 t=_mm_shuffle_ps(m,m,0x55);
  t=_mm_add_ss(t,m);
  m=_mm_shuffle_ps(m,m,0xaa);
  return LaneScalar(_mm_add_ss(m,t));
 }
 __forceinline LaneScalar lengthSquared() const {return dot(*this);}
};
extern float DAT_010c7948[];
struct SmallFloat {
 unsigned char index;
 __forceinline operator float() const {return DAT_010c7948[index];}
};
template<class T> struct ArrayBaseView {
 T* data;int size,capacity;
 __forceinline T* begin() {return data;}
 __forceinline const T* begin() const {return data;}
 __forceinline int GetLogicalSize() const {return size;}
 __forceinline T& operator[](int i) {return data[i];}
 __forceinline const T& operator[](int i) const {return data[i];}
};
template<class T> struct ArrayView:ArrayBaseView<T> {};
struct SkeletonData {
 int unk00,unk04,unk08;ArrayView<short> parents;ArrayView<void*> boneList;ArrayView<Transform48> poseList;
 __forceinline int getCount() const {return boneList.GetLogicalSize();}
 __forceinline const short* getParents() const {return parents.begin();}
 __forceinline const Transform48* getPoses() const {return poseList.begin();}
};
struct BoneState {
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
 SmallFloat scaleIndex; unsigned char unk19d; unsigned short unk19e;
 int unk1a0, unk1a4, unk1a8, unk1ac;
 VelocityVector velocity;
};
struct Skeleton {
 int unk00,unk04;ArrayView<BoneState*> stateList;ArrayView<void*> constraints;ArrayView<int> indexList;SkeletonData* data;
 __forceinline SkeletonData* getData() const {return data;}
 __forceinline int getNumBones() const {return getData()->getCount();}
 __forceinline BoneState* getBody(int i) const {int k=indexList[i];return k>=0?stateList[k]:0;}
 void FUN_00ce1ad0(Transform48*,void*);
};
struct Processor {
 void FUN_00cdb3e0();
 void FUN_00cdb7c0(float delta, Transform48* transforms, void* settings, int* results);
};
struct PoseLookup { void** FUN_00cda8d0(); };
struct BlendData { int unk00,unk04,unk08,unk0c; void* data; };
extern float DAT_011afe64;
extern float DAT_010c7948[];
void UpdateEntriesByKind(Skeleton*);
void EnableBehaviorsByKind(Skeleton*);
void FUN_00c7a410(Skeleton*, Transform48*);
void CallWithGlobal(int, void*, void*, Transform48*);
void FUN_00cddef0(int, void*, Transform48*, Transform48*);
void FUN_00ce3a00(void*,void*,void*,Transform48*,int);
struct RagdollUpdateController {
 int unk00; bool needsInit; unsigned char unk05; unsigned short unk06; int unk08; int mode;
 int settings10, settings14, settings18, settings1c, settings20, settings24, settings28, settings2c, settings30, settings34, settings38, settings3c, settings40;
 bool forceMode; unsigned char unk45; unsigned short unk46;
 Skeleton* skeleton; Processor* processor; bool active; unsigned char unk51; unsigned short unk52;
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
 PoseLookup* lookup;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
 BlendData* blend;
 void FUN_00c7d030(const Transform48* input);
};
// @fnv 0x00c7d030
void RagdollUpdateController::FUN_00c7d030(const Transform48* input) {
 SkeletonData* data=skeleton->getData();
 int count=data->getCount();
 ScratchTransforms outputStorage(count);
 Transform48* output=outputStorage.begin();
 ScratchTransforms poseStorage(count);
 Transform48* pose=poseStorage.begin();
 int oldMode=mode;
 if(forceMode) mode=1;
 if(needsInit) { UpdateEntriesByKind(skeleton); needsInit=false; }
 if(!input) {
  CallWithGlobal(count,(void*)data->getParents(),(void*)data->getPoses(),pose);
  void* referencePoses=(void*)data->getPoses();
  void* poseTrack=*lookup->FUN_00cda8d0();
  BlendData* currentBlend=blend;
  FUN_00ce3a00(currentBlend->data,poseTrack,referencePoses,pose,2);
  if(mode!=1) { void* bones=(void*)data->getParents(); FUN_00cddef0(count,bones,pose,output); }
 } else {
  for(int i=0;i<count;++i) outputStorage[i]=input[i];
 }
 switch(mode) {
 case 3: EnableBehaviorsByKind(skeleton); FUN_00c7a410(skeleton,output); mode=0; break;
 case 2:
  if(active) { processor->FUN_00cdb3e0(); active=false; }
  if(DAT_011afe64>0.0f) {
   IntBuffer results(count);
   processor->FUN_00cdb7c0(DAT_011afe64,output,&settings10,results.begin());
   bool fast=false;
   for(int index=0;index<skeleton->getNumBones();++index) {
    if(fast) break;
    {
     BoneState* state=skeleton->getBody(index);
     if(state) {
      float magnitude=state->velocity.lengthSquared();
      float limit=state->scaleIndex;
      limit=limit*limit;
      fast=magnitude>limit;
     }
    }
   }
   if(fast) { skeleton->FUN_00ce1ad0(pose,&settings10); active=true; }
  }
  break;
 case 1: { Skeleton* current=skeleton; current->FUN_00ce1ad0(pose,&settings10); break; }
 }
 if(forceMode) { mode=oldMode; forceMode=false; }
}

extern "C" __m128 _mm_setzero_ps();
namespace ControllerFloatHardware { extern "C" __m128 _mm_set_ps1(float); }
extern void* DAT_010c4ddc;
extern void* DAT_01071aec;
extern void* DAT_010c4db8;
extern char* DAT_0109b220;
extern const float DAT_010c4df8;
extern const float DAT_01022958;
extern const float DAT_01017868;
extern const __m128 DAT_010c71b0;
struct RefTarget {
    virtual void unused();
    virtual void destroy();
    volatile long refs;
};
struct RefSlot {
    RefTarget* object;
    RefSlot():object(0){}
    ~RefSlot();
    void clear() { RefTarget* old=object; if(old) { if(!InterlockedDecrement(&old->refs)) old->destroy(); object=0; } }
};
struct RefSlotArray {
    unsigned int data, size, capacity;
    RefSlotArray():data(0),size(0),capacity(0x80000000){}
    ~RefSlotArray();
};
struct SmallArray {
    void* vtable; unsigned int data,size,capacity;
    SmallArray():vtable(&DAT_01071aec),data(0),size(0),capacity(0){}
    ~SmallArray();
};
struct NameSlot {
    char* name;
    NameSlot():name(DAT_0109b220){}
    ~NameSlot();
};
struct NamePair { NameSlot name; unsigned int value; NamePair():value(0){} };
struct PlainArray {
    unsigned int data,size,capacity,extra;
    PlainArray():data(0),size(0),capacity(0),extra(0){}
    ~PlainArray();
};
struct __declspec(align(16)) StateRecord {
    unsigned int unk00;
    short first,second;
    float weight;
    unsigned int unk0c;
    __m128 position,velocity,rotation;
    bool active,valid;
    unsigned short unk42;
    float time,blend;
    unsigned int unk4c;
};
struct NodeArg {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual NiNode* get();
};
struct TempArray {
    void* vtable; unsigned int data,size,capacity;
    TempArray():vtable(&DAT_010c4db8),data(0),size(0),capacity(0){}
    ~TempArray();
};
typedef void (__thiscall *FreeTemp)(TempArray*,unsigned int);
extern FreeTemp DAT_010c4dc0;
TempArray::~TempArray() { vtable=&DAT_010c4db8; if(data) DAT_010c4dc0(this,data); }
extern void __cdecl FUN_00c7d3b0(NiNode*,NiNode*,TempArray*,bool*,unsigned int*);
extern void __cdecl RestoreNodeTransforms(NiNode*,TempArray*,bool,unsigned int);
struct ConstructorBase { virtual ~ConstructorBase(); };
struct LastArray { unsigned int data,size,capacity,extra; LastArray():data(0),size(0),capacity(0),extra(0){} };
struct ThirdArg { unsigned int value; };
union NodeOrFlag { NodeArg* node; bool flag; };
struct VecStore { __m128 value; VecStore& operator=(__m128 other) { value=other; return *this; } };
union SimdVector { __m128 value; signed char lanes[16]; };
class FUN_00c7f060 : public ConstructorBase {
public:
    bool unk04;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    float unk08;
    int unk0c;
    VecStore unk10;
    VecStore unk20;
    VecStore unk30;
    bool unk40;
    bool unk41;
    bool unk42;
    bool unk43;
    bool unk44;
    unsigned char unk45;
    unsigned char unk46;
    unsigned char unk47;
    unsigned int unk48;
    unsigned int unk4c;
    bool unk50;
    unsigned char unk51;
    unsigned char unk52;
    unsigned char unk53;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    RefSlot ref84;
    unsigned int unk88;
    bool unk8c;
    unsigned char unk8d;
    unsigned char unk8e;
    unsigned char unk8f;
    unsigned int unk90;
    RefSlotArray array94;
    SmallArray arraya0;
    bool unkb0;
    bool unkb1;
    bool unkb2;
    bool unkb3;
    bool unkb4;
    unsigned char unkb5;
    unsigned char unkb6;
    unsigned char unkb7;
    unsigned int unkb8;
    unsigned int unkbc;
    __m128 unkc0;
    __m128 unkd0;
    __m128 unke0;
    StateRecord records[2];
    bool unk190;
    unsigned char unk191;
    unsigned char unk192;
    unsigned char unk193;
    unsigned int unk194;
    bool unk198;
    unsigned char unk199;
    unsigned char unk19a;
    unsigned char unk19b;
    float unk19c;
    float unk1a0;
    bool unk1a4;
    bool unk1a5;
    unsigned char unk1a6;
    unsigned char unk1a7;
    float unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned char unk1bc;
    bool unk1bd;
    unsigned char unk1be;
    unsigned char unk1bf;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned char unk1ec;
    bool unk1ed;
    unsigned char unk1ee;
    unsigned char unk1ef;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    bool unk21c;
    bool unk21d;
    bool unk21e;
    bool unk21f;
    bool unk220;
    bool unk221;
    bool unk222;
    bool unk223;
    bool unk224;
    unsigned char unk225;
    unsigned char unk226;
    unsigned char unk227;
    unsigned int unk228;
    RefSlotArray array22c;
    unsigned short unk238;
    unsigned short unk23a;
    float unk23c;
    bool unk240;
    bool unk241;
    bool unk242;
    bool unk243;
    float unk244;
    unsigned int unk248;
    NamePair name24c;
    bool unk254;
    bool unk255;
    bool unk256;
    unsigned char unk257;
    unsigned int unk258;
    unsigned int unk25c;
    PlainArray array260;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    float unk27c;
    float unk280;
    bool unk284;
    unsigned char unk285;
    unsigned char unk286;
    unsigned char unk287;
    unsigned int unk288;
    bool unk28c;
    bool unk28d;
    bool unk28e;
    bool unk28f;
    float unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    NameSlot name2a0;
    RefSlot ref2a4;
    LastArray array2a8;
    unsigned int unk2b8;
    virtual ~FUN_00c7f060();
    FUN_00c7f060(NodeArg*,NodeOrFlag,void*);
    void FUN_00c7e9a0(NodeArg*,void*);
};
// @fnv 0x00c7f060
FUN_00c7f060::FUN_00c7f060(NodeArg* a,NodeOrFlag b,void* c) {
    unk23c=0.0f;
    unk48=0; unk4c=0; unk50=0; unk54=0; unk58=0; unk5c=0;
    unk240=false; unk241=true; unk242=true;
    SimdVector zero; zero.value=_mm_setzero_ps();
    for(int i=0;i<2;++i) {
        records[i].first=-1; records[i].second=-1;
        records[i].weight=1.04719758f;
        records[i].position=zero.value; records[i].velocity=zero.value;
        records[i].valid=false; records[i].active=true;
        records[i].rotation=DAT_010c71b0;
        records[i].time=0.0f; records[i].blend=0.0f;
    }
    unkd0=zero.value; unke0=zero.value; unkb4=false; unkc0=DAT_010c71b0;
    unk1a0=0.0f; unk19c=0.0f; unk1a8=0.0f;
    unk1a4=false; unk1a5=false;
    unk42=0; unkb0=0; unk21f=0; unk21c=0;
    unk41=0; unkb1=0; unk220=0; unk21d=0; unk255=0;
    unk43=0; unkb2=0; unk221=0; unkb3=0; unk222=0; unk21e=0;
    unk256=0; unk1bd=0; unk1ed=0; unk228=0; unk254=0;
    unk190=0; unk194=0;
    ref84.clear();
    unk248=0; unk258=-1;
    ref2a4.clear();
    unk88=0; unk290=1.0f; unk8c=0; unk28c=0; unk28d=0; unk244=0.0f;
    unk28e=0; unk28f=0; unk294=0; unk243=0; unk223=0; unk90=0;
    unk0c=2; unk10=zero.value; unk20=DAT_010c71b0; unk30=ControllerFloatHardware::_mm_set_ps1(1.0f);
    unk280=10000.0f; unk27c=20.0f; unk23a=0; unk08=0.0f;
    unk40=0; unk284=1; unk288=-1; unk44=0; unk04=0; unk198=0; unk224=1; unk238=0;
    NiNode* first=a?a->get():0;
    NiNode* second=b.node?b.node->get():0;
    b.flag=false;
    unsigned int count;
    if(first && second) count=0; else count=0;
    TempArray temp;
    if(first && second) FUN_00c7d3b0(first,second,&temp,&b.flag,&count);
    FUN_00c7e9a0(a,c);
    RestoreNodeTransforms(first,&temp,b.flag,count);
    unk2b8=0;
}

namespace InversePositionHardware {
extern "C" __m128 _mm_sub_ps(__m128, __m128);
}
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_rcp_ps(__m128);
extern const __m128 g_rotationOffset;

struct InversePositionVector : Vec4 {
    void FUN_00c7f840(const Vec4* t, const Vec4* p);
};

// @fnv 0x00c7f840
void InversePositionVector::FUN_00c7f840(const Vec4* t, const Vec4* p)
{
    const __m128 d = InversePositionHardware::_mm_sub_ps(p->value, t[0].value);
    const __m128 q = t[1].value;
    const __m128 w4 = _mm_shuffle_ps(q, q, 0xff);
    const __m128 qd = _mm_mul_ps(q, d);
    __m128 dot = _mm_add_ss(_mm_shuffle_ps(qd, qd, 0x55), qd);
    dot = _mm_add_ss(_mm_shuffle_ps(qd, qd, 0xaa), dot);
    const __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xc9), _mm_shuffle_ps(d, d, 0xd2));
    const __m128 c2 = _mm_mul_ps(_mm_shuffle_ps(q, q, 0xd2), _mm_shuffle_ps(d, d, 0xc9));
    const __m128 cr = InversePositionHardware::_mm_sub_ps(c2, c1);
    __m128 r = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w4, w4), g_rotationOffset), d);
    r = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(dot, dot, 0), q));
    r = _mm_add_ps(_mm_mul_ps(cr, w4), r);
    const __m128 v = _mm_add_ps(r, r);
    value = v;
    const __m128 s = t[2].value;
    const __m128 rc = _mm_rcp_ps(s);
    const __m128 e = _mm_mul_ps(_mm_mul_ps(rc, s), rc);
    value = _mm_mul_ps(InversePositionHardware::_mm_sub_ps(_mm_add_ps(rc, rc), e), v);
}

namespace FloatHardware { extern "C" ::__m128 _mm_sub_ps(::__m128,::__m128); }
extern "C" {
extern ::__m128 _mm_load_ss(float const*);
extern void _mm_store_ss(float*, ::__m128);
extern ::__m128 _mm_mul_ps(::__m128, ::__m128);
extern ::__m128 _mm_add_ps(::__m128, ::__m128);
extern ::__m128 _mm_add_ss(::__m128, ::__m128);
extern ::__m128 _mm_unpackhi_ps(::__m128, ::__m128);
extern ::__m128 _mm_rsqrt_ps(::__m128);
extern void _mm_prefetch(char const*, int);
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern const ::__m128 DAT_010c71c0;
extern const ::__m128 DAT_010c71d0;
extern const ::__m128 DAT_010c71e0;
}

typedef ::__m128 hkQuadReal;
typedef float hkReal;

class VectorComponentValue {
public:
    __forceinline VectorComponentValue(const hkQuadReal& x) : m_vValue(x) {}
    __forceinline VectorComponentValue() {}
    __forceinline hkQuadReal broadcast() const { return (_mm_shuffle_ps)(m_vValue, m_vValue, 0); }
    __forceinline const hkQuadReal& getQuad() const { return m_vValue; }
    hkQuadReal m_vValue;
};
typedef const VectorComponentValue& hkSimdRealParameter;

class hkBool {
public:
    __forceinline hkBool() {}
    __forceinline hkBool(bool b) { m_cBooleanValue = (char)b; }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};

class hkQuaternion;
class hkQsTransform;

class __declspec(align(16)) hkVector4 {
public:
    __forceinline hkVector4() {}
    __forceinline hkQuadReal& getQuad() { return m_vComponents; }
    __forceinline void operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; }
    __forceinline void SetAllComponents(hkSimdRealParameter a) { m_vComponents = (_mm_shuffle_ps)(a.getQuad(), a.getQuad(), 0); }
    __forceinline void add4(const hkVector4& v) { m_vComponents = (_mm_add_ps)(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1) { m_vComponents = (_mm_add_ps)(v0.m_vComponents, v1.m_vComponents); }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1) { m_vComponents = (FloatHardware::_mm_sub_ps)(v0.m_vComponents, v1.m_vComponents); }
    __forceinline void sub4(const hkVector4& v) { m_vComponents = (FloatHardware::_mm_sub_ps)(m_vComponents, v.m_vComponents); }
    __forceinline void mul4(const hkVector4& v) { m_vComponents = (_mm_mul_ps)(m_vComponents, v.m_vComponents); }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b) { m_vComponents = (_mm_mul_ps)(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(hkSimdRealParameter s) { m_vComponents = (_mm_mul_ps)(s.broadcast(), m_vComponents); }
    __forceinline void addMul4(const hkVector4& x, const hkVector4& y) { m_vComponents = (_mm_add_ps)(m_vComponents, (_mm_mul_ps)(x.m_vComponents, y.m_vComponents)); }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& x, const hkVector4& y) { m_vComponents = (_mm_add_ps)(a.m_vComponents, (_mm_mul_ps)(x.m_vComponents, y.m_vComponents)); }
    __forceinline void addMul4(hkSimdRealParameter r, const hkVector4& v1) { m_vComponents = (_mm_add_ps)(m_vComponents, (_mm_mul_ps)(r.broadcast(), v1.m_vComponents)); }
    __forceinline void setCross(const hkVector4& v0, const hkVector4& v1) {
        hkQuadReal cross0;
        cross0 = (_mm_mul_ps)((_mm_shuffle_ps)(v0.m_vComponents, v0.m_vComponents, 0xc9), (_mm_shuffle_ps)(v1.m_vComponents, v1.m_vComponents, 0xd2));
        hkQuadReal cross1;
        cross1 = (_mm_mul_ps)((_mm_shuffle_ps)(v0.m_vComponents, v0.m_vComponents, 0xd2), (_mm_shuffle_ps)(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = (FloatHardware::_mm_sub_ps)(cross0, cross1);
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const {
        hkQuadReal x2 = (_mm_mul_ps)(m_vComponents, a.m_vComponents);
        hkQuadReal xySum = (_mm_add_ss)((_mm_shuffle_ps)(x2, x2, 0x55), x2);
        return (_mm_add_ss)((_mm_shuffle_ps)(x2, x2, 0xaa), xySum);
    }
    __forceinline VectorComponentValue lengthSquared3() const { return this->dot3(*this); }
    __forceinline void setXYZW(const hkVector4& xyz, const hkVector4& w) {
        m_vComponents = (_mm_shuffle_ps)(xyz.m_vComponents, (_mm_unpackhi_ps)(xyz.m_vComponents, w.m_vComponents), 0xc4);
    }
    __forceinline void setSqrtInverse4(const hkVector4& vec) {
        hkQuadReal r = vec.m_vComponents;
        hkQuadReal e = (_mm_rsqrt_ps)(r);
        hkQuadReal he = (_mm_mul_ps)(DAT_010c71d0, e);
        hkQuadReal ree = (_mm_mul_ps)((_mm_mul_ps)(r, e), e);
        m_vComponents = (_mm_mul_ps)(he, (FloatHardware::_mm_sub_ps)(DAT_010c71c0, ree));
    }
    __forceinline VectorComponentValue getSimdAt(int i) const {
        switch (i) {
        case 0: return m_vComponents;
        case 1: return (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0x55);
        case 2: return (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0xaa);
        default: return (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0xff);
        }
    }
    __forceinline void broadcast(int i) {
        if (i == 0) m_vComponents = (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0);
        else if (i == 1) m_vComponents = (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0x55);
        else if (i == 2) m_vComponents = (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0xaa);
        else if (i == 3) m_vComponents = (_mm_shuffle_ps)(m_vComponents, m_vComponents, 0xff);
    }
    __forceinline void setBroadcast(const hkVector4& v, int i) {
        if (i == 0) m_vComponents = (_mm_shuffle_ps)(v.m_vComponents, v.m_vComponents, 0);
        else if (i == 1) m_vComponents = (_mm_shuffle_ps)(v.m_vComponents, v.m_vComponents, 0x55);
        else if (i == 2) m_vComponents = (_mm_shuffle_ps)(v.m_vComponents, v.m_vComponents, 0xaa);
        else if (i == 3) m_vComponents = (_mm_shuffle_ps)(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction);
    __forceinline void _setTransformedPos(const hkQsTransform& a, const hkVector4& b);
    hkQuadReal m_vComponents;
};

class __declspec(align(16)) hkQuaternion {
public:
    __forceinline hkQuaternion() {}
    __forceinline const hkVector4& getImag() const { return m_vec; }
    __forceinline void operator=(const hkQuaternion& q) { m_vec = q.m_vec; }
    void FUN_00c66320(const hkQuaternion& q0, const hkQuaternion& q1);
    void FUN_00cd9d10(const hkVector4& from, const hkVector4& to);
    hkVector4 m_vec;
};

inline __declspec(noinline) void hkQuaternion::FUN_00c66320(const hkQuaternion& q0, const hkQuaternion& q1) {
    hkVector4 vec;
    vec.setCross(q0.getImag(), q1.getImag());
    vec.addMul4(q0.m_vec.getSimdAt(3), q1.getImag());
    vec.addMul4(q1.m_vec.getSimdAt(3), q0.getImag());
    hkVector4 dot;
    dot.SetAllComponents(q0.m_vec.dot3(q1.m_vec));
    hkVector4 w;
    w.setMul4(q0.m_vec, q1.m_vec);
    w.sub4(dot);
    m_vec.setXYZW(vec, w);
}

class __declspec(align(16)) hkQsTransform {
public:
    __forceinline hkQsTransform() {}
    __forceinline const hkVector4& getTranslation() const { return m_vTranslation; }
    __forceinline const hkQuaternion& getRotation() const { return m_rotation; }
    __forceinline void SetBodyOrientation(const hkQuaternion& rotation) { m_rotation = rotation; }
    __forceinline void operator=(const hkQsTransform& t) {
        m_vTranslation = t.m_vTranslation;
        m_rotation = t.m_rotation;
        m_vScale = t.m_vScale;
    }
    __forceinline void SetProduct(const hkQsTransform& aTb, const hkQsTransform& bTc) {
        hkVector4 extraTrans;
        extraTrans.SetRotatedDirection(aTb.m_rotation, bTc.m_vTranslation);
        m_vTranslation.setAdd4(aTb.m_vTranslation, extraTrans);
        m_rotation.FUN_00c66320(aTb.m_rotation, bTc.m_rotation);
        m_vScale.setMul4(aTb.m_vScale, bTc.m_vScale);
    }
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
};

__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& quat, const hkVector4& direction) {
    hkVector4 minusHalf; minusHalf.getQuad() = DAT_010c71e0;
    hkVector4 qreal;
    qreal.setBroadcast(quat.m_vec, 3);
    hkVector4 q2minus1;
    q2minus1.setAddMul4(minusHalf, qreal, qreal);

    hkVector4 ret;
    ret.setMul4(direction, q2minus1);

    hkVector4 imagDotDir;
    imagDotDir.getQuad() = quat.getImag().dot3(direction).getQuad();
    imagDotDir.broadcast(0);
    ret.addMul4(imagDotDir, quat.getImag());

    hkVector4 imagCrossDir;
    imagCrossDir.setCross(quat.getImag(), direction);
    ret.addMul4(qreal, imagCrossDir);

    this->setAdd4(ret, ret);
}

__forceinline void hkVector4::_setTransformedPos(const hkQsTransform& a, const hkVector4& b) {
    hkVector4 temp(b);
    temp.mul4(a.m_vScale);
    SetRotatedDirection(a.m_rotation, temp);
    add4(a.m_vTranslation);
}

namespace MathUtilities {
    __forceinline void prefetch128(const void* p) { (_mm_prefetch)((const char*)p, 0); }
}
template <class T> __forceinline const T* hkAddByteOffsetConst(const T* base, long offset) {
    return reinterpret_cast<const T*>(reinterpret_cast<const char*>(base) + offset);
}

class hkMemoryAllocator {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
    template <class T> __forceinline void _bufFree(void* p, int numElem) { ReturnMemory(p, numElem * sizeof(T)); }
};

template <class T> class ValueWrapper {
public:
    __forceinline void operator=(T e) { m_kStorage = e; }
    __forceinline T val() const { return m_kStorage; }
    __forceinline operator T() const { return m_kStorage; }
    T m_kStorage;
};

template <class T> __forceinline T* hkAddByteOffset(T* base, long offset) {
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

struct StringPointerTriple {
    ValueWrapper<void*> m_next;
    __forceinline void* allocateStack(int numBytes, const char* what) {
        void* current = m_next;
        m_next = hkAddByteOffset(current, numBytes);
        return current;
    }
    __forceinline void deallocateStack(void* p) { m_next = p; }
};

class NineIntegerRecord {
public:
    static __forceinline NineIntegerRecord& GetMonitorStream() { return *(NineIntegerRecord*)FUN_00c85750(); }
    __forceinline StringPointerTriple& stack() { return m_aiEntries; }
    __forceinline hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
    StringPointerTriple m_aiEntries;
    int unk04, unk08, unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
};

template <class T> __forceinline T* hkAllocateStack(int n, const char* what = 0) {
    NineIntegerRecord& mem = NineIntegerRecord::GetMonitorStream();
    return static_cast<T*>(mem.stack().allocateStack(((n * (int)sizeof(T)) + 127) & ~127, what));
}
template <class T> __forceinline void hkDeallocateStack(T* ptr) {
    NineIntegerRecord::GetMonitorStream().stack().deallocateStack(static_cast<void*>(ptr));
}

struct RouterHeapAllocatorProvider {
    __forceinline hkMemoryAllocator& get(const void*) { return NineIntegerRecord::GetMonitorStream().heap(); }
};

struct hkTypeIsPod {};
namespace HavokArrayUtilities {
    template <class T> __forceinline void destruct(T*, int, hkTypeIsPod) {}
}

template <class T> class HavokElementArray {
public:
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void clear() { HavokArrayUtilities::destruct(m_data, m_iElementCount, hkTypeIsPod()); m_iElementCount = 0; }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc) {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0) alloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <class T> class hkArray : public HavokElementArray<T> {
public:
    __forceinline void ClearAndRelease() { HavokElementArray<T>::_clearAndDeallocate(RouterHeapAllocatorProvider().get(this)); }
};
template <class T> class StackAllocatedArray : public hkArray<T> {
public:
    __forceinline void init(int capacity) {
        this->m_data = 0;
        this->m_iElementCount = 0;
        this->m_iCapacityState = 0x80000000;
        this->m_data = hkAllocateStack<T>(capacity);
        this->m_iCapacityState = capacity | 0x80000000;
        m_pStackAllocation = this->m_data;
    }
    __forceinline hkBool wasReallocated() const { return m_pStackAllocation != this->m_data; }
    __forceinline void destroy() {
        if (!wasReallocated()) hkArray<T>::clear();
        hkDeallocateStack<T>(m_pStackAllocation);
        hkArray<T>::ClearAndRelease();
    }
    T* m_pStackAllocation;
};

class hkaSkeleton {
public:
    int unk00, unk04, unk08;
    hkArray<short> m_kParentIndices;
};

hkBool __cdecl WalkChainUntilLimit(const hkaSkeleton& skeleton, short start, short end, hkArray<short>& chain);
extern "C" void __cdecl FUN_00cde1d0(const hkaSkeleton& skeleton, hkQsTransform* pose);
extern "C" void __cdecl FUN_00cde2d0(const hkaSkeleton& skeleton, const hkQsTransform* ref, hkQsTransform* pose);

template <class T> class ReferenceCountedPointer {
public:
    __forceinline T* val() const { return m_pRetainedObject; }
    __forceinline T* operator->() const { return val(); }
    __forceinline operator T*() const { return val(); }
    T* m_pRetainedObject;
};

class __declspec(align(16)) hkaSkeletonMapperData {
public:
    struct __declspec(align(16)) SimpleMapping {
        short m_sBoneA;
        short m_sBoneB;
        hkQsTransform m_kAFromBTransform;
    };
    struct __declspec(align(16)) ChainMapping {
        short m_sStartBoneA;
        short m_sEndBoneA;
        short m_sStartBoneB;
        short m_sEndBoneB;
        hkQsTransform m_kStartAFromBTransform;
        hkQsTransform m_kEndAFromBTransform;
    };
    ReferenceCountedPointer<const hkaSkeleton> m_pSkeletonA;
    ReferenceCountedPointer<const hkaSkeleton> m_pSkeletonB;
    hkArray<SimpleMapping> m_kSimpleMappings;
    hkArray<ChainMapping> m_kChainMappings;
    hkArray<short> m_kUnmappedBones;
    hkQsTransform m_kExtractedMotionMapping;
    hkBool m_bKeepUnmappedLocal;
};

struct hkThreadLocalData {
    unsigned long m_slotID;
    __forceinline void* getData() const { return TlsGetValue(m_slotID); }
};
extern "C" hkThreadLocalData DAT_0126835c;

class StringCursor {
public:
    static __forceinline StringCursor& GetMonitorStream() { return *(StringCursor*)DAT_0126835c.getData(); }
    __forceinline char* GetStreamEnd() { return m_kRayEnd.val(); }
    __forceinline char* getCapacityMinus16() { return m_pCurrentCommand.val(); }
    __forceinline hkBool memoryAvailable() { return GetStreamEnd() < getCapacityMinus16(); }
    __forceinline void setEnd(char* ptr) { m_kRayEnd = ptr; }
    struct Command { const char* m_pCommandName; };
    struct CommandTimingEntry : public Command {
        unsigned int m_uiStartTicks;
        unsigned int m_uiEndTicks;
        __forceinline void setTime();
    };
    struct TimedNameRecord : public CommandTimingEntry {
        const char* m_pFirst;
    };
    ValueWrapper<char*> m_kRayStart;
    ValueWrapper<char*> m_kRayEnd;
    ValueWrapper<char*> m_pRayCursor;
    ValueWrapper<char*> m_pCurrentCommand;
};
__forceinline void StringCursor::CommandTimingEntry::setTime() {
    unsigned int ticks;
    __asm {
        rdtsc
        mov dword ptr[ticks], eax
    }
    m_uiStartTicks = ticks;
}

static __declspec(noinline) void FUN_00ce2a50(hkVector4& a, hkVector4& b) {
    hkVector4 aLen; aLen.SetAllComponents(a.lengthSquared3());
    hkVector4 bLen; bLen.SetAllComponents(b.lengthSquared3());
    hkVector4 lens; lens.setXYZW(aLen, bLen);
    hkVector4 inv; inv.setSqrtInverse4(lens);
    a.mul4(inv.getSimdAt(0));
    b.mul4(inv.getSimdAt(3));
}

class hkReferencedObject {
public:
    virtual ~hkReferencedObject();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkaSkeletonMapper : public hkReferencedObject {
public:
    void __cdecl FUN_00ce3a00(const hkQsTransform* poseAModelSpace, const hkQsTransform* originalPoseBLocalSpace, hkQsTransform* poseBModelSpace, int source) const;
    hkaSkeletonMapperData m_kMappingData;
};

// @fnv 0x00ce3a00
void __cdecl hkaSkeletonMapper::FUN_00ce3a00(const hkQsTransform* poseAModelSpace, const hkQsTransform* originalPoseBLocalSpace, hkQsTransform* poseBModelSpace, int source) const {
    {
        StringCursor& mStream = StringCursor::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            StringCursor::TimedNameRecord* h = reinterpret_cast<StringCursor::TimedNameRecord*>(mStream.GetStreamEnd());
            h->m_pCommandName = "LtMapPoseModelSpace";
            h->m_pFirst = "Stinit";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    {
        StringCursor& mStream = StringCursor::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            StringCursor::CommandTimingEntry* h = reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());
            h->m_pCommandName = "StsimpleMappings";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    {
        const int numSimpleMappings = m_kMappingData.m_kSimpleMappings.GetLogicalSize();
        for (int i = 0; i < numSimpleMappings; i++) {
            const int prefetchDistance = 128;
            MathUtilities::prefetch128(hkAddByteOffsetConst(&m_kMappingData.m_kSimpleMappings[i], prefetchDistance));
            const hkaSkeletonMapperData::SimpleMapping& simpleMapping = m_kMappingData.m_kSimpleMappings[i];
            poseBModelSpace[simpleMapping.m_sBoneB].SetProduct(poseAModelSpace[simpleMapping.m_sBoneA], simpleMapping.m_kAFromBTransform);
            MathUtilities::prefetch128(hkAddByteOffsetConst(&poseAModelSpace[simpleMapping.m_sBoneA], prefetchDistance));
            MathUtilities::prefetch128(hkAddByteOffsetConst(&poseBModelSpace[simpleMapping.m_sBoneB], prefetchDistance));
        }
    }
    {
        StringCursor& mStream = StringCursor::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            StringCursor::CommandTimingEntry* h = reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());
            h->m_pCommandName = "StchainMappings";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    {
        const int numChainMappings = m_kMappingData.m_kChainMappings.GetLogicalSize();
        for (int i = 0; i < numChainMappings; i++) {
            const hkaSkeletonMapperData::ChainMapping& chainMapping = m_kMappingData.m_kChainMappings[i];
            const short startBoneA = chainMapping.m_sStartBoneA;
            const short endBoneA = chainMapping.m_sEndBoneA;
            const short startBoneB = chainMapping.m_sStartBoneB;
            const short endBoneB = chainMapping.m_sEndBoneB;

            poseBModelSpace[startBoneB].SetProduct(poseAModelSpace[startBoneA], chainMapping.m_kStartAFromBTransform);

            StackAllocatedArray<short> chainBones;
            chainBones.init(endBoneB - startBoneB + 1);
            WalkChainUntilLimit(*m_kMappingData.m_pSkeletonB, startBoneB, endBoneB, chainBones);

            hkVector4 currentEndModelSpacePos;
            currentEndModelSpacePos = originalPoseBLocalSpace[endBoneB].getTranslation();
            for (int b = chainBones.GetLogicalSize() - 2; b >= 1; b--) {
                const short bone = chainBones[b];
                currentEndModelSpacePos._setTransformedPos(originalPoseBLocalSpace[bone], currentEndModelSpacePos);
            }
            currentEndModelSpacePos._setTransformedPos(poseBModelSpace[startBoneB], currentEndModelSpacePos);

            {
                const hkVector4& startModelSpacePos = poseBModelSpace[startBoneB].getTranslation();
                hkQsTransform desiredEndModelSpace;
                desiredEndModelSpace.SetProduct(poseAModelSpace[endBoneA], chainMapping.m_kEndAFromBTransform);
                const hkVector4& desiredEndModelSpacePos = desiredEndModelSpace.getTranslation();

                hkVector4 currentDirection; currentDirection.setSub4(currentEndModelSpacePos, startModelSpacePos);
                hkVector4 desiredDirection; desiredDirection.setSub4(desiredEndModelSpacePos, startModelSpacePos);
                FUN_00ce2a50(currentDirection, desiredDirection);

                hkQuaternion rotationQuaternion;
                rotationQuaternion.FUN_00cd9d10(currentDirection, desiredDirection);

                hkQuaternion currentRot = poseBModelSpace[startBoneB].getRotation();
                hkQuaternion temp;
                temp.FUN_00c66320(rotationQuaternion, currentRot);
                poseBModelSpace[startBoneB].SetBodyOrientation(temp);
            }

            for (int b = 1; b < chainBones.GetLogicalSize() - 1; b++) {
                const short childIdx = chainBones[b];
                const short parentIdx = chainBones[b - 1];
                const hkQsTransform& parentFromChild = originalPoseBLocalSpace[childIdx];
                const hkQsTransform& modelFromParent = poseBModelSpace[parentIdx];
                poseBModelSpace[childIdx].SetProduct(modelFromParent, parentFromChild);
            }
            chainBones.destroy();
        }
    }
    {
        StringCursor& mStream = StringCursor::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            StringCursor::CommandTimingEntry* h = reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());
            h->m_pCommandName = "StunmappedBones";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    {
        const int numUnmapped = m_kMappingData.m_kUnmappedBones.GetLogicalSize();
        if (m_kMappingData.m_bKeepUnmappedLocal) {
            for (int i = 0; i < numUnmapped; i++) {
                const short boneIdx = m_kMappingData.m_kUnmappedBones[i];
                const short parentIdx = m_kMappingData.m_pSkeletonB->m_kParentIndices[boneIdx];
                if (parentIdx != -1) {
                    const hkQsTransform& parentFromChild = originalPoseBLocalSpace[boneIdx];
                    const hkQsTransform& modelFromParent = poseBModelSpace[parentIdx];
                    poseBModelSpace[boneIdx].SetProduct(modelFromParent, parentFromChild);
                } else {
                    poseBModelSpace[boneIdx] = originalPoseBLocalSpace[boneIdx];
                }
            }
        }
    }
    {
        StringCursor& mStream = StringCursor::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            StringCursor::CommandTimingEntry* h = reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());
            h->m_pCommandName = "StenforceConstraints";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    switch (source) {
    case 1:
        FUN_00cde1d0(*m_kMappingData.m_pSkeletonB, poseBModelSpace);
        break;
    case 2:
        FUN_00cde2d0(*m_kMappingData.m_pSkeletonB, originalPoseBLocalSpace, poseBModelSpace);
        break;
    }
    {
        StringCursor& mStream = StringCursor::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            StringCursor::CommandTimingEntry* h = reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());
            h->m_pCommandName = "lt";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
}

// ---- Gamebryo / game helpers ----
void* __cdecl NiMalloc(unsigned int size);
void __cdecl NiFree(void* p);
void* __cdecl _fnv_zlib_memset(void* dst, int val, unsigned int n);

struct MM {
    void Deallocate(void* p);
};
extern MM _g_memoryManager;

namespace SkeletonBuild {

// ---- Havok memory ----
struct hkMemoryAllocator {
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct NineIntegerRecord {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* heap;
};
int __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* array, int capacity, int elemSize);
const char* __cdecl FUN_00cb1410(int name);

inline hkMemoryAllocator* HeapAllocator()
{
    NineIntegerRecord* r = reinterpret_cast<NineIntegerRecord*>(FUN_00c85750());
    return r->heap;
}

template<class T> struct HkArray {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    HkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~HkArray()
    {
        destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
        if (m_iCapacityState >= 0)
            HeapAllocator()->ReleaseBlock(m_data, getCapacity() * sizeof(T));
    }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator* alloc = HeapAllocator();
        if (getCapacity() < n) {
            int cap2 = getCapacity() * 2;
            FUN_00c908c0(alloc, this, n < cap2 ? cap2 : n, sizeof(T));
        }
    }
    __forceinline void reserveExactly(int n)
    {
        hkMemoryAllocator* alloc = HeapAllocator();
        if (getCapacity() < n)
            FUN_00c908c0(alloc, this, n, sizeof(T));
    }
    __forceinline void setSizePod(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    __forceinline void setSizeFill(int n, int fill)
    {
        reserve(n);
        int count = n - m_iElementCount;
        int* p = reinterpret_cast<int*>(m_data + m_iElementCount);
        for (int i = 0; i < count; ++i)
            p[i] = fill;
        m_iElementCount = n;
    }
    static __forceinline void destruct(T* t, int n)
    {
        for (int i = 0; i < n; ++i)
            t[i].~T();
    }
    static __forceinline void construct(T* t, int n)
    {
        for (int i = 0; i < n; ++i)
            new (t + i) T;
    }
    __forceinline void setSizeObj(int n)
    {
        reserve(n);
        destruct(m_data + n, m_iElementCount - n);
        construct(m_data + m_iElementCount, n - m_iElementCount);
        m_iElementCount = n;
    }
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
};

namespace SkeletonBuildHardware {
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float x, y, z, w;
};
}

struct hkVector4 {
    SkeletonBuildHardware::__m128 m_vComponents;
    void operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; }
};
struct hkBool {
    char m_cBooleanValue;
    hkBool() {}
    hkBool(bool b) : m_cBooleanValue(b) {}
    hkBool& operator=(bool b) { m_cBooleanValue = b; return *this; }
};
struct hkQsTransform {
    hkVector4 m_vTranslation;
    hkVector4 m_rotation;
    hkVector4 m_vScale;
    void operator=(const hkQsTransform& t) {
        m_vTranslation = t.m_vTranslation;
        m_rotation = t.m_rotation;
        m_vScale = t.m_vScale;
    }
};

struct hkStringPtr {
    const char* m_pcText;
    void FUN_00cb0a60();
    void FUN_00cb0c00();
    void FUN_00cb0c10(const char* s);
    hkStringPtr() { FUN_00cb0a60(); }
    ~hkStringPtr() { FUN_00cb0c00(); }
};

struct hkaBone {
    hkStringPtr m_name;
    hkBool m_bLockTranslation;
    hkaBone() { m_bLockTranslation = false; }
    void* operator new(unsigned int, void* p) { return p; }
    void operator delete(void*, void*) {}
};

struct hkReferencedObject {
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    __forceinline hkReferencedObject() { m_sReferenceCount = 1; }
    virtual ~hkReferencedObject() {}
    void* operator new(unsigned int n)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(HeapAllocator()->AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = static_cast<short>(n);
        return b;
    }
    void operator delete(void* p, unsigned int n) { HeapAllocator()->ReleaseBlock(p, n); }
};

struct hkaSkeleton : hkReferencedObject {
    hkStringPtr m_name;
    HkArray<short> m_kParentIndices;
    HkArray<hkaBone> m_kBones;
    HkArray<hkQsTransform> m_kReferencePose;
    HkArray<float> m_referenceFloats;
    HkArray<hkStringPtr> m_kBoneNames;
    __forceinline hkaSkeleton() {}
    virtual ~hkaSkeleton();
};

struct SkeletonPoseData {
    const hkaSkeleton* m_pSkeleton;
    HkArray<hkQsTransform> m_pLocalPose;
    HkArray<hkQsTransform> m_pModelPose;
    HkArray<unsigned int> m_pBoneFlags;
    hkBool m_bPoseFlag;
    hkBool m_bPoseInitialized;
    HkArray<float> m_kPoseData;

    void* operator new(unsigned int n) { return HeapAllocator()->AllocateMemoryBlock(n); }
    void operator delete(void* p, unsigned int n) { HeapAllocator()->ReleaseBlock(p, n); }

    __forceinline SkeletonPoseData(const hkaSkeleton* skeleton) : m_pSkeleton(skeleton), m_bPoseFlag(false), m_bPoseInitialized(false)
    {
        const int numBones = m_pSkeleton->m_kBones.GetLogicalSize();
        m_pModelPose.setSizePod(numBones);
        m_pLocalPose.setSizePod(numBones);
        m_pBoneFlags.setSizePod(numBones);
        m_kPoseData.reserveExactly((m_pSkeleton->m_referenceFloats.GetLogicalSize() + 3) & ~3);
        m_kPoseData.setSizeFill(m_pSkeleton->m_referenceFloats.GetLogicalSize(), 0);
    }
    void FUN_00cda110();
};

// ---- gathered bone records ----
struct BoneRecord {
    int name;
    int unk04;
    int unk08;
    int unk0c;
    hkQsTransform transform;
    short parent;
};

struct BoneRecordArray {
    BoneRecord** m_pBase;
    unsigned int m_uiSize;
    unsigned int m_uiMaxSize;
    BoneRecordArray() : m_pBase(0), m_uiSize(0), m_uiMaxSize(0) {}
    virtual ~BoneRecordArray()
    {
        if (m_pBase)
            Free(m_pBase);
    }
    virtual void* Alloc(unsigned int n);
    __declspec(dllimport) virtual void Free(void* p);
    void RemoveAll()
    {
        if (m_pBase) {
            Free(m_pBase);
            m_pBase = 0;
            m_uiMaxSize = 0;
            m_uiSize = 0;
        }
    }
};

struct NiTMapItemStub {
    NiTMapItemStub* m_pkNext;
    int m_key;
    int m_val;
};

struct NiTMapBaseStub {
    unsigned int m_uiHashSize;
    NiTMapItemStub** m_ppkHashTable;
    unsigned int m_uiCount;
    NiTMapBaseStub(unsigned int uiHashSize = 37)
    {
        m_uiHashSize = uiHashSize;
        m_uiCount = 0;
        unsigned int uiSize = sizeof(NiTMapItemStub*) * m_uiHashSize;
        m_ppkHashTable = static_cast<NiTMapItemStub**>(NiMalloc(uiSize));
        unsigned int bytes = m_uiHashSize * sizeof(NiTMapItemStub*);
        _fnv_zlib_memset(m_ppkHashTable, 0, bytes);
    }
    virtual ~NiTMapBaseStub()
    {
        RemoveAll();
        NiFree(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(int key) const;
    void RemoveAll();
};

struct BoneRecordMap : NiTMapBaseStub {
    BoneRecordMap() {}
    virtual ~BoneRecordMap() { RemoveAll(); }
};

template<class T> struct PlainPtr {
    T* ptr;
    T* operator->() const { return ptr; }
    operator T*() const { return ptr; }
    T* operator=(T* p) { ptr = p; return p; }
};
struct SkeletonHolder {
    int unk00;
    int unk04;
    int unk08;
    hkaSkeleton* m_pSkeleton;
};

struct BuildNode {
    int key;
    int unk04;
    void* payload;
};
BuildNode* __cdecl FUN_00c802d0(void* root);

struct AnimationOwner {
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
    void* root;
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
    SkeletonPoseData* pose;
    int unk08c;
    int unk090;
    HkArray<hkQsTransform> transforms;
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
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    PlainPtr<SkeletonHolder> skeletonHolder;

    void FUN_00c7b4f0(void* node, BoneRecordArray* records, BoneRecordMap* map);
    void FUN_00c7e3b0();
};

// @fnv 0x00c7e3b0
void AnimationOwner::FUN_00c7e3b0()
{
    if (!root)
        return;

    void* node = FUN_00c802d0(root)->payload;
    BoneRecordArray records;
    BoneRecordMap map;
    FUN_00c7b4f0(node, &records, &map);

    SkeletonHolder* holder = skeletonHolder;
    if (!holder->m_pSkeleton) {
        skeletonHolder->m_pSkeleton = new hkaSkeleton;
        int numBones = records.m_uiSize;
        skeletonHolder->m_pSkeleton->m_kBones.setSizeObj(numBones);
        skeletonHolder->m_pSkeleton->m_kParentIndices.setSizePod(numBones);
        skeletonHolder->m_pSkeleton->m_kReferencePose.setSizePod(numBones);
        for (unsigned int i = 0; i < records.m_uiSize; ++i) {
            hkaBone& bone = skeletonHolder->m_pSkeleton->m_kBones[i];
            bone.m_name.FUN_00cb0c10(FUN_00cb1410(records.m_pBase[i]->name));
            skeletonHolder->m_pSkeleton->m_kBones[i].m_bLockTranslation = true;
            skeletonHolder->m_pSkeleton->m_kReferencePose[i] = records.m_pBase[i]->transform;
            skeletonHolder->m_pSkeleton->m_kParentIndices[i] = records.m_pBase[i]->parent;
        }
    }

    for (unsigned int i = 0; i < records.m_uiSize; ++i) {
        BoneRecord* r = records.m_pBase[i];
        if (r)
            _g_memoryManager.Deallocate(reinterpret_cast<char*>(r) - reinterpret_cast<unsigned char*>(r)[-1]);
    }
    records.RemoveAll();

    pose = new SkeletonPoseData(skeletonHolder->m_pSkeleton);
    pose->FUN_00cda110();
    transforms.setSizePod(skeletonHolder->m_pSkeleton->m_kBones.GetLogicalSize());
}

} // namespace SkeletonBuild

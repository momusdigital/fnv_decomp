// src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer_ehsc_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer_ehsc_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct D625A0Allocator;
void __cdecl FUN_00c908c0(D625A0Allocator* alloc, void* array, int numElements, int sizeElem);
void __cdecl D625A0MemMove(void* dst, const void* src, unsigned int nbytes);
struct D625A0CharArray {
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void ReplaceRange(D625A0Allocator& alloc, int index, int numdel, const char* p, int numtoinsert);
};
extern char d_010d17d0;
char *FUN_00d634d0();
struct ItemSink;
typedef void (__thiscall* ProcessFn)(ItemSink* apThis, void* apItem);
struct ItemSinkVtbl {
    void* fn00;
    ProcessFn Process;
};
struct ItemSink {
    ItemSinkVtbl* m_pVtbl;
};
struct ItemHolder {
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
    void** m_ppItems;
    int m_iArrayLength;
};
struct FUN_00d634e0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ItemSink m_kSink;
    ItemHolder* m_pHolder;

    void ProcessItems();
};
struct HeadPart {
    virtual void h00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct OurPart {
    virtual void o00();

    int m_i04;

    void RegisterAndNotify(struct Registry* apRegistry);
};
struct NotifyTarget {
    virtual void v00();
    virtual void Notify(void* apItem);
};
struct SecondTarget {
    virtual void w00();
};
struct Container : HeadPart, OurPart, NotifyTarget, SecondTarget {
};
struct ItemList {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void** m_ppItems;
    int m_iArrayLength;

    void FUN_00c905b0();
};
struct Registry {
    void FUN_00c937a0(NotifyTarget* apTarget);
    void FUN_00c93920(SecondTarget* apTarget);
    ItemList* FUN_00c929e0();
};
struct Factory {
    void* FUN_00dd9380(const char*, void*);
};
extern void* DAT_01268fcc;
extern Factory* DAT_01269cd0;
extern const char DAT_010d17c4;
extern void AllocAndInitObject();
void __cdecl FUN_00d63da0();
extern int g_D63DC0Value;
int __cdecl FUN_00d63dc0();
// PassMembersToTarget - forwarding stub for a "container of" style object.
//
// `this` points at a sub-object that lives 0x20 bytes into a bigger object;
// the code recovers the owner pointer (this - 0x20) and passes it on to the
// two Target methods, which are called with the owner as their `this`.
struct Target {
    void FUN_00c91700(void* apArg);
    void ClearValue(void* apArg);
};
struct FUN_00d63480_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    void PassMembersToTarget(Target* apTarget);
};
// FUN_00d63c50 - the constructor of the Havok vehicle viewer
// (hkpVehicleViewer).
//
// The base class constructor (hkpWorldViewerBase) is called first with the
// argument that was passed in; afterwards the vtable pointer of the two
// listener bases and the vtable pointers of the viewer's own five base
// sub-objects are stored, and the last three members are initialised.
struct ViewerArg {
    int unk00;
    int unk04;
};
// hkpWorldViewerBase - its constructor is not defined here, so the call stays
// an external reference and the checker binds it from the original's bytes.
struct WorldViewerBase {
    WorldViewerBase(ViewerArg* arg);
    int* m_vtbl00;    // +0x00
    int  unk04;       // +0x04
    int* m_vtbl08;    // +0x08
    int  unk0c;       // +0x0c
    int  unk10;       // +0x10
    int  unk14;       // +0x14
    int  unk18;       // +0x18
    int  unk1c;       // +0x1c
    int* m_vtbl20;    // +0x20
    int  unk24;       // +0x24
};
struct FUN_00d63c50 : public WorldViewerBase {
    FUN_00d63c50(ViewerArg* arg);
    int* volatile m_vtbl28;   // +0x28
    int* volatile m_vtbl2c;   // +0x2c
    volatile int m_30;        // +0x30
    volatile int m_34;        // +0x34
    volatile int m_38;        // +0x38
};
// the vftables of the class and of its bases
extern int DAT_010cb1d4;
extern int DAT_010ccf7c;
extern int DAT_010d1854;
extern int DAT_010d1834;
extern int DAT_010d1824;
extern int DAT_010d1814;
extern int DAT_010d1804;
struct S_Heap { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void ReturnMemory(void* p, int n) throw(); };
struct S_Holder { int unk00; int unk04; int unk08; int unk0c; S_Heap* m10; S_Heap& heap() { return *m10; } };
void* __cdecl FUN_00c85750() throw();
struct S_P
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
    int unk68;
    void** m6c;
    int m70;
};
struct S_B0 { virtual void b0v0(); int unk04; };
struct S_B8 { virtual void b8v0(); int unk0C; int unk10; int unk14; int unk18; int unk1C; };
struct S_B20 { virtual void b20v0(); void PassMembersToTarget(void* child); };
struct FUN_00ddcc60 : S_B0, S_B8, S_B20
{
    S_P* m24;
    virtual ~FUN_00ddcc60() throw();
};
struct S_D { virtual ~S_D() throw() {} };
struct S_E { virtual ~S_E() throw() {} };
struct S_Arr
{
    void** m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void clear() throw()
    {
        S_Heap& heap = ((S_Holder*)FUN_00c85750())->heap();
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0) heap.ReturnMemory(m_data, (m_cap & 0x3fffffff) * (int)sizeof(void*));
        m_data = 0;
        m_cap = 0x80000000;
    }
};
struct FUN_00d63cb0 : FUN_00ddcc60, S_D, S_E
{
    S_Arr m30;
    virtual ~FUN_00d63cb0() throw();
};
class hkMemoryAllocatorD635;
struct hkMemoryRouterD635 {
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD635* m_pStreamAllocator;
    hkMemoryAllocatorD635& heap() { return *m_pStreamAllocator; }
};
namespace hkD635 {
    extern "C" hkMemoryRouterD635& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iSizeElem) throw();
struct hkBoolD635 {
    char m_cBooleanValue;
    operator bool() const { return m_cBooleanValue != 0; }
};
class hkClassD635 {
public:
    hkBoolD635 FUN_00d46d80(const hkClassD635& k) const throw();
};
class hkReferencedObjectD635 {
public:
    void FUN_00c90510() throw();
};
class hkClassNameRegistryD635 {
public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual const hkClassD635* GetClassByName(const char* className) const;
};
class hkVtableClassRegistryD635 {
public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual const hkClassD635* GetClassFromVirtualInstance(const void* obj) const;
};
class hkBuiltinTypeRegistryD635 {
public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual hkClassNameRegistryD635* GetClassNameRegistry();
    virtual hkVtableClassRegistryD635* GetVtableClassRegistry();
};
namespace hkD635 {
    extern hkBuiltinTypeRegistryD635* DAT_01268b08;
}
template <class T>
class hkArrayD635 {
public:
    __forceinline void AddBack(const T& t)
    {
        _pushBack(hkD635::FUN_00c85750(), t);
    }
    __forceinline void _pushBack(hkMemoryRouterD635& router, const T& t)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&router.heap(), this, sizeof(T));
        constructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    static __forceinline void constructWithCopy(T* p, int n, const T& tcopy)
    {
        for (int i = 0; i < n; ++i)
            p[i] = tcopy;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
class VehicleViewerD635 {
public:
    void AddVehicle(hkReferencedObjectD635* pkObj);

    int unk00, unk04;
    hkArrayD635<hkReferencedObjectD635*> m_ppVehicles;
};
// VC9 adjustor thunk: dual-slot override + static global forces
// [thunk]: TO::FUN_00d63dd0`adjustor{32}' = sub ecx,0x20; jmp TO::FUN_00d63dd0
struct Prim {
    virtual void FUN_00d63dd0();
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
};
struct B1 {
    virtual void FUN_00d63dd0();
};
struct TO : Prim, B1 {
// @fnv 0x00d63dd0
    virtual void FUN_00d63dd0();
};
static TO g_thunk;
// sub ecx,8; jmp Destroy
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (8 = vptr + one int field).
struct PrimaryBase
{
    virtual void FUN_00d63de0();
    int unk04;
};
struct SecondaryBase
{
    virtual void FUN_00d63de0();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d63de0
    virtual void FUN_00d63de0();
};
Derived::Derived()
{
}
struct Parent;
struct FirstBase {
    virtual Parent* FUN_00d63df0(unsigned int flags)=0;
    unsigned int unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20,unk24;
};
struct Receiver {
    virtual Parent* FUN_00d63df0(unsigned int flags)=0;
};
struct Parent : FirstBase,Receiver {
    Parent();
// @fnv 0x00d63df0
    virtual Parent* FUN_00d63df0(unsigned int flags);
};
Parent::Parent() {}
// FUN_00d63e00 : MSVC this-adjusting thunk  (sub ecx, 0x2c ; jmp <impl>)
struct A1_00d63e00 {
    A1_00d63e00();
    virtual void FUN_00d63e00();
    char pad[0x28];
};
struct A2_00d63e00 {
    A2_00d63e00();
    virtual void FUN_00d63e00();
};
struct Own_00d63e00 : A1_00d63e00, A2_00d63e00 {
    Own_00d63e00();
    virtual void key_fn();
// @fnv 0x00d63e00
    void FUN_00d63e00();
};
Own_00d63e00::Own_00d63e00() { }
void Own_00d63e00::key_fn() { }
Own_00d63e00* make_00d63e00() { static Own_00d63e00 o; return &o; }

namespace VehicleStepD63680 {
extern "C" void __cdecl __debugbreak(void);
typedef float hkReal;
typedef signed char hkInt8;
typedef signed short hkInt16;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef signed long __w64 hkLong;
enum hkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef unsigned __w64 hk_size_t;
typedef hkUint16 hkObjectIndex;__forceinline hkLong __cdecl hkGetByteOffset(const void*base,const void*pntr)
{
return hkLong(pntr)-hkLong(base);
}
template<typename TYPE>
__forceinline TYPE*__cdecl hkAddByteOffset(TYPE*base,hkLong offset)
{
return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base)+offset);
}
class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkClass;
class hkBool
{
public:
typedef char CompileTimeTrueType;inline hkBool(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};
class hkHalf
{
public:
inline hkHalf(){}
inline hkHalf(const float&f)
{
int t=((const int*)&f)[0];
m_uiFilterValue=hkInt16(t>>16);
}
private:
hkInt16 m_uiFilterValue;};template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
operator ENUM()const
{
return static_cast<ENUM>(m_kStorage);
}
void operator=(ENUM e)
{
m_kStorage=static_cast<STORAGE>(e);
}
private:
STORAGE m_kStorage;};
template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
__forceinline void operator=(TYPE e)
{
m_kStorage=e;
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline operator TYPE()const
{
return val();
}
private:
TYPE m_kStorage;};
extern "C"{
__declspec(dllimport)void*_stdcall TlsGetValue(unsigned long dwTlsIndex);}
template<typename T>
class hkThreadLocalData
{
public:
hkThreadLocalData();
__forceinline T getData()const
{
return(T)(hkUlong)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
template<typename T>struct TypeSizeConstant{enum{val=sizeof(T)};};
class hkMemoryAllocator
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();
void*allocateStack(int numBytes,const char*what);
__forceinline void deallocateStack(void*p);
__forceinline int getFreeStackSize(){return int(hkGetByteOffset(m_next,m_kRayEnd));}
protected:
ValueWrapper<void*>m_next;
ValueWrapper<void*>m_kRayEnd;};__forceinline void*StringPointerTriple::allocateStack(int numBytes,const char*what)
{
;
if(numBytes>getFreeStackSize())
{
;
}
void*current=m_next;
m_next=hkAddByteOffset(current,numBytes);
return current;
}
void StringPointerTriple::deallocateStack(void*p)
{
;
m_next=p;
}
class NineIntegerRecord
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
typedef hkMemoryAllocator Allocator;
static NineIntegerRecord&__cdecl GetMonitorStream(){return *static_cast<NineIntegerRecord*>(::FUN_00c85750());}
inline StringPointerTriple&stack(){return m_aiEntries;}
inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;};template<typename TYPE>
__forceinline TYPE*__cdecl hkAllocateStack(int n,const char*what=0)
{
NineIntegerRecord&mem=NineIntegerRecord::GetMonitorStream();
return static_cast<TYPE*>(mem.stack().allocateStack((((n*TypeSizeConstant<TYPE>::val)+((128)-1))&(~((128)-1))),what));
}
template<typename TYPE>
__forceinline void __cdecl hkDeallocateStack(TYPE*ptr)
{
NineIntegerRecord::GetMonitorStream().stack().deallocateStack(static_cast<void*>(ptr));
}
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject(){}
};
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
__forceinline hkReferencedObject();
virtual ~hkReferencedObject(){}
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(class FinishingFlag flag){}
};template<class TYPE>
class ReferenceCountedPointer
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
TYPE*m_pRetainedObject;};template<bool N>struct BooleanTypeConstant{typedef BooleanTypeConstant<N>type;enum{result=N};};
typedef BooleanTypeConstant<true>hkTypeIsPod;
struct RouterHeapAllocatorProvider
{
hkMemoryAllocator&get(const void*){return NineIntegerRecord::GetMonitorStream().heap();}
};
template<typename T>
class HavokElementArray
{
public:
typedef HavokElementArray<T>ThisType;
__forceinline HavokElementArray();
protected:
__forceinline HavokElementArray(const HavokElementArray&a){;}
public:
__forceinline void _useExternalArray(T*,int cap);
__forceinline T&operator[](int i);
__forceinline const T&operator[](int i)const;
__forceinline int GetLogicalSize()const;
protected:
__forceinline HavokElementArray<T>&copyFromArray(hkMemoryAllocator&,const HavokElementArray<T>&src,hkTypeIsPod);
public:
enum
{
CAPACITY_MASK=int(0x3FFFFFFF),
FLAG_MASK=int(0xC0000000),
DONT_DEALLOCATE_FLAG=int(0x80000000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
T*m_data;
int m_iElementCount;
int m_iCapacityState;
public:
HavokElementArray(FinishingFlag f){}
};
template<typename T,typename Allocator=RouterHeapAllocatorProvider>
class hkArray:public HavokElementArray<T>
{
public:
typedef Allocator AllocatorType;
__forceinline hkArray():HavokElementArray<T>(){}
hkArray(FinishingFlag f):HavokElementArray<T>(f){}
protected:
__forceinline hkArray(const hkArray&a);
public:
__forceinline hkArray&operator=(const HavokElementArray<T>&a);};
template<typename T>
__forceinline T&HavokElementArray<T>::operator[](int i)
{
;
return m_data[i];
}
template<typename T>
__forceinline const T&HavokElementArray<T>::operator[](int i)const
{
;
return m_data[i];
}
template<typename T>
__forceinline int HavokElementArray<T>::GetLogicalSize()const
{
return m_iElementCount;
}
template<typename T>
class ResizableArray
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
enum
{
CAPACITY_MASK=hkUint16(0x3fff),
FLAG_MASK=hkUint16(0xC000),
DONT_DEALLOCATE_FLAG=hkUint16(0x8000),
LOCKED_FLAG=hkUint16(0x4000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
public:
ResizableArray(FinishingFlag f){}
};
typedef union __declspec(intrin_type)__declspec(align(16))__m128{
struct { __int32 x, y, z, w; } lanes;}__m128;
extern "C"{
extern __m128 _mm_add_ss(__m128 _A,__m128 _B);
extern __m128 _mm_add_ps(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ss(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ps(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ss(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ps(__m128 _A,__m128 _B);
extern __m128 _mm_rsqrt_ss(__m128 _A);
extern __m128 _mm_andnot_ps(__m128 _A,__m128 _B);
extern __m128 _mm_cmpeq_ss(__m128 _A,__m128 _B);
extern __m128 _mm_shuffle_ps(__m128 _A,__m128 _B,unsigned int _Imm8);
extern __m128 _mm_set_ss(float _A);
extern __m128 _mm_load_ss(float const*_A);};
typedef __m128 hkQuadReal;
class hkVector4;
typedef const hkVector4&hkVector4Parameter;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
VectorComponentValue(hkReal x)
{
m_vValue=_mm_load_ss(&x);
}
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
__forceinline const hkQuadReal&getQuad()const
{
return m_vValue;
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;
extern const hkQuadReal DAT_010c71e0;
class hkQuaternion;
class hkQsTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void add4(const hkVector4&a);
__forceinline void setAdd4(const hkVector4&a,const hkVector4&b);
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void setMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void mul4(hkSimdRealParameter a);
__forceinline void setMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void addMul4(hkVector4Parameter a,hkVector4Parameter b);
__forceinline void setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r);
__forceinline void setAddMul4(const hkVector4&a,const hkVector4&x,const hkVector4&y);
__forceinline void setCross(const hkVector4&a,const hkVector4&b);
__forceinline void SetRotatedDirection(const hkQuaternion&q,const hkVector4&b);
__forceinline VectorComponentValue dot3(const hkVector4&a)const;
__forceinline VectorComponentValue lengthInverse3()const;
__forceinline void normalize3();
__forceinline void broadcast(int i);
__forceinline void setBroadcast(hkVector4Parameter v,int i);
__forceinline hkQuadReal&getQuad();
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
class hkQuaternion
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
inline hkQuaternion(const hkVector4&axis,hkReal angle);
void FUN_00cb2450(const hkVector4&axis,hkReal angle);
__forceinline const hkVector4&getImag()const;
public:
hkVector4 m_vec;
protected:
void setFlippedRotation(const hkVector4&from);};class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
protected:
hkVector4 m_kColumn0;
hkVector4 m_kColumn1;
hkVector4 m_kColumn2;};class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
hkRotation m_rotation;};
inline hkQuadReal&hkVector4::getQuad()
{
return m_vComponents;
}
inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4::add4(const hkVector4&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setMul4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
}
inline void hkVector4::mul4(hkSimdRealParameter s)
{
m_vComponents=_mm_mul_ps(s.broadcast(),m_vComponents);
}
inline void hkVector4::setMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_mul_ps(r.broadcast(),v1.m_vComponents);
}
inline void hkVector4::addMul4(const hkVector4&x,const hkVector4&y)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4::setAddMul4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter r)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(r.broadcast(),b.m_vComponents));
}
inline void hkVector4::setAddMul4(const hkVector4&a,const hkVector4&x,const hkVector4&y)
{
m_vComponents=_mm_add_ps(a.m_vComponents,
_mm_mul_ps(x.m_vComponents,y.m_vComponents));
}
inline void hkVector4::setCross(const hkVector4&v0,const hkVector4&v1)
{
hkQuadReal cross0;
cross0=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))));
hkQuadReal cross1;
cross1=_mm_mul_ps(
_mm_shuffle_ps(v0.m_vComponents,v0.m_vComponents,(((3)<<6)|((1)<<4)|((0)<<2)|((2)))),
_mm_shuffle_ps(v1.m_vComponents,v1.m_vComponents,(((3)<<6)|((0)<<4)|((2)<<2)|((1)))));
m_vComponents=_mm_sub_ps(cross0,cross1);}
inline VectorComponentValue hkVector4::dot3(const hkVector4&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline VectorComponentValue hkVector4::lengthInverse3()const
{
const hkQuadReal half=_mm_set_ss(0.5f);
const hkQuadReal three=_mm_set_ss(3.0f);
const hkQuadReal zero=_mm_set_ss(0.0f);
const hkQuadReal len2=this->dot3(*this).getQuad();
const hkQuadReal len2EqualsZero=_mm_cmpeq_ss(len2,zero);
const hkQuadReal approx=_mm_rsqrt_ss(len2);
const hkQuadReal refined=_mm_mul_ss(
_mm_mul_ss(half,approx),
_mm_sub_ss(three,_mm_mul_ss(_mm_mul_ss(len2,approx),approx)));
return _mm_andnot_ps(len2EqualsZero,refined);}
inline void hkVector4::normalize3()
{
hkQuadReal lenInv=lengthInverse3().broadcast();
m_vComponents=_mm_mul_ps(lenInv,m_vComponents);
}
inline void hkVector4::broadcast(int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(m_vComponents,m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
}
inline void hkVector4::setBroadcast(const hkVector4&v,int i)
{
if(i==0)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
}
else if(i==3)
{
m_vComponents=_mm_shuffle_ps(v.m_vComponents,v.m_vComponents,(((3)<<6)|((3)<<4)|((3)<<2)|((3))));
}
}
__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion&quat,const hkVector4&direction)
{
hkVector4 minusHalf;minusHalf.getQuad()=DAT_010c71e0;
hkVector4 qreal;
qreal.setBroadcast(quat.m_vec,3);
hkVector4 q2minus1;
q2minus1.setAddMul4(minusHalf,qreal,qreal);
hkVector4 ret;
ret.setMul4(direction,q2minus1);
hkVector4 imagDotDir;
imagDotDir.getQuad()=quat.getImag().dot3(direction).getQuad();
imagDotDir.broadcast(0);
ret.addMul4(imagDotDir,quat.getImag());
hkVector4 imagCrossDir;
imagCrossDir.setCross(quat.getImag(),direction);
ret.addMul4(qreal,imagCrossDir);
this->setAdd4(ret,ret);}
inline const hkVector4&hkQuaternion::getImag()const
{
return m_vec;
}
inline hkQuaternion::hkQuaternion(const hkVector4&axis,hkReal angle)
{
FUN_00cb2450(axis,angle);
}
class hkStringPtr
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkStringPtr(FinishingFlag f);
private:
const char*m_pcText;};
class hkMultiThreadCheck
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
enum ReadMode
{
THIS_OBJECT_ONLY,
RECURSIVE
};
protected:
void markForReadImpl(ReadMode mode);
public:
enum
{
MARKED_RO=0xffffffe1,
MARKED_RO_SELF_ONLY=0xffffffc1,
UNMARKED=0xfffffff1
};
protected:
hkUint16 m_usMarkCount;
public:
static class PhysicsSimulationContext*m_pWorldLock;};
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkVector4&getPosition()const;
protected:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVector4 m_vContactPosition;
hkVector4 m_vSeparatingNormal;};
inline const hkVector4&hkContactPoint::getPosition()const
{
return m_vContactPosition;
}
typedef hkUint32 hkpShapeKey;class hkpShape;
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
public:
const hkpShape*m_pCollisionShape;};
struct hkAabbUint32;
class hkpCollidable:public hkpCdBody
{
public:
static const struct ClassMemberDescriptor Members[];
public:
__forceinline hkUint32 GetFilterInfoForKey()const;
public:
struct BoundingVolumeData
{
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpCollidable::BoundingVolumeData));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
BoundingVolumeData();
BoundingVolumeData(class FinishingFlag flag);
__forceinline bool hasAllocations()const;
void deallocate();
void allocate(int numChildShapes);
__forceinline void invalidate(){m_min0=1;m_max0=0;}
__forceinline bool isValid()const{return m_min0<=m_max0;}
public:
hkUint32 m_min0, m_min1, m_min2;
hkUint8 m_expansionMin0, m_expansionMin1, m_expansionMin2;
hkUint8 m_ucExpansionShift;
hkUint32 m_max0, m_max1, m_max2;
hkUint8 m_expansionMax0, m_expansionMax1, m_expansionMax2;
hkUint8 m_ucUnknownByte;
hkUint16 m_uiNumChildShapeAabbs;
hkUint16 m_uiCapacityChildShapeAabbs;
hkAabbUint32*m_pChildShapeAabbs;
hkpShapeKey*m_pChildShapeKeys;
};
protected:
hkInt8 m_iOwnerOffset;
public:
hkUint8 m_uiForceCollideOntoPpu;
public:
struct BoundingVolumeData m_kBoundingVolumeData;};struct NarrowPhaseAgentEntry;
class hkpLinkedCollidable:public hkpCollidable
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
struct CollisionKeyEntry
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpLinkedCollidable::CollisionKeyEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
NarrowPhaseAgentEntry*m_pAgentEntry;
hkpLinkedCollidable*m_pCollidable;
};
protected:
hkArray<struct CollisionKeyEntry>m_kCollisionEntries;};class hkpWorldObject:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkpCollidable*getCollidable()const;
public:
enum BroadPhaseType
{
BROAD_PHASE_INVALID,
BROAD_PHASE_ENTITY,
BROAD_PHASE_PHANTOM,
BROAD_PHASE_BORDER,
BROAD_PHASE_MAX_ID
};
protected:
friend class hkpWorld;
public:
virtual class hkMotionState*GetMotionState()=0;
protected:
hkpWorld*m_pOwningWorld;
hkUlong m_ulUserData;
protected:
class hkpLinkedCollidable m_kCollidable;
protected:
class hkMultiThreadCheck m_kMultiThreadCheck;
private:
class hkReferencedObject*m_kNextStreamField;
public:
hkpWorldObject(class FinishingFlag flag);};inline const hkpCollidable*hkpWorldObject::getCollidable()const
{
return&m_kCollidable;
}
class hkpMaterial
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
enum ResponseType
{
RESPONSE_INVALID,
RESPONSE_SIMPLE_CONTACT,
RESPONSE_REPORTING,
RESPONSE_NONE,
RESPONSE_MAX_ID
};
private:
hkEnum<ResponseType,hkInt8>m_eResponseType;
public:
hkpMaterial(class FinishingFlag flag){}
};
class hkpConstraintInstance;
class hkpSimulationIsland;
class hkpMotion:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
enum MotionType
{
MOTION_INVALID,
MOTION_DYNAMIC,
MOTION_SPHERE_INERTIA,
MOTION_BOX_INERTIA,
MOTION_KEYFRAMED,
MOTION_FIXED,
MOTION_THIN_BOX_INERTIA,
MOTION_CHARACTER,
MOTION_MAX_ID
};
public:
inline MotionType getType()const{return m_type;}
public:
hkpMotion(class FinishingFlag flag):hkReferencedObject(flag){if(flag.m_bFinishing){m_fGravityFactor=1.f;}}
public:
enum{NUM_INACTIVE_FRAMES_TO_DEACTIVATE=5};
public:
hkEnum<MotionType,hkUint8>m_type;
class hkpMaxSizeMotion*m_pSavedMotion;
hkHalf m_fGravityFactor;};
class hkpKeyframedRigidMotion:public hkpMotion
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
hkpKeyframedRigidMotion():hkpMotion(FinishingFlag()){m_pSavedMotion=0;}
public:
public:
virtual void SetStepPosition(hkReal position,hkReal timestep);
public:
hkpKeyframedRigidMotion(class FinishingFlag flag):hkpMotion(flag){}
};
class hkpMaxSizeMotion:public hkpKeyframedRigidMotion
{
public:
static const struct ClassMemberDescriptor Members[];private:
void operator=(const hkpMaxSizeMotion&other);};
class hkpEntityListener;
class hkpEntityActivationListener;
class hkpAction;
class hkSpuCollisionCallbackUtil;
class hkLocalFrame;
class hkpEntity:public hkpWorldObject
{
public:
static const struct ClassMemberDescriptor Members[];
enum SpuCollisionCallbackEventFilter
{
SPU_SEND_NONE=0x00,
SPU_SEND_CONTACT_POINT_ADDED=0x01,
SPU_SEND_CONTACT_POINT_PROCESS=0x02,
SPU_SEND_CONTACT_POINT_REMOVED=0x04,
SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS=SPU_SEND_CONTACT_POINT_ADDED|SPU_SEND_CONTACT_POINT_PROCESS
};
public:
virtual ~hkpEntity();
protected:
const ResizableArray<struct ConstraintRuntimeInfo>&getConstraintMastersImpl()const;
public:
hkpEntity(class FinishingFlag flag);protected:
class hkpMaterial m_iMaterialIndex;
protected:
friend class ConstraintInstanceOwner;
public:
public:
class SmallArraySerializeOverrideType
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpEntity::SmallArraySerializeOverrideType));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
void*m_data;
hkUint16 m_iElementCount;
hkUint16 m_iCapacityState;
};
public:void*m_pEntityUserData;
public:hkUint32 m_uiFilterInfo;
public:hkObjectIndex m_usStorageIndex;
protected:hkUint16 m_usNextProcessCallbackDelay;
protected:ResizableArray<struct ConstraintRuntimeInfo>m_eSmallArraySerializeOverrideType;
protected:hkArray<hkpConstraintInstance*>m_kSlaveConstraints;
protected:
hkArray<hkUint8>m_pByteBuffer;
public:
hkInt8 m_iAutoRemoveLevel;
public:
struct SpuCollisionCallback
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpEntity::SpuCollisionCallback));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
SpuCollisionCallback():
m_pCallbackData(0),
m_pRayCursor(0),
m_uiCallbackType(SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS),
m_bCallbackEnabled(0x01)
{
}
hkSpuCollisionCallbackUtil*m_pCallbackData;
hkUint16 m_pRayCursor;
hkUint8 m_uiCallbackType;
hkUint8 m_bCallbackEnabled;
SpuCollisionCallback(FinishingFlag flag){}
};
struct ExtendedListeners
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpEntity::ExtendedListeners));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
ResizableArray<hkpEntityActivationListener*>m_kContactListenerArray;
ResizableArray<hkpEntityListener*>m_kEntityListenerArray;
};
public:
struct SpuCollisionCallback m_kSpuCollisionCallback;
public:class hkpMaxSizeMotion m_pMotionState;
protected:
friend class PhysicsEntity;
protected:
ResizableArray<hkpAction*>m_ppActions;
public:
ReferenceCountedPointer<hkLocalFrame>m_pLocalFrame;
protected:mutable ExtendedListeners*m_pExtendedListeners;};
class hkpWorldDeletionListener
{
public:
virtual ~hkpWorldDeletionListener(){}
virtual void WorldDeletedCallback(hkpWorld*world)=0;
virtual void worldRemoveAllCallback(hkpWorld*world){}
};
class hkVisualDebugger;
class hkProcessContext
{
public:
hkProcessContext():m_pOwnerObject(0){}
public:
hkVisualDebugger*m_pOwnerObject;};
class StringCursor
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
extern hkThreadLocalData<StringCursor*>DAT_0126835c;
return*DAT_0126835c.getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool __cdecl memoryAvailable()
{
return GetStreamEnd()<getCapacityMinus16();
}
__forceinline void __cdecl setEnd(char*ptr){m_kRayEnd=ptr;}
public:
static void __cdecl init();
public:
ValueWrapper<char*>m_kRayStart;
ValueWrapper<char*>m_kRayEnd;
ValueWrapper<char*>m_pRayCursor;
ValueWrapper<char*>m_pCurrentCommand;
public:
struct Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32 m_uiStartTicks;
hkUint32 m_uiEndTicks;
__forceinline void setTime();
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_uiStartTicks=ticks;
}
class ScopedTimer
{
public:
__forceinline ~ScopedTimer(){{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};}
};
class hkpActionListener
{
public:
virtual ~hkpActionListener(){}
virtual void ActionAddedCallback(hkpAction*action){}
virtual void ActionRemovedCallback(hkpAction*action){}
};
class hkpConstraintListener
{
public:
virtual ~hkpConstraintListener(){}
};class hkpPhantomListener
{
public:
virtual ~hkpPhantomListener(){}
};
class hkpEntityListener
{
public:
virtual ~hkpEntityListener(){}
};
class hkpPhysicsContextWorldListener
{
public:
virtual ~hkpPhysicsContextWorldListener(){}
virtual void WorldAddedCallback(hkpWorld*newWorld)=0;
virtual void WorldRemovedCallback(hkpWorld*newWorld)=0;
};
class hkpPhysicsContext:
public hkReferencedObject,public hkProcessContext,
public hkpWorldDeletionListener,
public hkpEntityListener,
public hkpPhantomListener,
public hkpConstraintListener,
public hkpActionListener
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
virtual void SetOwnerPointer(hkVisualDebugger*vdb);
protected:
virtual ~hkpPhysicsContext();};
class hkDisplayGeometry;
class hkDebugDisplayHandler;
class hkProcessHandler;
class hkProcess
{
public:
hkProcess(hkBool selectable)
:m_bSelectionEnabled(selectable){}
hkBool m_bSelectionEnabled;
hkDebugDisplayHandler*m_pDisplayHandler;
hkProcessHandler*m_pProcessHandler;
virtual void CollectProcessCommands(hkUint8*&commands,int&numCommands){commands=0;numCommands=0;}
};
class hkpWorldViewerBase:public hkReferencedObject,
public hkProcess,
protected hkpPhysicsContextWorldListener
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}protected:
hkpPhysicsContext*m_iValueAtOffset0C;};
class hkpWorldPostSimulationListener
{
public:
virtual ~hkpWorldPostSimulationListener(){}
virtual void step(hkpWorld*world)=0;
virtual void EntityRemovalCallback(hkpEntity*entity){}
};
class hkpVehicleViewer:
public hkpWorldViewerBase,
public hkpActionListener,
public hkpWorldPostSimulationListener
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject*b=static_cast<hkReferencedObject*>(p);;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){__debugbreak();return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){__debugbreak();}class CommandArgument;
static hkProcess*__cdecl create(const hkArray<hkProcessContext*>&contexts);
static void __cdecl RegisterViewer();
virtual int GetOperationType(){return (int)::DAT_01268fcc;}
virtual void init();
static inline const char*__cdecl getName(){return "Vehicles";}
protected:
hkpVehicleViewer(const hkArray<hkProcessContext*>&contexts);
virtual ~hkpVehicleViewer();
virtual void WorldAddedCallback(hkpWorld*world);
virtual void WorldRemovedCallback(hkpWorld*world);
virtual void step(hkpWorld*world);
virtual void ActionAddedCallback(hkpAction*action);
virtual void ActionRemovedCallback(hkpAction*action);
protected:
static int m_ucOperationType;
static const int ms_iProcessTag;
hkArray<class hkpVehicleInstance*>m_ppVehicles;
};
class hkpAction:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
private:
hkpWorld*m_pOwningWorld;
hkpSimulationIsland*m_pCurrentSimulationIsland;
protected:
hkUlong m_ulUserData;
hkStringPtr m_name;
public:
inline hkpSimulationIsland*GetSimulationIsland();
public:
inline void setSimulationIsland(hkpSimulationIsland*island);
public:
hkpAction(class FinishingFlag flag):hkReferencedObject(flag),m_name(flag){}
};
class hkpRigidBody:public hkpEntity
{
public:
static const struct ClassMemberDescriptor Members[];
public:
inline hkpMotion*getRigidMotion()const;
public:
static void __cdecl createDynamicRigidMotion(hkpMotion::MotionType motionType,
const hkVector4&position,const hkQuaternion&rotation,
hkReal mass,const hkMatrix3&inertiaLocal,const hkVector4&centreOfMassLocal,
hkReal maxLinearVelocity,hkReal maxAngularVelocity,
hkpMaxSizeMotion*motionBufferOut);
protected:
virtual hkMotionState*GetMotionState();
public:
hkpRigidBody(class FinishingFlag flag):hkpEntity(flag){}
};
class hkpUnaryAction:public hkpAction
{
public:
static const struct ClassMemberDescriptor Members[];protected:
hkpEntity*m_pEntity;
public:
hkpUnaryAction(class FinishingFlag flag):hkpAction(flag){}
};
class hkpVehicleWheelCollide:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
struct WheelCollideResult
{
public:
enum{MAX_NUM_SHAPE_KEYS=8};
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpVehicleWheelCollide::WheelCollideResult));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
class hkContactPoint m_vContactPoint;
hkReal m_fSuspensionLength;
hkpRigidBody*m_pUserData;
hkpShapeKey m_contactShapeKey0, m_contactShapeKey1, m_contactShapeKey2, m_contactShapeKey3, m_contactShapeKey4, m_contactShapeKey5, m_contactShapeKey6, m_contactShapeKey7;
hkReal m_fContactFriction;
hkReal m_fValueAtOffset4C;
hkReal m_fValueAtOffset50;
};enum WheelCollideType
{
INVALID_WHEEL_COLLIDE=0,
RAY_CAST_WHEEL_COLLIDE=1,
LINEAR_CAST_WHEEL_COLLIDE=2,
USER_WHEEL_COLLIDE1,
USER_WHEEL_COLLIDE2,
USER_WHEEL_COLLIDE3,
USER_WHEEL_COLLIDE4,
USER_WHEEL_COLLIDE5
};protected:
hkpVehicleWheelCollide():m_bWheelCollisionEnabled(false){m_type=INVALID_WHEEL_COLLIDE;}
public:
hkBool m_bWheelCollisionEnabled;
hkEnum<WheelCollideType,hkUint8>m_type;};
class hkpVehicleData:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
struct WheelComponentParams
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpVehicleData::WheelComponentParams));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
hkReal m_fSphereRadius;
hkReal m_fViscosityFriction;
hkReal m_fMaxFriction;
hkReal m_fSlipAngle;
hkReal m_fSlipVelocity;
hkReal m_fMaxContactBodyAcceleration;
hkReal m_fForceFeedbackMultiplier;
hkReal m_fMaxFrictionForce;
hkReal m_fFrictionEqualizer;
hkInt8 m_iAxle;
};
public:
hkVector4 m_kGravity;
hkInt8 m_iWheelCount;
hkRotation m_kChassisOrientation;
hkReal m_fChassisMass;
hkReal m_fTorqueMax;
hkReal m_fTorqueMin;
hkReal m_fTorqueFactor;
hkReal m_fTorquePitchFactor;
hkReal m_fTorqueRollFactor;
hkReal m_fTorqueYawFactor;
hkReal m_fExtraTorqueFactor;
hkReal m_fChassisUnitInertiaRoll;
hkReal m_fChassisUnitInertiaPitch;
hkReal m_fChassisUnitInertiaYaw;
hkArray<struct WheelComponentParams>m_kWheelParams;
hkArray<hkInt8>m_kNumWheelsPerAxle;
public:
hkpVehicleData(FinishingFlag f):hkReferencedObject(f),m_kWheelParams(f),m_kNumWheelsPerAxle(f){}
};
class hkpVehicleInstance:public hkpUnaryAction
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
struct WheelInfo
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpVehicleInstance::WheelInfo));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
enum{MAX_NUM_SHAPE_KEYS=8};
class hkContactPoint m_vContactPoint;
hkReal m_fSuspensionLength;
hkpRigidBody*m_pUserData;
hkpShapeKey m_contactShapeKey0, m_contactShapeKey1, m_contactShapeKey2, m_contactShapeKey3, m_contactShapeKey4, m_contactShapeKey5, m_contactShapeKey6, m_contactShapeKey7;
hkVector4 m_vContactPointVelocity;
hkVector4 m_vContactNormal;
hkReal m_fContactFriction;
hkVector4 m_vHardPointWs;
hkVector4 m_vRayEndPointWs;
hkVector4 m_vSuspensionDirectionWs;
hkQuaternion m_qSteeringOrientation;
hkReal m_fValueAtOffsetC0;
hkReal m_fSpinAngle;
hkReal m_fSkidEnergyDensity;
hkReal m_fSideForce;
hkReal m_fSuspensionForce;
hkReal m_fForwardForce;
void init();
};
public:
static const hkUint8 s_maxNumLocalWheels=16;
protected:
void UpdateVehicle(hkReal deltaTime,const hkpVehicleWheelCollide::WheelCollideResult*cdInfo);
public:
class hkpVehicleData*m_data;
class hkpVehicleDriverInput*m_pDriverInput;
class hkpVehicleSteering*m_pSteering;
class hkpVehicleEngine*m_pVehicleEngine;
class hkpVehicleTransmission*m_pTransmission;
class hkpVehicleBrake*m_pBrake;
class hkpVehicleSuspension*m_pSuspension;
class hkpVehicleAerodynamics*m_pAerodynamics;
class hkpVehicleWheelCollide*m_pWheelCollide;
class hkpTyremarksInfo*m_pTyremarksInfo;
class hkpVehicleVelocityDamper*m_pVelocityDamper;
hkArray<struct WheelInfo>m_kWheelInfoArray;
public:
inline class hkpRigidBody*getChassis(void)const;};
class hkDebugDisplayHandler
{
public:
enum Command
{
HK_STEP=0x00,
HK_ADD_GEOMETRY,
HK_UPDATE_GEOMETRY,
HK_SET_COLOR_GEOMETRY,
HK_REMOVE_GEOMETRY,
HK_DISPLAY_GEOMETRY_WITH_TRANSFORM,
HK_DISPLAY_GEOMETRY,
HK_DISPLAY_POINT,
HK_DISPLAY_LINE,
HK_DISPLAY_TEXT,
HK_SEND_STATISTICS_DUMP_DEPRICATED,
HK_HOLD_IMMEDIATE,
HK_ADD_CAMERA,
HK_UPDATE_CAMERA,
HK_REMOVE_CAMERA,
HK_SEND_MEMSTATS_DUMP,
HK_ADD_GEOMETRY_INSTANCE,
HK_DISPLAY_TEXT_3D,
HK_UPDATE_BEHAVIOR,
HK_LIST_BEHAVIORS,
HK_DISPLAY_ANNOTATION,
};
virtual ~hkDebugDisplayHandler(){}
virtual hkResult AddDisplayGeometry(const HavokElementArray<hkDisplayGeometry*>&geometries,const hkTransform&transform,hkUlong id,int tag,hkUlong shapeIdHint)=0;
virtual hkResult ReplaceGeometry(hkUlong origianalGeomId,const hkTransform&transform,hkUlong id,int tag,hkUlong shapeIdHint)=0;
virtual hkResult SetGeometryColor(int color,hkUlong id,int tag)=0;
virtual hkResult m_bUpdateGeometry(const hkTransform&transform,hkUlong id,int tag)=0;
virtual hkResult RemoveGeometry(hkUlong id,int tag,hkUlong shapeIdHint)=0;
virtual hkResult DisplayCamera(const hkVector4&from,const hkVector4&to,const hkVector4&up,hkReal nearPlane,hkReal farPlane,hkReal fov,const char*name)=0;
virtual hkResult DisplayBehaviorGraph(const HavokElementArray<int>&wordVarIdx,const HavokElementArray<int>&wordStack,const HavokElementArray<int>&quadVarIdx,const HavokElementArray<hkVector4>&quadStack,
const HavokElementArray<char*>&activeNodes,const HavokElementArray<int>&activeStateIds,const HavokElementArray<int>&activeTransitions,const HavokElementArray<hkQsTransform>&transforms)=0;
virtual hkResult DisplayPoint(const hkVector4&position,int colour,int id,int tag)=0;
virtual hkResult DisplayLine(const hkVector4&start,const hkVector4&end,int color,int id,int tag)=0;};
class hkColor
{
public:
static int __cdecl rgbFromChars(unsigned char red,unsigned char green,unsigned char blue,unsigned char alpha=0xff);public:
enum ExtendedColors
{
MAROON=0xFF800000,
DARKRED=0xFF8B0000,
RED=0xFFFF0000,
LIGHTPINK=0xFFFFB6C1,
CRIMSON=0xFFDC143C,
PALEVIOLETRED=0xFFDB7093,
HOTPINK=0xFFFF69B4,
DEEPPINK=0xFFFF1493,
MEDIUMVIOLETRED=0xFFC71585,
PURPLE=0xFF800080,
DARKMAGENTA=0xFF8B008B,
ORCHID=0xFFDA70D6,
THISTLE=0xFFD8BFD8,
PLUM=0xFFDDA0DD,
VIOLET=0xFFEE82EE,
FUCHSIA=0xFFFF00FF,
MAGENTA=0xFFFF00FF,
MEDIUMORCHID=0xFFBA55D3,
DARKVIOLET=0xFF9400D3,
DARKORCHID=0xFF9932CC,
BLUEVIOLET=0xFF8A2BE2,
INDIGO=0xFF4B0082,
MEDIUMPURPLE=0xFF9370DB,
SLATEBLUE=0xFF6A5ACD,
MEDIUMSLATEBLUE=0xFF7B68EE,
DARKBLUE=0xFF00008B,
MEDIUMBLUE=0xFF0000CD,
BLUE=0xFF0000FF,
NAVY=0xFF000080,
MIDNIGHTBLUE=0xFF191970,
DARKSLATEBLUE=0xFF483D8B,
ROYALBLUE=0xFF4169E1,
CORNFLOWERBLUE=0xFF6495ED,
LIGHTSTEELBLUE=0xFFB0C4DE,
ALICEBLUE=0xFFF0F8FF,
GHOSTWHITE=0xFFF8F8FF,
LAVENDER=0xFFE6E6FA,
DODGERBLUE=0xFF1E90FF,
STEELBLUE=0xFF4682B4,
DEEPSKYBLUE=0xFF00BFFF,
SLATEGRAY=0xFF708090,
LIGHTSLATEGRAY=0xFF778899,
LIGHTSKYBLUE=0xFF87CEFA,
SKYBLUE=0xFF87CEEB,
LIGHTBLUE=0xFFADD8E6,
TEAL=0xFF008080,
DARKCYAN=0xFF008B8B,
DARKTURQUOISE=0xFF00CED1,
CYAN=0xFF00FFFF,
MEDIUMTURQUOISE=0xFF48D1CC,
CADETBLUE=0xFF5F9EA0,
PALETURQUOISE=0xFFAFEEEE,
LIGHTCYAN=0xFFE0FFFF,
AZURE=0xFFF0FFFF,
LIGHTSEAGREEN=0xFF20B2AA,
TURQUOISE=0xFF40E0D0,
POWDERBLUE=0xFFB0E0E6,
DARKSLATEGRAY=0xFF2F4F4F,
AQUAMARINE=0xFF7FFFD4,
MEDIUMSPRINGGREEN=0xFF00FA9A,
MEDIUMAQUAMARINE=0xFF66CDAA,
SPRINGGREEN=0xFF00FF7F,
MEDIUMSEAGREEN=0xFF3CB371,
SEAGREEN=0xFF2E8B57,
LIMEGREEN=0xFF32CD32,
DARKGREEN=0xFF006400,
GREEN=0xFF008000,
LIME=0xFF00FF00,
FORESTGREEN=0xFF228B22,
DARKSEAGREEN=0xFF8FBC8F,
LIGHTGREEN=0xFF90EE90,
PALEGREEN=0xFF98FB98,
MINTCREAM=0xFFF5FFFA,
HONEYDEW=0xFFF0FFF0,
CHARTREUSE=0xFF7FFF00,
LAWNGREEN=0xFF7CFC00,
OLIVEDRAB=0xFF6B8E23,
DARKOLIVEGREEN=0xFF556B2F,
YELLOWGREEN=0xFF9ACD32,
GREENYELLOW=0xFFADFF2F,
BEIGE=0xFFF5F5DC,
LINEN=0xFFFAF0E6,
LIGHTGOLDENRODYELLOW=0xFFFAFAD2,
OLIVE=0xFF808000,
YELLOW=0xFFFFFF00,
LIGHTYELLOW=0xFFFFFFE0,
IVORY=0xFFFFFFF0,
DARKKHAKI=0xFFBDB76B,
KHAKI=0xFFF0E68C,
PALEGOLDENROD=0xFFEEE8AA,
WHEAT=0xFFF5DEB3,
GOLD=0xFFFFD700,
LEMONCHIFFON=0xFFFFFACD,
PAPAYAWHIP=0xFFFFEFD5,
DARKGOLDENROD=0xFFB8860B,
GOLDENROD=0xFFDAA520,
ANTIQUEWHITE=0xFFFAEBD7,
CORNSILK=0xFFFFF8DC,
OLDLACE=0xFFFDF5E6,
MOCCASIN=0xFFFFE4B5,
NAVAJOWHITE=0xFFFFDEAD,
ORANGE=0xFFFFA500,
BISQUE=0xFFFFE4C4,
TAN=0xFFD2B48C,
DARKORANGE=0xFFFF8C00,
BURLYWOOD=0xFFDEB887,
SADDLEBROWN=0xFF8B4513,
SANDYBROWN=0xFFF4A460,
BLANCHEDALMOND=0xFFFFEBCD,
LAVENDERBLUSH=0xFFFFF0F5,
SEASHELL=0xFFFFF5EE,
FLORALWHITE=0xFFFFFAF0,
SNOW=0xFFFFFAFA,
PERU=0xFFCD853F,
PEACHPUFF=0xFFFFDAB9,
CHOCOLATE=0xFFD2691E,
SIENNA=0xFFA0522D,
LIGHTSALMON=0xFFFFA07A,
CORAL=0xFFFF7F50,
DARKSALMON=0xFFE9967A,
MISTYROSE=0xFFFFE4E1,
ORANGERED=0xFFFF4500,
SALMON=0xFFFA8072,
TOMATO=0xFFFF6347,
ROSYBROWN=0xFFBC8F8F,
PINK=0xFFFFC0CB,
INDIANRED=0xFFCD5C5C,
LIGHTCORAL=0xFFF08080,
BROWN=0xFFA52A2A,
FIREBRICK=0xFFB22222,
BLACK=0xFF000000,
DIMGRAY=0xFF696969,
GRAY=0xFF808080,
DARKGRAY=0xFFA9A9A9,
SILVER=0xFFC0C0C0,
LIGHTGREY=0xFFD3D3D3,
GAINSBORO=0xFFDCDCDC,
WHITESMOKE=0xFFF5F5F5,
WHITE=0xFFFFFFFF,
GREY=0xff888888,
GREY25=0xff404040,
GREY50=0xff808080,
GREY75=0xffc0c0c0,
};};
template<typename T>
class PointerArrayView
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline T&operator[](int i);protected:
__forceinline PointerArrayView(){}
ValueWrapper<T*>m_data;};
template<typename T>
class HkDynamicArray:public PointerArrayView<T>
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline HkDynamicArray(int n,const char*what=0);
__forceinline ~HkDynamicArray();};
template<typename T>
__forceinline HkDynamicArray<T>::HkDynamicArray(int capacity,const char*what)
{
this->m_data=hkAllocateStack<T>(capacity);
;
}
template<typename T>
__forceinline HkDynamicArray<T>::~HkDynamicArray()
{
hkDeallocateStack(this->m_data.val());
}
template<typename T>
__forceinline T&PointerArrayView<T>::operator[](int i)
{
;
return m_data[i];
}
// Draws each vehicle's contact points, spokes and wheel directions through the debug display handler.
// @fnv 0x00d63680
void hkpVehicleViewer::step(hkpWorld*world)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "hkpVehicleViewer::step";h->setTime();mStream.setEnd((char*)(h+1));}};ScopedTimer timeblock14;
const int numVehicles=m_ppVehicles.GetLogicalSize();
const int numWheelSegments=12;
for(int i=0;i<numVehicles;i++)
{
const hkpVehicleInstance*vehicle=m_ppVehicles[i];
const int numWheels=vehicle->m_kWheelInfoArray.GetLogicalSize();
HkDynamicArray<hkVector4>centerPoint(numWheels);
for(int w=0;w<numWheels;w++)
{
const hkpVehicleData::WheelComponentParams&wheelParam=vehicle->m_data->m_kWheelParams[w];
const hkpVehicleInstance::WheelInfo&wheel=vehicle->m_kWheelInfoArray[w];
const hkVector4&contactPoint=wheel.m_vContactPoint.getPosition();
const hkVector4&hardPoint=wheel.m_vContactPointVelocity;
const int collidableId=(wheel.m_pUserData)?(int)(hkUlong)(wheel.m_pUserData->getCollidable()):0;
m_pDisplayHandler->DisplayLine(contactPoint,hardPoint,(wheel.m_pUserData)? hkColor::RED:hkColor::ROSYBROWN,collidableId,(int)::DAT_01268fcc);
centerPoint[w].setAddMul4(contactPoint,wheel.m_vHardPointWs,-wheelParam.m_fSphereRadius);
{
hkVector4 spoke;spoke=wheel.m_vHardPointWs;
hkQuaternion spokeRotation(wheel.m_vSuspensionDirectionWs,-wheel.m_fSpinAngle);
spoke.SetRotatedDirection(spokeRotation,spoke);
spoke.normalize3();
spoke.mul4(wheelParam.m_fSphereRadius);
hkVector4 start;start.setAdd4(centerPoint[w],spoke);
hkVector4 end;end.setSub4(centerPoint[w],spoke);
m_pDisplayHandler->DisplayLine(start,end,(wheel.m_pUserData)? hkColor::WHITESMOKE:hkColor::ROSYBROWN,collidableId,(int)::DAT_01268fcc);
}
hkVector4 spokes[numWheelSegments];
spokes[0].setMul4(wheelParam.m_fSphereRadius,wheel.m_vHardPointWs);
hkQuaternion spokeRotation(wheel.m_vSuspensionDirectionWs,360.0 / numWheelSegments*0.017453292f);
for(int s=1;s<numWheelSegments+2;s++)
{
if(s<numWheelSegments)
{
spokes[s].SetRotatedDirection(spokeRotation,spokes[s-1]);
}
if(s<=numWheelSegments)
{
spokes[s-1].add4(centerPoint[w]);
}
if(s>=2)
{
m_pDisplayHandler->DisplayLine(spokes[(s-2)% numWheelSegments],spokes[(s-1)% numWheelSegments],(wheel.m_pUserData)? hkColor::WHITESMOKE:hkColor::ROSYBROWN,collidableId,(int)::DAT_01268fcc);
}
}
}
const int numAxles=vehicle->m_data->m_kNumWheelsPerAxle.GetLogicalSize();
for(int axle=0;axle<numAxles;axle++)
{
hkVector4 a;
hkVector4 b;
bool firstTimeThrough=true;
const int totalWheelsOnThisAxle=vehicle->m_data->m_kNumWheelsPerAxle[axle];
int wheelsFoundOnThisAxle=0;
for(int w=0;w<numWheels;w++)
{
const hkpVehicleData::WheelComponentParams&wheelParam=vehicle->m_data->m_kWheelParams[w];
const hkpVehicleInstance::WheelInfo&wheel=vehicle->m_kWheelInfoArray[w];
const int collidableId=(wheel.m_pUserData)?(int)(hkUlong)(wheel.m_pUserData->getCollidable()):0;
if(wheelParam.m_iAxle !=axle)continue;
wheelsFoundOnThisAxle++;
a=b;
b=centerPoint[w];
if(firstTimeThrough)
{
firstTimeThrough=false;
}
else
{
m_pDisplayHandler->DisplayLine(a,b,hkColor::YELLOWGREEN,collidableId,(int)::DAT_01268fcc);
}
if(wheelsFoundOnThisAxle==totalWheelsOnThisAxle)break;
}
}
}
}
}

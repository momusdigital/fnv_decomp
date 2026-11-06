// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/bvtreestream/hkpbvtreestreamagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl FUN_00d312f0(void*, void*, void*, void*);
struct FUN_00d2dd30_class {
    void __thiscall FUN_00d2dd30(void* a, void* b, void* c, void* d);
};
extern "C" void __cdecl FUN_00da3510(void* a, void* b);
struct FUN_00d2ddd0_class {
    void __thiscall FUN_00d2ddd0(int a);
};
extern "C" void __cdecl FUN_00d31110(void*, void*, void*, void*);
// @fnv 0x00d2dd50
extern "C" void __stdcall FUN_00d2dd50(void* a, void* b, void* c, void* d)
{
    FUN_00d31110(a, b, c, d);
}
void __cdecl FUN_00d30f50(void*, void*, void*, void*, void*);
struct OperationAdapter {
    void FUN_00d2dd70(void* a, void* b, void* c, void* d, void* e);
};
struct FUN_00d2dda0_class {
    virtual void finish(int);
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
    void __thiscall FUN_00d2dda0(int value);
};
extern void __cdecl FUN_00da42b0(void*, int, int, int);
void __cdecl FUN_00da35f0(void* self, float a, float b, void* c);
struct FUN_00d2ddf0_Class {
    void __thiscall FUN_00d2ddf0(float a, float b, void* c);
};
struct hkMemoryAllocator {
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct AudioMgr {
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap() { return *unk10; }
};
struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio() { return (AudioMgr*)FUN_00c85750(); }
struct RefObj {
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
struct Obj : RefObj {
    int pad[14];
    Obj* FUN_00d2def0(int, int, int, int);
};
inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)audio()->heap().AllocateMemoryBlock(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}
void* __cdecl FUN_00d2df50(int a, int b, int c, int d);
void FUN_00d2e680();
void FUN_00d2e970();
void FUN_00d2e9b0();
void FUN_00d2e9f0();
void FUN_00d2df50();
void FUN_00d31110();
void FUN_00d30f50();
struct Conversion { void (*convert)(); void (*create)(); void (*copy)(); void (*destroy)(); bool enabled; bool supported; };
struct Registry { void FUN_00cfbbe0(Conversion*,int,int); };
void FUN_00d2e760(Registry* registry);
typedef void* (__cdecl* S_00d2e8e0_CreateFunc)(void*, void*, void*, void*);
typedef void (__cdecl* S_00d2e8e0_GetPenetrationsFunc)(void*, void*, void*, void*);
typedef void (__cdecl* S_00d2e8e0_GetClosestPointsFunc)(void*, void*, void*, void*);
typedef void (__cdecl* S_00d2e8e0_LinearCastFunc)(void*, void*, void*, void*, void*);
void* FUN_00d2e7f0(void*, void*, void*, void*);
void FUN_00d2e970(void*, void*, void*, void*);
void FUN_00d2e9b0(void*, void*, void*, void*);
void FUN_00d2e9f0(void*, void*, void*, void*, void*);
void* FUN_00d2e5a0(void*, void*, void*, void*);
void FUN_00d31110(void*, void*, void*, void*);
void FUN_00d30f50(void*, void*, void*, void*, void*);
struct S_00d2e8e0_AgentFuncs {
    S_00d2e8e0_CreateFunc m_pCreateFunc;
    S_00d2e8e0_GetPenetrationsFunc m_pQueryPenetrationsFunc;
    S_00d2e8e0_GetClosestPointsFunc m_pGetPenetrationsFunc;
    S_00d2e8e0_LinearCastFunc m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};
struct S_00d2e8e0_Dispatcher {
    void FUN_00cfbbe0(S_00d2e8e0_AgentFuncs& f, int typeA, int typeB);
};
void FUN_00d2e8e0(S_00d2e8e0_Dispatcher* dispatcher);
extern float g_D2E9B0MaxDistance;
struct D2E9B0CollectorBase {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();

    float m_fEarlyOutDistance;

    D2E9B0CollectorBase() : m_fEarlyOutDistance(g_D2E9B0MaxDistance) {}
};
struct D2E9B0Collector : D2E9B0CollectorBase {
    int m_iData;

    D2E9B0Collector(int iData) : m_iData(iData) {}

    virtual void unk00();
    virtual void unk04();
};
void __cdecl FUN_00d31110(int a, int b, int c, D2E9B0CollectorBase* collector);
void __cdecl FUN_00d2e9b0(int a, int b, int c, int d);
extern float DAT_0104da48;
struct hkpSymmetricAgentFlipCollector
{
    virtual void dispose();
    virtual void collect(float value);
    virtual void process(void* value);
    float threshold;
    void* object;
};
struct Context
{
    void FUN_00d43880(void* first, void* second, void* third, hkpSymmetricAgentFlipCollector* collector);
    void FUN_00d2edd0(void* first, void* second, void* third, void* fourth);
};
extern "C" void* __cdecl FUN_00d06f80(void* ptr, unsigned int size);
extern "C" void __cdecl FUN_00d97250(void* a, int b, void* c);
extern "C" const char str_010ce828[];
struct VisitTarget {
    virtual void v00() {}
    virtual void v01() {}
    virtual void v02() {}
    virtual void v03() {}
    virtual void v04() {}
    virtual void Visit(int kind, const char* name, void* data, unsigned int size, void* extra) {}
    int unk04;
    int m_08;
    int unk0C;
    unsigned char m_10;
};
struct PackedBuffer {
    void* m_ptr;
    unsigned int m_uiItemCount;
    unsigned int m_flag;
};
struct BufOwner {
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
    PackedBuffer m_buf;
    void __thiscall VisitPackedBuffer(VisitTarget* target, int flags);
};
extern "C" const void* DAT_010ce81c;
struct Collector {
    const void* vtable;
    char flip;
    void* collector;
};
void __cdecl FUN_00d2e970(void* bodyA, void* bodyB, void* arg3, void* orig_collector);
struct FUN_00d2eb50_nib {
    unsigned char lo : 4;
    unsigned char hi : 4;
};
struct FUN_00d2eb50_cls {
    unsigned short m_w00;
    unsigned short m_w02;
    unsigned short m_w04;
    unsigned char m_unk06;
    unsigned char m_unk07;
    unsigned char m_b08;
    unsigned char m_b09;
    FUN_00d2eb50_nib m_nib0a;
    void __thiscall SwapFields();
};
struct CpuCallData { void* descriptor; float bound; unsigned int value; };
extern float DAT_0104da48;
extern unsigned char DAT_010ce7fc;
struct CpuObject {
    void FUN_00d2dd50(void*, void*, unsigned int, CpuCallData*);
    void DispatchWithBoundData(void*, void*, unsigned int, unsigned int);
};
struct CallTarget_00d2de20 { int FUN_00d2de20(int, int, int, int); };
struct SearchObject {
    int CallTarget(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// Havok style body collector: a virtual table pointer, an "active" flag and a payload pointer.
struct hkpCollectorBase {
    char active;
    hkpCollectorBase() { active = 0; }
};
struct hkpSymmetricAgentFlipBodyCollector : hkpCollectorBase {
    virtual void addBody();
    virtual void reset();
    void* payload;
};
// Game side wrapper that fills the collector and hands it to the query routine.
struct FUN_00d43cd0_class {
    void __thiscall ProcessCollisionEntries(void* a, void* b, void* c, void* d);
    void __thiscall FUN_00d2ed90(void* a1, void* a2, void* a3, void* a4);
};
#include <xmmintrin.h>
struct S2ee10_Ref { void* p; };
struct S2ee10_Vec4;
extern "C" const S2ee10_Vec4 DAT_010c4c00;
struct S2ee10_Simd {
    __m128 m_vValue;
};
struct S2ee10_Vec4 {
    __m128 m_vComponents;
    inline void setNeg4(const S2ee10_Vec4& v);
    inline S2ee10_Simd getSimdAt3() const
    {
        S2ee10_Simd r;
        r.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }
    inline void addMul4(const S2ee10_Simd& r, const S2ee10_Vec4& a)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(r.m_vValue, a.m_vComponents), m_vComponents);
    }
};
inline void S2ee10_Vec4::setNeg4(const S2ee10_Vec4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00.m_vComponents);
}
struct S2ee10_ContactPoint {
    S2ee10_Vec4 m_vContactPosition;
    S2ee10_Vec4 m_vSeparatingNormal;
    S2ee10_Vec4 m_extra;
};
struct S2ee10_GskCache {
    unsigned short m_kVertices[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    unsigned char m_flagsLo : 4;
    unsigned char m_flagsHi : 4;

    inline void flip()
    {
        unsigned char lo = m_flagsLo;
        m_flagsLo = m_flagsHi;
        m_flagsHi = lo;
        unsigned char d = m_ucDimensionA;
        m_ucDimensionA = m_ucDimensionB;
        m_ucDimensionB = d;
        int idx = m_ucDimensionA + m_ucDimensionB - 1;
        unsigned short v0 = m_kVertices[0];
        m_kVertices[0] = m_kVertices[idx];
        m_kVertices[idx] = v0;
        if ((m_ucDimensionA & m_ucDimensionB) == 2) {
            unsigned short t = m_kVertices[1];
            m_kVertices[1] = m_kVertices[2];
            m_kVertices[2] = t;
        }
    }
};
struct S2ee10_ToiInfo {
    S2ee10_Vec4 m_vSeparatingNormal;
    float m_uiCommandId;
    int unk14;
    int unk18;
    int unk1c;
    S2ee10_GskCache m_kGskCache;

    inline void flip()
    {
        m_vSeparatingNormal.setNeg4(m_vSeparatingNormal);
        m_kGskCache.flip();
    }
};
struct S2ee10_Output {
    S2ee10_ContactPoint* m_pAlignedPairData;
    int m_pConstraintOwner;
    int m_potentials;
    int unk0c;
    S2ee10_ContactPoint m_akContactPoints[256];
    S2ee10_Vec4 unk3010;
    S2ee10_ToiInfo m_fTimeOfImpact;
};
struct hkpCdBody;
struct CollisionAgentContext;
class hkpAgentBase {
public:
    void FUN_00d437a0(S2ee10_Ref bodyA, const hkpCdBody& bodyB, const CollisionAgentContext& input, S2ee10_Output& output);
};
class hkpSymmetricAgentT : public hkpAgentBase {
public:
    void FUN_00d2ee10(const hkpCdBody& bodyA, S2ee10_Ref bodyB, const CollisionAgentContext& input, S2ee10_Output& output);
};

extern "C" void __cdecl __debugbreak(void);
typedef float hkReal;
typedef signed int hkInt32;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkClass;
typedef int hkBool32;
class hkBool
{
public:
typedef char CompileTimeTrueType;
typedef int CompileTimeFalseType;inline hkBool(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
hkEnum(ENUM e)
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
__forceinline ValueWrapper(TYPE e)
:m_kStorage(e)
{
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline TYPE operator->()const
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
hkThreadLocalData()
{
m_slotID=TlsAlloc();
}
__forceinline T getData()const
{
return(T)(hkUlong)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
template<typename T>struct TypeSizeConstant{enum{val=sizeof(T)};};
class hkMemoryAllocator_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
virtual ~hkMemoryAllocator_S();
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;
virtual void*AllocateBufferWithSize(int&reqNumBytesInOut);
virtual void ReturnMemory(void*p,int numBytes);
virtual void*BufRealloc(void*pold,int oldNumBytes,int&reqNumBytesInOut);
virtual void AllocateMemoryBlocks(void**ptrsOut,int numPtrs,int blockSize);
virtual void AllocateFixedSizeBlocks(void**ptrsIn,int numPtrs,int blockSize);
virtual bool CanAllocateMemory(int numBytes);
virtual bool CanAllocateBytes(int numBytes);template<typename TYPE>
inline void _bufFree(void*p,int numElem)
{
const int SIZE_ELEM=TypeSizeConstant<TYPE>::val;
ReturnMemory(p,numElem*SIZE_ELEM);
}
public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;
ValueWrapper<void*>m_kRayStart;
ValueWrapper<void*>m_kRayEnd;};
class NineIntegerRecord
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
typedef hkMemoryAllocator_S Allocator;
static NineIntegerRecord&__cdecl GetMonitorStream();inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;
Allocator*m_pDebugAllocator;};
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline virtual ~hkBaseObject(){}
public:
__forceinline hkBaseObject(){}
};
class hkStatisticsCollector;
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
virtual const hkClass*GetClassType()const;
virtual void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(class FinishingFlag flag){}
};template<bool N>struct BooleanTypeConstant{typedef BooleanTypeConstant<N>type;enum{result=N};};
typedef BooleanTypeConstant<true>hkTypeIsPod;
typedef BooleanTypeConstant<false>hkTypeIsClass;
template<typename T>
hkBool::CompileTimeFalseType operator==(const T&,const hkTypeIsPod&);
template<typename T>
struct IsPodType:public BooleanTypeConstant<(sizeof(*static_cast<T*>(0)==*static_cast<const hkTypeIsPod*>(0))==sizeof(hkBool::CompileTimeTrueType))>{};
template<>struct IsPodType<hkUint32>:public hkTypeIsPod{};
class HavokArrayUtilities
{
public:
template<typename T>static __forceinline void construct(T*t,int n,hkTypeIsPod);
template<typename T>static __forceinline void constructWithCopy(T*t,int n,const T&tcopy,hkTypeIsPod);
template<typename T>static __forceinline void destruct(T*t,int n,hkTypeIsPod);
template<typename T>static __forceinline void destruct(T*t,int n,hkTypeIsClass);};template<typename T>
__forceinline void HavokArrayUtilities::constructWithCopy(T*t,int n,const T&tcopy,hkTypeIsPod)
{
for(int i=0;i<n;++i)
{
t[i]=tcopy;
}
}
template<typename T>
__forceinline void HavokArrayUtilities::destruct(T*t,int n,hkTypeIsPod)
{
}
struct RouterHeapAllocatorProvider
{
hkMemoryAllocator_S&get(const void*){return NineIntegerRecord::GetMonitorStream().heap();}
};
template<typename T>
class HavokElementArray
{
public:
typedef HavokElementArray<T>ThisType;
__forceinline HavokElementArray(T*buffer,int size,int capacity);
protected:
__forceinline HavokElementArray(const HavokElementArray&a){;}
public:
__forceinline void _useExternalArray(T*,int cap);
__forceinline ~HavokElementArray();
__forceinline int GetLogicalSize()const;
__forceinline int getCapacity()const;
__forceinline void clear();
__forceinline void _clearAndDeallocate(hkMemoryAllocator_S&alloc);
__forceinline void pushBackUnchecked(const T&e);
typedef T*iterator;
__forceinline iterator begin();
protected:
__forceinline HavokElementArray<T>&copyFromArray(hkMemoryAllocator_S&,const HavokElementArray<T>&src,hkTypeIsPod);
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
typedef Allocator AllocatorType;__forceinline ~hkArray();
__forceinline hkArray(T*buffer,int size,int capacity):HavokElementArray<T>(buffer,size,capacity){}
protected:
__forceinline hkArray(const hkArray&a);
public:
__forceinline hkArray&operator=(const HavokElementArray<T>&a);
__forceinline void ClearAndRelease(){HavokElementArray<T>::_clearAndDeallocate(AllocatorType().get(this));}
};
template<typename T,unsigned N,typename Allocator=RouterHeapAllocatorProvider>
class hkInplaceArray:public hkArray<T,Allocator>
{
public:
typedef hkInplaceArray<T,N,Allocator>mytype;
explicit __forceinline hkInplaceArray(int size=0);
__forceinline ~hkInplaceArray(){}
public:
T m_kStorage[N];
public:
hkInplaceArray(FinishingFlag f):hkArray<T,Allocator>(f){}
};template<typename T>
__forceinline int HavokElementArray<T>::GetLogicalSize()const
{
return m_iElementCount;
}
template<typename T>
__forceinline int HavokElementArray<T>::getCapacity()const
{
return(m_iCapacityState&static_cast<int>(CAPACITY_MASK));
}
template<typename T>
__forceinline void HavokElementArray<T>::clear()
{
HavokArrayUtilities::destruct(m_data,m_iElementCount,typename IsPodType<T>::type());
m_iElementCount=0;
}
template<typename T>
__forceinline HavokElementArray<T>::HavokElementArray(T*ptr,int size,int capacity)
:m_data(ptr),
m_iElementCount(size),
m_iCapacityState(capacity | DONT_DEALLOCATE_FLAG)
{
;
;
}
template<typename T>
__forceinline HavokElementArray<T>::~HavokElementArray()
{
;
;
}
template<typename T>
__forceinline void HavokElementArray<T>::_clearAndDeallocate(hkMemoryAllocator_S&alloc)
{
clear();
if((m_iCapacityState&DONT_DEALLOCATE_FLAG)==0)
{
alloc._bufFree<T>(m_data,getCapacity());
}
m_data=0;
m_iCapacityState=DONT_DEALLOCATE_FLAG;
}
template<typename T>
__forceinline void HavokElementArray<T>::pushBackUnchecked(const T&t)
{
;
HavokArrayUtilities::constructWithCopy(m_data+m_iElementCount,1,t,typename IsPodType<T>::type());
m_iElementCount++;
}
template<typename T>
typename HavokElementArray<T>::iterator HavokElementArray<T>::begin()
{
return m_data;
}
template<typename T,typename Allocator>
__forceinline hkArray<T,Allocator>::~hkArray()
{
ClearAndRelease();
}
template<typename T,unsigned N,typename Allocator>
__forceinline hkInplaceArray<T,N,Allocator>::hkInplaceArray(int size)
:hkArray<T,Allocator>(m_kStorage,size,N)
{
}

;
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
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;
class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;
class Vector4Comparison
{
public:
enum Mask
{
MASK_NONE=0,
MASK_X=1,
MASK_Y=2,
MASK_XY=3,
MASK_Z=4,
MASK_XZ=5,
MASK_YZ=6,
MASK_XYZ=7,
MASK_W=8,
MASK_XW=9,
MASK_YW=10,
MASK_XYW=11,
MASK_ZW=12,
MASK_XZW=13,
MASK_YZW=14,
MASK_XYZW=15
};
__forceinline void setAnd(hkVector4ComparisonParameter a,hkVector4ComparisonParameter b){m_uiMask=_mm_and_ps(a.m_uiMask,b.m_uiMask);}
__forceinline hkBool32 allAreSet(Mask m)const{return(_mm_movemask_ps(m_uiMask)&m)==m;}
private:
hkQuadReal m_uiMask;
friend class hkVector4;};
class hkRotation;
class hkTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4&v);
__forceinline void setAll3(hkReal x);
__forceinline void setZero4();
__forceinline void add4(const hkVector4&a);
__forceinline void setAdd4(const hkVector4&a,const hkVector4&b);
__forceinline void sub4(const hkVector4&a);
__forceinline void setSub4(const hkVector4&a,const hkVector4&b);
__forceinline void setMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void addMul4(hkSimdRealParameter r,const hkVector4&a);
__forceinline void setCross(const hkVector4&a,const hkVector4&b);
__forceinline Vector4Comparison compareLessThanEqual4(hkVector4Parameter a)const;
__forceinline void setNeg4(const hkVector4&v);
__forceinline void setMin4(const hkVector4&a,const hkVector4&b);
__forceinline void setMax4(const hkVector4&a,const hkVector4&b);
__forceinline void _setRotatedInverseDir(const hkRotation&a,const hkVector4&b);
__forceinline void _setTransformedInversePos(const hkTransform&a,const hkVector4&b);
__forceinline hkReal&operator()(int i);
__forceinline const hkReal&operator()(int i)const;
__forceinline const hkQuadReal&getQuad()const;
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
public:
hkVector4 m_vec;
protected:
void setFlippedRotation(const hkVector4&from);};class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkMatrix3(){}
__forceinline const hkVector4&getColumn(int i)const;
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
__forceinline hkTransform(){}
__forceinline const hkVector4&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
void SetConjugate(const hkTransform&t);
void SetMulInverse(const hkTransform&bTa,const hkTransform&bTc);
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};
class hkSweptTransform
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline void _approxTransformAt(hkTime time,hkTransform&transformOut)const;
__forceinline hkReal getInvDeltaTime()const;
public:
hkVector4 m_vCenterOfMass0;
hkVector4 m_vCenterOfMass1;
hkQuaternion m_qRotation0;
hkQuaternion m_qRotation1;
hkVector4 m_vCenterOfMassLocal;};inline const hkQuadReal&hkVector4::getQuad()const
{
return m_vComponents;
}
inline void hkVector4::operator=(const hkVector4&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4::setAll3(hkReal a)
{
m_vComponents=_mm_set_ps1(a);
}
inline void hkVector4::setZero4()
{
m_vComponents=_mm_setzero_ps();
}
inline void hkVector4::add4(const hkVector4&v)
{
m_vComponents=_mm_add_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setAdd4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::sub4(const hkVector4&v)
{
m_vComponents=_mm_sub_ps(m_vComponents,v.m_vComponents);
}
inline void hkVector4::setSub4(const hkVector4&v0,const hkVector4&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline void hkVector4::setMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_mul_ps(r.broadcast(),v1.m_vComponents);
}
inline void hkVector4::addMul4(hkSimdRealParameter r,const hkVector4&v1)
{
m_vComponents=_mm_add_ps(m_vComponents,
_mm_mul_ps(r.broadcast(),v1.m_vComponents));
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
inline Vector4Comparison hkVector4::compareLessThanEqual4(const hkVector4&a)const
{
Vector4Comparison m;m.m_uiMask=_mm_cmple_ps(m_vComponents,a.m_vComponents);
return m;
}
extern "C" const hkQuadReal DAT_010c44d0;
extern "C" const char str_010ce7d4[];
inline void hkVector4::setNeg4(const hkVector4&v)
{
m_vComponents=_mm_xor_ps(v.m_vComponents,DAT_010c44d0);
}
inline void hkVector4::setMin4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=_mm_min_ps(a.getQuad(),b.getQuad());
}
inline void hkVector4::setMax4(const hkVector4&a,const hkVector4&b)
{
m_vComponents=_mm_max_ps(a.getQuad(),b.getQuad());
}
inline void hkVector4::_setRotatedInverseDir(const hkRotation&r,const hkVector4&b)
{
hkQuadReal c0=r.getColumn(0).m_vComponents;
hkQuadReal c1=r.getColumn(1).m_vComponents;
hkQuadReal c2=r.getColumn(2).m_vComponents;
{hkQuadReal _tmp,_ctmp;_tmp=_mm_unpacklo_ps(c0,c1);_ctmp=_mm_shuffle_ps(_mm_unpackhi_ps(c0,c1),c2,(((3)<<6)|((2)<<4)|((1)<<2)|((0))));c0=_mm_movelh_ps(_tmp,c2);c1=_mm_shuffle_ps(_mm_movehl_ps(c0,_tmp),c2,(((3)<<6)|((1)<<4)|((1)<<2)|((0))));c2=_ctmp;};
const hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=_mm_mul_ps(c0,b0);
const hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=_mm_mul_ps(c1,b1);
const hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=_mm_mul_ps(c2,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),r2);}
inline void hkVector4::_setTransformedInversePos(const hkTransform&a,const hkVector4&b)
{
hkVector4 t0;t0.setSub4(b,a.getTranslation());
_setRotatedInverseDir(a.getRotation(),t0);
}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4&hkTransform::getTranslation()const
{
return m_vTranslation;
}
const hkRotation&hkTransform::getRotation()const
{
return m_rotation;
}
hkReal hkSweptTransform::getInvDeltaTime()const
{
return m_vCenterOfMass1(3);
}
class StringCursor
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
extern hkThreadLocalData<StringCursor*>g_pMonitorStream;
return*g_pMonitorStream.getData();
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
hkBool m_bFlag;
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
};
struct TimedNameRecord:public StringCursor::CommandTimingEntry
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::TimedNameRecord));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pFirst;
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
class hkMotionState
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkTransform&getTransform()const;
inline const hkSweptTransform&getSweptTransform()const;
protected:
hkTransform m_kMotionTransform;
class hkSweptTransform m_kSweptTransform;
public:
hkVector4 m_kDeltaAngle;
hkReal m_fObjectRadius;};const hkTransform&hkMotionState::getTransform()const
{
return m_kMotionTransform;
}
const hkSweptTransform&hkMotionState::getSweptTransform()const
{
return m_kSweptTransform;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline hkBool contains(const hkAabb&other)const;
public:
hkVector4 m_kMinimumCorner;
hkVector4 m_kMaximumCorner;};hkBool hkAabb::contains(const hkAabb&other)const
{
Vector4Comparison mincomp=m_kMinimumCorner.compareLessThanEqual4(other.m_kMinimumCorner);
Vector4Comparison maxcomp=other.m_kMaximumCorner.compareLessThanEqual4(m_kMaximumCorner);
Vector4Comparison both;both.setAnd(mincomp,maxcomp);
return both.allAreSet(Vector4Comparison::MASK_XYZ)!=0;}
typedef hkUint16 hkContactPointId;
enum CollisionShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
HK_SHAPE_CYLINDER,
HK_SHAPE_TRIANGLE,
HK_SHAPE_BOX,
HK_SHAPE_CAPSULE,
HK_SHAPE_CONVEX_VERTICES,
HK_SHAPE_COLLECTION,
HK_SHAPE_BV_TREE,
HK_SHAPE_LIST,
HK_SHAPE_MOPP,
HK_SHAPE_CONVEX_TRANSLATE,
HK_SHAPE_CONVEX_TRANSFORM,
HK_SHAPE_SAMPLED_HEIGHT_FIELD,
HK_SHAPE_EXTENDED_MESH,
HK_SHAPE_TRANSFORM,
HK_SHAPE_COMPRESSED_MESH,
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
HK_SHAPE_CONVEX,
HK_SHAPE_PACKED_CONVEX_VERTICES,
HK_SHAPE_MOPP_EMBEDDED,
HK_SHAPE_CONVEX_PIECE,
HK_SHAPE_MULTI_SPHERE,
HK_SHAPE_CONVEX_LIST,
HK_SHAPE_TRIANGLE_COLLECTION,
HK_SHAPE_MULTI_RAY,
HK_SHAPE_HEIGHT_FIELD,
HK_SHAPE_SPHERE_REP,
HK_SHAPE_BV,
HK_SHAPE_PLANE,
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL=-1
};
class hkpCollisionDispatcher;
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline void getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const;
virtual hkReal getMaximumProjection(const hkVector4&direction)const;
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape::PhysicsShape));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<CollisionShapeType,hkUint32>m_type;
public:
hkpShape(class FinishingFlag flag):hkReferencedObject(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};void hkpShape::getAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const
{
CalculateAabb(localToWorld,tolerance,out);
}
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
__forceinline const hkMotionState*GetMotionState()const;
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;};
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkMotionState*hkpCdBody::GetMotionState()const
{
return static_cast<const hkMotionState*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
struct GskAgentInput;
class hkpContactMgr;
class hkpConstraintOwner;
struct AgentProcessingInput
{
AgentProcessingInput():m_pAdditionalCollidableBody(0){}
ValueWrapper<const hkpCdBody*>m_pBodyA;
ValueWrapper<const hkpCdBody*>m_pBodyB;
ValueWrapper<const hkpCdBody*>m_pAdditionalCollidableBody;
ValueWrapper<const GskAgentInput*>m_pRayCastInput;
ValueWrapper<hkpContactMgr*>m_pContactManager;
hkTransform m_kTransform;};
struct AgentSubtypeMarker:public AgentProcessingInput
{
ValueWrapper<hkReal>m_fSubtypeValue;
hkVector4 m_vSubtypePosition;};
struct CollisionQualityInfo
{
__declspec(align(16))hkReal m_fMinimumCollisionSeparation;
hkReal m_fMinimumExtraSeparation;
hkReal m_fMaximumExtraSeparation;
hkReal m_fTimeOfImpactSeparation;
ValueWrapper<hkBool32>m_iQualityInfoValue10;};
class hkpCollisionFilter;
class hkpConvexListFilter;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;
ValueWrapper<const hkpCollisionFilter*>m_iFilter;
ValueWrapper<const hkpConvexListFilter*>m_pConvexListCollisionFilter;
struct AabbBoundsAndScale
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(CollisionAgentContext::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4 m_kAabbMin;
hkVector4 m_kAabbMaximum;
hkVector4 m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};
struct WorldOperationEntry;
struct ShapeSweepParameters;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}__forceinline void __cdecl operator delete(void*p){hkReferencedObject*b=static_cast<hkReferencedObject*>(p);;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,b->m_usMemSizeAndFlags);}__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){__debugbreak();return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){__debugbreak();}class CommandArgument;
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector)=0;
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector)=0;
virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&castCollector,hkpCdPointCollector*startCollector)=0;
public:
virtual void processCollision(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
virtual void cleanup(hkpConstraintOwner&info)=0;
virtual void ProcessContactPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner){}
virtual void RemovePoint(const CollisionAgentContext&input);
virtual void WarpTime(hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
virtual void removePoint(hkContactPointId idToRemove);
virtual void CommitPotentialContactPoint(hkContactPointId iContactPointId);
virtual void MarkContactPointAsZombie(hkContactPointId idTobecomeZombie);
protected:
inline virtual ~hkpCollisionAgent();
inline hkpCollisionAgent(hkpContactMgr*contactMgr);
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();
};class hkStepInfo
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
__declspec(align(16))ValueWrapper<hkTime>m_uiStartTime;
ValueWrapper<hkTime>m_fEndTime;
ValueWrapper<hkReal>m_fTimeStep;};
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable ValueWrapper<CollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};
class hkpBvTreeAgent:public hkpCollisionAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);
static void __cdecl m_pVirtualFunction2(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);
virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&collector,hkpCdPointCollector*startCollector);
static void __cdecl m_pVirtualFunction3(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&collector,hkpCdPointCollector*startCollector);
virtual void processCollision(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void cleanup(hkpConstraintOwner&info);
static void __cdecl setUseAabbCaching(hkBool useIt);
static hkBool __cdecl getUseAabbCaching();
public:
static hkBool ms_bUseAabbCaching;
virtual void ProcessContactPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner);
virtual void RemovePoint(const CollisionAgentContext&input);
virtual void WarpTime(hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
__forceinline static hkResult __cdecl BuildCollisionHitList(
const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkTransform&bTa,
const hkVector4&linearTimInfo,const GskAgentInput&input,
hkAabb*cachedAabb,hkArray<hkpShapeKey>&hitListOut);
public:
hkpBvTreeAgent(hkpContactMgr*mgr);
protected:
void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
static hkpCollisionAgent*__cdecl CreateBvTreeAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&env,hkpContactMgr*mgr);
void ProcessCollisionPartners(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner);
__forceinline void prepareCollisionPartnersProcess(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,hkpConstraintOwner&constraintOwner);
static void __cdecl CalculateAabbForLinearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkAabb&aabbOut);
static void __cdecl CalculateAabbForCollision(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkAabb&aabbOut);
~hkpBvTreeAgent(){}
struct BvTreeAgentTrack
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpBvTreeAgent::BvTreeAgentTrack));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkpShapeKey m_key;
hkInt32 m_iValueAtOffset4;
hkpCollisionAgent*m_pCollisionAgent;
hkpShapeKey&GetIteratorKey(){return m_key;}
void setKey(hkpShapeKey&key){m_key=key;}
};
hkArray<BvTreeAgentTrack>m_kEntries;
hkAabb m_kBoundingBox;
static hkBool ms_bUseAabbCache;
static hkpCollisionAgent*__cdecl createShapeBvAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createBvTreeShapeAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createBvBvAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
};
struct hkpAgent1nSector
{
enum{SECTOR_SIZE=512,NET_SECTOR_SIZE=SECTOR_SIZE-16};};
struct AgentSectorPointerArray
{
hkArray<hkpAgent1nSector*>m_kSectors;};
class hkpBvTreeStreamAgent:public hkpCollisionAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
static void __cdecl registerConvexListAgent(hkpCollisionDispatcher*dispatcher);
static void __cdecl registerMultiRayAgent(hkpCollisionDispatcher*dispatcher);
virtual void processCollision(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void cleanup(hkpConstraintOwner&info);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&collector);
virtual void linearCast(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&collector,hkpCdPointCollector*startCollector);
virtual void ProcessContactPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpConstraintOwner&constraintOwner);
virtual void RemovePoint(const CollisionAgentContext&input);
virtual void WarpTime(hkTime oldTime,hkTime newTime,const CollisionAgentContext&input);
protected:
hkResult prepareCollisionPartnersProcess(AgentSubtypeMarker&input,hkArray<hkpShapeKey>&hitList);
hkpBvTreeStreamAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
~hkpBvTreeStreamAgent(){}
void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
static hkpCollisionAgent*__cdecl createShapeBvAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createBvTreeShapeAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl dispatchBvTreeConvexList(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl dispatchConvexListBvTree(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
hkpCollisionDispatcher*m_pCollisionDispatcher;
hkAabb m_kBoundingBox;
AgentSectorPointerArray m_kAgentNnTrack;
};
extern "C"
{
void __cdecl BuildShapeCollectionBWorldOperations(AgentSectorPointerArray&agentTrack,const AgentSubtypeMarker&input,const hkpShapeContainer*shapeContainterB,const hkpShapeKey*hitList,WorldOperationEntry&output);}
class hkpBvTreeShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
enum BvTreeType
{
BVTREE_MOPP,
BVTREE_TRISAMPLED_HEIGHTFIELD,
BVTREE_USER,
BVTREE_MAX
};
virtual void GetObbHits(const hkTransform&obbTransform,const hkVector4&obbExtent,hkReal tolerance,hkArray<hkpShapeKey>&hits)const=0;
virtual void GetAabbHits(const hkAabb&aabb,hkArray<hkpShapeKey>&hits)const=0;
public:
hkEnum<BvTreeType,hkUint8>m_uiUserData;};namespace MotionUtilities
{
__forceinline void __cdecl calcTimInfo(const hkMotionState&ms0,const hkMotionState&ms1,hkReal deltaTime,hkVector4&timOut);}
void __cdecl MotionUtilities::calcTimInfo(const hkMotionState&ms0,const hkMotionState&ms1,hkReal deltaTime,hkVector4&timOut)
{
const hkSweptTransform&st0=ms0.getSweptTransform();
const hkSweptTransform&st1=ms1.getSweptTransform();
hkVector4 diff0;diff0.setSub4(st0.m_vCenterOfMass0,st0.m_vCenterOfMass1);
hkVector4 diff1;diff1.setSub4(st1.m_vCenterOfMass1,st1.m_vCenterOfMass0);
hkReal f0=deltaTime*st0.getInvDeltaTime();
hkReal f1=deltaTime*st1.getInvDeltaTime();
timOut.setMul4(f0,diff0);
timOut.addMul4(f1,diff1);
timOut(3)=f0*ms0.m_kDeltaAngle(3)*ms0.m_fObjectRadius+f1*ms1.m_kDeltaAngle(3)*ms1.m_fObjectRadius;}
namespace AlgorithmUtilities
{template<typename T>
class less
{
public:
__forceinline hkBool32 operator()(const T&a,const T&b)
{
return(a<b);
}
};
template<typename T>
__forceinline void __cdecl quickSort(T*pArr,int iSize)
{
quickSort(pArr,iSize,less<T>());
}
template<typename T,typename L>
void __cdecl QuickSortSubrange(T*pArr,int d,int h,L cmpLess);}
namespace AlgorithmUtilities
{template<typename T,typename L>
void __cdecl quickSort(T*pArr,int iSize,L cmpLess)
{
if(iSize>1)
{
int low=0;
int high=iSize-1;
QuickSortSubrange(pArr,low,high,cmpLess);
}
}
}
void SetMemoryState(hkMemoryAllocator_S::MemoryState state);__forceinline bool hkHasMemoryAvailable(int id,int size)
{
bool hasAvailable=NineIntegerRecord::GetMonitorStream().heap().CanAllocateBytes(size);
return hasAvailable;
}
hkResult __cdecl hkpBvTreeAgent::BuildCollisionHitList(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkTransform&bTa,
const hkVector4&linearTimInfo,const GskAgentInput&input,
hkAabb*cachedAabb,hkArray<hkpShapeKey>&hitListOut)
{
hkAabb aabb;
{
const hkMotionState*msA=bodyA.GetMotionState();
const hkMotionState*msB=bodyB.GetMotionState();
hkVector4 timInfo;timInfo._setRotatedInverseDir(bodyB.getTransform().getRotation(),linearTimInfo);
hkVector4 aabbExtents;
if(input.m_pCollisionQualityInfo->m_iQualityInfoValue10.val())
{
const hkReal secOrdErrA=(msA->m_kDeltaAngle(3)+msB->m_kDeltaAngle(3))*msA->m_fObjectRadius;
const hkReal secOrdErrB=msB->m_kDeltaAngle(3)*msB->m_kDeltaAngle(3)*msB->m_fObjectRadius;
const hkReal checkEpsilon=input.m_fScalar*0.5+(secOrdErrA+secOrdErrB);
bodyA.getShape()->getAabb(bTa,checkEpsilon,aabb);
hkVector4 massCenterAinB;
{
hkVector4 radius4;
radius4.setAll3(input.m_fScalar*0.5+msA->m_fObjectRadius+secOrdErrB);
massCenterAinB._setTransformedInversePos(bodyB.getTransform(),msA->getSweptTransform().m_vCenterOfMass1);
hkVector4 maxR;maxR.setAdd4(massCenterAinB,radius4);
hkVector4 minR;minR.setSub4(massCenterAinB,radius4);
aabb.m_kMinimumCorner.setMax4(aabb.m_kMinimumCorner,minR);
aabb.m_kMaximumCorner.setMin4(aabb.m_kMaximumCorner,maxR);
}
aabbExtents.setSub4(aabb.m_kMaximumCorner,aabb.m_kMinimumCorner);
{
if(msB->m_kDeltaAngle(3)>0.0)
{
hkVector4 relPos;relPos.setSub4(massCenterAinB,msB->getSweptTransform().m_vCenterOfMassLocal);
hkVector4 offsetOut;offsetOut.setCross(relPos,msB->m_kDeltaAngle);
hkReal f=input.m_pStepInfo.m_fTimeStep*msB->getSweptTransform().getInvDeltaTime();
timInfo.addMul4(f,offsetOut);
}
hkVector4 zero;zero.setZero4();
hkVector4 minPath;minPath.setMin4(zero,timInfo);
hkVector4 maxPath;maxPath.setMax4(zero,timInfo);
aabb.m_kMinimumCorner.add4(minPath);
aabb.m_kMaximumCorner.add4(maxPath);
}
}
else
{
const hkReal checkEpsilon=input.m_fScalar*0.5;
bodyA.getShape()->getAabb(bTa,checkEpsilon,aabb);
aabbExtents.setSub4(aabb.m_kMaximumCorner,aabb.m_kMinimumCorner);
}
if(cachedAabb)
{
if(cachedAabb->contains(aabb))
{
return HK_FAILURE;
}
hkVector4 zero;zero.setZero4();
hkVector4 minPath;minPath.setMin4(zero,timInfo);
hkVector4 maxPath;maxPath.setMax4(zero,timInfo);
hkVector4 expand4;expand4.setAll3(input.m_fScalar*0.5);
aabb.m_kMinimumCorner.sub4(expand4);
aabb.m_kMaximumCorner.add4(expand4);
const hkReal maxExpand=0.4f;
const hkReal framesLookAhead=-2.0f;
hkVector4 minExtentPath;minExtentPath.setMul4(framesLookAhead,maxPath);
hkVector4 maxExtentPath;maxExtentPath.setMul4(framesLookAhead,minPath);
hkVector4 maxExpand4;maxExpand4.setMul4(maxExpand,aabbExtents);
maxExtentPath.setMin4(maxExtentPath,maxExpand4);
hkVector4 minExpand4;minExpand4.setNeg4(maxExpand4);
minExtentPath.setMax4(minExtentPath,minExpand4);
aabb.m_kMinimumCorner.add4(minExtentPath);
aabb.m_kMaximumCorner.add4(maxExtentPath);
*cachedAabb=aabb;
}
}
const hkpBvTreeShape*bvB=static_cast<const hkpBvTreeShape*>(bodyB.getShape());
bvB->GetAabbHits(aabb,hitListOut);
return HK_SUCCESS;}
// @fnv 0x00d2df90
void hkpBvTreeStreamAgent::processCollision(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&output)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::TimedNameRecord*h=reinterpret_cast<StringCursor::TimedNameRecord*>(mStream.GetStreamEnd());h->m_pCommandName="L" "t" "BvTree3";h->m_pFirst="S" "t" "QueryTree";h->setTime();mStream.setEnd((char*)(h+1));}};
AgentSubtypeMarker in3;
{
in3.m_pBodyA=&bodyA;
in3.m_pBodyB=&bodyB;
in3.m_pContactManager=m_pContactManager;
in3.m_pRayCastInput=&input;
const hkMotionState*msA=bodyA.GetMotionState();
const hkMotionState*msB=bodyB.GetMotionState();
MotionUtilities::calcTimInfo(*msA,*msB,input.m_pStepInfo.m_fTimeStep,in3.m_vSubtypePosition);
in3.m_kTransform.SetMulInverse(msA->getTransform(),msB->getTransform());
}
hkInplaceArray<hkpShapeKey,128>hitList;
hitList.pushBackUnchecked(0xffffffff);
hkResult prepareSuccessful;
{
hkTransform bTa;bTa.SetConjugate(in3.m_kTransform);
prepareSuccessful=hkpBvTreeAgent::BuildCollisionHitList(bodyA,bodyB,bTa,in3.m_vSubtypePosition,input,&m_kBoundingBox,hitList);
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName=str_010ce7d4;h->setTime();mStream.setEnd((char*)(h+1));}};
if(prepareSuccessful==HK_SUCCESS)
{
int newMemNeeded=(hitList.GetLogicalSize()/ 4+1-m_kAgentNnTrack.m_kSectors.GetLogicalSize())*hkpAgent1nSector::SECTOR_SIZE;
if(!hkHasMemoryAvailable(3,newMemNeeded))
{
SetMemoryState(hkMemoryAllocator_S::MEMORY_STATE_OUT_OF_MEMORY);
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="l" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
return;
}
AlgorithmUtilities::quickSort(hitList.begin(),hitList.GetLogicalSize());
;
const hkpBvTreeShape*bvB=static_cast<const hkpBvTreeShape*>(bodyB.getShape());
const hkpShapeContainer*shapeContainer=bvB->GetShapeContainer();
BuildShapeCollectionBWorldOperations(m_kAgentNnTrack,in3,shapeContainer,hitList.begin(),output);
}
else
{
const hkpBvTreeShape*bvB=static_cast<const hkpBvTreeShape*>(bodyB.getShape());
const hkpShapeContainer*shapeContainer=bvB->GetShapeContainer();
BuildShapeCollectionBWorldOperations(m_kAgentNnTrack,in3,shapeContainer,0,output);
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="l" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}

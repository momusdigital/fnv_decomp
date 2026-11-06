
// src/havok/physics/dynamics/constraint/chain/stiffspring/hkpstiffspringchaindata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/stiffspring/hkpstiffspringchaindata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpStiffSpringChainData.h"

struct hkStiffSpringChainData
{
    unsigned int m_uiCurrentValue;
    void getRuntimeInfo(bool bFlag, unsigned int* pOut);
};

// @fnv 0x00e3af80
void hkStiffSpringChainData::getRuntimeInfo(bool bFlag, unsigned int* pOut)
{
    if (bFlag)
    {
        unsigned int u = *(unsigned int*)((char*)this + 0x1c);
        pOut[1] = u;
        pOut[0] = u * 8;
    }
    else
    {
        pOut[1] = 0;
        pOut[0] = 0;
    }
}

// @fnv 0x00e3af30
int __cdecl FUN_00e3af30()
{
    return 0x64;
}

struct ConstraintInfo
{
    int m_maxNumExternalSlaveContactPoints;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    hkpBridgeAtoms* m_kBridgeAtoms;
    int m_usSizeOfAllAtoms;
};

class hkpStiffSpringChain : public hkpStiffSpringChainData
{
  public:
    void getConstraintInfo(ConstraintInfo& info);
};

// @fnv 0x00e3af40
void hkpStiffSpringChain::getConstraintInfo(ConstraintInfo& info)
{
    info.m_kBridgeAtoms = &m_kBridgeAtoms;
    info.m_iSolverResultCount = 0;
    info.m_iSolverElementTemporaryCount = 0;
    info.m_maxNumExternalSlaveContactPoints = 0;
    info.m_iSchemaByteSize = 16;
    info.m_usSizeOfAllAtoms = sizeof(hkpBridgeAtoms);

    int size = m_pConstraintInfo.m_iElementCount;
    info.m_iSchemaByteSize += (size * 80 + 36 + 15) & ~15;
    info.m_iSolverResultCount = size;
    info.m_iSolverElementTemporaryCount = size;
}

class hkMemoryAllocatorE3B4
{
  public:
    virtual ~hkMemoryAllocatorE3B4() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE3B4
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorE3B4* m_pStreamAllocator;
    hkMemoryAllocatorE3B4& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterE3B4& __cdecl FUN_00c85750();

class FUN_00e3b0a0
{
  public:
    virtual ~FUN_00e3b0a0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<FUN_00e3b0a0*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00e3b0a0* DestroyAndFree(unsigned int uiFlags) throw();
};

// Runs the destructor and, when bit 0 of uiFlags is set, frees the object through operator delete; returns this.
// @fnv 0x00e3b4a0
FUN_00e3b0a0* FUN_00e3b0a0::DestroyAndFree(unsigned int uiFlags) throw()
{
    this->FUN_00e3b0a0::~FUN_00e3b0a0();
    if (uiFlags & 1)
        FUN_00e3b0a0::operator delete(this);
    return this;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    void _mm_store_ss(float*, __m128);
}
union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;
};
extern "C" const __m128 DAT_01268370;
struct QuantizedBoundsData;
struct SolverSchemaHeader;
struct hkpEntityS
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
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    hkUint32 m_uiFilterInfo;
    int unka8;
    int unkac;
    int unkb0;
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
    hkTransform m_kMotionTransform;
};
struct hkpConstraintChainInstanceS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkpEntityS* m_pEntityA;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    hkArray<hkpEntityS*> m_ppRigidBodies;
};
struct SixteenWordFloatRecord
{
    int m_unk00;
    int m_unk04;
    int m_fQueryInputValue;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int m_iBeforeFourthQueryValue;
    hkReal m_fFourthQueryValue;
    int m_unk28;
    int m_unk2c;
    const QuantizedBoundsData* m_pBodyA;
    const QuantizedBoundsData* m_pBodyB;
    const hkTransform* m_kBodyALocalFrame;
    const hkTransform* m_kBodyBLocalFrame;
    int m_unk40;
    int m_unk44;
    int m_unk48;
    int m_unk4c;
    int m_unk50;
    int m_unk54;
    int m_unk58;
    int m_unk5c;
    hkpConstraintChainInstanceS* m_pConstraintChainInstance;
    void* m_pByteBuffer;
    int m_unk68;
    int m_unk6c;
    int m_unk70;
    int m_unk74;
    int m_unk78;
    int m_unk7c;
};
template <class T> struct OutputSlot31
{
    T* ptr;
    __forceinline OutputSlot31()
    {}
    __forceinline OutputSlot31(T* p) : ptr(p)
    {}
    __forceinline operator T*() const
    {
        return ptr;
    }
    __forceinline T* value() const
    {
        return ptr;
    }
    __forceinline T* const& cref() const
    {
        return ptr;
    }
    __forceinline T*& ref()
    {
        return ptr;
    }
};
struct QueryResultSchema
{
    OutputSlot31<SolverSchemaHeader> m_pQueryResultSchema;
};
struct hk1dLinearBilateralConstraintInfo
{
    hkVector4q m_kPivotA;
    hkVector4q m_kPivotB;
    hkVector4q m_kConstraintAxis;
};
class hkpStiffSpringChainDataConstraintInfo
{
  public:
    hkVector4 m_kPivotInA;
    hkVector4 m_kPivotInB;
    hkReal m_fSpringRestLength;
    int unk24;
    int unk28;
    int unk2c;
};
struct hkVector4T : public hkVector4
{
    void SetTransformedPoint(const hkTransform& t, const hkVector4& v) throw();
};
struct hkMemoryAllocator
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
struct hkMemoryRouterS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
};
void __cdecl ResizeAudioStream(hkMemoryAllocator* alloc, void* array, int sizeElem) throw();
extern "C" void __cdecl AppendEventRecord(const SixteenWordFloatRecord& in, QueryResultSchema& out, void* solverResults,
                                     int solverResultStriding) throw();
SolverSchemaHeader* __cdecl FUN_00dd13b0(SolverSchemaHeader* schema) throw();
void __cdecl FUN_00dcee70(SixteenWordFloatRecord* in) throw();
void __cdecl FUN_00dcf720(const hk1dLinearBilateralConstraintInfo& info, const SixteenWordFloatRecord& in,
                          SolverSchemaHeader* schema, hkReal rhs) throw();
void __cdecl FUN_00dd1180(int numConstraints, hkReal tau, hkReal damping, hkReal cfm, int* offsets, hkUint32 base,
                          SolverSchemaHeader* schema, const SixteenWordFloatRecord& in, QueryResultSchema& out) throw();
__forceinline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
struct hkInplaceIntArray32
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[32];
    __forceinline hkInplaceIntArray32()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000 | 32;
    }
    __forceinline ~hkInplaceIntArray32()
    {
        hkMemoryAllocator* alloc = reinterpret_cast<hkMemoryAllocator*>(&FUN_00c85750().heap());
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc->ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(int));
        }
    }
    __forceinline void pushBackUnchecked(int v)
    {
        m_data[m_iElementCount] = v;
        m_iElementCount++;
    }
    __forceinline void AddBack(hkMemoryRouterS* alloc, int v)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(alloc->m_pStreamAllocator, this, sizeof(int));
        }
        new (&m_data[m_iElementCount]) int(v);
        m_iElementCount++;
    }
};
static __forceinline __m128 hkLengthSquared3(const hkVector4q& v)
{
    __m128 p = _mm_mul_ps(v.m_vComponents, v.m_vComponents);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
}
static __forceinline __m128 hkLengthInverse3(const hkVector4q& v)
{
    __m128 len2 = hkLengthSquared3(v);
    __m128 e = _mm_rsqrt_ss(len2);
    __m128 r =
        _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e), _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
    return _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
}
static __forceinline hkReal hkNormalizeWithLength3(hkVector4q& v)
{
    __m128 invLen = hkLengthInverse3(v);
    invLen = _mm_shuffle_ps(invLen, invLen, 0);
    hkReal length;
    _mm_store_ss(&length, _mm_mul_ss(hkLengthSquared3(v), invLen));
    v.m_vComponents = _mm_mul_ps(invLen, v.m_vComponents);
    return length;
}
struct hkpStiffSpringChainDataEx : public hkpStiffSpringChainData
{
// @fnv 0x00e3b0f0
    void buildJacobian(const SixteenWordFloatRecord& inNonConst, QueryResultSchema& out) volatile;
};
void hkpStiffSpringChainDataEx::buildJacobian(const SixteenWordFloatRecord& inNonConst, QueryResultSchema& out) volatile
{
    AppendEventRecord(inNonConst, out, inNonConst.m_pByteBuffer, 8);
    SixteenWordFloatRecord in = inNonConst;
    in.m_pConstraintChainInstance = 0;
    in.m_pByteBuffer = 0;
    hkInplaceIntArray32 velocityAccumulatorsOffsets;
    hkpConstraintChainInstanceS* instance = inNonConst.m_pConstraintChainInstance;
    int numConstraints = instance->m_ppRigidBodies.m_iElementCount - 1;
    hkUint32 base = (hkUint32)inNonConst.m_pBodyA - instance->m_pEntityA->m_uiFilterInfo;
    hkpEntityS* rA = instance->m_ppRigidBodies.m_data[0];
    in.m_pBodyB = (const QuantizedBoundsData*)(base + rA->m_uiFilterInfo);
    velocityAccumulatorsOffsets.pushBackUnchecked((hkUint32)in.m_pBodyB - base);
    in.m_kBodyBLocalFrame = &rA->m_kMotionTransform;
    in.m_fFourthQueryValue = 1.0f;
    in.m_iBeforeFourthQueryValue = in.m_fQueryInputValue;
    SolverSchemaHeader* schema = FUN_00dd13b0(out.m_pQueryResultSchema.value());
    for (int i = 0; i < numConstraints; i++)
    {
        in.m_pBodyA = in.m_pBodyB;
        in.m_kBodyALocalFrame = in.m_kBodyBLocalFrame;
        hkpEntityS* rB = instance->m_ppRigidBodies.m_data[i + 1];
        in.m_pBodyB = (const QuantizedBoundsData*)(base + rB->m_uiFilterInfo);
        velocityAccumulatorsOffsets.AddBack(reinterpret_cast<hkMemoryRouterS*>(&FUN_00c85750()),
                                            (hkUint32)in.m_pBodyB - base);
        in.m_kBodyBLocalFrame = &rB->m_kMotionTransform;
        hk1dLinearBilateralConstraintInfo bp;
        static_cast<hkVector4T&>(bp.m_kPivotA.m_vec)
            .SetTransformedPoint(*in.m_kBodyALocalFrame, m_pConstraintInfo.m_data[i].m_kPivotInA);
        static_cast<hkVector4T&>(bp.m_kPivotB.m_vec)
            .SetTransformedPoint(*in.m_kBodyBLocalFrame, m_pConstraintInfo.m_data[i].m_kPivotInB);
        hkVector4q dir;
        dir.m_vComponents = _mm_sub_ps(bp.m_kPivotA.m_vComponents, bp.m_kPivotB.m_vComponents);
        hkReal length = hkNormalizeWithLength3(dir);
        if (length > 0.0f)
        {
            bp.m_kConstraintAxis.m_vComponents = dir.m_vComponents;
        }
        else
        {
            bp.m_kConstraintAxis.m_vComponents = DAT_01268370;
            length = 0.0f;
        }
        FUN_00dcee70(&in);
        hkReal rhs = m_pConstraintInfo.m_data[i].m_fSpringRestLength - length;
        FUN_00dcf720(bp, in, schema, rhs);
        schema = reinterpret_cast<SolverSchemaHeader*>(reinterpret_cast<char*>(schema) + 0x30);
    }
    FUN_00dd1180(numConstraints, m_fTau, m_fMotorDamping, m_fMaxErrorDistance, velocityAccumulatorsOffsets.m_data, base,
                 schema, inNonConst, out);
}

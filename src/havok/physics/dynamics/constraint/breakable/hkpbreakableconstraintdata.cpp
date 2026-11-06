
// src/havok/physics/dynamics/constraint/breakable/hkpbreakableconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/breakable/hkpbreakableconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBreakableConstraintData.h"

struct FUN_00d4de80_class
{
    void FUN_00d4de80(int, void* out);
};
// @fnv 0x00d4de80
void FUN_00d4de80_class::FUN_00d4de80(int, void* out)
{
    ((int*)out)[1] = *(unsigned short*)((char*)this + 0x1e);
    ((int*)out)[0] = *(unsigned short*)((char*)this + 0x1c) + 0x34;
}

struct GenericConstraintAtomScheme
{
    char pad[0x10];
    void* m_kBridgeAtoms;    // +0x10
    int m_usSizeOfAllAtoms;  // +0x14
};

struct FUN_00d4de50_class
{
    char pad[0x18];
    void* m_pHavokConstraint;  // +0x18
    void PopulateInfo(GenericConstraintAtomScheme* info);
};

// @fnv 0x00d4de50
void FUN_00d4de50_class::PopulateInfo(GenericConstraintAtomScheme* info)
{
    ((void(__thiscall*)(void*, GenericConstraintAtomScheme*))((*(void***)m_pHavokConstraint)[0x3c / 4]))(
        m_pHavokConstraint, info);
    info->m_kBridgeAtoms = (char*)this + 0xc;
    info->m_usSizeOfAllAtoms = 0xc;
}

struct FUN_00d4dea0_object
{
    virtual void FUN_00d4dea80();
    virtual void FUN_00d4dea84();
    virtual void FUN_00d4dea88();
    virtual void FUN_00d4dea8c();
    virtual void FUN_00d4dea90();
    virtual void FUN_00d4dea94();
    virtual void FUN_00d4dea98();
    virtual void FUN_00d4dea9c(void*);
};

struct FUN_00d4dea0_class
{
    virtual void FUN_00d4de70();
    virtual void FUN_00d4de74();
    virtual void FUN_00d4de78();
    virtual void FUN_00d4de7c();
    virtual void FUN_00d4de80();
    virtual void FUN_00d4de84();
    virtual void FUN_00d4de88();
    virtual void FUN_00d4de8c();
    char FUN_00d4de90[0x14];
    FUN_00d4dea0_object* FUN_00d4dea0_object;
    void* FUN_00d4dea0(void*);
};

// @fnv 0x00d4dea0
void* FUN_00d4dea0_class::FUN_00d4dea0(void* value)
{
    FUN_00d4dea0_object->FUN_00d4dea9c(value);
    return value;
}

extern void* DAT_010d0a1c;
extern void* _DAT_0102e388;
struct DDCC60World
{
    void removeReference();
};
struct FUN_00d4e000_class
{
    void* m_vt;
    void* m1;
    void* m2;
    void* m3;
    void* m4;
    void* m5;
    DDCC60World* m6;
    void FUN_00d4e000();
};
// @fnv 0x00d4e000
void FUN_00d4e000_class::FUN_00d4e000()
{
    DDCC60World* pOldWorld = m6;
    m_vt = &DAT_010d0a1c;
    pOldWorld->removeReference();
    m_vt = &_DAT_0102e388;
}

// @fnv 0x00d4dec0
int __cdecl FUN_00d4dec0()
{
    return 0xc;
}

struct FnvCpu_FUN_00cc48b0_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cc48b0_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cc48b0_CpuAllocator* allocator;
};
FnvCpu_FUN_00cc48b0_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00cc48b0_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d4e000();
    FnvCpu_FUN_00cc48b0_CpuObject* Destroy(unsigned int flags);
};
// Calls FUN_00d4e000, then if flags has bit 0 set, frees this object through the allocator from FUN_00c85750, and returns this.
// @fnv 0x00cc48b0
FnvCpu_FUN_00cc48b0_CpuObject* FnvCpu_FUN_00cc48b0_CpuObject::Destroy(unsigned int flags)
{
    FUN_00d4e000();
    if (flags & 1)
    {
        FnvCpu_FUN_00cc48b0_CpuAllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Invoke(this, size);
    }
    return this;
}

struct hkFinishLoadedObjectFlagD4DF
{
    int m_bFinishing;
};

class hkpConstraintDataD4DF;

struct FUN_00d21ce0_cls
{
    hkUint16 m_type;
    hkUint16 m_pad02;
    void* m_pBridge;
    hkpConstraintDataD4DF* m_pConstraintData;

    FUN_00d21ce0_cls(hkFinishLoadedObjectFlagD4DF flag)
    {
        if (flag.m_bFinishing)
            FUN_00d21ce0(m_pConstraintData);
    }
    void FUN_00d21ce0(void* pvConstraintData) throw();
};

struct hkpBridgeAtomsD4DF
{
    FUN_00d21ce0_cls m_kBridgeAtom;

    hkpBridgeAtomsD4DF(hkFinishLoadedObjectFlagD4DF flag) : m_kBridgeAtom(flag)
    {}
};

class hkReferencedObjectD4DF
{
  public:
    hkReferencedObjectD4DF(hkFinishLoadedObjectFlagD4DF flag)
    {}
    virtual ~hkReferencedObjectD4DF();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpConstraintDataD4DF : public hkReferencedObjectD4DF
{
  public:
    hkpConstraintDataD4DF(hkFinishLoadedObjectFlagD4DF flag) : hkReferencedObjectD4DF(flag)
    {}
    hkUlong m_ulUserData;
};

class FUN_00d4dfc0 : public hkpConstraintDataD4DF
{
  public:
    hkpBridgeAtomsD4DF m_kBridgeAtoms;

    FUN_00d4dfc0(hkFinishLoadedObjectFlagD4DF flag);
    virtual ~FUN_00d4dfc0();
};

// Constructs the constraint data and bridge atoms, then, when the finish-loaded flag is set, calls the bridge atoms' finish routine on this object.
// @fnv 0x00d4dfc0
FUN_00d4dfc0::FUN_00d4dfc0(hkFinishLoadedObjectFlagD4DF flag) : hkpConstraintDataD4DF(flag), m_kBridgeAtoms(flag)
{
    if (flag.m_bFinishing)
        m_kBridgeAtoms.m_kBridgeAtom.FUN_00d21ce0(this);
}

class hkReferencedObjectCDF7
{
  public:
    hkReferencedObjectCDF7() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectCDF7() throw();
    void FUN_00c90510() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkListenerCDF7
{
  public:
    hkListenerCDF7() throw()
    {
        m_type = 1;
    }
    void FUN_00d21ce0(void* owner) throw();

    short m_type;
    short unk02;
    int unk04;
    int unk08;
};

class hkMidCDF7 : public hkReferencedObjectCDF7
{
  public:
    hkMidCDF7() throw() : m_08(0)
    {}
    virtual ~hkMidCDF7() throw();
    int m_08;
};

class FUN_00cdf710 : public hkMidCDF7
{
  public:
    FUN_00cdf710(hkReferencedObjectCDF7* ref) throw();
    virtual ~FUN_00cdf710() throw();

    hkReferencedObjectCDF7* m_ref;
    hkListenerCDF7 m_kListener;
    float m_1c;
};

// Stores ref, calls FUN_00c90510 on it if non-null, sets m_1c to 0.01, and calls FUN_00d21ce0(this) on m_kListener.
// @fnv 0x00cdf710
FUN_00cdf710::FUN_00cdf710(hkReferencedObjectCDF7* ref) throw() : m_ref(ref), m_1c(0.01f)
{
    if (m_ref)
        m_ref->FUN_00c90510();
    m_kListener.FUN_00d21ce0(this);
}

class hkBoolD4DE
{
  public:
    hkBoolD4DE(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    char m_cBooleanValue;
};

struct hkFilterInfoD4DE
{
    unsigned short m_kPointA;
    unsigned short unk02;
    unsigned short m_kPointB;
    unsigned short unk06;
};

class hkShapeD4DE
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24(hkBoolD4DE b, hkFilterInfoD4DE* out);

    void FUN_00c90510();
    void FUN_00c905b0();
};

class hkOwnerD4DE
{
  public:
    int unk00[6];
    hkShapeD4DE* m_pCollisionShape;
    unsigned short m_1c;
    unsigned short m_1e;

    void SetCollisionShape(hkShapeD4DE* shape);
};

// Calls FUN_00c90510 on shape and FUN_00c905b0 on the old shape, stores shape, and copies its vf24 filter info into m_1c and m_1e.
// @fnv 0x00d4ded0
void hkOwnerD4DE::SetCollisionShape(hkShapeD4DE* shape)
{
    if (shape)
        shape->FUN_00c90510();
    if (m_pCollisionShape)
        m_pCollisionShape->FUN_00c905b0();
    m_pCollisionShape = shape;
    if (shape)
    {
        hkFilterInfoD4DE info;
        m_pCollisionShape->vf24(true, &info);
        m_1c = info.m_kPointA;
        m_1e = info.m_kPointB;
    }
}

struct hkpConstraintInfoD4E0
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    hkpConstraintAtom* m_kBridgeAtoms;
    int m_usSizeOfAllAtoms;
};

struct hkpConstraintDataVtD4E0 : hkReferencedObject
{
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void PopulateInfo(hkpConstraintInfoD4E0& info) const;
};

struct hkpVelocityAccumulatorD4E0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_vLinearVelocity;
    hkVector4 m_vAngularVelocity;
};

struct hkpConstraintQueryInD4E0
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
    const hkpVelocityAccumulatorD4E0* m_pBodyA;
    const hkpVelocityAccumulatorD4E0* m_pBodyB;
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
    struct hkpConstraintInstanceD4E0* m_pConstraintChainInstance;
    char* m_pByteBuffer;
};

struct hkpWorldD4E0
{
    void FUN_00c97e80(hkBool* result, struct hkpConstraintInstanceD4E0* constraint);
};

struct hkpEntityD4E0
{
    int unk00;
    int unk04;
    hkpWorldD4E0* m_pOwningWorld;
};

struct hkpConstraintInstanceD4E0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkpEntityD4E0* m_entities0;
};

struct hkpBoolResultD4E0
{
    hkBool m_cBooleanValue;
};

void __stdcall FUN_00d4de30(const hkpConstraintQueryInD4E0& in, int out);
void __cdecl FUN_00d72190(hkpConstraintAtom* atoms, const hkpConstraintQueryInD4E0& in, hkpBoolResultD4E0 flag,
                          int out);
void __cdecl FUN_00d6f460(hkpConstraintAtom* atoms, int sizeOfAllAtoms, const hkpConstraintQueryInD4E0& in, int out);

struct RuntimeD4E0
{
    hkBool m_bFlag;
    hkReal m_fVectorA[3];
    hkReal m_fVectorB[3];
    hkReal m_fVectorC[3];
    hkReal m_fVectorD[3];
};

__forceinline void store3(const hkVector4& v, hkReal* p)
{
    p[0] = v.x;
    p[1] = v.y;
    p[2] = v.z;
}

struct S00d4e0f0_Object : hkpBreakableConstraintData
{
    void buildJacobian(const hkpConstraintQueryInD4E0& in, int out);
};

// If the runtime flag is clear, saves body velocities and calls FUN_00d72190 or FUN_00d6f460; else calls FUN_00d4de30 and optionally removes the constraint.
// @fnv 0x00d4e0f0
void S00d4e0f0_Object::buildJacobian(const hkpConstraintQueryInD4E0& in, int out)
{
    RuntimeD4E0* runtime = reinterpret_cast<RuntimeD4E0*>(in.m_pByteBuffer + m_usRuntimeOffset);

    if (!runtime->m_bFlag)
    {
        const hkpVelocityAccumulatorD4E0* bodyA = in.m_pBodyA;
        const hkpVelocityAccumulatorD4E0* bodyB = in.m_pBodyB;
        store3(bodyA->m_vLinearVelocity, runtime->m_fVectorA);
        store3(bodyB->m_vLinearVelocity, runtime->m_fVectorB);
        store3(bodyA->m_vAngularVelocity, runtime->m_fVectorC);
        store3(bodyB->m_vAngularVelocity, runtime->m_fVectorD);

        hkpConstraintInfoD4E0 info;
        reinterpret_cast<const hkpConstraintDataVtD4E0*>(m_pConstraintData)->PopulateInfo(info);

        if (info.m_kBridgeAtoms->m_type == hkpConstraintAtom::TYPE_CONTACT)
        {
            hkpBoolResultD4E0 flag;
            flag.m_cBooleanValue = 1;
            FUN_00d72190(info.m_kBridgeAtoms, in, flag, out);
        }
        else
        {
            FUN_00d6f460(info.m_kBridgeAtoms, info.m_usSizeOfAllAtoms, in, out);
        }
    }
    else
    {
        FUN_00d4de30(in, out);

        if (m_bRemoveWhenBroken)
        {
            hkBool result;
            hkpConstraintInstanceD4E0* instance = in.m_pConstraintChainInstance;
            instance->m_entities0->m_pOwningWorld->FUN_00c97e80(&result, instance);
        }
    }
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_load_ss(float const*);
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_set_ps1(float);
    double __cdecl sqrt(double);
}

extern const __m128 DAT_010ec7f0;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(hkReal s)
    {
        m_vComponents = _mm_set_ps1(s);
    }
    __forceinline void setInterpolate4(const hkVector4q& v0, const hkVector4q& v1, const hkVector4q& t)
    {
        __m128 s = _mm_sub_ps(DAT_010ec7f0, t.m_vComponents);
        m_vComponents = _mm_add_ps(_mm_mul_ps(v0.m_vComponents, s), _mm_mul_ps(v1.m_vComponents, t.m_vComponents));
    }
    __forceinline void blendFrom(const hkVector4q& v0, const hkVector4q& t)
    {
        hkVector4q tmp;
        tmp.setInterpolate4(v0, *this, t);
        m_vComponents = tmp.m_vComponents;
    }
};

static __forceinline hkReal hkMath_sqrt(hkReal r)
{
    return (hkReal)sqrt(r);
}

static __forceinline hkReal hkMath_sqrtInverse(hkReal r)
{
    return 1.0f / hkMath_sqrt(r);
}

struct ContactImpulseInfo
{
    hkReal m_fAccumulatedImpulse;
    hkReal m_fImpulseLimit;

    __forceinline hkReal getImpulseApplied() const
    {
        return m_fAccumulatedImpulse;
    }
};

struct QuantizedBoundsData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4q m_vLinearVelocity;
    hkVector4q m_vAngularVelocity;
};

struct SixteenWordFloatRecord
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
    QuantizedBoundsData* m_pBodyA;
    QuantizedBoundsData* m_pBodyB;
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
    struct Pad
    {
        void* m_val;
        __forceinline void* val() const
        {
            return m_val;
        }
    } m_pConstraintChainInstance;
    ContactImpulseInfo* m_pByteBuffer;
};

struct hkpBreakableRuntime
{
    hkBool m_bFlag;
    hkReal m_linearVelA[3];
    hkReal m_linearVelB[3];
    hkReal m_angularVelA[3];
    hkReal m_angularVelB[3];
};

class hkBoolC
{
  public:
    __forceinline hkBoolC(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};

struct hkpBreakableConstraintData_e1e0 : hkpBreakableConstraintData
{
    void FUN_00d4e020(void* instance, hkBoolC isBroken, hkReal currentConstraintForce);
    void FUN_00d4e1e0(const SixteenWordFloatRecord* in);
};

// If the squared impulse sum exceeds breaking strength squared, calls FUN_00d4e020 and optionally blends body velocities back; always zeroes the impulses.
// @fnv 0x00d4e1e0
void hkpBreakableConstraintData_e1e0::FUN_00d4e1e0(const SixteenWordFloatRecord* in)
{
    ContactImpulseInfo* pImpulseInfo = in->m_pByteBuffer;
    hkpBreakableRuntime* runtime =
        reinterpret_cast<hkpBreakableRuntime*>(reinterpret_cast<char*>(pImpulseInfo) + m_usRuntimeOffset);
    int numResults = m_usNumSolverResults;

    if (!runtime->m_bFlag)
    {
        hkReal sumImpulse = 0.0f;
        for (int i = 0; i < numResults; i++)
        {
            hkReal impulse = pImpulseInfo[i].getImpulseApplied();
            sumImpulse += impulse * impulse;
        }

        if (sumImpulse > m_fBreakingStrength * m_fBreakingStrength)
        {

            FUN_00d4e020(in->m_pConstraintChainInstance.val(), true, hkMath_sqrt(sumImpulse));

            if (m_bRevertBackVelocityOnBreak)
            {
                hkVector4q factor;
                factor.SetAllComponents(hkMath_sqrtInverse(sumImpulse) * m_fBreakingStrength);

                hkVector4q linA;
                linA.set(runtime->m_linearVelA[0], runtime->m_linearVelA[1], runtime->m_linearVelA[2]);
                hkVector4q linB;
                linB.set(runtime->m_linearVelB[0], runtime->m_linearVelB[1], runtime->m_linearVelB[2]);
                hkVector4q angA;
                angA.set(runtime->m_angularVelA[0], runtime->m_angularVelA[1], runtime->m_angularVelA[2]);
                hkVector4q angB;
                angB.set(runtime->m_angularVelB[0], runtime->m_angularVelB[1], runtime->m_angularVelB[2]);

                QuantizedBoundsData* bodyA = in->m_pBodyA;
                QuantizedBoundsData* bodyB = in->m_pBodyB;
                bodyA->m_vLinearVelocity.blendFrom(linA, factor);
                bodyB->m_vLinearVelocity.blendFrom(linB, factor);
                bodyA->m_vAngularVelocity.blendFrom(angA, factor);
                bodyB->m_vAngularVelocity.blendFrom(angB, factor);
            }
        }
    }

    for (int i = 0; i < numResults; i++)
    {
        pImpulseInfo[i].m_fAccumulatedImpulse = 0.0f;
    }
}

namespace fnv_00d4df30 {
struct hkBoolD4D
{
    char m_cBooleanValue;
    hkBoolD4D()
    {}
    hkBoolD4D(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    hkBoolD4D& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};

struct RuntimeInfoD4D
{
    int m_iSolverIterationCount;
    int m_iSolverResultCount;
};

class hkpConstraintDataD4D
{
  public:
    hkpConstraintDataD4D() : m_sReferenceCount(1), m_ulUserData(0)
    {}
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual void unkv10();
    virtual void unkv14();
    virtual void unkv18();
    virtual void unkv1C();
    virtual void unkv20();
    virtual void GetConstraintRuntimeInfo(hkBoolD4D wantRuntime, RuntimeInfoD4D& infoOut) const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;

    void FUN_00c90510() const throw();
};

struct FUN_00d21ce0_cls
{
    unsigned short m_type;
    unsigned short unk02;
    void* m_pBridge;
    hkpConstraintDataD4D* m_pConstraintData;

    FUN_00d21ce0_cls()
    {
        m_type = 1;
    }
    void FUN_00d21ce0(void* constraintData) throw();
};

class FUN_00d4df30 : public hkpConstraintDataD4D
{
  public:
    FUN_00d21ce0_cls m_kBridgeAtoms;
    hkpConstraintDataD4D* m_pConstraintData;
    unsigned short m_usRuntimeOffset;
    unsigned short m_usNumSolverResults;
    float m_fBreakingStrength;
    hkBoolD4D m_bRemoveWhenBroken;
    hkBoolD4D m_bRevertBackVelocityOnBreak;

    FUN_00d4df30(hkpConstraintDataD4D* constraintData);
    virtual ~FUN_00d4df30();
};

// @fnv 0x00d4df30
FUN_00d4df30::FUN_00d4df30(hkpConstraintDataD4D* constraintData) : m_pConstraintData(constraintData)
{
    m_fBreakingStrength = 10.0f;
    m_bRemoveWhenBroken = false;
    m_bRevertBackVelocityOnBreak = false;
    if (m_pConstraintData)
    {
        m_pConstraintData->FUN_00c90510();
        RuntimeInfoD4D info;
        m_pConstraintData->GetConstraintRuntimeInfo(true, info);
        m_usRuntimeOffset = (unsigned short)info.m_iSolverIterationCount;
        m_usNumSolverResults = (unsigned short)info.m_iSolverResultCount;
    }
    m_kBridgeAtoms.FUN_00d21ce0(this);
}
}  // namespace fnv_00d4df30

class GlobalObjectO2_00d472a0;

class hkBoolD4E0
{
  public:
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    hkBoolD4E0& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }
    bool operator==(bool e) const
    {
        return m_cBooleanValue == e;
    }
    char m_cBooleanValue;
};

struct hkpConstraintRuntimeD4E0
{
    int unk00, unk04, unk08, unk0c;
    unsigned short unk10;
    unsigned char m_flags;
    unsigned char unk13;
    int unk14, unk18;
    char* m_pRuntime;
};

class hkpSimulationIslandD4E0;

struct BrkEntity
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    hkpSimulationIslandD4E0* m_pSimulationIsland;
};

struct BrkInstance
{
    int unk00;
    int unk04;
    BrkEntity* m_pEntity;
    int unk0C, unk10, unk14, unk18, unk1c, unk20;
    unsigned short m_kListeners;
    unsigned short unk26;
    int unk28, unk2c;
    hkpConstraintRuntimeD4E0* m_pConstraintInternal;
};

struct BrkInfo
{
    hkpSimulationIslandD4E0* m_pCurrentSimulationIsland;
    BrkInstance* m_pHavokConstraint;
    const GlobalObjectO2_00d472a0* m_type;
    int m_0c;
    float m_uiFilterValue;
    float m_threshold;

    BrkInfo(hkpSimulationIslandD4E0* island, BrkInstance* constraint, const GlobalObjectO2_00d472a0* type)
        : m_pCurrentSimulationIsland(island), m_pHavokConstraint(constraint), m_type(type), m_0c(0)
    {}
};

void __cdecl FUN_00d85fa0(BrkInfo* pkInfo);
void __cdecl FUN_00d86050(BrkInfo* pkInfo);
void __cdecl FUN_00d00b40(hkpSimulationIslandD4E0* pkIsland, BrkInfo* pkInfo);
void __cdecl FUN_00d00bf0(hkpSimulationIslandD4E0* pkIsland, BrkInfo* pkInfo);

extern char DAT_01269c44;

struct hkpBreakableRuntimeD4E0
{
    hkBoolD4E0 m_bFlag;
};

class hkpBreakableConstraintDataD4E0
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned short m_runtimeOffset;
    short unk1E;
    float m_threshold;

    void FUN_00d4e020(BrkInstance* instanceArg, hkBoolD4E0 broken, float currentForce);
};

// Sets the broken flag on the breakable runtime, updates the constraint flags, and dispatches a BrkInfo event to listeners and the simulation island.
// @fnv 0x00d4e020
void hkpBreakableConstraintDataD4E0::FUN_00d4e020(BrkInstance* apInstance, hkBoolD4E0 broken, float currentForce)
{
    BrkInstance* instance = reinterpret_cast<BrkInstance*>(*(volatile int*)&apInstance);
    hkpBreakableRuntimeD4E0* runtime =
        reinterpret_cast<hkpBreakableRuntimeD4E0*>(m_runtimeOffset + instance->m_pConstraintInternal->m_pRuntime);
    bool wasBroken = runtime->m_bFlag;
    if (broken == wasBroken)
    {
        return;
    }
    runtime->m_bFlag = broken;
    if (!broken)
    {
        instance->m_pConstraintInternal->m_flags |= 4;
    }
    else
    {
        instance->m_pConstraintInternal->m_flags &= ~4;
    }

    hkpSimulationIslandD4E0* world = instance->m_pEntity->m_pSimulationIsland;
    BrkInfo event(world, instance, reinterpret_cast<const GlobalObjectO2_00d472a0*>(&DAT_01269c44));
    if (broken)
    {
        event.m_0c = 0;
        event.m_uiFilterValue = currentForce;
        event.m_threshold = this->m_threshold;
        if (event.m_pHavokConstraint->m_kListeners)
        {
            FUN_00d85fa0(&event);
        }
        FUN_00d00b40(world, &event);
    }
    else
    {
        event.m_0c = 0;
        if (event.m_pHavokConstraint->m_kListeners)
        {
            FUN_00d86050(&event);
        }
        FUN_00d00bf0(world, &event);
    }
}

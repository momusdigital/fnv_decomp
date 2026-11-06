
// src/havok/physics/dynamics/constraint/motor/velocity/hkpvelocityconstraintmotor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/motor/velocity/hkpvelocityconstraintmotor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVelocityConstraintMotor.h"

struct hkMemory_d861c0
{
    virtual void v00();
    virtual void* allocateChunk(int nbytes) throw();
};
struct hkThreadMemoryHolder_d861c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemory_d861c0* m_pBuffer;
    hkMemory_d861c0& heap()
    {
        return *m_pBuffer;
    }
};
struct Router_d861
{
    static hkThreadMemoryHolder_d861c0& __cdecl FUN_00c85750() throw();
};

inline void* operator new(unsigned int size, void* p)
{
    return p;
}

class hkReferencedObject_d861
{
  public:
    virtual void v0();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    __forceinline hkReferencedObject_d861() throw()
    {
        m_usMemSizeAndFlags = 0x20;
        m_sReferenceCount = 1;
    }
};

class hkpConstraintMotor_d861 : public hkReferencedObject_d861
{
  public:
    virtual void v0();
    signed char m_type;
    char pad9[3];

    __forceinline hkpConstraintMotor_d861(const hkpConstraintMotor_d861& o) throw()
        : hkReferencedObject_d861(), m_type(o.m_type)
    {}
};

class hkpLimitedForceConstraintMotor_d861 : public hkpConstraintMotor_d861
{
  public:
    float m_fMinForce;
    float m_fMaxForce;

    __forceinline hkpLimitedForceConstraintMotor_d861(const hkpLimitedForceConstraintMotor_d861& o) throw()
        : hkpConstraintMotor_d861(o), m_fMinForce(o.m_fMinForce), m_fMaxForce(o.m_fMaxForce)
    {}
};

class hkpVelocityConstraintMotor_d861 : public hkpLimitedForceConstraintMotor_d861
{
  public:
    virtual void v0();
    float m_fTau;
    float m_fVelocityTarget;
    char m_bUseVelocityTarget;
    char pad1D[3];

    __forceinline hkpVelocityConstraintMotor_d861(const hkpVelocityConstraintMotor_d861& o) throw()
        : hkpLimitedForceConstraintMotor_d861(o), m_fTau(o.m_fTau), m_fVelocityTarget(o.m_fVelocityTarget),
          m_bUseVelocityTarget(o.m_bUseVelocityTarget)
    {}

    hkpVelocityConstraintMotor_d861* clone() const;
};

// Allocates a chunk from the thread memory holder and constructs a copy of this hkpVelocityConstraintMotor_d861 in it.
// @fnv 0x00d861c0
hkpVelocityConstraintMotor_d861* hkpVelocityConstraintMotor_d861::clone() const
{
    void* mem = Router_d861::FUN_00c85750().heap().allocateChunk(sizeof(hkpVelocityConstraintMotor_d861));
    __assume(mem != 0);
    return new (mem) hkpVelocityConstraintMotor_d861(*this);
}

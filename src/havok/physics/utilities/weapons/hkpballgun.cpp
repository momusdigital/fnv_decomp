
// src/havok/physics/utilities/weapons/hkpballgun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpballgun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpBallGun.h"

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

struct hkBoolE46E
{
    char m_cBooleanValue;
    hkBoolE46E(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class hkpWorldE46E;

class hkpRigidBodyE46E : public FUN_00d1df70
{
  public:
    int m_00;
    int m_04;
    hkpWorldE46E* m_pOwningWorld;

    hkpWorldE46E* getWorld() const
    {
        return m_pOwningWorld;
    }
};

class hkpWorldE46E
{
  public:
    hkBoolE46E ProcessTarget(hkpRigidBodyE46E* pkEntity) throw();
};

template <class T> class hkQueueE46E
{
  public:
    T* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    bool isEmpty() const
    {
        return m_iNodeCount == 0;
    }
    void dequeue(T& data)
    {
        data = m_data[m_pFirstNode];
        m_pFirstNode++;
        if (m_pFirstNode == m_pRayCursor)
            m_pFirstNode = 0;
        m_iNodeCount--;
    }
};

template <class T> class hkArrayE46E
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkpFirstPersonGunListenerE46E
{
  public:
    virtual ~hkpFirstPersonGunListenerE46E() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void bulletDeletedCallback(hkpRigidBodyE46E* pkBullet) throw();
};

class hkpFirstPersonGunE46E
{
  public:
    virtual ~hkpFirstPersonGunE46E() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
    hkUint8 m_type;
    const char* m_name;
    hkUint8 m_uiKeyboardKey;
    hkArrayE46E<hkpFirstPersonGunListenerE46E*> m_kListeners;
};

class hkpBallGunE46E : public hkpFirstPersonGunE46E
{
  public:
    hkReal m_fBulletRadius;
    hkReal m_fBulletVelocity;
    hkReal m_fBulletMass;
    hkReal m_fBulletSpread;
    hkInt32 m_iBulletBatchCount;
    int m_34;
    int m_38;
    int m_3c;
    hkReal m_kBulletDirection[4];
    hkQueueE46E<hkpRigidBodyE46E*>* m_pBulletQueue;

    void reset(hkpWorldE46E* pkWorld) throw();
};

// @fnv 0x00e46ea0
void hkpBallGunE46E::reset(hkpWorldE46E* pkWorld) throw()
{
    while (!m_pBulletQueue->isEmpty())
    {
        hkpRigidBodyE46E* pkBody;
        m_pBulletQueue->dequeue(pkBody);
        for (int i = m_kListeners.GetLogicalSize() - 1; i >= 0; i--)
            m_kListeners[i]->bulletDeletedCallback(pkBody);
        if (pkBody->getWorld() == pkWorld)
            pkWorld->ProcessTarget(pkBody);
        pkBody->removeReference();
    }
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

static const float DAT_0101df44 = 0.2f;
static const float DAT_0104ef80 = 40.0f;
static const float DAT_0101b268 = 50.0f;

struct hkVector4E46F
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct hkMemoryAllocatorE46F
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};

struct hkMemoryRouterE46F
{
    unsigned int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE46F* m_pStreamAllocator;

    hkMemoryAllocatorE46F& heap()
    {
        return *m_pStreamAllocator;
    }
};

hkMemoryRouterE46F* __cdecl FUN_00c85750();

struct FUN_00cb0c10
{
    void operator=(const char* pcString);

    const char* m_pcText;
};

struct FUN_00e46e80
{
    static void* operator new(unsigned int uiSize)
    {
        return FUN_00c85750()->heap().AllocateMemoryBlock(uiSize);
    }

    FUN_00e46e80() throw();

    void FUN_00e45460(int iCapacity);

    void* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;
};

class FUN_00e46660
{
  public:
    FUN_00e46660() throw();
    virtual ~FUN_00e46660() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    FUN_00cb0c10 m_name;
    unsigned char m_uiKeyboardKey;
    void** m_kListeners;
    int m_listenersSize;
    int m_listenersCapacityAndFlags;
};

class FUN_00e46f90 : public FUN_00e46660
{
  public:
    FUN_00e46f90(int iNumBullets) throw();
    virtual ~FUN_00e46f90() throw();

    float m_fBulletRadius;
    float m_fBulletVelocity;
    float m_fBulletMass;
    float m_fBulletSpread;
    int m_iBulletBatchCount;
    hkVector4E46F m_kBulletDirection;
    FUN_00e46e80* m_pBulletQueue;
    unsigned int unk54, unk58, unk5C;
};

// Initializes a BallGun with default bullet properties and allocates a bullet queue with the specified capacity.
// @fnv 0x00e46f90
FUN_00e46f90::FUN_00e46f90(int iNumBullets) throw()
    : m_fBulletRadius(DAT_0101df44), m_fBulletVelocity(DAT_0104ef80), m_iBulletBatchCount(iNumBullets)
{
    m_fBulletSpread = m_fBulletMass = DAT_0101b268;
    m_kBulletDirection.setZero4();
    m_type = 1;
    m_name = "BallGun";
    m_pBulletQueue = new FUN_00e46e80();
    m_pBulletQueue->FUN_00e45460(iNumBullets);
}

namespace fnv_00e47020 {
class hkMemoryAllocatorE470
{
  public:
    virtual ~hkMemoryAllocatorE470() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE470
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorE470* m_pStreamAllocator;
    hkMemoryAllocatorE470& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterE470& __cdecl FUN_00c85750() throw();

struct hkBoolE470
{
    char m_cBooleanValue;
};

class JobE470;

class JobOwnerE470
{
  public:
    hkBoolE470 ProcessTarget(JobE470* pkJob) throw();
};

class JobE470
{
  public:
    void FUN_00c905b0() throw();
    int unk00, unk04;
    JobOwnerE470* m_pkOwnerManager;
};

class JobListenerE470
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void OnJobCancelled(JobE470* pkJob) throw();
};

template <class T> class hkQueueE470
{
  public:
    T* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    bool isEmpty() const
    {
        return m_iNodeCount == 0;
    }
    void dequeue(T& data)
    {
        data = m_data[m_pFirstNode];
        if (++m_pFirstNode == m_pRayCursor)
            m_pFirstNode = 0;
        m_iNodeCount--;
    }
    void FUN_00e47390() throw();
};

class FUN_00e466e0
{
  public:
    virtual ~FUN_00e466e0() throw();
    int unk04, unk08, unk0C, unk10;
};

class FUN_00e47020 : public FUN_00e466e0
{
  public:
    JobListenerE470** m_kListeners;
    int m_numListeners;
    int unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44;
    int unk48, unk4C;
    hkQueueE470<JobE470*>* m_pkQueue;

    virtual ~FUN_00e47020() throw();
};

// Destructor: for each queued job calls OnJobCancelled on every listener, ProcessTarget on its owner manager and FUN_00c905b0 on it, then frees the queue.
// @fnv 0x00e47020
FUN_00e47020::~FUN_00e47020() throw()
{
    while (!m_pkQueue->isEmpty())
    {
        JobE470* pkJob;
        m_pkQueue->dequeue(pkJob);
        for (int i = m_numListeners - 1; i >= 0; i--)
            m_kListeners[i]->OnJobCancelled(pkJob);
        if (pkJob->m_pkOwnerManager)
            pkJob->m_pkOwnerManager->ProcessTarget(pkJob);
        pkJob->FUN_00c905b0();
    }
    hkQueueE470<JobE470*>* pkQueue = m_pkQueue;
    if (pkQueue)
    {
        pkQueue->FUN_00e47390();
        FUN_00c85750().heap().ReleaseBlock(pkQueue, sizeof(*pkQueue));
    }
}
}  // namespace fnv_00e47020

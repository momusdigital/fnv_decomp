
// src/havok/physics/collide/agent/util/symmetric/hkpsymmetricagentlinearcast.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/util/symmetric/hkpsymmetricagentlinearcast.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d2dbe0;
struct Callback
{
    virtual void Reserved0();
    virtual void Reserved1();
    virtual void Run(FUN_00d2dbe0*, int);
};
struct Result
{
    int unk00[4];
    Callback* callback;
};
struct FUN_00d2dbe0
{
    int unk00[3];
    Result* result;
    Result* FUN_00c85750();
    virtual void Virtual0();
    FUN_00d2dbe0(unsigned int flags);
};
// If bit 0 of flags is set, obtains a Result via FUN_00c85750 and invokes its callback's Run with this and 8.
// @fnv 0x00d2dbe0
FUN_00d2dbe0::FUN_00d2dbe0(unsigned int flags)
{
    if (flags & 1)
    {
        Result* value = FUN_00c85750();
        value->callback->Run(this, 8);
    }
}

struct Inner
{
    virtual void v00();
    virtual unsigned char Invoke(void* first, void* second);
    unsigned char state;
};
struct Wrapper
{
    virtual void v00();
    unsigned char state;
    Inner* inner;
    unsigned char ForwardAndSyncState(void* first, void* second);
};
// Calls inner->Invoke with the two arguments swapped, then copies inner->state into this wrapper's state and returns it.
// @fnv 0x00da7150
unsigned char Wrapper::ForwardAndSyncState(void* first, void* second)
{
    inner->Invoke(second, first);
    return state = inner->state;
}

#include <xmmintrin.h>
extern const __m128 DAT_010c4c00;
struct S_00da7070_Vec4
{
    float x;
    float y;
    float z;
    float w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
};
struct S_00da7070_CdPoint
{
    S_00da7070_Vec4 m_vContactPosition;
    S_00da7070_Vec4 m_vSeparatingNormal;
    const void* m_pBodyA;
    const void* m_pBodyB;
};
struct S_00da7070_Collector
{
    virtual ~S_00da7070_Collector();
    virtual void AddCdPoint(const S_00da7070_CdPoint& p);
    float m_fEarlyOutDistance;
};
struct S_00da7070 : S_00da7070_Collector
{
    S_00da7070_Collector* m_childCollector;
    void AddFlippedCdPoint(const S_00da7070_CdPoint& p);
};
// Creates a flipped contact point by negating the separating normal, swapping bodies, and projecting the position, then adds it to the child collector.
// @fnv 0x00da7070
void S_00da7070::AddFlippedCdPoint(const S_00da7070_CdPoint& p)
{
    __declspec(align(16)) S_00da7070_CdPoint flipped;
    __m128 d = _mm_shuffle_ps(p.m_vSeparatingNormal.q(), p.m_vSeparatingNormal.q(), 0xff);
    flipped.m_vContactPosition.q() = _mm_add_ps(p.m_vContactPosition.q(), _mm_mul_ps(p.m_vSeparatingNormal.q(), d));
    flipped.m_pBodyA = p.m_pBodyB;
    flipped.m_pBodyB = p.m_pBodyA;
    flipped.m_vSeparatingNormal.q() = _mm_xor_ps(p.m_vSeparatingNormal.q(), DAT_010c4c00);
    m_childCollector->AddCdPoint(flipped);
    m_fEarlyOutDistance = m_childCollector->m_fEarlyOutDistance;
}

namespace fnv_00da70e0 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128;
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);

extern const __m128 DAT_010c4c00;

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline hkVector4& operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    __forceinline void setBroadcast3(const hkVector4& v)
    {
        __m128 t = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
        m_vComponents = _mm_shuffle_ps(t, t, 0);
    }
    __forceinline void mul4(const hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void add4(const hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00);
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAddMul4(const hkVector4& a, const hkVector4& b, const hkVector4& r)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(b.m_vComponents, r.m_vComponents));
    }
    __forceinline void setNeg3(const hkVector4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00);
    }
    __forceinline void neg4()
    {
        m_vComponents = _mm_xor_ps(m_vComponents, DAT_010c4c00);
    }
};

struct VecDispatch
{
    virtual void v00();
    virtual void Dispatch(void* packet);
    float m_04;
};
struct VecArg
{
    hkVector4 m_00;
    hkVector4 m_10;
    unsigned int m_20;
    unsigned int m_24;
};
struct VecPacket
{
    hkVector4 m_00;
    hkVector4 m_10;
    unsigned int m_20;
    unsigned int m_24;
    __forceinline VecPacket(unsigned int a, unsigned int b) : m_20(a), m_24(b)
    {}
};
struct VecHolder
{
    unsigned int unk00;
    float m_04;
    unsigned int unk08;
    unsigned int unk0C;
    hkVector4 m_10;
    VecDispatch* m_20;

    void addCdPoint(const VecArg& arg);
};

// Builds a packet with arg.m_00 + m_10 * arg.m_10's w and arg.m_10 negated, dispatches it via m_20, and copies m_20->m_04 to m_04.
// @fnv 0x00da70e0
void VecHolder::addCdPoint(const VecArg& arg)
{
    VecPacket p(arg.m_24, arg.m_20);
    hkVector4 w;
    w.setBroadcast3(arg.m_10);
    p.m_00.setAddMul4(arg.m_00, m_10, w);
    p.m_10.setNeg3(arg.m_10);
    m_20->Dispatch(&p);
    m_04 = m_20->m_04;
}
}  // namespace fnv_00da70e0

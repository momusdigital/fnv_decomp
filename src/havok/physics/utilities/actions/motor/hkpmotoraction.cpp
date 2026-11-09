
// src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/motor/hkpmotoraction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMotorAction.h"

#include <xmmintrin.h>
extern int vftable_hkpMotorAction;

struct FUN_00d2b260_Obj
{
    void FUN_00d2b260(int a1, int a2);
};

struct hkVec4
{
    __m128 quad;
    __forceinline void normalize3();
};

__forceinline void hkVec4::normalize3()
{
    __m128 v = quad;
    __m128 sq = _mm_mul_ps(v, v);
    __m128 t = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0x4e), sq);
    __m128 d = _mm_add_ps(_mm_shuffle_ps(t, t, 0xb1), t);

    __m128 rs = _mm_rsqrt_ss(d);
    __m128 mask = _mm_cmpeq_ss(d, _mm_set_ss(0.0f));
    __m128 dr = _mm_mul_ss(_mm_mul_ss(d, rs), rs);
    __m128 inv = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), rs), _mm_sub_ss(_mm_set_ss(3.0f), dr));
    __m128 sel = _mm_andnot_ps(mask, inv);
    quad = _mm_mul_ps(_mm_shuffle_ps(sel, sel, 0), v);
}

struct FUN_00d4d720
{
    int* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_pEntity;
    int unk1c;
    hkVec4 m_kAxisEndPoints;
    volatile float m_fSpinRate;
    volatile float m_fGain;
    volatile unsigned char m_bSlotEnabled;

    FUN_00d4d720(int entity, const float* axis, float spinRate, float gain);
};

// Calls FUN_00d2b260(entity, 0), sets the vtable, loads and normalizes axis, stores spinRate and gain, and sets m_bSlotEnabled to 1.
// @fnv 0x00d4d720
FUN_00d4d720::FUN_00d4d720(int entity, const float* axis, float spinRate, float gain)
{
    reinterpret_cast<FUN_00d2b260_Obj*>(this)->FUN_00d2b260(entity, 0);
    m_vtbl = &vftable_hkpMotorAction;
    m_kAxisEndPoints.quad = _mm_load_ps(axis);
    m_fSpinRate = spinRate;
    m_fGain = gain;
    m_bSlotEnabled = 1;
    m_kAxisEndPoints.normalize3();
}


// src/havok/physics/utilities/actions/dashpot/hkpdashpotaction_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/dashpot/hkpdashpotaction.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/dashpot/hkpdashpotaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/dashpot/hkpdashpotaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpDashpotAction.h"
#include <xmmintrin.h>
extern float DAT_0101e2bc;
extern float DAT_01013ea4;
extern int DAT_010d0994;
struct FUN_00cf4d80_shell { void FUN_00cf4d80(int entityA, int entityB, int name); };
struct FUN_00d4d980_Class : hkpDashpotAction { FUN_00d4d980_Class* FUN_00d4d980(int entityA, int entityB, int name); };
// FUN_00d4d9d0 - hkpDashpotAction clone-style factory (Havok)
__declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
unsigned long g_tlsIdx = 0;
__declspec(noinline) void* FUN_00c85750() {
	unsigned long idx = g_tlsIdx;
	return TlsGetValue(idx);
}
class DashHeap1 {
public:
	virtual void unk00();
	virtual void* allocate(int size);
};
struct DashRouter1 {
	void* u00;
	void* u04;
	void* u08;
	void* u0c;
	DashHeap1* u10;
};
class FUN_00d4d980_class {
public:
	void* FUN_00d4d980(hkpEntity* entityA, hkpEntity* entityB, hkUlong userData);
};
__declspec(noinline) void* FUN_00d4d980_class::FUN_00d4d980(hkpEntity* entityA, hkpEntity* entityB, hkUlong userData) {
	return this;
}
class hkpDashpotActionX : public hkpDashpotAction {
public:
	hkpAction* FUN_00d4d9d0(const hkArray<hkpEntity*>& newEntities, const hkArray<hkpEntity*>& removedEntities);
};

#include <xmmintrin.h>
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern double DAT_010d09b8;
extern float DAT_01012054;

namespace DashpotApplyDetail {

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);

typedef void* (__stdcall *DashpotApplyTlsGetter)(unsigned long dwTlsIndex);

static inline __m128 dashpotApplyBroadcast(float f) { __m128 t = _mm_load_ss(&f); return _mm_shuffle_ps(t,t,0); }

struct S00d4da60_Transform;

struct __declspec(align(16)) DashpotApplyVector
{
    float x, y, z, w;
    void FUN_00c7f640(const S00d4da60_Transform* transform, const DashpotApplyVector* point);
};

struct S00d4da60_Transform
{
    DashpotApplyVector m_kColumn0, m_kColumn1, m_kColumn2, m_vTranslation;
};

struct S00d4da60_ProfRec
{
    const char* m_pName;
    unsigned int m_iTick;
    unsigned int unk08;
};

struct S00d4da60_ProfBuf
{
    unsigned int unk00;
    S00d4da60_ProfRec* m_pCur;
    unsigned int unk08;
    S00d4da60_ProfRec* m_pRecordEnd;
};

struct S00d4da60_Body
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void ApplyImpulseAtPoint(const DashpotApplyVector* impulse, const DashpotApplyVector* point);
};

struct S00d4da60_Entity
{
    void* m_vtbl;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
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
    S00d4da60_Body m_kCollisionBody;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    S00d4da60_Transform m_kMotionTransform;
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
    DashpotApplyVector m_kTranslationalVelocity;
    void FUN_00c9c1d0();
};

struct S00d4da60_StepInfo
{
    int unk00;
    int unk04;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

struct S00d4da60_StepRef
{
    const S00d4da60_StepInfo* p;
    const S00d4da60_StepInfo* operator->() const { return p; }
};

struct S00d4da60_DashpotAction
{
    void* m_vtbl;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    S00d4da60_Entity* m_pEntityA;
    S00d4da60_Entity* m_pEntityB;
    DashpotApplyVector m_kPoint[2];
    float m_fSpringStrength;
    float m_fMotorDamping;
    void* unk48;
    void* unk4C;
    DashpotApplyVector m_fContactImpulse;
    void applyAction(S00d4da60_StepRef stepInfo);
};

// @fnv 0x00d4da60
void S00d4da60_DashpotAction::applyAction(S00d4da60_StepRef stepInfo)
{
    DashpotApplyTlsGetter pfnTls = TlsGetValue;

    {
        S00d4da60_ProfBuf* pBuf = (S00d4da60_ProfBuf*)pfnTls(DAT_0126835c);
        if (pBuf->m_pCur < pBuf->m_pRecordEnd)
        {
            S00d4da60_ProfRec* pRec = pBuf->m_pCur;
            pRec->m_pName = "TtDashpot";
            _ReadWriteBarrier();
            unsigned int tick;
            __asm {
                rdtsc
                mov dword ptr[tick], eax
            }
            pRec->m_iTick = tick;
            pBuf->m_pCur = pRec + 1;
        }
    }

    float dt = stepInfo->m_fTimeStep * DAT_010d09b8;

    S00d4da60_Entity* entityA = m_pEntityA;
    S00d4da60_Entity* entityB = m_pEntityB;

    struct S00d4da60_Scratch { DashpotApplyVector points[2]; DashpotApplyVector opposite; } scratch;
    scratch.points[1].FUN_00c7f640(&entityA->m_kMotionTransform, &m_kPoint[0]);
    scratch.points[0].FUN_00c7f640(&entityB->m_kMotionTransform, &m_kPoint[1]);

    __m128 relVel = _mm_sub_ps(((const __m128&)entityA->m_kTranslationalVelocity), ((const __m128&)entityB->m_kTranslationalVelocity));
    __m128 dir = _mm_sub_ps(((const __m128&)scratch.points[1]), ((const __m128&)scratch.points[0]));
    DashpotApplyVector* impulse = &m_fContactImpulse;
    float factor = m_fSpringStrength * dt;
    __m128 strength = _mm_load_ss(&factor);
    __m128 strengthVec = _mm_shuffle_ps(strength,strength,0);
    factor = dt * m_fMotorDamping;
    _mm_store_ps(&impulse->x, _mm_mul_ps(strengthVec, dir));
    __m128 damping = _mm_load_ss(&factor);
    __m128 dampingVec = _mm_shuffle_ps(damping,damping,0);
    _mm_store_ps(&impulse->x, _mm_add_ps(_mm_mul_ps(dampingVec, relVel), ((const __m128&)*impulse)));
    _ReadWriteBarrier();
    _mm_store_ps(&scratch.opposite.x, _mm_mul_ps(dashpotApplyBroadcast(DAT_01012054), ((const __m128&)*impulse)));
    entityA->FUN_00c9c1d0();
    entityA->m_kCollisionBody.ApplyImpulseAtPoint(&scratch.opposite, &scratch.points[1]);
    entityB->FUN_00c9c1d0();
    entityB->m_kCollisionBody.ApplyImpulseAtPoint(impulse, &scratch.points[0]);

    {
        S00d4da60_ProfBuf* pBuf = (S00d4da60_ProfBuf*)pfnTls(DAT_0126835c);
        if (pBuf->m_pCur < pBuf->m_pRecordEnd)
        {
            S00d4da60_ProfRec* pRec = pBuf->m_pCur;
            pRec->m_pName = "Et";
            _ReadWriteBarrier();
            unsigned int tick;
            __asm {
                rdtsc
                mov dword ptr[tick], eax
            }
            pRec->m_iTick = tick;
            pBuf->m_pCur = pRec + 1;
        }
    }
}



}

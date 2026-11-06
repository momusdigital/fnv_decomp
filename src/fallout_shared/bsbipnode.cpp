// fallout_shared/bsbipnode.cpp: AnimationInterpolatorNode (5 functions)

#include "bsbipnode_decls.h"

// @fnv 0x004f0380
void AnimationInterpolatorNode::UpdateInterpolatorsAtTime(float time, bool selective)
{
    if (!FUN_004f05a0() || !m_usNumInterps)
        return;

    int iIndex;
    NiAVObject* target;
    NiQuatTransform transform;
    // Cache the pass limit while the shared transform remains available.
    {
        const int lastIndex = m_usNumInterps - 1;
        for (iIndex = 0; iIndex < lastIndex; ++iIndex)
        {
            target = m_ppTargetObjects[iIndex];
            if (!target)
                continue;
            if (!selective && !target->GetSelectiveUpdate())
                continue;
            else if (selective && target->GetSelectiveUpdate())
                continue;

            if (m_pkBlendInterpolators[iIndex].Update(time, target, transform))
            {
                if (transform.IsTranslateXNotNegatedConstant())
                    target->FUN_00440460(transform.GetTranslate());
                if (transform.FUN_004f02e0())
                    target->FUN_004f0160(transform.GetOffsetC());
                if (transform.FUN_004f0320())
                    target->FUN_00440490(transform.GetFloatAtOffset1C());
            }
        }

        target = m_ppTargetObjects[iIndex];
        if (!target || (!selective && !target->GetSelectiveUpdate()))
            return;
        if (m_pkBlendInterpolators[iIndex].Update(time, target, transform))
        {
            if (transform.IsTranslateXNotNegatedConstant())
                target->FUN_00440460(transform.GetTranslate());
            if (transform.FUN_004f02e0())
                target->FUN_004f0160(transform.GetOffsetC());
            if (transform.FUN_004f0320())
                target->FUN_00440490(transform.GetFloatAtOffset1C());
        }
    }
}

struct FUN_004f0000_shell : public NiAVObject
{
    bool FUN_004f0000();
};

struct FUN_00456630_helper
{
    bool FUN_00456630(unsigned int);
};

// @fnv 0x004f0000
bool FUN_004f0000_shell::FUN_004f0000()
{
    return ((FUN_00456630_helper*)this)->FUN_00456630(0x40000);
}

struct FUN_004f00e0_shell : public NiAVObject
{
    void SetWorldTranslate(void*);
};

// @fnv 0x004f00e0
void FUN_004f00e0_shell::SetWorldTranslate(void* kTrn)
{
    *reinterpret_cast<NiPoint3*>(reinterpret_cast<char*>(this) + 0x8C) = *reinterpret_cast<const NiPoint3*>(kTrn);
}

extern int DAT_011f36bc;
extern int g_011f36e4;
struct UpdData
{
    int a;
    int b;
    int c;
    void NiUpdateData(float, bool, bool);
};
struct CtlV
{
    virtual void v0();
    virtual void v1();
    virtual const void* GetRTTI();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f0a();
    virtual void f0b();
    virtual void f0c();
    virtual void f0d();
    virtual void f0e();
    virtual void f0f();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f1a();
    virtual void f1b();
    virtual void f1c();
    virtual void f1d();
    virtual void f1e();
    virtual void f1f();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void Update(UpdData*);
    CtlV* GetNext() const;
};
struct ModelOps
{
    CtlV* GetObject3D();
};
struct FUN_004f0040_shell
{
    void UpdateControls(float afTime);
};

// @fnv 0x004f0040
void FUN_004f0040_shell::UpdateControls(float afTime)
{
    CtlV* pkControl;
    for (pkControl = ((ModelOps*)this)->GetObject3D(); pkControl; pkControl = pkControl->GetNext())
    {
        if (pkControl->GetRTTI() == &DAT_011f36bc)
        {
            ((AnimationInterpolatorNode*)pkControl)->UpdateInterpolatorsAtTime(afTime, false);
        }
        else if (pkControl->GetRTTI() == &g_011f36e4)
        {
            UpdData updateData;
            updateData.NiUpdateData(afTime, false, false);
            pkControl->Update(&updateData);
        }
    }
}

__declspec(thread) int DAT_tls_0x2c0;

// @fnv 0x004f0020
void FUN_004f0020(int value)
{
    DAT_tls_0x2c0 = value;
}

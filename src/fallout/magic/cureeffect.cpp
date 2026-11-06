
// src/fallout/magic/cureeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/cureeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Actor;
struct MagicTarget
{
    Actor* GetOwnerActor() const;
};

struct FUN_0080d4b0_shell
{
    bool HasActor(MagicTarget* apTarget);
};

// @fnv 0x0080d4b0
bool FUN_0080d4b0_shell::HasActor(MagicTarget* apTarget)
{
    Actor* pActor = apTarget ? apTarget->GetOwnerActor() : 0;
    return pActor != 0;
}

struct BSThread
{
    unsigned int GetThreadID();
};
struct Unk824630
{
    void FUN_00824630(int);
};
struct Unk824800
{
    void RemoveEffectsByArchetype(int, int);
};
struct CureEffect
{
    char _pad[0x48];
    int m_eSpellType;
    int m_iCureType;
    void Start();
};
// @fnv 0x0080c210
void CureEffect::Start()
{
    if (m_iCureType == -1)
        ((Unk824630*)((BSThread*)this)->GetThreadID())->FUN_00824630(m_eSpellType);
    else
        ((Unk824800*)((BSThread*)this)->GetThreadID())->RemoveEffectsByArchetype(m_iCureType, 0);
}

struct MagicCaster;
struct MagicItem;
struct EffectItem;

struct ActiveEffect
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v0a()
    {}
    virtual void v0b()
    {}
    virtual void v0c()
    {}
    virtual void v0d()
    {}
    virtual void v0e()
    {}
    virtual void v0f()
    {}
    virtual void v10()
    {}
    virtual void v11(ActiveEffect*)
    {}
};

struct FUN_0080c070 : ActiveEffect
{
    char _pad[0x4c];

    FUN_0080c070(MagicCaster*, MagicItem*, EffectItem*, int);
};

struct FUN_0080c0b0 : ActiveEffect
{
    char _pad[0x4c];

    FUN_0080c0b0(MagicCaster*, MagicItem*, EffectItem*, int);
};

struct FUN_0080c0f0_shell : ActiveEffect
{
    char _pad0[4];
    MagicItem* pMagicItem;
    EffectItem* pEffectItem;
    char _pad1[0x18];
    MagicCaster* pMagicCaster;
    char _pad2[0x1c];
    int m_eSpellType;
    int m_iCureType;

    ActiveEffect* Clone();
};

void* __cdecl operator new(unsigned int);

// @fnv 0x0080c0f0
ActiveEffect* FUN_0080c0f0_shell::Clone()
{
    ActiveEffect* pEffect = 0;

    if (m_iCureType == -1)
    {
        pEffect = new FUN_0080c070(pMagicCaster, pMagicItem, pEffectItem, m_eSpellType);
    }
    else
    {
        pEffect = new FUN_0080c0b0(pMagicCaster, pMagicItem, pEffectItem, m_iCureType);
    }

    this->v11(pEffect);
    return pEffect;
}

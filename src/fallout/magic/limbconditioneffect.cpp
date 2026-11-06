// fallout/magic/limbconditioneffect.cpp: LimbConditionEffect, MyEffect, LimbConditionEffectShell, ValueModifierEffect (11 functions)

bool g_bLimbConditionEffectInitialized;

// @fnv 0x005b9210
bool GetLimbConditionEffectInitialized()
{
    return g_bLimbConditionEffectInitialized;
}

struct Actor;
struct LimbConditionEffect
{
    unsigned short __thiscall FUN_00802d90(Actor* apActor);
    unsigned short __thiscall FUN_0080f2b0(Actor* apActor);
};

// @fnv 0x0080f2b0
unsigned short __thiscall LimbConditionEffect::FUN_0080f2b0(Actor* apActor)
{
    unsigned short isize = 0;
    isize += ((LimbConditionEffect*)this)->FUN_00802d90(apActor);
    isize += 4;
    return isize;
}

struct ValueModifierEffect
{
    ValueModifierEffect(void*, void*, void*);
};
extern int DAT_0107a3fc;
struct FUN_0080f060 : ValueModifierEffect
{
    FUN_0080f060(void*, void*, void*);
};
// Constructs the object by calling the ValueModifierEffect base constructor, setting the vtable to DAT_0107a3fc and initializing the field at offset 0x4C to -1.
// @fnv 0x0080f060
FUN_0080f060::FUN_0080f060(void* a, void* b, void* c) : ValueModifierEffect(a, b, c)
{
    *(void**)this = (void*)&DAT_0107a3fc;
    *(int*)((char*)this + 0x4C) = -1;
}

struct TESSaveLoadGame
{
    void ReadTypedData(void*, unsigned int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct Base00802dd0
{
    void FUN_00802dd0(void*);
};
struct FUN_0080f2f0_Owner
{
    char _pad[0x4C];
    int m_4C;
    void FUN_0080f2f0(void*);
};
// @fnv 0x0080f2f0
void FUN_0080f2f0_Owner::FUN_0080f2f0(void* a1)
{
    ((Base00802dd0*)this)->FUN_00802dd0(a1);
    g_TESSaveLoadGame->ReadTypedData(&m_4C, 4);
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct Unk0080F320
{
    void SaveGameBGS(BGSSaveFormBuffer*);
    void SaveToBuffer(BGSSaveFormBuffer*);
    char _pad[0x4C];
    int _m4C;
};
// @fnv 0x0080f320
void Unk0080F320::SaveToBuffer(BGSSaveFormBuffer* apBuffer)
{
    SaveGameBGS(apBuffer);
    apBuffer->SaveData(&_m4C, 4, 0);
}

struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
    void __thiscall ReadTypedData(void*, unsigned int);
};
struct ActiveEffect
{
    virtual void __thiscall LoadGame(BGSLoadFormBuffer*);
};
struct MyEffect : ActiveEffect
{
    void __thiscall FUN_0080f350(BGSLoadFormBuffer*);
};
// Calls ActiveEffect::LoadGame, then for buffer version 8 or higher reads 4 bytes into the field at offset 0x4c.
// @fnv 0x0080f350
void __thiscall MyEffect::FUN_0080f350(BGSLoadFormBuffer* apBuffer)
{
    ActiveEffect::LoadGame(apBuffer);
    if (apBuffer->GetVersion() >= 8)
    {
        apBuffer->ReadTypedData((char*)this + 0x4c, 4);
    }
}

struct ValueModifierEffectShell : public ValueModifierEffect
{
    void __thiscall CopyData(ActiveEffect* other);
};

struct LimbConditionEffectShell : public LimbConditionEffect
{
    char _pad[0x4C];
    int m_4C;
    void __thiscall FUN_0080f150(ActiveEffect* other);
};

// Copies the base value-modifier data from other, then, if other is a LimbConditionEffect, copies m_4C into it.
// @fnv 0x0080f150
void __thiscall LimbConditionEffectShell::FUN_0080f150(ActiveEffect* other)
{
    reinterpret_cast<ValueModifierEffectShell*>(this)->CopyData(other);
    LimbConditionEffect* target = dynamic_cast<LimbConditionEffect*>(other);
    if (target)
        reinterpret_cast<LimbConditionEffectShell*>(target)->m_4C = m_4C;
}

namespace fnv_0082ba30 {
struct ValueModifierEffect
{
    char _pad[0x4C];
    int m_4C;
    void FUN_00802db0(Actor*);
    void FUN_0082ba30(Actor*);
};
struct TESSaveLoadGame
{
    void FUN_008579b0(int*, int);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
// @fnv 0x0082ba30
void ValueModifierEffect::FUN_0082ba30(Actor* apActor)
{
    FUN_00802db0(apActor);
    g_TESSaveLoadGame->FUN_008579b0(&m_4C, 4);
}
}  // namespace fnv_0082ba30

struct GameSettingCollection
{
    float fValue;
};
template <class T> struct SettingT
{
    float* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1213;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1214;
struct ActorValue
{
    enum Index
    {
        All = 25,
        None = -1
    };
};
struct ValueModifierEffectHelper
{
    void __thiscall ApplyActorValueModifier(Actor*, float, ActorValue::Index);
};
struct LimbConditionEffect_0080f220
{
    char _pad[0x4C];
    int m_4C;
    void __thiscall ModifyActorValue(Actor* apActor, float afModifier, ActorValue::Index aeOverrideActorValue);
};
// @fnv 0x0080f220
void __thiscall LimbConditionEffect_0080f220::ModifyActorValue(Actor* apActor, float afModifier,
                                                           ActorValue::Index aeOverrideActorValue)
{
    if (m_4C != ActorValue::None)
    {
        float fScaledMagnitude = afModifier * *originalRuntimeFloatSetting1213.Float();
        ((ValueModifierEffectHelper*)this)->ApplyActorValueModifier(apActor, afModifier, (ActorValue::Index)m_4C);
    }
    else
    {
        float fScaledMagnitude = afModifier * *originalRuntimeFloatSetting1214.Float();
        for (int i = ActorValue::All; i < 32; ++i)
            ((ValueModifierEffectHelper*)this)
                ->ApplyActorValueModifier(apActor, fScaledMagnitude, (ActorValue::Index)i);
    }
}

struct FUN_0080f1a0_StandIn : ValueModifierEffect
{
    char _pad[0x50 - sizeof(void*)];
    int _m50;
    FUN_0080f1a0_StandIn(void*, void*, void*);
};

// Allocates and constructs a stand-in ValueModifierEffect-derived object from three arguments and returns it.
// @fnv 0x0080f1a0
FUN_0080f1a0_StandIn* FUN_0080f1a0(void* ap1, void* ap2, void* ap3)
{
    return new FUN_0080f1a0_StandIn(ap1, ap2, ap3);
}

void* __cdecl operator new(unsigned int);
extern int _data_011c16bc;

struct FUN_0080f0a0_Class
{
// @fnv 0x0080f0a0
    virtual void FUN_0080f0a0_00()
    {}
    virtual void FUN_0080f0a0_01()
    {}
    virtual void FUN_0080f0a0_02()
    {}
    virtual void FUN_0080f0a0_03()
    {}
    virtual void FUN_0080f0a0_04()
    {}
    virtual void FUN_0080f0a0_05()
    {}
    virtual void FUN_0080f0a0_06()
    {}
    virtual void FUN_0080f0a0_07()
    {}
    virtual void FUN_0080f0a0_08()
    {}
    virtual void FUN_0080f0a0_09()
    {}
    virtual void FUN_0080f0a0_10()
    {}
    virtual void FUN_0080f0a0_11()
    {}
    virtual void FUN_0080f0a0_12()
    {}
    virtual void FUN_0080f0a0_13()
    {}
    virtual void FUN_0080f0a0_14()
    {}
    virtual void FUN_0080f0a0_15()
    {}
    virtual void FUN_0080f0a0_16()
    {}
    virtual void CopyFrom(ActiveEffect* other);

    char _pad[4];
    void* _p8;
    void* _pC;
    char _pad10[0x18];
    void* _p28;
};

ActiveEffect* __fastcall Clone(FUN_0080f0a0_Class* self)
{
    ActiveEffect* presult = (ActiveEffect*)new FUN_0080f1a0_StandIn(self->_p28, self->_p8, self->_pC);

    self->CopyFrom(presult);

    return presult;
}

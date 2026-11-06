// fallout_shared/magic/spellitem.cpp: SpellItem, MagicItem (15 functions)

#include "spellitem_decls.h"

// Resets spellType, cost, level and flags to 0, -1, 0 and 0.
// @fnv 0x0040e330
void SpellItem::ResetFormData()
{
    spellType = 0;
    cost = -1;
    level = 0;
    flags = 0;
}

// @fnv 0x0040e280
int __fastcall FUN_0040e280(int thisPtr)
{
    return 0x54495053;
}

struct FUN_0040e500_shell
{
    void SetValue(int value);
};

// @fnv 0x0040e500
void FUN_0040e500_shell::SetValue(int value)
{
    *reinterpret_cast<int*>(this + 0x38) = value;
}

void __cdecl _Deallocate(void* p);

struct FUN_0040e290_shell
{
    void FUN_0040e2c0();
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls FUN_0040e2c0, frees this via _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0040e290
void* FUN_0040e290_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_0040e2c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FlaggedData
{
    int __thiscall ContainsAnyFlag(unsigned int);
};

struct FUN_0040e670_shell
{
    void FUN_0040e670();
};

// @fnv 0x0040e670
void FUN_0040e670_shell::FUN_0040e670()
{
    ((FlaggedData*)((char*)this - 0x18))->ContainsAnyFlag(0x40);
}

struct Base5a
{
    virtual ~Base5a();
    char _pad[20];
};
struct IngredientItem
{
    virtual ~IngredientItem();
};
struct FUN_00409210
{
    Base5a _a;
    IngredientItem _b;
    ~FUN_00409210();
};
// Destructor for the object holding a Base5a and an IngredientItem; the body is empty.
// @fnv 0x00409210
FUN_00409210::~FUN_00409210()
{}

struct FUN_0040e1e0_shell
{
    bool FUN_0040e1e0();
};
// Returns true when the object at this-0x18 reports false for the argument 1.
// @fnv 0x0040e1e0
bool __thiscall FUN_0040e1e0_shell::FUN_0040e1e0()
{
    return !(unsigned char)((FlaggedData*)((char*)this - 0x18))->ContainsAnyFlag(1);
}

struct FUN_0040e650_shell : FlaggedData
{
    void FUN_0040e650();
};
// @fnv 0x0040e650
void FUN_0040e650_shell::FUN_0040e650()
{
    ((FlaggedData*)((char*)this - 0x18))->ContainsAnyFlag(0x20);
}

class TESForm40E
{
  public:
    virtual ~TESForm40E();
    void SetFormType(int eType);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class TESFullName40E
{
  public:
    virtual ~TESFullName40E();

    int unk04;
    int unk08;
};

class MagicItem40E
{
  public:
    virtual ~MagicItem40E();

    int unk04;
    int unk08;
};

class MagicItemForm40E : public TESForm40E, public TESFullName40E, public MagicItem40E
{
  public:
    MagicItemForm40E();
    virtual ~MagicItemForm40E();
};

class FUN_0040e160 : public MagicItemForm40E
{
  public:
    FUN_0040e160();
    virtual ~FUN_0040e160();

    void InitItem();
};

// Sets the form type to 0x14 and calls InitItem to initialize the magic item form.
// @fnv 0x0040e160
FUN_0040e160::FUN_0040e160()
{
    SetFormType(0x14);
    InitItem();
}

// Secondary-interface override: the speaker sound when the info is flagged, otherwise a sound picked
// from the interface's own value.

class E600Sound;

E600Sound* __cdecl E600PickSound(float fValue);

class E600Info
{
  public:
    virtual ~E600Info();
    bool HasFlag(int iFlag);
    E600Sound* GetSpeaker();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

class E600SoundSource
{
  public:
    virtual void Unk_00();
    virtual E600Sound* FUN_0040e600();
    virtual float GetValue(int iIndex);
};

class E600TopicInfo : public E600Info, public E600SoundSource
{
  public:
    virtual E600Sound* FUN_0040e600();
};

// Returns the speaker sound if flag 1 is set, otherwise picks a sound from the value at index 0.
// @fnv 0x0040e600
E600Sound* E600TopicInfo::FUN_0040e600()
{
    if (HasFlag(1))
        return GetSpeaker();
    else
        return E600PickSound(GetValue(0));
}

class FormPart40E
{
  public:
    virtual ~FormPart40E();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class NamePart40E
{
  public:
    virtual void GetName();

    int unk04;
    int unk08;
};

class EffectPart40E
{
  public:
    virtual void GetEffects();

    int unk04;
};

class MagicItemObject40E : public FormPart40E, public NamePart40E, public EffectPart40E
{
  public:
    virtual ~MagicItemObject40E();

    void ClearData();
};

class FUN_0040e2c0 : public MagicItemObject40E
{
  public:
    virtual ~FUN_0040e2c0();
};

// @fnv 0x0040e2c0
FUN_0040e2c0::~FUN_0040e2c0()
{
    ClearData();
}

struct TESForm
{
    virtual ~TESForm();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int GetA();
    int GetB();
};

struct MagicBase
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual int s6();
    virtual bool FUN_0040e3c0(class MagicItem* p);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

class MagicItem : public TESForm, public MagicBase
{
  public:
    unsigned char m_40;
    bool FUN_0040e3c0(MagicItem* p);
};

// Casts p to SpellItem and returns true if it is null or differs from this item in s6, GetA, GetB or m_40; otherwise false.
// @fnv 0x0040e3c0
bool MagicItem::FUN_0040e3c0(MagicItem* apItem)
{
    MagicItem* a = reinterpret_cast<MagicItem*>(dynamic_cast<SpellItem*>(apItem));
    if (a == 0)
    {
        return true;
    }
    if (a->s6() != s6() || a->GetA() != GetA() || a->GetB() != GetB() || a->m_40 != m_40)
    {
        return true;
    }
    return false;
}

bool FUN_00401500();
void __cdecl AppendChunk(int iValue, void* pData, int iSize);
struct SubE360
{
    void FUN_005a6b10();
};
struct PadE360
{
    virtual void f00();
};
struct IfaceE360
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
    virtual int GetValue();
    virtual void FUN_0040e360();
};
struct ObjE360 : PadE360, IfaceE360
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SubE360 m_sub;
    virtual void FUN_0040e360();
};
// @fnv 0x0040e360
void ObjE360::FUN_0040e360()
{
    if (FUN_00401500())
        m_sub.FUN_005a6b10();
    AppendChunk(GetValue(), &m_sub, 0x10);
    if (FUN_00401500())
        m_sub.FUN_005a6b10();
}

struct Actor;
struct MagicEffectKind
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int GetType();
};
struct SpellData
{
    bool FUN_0040e210(int flag);
    int GetField38();
};
struct ActorValues
{
    int FUN_0066ef20(int id);
};
float __cdecl ScaleBySettingBlend(float cost, int value, int adjustment);
struct FUN_0040e520_shell
{
    int GetAssociatedSkill();
    float GetTotalCost(Actor* caster);
    float FUN_0040e520(Actor* caster);
};
// @fnv 0x0040e520
float FUN_0040e520_shell::FUN_0040e520(Actor* caster)
{
    float cost = 0.0f;
    Actor* effectiveCaster = (((MagicEffectKind*)((char*)this - 12))->GetType() == 2 ||
                              ((MagicEffectKind*)((char*)this - 12))->GetType() == 3)
                                 ? 0
                                 : caster;
    if (((SpellData*)((char*)this - 36))->FUN_0040e210(1))
    {
        cost = (float)((SpellData*)((char*)this - 36))->GetField38();
        if (effectiveCaster)
        {
            cost =
                ScaleBySettingBlend(cost, ((ActorValues*)((char*)effectiveCaster + 0xa4))->FUN_0066ef20(GetAssociatedSkill()),
                                    ((ActorValues*)((char*)effectiveCaster + 0xa4))->FUN_0066ef20(11));
        }
    }
    else
    {
        cost = GetTotalCost(effectiveCaster);
    }
    return cost;
}

extern char DAT_01183060;
extern char DAT_01183140;
extern "C" void* __cdecl _FNV_DynamicCast(void*, int, void*, void*, int);
class TESActorBase;
class TESTopicInfo
{
  public:
    TESActorBase* GetSpeaker();
};
struct SpeakerSink40E
{
    void FUN_00409480(TESActorBase* value);
};

struct CopySource40E : TESForm, MagicBase
{
    unsigned char flags;
    int GetField38();
};
struct CopyOwner40E;
struct CopyPart40E
{
    virtual void slot0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    unsigned char flags;
    virtual void FUN_0040e470(MagicItem* input);
};
struct CopyOwner40E : TESForm, CopyPart40E
{
    void FUN_008d7dc0(int value);
    virtual void FUN_0040e470(MagicItem* input);
};
// Passes source values to setters, assigns the value returned by GetSpeaker, and copies the source flags.
// @fnv 0x0040e470
void CopyOwner40E::FUN_0040e470(MagicItem* apSource)
{
    CopySource40E* source = static_cast<CopySource40E*>(_FNV_DynamicCast(apSource, 0, &DAT_01183140, &DAT_01183060, 0));
    if (source == 0)
        return;
    FUN_008d7dc0(source->s6());
    reinterpret_cast<FUN_0040e500_shell*>(this)->SetValue(source->GetField38());
    reinterpret_cast<SpeakerSink40E*>(this)->FUN_00409480(reinterpret_cast<TESTopicInfo*>(source)->GetSpeaker());
    flags = source->flags;
}

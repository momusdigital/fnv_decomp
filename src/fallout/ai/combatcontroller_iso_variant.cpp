// src/fallout/ai/combatcontroller_iso_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/combatcontroller.cpp that match byte for byte only
// with VC9 SP1 and /MT /Od /Oy- /GS /EHsc /Gy (unit lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton.

#include "multi_bound_marker_data.h"

int __fastcall FUN_007031c0(int);

struct ActorValueOwner
{
    int GetActorValueAsInteger(int);
};

struct MiddleHighProcess
{
    int GetWeaponForm();
};

struct TESAmmoInitCalls
{
    unsigned int FUN_0097ae90();
};

class Actor
{
  public:
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void d009();
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual void d064();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void d133();
    virtual void d134();
    virtual bool Method21c();
};

class Creature : public Actor
{
  public:
    float GetWeaponSkill();
};

struct FUN_0097fc70_shell
{
    int FUN_0097fc70();
};

// @fnv 0x0097fc70
int FUN_0097fc70_shell::FUN_0097fc70()
{
    int iresult = 0;
    Creature* pcreature;

    if (!((Actor*)((TESAmmoInitCalls*)this)->FUN_0097ae90())->Method21c())
    {
        if (FUN_007031c0((int)this))
        {
            iresult = ((ActorValueOwner*)(((TESAmmoInitCalls*)this)->FUN_0097ae90() + 0xa4))
                          ->GetActorValueAsInteger(((MiddleHighProcess*)FUN_007031c0((int)this))->GetWeaponForm());
        }
        else
        {
            iresult =
                ((ActorValueOwner*)(((TESAmmoInitCalls*)this)->FUN_0097ae90() + 0xa4))->GetActorValueAsInteger(0x2d);
        }
    }
    else
    {
        pcreature = dynamic_cast<Creature*>((Actor*)((TESAmmoInitCalls*)this)->FUN_0097ae90());
        if (pcreature)
        {
            iresult = (int)pcreature->GetWeaponSkill();
        }
    }

    return iresult;
}

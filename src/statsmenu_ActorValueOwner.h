// Private declaration copy; original: relay_work/queue/queue058/01_fallout_interface_menus_statsmenu_cpp/include/ActorValueOwner.h
// Source layout: ActorValueOwner. PC corrections are in generate_headers.py.
#ifndef FNV_ACTORVALUEOWNER_H
#define FNV_ACTORVALUEOWNER_H

#include "statsmenu_layout_support.h"
class ActorValueOwner
{
  public:
    virtual int GetBaseActorValue(ActorValue::Index actorValue);
    virtual float GetBaseActorValueFloat(ActorValue::Index actorValue);
    virtual int GetActorValue(ActorValue::Index actorValue);
    virtual float GetCurrentActorValue(ActorValue::Index actorValue);
    virtual float GetPermanentActorValueFloat(ActorValue::Index actorValue);
    virtual float GetTemporaryActorValue(ActorValue::Index actorValue);
    virtual float GetDamageActorValue(ActorValue::Index actorValue);
    virtual int GetPermanentActorValue(ActorValue::Index actorValue);
    virtual float GetPermanentActorValueAdjustment(ActorValue::Index actorValue);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    Actor* GetActorOwner();
    int GetClampedActorValueI(ActorValue::Index value);
};
FNV_STATIC_ASSERT(sizeof(ActorValueOwner) == 0x4);
#endif


// src/fallout/audio/falloutradio_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00835be0: the skeleton of src/fallout/audio/falloutradio.cpp
// that unit declares it this way.

#include "falloutradio_private_decls_decl_falloutradio.h"

class BGSTalkingActivator : public TESForm
{
};
class DialogueResponse;
class TESTopicInfo;
class TESQuest;
class DialogueItem
{
  public:
    BSSimpleList<DialogueResponse*> responses;
    BSSimpleList<DialogueResponse*>* current;
    TESTopicInfo* info;
    TESTopic* topic;
    TESQuest* quest;
    TESObjectREFR* speaker;
    bool FUN_0083c7b0();
};
class Conversation
{
  public:
    BSSimpleList<DialogueItem*> items;
    BSSimpleList<DialogueItem*>* current;
    bool FUN_0083b9f0();
    void FUN_0083c470();
    bool FUN_0083b9a0();
    DialogueItem* FUN_0083c820();
    ~Conversation();
};
class TESTopic;
TESTopic* GetTopicSubTypeName(int, int);
FalloutRadio::RadioStationState* CreateRadioStationState(BGSTalkingActivator*, bool);
void FUN_00834260(FalloutRadio::RadioStationState*);
void AdvanceConversation(FalloutRadio::RadioStationState*, TESTopic*);
bool FUN_00833ce0();
void FUN_008304a0();
void FUN_008304c0();
class ATM
{
  public:
    void Enter(const char*);
    void FUN_004538c0();
};
extern ATM g_011dd5e8;
class BSAudio
{
  public:
    unsigned int GetSynchTime();
};
BSAudio* FUN_00453a70();
// @fnv 0x00835be0
void FUN_00835be0(BGSTalkingActivator* form, TESTopic* topic)
{
    TESTopic* a = 0;
    FalloutRadio::RadioStationState* station = 0;
    if (DAT_011dd436)
        return;
    BSSimpleList<FalloutRadio::RadioStationState*>* entries = &DAT_011dd554;
    while (entries && entries->GetItem())
    {
        if (entries->GetItem()->form == form)
        {
            station = entries->GetItem();
            break;
        }
        entries = entries->GetNext();
    }
    if (!station)
        station = CreateRadioStationState(form, false);
    a = topic ? topic : GetTopicSubTypeName(7, 0);
    if (!station || station->form->FUN_00440da0())
        return;
    bool f = station->station.IsFlag20Set();
    g_011dd5e8.Enter("FalloutRadio::StartRadioConversation");
    if (station->station.conversation)
        while (station->station.conversation->FUN_0083b9f0())
        {
        }
    if (station->station.FUN_00833be0())
    {
        station->station.FUN_00833100(false);
        station->station.state = 1;
        FUN_00834260(station);
    }
    if (DAT_011dd42c == station && DAT_011dd434)
    {
        DAT_011dd5bc.Stop();
        DAT_011dd5bc.Release();
        if (FUN_00833ce0())
        {
            FUN_008304a0();
            FUN_008325a0(true);
            FalloutAudioMedia::PlayMedia(MEDIATYPE_RADIO, 0, 1000, false, false, 0.0f, 0);
            FUN_008304c0();
        }
    }
    BSSimpleList<FalloutRadio::RadioReceiver*>* b = &station->receivers;
    while (b && b->GetItem())
    {
        FalloutRadio::RadioReceiver* receiver = b->GetItem();
        receiver->sound.Stop();
        receiver->sound.Release();
        b = b->GetNext();
    }
    AdvanceConversation(station, a);
    station->station.state = 0;
    station->station.conversation->FUN_0083c470();
    station->station.conversation->FUN_0083b9a0();
    if (!station->station.conversation->FUN_0083c820())
    {
        delete station->station.conversation;
        station->station.conversation = 0;
        station->station.state = 1;
    }
    else
    {
        if (DAT_011dd42c == station && DAT_011dd434)
        {
            DAT_011dd5bc.Stop();
            DAT_011dd5bc.Release();
            if (FUN_00833ce0())
            {
                FUN_008304a0();
                FUN_008325a0(true);
                FalloutAudioMedia::PlayMedia(MEDIATYPE_RADIO, 0, 1000, false, false, 0.0f, 0);
                FUN_008304c0();
            }
        }
        station->station.conversation->FUN_0083c820()->FUN_0083c7b0();
    }
    if (station->station.state > 1)
        station->station.state = 0;
    station->station.nextUpdate = FUN_00453a70()->GetSynchTime() + 50;
    station->station.SetFlag80(true);
    station->station.FUN_00833100(f);
    g_011dd5e8.FUN_004538c0();
}

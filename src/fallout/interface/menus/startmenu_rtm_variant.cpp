// src/fallout/interface/menus/startmenu_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/interface/menus/startmenu.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "startmenu_packet.h"
void FUN_007d1b30();
float FUN_007d1d00(int type);
void FUN_007d30d0();

#include <string.h>
#include <stdio.h>
struct MainMenuDeletable
{
    virtual ~MainMenuDeletable();
};
struct MainMenuAudioAccess
{
    void FUN_00ad84e0(int, bool);
};
BSAudio* __cdecl FUN_00453a70();
struct MainMenuResetAccess
{
    void FUN_007d0b90();
};
struct MainMenuWorldAccess
{
    void ShowLoadingMenu(int, int, int);
};
struct MainMenuPlayerAccess
{
    int GetMediaLocationController();
};
class TES;
void __cdecl PlayAudioMedia(int, const char*, unsigned int, bool, bool, float, unsigned int);
void __cdecl FUN_008304c0();
void __cdecl FUN_00703610();
void __cdecl FUN_00706320(int);
void __cdecl FUN_00761460(bool);
void __cdecl ResetTaskQueueGlobals();
BGSSaveLoadUI* __cdecl FUN_00a25920();
extern StartMenu* DAT_011daac0;
extern bool DAT_011daacd;
extern OSGlobals* g_osGlobals;
extern TES* g_TES;
struct PC7d;
extern PC7d* g_thePlayer;

// @fnv 0x007d0a70
void FUN_007d0a70()
{
    char acMusicPath[64];
    delete (MainMenuDeletable*)DAT_011daac0;
    FUN_00703610();
    FUN_00706320(0);
    ((MainMenuAudioAccess*)FUN_00453a70())->FUN_00ad84e0(-1, false);
    ResetTaskQueueGlobals();
    {
        int bIsChild = ((MainMenuPlayerAccess*)g_thePlayer)->GetMediaLocationController();
        bIsChild = 0;
    }
    if (FUN_00a25920())
    {
        FUN_00a25920()->FUN_007d0bd0(false);
        FUN_00a25920()->FUN_007d0bb0();
    }
    DAT_011daacd = true;
    ((MainMenuResetAccess*)g_osGlobals)->FUN_007d0b90();
    ((MainMenuWorldAccess*)g_TES)->ShowLoadingMenu(1, 0, 0);
    memset(acMusicPath, 0, 64);
    sprintf_s(acMusicPath, 64, "Data\\Music\\Special\\MainTitle.mp3");
    FUN_00761460(true);
    PlayAudioMedia(8, acMusicPath, 5000, true, true, 0.0f, 0);
    FUN_008304c0();
}

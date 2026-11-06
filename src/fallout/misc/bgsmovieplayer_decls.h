// fallout/misc/bgsmovieplayer_decls.h: declares Direct3DDeviceInterface, NiRenderer, BSAudio, OSGlobals, BGSMoviePlayer
#ifndef FNV_BGSMOVIEPLAYER_DECLS_H
#define FNV_BGSMOVIEPLAYER_DECLS_H


class Direct3DDeviceInterface
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual int __stdcall TestCooperativeLevel();
};

class NiRenderer
{
  public:
    void StartScene();
    void FinishScene();
    Direct3DDeviceInterface* FUN_004dc020();
    int FUN_004e9530();
    char _pdbpad_1[7];
    char m_spAccum_pad7_pad7[4];
    void* m_pCamera;
    void* m_pActiveRenderTargetGroup;
    char m_acRendererDataB[4];
    char _pdbpad_18[104];
    char m_acRendererDataC[128];
    char m_acRendererDataD[128];
    char m_acRendererDataE[128];
    int m_iRendererState;
    unsigned int m_uiRendererFlags;
    bool m_bRendererFlagA;
    bool m_bRendererFlagB;
    char _pdbpad_20a[118];
};

NiRenderer* FUN_004bc3f0();
NiRenderer* FUN_0043c4b0();

class BSAudio
{
  public:
    bool FUN_005bb4d0();
    void FUN_007eb8a0();
    void SetUseMultipleThreads(bool);
    void Update(bool);
    void DisableAudioPlayback();
};

BSAudio* FUN_00453a70();
extern unsigned char DAT_011de714;

bool FUN_004de070();
bool FUN_004de080();
float FUN_004de0e0();
float FUN_004de0f0();
unsigned int FUN_004dc1f0();
unsigned int FUN_004dc200();

class HotkeyWheelDisplay;

class HotkeyWheelDisplay
{
  public:
    void FUN_00a23010();
    int SetHotkeyItem(unsigned int, bool);
};

class OSGlobals
{
  public:
    unsigned int GetUptimeMilliseconds();
    HotkeyWheelDisplay* FUN_00877720();
};

extern OSGlobals* g_osGlobals;

class BGSMoviePlayer
{
  public:
    unsigned char layout_00[0x20];
    unsigned char field_20;

    Direct3DDeviceInterface* GetDevice();
    void StartScene();
    void FinishScene();
    void BeginMoviePlayback();
    void EndMoviePlayback();
    unsigned int GetUptimeMilliseconds();
    unsigned int UpdateInterfaceState();
    unsigned int GetScreenWidthOverride();
    unsigned int GetFirstInterfaceFloat();
    bool IsDeviceReady();
    bool CheckContinuePlaying(bool);
    bool FUN_00ec17c0();
    void FUN_00ec29b0();
    bool UpdateMoviePlayback(bool);
};

#endif

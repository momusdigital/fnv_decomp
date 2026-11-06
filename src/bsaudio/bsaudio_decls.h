// bsaudio/bsaudio_decls.h: declares BSAudio, BSAudioListener, BSAudioThreadState, BSAudioMemContext, BSAudioManager
#ifndef FNV_BSAUDIO_WORKER_DECLS_H
#define FNV_BSAUDIO_WORKER_DECLS_H


#include "layout_support.h"
#include "BSAudioSyncTimer.h"
#include "NiPoint3.h"

class BSAudioListener;

#pragma pack(push, 4)
class BSAudio
{
  public:
    void** m_ppVirtualMethodTable;
    bool m_bAudioEnabled;
    bool bInitialized;
    bool m_bUseMultipleThreads;
    unsigned char layoutPadding7[1];
    unsigned int m_uiAudioFlags;
    bool m_bAudioOutputPaused;
    unsigned char layoutPaddingD[3];
    BSAudioListener* m_pAudioListener;
    BSAudioSyncTimer m_kAudioBackendData;
    void* m_pfnReadAudioData;
    void* m_pfnReadAudioFile;
    void* m_pfnIsAudioFileAvailable;
    void* m_pfnGetSoundHandleValue;
    void* m_pfnInitializeAudio;
    void* m_pfnShutdownAudio;

    void SetAudioState(unsigned int);
    static void EnableAudio();
    static void DeactivateAudio();
    float GetMusicVolume();
    void DisableAudioPlayback();
    void SetListenerPosition(NiPoint3);
    void SetAudioProperty(unsigned int, unsigned int, unsigned int);

    void Update(bool);
    void SetUseMultipleThreads(bool);
    void Precache(char*, unsigned int);

    float GetMasterVolume();
    float FUN_00ad7a20();
    float FUN_00ad7a50();
    float FUN_00ad7a80();
    float FUN_00ad7ab0();
    float FUN_00ad7c80();
    bool IsAudioUnderwater();
    void FUN_00ad7990(bool);
    void FUN_00ad7940(NiPoint3, NiPoint3);
    void FUN_00ad79b0(unsigned int);
    void FUN_00ad77f0(float, unsigned int);
    void FUN_00ad8100(unsigned int, unsigned int, unsigned int);
    void ForwardToManager(unsigned int, unsigned int);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSAudio) == 0x38);

// BSAudioListener interface. Only the vtable slots this unit forwards to are
// declared; the remaining slots keep their ordinal names so the introducing
// virtuals line up with the deployed PC vtable.
class BSAudioListener
{
  public:
    void** m_ppVirtualMethodTable;
    NiPoint3 m_kListenerPosition;    // +0x4
    NiPoint3 m_kListenerVelocity;    // +0x10
    NiPoint3 m_kForward;             // +0x1c
    NiPoint3 m_kUp;                  // +0x28
    unsigned int m_uiListenerID;     // +0x34
    float m_fGain;                   // +0x38
    float m_fDopplerScale;           // +0x3c
    float m_fDistanceScale;          // +0x40
    unsigned int m_uiListenerFlags;  // +0x44

    virtual void vfn_0(bool doFree);                      // +0x00
    virtual void vfn_4();                                 // +0x04
    virtual void vfn_8(NiPoint3* pos);                    // +0x08
    virtual void vfn_c();                                 // +0x0c
    virtual void vfn_10();                                // +0x10
    virtual void vfn_14(NiPoint3* front, NiPoint3* top);  // +0x14
    virtual void vfn_18();                                // +0x18
    virtual void vfn_1c();                                // +0x1c
    virtual void vfn_20(NiPoint3* velocity);              // +0x20
    virtual void vfn_24();                                // +0x24
    virtual void vfn_28(unsigned int value);              // +0x28
    virtual void vfn_2c();                                // +0x2c
    virtual void vfn_30(float factor);                    // +0x30

    void SetListenerID(unsigned int);
    unsigned int GetListenerID();
};

// Per-thread allocator bookkeeping. The tracker keeps the active memory context
// in the thread-local block of the engine module; the block sits behind a long
// run of other thread-local objects, so only its tail is this unit's.
struct BSAudioThreadState
{
    unsigned char precedingThreadState[0x2b4];
    int m_uiMemoryContext;
};

extern "C" volatile unsigned int _tls_index;
extern "C" unsigned long __readfsdword(unsigned long);

__forceinline BSAudioThreadState* BSAudioGetThreadState()
{
    unsigned int index = _tls_index;
    return reinterpret_cast<BSAudioThreadState**>(__readfsdword(0x2c))[index];
}

// RAII swap of the running memory context onto the audio context. The previous
// context is restored by the destructor, which /EHsc runs on every path out of
// the guarded scope, so the swap survives the early returns below.
class BSAudioMemContext
{
  public:
    int previous;
    __forceinline BSAudioMemContext(MEM_CONTEXT m_uiMemoryContext)
        : previous(BSAudioGetThreadState()->m_uiMemoryContext)
    {
        BSAudioGetThreadState()->m_uiMemoryContext = m_uiMemoryContext;
    }
    __forceinline ~BSAudioMemContext()
    {
        BSAudioGetThreadState()->m_uiMemoryContext = previous;
    }
};

// the PC runtime corrections already applied by the accepted unit; only the
// tail this unit forwards to is spelled out.
class BSAudioManager
{
  public:
    unsigned char layoutPadding0[0x140];
    float fMasterVolume;                 // +0x140
    float m_fVolumeSetting1;             // +0x144
    float m_fVolumeSetting2;             // +0x148
    float m_fVolumeSetting3;             // +0x14c
    float m_fVolumeSetting4;             // +0x150
    float m_fVolumeSetting5;             // +0x154
    float m_fVolumeSetting6;             // +0x158
    float m_fVolumeSetting7;             // +0x15c
    float m_fVolumeSetting8;             // +0x160
    float m_fVolumeSetting9;             // +0x164
    float m_fVolumeSetting10;            // +0x168
    float m_fVolumeSetting11;            // +0x16c
    unsigned int m_uiAudioManagerFlags;  // +0x170
    bool m_bAudioPaused;                 // +0x174
    bool m_bUnderwater;                  // +0x175

    static BSAudioManager& GetRandomGenerator();
    void DisableAudioPlayback(unsigned int, bool);
    void SetAudioSettingValue(unsigned int, unsigned int, unsigned int);
    void SetListenerPosition(NiPoint3);
    bool FUN_00adbf50(unsigned int);

    void Update(bool);
    void StartAudioThreads();
    void StopAudioThreads();
    void FUN_00add570(char*, unsigned int);
    void FUN_00add630(unsigned int, unsigned int);
    void FUN_00add6f0(unsigned int, unsigned int, unsigned int);
    void FUN_00ad9f30();
    void FUN_00ada300(float, unsigned int);
    void FUN_00adeff0(bool);
};

class SoundPlaybackHandle
{
  public:
    unsigned int uiSoundID;
    bool Release();
};

extern "C"
{
    extern unsigned char DAT_011dcfa4;
}

#endif

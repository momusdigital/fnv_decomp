// bsaudio/bsaudio.cpp: BSAudio, AudioUpdateStand, Owner (65 functions)

#include "bsaudio_decls.h"

// @fnv 0x00ad8780
void BSAudio::SetAudioState(unsigned int argument0)
{}

// @fnv 0x00762150
void BSAudio::EnableAudio()
{
    DAT_011dcfa4 = 1;
}

// @fnv 0x007624c0
void BSAudio::DeactivateAudio()
{
    DAT_011dcfa4 = 0;
}

// @fnv 0x007ec380
void BSAudio::DisableAudioPlayback()
{
    reinterpret_cast<BSAudioManager*>(this)->DisableAudioPlayback(0x3002, false);
}

// @fnv 0x00ad7ae0
float BSAudio::GetMusicVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->m_fVolumeSetting5;
    return volume;
}

// @fnv 0x00ad8480
void BSAudio::SetAudioProperty(unsigned int type, unsigned int flags, unsigned int value)
{
    BSAudioManager::GetRandomGenerator().SetAudioSettingValue(type, flags, value);
}

// @fnv 0x00ad78b0
void BSAudio::SetListenerPosition(NiPoint3 position)
{
    BSAudioManager::GetRandomGenerator().SetListenerPosition(position);
}

// @fnv 0x00ad8d10
bool SoundPlaybackHandle::Release()
{
    if (uiSoundID == 0xffffffff)
    {
        return false;
    }

    bool released = BSAudioManager::GetRandomGenerator().FUN_00adbf50(uiSoundID);
    if (released)
    {
        uiSoundID = 0xffffffff;
    }
    return released;
}

// @fnv 0x00ad79f0
float BSAudio::GetMasterVolume()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->fMasterVolume;
    return volume;
}

// @fnv 0x00ad7a20
float BSAudio::FUN_00ad7a20()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->m_fVolumeSetting1;
    return volume;
}

// @fnv 0x00ad7a50
float BSAudio::FUN_00ad7a50()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->m_fVolumeSetting2;
    return volume;
}

// @fnv 0x00ad7a80
float BSAudio::FUN_00ad7a80()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->m_fVolumeSetting3;
    return volume;
}

// @fnv 0x00ad7ab0
float BSAudio::FUN_00ad7ab0()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->m_fVolumeSetting4;
    return volume;
}

// @fnv 0x00ad7c80
float BSAudio::FUN_00ad7c80()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    float volume = manager->m_fVolumeSetting6;
    return volume;
}

// @fnv 0x00ad7c50
bool BSAudio::IsAudioUnderwater()
{
    BSAudioManager* manager = &BSAudioManager::GetRandomGenerator();
    bool underwater = manager->m_bUnderwater;
    return underwater;
}

// @fnv 0x00ad7990
void BSAudio::FUN_00ad7990(bool value)
{
    BSAudioManager::GetRandomGenerator().FUN_00adeff0(value);
}

// @fnv 0x00ad79b0
void BSAudio::FUN_00ad79b0(unsigned int value)
{
    if (m_pAudioListener)
    {
        m_pAudioListener->vfn_28(value);
    }
}

// @fnv 0x00ad7940
void BSAudio::FUN_00ad7940(NiPoint3 front, NiPoint3 top)
{
    if (m_pAudioListener)
    {
        m_pAudioListener->vfn_14(&front, &top);
    }
}

// @fnv 0x00ad7740
void BSAudio::Update(bool flag)
{
    BSAudioMemContext m_uiMemoryContext(MEM_CONTEXT_MEM_CONTEXT_AUDIO);
    BSAudioManager::GetRandomGenerator().Update(flag);
}

// @fnv 0x00ad7fa0
void BSAudio::Precache(char* file, unsigned int size)
{
    BSAudioMemContext m_uiMemoryContext(MEM_CONTEXT_MEM_CONTEXT_AUDIO);
    BSAudioManager::GetRandomGenerator().FUN_00add570(file, size);
}

// @fnv 0x00ad77f0
void BSAudio::FUN_00ad77f0(float value, unsigned int flags)
{
    BSAudioMemContext m_uiMemoryContext(MEM_CONTEXT_MEM_CONTEXT_AUDIO);
    BSAudioManager::GetRandomGenerator().FUN_00ada300(value, flags);
}

// @fnv 0x00ad8100
void BSAudio::FUN_00ad8100(unsigned int type, unsigned int flags, unsigned int value)
{
    BSAudioMemContext m_uiMemoryContext(MEM_CONTEXT_MEM_CONTEXT_AUDIO);
    BSAudioManager::GetRandomGenerator().FUN_00add6f0(type, flags, value);
}

// @fnv 0x00ad8050
void BSAudio::ForwardToManager(unsigned int type, unsigned int value)
{
    BSAudioMemContext m_uiMemoryContext(MEM_CONTEXT_MEM_CONTEXT_AUDIO);
    BSAudioManager::GetRandomGenerator().FUN_00add630(type, value);
}

struct FUN_00ad8740_shell : public BSAudio
{
    void FUN_00ad8740();
};

// Calls the callback at offset 0x34 if set, then clears bit 0 of the flags at offset 0x1c.
// @fnv 0x00ad8740
void FUN_00ad8740_shell::FUN_00ad8740()
{
    if (*reinterpret_cast<void (**)()>(reinterpret_cast<char*>(this) + 0x34))
    {
        (*reinterpret_cast<void (**)()>(reinterpret_cast<char*>(this) + 0x34))();
    }
    char* p = reinterpret_cast<char*>(this) + 0x14;
    *reinterpret_cast<unsigned int*>(p + 8) &= ~1u;
}

struct TLSPad_00ad7740
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSPad_00ad7740 g_tls_00ad7740;
struct MemCtxGuard_00ad7740
{
    int saved;
    __forceinline MemCtxGuard_00ad7740(int v)
    {
        int t = g_tls_00ad7740.memContext;
        saved = t;
        g_tls_00ad7740.memContext = v;
    }
    __forceinline ~MemCtxGuard_00ad7740()
    {
        int t = saved;
        g_tls_00ad7740.memContext = t;
    }
};
struct AudioUpdateStand
{
    void FUN_00ad7740(bool abFlag);
};
// Sets the thread-local memory context to 0xb for the duration of the call, then forwards abFlag to BSAudioManager::Update.
// @fnv 0x00ad7740
void AudioUpdateStand::FUN_00ad7740(bool abFlag)
{
    MemCtxGuard_00ad7740 guard(0xb);
    BSAudioManager::GetRandomGenerator().Update(abFlag);
}

namespace fnv_00ad7fa0 {
struct TLSPad_00ad7740
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSPad_00ad7740 g_tls_00ad7740;
struct MemCtxGuard_00ad7740
{
    int saved;
    __forceinline MemCtxGuard_00ad7740(int v)
    {
        int t = g_tls_00ad7740.memContext;
        saved = t;
        g_tls_00ad7740.memContext = v;
    }
    __forceinline ~MemCtxGuard_00ad7740()
    {
        int t = saved;
        g_tls_00ad7740.memContext = t;
    }
};
struct AudioUpdateStand
{
    void FUN_00ad7fa0(char* apName, unsigned int aiFlag);
};
// @fnv 0x00ad7fa0
void AudioUpdateStand::FUN_00ad7fa0(char* apName, unsigned int aiFlag)
{
    MemCtxGuard_00ad7740 guard(0xb);
    BSAudioManager::GetRandomGenerator().FUN_00add570(apName, aiFlag);
}
}  // namespace fnv_00ad7fa0

struct FUN_0083b8d0_stub
{
    void FUN_0083b8d0();
};
struct FUN_00798450_shell
{
    void* FUN_00798450(unsigned int flags);
};
// Calls FUN_0083b8d0 on this, deletes this when flags has bit 1 set, and returns this.
// @fnv 0x00798450
void* FUN_00798450_shell::FUN_00798450(unsigned int flags)
{
    ((FUN_0083b8d0_stub*)this)->FUN_0083b8d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct TESResponse
{
    int GetNext();
};
struct Tile
{
    void Set(int, float, bool);
};
void* __cdecl FUN_004b7210();
extern int DAT_011da9a4;
// If DAT_011da9a4 is set, stores 7 at offset 0x28 and calls Set(0xfa9, 255.0f, true) on the next TESResponse tile.
// @fnv 0x007c2420
void FUN_007c2420()
{
    if (DAT_011da9a4)
    {
        *(int*)(DAT_011da9a4 + 0x28) = 7;
        ((Tile*)((TESResponse*)FUN_004b7210())->GetNext())->Set(0xfa9, 255.0f, true);
    }
}

struct FUN_00aa4a50_shell2
{
    void FUN_00aa4a50(int a);
};
// @fnv 0x00aa4a50
void FUN_00aa4a50_shell2::FUN_00aa4a50(int a)
{}

__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ada0f0_stub
{
    void FUN_00ada0f0();
};
struct FUN_00ad9870_stub
{
    void FUN_00ad9870();
};
struct FUN_00ad7150_shell
{
    char pad[4];
    bool bActive;
    bool bFlag5;
    bool bFlag6;
    bool IsActive()
    {
        return bActive;
    }
    void FUN_00ad7150();
};
// If the object is active, optionally calls FUN_00ada0f0, clears bFlag5 and calls FUN_00ad9870, all under an AudioThreadModeScope.
// @fnv 0x00ad7150
void FUN_00ad7150_shell::FUN_00ad7150()
{
    AudioThreadModeScope scope;
    if (IsActive())
    {
        if (bFlag6)
            ((FUN_00ada0f0_stub*)&BSAudioManager::GetRandomGenerator())->FUN_00ada0f0();
        bFlag5 = false;
        ((FUN_00ad9870_stub*)&BSAudioManager::GetRandomGenerator())->FUN_00ad9870();
    }
}

struct FUN_00ad78e0_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual const NiPoint3* v3();
};
extern NiPoint3 _NiPoint3_ZERO;
struct FUN_00ad78e0_shell
{
    FUN_00ad78e0_obj* pObj;
    int pad[3];
};
struct FUN_00ad78e0_cls
{
    char pad[0x10];
    FUN_00ad78e0_obj* pObj;
    NiPoint3 FUN_00ad78e0();
};
// @fnv 0x00ad78e0
NiPoint3 FUN_00ad78e0_cls::FUN_00ad78e0()
{
    const NiPoint3* p = pObj ? pObj->v3() : &_NiPoint3_ZERO;
    return *p;
}

void __fastcall FUN_00adc160(void*);

// Sets BSAudioManager's master volume to f and calls FUN_00adc160 with the manager.
// @fnv 0x00ad7b10
void __fastcall SetMasterVolume(float afVolume, int)
{
    BSAudioManager& mgr = BSAudioManager::GetRandomGenerator();
    mgr.fMasterVolume = afVolume;
    FUN_00adc160(&mgr);
}

struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7b40
{
    void Set(float value);
};

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7b40
void FUN_00ad7b40::Set(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->m_fVolumeSetting1 = value;
    reinterpret_cast<AudioStub*>(mgr)->FUN_00adc160();
}

struct FUN_00adc160_shell
{
    void __thiscall FUN_00adc160();
};

// @fnv 0x00ad7b70
void __fastcall FUN_00ad7b70(void* thisPtr, float m_fVolumeSetting2)
{
    BSAudioManager& instance = BSAudioManager::GetRandomGenerator();
    instance.m_fVolumeSetting2 = m_fVolumeSetting2;
    ((FUN_00adc160_shell*)&instance)->FUN_00adc160();
}

namespace fnv_00ad7ba0 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7ba0
{
    void Set(float value);
};

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7ba0
void FUN_00ad7ba0::Set(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->m_fVolumeSetting3 = value;
    reinterpret_cast<AudioStub*>(mgr)->FUN_00adc160();
}
}  // namespace fnv_00ad7ba0

namespace fnv_00ad7bd0 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7bd0
{
    void Set(float value);
};

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7bd0
void FUN_00ad7bd0::Set(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->m_fVolumeSetting4 = value;
    reinterpret_cast<AudioStub*>(mgr)->FUN_00adc160();
}
}  // namespace fnv_00ad7bd0

namespace fnv_00ad7c00 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7c00
{
    void Set(float value);
};

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7c00
void FUN_00ad7c00::Set(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->m_fVolumeSetting5 = value;
    reinterpret_cast<AudioStub*>(mgr)->FUN_00adc160();
}
}  // namespace fnv_00ad7c00

void __fastcall FUN_00adc160(BSAudioManager* m);
struct FUN_00ad7c30_shell2
{
    void FUN_00ad7c30();
};
// @fnv 0x00ad7c30
void FUN_00ad7c30_shell2::FUN_00ad7c30()
{
    FUN_00adc160(&BSAudioManager::GetRandomGenerator());
}

struct FUN_00ad7cb0_shell2
{
    float FUN_00ad7cb0();
};
// Reads the float at offset 0x15c of the BSAudioManager singleton and returns it.
// @fnv 0x00ad7cb0
float FUN_00ad7cb0_shell2::FUN_00ad7cb0()
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float val = *(float*)((char*)mgr + 0x15c);
    return val;
}

struct FUN_00ad7ce0
{
    float Get();
};

// @fnv 0x00ad7ce0
float FUN_00ad7ce0::Get()
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->m_fVolumeSetting8;
    return result;
}

struct FUN_00ad7d10
{
    float Get();
};

// @fnv 0x00ad7d10
float FUN_00ad7d10::Get()
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->m_fVolumeSetting9;
    return result;
}

struct FUN_00ad7d40
{
    float Get();
};

// @fnv 0x00ad7d40
float FUN_00ad7d40::Get()
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->m_fVolumeSetting10;
    return result;
}

struct FUN_00ad7d70
{
    float Get();
};

// @fnv 0x00ad7d70
float FUN_00ad7d70::Get()
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    float result = mgr->m_fVolumeSetting11;
    return result;
}

namespace fnv_00ad7da0 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7da0
{
    void Set(float value);
};

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7da0
void FUN_00ad7da0::Set(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->m_fVolumeSetting6 = value;
    reinterpret_cast<AudioStub*>(mgr)->FUN_00adc160();
}
}  // namespace fnv_00ad7da0

namespace fnv_00ad7dd0 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7dd0
{
    void Set(float value);
};

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7dd0
void FUN_00ad7dd0::Set(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->m_fVolumeSetting7 = value;
    reinterpret_cast<AudioStub*>(mgr)->FUN_00adc160();
}
}  // namespace fnv_00ad7dd0

namespace fnv_00ad7e00 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7e00
{
    void Set(float value);
};

// Stores value into the audio manager's field and then calls FUN_00adc160 on it.
// @fnv 0x00ad7e00
void FUN_00ad7e00::Set(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->m_fVolumeSetting8 = value;
    reinterpret_cast<AudioStub*>(mgr)->FUN_00adc160();
}
}  // namespace fnv_00ad7e00

namespace fnv_00ad7e30 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7e30
{
    void Set(float value);
};

// Stores value into the audio manager's field and calls FUN_00adc160 on it.
// @fnv 0x00ad7e30
void FUN_00ad7e30::Set(float value)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->m_fVolumeSetting9 = value;
    reinterpret_cast<AudioStub*>(mgr)->FUN_00adc160();
}
}  // namespace fnv_00ad7e30

void __fastcall FUN_00adc160(BSAudioManager*);
struct FUN_00ad7e60_shell
{
    void FUN_00ad7e60(float v);
};
// @fnv 0x00ad7e60
void FUN_00ad7e60_shell::FUN_00ad7e60(float v)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->m_fVolumeSetting10 = v;
    FUN_00adc160(mgr);
}

void __fastcall FUN_00adc160(BSAudioManager*);
struct FUN_00ad7e90_shell
{
    void FUN_00ad7e90(float v);
};
// @fnv 0x00ad7e90
void FUN_00ad7e90_shell::FUN_00ad7e90(float v)
{
    BSAudioManager* mgr = &BSAudioManager::GetRandomGenerator();
    mgr->m_fVolumeSetting11 = v;
    FUN_00adc160(mgr);
}

void __fastcall FUN_00ad87d0(BSAudioManager* m);
struct FUN_00ad7ec0_shell2
{
    void FUN_00ad7ec0();
};
// @fnv 0x00ad7ec0
void FUN_00ad7ec0_shell2::FUN_00ad7ec0()
{
    FUN_00ad87d0(&BSAudioManager::GetRandomGenerator());
}

namespace fnv_00ad7ee0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ae5ff0_stub
{
    int FUN_00ae5ff0(unsigned int);
};
struct FUN_00ad7ee0_shell
{
    int FUN_00ad7ee0(unsigned int n);
};
// Saves the current audio thread mode, sets it to 11 for the duration of the call, then restores it and returns the result of FUN_00ae5ff0(n).
// @fnv 0x00ad7ee0
int FUN_00ad7ee0_shell::FUN_00ad7ee0(unsigned int n)
{
    AudioThreadModeScope scope;
    return ((FUN_00ae5ff0_stub*)&BSAudioManager::GetRandomGenerator())->FUN_00ae5ff0(n);
}
}  // namespace fnv_00ad7ee0

namespace fnv_00ad81c0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ae6bf0_stub
{
    void SetAudioCacheSize(unsigned int);
};
struct FUN_00ad81c0_shell
{
    void SetAudioThreadModeAndForward(unsigned int n);
};
// Saves the current audio thread mode, sets it to 11 for the scope, and forwards n to SetAudioCacheSize on the BSAudioManager singleton.
// @fnv 0x00ad81c0
void FUN_00ad81c0_shell::SetAudioThreadModeAndForward(unsigned int auiValue)
{
    AudioThreadModeScope scope;
    ((FUN_00ae6bf0_stub*)&BSAudioManager::GetRandomGenerator())->SetAudioCacheSize(auiValue);
}
}  // namespace fnv_00ad81c0

namespace fnv_00ad8270 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ae6c60_stub
{
    int FUN_00ae6c60();
};
struct FUN_00ad8270_shell
{
    int FUN_00ad8270();
};
// @fnv 0x00ad8270
int FUN_00ad8270_shell::FUN_00ad8270()
{
    AudioThreadModeScope scope;
    return ((FUN_00ae6c60_stub*)&BSAudioManager::GetRandomGenerator())->FUN_00ae6c60();
}
}  // namespace fnv_00ad8270

namespace fnv_00ad8320 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ae6ca0_stub
{
    void FUN_00ae6ca0(bool);
};
struct FUN_00ad8320_shell
{
    void FUN_00ad8320(bool b);
};
// Saves the current audio thread mode, sets it to 11 for the duration of the call, then restores it after forwarding b to FUN_00ae6ca0 on the audio manager.
// @fnv 0x00ad8320
void FUN_00ad8320_shell::FUN_00ad8320(bool b)
{
    AudioThreadModeScope scope;
    ((FUN_00ae6ca0_stub*)&BSAudioManager::GetRandomGenerator())->FUN_00ae6ca0(b);
}
}  // namespace fnv_00ad8320

namespace fnv_00ad83d0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ae6cf0_stub
{
    bool FUN_00ae6cf0();
};
struct FUN_00ad83d0_shell
{
    bool FUN_00ad83d0();
};
// @fnv 0x00ad83d0
bool FUN_00ad83d0_shell::FUN_00ad83d0()
{
    AudioThreadModeScope scope;
    return ((FUN_00ae6cf0_stub*)&BSAudioManager::GetRandomGenerator())->FUN_00ae6cf0();
}
}  // namespace fnv_00ad83d0

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00ad7000_stub
{
    void FUN_00ad7000();
};
struct FUN_00ad8790_shell
{
    void* FUN_00ad8790(unsigned int flags);
};
// Calls FUN_00ad7000 on this, deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00ad8790
void* FUN_00ad8790_shell::FUN_00ad8790(unsigned int flags)
{
    ((FUN_00ad7000_stub*)this)->FUN_00ad7000();
    if (flags & 1)
        g_memoryManager.Deallocate(this);
    return this;
}

struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00ad7230_shell : public BSAudio
{
    void FUN_00ad7230(bool);
};

extern __declspec(thread) int iCurrentMemContext;

inline int GetCurrentMemContext()
{
    return iCurrentMemContext;
}
inline void SetCurrentMemContext(int aiContext)
{
    iCurrentMemContext = aiContext;
}

struct MemContextScope
{
    int m_eMemoryContext;
    MemContextScope(int aiContext)
    {
        m_eMemoryContext = GetCurrentMemContext();
        iCurrentMemContext = aiContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(m_eMemoryContext);
    }
};

extern bool DAT_01202800;

struct SettingBool
{
    virtual ~SettingBool();
    bool bValue;
    char* pKey;
    bool& GetBool()
    {
        return this ? bValue : (DAT_01202800 = false);
    }
};

extern SettingBool g_011f6dfc;

struct BSAudioState
{
    virtual ~BSAudioState();
    bool m_bAudioEnabled;
    bool IsAudioEnabled()
    {
        return m_bAudioEnabled;
    }
};

// @fnv 0x00ad7230
void FUN_00ad7230_shell::FUN_00ad7230(bool abUseMultipleThreads)
{
    MemContextScope tempMemContext(11);
    if (!reinterpret_cast<BSAudioState*>(this)->IsAudioEnabled())
    {
        return;
    }
    if (!g_011f6dfc.GetBool() && abUseMultipleThreads)
    {
        return;
    }
    if (abUseMultipleThreads && !*(reinterpret_cast<bool*>(this) + 6))
    {
        BSAudioManager::GetRandomGenerator().StartAudioThreads();
    }
    else if (!abUseMultipleThreads && *(reinterpret_cast<bool*>(this) + 6))
    {
        BSAudioManager::GetRandomGenerator().StopAudioThreads();
    }
    *(reinterpret_cast<bool*>(this) + 6) = abUseMultipleThreads;
}

struct BSAudioSoundHandle
{
    unsigned int uiSoundID;
    bool m_bLooping;
    unsigned int uiState;
    ~BSAudioSoundHandle();
};
struct FUN_00ae5870_t
{
    BSAudioSoundHandle FUN_00ae5870(unsigned int, unsigned int);
};
struct FUN_00ad73b0_t : public BSAudio
{
    BSAudioSoundHandle FUN_00ad73b0(unsigned int, unsigned int);
};
extern __declspec(thread) int BSAudioThreadContext;
__forceinline int BSAudioGetMemContext()
{
    return BSAudioThreadContext;
}
__forceinline void BSAudioSetMemContext(int aiMemoryContext)
{
    BSAudioThreadContext = aiMemoryContext;
}
struct BSAudioScopedMemContext
{
    int m_eMemoryContext;
    __forceinline BSAudioScopedMemContext(int m_iLineNumber) : m_eMemoryContext(BSAudioGetMemContext())
    {
        BSAudioSetMemContext(m_iLineNumber);
    }
    __forceinline ~BSAudioScopedMemContext()
    {
        BSAudioSetMemContext(m_eMemoryContext);
    }
};
// Sets the audio memory context to 11, then forwards the form ID and type flags to the sound manager to create a sound handle.
// @fnv 0x00ad73b0
BSAudioSoundHandle FUN_00ad73b0_t::FUN_00ad73b0(unsigned int aiFormID, unsigned int aiTypeFlags)
{
    BSAudioScopedMemContext tempMemContext(11);
    return reinterpret_cast<FUN_00ae5870_t*>(&BSAudioManager::GetRandomGenerator())->FUN_00ae5870(aiFormID, aiTypeFlags);
}

namespace fnv_00ad7620 {
extern __declspec(thread) int iCurrentMemContext;

inline int GetCurrentMemContext()
{
    return iCurrentMemContext;
}
inline void SetCurrentMemContext(int aiContext)
{
    iCurrentMemContext = aiContext;
}

struct MemContextScope
{
    int m_eMemoryContext;
    MemContextScope(int aiContext)
    {
        m_eMemoryContext = GetCurrentMemContext();
        iCurrentMemContext = aiContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(m_eMemoryContext);
    }
};

struct BSSoundHandleEx
{
    unsigned int uiSoundID;
    bool m_bLooping;
    unsigned int uiState;
    BSSoundHandleEx(const BSSoundHandleEx& rhs)
        : uiSoundID(rhs.uiSoundID), m_bLooping(rhs.m_bLooping), uiState(rhs.uiState)
    {}
    ~BSSoundHandleEx()
    {}
    bool Play(bool);
    bool SetPosition(float, float, float);
};

struct FUN_00ae5870_t
{
    BSSoundHandleEx FUN_00ae5870(unsigned int, unsigned int);
};

struct FUN_00ad7620_t : public BSAudio
{
    BSSoundHandleEx FUN_00ad7620(unsigned int aiFormID, unsigned int aiTypeFlags, NiPoint3 aLoc, unsigned int aiID);
};

// Creates a sound handle for the given form and type flags, positions it at aLoc, starts playback, and returns the handle.
// @fnv 0x00ad7620
BSSoundHandleEx FUN_00ad7620_t::FUN_00ad7620(unsigned int aiFormID, unsigned int aiTypeFlags, NiPoint3 aLoc,
                                             unsigned int aiID)
{
    MemContextScope tempMemContext(11);
    BSSoundHandleEx hndl =
        reinterpret_cast<FUN_00ae5870_t*>(&BSAudioManager::GetRandomGenerator())->FUN_00ae5870(aiFormID, aiTypeFlags);
    hndl.SetPosition(aLoc.x, aLoc.y, aLoc.z);
    hndl.Play(true);
    return hndl;
}
}  // namespace fnv_00ad7620

namespace fnv_00ad77f0 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00ad77f0_shell : public BSAudio
{
    void FUN_00ad77f0(float, unsigned int);
};

struct OH2TlsBlock
{
    char pad[0x2b4];
    int m_iThreadLocalValue;
};
extern __declspec(thread) OH2TlsBlock g_OH2Tls;
struct OH2MemContext
{
    int m_eMemoryContext;
    __forceinline OH2MemContext(int aiContext)
    {
        int iOld = g_OH2Tls.m_iThreadLocalValue;
        m_eMemoryContext = iOld;
        g_OH2Tls.m_iThreadLocalValue = aiContext;
    }
    __forceinline ~OH2MemContext()
    {
        int iOld = m_eMemoryContext;
        g_OH2Tls.m_iThreadLocalValue = iOld;
    }
};
// @fnv 0x00ad77f0
void FUN_00ad77f0_shell::FUN_00ad77f0(float afCurrentGamehour, unsigned int aiWeatherConditions)
{
    OH2MemContext tempMemContext(0xb);
    BSAudioManager::GetRandomGenerator().FUN_00ada300(afCurrentGamehour, aiWeatherConditions);
}
}  // namespace fnv_00ad77f0

class TargetAD79
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void Apply(void* pA, void* pB);
};

template <class T> class NiPointerAD79
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

class FUN_00ad7940_C
{
  public:
    char unk00[0x10];
    NiPointerAD79<TargetAD79> m_spReferencedObject;

    void FUN_00ad7940(int a1, int a2, int a3, int a4, int a5, int a6);
};

// If m_spReferencedObject is set, calls its Apply method with pointers to a1 and a4.
// @fnv 0x00ad7940
void FUN_00ad7940_C::FUN_00ad7940(int a1, int a2, int a3, int a4, int a5, int a6)
{
    if (m_spReferencedObject)
        m_spReferencedObject->Apply(&a1, &a4);
}

struct FUN_00ad79b0_shell : public BSAudio
{
    void FUN_00ad79b0(unsigned int);
};

__forceinline BSAudioListener* BSAudioGetListener(BSAudio* pAudio)
{
    return pAudio->m_pAudioListener;
}
// If a listener is attached, forwards aiEnviroType to the listener's vfn_28 virtual method.
// @fnv 0x00ad79b0
void FUN_00ad79b0_shell::FUN_00ad79b0(unsigned int aiEnviroType)
{
    if (BSAudioGetListener(this))
    {
        BSAudioGetListener(this)->vfn_28(aiEnviroType);
    }
}

namespace sad7c50 {

struct Settings
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    unsigned char unk174;
    bool m_bEnableState;

    bool IsEnabled()
    {
        return m_bEnableState;
    }
};

Settings* FUN_00ad9060();

struct Owner
{
    bool IsAudioUnderwater();
};

// Returns whether the global settings object is enabled by calling IsEnabled on the Settings instance from FUN_00ad9060.
// @fnv 0x00ad7c50
bool Owner::IsAudioUnderwater()
{
    Settings* pkSettings = FUN_00ad9060();
    return pkSettings->IsEnabled();
}

}

extern __declspec(thread) int g_tlsMemContext;

namespace sad8050 {

struct MemContextGuard
{
    int m_iPrevious;

    MemContextGuard(int aiMemoryContext)
    {
        int iPrevious = g_tlsMemContext;
        m_iPrevious = iPrevious;
        g_tlsMemContext = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        int iPrevious = m_iPrevious;
        g_tlsMemContext = iPrevious;
    }
};

struct Manager
{
    void FUN_00add630(int iArg0, int iArg1);
};

Manager* FUN_00ad9060();

struct Owner
{
    void ForwardToManager(int iArg0, int iArg1);
};

// Sets the thread memory context to 0xb and forwards iArg0 and iArg1 to FUN_00add630 on the Manager returned by FUN_00ad9060.
// @fnv 0x00ad8050
void Owner::ForwardToManager(int iArg0, int iArg1)
{
    MemContextGuard kGuard(0xb);
    FUN_00ad9060()->FUN_00add630(iArg0, iArg1);
}

}

namespace fnv_00ad8100 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00ad8100_shell : public BSAudio
{
    void FUN_00ad8100(char*, unsigned int, void*);
};

struct TLSData
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSData g_tlsData;

static inline int GetCurrentMemContext()
{
    return g_tlsData.memContext;
}

static inline void SetCurrentMemContext(int context)
{
    g_tlsData.memContext = context;
}

struct MemContextScope
{
    int oldContext;
    MemContextScope(int newContext)
    {
        oldContext = GetCurrentMemContext();
        g_tlsData.memContext = newContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(oldContext);
    }
};

// Sets memory context 11 and forwards the sound name, flags, and parameter to BSAudioManager::FUN_00add6f0.
// @fnv 0x00ad8100
void FUN_00ad8100_shell::FUN_00ad8100(char* apSoundName, unsigned int aiFlags, void* apParam)
{
    MemContextScope tempMemContext(11);
    BSAudioManager::GetRandomGenerator().FUN_00add6f0((unsigned int)apSoundName, aiFlags, (unsigned int)apParam);
}
}  // namespace fnv_00ad8100

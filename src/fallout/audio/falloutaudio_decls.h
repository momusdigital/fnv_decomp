// fallout/audio/falloutaudio_decls.h: declares TESForm, NiPoint3, SettingT_GameSettingCollection_, RegionSound, BSAudio and more
#ifndef FALLOUTAUDIO_DECLS_H
#define FALLOUTAUDIO_DECLS_H

#include <stddef.h>
enum ENUM_FORM_ID
{
    FORM_NONE = 0,
    FORM_ONE = 1
};
class TESForm
{
  public:
    virtual void Destroy();
    unsigned int GetFormID();
    void SetFormType(ENUM_FORM_ID);
    static TESForm* GetFormByID(unsigned int);
};
class TESSound;
class BGSAcousticSpace;
class SoundPlaybackHandle;
struct NiPoint3
{
    float x, y, z;
    NiPoint3();
};
union SETTING_VALUE
{
    float f;
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    T& GetItem();
    BSSimpleList* GetNext();
    bool IsEmpty();
    void RemoveHead();
};
struct RegionSound
{
    TESSound* sound;
    unsigned int weatherFlags;
    unsigned int chance;
};
class SoundPlaybackHandle
{
  public:
    unsigned int id;
    bool assumeSuccess;
    int state;
    SoundPlaybackHandle();
    SoundPlaybackHandle(bool);
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle&);
    void FUN_004188d0();
    bool IsPlaying();
    bool IsValid();
    bool Play(bool);
    bool Stop();
    bool Release();
    bool StopWithFade(unsigned int);
    bool SetFadeInTime(unsigned int);
    bool SetPosition(float, float, float);
    void SetPriority(unsigned char);
    void SetFormType(int);
};
class BSAudio
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual const NiPoint3& GetPosition();
    SoundPlaybackHandle GetSoundHandleByEditorID(const char*, unsigned int);
    SoundPlaybackHandle GetSoundHandleByFilePath(const char*, unsigned int, void*);
    void Precache(const char*, unsigned int, void*);
    bool IsAudioUnderwater();
    void FUN_00ad79b0(int);
    void FUN_00ad77f0(float, unsigned int);
    int GetCurrentTimeMilliseconds();
    void* GetAudioBackendData();
};
class TESLandTexture
{
  public:
    static BSAudio* GetSoundSystem();
};
class TESWeather
{
  public:
    unsigned char GetWeatherDataRaw(int);
};
class NiGeometry
{
  public:
    void FUN_00450f90(bool);
};
class NiNode : public NiGeometry
{
};
template <class T> class NiPointer
{
  public:
    T* object;
    operator T*() const;
};
class Model
{
  public:
    NiNode* GetObject3D();
};
class Sun : public Model
{
};
class Clouds
{
  public:
    void FUN_0063a610();
};
class Precipitation
{
  public:
    void FUN_00636ed0(float);
};
class SkySound : public SoundPlaybackHandle
{
  public:
    ~SkySound();
};
enum Sky__SKY_MODE
{
    SM_NONE = 0,
    SM_INTERIOR = 1,
    SM_FAKEEXTERIOR = 2,
    SM_FULL = 3,
    SM_COUNT = 4
};
class Sky
{
  public:
    void** vtable;
    NiPointer<NiNode> m_pRootNode;
    unsigned char prefix08[0x20];
    Sun* m_pSun;
    Clouds* m_pClouds;
    unsigned char prefix30[8];
    Precipitation* m_pPrecipitation;
    unsigned char environment3c[0xbc];
    Sky__SKY_MODE eMode;
    BSSimpleList<SkySound*>* m_pSkySounds;
    float m_fWeatherFade;
    TESWeather* GetAudioBackendData();
    TESWeather* FUN_0044edb0();
    float GetFieldEC();
    void SetMode(Sky__SKY_MODE);
    void LoadAllTextures();
    void UnloadAllTextures();
    void UpdateHDRValues();
};
class TES
{
  public:
    Sky* GetLogDate();
    void FUN_00455690();
};
class TESObjectCELL
{
  public:
    BGSAcousticSpace* GetAcousticSpace();
};
class PlayerCharacter
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual const NiPoint3& GetPos();
    char regionPadding[0x5f9 - 4];
    bool regionSoundsEnabled;
    char regionPadding2[0x774 - 0x5fa];
    BSSimpleList<RegionSound*> regionSounds;
    char regionPadding3[0x7dc - 0x774 - sizeof(BSSimpleList<RegionSound*>)];
    unsigned int regionSoundTimer;
    TESObjectCELL* GetTarget();
    BSSimpleList<RegionSound*>* GetRegionSounds();
    void ResetRegionSoundTimer();
    bool IsRegionSoundsEnabled();
};
class TESRegionData
{
  public:
    BSSimpleList<RegionSound*>* GetOffsetC();
};
class RegionDataList
{
  public:
    TESRegionData* Find(int);
};
class NiAVObject
{
  public:
    RegionDataList* GetParent();
};
struct RegionSoundSource
{
    NiAVObject* region;
    TESRegionData* data;
};
struct RegionSoundOffset
{
    float y;
    float x;
};
class BGSImpactData
{
  public:
    NiAVObject* GetDecalTextureSet() const;
};
class TESTopicInfo
{
  public:
    TESSound* GetSpeaker();
    TESSound* GetConversationData();
};
class LowProcess
{
  public:
    TESSound* GetCurrentBoundObject();
    TESSound* GetTarget();
};
class BGSAcousticSpace : public BGSImpactData
{
  public:
    bool GetByteAtOffset48();
    int GetField4C();
};
struct SoundData
{
    unsigned char minDistance, maxDistance;
    unsigned char pitch;
    unsigned char unused;
    unsigned int flags;
    unsigned short frequency;
    unsigned short attenuation;
    unsigned char tail[24];
};
class TESSound : public TESForm
{
  public:
    const char* FUN_00511840();
    SoundData CopyBig();
    unsigned char GetHighByteOfField4E();
    unsigned char FUN_0082d700();
    unsigned int Deallocate();
    unsigned char GetField45();
    static unsigned int GetPlaybackFlags(unsigned int);
};
class TESDataHandler
{
  public:
    TESSound* GetSoundByEditorID(const char*);
    bool FUN_004516b0();
    void* GetFirstSceneObject();
};
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
class Interface
{
  public:
    enum enumMenus
    {
        MenuLoading = 0x3f5
    };
    static bool GetSelectedTargetIndex(enumMenus);
};
template <class K, class V> class NiTPointerMap
{
  public:
    void* GetFirstPos();
    void GetNext(void*&, K&, V&);
    bool RemoveAt(K);
    bool IsEmpty();
    bool GetAt(K, V&) const;
    void SetAt(K, V);
};
class SoundPlaybackManager
{
  public:
    static void ProcessPendingSounds();
    static bool ResolveSoundFile(const char*, char*, unsigned int*, void**);
    static void ResetAcousticSpace(BGSAcousticSpace*);
    static bool CanPlaySoundAt(TESSound*, NiPoint3, float);
    static void LoadGame(class BGSLoadGameBuffer*);
    static void SetAcousticSpace(BGSAcousticSpace*);
    static void InitFootstepImpacts();
    static void InitializeSlots();
};
namespace std {
float abs(float);
int abs(int);
}
unsigned int DialogueRandom();
bool RandomBoolean(float);
void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);
extern TESDataHandler* g_dataHandler;
extern PlayerCharacter* g_thePlayer;
extern TES* g_TES;
extern bool DAT_011dcfa6, DAT_011dcfa7, DAT_011dcfb0, DAT_011dcfb1;
extern TESSound* DAT_011dcfa8;
extern unsigned int DAT_011dcfac;
extern BGSAcousticSpace* DAT_011dcfb4;
extern BGSAcousticSpace* DAT_011dcfb8;
extern int DAT_011dcfc0;
extern SettingT_GameSettingCollection_ DAT_011dd044, DAT_011dd094, DAT_011dd050, DAT_011dd06c, DAT_011dcfe4;
extern SettingT_GameSettingCollection_ DAT_011f6dc0, DAT_011f6dcc, DAT_011f6dd8, DAT_011f6de4;
extern SoundPlaybackHandle DAT_011dd0a0, DAT_011dd0d8;
extern NiTPointerMap<unsigned int, SoundPlaybackHandle*> DAT_011dd014;
class BGSLoadGameBuffer
{
  public:
    unsigned int ReadFormIdentifier();
};
int Warning(const char*, ...);
extern bool DAT_011ccb74;
#endif

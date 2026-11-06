// fallout_shared/mediaset_decls.h: declares TESFullName, TESFormInitFlag, TESBoundObject, TESSound, MediaLocationController and more
#ifndef FNV_MEDIASET_DECLS_H
#define FNV_MEDIASET_DECLS_H


#include "layout_support.h"
#include "mediaset_form.h"
// Unit-local full-name declaration includes its external lifetime methods.
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
    TESFullName();
    ~TESFullName();
};

class TESFormInitFlag : public TESForm
{
  public:
    static TESForm* GetFormByID(unsigned int formID);
};

class TESBoundObject : public TESForm
{
};

class TESSound : public TESBoundObject
{
};

class MediaLocationController
{
  public:
    int FUN_00598000();
    bool GetByteAtOffset55();
};
class TESObjectREFR
{
  public:
    float GetScale();
};
template <class T> class NiPointer
{
  public:
    T* operator->() const;
};
enum MEDIATYPE
{
    MEDIA_INCIDENTAL = 2
};
class FalloutAudioMedia
{
  public:
    static bool IsMediaPlaying(MEDIATYPE, bool);
    static void FadeOutMedia(int, MEDIATYPE);
    static void PlayMedia(MEDIATYPE, const char*, unsigned int, bool, bool, float, unsigned int);
    static void EndMediaUpdate();
};
unsigned int FUN_00830970(MEDIATYPE);
unsigned int FUN_00830a20(MEDIATYPE);
extern unsigned int DAT_011dd37c;

#pragma pack(push, 4)
class MediaSet : public TESForm, public TESFullName
{
  public:
    class MediaSetEntry
    {
      public:
        BSStringT<char> Name;
        float Attenuation;
        float Percent;
        MediaSetEntry();
        ~MediaSetEntry();
        void Clear();
    };

    enum MEDIASETTYPE
    {
        BATTLE = 0,
        LAYER_LOCATION = 1,
        LAYER_DUNGEON = 2,
        INCIDENTAL = 3,
        SETTYPE_COUNT = 4
    };

    unsigned int m_uiMediaValue1;
    unsigned int m_uiMediaValue2;
    unsigned int m_uiMediaValue3;
    bool bEffectFlag;
    bool m_bActorStateFlag;
    bool m_bCountWasNonzero;
    bool m_bConditionWasTrue;
    char m_cMediaState;
    TESFullName m_kFullName;
    MEDIASETTYPE Type;
    MediaSetEntry m_kMediaSetEntry1;
    MediaSetEntry m_kMediaSetEntry2;
    MediaSetEntry m_kMediaSetEntry3;
    MediaSetEntry m_kMediaSetEntry4;
    MediaSetEntry m_kMediaSetEntry5;
    MediaSetEntry m_kMediaSetEntry6;
    char m_cMediaFlag;
    float m_fMediaParameter1;
    float fSkillValueBonus;
    float m_fMediaParameter3;
    float m_fMediaValue;
    TESSound* m_pSound1;
    TESSound* m_pSound2;

    virtual void InitItem();
    MediaSet();
    void ClearData();
    void ResetFormData();
    bool UpdateLayerLocation(unsigned int, bool, MediaLocationController*);
    bool PointLocation(unsigned int, bool, MediaLocationController*);
    bool UpdateBattleState(bool, unsigned int, int);
    void UpdateIncidental(unsigned int);
    bool Update(unsigned int auiTime, bool abForce, MediaLocationController* apController);
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(MediaSet) == 0xC4);
FNV_STATIC_ASSERT(offsetof(MediaSet, m_pSound1) == 0xBC);
FNV_STATIC_ASSERT(offsetof(MediaSet, m_pSound2) == 0xC0);

extern unsigned int DAT_011ca9fc;

int Warning(const char* format, ...);

#endif


// src/gamebryo2.2/corelibs/nianimation/nikeybasedinterpolator_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nianimation/nikeybasedinterpolator.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// NiQuaternion component-wise inequality comparison.
// Returns true when any of the four quaternion components differs.
class NiQuaternion
{
  public:
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;

    bool operator!=(const NiQuaternion& kOther) const;
};
// @fnv 0x0064a290
bool NiQuaternion::operator!=(const NiQuaternion& kOther) const
{
    return m_fVectorX != kOther.m_fVectorX || m_fVectorY != kOther.m_fVectorY || m_fVectorZ != kOther.m_fVectorZ ||
           m_fScalarPart != kOther.m_fScalarPart;
}

extern void* _DAT_01097054;

struct NiInterpolator
{
    NiInterpolator();
};

struct FUN_00a3ca10 : NiInterpolator
{
    FUN_00a3ca10();
};

// @fnv 0x00a3ca10
FUN_00a3ca10::FUN_00a3ca10()
{
    *reinterpret_cast<void**>(this) = &_DAT_01097054;
}

extern "C" void __cdecl operator delete(void*, unsigned int);
extern "C" void* DAT_01097054;
struct NiKeyBasedInterpolator
{
    void* m_pVTable;
    void __thiscall FUN_00a57010();
    NiKeyBasedInterpolator* __thiscall FUN_00a3ca50(unsigned int flags);
};
// @fnv 0x00a3ca50
NiKeyBasedInterpolator* __thiscall NiKeyBasedInterpolator::FUN_00a3ca50(unsigned int flags)
{
    m_pVTable = &DAT_01097054;
    FUN_00a57010();
    if (flags & 1)
        operator delete(this, 0xc);
    return this;
}

namespace fnv_00a3ca80 {
struct AnimationKey;
struct NiKeyBasedInterpolator
{
    AnimationKey* FUN_00a3ca80(unsigned int uiWhichKey, unsigned short usChannel);
};
// @fnv 0x00a3ca80
AnimationKey* NiKeyBasedInterpolator::FUN_00a3ca80(unsigned int uiWhichKey, unsigned short usChannel)
{
    typedef unsigned char(__thiscall * FnStride)(NiKeyBasedInterpolator*, unsigned short);
    typedef AnimationKey*(__thiscall * FnArray)(NiKeyBasedInterpolator*, unsigned short);
    unsigned char stride = ((FnStride)(*(void***)this)[60])(this, usChannel);
    AnimationKey* keys = ((FnArray)(*(void***)this)[59])(this, usChannel);
    return (AnimationKey*)((char*)keys + uiWhichKey * stride);
}
}  // namespace fnv_00a3ca80

namespace fnv_00a3cbf0 {
struct StrArr
{
    unsigned char _pad0[8];
    unsigned short m_usMax;
    unsigned short m_usSize;
    unsigned short m_usPad;
    unsigned short m_usGrow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct NiInterpolator
{
    void FUN_00a570b0(StrArr*);
};
struct NiKeyBasedInterpolator : public NiInterpolator
{
    void GetViewerStrings(StrArr*);
};
char* _FUN_00a7d330(const char*);
extern const char* _DAT_011f3740;
// @fnv 0x00a3cbf0
void NiKeyBasedInterpolator::GetViewerStrings(StrArr* pkStrings)
{
    NiInterpolator::FUN_00a570b0(pkStrings);
    char* pcStr = _FUN_00a7d330(_DAT_011f3740);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMax)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrow);
    pkStrings->SetAt(uiSize, pcStr);
}
}  // namespace fnv_00a3cbf0

struct AnimationKey
{
    float m_fTime;
};

class KeyInterp
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual unsigned short GetKeyChannelCount() const;
    virtual unsigned int GetColorKeyCount(unsigned short usChannel) const;
    virtual void v57();
    virtual void v58();
    virtual AnimationKey* GetChannelKeys(unsigned short usChannel) const;
    virtual unsigned char GetColorKeySize(unsigned short usChannel) const;

    static AnimationKey* KeyAt(AnimationKey* pkKeys, unsigned int uiIndex, unsigned char ucSize)
    {
        return (AnimationKey*)((char*)pkKeys + uiIndex * ucSize);
    }

    void GetActiveTimeRange(float& fBeginKeyTime, float& fEndKeyTime) const;
};

extern float DAT_0109704c;
extern float DAT_01015f5c;

// @fnv 0x00a3cac0
void KeyInterp::GetActiveTimeRange(float& fBeginKeyTime, float& fEndKeyTime) const
{
    fBeginKeyTime = DAT_0109704c;
    fEndKeyTime = DAT_01015f5c;
    for (unsigned int us = 0; us < GetKeyChannelCount(); us++)
    {
        AnimationKey* pkBeginKey = KeyAt(GetChannelKeys(us), 0, GetColorKeySize(us));
        unsigned int uiLast = GetColorKeyCount(us) - 1;
        AnimationKey* pkEndKey = KeyAt(GetChannelKeys(us), uiLast, GetColorKeySize(us));
        if (pkBeginKey && pkEndKey)
        {
            if (pkBeginKey->m_fTime < fBeginKeyTime)
                fBeginKeyTime = pkBeginKey->m_fTime;
            if (pkEndKey->m_fTime > fEndKeyTime)
                fEndKeyTime = pkEndKey->m_fTime;
        }
    }
    if (fBeginKeyTime == 3.4028234663852886e+38 && fEndKeyTime == -3.4028234663852886e+38)
    {
        fBeginKeyTime = 0.0f;
        fEndKeyTime = 0.0f;
    }
}

// fallout_shared/facegen/bsfacegenanimationdata.cpp: BSFaceGenAnimationData, BSFaceGenKeyframeMultiple, AnimHost, BSFaceGenEyeData (43 functions)

#include "bsfacegenanimationdata_decls.h"
// Deletes the target object if present and sets the target pointer to null.
// @fnv 0x0064b5e0
void BSFaceGenAnimationData::ClearTransitionTarget()
{
    if (target)
        delete target;
    target = 0;
}
// Forwards the four boolean arguments to the virtual functions at vtable slots 0x100 and 0x104.
// @fnv 0x0064ae60
void BSFaceGenAnimationData::SetMorphFlags(bool abArg1, bool abArg2, bool abArg3, bool abArg4)
{
    vfn_100(abArg1, abArg2, abArg3, abArg4);
    vfn_104(abArg1, abArg2, abArg3, abArg4);
}
// @fnv 0x0064a920
void BSFaceGenAnimationData::SetStateFlags(bool abDead, bool b)
{
    if (abDead && !dead)
    {
        vfn_b4(b ? 0.0f : 1.0f, true, true, true, true, true);
        dead = abDead;
        dirty = true;
    }
    else if (!abDead && dead)
    {
        dead = abDead;
        vfn_b4(b ? 0.0f : 1.0f, true, true, true, true, false);
        dirty = true;
        changed = true;
    }
}
// @fnv 0x0064ab40
void BSFaceGenAnimationData::AddModifierKeyframe(float* values, float time)
{
    BSFaceGenKeyframeMultiple frame(MODIFIER, 17);
    if (dead || !values || time < 0.0)
        return;
    frame.SetTime(time);
    for (unsigned i = 0; i < 17; i++)
        frame.FUN_0064a4d0(i, values[i]);
    frame.InsertIntoKeyframeList((NiTPointerList<BSFaceGenKeyframe*>*)((char*)this + 0x88));
}
// @fnv 0x0064ad20
void BSFaceGenAnimationData::AddKeyframe(BS_FACEGEN_MORPH_TYPE type, float time, bool unused)
{
    if (dead)
        return;
    switch (type)
    {
    case PHONEME: {
        BSFaceGenKeyframeMultiple frame(PHONEME, 16);
        frame.SetTime(time);
        frame.InsertIntoKeyframeList((NiTPointerList<BSFaceGenKeyframe*>*)((char*)this + 0xbc));
        break;
    }
    case MODIFIER: {
        BSFaceGenKeyframeMultiple frame(MODIFIER, 17);
        frame.SetTime(time);
        frame.InsertIntoKeyframeList((NiTPointerList<BSFaceGenKeyframe*>*)((char*)this + 0x88));
        break;
    }
    case CUSTOM: {
        BSFaceGenKeyframeMultiple frame(CUSTOM, 1);
        frame.SetTime(time);
        frame.InsertIntoKeyframeList((NiTPointerList<BSFaceGenKeyframe*>*)((char*)this + 0xf0));
        break;
    }
    }
}
// @fnv 0x0064aa00
void BSFaceGenAnimationData::InsertPhonemeKeyframe(float* values, float time)
{
    BSFaceGenKeyframeMultiple frame(PHONEME, 16);
    if (dead || !values || time < 0.0)
        return;
    unsigned i;
    for (i = 0; i < 16; i++)
    {
        if (values[i] < 0.0 || values[i] > 1.0)
            return;
    }
    frame.SetTime(time);
    for (i = 0; i < 16; i++)
        frame.FUN_0064a4d0(i, values[i]);
    frame.InsertIntoKeyframeList((NiTPointerList<BSFaceGenKeyframe*>*)((char*)this + 0xbc));
}
// @fnv 0x0064b2b0
void BSFaceGenAnimationData::SetExpressionWeight(int expression, float quantity)
{
    if (expression < -1 || expression > 15 || quantity < 0.0 || quantity > 1.0)
        return;
    if (target)
        target->vfn_20(true);
    else
    {
        target = new BSFaceGenKeyframeMultiple(EXPRESSION, 15);
        target->vfn_38();
    }
    if (expression == -1 || quantity == 0.0)
        return;
    target->FUN_0064a4d0(expression, quantity);
    if (!((BSFaceGenKeyframeMultiple*)((char*)this + 0x10))->vfn_2c(target))
        vfn_120();
}
// Reads three rotation values, clamps each to a range, stores them into the quaternion, and returns whether it differs from identity.
// @fnv 0x0064a100
bool BSFaceGenAnimationData::CalculateRotationQuaternion(NiQuaternion& rotation)
{
    float fX = ((RotationValues*)((char*)this + 0xa8))->FUN_005dd4e0(16);
    float fZ = ((RotationValues*)((char*)this + 0xa8))->FUN_005dd4e0(15);
    float fY = ((RotationValues*)((char*)this + 0xa8))->FUN_005dd4e0(14);
    if (fX == DAT_010231b0)
        fX = 0.0f;
    fX = fX > DAT_01064f58 ? (fX < DAT_01064f50 ? fX : DAT_01064f50) : DAT_01064f58;
    if (fZ == DAT_010231b0)
        fZ = 0.0f;
    fZ = fZ > DAT_01064f58 ? (fZ < DAT_01064f50 ? fZ : DAT_01064f50) : DAT_01064f58;
    if (fY == DAT_010231b0)
        fY = 0.0f;
    fY = fY > DAT_01064f58 ? (fY < DAT_01064f50 ? fY : DAT_01064f50) : DAT_01064f58;
    rotation.SetRotationFromEulerXYZ(fX, fZ, fY);
    return rotation != NiQuaternion::IDENTITY;
}
// @fnv 0x0064a770
void BSFaceGenAnimationData::FadeOutMorphs(float time, bool expression, bool phoneme, bool modifier, bool custom)
{
    vfn_104(expression, phoneme, modifier, custom);
    if (expression)
    {
        ((BSFaceGenKeyframeMultiple*)((char*)this + 0x24))->vfn_10(0.0f);
        if (time > 0.0)
            vfn_f8(EXPRESSION, time, true);
        else
            ((BSFaceGenKeyframeMultiple*)((char*)this + 0x24))->vfn_20(true);
    }
    if (modifier)
    {
        ((BSFaceGenKeyframeMultiple*)((char*)this + 0x38))->vfn_10(0.0f);
        if (time > 0.0)
            vfn_f8(MODIFIER, time, true);
        else
            ((BSFaceGenKeyframeMultiple*)((char*)this + 0x38))->vfn_20(true);
    }
    if (phoneme)
    {
        ((BSFaceGenKeyframeMultiple*)((char*)this + 0x4c))->vfn_10(0.0f);
        if (time > 0.0)
            vfn_f8(PHONEME, time, true);
        else
            ((BSFaceGenKeyframeMultiple*)((char*)this + 0x4c))->vfn_20(true);
    }
    if (custom)
    {
        ((BSFaceGenKeyframeMultiple*)((char*)this + 0x60))->vfn_10(0.0f);
        if (time > 0.0)
            vfn_f8(CUSTOM, time, true);
        else
            ((BSFaceGenKeyframeMultiple*)((char*)this + 0x60))->vfn_20(true);
    }
}
// If index is within count and quantities[index] differs from value, stores value there and returns true; otherwise returns false.
// @fnv 0x0064a4d0
bool BSFaceGenKeyframeMultiple::FUN_0064a4d0(unsigned int index, float value)
{
    if (index < count && quantities[index] != value)
    {
        quantities[index] = value;
        return true;
    }
    return false;
}

class BSFadeNode
{
  public:
    int m_iFadeNodeMode;
    BSFadeNode(const char*);
};

extern BSFadeNode* DAT_011d5744;

// Allocates a BSFadeNode named "FAD" and stores it in DAT_011d5744.
// @fnv 0x00649e40
void FUN_00649e40()
{
    DAT_011d5744 = new BSFadeNode("FAD");
}

struct FUN_0064a310_shell : public BSFaceGenAnimationData
{
    void ResetFaceGenAnimationData(float, bool, bool, bool, bool, bool);
};

extern const double gModifierZero;

class RecursiveSpinLock
{
  public:
    void Lock(const char*);
    void Unlock();
};

struct BSFaceGenAnimationData_Vtable
{
    char pad[0xb8];
    void(__thiscall* vfn_b8)(void*, float, bool, bool, bool, bool, bool);
    void(__thiscall* vfn_bc)(void*, float, bool, bool, bool, bool);
};

// @fnv 0x0064a310
void FUN_0064a310_shell::ResetFaceGenAnimationData(float afTime, bool abResetExpression, bool abResetPhoneme,
                                                   bool abResetModifier, bool abResetCustomMorph, bool abForDeath)
{
    reinterpret_cast<RecursiveSpinLock*>(reinterpret_cast<char*>(this) + 0x1a0)->Lock(0);

    (*reinterpret_cast<BSFaceGenAnimationData_Vtable**>(this))
        ->vfn_b8(this, afTime, abResetExpression, abResetPhoneme, abResetModifier, abResetCustomMorph, abForDeath);
    (*reinterpret_cast<BSFaceGenAnimationData_Vtable**>(this))
        ->vfn_bc(this, afTime, abResetExpression, abResetPhoneme, abResetModifier, abResetCustomMorph);

    if (afTime == gModifierZero)
    {
        if (abResetExpression)
        {
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x74)->vfn_10(0.0f);
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x74)->vfn_20(true);
        }
        if (abResetModifier)
        {
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xa8)->vfn_10(0.0f);
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xa8)->vfn_20(true);
            if (abForDeath)
            {
                reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xa8)
                    ->FUN_0064a4d0(0, 1.0f);
                reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xa8)
                    ->FUN_0064a4d0(1, 1.0f);
            }
        }
        if (abResetPhoneme)
        {
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xdc)->vfn_10(0.0f);
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0xdc)->vfn_20(true);
        }
        if (abResetCustomMorph)
        {
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x110)->vfn_10(0.0f);
            reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x110)->vfn_20(true);
        }
    }

    reinterpret_cast<RecursiveSpinLock*>(reinterpret_cast<char*>(this) + 0x1a0)->Unlock();
}

struct FUN_0064a520_shell : public BSFaceGenAnimationData
{
    void ResetFaceGenData(float, bool, bool, bool, bool, bool);
};

extern double _gModifierZero;

class BSFaceGenManager
{
  public:
    static void __cdecl ApplyFaceGenValues(float*, unsigned int, bool);
};

// @fnv 0x0064a520
void FUN_0064a520_shell::ResetFaceGenData(float afTime, bool abResetExpression, bool abResetPhoneme,
                                          bool abResetModifier, bool abResetCustomMorph, bool abForDeath)
{
    float pmods[17];

    reinterpret_cast<void(__thiscall*)(void*, bool, bool, bool, bool)>((*reinterpret_cast<void***>(this))[0xfc / 4])(
        this, abResetExpression, abResetPhoneme, abResetModifier, abResetCustomMorph);

    if (abResetExpression)
    {
        reinterpret_cast<void(__thiscall*)(void*, float)>((*reinterpret_cast<void***>(
            reinterpret_cast<char*>(this) + 0x10))[0x10 / 4])(reinterpret_cast<char*>(this) + 0x10, 0.0f);

        if (afTime > _gModifierZero)
        {
            reinterpret_cast<void(__thiscall*)(void*, int, float)>((*reinterpret_cast<void***>(this))[0x114 / 4])(
                this, -1, 1.0f);
        }
        else
        {
            reinterpret_cast<void(__thiscall*)(void*, int)>((*reinterpret_cast<void***>(
                reinterpret_cast<char*>(this) + 0x10))[0x20 / 4])(reinterpret_cast<char*>(this) + 0x10, 1);
        }
    }

    if (abResetModifier)
    {
        reinterpret_cast<void(__thiscall*)(void*, float)>((*reinterpret_cast<void***>(
            reinterpret_cast<char*>(this) + 0x94))[0x10 / 4])(reinterpret_cast<char*>(this) + 0x94, 0.0f);

        if (afTime > _gModifierZero)
        {
            if (abForDeath)
            {
                BSFaceGenManager::ApplyFaceGenValues(pmods, 0x11, 1);
                pmods[0] = 1.0f;
                pmods[1] = 1.0f;
                reinterpret_cast<void(__thiscall*)(void*, float*, float)>((*reinterpret_cast<void***>(this))[0xf0 / 4])(
                    this, pmods, afTime);
            }
            else
            {
                reinterpret_cast<void(__thiscall*)(void*, int, float, int)>(
                    (*reinterpret_cast<void***>(this))[0xf4 / 4])(this, 2, afTime, 1);
            }
        }
        else
        {
            reinterpret_cast<void(__thiscall*)(void*, int)>((*reinterpret_cast<void***>(
                reinterpret_cast<char*>(this) + 0x94))[0x20 / 4])(reinterpret_cast<char*>(this) + 0x94, 1);

            if (abForDeath)
            {
                reinterpret_cast<void(__thiscall*)(void*, int, float)>((*reinterpret_cast<void***>(this))[0xa0 / 4])(
                    this, 0, 1.0f);
                reinterpret_cast<void(__thiscall*)(void*, int, float)>((*reinterpret_cast<void***>(this))[0xa0 / 4])(
                    this, 1, 1.0f);
            }
        }
    }

    if (abResetPhoneme)
    {
        reinterpret_cast<void(__thiscall*)(void*, float)>((*reinterpret_cast<void***>(
            reinterpret_cast<char*>(this) + 0xc8))[0x10 / 4])(reinterpret_cast<char*>(this) + 0xc8, 0.0f);

        if (afTime > _gModifierZero)
        {
            reinterpret_cast<void(__thiscall*)(void*, int, float, int)>((*reinterpret_cast<void***>(this))[0xf4 / 4])(
                this, 0, afTime, 1);
        }
        else
        {
            reinterpret_cast<void(__thiscall*)(void*, int)>((*reinterpret_cast<void***>(
                reinterpret_cast<char*>(this) + 0xc8))[0x20 / 4])(reinterpret_cast<char*>(this) + 0xc8, 1);
        }
    }

    if (abResetCustomMorph)
    {
        reinterpret_cast<void(__thiscall*)(void*, float)>((*reinterpret_cast<void***>(
            reinterpret_cast<char*>(this) + 0xfc))[0x10 / 4])(reinterpret_cast<char*>(this) + 0xfc, 0.0f);

        if (afTime > _gModifierZero)
        {
            reinterpret_cast<void(__thiscall*)(void*, int, float, int)>((*reinterpret_cast<void***>(this))[0xf4 / 4])(
                this, 3, afTime, 1);
        }
        else
        {
            reinterpret_cast<void(__thiscall*)(void*, int)>((*reinterpret_cast<void***>(
                reinterpret_cast<char*>(this) + 0xfc))[0x20 / 4])(reinterpret_cast<char*>(this) + 0xfc, 1);
        }
    }
}

struct FUN_0064b400_shell : public BSFaceGenAnimationData
{
    void SetMoodExpression(int, bool);
};

// @fnv 0x0064b400
void FUN_0064b400_shell::SetMoodExpression(int aiMoodindex, bool abTalking)
{
    if (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c) != 0)
    {
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->vfn_20(true);
    }
    else
    {
        *reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c) =
            new BSFaceGenKeyframeMultiple(EXPRESSION, 15);
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->vfn_38();
    }

    if (*reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x18e))
        return;

    switch (aiMoodindex)
    {
    case 0:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->FUN_0064a4d0(5, 1.0f);
        break;
    case 1:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->FUN_0064a4d0(6, 1.0f);
        break;
    case 2:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->FUN_0064a4d0(7, 1.0f);
        break;
    case 3:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->FUN_0064a4d0(8, 1.0f);
        break;
    case 4:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->FUN_0064a4d0(9, 1.0f);
        break;
    case 5:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->FUN_0064a4d0(10, 1.0f);
        break;
    case 6:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->FUN_0064a4d0(11, 1.0f);
        break;
    case 7:
        (*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c))->FUN_0064a4d0(12, 1.0f);
        break;
    }

    if (!reinterpret_cast<BSFaceGenKeyframeMultiple*>(reinterpret_cast<char*>(this) + 0x10)
             ->vfn_2c(*reinterpret_cast<BSFaceGenKeyframeMultiple**>(reinterpret_cast<char*>(this) + 0x0c)))
    {
        typedef void(__thiscall * Vfn120)(void*);
        (*reinterpret_cast<Vfn120*>((*reinterpret_cast<char**>(this)) + 0x120))(this);
    }
}

class Script;

template <class T> class NiTListItem
{
  public:
    NiTListItem<T>* m_pkNext;
    NiTListItem<T>* m_pkPrev;
    T m_element;
};

template <class T> class NiTPointerAllocator
{
};

template <class Alloc, class T> class NiTPointerListBase
{
  public:
    NiTListItem<T>* m_pkHead;
    NiTListItem<T>* m_pkTail;
    unsigned int m_uiCount;

    void DeleteItem(NiTListItem<T>*);
};

// Removes the head node from the list, fixes up head/tail links, deletes the node, decrements the count and returns its Script element.
// @fnv 0x007b5390
Script* __fastcall PopFrontScript(NiTPointerListBase<NiTPointerAllocator<unsigned int>, Script*>* pThis)
{
    NiTListItem<Script*>* pkNode = pThis->m_pkHead;
    pThis->m_pkHead = pThis->m_pkHead->m_pkNext;
    if (pThis->m_pkHead)
        pThis->m_pkHead->m_pkPrev = 0;
    else
        pThis->m_pkTail = 0;

    Script* pScript = pkNode->m_element;
    pThis->DeleteItem(pkNode);
    pThis->m_uiCount--;
    return pScript;
}

struct SettingT_GCol
{
    float* Float();
};
extern SettingT_GCol originalRuntimeFloatSetting1271;
extern const double DAT_01023128;
// @fnv 0x00649f00
void ComputeAngleRange(float* afMin, float* afMax)
{
    *afMax = *originalRuntimeFloatSetting1271.Float() * DAT_01023128;
    if (*afMax < _gModifierZero)
        *afMax = 0.0f;
    if (*afMax > DAT_01064f50)
        *afMax = 1.5707964f;
    *afMin = *afMax * -1.0;
}

namespace fnv_00649f70 {
struct SettingT_GCol
{
    float* Float();
};
extern SettingT_GCol originalRuntimeFloatSetting1271;
extern const double DAT_01023128;
// @fnv 0x00649f70
void ClampMinMaxFromSetting(float* afMin, float* afMax)
{
    *afMax = *originalRuntimeFloatSetting1271.Float() * DAT_01023128;
    if (*afMax < _gModifierZero)
        *afMax = 0.0f;
    if (*afMax > DAT_01064f50)
        *afMax = 1.5707964f;
    *afMin = *afMax * -1.0;
}
}  // namespace fnv_00649f70

struct SettingT_GameSettingCollection_
{
    float* Float();
};
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting1273;
extern const double DAT_01023128;
extern double _gModifierZero;
void __cdecl ComputeAngleRange(float*, float*);
// @fnv 0x00649fe0
void FUN_00649fe0(float* afMin, float* afMax)
{
    float fMin;
    float fScaledValue;
    *afMax = *originalRuntimeFloatSetting1273.Float() * DAT_01023128;
    if (*afMax < _gModifierZero)
        *afMax = 0.0f;
    if (*afMax > DAT_01064f50)
        *afMax = 1.5707964f;
    ComputeAngleRange(&fMin, &fScaledValue);
    if (*afMax > fScaledValue)
        *afMax = fScaledValue;
    *afMin = *afMax * -1.0;
}

extern const double DAT_01023128;
extern const double DAT_01064f50;
extern double _gModifierZero;
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting1274;
void __cdecl ClampMinMaxFromSetting(float*, float*);

// Computes a clamped max eye angle from a runtime float setting and writes its negation as the min angle.
// @fnv 0x0064a070
void __cdecl GetEyeAngleLimits(float* afMinOut, float* afMaxOut)
{
    float fminEye;
    float fmaxEye;
    *afMaxOut = *originalRuntimeFloatSetting1274.Float() * DAT_01023128;
    if (*afMaxOut < _gModifierZero)
        *afMaxOut = 0.0f;
    if (*afMaxOut > DAT_01064f50)
        *afMaxOut = 1.5707963705062866f;
    ClampMinMaxFromSetting(&fminEye, &fmaxEye);
    if (*afMaxOut > fmaxEye)
        *afMaxOut = fmaxEye;
    *afMinOut = *afMaxOut * -1.0;
}

namespace fnv_0064b630 {
struct NiStream;
struct blob8
{
    char b[8];
};
struct NiPoint2
{
    static struct blob8 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float Dot(void*);
    float Unitize();
    static void LoadBinary(NiStream*, NiPoint2*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint2*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float x;
    float y;
};
typedef char _sizecheck_NiPoint2[sizeof(NiPoint2) == 8 ? 1 : -1];
struct FUN_0064b630_shell : public BSFaceGenAnimationData
{
    bool UpdateFaceGenAnimation(float);
};

struct Setting_S
{
    float* Float();
};
struct RecursiveSpinLock
{
    void Lock(const char*);
    void Unlock();
};
struct BSFaceGenManager
{
    static void __cdecl ApplyFaceGenValues(float*, unsigned int, bool);
};
extern double _gModifierZero;
struct ArrHelper
{
    bool FUN_0076b610() const;
};
struct B006815c0
{
    B006815c0();
    float x, y;
};
float RandomFloat0To1();
bool FUN_0064bcb0();
extern Setting_S originalRuntimeFloatSetting1263;
extern Setting_S originalRuntimeFloatSetting1264;
extern Setting_S originalRuntimeFloatSetting1265;
extern Setting_S originalRuntimeFloatSetting1266;
extern Setting_S originalRuntimeFloatSetting1276;

class FaceGenKeyframeCalls
{
  public:
    virtual ~FaceGenKeyframeCalls();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void Blend(FaceGenKeyframeCalls*, float, bool, bool);
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void Copy(FaceGenKeyframeCalls*);
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual bool Update(float, FaceGenKeyframeCalls*);
    virtual bool IsChanged();
};

class FaceGenAnimationDataCalls
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void AddModifierKeyframe(float*, float);
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void ClearTransitionTarget();
};

bool AdvanceKeyframe(float, ArrHelper*, FaceGenKeyframeCalls*, bool);

// @fnv 0x0064b630
bool FUN_0064b630_shell::UpdateFaceGenAnimation(float afTime)
{
    reinterpret_cast<RecursiveSpinLock*>((char*)this + 0x1a0)->Lock(0);
    B006815c0 delta;
    bool bchangedSpeech;
    float ftime = afTime;
    bool bchangedExp;
    float flookdown = reinterpret_cast<RotationValues*>((char*)this + 0xa8)->FUN_005dd4e0(8);
    bool bchangedAnim;
    bool bchangedCust;
    bool bchangedMod;
    bool bchangedPhon;

    if (FUN_0064bcb0() && !*((bool*)this + 0x18e) && reinterpret_cast<ArrHelper*>((char*)this + 0x88)->FUN_0076b610() &&
        *originalRuntimeFloatSetting1263.Float() > _gModifierZero &&
        *originalRuntimeFloatSetting1264.Float() > _gModifierZero &&
        *originalRuntimeFloatSetting1265.Float() > _gModifierZero &&
        *originalRuntimeFloatSetting1266.Float() >= *originalRuntimeFloatSetting1265.Float() &&
        flookdown < *originalRuntimeFloatSetting1276.Float())
    {
        float fblinkdelay = *originalRuntimeFloatSetting1266.Float() - *originalRuntimeFloatSetting1265.Float();
        float pmods[17];
        BSFaceGenManager::ApplyFaceGenValues(pmods, 17, false);
        pmods[0] = 0.0f;
        pmods[1] = 0.0f;
        reinterpret_cast<FaceGenAnimationDataCalls*>(this)->AddModifierKeyframe(
            pmods, *originalRuntimeFloatSetting1265.Float() + RandomFloat0To1() * fblinkdelay);
        BSFaceGenManager::ApplyFaceGenValues(pmods, 17, false);
        pmods[0] = 1.0f;
        pmods[1] = 1.0f;
        reinterpret_cast<FaceGenAnimationDataCalls*>(this)->AddModifierKeyframe(
            pmods, *originalRuntimeFloatSetting1263.Float());
        BSFaceGenManager::ApplyFaceGenValues(pmods, 17, false);
        pmods[0] = 0.0f;
        pmods[1] = 0.0f;
        reinterpret_cast<FaceGenAnimationDataCalls*>(this)->AddModifierKeyframe(
            pmods, *originalRuntimeFloatSetting1264.Float());
    }

    if (afTime > _gModifierZero)
    {
        *((bool*)this + 0x18b) = false;

        bchangedSpeech = reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x10)
                             ->Update(ftime, *reinterpret_cast<FaceGenKeyframeCalls**>((char*)this + 0xc));
        if (!*((bool*)this + 0x190) && *((bool*)this + 0x18f))
            bchangedAnim = true;
        else
            bchangedAnim = reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x24)->IsChanged();
        if (!bchangedAnim && !bchangedSpeech)
            reinterpret_cast<FaceGenAnimationDataCalls*>(this)->ClearTransitionTarget();
        if (bchangedSpeech)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x74)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x10));
            if (bchangedAnim)
                reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x74)
                    ->Blend(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x24), 1.0f, false, false);
        }
        else if (bchangedAnim)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x74)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x24));
        }
        bchangedExp = (bchangedSpeech || bchangedAnim) ? true : false;

        bchangedSpeech = AdvanceKeyframe(ftime, reinterpret_cast<ArrHelper*>((char*)this + 0x88),
                                         reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x94), false);
        if (!*((bool*)this + 0x190) && *((bool*)this + 0x18f))
            bchangedAnim = true;
        else
            bchangedAnim = reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x38)->IsChanged();
        if (bchangedSpeech)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xa8)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x94));
            if (bchangedAnim)
                reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xa8)
                    ->Blend(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x38), 1.0f, false, false);
        }
        else if (bchangedAnim)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xa8)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x38));
        }
        bchangedMod = (bchangedSpeech || bchangedAnim) ? true : false;

        bchangedSpeech = AdvanceKeyframe(ftime, reinterpret_cast<ArrHelper*>((char*)this + 0xbc),
                                         reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xc8), false);
        if (!*((bool*)this + 0x190) && *((bool*)this + 0x18f))
            bchangedAnim = true;
        else
            bchangedAnim = reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x4c)->IsChanged();
        if (bchangedSpeech)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xdc)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xc8));
            if (bchangedAnim)
                reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xdc)
                    ->Blend(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x4c), 1.0f, false, false);
        }
        else if (bchangedAnim)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xdc)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x4c));
        }
        bchangedPhon = (bchangedSpeech || bchangedAnim) ? true : false;

        bchangedSpeech = AdvanceKeyframe(ftime, reinterpret_cast<ArrHelper*>((char*)this + 0xf0),
                                         reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xfc), false);
        if (!*((bool*)this + 0x190) && *((bool*)this + 0x18f))
            bchangedAnim = true;
        else
            bchangedAnim = reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x60)->IsChanged();
        if (bchangedSpeech)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x110)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0xfc));
            if (bchangedAnim)
                reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x110)
                    ->Blend(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x60), 1.0f, false, false);
        }
        else if (bchangedAnim)
        {
            reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x110)
                ->Copy(reinterpret_cast<FaceGenKeyframeCalls*>((char*)this + 0x60));
        }
        bchangedCust = (bchangedSpeech || bchangedAnim) ? true : false;

        *((bool*)this + 0x18b) = bchangedExp || bchangedMod || bchangedPhon || bchangedCust;
    }

    *((bool*)this + 0x190) = *((bool*)this + 0x18f);
    reinterpret_cast<RecursiveSpinLock*>((char*)this + 0x1a0)->Unlock();
    return *((bool*)this + 0x18b);
}
}  // namespace fnv_0064b630

extern unsigned char DAT_011d59e0;

// @fnv 0x0064bcb0
unsigned char __cdecl FUN_0064bcb0()
{
    return DAT_011d59e0;
}

struct BS_FACEGEN_MODIFIER
{
    int m;
};

struct FUN_00649a50_shell
{
    void SetArrayElement(int a, float f);
};

struct FUN_00649c10_shell
{
    void SetAnimModifierValue(BS_FACEGEN_MODIFIER aeModifier, float afValue);
};

// If the modifier index is below 0x11, forwards the index and value to the object at offset 0x38.
// @fnv 0x00649c10
void FUN_00649c10_shell::SetAnimModifierValue(BS_FACEGEN_MODIFIER aeModifier, float afValue)
{
    if (aeModifier.m < 0x11)
    {
        reinterpret_cast<FUN_00649a50_shell*>(reinterpret_cast<char*>(this) + 0x38)
            ->SetArrayElement(aeModifier.m, afValue);
    }
}

namespace fnv_00649a20 {
struct FUN_00649a50_shell
{
    void SetArrayElement(int, float);
};
struct FUN_00649a20_shell
{
    char _pad[16];
    FUN_00649a50_shell m;
    void SetExpressionValue(int, float);
};
// If aeExpression is below 15, forwards aeExpression and afValue to the contained SetArrayElement handler.
// @fnv 0x00649a20
void FUN_00649a20_shell::SetExpressionValue(int aeExpression, float afValue)
{
    if (aeExpression < 15)
        m.SetArrayElement(aeExpression, afValue);
}
}  // namespace fnv_00649a20

namespace fnv_00649a70 {
struct FUN_00649a50_shell
{
    void SetArrayElement(int, float);
};
struct FUN_00649a70_shell
{
    void SetModifierValue(int, float);
};
// Forwards aeModifier and afValue to the SetArrayElement handler at offset 0x94 when aeModifier is below 0x11.
// @fnv 0x00649a70
void FUN_00649a70_shell::SetModifierValue(int aeModifier, float afValue)
{
    if (aeModifier < 0x11)
        ((FUN_00649a50_shell*)((char*)this + 0x94))->SetArrayElement(aeModifier, afValue);
}
}  // namespace fnv_00649a70

namespace fnv_00649ae0 {
struct FUN_00649a50_shell
{
    void SetArrayElement(int, float);
};
struct FUN_00649ae0_shell
{
    char _pad[0xC8];
    FUN_00649a50_shell m;
    void SetPhonemeValue(int, float);
};
// If aePhoneme is below 0x10, forwards aePhoneme and afValue to m.SetArrayElement.
// @fnv 0x00649ae0
void FUN_00649ae0_shell::SetPhonemeValue(int aePhoneme, float afValue)
{
    if (aePhoneme < 0x10)
    {
        m.SetArrayElement(aePhoneme, afValue);
    }
}
}  // namespace fnv_00649ae0

namespace fnv_00649b50 {
enum BS_FACEGEN_CUSTOM_MORPH
{
    BS_FACEGEN_CUSTOM_MORPH_Dummy = 0
};
struct FUN_00649a50_shell
{
    void SetArrayElement(int, float);
};
struct FUN_00649b50_Pad
{
    char _pad[0xFC];
};
struct FUN_00649b50_shell : FUN_00649b50_Pad, FUN_00649a50_shell
{
    void SetCustomMorphValue(BS_FACEGEN_CUSTOM_MORPH, float);
};
// @fnv 0x00649b50
void FUN_00649b50_shell::SetCustomMorphValue(BS_FACEGEN_CUSTOM_MORPH aeCustomMorph, float afValue)
{
    if (aeCustomMorph < 1)
        FUN_00649a50_shell::SetArrayElement(aeCustomMorph, afValue);
}
}  // namespace fnv_00649b50

namespace fnv_00649be0 {
struct FUN_00649a50_shell
{
    void SetArrayElement(int, float);
};
struct FUN_00649be0_shell
{
    char pad[0x24];
    FUN_00649a50_shell obj;
    void SetAnimExpressionValue(int, float);
};
// If aeExpression is below 15, forwards aeExpression and afValue to SetArrayElement on the member object.
// @fnv 0x00649be0
void FUN_00649be0_shell::SetAnimExpressionValue(int aeExpression, float afValue)
{
    if (aeExpression < 15)
        obj.SetArrayElement(aeExpression, afValue);
}
}  // namespace fnv_00649be0

namespace fnv_00649c40 {
struct FUN_00649a50_shell
{
    void SetArrayElement(int, float);
};
struct FUN_00649c40_shell
{
    void SetAnimPhonemeValue(int, float);
};
// If aePhoneme is below 0x10, forwards the phoneme index and value to the SetArrayElement object at offset 0x4C.
// @fnv 0x00649c40
void FUN_00649c40_shell::SetAnimPhonemeValue(int aePhoneme, float afValue)
{
    if (aePhoneme < 0x10)
    {
        ((FUN_00649a50_shell*)((char*)this + 0x4C))->SetArrayElement(aePhoneme, afValue);
    }
}
}  // namespace fnv_00649c40

namespace fnv_00649c70 {
struct FUN_00649a50_shell
{
    void SetArrayElement(int, float);
};
struct FUN_00649c70_shell
{
    char _pad[0x60];
    FUN_00649a50_shell m;
    void SetAnimCustomMorphValue(int, float);
};
// If aeCustomMorph is less than 1, forwards aeCustomMorph and afValue to m.SetArrayElement.
// @fnv 0x00649c70
void FUN_00649c70_shell::SetAnimCustomMorphValue(int aeCustomMorph, float afValue)
{
    if (aeCustomMorph < 1)
        m.SetArrayElement(aeCustomMorph, afValue);
}
}  // namespace fnv_00649c70

struct FUN_00649ca0_shell
{
    void FUN_00649ce0();
    void* FUN_00649ca0(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls FUN_00649ce0, then if bit 0 of flags is set frees this with size 0x1C0, and returns this.
// @fnv 0x00649ca0
void* FUN_00649ca0_shell::FUN_00649ca0(unsigned int flags)
{
    this->FUN_00649ce0();
    if (flags & 1)
        _delete(this, 0x1C0);
    return this;
}

namespace fnv_00649ec0 {
struct BSFadeNode
{
    int FUN_004b9900(int);
};
extern BSFadeNode* DAT_011d5744;
// Clears DAT_011d5744, calling FUN_004b9900(1) on the previous BSFadeNode if non-null.
// @fnv 0x00649ec0
void FUN_00649ec0()
{
    BSFadeNode* b = DAT_011d5744;
    BSFadeNode* a;
    int c;
    a = b;
    if (a)
        c = a->FUN_004b9900(1);
    else
        c = 0;
    DAT_011d5744 = 0;
}
}  // namespace fnv_00649ec0

struct GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_011d57a4;

struct FUN_006499c0_shell
{
    GlobalObject_00a7b610* GetGlobalObject();
};

// @fnv 0x006499c0
GlobalObject_00a7b610* FUN_006499c0_shell::GetGlobalObject()
{
    return &g_011d57a4;
}

namespace fnv_00649a50 {
struct FUN_00649a50_shell
{
    int pad[3];
    float* arr;
    void SetArrayElement(int idx, float val);
};
// @fnv 0x00649a50
void FUN_00649a50_shell::SetArrayElement(int aiIndex, float afValue)
{
    arr[aiIndex] = afValue;
}
}  // namespace fnv_00649a50

struct NiPoint3
{
    float x;
    float y;
    float z;
};
extern NiPoint3 _NiPoint3_ZERO;
struct FUN_0064bd60_This
{
    char _pad0[0x124];
    NiPoint3 kPoint;
    char _pad1[0x58];
    bool bFull;
    void Reset(bool abInstant);
};
// Resets the point to zero and stores the given flag in bFull.
// @fnv 0x0064bd60
void FUN_0064bd60_This::Reset(bool abInstant)
{
    kPoint = _NiPoint3_ZERO;
    bFull = abInstant;
}

namespace fnv_0064bcc0 {
struct NiPoint3
{
    float x, y, z;
};
extern NiPoint3 _NiPoint3_ZERO;
struct NiPlane
{
    bool FUN_004390c0(const NiPoint3&);
    bool operator==(const NiPoint3&);
};
struct FUN_0064bcc0_shell
{
    void SetHeadTrackVector(float, float, float, int);
};
// Tests the stored plane and the incoming point against zero, updates the flag at 0x174 and value at 0x178, stores the point at 0x124 and sets the byte at 0x189.
// @fnv 0x0064bcc0
void FUN_0064bcc0_shell::SetHeadTrackVector(float afX, float afY, float afZ, int)
{
    if (((NiPlane*)((char*)this + 0x124))->FUN_004390c0(_NiPoint3_ZERO))
    {
        if (((NiPlane*)&afX)->operator==(_NiPoint3_ZERO))
        {
            *(int*)((char*)this + 0x174) = 1;
            *(float*)((char*)this + 0x178) = 0.0f;
        }
    }
    if (((NiPlane*)&afX)->FUN_004390c0(_NiPoint3_ZERO))
        *(int*)((char*)this + 0x174) = 0;
    *(NiPoint3*)((char*)this + 0x124) = *(NiPoint3*)&afX;
    *(char*)((char*)this + 0x189) = 1;
}
}  // namespace fnv_0064bcc0

unsigned int _data_011c16bc;

struct FUN_0064b160_vtable
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual void v4()
    {}
    virtual void v5()
    {}
    virtual void v6()
    {}
    virtual void v7()
    {}
    virtual void v8()
    {}
    virtual void v9()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void v17()
    {}
    virtual void v18()
    {}
    virtual void v19()
    {}
    virtual void v20()
    {}
    virtual void v21()
    {}
    virtual void v22()
    {}
    virtual void v23()
    {}
    virtual void v24()
    {}
    virtual void v25()
    {}
    virtual void v26()
    {}
    virtual void v27()
    {}
    virtual void v28()
    {}
    virtual void v29()
    {}
    virtual void v30()
    {}
    virtual void v31()
    {}
    virtual void v32()
    {}
    virtual void v33()
    {}
    virtual void v34()
    {}
    virtual void v35()
    {}
    virtual void v36()
    {}
    virtual void v37()
    {}
    virtual void v38()
    {}
    virtual void v39()
    {}
    virtual void v40()
    {}
    virtual void v41()
    {}
    virtual void v42()
    {}
    virtual void v43()
    {}
    virtual void v44()
    {}
    virtual void v45()
    {}
    virtual void v46()
    {}
    virtual void v47()
    {}
    virtual void v48()
    {}
    virtual void v49()
    {}
    virtual void v50()
    {}
    virtual void v51()
    {}
    virtual void v52()
    {}
    virtual void v53()
    {}
    virtual void v54()
    {}
    virtual void v55()
    {}
    virtual void v56()
    {}
    virtual void v57()
    {}
    virtual void v58()
    {}
    virtual void v59()
    {}
    virtual void v60()
    {}
    virtual void v61()
    {}
    virtual void v62()
    {}
    virtual void v63()
    {}
    virtual void v64()
    {}
    virtual void v65()
    {}
    virtual void v66()
    {}
    virtual void v67()
    {}
    virtual void v68()
    {}
    virtual void v69()
    {}
    virtual void v70()
    {}
    virtual void v71()
    {}
    virtual void vfn_120()
    {}
};

struct FUN_0064b160_shell : public FUN_0064b160_vtable
{
    unsigned char pad0[8];
    BSFaceGenKeyframeMultiple* m_pFaceGenKeyframeMultiple;
    unsigned char pad1[0x17e];
    bool bCompassReferenceDead;

    void SetExpressionKeyframes(float* apQuantities);
};

// @fnv 0x0064b160
void FUN_0064b160_shell::SetExpressionKeyframes(float* apQuantities)
{
    if (bCompassReferenceDead || apQuantities == 0)
    {
        vfn_120();
        return;
    }

    if (m_pFaceGenKeyframeMultiple)
        delete m_pFaceGenKeyframeMultiple;

    m_pFaceGenKeyframeMultiple = new BSFaceGenKeyframeMultiple(EXPRESSION, 15);

    for (unsigned int iexp = 0; iexp < 15; ++iexp)
        m_pFaceGenKeyframeMultiple->FUN_0064a4d0(iexp, apQuantities[iexp]);

    if (!reinterpret_cast<BSFaceGenKeyframe*>(reinterpret_cast<char*>(this) + 0x10)->vfn_2c(m_pFaceGenKeyframeMultiple))
        vfn_120();
}

struct FaceGenAnimBase
{
    virtual ~FaceGenAnimBase();
    int unk04;
    int unk08;
    int unk0C;
};

struct FaceGenKeyframeMember
{
    ~FaceGenKeyframeMember();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct FaceGenKeyframeListMember
{
    ~FaceGenKeyframeListMember();
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_00649ce0 : FaceGenAnimBase
{
    FaceGenKeyframeMember kf10;
    FaceGenKeyframeMember kf24;
    FaceGenKeyframeMember kf38;
    FaceGenKeyframeMember kf4C;
    FaceGenKeyframeMember kf60;
    FaceGenKeyframeMember kf74;
    FaceGenKeyframeListMember list88;
    FaceGenKeyframeMember kf94;
    FaceGenKeyframeMember kfA8;
    FaceGenKeyframeListMember listBC;
    FaceGenKeyframeMember kfC8;
    FaceGenKeyframeMember kfDC;
    FaceGenKeyframeListMember listF0;
    FaceGenKeyframeMember kfFC;
    FaceGenKeyframeMember kf110;

    virtual ~FUN_00649ce0();
    void SetMorphFlags(bool, bool, bool, bool);
};

// Destructor that calls the cleanup routine with all four flags set to true.
// @fnv 0x00649ce0
FUN_00649ce0::~FUN_00649ce0()
{
    SetMorphFlags(true, true, true, true);
}

extern const double DAT_01012060;

struct FUN_0064ac30_shell : public BSFaceGenAnimationData
{
    void SetKeyframeQuantities(float* quantities, float time);
};

struct FUN_0064ed60_shell
{
    void AddToCompatibleList(NiTPointerList<BSFaceGenKeyframe*>* list);
};

// @fnv 0x0064ac30
void FUN_0064ac30_shell::SetKeyframeQuantities(float* quantities, float time)
{
    BSFaceGenKeyframeMultiple keyframe(CUSTOM, 1);
    if (dead || quantities == 0 || time < DAT_01012060)
    {
        return;
    }

    keyframe.SetTime(time);
    for (unsigned int i = 0; i < 1; ++i)
    {
        keyframe.FUN_0064a4d0(i, quantities[i]);
    }
    reinterpret_cast<FUN_0064ed60_shell*>(&keyframe)->AddToCompatibleList(
        reinterpret_cast<NiTPointerList<BSFaceGenKeyframe*>*>(reinterpret_cast<char*>(this) + 0xf0));
}

// 0x0064aec0  /MT /Od /Oy- /GS /EHsc /Gy  thiscall, 4 bools (ret 0x10)

class KItem
{
  public:
    virtual ~KItem();
};

struct KList
{
    void* head;
    void* tail;
    int count;
    int FUN_44ddc0();
    KItem** FUN_73ac90();
    KItem* RemoveHead();
};

struct KBlk
{
    KList list;
    char pad[0x34 - 0xc];
};

class AnimHost
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
    char padA[0x88 - 4];
    KBlk blk88;
    KBlk blkbc;
    KBlk blkf0;
    void ClearLists(bool arg8, bool argC, bool arg10, bool arg14);
};

// Optionally calls vfn_120, then for each enabled flag drains and deletes every item from the corresponding list (blk88, blkbc, blkf0).
// @fnv 0x0064aec0
void AnimHost::ClearLists(bool abCallVirtual, bool abClearListBc, bool abClearList88, bool abClearListF0)
{
    if (abCallVirtual)
    {
        this->vfn_120();
    }
    KItem* pItem;
    if (abClearList88 && blk88.list.FUN_44ddc0() != 0)
    {
        pItem = *blk88.list.FUN_73ac90();
        while (pItem != 0)
        {
            delete pItem;
            blk88.list.RemoveHead();
            pItem = (blk88.list.FUN_44ddc0() != 0) ? *blk88.list.FUN_73ac90() : 0;
        }
    }
    if (abClearListBc && blkbc.list.FUN_44ddc0() != 0)
    {
        pItem = *blkbc.list.FUN_73ac90();
        while (pItem != 0)
        {
            delete pItem;
            blkbc.list.RemoveHead();
            pItem = (blkbc.list.FUN_44ddc0() != 0) ? *blkbc.list.FUN_73ac90() : 0;
        }
    }
    if (abClearListF0 && blkf0.list.FUN_44ddc0() != 0)
    {
        pItem = *blkf0.list.FUN_73ac90();
        while (pItem != 0)
        {
            delete pItem;
            blkf0.list.RemoveHead();
            pItem = (blkf0.list.FUN_44ddc0() != 0) ? *blkf0.list.FUN_73ac90() : 0;
        }
    }
}

struct FUN_0044ddc0
{
    int Call();
};
struct FUN_0064b0f0
{
    char m_unk000[0x88];
    FUN_0044ddc0 m_088;
    char m_unk088[0xbc - 0x88 - sizeof(FUN_0044ddc0)];
    FUN_0044ddc0 m_0bc;
    char m_unk0bc[0xf0 - 0xbc - sizeof(FUN_0044ddc0)];
    FUN_0044ddc0 m_0f0;
    unsigned char Check(int aiMode);
};

// Switches on aiMode and returns whether the matching member's Call() returns 0, or 1 for other modes.
// @fnv 0x0064b0f0
unsigned char FUN_0064b0f0::Check(int aiMode)
{
    switch (aiMode)
    {
    case 0:
        return m_0bc.Call() == 0;
        break;
    case 2:
        return m_088.Call() == 0;
        break;
    case 3:
        return m_0f0.Call() == 0;
        break;
    }
    return 1;
}

unsigned char FUN_0064bcb0();
void ComputeAngleRange(float*, float*);
void ClampMinMaxFromSetting(float*, float*);
void FUN_005330e0(float&, float, float);

class BSFaceGenEyeData
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    BSFaceGenKeyframeMultiple modifiers;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    float eyeHeading;
    float eyePitch;
    void SetEyeHeadingAndPitch(float heading, float pitch);
};

// Clamps heading and pitch to the eye limits, writes the normalized values into modifier slots 8-11, and stores eyeHeading and eyePitch.
// @fnv 0x0064c410
void BSFaceGenEyeData::SetEyeHeadingAndPitch(float heading, float pitch)
{
    float maxPitch6;
    float maxHeading9;
    float minHeading3;
    float minPitch;
    if (!FUN_0064bcb0())
        return;
    ComputeAngleRange(&minHeading3, &maxHeading9);
    ClampMinMaxFromSetting(&maxPitch6, &minPitch);
    FUN_005330e0(heading, minHeading3, maxHeading9);
    FUN_005330e0(pitch, maxPitch6, minPitch);
    if (heading >= 0.0)
    {
        modifiers.FUN_0064a4d0(10, heading / maxHeading9);
        modifiers.FUN_0064a4d0(9, 0.0f);
    }
    else
    {
        modifiers.FUN_0064a4d0(10, 0.0f);
        modifiers.FUN_0064a4d0(9, heading / minHeading3);
    }
    if (pitch >= 0.0)
    {
        modifiers.FUN_0064a4d0(11, pitch / minPitch);
        modifiers.FUN_0064a4d0(8, 0.0f);
    }
    else
    {
        modifiers.FUN_0064a4d0(11, 0.0f);
        modifiers.FUN_0064a4d0(8, pitch / maxPitch6);
    }
    eyeHeading = heading;
    eyePitch = pitch;
}

// 0x0064ca60  /MT /Od /Oy- /GS /EHsc /Gy
// static member: 4 stack args (float, list, keyframe, bool)

struct KFNode
{
    KFNode* next;
    KFNode* prev;
    void* data;
};

class Keyframe;

class ListBase
{
  public:
    KFNode* first;
    KFNode* last;
    unsigned count;
    Keyframe** GetHead();
    Keyframe* RemoveHead();
};

unsigned __fastcall FUN_0044ddc0(void*);

class Keyframe
{
  public:
    virtual int vfn_0(int);
    virtual int vfn_4();
    virtual void vfn_8();
    virtual float vfn_c();
    virtual void vfn_10(float);
    virtual void vfn_14();
    virtual void vfn_18();
    virtual bool vfn_1c(Keyframe*, float, int, bool);
};

struct FUN_0064ca60_shell
{
    static bool AdvanceKeyframe(float, ListBase*, Keyframe*, bool);
};

// @fnv 0x0064ca60
bool FUN_0064ca60_shell::AdvanceKeyframe(float afTime, ListBase* list, Keyframe* key, bool flag)
{
    bool result2 = false;
    if (key == 0 || list == 0)
        return false;
    if (FUN_0044ddc0(list) && *list->GetHead())
    {
        if ((*list->GetHead())->vfn_4() != key->vfn_4())
            return false;
    }
    if (FUN_0044ddc0(list) <= 0)
    {
        key->vfn_10(0.0f);
        return false;
    }
    key->vfn_10(key->vfn_c() + afTime);

    Keyframe* kf = *list->GetHead();
    while (kf != 0 && key->vfn_c() >= kf->vfn_c())
    {
        result2 |= key->vfn_1c(kf, 1.0f, 1, flag);
        key->vfn_10(key->vfn_c() - kf->vfn_c());
        list->RemoveHead();
        Keyframe* x3 = kf;
        Keyframe* y3 = x3;
        y3 ? y3->vfn_0(1) : 0;
        if (FUN_0044ddc0(list) > 0)
            kf = *list->GetHead();
        else
            kf = 0;
    }
    if (kf != 0)
        result2 |= key->vfn_1c(kf, key->vfn_c() / kf->vfn_c(), 1, flag);
    else
        key->vfn_10(0.0f);
    return result2;
}

class NiFixedString;
const NiFixedString& FUN_006499d0();

extern const NiPoint3 NiPoint3_ZERO;

class GlobalObject_0048f200
{
  public:
    int unk00;
    int unk04;
    int unk08;
    GlobalObject_0048f200();
    ~GlobalObject_0048f200();
};

class B006815c0
{
  public:
    NiPoint3 pt;
    float f130;
    float f134;
    float f138;
    float f13c;
    float f140;
    float f144;
    int i148;
    bool b14c;
    bool b14d;
    bool b14e;
    bool b14f;
    float f150;
    float f154;
    float f158;
    float f15c;
    float f160;
    float f164;
    float f168;
    float f16c;
    float f170;
    int i174;
    float f178;
    float f17c;
    int unk180;
    int unk184;
    bool b188;
    bool b189;
    bool b18a;
    bool b18b;
    bool b18c;
    bool b18d;
    bool b18e;
    bool b18f;
    bool b190;
    bool b191;
    bool b192;
    bool b193;
    float f194;
    int unk198;
    int unk19c;
    B006815c0();
};

class Actor;
template <class T> class BSSimpleList
{
  public:
    int unk00;
    int unk04;
    BSSimpleList();
};

class NiExtraData
{
  public:
    virtual void vfn_0();
    int unk04;
    int unk08;
    BSFaceGenKeyframeMultiple* target;
    NiExtraData(const NiFixedString&);
    ~NiExtraData();
};

class FUN_00649680 : public NiExtraData
{
  public:
    BSFaceGenKeyframeMultiple kf10;
    BSFaceGenKeyframeMultiple kf24;
    BSFaceGenKeyframeMultiple kf38;
    BSFaceGenKeyframeMultiple kf4c;
    BSFaceGenKeyframeMultiple kf60;
    BSFaceGenKeyframeMultiple kf74;
    GlobalObject_0048f200 obj88;
    BSFaceGenKeyframeMultiple kf94;
    BSFaceGenKeyframeMultiple kfa8;
    GlobalObject_0048f200 objbc;
    BSFaceGenKeyframeMultiple kfc8;
    BSFaceGenKeyframeMultiple kfdc;
    GlobalObject_0048f200 objf0;
    BSFaceGenKeyframeMultiple kffc;
    BSFaceGenKeyframeMultiple kf110;
    B006815c0 unk124;
    BSSimpleList<Actor*> unk1a0;

    FUN_00649680();
};

// @fnv 0x00649680
FUN_00649680::FUN_00649680()
    : NiExtraData(FUN_006499d0()), kf10(EXPRESSION, 15), kf24(EXPRESSION, 15), kf38(MODIFIER, 17), kf4c(PHONEME, 16),
      kf60(CUSTOM, 1), kf74(EXPRESSION, 15), obj88(), kf94(MODIFIER, 17), kfa8(MODIFIER, 17), objbc(),
      kfc8(PHONEME, 16), kfdc(PHONEME, 16), objf0(), kffc(CUSTOM, 1), kf110(CUSTOM, 1), unk124(), unk1a0()
{
    target = 0;
    unk124.pt = NiPoint3_ZERO;
    unk124.b18b = false;
    unk124.b188 = false;
    unk124.b18c = false;
    unk124.b18e = false;
    unk124.b191 = false;
    unk124.f194 = 0.0f;
    unk124.i174 = 0;
    unk124.f178 = 0.0f;
    unk124.f17c = 0.0f;
    unk124.f140 = 0.0f;
    unk124.f144 = 0.0f;
    unk124.i148 = 0;
    unk124.b14c = true;
    unk124.f138 = 0.0f;
    unk124.f13c = 0.0f;
    unk124.f130 = 0.0f;
    unk124.f134 = 0.0f;
    unk124.f150 = 0.0f;
    unk124.f154 = 0.0f;
    unk124.f158 = 0.0f;
    unk124.f15c = 0.0f;
    unk124.f160 = 0.0f;
    unk124.f164 = 0.0f;
    unk124.f168 = 0.0f;
    unk124.f16c = 0.0f;
    unk124.f170 = 0.0f;
    unk124.b189 = true;
    unk124.b18d = false;
    unk124.pt = NiPoint3_ZERO;
    unk124.b18f = false;
    unk124.b190 = false;
}

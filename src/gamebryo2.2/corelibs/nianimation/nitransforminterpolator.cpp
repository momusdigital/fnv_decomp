// gamebryo2.2/corelibs/nianimation/nitransforminterpolator.cpp: NiTransformInterpolator, Holder, NiTransformInterpolatorCopy, InterpolatorF7B0 (26 functions)

#include "nitransforminterpolator_decls.h"
// @fnv 0x00a3fae0
NiTransformInterpolator::NiTransformInterpolator(NiQuatTransform kTransform)
    : m_kDefaultTransform(kTransform), m_spTransformData(0)
{
    m_usLastRotationKeyIndex = 0;
    m_usLastPositionKeyIndex = 0;
    m_usLastScaleKeyIndex = 0;
    m_bPoseValid = false;
}

static inline bool TransformIsValid(const NiQuatTransform& value)
{
    return value.m_fScale != -3.4028234663852886e38 || value.m_kRotate.m_fVectorY != -3.4028234663852886e38 ||
           value.m_kTranslate.x != -3.4028234663852886e38;
}
// @fnv 0x00a3fdb0
bool NiTransformInterpolator::Update(float time, NiObjectNET* target, NiQuatTransform& value)
{
    if (m_bPoseValid)
    {
        m_fLastTime = time;
        value = m_kDefaultTransform;
        return true;
    }
    if (m_fLastTime == time)
    {
        value = m_kDefaultTransform;
        if (!TransformIsValid(m_kDefaultTransform))
            return false;
        return true;
    }
    unsigned int count;
    AnimationKey::KeyType eKeyType;
    unsigned char size;
    unsigned int last;
    PositionKeyInterpolator* pTranslateKeys = FUN_00a3f990(count, eKeyType, size);
    if (count > 0)
    {
        last = m_usLastRotationKeyIndex;
        m_kDefaultTransform.m_kTranslate =
            PositionKeyInterpolator::InterpolatePosition(time, pTranslateKeys, eKeyType, count, last, size);
        m_usLastRotationKeyIndex = (unsigned short)last;
    }
    TimedRotationKey* pRotateKeys = FUN_0058cb00(count, eKeyType, size);
    if (count > 0)
    {
        last = m_usLastPositionKeyIndex;
        m_kDefaultTransform.m_kRotate =
            TimedRotationKey::InterpolatePosition(time, pRotateKeys, eKeyType, count, last, size);
        m_usLastPositionKeyIndex = (unsigned short)last;
    }
    TimedAnimationKey* pScaleKeys = GetScaleKeys(count, eKeyType, size);
    if (count > 0)
    {
        last = m_usLastScaleKeyIndex;
        m_kDefaultTransform.m_fScale =
            TimedAnimationKey::InterpolatePosition(time, pScaleKeys, eKeyType, count, last, size);
        m_usLastScaleKeyIndex = (unsigned short)last;
    }
    value = m_kDefaultTransform;
    if (!TransformIsValid(m_kDefaultTransform))
        return false;
    m_fLastTime = time;
    return true;
}

void __fastcall FUN_00a3ca30(void* pThis);
void __cdecl FUN_00aa1460(void* p, unsigned int s);

// @fnv 0x00a40410
void* __fastcall FUN_00a40410(NiTransformInterpolator* pThis, int, unsigned int flags)
{
    NiRefObject* pkData = *(NiRefObject**)((char*)pThis + 0x2c);
    if (pkData)
        pkData->DecRefCount();
    FUN_00a3ca30(pThis);
    if (flags & 1)
        FUN_00aa1460(pThis, 0x48);
    return pThis;
}

enum KeyContent
{
    KEY_CONTENT_NONE = 0,
    KEY_CONTENT_QUATERNION = 1,
    KEY_CONTENT_POSITION = 2,
    KEY_CONTENT_ROTATION = 3,
    KEY_CONTENT_SCALE = 4,
    KEY_CONTENT_NORMAL = 5,
    KEY_CONTENT_TANGENT = 6
};

// Maps a channel index to a KeyContent: 0 quaternion, 1 position, 2 none, otherwise tangent.
// @fnv 0x00a3f570
KeyContent __stdcall FUN_00a3f570(unsigned short usChannel)
{
    if (usChannel == 0)
        return KEY_CONTENT_QUATERNION;
    if (usChannel == 1)
        return KEY_CONTENT_POSITION;
    if (usChannel == 2)
        return KEY_CONTENT_NONE;
    return KEY_CONTENT_TANGENT;
}

struct FUN_00a3f600_shell
{
    void* __thiscall FUN_00a3f600(short a);
};

// Returns the pointer stored at offset 0x14, 0x10 or 0x18 of the object at this+0x2c depending on a (0, 1, 2), or null.
// @fnv 0x00a3f600
void* FUN_00a3f600_shell::FUN_00a3f600(short aiIndex)
{
    if (aiIndex == 0)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(void**)((char*)p + 0x14);
    }
    else if (aiIndex == 1)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(void**)((char*)p + 0x10);
    }
    else if (aiIndex == 2)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(void**)((char*)p + 0x18);
    }
    return 0;
}

struct FUN_00a3f650_shell
{
    int __thiscall FUN_00a3f650(short arg);
};

// Returns a field from the object at offset 0x2c based on arg (0, 1, or 2), or 0 if that pointer is null or arg is other.
// @fnv 0x00a3f650
int __thiscall FUN_00a3f650_shell::FUN_00a3f650(short aiIndex)
{
    if (aiIndex == 0)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(int*)((char*)p + 0x24);
    }
    else if (aiIndex == 1)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(int*)((char*)p + 0x20);
    }
    else if (aiIndex == 2)
    {
        void* p = *(void**)((char*)this + 0x2c);
        if (p)
            return *(int*)((char*)p + 0x28);
    }
    return 0;
}

struct FUN_00a3f990_shell
{
    int __thiscall FUN_00a3f990(unsigned int* out1, int* out2, unsigned char* out3);
};

// Reads fields at offsets 0xa, 0x14, 0x1d and 0x24 from the object at this+0x2c into the out parameters and returns the last; zeroes them if that pointer is null.
// @fnv 0x00a3f990
int __thiscall FUN_00a3f990_shell::FUN_00a3f990(unsigned int* puiValue, int* piValue, unsigned char* pucValue)
{
    void* p = *(void**)((char*)this + 0x2c);
    if (p)
    {
        *puiValue = *(unsigned short*)((char*)p + 0xa);
        *piValue = *(int*)((char*)p + 0x14);
        *pucValue = *(unsigned char*)((char*)p + 0x1d);
        return *(int*)((char*)p + 0x24);
    }
    *puiValue = 0;
    *piValue = 0;
    *pucValue = 0;
    return 0;
}

struct FUN_00a3fad0_shell : public NiTransformInterpolator
{
    void* FUN_00a3fad0();
};

extern "C" const char* g_011f3ee0_arg1;

// @fnv 0x00a3fad0
void* FUN_00a3fad0_shell::FUN_00a3fad0()
{
    return &g_011f3ee0_arg1;
}

struct CloningProcess;
struct NiInterpolator;
struct NiObjectNET;
struct NiStream;
struct BSRotAccumTransfInterpolator : public NiTransformInterpolator
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSRotAccumTransfInterpolator*, CloningProcess*);
    virtual bool Update(float, NiObjectNET*, NiQuatTransform*);
    void __local_vftable_ctor_closure();
    NiQuaternion m_kAccumulatedRotation;
};
typedef char _sizecheck_BSRotAccumTransfInterpolator[sizeof(BSRotAccumTransfInterpolator) == 88 ? 1 : -1];
struct FUN_00a3fd10_shell : public NiTransformInterpolator
{
    NiInterpolator* FUN_00a3fd10(float, float);
};

struct FUN_00a57050_tgt
{
    FUN_00a3fd10_shell* FUN_00a57050(float, float);
};
struct FUN_00a4e410_tgt
{
    void FUN_00a4e410(float, float, NiTransformData**);
};
struct FUN_00a3f930_tgt
{
    void SetTransformData(NiTransformData*);
};
struct RcObj
{
    virtual void v0();
    virtual void Destroy();
    int m_uiRefs;
};
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

// @fnv 0x00a3fd10
NiInterpolator* FUN_00a3fd10_shell::FUN_00a3fd10(float m_fStartTime, float m_fMaximumDistance)
{
    NiTransformInterpolator* pkSeqInterp =
        (NiTransformInterpolator*)((FUN_00a57050_tgt*)this)->FUN_00a57050(m_fStartTime, m_fMaximumDistance);
    if (pkSeqInterp && *(void**)((char*)this + 0x2c))
    {
        NiTransformData* spNewData = 0;
        ((FUN_00a4e410_tgt*)*(void**)((char*)this + 0x2c))->FUN_00a4e410(m_fStartTime, m_fMaximumDistance, &spNewData);
        ((FUN_00a3f930_tgt*)pkSeqInterp)->SetTransformData(spNewData);
        *(unsigned short*)((char*)pkSeqInterp + 0x30) = 0;
        *(unsigned short*)((char*)pkSeqInterp + 0x32) = 0;
        *(unsigned short*)((char*)pkSeqInterp + 0x34) = 0;
        if (spNewData)
        {
            RcObj* o = (RcObj*)spNewData;
            if (!InterlockedDecrement((volatile long*)&o->m_uiRefs))
                o->Destroy();
        }
    }
    return (NiInterpolator*)pkSeqInterp;
}

struct FUN_00a3f5b0_t : public NiTransformInterpolator
{
    unsigned int FUN_00a3f5b0(unsigned short usChannel) const;
};
// Returns the unsigned short at offset 0xa, 0x8 or 0xc of the data pointer at this+0x2c for channel 0, 1 or 2, else 0.
// @fnv 0x00a3f5b0
unsigned int FUN_00a3f5b0_t::FUN_00a3f5b0(unsigned short usChannel) const
{
    if (usChannel == 0)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(unsigned short*)(pkData + 0xa);
    }
    else if (usChannel == 1)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(unsigned short*)(pkData + 0x8);
    }
    else if (usChannel == 2)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(unsigned short*)(pkData + 0xc);
    }
    return 0;
}

struct FUN_00a3f6a0_t : public NiTransformInterpolator
{
    bool FUN_00a3f6a0(unsigned short usChannel) const;
};
// Returns the bool flag at offset 0x1d, 0x1c or 0x1e of the data pointer at this+0x2c for channel 0, 1 or 2; false otherwise.
// @fnv 0x00a3f6a0
bool FUN_00a3f6a0_t::FUN_00a3f6a0(unsigned short usChannel) const
{
    if (usChannel == 0)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(bool*)(pkData + 0x1d);
    }
    else if (usChannel == 1)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(bool*)(pkData + 0x1c);
    }
    else if (usChannel == 2)
    {
        char* pkData = *(char**)((char*)this + 0x2c);
        if (pkData)
            return *(bool*)(pkData + 0x1e);
    }
    return false;
}

struct NiTransformData_FUN_00a4df40
{
    void FUN_00a4df40(float m_fStartTime, float m_fMaximumDistance);
};
struct FUN_00a3f6f0_t : public NiTransformInterpolator
{
    void FUN_00a3f6f0(float m_fStartTime, float m_fMaximumDistance);
};
// @fnv 0x00a3f6f0
void FUN_00a3f6f0_t::FUN_00a3f6f0(float afArg1, float afArg2)
{
    NiTransformData_FUN_00a4df40* pkData = *(NiTransformData_FUN_00a4df40**)((char*)this + 0x2c);
    if (pkData)
        pkData->FUN_00a4df40(afArg1, afArg2);
}

// Returns the scale key array from the interpolator's transform data, filling in key count, interpolation type and key size, or zeroes if no data exists.
// @fnv 0x00a3f9e0
TimedAnimationKey* NiTransformInterpolator::GetScaleKeys(unsigned int& uiNumScaleKeys,
                                                         AnimationKey::KeyType& eScaleKeyType,
                                                         unsigned char& ucScaleKeySize)
{
    NiTransformData* pkData = *(NiTransformData**)&m_spTransformData;
    if (pkData)
    {
        uiNumScaleKeys = pkData->m_usNumScaleKeys;
        eScaleKeyType = (AnimationKey::KeyType)pkData->m_eScaleKeyType;
        ucScaleKeySize = pkData->m_ucScaleKeySize;
        return pkData->m_pkScaleKeyArray;
    }
    uiNumScaleKeys = 0;
    eScaleKeyType = AnimationKey::NOINTERP;
    ucScaleKeySize = 0;
    return 0;
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a40460_shell : public NiTransformInterpolator
{
    NiObject* FUN_00a40460(CloningProcess*);
};

inline void* operator new(unsigned int, void* pkMem)
{
    return pkMem;
}
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct FUN_00a3fa30 : public NiTransformInterpolator
{
    FUN_00a3fa30(NiTransformData* pkData);
};
struct NiTransformInterpolatorCopy
{
    void FUN_00a40360(NiTransformInterpolator* pkDest, CloningProcess* kCloning);
};
// Allocates a new NiTransformInterpolator and copies this interpolator's data into it via FUN_00a40360, returning it as a NiObject.
// @fnv 0x00a40460
NiObject* FUN_00a40460_shell::FUN_00a40460(CloningProcess* kCloning)
{
    NiTransformInterpolator* pkObject = new (BSFadeNode::operator new(sizeof(NiTransformInterpolator))) FUN_00a3fa30(0);
    ((NiTransformInterpolatorCopy*)this)->FUN_00a40360(pkObject, kCloning);
    return (NiObject*)pkObject;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct RefObj
{
    virtual ~RefObj();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }
    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
};
struct Holder
{
    char _pad[0x2c];
    RefObj* m_spTransformData;
    unsigned short m_us0;
    unsigned short m_us1;
    unsigned short m_us2;
    void SetTransformData(RefObj* pkData);
};
// Replaces the held RefObj pointer with pkData, adjusting reference counts, and resets the three counters to zero.
// @fnv 0x00a3f930
void Holder::SetTransformData(RefObj* pkData)
{
    if (m_spTransformData != pkData)
    {
        if (m_spTransformData)
            m_spTransformData->DecRefCount();
        m_spTransformData = pkData;
        if (pkData)
            pkData->IncRefCount();
    }
    m_us1 = 0;
    m_us2 = 0;
    m_us0 = 0;
}

namespace fnv_00a3fa30 {
static const float DAT_01015f5c = -3.402823466e+38F;
struct FUN_00a3fa30 : public NiKeyBasedInterpolator
{
    NiQuatTransform m_kDefaultTransform;
    TransformDataPointer<NiTransformData> m_spTransformData;
    unsigned short m_usLastRotationKeyIndex;
    unsigned short m_usLastPositionKeyIndex;
    unsigned short m_usLastScaleKeyIndex;
    FUN_00a3fa30(NiTransformData* pkData);
};
// @fnv 0x00a3fa30
FUN_00a3fa30::FUN_00a3fa30(NiTransformData* pkData) : m_spTransformData(pkData)
{
    m_kDefaultTransform.m_kTranslate.x = DAT_01015f5c;
    m_kDefaultTransform.m_kRotate.m_fVectorY = DAT_01015f5c;
    m_kDefaultTransform.m_fScale = DAT_01015f5c;
    m_usLastRotationKeyIndex = 0;
    m_usLastPositionKeyIndex = 0;
    m_usLastScaleKeyIndex = 0;
    *(bool*)((char*)this + 0x44) = false;
}
}  // namespace fnv_00a3fa30

namespace fnv_00a3fb20 {
struct CloningProcess;
struct NiObjectNET;
struct NiStream;
struct BSRotAccumTransfInterpolator : public NiTransformInterpolator
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSRotAccumTransfInterpolator*, CloningProcess*);
    virtual bool Update(float, NiObjectNET*, NiQuatTransform*);
    void __local_vftable_ctor_closure();
    NiQuaternion m_kAccumulatedRotation;
};
typedef char _sizecheck_BSRotAccumTransfInterpolator[sizeof(BSRotAccumTransfInterpolator) == 88 ? 1 : -1];
struct TransformAnimationData : public TimedRotationKey
{
    static int RegisterObjectLoader();
    static void RegisterSupportedFunctions(int, int);
    static AnimationKey* CreateObjectFromStream(NiStream*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveToStream(NiStream*, AnimationKey*, unsigned int);
    static void SaveBinary(NiStream*, AnimationKey*);
    static void Copy(AnimationKey*, void*);
    static AnimationKey* CreateArray(unsigned int);
    static void DeleteArray(AnimationKey*);
    static bool Insert(float, AnimationKey**, unsigned int*);
    static float ComputeMaxCurvature(AnimationKey*, unsigned int);
    static void Interpolate(float, void*, void*, void*);
    static void InterpolateD1(float, void*, void*, void*);
    static void InterpolateD2(float, void*, void*, void*);
    static bool Equal(void*, void*);
    static void FillDerivedVals(AnimationKey*, unsigned int, unsigned char);
    void Initialize(TimedAnimationKey*, unsigned int, int, TimedAnimationKey*, unsigned int, int, TimedAnimationKey*,
                    unsigned int, int);
    void CleanUp();
    void SetKeyData(unsigned char, TimedAnimationKey*);
    void SetNumKeys(unsigned char, unsigned int);
    void SetType(unsigned char, int);
    void SetAnimationKeys(unsigned char, unsigned int, TimedAnimationKey*);
    TimedAnimationKey* GetKeys(unsigned char);
    unsigned char GetKeySize(unsigned char);
    unsigned int GetNumKeys(unsigned char);
    int GetType(unsigned char);
    void* __vecDelDtor(unsigned int);
    char _pad_4[16];
    char m_uiNumKeys[12];
    char m_eRequestType[12];
    char m_ucKeyTypes[3];
    char _pad_2f[1];
    char m_ppKeyData[12];
    char m_uiLastKeyIndex[12];
};
typedef char _sizecheck_NiEulerRotKey[sizeof(TransformAnimationData) == 72 ? 1 : -1];
struct FUN_00a3fb20_shell : public NiTransformInterpolator
{
    void FUN_00a3fb20(float*, float*);
};

extern float DAT_01097308;
extern float _DAT_01015f5c;
struct TDat
{
    char pad[8];
    unsigned short usNumRot, usNumPos, usNumScale;
    char pad0e[2];
    int eRotType, ePosType, eScaleType;
    unsigned char ucRotSize, ucPosSize, ucScaleSize;
    char pad1f;
    char* pkRot;
    char* pkPos;
    char* pkScale;
};
struct EulerK
{
    char pad[0x14];
    unsigned int m_uiNumKeys[3];
    int m_eRequestType[3];
    unsigned char m_ucKeyTypes[3];
    char pad2f;
    char* m_ppKeyData[3];
};
static inline char* TI_GetPos(TDat* d, unsigned int& n, int& t, unsigned char& s)
{
    char* pk = 0;
    if (d)
    {
        n = d->usNumPos;
        t = d->ePosType;
        s = d->ucPosSize;
        pk = d->pkPos;
    }
    else
    {
        n = 0;
    }
    return pk;
}
static inline char* TI_GetRot(TDat* d, unsigned int& n, int& t, unsigned char& s)
{
    char* pk = 0;
    if (d)
    {
        n = d->usNumRot;
        t = d->eRotType;
        s = d->ucRotSize;
        pk = d->pkRot;
    }
    else
    {
        n = 0;
    }
    return pk;
}
static inline char* TI_GetScale(TDat* d, unsigned int& n, int& t, unsigned char& s)
{
    char* pk = 0;
    if (d)
    {
        n = d->usNumScale;
        t = d->eScaleType;
        s = d->ucScaleSize;
        pk = d->pkScale;
    }
    else
    {
        n = 0;
    }
    return pk;
}
static inline float TI_Time(char* keys, unsigned int i, unsigned char s)
{
    return *(float*)(keys + i * s);
}

// Computes the first and last key times across the position, rotation and scale key arrays, defaulting both to 0 when no keys exist.
// @fnv 0x00a3fb20
void FUN_00a3fb20_shell::FUN_00a3fb20(float* fBeginKeyTime, float* fEndKeyTime)
{
    *fBeginKeyTime = DAT_01097308;
    *fEndKeyTime = _DAT_01015f5c;
    bool bHasKeys = false;

    unsigned int uiNumKeys;
    int eTransType;
    unsigned char ucSize;
    char* pkTransKeys = TI_GetPos(*(TDat**)((char*)this + 0x2c), uiNumKeys, eTransType, ucSize);
    if (uiNumKeys > 0)
    {
        float fKeyTime = TI_Time(pkTransKeys, 0, ucSize);
        if (fKeyTime < *fBeginKeyTime)
            *fBeginKeyTime = fKeyTime;
        fKeyTime = TI_Time(pkTransKeys, uiNumKeys - 1, ucSize);
        if (fKeyTime > *fEndKeyTime)
            *fEndKeyTime = fKeyTime;
        bHasKeys = true;
    }

    int eRotType;
    char* pkRotKeys = TI_GetRot(*(TDat**)((char*)this + 0x2c), uiNumKeys, eRotType, ucSize);
    if (uiNumKeys > 0)
    {
        if (eRotType == 4)
        {
            EulerK* pkEulerKey = (EulerK*)pkRotKeys;
            for (unsigned char ucAxis = 0; ucAxis < 3; ucAxis++)
            {
                unsigned int uiNumFloatKeys = pkEulerKey->m_uiNumKeys[ucAxis];
                if (uiNumFloatKeys > 0)
                {
                    char* pkFloatKeys = pkEulerKey->m_ppKeyData[ucAxis];
                    unsigned char ucFloatKeySize = pkEulerKey->m_ucKeyTypes[ucAxis];
                    float fKeyTime = TI_Time(pkFloatKeys, 0, ucFloatKeySize);
                    if (fKeyTime < *fBeginKeyTime)
                        *fBeginKeyTime = fKeyTime;
                    fKeyTime = TI_Time(pkFloatKeys, uiNumFloatKeys - 1, ucFloatKeySize);
                    if (fKeyTime > *fEndKeyTime)
                        *fEndKeyTime = fKeyTime;
                    bHasKeys = true;
                }
            }
        }
        else
        {
            float fKeyTime = TI_Time(pkRotKeys, 0, ucSize);
            if (fKeyTime < *fBeginKeyTime)
                *fBeginKeyTime = fKeyTime;
            fKeyTime = TI_Time(pkRotKeys, uiNumKeys - 1, ucSize);
            if (fKeyTime > *fEndKeyTime)
                *fEndKeyTime = fKeyTime;
            bHasKeys = true;
        }
    }

    int eScaleType;
    char* pkScaleKeys = TI_GetScale(*(TDat**)((char*)this + 0x2c), uiNumKeys, eScaleType, ucSize);
    if (uiNumKeys > 0)
    {
        float fKeyTime = TI_Time(pkScaleKeys, 0, ucSize);
        if (fKeyTime < *fBeginKeyTime)
            *fBeginKeyTime = fKeyTime;
        fKeyTime = TI_Time(pkScaleKeys, uiNumKeys - 1, ucSize);
        if (fKeyTime > *fEndKeyTime)
            *fEndKeyTime = fKeyTime;
        bHasKeys = true;
    }

    if (!bHasKeys)
    {
        *fBeginKeyTime = 0.0f;
        *fEndKeyTime = 0.0f;
    }
}
}  // namespace fnv_00a3fb20

namespace fnv_00a404b0 {
struct CloningProcess;
struct NiObjectNET;
struct NiStream;
struct BSRotAccumTransfInterpolator : public NiTransformInterpolator
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSRotAccumTransfInterpolator*, CloningProcess*);
    virtual bool Update(float, NiObjectNET*, NiQuatTransform*);
    void __local_vftable_ctor_closure();
    NiQuaternion m_kAccumulatedRotation;
};
typedef char _sizecheck_BSRotAccumTransfInterpolator[sizeof(BSRotAccumTransfInterpolator) == 88 ? 1 : -1];
struct FUN_00a404b0_shell : public NiTransformInterpolator
{
    void FUN_00a404b0(void*);
};

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct FUN_00a3cbf0_shell
{
    void FUN_00a3cbf0(StrArr*);
};
struct FUN_00a38cb0_shell
{
    void FUN_00a38cb0(StrArr*);
};
extern char* _FUN_00a7d330(char*);
extern char* g_011f3ee0_arg1;
// @fnv 0x00a404b0
void FUN_00a404b0_shell::FUN_00a404b0(void* pkStrings)
{
    ((FUN_00a3cbf0_shell*)this)->FUN_00a3cbf0((StrArr*)pkStrings);
    char* pString = _FUN_00a7d330(g_011f3ee0_arg1);
    unsigned int count = *(unsigned short*)((char*)pkStrings + 0xa);
    unsigned int size = *(unsigned short*)((char*)pkStrings + 0x8);
    if (count >= size)
        ((StrArr*)pkStrings)->SetSize(*(unsigned short*)((char*)pkStrings + 0xe) + count);
    ((StrArr*)pkStrings)->SetAt(count, pString);
    ((FUN_00a38cb0_shell*)((char*)this + 0xc))->FUN_00a38cb0((StrArr*)pkStrings);
    void* pData = *(void**)((char*)this + 0x2c);
    if (pData)
        ((void(__thiscall*)(void*, StrArr*))(*(void***)pData)[24])(pData, (StrArr*)pkStrings);
}
}  // namespace fnv_00a404b0

extern double DAT_010241b0;

class FUN_00a3f720_cls
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    float m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    float m_1c;
    unsigned int unk20;
    unsigned int unk24;
    float m_28;
    unsigned int m_2c;

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
    virtual void v55();
    virtual unsigned int v56(unsigned short arg);

    bool FUN_00a3f720(unsigned short mode);
};

// For modes 0-2, rejects when m_2c is set and v56(mode) > 0, otherwise compares the mode's float field against DAT_010241b0.
// @fnv 0x00a3f720
bool FUN_00a3f720_cls::FUN_00a3f720(unsigned short mode)
{
    double value;
    switch (mode)
    {
    case 0:
        if (m_2c != 0 && v56(mode) > 0)
        {
            return false;
        }
        value = m_0c;
        break;
    case 1:
        if (m_2c != 0 && v56(mode) > 0)
        {
            return false;
        }
        value = m_1c;
        break;
    case 2:
        if (m_2c != 0 && v56(mode) > 0)
        {
            return false;
        }
        value = m_28;
        break;
    default:
        return false;
    }
    return DAT_010241b0 != value;
}

struct S_00a3f870_Data
{
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
    virtual void __thiscall v21(unsigned int arg);
};

struct S_00a3f870_This
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    S_00a3f870_Data* unk2c;

    bool __thiscall FUN_00aa0ad0(unsigned int arg);
    bool __thiscall FUN_00a3f870(unsigned int arg);
};

// Calls FUN_00aa0ad0(arg); if it succeeds, invokes v21(arg) on unk2c when non-null and returns true, otherwise returns false.
// @fnv 0x00a3f870
bool __thiscall S_00a3f870_This::FUN_00a3f870(unsigned int arg)
{
    if (!this->FUN_00aa0ad0(arg))
        return false;

    S_00a3f870_Data* data = this->unk2c;
    if (data)
        data->v21(arg);

    return true;
}

class A3F8D0Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual bool IsEqual(A3F8D0Object* pkObject);
};

template <class T> struct A3F8D0Pointer
{
    T* m_pObject;

    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct A3F8D0Transform
{
    float m_afValues[8];

    bool operator==(const A3F8D0Transform& kOther) const;
};

class A3F8D0Interpolator : public A3F8D0Object
{
  public:
    bool BaseIsEqual(A3F8D0Object* pkObject);
    bool FUN_00a3f8d0(A3F8D0Object* pkObject);

    int unk04;
    int unk08;
    A3F8D0Transform m_kValue;
    A3F8D0Pointer<A3F8D0Object> m_spTransformData;
};

// Compares the base object, the transform value and the optional pointer's target for equality, returning true only if all match.
// @fnv 0x00a3f8d0
bool A3F8D0Interpolator::FUN_00a3f8d0(A3F8D0Object* pkObject)
{
    if (!BaseIsEqual(pkObject))
        return false;
    A3F8D0Interpolator* pkOther = (A3F8D0Interpolator*)pkObject;
    if (!(m_kValue == pkOther->m_kValue))
        return false;
    if ((m_spTransformData && !pkOther->m_spTransformData) || (!m_spTransformData && pkOther->m_spTransformData))
        return false;
    if (m_spTransformData && !m_spTransformData->IsEqual(pkOther->m_spTransformData))
        return false;
    return true;
}

struct FUN_00a95ca0_helper
{
    void __thiscall FUN_00a95ca0(NiStream* stream);
};

struct FUN_00a38b60_tgt
{
    void __thiscall FUN_00a38b60(NiStream* stream);
};

struct FUN_00a3f8a0_stream
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30(void* value);
};

struct FUN_00a3f8a0_t
{
    void* unk00;
    void* unk04;
    void* unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* unk2C;

    void __thiscall FUN_00a3f8a0(NiStream* stream);
};

// @fnv 0x00a3f8a0
void __thiscall FUN_00a3f8a0_t::FUN_00a3f8a0(NiStream* stream)
{
    reinterpret_cast<FUN_00a95ca0_helper*>(this)->FUN_00a95ca0(stream);
    reinterpret_cast<FUN_00a38b60_tgt*>(reinterpret_cast<char*>(this) + 0x0C)->FUN_00a38b60(stream);
    reinterpret_cast<FUN_00a3f8a0_stream*>(stream)->vf30(unk2C);
}

#include <string.h>

void __stdcall FUN_00aa0ab0(NiTransformInterpolator* pkDest, CloningProcess* kCloning);

struct S_00a40360_Ptr
{
    RefObj* p;
    S_00a40360_Ptr& operator=(const S_00a40360_Ptr& rhs)
    {
        if (p != rhs.p)
        {
            if (p)
                p->DecRefCount();
            p = rhs.p;
            if (p)
                p->IncRefCount();
        }
        return *this;
    }
};

struct S_00a40360_Source
{
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
    S_00a40360_Ptr unk2c;
    unsigned short unk30;
    unsigned short unk32;
    unsigned short unk34;
    unsigned short unk36;
    int unk38;
    int unk3c;
    int unk40;
};

// Calls FUN_00aa0ab0, then copies 32 bytes at offset 0x0c plus fields 0x38-0x40, the ref-counted pointer at 0x2c and the shorts at 0x30-0x34 into pkDest.
// @fnv 0x00a40360
void NiTransformInterpolatorCopy::FUN_00a40360(NiTransformInterpolator* pkDest, CloningProcess* kCloning)
{
    S_00a40360_Source* pSource = reinterpret_cast<S_00a40360_Source*>(this);
    S_00a40360_Source* pDest = reinterpret_cast<S_00a40360_Source*>(pkDest);

    FUN_00aa0ab0(pkDest, kCloning);

    memcpy(&pDest->unk0c, &pSource->unk0c, 32);

    pDest->unk38 = pSource->unk38;
    pDest->unk3c = pSource->unk3c;
    pDest->unk40 = pSource->unk40;
    pDest->unk2c = pSource->unk2c;
    pDest->unk30 = pSource->unk30;
    pDest->unk32 = pSource->unk32;
    pDest->unk34 = pSource->unk34;
}

namespace fnv_00a403f0 {
void* __cdecl FUN_00aa13e0(unsigned int size);
inline void* __cdecl operator new(unsigned int, void* address)
{
    return address;
}
// @fnv 0x00a403f0
FUN_00a3fa30* __cdecl FUN_00a403f0()
{
    void* storage = FUN_00aa13e0(sizeof(FUN_00a3fa30));
    if (storage)
        return new (storage) FUN_00a3fa30(static_cast<NiTransformData*>(0));
    return 0;
}
}  // namespace fnv_00a403f0

struct NiStreamF7B0;
class NiObjectF7B0;

struct NiPoint3F7B0
{
    float x, y, z;
};

struct NiQuatTransformF7B0
{
    bool IsTranslateValid() const
    {
        return m_kTranslate.x != -3.4028234663852886e+38;
    }
    bool IsRotateValid() const
    {
        return m_fRotX != -3.4028234663852886e+38;
    }
    bool IsScaleValid() const
    {
        return m_fScale != -3.4028234663852886e+38;
    }
    bool IsMarkedInvalid() const
    {
        return !IsScaleValid() && !IsRotateValid() && !IsTranslateValid();
    }
    void LoadBinary(NiStreamF7B0& kStream);
    NiPoint3F7B0 m_kTranslate;
    float m_fRotW;
    float m_fRotX;
    float m_fRotY;
    float m_fRotZ;
    float m_fScale;
};

struct NiStreamF7B0
{
    NiObjectF7B0* DeserializeObject();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

class NiObjectF7B0
{
  public:
    virtual ~NiObjectF7B0();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
    long m_uiRefCount;
};

template <class T> class NiPointerF7B0
{
  public:
    NiPointerF7B0& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};

class InterpolatorF7B0
{
  public:
    void LoadBinaryBase(NiStreamF7B0& kStream);
    void FUN_00a3f7b0(NiStreamF7B0& kStream);

    void* m_pVTable;
    int unk04;
    int unk08;
    NiQuatTransformF7B0 m_kDefaultTransform;
    NiPointerF7B0<NiObjectF7B0> m_spTransformData;
    int unk30;
    int unk34;
    NiPoint3F7B0 m_kLastTranslate;
    bool m_bPose;
};

// Deserializes the interpolator's default transform, transform data object, and pose flag from the stream after loading the base class.
// @fnv 0x00a3f7b0
void InterpolatorF7B0::FUN_00a3f7b0(NiStreamF7B0& kStream)
{
    LoadBinaryBase(kStream);
    m_kDefaultTransform.LoadBinary(kStream);
    m_kLastTranslate = m_kDefaultTransform.m_kTranslate;
    m_spTransformData = kStream.DeserializeObject();
    m_bPose = !m_spTransformData.m_pObject && !m_kDefaultTransform.IsMarkedInvalid();
}

struct S00a3ffd0_Pt : NiPoint3
{
    __declspec(noinline) bool FUN_00439090(const NiPoint3& p) const
    {
        return !(x == p.x && y == p.y && z == p.z);
    }
};
struct S00a3ffd0_PosKey : AnimationKey
{
    S00a3ffd0_Pt m_kPositionValue;
    S00a3ffd0_PosKey* GetKeyPointerByIndex(unsigned int ui, unsigned char ucSize)
    {
        return (S00a3ffd0_PosKey*)((char*)this + ui * ucSize);
    }
};
struct S00a3ffd0_RotKey : AnimationKey
{
    NiQuaternion m_kRotationValue;
    S00a3ffd0_RotKey* GetKeyPointerByIndex(unsigned int ui, unsigned char ucSize)
    {
        return (S00a3ffd0_RotKey*)((char*)this + ui * ucSize);
    }
};
struct S00a3ffd0_FloatKey : AnimationKey
{
    float m_fValue;
    S00a3ffd0_FloatKey* GetKeyPointerByIndex(unsigned int ui, unsigned char ucSize)
    {
        return (S00a3ffd0_FloatKey*)((char*)this + ui * ucSize);
    }
};
inline bool S00a3ffd0_QEq(const NiQuaternion& a, const NiQuaternion& q)
{
    return a.m_fVectorX == q.m_fVectorX && a.m_fVectorY == q.m_fVectorY && a.m_fVectorZ == q.m_fVectorZ &&
           a.m_fScalarPart == q.m_fScalarPart;
}
struct S00a3ffd0_Data : NiTransformData
{
    void FUN_00a4e350(unsigned int, unsigned int, unsigned int);
    void FUN_00a4e2e0(unsigned int, unsigned int, unsigned int);
    void FUN_00a4e3b0(unsigned int, unsigned int, unsigned int);
    S00a3ffd0_PosKey* GetPos(unsigned int& n, int& t, unsigned char& s) const
    {
        n = m_usNumPosKeys;
        t = m_ePositionKeyType;
        s = m_ucPositionKeySize;
        return (S00a3ffd0_PosKey*)m_pkPositionKeys;
    }
    S00a3ffd0_RotKey* GetRot(unsigned int& n, int& t, unsigned char& s) const
    {
        n = m_usNumRotKeys;
        t = m_eRotationKeyType;
        s = m_ucRotationKeySize;
        return (S00a3ffd0_RotKey*)m_pkRotationKeys;
    }
    S00a3ffd0_FloatKey* GetScale(unsigned int& n, int& t, unsigned char& s) const
    {
        n = m_usNumScaleKeys;
        t = m_eScaleKeyType;
        s = m_ucScaleKeySize;
        return (S00a3ffd0_FloatKey*)m_pkScaleKeyArray;
    }
};
struct S00a3ffd0_Interp : NiTransformInterpolator
{
    S00a3ffd0_Data* DataView()
    {
        return (S00a3ffd0_Data*)m_spTransformData.p;
    }
    void FUN_00a3ffd0();
};
// Evaluates position, rotation, and scale keys to determine if they are constant, updating m_kDefaultTransform and clearing m_spTransformData if all are absent.
// @fnv 0x00a3ffd0
void S00a3ffd0_Interp::FUN_00a3ffd0()
{
    if (!m_spTransformData.p)
        return;
    NiQuatTransform kTransform;
    unsigned int uiNumKeys;
    int eType;
    unsigned char ucSize;
    S00a3ffd0_PosKey* pkPosKeys = DataView()->GetPos(uiNumKeys, eType, ucSize);
    if (uiNumKeys == 0)
    {
        DataView()->FUN_00a4e350(0, 0, 0);
        if (m_kDefaultTransform.m_kTranslate.x != -3.4028234663852886e38)
            kTransform.m_kTranslate = m_kDefaultTransform.m_kTranslate;
    }
    else
    {
        NiPoint3 kValue = pkPosKeys->GetKeyPointerByIndex(0, ucSize)->m_kPositionValue;
        bool positionConstant = false;
        if (uiNumKeys == 1)
        {
            positionConstant = true;
        }
        else if (eType == 1 || eType == 5)
        {
            positionConstant = true;
            for (unsigned int ui = 1; positionConstant && ui < uiNumKeys; ui++)
            {
                if (pkPosKeys->GetKeyPointerByIndex(ui, ucSize)->m_kPositionValue.FUN_00439090(kValue))
                    positionConstant = false;
            }
        }
        if (positionConstant)
        {
            DataView()->FUN_00a4e350(0, 0, 0);
            kTransform.m_kTranslate = kValue;
        }
        else if (m_kDefaultTransform.m_kTranslate.x != -3.4028234663852886e38)
            kTransform.m_kTranslate = m_kDefaultTransform.m_kTranslate;
    }
    S00a3ffd0_RotKey* pkRotKeys = DataView()->GetRot(uiNumKeys, eType, ucSize);
    if (uiNumKeys == 0)
    {
        DataView()->FUN_00a4e2e0(uiNumKeys, uiNumKeys, uiNumKeys);
        if (m_kDefaultTransform.m_kRotate.m_fVectorY != -3.4028234663852886e38)
            kTransform.m_kRotate = m_kDefaultTransform.m_kRotate;
    }
    else
    {
        NiQuaternion kValue;
        kValue = pkRotKeys->GetKeyPointerByIndex(0, ucSize)->m_kRotationValue;
        bool rotationConstant;
        try
        {
            if (uiNumKeys == 1 && eType != 4)
                goto constant52;
            if (eType != 1 && eType != 5)
                goto fallback52;
        }
        catch (...)
        {
            throw;
        }
        rotationConstant = true;
        for (unsigned int ui = 1; rotationConstant && ui < uiNumKeys; ui++)
        {
            if (!S00a3ffd0_QEq(pkRotKeys->GetKeyPointerByIndex(ui, ucSize)->m_kRotationValue, kValue))
                rotationConstant = false;
        }
    done52:;
        if (rotationConstant)
        {
        constant52:
            DataView()->FUN_00a4e2e0(0, 0, 0);
            kTransform.m_kRotate = kValue;
        }
        else
        {
        fallback52:
            if (m_kDefaultTransform.m_kRotate.m_fVectorY != -3.4028234663852886e38)
                kTransform.m_kRotate = m_kDefaultTransform.m_kRotate;
        }
    }
    S00a3ffd0_FloatKey* pkScaleKeys = DataView()->GetScale(uiNumKeys, eType, ucSize);
    if (uiNumKeys == 0)
    {
        DataView()->FUN_00a4e3b0(0, 0, 0);
        if (m_kDefaultTransform.m_fScale != -3.4028234663852886e38)
            kTransform.m_fScale = m_kDefaultTransform.m_fScale;
    }
    else
    {
        float kValue = pkScaleKeys->GetKeyPointerByIndex(0, ucSize)->m_fValue;
        bool scaleConstant = false;
        if (uiNumKeys == 1)
        {
            scaleConstant = true;
        }
        else if (eType == 1 || eType == 5)
        {
            scaleConstant = true;
            for (unsigned int ui = 1; scaleConstant && ui < uiNumKeys; ui++)
            {
                if (pkScaleKeys->GetKeyPointerByIndex(ui, ucSize)->m_fValue != kValue)
                    scaleConstant = false;
            }
        }
        if (scaleConstant)
        {
            DataView()->FUN_00a4e3b0(0, 0, 0);
            kTransform.m_fScale = kValue;
        }
        else if (m_kDefaultTransform.m_fScale != -3.4028234663852886e38)
            kTransform.m_fScale = m_kDefaultTransform.m_fScale;
    }
    if (!DataView()->m_usNumPosKeys && !DataView()->m_usNumRotKeys && !DataView()->m_usNumScaleKeys)
        m_spTransformData = 0;
    m_kDefaultTransform = kTransform;
}

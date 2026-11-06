
// src/gamebryo2.2/corelibs/nianimation/niquaternioninterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niquaternioninterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

enum NiAnimationKey_KeyContent
{
    kCONTENT_NONE = 0,
    kCONTENT_INT = 1,
    kCONTENT_FLOAT = 2,
    kCONTENT_BOOL = 3,
    kCONTENT_BARYC = 4,
    kCONTENT_QUATERNION = 5,
    kCONTENT_VECTOR = 6,
    kCONTENT_MATRIX = 7,
    kCONTENT_COLOR = 8,
    kCONTENT_LIGHT = 9
};

struct AnimationKey
{
    typedef NiAnimationKey_KeyContent KeyContent;
};

struct NiKeyBasedInterpolator
{
};

struct NiQuaternionInterpolator : NiKeyBasedInterpolator
{
    AnimationKey::KeyContent __stdcall GetKeyContent();
};

// @fnv 0x00a487e0
AnimationKey::KeyContent __stdcall NiQuaternionInterpolator::GetKeyContent()
{
    return kCONTENT_FLOAT;
}

namespace fnv_00a48960 {
struct NiRotData;
template <class T> struct NiPointer
{
    T* m_p;
};
struct NiKeyBasedInterpolator
{
};
struct NiQuaternionInterpolator : NiKeyBasedInterpolator
{
    NiPointer<NiRotData> m_spQuaternionData;
    void FUN_00a48960(float m_fStartTime, float m_fMaximumDistance);
};

struct NiRotData
{
    void FUN_00a48f70(float, float);
};

// @fnv 0x00a48960
void NiQuaternionInterpolator::FUN_00a48960(float m_fStartTime, float m_fMaximumDistance)
{
    NiRotData* p = *(NiRotData**)((char*)this + 0x1c);
    if (p)
        p->FUN_00a48f70(m_fStartTime, m_fMaximumDistance);
}
}  // namespace fnv_00a48960

extern "C" const void* g_011f3f60;

// @fnv 0x00a48ab0
const void* __cdecl FUN_00a48ab0()
{
    return &g_011f3f60;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

extern int DAT_010986f4;
extern int DAT_011f4208;
extern int DAT_011f420c;
extern int DAT_011f4210;
extern int DAT_011f4214;

struct NiKeyBasedInterpolatorHelper
{
    void NiKeyBasedInterpolator();
};

struct NiQuaternionInterpolator;

// @fnv 0x00a48d70
NiQuaternionInterpolator* __cdecl CreateNiQuaternionInterpolator()
{
    NiQuaternionInterpolator* p = (NiQuaternionInterpolator*)BSFadeNode::operator new(0x24);
    if (p)
    {
        ((NiKeyBasedInterpolatorHelper*)p)->NiKeyBasedInterpolator();
        *(int*)(p) = (int)&DAT_010986f4;
        *(int*)(p + 0xc) = DAT_011f4208;
        *(int*)(p + 0x10) = DAT_011f420c;
        *(int*)(p + 0x14) = DAT_011f4210;
        *(int*)(p + 0x18) = DAT_011f4214;
        *(int*)(p + 0x1c) = 0;
        *(int*)(p + 0x20) = 0;
        return p;
    }
    return 0;
}

struct NiStream
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void SaveLink(void*);
};
struct FUN_00a95ca0_helper
{
    void FUN_00a95ca0(NiStream*);
};
struct QVal
{
    char data[16];
    void FUN_00a6e4a0(NiStream*);
};
struct TargetWrap
{
    char _0[12];
    QVal _q;
    void* _p;
    void SaveToStream(NiStream*);
};
// @fnv 0x00a48a20
void TargetWrap::SaveToStream(NiStream* kStream)
{
    ((FUN_00a95ca0_helper*)this)->FUN_00a95ca0(kStream);
    _q.FUN_00a6e4a0(kStream);
    kStream->SaveLink(_p);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void __cdecl _delete(void*, unsigned int);
struct RefObj
{
    virtual void F0();
    virtual void F1();
    long m_ref;
};
struct FUN_00a3ca30_shell
{
    void __thiscall FUN_00a3ca30();
};
struct FUN_00a48dd0_shell
{
    char _pad[0x1c];
    RefObj* m_p;
    char _pad2[4];
    void* __thiscall Release(unsigned int);
};
// @fnv 0x00a48dd0
void* __thiscall FUN_00a48dd0_shell::Release(unsigned int uiDeleteFlags)
{
    RefObj* p = m_p;
    if (p)
    {
        if (InterlockedDecrement(&p->m_ref) == 0)
            p->F1();
    }
    ((FUN_00a3ca30_shell*)this)->FUN_00a3ca30();
    if (uiDeleteFlags & 1)
        _delete(this, 0x24);
    return this;
}

// Stand-in for the game's NiBound (a 4 x float bounding volume) and for the
// interpolator object that owns GetChannelPosed.
//
// Object layout taken from the disassembly of the original:
//   +0x00 .. +0x0b   the NiKeyBasedInterpolator part of the object
//   +0x0c .. +0x1b   the NiBound value of the object
//   +0x1c            pointer to the key data (null when the interpolator is constant)

class NiBound
{
  public:
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fBoundRadius;
    bool __thiscall FUN_00a92660(const NiBound& other);
};

// The default bound every interpolator is compared against.
extern NiBound g_NiBoundDefault;

struct NiQuaternionInterpolatorStandIn
{
    int unk00;
    int unk04;
    int unk08;
    NiBound m_bound;
    RefObj* m_pKeyData;
    bool __thiscall GetChannelPosed(unsigned int nTime);
};

// @fnv 0x00a48800
bool NiQuaternionInterpolatorStandIn::GetChannelPosed(unsigned int nTime)
{
    if (m_pKeyData != 0)
        return false;
    bool bIsDefault = !m_bound.FUN_00a92660(g_NiBoundDefault);
    return bIsDefault;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct NiQuaternion
{
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    bool operator!=(const NiQuaternion& q) const;
};

struct TimedRotationKey
{
    float m_fTime;
    NiQuaternion m_kRotationValue;
};

extern NiQuaternion g_kInvalidQuat;

struct NiRefObject
{
    virtual void Dtor();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct NiRotData : NiRefObject
{
    unsigned int m_uiNumKeys;
    TimedRotationKey* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    TimedRotationKey* ComputePositionAtTime(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const
    {
        uiNumKeys = m_uiNumKeys;
        eType = m_eRequestType;
        ucSize = m_ucKeyDataSize;
        return m_pKeyArray;
    }
};

template <class T> struct NiPointerT
{
    T* m_pObject;
    NiPointerT& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
        }
        return *this;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct NiQuatInterp
{
    void* vtbl;
    int unk04;
    int unk08;
    NiQuaternion m_kQuaternionValue;
    NiPointerT<NiRotData> m_spQuaternionData;
    void CollapseQuatInterp();
};

// @fnv 0x00a48820
void NiQuatInterp::CollapseQuatInterp()
{
    if (m_spQuaternionData)
    {
        unsigned int uiNumKeys;
        int eType;
        unsigned char ucSize;
        TimedRotationKey* pkKeys = m_spQuaternionData->ComputePositionAtTime(uiNumKeys, eType, ucSize);
        if (uiNumKeys == 0)
        {
            m_spQuaternionData = 0;
            m_kQuaternionValue = g_kInvalidQuat;
        }
        else
        {
            NiQuaternion kValue = pkKeys->m_kRotationValue;
            if (uiNumKeys != 1 || eType == 4)
            {
                if (eType != 1 && eType != 5)
                    return;
                bool bAllEqual = true;
                for (unsigned int i = 1; bAllEqual && i < uiNumKeys; i++)
                {
                    TimedRotationKey* pk = (TimedRotationKey*)((char*)pkKeys + i * ucSize);
                    if (pk->m_kRotationValue != kValue)
                        bAllEqual = false;
                }
                if (!bAllEqual)
                    return;
            }
            m_spQuaternionData = 0;
            m_kQuaternionValue = kValue;
        }
    }
}

class BA48A50Object
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual bool IsEqual(BA48A50Object* pkObject);
};

template <class T> class BA48A50Pointer
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
    bool operator!() const
    {
        return m_pObject == 0;
    }

    T* m_pObject;
};

class BA48A50Quaternion
{
  public:
    bool operator!=(const BA48A50Quaternion& kQuat) const;

    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

class BA48A50Base : public BA48A50Object
{
  public:
    bool BaseIsEqual(BA48A50Object* pkObject);

    int unk04;
    int unk08;
};

class BA48A50Interpolator : public BA48A50Base
{
  public:
    bool FUN_00a48a50(BA48A50Object* pkObject);

    BA48A50Quaternion m_kValue;
    BA48A50Pointer<BA48A50Object> m_spTransformData;
};

// @fnv 0x00a48a50
bool BA48A50Interpolator::FUN_00a48a50(BA48A50Object* pkObject)
{
    if (!BaseIsEqual(pkObject))
        return false;

    BA48A50Interpolator* pkOther = (BA48A50Interpolator*)pkObject;

    if (m_kValue != pkOther->m_kValue)
        return false;

    if ((m_spTransformData && !pkOther->m_spTransformData) || (!m_spTransformData && pkOther->m_spTransformData))
        return false;

    if (m_spTransformData && !m_spTransformData->IsEqual(pkOther->m_spTransformData))
        return false;

    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* p);

struct FUN_00a48bc0_cls
{
    int unk00[7];
    RefObj* m_1c;
    int m_20;

    FUN_00a48bc0_cls* FUN_00a57050(float a, float b);
    FUN_00a48bc0_cls* Interpolate(float a, float b);
};

struct InterpHelper
{
    void CopyTo(float a, float b, RefObj** out);
};

inline void DecRef(RefObj* p)
{
    if (InterlockedDecrement(&p->m_ref) == 0)
        p->F1();
}

inline void Assign(RefObj*& dst, RefObj* src)
{
    if (dst != src)
    {
        if (dst)
            DecRef(dst);
        dst = src;
        if (dst)
            InterlockedIncrement(&dst->m_ref);
    }
}

// @fnv 0x00a48bc0
FUN_00a48bc0_cls* FUN_00a48bc0_cls::Interpolate(float a, float b)
{
    FUN_00a48bc0_cls* pResult = FUN_00a57050(a, b);
    if (m_1c)
    {
        RefObj* pInterp = 0;
        ((InterpHelper*)m_1c)->CopyTo(a, b, &pInterp);
        Assign(pResult->m_1c, pInterp);
        pResult->m_20 = 0;
        if (pInterp)
            DecRef(pInterp);
    }
    return pResult;
}

extern "C" const void* g_011f3f60;
extern "C" char DAT_01098800;
extern "C" char DAT_010987ec;

struct Stream
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;

    void __thiscall FUN_0096ad30(unsigned int index);
    void __thiscall FUN_0096ae90(unsigned int index, void** value);
};
struct Storage
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* __thiscall FUN_00a6e190(void* value);
};
void* __cdecl FUN_00a7d330(const void* value);
void* __cdecl FUN_00a7d5a0(const void* key, void* value);

struct QuaternionInterpolator
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    Storage unk0c;
    void* unk1c;

    void __thiscall GetViewerStrings(Stream* stream);
    void __thiscall FUN_00a48ea0(Stream* stream);
};

// @fnv 0x00a48ea0
void QuaternionInterpolator::FUN_00a48ea0(Stream* stream)
{
    GetViewerStrings(stream);
    void* value = FUN_00a7d330(g_011f3f60);
    unsigned int index = stream->unk0a;
    if (index >= stream->unk08)
        stream->FUN_0096ad30(index + stream->unk0e);
    stream->FUN_0096ae90(index, &value);

    value = unk0c.FUN_00a6e190(&DAT_01098800);
    index = stream->unk0a;
    if (index >= stream->unk08)
        stream->FUN_0096ad30(index + stream->unk0e);
    stream->FUN_0096ae90(index, &value);

    void* payload = unk1c;
    value = FUN_00a7d5a0(&DAT_010987ec, payload);
    index = stream->unk0a;
    if (index >= stream->unk08)
        stream->FUN_0096ad30(index + stream->unk0e);
    stream->FUN_0096ae90(index, &value);
}

struct Quat48c
{
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    Quat48c()
    {}
    Quat48c(float w, float x, float y, float z) : m_fVectorX(w), m_fVectorY(x), m_fVectorZ(y), m_fScalarPart(z)
    {}
    bool FUN_00a92660(const Quat48c& q) const;
    bool operator==(const Quat48c& q) const
    {
        return FUN_00a92660(q);
    }
    bool operator!=(const Quat48c& q) const
    {
        return !FUN_00a92660(q);
    }
};
struct RotKey48c
{
    float m_fTime;
    Quat48c m_kRotationValue;
};
Quat48c __cdecl FUN_00a28740(float fTime, RotKey48c* pkKeys, int eType, unsigned int uiNumKeys,
                             unsigned int* puiLastIdx, unsigned char ucSize);

struct RotData48c
{
    void* vtbl;
    long m_uiRefCount;
    unsigned int m_uiNumKeys;
    RotKey48c* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    RotKey48c* ComputePositionAtTime(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const
    {
        uiNumKeys = m_uiNumKeys;
        eType = m_eRequestType;
        ucSize = m_ucKeyDataSize;
        return m_pKeyArray;
    }
};
struct ObjNET48c;

class QuatInterp48c
{
  public:
    void* vtbl;
    int m_uiRefCount;
    float m_fLastTime;
    Quat48c m_kQuaternionValue;
    RotData48c* m_spQuaternionData;
    unsigned int m_uiLastKeyIndex;

    bool TimeHasChanged(float fTime)
    {
        return m_fLastTime != fTime;
    }
    RotKey48c* GetKeys(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const
    {
        if (m_spQuaternionData)
            return m_spQuaternionData->ComputePositionAtTime(uiNumKeys, eType, ucSize);
        uiNumKeys = 0;
        eType = 0;
        ucSize = 0;
        return 0;
    }
    bool GetQuaternionAtTime(float fTime, ObjNET48c* pkInterpTarget, Quat48c& kValue);
};

// @fnv 0x00a48c80
bool QuatInterp48c::GetQuaternionAtTime(float fTime, ObjNET48c* pkInterpTarget, Quat48c& kValue)
{
    if (!TimeHasChanged(fTime))
    {
        kValue = m_kQuaternionValue;
        if (m_kQuaternionValue == (*(const Quat48c*)&DAT_011f4208))
            return false;
        return true;
    }

    unsigned int uiNumKeys;
    int eType;
    unsigned char ucSize;
    RotKey48c* pkKeys = GetKeys(uiNumKeys, eType, ucSize);
    if (uiNumKeys > 0)
    {
        m_kQuaternionValue = FUN_00a28740(fTime, pkKeys, eType, uiNumKeys, &m_uiLastKeyIndex, ucSize);
    }

    if (m_kQuaternionValue == (*(const Quat48c*)&DAT_011f4208))
        return false;

    kValue = m_kQuaternionValue;
    m_fLastTime = fTime;
    return true;
}

extern const float DAT_010986e8;
extern const float DAT_01015f5c;
struct KeyTrackData
{
    float m_00;
    int unk04, unk08, unk0c, unk10, m_14, m_18, m_1c, unk20, unk24, unk28;
    unsigned char m_2c, m_2d, m_2e;
    float* m_30;
    float* m_34;
    float* m_38;
};
struct KeyDesc
{
    int unk00, unk04;
    unsigned int m_08;
    KeyTrackData* m_0c;
    volatile int m_10;
    unsigned char m_14;
};
struct FUN_00a48ac0_cls
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    KeyDesc* m_1c;
    void GetKeyRange(float*, float*);
};
// @fnv 0x00a48ac0
void FUN_00a48ac0_cls::GetKeyRange(float* outLo, float* outHi)
{
    KeyDesc* p = m_1c;
    if (p)
    {
        unsigned int count = p->m_08;
        int type = p->m_10;
        unsigned char stride = p->m_14;
        KeyTrackData* base = p->m_0c;
        if (count > 0)
        {
            if (type == 4)
            {
                float fKey;
                float lo = DAT_010986e8;
                float hi = DAT_01015f5c;
                unsigned char* pucStride = &base->m_2c;
                float** pk = &base->m_30;
                int iTrack = 3;
                do
                {
                    float* key = *pk;
                    fKey = key[0];
                    int iKeyCount = *(int*)((char*)pk - 0x1c);
                    unsigned char ucKeyStride = *pucStride;
                    if (fKey < lo)
                        lo = fKey;
                    fKey = *(float*)((char*)key + (iKeyCount - 1) * ucKeyStride);
                    if (fKey > hi)
                        hi = fKey;
                    pk++;
                    pucStride++;
                } while (--iTrack);
                *outLo = lo;
                *outHi = hi;
                return;
            }
            *outLo = base->m_00;
            *outHi = *(float*)((char*)base + (count - 1) * stride);
            return;
        }
    }
    *outLo = 0.0f;
    *outHi = 0.0f;
}

class CloningProcess;
struct A48E20_Color
{
    float r, g, b, a;
};

void* __cdecl FUN_00aa13e0(unsigned int size);
struct A48E20_Base
{
    void FUN_00a3ca10() throw();
};
struct A48E20_Object : A48E20_Base
{
    void* m_pVtable;
    int unk04;
    int unk08;
    A48E20_Color m_0C;
    int m_1C;
    int m_20;

    static void* operator new(unsigned int size)
    {
        return FUN_00aa13e0(size);
    }
    A48E20_Object()
    {
        FUN_00a3ca10();
        m_pVtable = &DAT_010986f4;
        m_0C = *reinterpret_cast<const A48E20_Color*>(&DAT_011f4208);
        m_1C = 0;
        *(volatile int*)&m_20 = 0;
    }
};
struct A48E20_Owner
{
    void FUN_00a3c0a0(A48E20_Object* clone, CloningProcess* cloning);
    A48E20_Object* Clone(CloningProcess* cloning);
};
// Allocates a new A48E20_Object, initializes it via FUN_00a3c0a0 with the given CloningProcess, and returns the new object.
// @fnv 0x00a48e20
A48E20_Object* A48E20_Owner::Clone(CloningProcess* cloning)
{
    A48E20_Object* clone = new A48E20_Object;
    FUN_00a3c0a0(clone, cloning);
    return clone;
}

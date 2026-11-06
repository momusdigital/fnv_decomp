
// src/gamebryo2.2/corelibs/nianimation/bsrotaccumtransfinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bsrotaccumtransfinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiRTTI
{
};

extern NiRTTI g_011f3ee0;

// @fnv 0x00a43ab0
NiRTTI* __cdecl FUN_00a43ab0()
{
    return &g_011f3ee0;
}

struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct NiTransformInterpolator
{
    void* vfptr;
    char _pad[68];
    void CopyMemberData(int);
};
struct NiQuaternion
{
    float x;
    float y;
    float z;
    float w;
    static const NiQuaternion IDENTITY;
};
extern int DAT_01097af4;
extern int DAT_011a9ea8;
extern int DAT_011a9eac;
extern int DAT_011a9eb0;
struct BSRotAccumTransfInterpolator : NiTransformInterpolator
{
    int q0;
    int q1;
    int q2;
    int RunFourthVirtual;
};
// Allocates a 0x58-byte BSRotAccumTransfInterpolator, initializes its vtable and quaternion fields from NiQuaternion::IDENTITY and globals, and returns it.
// @fnv 0x00a43e40
BSRotAccumTransfInterpolator* CreateRotAccumTransfInterpolator()
{
    BSRotAccumTransfInterpolator* pInterpolator = (BSRotAccumTransfInterpolator*)BSFadeNode::operator new(0x58);
    if (pInterpolator)
    {
        pInterpolator->CopyMemberData(0);
        pInterpolator->vfptr = (void*)&DAT_01097af4;
        pInterpolator->q0 = *(int*)&NiQuaternion::IDENTITY;
        pInterpolator->q1 = DAT_011a9ea8;
        pInterpolator->q2 = DAT_011a9eac;
        pInterpolator->RunFourthVirtual = DAT_011a9eb0;
        return pInterpolator;
    }
    return 0;
}

extern int DAT_011a9ea4;

void* __cdecl FUN_00aa13e0(unsigned int size);

struct FUN_00a3fa30_cls
{
    void FUN_00a3fa30(int a);
};

struct QuadInts
{
    int a;
    int b;
    int c;
    int d;
};

struct FUN_00a43e90_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    QuadInts m_48;
    void FUN_00a40360(BSRotAccumTransfInterpolator* obj, int a);
    BSRotAccumTransfInterpolator* CreateInterpolator(int a);
};

// @fnv 0x00a43e90
BSRotAccumTransfInterpolator* FUN_00a43e90_cls::CreateInterpolator(int a)
{
    BSRotAccumTransfInterpolator* obj = (BSRotAccumTransfInterpolator*)FUN_00aa13e0(0x58);
    if (obj != 0)
    {
        ((FUN_00a3fa30_cls*)obj)->FUN_00a3fa30(0);
        obj->vfptr = (void*)&DAT_01097af4;
        obj->q0 = DAT_011a9ea4;
        obj->q1 = DAT_011a9ea8;
        obj->q2 = DAT_011a9eac;
        obj->RunFourthVirtual = DAT_011a9eb0;
    }
    else
    {
        obj = 0;
    }
    FUN_00a40360(obj, a);
    *(QuadInts*)&obj->q0 = m_48;
    return obj;
}

struct TimedRotationKey
{
    float m_fTime;
    NiQuaternion m_kRotationValue;
};

struct NiTransformData
{
    int unk00;
    int unk04;
    unsigned short m_usNumRotKeys;
    short unk0a;
    int unk0c;
    int m_eRotationKeyType;
    int unk14;
    int unk18;
    unsigned char m_ucRotationKeySize;
    char unk1d[3];
    TimedRotationKey* m_pkRotationKeys;
};

struct BaseInterp
{
    int unk00[11];
    NiTransformData* m_spTransformData;

    TimedRotationKey* GetRotData(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const
    {
        if (m_spTransformData)
        {
            uiNumKeys = m_spTransformData->m_usNumRotKeys;
            eType = m_spTransformData->m_eRotationKeyType;
            ucSize = m_spTransformData->m_ucRotationKeySize;
            return m_spTransformData->m_pkRotationKeys;
        }
        uiNumKeys = 0;
        eType = 0;
        ucSize = 0;
        return 0;
    }

    void __thiscall FUN_00a43330(int a);
};

struct FUN_00a43ac0_Class : BaseInterp
{
    int unk30[6];
    NiQuaternion m_kRotValue;

    void __thiscall UpdateRotValue(int a);
};

// Calls FUN_00a43330, then copies the first rotation key's quaternion into m_kRotValue when rotation keys exist.
// @fnv 0x00a43ac0
void FUN_00a43ac0_Class::UpdateRotValue(int a)
{
    FUN_00a43330(a);
    unsigned int uiNumKeys;
    int eType;
    unsigned char ucSize;
    TimedRotationKey* pkKeys = GetRotData(uiNumKeys, eType, ucSize);
    if (uiNumKeys != 0)
    {
        m_kRotValue = pkKeys[0].m_kRotationValue;
    }
}

void __cdecl FUN_00a3f7b0();
// @fnv 0x00a43a70
void __cdecl FUN_00a43a70()
{
    FUN_00a3f7b0();
}

extern void __cdecl FUN_00a3f870();

// @fnv 0x00a43a80
void __cdecl FUN_00a43a80()
{
    FUN_00a3f870();
}

void __cdecl FUN_00a3f8a0();
// @fnv 0x00a43a90
void __cdecl FUN_00a43a90()
{
    FUN_00a3f8a0();
}

extern void FUN_00a3f8d0();

// @fnv 0x00a43aa0
void FUN_00a43aa0()
{
    FUN_00a3f8d0();
}

#include <string.h>
struct PositionValue
{
    float x, y, z;
    PositionValue& operator=(const PositionValue& r)
    {
        memcpy(this, &r, sizeof(*this));
        return *this;
    }
};
struct QuaternionValue
{
    float x, y, z, w;
    __declspec(noinline) QuaternionValue FUN_00a2bcf0(const QuaternionValue& q) const
    {
        QuaternionValue r;
        r.w = w * q.w - x * q.x - y * q.y - z * q.z;
        r.x = w * q.x + x * q.w + y * q.z - z * q.y;
        r.y = w * q.y + y * q.w + z * q.x - x * q.z;
        r.z = w * q.z + z * q.w + x * q.y - y * q.x;
        return r;
    }
    void FUN_00a38560();
    void FUN_00a6df40(const void*);
};
struct QQuatOps : QuaternionValue
{
    QQuatOps()
    {}
    QQuatOps(const QuaternionValue& r)
    {
        memcpy(this, &r, sizeof(r));
    }
};
struct ConjugateValue : QuaternionValue
{
    ConjugateValue(const ConjugateValue& r)
    {
        memcpy(this, &r, sizeof(*this));
    }
};
struct TransformValue
{
    PositionValue position;
    QuaternionValue rotation;
    float scale;
    TransformValue& operator=(const TransformValue& r)
    {
        memcpy(this, &r, sizeof(*this));
        return *this;
    }
    bool IsValid() const
    {
        if (scale == -3.4028234663852886e38 && rotation.y == -3.4028234663852886e38 &&
            position.x == -3.4028234663852886e38)
            return false;
        return true;
    }
};
ConjugateValue __cdecl FUN_00a6dc00(const QuaternionValue&);
PositionValue __cdecl FUN_00a27490(float, void*, int, unsigned int, unsigned int&, unsigned char);
QuaternionValue __cdecl FUN_00a28740(float, void*, int, unsigned int, unsigned int&, unsigned char);
float __cdecl InterpolateKey(float, void*, int, unsigned int, unsigned int&, unsigned char);
struct RotationObject
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    float matrix00;
};
struct RotAccumInterpolator
{
    void* vfptr;
    int unk04;
    float lastTime;
    TransformValue value;
    void* data;
    unsigned short positionIndex, rotationIndex, scaleIndex;
    unsigned short unk36;
    int unk38, unk3c, unk40;
    bool alwaysUpdate;
    unsigned char unk45;
    unsigned short unk46;
    QuaternionValue previousRotation;
    void* FUN_00a3f990(unsigned int*, int*, unsigned char*);
    void* FUN_0058cb00(unsigned int*, int*, unsigned char*);
    void* GetScaleKeys(unsigned int*, int*, unsigned char*);
    bool Evaluate(float time, RotationObject* object, TransformValue& result);
};
// Evaluates position, rotation and scale keys at time, applies rotation delta to object matrix, and stores the result in result.
// @fnv 0x00a43b00
bool RotAccumInterpolator::Evaluate(float time, RotationObject* object, TransformValue& result)
{
    if (alwaysUpdate)
    {
        lastTime = time;
        result = value;
        return true;
    }
    if (lastTime == time)
    {
        result = value;
        return value.IsValid();
    }
    unsigned int count;
    int type;
    unsigned char stride;
    unsigned int index;
    void* keys = FUN_00a3f990(&count, &type, &stride);
    if (count > 0)
    {
        index = positionIndex;
        value.position = FUN_00a27490(time, keys, type, count, index, stride);
        positionIndex = (unsigned short)index;
    }
    keys = FUN_0058cb00(&count, &type, &stride);
    if (count > 0)
    {
        index = rotationIndex;
        QuaternionValue rotation = FUN_00a28740(time, keys, type, count, index, stride);
        if (object)
        {
            QQuatOps delta = rotation.FUN_00a2bcf0(FUN_00a6dc00(previousRotation));
            QQuatOps objectRotation;
            objectRotation.FUN_00a6df40(&object->matrix00);
            (QuaternionValue&)objectRotation = objectRotation.FUN_00a2bcf0(delta);
            objectRotation.FUN_00a38560();
            value.rotation = objectRotation;
        }
        else
        {
            value.rotation = rotation;
        }
        previousRotation = rotation;
        rotationIndex = (unsigned short)index;
    }
    {
        int scaleType;
        keys = GetScaleKeys(&count, &scaleType, &stride);
        if (count > 0)
        {
            index = scaleIndex;
            value.scale = InterpolateKey(time, keys, scaleType, count, index, stride);
            scaleIndex = (unsigned short)index;
        }
    }
    result = value;
    if (!value.IsValid())
        return false;
    lastTime = time;
    return true;
}

#include <windows.h>
extern int DAT_01097af4;

struct a43df0_Counted
{
    virtual void v00();
    virtual void Release();
    int refCount;
};

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00a43df0_cls
{
    int m_vptr;
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
    a43df0_Counted* m_pCounted;
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

    void BaseCleanup();
    FUN_00a43df0_cls* FUN_00a43df0(unsigned char acFlags);
};

// Decrements the referenced object's count and calls Release at zero, then calls BaseCleanup and FUN_00aa1460 when bit 0 is set.
// @fnv 0x00a43df0
FUN_00a43df0_cls* FUN_00a43df0_cls::FUN_00a43df0(unsigned char acFlags)
{
    *(volatile int*)&m_vptr = (int)&DAT_01097af4;
    a43df0_Counted* pCounted = *(a43df0_Counted* volatile*)&m_pCounted;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->refCount) == 0)
        {
            pCounted->Release();
        }
    }
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x58);
    }
    return this;
}

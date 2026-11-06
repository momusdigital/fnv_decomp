// gamebryo2.2/corelibs/nianimation/nibsplinetransforminterpolator.cpp: NiBSplineTransformInterpolator, SplineWork, BSplineTransformLoad (15 functions)

#include "nibsplinetransforminterpolator_decls.h"
// Loads the base interpolator and transform, then reads the translation, rotation and scale handles from the stream.
// @fnv 0x00a50470
void NiBSplineTransformInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineInterpolator::LoadBinary(stream);
    m_kTransform.LoadBinary(stream);
    stream.m_pUnderlyingStream->ReadScalar(&m_uiTranslationHandle, 4);
    stream.m_pUnderlyingStream->ReadScalar(&m_uiRotationHandle, 4);
    stream.m_pUnderlyingStream->ReadScalar(&m_uiScaleHandle, 4);
}

// Maps channel 0 to 3, 1 to 4 and 2 to 1, returning 0 for any other channel.
// @fnv 0x00a4fde0
unsigned int __stdcall FUN_00a4fde0(unsigned short usChannel)
{
    switch (usChannel)
    {
    case 0:
        return 3;
    case 1:
        return 4;
    case 2:
        return 1;
    }
    return 0;
}

// Returns 3 for channels 0, 1 and 2, and 0 for any other channel value.
// @fnv 0x00a4fe20
unsigned int __stdcall FUN_00a4fe20(unsigned short usChannel)
{
    switch (usChannel)
    {
    case 0:
        return 3;
    case 1:
        return 3;
    case 2:
        return 3;
    }
    return 0;
}

struct FUN_00a4fe50_obj
{
    char pad[0x3c];
    unsigned int m_kTransCPHandle;
    unsigned int m_kRotCPHandle;
    unsigned int m_kScaleCPHandle;
};
// Returns the stored handle for channel 0, 1 or 2 (translation, rotation, scale), or 0xffff for any other channel.
// @fnv 0x00a4fe50
unsigned int __fastcall GetChannelHandle(FUN_00a4fe50_obj* self, int, unsigned short usChannel)
{
    switch (usChannel)
    {
    case 0:
        return self->m_kTransCPHandle;
    case 1:
        return self->m_kRotCPHandle;
    case 2:
        return self->m_kScaleCPHandle;
    }
    return 0xffff;
}

struct FUN_00a4fe80_obj
{
    char pad[0x3c];
    unsigned int m_kTransCPHandle;
    unsigned int m_kRotCPHandle;
    unsigned int m_kScaleCPHandle;
};
// Stores kControlHandle into the translation, rotation or scale control-point handle field selected by usChannel (0, 1 or 2).
// @fnv 0x00a4fe80
void __fastcall SetControlPointHandle(FUN_00a4fe80_obj* self, int, unsigned int kControlHandle,
                                      unsigned short usChannel)
{
    switch (usChannel)
    {
    case 0:
        self->m_kTransCPHandle = kControlHandle;
        break;
    case 1:
        self->m_kRotCPHandle = kControlHandle;
        break;
    case 2:
        self->m_kScaleCPHandle = kControlHandle;
        break;
    }
}

extern double _DAT_010241b0;
struct FUN_00a50090_obj
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3();
    virtual void Unk4();
    virtual void Unk5();
    virtual void Unk6();
    virtual void Unk7();
    virtual void Unk8();
    virtual void Unk9();
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void Unk38();
    virtual void Unk39();
    virtual void Unk40();
    virtual void Unk41();
    virtual void Unk42();
    virtual void Unk43();
    virtual void Unk44();
    virtual void Unk45();
    virtual void Unk46();
    virtual void Unk47();
    virtual void Unk48();
    virtual void Unk49();
    virtual void Unk50();
    virtual void Unk51();
    virtual void Unk52();
    virtual void Unk53();
    virtual void Unk54();
    virtual void Unk55();
    virtual unsigned int GetNumCPs(unsigned short);
    char pad[0x1c - 4];
    float m_uiX;
    char pad2[0x2c - 0x20];
    float m_uiY;
    char pad3[0x38 - 0x30];
    float m_uiZ;
};
// Returns true when the given channel has no control points and its stored value differs from _DAT_010241b0; false otherwise.
// @fnv 0x00a50090
bool __fastcall FUN_00a50090(FUN_00a50090_obj* self, int, unsigned short usChannel)
{
    switch (usChannel)
    {
    case 0:
        if (self->GetNumCPs(usChannel) > 0)
            return false;
        return self->m_uiX != _DAT_010241b0;
    case 1:
        if (self->GetNumCPs(usChannel) > 0)
            return false;
        return self->m_uiY != _DAT_010241b0;
    case 2:
        if (self->GetNumCPs(usChannel) > 0)
            return false;
        return self->m_uiZ != _DAT_010241b0;
    default:
        return false;
    }
}

struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct FUN_00a50110_quat
{
    char data[0x20];
};
struct FUN_00a50110_proc;
struct FUN_00a4fff0;
struct FUN_00a50110_obj : public BSFadeNode
{
    char pad[0x1c];
    FUN_00a50110_quat m_kDefaultTransform;
    unsigned int m_kTransCPHandle;
    unsigned int m_kRotCPHandle;
    unsigned int m_kScaleCPHandle;
    FUN_00a50110_obj(int, unsigned short, unsigned short, unsigned short, int) throw();
    void FUN_00a57fd0(FUN_00a50110_obj*, FUN_00a50110_proc&);
};
// @fnv 0x00a50110
FUN_00a50110_obj* __fastcall CreateClone(FUN_00a50110_obj* self, int, FUN_00a50110_proc* kCloning)
{
    FUN_00a50110_obj* pkObject = new FUN_00a50110_obj(0, 0xffff, 0xffff, 0xffff, 0);
    self->FUN_00a57fd0(pkObject, *kCloning);
    pkObject->m_kDefaultTransform = self->m_kDefaultTransform;
    pkObject->m_kTransCPHandle = self->m_kTransCPHandle;
    pkObject->m_kRotCPHandle = self->m_kRotCPHandle;
    pkObject->m_kScaleCPHandle = self->m_kScaleCPHandle;
    return pkObject;
}

namespace fnv_00a50180 {
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct FUN_00a4fff0 : public BSFadeNode
{
    FUN_00a4fff0(int, unsigned short, unsigned short, unsigned short, int) throw();
    int m_data[18];
};
// Allocates and constructs a FUN_00a4fff0 with arguments 0, 0xffff, 0xffff, 0xffff, 0, returning the new object.
// @fnv 0x00a50180
FUN_00a4fff0* FUN_00a50180()
{
    return new FUN_00a4fff0(0, 0xffff, 0xffff, 0xffff, 0);
}
}  // namespace fnv_00a50180

struct FUN_00a501b0_quat
{
    char data[0x20];
    bool Equals(const FUN_00a501b0_quat*);
};
struct FUN_00a501b0_obj
{
    char pad[0x1c];
    FUN_00a501b0_quat m_kDefaultTransform;
    unsigned int m_kTransCPHandle;
    unsigned int m_kRotCPHandle;
    unsigned int m_kScaleCPHandle;
    bool FUN_00a57e90(FUN_00a501b0_obj*);
};
// Returns true if the object passes FUN_00a57e90, its quaternion matches, and the trans, rot and scale CP handles all match the other object's.
// @fnv 0x00a501b0
bool __fastcall IsEqual(FUN_00a501b0_obj* self, int, FUN_00a501b0_obj* pkObject)
{
    if (self->FUN_00a57e90(pkObject) && self->m_kDefaultTransform.Equals(&pkObject->m_kDefaultTransform) &&
        pkObject->m_kTransCPHandle == self->m_kTransCPHandle && pkObject->m_kRotCPHandle == self->m_kRotCPHandle &&
        pkObject->m_kScaleCPHandle == self->m_kScaleCPHandle)
        return true;
    return false;
}

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00a50070_cls
{
    int unk00;

    void BaseCleanup();

    FUN_00a50070_cls* Destroy(unsigned char acFlags);
};

// @fnv 0x00a50070
FUN_00a50070_cls* FUN_00a50070_cls::Destroy(unsigned char acFlags)
{
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x48);
    }
    return this;
}

struct SplineVector
{
    float x, y, z;
    SplineVector(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
struct SplineQuaternion
{
    float w, x, y, z;
    SplineQuaternion(float a, float b, float c, float d)
    {
        Set(a, b, c, d);
    }
    void Set(float, float, float, float);
    void NormalizeQuaternion();
};
struct SplineTransform
{
    SplineVector translation;
    SplineQuaternion rotation;
    float scale;
    bool Valid() const
    {
        return scale != -3.4028234663852886e+38 || rotation.x != -3.4028234663852886e+38 ||
               translation.x != -3.4028234663852886e+38;
    }
};
struct SplineData
{
    void FUN_00a52550(float, float*, unsigned, void*, unsigned);
};
struct SplineWork
{
    unsigned unk00, unk04;
    float lastTime, startTime, endTime;
    SplineData* data;
    void* basis;
    SplineTransform transform;
    unsigned translationHandle, rotationHandle, scaleHandle;
    bool EvaluateSpline(float, void*, SplineTransform&);
};
// Samples translation, rotation and scale from the spline data at the given time, caches the transform, and returns whether it is valid.
// @fnv 0x00a50200
bool SplineWork::EvaluateSpline(float time, void*, SplineTransform& output)
{
    if (lastTime == time)
    {
        output = transform;
        if (!transform.Valid())
            return false;
        return true;
    }
    float ratio = (time - startTime) / (endTime - startTime);
    float values[4];
    if (translationHandle != 0xffff)
    {
        data->FUN_00a52550(ratio, values, 3, basis, translationHandle);
        transform.translation = SplineVector(values[0], values[1], values[2]);
    }
    if (rotationHandle != 0xffff)
    {
        data->FUN_00a52550(ratio, values, 4, basis, rotationHandle);
        SplineQuaternion quat(values[0], values[1], values[2], values[3]);
        quat.NormalizeQuaternion();
        transform.rotation = quat;
    }
    if (scaleHandle != 0xffff)
    {
        data->FUN_00a52550(ratio, values, 1, basis, scaleHandle);
        transform.scale = values[0];
    }
    output = transform;
    if (!transform.Valid())
        return false;
    lastTime = time;
    return true;
}

class A503E0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A503E0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A503E0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A503E0Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    A503E0BinaryStream* m_pBackingStream;
};

template <class T>
inline void A503E0BinaryStreamSave(A503E0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A503E0SaveBinary(A503E0Stream& kStream, const T& value)
{
    A503E0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

struct A503E0Color
{
    float r;
    float g;
    float b;
    float a;

    void SaveBinary(A503E0Stream& kStream);
};

class A503E0Base
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;

    void SaveToStream(A503E0Stream& kStream);
};

class A503E0Light : public A503E0Base
{
  public:
    A503E0Color m_kFogTint;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    float m_fValue0;
    float m_fValue1;
    float m_fValue2;

    void FUN_00a503e0(A503E0Stream& kStream);
};

// Saves the base data, color, and three float values of the light to the stream.
// @fnv 0x00a503e0
void A503E0Light::FUN_00a503e0(A503E0Stream& kStream)
{
    SaveToStream(kStream);
    m_kFogTint.SaveBinary(kStream);
    A503E0SaveBinary(kStream, m_fValue0);
    A503E0SaveBinary(kStream, m_fValue1);
    A503E0SaveBinary(kStream, m_fValue2);
}

extern unsigned int _DAT_011f3fe4;
extern unsigned char _DAT_010996bc;
extern unsigned char _DAT_010996ac;
extern unsigned char _DAT_01099698;
unsigned int __cdecl FUN_00a7d330(unsigned int);
unsigned int __cdecl FUN_00a7d510(const unsigned char*, unsigned int);

struct BinaryStreamPosition
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, unsigned int*);
};
struct BSplineBaseCalls : NiBSplineInterpolator
{
    void FUN_00a58200(NiStream&);
};
struct QuatLoadCalls : NiQuatTransform
{
    void FUN_00a38cb0(NiStream&);
};
struct BSplineTransformLoad : NiBSplineTransformInterpolator
{
    void LoadBSplineTransform(NiStream& stream);
};
// Loads the base interpolator, the quaternion transform and the translation, rotation and scale handles from the stream.
// @fnv 0x00a50500
void BSplineTransformLoad::LoadBSplineTransform(NiStream& stream)
{
    reinterpret_cast<BSplineBaseCalls*>(this)->FUN_00a58200(stream);
    BinaryStreamPosition& pos = reinterpret_cast<BinaryStreamPosition&>(stream);
    unsigned int value = FUN_00a7d330(_DAT_011f3fe4);
    unsigned int index = pos.unk0A;
    if (index >= pos.unk08)
        pos.FUN_0096ad30(index + pos.unk0E);
    pos.FUN_0096ae90(index, &value);

    reinterpret_cast<QuatLoadCalls&>(m_kTransform).FUN_00a38cb0(stream);
    value = FUN_00a7d510(&_DAT_010996bc, m_uiTranslationHandle);
    index = pos.unk0A;
    if (index >= pos.unk08)
        pos.FUN_0096ad30(index + pos.unk0E);
    pos.FUN_0096ae90(index, &value);

    value = FUN_00a7d510(&_DAT_010996ac, m_uiRotationHandle);
    index = pos.unk0A;
    if (index >= pos.unk08)
        pos.FUN_0096ad30(index + pos.unk0E);
    pos.FUN_0096ae90(index, &value);

    value = FUN_00a7d510(&_DAT_01099698, m_uiScaleHandle);
    index = pos.unk0A;
    if (index >= pos.unk08)
        pos.FUN_0096ad30(index + pos.unk0E);
    pos.FUN_0096ae90(index, &value);
}

extern float g_fInitA;
extern float g_fInitB;
extern int g_vtable_00a57f20;
extern long(__stdcall* g_pfnInterlockedIncrement)(long volatile* value);

struct FUN_00a57f20_base
{
    void Init();
};

struct FUN_00a57f20_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    float m_0c;
    float m_10;
    void* m_14;
    void* m_18;

    FUN_00a57f20_cls* FUN_00a57f20(void* a, void* b);
};

// @fnv 0x00a57f20
FUN_00a57f20_cls* FUN_00a57f20_cls::FUN_00a57f20(void* pFirst, void* pSecond)
{
    reinterpret_cast<FUN_00a57f20_base*>(this)->Init();
    m_0c = g_fInitA;
    long(__stdcall * pfnInterlockedIncrement)(long volatile*) = g_pfnInterlockedIncrement;
    m_10 = g_fInitB;
    *(int**)this = &g_vtable_00a57f20;
    m_14 = pFirst;
    if (pFirst != 0)
    {
        pfnInterlockedIncrement((long volatile*)((char*)pFirst + 4));
    }
    m_18 = pSecond;
    if (pSecond != 0)
    {
        pfnInterlockedIncrement((long volatile*)((char*)pSecond + 4));
    }
    return this;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);

struct FUN_00a57fd0_ref
{
    virtual void Unknown();
    virtual void Delete();
    volatile long references;
    FUN_00a57fd0_ref* FUN_00a5d3f0(FUN_00a50110_proc&);
};
struct FUN_00a57fd0_fields
{
    void* vtable;
    unsigned int state04;
    unsigned int state08;
    volatile float value0c;
    float value10;
    FUN_00a57fd0_ref* object14;
    FUN_00a57fd0_ref* object18;
    void FUN_00aa1000(FUN_00a50110_obj*, FUN_00a50110_proc&);
};

// @fnv 0x00a57fd0
void FUN_00a50110_obj::FUN_00a57fd0(FUN_00a50110_obj* destination, FUN_00a50110_proc& cloning)
{
    FUN_00a57fd0_fields* source = reinterpret_cast<FUN_00a57fd0_fields*>(this);
    FUN_00a57fd0_fields* target = reinterpret_cast<FUN_00a57fd0_fields*>(destination);
    source->FUN_00aa1000(destination, cloning);
    target->value10 = source->value10;
    target->value0c = source->value0c;

    FUN_00a57fd0_ref* previous = *reinterpret_cast<FUN_00a57fd0_ref* volatile*>(&target->object14);
    if (previous != source->object14)
    {
        if (previous && InterlockedDecrement(&previous->references) == 0)
            previous->Delete();
        target->object14 = source->object14;
        if (target->object14)
            InterlockedIncrement(&target->object14->references);
    }

    if (source->object18)
    {
        FUN_00a57fd0_ref* clone = source->object18->FUN_00a5d3f0(cloning);
        FUN_00a57fd0_ref* existing = target->object18;
        if (existing != clone)
        {
            if (existing && InterlockedDecrement(&existing->references) == 0)
                existing->Delete();
            target->object18 = clone;
            if (clone)
                InterlockedIncrement(&clone->references);
        }
    }
}

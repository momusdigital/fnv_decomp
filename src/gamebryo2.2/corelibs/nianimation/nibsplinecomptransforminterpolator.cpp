// gamebryo2.2/corelibs/nianimation/nibsplinecomptransforminterpolator.cpp: NiBSplineCompTransformInterpolator, Holder, SThis (11 functions)

#include "nibsplinecomptransforminterpolator_decls.h"
#include "nibsplinecomptransforminterpolator_types_NiBSplineCompTransformInterpolator.h"
#include "nibsplinecomptransforminterpolator_types_NiStream.h"
#include "nibsplinecomptransforminterpolator_types_NiBSplineData.h"
#include "nibsplinecomptransforminterpolator_types_NiCloningProcess.h"

extern double _DAT_010241b0;

// @fnv 0x00a51140
void NiBSplineCompTransformInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineTransformInterpolator::LoadBinary(stream);

    stream.m_pUnderlyingStream->ReadComp(m_afOffsetAndHalfRange, 0x18, 4);
}

// Copies the spline transform interpolator's translation, rotation and scale control-point handles and an extra field into destination.
// @fnv 0x00a4fec0
void NiBSplineCompTransformInterpolator::CopyMemberData(NiBSplineCompTransformInterpolator* destination,
                                                        CloningProcess& cloningProcess)
{
    FUN_00a57fd0(destination, cloningProcess);
    destination->m_kDefaultTransform = m_kDefaultTransform;
    destination->m_kTransCPHandle = m_kTransCPHandle;
    destination->m_kRotCPHandle = m_kRotCPHandle;
    destination->m_kScaleCPHandle = m_kScaleCPHandle;
}

// @fnv 0x00a50f60
bool NiBSplineCompTransformInterpolator::Update(float time, NiObjectNET* target, NiQuatTransform& value)
{
    if (m_fLastTime == time)
    {
        NiQuatTransform* transformValue = &m_kDefaultTransform;
        value = *transformValue;
        if (transformValue->m_fScale == _DAT_010241b0 && transformValue->m_kRotate.m_fVectorY == _DAT_010241b0 &&
            transformValue->m_kTranslate.x == _DAT_010241b0)
            return false;
        return true;
    }

    float normalizedTime = (time - m_fStartTime) / (m_fEndTime - m_fStartTime);
    union DecodedValue
    {
        float values[4];
        NiQuaternion rotation;
    } decodedValue;
    NiPoint3 translation;
    if (m_kTransCPHandle != 0xffff)
    {
        m_spTransformData.m_pObject->CalculateSplineValue(normalizedTime, decodedValue.values, 3,
                                                          m_spSplineBasisData.m_pObject, m_kTransCPHandle,
                                                          m_afOffsetAndHalfRange[0], m_afOffsetAndHalfRange[1]);
        translation.x = decodedValue.values[0];
        translation.y = decodedValue.values[1];
        translation.z = decodedValue.values[2];
        m_kDefaultTransform.m_kTranslate = translation;
    }
    if (m_kRotCPHandle != 0xffff)
    {
        m_spTransformData.m_pObject->CalculateSplineValue(normalizedTime, decodedValue.values, 4,
                                                          m_spSplineBasisData.m_pObject, m_kRotCPHandle,
                                                          m_afOffsetAndHalfRange[2], m_afOffsetAndHalfRange[3]);
        m_kDefaultTransform.m_kRotate = decodedValue.rotation;
        m_kDefaultTransform.m_kRotate.EnsureCanonicalSign();
    }
    if (m_kScaleCPHandle != 0xffff)
    {
        m_spTransformData.m_pObject->CalculateSplineValue(normalizedTime, decodedValue.values, 1,
                                                          m_spSplineBasisData.m_pObject, m_kScaleCPHandle,
                                                          m_afOffsetAndHalfRange[4], m_afOffsetAndHalfRange[5]);
        m_kDefaultTransform.m_fScale = decodedValue.values[0];
    }

    NiQuatTransform* transformValue = &m_kDefaultTransform;
    value = *transformValue;
    if (transformValue->m_fScale == _DAT_010241b0 && transformValue->m_kRotate.m_fVectorY == _DAT_010241b0 &&
        transformValue->m_kTranslate.x == _DAT_010241b0)
        return false;
    m_fLastTime = time;
    return true;
}

void __fastcall FUN_00a57f80(void* pThis);

struct NiMemObject_DeleteHelper : public NiMemObject
{
    static void __cdecl operator delete(void* p, size_t s);
};

// Calls FUN_00a57f80 on pThis, then frees pThis with the delete helper when flags has bit 0 set, and returns pThis.
// @fnv 0x00a50e50
void* __fastcall FUN_00a50e50(void* pThis, int, unsigned int flags)
{
    FUN_00a57f80(pThis);
    if (flags & 1)
    {
        NiMemObject_DeleteHelper::operator delete(pThis, 0x60);
    }
    return pThis;
}

extern int g_011f4004;

// @fnv 0x00a50e40
int* __cdecl FUN_00a50e40()
{
    return &g_011f4004;
}

struct FUN_00a501b0_caller
{
    bool IsEqual(NiObject*);
};
struct FUN_00a50e00_shell : NiBSplineCompTransformInterpolator
{
    bool IsEqual(NiObject* pkObject);
};
// @fnv 0x00a50e00
bool FUN_00a50e00_shell::IsEqual(NiObject* pkObject)
{
    NiBSplineCompTransformInterpolator* pkDest;
    unsigned int ui;
    if (!((FUN_00a501b0_caller*)this)->IsEqual(pkObject))
        return false;
    pkDest = (NiBSplineCompTransformInterpolator*)pkObject;
    for (ui = 0; ui < 6; ui++)
    {
        if (m_afOffsetAndHalfRange[ui] != pkDest->m_afOffsetAndHalfRange[ui])
            return false;
    }
    return true;
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
extern int g_011f4004;
char* _FUN_00a7d330(const char*);
struct Holder
{
    void LoadBSplineTransform(StrArr*);
    void AppendString(StrArr*);
};
// @fnv 0x00a511c0
void Holder::AppendString(StrArr* pkStrings)
{
    LoadBSplineTransform(pkStrings);
    char* s = _FUN_00a7d330((const char*)g_011f4004);
    unsigned int uiSize = *(unsigned short*)((char*)pkStrings + 0xa);
    unsigned int uiCapacity = *(unsigned short*)((char*)pkStrings + 8);
    if (uiSize >= uiCapacity)
    {
        unsigned int grow = *(unsigned short*)((char*)pkStrings + 0xe);
        pkStrings->SetSize(uiSize + grow);
    }
    pkStrings->SetAt(uiSize, s);
}

struct SOut
{
    int _pad0;
    int m_pos;
    int(__cdecl* m_pfnRead)(SOut*, void*, unsigned int, unsigned int*, unsigned int);
    int(__cdecl* m_pfnWrite)(SOut*, void*, unsigned int, unsigned int*, unsigned int);
};
struct SStream
{
    char _pad[0x250];
    SOut* m_out;
};
struct SBase
{
    void FUN_00a503e0(SStream&);
};
struct SThis
{
    char _pad[0x48];
    char m_buf[0x18];
    void FUN_00a51180(SStream&);
};
// @fnv 0x00a51180
void SThis::FUN_00a51180(SStream& stream)
{
    ((SBase*)this)->FUN_00a503e0(stream);
    SOut* __restrict output = stream.m_out;
    unsigned int size = 4;
    output->m_pos += output->m_pfnWrite(output, m_buf, 0x18, &size, 1);
}

extern int DAT_011a8400;
extern int DAT_011a8404;
extern int DAT_011a8408;
extern int DAT_011f3704;
extern int DAT_011f3708;
extern int DAT_011f370c;
extern int DAT_011f3710;
extern float DAT_01096b8c;
extern int DAT_0109957c;

struct BaseHolder
{
    void FUN_00a57f20(int, int);
};

struct FUN_00a4fff0_t : BaseHolder
{
    int m_vft;
    int m_f04;
    int m_f08;
    int m_f0c;
    int m_f10;
    int m_f14;
    int m_f18;
    int m_f1c;
    int m_f20;
    int m_f24;
    int m_f28;
    int m_f2c;
    int m_f30;
    int m_f34;
    float m_f38;
    int m_f3c;
    int m_f40;
    int m_f44;
    FUN_00a4fff0_t(int, int, int, int, int);
};

// Calls the base constructor with a and e, sets the vtable, copies global values into fields m_f1c..m_f38, and stores b, c, d in m_f3c..m_f44.
// @fnv 0x00a4fff0
FUN_00a4fff0_t::FUN_00a4fff0_t(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    FUN_00a57f20(aiArg1, aiArg5);
    m_vft = (int)&DAT_0109957c;
    m_f1c = DAT_011a8400;
    m_f20 = DAT_011a8404;
    m_f24 = DAT_011a8408;
    m_f28 = DAT_011f3704;
    m_f2c = DAT_011f3708;
    m_f30 = DAT_011f370c;
    m_f34 = DAT_011f3710;
    m_f38 = DAT_01096b8c;
    m_f3c = aiArg2;
    m_f40 = aiArg3;
    m_f44 = aiArg4;
}

static const float NI_INFINITY = 3.402823466e+38f;
static const float g_fA50F00Invalid = NI_INFINITY;

struct BA50F00Range
{
    BA50F00Range() : m_fLow(g_fA50F00Invalid), m_fHigh(g_fA50F00Invalid)
    {}

    float m_fLow;
    float m_fHigh;
};

class BA50F00Interpolator
{
  public:
    static void* operator new(unsigned int uiSize);

    BA50F00Interpolator(int iFlags, unsigned short usA, unsigned short usB, unsigned short usC, int iD);
    virtual ~BA50F00Interpolator();

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
};

class BA50F00Evaluator : public BA50F00Interpolator
{
  public:
    __forceinline BA50F00Evaluator() throw() : BA50F00Interpolator(0, 0xffff, 0xffff, 0xffff, 0)
    {}
    virtual ~BA50F00Evaluator();

    BA50F00Range m_kRangeX;
    BA50F00Range m_kRangeY;
    BA50F00Range m_kRangeZ;
};

// Allocates and constructs a new BA50F00Evaluator and returns it as a BA50F00Interpolator pointer.
// @fnv 0x00a50f00
BA50F00Interpolator* __cdecl CreateEvaluator()
{
    return new BA50F00Evaluator;
}

class A50E70CloningProcess;

class A50E70Base
{
  public:
    A50E70Base(int iA, unsigned short usB, unsigned short usC, unsigned short usD, int iE) throw();
    virtual ~A50E70Base();
    static void* operator new(unsigned int uiSize) throw();
    static void operator delete(void* pvMem);

    void CopyMemberData(A50E70Base* pkDest, A50E70CloningProcess& kCloning);
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
};

struct A50E70Range
{
    float m_fMin0;
    float m_fMin1;
    float m_fMin2;
    float m_fMax0;
    float m_fMax1;
    float m_fMax2;

    A50E70Range() throw()
        : m_fMin0(NI_INFINITY), m_fMin1(NI_INFINITY), m_fMin2(NI_INFINITY), m_fMax0(NI_INFINITY), m_fMax1(NI_INFINITY),
          m_fMax2(NI_INFINITY)
    {}
};

class A50E70Object : public A50E70Base
{
  public:
    __forceinline A50E70Object() throw() : A50E70Base(0, 0xffff, 0xffff, 0xffff, 0)
    {}
    virtual ~A50E70Object();

    __forceinline void CopyMemberData(A50E70Object* pkDest, A50E70CloningProcess& kCloning)
    {
        A50E70Base::CopyMemberData(pkDest, kCloning);
        pkDest->m_kRange.m_fMin0 = m_kRange.m_fMin0;
        pkDest->m_kRange.m_fMin1 = m_kRange.m_fMin1;
        pkDest->m_kRange.m_fMin2 = m_kRange.m_fMin2;
        pkDest->m_kRange.m_fMax0 = m_kRange.m_fMax0;
        pkDest->m_kRange.m_fMax1 = m_kRange.m_fMax1;
        pkDest->m_kRange.m_fMax2 = m_kRange.m_fMax2;
    }
    A50E70Object* CreateClone(A50E70CloningProcess& kCloning);

    A50E70Range m_kRange;
};

// @fnv 0x00a50e70
A50E70Object* A50E70Object::CreateClone(A50E70CloningProcess& kCloning)
{
    A50E70Object* pkDest = new A50E70Object;
    CopyMemberData(pkDest, kCloning);
    return pkDest;
}

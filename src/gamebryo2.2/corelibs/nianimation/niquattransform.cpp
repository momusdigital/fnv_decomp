// gamebryo2.2/corelibs/nianimation/niquattransform.cpp: NiQuatTransform, QXform, QXformViewer, QXform2 (8 functions)

#include "niquattransform_types_NiQuatTransform.h"
#include "niquattransform_types_NiStream.h"
#include "niquattransform_types_NiColor.h"
#include "niquattransform_types_NiColorA.h"

#include "niquattransform_binary.h"

// Reads translation, rotation and scale from the stream; for older versions reads validity bytes and sets invalid components to kInvalidTransformValue.
// @fnv 0x00a38bb0
void NiQuatTransform::LoadBinary(NiStream& stream)
{
    reinterpret_cast<NiColor&>(m_kTranslate).LoadBinary(stream);
    reinterpret_cast<RgbaColor&>(m_kRotate).LoadBinary(stream);
    stream.m_pUnderlyingStream->ReadScalar(&m_fScale, 4);
    if (stream.m_uiNifVersion < 0x0A01006E)
    {
        unsigned char valid;
        stream.m_pUnderlyingStream->ReadScalar(&valid, 1);
        if (!valid)
            m_kTranslate.x = kInvalidTransformValue;
        stream.m_pUnderlyingStream->ReadScalar(&valid, 1);
        if (!valid)
            m_kRotate.m_fVectorY = kInvalidTransformValue;
        stream.m_pUnderlyingStream->ReadScalar(&valid, 1);
        if (!valid)
            m_fScale = kInvalidTransformValue;
    }
}

struct Inner_00a6db50
{
    void __thiscall Set(float, float, float, float);
};
struct Outer_00a2bdb0
{
    int _0;
    Inner_00a6db50 _4;
    Outer_00a2bdb0* __thiscall FUN_00a2bdb0();
};
// Calls the inner object's method with four zero floats and returns this.
// @fnv 0x00a2bdb0
Outer_00a2bdb0* __thiscall Outer_00a2bdb0::FUN_00a2bdb0()
{
    _4.Set(0.0f, 0.0f, 0.0f, 0.0f);
    return this;
}

extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
struct QQuatOps
{
    NiQuaternion FUN_00a2bcf0(const NiQuaternion& q) const;
    void FUN_00a38560();
};
struct QXform
{
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
    QXform() : m_kTranslate(DAT_011a8400), m_kRotate(DAT_011f3704), m_fScale(kInvalidTransformValue)
    {}
    bool IsScaleValid() const
    {
        return m_fScale != -3.4028234663852886e38;
    }
    bool IsRotateValid() const
    {
        return m_kRotate.m_fVectorY != -3.4028234663852886e38;
    }
    bool IsTranslateValid() const
    {
        return m_kTranslate.x != -3.4028234663852886e38;
    }
    void MakeScaleInvalid()
    {
        m_fScale = kInvalidTransformValue;
    }
    void MakeRotateInvalid()
    {
        m_kRotate.m_fVectorY = kInvalidTransformValue;
    }
    void MakeTranslateInvalid()
    {
        m_kTranslate.x = kInvalidTransformValue;
    }
    QXform FUN_00a38a00(const QXform& kXform) const;
};
// @fnv 0x00a38a00
QXform QXform::FUN_00a38a00(const QXform& kXform) const
{
    QXform kResult;
    if (IsScaleValid() && kXform.IsScaleValid())
        kResult.m_fScale = kXform.m_fScale * m_fScale;
    else
        kResult.MakeScaleInvalid();
    if (IsRotateValid() && kXform.IsRotateValid())
    {
        NiQuaternion kRotate = ((const QQuatOps*)&m_kRotate)->FUN_00a2bcf0(kXform.m_kRotate);
        ((QQuatOps*)&kRotate)->FUN_00a38560();
        kResult.m_kRotate = kRotate;
    }
    else
        kResult.MakeRotateInvalid();
    if (IsTranslateValid() && kXform.IsTranslateValid())
    {
        NiPoint3 kTranslate;
        kTranslate.x = kXform.m_kTranslate.x + m_kTranslate.x;
        kTranslate.y = kXform.m_kTranslate.y + m_kTranslate.y;
        kTranslate.z = kXform.m_kTranslate.z + m_kTranslate.z;
        kResult.m_kTranslate = kTranslate;
    }
    else
        kResult.MakeTranslateInvalid();
    return kResult;
}

char* GetViewerStringName(const char* pcName);
char* GetViewerStringFloat(const char* pcName, float fValue);

struct ViewerPoint3 : NiPoint3
{
    char* FormatToBuffer(const char* pcName) const;
};
struct ViewerQuaternion : NiQuaternion
{
    char* FormatToBuffer(const char* pcName) const;
};

struct ViewerStrings
{
    virtual ~ViewerStrings();
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& pcElement);
    unsigned int Add(char*& pcElement)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
};

struct QXformViewer : QXform
{
    void FUN_00a38cb0(ViewerStrings* pkStrings);
};

// Appends the class name and, when valid, the translate, rotate and scale members to the viewer string list.
// @fnv 0x00a38cb0
void QXformViewer::FUN_00a38cb0(ViewerStrings* pkStrings)
{
    char* pcString = GetViewerStringName("NiQuatTransform");
    pkStrings->Add(pcString);
    if (IsTranslateValid())
    {
        char* pcString = static_cast<ViewerPoint3&>(m_kTranslate).FormatToBuffer("m_kTranslate");
        pkStrings->Add(pcString);
    }
    if (IsRotateValid())
    {
        char* pcString = static_cast<ViewerQuaternion&>(m_kRotate).FormatToBuffer("m_kRotate");
        pkStrings->Add(pcString);
    }
    if (IsScaleValid())
    {
        char* pcString = GetViewerStringFloat("m_fScale", m_fScale);
        pkStrings->Add(pcString);
    }
}

extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;

struct QMat3
{
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    NiPoint3 MulPoint(const NiPoint3& p) const;
};
extern const QMat3 kQMat3Identity;

inline NiPoint3 ScalePoint(float f, const NiPoint3& p)
{
    NiPoint3 r;
    r.x = f * p.x;
    r.y = f * p.y;
    r.z = f * p.z;
    return r;
}

struct QQuatRot
{
    void ToRotationMatrix(QMat3& m) const;
};

struct QXform2
{
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
    QXform2() : m_kTranslate(DAT_011a8400), m_kRotate(DAT_011f3704), m_fScale(kInvalidTransformValue)
    {}
    bool IsScaleValid() const
    {
        return m_fScale != -3.4028234663852886e38;
    }
    bool IsRotateValid() const
    {
        return m_kRotate.m_fVectorY != -3.4028234663852886e38;
    }
    bool IsTranslateValid() const
    {
        return m_kTranslate.x != -3.4028234663852886e38;
    }
    QXform2 FUN_00a38830(const QXform2& kXform) const;
};

// @fnv 0x00a38830
QXform2 QXform2::FUN_00a38830(const QXform2& kXform) const
{
    QXform2 kRes;
    float fScale = 1.0f;
    if (IsScaleValid() && kXform.IsScaleValid())
    {
        float fNew = m_fScale * kXform.m_fScale;
        kRes.m_fScale = fNew;
        fScale = fNew;
    }
    else
    {
        kRes.m_fScale = kInvalidTransformValue;
    }
    QMat3 kRot = kQMat3Identity;
    if (IsRotateValid() && kXform.IsRotateValid())
    {
        NiQuaternion kQ = ((const QQuatOps*)&m_kRotate)->FUN_00a2bcf0(kXform.m_kRotate);
        ((QQuatOps*)&kQ)->FUN_00a38560();
        kRes.m_kRotate = kQ;
        ((const QQuatRot*)&m_kRotate)->ToRotationMatrix(kRot);
    }
    else
    {
        kRes.m_kRotate.m_fVectorY = kInvalidTransformValue;
    }
    if (IsTranslateValid() && kXform.IsTranslateValid())
    {
        NiPoint3 kS = ScalePoint(fScale, kRot.MulPoint(kXform.m_kTranslate));
        NiPoint3 kSum;
        kSum.x = m_kTranslate.x + kS.x;
        kSum.y = m_kTranslate.y + kS.y;
        kSum.z = m_kTranslate.z + kS.z;
        kRes.m_kTranslate = kSum;
    }
    else
    {
        kRes.m_kTranslate.x = kInvalidTransformValue;
    }
    return kRes;
}

class A38B60BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A38B60BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A38B60BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A38B60Object;

class NiStreamA38
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void SaveLinkID(A38B60Object* pkObject);
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
    A38B60BinaryStream* m_pBackingStream;
};

template <class T>
inline void A38B60BinaryStreamSave(A38B60BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A38B60SaveBinary(NiStreamA38& kStream, const T& value)
{
    A38B60BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class NiObjectA38
{
  public:
    void SaveBinary(NiStreamA38& kStream);

    int unk00;
    int unk04;
    int unk08;
};

class KeyA38
{
  public:
    void SaveBinary(NiStreamA38* pkStream);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class DataA38 : public NiObjectA38
{
  public:
    void FUN_00a38b60(NiStreamA38& kStream);

    KeyA38 m_kControlPoint;
    unsigned int m_uiCurrentValue;
};

// Saves the base NiObjectA38, the KeyA38 member and the unsigned int member to the stream.
// @fnv 0x00a38b60
void DataA38::FUN_00a38b60(NiStreamA38& kStream)
{
    NiObjectA38::SaveBinary(kStream);
    m_kControlPoint.SaveBinary(&kStream);
    A38B60SaveBinary(kStream, m_uiCurrentValue);
}

struct QQ
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    void Set(float w, float x, float y, float z);
    QQ FUN_00a2bcf0(const QQ& q) const;
};
// Multiplies this quaternion by q using the Hamilton product and returns the resulting quaternion.
// @fnv 0x00a2bcf0
QQ QQ::FUN_00a2bcf0(const QQ& aQuat) const
{
    QQ r;
    r.Set(m_fVectorX * aQuat.m_fVectorX - m_fVectorY * aQuat.m_fVectorY - m_fVectorZ * aQuat.m_fVectorZ -
              m_fScalarPart * aQuat.m_fScalarPart,
          m_fVectorX * aQuat.m_fVectorY + m_fVectorY * aQuat.m_fVectorX + m_fVectorZ * aQuat.m_fScalarPart -
              m_fScalarPart * aQuat.m_fVectorZ,
          m_fVectorX * aQuat.m_fVectorZ + m_fVectorZ * aQuat.m_fVectorX + m_fScalarPart * aQuat.m_fVectorY -
              m_fVectorY * aQuat.m_fScalarPart,
          m_fVectorX * aQuat.m_fScalarPart + m_fScalarPart * aQuat.m_fVectorX + m_fVectorY * aQuat.m_fVectorZ -
              m_fVectorZ * aQuat.m_fVectorY);
    return r;
}

#include <string.h>
struct NiQuaternionConjugateValue
{
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    NiQuaternionConjugateValue& operator=(const NiQuaternionConjugateValue& q)
    {
        memcpy(this, &q, sizeof(q));
        return *this;
    }
};
NiQuaternionConjugateValue NiQuaternionConjugate(const NiQuaternionConjugateValue& kQuat);
struct QuatPoint
{
    float x, y, z;
    QuatPoint()
    {}
    QuatPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    QuatPoint operator-() const
    {
        return QuatPoint(-x, -y, -z);
    }
    QuatPoint operator*(float fScale) const
    {
        QuatPoint kR;
        kR.x = x * fScale;
        kR.y = y * fScale;
        kR.z = z * fScale;
        return kR;
    }
};
class ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];
    QuatPoint operator*(const QuatPoint& kPt) const
    {
        QuatPoint kR;
        kR.x = m_afEntries[0][0] * kPt.x + m_afEntries[0][1] * kPt.y + m_afEntries[0][2] * kPt.z;
        kR.y = m_afEntries[1][0] * kPt.x + m_afEntries[1][1] * kPt.y + m_afEntries[1][2] * kPt.z;
        kR.z = m_afEntries[2][0] * kPt.x + m_afEntries[2][1] * kPt.y + m_afEntries[2][2] * kPt.z;
        return kR;
    }
};
struct QuatRotate
{
    void ToRotation(ThreeByThreeMatrix& kRot) const;
};
extern char DAT_011a9448;
static const double DAT_010241b0 = -3.4028234663852886e+38;
static const float DAT_01096b8c = -3.402823466e+38f;
struct FUN_00a386a0_shell : NiQuatTransform
{
    void Inverse(NiQuatTransform& kDest);
};

// Computes the inverse transform into kDest by inverting scale, conjugating and rotating the quaternion, and transforming the translation.
// @fnv 0x00a386a0
void FUN_00a386a0_shell::Inverse(NiQuatTransform& kDest)
{
    float fInvScale = 1.0f;
    if (m_fScale == DAT_010241b0)
    {
        kDest.m_fScale = DAT_01096b8c;
    }
    else
    {
        kDest.m_fScale = 1.0f / m_fScale;
        fInvScale = kDest.m_fScale;
    }
    ThreeByThreeMatrix kRot = *(ThreeByThreeMatrix*)&DAT_011a9448;
    if (m_kRotate.m_fVectorY == DAT_010241b0)
    {
        kDest.m_kRotate.m_fVectorY = DAT_01096b8c;
    }
    else
    {
        *(NiQuaternionConjugateValue*)&kDest.m_kRotate =
            NiQuaternionConjugate(*(NiQuaternionConjugateValue*)&m_kRotate);
        ((QuatRotate*)&kDest.m_kRotate)->ToRotation(kRot);
    }
    if (m_kTranslate.x == DAT_010241b0)
    {
        kDest.m_kTranslate.x = DAT_01096b8c;
    }
    else
    {
        *(QuatPoint*)&kDest.m_kTranslate = (kRot * -*(QuatPoint*)&m_kTranslate) * fInvScale;
    }
}

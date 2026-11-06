// gamebryo2.2/corelibs/nimain/nicamera.cpp: NiCamera, ComparableCamera, CamLook, ScreenCamera and more (20 functions)

#include "fnv_a3d_camera.h"

// @fnv 0x00A711B0
void NiCamera::UpdateWorldData(NiUpdateData& update)
{
    NiAVObject::UpdateWorldData(update);
    UpdateWorldFrustum();
}

// @fnv 0x00A6FAF0
void NiCamera::UpdateViewFrustum(const NiFrustum& frustum)
{
    m_kViewFrustum.m_fNearPlane = frustum.m_fNearPlane;
    float minimumNear = frustum.m_fFarPlane / m_fMaxFarNearRatio;
    if (m_kViewFrustum.m_fNearPlane < minimumNear)
        m_kViewFrustum.m_fNearPlane = minimumNear;
    if (m_kViewFrustum.m_fNearPlane < m_fMinNearPlaneDist)
        m_kViewFrustum.m_fNearPlane = m_fMinNearPlaneDist;
    m_kViewFrustum.m_fLeftBound = frustum.m_fLeftBound;
    m_kViewFrustum.m_fRightBound = frustum.m_fRightBound;
    m_kViewFrustum.m_fTopBound = frustum.m_fTopBound;
    m_kViewFrustum.m_fBottomBound = frustum.m_fBottomBound;
    m_kViewFrustum.m_fFarPlane = frustum.m_fFarPlane;
    m_kViewFrustum.m_bOrthographic = frustum.m_bOrthographic;
}

// @fnv 0x00A711D0
void NiCamera::LinkObject(NiStream& stream)
{
    NiAVObject::LinkObject(stream);
    NiObject* obsoleteScene = stream.GetLoadedObject();
    if (obsoleteScene)
        InterlockedIncrement(&obsoleteScene->m_uiRefCount);
    unsigned int count = stream.GetLinkID();
    for (unsigned int i = 0; i < count; ++i)
    {
        NiObject* object = stream.GetLoadedObject();
        if (object)
        {
            InterlockedIncrement(&object->m_uiRefCount);
            if (!InterlockedDecrement(&object->m_uiRefCount))
                object->DeleteThis();
        }
    }
    if (stream.m_uiNifVersion >= 0x04010004)
    {
        count = stream.GetLinkID();
        for (unsigned int i = 0; i < count; ++i)
        {
            NiObject* object = stream.GetLoadedObject();
            if (object)
            {
                InterlockedIncrement(&object->m_uiRefCount);
                if (!InterlockedDecrement(&object->m_uiRefCount))
                    object->DeleteThis();
            }
        }
        if (stream.m_uiNifVersion >= 0x0a000107 && stream.m_uiNifVersion < 0x0a00010f)
        {
            count = stream.GetLinkID();
            for (unsigned int i = 0; i < count; ++i)
                stream.GetLoadedObject();
        }
    }
    if (obsoleteScene && !InterlockedDecrement(&obsoleteScene->m_uiRefCount))
        obsoleteScene->DeleteThis();
}

// The stream scalar operation is expanded in this unit, rather than defining an
// implementation owned by NiBinaryStream or introducing an out-of-line helper.
#define FNV_READ_SCALAR(value)                                                                                         \
    do                                                                                                                 \
    {                                                                                                                  \
        NiBinaryStream* input = stream.m_pUnderlyingStream;                                                            \
        unsigned int componentSize = sizeof(value);                                                                    \
        input->m_uiStreamFlags += input->m_pfnRead(input, &(value), sizeof(value), &componentSize, 1);                 \
    } while (0)

#undef FNV_READ_SCALAR

// @fnv 0x00A703A0
void NiCamera::ScreenPointToRay(float x, float y, NiPoint3& origin, NiPoint3& direction)
{
    if (m_kViewFrustum.m_bOrthographic)
    {
        NiPoint3 basis1;
        basis1.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][0];
        basis1.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][0];
        basis1.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][0];
        direction = basis1;
        direction.ComputeMagnitude();

        NiPoint3 basis2;
        basis2.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][1];
        basis2.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][1];
        basis2.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][1];
        NiPoint3 up;
        up.x = y * basis2.x;
        up.y = y * basis2.y;
        up.z = y * basis2.z;
        NiPoint3 basis3;
        basis3.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][2];
        basis3.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][2];
        basis3.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][2];
        NiPoint3 right;
        right.x = x * basis3.x;
        right.y = x * basis3.y;
        right.z = x * basis3.z;
        NiPoint3 basis4;
        basis4.x = m_kWorldSpaceTransform.m_kTranslation.x + right.x;
        basis4.y = m_kWorldSpaceTransform.m_kTranslation.y + right.y;
        basis4.z = m_kWorldSpaceTransform.m_kTranslation.z + right.z;
        NiPoint3 sum;
        sum.x = basis4.x + up.x;
        sum.y = basis4.y + up.y;
        sum.z = basis4.z + up.z;
        origin = sum;
    }
    else
    {
        NiPoint3 basis1;
        basis1.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][1];
        basis1.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][1];
        basis1.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][1];
        NiPoint3 up;
        up.x = y * basis1.x;
        up.y = y * basis1.y;
        up.z = y * basis1.z;
        NiPoint3 basis2;
        basis2.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][2];
        basis2.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][2];
        basis2.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][2];
        NiPoint3 right;
        right.x = x * basis2.x;
        right.y = x * basis2.y;
        right.z = x * basis2.z;
        NiPoint3 basis3;
        basis3.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][0];
        basis3.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][0];
        basis3.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][0];
        NiPoint3 sum;
        sum.x = basis3.x + right.x;
        sum.y = basis3.y + right.y;
        sum.z = basis3.z + right.z;
        NiPoint3 basis4;
        basis4.x = sum.x + up.x;
        basis4.y = sum.y + up.y;
        basis4.z = sum.z + up.z;
        direction = basis4;
        direction.ComputeMagnitude();
        origin = m_kWorldSpaceTransform.m_kTranslation;
    }
}

// @fnv 0x00A70B40
void NiCamera::UpdateWorldBound()
{
    if (!m_kWorldBound)
    {
        NiBound* bound = static_cast<NiBound*>(g_memoryManager.Allocate(sizeof(NiBound)));
        SetWorldBound(bound);
        bound = m_kWorldBound;
        bound->m_kCenter = NiPoint3::ZERO;
        bound->m_fBoundRadius = 0.0f;
    }
    m_kWorldBound->m_kCenter = m_kWorldSpaceTransform.m_kTranslation;
}

#pragma optimize("", off)
// @fnv 0x0045BBE0
const NiFrustum& NiCamera::GetViewFrustum() const
{
    return m_kViewFrustum;
}
#pragma optimize("", on)

extern int DAT_0109cb9c;
void __fastcall FUN_00a5a390(void* pThis);

struct NiMemObject
{
    static void __cdecl operator delete(void*, unsigned int);
};

// @fnv 0x00a70050
void* __fastcall DestroyCamera(int* pThis, int, unsigned int flags)
{
    *pThis = (int)&DAT_0109cb9c;
    FUN_00a5a390(pThis);
    if (flags & 1)
        NiMemObject::operator delete(pThis, 0x114);
    return pThis;
}

extern const char* const g_011f5e6c_arg1;
// @fnv 0x00a70040
const char* const* __cdecl FUN_00a70040()
{
    return &g_011f5e6c_arg1;
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
struct FUN_00a713e0_shell : public NiCamera
{
    NiObject* FUN_00a713e0(CloningProcess*);
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00a712f0 : BSFadeNode
{
    FUN_00a712f0() throw();
    char body[0x114];
};
struct CamStub
{
    void FUN_00a70f60(void*, CloningProcess*);
};
// @fnv 0x00a713e0
void* __fastcall FUN_00a713e0(CamStub* self, int edx, CloningProcess* kCloning)
{
    FUN_00a712f0* pkObject = new FUN_00a712f0();
    self->FUN_00a70f60(pkObject, kCloning);
    return pkObject;
}

namespace fnv_00a71430 {
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00a712f0 : BSFadeNode
{
    FUN_00a712f0() throw();
    char body[0x114];
};
// @fnv 0x00a71430
FUN_00a712f0* FUN_00a71430()
{
    return new FUN_00a712f0();
}
}  // namespace fnv_00a71430

struct StrArr
{
    unsigned short m_auiShapeKeys[4];
    unsigned short m_iElementCount;
    unsigned short m_uiBufferCapacity;
    unsigned short m_reserved;
    unsigned short m_growth;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct FUN_00a5ea70_t
{
    void FUN_00a5ad00(StrArr* strings);
};

struct NiFrustumViewerProxy
{
    char* FormatFrustumViewerString(char const* name);
    char* ToString(char const* name);
};

struct NiPoint3ViewerProxy
{
    char* FUN_00a59af0(char const* name);
};

extern char const* const g_011f5e6c_arg1;

char* __cdecl _FUN_00a7d330(char const* value);
char* __cdecl FUN_00a7d550(char const* name, float value);

struct FUN_00a71920_shell
{
    void FUN_00a71920(StrArr* strings);
};

// @fnv 0x00a71920
void FUN_00a71920_shell::FUN_00a71920(StrArr* strings)
{
    reinterpret_cast<FUN_00a5ea70_t*>(this)->FUN_00a5ad00(strings);

    char* value;
    unsigned int index;
    unsigned int size;

    value = _FUN_00a7d330(g_011f5e6c_arg1);
    index = strings->m_uiBufferCapacity;
    size = strings->m_iElementCount;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_growth) + index);
    strings->SetAt(index, value);

    value =
        reinterpret_cast<NiFrustumViewerProxy*>(reinterpret_cast<char*>(this) + 0xdc)->FormatFrustumViewerString("m_kViewFrustum");
    index = strings->m_uiBufferCapacity;
    size = strings->m_iElementCount;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_growth) + index);
    strings->SetAt(index, value);

    value = reinterpret_cast<NiFrustumViewerProxy*>(reinterpret_cast<char*>(this) + 0x100)->ToString("m_kPort");
    index = strings->m_uiBufferCapacity;
    size = strings->m_iElementCount;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_growth) + index);
    strings->SetAt(index, value);

    NiPoint3 point;
    point.x = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x68);
    point.y = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x74);
    point.z = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x80);
    value = reinterpret_cast<NiPoint3ViewerProxy*>(&point)->FUN_00a59af0("m_kWorldDir");
    index = strings->m_uiBufferCapacity;
    size = strings->m_iElementCount;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_growth) + index);
    strings->SetAt(index, value);

    point.x = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x6c);
    point.y = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x78);
    point.z = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x84);
    value = reinterpret_cast<NiPoint3ViewerProxy*>(&point)->FUN_00a59af0("m_kWorldUp");
    index = strings->m_uiBufferCapacity;
    size = strings->m_iElementCount;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_growth) + index);
    strings->SetAt(index, value);

    point.x = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x70);
    point.y = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x7c);
    point.z = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x88);
    value = reinterpret_cast<NiPoint3ViewerProxy*>(&point)->FUN_00a59af0("m_kWorldRight");
    index = strings->m_uiBufferCapacity;
    size = strings->m_iElementCount;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_growth) + index);
    strings->SetAt(index, value);

    value = FUN_00a7d550("m_fMinNearPlaneDist", *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xf8));
    index = strings->m_uiBufferCapacity;
    size = strings->m_iElementCount;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_growth) + index);
    strings->SetAt(index, value);

    value = FUN_00a7d550("m_fMaxFarNearRatio", *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xfc));
    index = strings->m_uiBufferCapacity;
    size = strings->m_iElementCount;
    if (index >= size)
        strings->SetSize(static_cast<unsigned int>(strings->m_growth) + index);
    strings->SetAt(index, value);
}

extern double DAT_01011588;

class FUN_00a6fb90_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    void FUN_00a6fb90(float scale, unsigned char flag);
};

// Recomputes the four float members from the current pair, scaled by scale and DAT_01011588, swapping which pair is updated based on flag.
// @fnv 0x00a6fb90
void FUN_00a6fb90_cls::FUN_00a6fb90(float scale, unsigned char flag)
{
    if (flag != 0)
    {
        float d = m_fRightBound - m_fLeftBound;
        float tc = (float)((d / scale) * DAT_01011588);
        float fSum = (float)((m_fBottomBound + m_fTopBound) * DAT_01011588);
        m_fTopBound = fSum + tc;
        m_fBottomBound = fSum - tc;
    }
    else
    {
        float d = m_fTopBound - m_fBottomBound;
        float tc = (float)((d * scale) * DAT_01011588);
        float fSum = (float)((m_fRightBound + m_fLeftBound) * DAT_01011588);
        m_fRightBound = fSum + tc;
        m_fLeftBound = fSum - tc;
    }
}

struct ComparableCamera : NiCamera
{
    bool FUN_00a5a260(NiObject*);
    bool IsEqualTo(NiObject* other);
};
// @fnv 0x00a6ff20
bool ComparableCamera::IsEqualTo(NiObject* other)
{
    NiCamera* camera = (NiCamera*)other;
    if (FUN_00a5a260(other) && m_kViewFrustum.m_fLeftBound == camera->m_kViewFrustum.m_fLeftBound &&
        m_kViewFrustum.m_fRightBound == camera->m_kViewFrustum.m_fRightBound &&
        m_kViewFrustum.m_fTopBound == camera->m_kViewFrustum.m_fTopBound &&
        m_kViewFrustum.m_fBottomBound == camera->m_kViewFrustum.m_fBottomBound &&
        m_kViewFrustum.m_fNearPlane == camera->m_kViewFrustum.m_fNearPlane &&
        m_kViewFrustum.m_fFarPlane == camera->m_kViewFrustum.m_fFarPlane &&
        m_kPort.m_fMinimumU == camera->m_kPort.m_fMinimumU && m_kPort.m_fMaximumU == camera->m_kPort.m_fMaximumU &&
        m_kPort.m_fMinimumV == camera->m_kPort.m_fMinimumV && m_kPort.m_fMaximumV == camera->m_kPort.m_fMaximumV &&
        m_fTrailingValue == camera->m_fTrailingValue)
        return true;
    return false;
}

struct CamPoint
{
    float x, y, z;
    CamPoint()
    {}
    CamPoint(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    CamPoint operator-(const CamPoint& p) const
    {
        return CamPoint(x - p.x, y - p.y, z - p.z);
    }
    CamPoint operator-() const
    {
        return CamPoint(-x, -y, -z);
    }
    float SqrLength() const
    {
        return x * x + y * y + z * z;
    }
    void Unitize();
    CamPoint CrossProduct(const CamPoint& v) const;
};

struct CamMatrix
{
    float m_afEntries[3][3];
    CamMatrix()
    {}
    CamMatrix(const CamPoint& c0, const CamPoint& c1, const CamPoint& c2)
    {
        m_afEntries[0][0] = c0.x;
        m_afEntries[1][0] = c0.y;
        m_afEntries[2][0] = c0.z;
        m_afEntries[0][1] = c1.x;
        m_afEntries[1][1] = c1.y;
        m_afEntries[2][1] = c1.z;
        m_afEntries[0][2] = c2.x;
        m_afEntries[1][2] = c2.y;
        m_afEntries[2][2] = c2.z;
    }
    void SetCols(const CamPoint& c0, const CamPoint& c1, const CamPoint& c2)
    {
        m_afEntries[0][0] = c0.x;
        m_afEntries[1][0] = c0.y;
        m_afEntries[2][0] = c0.z;
        m_afEntries[0][1] = c1.x;
        m_afEntries[1][1] = c1.y;
        m_afEntries[2][1] = c1.z;
        m_afEntries[0][2] = c2.x;
        m_afEntries[1][2] = c2.y;
        m_afEntries[2][2] = c2.z;
    }
    CamMatrix ComposeMatrices(const CamMatrix& m) const;
};

struct CamLook : public NiCamera
{
    bool SetLookAt(const CamPoint& point, const CamPoint& up);
    const CamPoint& GetWorldTranslate() const
    {
        return *(const CamPoint*)&m_kWorldSpaceTransform.m_kTranslation;
    }
    void SetLocalRotation(const CamMatrix& m)
    {
        *(CamMatrix*)&m_kLocalTransform.m_kOrientation = m;
    }
    __forceinline void Update(float t)
    {
        NiUpdateData data;
        data.fTime = t;
        data.m_bUpdateEnabled = false;
        data.m_bRender = false;
        data.m_bInterpolate = false;
        data.m_bTimeToDie = false;
        data.m_bVisible = false;
        UpdateWorldData(data);
        UpdateWorldBound();
    }
};

// @fnv 0x00a701b0
bool CamLook::SetLookAt(const CamPoint& point, const CamPoint& worldUp)
{
    CamPoint dir = GetWorldTranslate() - point;
    if (dir.SqrLength() < (double)1e-10f)
        return false;
    dir.Unitize();
    CamMatrix rot;
    {
        CamPoint right = worldUp.CrossProduct(dir);
        if (right.SqrLength() < 0.5f)
            return false;
        CamPoint up = dir.CrossProduct(right);
        if (up.SqrLength() < 0.5f)
            return false;
        rot.SetCols(-dir, up, right);
    }
    if (m_pParentNode)
        rot = ((const CamMatrix*)&m_pParentNode->m_kWorldSpaceTransform.m_kOrientation)->ComposeMatrices(rot);
    SetLocalRotation(rot);
    Update(0.0f);
    return true;
}

struct ScreenCamera : public NiCamera
{
    bool ProjectToScreen(const NiPoint3& kPt, float& fBx, float& fBy, float fZeroTolerance) const;
};

// @fnv 0x00a6fc50
bool ScreenCamera::ProjectToScreen(const NiPoint3& kPt, float& fBx, float& fBy, float fZeroTolerance) const
{
    float fW = kPt.x * m_afWorldToCamera[3][0] + kPt.y * m_afWorldToCamera[3][1] + kPt.z * m_afWorldToCamera[3][2] +
               m_afWorldToCamera[3][3];

    if (fW > fZeroTolerance)
    {
        float fInvW = 1.0f / fW;

        fBx = kPt.x * m_afWorldToCamera[0][0] + kPt.y * m_afWorldToCamera[0][1] + kPt.z * m_afWorldToCamera[0][2] +
              m_afWorldToCamera[0][3];
        fBy = kPt.x * m_afWorldToCamera[1][0] + kPt.y * m_afWorldToCamera[1][1] + kPt.z * m_afWorldToCamera[1][2] +
              m_afWorldToCamera[1][3];

        fBx = fBx * fInvW;
        fBy = fBy * fInvW;

        if (fBx >= -1.0f && fBx <= 1.0f && fBy >= -1.0f && fBy <= 1.0f)
        {
            fBx = (m_kPort.m_fMaximumU - m_kPort.m_fMinimumU) * 0.5 * fBx;
            fBy = (m_kPort.m_fMinimumV - m_kPort.m_fMaximumV) * 0.5 * fBy;
            fBx += (m_kPort.m_fMaximumU + m_kPort.m_fMinimumU) * 0.5;
            fBy += (m_kPort.m_fMaximumV + m_kPort.m_fMinimumV) * 0.5;
            return true;
        }
    }

    return false;
}

class FUN_00a6ff10_StandIn
{
  public:
    bool FUN_00a59f00(NiStream& stream);
    bool FUN_00a6ff10(NiStream& stream);
};

// @fnv 0x00a6ff10
bool FUN_00a6ff10_StandIn::FUN_00a6ff10(NiStream& stream)
{
    return FUN_00a59f00(stream);
}

struct NiStreamTail
{
    void FUN_00a645b0();
    void FUN_00a64670();
};

struct NiCameraHack : NiCamera
{
    void FUN_00a71450(NiStream& stream);
};
inline unsigned int BinaryRead(NiBinaryStream* pkStream, void* pvBuffer, unsigned int uiTotalBytes,
                               unsigned int* puiComponentSizes, unsigned int uiNumComponents)
{
    unsigned int uiBytesRead =
        pkStream->m_pfnRead(pkStream, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
    pkStream->m_uiStreamFlags += uiBytesRead;
    return uiBytesRead;
}
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkIstr, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    BinaryRead(pkIstr, pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    NiBinaryStreamLoad(stream.m_pUnderlyingStream, &value, 1);
}
inline void ReadBinaryValue(NiStream& stream, bool& value)
{
    unsigned char ucValue;
    ReadBinaryValue(stream, ucValue);
    value = (ucValue != 0);
}

// Reads camera frustum, port, and trailing values from a NiStream, handling NIF version differences for flags and orthographic projection.
// @fnv 0x00a71450
void NiCameraHack::FUN_00a71450(NiStream& stream)
{
    NiAVObject::LoadBinary(stream);

    unsigned int uiAVObjectFlags;
    if (stream.m_uiNifVersion < 0x0A000102)
        uiAVObjectFlags = stream.m_usAVObjectFlags;
    else
    {
        NiBinaryStreamLoad(stream.m_pUnderlyingStream, (unsigned short*)&uiAVObjectFlags, 1);
    }
    ReadBinaryValue(stream, m_kViewFrustum.m_fLeftBound);
    ReadBinaryValue(stream, m_kViewFrustum.m_fRightBound);
    ReadBinaryValue(stream, m_kViewFrustum.m_fTopBound);
    ReadBinaryValue(stream, m_kViewFrustum.m_fBottomBound);
    ReadBinaryValue(stream, m_kViewFrustum.m_fNearPlane);
    ReadBinaryValue(stream, m_kViewFrustum.m_fFarPlane);

    if (stream.m_uiNifVersion < 0x0A000105)
        m_kViewFrustum.m_bOrthographic = false;
    else
    {
        unsigned char ucOrthographic;
        ReadBinaryValue(stream, ucOrthographic);
        m_kViewFrustum.m_bOrthographic = (ucOrthographic != 0);
    }

    ReadBinaryValue(stream, m_kPort.m_fMinimumU);
    ReadBinaryValue(stream, m_kPort.m_fMaximumU);
    ReadBinaryValue(stream, m_kPort.m_fMinimumV);
    ReadBinaryValue(stream, m_kPort.m_fMaximumV);
    ReadBinaryValue(stream, m_fTrailingValue);

    reinterpret_cast<NiStreamTail*>(&stream)->FUN_00a645b0();
    reinterpret_cast<NiStreamTail*>(&stream)->FUN_00a64670();

    if (stream.m_uiNifVersion >= 0x04010004)
    {
        reinterpret_cast<NiStreamTail*>(&stream)->FUN_00a64670();
        if (stream.m_uiNifVersion >= 0x0A000107)
        {
            if (stream.m_uiNifVersion < 0x0A00010F)
                reinterpret_cast<NiStreamTail*>(&stream)->FUN_00a64670();
        }
    }
}

#include <math.h>
static inline float CamAbs(float fValue)
{
    return float(fabs(fValue));
}

struct FUN_00a6fdb0_t : public NiCamera
{
    bool ProjectPointToScreen(const NiPoint3& kPt, float& fBx, float& fBy, float& fBz, float fZeroTolerance) const;
};

// Projects a world-space point into camera/screen space using m_afWorldToCamera and m_kPort, writing the result to fBx, fBy, fBz.
// @fnv 0x00a6fdb0
bool FUN_00a6fdb0_t::ProjectPointToScreen(const NiPoint3& kPt, float& fBx, float& fBy, float& fBz,
                                          float fZeroTolerance) const
{
    bool bResult = false;
    float fW = m_afWorldToCamera[3][0] * kPt.x + m_afWorldToCamera[3][1] * kPt.y + m_afWorldToCamera[3][2] * kPt.z +
               m_afWorldToCamera[3][3];
    fW = CamAbs(fW);
    if (fW > fZeroTolerance)
    {
        bResult = true;
        float fInvW = 1.0f / fW;
        fBx = m_afWorldToCamera[0][0] * kPt.x + m_afWorldToCamera[0][1] * kPt.y + m_afWorldToCamera[0][2] * kPt.z +
              m_afWorldToCamera[0][3];
        fBy = m_afWorldToCamera[1][0] * kPt.x + m_afWorldToCamera[1][1] * kPt.y + m_afWorldToCamera[1][2] * kPt.z +
              m_afWorldToCamera[1][3];
        fBx = fBx * fInvW;
        fBy = fBy * fInvW;
        fBx *= (m_kPort.m_fMaximumU - m_kPort.m_fMinimumU) * 0.5f;
        fBy *= (m_kPort.m_fMinimumV - m_kPort.m_fMaximumV) * 0.5f;
        fBx += (m_kPort.m_fMaximumU + m_kPort.m_fMinimumU) * 0.5f;
        fBy += (m_kPort.m_fMaximumV + m_kPort.m_fMinimumV) * 0.5f;
        float fZ = m_afWorldToCamera[2][0] * kPt.x + m_afWorldToCamera[2][1] * kPt.y + m_afWorldToCamera[2][2] * kPt.z +
                   m_afWorldToCamera[2][3];
        fBz = fZ * fInvW;
    }
    return bResult;
}

struct CrossPoint : NiPoint3
{
    __declspec(noalias) NiPoint3 CrossProduct(const NiPoint3& vector) const;
};

inline NiPoint3 Scaled(float radius, const NiPoint3& unit)
{
    NiPoint3 result;
    result.x = radius * unit.x;
    result.y = radius * unit.y;
    result.z = radius * unit.z;
    return result;
}

__forceinline NiPoint3 Added(const NiPoint3& a, const NiPoint3& b)
{
    NiPoint3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

__forceinline void ClampBounds(float& lower, float& upper, float minimum, float maximum)
{
    if (lower < minimum)
    {
        lower = minimum;
        if (upper < minimum)
            upper = minimum;
        else if (upper > maximum)
            upper = maximum;
    }
    else if (upper > maximum)
    {
        upper = maximum;
        if (lower > maximum)
            lower = maximum;
    }
}

__forceinline void FullBound(NiPoint3& lo, NiPoint3& hi)
{
    lo.y = -1.0f;
    lo.x = -1.0f;
    hi.y = 1.0f;
    hi.x = 1.0f;
}

struct CameraBoundMatcher : public NiCamera
{
    void FUN_00a705f0(const NiBound& bound, NiPoint3& kMinBoundsCur, NiPoint3& kMaxPoint, float fTolerance);
};

// @fnv 0x00a705f0
void CameraBoundMatcher::FUN_00a705f0(const NiBound& bound, NiPoint3& kMinPoint, NiPoint3& kMaxPoint, float fTolerance)
{
    NiPoint3 kTargetCenter = bound.m_kCenter;
    float fRadius = bound.m_fBoundRadius;
    NiPoint3 kScratch;
    kScratch.x = kTargetCenter.x - m_kWorldSpaceTransform.m_kTranslation.x;
    kScratch.y = kTargetCenter.y - m_kWorldSpaceTransform.m_kTranslation.y;
    kScratch.z = kTargetCenter.z - m_kWorldSpaceTransform.m_kTranslation.z;
    float fInv = 1.0f / (m_kViewFrustum.m_fFarPlane - m_kViewFrustum.m_fNearPlane);
    NiPoint3 kCol0;
    kCol0.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][0];
    kCol0.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][0];
    kCol0.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][0];
    float m_fProjectionDepth = kCol0.x * kScratch.x + kCol0.y * kScratch.y + kCol0.z * kScratch.z;
    m_fProjectionDepth = m_fProjectionDepth - m_kViewFrustum.m_fNearPlane;
    if (m_kViewFrustum.m_bOrthographic)
    {
        kMinPoint.z = 0.0f;
        kMaxPoint.z = 0.0f;
    }
    else
    {
        kMinPoint.z = float(m_fProjectionDepth - fRadius) * fInv;
        kMaxPoint.z = float(m_fProjectionDepth + fRadius) * fInv;
    }
    {
        NiPoint3 kRel;
        kRel.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][1];
        kRel.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][1];
        kRel.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][1];
        NiPoint3 kCross = Scaled(fRadius, ((const CrossPoint&)kScratch).CrossProduct(kRel));
        NiPoint3 kPt;
        kPt.x = kTargetCenter.x - kCross.x;
        kPt.y = kTargetCenter.y - kCross.y;
        kPt.z = kTargetCenter.z - kCross.z;
        float fW = kPt.x * m_afWorldToCamera[3][0] + (double)(kPt.y * m_afWorldToCamera[3][1]) +
                   (double)(kPt.z * m_afWorldToCamera[3][2]) + m_afWorldToCamera[3][3];
        if (fW > fTolerance)
        {
        }
        else
        {
            FullBound(kMinPoint, kMaxPoint);
            ClampBounds(kMinPoint.z, kMaxPoint.z, 0.0f, 1.0f);
            return;
        }
        float coordinateX = kPt.x;
        float coordinateZ = kPt.z;
        kMinPoint.x = (coordinateX * m_afWorldToCamera[0][0] + kPt.y * m_afWorldToCamera[0][1] +
                       coordinateZ * m_afWorldToCamera[0][2] + m_afWorldToCamera[0][3]) /
                      fW;
        NiPoint3 kPositive = Added(kTargetCenter, kCross);
        float fWMax = kPositive.x * m_afWorldToCamera[3][0] + kPositive.y * m_afWorldToCamera[3][1] +
                      kPositive.z * m_afWorldToCamera[3][2] + m_afWorldToCamera[3][3];
        if (fWMax > fTolerance)
        {
        }
        else
        {
            FullBound(kMinPoint, kMaxPoint);
            ClampBounds(kMinPoint.z, kMaxPoint.z, 0.0f, 1.0f);
            return;
        }
        kMaxPoint.x = (kPositive.x * m_afWorldToCamera[0][0] + kPositive.y * m_afWorldToCamera[0][1] +
                       kPositive.z * m_afWorldToCamera[0][2] + m_afWorldToCamera[0][3]) /
                      fWMax;
    }
    {
        NiPoint3 kRel;
        kRel.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][2];
        kRel.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][2];
        kRel.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][2];
        NiPoint3 kCross = Scaled(fRadius, ((const CrossPoint&)kRel).CrossProduct(kScratch));
        NiPoint3 kPt;
        kPt.x = kTargetCenter.x - kCross.x;
        kPt.y = kTargetCenter.y - kCross.y;
        kPt.z = kTargetCenter.z - kCross.z;
        float fW = kPt.x * m_afWorldToCamera[3][0] + kPt.y * m_afWorldToCamera[3][1] + kPt.z * m_afWorldToCamera[3][2] +
                   m_afWorldToCamera[3][3];
        if (fW > fTolerance)
        {
        }
        else
        {
            FullBound(kMinPoint, kMaxPoint);
            ClampBounds(kMinPoint.z, kMaxPoint.z, 0.0f, 1.0f);
            return;
        }
        kMinPoint.y = ((double)(kPt.x * m_afWorldToCamera[1][0]) + (double)(kPt.y * m_afWorldToCamera[1][1]) +
                       kPt.z * m_afWorldToCamera[1][2] + m_afWorldToCamera[1][3]) /
                      fW;
        NiPoint3 kPositive;
        kPositive.x = kTargetCenter.x + kCross.x;
        kPositive.y = kTargetCenter.y + kCross.y;
        kPositive.z = kTargetCenter.z + kCross.z;
        float fWMax = kPositive.x * m_afWorldToCamera[3][0] + kPositive.y * m_afWorldToCamera[3][1] +
                      kPositive.z * m_afWorldToCamera[3][2] + m_afWorldToCamera[3][3];
        if (fWMax > fTolerance)
        {
        }
        else
        {
            FullBound(kMinPoint, kMaxPoint);
            ClampBounds(kMinPoint.z, kMaxPoint.z, 0.0f, 1.0f);
            return;
        }
        kMaxPoint.y = (kPositive.x * m_afWorldToCamera[1][0] + kPositive.y * m_afWorldToCamera[1][1] +
                       kPositive.z * m_afWorldToCamera[1][2] + m_afWorldToCamera[1][3]) /
                      fWMax;
    }
    ClampBounds(kMinPoint.x, kMaxPoint.x, -1.0f, 1.0f);
    ClampBounds(kMinPoint.y, kMaxPoint.y, -1.0f, 1.0f);

    ClampBounds(kMinPoint.z, kMaxPoint.z, 0.0f, 1.0f);
}

struct CameraVector
{
    float x, y, z;
    float UpDot(const CameraVector& b) const
    {
        return (x * b.x) + y * b.y + z * b.z;
    }
    CameraVector()
    {}
    CameraVector(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    float Dot(const CameraVector& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
    float ParenDot(const CameraVector& b) const
    {
        return (x * b.x + y * b.y) + z * b.z;
    }
    float operator*(const CameraVector& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
};
struct CameraMatrix
{
    float m_afEntries[3][3];
    void GetCol(int col, CameraVector& out) const
    {
        out.x = m_afEntries[0][col];
        out.y = m_afEntries[1][col];
        out.z = m_afEntries[2][col];
    }
};
class S00a70ba0_Cam : public NiAVObject
{
  public:
    float m_afWorldToCamera[4][4];
    NiFrustum m_kViewFrustum;
    float m_fMinNearPlaneDist, m_fMaxFarNearRatio;
    NiRect<float> m_kPort;
    float m_fTrailingValue;
    void UpdateWorldToCamera();
    void Right(float& x, float& y, float& z) const
    {
        x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][2];
        y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][2];
        z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][2];
    }

    const CameraMatrix& Rotation() const
    {
        return *(const CameraMatrix*)&m_kWorldSpaceTransform.m_kOrientation;
    }

    void CopyColumn(int col, CameraVector& out) const
    {
        out.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][col];
        out.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][col];
        out.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][col];
    }
    CameraVector Column(int col) const
    {
        return CameraVector(m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][col], m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][col],
                            m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][col]);
    }
    const CameraVector& Location() const
    {
        return *(const CameraVector*)&m_kWorldSpaceTransform.m_kTranslation;
    }
};

// Computes the m_afWorldToCamera matrix from the camera orientation, translation, and view frustum for orthographic or perspective projection.
// @fnv 0x00a70ba0
void S00a70ba0_Cam::UpdateWorldToCamera()
{
    CameraVector kWorldPosition;
    Rotation().GetCol(0, kWorldPosition);
    CameraVector kLoc = *(const CameraVector*)&m_kWorldSpaceTransform.m_kTranslation;
    CameraVector kUp;
    Rotation().GetCol(1, kUp);
    CameraVector kRight;
    Right(kRight.x, kRight.y, kRight.z);

    float fRightDot = -kLoc.Dot(kRight);
    float fUpDot = -kLoc.UpDot(kUp);
    float fDirDot = -kLoc.Dot(kWorldPosition);

    float fRpL = m_kViewFrustum.m_fRightBound + m_kViewFrustum.m_fLeftBound;
    float fBpT = m_kViewFrustum.m_fBottomBound + m_kViewFrustum.m_fTopBound;
    float fInvRmL = 1.0f / (m_kViewFrustum.m_fRightBound - m_kViewFrustum.m_fLeftBound);
    float fInvTmB = 1.0f / (m_kViewFrustum.m_fTopBound - m_kViewFrustum.m_fBottomBound);
    float fInvFmN = 1.0f / (m_kViewFrustum.m_fFarPlane - m_kViewFrustum.m_fNearPlane);

    if (m_kViewFrustum.m_bOrthographic)
    {
        float f2RmL = (float)(2.0 * fInvRmL);
        float f2TmB = (float)(2.0 * fInvTmB);
        m_afWorldToCamera[0][0] = kRight.x * f2RmL;
        m_afWorldToCamera[0][1] = kRight.y * f2RmL;
        m_afWorldToCamera[0][2] = kRight.z * f2RmL;
        float fA = fRpL * fInvRmL;
        m_afWorldToCamera[0][3] = fA + fRightDot * f2RmL;
        m_afWorldToCamera[1][0] = kUp.x * f2TmB;
        m_afWorldToCamera[1][1] = kUp.y * f2TmB;
        m_afWorldToCamera[1][2] = kUp.z * f2TmB;
        float fB = fBpT * fInvTmB;
        m_afWorldToCamera[1][3] = fB + fUpDot * f2TmB;
        m_afWorldToCamera[2][0] = kWorldPosition.x * fInvFmN;
        m_afWorldToCamera[2][1] = kWorldPosition.y * fInvFmN;
        m_afWorldToCamera[2][2] = kWorldPosition.z * fInvFmN;
        float fC = -m_kViewFrustum.m_fNearPlane * fInvFmN;
        m_afWorldToCamera[2][3] = fDirDot * fInvFmN + fC;
        m_afWorldToCamera[3][0] = 0.0f;
        m_afWorldToCamera[3][1] = 0.0f;
        m_afWorldToCamera[3][2] = 0.0f;
        m_afWorldToCamera[3][3] = 1.0f;
    }
    else
    {
        float f2RmL = (float)(2.0 * fInvRmL);
        float fA = -fRpL * fInvRmL;
        float f2TmB = (float)(2.0 * fInvTmB);
        float fB = -fBpT * fInvTmB;
        float fF = m_kViewFrustum.m_fFarPlane * fInvFmN;
        m_afWorldToCamera[0][0] = fA * kWorldPosition.x + f2RmL * kRight.x;
        m_afWorldToCamera[0][1] = fA * kWorldPosition.y + f2RmL * kRight.y;
        m_afWorldToCamera[0][2] = fA * kWorldPosition.z + f2RmL * kRight.z;
        m_afWorldToCamera[0][3] = fA * fDirDot + f2RmL * fRightDot;
        m_afWorldToCamera[1][0] = fB * kWorldPosition.x + f2TmB * kUp.x;
        m_afWorldToCamera[1][1] = fB * kWorldPosition.y + f2TmB * kUp.y;
        m_afWorldToCamera[1][2] = fB * kWorldPosition.z + f2TmB * kUp.z;
        m_afWorldToCamera[1][3] = fB * fDirDot + f2TmB * fUpDot;
        m_afWorldToCamera[2][0] = fF * kWorldPosition.x;
        m_afWorldToCamera[2][1] = fF * kWorldPosition.y;
        m_afWorldToCamera[2][2] = fF * kWorldPosition.z;
        float fC = -m_kViewFrustum.m_fNearPlane * fF;
        m_afWorldToCamera[2][3] = fF * fDirDot + fC;
        m_afWorldToCamera[3][0] = kWorldPosition.x;
        m_afWorldToCamera[3][1] = kWorldPosition.y;
        m_afWorldToCamera[3][2] = kWorldPosition.z;
        m_afWorldToCamera[3][3] = fDirDot;
    }
}

extern "C" void* __cdecl FUN_00ec44d0(void* destination, const void* source, unsigned int count);

struct FUN_00a5ac90_Obj
{
    void FUN_00a5ac90(NiCamera* first, int second);
};

union FUN_00a70f60_FloatBits
{
    float f;
    unsigned int i;
};

struct FUN_00a70f60_Obj
{
    void __thiscall FUN_00a70f60(NiCamera* destination, int second);
};

// Copies NiCamera state from source to destination via base copy, memcpy, and field assignments.
// @fnv 0x00a70f60
void __thiscall FUN_00a70f60_Obj::FUN_00a70f60(NiCamera* destination, int second)
{
    NiCamera* source = reinterpret_cast<NiCamera*>(this);

    reinterpret_cast<FUN_00a5ac90_Obj*>(source)->FUN_00a5ac90(destination, second);

    FUN_00ec44d0(reinterpret_cast<char*>(destination) + 0x9C, reinterpret_cast<char*>(source) + 0x9C, 0x40);

    FUN_00a70f60_FloatBits* sourceTranslate =
        reinterpret_cast<FUN_00a70f60_FloatBits*>(reinterpret_cast<char*>(source) + 0x8C);
    FUN_00a70f60_FloatBits* destinationTranslate =
        reinterpret_cast<FUN_00a70f60_FloatBits*>(reinterpret_cast<char*>(destination) + 0x8C);

    destinationTranslate[0].i = sourceTranslate[0].i;
    destinationTranslate[1].i = sourceTranslate[1].i;
    destinationTranslate[2].i = sourceTranslate[2].i;

    destination->m_kViewFrustum = source->m_kViewFrustum;

    volatile int* sourceValues = reinterpret_cast<volatile int*>(reinterpret_cast<char*>(source) + 0x100);
    volatile int* destinationValues = reinterpret_cast<volatile int*>(reinterpret_cast<char*>(destination) + 0x100);

    destinationValues[0] = sourceValues[0];
    destinationValues[1] = sourceValues[1];
    destinationValues[2] = sourceValues[2];
    destinationValues[3] = sourceValues[3];

    float* sourceFloats = reinterpret_cast<float*>(reinterpret_cast<char*>(source) + 0x110);
    float* destinationFloats = reinterpret_cast<float*>(reinterpret_cast<char*>(destination) + 0x110);

    destinationFloats[0] = sourceFloats[0];
    destinationFloats[-6] = sourceFloats[-6];
    destinationFloats[-5] = sourceFloats[-5];
}

struct CameraWindowRay : NiCamera
{
    bool MapScreenToRay(long x, long y, NiPoint3& origin, NiPoint3& direction, const NiRenderTargetGroup* group);
};
// Maps screen coordinates to a view-space ray using the camera port and view frustum, returning false if the point is outside the port.
// @fnv 0x00a71080
bool CameraWindowRay::MapScreenToRay(long aiScreenX, long aiScreenY, NiPoint3& origin, NiPoint3& direction,
                                     const NiRenderTargetGroup* apRenderTargetGroup)
{
    if (!NiRenderer::ms_pRenderer)
        return false;
    float fMappedU, fMappedV;
    {
        float mappedX, mappedY;
        if (!NiRenderer::ms_pRenderer->MapScreenCoordinates(aiScreenX, aiScreenY, mappedX, mappedY,
                                                            apRenderTargetGroup))
            return false;
        if (mappedX > m_kPort.m_fMaximumU || mappedX < m_kPort.m_fMinimumU || mappedY > m_kPort.m_fMinimumV ||
            mappedY < m_kPort.m_fMaximumV)
            return false;
        fMappedU = mappedX;
        fMappedV = mappedY;
    }
    ScreenPointToRay(
        m_kViewFrustum.m_fLeftBound +
            (m_kViewFrustum.m_fRightBound - m_kViewFrustum.m_fLeftBound) *
                static_cast<float>((fMappedU - m_kPort.m_fMinimumU) / (m_kPort.m_fMaximumU - m_kPort.m_fMinimumU)),
        m_kViewFrustum.m_fBottomBound +
            (m_kViewFrustum.m_fTopBound - m_kViewFrustum.m_fBottomBound) *
                static_cast<float>((fMappedV - m_kPort.m_fMaximumV) / (m_kPort.m_fMinimumV - m_kPort.m_fMaximumV)),
        origin, direction);
    return true;
}

struct NiAVObjectHelper : public NiAVObject
{
    void SaveBinaryAV(NiStream& stream);
};

struct NiStreamLinks
{
    virtual ~NiStreamLinks();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0a();
    virtual void Unk_0b();
    virtual void SaveLinkID(const NiObject* object);
};

struct NiBinaryStreamW : public NiBinaryStream
{
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

template <class T> inline unsigned int WriteBinaryArray(NiBinaryStream& binary, const T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    return ((NiBinaryStreamW&)binary).BinaryWrite(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

inline NiBinaryStream* GetOstr(NiStream& kStream)
{
    return *(NiBinaryStream**)kStream.outputAndLinkTables;
}

template <class T> inline void SerializeValue(NiStream& kStream, const T& tValue)
{
    WriteBinaryArray(*GetOstr(kStream), &tValue, 1);
}

struct NiCamera_Candidate : public NiCamera
{
    void FUN_00a716c0(NiStream& kStream);
};

// Saves the camera's AV object data, view frustum, port, and link ID to the binary stream via SerializeValue calls.
// @fnv 0x00a716c0
void NiCamera_Candidate::FUN_00a716c0(NiStream& kStream)
{
    ((NiAVObjectHelper*)this)->SaveBinaryAV(kStream);

    unsigned short usFlags = 0;
    SerializeValue(kStream, usFlags);

    SerializeValue(kStream, m_kViewFrustum.m_fLeftBound);
    SerializeValue(kStream, m_kViewFrustum.m_fRightBound);
    SerializeValue(kStream, m_kViewFrustum.m_fTopBound);
    SerializeValue(kStream, m_kViewFrustum.m_fBottomBound);
    SerializeValue(kStream, m_kViewFrustum.m_fNearPlane);
    SerializeValue(kStream, m_kViewFrustum.m_fFarPlane);
    bool bOrtho = m_kViewFrustum.m_bOrthographic;
    SerializeValue(kStream, bOrtho);

    SerializeValue(kStream, m_kPort.m_fMinimumU);
    SerializeValue(kStream, m_kPort.m_fMaximumU);
    SerializeValue(kStream, m_kPort.m_fMinimumV);
    SerializeValue(kStream, m_kPort.m_fMaximumV);

    SerializeValue(kStream, m_fTrailingValue);

    ((NiStreamLinks&)kStream).SaveLinkID(0);

    unsigned int ItemUpdateArray = 0;
    SerializeValue(kStream, ItemUpdateArray);
    SerializeValue(kStream, ItemUpdateArray);
}

#include <string.h>
int NiSprintf(char*, unsigned int, const char*, ...);
void* NiMalloc(unsigned int);

struct NiRectFloat
{
    float m_fMinimumU;  // +0x00
    float m_fMaximumU;  // +0x04
    float m_fMinimumV;  // +0x08
    float m_fMaximumV;  // +0x0c

    char* ToString(const char* pPrefix) const;
};

// Formats the rect's four float bounds into a newly allocated string prefixed by pPrefix.
// @fnv 0x00a71020
char* NiRectFloat::ToString(const char* pPrefix) const
{
    char* pString;
    unsigned int uiLen;
    uiLen = (unsigned int)strlen(pPrefix) + 64;
    pString = (char*)NiMalloc(uiLen);
    NiSprintf(pString, uiLen, "%s = (L=%g,R=%g,T=%g,B=%g)", pPrefix, m_fMinimumU, m_fMaximumU, m_fMinimumV,
              m_fMaximumV);
    return pString;
}

extern const float g_fDefaultMaxFarNearRatioA71;

class NiFrustumA71
{
  public:
    NiFrustumA71(bool bOrtho = false) throw();
    NiFrustumA71(float fLeft, float fRight, float fTop, float fBottom, float fNear, float fFar, bool bOrtho = false)
    {
        m_fLeftBound = fLeft;
        m_fRightBound = fRight;
        m_fTopBound = fTop;
        m_fBottomBound = fBottom;
        m_fNearPlane = fNear;
        m_fFarPlane = fFar;
        m_bOrthographic = bOrtho;
    }

    float m_fLeftBound;
    float m_fRightBound;
    float m_fTopBound;
    float m_fBottomBound;
    float m_fNearPlane;
    float m_fFarPlane;
    bool m_bOrthographic;
};

template <class T> class NiRectA71
{
  public:
    NiRectA71(T left = T(0), T right = T(0), T top = T(0), T bottom = T(0))
    {
        m_fMinimumU = left;
        m_fMaximumU = right;
        m_fMinimumV = top;
        m_fMaximumV = bottom;
    }

    T m_fMinimumU;
    T m_fMaximumU;
    T m_fMinimumV;
    T m_fMaximumV;
};

class NiUpdateDataA71
{
  public:
    NiUpdateDataA71(float fTime = 0.0f, bool m_bUpdateEnabled = false, bool bIsMultiThreaded = false,
                    bool byPass = false, bool bUnk = false, bool bUnk2 = false)
    {
        m_fTime = fTime;
        m_bUpdate = m_bUpdateEnabled;
        m_bIsMultiThreaded = bIsMultiThreaded;
        m_bByPass = byPass;
        m_bUnk = bUnk;
        m_bUnk2 = bUnk2;
    }

    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    bool m_bByPass;
    bool m_bUnk;
    bool m_bUnk2;
};

class NiAVObjectA71
{
  public:
    NiAVObjectA71() throw();
    virtual ~NiAVObjectA71() throw();
    void UpdateWorldData(NiUpdateDataA71& kUpdate) throw();

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
};

class FUN_00a712f0_Camera : public NiAVObjectA71
{
  public:
    FUN_00a712f0_Camera();
    virtual ~FUN_00a712f0_Camera();

    void UpdateWorldFrustum() throw();
    static void UpdateCameras() throw();

    NiFrustumA71 m_kViewFrustum;
    float m_fMinNearPlaneDist;
    float m_fMaxFarNearRatio;
    NiRectA71<float> m_kPort;
    float m_fTrailingValue;
};

// Initialises the camera's view frustum, port, near/far limits and trailing value, then calls UpdateWorldData, UpdateWorldFrustum and UpdateCameras.
// @fnv 0x00a712f0
FUN_00a712f0_Camera::FUN_00a712f0_Camera() : m_kViewFrustum(false)
{
    m_kViewFrustum.m_bOrthographic = false;
    m_kViewFrustum.m_fNearPlane = 1.0f;
    m_kViewFrustum.m_fFarPlane = 2.0f;
    m_kViewFrustum.m_fTopBound = 0.5f;
    m_kViewFrustum.m_fBottomBound = -0.5f;
    m_kViewFrustum.m_fLeftBound = -0.5f;
    m_kViewFrustum.m_fRightBound = 0.5f;
    m_fMinNearPlaneDist = 0.1f;
    m_fMaxFarNearRatio = g_fDefaultMaxFarNearRatioA71;
    m_kPort.m_fMinimumV = 1.0f;
    m_kPort.m_fMaximumU = 1.0f;
    m_fTrailingValue = 1.0f;
    m_kPort.m_fMaximumV = 0.0f;
    m_kPort.m_fMinimumU = 0.0f;

    NiUpdateDataA71 kData;
    UpdateWorldData(kData);
    UpdateWorldFrustum();
    UpdateCameras();
}

class NiPoint3V7
{
  public:
    float x, y, z;
    NiPoint3V7()
    {}
    NiPoint3V7(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    NiPoint3V7 operator-(const NiPoint3V7& pt) const
    {
        return NiPoint3V7(x - pt.x, y - pt.y, z - pt.z);
    }
    float operator*(const NiPoint3V7& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
    void ComputeMagnitude();
    NiPoint3V7 CrossProduct(const NiPoint3V7& vector) const;
    static const NiPoint3V7 ZERO;
};
class NiMatrix3V7
{
  public:
    float m_afEntries[3][3];
    NiMatrix3V7 ComposeMatrices(const NiMatrix3V7& matrix) const;
};
class NiTransformV7
{
  public:
    NiMatrix3V7 m_kOrientation;
    NiPoint3V7 m_kTranslation;
    float m_fScale;
};
class NiBoundV7
{
  public:
    NiPoint3V7 m_kCenter;
    float m_fBoundRadius;
};
class NiFrustumV7
{
  public:
    float m_fLeftBound, m_fRightBound, m_fTopBound, m_fBottomBound, m_fNearPlane, m_fFarPlane;
    bool m_bOrthographic;
};
class NiUpdateDataV7
{
  public:
    NiUpdateDataV7(float fTime = 0.0f, bool m_bUpdateEnabled = false, bool m_bRender = false)
        : fTime(fTime), m_bUpdateEnabled(m_bUpdateEnabled), m_bRender(m_bRender), m_bInterpolate(false),
          m_bTimeToDie(false), m_bVisible(false)
    {}
    float fTime;
    bool m_bUpdateEnabled, m_bRender, m_bInterpolate, m_bTimeToDie, m_bVisible;
};
class NiRefObjectV7
{
  public:
    virtual ~NiRefObjectV7();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
};
class NiObjectV7 : public NiRefObjectV7
{
  public:
    virtual NiRTTI* GetType();
    virtual NiNode* GetNiNode();
    virtual BSFadeNode* GetFadeNode();
    virtual BSMultiBoundNode* GetMultiBoundNode();
    virtual NiGeometry* GetNiGeometry();
    virtual NiTriBasedGeom* GetTriBasedGeom();
    virtual NiTriStrips* GetTriStrips();
    virtual NiTriShape* GetTriShape();
    virtual BSSegmentedTriShape* GetSegmentedTriShape();
    virtual BSResizableTriShape* GetResizableTriShape();
    virtual NiParticles* GetNiParticles();
    virtual NiLines* GetNiLines();
    virtual bhkNiCollisionObject* GetCollisionObject();
    virtual bhkBlendCollisionObject* GetBlendCollisionObject();
    virtual bhkRigidBody* GetRigidBody();
    virtual bhkLimitedHingeConstraint* GetLimitedHingeConstraint();
    virtual NiObjectV7* Clone(NiObjectCopyInfo* copyInfo);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual bool RegisterStreamables(NiStream& stream);
    virtual void SaveBinary(NiStream& stream);
    virtual bool Compare(NiObjectV7* other);
    virtual void GetViewerStrings(NiTArray<char*>* strings);
    virtual void AddViewerStrings(NiTArray<char*>* strings);
    virtual void ProcessClone(NiObjectCopyInfo* copyInfo);
    virtual void PostLinkObject(NiStream& stream);
    virtual bool StreamCanSkip();
    virtual NiRTTI* GetStreamableRTTI();
    virtual void SetWorldBound(NiBoundV7* bound);
    virtual unsigned int GetBlockAllocationSize();
    virtual void Unk_20();
    virtual void Unk_21(unsigned int argument);
    virtual NiControllerManager* GetControllerManager();
};
class NiObjectNETV7 : public NiObjectV7
{
  public:
    const char* m_kName;
    NiTimeController* m_pControllers;
    NiExtraData** m_ppExtraData;
    unsigned short m_usExtraDataCount, m_usMaxSize;
};
class NiAVObjectV7 : public NiObjectNETV7
{
  public:
    NiNode* m_pParentNode;
    NiCollisionObject* m_spCollisionObject;
    NiBoundV7* m_kWorldBound;
    void* m_pkPropertyListHead;
    void* m_pkPropertyListTail;
    unsigned int m_uiPropertyListCount;
    unsigned int m_uiObjectFlags;
    NiTransformV7 m_kLocalTransform, m_kWorldSpaceTransform;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void UpdateControllers(NiUpdateDataV7& update);
    virtual void ApplyTransform(NiMatrix3V7* rotate, NiPoint3V7* translate, bool multiply);
    virtual void Unk_25(unsigned int value);
    virtual void Unk_26(unsigned int value);
    virtual NiAVObjectV7* GetObjectByName(NiFixedString* name);
    virtual void SetSelectiveUpdateFlags(unsigned char* selective, unsigned int transform, unsigned char* rigid);
    virtual void UpdateDownwardPass(NiUpdateDataV7& update, unsigned int flags);
    virtual void UpdateSelectedDownwardPass(NiUpdateDataV7& update, unsigned int flags);
    virtual void UpdateRigidDownwardPass(NiUpdateDataV7& update, unsigned int flags);
    virtual void Unk_2C(const GeometryProperties& properties);
    virtual void Unk_2D(unsigned int value);
    virtual void UpdateWorldData(NiUpdateDataV7& update);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateDataV7& update);
    virtual void PreAttachUpdate(NiNode* parent, NiUpdateDataV7& update);
    virtual void PreAttachUpdateProperties(NiNode* parent);
    virtual void DetachParent(unsigned int value);
    virtual void UpdateUpwardPassParent();
    virtual void OnVisible(NiCullingProcess* culling);
    virtual void PurgeRendererData(NiDX9Renderer* renderer);
};
class NiCameraV7 : public NiAVObjectV7
{
  public:
    float m_afWorldToCamera[4][4];
    NiFrustumV7 m_kViewFrustum;
    float m_fMinNearPlaneDist, m_fMaxFarNearRatio;
    float m_kPort_l, m_kPort_r, m_kPort_t, m_kPort_b;
    float m_fTrailingValue;
    const NiFrustumV7& GetViewFrustum() const;
    void UpdateViewFrustum(const NiFrustumV7& frustum);
    virtual void UpdateWorldData(NiUpdateDataV7& update);
    virtual void UpdateWorldBound();
    void UpdateWorldFrustum();
    virtual void LinkObject(NiStream& stream);
    virtual void LoadBinary(NiStream& stream);
    bool WindowPixelToRay(long x, long y, NiPoint3V7& origin, NiPoint3V7& direction, const NiRenderTargetGroup* group);
    void ScreenPointToRay(float x, float y, NiPoint3V7& origin, NiPoint3V7& direction);
    bool AimAt(const NiPoint3V7& point, const NiPoint3V7& up);
    void GetScreenSpaceBounds(const NiBoundV7& bound, NiPoint3V7& minimum, NiPoint3V7& maximum, float tolerance);
    NiPoint3V7 GetWorldTranslation() const
    {
        NiPoint3V7 kDVector;
        kDVector.x = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[0][0];
        kDVector.y = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[1][0];
        kDVector.z = m_kWorldSpaceTransform.m_kOrientation.m_afEntries[2][0];
        return kDVector;
    }
    bool FUN_00a70080(const NiBoundV7& bound);
};

// Projects a bound onto the camera's forward axis to set the view frustum near/far planes, then updates world data and bound.
// @fnv 0x00a70080
bool NiCameraV7::FUN_00a70080(const NiBoundV7& bound)
{
    NiPoint3V7 kWDir = GetWorldTranslation();
    NiPoint3V7 kDiff = bound.m_kCenter - m_kWorldSpaceTransform.m_kTranslation;
    float fProjection = kDiff * kWDir;
    float fNear = fProjection - bound.m_fBoundRadius;
    float fFar = fProjection + bound.m_fBoundRadius;
    if (fFar <= 0.0f)
        return false;
    float minimum = fFar / m_fMaxFarNearRatio;
    if (fNear < minimum)
        fNear = minimum;
    if (fNear < m_fMinNearPlaneDist)
        fNear = m_fMinNearPlaneDist;
    m_kViewFrustum.m_fNearPlane = fNear;
    m_kViewFrustum.m_fFarPlane = fFar;
    NiUpdateDataV7 update;
    UpdateWorldData(update);
    UpdateWorldBound();
    return true;
}

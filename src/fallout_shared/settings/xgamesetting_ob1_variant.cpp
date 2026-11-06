
// src/fallout_shared/settings/xgamesetting_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/fallout_shared/settings/xgamesetting.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "xgamesetting_decls.h"

class NiRTTI
{
  public:
    const char* m_pcName;
    NiRTTI* m_pBaseRTTI;
};
class GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3fd4;
extern GlobalObjectO2_00a7b610 g_011f49a4;
extern GlobalObjectO2_00a7b610 g_011f4428;
struct StrArr
{
    unsigned int FUN_00c4c8d0(char*& s);
};
struct FUN_00a4f300_shell
{
    int unk[16];
    unsigned short pad40;
    unsigned short m_usElementCount;
    void* GetEntryAt(int i);
};
class NiTimeController;
class NiProperty;
template <class T> struct NiPtr
{
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
};
class NiAVObject
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual NiRTTI* GetRTTI();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual int vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual int vf30();
    NiTimeController* GetController(const NiRTTI* rtti);
    NiProperty* GetProperty(unsigned int type);
};
struct NiNodeY
{
    int unk[0x28];
    NiPtr<NiAVObject>* m_pBase;
    unsigned short m_usMax;
    unsigned short m_usSize;
    __forceinline NiPtr<NiAVObject>& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
__forceinline bool IsKindOfA(NiRTTI* r)
{
    while (r)
    {
        if (r == (NiRTTI*)&g_011f49a4)
            return true;
        r = r->m_pBaseRTTI;
    }
    return false;
}
__forceinline bool IsKindOfN(NiRTTI* r)
{
    while (r)
    {
        if (r == (NiRTTI*)&g_011f4428)
            return true;
        r = r->m_pBaseRTTI;
    }
    return false;
}
__forceinline NiAVObject* CastA(NiAVObject* p)
{
    if (!p)
        return 0;
    return (NiAVObject*)(IsKindOfA(p->GetRTTI()) ? p : 0);
}
__forceinline NiNodeY* CastN(NiAVObject* p)
{
    int u;
    if (!p)
        return 0;
    return (NiNodeY*)(IsKindOfN(p->GetRTTI()) ? p : 0);
}

// @fnv 0x00c4bd80
void __cdecl FUN_00c4bd80(NiAVObject* obj, StrArr* arr)
{
    NiNodeY* node7;
    FUN_00a4f300_shell* c7;
    NiAVObject* propA;
    NiAVObject* geom2;
    unsigned int count4;
    unsigned int i3;
    char* s2;
    unsigned int j;
    if (obj)
    {
        c7 = (FUN_00a4f300_shell*)obj->GetController((const NiRTTI*)&g_011f3fd4);
        if (!c7 && (obj->vf1c() || obj->vf30()))
        {
            geom2 = obj;
            propA = CastA((NiAVObject*)geom2->GetProperty(5));
            if (propA)
                c7 = (FUN_00a4f300_shell*)((NiAVObject*)propA)->GetController((const NiRTTI*)&g_011f3fd4);
        }
        if (c7)
        {
            count4 = c7->m_usElementCount;
            for (i3 = 0; i3 < count4; i3++)
            {
                s2 = (char*)c7->GetEntryAt(i3);
                if (s2)
                    arr->FUN_00c4c8d0(s2);
            }
        }
        node7 = CastN(obj);
        if (node7)
        {
            for (j = 0; j < node7->m_usSize; j++)
            {
                FUN_00c4bd80(node7->GetAt(j), arr);
            }
        }
    }
}

namespace fnv_00c4c2d0 {
struct NiPoint3
{
    float x;
    float y;
    float z;
};
struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    inline float GetEntry(int uiRow, int uiCol) const
    {
        return m_afEntries[uiRow][uiCol];
    }
};
struct NiTransform
{
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};
struct NiAVObject
{
    void FUN_004b4880(NiTransform* p);
};
struct Mat4
{
    float m[4][4];
};
extern NiPoint3 DAT_011f474c;
extern "C" Mat4* __stdcall D3DXMatrixInverse(Mat4* pOut, float* pDet, const Mat4* pM);
inline void Dead21()
{
    int d0;
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    int d8;
    int d9;
    int d10;
    int d11;
    int d12;
    int d13;
    int d14;
    int d15;
    int d16;
    int d17;
    int d18;
    int d19;
    int d20;
    int d21;
}
// @fnv 0x00c4c2d0
void __cdecl FUN_00c4c2d0(NiAVObject* pObj, int bInverse, Mat4* pOut)
{
    if (!bInverse)
    {
        NiTransform kXf;
        pObj->FUN_004b4880(&kXf);
        Dead21();
        pOut->m[0][0] = kXf.m_kOrientation.GetEntry(0, 0) * kXf.m_fScale;
        pOut->m[0][1] = kXf.m_kOrientation.GetEntry(1, 0) * kXf.m_fScale;
        pOut->m[0][2] = kXf.m_kOrientation.GetEntry(2, 0) * kXf.m_fScale;
        pOut->m[0][3] = 0.0f;
        pOut->m[1][0] = kXf.m_kOrientation.GetEntry(0, 1) * kXf.m_fScale;
        pOut->m[1][1] = kXf.m_kOrientation.GetEntry(1, 1) * kXf.m_fScale;
        pOut->m[1][2] = kXf.m_kOrientation.GetEntry(2, 1) * kXf.m_fScale;
        pOut->m[1][3] = 0.0f;
        pOut->m[2][0] = kXf.m_kOrientation.GetEntry(0, 2) * kXf.m_fScale;
        pOut->m[2][1] = kXf.m_kOrientation.GetEntry(1, 2) * kXf.m_fScale;
        pOut->m[2][2] = kXf.m_kOrientation.GetEntry(2, 2) * kXf.m_fScale;
        pOut->m[2][3] = 0.0f;
        pOut->m[3][0] = kXf.m_kTranslation.x;
        pOut->m[3][1] = kXf.m_kTranslation.y;
        pOut->m[3][2] = kXf.m_kTranslation.z;
        pOut->m[3][3] = 1.0f;
    }
    else
    {
        Mat4 kM;
        kM.m[3][2] = 0.0f;
        kM.m[3][1] = 0.0f;
        kM.m[3][0] = 0.0f;
        kM.m[2][3] = 0.0f;
        kM.m[2][1] = 0.0f;
        kM.m[2][0] = 0.0f;
        kM.m[1][3] = 0.0f;
        kM.m[1][2] = 0.0f;
        kM.m[1][0] = 0.0f;
        kM.m[0][3] = 0.0f;
        kM.m[0][2] = 0.0f;
        kM.m[0][1] = 0.0f;
        kM.m[3][3] = 1.0f;
        kM.m[2][2] = 1.0f;
        kM.m[1][1] = 1.0f;
        kM.m[0][0] = 1.0f;
        const NiPoint3& rPos = DAT_011f474c;
        kM.m[3][0] = rPos.x;
        kM.m[3][1] = rPos.y;
        kM.m[3][2] = rPos.z;
        D3DXMatrixInverse(pOut, 0, &kM);
    }
}
}  // namespace fnv_00c4c2d0

class NiPoint3
{
  public:
    float x, y, z;
};
class ThreeByThreeMatrix
{
  public:
    enum Axis
    {
        X,
        Y,
        Z
    };
    float m_entry[3][3];

    inline float GetEntry(unsigned int uiRow, unsigned int uiCol) const
    {
        return m_entry[uiRow][uiCol];
    }
};
struct Transform
{
    ThreeByThreeMatrix rotate;
    NiPoint3 translate;
    float scale;
};
// @fnv 0x00c4c530
void __cdecl FUN_00c4c530(const Transform& transform, unsigned int count, const NiPoint3* positions,
                          NiPoint3* transformedPositions, const NiPoint3* normals, NiPoint3* transformedNormals)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        if (transformedPositions)
        {
            {
                float a = transform.rotate.GetEntry(0, 0);
                float b = transform.rotate.GetEntry(0, 1);
                float c = transform.rotate.GetEntry(0, 2);
                transformedPositions[i].x =
                    float((a * positions[i].x + b * positions[i].y + c * positions[i].z) * transform.scale +
                          transform.translate.x);
            }
            {
                float a = transform.rotate.GetEntry(1, 0);
                float b = transform.rotate.GetEntry(1, 1);
                float c = transform.rotate.GetEntry(1, 2);
                transformedPositions[i].y =
                    float((a * positions[i].x + b * positions[i].y + c * positions[i].z) * transform.scale +
                          transform.translate.y);
            }
            {
                float a = transform.rotate.GetEntry(2, 0);
                float b = transform.rotate.GetEntry(2, 1);
                float c = transform.rotate.GetEntry(2, 2);
                transformedPositions[i].z =
                    float((a * positions[i].x + b * positions[i].y + c * positions[i].z) * transform.scale +
                          transform.translate.z);
            }
        }
        if (transformedNormals)
        {
            {
                float a = transform.rotate.GetEntry(0, 0);
                float b = transform.rotate.GetEntry(0, 1);
                float c = transform.rotate.GetEntry(0, 2);
                transformedNormals[i].x = a * normals[i].x + b * normals[i].y + c * normals[i].z;
            }
            {
                float a = transform.rotate.GetEntry(1, 0);
                float b = transform.rotate.GetEntry(1, 1);
                float c = transform.rotate.GetEntry(1, 2);
                transformedNormals[i].y = a * normals[i].x + b * normals[i].y + c * normals[i].z;
            }
            {
                float a = transform.rotate.GetEntry(2, 0);
                float b = transform.rotate.GetEntry(2, 1);
                float c = transform.rotate.GetEntry(2, 2);
                transformedNormals[i].z = a * normals[i].x + b * normals[i].y + c * normals[i].z;
            }
        }
    }
}

class NiRTTIC4BB
{
  public:
    const NiRTTIC4BB* GetBaseRTTI() const
    {
        return m_pBaseRTTI;
    }
    const char* m_pcName;
    const NiRTTIC4BB* m_pBaseRTTI;
};

class NiObjectC4BB
{
  public:
    virtual void v00();
    virtual void v04();
    virtual const NiRTTIC4BB* GetRTTI() const;
};

inline bool IsKindOfC4BB(const NiRTTIC4BB* pkRTTI, const NiObjectC4BB* pkObject)
{
    const NiRTTIC4BB* pkTmp = pkObject->GetRTTI();
    while (pkTmp)
    {
        if (pkTmp == pkRTTI)
            return true;
        pkTmp = pkTmp->GetBaseRTTI();
    }
    return false;
}

class TargetC4BB : public NiObjectC4BB
{
  public:
    static const NiRTTIC4BB ms_kRTTI;
    void* GetDataImpl() const
    {
        return m_pResource;
    }
    void* GetData() const
    {
        return GetDataImpl();
    }
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
    void* m_pResource;
};

inline TargetC4BB* DynamicCastC4BB(NiObjectC4BB* pkObject)
{
    return !pkObject ? 0 : (TargetC4BB*)(IsKindOfC4BB(&TargetC4BB::ms_kRTTI, pkObject) ? pkObject : 0);
}

// @fnv 0x00c4bb40
void* __cdecl FUN_00c4bb40(NiObjectC4BB* pkObject)
{
    void* pvData = 0;
    TargetC4BB* pkTarget;
    if (!pkObject)
        pkTarget = 0;
    else
        pkTarget = (TargetC4BB*)(IsKindOfC4BB(&TargetC4BB::ms_kRTTI, pkObject) ? pkObject : 0);
    if (pkTarget)
        pvData = pkTarget->GetData();
    return pvData;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern char* DAT_0109b220;
char* __cdecl FUN_00a5b690(const char* s);
int __cdecl FUN_00ec65a6(char* dst, unsigned size, const char* src);
int __cdecl FUN_00ec6bd2(char* dst, unsigned size, const char* src);
static __forceinline void DeadQ3()
{
    int dq[3];
}
static __forceinline void DeadQ2()
{
    int dq[2];
}
static __forceinline void DeadQ1()
{
    int dq[1];
}
struct FixStrQ
{
    char* m_kHandle;
    FixStrQ(const char* s)
    {
        if (s == 0)
            m_kHandle = DAT_0109b220;
        else
            m_kHandle = FUN_00a5b690(s);
    }
    ~FixStrQ()
    {
        if (m_kHandle == DAT_0109b220)
            return;
        long* pRef = (long*)(m_kHandle - 8);
        InterlockedDecrement(pRef);
    }
    FixStrQ& FUN_0043ba10(const FixStrQ& o);
    const char* CStr()
    {
        const char* p = m_kHandle;
        return p;
    }
};
struct NamedQ
{
    int unk00, unk04;
    FixStrQ m_kName;
    const char* GetName()
    {
        return m_kName.CStr();
    }
    void SetName(const FixStrQ& kName)
    {
        DeadQ3();
        m_kName.FUN_0043ba10(kName);
    }
};
struct PathQ
{
    char m_szDir[0x203];
    char m_szName[0x100];
    char m_szExt[0x105];
    PathQ(const char* p);
};
// @fnv 0x00c4bbc0
void __cdecl FUN_00c4bbc0(NamedQ* pObj, const char* pcPath)
{
    const char* pcOld_ = pObj->GetName();
    PathQ kKPath(pcPath);
    char acBuf[0x100];
    if (pcOld_)
        FUN_00ec65a6(acBuf, 0x100, pcOld_);
    else
        acBuf[0] = 0;
    FUN_00ec6bd2(acBuf, 0x100, "_:");
    FUN_00ec6bd2(acBuf, 0x100, kKPath.m_szName);
    pObj->SetName(FixStrQ(acBuf));
}

class NiPoint3R
{
  public:
    float x, y, z;

    NiPoint3R()
    {}
    NiPoint3R(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }
    NiPoint3R operator-() const
    {
        return NiPoint3R(-x, -y, -z);
    }
    NiPoint3R operator*(float f) const
    {
        return NiPoint3R(f * x, f * y, f * z);
    }
    NiPoint3R operator+(const NiPoint3R& p) const
    {
        return NiPoint3R(x + p.x, y + p.y, z + p.z);
    }
    NiPoint3R operator-(const NiPoint3R& p) const
    {
        return NiPoint3R(x - p.x, y - p.y, z - p.z);
    }
    float Dot(const NiPoint3R&) const;
    float Length() const;
    void FUN_004a0c10()
    {
        float len = Length();
        if (len > 1e-06)
        {
            float inv = 1.0f / len;
            x *= inv;
            y *= inv;
            z *= inv;
        }
        else
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }
    }
};
inline NiPoint3R __cdecl operator*(float f, const NiPoint3R& p)
{
    return NiPoint3R(f * p.x, f * p.y, f * p.z);
}
extern "C" NiPoint3R __cdecl FUN_004a3760(float f, const NiPoint3R& p);
class NiMatrix3R
{
  public:
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void FUN_00439f50(unsigned int, NiPoint3R&) const;
    NiPoint3R Column(unsigned int column) const
    {
        NiPoint3R result;
        FUN_00439f50(column, result);
        return result;
    }
    void FUN_00476980(const NiPoint3R&, const NiPoint3R&, const NiPoint3R&);
};
struct NiUpdateData
{
    float time;
    bool controllers, geometry;
    bool unk06, unk07, unk08;
    NiUpdateData(float, bool, bool);
};
struct NiFrustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool orthographic;
};
struct Source
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
    NiMatrix3R rotation;
    NiPoint3R position;
    float scale;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    NiFrustum property;
};
struct NiCamera
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
    int unk2c;
    int unk30;
    NiMatrix3R rotation;
    NiPoint3R position;
    float scale;
    void UpdateViewFrustum(const NiFrustum&);
    void Update(NiUpdateData&);
};
struct Plane
{
    NiPoint3R normal;
    float distance;
    float Distance(const NiPoint3R& p) const
    {
        return normal.Dot(p) - distance;
    }
};
double __cdecl _fabs(double);
inline double Abs(float value)
{
    return (float)_fabs(value);
}
// @fnv 0x00c4bf40
void __cdecl FUN_00c4bf40(Source* source, Plane* plane, NiCamera* dest)
{
    NiPoint3R position = source->position;
    NiPoint3R first7 = source->rotation.Column(0);
    NiPoint3R second3 = source->rotation.Column(2);
    NiPoint3R thirdB = source->rotation.Column(1);
    NiPoint3R reflected6 = position + (-plane->normal) * (float)(2.0 * plane->Distance(position));
    NiPoint3R direction6 = -first7;
    direction6.FUN_004a0c10();
    NiPoint3R axisA = (float)(2.0 * plane->normal.Dot(direction6)) * plane->normal - direction6;
    direction6 = -second3;
    direction6.FUN_004a0c10();
    NiPoint3R axis2 = FUN_004a3760((float)(2.0 * plane->normal.Dot(direction6)), plane->normal) - direction6;
    direction6 = thirdB;
    direction6.FUN_004a0c10();
    NiPoint3R axis7 = FUN_004a3760((float)(2.0 * plane->normal.Dot(direction6)), plane->normal) - direction6;
    NiMatrix3R matrix;
    matrix.FUN_00476980(axisA, axis7, axis2);
    dest->position = reflected6;
    dest->rotation = matrix;
    dest->scale = Abs(source->scale);
    dest->UpdateViewFrustum(source->property);
    NiUpdateData update2(0.0f, false, false);
    dest->Update(update2);
}

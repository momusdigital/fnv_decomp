
// src/fallout_shared/bgsdecalmanager_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /GF /Ob1 (unit src/fallout_shared/bgsdecalmanager.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

#include "bgsdecalmanager_decls.h"
#include "bgsdecalmanager_types_BGSDecalManager.h"
#include "bgsdecalmanager_types_BSTempEffectSimpleDecal.h"

struct HostV;
struct ObjV
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19();
    virtual void v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(), v32(), v33(),
        v34(), v35(), v36(), v37(), v38(), v39();
    virtual void v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(), v48(), v49(), v50(), v51(), v52();
    virtual void Attach(HostV* pkHost);
    char pad04[0x2c];
    unsigned int m_uiValue1;
    bool TestFlag(unsigned int uiMask) const
    {
        return (m_uiValue1 & uiMask) != 0;
    }
};
struct CtrlV
{
    char pad[0x28];
    int m_i28;
    bool IsEmpty() const
    {
        return m_i28 == 0;
    }
    int BuildEntryValueArray();
    bool FUN_00c491a0(ObjV* pkObj);
    void SetActorList(int iState);
};
struct HostV
{
    char pad[0x8c];
    void* m_pv8c;
    int m_iFadeIndex;
    char pad94[0x2c];
    CtrlV* m_pkCtrl;
    bool HasX() const
    {
        return (bool)m_pv8c;
    }
    void FUN_00a694e0(ObjV* pkObj);
    void FUN_00c4ee90(ObjV* pkObj);
};
// @fnv 0x00c4ee90
void HostV::FUN_00c4ee90(ObjV* pkObj)
{
    if (m_iFadeIndex != 2 && m_iFadeIndex != 1)
    {
        ObjV* pkTmp = pkObj;
        if (pkTmp->TestFlag(0x1000))
        {
            if (!pkTmp->TestFlag(0x100000))
                pkObj->Attach(this);
        }
        else if (!m_pkCtrl || m_pkCtrl->IsEmpty() || m_iFadeIndex == 3)
        {
            if (pkObj->TestFlag(0x800) || !HasX())
                pkObj->Attach(this);
            else
                FUN_00a694e0(pkObj);
        }
        else if (pkObj->TestFlag(0x800) || ((!m_pkCtrl || m_pkCtrl->IsEmpty()) && !HasX()))
        {
            pkObj->Attach(this);
        }
        else
        {
            int iState = m_pkCtrl->BuildEntryValueArray();
            if (m_pkCtrl->FUN_00c491a0(pkObj))
                pkObj->Attach(this);
            m_pkCtrl->SetActorList(iState);
        }
    }
    else if (m_iFadeIndex == 1)
    {
        pkObj->Attach(this);
    }
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiCullingProcess;
class NiNodeX;
class NiObj
{
  public:
    virtual void vf00();
    virtual void DeleteThis();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c(NiNodeX* n);
    long m_uiRefCount;
    __forceinline void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
class NiNodeX : public NiObj
{
  public:
};
class NiAVObject
{
  public:
    void Cull(NiCullingProcess& p);
};
class SceneMgr;
extern SceneMgr* DAT_011f4748;
class SceneMgr
{
  public:
    int unk00;
    int unk04;
    NiNodeX* unk08;
};
inline NiNodeX* GetRoot()
{
    SceneMgr* m = DAT_011f4748;
    int u1;
    int u2;
    return m->unk08;
}
class Accum : public NiObj
{
};
class AccPtr
{
  public:
    NiObj* m_pObject;
    __forceinline AccPtr(NiObj* o = 0)
    {
        m_pObject = o;
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~AccPtr()
    {
        int u3;
        int u4;
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    __forceinline NiObj* operator->()
    {
        return m_pObject;
    }
    __forceinline operator NiObj*()
    {
        return m_pObject;
    }
    void AssignRefCounted(void* src);
    AccPtr& FUN_0066b0d0(NiNodeX* p);
};
class NiCullingProcess
{
  public:
    virtual void vf00();
    int unk04;
    int unk08;
    NiNodeX* unk0c;
    void FUN_00a694a0(void* p);
    void Process(NiNodeX* a, NiAVObject* b, int c);
};

// @fnv 0x00c4f070
void NiCullingProcess::Process(NiNodeX* a, NiAVObject* b, int c)
{
    if (!a || !b)
        return;
    unk0c = a;
    FUN_00a694a0((char*)unk0c + 0xdc);
    int saved = 0;
    if (c)
    {
        saved = unk08;
        unk08 = c;
    }
    AccPtr sp;
    if (!unk08)
    {
        sp.AssignRefCounted((char*)this + 0xc4);
        if (!sp)
            sp.FUN_0066b0d0(GetRoot());
        if (sp)
            sp->vf8c(a);
    }
    b->Cull(*this);
    if (c)
        unk08 = saved;
}

void __cdecl FUN_00a29680(const char* pcFormat, ...);

class NiFixedString
{
  public:
    const char* m_kHandle;
    operator const char*() const
    {
        return m_kHandle;
    }
};

class NiGeometry
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    NiFixedString m_kName;
    const char* GetName() const
    {
        return m_kName;
    }
};

class NiAccumulator
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual bool RegisterObject(NiGeometry* pkGeom);
};

template <class T> class NiPtr
{
  public:
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

class BSCullingProcess : public NiCullingProcess
{
  public:
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unkA0, unkA4, unkA8, unkAc, unkB0, unkB4, unkB8, unkBc;
    int unkC0;
    NiPtr<NiAccumulator> m_acRendererDataA;

    void AppendVirtual(NiGeometry& kVisible);
};

// @fnv 0x00c4f1d0
void BSCullingProcess::AppendVirtual(NiGeometry& kVisible)
{
    bool bRegistered = false;
    if (m_acRendererDataA)
    {
        if (m_acRendererDataA->RegisterObject(&kVisible))
            bRegistered = true;
    }
    if (!bRegistered)
    {
        FUN_00a29680("NiCullingProcess::Append> Geometry failed RegisterObject, not rendering: %s\n",
                     kVisible.GetName() ? kVisible.GetName() : "NULL");
    }
}

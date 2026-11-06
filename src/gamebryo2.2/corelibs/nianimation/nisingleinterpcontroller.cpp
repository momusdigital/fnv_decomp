// gamebryo2.2/corelibs/nianimation/nisingleinterpcontroller.cpp: NiSingleInterpController, BSMultiTargetTreadTransfControllerStandIn (20 functions)

#include "nisingleinterpcontroller_decls.h"
// Calls the base NiTimeController::ProcessClone, then forwards the clone process to the interpolator if one is set.
// @fnv 0x00a38f50
void NiSingleInterpController::ProcessClone(CloningProcess& process)
{
    NiTimeController::ProcessClone(process);
    NiInterpolator* pInterpolator = m_spControllerInterpolator;
    if (pInterpolator)
        pInterpolator->ProcessClone(process);
}
// @fnv 0x00a38f80
void NiSingleInterpController::LoadBinary(NiStream& stream)
{
    NiInterpController::LoadBinary(stream);
    if (stream.version >= 0x0a010068)
    {
        NiInterpolator* value = (NiInterpolator*)stream.DeserializeObject();
        NiInterpolator* old = m_spControllerInterpolator;
        if (old != value)
        {
            if (old && InterlockedDecrement(&((NiObject*)old)->refCount) == 0)
                ((NiObject*)old)->DeleteThis();
            m_spControllerInterpolator = value;
            if (value)
                InterlockedIncrement(&((NiObject*)value)->refCount);
        }
    }
}

extern int DAT_0109632c;
void __fastcall FUN_00a6d220(void*);

// @fnv 0x00a2f8c0
void* __fastcall FUN_00a2f8c0(void* pThis)
{
    FUN_00a6d220(pThis);
    *((unsigned short*)pThis + 4) &= 0xffdf;
    *(int**)pThis = &DAT_0109632c;
    return pThis;
}

struct FUN_00a38e20_shell : public NiSingleInterpController
{
    void* FUN_00a38e20();
};

extern const char* const g_011f36ec_arg1;

// @fnv 0x00a38e20
void* FUN_00a38e20_shell::FUN_00a38e20()
{
    return const_cast<void*>(static_cast<const void*>(&g_011f36ec_arg1));
}

struct NiBlendInterpolator;
struct CloningProcess;
struct NiObjectNET;
struct NiUpdateData;
struct NiFloatInterpController : public NiSingleInterpController
{
    virtual void __vslot_0();
    virtual void UpdateFloatValue(float*);
    virtual void* GetRTTI();
    void CopyMemberData(NiFloatInterpController*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    virtual void GetViewerStrings(void*);
    virtual NiInterpolator* GetInterpolatorAtIndex(unsigned short);
    virtual void SetInterpolatorForTarget(NiInterpolator*, unsigned short);
    virtual NiBlendInterpolator* GetBlendInterpolator(unsigned short, bool, bool, float, unsigned char);
    virtual bool ControlsTransform(NiInterpolator*, unsigned short);
    void __local_vftable_ctor_closure();
};
typedef char _sizecheck_NiFloatInterpController[sizeof(NiFloatInterpController) == 56 ? 1 : -1];
struct BSFrustumFOVController : public NiFloatInterpController
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSFrustumFOVController*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void GetViewerStrings(void*);
    virtual void Update(NiUpdateData*);
    virtual bool TargetIsRequired(NiObjectNET*);
    virtual void UpdateFloatValue(float*);
    void __local_vftable_ctor_closure();
};
typedef char _sizecheck_BSFrustumFOVController[sizeof(BSFrustumFOVController) == 56 ? 1 : -1];
struct FUN_00a38e30_shell : public NiSingleInterpController
{
    NiInterpolator* FUN_00a38e30(unsigned short);
};

// @fnv 0x00a38e30
NiInterpolator* __thiscall FUN_00a38e30_shell::FUN_00a38e30(unsigned short usIndex)
{
    return *reinterpret_cast<NiInterpolator**>(reinterpret_cast<unsigned char*>(this) + 0x34);
}

struct FUN_00a2f8e0_shell : public NiInterpController
{
    void* FUN_00a2f8e0();
};

extern const char* const g_011f36bc_arg1;

// @fnv 0x00a2f8e0
void* FUN_00a2f8e0_shell::FUN_00a2f8e0()
{
    return (void*)&g_011f36bc_arg1;
}

struct FUN_00a38df0_shell
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    void* m_p10;
    void* m_p14;
    void* m_p18;
    void* m_p1c;
    void* m_p20;
    void* m_p24;
    void* m_p28;
    void* m_p2c;
    void* m_p30;
    void* m_p34;
    void* m_p38;
    void* m_p3c;
    void* m_p40;
    void* m_p44;
    void* m_p48;
    void* m_p4c;
    void* m_p50;
    void* m_p54;
    void* m_p58;
    void* m_p5c;
    void* m_p60;
    void* m_p64;
    void* m_p68;
    void* m_p6c;
    void* m_p70;
    void* m_p74;
    void* m_p78;
    void* m_p7c;
    void* m_p80;
    void* m_p84;
    void* m_p88;
    void* m_p8c;
    void* m_p90;
    void* m_p94;
    void* m_p98;
    void* m_p9c;
    void* m_pa0;
    void* m_pa4;
    void* m_pa8;
    void* m_pac;
    void* m_pb0;
    void* m_pb4;
    void* m_pb8;
    void* m_pbc;
    void* m_pc0;
    void* m_pc4;
    void* m_pc8;
    void* m_pcc;
    void* m_pd0;
    void* m_pd4;
    void* m_pd8;
    void* m_pdc;
    void* m_pe0;
    void* m_pe4;
    void* m_pe8;
    void* m_p1e8;
    void TargetIsRequiredType();
};
// @fnv 0x00a38df0
void FUN_00a38df0_shell::TargetIsRequiredType()
{
    ((void(__thiscall*)(void*, void*))(*reinterpret_cast<void***>(this))[0xe8 / 4])(this, m_p2c);
}

struct FakeInterpGuarantee
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void SetActiveTimeRange(float, float) = 0;
};
struct FUN_00a38e90_shell
{
    void GuaranteeTimeRange(float, float);
};
// @fnv 0x00a38e90
void FUN_00a38e90_shell::GuaranteeTimeRange(float m_fStartTime, float m_fMaximumDistance)
{
    NiInterpolator* p = ((NiSingleInterpController*)this)->m_spControllerInterpolator;
    if (p)
        ((FakeInterpGuarantee*)p)->SetActiveTimeRange(m_fStartTime, m_fMaximumDistance);
}

struct InterpHelper
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual bool RegisterStreamables(NiStream&);
};
struct FUN_00a38fe0_shell : NiSingleInterpController
{
    bool FUN_00a2f8b0(NiStream&);
    bool RegisterInterpolatorStreamables(NiStream&);
};
// Calls FUN_00a2f8b0, then if the interpolator at offset 0x34 is set, registers its streamables with kStream; returns true unless the first call fails.
// @fnv 0x00a38fe0
bool FUN_00a38fe0_shell::RegisterInterpolatorStreamables(NiStream& kStream)
{
    if (!FUN_00a2f8b0(kStream))
        return false;
    NiInterpolator* pkInterp = *(NiInterpolator**)((char*)this + 0x34);
    if (pkInterp)
        ((InterpHelper*)pkInterp)->RegisterStreamables(kStream);
    return true;
}

struct S00c27120
{
    void FUN_00c27120(class NiStream&);
};
struct FUN_00a39010_shell : NiSingleInterpController
{
    void FUN_00a39010(NiStream&);
};
// @fnv 0x00a39010
void FUN_00a39010_shell::FUN_00a39010(NiStream& kStream)
{
    ((S00c27120*)this)->FUN_00c27120(kStream);
    ((void(__thiscall*)(NiStream*, NiInterpolator*))(*(void***)&kStream)[12])(&kStream,
                                                                              *(NiInterpolator**)((char*)this + 0x34));
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
char* _FUN_00a7d330(char const*);
extern char const* const g_011f36ec_arg1;
struct BaseWrap
{
    void WriteManagerControlledFlag(StrArr*);
};
struct InterpWrap
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void GetViewerStrings(StrArr*);
};
struct Holder00a390a0
{
    void FUN_00a390a0(StrArr*);
};
// @fnv 0x00a390a0
void Holder00a390a0::FUN_00a390a0(StrArr* pkStrings)
{
    ((BaseWrap*)this)->WriteManagerControlledFlag(pkStrings);
    char* psz = _FUN_00a7d330(g_011f36ec_arg1);
    unsigned int uiIdx = *(unsigned short*)((char*)pkStrings + 0xA);
    if (uiIdx >= *(unsigned short*)((char*)pkStrings + 8))
        pkStrings->SetSize(uiIdx + *(unsigned short*)((char*)pkStrings + 0xE));
    pkStrings->SetAt(uiIdx, psz);
    InterpWrap* pInterp = *(InterpWrap**)((char*)this + 0x34);
    if (pInterp)
        pInterp->GetViewerStrings(pkStrings);
}

struct FUN_00a38e40_cls : public NiSingleInterpController
{
    void SetInterpolator(NiInterpolator* pNew, unsigned int unused);
};

// Replaces the stored interpolator pointer, releasing the old one and incrementing the new one's reference count.
// @fnv 0x00a38e40
void FUN_00a38e40_cls::SetInterpolator(NiInterpolator* apNewInterpolator, unsigned int unused)
{
    NiInterpolator* pOld = m_spControllerInterpolator;
    if (pOld == apNewInterpolator)
    {
        return;
    }
    if (pOld != 0)
    {
        if (InterlockedDecrement(&((NiObject*)pOld)->refCount) == 0)
        {
            ((NiObject*)pOld)->DeleteThis();
        }
    }
    m_spControllerInterpolator = apNewInterpolator;
    if (apNewInterpolator != 0)
    {
        InterlockedIncrement(&((NiObject*)apNewInterpolator)->refCount);
    }
}

struct S_00a39030_Interp
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
    virtual void v21();
    virtual void v22();
    virtual bool v23(void* other);
};

struct FUN_00a39030_cls : public NiSingleInterpController
{
    bool CheckCompatible(NiSingleInterpController* other);
    bool IsCompatibleWith(NiSingleInterpController* other);
};

// @fnv 0x00a39030
bool FUN_00a39030_cls::IsCompatibleWith(NiSingleInterpController* other)
{
    if (!CheckCompatible(other))
        return false;
    if ((m_spControllerInterpolator && !other->m_spControllerInterpolator) ||
        (!m_spControllerInterpolator && other->m_spControllerInterpolator))
        return false;
    if (m_spControllerInterpolator)
    {
        S_00a39030_Interp* p = (S_00a39030_Interp*)m_spControllerInterpolator;
        NiInterpolator* o = other->m_spControllerInterpolator;
        if (!p->v23(o))
            return false;
    }
    return true;
}

extern "C" short DAT_01096320;

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
};

class FUN_00a39080_cls
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
    Holder* m_2c;
    short FUN_00a39080(int* value);
};

// @fnv 0x00a39080
short FUN_00a39080_cls::FUN_00a39080(int* piValue)
{
    Holder* holder = m_2c;
    if (holder->unk08 == *piValue)
    {
        return 0;
    }
    return DAT_01096320;
}

class NiTargetA38
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void GetBeginEndKeyTimes(float* pfBegin, float* pfEnd);
};

template <class T> class NiPointerA38
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

    T* m_pObject;
};

class NiTimeControllerA38
{
  public:
    enum
    {
        MANAGERCONTROLLED_MASK = 0x0020,
        MANAGERCONTROLLED_POS = 5
    };

    unsigned short GetField(unsigned short uMask, unsigned short uPos) const
    {
        return (m_uiObjectFlags & uMask) >> uPos;
    }
    bool GetManagerControlled() const
    {
        return (bool)(GetField(MANAGERCONTROLLED_MASK, MANAGERCONTROLLED_POS) & 1);
    }
    void AdvanceControllerTime();
    void UpdateKeyTimes();

    void* m_ppVirtualMethodTable;
    int unk04;
    unsigned short m_uiObjectFlags;
    short unk0A;
    int unk0C;
    int unk10;
    float m_fLoKeyTime;
    float m_fHiKeyTime;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    NiPointerA38<NiTargetA38> m_spControllerInterpolator;
};

// @fnv 0x00a38ec0
void NiTimeControllerA38::UpdateKeyTimes()
{
    if (GetManagerControlled())
        return;
    AdvanceControllerTime();
    if (m_spControllerInterpolator)
        m_spControllerInterpolator->GetBeginEndKeyTimes(&m_fLoKeyTime, &m_fHiKeyTime);
}

extern void FUN_00c9a6b0();

// @fnv 0x00a35850
void FUN_00a35850()
{
    FUN_00c9a6b0();
}

struct A30440Stream;
struct A30440Controller
{
    void SaveBinary(A30440Stream&);
};
struct FUN_00a35870 : A30440Controller
{
    void DoSave(A30440Stream& arStream);
};
// @fnv 0x00a35870
void FUN_00a35870::DoSave(A30440Stream& arStream)
{
    SaveBinary(arStream);
}

unsigned short __cdecl FUN_00c283f0(void*, void*);

// @fnv 0x00a35880
unsigned short __cdecl FUN_00a35880(void* param1, void* param2)
{
    return FUN_00c283f0(param1, param2);
}

class BSMultiTargetTreadTransfControllerStandIn
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
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfAC();
    virtual void vfb0();

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
    unsigned short unk38;

    virtual unsigned short GetInterpolatorCount();
};

// @fnv 0x00a35890
unsigned short BSMultiTargetTreadTransfControllerStandIn::GetInterpolatorCount()
{
    return unk38;
}

void __cdecl FUN_00a2f8b0(int arg);
// @fnv 0x00a35860
void __cdecl FUN_00a35860(int arg)
{
    FUN_00a2f8b0(arg);
}

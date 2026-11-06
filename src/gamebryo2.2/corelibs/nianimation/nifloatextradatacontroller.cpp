// gamebryo2.2/corelibs/nianimation/nifloatextradatacontroller.cpp: NiFloatExtraDataController (9 functions)

#include "nifloatextradatacontroller_decls.h"

// @fnv 0x00a41300
void NiFloatExtraDataController::Update(NiUpdateData& update)
{
    if (GetManagerControlled())
        m_fControllerTime = DAT_01096324;
    else if (AdvanceController(update.GetTime()))
    {
        if (!m_spControllerInterpolator.m_pObject || !m_spControllerInterpolator.m_pObject->Unk_35())
            return;
    }

    float value;
    if (m_spControllerInterpolator.m_pObject &&
        m_spControllerInterpolator.m_pObject->Unk_27(m_fControllerTime, m_pkTarget, value))
    {
        if (m_pExtraData.m_pObject)
            static_cast<NiFloatExtraData*>(m_pExtraData.m_pObject)->m_fValue = value;
    }
}

struct NiStream
{
    void ResetStreamState();
};

struct NiPSysModifierCtlr
{
    void LoadBinary(NiStream&);
};

// @fnv 0x00a4fbd0
void __fastcall LoadBinaryWithVersionCheck(NiPSysModifierCtlr* pThis, int, NiStream& kStream)
{
    pThis->LoadBinary(kStream);
    if (*(unsigned int*)((char*)&kStream + 0xd8) < 0x0a010068)
    {
        kStream.ResetStreamState();
    }
}

extern int DAT_0109aa14;
extern int EmptyFS;

struct NiTimeController_Call
{
    void SetControllerActive();
};

// @fnv 0x00a572a0
int* __fastcall InitTimeController(int* pThis)
{
    reinterpret_cast<NiTimeController_Call*>(pThis)->SetControllerActive();
    pThis[0] = reinterpret_cast<int>(&DAT_0109aa14);
    pThis[14] = EmptyFS;
    pThis[15] = 0;
    return pThis;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f3e6c;

// @fnv 0x00a41230
const GlobalObjectO2_00a7b610* __cdecl GetRTTI()
{
    return &g_011f3e6c;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct FUN_00a3c390 : BSFadeNode
{
    char pad[0x18];
    FUN_00a3c390(float v) throw();
};
struct FloatSrc
{
    char pad[0xc];
    float m_fFloatValue;
    float Get() const
    {
        float f = m_fFloatValue;
        return f;
    }
};

// Allocates a FUN_00a3c390 fade node constructed from the float value returned by the FloatSrc at self+0x3c.
// @fnv 0x00a41240
void* __fastcall CreateFadeNodeFromFloatSource(void* self, int edx, unsigned short usIndex)
{
    return new FUN_00a3c390((*(FloatSrc**)((char*)self + 0x3c))->Get());
}

namespace fnv_00a41280 {
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
extern void* DAT_010975fc;
int* __fastcall InitTimeController(int*);
struct CopyHelper
{
    void CopyMemberData(CopyHelper* dest, void* process);
};

static void* Init(void* p)
{
    InitTimeController((int*)p);
    *(void**)p = &DAT_010975fc;
    return p;
}

// @fnv 0x00a41280
void* __fastcall CreateClone(CopyHelper* self, int edx, void* kCloning)
{
    void* pMemory = BSFadeNode::operator new(0x40);
    void* pkObject = pMemory ? Init(pMemory) : 0;
    self->CopyMemberData((CopyHelper*)pkObject, kCloning);
    return pkObject;
}
}  // namespace fnv_00a41280

namespace fnv_00a41380 {
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610* g_011f3e6c;
struct ActorCombatGroup;
struct ArrHelper
{
    void* vt;
    unsigned int refs;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short pad;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int n);
    void SetAt(unsigned int i, ActorCombatGroup*& v);
};
void __stdcall FUN_00a57420(ArrHelper* a);
ActorCombatGroup* __cdecl FUN_00a7d330(GlobalObjectO2_00a7b610* g);

// @fnv 0x00a41380
void __stdcall AppendGlobalObject(ArrHelper* pkStrings)
{
    FUN_00a57420(pkStrings);
    ActorCombatGroup* v = FUN_00a7d330(g_011f3e6c);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, v);
}
}  // namespace fnv_00a41380

namespace fnv_00a4fc00 {
struct NiPSysModifierCtlr
{
    void LinkObject(NiStream& s);
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiColorData;
struct NiColorInterpolator : NiRefObject
{
    char pad[0x1c];
    static void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }
    NiColorInterpolator(NiColorData* pkColorData) throw();
};
struct StreamLink
{
    NiObject* GetLoadedObject();
};
struct StreamView
{
    char pad[0xd8];
    unsigned int m_uiNifVersion;
};

// @fnv 0x00a4fc00
void __fastcall LinkColorInterpolator(NiPSysModifierCtlr* self, int edx, NiStream* kStream)
{
    self->LinkObject(*kStream);
    if (((StreamView*)kStream)->m_uiNifVersion < 0x0a010068)
    {
        NiColorData* pkColorData = (NiColorData*)((StreamLink*)kStream)->GetLoadedObject();
        NiColorInterpolator* p = new NiColorInterpolator(pkColorData);
        NiColorInterpolator** ppInterpolatorSlot = (NiColorInterpolator**)((char*)self + 0x34);
        if (*ppInterpolatorSlot != p)
        {
            if (*ppInterpolatorSlot)
                (*ppInterpolatorSlot)->DecRefCount();
            *ppInterpolatorSlot = p;
            if (p)
                p->IncRefCount();
        }
        (*(void(__thiscall**)(NiColorInterpolator*))(*(char**)*ppInterpolatorSlot + 0xbc))(*ppInterpolatorSlot);
    }
}
}  // namespace fnv_00a4fc00

// NiFloatExtraDataController helper: push the controller's float extra-data value
// into the fade node that owns it (if the node is registered for this controller).
struct FadeNode
{
    FadeNode* LookupNode(void* pKey);
    void SetValue(float fValue);
};

extern int g_011f3738;

struct FUN_00a412d0_cls : public NiFloatExtraDataController
{
    void ApplyFadeValue(FadeNode* pFadeNode, int iIndex);
};

// Looks up the fade node for g_011f3738 and sets its value from this controller's float extra data.
// @fnv 0x00a412d0
void FUN_00a412d0_cls::ApplyFadeValue(FadeNode* pFadeNode, int iIndex)
{
    FadeNode* pTarget;
    if (pFadeNode == 0)
        pTarget = 0;
    else
        pTarget = pFadeNode->LookupNode(&g_011f3738);

    NiFloatExtraData* pExtraData = static_cast<NiFloatExtraData*>(this->m_pExtraData.operator->());
    pTarget->SetValue(pExtraData->m_fValue);
}

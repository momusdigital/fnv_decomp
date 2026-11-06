
// src/gamebryo2.2/corelibs/niparticle/nipsysgravitystrengthctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysgravitystrengthctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202700;

// @fnv 0x00c2a8a0
void* __cdecl FUN_00c2a8a0()
{
    return &g_01202700;
}

struct NiRTTI
{
    const char* m_pcName;
    NiRTTI* m_pkBase;
};
extern NiRTTI g_01202548;
struct NiObject
{
    virtual ~NiObject();
    virtual void _a();
    virtual const NiRTTI* GetRTTI() const;
    bool IsKindOfType(const NiRTTI* pkRTTI) const;
};
inline bool NiObject::IsKindOfType(const NiRTTI* pkRTTI) const
{
    const NiRTTI* pkMy = GetRTTI();
    if (!pkMy)
        return false;
    do
    {
        if (pkMy == pkRTTI)
            return true;
        pkMy = pkMy->m_pkBase;
    } while (pkMy);
    return false;
}
struct NiPSysModifier : NiObject
{
};
struct NiObjectNET
{
};
struct B00c1bff0
{
    void* FUN_00c1b0f0(void*);
};
struct BaseStandIn
{
    bool IsTargetParticleSystem(NiObjectNET*);
    char _pad[0x38];
};
struct NiPSysGravityStrengthCtlr : BaseStandIn
{
    void* m_p38;
    bool InterpTargetIsCorrectType(NiObjectNET*);
};
// @fnv 0x00c2a910
bool NiPSysGravityStrengthCtlr::InterpTargetIsCorrectType(NiObjectNET* pkTarget)
{
    if (!BaseStandIn::IsTargetParticleSystem(pkTarget))
        return false;
    NiPSysModifier* pkModifier = (NiPSysModifier*)((B00c1bff0*)pkTarget)->FUN_00c1b0f0((void*)&m_p38);
    if (!pkModifier)
        return false;
    return pkModifier->IsKindOfType(&g_01202548);
}

namespace fnv_00c2a960 {
struct StrArr
{
    unsigned char _pad[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _pad2;
    unsigned short m_usGrowSize;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
void __stdcall FUN_00c32f60(StrArr*);
char* __cdecl _FUN_00a7d330(void*);
struct NiPSysGravityStrengthCtlr
{
    void GetViewerStrings(StrArr*);
};
// Appends the string returned by _FUN_00a7d330(g_01202700) to pkStrings, growing the array if it is full.
// @fnv 0x00c2a960
void NiPSysGravityStrengthCtlr::GetViewerStrings(StrArr* pkStrings)
{
    FUN_00c32f60(pkStrings);
    char* pStr = _FUN_00a7d330(g_01202700);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowSize);
    pkStrings->SetAt(uiSize, pStr);
}
}  // namespace fnv_00c2a960

class C2A8C0CloningProcess;

class C2A8C0Base
{
  public:
    C2A8C0Base() throw();
    virtual ~C2A8C0Base();
    static void* operator new(unsigned int uiSize) throw();
    static void operator delete(void* pvMem);

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
};

class C2A8C0Object : public C2A8C0Base
{
  public:
    __forceinline C2A8C0Object() throw()
    {}
    virtual ~C2A8C0Object();

    void CopyMemberData(C2A8C0Object* pkDest, C2A8C0CloningProcess& kCloning);
    C2A8C0Object* CreateClone(C2A8C0CloningProcess& kCloning);
};

// @fnv 0x00c2a8c0
C2A8C0Object* C2A8C0Object::CreateClone(C2A8C0CloningProcess& kCloning)
{
    C2A8C0Object* pkDest = new C2A8C0Object;
    CopyMemberData(pkDest, kCloning);
    return pkDest;
}

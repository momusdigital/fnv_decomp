
// src/gamebryo2.2/corelibs/nianimation/nirollcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nirollcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern const char* const g_011f3f58_arg1;

// @fnv 0x00a485a0
const char* const* __cdecl FUN_00a485a0()
{
    return &g_011f3f58_arg1;
}

extern void* g_011f3f58;

// @fnv 0x00a485b0
void* __cdecl FUN_00a485b0()
{
    return &g_011f3f58;
}

struct BSFadeNode {
    static void* __cdecl operator new(unsigned int);
};

void __fastcall FUN_00a6d220(void*);
extern int DAT_01098634;

// @fnv 0x00a48750
void* __cdecl FUN_00a48750()
{
    void* pFadeNode = BSFadeNode::operator new(0x3c);
    if (pFadeNode)
    {
        FUN_00a6d220(pFadeNode);
        *(int*)((char*)pFadeNode + 0x38) = 0;
        *(int*)((char*)pFadeNode + 0x34) = 0;
        *(int*)pFadeNode = (int)&DAT_01098634;
        return pFadeNode;
    }
    return 0;
}

void __cdecl _delete(void*, unsigned int);
struct S_00a485c0 {
	void FUN_00a57990();
	void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00a57990, frees this with _delete when flags has bit 1 set, and returns this.
// @fnv 0x00a485c0
void* S_00a485c0::DestroyIfFlagged(unsigned int flags)
{
	FUN_00a57990();
	if (flags & 1)
		_delete(this, 0x3c);
	return this;
}

struct StrArr {
    char _pad[8];
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _pad2;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char* &);
};
void __stdcall FUN_00a6d830(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
struct NiRollController {
    void GetViewerStrings(StrArr*);
};
// Appends the string returned by _FUN_00a7d330(g_011f3f58) to the StrArr, growing it via SetSize when full, then stores it with SetAt.
// @fnv 0x00a48790
void NiRollController::GetViewerStrings(StrArr* pStrArr)
{
    FUN_00a6d830(pStrArr);
    char* pkString = _FUN_00a7d330((const char*)g_011f3f58);
    unsigned int uiSize = pStrArr->m_usSize;
    unsigned int uiMaxSize = pStrArr->m_usMaxSize;
    if (uiSize >= uiMaxSize)
        pStrArr->SetSize(uiSize + pStrArr->m_usGrowBy);
    pStrArr->SetAt(uiSize, pkString);
}

typedef unsigned int A486F0size_t;

struct A486F0CloningProcess;

struct A486F0Object {
    static void* operator new(A486F0size_t stSize);

    __declspec(nothrow) A486F0Object();
    virtual ~A486F0Object();

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

    void CopyMemberData(A486F0Object* pkDest, A486F0CloningProcess& kCloning);
};

struct A486F0Pointer {
    void* m_pObject;

    A486F0Pointer() : m_pObject(0) {}
};

struct A486F0ControllerBase : A486F0Object {
    int m_unk34;
    A486F0Pointer m_spReferencedObject;

    A486F0ControllerBase() { m_unk34 = 0; }
};

struct A486F0Controller : A486F0ControllerBase {
    A486F0Controller() {}
    virtual ~A486F0Controller();

    A486F0Object* CreateClone(A486F0CloningProcess& kCloning);
};

// Allocates a new controller, copies this object's state into it via the cloning process, and returns the clone.
// @fnv 0x00a486f0
A486F0Object* A486F0Controller::CreateClone(A486F0CloningProcess& kCloning)
{
    A486F0Controller* pkClone = new A486F0Controller;
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

void __cdecl FUN_00a57a70();

// @fnv 0x00a48560
void __cdecl FUN_00a48560()
{
    FUN_00a57a70();
}

void __cdecl RegisterStreamables();
// @fnv 0x00a48570
void __cdecl FUN_00a48570()
{
    RegisterStreamables();
}

void __cdecl SaveBinary();

// @fnv 0x00a48580
void __cdecl FUN_00a48580() {
    SaveBinary();
}

void __cdecl IsEqual();

// @fnv 0x00a48590
void __cdecl FUN_00a48590()
{
    IsEqual();
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

void __cdecl FUN_00a57970();
// @fnv 0x00a48550
void __cdecl FUN_00a48550() { FUN_00a57970(); }

struct NiUpdateDataA485 {
    float m_fTime;
};

class NiMatrix3A485 {
public:
    NiMatrix3A485 operator*(const NiMatrix3A485& mat) const;
    void SetZRotation(float fAngleDifference)
    {
        float sn, cs;
        fnv_SinCos(fAngleDifference, sn, cs);
        m_afEntries[0][0] = cs;
        m_afEntries[0][1] = sn;
        m_afEntries[0][2] = 0.0f;
        m_afEntries[1][0] = -sn;
        m_afEntries[1][1] = cs;
        m_afEntries[1][2] = 0.0f;
        m_afEntries[2][0] = 0.0f;
        m_afEntries[2][1] = 0.0f;
        m_afEntries[2][2] = 1.0f;
    }
    float m_afEntries[3][3];
};

class NiAVObjectA485 {
public:
    virtual void vfn_00();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    NiMatrix3A485 m_kRotate;
};

struct NiFloatKeyA485 {
    static float __cdecl InterpolateKey(float fTime, NiFloatKeyA485* pkKeys, int eType, unsigned int uiNumKeys, unsigned int& uiLastIdx, unsigned char ucSize);
};

class NiRollControllerA485 {
public:
    virtual void vfn_00();
    bool FUN_00a36250(float fTime);
    NiFloatKeyA485* GetFloatKeys(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize);
    void Update(NiUpdateDataA485& kUpdateData);

    unsigned int m_uiRefCount;
    unsigned short m_uiObjectFlags;
    unsigned short unk0A;
    float m_fFrequency, m_fPhase, m_fLoKeyTime, m_fHiKeyTime, m_fStartTime, m_fLastTime, m_fWeightAdjustedLastTime;
    float m_fControllerTime;
    NiAVObjectA485* m_pkTarget;
    void* m_spNextController;
    unsigned int m_uiLastKeyIndex;
};

// @fnv 0x00a485e0
void NiRollControllerA485::Update(NiUpdateDataA485& kUpdateData)
{
    if (!m_pkTarget || FUN_00a36250(kUpdateData.m_fTime))
        return;

    unsigned int uiNumKeys;
    int eType;
    unsigned char ucSize;
    NiFloatKeyA485* pkKeys = GetFloatKeys(uiNumKeys, eType, ucSize);
    float fRoll = NiFloatKeyA485::InterpolateKey(m_fControllerTime, pkKeys, eType, uiNumKeys, m_uiLastKeyIndex, ucSize);

    NiMatrix3A485 kRot = m_pkTarget->m_kRotate;
    NiMatrix3A485 kRoll;
    kRoll.SetZRotation(-fRoll);
    kRot = kRot * kRoll;
    m_pkTarget->m_kRotate = kRot;
}

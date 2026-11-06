
// src/havok/physics/dynamics/collide/hkpsimpleconstraintcontactmgr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/hkpsimpleconstraintcontactmgr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpSimpleConstraintContactMgr.h"

struct FUN_00cfd3f0_class {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    char* FUN_00cfd3f0(unsigned short index);
};

// @fnv 0x00cfd3f0
char* FUN_00cfd3f0_class::FUN_00cfd3f0(unsigned short index)
{
    return (char*)m_3c + 0x30 + (unsigned char)*(unsigned char*)((char*)m_20 + index) * 32;
}

struct FUN_00cfcc70_data {
    unsigned int m_00;
    unsigned short m_04;
    unsigned short m_08;
    unsigned short m_0c;
};

struct FUN_00cfcc70_class {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    unsigned short m_10;
    unsigned char m_12[0x2a];
    void* m_3c;

    int reserveContactPointsImpl(int value);
};

// @fnv 0x00cfcc70
int FUN_00cfcc70_class::reserveContactPointsImpl(int value) {
    FUN_00cfcc70_data* data = static_cast<FUN_00cfcc70_data*>(m_3c);
    int field4 = data->m_04;
    int limit = *reinterpret_cast<unsigned short*>(
        reinterpret_cast<unsigned char*>(data) + 0x0c);
    int current = m_10;

    field4 += value;
    current += field4;
    limit -= 2;

    if (current > limit)
        return 1;

    m_10 = static_cast<unsigned short>(
        static_cast<unsigned char>(
            static_cast<unsigned char>(m_10) +
            static_cast<unsigned char>(value)));
    return 0;
}

extern "C" void __cdecl ProcessCollisionEvent(void*, void*, float, void*);

// @fnv 0x00cfce30
void __stdcall FUN_00cfce30(void* a1, float a2, void* a3)
{
    unsigned char* p = (unsigned char*)a1;
    void* eax = *(void**)(p + 0xc);
    void* esi = *(void**)((unsigned char*)eax + 8);
    if ((p[0x27] & 8) == 0)
    {
        unsigned char al = *(unsigned char*)((unsigned char*)eax + 0xe8);
        void* edx = *(void**)(p + 0x10);
        if (al == 5 || al == 4)
        {
            unsigned char bl = *(unsigned char*)((unsigned char*)edx + 0xe8);
            if (bl == 5 || bl == 4)
                return;
        }
        ProcessCollisionEvent(esi, a1, a2, a3);
    }
}

struct FUN_00cfd410_class {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    unsigned char* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    unsigned char* m_3c;

    unsigned char* FUN_00cfd410(unsigned short index);
};

// @fnv 0x00cfd410
unsigned char* FUN_00cfd410_class::FUN_00cfd410(unsigned short index) {
    unsigned char* pIndices = m_20;
    unsigned int value = pIndices[index];

    if (value == 0xff)
        return 0;

    unsigned char* base = m_3c;
    short signedValue = static_cast<short>(value);

    return base + 0x30
        + (*(reinterpret_cast<unsigned short*>(base + 6)) << 5)
        + (*(reinterpret_cast<unsigned char*>(base + 0xa)) * signedValue);
}

struct FUN_00cf40b0_class {
    void FUN_00cf40b0();
};

struct FUN_00cfda50_class {
    void FUN_00cfda50();
};

extern int DAT_010cc984;
extern int _DAT_0102e388;

struct FUN_00cfd720 {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    void* m_38;
    void* m_3c;
    void* m_40;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    ~FUN_00cfd720();
};

void __cdecl FUN_00cb3dd0(void*, void*, int);

// @fnv 0x00cfd720
FUN_00cfd720::~FUN_00cfd720() {
    *(void**)this = (void*)&DAT_010cc984;
    if (*(unsigned short*)(*(char**)((char*)this + 0x3c) + 4) != 0) {
        FUN_00cb3dd0(*(void**)((char*)this + 0xc), (char*)this + 0x44, 1);
    }
    *(void**)((char*)this + 0x58) = 0;
    *(void**)((char*)this + 0x5c) = 0;
    *(void**)((char*)this + 0x50) = 0;
    ((FUN_00cf40b0_class*)((char*)this + 0x44))->FUN_00cf40b0();
    ((FUN_00cfda50_class*)((char*)this + 0x14))->FUN_00cfda50();
    *(void**)this = (void*)&_DAT_0102e388;
}

struct FUN_00cfd7d0_class {
    unsigned char* m_00;
    unsigned int m_04;
    void DecrementBytesAboveValue(unsigned int value);
};

// For each byte in m_00 up to m_04, if the byte is not 0xff and greater than value, decrements it by one.
// @fnv 0x00cfd7d0
void FUN_00cfd7d0_class::DecrementBytesAboveValue(unsigned int auiThreshold)
{
    for (int i = (int)m_04 - 1; i >= 0; --i) {
        unsigned char c = m_00[i];
        if (c != 0xff && (int)c > (int)auiThreshold)
            --m_00[i];
    }
}

struct FUN_00cfdae0_router
{
	virtual void FUN_00cfdae0_slot0();
	virtual void FUN_00cfdae0_slot1();
	virtual void FUN_00cfdae0_deallocate(void* object, unsigned short size);
};

struct FUN_00cfdae0_manager
{
	void* m_00;
	void* m_04;
	void* m_08;
	void* m_0c;
	FUN_00cfdae0_router* m_router;
};

FUN_00cfdae0_manager* _D1A0E0GetMemoryRouter();

struct FUN_00cfdae0_class
{
	unsigned int m_00;
	unsigned short m_iElementCount;

	void FUN_00cfda50();
	FUN_00cfdae0_class* Destroy(unsigned char flags);
};

// @fnv 0x00cfdae0
FUN_00cfdae0_class* FUN_00cfdae0_class::Destroy(unsigned char flags)
{
	FUN_00cfda50();

	if (flags & 1)
	{
		FUN_00cfdae0_manager* manager = _D1A0E0GetMemoryRouter();
		unsigned short size = m_iElementCount;
		manager->m_router->FUN_00cfdae0_deallocate(this, size);
	}

	return this;
}

struct ContactSubobject {
    virtual void __fastcall method00(void*);
    virtual void __fastcall method04(void*);
    virtual void __fastcall method08(void*);
    virtual void __fastcall method0c(void*);
    virtual void __fastcall method10(void*);
    virtual void __fastcall method14(void*);
    virtual void __fastcall method18(void*);
    virtual void __fastcall method1c(void*);
    virtual void __fastcall method20(void*);
    virtual void __fastcall method24(void*);
    virtual void __fastcall method28(void*);
    virtual void __fastcall method2c(void*);
    virtual void __fastcall method30(void*);
    virtual void __fastcall method34(void*);
    virtual void __fastcall method38(void*);
    virtual void __fastcall method3c(void*);
    virtual void __fastcall method40(void*);
};
struct FUN_00cfccb0_class {
    void* m_00; void* m_04; void* m_08; void* m_0c; void* m_10;
    ContactSubobject embedded;
    void __fastcall FUN_00cfccb0(void* forwardedArg);
};
// @fnv 0x00cfccb0
void FUN_00cfccb0_class::FUN_00cfccb0(void* forwardedArg) {
    embedded.method40(forwardedArg);
}

// FUN_00cfd660 : a forwarding member  (add ecx, 0x20 ; jmp <base impl>)
extern int g_sink_00cfd660;
struct First_00cfd660 {
    First_00cfd660();
    virtual void f0();
    char pad[0x1c];
};
struct Base_00cfd660 {
    Base_00cfd660();
    void target();
};
struct Derived_00cfd660 : First_00cfd660, Base_00cfd660 {
    void FUN_00cfd660();
};
__declspec(noinline) void Base_00cfd660::target() { g_sink_00cfd660 = 1; }
// @fnv 0x00cfd660
void Derived_00cfd660::FUN_00cfd660() { Base_00cfd660::target(); }

extern int DAT_01268798;

// @fnv 0x00cfdad0
int* __cdecl FUN_00cfdad0()
{
    return &DAT_01268798;
}

struct FnvCpu_FUN_00cfcc60_CpuObject { char* FUN_00cfcc60(); };
// @fnv 0x00cfcc60
char* FnvCpu_FUN_00cfcc60_CpuObject::FUN_00cfcc60()
{
    return reinterpret_cast<char*>(this) + 68;
}

struct FUN_00cfccc0_target {
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
    virtual void __thiscall vf44(int a, float b, int c, int d, int e, int f);
};

struct FUN_00cfccc0_class {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    FUN_00cfccc0_target m_14;

    void __thiscall ForwardToVf44(int a, float b, int c, int d, int e, int f);
};

// Forwards all six arguments to the virtual method vf44 on the m_14 subobject.
// @fnv 0x00cfccc0
void __thiscall FUN_00cfccc0_class::ForwardToVf44(int aiArg1, float afArg2, int aiArg3, int aiArg4, int aiArg5, int aiArg6) {
    m_14.vf44(aiArg1, afArg2, aiArg3, aiArg4, aiArg5, aiArg6);
}

struct ContactRecord {
    unsigned short flags;
    unsigned short reserved;
    void* secondInput;
    unsigned short* firstContact;
    unsigned short* secondContact;
    void* optional;
    void* owner;
    void* firstInput;
};
void __cdecl FUN_00d01900(void* handler, ContactRecord* record);
void __cdecl FUN_00d001c0(unsigned short* contact, ContactRecord* record);
struct FUN_00cfccf0_class {
    void* m_00; void* m_04; void* m_08; void* m_0c;
    void* m_10; void* m_14; void* m_18; void* m_1c;
    void* m_20; void* m_24; void* m_28; void* m_2c;
    void* m_30; void* m_34; void* m_38; void* m_3c;
    void* m_40; void* m_44; void* m_48; void* m_4c;
    void* m_50; void* m_54;
    unsigned short* m_58;
    unsigned short* m_5c;
    void ProcessContactPair(void* firstInput, void* secondInput);
};
// Builds a ContactRecord from the two stored contacts and inputs, dispatches it via m_0c, then processes each contact whose flag at index 0x102 is set.
// @fnv 0x00cfccf0
void FUN_00cfccf0_class::ProcessContactPair(void* firstInput, void* secondInput) {
    unsigned short* first = m_58;
    unsigned short* second = m_5c;
    ContactRecord record;
    record.flags = 0xffff;
    record.secondInput = secondInput;
    record.firstContact = first;
    record.secondContact = second;
    record.owner = this;
    record.firstInput = firstInput;
    FUN_00d01900(m_0c, &record);
    if (first[0x102]) FUN_00d001c0(first, &record);
    if (second[0x102]) FUN_00d001c0(second, &record);
}

struct hkpConstraintInfoCFD2 {
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;

    void clear()
    {
        m_iMaxSchemaSize = 0;
        m_iSchemaByteSize = 0;
        m_iSolverResultCount = 0;
        m_iSolverElementTemporaryCount = 0;
    }
    void add(int iSchemaSize, int iNumSolverResults, int iNumSolverElemTemps)
    {
        m_iSchemaByteSize += iSchemaSize;
        m_iSolverResultCount += iNumSolverResults;
        m_iSolverElementTemporaryCount += iNumSolverElemTemps;
    }
};

struct hkConstraintInternalCFD2 {
    char m_acUnk00[0x14];
    hkUint16 m_iSchemaByteSize;
    hkUint16 m_iSolverResultCount;
    hkUint16 m_iSolverElementTemporaryCount;
};

class hkpConstraintInstanceCFD2 {
public:
    char m_acUnk00[0x30];
    hkConstraintInternalCFD2* m_pConstraintInternal;
};

class hkpConstraintOwnerCFD2 : public hkReferencedObject {
public:
    hkpConstraintInfoCFD2 m_kConstraintInfo;

    void subConstraintInfo(hkpConstraintInstanceCFD2* pkConstraint, hkpConstraintInfoCFD2& kDelta)
    {
        m_kConstraintInfo.m_iSchemaByteSize -= kDelta.m_iSchemaByteSize;
        m_kConstraintInfo.m_iSolverResultCount -= kDelta.m_iSolverResultCount;
        m_kConstraintInfo.m_iSolverElementTemporaryCount -= kDelta.m_iSolverElementTemporaryCount;
        hkConstraintInternalCFD2* pkInternal = pkConstraint->m_pConstraintInternal;
        pkInternal->m_iSolverResultCount = hkUint16(pkInternal->m_iSolverResultCount - kDelta.m_iSolverResultCount);
        pkInternal->m_iSolverElementTemporaryCount = hkUint16(pkInternal->m_iSolverElementTemporaryCount - kDelta.m_iSolverElementTemporaryCount);
        pkInternal->m_iSchemaByteSize = hkUint16(pkInternal->m_iSchemaByteSize - kDelta.m_iSchemaByteSize);
    }
};

struct hkpSimpleContactConstraintAtomCFD2 {
    hkUint16 m_type;
    hkUint16 m_usSizeOfAllAtoms;
    hkUint16 m_usNumContactPoints;
    hkUint16 m_usMaxNumContactPointProperties;
    hkUint8 m_acUnk08[2];
    hkUint8 m_ucContactPointPropertiesStriding;
    hkUint8 m_acUnk0B[5];
    hkUint16 m_flags;
    hkUint8 m_acUnk12[0x1e];

    hkUint8* getContactPointPropertiesStream(hkInt16 i)
    {
        return (hkUint8*)(this + 1) + m_usMaxNumContactPointProperties * 0x20 + i * m_ucContactPointPropertiesStriding;
    }
};

void __cdecl FUN_00cfd950(hkpSimpleContactConstraintAtomCFD2* pkAtom, int iIndex);
hkpSimpleContactConstraintAtomCFD2* __cdecl ShrinkBlockIfSparse(hkpSimpleContactConstraintAtomCFD2* pkAtom, int iNumFreeElemsLeft, hkBool& bAtomReallocated);
void __cdecl ReplaceEntry(hkpConstraintInstanceCFD2* pkConstraint, hkpSimpleContactConstraintAtomCFD2* pkOldAtom, hkpSimpleContactConstraintAtomCFD2* pkNewAtom, int iNewSize);

class hkSimpleContactConstraintDataCFD2 {
public:
    void* m_vtbl;
    int m_aiUnk04[2];
    hkArray<hkUint8> m_kAtoms;
    int m_aiUnk18[3];
    hkpConstraintInstanceCFD2* m_pHavokConstraint;
    hkpSimpleContactConstraintAtomCFD2* m_pAtom;
    int m_iAtomSize;

    int FUN_00cfd200(hkpConstraintOwnerCFD2& kConstraintOwner, hkUint16 uiId);
};

// @fnv 0x00cfd200
int hkSimpleContactConstraintDataCFD2::FUN_00cfd200(hkpConstraintOwnerCFD2& kConstraintOwner, hkUint16 uiId)
{
    int iIndex = m_kAtoms.m_data[uiId];
    hkpSimpleContactConstraintAtomCFD2* pkAtom = m_pAtom;
    m_kAtoms.m_data[uiId] = 0xff;
    hkpConstraintInfoCFD2 kConInfo;
    kConInfo.clear();
    hkpSimpleContactConstraintAtomCFD2* pkOldAtom = m_pAtom;
    hkBool bAtomReallocated = false;
    const int iNumContactPoints = pkAtom->m_usNumContactPoints;
    if (iNumContactPoints == 2)
        kConInfo.add(0x20, 1, 1);
    if (iNumContactPoints & 1)
        kConInfo.add(0x30, 1, 1);
    else
        kConInfo.add(0x40, 1, 1);

    FUN_00cfd950(pkAtom, iIndex);
    pkAtom->getContactPointPropertiesStream(iIndex)[0xf] &= ~2;
    pkAtom = ShrinkBlockIfSparse(m_pAtom, 1, bAtomReallocated);
    m_pAtom = pkAtom;
    ((FUN_00cfd7d0_class*)&m_kAtoms)->DecrementBytesAboveValue(iIndex);

    if (m_pHavokConstraint->m_pConstraintInternal)
        kConstraintOwner.subConstraintInfo(m_pHavokConstraint, kConInfo);
    if (bAtomReallocated) {
        ReplaceEntry(m_pHavokConstraint, pkOldAtom, m_pAtom, m_pAtom->m_usSizeOfAllAtoms);
        m_iAtomSize = m_pAtom->m_usSizeOfAllAtoms;
    }
    pkAtom->m_flags |= 5;
    return iNumContactPoints - 1;
}

class hkpEntityCFD;
class hkpWorldCFD;
class hkpContactPointPropertiesCFD;
class hkpSimpleConstraintContactMgrCFD;

class hkpConstraintInstanceCFD {
public:
    virtual ~hkpConstraintInstanceCFD() throw();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkpEntityCFD* m_pEntityA;
    hkpEntityCFD* m_pEntityB;
};

class hkpConstraintOwnerCFD {
public:
    virtual ~hkpConstraintOwnerCFD() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void AddConstraintToCriticalLockedIsland(hkpConstraintInstanceCFD* pkConstraint) throw();
};

template <class T>
struct hkSmallArrayCFD {
    T* m_data;
    hkUint16 m_iElementCount;
    hkUint16 m_iCapacityState;
};

class hkpEntityCFD {
public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    hkMatrix4 unk010;
    hkMatrix4 unk050;
    hkMatrix4 unk090;
    hkMatrix4 unk0D0;
    hkMatrix4 unk110;
    hkMatrix4 unk150;
    hkMatrix4 unk190;
    hkMatrix3 unk1D0;
    hkSmallArrayCFD<void*> m_kContactListeners;
};

struct hkpSimpleContactConstraintAtomCFD {
    hkUint16 unk00;
    hkUint16 unk02;
    hkUint16 unk04;
    hkUint16 m_usMaxNumContactPoints;
    hkUint16 unk08;
    hkUint8 m_ucContactPointPropertiesStriding;
    hkUint8 unk0B;
    hkUint32 unk0C;
    hkVector4 unk10;
    hkVector4 unk20;

    hkpContactPointPropertiesCFD* getContactPointPropertiesStream(int i)
    {
        char* pcBase = reinterpret_cast<char*>(this) + sizeof(hkpSimpleContactConstraintAtomCFD) + m_usMaxNumContactPoints * 0x20;
        return reinterpret_cast<hkpContactPointPropertiesCFD*>(pcBase + i * m_ucContactPointPropertiesStriding);
    }
};

class hkpSimpleContactConstraintDataCFD {
public:
    int unk00;
    int unk04;
    int unk08;
    hkArray<hkUint8> m_kAtoms;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    hkpSimpleContactConstraintAtomCFD* m_pAtom;
    int unk2C;

    hkpContactPointPropertiesCFD* GetContactPointProperties(hkUint16 id)
    {
        int iIndex = m_kAtoms.m_data[id];
        if (iIndex == 0xff)
            return 0;
        return m_pAtom->getContactPointPropertiesStream(static_cast<hkInt16>(iIndex));
    }

    int FUN_00cfd200(hkpConstraintOwnerCFD& kOwner, hkUint16 id) throw();
};

struct hkpContactPointRemovedEventCFD {
    hkUint16 m_usContactPointId;
    hkpContactPointPropertiesCFD* m_pContactPointProperties;
    hkpEntityCFD* m_pEntityA;
    hkpEntityCFD* m_pEntityB;
    int m_iUnknownValue;
    hkpSimpleConstraintContactMgrCFD* m_pContactMgr;
    hkpConstraintOwnerCFD* m_pConstraintOwner;

    hkpContactPointRemovedEventCFD(hkUint16 id, hkpSimpleConstraintContactMgrCFD* pkMgr, hkpConstraintOwnerCFD* pkOwner, hkpContactPointPropertiesCFD* pkProps, hkpEntityCFD* pkA, hkpEntityCFD* pkB)
        : m_usContactPointId(id), m_pContactPointProperties(pkProps), m_pEntityA(pkA), m_pEntityB(pkB), m_pContactMgr(pkMgr), m_pConstraintOwner(pkOwner) {}
};

void __cdecl FUN_00d01900(hkpWorldCFD* pkWorld, hkpContactPointRemovedEventCFD& kEvent) throw();
void __cdecl FUN_00d001c0(hkpEntityCFD* pkEntity, hkpContactPointRemovedEventCFD& kEvent) throw();

class hkpSimpleConstraintContactMgrCFD : public hkReferencedObject {
public:
    int unk08;
    hkpWorldCFD* m_pOwningWorld;
    int unk10;
    hkpSimpleContactConstraintDataCFD m_kSimpleContactConstraintData;
    hkpConstraintInstanceCFD m_pHavokConstraint;

    void FUN_00cfd320(hkUint16 cpId, hkpConstraintOwnerCFD& kOwner) throw();
};

// @fnv 0x00cfd320
void hkpSimpleConstraintContactMgrCFD::FUN_00cfd320(hkUint16 cpId, hkpConstraintOwnerCFD& kOwner) throw()
{
    hkpEntityCFD* pkEntityA = m_pHavokConstraint.m_pEntityA;
    hkpEntityCFD* pkEntityB = m_pHavokConstraint.m_pEntityB;
    hkpContactPointRemovedEventCFD kEvent(cpId, this, &kOwner, m_kSimpleContactConstraintData.GetContactPointProperties(cpId), pkEntityA, pkEntityB);
    FUN_00d01900(m_pOwningWorld, kEvent);
    if (pkEntityA->m_kContactListeners.m_iElementCount)
        FUN_00d001c0(pkEntityA, kEvent);
    if (pkEntityB->m_kContactListeners.m_iElementCount)
        FUN_00d001c0(pkEntityB, kEvent);
    if (m_kSimpleContactConstraintData.FUN_00cfd200(kOwner, cpId) == 0)
        kOwner.AddConstraintToCriticalLockedIsland(&m_pHavokConstraint);
}

class hkReferencedObjectCFD4 {
public:
    hkReferencedObjectCFD4() { m_sReferenceCount = 1; }
    virtual ~hkReferencedObjectCFD4();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkWorldCFD4;

class FUN_00cfd450 : public hkReferencedObjectCFD4 {
public:
    FUN_00cfd450(hkWorldCFD4* pkWorld);
    virtual ~FUN_00cfd450();

    hkWorldCFD4* m_pOwningWorld;
};

// @fnv 0x00cfd450
FUN_00cfd450::FUN_00cfd450(hkWorldCFD4* pkWorld)
{
    m_pOwningWorld = pkWorld;
}

extern int DAT_010cc984;

struct ContactData;
struct ContactCache
{
    unsigned int unk00;
    unsigned short mode04;
    unsigned short unk06;
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
    void FUN_00d92f20(ContactData* data, const unsigned char* first, const unsigned char* second);
};

struct ContactData
{
    unsigned int unk00;
    unsigned short mode04;
    unsigned short unk06;
    ContactCache* cache08;
    ContactCache* cache0C;
    unsigned int unk10;
    const unsigned char* first14;
    const unsigned char* second18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int flags34;

    void FUN_00cf3f40(int enabled);
    void SetActive(unsigned short index);
};

struct ContactManager
{
    int* vtable;
    unsigned short unk04;
    unsigned short state06;
    unsigned int unk08;
    const unsigned char* first0C;
    unsigned short unk10;
    unsigned short unk12;
    ContactCache cache;
    ContactData data;

    ContactManager* InitContact(const unsigned char* first,
                                 const unsigned char* second,
                                 const unsigned char* third);
};

// Initialises the contact manager: sets state, wires the cache and data pointers, looks up a table entry from the two types and applies it via SetActive.
// @fnv 0x00cfd670
ContactManager* ContactManager::InitContact(const unsigned char* first,
                                              const unsigned char* second,
                                              const unsigned char* third)
{
    state06 = 1;
    unk08 = 0;
    vtable = &DAT_010cc984;
    cache.FUN_00d92f20(&data, second, third);
    data.FUN_00cf3f40(1);

    data.first14 = second;
    data.cache0C = &cache;
    data.second18 = third;
    data.flags34 = 0xffffffff;
    first0C = first;
    unk12 = 0;
    unk10 = 0;
    cache.mode04 = 0;
    data.mode04 = 0;

    const unsigned char* table = *reinterpret_cast<const unsigned char* const*>(first + 0x80);
    int firstType = static_cast<signed char>(second[0x2a]);
    int secondType = static_cast<signed char>(third[0x2a]);
    int tableIndex = static_cast<signed char>(table[0x1bb0 + firstType * 10 + secondType]);
    unsigned short result = *reinterpret_cast<const unsigned short*>(table + 0x1c5c + tableIndex * 64);
    data.SetActive(result);
    return this;
}

struct OffsetDescriptor {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char relativeOffset;
};
struct AllocatorInterface {
    virtual void unk00();
    virtual void* allocate(unsigned int size);
};
struct MemoryContext {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocatorInterface* allocator;
};
MemoryContext* __cdecl FUN_00c85750();
struct ContactObject {
    int unk00;
    unsigned short GetAllocationSize;
    ContactObject* InitContact(void* a, void* b, void* c);
};
struct FUN_00cfd780_class {
    void* unk00;
    void* unk04;
    void* m_08;
    ContactObject* AllocateContactObject(OffsetDescriptor* first, OffsetDescriptor* second, int unused);
};
// @fnv 0x00cfd780
ContactObject* FUN_00cfd780_class::AllocateContactObject(OffsetDescriptor* first, OffsetDescriptor* second, int unused)
{
    void* relativeFirst = (char*)first + first->relativeOffset;
    void* relativeSecond = (char*)second + second->relativeOffset;
    MemoryContext* manager = FUN_00c85750();
    ContactObject* pContactObject = (ContactObject*)manager->allocator->allocate(128);
    pContactObject->GetAllocationSize = 128;
    return pContactObject->InitContact(m_08, relativeFirst, relativeSecond);
}

namespace fnv_00cfd9f0 {
class hkMemoryAllocatorCFD9;

struct hkMemoryRouterCFD9 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCFD9* m_pStreamAllocator;
    hkMemoryAllocatorCFD9& heap() { return *m_pStreamAllocator; }
};
extern "C" hkMemoryRouterCFD9& __cdecl FUN_00c85750();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T>
__forceinline void constructWithCopyCFD9(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T>
class hkArrayCFD9 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorCFD9& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyCFD9(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkpShapeKeyMaskCFD9 {
public:
    hkUint8* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void FUN_00cfd9f0(hkArrayCFD9<hkUint16>& kIndicesOut) const;
};

// Appends each index whose mask byte is not 0xff to kIndicesOut.
// @fnv 0x00cfd9f0
void hkpShapeKeyMaskCFD9::FUN_00cfd9f0(hkArrayCFD9<hkUint16>& kIndicesOut) const
{
    for (int i = 0; i < m_iElementCount; i++) {
        if (m_data[i] != 0xff)
            kIndicesOut.AddBack((hkUint16)i);
    }
}
}  // namespace fnv_00cfd9f0

namespace fnv_00cfdb10 {
struct AudioVtable_00cfdb10 {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08(void* object, unsigned short value);
};

struct AudioObject_00cfdb10 {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    AudioVtable_00cfdb10* m_10;
};

AudioObject_00cfdb10* __cdecl FUN_00c85750();

struct ContactManager_00cfdb10 {
    virtual int FUN_00cfdb10(unsigned char flags);
    unsigned short m_04;

    void FUN_00cfd720();
};

__declspec(noinline) void ContactManager_00cfdb10::FUN_00cfd720() {
    g_sink_00cfd660 = 1;
}

void AudioVtable_00cfdb10::vf00() {
}

void AudioVtable_00cfdb10::vf04() {
}

void AudioVtable_00cfdb10::vf08(void* object, unsigned short value) {
}

// Calls FUN_00cfd720, and if bit 0 of flags is set, fetches an audio object and invokes its vtable vf08 with this and m_04.
// @fnv 0x00cfdb10
int ContactManager_00cfdb10::FUN_00cfdb10(unsigned char flags) {
    FUN_00cfd720();

    if ((flags & 1) != 0) {
        AudioObject_00cfdb10* audio = FUN_00c85750();
        audio->m_10->vf08(this, m_04);
    }

    return (int)this;
}
}  // namespace fnv_00cfdb10

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

struct ContactCallDescriptor {
    int kind;
    void* firstManager;
    void* secondManager;
    void* owner;
    int reservedStatus;
    void* sourceTail;
    void* sourceContact;
    unsigned char state0, state1, state2, state3;
    void* sourceHeader;
    void* forwardedArgument;
    void* sourceProperties;
    int statusA, statusB;
};
struct ContactSource {
    void* unk00;
    int unk04, unk08;
    void* firstManager;
    void* secondManager;
    int unk14, member18, unk1c, unk20, unk24, unk28, member2c;
    int unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,member50;
};
extern "C" void __cdecl FUN_00d00ca0(void*, ContactCallDescriptor*);
extern "C" void __cdecl FUN_00cfff00(void*, int*);
struct ContactContext {
    void FUN_00cfcd70(ContactSource* source, void* other);
};
// @fnv 0x00cfcd70
void ContactContext::FUN_00cfcd70(ContactSource* source, void* other)
{
    ContactCallDescriptor info;
    info.owner = this;
    info.kind = 2;
    info.firstManager = source->firstManager;
    info.secondManager = source->secondManager;
    info.reservedStatus = 0;
    info.sourceTail = &source->member50;
    info.sourceContact = &source->member18;
    info.state0 = 0;
    info.state1 = 0;
    info.state2 = 0;
    info.sourceHeader = &source->unk04;
    info.forwardedArgument = other;
    info.sourceProperties = &source->member2c;
    info.statusA = 0;
    info.statusB = 0;
    void* first = source->firstManager;
    FUN_00d00ca0(*(void**)((char*)first + 8), &info);
    info.kind = 0;
    if (*(unsigned short*)((char*)source->firstManager + 0x204) != 0)
        FUN_00cfff00(source->firstManager, &info.kind);
    info.kind = 1;
    if (*(unsigned short*)((char*)source->secondManager + 0x204) != 0)
        FUN_00cfff00(source->secondManager, &info.kind);
}

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T>
class hkArrayCFD5 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    const T* begin() const { return m_data; }
};

struct hkpAgentNnSectorCFD5 {
    unsigned short unk00;
    unsigned short m_uiAgentCount;
};

class hkStatisticsCollectorCFD5 {
public:
    virtual ~hkStatisticsCollectorCFD5() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize, int iAllocatedSize) throw();
    virtual void beginObject(const char* pcName) throw();
    virtual void endObject() throw();

    int m_04;
    int m_08;
    int m_0c;
    bool m_countDontDeallocate;

    void DispatchWithMode(const char* pcName, const void* pvBlock, int iSize, int iFlags) throw();

    template <class T>
    void addArray(const char* pcName, const hkArrayCFD5<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate) {
            int iAllocated = FUN_00d06f80(kArray.begin(), kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

class hkClassCFD5;

class hkpSimpleConstraintContactMgrCFD5 {
public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkArrayCFD5<unsigned char> m_contactIds;
    int unk2C, unk30, unk34, unk38;
    hkpAgentNnSectorCFD5* m_pAtom;

    void FUN_00cfd5e0(hkStatisticsCollectorCFD5* pkCollector, const hkClassCFD5* pkClass) const throw();
};

// Reports the hkpSimpleConstraintContactMgr object to the statistics collector, dispatching the atom and contact ID array.
// @fnv 0x00cfd5e0
void hkpSimpleConstraintContactMgrCFD5::FUN_00cfd5e0(hkStatisticsCollectorCFD5* pkCollector, const hkClassCFD5* pkClass) const throw()
{
    pkCollector->beginObject("hkpSimpleConstraintContactMgr");
    pkCollector->DispatchWithMode("ContactAtom", m_pAtom, m_pAtom->m_uiAgentCount, 0);
    pkCollector->addArray("ContactIds", m_contactIds);
    pkCollector->endObject();
}

struct hkAllocatorCFDA {
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCFDA {
    int unk00, unk04, unk08, unk0C;
    hkAllocatorCFDA* m_pkHeap;
    hkAllocatorCFDA& heap() { return *m_pkHeap; }
};

namespace hkRouterCFDA {
    extern "C" hkMemoryRouterCFDA* __cdecl FUN_00c85750() throw();
}

int __cdecl RoundUpToBucketSize(int iType) throw();

template <typename T>
struct hkArrayCFDA {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayCFDA() throw()
    {
        hkAllocatorCFDA& kAlloc = hkRouterCFDA::FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct hkBlockCFDA {
    unsigned short unk00;
    unsigned short m_type;
};

class hkBaseObjectCFDA {
public:
    virtual ~hkBaseObjectCFDA() throw() {}
    int unk04, unk08;
};

class FUN_00cfda50 : public hkBaseObjectCFDA {
public:
    hkArrayCFDA<char> m_buffer;
    int unk18, unk1C, unk20, unk24;
    hkBlockCFDA* m_block;

    virtual ~FUN_00cfda50() throw();
};

// Releases the hkBlockCFDA held by m_block back to the hkMemoryRouterCFDA heap using its rounded-up bucket size.
// @fnv 0x00cfda50
FUN_00cfda50::~FUN_00cfda50() throw()
{
    hkBlockCFDA* pkBlock = m_block;
    if (pkBlock) {
        int iSize = RoundUpToBucketSize(pkBlock->m_type);
        hkRouterCFDA::FUN_00c85750()->heap().ReleaseBlock(pkBlock, iSize);
    }
}

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" {
__m128 _mm_sub_ps(__m128, __m128);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
void _mm_store_ss(float*, __m128);
}

typedef unsigned short hkContactPointId;
typedef unsigned long hkUlong;

struct hkVec4
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVec4& v) { m_vComponents = v.m_vComponents; }
    __forceinline void setSub4(const hkVec4& a, const hkVec4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline float dot3(const hkVec4& b) const
    {
        __m128 p = _mm_mul_ps(m_vComponents, b.m_vComponents);
        __m128 y = _mm_shuffle_ps(p, p, 0x55);
        y = _mm_add_ss(y, p);
        __m128 z = _mm_shuffle_ps(p, p, 0xaa);
        __m128 d = _mm_add_ss(z, y);
        float r;
        _mm_store_ss(&r, d);
        return r;
    }
};

struct hkContactPt
{
    hkVec4 m_vContactPosition;
    hkVec4 m_vSeparatingNormal;
    float getDistance() const { return m_vSeparatingNormal.m_vComponents.m128_f32[3]; }
};

struct hkCPProperties
{
    float m_fAccumulatedImpulse;
    float m_fImpulseLimit;
    unsigned int m_uiUserData;
    unsigned char m_fSlipAngle;
    unsigned char m_fElasticity;
    unsigned short m_usFlags;
    float m_unk10;
    float getRestitution() const { return m_fElasticity * (1.0f / 128.0f); }
};

struct hkCdBodyStub;
struct hkGskCacheStub;

struct hkProcessCollisionInputStub
{
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068;unsigned char unk06c;
    char m_flag6d;
};

struct hkConstraintInstanceStub;

struct hkConstraintOwnerStub
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void AddConstraintToCriticalSection(hkConstraintInstanceStub* constraint);
    virtual void vf10();
    virtual void AddCallbackRequest(hkConstraintInstanceStub* constraint, int request);
};

struct hkProcessCollisionOutputStub
{
    void* m_unk00;
    hkConstraintOwnerStub* m_pConstraintOwner;
};

struct hkContactListenerArray
{
    void* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
};

struct hkRigidBodyStub
{
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038; unsigned int unk03c; unsigned int unk040; unsigned int unk044; unsigned int unk048; unsigned int unk04c; unsigned int unk050; unsigned int unk054; unsigned int unk058; unsigned int unk05c; unsigned int unk060; unsigned int unk064; unsigned int unk068; unsigned int unk06c; unsigned int unk070; unsigned int unk074; unsigned int unk078; unsigned int unk07c; unsigned int unk080; unsigned int unk084; unsigned int unk088; unsigned int unk08c; unsigned int unk090; unsigned int unk094; unsigned int unk098; unsigned int unk09c; unsigned int unk0a0; unsigned int unk0a4; unsigned int unk0a8; unsigned int unk0ac; unsigned int unk0b0; unsigned int unk0b4; unsigned int unk0b8; unsigned int unk0bc; unsigned int unk0c0; unsigned int unk0c4; unsigned int unk0c8; unsigned int unk0cc; unsigned int unk0d0; unsigned int unk0d4; unsigned int unk0d8; unsigned int unk0dc; unsigned int unk0e0; unsigned int unk0e4; unsigned int unk0e8; unsigned int unk0ec; unsigned int unk0f0; unsigned int unk0f4; unsigned int unk0f8; unsigned int unk0fc; unsigned int unk100; unsigned int unk104; unsigned int unk108; unsigned int unk10c; unsigned int unk110; unsigned int unk114; unsigned int unk118; unsigned int unk11c; unsigned int unk120; unsigned int unk124; unsigned int unk128; unsigned int unk12c; unsigned int unk130; unsigned int unk134; unsigned int unk138; unsigned int unk13c; unsigned int unk140; unsigned int unk144; unsigned int unk148; unsigned int unk14c; unsigned int unk150; unsigned int unk154; unsigned int unk158; unsigned int unk15c; unsigned int unk160; unsigned int unk164; unsigned int unk168; unsigned int unk16c; unsigned int unk170; unsigned int unk174; unsigned int unk178; unsigned int unk17c; unsigned int unk180; unsigned int unk184; unsigned int unk188; unsigned int unk18c; unsigned int unk190; unsigned int unk194; unsigned int unk198; unsigned int unk19c; unsigned int unk1a0; unsigned int unk1a4; unsigned int unk1a8; unsigned int unk1ac; unsigned int unk1b0; unsigned int unk1b4; unsigned int unk1b8; unsigned int unk1bc; unsigned int unk1c0; unsigned int unk1c4; unsigned int unk1c8; unsigned int unk1cc; unsigned int unk1d0; unsigned int unk1d4; unsigned int unk1d8; unsigned int unk1dc; unsigned int unk1e0; unsigned int unk1e4; unsigned int unk1e8; unsigned int unk1ec; unsigned int unk1f0; unsigned int unk1f4; unsigned int unk1f8; unsigned int unk1fc;
    hkContactListenerArray m_kContactListeners;

    void FUN_00ca0c40(const hkVec4& p, hkVec4& vecOut) const;
    float FUN_00cac860() const;
};

struct hkContactPointAddedEventStub
{
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0c;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    int m_iResultCode;
    unsigned int m_unk24;
    unsigned int m_unk28;
    unsigned int m_unk2c;
    unsigned short m_unk30;
    unsigned short m_usNextProcessCallbackDelay;

    hkContactPointAddedEventStub(hkContactPointId id, void* mgr, const hkProcessCollisionInputStub* input,
        hkProcessCollisionOutputStub* output, const hkCdBodyStub* a, const hkCdBodyStub* b, hkContactPt* cp,
        const hkGskCacheStub* gskCache, hkCPProperties* cpProp, float projectedVelocity);
};

void __cdecl FUN_00d01850(void* world, hkContactPointAddedEventStub& event);
void __cdecl FUN_00d00110(hkRigidBodyStub* entity, hkContactPointAddedEventStub& event);

struct hkSimpleContactAtomStub
{
    unsigned int m_unk00;
    unsigned short m_usNumContactPoints;
    unsigned short m_unk06;
    unsigned int m_unk08;
    unsigned short m_usMaxNumContactPointProperties;
};

struct hkSimpleContactConstraintDataStub
{
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010; unsigned int unk014; unsigned int unk018; unsigned int unk01c; unsigned int unk020;
    hkConstraintInstanceStub* m_pHavokConstraint;
    hkSimpleContactAtomStub* m_pAtom;
    unsigned int unk02c;

    hkContactPointId FUN_00d92df0(hkConstraintOwnerStub* owner, hkContactPt** cpOut, hkCPProperties** cpiOut);
};

struct hkConstraintInstanceBody
{
    unsigned int unk000; unsigned int unk004; unsigned int unk008; unsigned int unk00c; unsigned int unk010;
    hkRigidBodyStub* m_kActorEntries[2];
    unsigned int unk01c; unsigned int unk020; unsigned int unk024; unsigned int unk028; unsigned int unk02c; unsigned int unk030; unsigned int unk034; unsigned int unk038;
};

template <class T>
inline T* hkSelectOther(T* a, T* pairA, T* pairB)
{
    return (T*)(hkUlong(a) ^ hkUlong(pairA) ^ hkUlong(pairB));
}

struct hkSimpleConstraintContactMgrStub
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void removeContactPointImpl(hkContactPointId id, hkConstraintOwnerStub* owner);

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_type;
    void* m_pOwningWorld;
    unsigned short m_uiContactPointCount;
    unsigned short m_usNextProcessCallbackDelay;
    hkSimpleContactConstraintDataStub m_kSimpleContactConstraintData;
    hkConstraintInstanceBody m_pHavokConstraint;

    hkRigidBodyStub* FUN_00cfd800(const hkCdBodyStub& a, const hkCdBodyStub& b, int maxImpulse, hkCPProperties* cpi);
    hkContactPointId addContactPointImpl(const hkCdBodyStub& a, const hkCdBodyStub& b, const hkProcessCollisionInputStub& input,
        hkProcessCollisionOutputStub& output, const hkGskCacheStub* contactCache, hkContactPt& cp);
};

// @fnv 0x00cfcf80
hkContactPointId hkSimpleConstraintContactMgrStub::addContactPointImpl(const hkCdBodyStub& a, const hkCdBodyStub& b,
    const hkProcessCollisionInputStub& input, hkProcessCollisionOutputStub& output,
    const hkGskCacheStub* contactCache, hkContactPt& cp)
{
    int numContactPoints = m_kSimpleContactConstraintData.m_pAtom->m_usNumContactPoints;
    if (m_uiContactPointCount + numContactPoints > m_kSimpleContactConstraintData.m_pAtom->m_usMaxNumContactPointProperties - 2)
    {
        return 0xffff;
    }

    if (numContactPoints == 0)
    {
        output.m_pConstraintOwner->AddConstraintToCriticalSection((hkConstraintInstanceStub*)&m_pHavokConstraint);
    }

    hkCPProperties* cpi;
    hkContactPointId id;
    {
        hkContactPt* dcp;
        hkConstraintOwnerStub* owner = output.m_pConstraintOwner;
        id = m_kSimpleContactConstraintData.FUN_00d92df0(owner, &dcp, &cpi);
        *dcp = cp;
    }

    hkRigidBodyStub* rbA = FUN_00cfd800(a, b, 10000, cpi);
    hkRigidBodyStub* rbB = hkSelectOther(rbA, m_pHavokConstraint.m_kActorEntries[0], m_pHavokConstraint.m_kActorEntries[1]);

    hkVec4 velA;
    hkVec4 velB;
    rbA->FUN_00ca0c40(cp.m_vContactPosition, velA);
    rbB->FUN_00ca0c40(cp.m_vContactPosition, velB);

    hkVec4 relVel;
    relVel.setSub4(velA, velB);
    float projectedVel = relVel.dot3(cp.m_vSeparatingNormal);

    cpi->m_fAccumulatedImpulse = 0.0f;
    cpi->m_uiUserData = 0;

    hkContactPointAddedEventStub event(id, this, &input, &output, &a, &b, &cp, contactCache, cpi, projectedVel);
    FUN_00d01850(m_pOwningWorld, event);
    if (rbA->m_kContactListeners.GetLogicalSize())
    {
        FUN_00d00110(rbA, event);
    }
    if (rbB->m_kContactListeners.GetLogicalSize())
    {
        FUN_00d00110(rbB, event);
    }

    if (event.m_iResultCode == 1)
    {
        removeContactPointImpl(id, output.m_pConstraintOwner);
        return 0xffff;
    }

    m_usNextProcessCallbackDelay = event.m_usNextProcessCallbackDelay;

    if (input.m_flag6d && cpi->getRestitution() == 0.0f
        && rbA->m_kContactListeners.GetLogicalSize() <= 0 && rbB->m_kContactListeners.GetLogicalSize() <= 0)
    {
        float invMassB = rbB->FUN_00cac860();
        float invMassSum = rbA->FUN_00cac860() + invMassB;
        float f = 1.0f / (invMassSum + 1e-10f);
        cpi->m_fAccumulatedImpulse = f * -0.2f * projectedVel;
        cpi->m_fImpulseLimit = 0.0f;
        cpi->m_unk10 = cp.getDistance();
    }
    else
    {
        output.m_pConstraintOwner->AddCallbackRequest(m_kSimpleContactConstraintData.m_pHavokConstraint, 1);
    }
    return id;
}

#include <math.h>
struct hkUFloat8q {
    unsigned char m_uiFilterValue;
    hkUFloat8q& operator=(const float& fv);
};

struct hkpMaterialq {
    int m_eResponseType;
    hkReal m_fSlipAngle;
    hkReal m_fElasticity;
};

struct RigidBodyq {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88;
    hkpMaterialq m_iMaterialIndex;
};

struct CdBodyQ;
struct CollidableQ {
    int unk00; int unk04; int unk08; int unk0c;
    signed char m_iOwnerOffset;
    void* getOwner() const { return (void*)((char*)this + m_iOwnerOffset); }
};

struct CdBodyQ {
    void* m_pCollisionShape;
    int m_uiCollisionShapeKey;
    void* m_pMotionState;
    CdBodyQ* m_parent;
    const CdBodyQ* getParent() const { return m_parent; }
    const CollidableQ* getRootCollidable() const { const CdBodyQ* r = this; while (r->m_parent) r = r->m_parent; return reinterpret_cast<const CollidableQ*>(r); }
};

struct ContactPropsQ {
    int unk00; int unk04; int unk08;
    hkUFloat8q m_fSlipAngle;
    unsigned char m_fElasticity;
    unsigned char m_usFlags;
    unsigned char m_flags;
    int unk10;
    int m_aiContactData[1];
    void setRestitution(hkReal r) { m_fElasticity = (unsigned char)fnv_FloatToInt((float)(r * 128.0)); }
};

struct CollisionFilterInfoQ {
    int unk00; int unk04;
    unsigned char m_numA;
    unsigned char m_numB;
};

struct FUN_00cfd800_mgr {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38;
    CollisionFilterInfoQ* m_3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54;
    RigidBodyq* m_pRigidBodyA;
    RigidBodyq* m_pRigidBodyB;

    void* FUN_00cfd800(const CdBodyQ& a, const CdBodyQ& b, int maxNum, ContactPropsQ* cpi);
};

// @fnv 0x00cfd800
void* FUN_00cfd800_mgr::FUN_00cfd800(const CdBodyQ& a, const CdBodyQ& b, int maxNum, ContactPropsQ* cpi)
{
    RigidBodyq* rba = m_pRigidBodyA;
    RigidBodyq* rbb = m_pRigidBodyB;
    cpi->m_fSlipAngle = sqrt(rbb->m_iMaterialIndex.m_fSlipAngle * rba->m_iMaterialIndex.m_fSlipAngle);
    cpi->setRestitution(sqrt(rbb->m_iMaterialIndex.m_fElasticity * rba->m_iMaterialIndex.m_fElasticity));
    cpi->m_usFlags = 0;

    void* bodyA = a.getRootCollidable()->getOwner();

    CollisionFilterInfoQ* info = m_3c;
    int numB = info->m_numB;
    int numA = info->m_numA;
    int* ext = cpi->m_aiContactData;
    if (numA + numB == 0) return bodyA;

    const CdBodyQ* first;
    const CdBodyQ* second;
    if (bodyA == rba) { first = &a; second = &b; }
    else { first = &b; second = &a; bodyA = rbb; }

    if (numA >= maxNum) numA = maxNum;
    int rem = maxNum - numA;
    if (numB >= rem) numB = rem;

    int* dest = &ext[numA];
    if (first->m_uiCollisionShapeKey == -1 && first->m_parent) first = first->m_parent;
    {
        for (int i = 0; first && i < numA; i++) {
            ext[i] = first->m_uiCollisionShapeKey;
            first = first->m_parent;
        }
    }
    if (second->m_uiCollisionShapeKey == -1 && second->m_parent) second = second->m_parent;
    {
        for (int i = 0; second && i < numB; i++) {
            dest[i] = second->m_uiCollisionShapeKey;
            second = second->m_parent;
        }
    }
    return bodyA;
}

namespace fnv_00cfd950 {
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };

struct hkVector4q {
    __m128 m_vComponents;
    void operator=(const hkVector4q& v) { m_vComponents = v.m_vComponents; }
};

struct hkContactPointq {
    hkVector4q m_vContactPosition;
    hkVector4q m_vSeparatingNormal;
};

static __forceinline void memCpy4(void* dst, const void* src, int numWords)
{
    const hkUint32* src32 = reinterpret_cast<const hkUint32*>(src);
    hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
    for (int i = 0; i < numWords; i++)
    {
        *(dst32++) = *(src32++);
    }
}

// Removes the contact point at iIndex from pkAtom by shifting later contact points and their properties down and decrementing m_usNumContactPoints.
// @fnv 0x00cfd950
void __cdecl FUN_00cfd950(hkpSimpleContactConstraintAtomCFD2* pkAtom, int iIndex)
{
    int numContactPoints = pkAtom->m_usNumContactPoints - 1;
    pkAtom->m_usNumContactPoints = hkUint16(numContactPoints);
    hkContactPointq* cp = reinterpret_cast<hkContactPointq*>(pkAtom + 1) + iIndex;
    int striding = pkAtom->m_ucContactPointPropertiesStriding;
    hkUint8* cpp = reinterpret_cast<hkUint8*>(reinterpret_cast<hkContactPointq*>(pkAtom + 1) + pkAtom->m_usMaxNumContactPointProperties)
        + hkInt16(iIndex) * hkInt16(striding);

    for (int i = iIndex; i < numContactPoints; i++)
    {
        cp[0] = cp[1];
        hkUint8* nextCpp = cpp + striding;
        memCpy4(cpp, nextCpp, striding >> 2);
        cp++;
        cpp = nextCpp;
    }
}
}  // namespace fnv_00cfd950

struct Obj { unsigned unk000; unsigned unk004; unsigned unk008; unsigned unk00c; unsigned unk010; unsigned unk014; unsigned unk018; unsigned unk01c; unsigned unk020; unsigned unk024; unsigned unk028; unsigned unk02c; unsigned unk030; unsigned unk034; unsigned unk038; unsigned unk03c; unsigned unk040; unsigned unk044; unsigned unk048; unsigned unk04c; unsigned unk050; unsigned unk054; unsigned unk058; unsigned unk05c; unsigned unk060; unsigned unk064; unsigned unk068; unsigned unk06c; unsigned unk070; unsigned unk074; unsigned unk078; unsigned unk07c; unsigned unk080; unsigned unk084; unsigned unk088; unsigned unk08c; unsigned unk090; unsigned unk094; unsigned unk098; unsigned unk09c; unsigned unk0a0; unsigned unk0a4; unsigned unk0a8; unsigned unk0ac; unsigned unk0b0; unsigned unk0b4; unsigned unk0b8; unsigned unk0bc; unsigned unk0c0; unsigned unk0c4; unsigned unk0c8; unsigned unk0cc; unsigned unk0d0; unsigned unk0d4; unsigned unk0d8; unsigned unk0dc; unsigned unk0e0; unsigned unk0e4; unsigned unk0e8; unsigned unk0ec; unsigned unk0f0; unsigned unk0f4; unsigned unk0f8; unsigned unk0fc; unsigned unk100; unsigned unk104; unsigned unk108; unsigned unk10c; unsigned unk110; unsigned unk114; unsigned unk118; unsigned unk11c; unsigned unk120; unsigned unk124; unsigned unk128; unsigned unk12c; unsigned unk130; unsigned unk134; unsigned unk138; unsigned unk13c; unsigned unk140; unsigned unk144; unsigned unk148; unsigned unk14c; unsigned unk150; unsigned unk154; unsigned unk158; unsigned unk15c; unsigned unk160; unsigned unk164; unsigned unk168; unsigned unk16c; unsigned unk170; unsigned unk174; unsigned unk178; unsigned unk17c; unsigned unk180; unsigned unk184; unsigned unk188; unsigned unk18c; unsigned unk190; unsigned unk194; unsigned unk198; unsigned unk19c; unsigned unk1a0; unsigned unk1a4; unsigned unk1a8; unsigned unk1ac; unsigned unk1b0; unsigned unk1b4; unsigned unk1b8; unsigned unk1bc; unsigned unk1c0; unsigned unk1c4; unsigned unk1c8; unsigned unk1cc; unsigned unk1d0; unsigned unk1d4; unsigned unk1d8; unsigned unk1dc; unsigned unk1e0; unsigned unk1e4; unsigned unk1e8; unsigned unk1ec; unsigned unk1f0; unsigned unk1f4; unsigned unk1f8; unsigned unk1fc; unsigned unk200; unsigned short m204; };
struct EventBase { int a1; int a2; int z18; int u1c; int a6; int a7; int a7b; float f; int result; void* self; EventBase(int a1, int a2, int a3, int* a4, float a5, int a6, int a7, float* a8, int a9, void* owner) : a1(a1), a2(a2), z18(0), a6(a6), a7(a7), a7b(a9), f(*a8), self(owner) {} };
struct Ctx : EventBase { int a3; int* a4; float a5; Ctx(int a1, int a2, int a3, int* a4, float a5, int a6, int a7, float* a8, int a9, void* owner) : EventBase(a1,a2,a3,a4,a5,a6,a7,a8,a9,owner) , a3(a3), a4(a4), a5(a5) {} };
struct Cls;
struct Cls {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(int, int);
    unsigned unk04, unk08; void* m0c; unsigned unk10; unsigned unk14; unsigned unk18; unsigned unk1c; unsigned unk20; unsigned unk24; unsigned unk28; unsigned unk2c; unsigned unk30; unsigned unk34; unsigned unk38; unsigned unk3c; unsigned unk40; unsigned unk44; unsigned unk48; unsigned unk4c; unsigned unk50; unsigned unk54; unsigned m58; unsigned m5c;
    Obj* FUN_00cfd800(int, int, int, int);
    int addToiImpl(int a1, int a2, int a3, int* a4, float a5, int a6, int a7, float* a8, int a9);
};
void __cdecl FUN_00d01850(void*, Ctx*);
void __cdecl FUN_00d00110(Obj*, Ctx*);
// Dispatches an event context to m0c and to two objects with m204 set; result 1 calls v8(a4[1], a9), otherwise *a8 receives the context float; returns the result.
// @fnv 0x00cfce80
int Cls::addToiImpl(int a1, int a2, int a3, int* a4, float a5, int a6, int a7, float* a8, int a9) {
    Obj* o = FUN_00cfd800(a1, a2, 7, a9);
    Obj* p = (Obj*)((unsigned)o ^ m58 ^ m5c);
    Ctx c(a1,a2,a3,a4,a5,a6,a7,a8,a9,this);
    c.result = 0;
    FUN_00d01850(m0c, &c);
    if (o->m204) FUN_00d00110(o, &c);
    if (p->m204) FUN_00d00110(p, &c);
    if (c.result == 1) v8(a4[1], a9);
    else *a8 = c.f;
    return c.result;
}

extern "C" void _mm_stream_ps(float*, __m128);

struct CfdInfoItem {
    __m128 m_v0;
    __m128 m_v1;
    unsigned char* m_table;
    int unk24;
    int unk28;
    int unk2c;
};

struct CfdSolver {
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14(void* data, int flags);
};

struct CfdInfo {
    CfdInfoItem* m_kRayEnd;
    CfdSolver* m_pSolver;
    int unk08;
    int unk0c;
    CfdInfoItem m_items[1];
};

struct CfdHeader {
    int unk00;
    unsigned short unk04;
    unsigned short m_offset;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char m_iElementIndex;
};

struct CfdEntity {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    signed char m_motionOffset;
};

struct CfdBody {
    int unk000; int unk004; int unk008; int unk00c; int unk010; int unk014; int unk018; int unk01c;
    int unk020; int unk024; int unk028; int unk02c; int unk030; int unk034; int unk038; int unk03c;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c;
    int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c;
    int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c;
    int unk0a0; int unk0a4;
    unsigned short unk0a8;
    unsigned short m_uiItemCount;
    int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8;
    int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc; int unk0e0; int unk0e4; int unk0e8;
    int unk0ec; int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108;
    int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128;
    int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148;
    int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168;
    int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188;
    int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4; int unk1a8;
    int unk1ac; int unk1b0; int unk1b4; int unk1b8; int unk1bc; int unk1c0; int unk1c4; int unk1c8;
    int unk1cc; int unk1d0; int unk1d4; int unk1d8; int unk1dc; int unk1e0; int unk1e4; int unk1e8;
    int unk1ec; int unk1f0; int unk1f4; int unk1f8; int unk1fc; int unk200;
    unsigned short m_numJac;
};

struct CfdMgr;

template <class T> inline T CfdMin(T a, T b) { return a < b ? a : b; }

struct CfdParams {
    CfdEntity* m_kPointA;
    CfdEntity* m_kPointB;
    int unk08;
    CfdInfo* m_info;
    void* m_ptrs[256];
    CfdMgr* m_pOwnerObject;
};

extern "C" void __cdecl NotifyShapeSetListeners(void* a, CfdParams* p);
extern "C" void __cdecl FUN_00d00270(void* a, CfdParams* p);

struct CfdMgr {
    int unk00;
    int unk04;
    int unk08;
    void* unk0c;
    unsigned short unk10;
    unsigned short m_uiItemCount;
    int unk14;
    int unk18;
    int unk1c;
    int m_uiEdgeIndex;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    void* m_data;
    CfdHeader* m_kHeader;

    void FUN_00cfd470(CfdEntity* a, CfdEntity* b, int unused, CfdInfo* info);
};

// If m_uiItemCount is zero, builds params and runs NotifyShapeSetListeners, FUN_00d00270 and method14; then updates the count and streams item vectors into the header.
// @fnv 0x00cfd470
void CfdMgr::FUN_00cfd470(CfdEntity* apEntityA, CfdEntity* apEntityB, int unused, CfdInfo* info)
{
    int newCount = m_uiItemCount;
    if (newCount-- == 0) {
        CfdBody* bodyA = (CfdBody*)((char*)apEntityA + apEntityA->m_motionOffset);
        CfdBody* bodyB = (CfdBody*)((char*)apEntityB + apEntityB->m_motionOffset);
        newCount = CfdMin(bodyA->m_uiItemCount, bodyB->m_uiItemCount);
        CfdParams params;
        params.m_kPointA = apEntityA;
        params.m_kPointB = apEntityB;
        params.m_info = info;
        params.m_pOwnerObject = this;
        CfdInfoItem* end = info->m_kRayEnd;
        void** out = params.m_ptrs;
        for (CfdInfoItem* pItem = info->m_items; pItem < end; pItem++) {
            int idx = pItem->m_table[m_uiEdgeIndex];
            void* ptr;
            if (idx == 0xff) {
                ptr = 0;
            } else {
                CfdHeader* h = m_kHeader;
                ptr = (char*)h + (short)idx * h->m_iElementIndex + h->m_offset * 32 + 0x30;
            }
            *out++ = ptr;
        }
        NotifyShapeSetListeners(unk0c, &params);
        if (bodyA->m_numJac != 0) FUN_00d00270(bodyA, &params);
        if (bodyB->m_numJac != 0) FUN_00d00270(bodyB, &params);
        info->m_pSolver->method14(m_data, 8);
    }
    m_uiItemCount = newCount;
    CfdInfoItem* end = info->m_kRayEnd;
    for (CfdInfoItem* pItem = info->m_items; pItem < end; pItem++) {
        float* dst = (float*)((char*)m_kHeader + pItem->m_table[m_uiEdgeIndex] * 32 + 0x30);
        _mm_stream_ps(dst, pItem->m_v0);
        _mm_stream_ps(dst + 4, pItem->m_v1);
    }
}

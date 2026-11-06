// gamebryo2.2/corelibs/nianimation/niblendboolinterpolator.cpp: NiBlendBoolInterpolator, BlendBoolShell (13 functions)

#include "niblendboolinterpolator_types_NiBlendBoolInterpolator.h"
#include "niblendboolinterpolator_types_NiStream.h"
#include "niblendboolinterpolator_NiBinaryStream.h"

// @fnv 0x00a56880
bool NiBlendBoolInterpolator::Update(float time, NiObjectNET* target, bool& value)
{
    bool updated = false;
    if (m_ucInterpCount == 1)
    {
        updated = UpdateAccumulatedTransform(time, target, value);
    }
    else if (m_ucInterpCount > 0)
    {
        NiBlendInterpolator::NormalizeWeights();
        updated = UpdateSingleInterpolator(time, target, value);
    }
    m_fLastTime = time;
    return updated;
}

struct FUN_00a565a0_shell : public NiBlendBoolInterpolator
{
    bool FUN_00a565a0(NiInterpolator*);
};

// Calls the virtual function at offset 0xa4 on pkInterpolator and returns its bool result.
// @fnv 0x00a565a0
bool FUN_00a565a0_shell::FUN_00a565a0(NiInterpolator* pkInterpolator)
{
    return (*(bool(__thiscall**)(NiInterpolator*))(*(int*)pkInterpolator + 0xa4))(pkInterpolator);
}

class BSFadeNode
{
  public:
    static void* __cdecl operator new(unsigned int);
};

void __fastcall FUN_00a36890(void* pThis);
extern int DAT_0109a67c;

// @fnv 0x00a565c0
void* __cdecl FUN_00a565c0()
{
    void* p = BSFadeNode::operator new(0x34);
    if (p)
    {
        FUN_00a36890(p);
        *reinterpret_cast<void**>(p) = &DAT_0109a67c;
        reinterpret_cast<unsigned char*>(p)[0x30] = DAT_0109a914;
        return p;
    }
    return 0;
}

struct FUN_00a568e0_shell : public NiBlendBoolInterpolator
{
    void FUN_00a568e0(NiStream*);
};

// Loads the base NiBlendInterpolator data from kStream, then reads one byte into this+0x30 and advances the stream position by the bytes read.
// @fnv 0x00a568e0
void FUN_00a568e0_shell::FUN_00a568e0(NiStream* kStream)
{
    NiBlendInterpolator::LoadBinary(*kStream);
    NiBinaryStream* __restrict input = *(NiBinaryStream**)((char*)kStream + 0x24c);
    unsigned int size = 1;
    *(unsigned int*)((char*)input + 4) +=
        (*(unsigned int(__cdecl**)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int))(
            (char*)input + 8))(input, (char*)this + 0x30, 1, &size, 1);
}

extern int DAT_0109a67c;
// Constructs a NiBlendInterpolator with the given arguments, installs the vtable at DAT_0109a67c and sets byte 0x30 from DAT_0109a914.
// @fnv 0x00a56560
NiBlendInterpolator* __fastcall ConstructBlendInterpolator(NiBlendInterpolator* self, int unused, bool a, float b,
                                                           unsigned char c)
{
    self->NiBlendInterpolator::NiBlendInterpolator(a, b, c);
    *(int**)self = &DAT_0109a67c;
    *((unsigned char*)self + 0x30) = DAT_0109a914;
    return self;
}

struct M76Obj
{
    char pad[0x30];
    bool m_bBoolValue;
    bool FUN_00a36fd0(M76Obj*);
    bool IsBoolValueEqual(M76Obj*);
};
// Returns true if FUN_00a36fd0 succeeds and this object's m_bBoolValue equals the passed object's m_bBoolValue.
// @fnv 0x00a565f0
bool M76Obj::IsBoolValueEqual(M76Obj* pkObject)
{
    if (!FUN_00a36fd0(pkObject))
        return false;
    M76Obj* pkDest = pkObject;
    return m_bBoolValue == pkDest->m_bBoolValue ? true : false;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f407c;
// @fnv 0x00a56620
void* __cdecl FUN_00a56620()
{
    return &g_011f407c;
}

void __fastcall DestroyInterpolatorArray(void*);
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// Calls DestroyInterpolatorArray on self, then if flags has bit 0 set calls __Dummy_00b6fef0 with self and 0x34, and returns self.
// @fnv 0x00a56630
void* __fastcall FUN_00a56630(void* self, int, unsigned int flags)
{
    DestroyInterpolatorArray(self);
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x34);
    return self;
}

namespace fnv_00a56650 {
extern int DAT_0109a67c;
extern unsigned char DAT_0109a914;
void __fastcall FUN_00a36890(void*);
struct M76Obj
{
    void* vtbl;
    char pad[0x2c];
    unsigned char m_bBoolValue;
    static void* __cdecl operator new(unsigned int);
    void FUN_00a37510(M76Obj*, void*);
};
// Allocates and initialises an M76Obj, passes it to self's FUN_00a37510 with cloning, copies self's m_bBoolValue into it and returns it.
// @fnv 0x00a56650
M76Obj* __fastcall CreateClone(M76Obj* self, int, void* cloning)
{
    M76Obj* pkObject = new M76Obj;
    if (pkObject)
    {
        FUN_00a36890(pkObject);
        pkObject->vtbl = &DAT_0109a67c;
        pkObject->m_bBoolValue = DAT_0109a914;
    }
    else
    {
        pkObject = 0;
    }
    self->FUN_00a37510(pkObject, cloning);
    pkObject->m_bBoolValue = self->m_bBoolValue;
    return pkObject;
}
}  // namespace fnv_00a56650

namespace fnv_00a566a0 {
extern float DAT_0109696c;
extern unsigned char DAT_0109a914;
struct M76Ctrl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual bool Update(float, void*, bool*);
};
struct M76Obj
{
    void* vtbl;
    char pad4[8];
    unsigned int m_uiValue1;
    char pad10[8];
    M76Ctrl* m_pkInterp;
    char pad1c[4];
    float m_fLastTime;
    char pad24[0xc];
    unsigned char m_bBoolValue;
    bool UpdateInterpBool(float, void*, bool*);
};
// @fnv 0x00a566a0
bool M76Obj::UpdateInterpBool(float fTime, void* pkInterpTarget, bool* bValue)
{
    if (m_uiValue1 & 1)
        fTime = m_fLastTime;
    if (fTime == DAT_0109696c)
        return false;
    if (m_pkInterp->Update(fTime, pkInterpTarget, bValue))
    {
        m_bBoolValue = *bValue;
        return true;
    }
    *bValue = false;
    m_bBoolValue = DAT_0109a914;
    return false;
}
}  // namespace fnv_00a566a0

namespace fnv_00a56920 {
struct M76Bin
{
    unsigned int pad0;
    unsigned int position;
    unsigned int pad1;
    unsigned int(__cdecl* write)(M76Bin*, const void*, unsigned int, unsigned int*, unsigned int);
};
struct M76Stream
{
    char pad[0x250];
    M76Bin* output;
};
struct M76Obj
{
    void FUN_00a37ec0(M76Stream*);
    char pad[0x30 - 0];
    void SaveBinary(M76Stream*);
};
// Writes the object's base data via FUN_00a37ec0, then writes one byte at offset 0x30 through the stream's output bin.
// @fnv 0x00a56920
void __fastcall SaveBinary(M76Obj* self, int, M76Stream* stream)
{
    self->FUN_00a37ec0(stream);
    M76Bin* __restrict out = stream->output;
    unsigned int size = 1;
    out->position += out->write(out, reinterpret_cast<char*>(self) + 0x30, 1, &size, 1);
}
}  // namespace fnv_00a56920

namespace fnv_00a56960 {
struct M76Arr
{
    void* vtbl;
    void* data;
    unsigned short m_usMaxSize;
    unsigned short m_usESize;
    unsigned short pad0c;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* item)
    {
        unsigned int index = m_usESize;
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        SetAt(index, item);
    }
};
struct M76Obj
{
    char pad[0x30];
    unsigned char m_bBoolValue;
    void FUN_00a38080(M76Arr*);
};
struct M76Glob
{
    int pad;
};
extern M76Glob* g_011f407c;
char* __cdecl FUN_00a7d330(M76Glob*);
char* __cdecl FUN_00a7d410(const char*, unsigned int);
// Calls FUN_00a38080, then appends the result of FUN_00a7d330 and the formatted "m_bBoolValue" string to pkStrings.
// @fnv 0x00a56960
void __fastcall AddBoolValueStrings(M76Obj* self, int, M76Arr* pkStrings)
{
    self->FUN_00a38080(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_011f407c));
    pkStrings->Add(FUN_00a7d410("m_bBoolValue", self->m_bBoolValue));
}
}  // namespace fnv_00a56960

struct NiInterpolatorPtr
{
    NiInterpolator* m_pObject;
    operator NiInterpolator*() const
    {
        return m_pObject;
    }
    NiInterpolator* operator->() const
    {
        return m_pObject;
    }
};

class NiBlendInterpolator__InterpArrayItem
{
  public:
    NiInterpolatorPtr m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    char m_cPriority;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};

// stand-in for the vtable layout: Update(float, NiObjectNET*, bool&) is slot 40 (+0xa0)
struct BoolInterpUpdater
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
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual bool Update(float, NiObjectNET*, unsigned char&);
};

struct BlendBoolShell : public NiBlendBoolInterpolator
{
    bool GetUpdateTimeForItem(float& fTime, NiBlendInterpolator__InterpArrayItem& kItem)
    {
        NiInterpolator* pkInterpolator = kItem.m_spControllerInterpolator;
        if (pkInterpolator && kItem.m_fNormalizedWeight != 0.0f)
        {
            if (m_uiObjectFlags & 1)
                fTime = kItem.m_fLastEvaluationTime;
            if (fTime == DAT_0109696c)
                return false;
            return true;
        }
        return false;
    }
    bool FUN_00a56710(float, NiObjectNET*, bool&);
};

// Accumulates successful interpolator updates by normalized weight; when any update succeeds, sets both boolean values using a 0.5 threshold.
// @fnv 0x00a56710
bool BlendBoolShell::FUN_00a56710(float fTime, NiObjectNET* pkInterpTarget, bool& bValue)
{
    float fTotalValue = 0.0f;
    float fTotalWeight = 1.0f;
    bool bModifiedValue = false;
    for (unsigned char uc = 0; uc < m_ucArraySize; uc++)
    {
        unsigned int uOff = uc * sizeof(NiBlendInterpolator__InterpArrayItem);
        NiBlendInterpolator__InterpArrayItem& kItem = m_pInterpArray[uc];
        if (kItem.m_spControllerInterpolator && m_pInterpArray[uc].m_fNormalizedWeight > 0.0f)
        {
            float fUpdateTime = fTime;
            if (!GetUpdateTimeForItem(fUpdateTime, m_pInterpArray[uc]))
            {
                fTotalWeight -= kItem.m_fNormalizedWeight;
                continue;
            }
            unsigned char bInterpValue;
            if (((BoolInterpUpdater*)(NiInterpolator*)kItem.m_spControllerInterpolator)
                    ->Update(fUpdateTime, pkInterpTarget, bInterpValue))
            {
                int iV;
                NiBlendInterpolator__InterpArrayItem* pA = m_pInterpArray;
                *(volatile int*)&iV = bInterpValue;
                fTotalValue += ((NiBlendInterpolator__InterpArrayItem*)((char*)pA + uOff))->m_fNormalizedWeight * iV;
                bModifiedValue = true;
            }
            else
            {
                fTotalWeight -= m_pInterpArray[uc].m_fNormalizedWeight;
            }
        }
    }
    if (!bModifiedValue)
    {
        bValue = false;
        m_bBoolValue = DAT_0109a914;
        return false;
    }
    float fValue = fTotalValue / fTotalWeight;
    if (fValue < 0.5f)
    {
        m_bBoolValue = false;
        bValue = false;
    }
    else
    {
        m_bBoolValue = true;
        bValue = true;
    }
    return true;
}

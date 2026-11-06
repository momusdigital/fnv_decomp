// gamebryo2.2/corelibs/nianimation/niblendfloatinterpolator.cpp: NiBlendFloatInterpolator, NiBlendInterpolator, BlendFloatSource (12 functions)

#include "niblendfloatinterpolator_pre.h"
#include "niblendfloatinterpolator_types_NiStream.h"
#include "niblendfloatinterpolator_types_NiBlendFloatInterpolator.h"
#include "NiObjectNET.h"

// Updates the blend interpolator for the given time and target, delegating to single or multi-interpolator update paths and storing the last time.
// @fnv 0x00a40810
bool NiBlendFloatInterpolator::Update(float time, NiObjectNET* target, float& value)
{
    bool result = false;
    if (m_ucInterpCount == 1)
        result = NiBlendFloatInterpolator::UpdateAccumulatedTransform(time, target, value);
    else if (m_ucInterpCount > 0)
    {
        NiBlendInterpolator::NormalizeWeights();
        result = NiBlendFloatInterpolator::UpdateSingleInterpolator(time, target, value);
    }
    m_fLastTime = time;
    return result;
}

__forceinline void ReadFloat(NiBinaryStream* input, float* value)
{
    unsigned int size = 4;
    input->m_uiStreamFlags += input->m_pfnRead(input, value, 4, &size, 1);
}
// Calls the base NiBlendInterpolator::LoadBinary, then reads a float from the stream into m_fFloatValue.
// @fnv 0x00a40870
void NiBlendFloatInterpolator::LoadBinary(NiStream& stream)
{
    NiBlendInterpolator::LoadBinary(stream);
    ReadFloat(stream.m_pUnderlyingStream, &m_fFloatValue);
}

// @fnv 0x00a40640
bool NiBlendFloatInterpolator::UpdateAccumulatedTransform(float time, NiObjectNET* target, float& value)
{
    if (m_uiObjectFlags & 1)
        time = m_fSingleInterpolatorTime;
    if (time == DAT_0109696c)
        return false;
    if (m_pSingleInterpolator->vfn_09c(time, target, m_fFloatValue))
    {
        value = m_fFloatValue;
        return true;
    }
    m_fFloatValue = DAT_0109a918;
    value = DAT_0109a918;
    return false;
}

__forceinline bool NiBlendInterpolator::GetBlendUpdateTime(float& time, NiBlendInterpolator__InterpArrayItem& item)
{
    if (!item.m_spControllerInterpolator || item.m_fNormalizedWeight == 0.0f)
        return false;
    if (m_uiObjectFlags & 1)
        time = item.m_fLastEvaluationTime;
    return time != DAT_0109696c;
}

// Blends weighted float values from the interpolator array into m_fFloatValue, normalizing by total weight, and writes the result to value.
// @fnv 0x00a406c0
bool NiBlendFloatInterpolator::UpdateSingleInterpolator(float time, NiObjectNET* target, float& value)
{
    m_fFloatValue = 0.0f;
    bool valid = false;
    float totalWeight = 1.0f;
    float currentValue;
    for (unsigned char i = 0; i < m_ucArraySize; ++i)
    {
        NiInterpolator* interpolator = m_pInterpArray[i].m_spControllerInterpolator;
        if (interpolator && m_pInterpArray[i].m_fNormalizedWeight > 0.0f)
        {
            NiBlendInterpolator__InterpArrayItem& item = m_pInterpArray[i];
            float updateTime = time;
            if (!GetBlendUpdateTime(updateTime, item))
                totalWeight -= item.m_fNormalizedWeight;
            else if (interpolator->vfn_09c(updateTime, target, currentValue))
            {
                valid = true;
                m_fFloatValue += m_pInterpArray[i].m_fNormalizedWeight * currentValue;
            }
            else
                totalWeight -= m_pInterpArray[i].m_fNormalizedWeight;
        }
    }
    m_fFloatValue /= totalWeight;
    if (!valid)
    {
        value = DAT_0109a918;
        m_fFloatValue = DAT_0109a918;
        return false;
    }
    value = m_fFloatValue;
    return true;
}

struct FUN_00a40560_shell : public NiBlendFloatInterpolator
{
    bool FUN_00a40560(NiInterpolator*);
};

struct Vtable_00a40560
{
    char pad[0xa8];
    bool(__thiscall* fn)(void*);
};

// Calls the function pointer at offset 0xa8 in pkInterpolator's vtable and returns its bool result.
// @fnv 0x00a40560
bool FUN_00a40560_shell::FUN_00a40560(NiInterpolator* pkInterpolator)
{
    return (**(Vtable_00a40560**)pkInterpolator).fn(pkInterpolator);
}

struct FUN_00a40520 : NiBlendInterpolator
{
    float m_fFloatValue;
    FUN_00a40520(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize);
    virtual ~FUN_00a40520();
};
// Constructs the interpolator via NiBlendInterpolator and initializes m_fFloatValue from DAT_0109a918.
// @fnv 0x00a40520
FUN_00a40520::FUN_00a40520(bool onlyUseHighestWeight, float weightThreshold, unsigned char arraySize)
    : NiBlendInterpolator(onlyUseHighestWeight, weightThreshold, arraySize)
{
    m_fFloatValue = DAT_0109a918;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

void __fastcall FUN_00a36890(void*);
extern const void* vftable_NiBlendFloatInterpolator[];

// @fnv 0x00a40580
void* __cdecl CreateNiBlendFloatInterpolator()
{
    void* pInterpolator = BSFadeNode::operator new(0x34);
    if (pInterpolator)
    {
        FUN_00a36890(pInterpolator);
        *(void**)pInterpolator = (void*)vftable_NiBlendFloatInterpolator;
        *(float*)((char*)pInterpolator + 0x30) = DAT_0109a918;
        return pInterpolator;
    }
    return 0;
}

struct M76Obj
{
    char pad[0x30];
    float m_fFloatValue;
    bool FUN_00a36fd0(M76Obj*);
    bool IsFloatValueEqual(M76Obj*);
};
// Returns true if FUN_00a36fd0 succeeds and this object's m_fFloatValue equals the passed object's m_fFloatValue.
// @fnv 0x00a405b0
bool M76Obj::IsFloatValueEqual(M76Obj* pkObject)
{
    if (!FUN_00a36fd0(pkObject))
        return false;
    M76Obj* pkDest = pkObject;
    if (m_fFloatValue != pkDest->m_fFloatValue)
        return false;
    return true;
}

struct GlobalObjectO2_00a7b610
{
    int pad;
};
extern GlobalObjectO2_00a7b610 g_011f3e58;
// @fnv 0x00a405e0
void* __cdecl FUN_00a405e0()
{
    return &g_011f3e58;
}

namespace fnv_00a408b0 {
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
// @fnv 0x00a408b0
void __fastcall SaveBinary(M76Obj* self, int, M76Stream* stream)
{
    self->FUN_00a37ec0(stream);
    M76Bin* __restrict out = stream->output;
    unsigned int size = 4;
    out->position += out->write(out, reinterpret_cast<char*>(self) + 0x30, 4, &size, 1);
}
}  // namespace fnv_00a408b0

namespace fnv_00a408f0 {
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
    float m_fFloatValue;
    void FUN_00a38080(M76Arr*);
};
struct M76Glob
{
    int pad;
};
extern M76Glob* g_011f3e58;
char* __cdecl FUN_00a7d330(M76Glob*);
char* __cdecl FUN_00a7d550(const char*, float);
// Calls FUN_00a38080 on self, then appends the result of FUN_00a7d330(g_011f3e58) and a formatted "m_fFloatValue" string to pkStrings.
// @fnv 0x00a408f0
void __fastcall AppendFloatValueStrings(M76Obj* self, int, M76Arr* pkStrings)
{
    self->FUN_00a38080(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_011f3e58));
    pkStrings->Add(FUN_00a7d550("m_fFloatValue", self->m_fFloatValue));
}
}  // namespace fnv_00a408f0

extern void* __cdecl FUN_00aa13e0(unsigned int size);
struct CopyMembersArguments
{
    NiBlendFloatInterpolator* destination;
    void* cloningProcess;
};
extern "C" void __fastcall FUN_00a37510(void* source, CopyMembersArguments args);

struct BlendFloatSource : NiBlendFloatInterpolator
{
    NiBlendFloatInterpolator* __thiscall CreateClone(void* cloning);
};

// Allocates a NiBlendFloatInterpolator, initialises it, copies members from this via FUN_00a37510, and returns the clone.
// @fnv 0x00a405f0
NiBlendFloatInterpolator* BlendFloatSource::CreateClone(void* pCloningProcess)
{
    NiBlendFloatInterpolator* copy =
        static_cast<NiBlendFloatInterpolator*>(FUN_00aa13e0(sizeof(NiBlendFloatInterpolator)));
    if (copy)
    {
        FUN_00a36890(copy);
        *reinterpret_cast<const void***>(copy) = vftable_NiBlendFloatInterpolator;
        copy->m_fFloatValue = DAT_0109a918;
    }
    else
    {
        copy = 0;
    }
    CopyMembersArguments args = {copy, pCloningProcess};
    FUN_00a37510(this, args);
    copy->m_fFloatValue = m_fFloatValue;
    return copy;
}

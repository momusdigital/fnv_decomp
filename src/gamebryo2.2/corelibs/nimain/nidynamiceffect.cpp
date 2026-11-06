// gamebryo2.2/corelibs/nimain/nidynamiceffect.cpp: EffectObject, FNVEffect (7 functions)

#include "nidynamiceffect_decls.h"

// @fnv 0x00a68ea0
void NiDynamicEffect::LoadBinary(NiStream& stream)
{
    NiAVObject::LoadBinary(stream);
    if (stream.m_uiNifVersion >= 0x0a010066)
    {
        unsigned char on;
        ReadBinaryValue(stream, on);
        m_bEffectEnabled = on != 0;
    }
    if (stream.m_uiNifVersion < 0x04010000)
    {
        int count;
        ReadBinaryValue(stream, count);
        for (int i = 0; i < count; ++i)
        {
            unsigned int linkID;
            ReadBinaryValue(stream, linkID);
        }
    }
    if (stream.m_uiNifVersion >= 0x0a00010e)
        stream.ReadUnsignedInteger();
}

// @fnv 0x00a69070
void NiDynamicEffect::LinkObject(NiStream& stream)
{
    NiAVObject::LinkObject(stream);
    if (stream.m_uiNifVersion >= 0x0a00010e)
    {
        unsigned int count = stream.GetLinkID();
        while (count--)
        {
            NiNode* node = reinterpret_cast<NiNode*>(stream.GetLoadedObject());
            if (node)
            {
                NiTListItem<NiNode*>* item = NiDynamicEffectNewListItem();
                item->m_element = node;
                item->m_pkPrev = 0;
                item->m_pkNext = m_kAffectedNodes.m_pkHead;
                if (m_kAffectedNodes.m_pkHead)
                    m_kAffectedNodes.m_pkHead->m_pkPrev = item;
                else
                    m_kAffectedNodes.m_pkTail = item;
                ++m_kAffectedNodes.m_kItemCount.m_uiCount;
                m_kAffectedNodes.m_pkHead = item;
            }
        }
    }
}

// @fnv 0x00a69320
NiDynamicEffect::NiDynamicEffect()
    : m_bEffectEnabled(true), m_ucEffectCategory(0xff), m_uiEffectPushCount(0), m_uiRevID(1)
{
    m_iIndex = InterlockedIncrement(&DAT_011a9b58);
}

void __fastcall FUN_00a5a390(void*);
void __fastcall FUN_00a68e30(void*);
struct BSShaderLightingProperty
{
    void ClearLights();
};
void __cdecl _delete(void*, unsigned int);

extern const void* vftable_NiDynamicEffect;

struct FUN_00a69390_shell : public NiDynamicEffect
{
    void* __thiscall DestroyNiDynamicEffect(unsigned int flags);
};

// @fnv 0x00a69390
void* __thiscall FUN_00a69390_shell::DestroyNiDynamicEffect(unsigned int flags)
{
    *reinterpret_cast<void**>(this) = &vftable_NiDynamicEffect;
    FUN_00a68e30(this);
    reinterpret_cast<BSShaderLightingProperty*>(reinterpret_cast<char*>(this) + 0xb8)->ClearLights();
    reinterpret_cast<BSShaderLightingProperty*>(reinterpret_cast<char*>(this) + 0xac)->ClearLights();
    FUN_00a5a390(this);
    if (flags & 1)
        _delete(this, 0xc4);
    return this;
}

struct StrArr
{
    void* m_vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char* const&);
    unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    void SetAtInline(unsigned int uiIndex, char* element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element)
                m_usESize++;
        }
        else
        {
            if (element)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int AddInline(char* element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAtInline(uiIndex, element);
        return uiIndex;
    }
};
struct FUN_00a5ea70_t
{
    void FUN_00a5ad00(StrArr*);
};
int NiSprintf(char*, unsigned int, const char*, ...);
char* FUN_00a7d330(const char*);
char* __cdecl FUN_00a7d5a0(const char*, void*);
extern const char* const g_011f4a28_arg1;
struct NiNode;
struct Zx3ListNode
{
    Zx3ListNode* m_pkNext;
    Zx3ListNode* m_pkPrev;
    NiNode* m_element;
};
inline NiNode* Zx3GetNext(Zx3ListNode*& kPos)
{
    NiNode*& element = kPos->m_element;
    kPos = kPos->m_pkNext;
    return element;
}
struct Zx3Effect : public NiAVObject
{
    bool m_bEffectEnabled;
    unsigned char m_ucEffectCategory;
    int m_iIndex;
    unsigned int m_uiEffectPushCount;
    unsigned int m_uiRevID;
    Zx3ListNode* m_pkAffectedHead;
    Zx3ListNode* m_pkAffectedTail;
    int m_uiAffectedCount;
    Zx3ListNode* m_pkUnaffectedHead;
    void GetViewerStrings(StrArr* pkStrings);
};

// @fnv 0x00a69140
void Zx3Effect::GetViewerStrings(StrArr* pkStrings)
{
    ((FUN_00a5ea70_t*)this)->FUN_00a5ad00(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_011f4a28_arg1));
    if (m_uiAffectedCount)
    {
        Zx3ListNode* kPos = m_pkAffectedHead;
        int i = 0;
        while (kPos)
        {
            NiNode* pkNode = Zx3GetNext(kPos);
            char acPrefix[64];
            NiSprintf(acPrefix, 64, "affected node[%d]", i);
            pkStrings->AddInline(FUN_00a7d5a0(acPrefix, pkNode));
            i++;
        }
        kPos = m_pkUnaffectedHead;
        while (kPos)
        {
            NiNode* pkNode = Zx3GetNext(kPos);
            char acPrefix[64];
            NiSprintf(acPrefix, 64, "unaffected node[%d]", i);
            pkStrings->AddInline(FUN_00a7d5a0(acPrefix, pkNode));
            i++;
        }
    }
}

struct EffectObject : NiDynamicEffect
{
    void __thiscall FUN_00a5a900(NiStream* stream);
    void __thiscall SaveToStream(NiStream* stream);
};
static __forceinline unsigned int WriteBytes(NiBinaryStream* output, const void* bytes, unsigned int length)
{
    unsigned int componentLength = length;
    unsigned int written = output->m_pfnWrite(output, bytes, length, &componentLength, 1);
    output->m_uiStreamFlags += written;
    return written;
}
typedef void(__thiscall* SaveLinkedObject)(NiStream*, NiNode*);
static __forceinline void WriteLinkedObject(NiStream* stream, NiNode*& object)
{
    ((SaveLinkedObject*)stream->m_ppVirtualMethodTable)[12](stream, object);
}
// @fnv 0x00a68f80
void __thiscall EffectObject::SaveToStream(NiStream* stream)
{
    FUN_00a5a900(stream);
    unsigned char enabled = m_bEffectEnabled;
    NiBinaryStream* output = stream->m_pBackingStream;
    WriteBytes(output, &enabled, 1);
    int objectCount = m_kAffectedNodes.m_kItemCount.m_uiCount;
    output = stream->m_pBackingStream;
    WriteBytes(output, &objectCount, 4);
    if (objectCount > 0)
    {
        NiTListItem<NiNode*>* node = m_kAffectedNodes.m_pkTail;
        while (node)
        {
            NiNode*& element = node->m_element;
            node = node->m_pkPrev;
            WriteLinkedObject(stream, element);
        }
    }
}

static inline NiNode* GetNext(NiTListItem<NiNode*>*& node)
{
    NiNode*& element = node->m_element;
    node = node->m_pkNext;
    return element;
}
class FNVEffect : public NiDynamicEffect
{
  public:
    bool __thiscall FUN_00a5a260(FNVEffect* other);
    bool __thiscall IsEqual(FNVEffect* other);
};
// Returns false if counts differ or paired entries differ in nullness; otherwise returns true if FUN_00a5a260 succeeds.
// @fnv 0x00a68d80
bool __thiscall FNVEffect::IsEqual(FNVEffect* other)
{
    if (!FUN_00a5a260(other))
        return false;
    if (m_kEffectTargetNodes.m_kItemCount.m_uiCount != other->m_kEffectTargetNodes.m_kItemCount.m_uiCount)
        return false;
    if (m_kEffectTargetNodes.m_kItemCount.m_uiCount > 0)
    {
        NiTListItem<NiNode*>* left = m_kEffectTargetNodes.m_pkHead;
        NiTListItem<NiNode*>* right = other->m_kEffectTargetNodes.m_pkHead;
        while (left)
        {
            NiNode* pLeftNode = GetNext(left);
            NiNode* pRightNode = GetNext(right);
            if (pLeftNode && !pRightNode)
                return false;
            if (!pLeftNode && pRightNode)
                return false;
        }
    }
    if (m_kAffectedNodes.m_kItemCount.m_uiCount != other->m_kAffectedNodes.m_kItemCount.m_uiCount)
        return false;
    if (m_kAffectedNodes.m_kItemCount.m_uiCount > 0)
    {
        NiTListItem<NiNode*>* left = m_kAffectedNodes.m_pkHead;
        NiTListItem<NiNode*>* right = other->m_kAffectedNodes.m_pkHead;
        while (left)
        {
            NiNode* pLeftNode = GetNext(left);
            NiNode* pRightNode = GetNext(right);
            if (pLeftNode && !pRightNode)
                return false;
            if (!pLeftNode && pRightNode)
                return false;
        }
    }
    return true;
}

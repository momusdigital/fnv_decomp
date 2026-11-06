// gamebryo2.2/corelibs/nimain/nimaterialproperty.cpp: free functions (8 functions)

#include "nimaterialproperty_decls.h"

extern int DAT_0109d6c4;
void __fastcall DestroyFogProperty(void*);

class NiRenderer
{
  public:
    static NiRenderer* ms_pRenderer;
};

struct NiMemObject_Del
{
    static void __cdecl operator delete(void*, size_t);
};

// @fnv 0x00a756f0
void* __fastcall NiMaterialProperty_Destructor(NiMaterialProperty* pThis, int, unsigned int flags)
{
    *(int**)pThis = &DAT_0109d6c4;
    if (NiRenderer::ms_pRenderer)
        (*(void(__thiscall**)(NiRenderer*, NiMaterialProperty*))(*(int*)NiRenderer::ms_pRenderer + 0xf4))(
            NiRenderer::ms_pRenderer, pThis);
    DestroyFogProperty(pThis);
    if (flags & 1)
        NiMemObject_Del::operator delete(pThis, 0x4c);
    return pThis;
}

struct FUN_00a75790_shell : public NiMaterialProperty
{
    void FUN_00a75790(NiStream*);
};

// Loads a NiMaterialProperty from a stream, reading two colors and two or three floats depending on the stream version.
// @fnv 0x00a75790
void FUN_00a75790_shell::FUN_00a75790(NiStream* pkStream)
{
    NiStream& stream = *pkStream;
    NiProperty::LoadBinary(stream);
    if (stream.m_uiBSVersion < 26)
    {
        NiColor kDummy;
        kDummy.LoadBinary(stream);
        kDummy.LoadBinary(stream);
        reinterpret_cast<NiColor*>(reinterpret_cast<char*>(this) + 0x1C)->LoadBinary(stream);
        reinterpret_cast<NiColor*>(reinterpret_cast<char*>(this) + 0x28)->LoadBinary(stream);
        ReadBinaryValue(stream, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x38));
        ReadBinaryValue(stream, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x3C));
    }
    else
    {
        reinterpret_cast<NiColor*>(reinterpret_cast<char*>(this) + 0x1C)->LoadBinary(stream);
        reinterpret_cast<NiColor*>(reinterpret_cast<char*>(this) + 0x28)->LoadBinary(stream);
        ReadBinaryValue(stream, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x38));
        ReadBinaryValue(stream, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x3C));
        ReadBinaryValue(stream, *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x40));
    }
}

class BSFadeNode
{
  public:
    static void* __cdecl operator new(unsigned int);
};

void* __fastcall FUN_00a75650(void* pThis);
extern void* DAT_011f4a64;

// @fnv 0x00a759e0
void __cdecl FUN_00a759e0()
{
    void* pMemory = BSFadeNode::operator new(0x4c);
    NiRefObject* pFadeNode = (NiRefObject*)(pMemory ? FUN_00a75650(pMemory) : 0);
    if ((NiRefObject*)DAT_011f4a64 != pFadeNode)
    {
        if (DAT_011f4a64)
            ((NiRefObject*)DAT_011f4a64)->DecRefCount();
        DAT_011f4a64 = pFadeNode;
        if (pFadeNode)
            pFadeNode->IncRefCount();
    }
}

struct NiPlane
{
    bool operator==(const NiPlane&) const;
};
struct EqBase
{
    bool FUN_00a62140(NiObject*);
};
struct FUN_00a75960_shell : public EqBase
{
    bool IsEqual(NiObject* o);
};
// @fnv 0x00a75960
bool FUN_00a75960_shell::IsEqual(NiObject* apObject)
{
    if (FUN_00a62140(apObject))
    {
        NiPlane* pPlaneA = (NiPlane*)((char*)this + 0x1c);
        NiPlane* b = (NiPlane*)((char*)apObject + 0x1c);
        if (!pPlaneA->operator==(*b))
        {
            NiPlane* pPlaneC = (NiPlane*)((char*)this + 0x28);
            NiPlane* pPlaneD = (NiPlane*)((char*)apObject + 0x28);
            if (!pPlaneC->operator==(*pPlaneD))
            {
                if (*(int*)((char*)this + 0x34) == *(int*)((char*)apObject + 0x34))
                {
                    if (*(float*)((char*)this + 0x38) == *(float*)((char*)apObject + 0x38))
                    {
                        if (*(float*)((char*)this + 0x3c) == *(float*)((char*)apObject + 0x3c))
                        {
                            if (*(float*)((char*)this + 0x40) == *(float*)((char*)apObject + 0x40))
                                return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

extern void* DAT_011f4a64;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct Holder
{
    virtual void f0();
    virtual void f1();
};
// If DAT_011f4a64 is set, decrements its reference count at offset 4 and calls f1() when it reaches zero, then clears DAT_011f4a64.
// @fnv 0x00a75a40
void ReleaseGlobalHolder()
{
    if (DAT_011f4a64)
    {
        Holder* pHolder = (Holder*)DAT_011f4a64;
        if (InterlockedDecrement((volatile long*)((char*)DAT_011f4a64 + 4)) == 0)
            pHolder->f1();
        DAT_011f4a64 = 0;
    }
}

class BA75730Cloning;

class BA75730Object
{
  public:
    static void* operator new(unsigned int uiSize);

    void CopyMembersStream(BA75730Object* pkDest, BA75730Cloning& kCloning);
};

class FUN_00a75730_cls : public BA75730Object
{
  public:
    FUN_00a75730_cls() throw();
    BA75730Object* CreateClone(BA75730Cloning& kCloning);
    void CopyMemberData(FUN_00a75730_cls* pkDest, BA75730Cloning& kCloning);

    int unk00;
    int unk04;
    int unk08;
    int m_iArrayLength;
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
    int unk40;
    int unk44;
    int unk48;
};

// @fnv 0x00a75730
BA75730Object* FUN_00a75730_cls::CreateClone(BA75730Cloning& kCloning)
{
    if (m_iArrayLength)
    {
        FUN_00a75730_cls* pkClone = new FUN_00a75730_cls;
        CopyMemberData(pkClone, kCloning);
        return pkClone;
    }
    CopyMembersStream(this, kCloning);
    return this;
}

class BA758C0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BA758C0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(BA758C0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class BA758C0Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    unsigned int m_uiFileVersion;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    BA758C0BinaryStream* m_pUnderlyingStream;
    BA758C0BinaryStream* m_pBackingStream;
};

template <class T>
inline void BA758C0BinaryStreamSave(BA758C0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void BA758C0SaveBinary(BA758C0Stream& kStream, const T& value)
{
    BA758C0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class BA758C0Color
{
  public:
    void SaveBinary(BA758C0Stream& kStream);

    float r;
    float g;
    float b;
};

class BA758C0Property
{
  public:
    void SaveBinary(BA758C0Stream& kStream);
};

class FUN_00a758c0_cls : public BA758C0Property
{
  public:
    void FUN_00a758c0(BA758C0Stream& kStream);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    BA758C0Color m_kAmbient;
    BA758C0Color m_kDiffuse;
    int unk34;
    float m_fShine;
    float m_fAlpha;
    float m_fEmitMult;
};

// Saves the base property, ambient and diffuse colors, shine, alpha and emit multiplier to the stream.
// @fnv 0x00a758c0
void FUN_00a758c0_cls::FUN_00a758c0(BA758C0Stream& kStream)
{
    BA758C0Property::SaveBinary(kStream);
    m_kAmbient.SaveBinary(kStream);
    m_kDiffuse.SaveBinary(kStream);
    BA758C0SaveBinary(kStream, m_fShine);
    BA758C0SaveBinary(kStream, m_fAlpha);
    BA758C0SaveBinary(kStream, m_fEmitMult);
}

struct NiRTTI
{
    const char* m_pcName;
    const char* GetName() const
    {
        return m_pcName;
    }
};

struct NiViewerStringsArray
{
    void* m_ppVirtualMethodTable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& element);
    unsigned int Add(char* const& element)
    {
        unsigned int idx = m_usSize;
        if (idx >= m_usMaxSize)
            SetSize(idx + m_usGrowBy);
        SetAt(idx, element);
        return idx;
    }
};

struct ViewerColor
{
    float r, g, b;
    char* FormatToBuffer(const char* pcPrefix) const;
};

struct ViewerPropertyBase
{
    void GetViewerStrings(NiViewerStringsArray* pkStrings);
};

extern NiRTTI g_011f4a5c;
char* __cdecl FUN_00a7d330(const char* pcText);
char* __cdecl FUN_00a7d550(const char* pcPrefix, float fValue);

struct FUN_00a75a70_shell : public ViewerPropertyBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_iIndex;
    ViewerColor m_spec;
    ViewerColor m_emit;
    ViewerColor* m_external_emit;
    float m_fShine;
    float m_fAlpha;
    float m_fEmitMult;
    void FUN_00a75a70(NiViewerStringsArray* pkStrings);
};

// Appends the RTTI name, spec, emit (external or local), shine, alpha and emit multiplier strings to the viewer strings array.
// @fnv 0x00a75a70
void FUN_00a75a70_shell::FUN_00a75a70(NiViewerStringsArray* pkStrings)
{
    ViewerPropertyBase::GetViewerStrings(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_011f4a5c.GetName()));
    pkStrings->Add(m_spec.FormatToBuffer("m_spec"));
    if (m_external_emit)
        pkStrings->Add(m_external_emit->FormatToBuffer("m_external_emit"));
    else
        pkStrings->Add(m_emit.FormatToBuffer("m_emit"));
    pkStrings->Add(FUN_00a7d550("m_fShine", m_fShine));
    pkStrings->Add(FUN_00a7d550("m_fAlpha", m_fAlpha));
    pkStrings->Add(FUN_00a7d550("m_fEmitMult", m_fEmitMult));
}

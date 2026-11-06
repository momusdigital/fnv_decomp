// gamebryo2.2/corelibs/nimain/nitexturingproperty.cpp: Holder, NiTexturingProperty, Map, MyThis and more (44 functions)

#include "nitexturingproperty_decls.h"

// Loads the texturing property from a stream: apply mode, map array, optional shader maps, then calls UpdateMultiTexture.
// @fnv 0x00a6ad60
void NiTexturingProperty::LoadBinary(NiStream& stream)
{
    NiProperty::LoadBinary(stream);
    if (stream.m_uiNifVersion < 0x14010002)
    {
        ApplyMode mode;
        ReadBinaryValue(stream, mode);
        SetApplyMode(mode);
    }
    else
    {
        ReadBinaryValue(stream, m_uiObjectFlags);
        m_uiObjectFlags &= ~0xff0;
    }
    unsigned int count;
    ReadBinaryValue(stream, count);
    unsigned int size = count;
    if (stream.m_uiNifVersion < 0x14020005 && size > 6)
        size += 2;
    m_kStringArray.SetSize(size);
    if (stream.m_uiNifVersion < 0x0303000d)
        stream.SetLinkIDCount(count + 1);
    else
        stream.SetLinkIDCount(count);
    for (unsigned int i = 0; i < count; ++i)
    {
        // Legacy streams store a four-byte presence value. A present entry
        // is replaced by its constructed map before insertion in the array.
        union
        {
            unsigned int presence;
            Map* map;
        } mapEntry;
        mapEntry.map = 0;
        unsigned int index = i;
        bool exists;
        if (stream.m_uiNifVersion < 0x04010000)
        {
            ReadBinaryValue(stream, mapEntry.presence);
            exists = (mapEntry.presence != 0);
        }
        else
            ReadBinaryValue(stream, exists);
        if (stream.m_uiNifVersion < 0x0303000d)
        {
            if (i >= 5)
            {
                stream.SetLinkIDCount(0);
                index++;
            }
        }
        else if (i == 5)
        {
            stream.SetLinkIDCount(exists);
            if (exists)
            {
                mapEntry.map = new BumpMap;
                mapEntry.map->LoadBinary(stream);
            }
            SetMapAt(m_kStringArray, 5, mapEntry.map);
            continue;
        }
        else if (i == 7 && stream.m_uiNifVersion >= 0x14020005)
        {
            stream.SetLinkIDCount(exists);
            if (exists)
            {
                mapEntry.map = new ParallaxMap;
                mapEntry.map->LoadBinary(stream);
            }
            SetMapAt(m_kStringArray, 7, mapEntry.map);
            continue;
        }
        stream.SetLinkIDCount(exists);
        if (exists)
        {
            mapEntry.map = new Map;
            mapEntry.map->LoadBinary(stream);
        }
        m_kStringArray.SetAtGrow(index, mapEntry.map);
    }
    if (stream.m_uiNifVersion >= 0x05000011)
    {
        ReadBinaryValue(stream, count);
        stream.SetLinkIDCount(count);
        if (count)
        {
            m_pShaderMaps = new NiTPrimitiveArray<ShaderMap*>(count);
            for (unsigned int i = 0; i < count; ++i)
            {
                bool exists;
                ReadBinaryValue(stream, exists);
                stream.SetLinkIDCount(exists);
                ShaderMap* map = 0;
                if (exists)
                {
                    ShaderMap* pLoadedShaderMap = new ShaderMap;
                    pLoadedShaderMap->LoadBinary(stream);
                    map = pLoadedShaderMap;
                }
                m_pShaderMaps->SetAt(i, map);
            }
        }
    }
    UpdateMultiTexture();
}

// @fnv 0x00a6b410
void NiTexturingProperty::InitializePoint3()
{
    ms_pDefaultProperty = new NiTexturingProperty;
    ms_kTextureMapNames[0] = "Base";
    ms_kTextureMapNames[1] = "Dark";
    ms_kTextureMapNames[2] = "Detail";
    ms_kTextureMapNames[3] = "Gloss";
    ms_kTextureMapNames[4] = "Glow";
    ms_kTextureMapNames[5] = "Bump";
    ms_kTextureMapNames[6] = "Normal";
    ms_kTextureMapNames[7] = "Parallax";
    ms_kTextureMapNames[8] = "Decal";
    ms_kTextureMapNames[9] = "Shader";
}

// Reads a texture map's clamp mode, filter mode, texture index, and optional transform from the stream based on its version.
// @fnv 0x00a6b640
void NiTexturingProperty::Map::LoadBinary(NiStream& stream)
{
    stream.ResetStreamState();
    if (stream.m_uiNifVersion < 0x14010002)
    {
        {
            ClampMode clamp;
            ReadBinaryValue(stream, clamp);
            SetClampMode(clamp);
        }
        {
            FilterMode filter;
            ReadBinaryValue(stream, filter);
            SetFilterMode(filter);
        }
        unsigned int index;
        ReadBinaryValue(stream, index);
        SetTextureIndex(index);
    }
    else
        ReadBinaryValue(stream, m_uiObjectFlags);
    if (stream.m_uiNifVersion < 0x0a030004)
    {
        unsigned short unused;
        ReadBinaryValue(stream, unused);
        ReadBinaryValue(stream, unused);
    }
    if (stream.m_uiNifVersion < 0x04010010)
    {
        unsigned short unused;
        ReadBinaryValue(stream, unused);
    }
    if (stream.m_uiNifVersion >= 0x0a00010a)
    {
        m_pTextureTransform = 0;
        bool hasTransform;
        ReadBinaryValue(stream, hasTransform);
        if (hasTransform == true)
        {
            m_pTextureTransform = new TextureMapTransform;
            m_pTextureTransform->LoadBinary(stream);
        }
    }
}

void __fastcall FUN_00a68e30(void* pThis);
void __fastcall FUN_00a5a390(void* pThis);

class BSShaderLightingProperty
{
  public:
    void ClearLights();
};

class NiDynamicEffect
{
  public:
    virtual void vfn_0();
    __forceinline ~NiDynamicEffect()
    {
        FUN_00a68e30(this);
        reinterpret_cast<BSShaderLightingProperty*>(reinterpret_cast<char*>(this) + 0xb8)->ClearLights();
        reinterpret_cast<BSShaderLightingProperty*>(reinterpret_cast<char*>(this) + 0xac)->ClearLights();
        FUN_00a5a390(this);
    }
};

// @fnv 0x00a69030
void __fastcall DestroyDynamicEffect(NiDynamicEffect* apEffect)
{
    apEffect->~NiDynamicEffect();
}

bool __fastcall VisitSkinGraphLinks(void* pThis, int, NiStream& kStream);

// @fnv 0x00a6c680
bool __fastcall RegisterStreamables(void* pThis, int edx, NiStream& kStream)
{
    if (!VisitSkinGraphLinks(pThis, edx, kStream))
        return false;
    return true;
}

extern const char* const g_011f4a28_arg1;
// @fnv 0x00a69060
const char* const* FUN_00a69060()
{
    return &g_011f4a28_arg1;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct FUN_00a69e00
{
    unsigned short m_usFlags;
    void* m_spTexture;
    void* m_pkXform;
    FUN_00a69e00(void* tex, unsigned short a, short b, unsigned short c, void* xf);
    virtual void Dummy();
};
// @fnv 0x00a69e00
FUN_00a69e00::FUN_00a69e00(void* apTexture, unsigned short ausLowFlags, short asMidFlags, unsigned short ausHighFlags,
                           void* apXform)
{
    m_usFlags = 0;
    m_spTexture = apTexture;
    if (apTexture)
        InterlockedIncrement(reinterpret_cast<volatile long*>(reinterpret_cast<unsigned char*>(apTexture) + 4));
    m_pkXform = apXform;
    m_usFlags = (((((asMidFlags << 4) | ausHighFlags) << 8) | (m_usFlags & 0xc0ff)) & 0xff00) | ausLowFlags;
}

// @fnv 0x00a6a000
int FUN_00a6a000()
{
    return 3;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f49a4;
// @fnv 0x00a6a140
GlobalObjectO2_00a7b610* FUN_00a6a140()
{
    return &g_011f49a4;
}

struct NiObject;
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a6c610_shell : public NiTexturingProperty
{
    NiObject* CloneTexturingProperty(CloningProcess*);
};

struct NiObject
{
    void CopyMembersStream(NiObject*, CloningProcess*);
};
struct FUN_00a6bb00_holder
{
    void CloneTo(NiTexturingProperty*, CloningProcess*);
};
// @fnv 0x00a6c610
NiObject* FUN_00a6c610_shell::CloneTexturingProperty(CloningProcess* pCloningProcess)
{
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xc))
    {
        NiTexturingProperty* p = new NiTexturingProperty;
        reinterpret_cast<FUN_00a6bb00_holder*>(this)->CloneTo(p, pCloningProcess);
        return reinterpret_cast<NiObject*>(p);
    }
    reinterpret_cast<NiObject*>(this)->CopyMembersStream(reinterpret_cast<NiObject*>(this), pCloningProcess);
    return reinterpret_cast<NiObject*>(this);
}

struct Elem4
{
    unsigned char a;
    unsigned char b;
    unsigned short c;
};
struct EqObj
{
    bool FUN_00a864d0(EqObj*);
    unsigned int m_auiShapeKeys[13];
    unsigned int m_uiCount;
    Elem4* m_pElems;
};
// Returns true if the base comparison passes, the counts match, and every element's a, b and c fields are equal.
// @fnv 0x00a6c6a0
bool __fastcall FUN_00a6c6a0(EqObj* self, int, EqObj* other)
{
    if (!self->FUN_00a864d0(other))
        return false;
    if (self->m_uiCount != other->m_uiCount)
        return false;
    for (unsigned int i = 0; i < self->m_uiCount; i++)
    {
        const Elem4& x = other->m_pElems[i];
        const Elem4& y = self->m_pElems[i];
        if (y.a != x.a || y.b != x.b || y.c != x.c)
            return false;
    }
    return true;
}

int NiSprintf(char* dst, int size, const char* fmt, ...);
void* NiMalloc(unsigned int size);
extern "C" size_t __cdecl strlen(const char*);

// Allocates a string and formats prefix with a texture address-mode suffix selected by mode, defaulting to UNKNOWN!!!.
// @fnv 0x00a69b90
char* BuildTextureAddressModeString(const char* prefix, int mode)
{
    char* result;
    unsigned int len;
    {
        len = strlen(prefix);
    }
    result = (char*)NiMalloc(len + 0x14);
    switch (mode)
    {
    case 0:
        NiSprintf(result, len + 0x14, "%s = CLAMP_S_CLAMP_T", prefix);
        break;
    case 1:
        NiSprintf(result, len + 0x14, "%s = CLAMP_S_WRAP_T", prefix);
        break;
    case 2:
        NiSprintf(result, len + 0x14, "%s = WRAP_S_CLAMP_T", prefix);
        break;
    case 3:
        NiSprintf(result, len + 0x14, "%s = WRAP_S_WRAP_T", prefix);
        break;
    default:
        NiSprintf(result, len + 0x14, "%s = UNKNOWN!!!", prefix);
        break;
    }
    return result;
}

int _NiStricmp(const char*, const char*);
inline bool MapNameEqual(const char* a, const char* b)
{
    if (a == b)
        return true;
    if (!b || !a)
        return false;
    return _NiStricmp(a, b) == 0;
}
// Searches the ten texture map handles for one matching pkName and, on a match, stores its index in puiID and returns true.
// @fnv 0x00a69d80
bool FindTextureMapIndexByName(NiFixedString* pkName, unsigned int* puiID)
{
    for (unsigned int i = 0; i < 10; i++)
    {
        if (MapNameEqual(NiTexturingProperty::ms_kTextureMapNames[i].m_kHandle, pkName->m_kHandle))
        {
            *puiID = i;
            return true;
        }
    }
    return false;
}

struct S8
{
    int _p[4];
    int _v;
    bool IsEquivalent(S8*);
    unsigned char FUN_00a69f50(S8*);
};
// Returns 0 if IsEquivalent fails, otherwise returns whether _v equals o->_v.
// @fnv 0x00a69f50
unsigned char S8::FUN_00a69f50(S8* pOther)
{
    if (!IsEquivalent(pOther))
        return 0;
    return _v == pOther->_v;
}

void __cdecl _NiFreeAlias(void*);
struct DeallocHelper
{
    void _DeallocateAlias(void*);
};
extern int DAT_0109c394;
struct S00a6a050
{
    void* vf;
    void* p;
    void* FUN_00a6a050(unsigned int);
};
// @fnv 0x00a6a050
void* S00a6a050::FUN_00a6a050(unsigned int auiFlags)
{
    void* t = p;
    vf = (void*)&DAT_0109c394;
    _NiFreeAlias(t);
    if (auiFlags & 1)
        ((DeallocHelper*)&g_memoryManager)->_DeallocateAlias(this);
    return this;
}

void _NiFreeAlias(void*);
extern int DAT_0109c39c;
struct DeallocHack
{
    void _DeallocateAlias(void*);
};
struct Holder
{
    void* f0;
    void* f1;
    void* FUN_00a6a080(unsigned int);
};
// Frees f1 via _NiFreeAlias, sets f0 to DAT_0109c39c, and deallocates this when a has bit 0 set; returns this.
// @fnv 0x00a6a080
void* Holder::FUN_00a6a080(unsigned int auiFlags)
{
    void* p = f1;
    f0 = (void*)&DAT_0109c39c;
    _NiFreeAlias(p);
    if (auiFlags & 1)
        ((DeallocHack*)&g_memoryManager)->_DeallocateAlias(this);
    return this;
}

namespace fnv_00a6ab90 {
struct Holder
{
    void NiTexturingPropertyDestructor();
    void* DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// @fnv 0x00a6ab90
void* Holder::DestroyIfFlagged(unsigned int flags)
{
    NiTexturingPropertyDestructor();
    if (flags & 1)
        _delete(this, 0x30);
    return this;
}
}  // namespace fnv_00a6ab90

struct MyBinStream
{
    int _0;
    int pos;
    int(__cdecl* read)(MyBinStream*, void*, int, unsigned int*, int);
};
struct MyThis
{
    void LoadMapBinary(NiStream&);
};
// Loads the base map from the stream, then reads a 4-byte value into the object at offset 0x10.
// @fnv 0x00a6ba80
void MyThis::LoadMapBinary(NiStream& stream)
{
    ((NiTexturingProperty::Map*)this)->NiTexturingProperty::Map::LoadBinary(stream);
    MyBinStream* __restrict input = *(MyBinStream**)((char*)&stream + 0x24c);
    unsigned int size = 4;
    input->pos += input->read(input, (char*)this + 0x10, 4, &size, 1);
}

extern void* DAT_0126f580[];
extern int DAT_0126f594;
struct FakeVT
{
    void* _p[37];
    long(__stdcall* SetTexture)(void*, unsigned int, void*);
};
struct FakeDev
{
    FakeVT* vt;
};
struct NiDX92DBufferData
{
    char _b[0x14];
    void* m1;
    void* m2;
    bool SetTextureSlot(void*, unsigned int);
};
// @fnv 0x00e7cd50
bool NiDX92DBufferData::SetTextureSlot(void* pDev, unsigned int auiIndex)
{
    void* pTexture = m1;
    if (pTexture)
    {
        if (auiIndex > (unsigned int)DAT_0126f594)
            return false;
        if (m2)
            pTexture = m2;
        if (pTexture != DAT_0126f580[auiIndex])
        {
            long hr = ((FakeDev*)pDev)->vt->SetTexture(pDev, auiIndex, pTexture);
            if (hr < 0)
                return false;
            DAT_0126f580[auiIndex] = pTexture;
        }
        return true;
    }
    return false;
}

struct S_A69F80
{
    char _pad[16];
    float m_10;
    bool IsEquivalent(S_A69F80*);
    bool MatchesValue(S_A69F80*);
};
// Returns true if IsEquivalent succeeds and m_10 equals pkObject->m_10, otherwise false.
// @fnv 0x00a69f80
bool S_A69F80::MatchesValue(S_A69F80* pkObject)
{
    if (!IsEquivalent(pkObject))
        return false;
    if (m_10 != pkObject->m_10)
        return false;
    return true;
}

namespace fnv_00a6bac0 {
struct MapBase
{
    void FUN_00a6b830(class NiStream&);
};
struct MyStream
{
    void* _v0;
    int _pos;
    int(__cdecl* _read)(MyStream*, void*, unsigned int, unsigned int*, unsigned int);
    int(__cdecl* _write)(MyStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct Holder
{
    char _pad[16];
    int _v;
    void WriteToStream(class NiStream&);
};
// Calls the base class stream writer, then writes the 4-byte value at this+16 to the stream and advances its position.
// @fnv 0x00a6bac0
void Holder::WriteToStream(class NiStream& aStream)
{
    ((MapBase*)this)->FUN_00a6b830(aStream);
    MyStream* __restrict ostr = *(MyStream**)((char*)&aStream + 0x250);
    unsigned int size = 4;
    ostr->_pos += ostr->_write(ostr, &this->_v, 4, &size, 1);
}
}  // namespace fnv_00a6bac0

namespace fnv_00a69ed0 {
struct S8
{
    float m_kPointA[5];
    bool IsEquivalent(S8*);
    bool FUN_00a69ed0(S8*);
};

// @fnv 0x00a69ed0
bool S8::FUN_00a69ed0(S8* apOther)
{
    if (IsEquivalent(apOther))
    {
        if (m_kPointA[4] == apOther->m_kPointA[4] && m_kPointA[5] == apOther->m_kPointA[5] && m_kPointA[6] == apOther->m_kPointA[6] &&
            m_kPointA[7] == apOther->m_kPointA[7] && m_kPointA[8] == apOther->m_kPointA[8] && m_kPointA[9] == apOther->m_kPointA[9])
            return true;
    }
    return false;
}
}  // namespace fnv_00a69ed0

void* _NiMalloc(unsigned int);
int _NiSprintf(char*, unsigned int, const char*, ...);

// Allocates a string sized to pcPrefix plus 30 and formats it as "<pcPrefix> = FILTER_..." based on eMode, defaulting to UNKNOWN!!!.
// @fnv 0x00a69c50
char* BuildFilterModeString(const char* pcPrefix, unsigned int eMode)
{
    char* pcString;
    unsigned int uiBufferSize;

    uiBufferSize = static_cast<unsigned int>(strlen(pcPrefix)) + 30;
    pcString = static_cast<char*>(_NiMalloc(uiBufferSize));

    switch (eMode)
    {
    case 0:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_NEAREST", pcPrefix);
        break;

    case 1:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_BILERP", pcPrefix);
        break;

    case 2:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_TRILERP", pcPrefix);
        break;

    case 3:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_NEAREST_MIPNEAREST", pcPrefix);
        break;

    case 4:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_NEAREST_MIPLERP", pcPrefix);
        break;

    case 5:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_BILERP_MIPNEAREST", pcPrefix);
        break;

    case 6:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_ANISO", pcPrefix);
        break;

    case 7:
        _NiSprintf(pcString, uiBufferSize, "%s = FILTER_MAGLERP_MINANISO", pcPrefix);
        break;

    default:
        _NiSprintf(pcString, uiBufferSize, "%s = UNKNOWN!!!", pcPrefix);
        break;
    }

    return pcString;
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

// @fnv 0x00a6ad40
NiTexturingProperty* CreateTexturingProperty()
{
    return new NiTexturingProperty();
}

// NiTexturingProperty::BumpMap default constructor: identity luma, half-scale bump matrix.
// (Declared here under the tag name so the checker can find it; layout mirrors BumpMap.)

class FUN_00a69fb0 : public NiTexturingProperty::Map
{
  public:
    float m_fLumaScale;
    float m_fLumaOffset;
    float m_fBumpMat00;
    float m_fBumpMat01;
    float m_fBumpMat10;
    float m_fBumpMat11;

    FUN_00a69fb0() throw();
    virtual ~FUN_00a69fb0();
};

// Initializes the map's luma scale/offset and bump matrix fields to their default values.
// @fnv 0x00a69fb0
FUN_00a69fb0::FUN_00a69fb0() throw()
    : m_fLumaScale(1.0f), m_fLumaOffset(0.0f), m_fBumpMat00(0.5f), m_fBumpMat01(0.0f), m_fBumpMat10(0.0f),
      m_fBumpMat11(0.5f)
{}

class NiTexture
{
  public:
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void Apply(unsigned int);
};

struct FUN_00a6a560_cls : public NiTexturingProperty
{
    bool FUN_00a62130(unsigned int);
    bool ApplyTextures(unsigned int uiArg);
};

// @fnv 0x00a6a560
bool FUN_00a6a560_cls::ApplyTextures(unsigned int uiArg)
{
    if (!FUN_00a62130(uiArg))
    {
        return false;
    }
    for (unsigned int i = 0; i < m_kStringArray.m_usSize; ++i)
    {
        NiTexturingProperty::Map* map = m_kStringArray.m_pBase[i];
        if (map != 0)
        {
            NiTexture* tex = map->m_spTexture.m_pObject;
            if (tex != 0)
            {
                tex->Apply(uiArg);
            }
        }
    }
    if (m_pShaderMaps != 0)
    {
        for (unsigned int j = 0; j < m_pShaderMaps->m_usSize; ++j)
        {
            NiTexturingProperty::Map* map = m_pShaderMaps->m_pBase[j];
            if (map != 0)
            {
                NiTexture* tex = map->m_spTexture.m_pObject;
                if (tex != 0)
                {
                    tex->Apply(uiArg);
                }
            }
        }
    }
    return true;
}

void* NiMalloc(unsigned int size);
NiTexture* FUN_00a5ff10(void* pkPrefs, const char* pcName, void* pkOther);

typedef NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> > CamPathArray;

struct PropertyBase : NiMemObject
{
    virtual void Vfn00();
    unsigned int m_uiRefCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    PropertyBase();
};

struct TexMapArrayBase
{
    virtual void Vfn00();
    NiTexturingProperty::Map** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    TexMapArrayBase(unsigned int uiMaxSize, unsigned int uiGrowBy)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = (NiTexturingProperty::Map**)NiMalloc(sizeof(NiTexturingProperty::Map*) * m_usMaxSize);
        else
            m_pBase = 0;
    }
    void SetAt(unsigned int i, NiTexturingProperty::Map* map)
    {
        reinterpret_cast<CamPathArray*>(this)->SetAt(i, reinterpret_cast<BGSCameraPath*&>(map));
    }
};

struct TexMapArray : TexMapArrayBase
{
    virtual void Vfn00();
    TexMapArray(unsigned int uiMaxSize, unsigned int uiGrowBy) : TexMapArrayBase(uiMaxSize, uiGrowBy)
    {}
};

struct TexMapStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    TexMapStub(NiTexture* pkTexture, unsigned int uiIndex, int eClamp, int eFilter,
               TextureMapTransform* pkXform) throw();
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
};

struct FUN_00a6abb0 : PropertyBase
{
    unsigned short m_uiObjectFlags;
    TexMapArray m_kStringArray;
    void* m_pShaderMaps;
    virtual void Vfn00();
    FUN_00a6abb0(void* pkPrefs, NiFixedString& kName, void* pkOther);
};

// @fnv 0x00a6abb0
FUN_00a6abb0::FUN_00a6abb0(void* pkPrefs, NiFixedString& kName, void* pkOther) : m_uiObjectFlags(0), m_kStringArray(9, 1)
{
    m_pShaderMaps = 0;
    const char* pcName = kName.m_kHandle;
    NiTexture* pkTexture = FUN_00a5ff10(pkPrefs, pcName, pkOther);
    m_kStringArray.SetAt(0, (NiTexturingProperty::Map*)new TexMapStub(pkTexture, 0, 3, 1, 0));
    m_kStringArray.SetAt(1, 0);
    m_kStringArray.SetAt(2, 0);
    m_kStringArray.SetAt(3, 0);
    m_kStringArray.SetAt(4, 0);
    m_kStringArray.SetAt(5, 0);
    m_kStringArray.SetAt(6, 0);
    m_kStringArray.SetAt(7, 0);
    m_kStringArray.SetAt(8, 0);
    m_uiObjectFlags &= 0xf00f;
    unsigned int size = m_kStringArray.m_usSize;
    unsigned int i;
    for (i = 1; i < size; ++i)
    {
        if (m_kStringArray.m_pBase[i])
        {
            m_uiObjectFlags |= 1;
            goto done;
        }
    }
    m_uiObjectFlags &= ~1;
done:
    m_uiObjectFlags = (m_uiObjectFlags & ~0xe) | (2 << 1);
}

struct NiStreamOut : public NiStream
{
    NiBinaryStream* m_pBackingStream;
};

inline unsigned int NiBinaryWrite(NiBinaryStream* pkStr, const void* pvBuffer, unsigned int uiBytes)
{
    unsigned int uiSize = uiBytes;
    unsigned int uiWritten = pkStr->m_pfnWrite(pkStr, pvBuffer, uiBytes, &uiSize, 1);
    pkStr->m_uiStreamFlags += uiWritten;
    return uiWritten;
}

template <class T> inline void SerializeValue(NiStream& kStream, const T& value)
{
    NiBinaryWrite(static_cast<NiStreamOut&>(kStream).m_pBackingStream, &value, sizeof(T));
}

struct NiPropertySaveStub
{
    void SaveBinary(NiStream& kStream);
};

struct NiTexturingPropertySave : public NiTexturingProperty
{
    void FUN_00a6b250(NiStream& kStream);
};

// Saves the base map array and optional shader map array to the stream, writing a count and a presence flag plus data for each map.
// @fnv 0x00a6b250
void NiTexturingPropertySave::FUN_00a6b250(NiStream& kStream)
{
    reinterpret_cast<NiPropertySaveStub*>(this)->SaveBinary(kStream);

    SerializeValue(kStream, m_uiObjectFlags);

    unsigned int uiNumMaps = m_kStringArray.m_usSize;
    SerializeValue(kStream, uiNumMaps);
    unsigned int i;
    for (i = 0; i < uiNumMaps; i++)
    {
        Map* pkMap = m_kStringArray.m_pBase[i];
        bool bMap = (pkMap != 0);
        SerializeValue(kStream, bMap);
        if (bMap)
            pkMap->SaveBinary(kStream);
    }

    if (m_pShaderMaps)
    {
        uiNumMaps = m_pShaderMaps->m_usSize;
        SerializeValue(kStream, uiNumMaps);
        for (i = 0; i < uiNumMaps; i++)
        {
            ShaderMap* pkMap = m_pShaderMaps->m_pBase[i];
            bool bMap = (pkMap != 0);
            SerializeValue(kStream, bMap);
            if (bMap)
                pkMap->SaveBinary(kStream);
        }
    }
    else
    {
        uiNumMaps = 0;
        SerializeValue(kStream, uiNumMaps);
    }
}

class A6B830BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A6B830BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A6B830BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A6B830Object;

class A6B830Stream
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void SaveLinkID(A6B830Object* pkObject);
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
    int unk0D8;
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
    int unk24C;
    A6B830BinaryStream* m_pBackingStream;
};

template <class T>
inline void A6B830BinaryStreamSave(A6B830BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A6B830SaveBinary(A6B830Stream& kStream, const T& value)
{
    A6B830BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class A6B830Child
{
  public:
    void SaveBinary(A6B830Stream& kStream);
};

class A6B830Helper
{
  public:
    void FUN_00a6b830(A6B830Stream& kStream);

    int unk00;
    unsigned short m_usFlags;
    short unk06;
    A6B830Object* m_pkTarget;
    A6B830Child* m_pkChild;
};

// Writes the target link ID, flags, a child-present flag and, if present, the child's binary data to the stream.
// @fnv 0x00a6b830
void A6B830Helper::FUN_00a6b830(A6B830Stream& kStream)
{
    kStream.SaveLinkID(m_pkTarget);
    A6B830SaveBinary(kStream, m_usFlags);
    bool bHasChild = m_pkChild != 0;
    A6B830SaveBinary(kStream, bHasChild);
    if (m_pkChild)
        m_pkChild->SaveBinary(kStream);
}

// NiTexturingProperty::BumpMap::LoadBinary
class A6B8C0BumpMap : public NiTexturingProperty::BumpMap
{
  public:
    void FUN_00a6b8c0(NiStream& kStream);
};

// Loads the base map data from kStream, then reads six float values into the bump map's luma and matrix fields.
// @fnv 0x00a6b8c0
void A6B8C0BumpMap::FUN_00a6b8c0(NiStream& kStream)
{
    Map::LoadBinary(kStream);
    ReadBinaryValue(kStream, m_fLumaScale);
    ReadBinaryValue(kStream, m_fLumaOffset);
    ReadBinaryValue(kStream, m_fBumpMat00);
    ReadBinaryValue(kStream, m_fBumpMat01);
    ReadBinaryValue(kStream, m_fBumpMat10);
    ReadBinaryValue(kStream, m_fBumpMat11);
}

struct S_00a6b9a0_Bin
{
    int unk00;
    unsigned int unk04;
    int unk08;
    unsigned int(__cdecl* unk0c)(S_00a6b9a0_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* p, unsigned int n)
    {
        unsigned int size = n;
        unsigned int r = unk0c(this, p, n, &size, 1);
        unk04 += r;
        return r;
    }
};
struct S_00a6b9a0_Stream
{
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    S_00a6b9a0_Bin* unk250;
};
struct S_00a6b9a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    void FUN_00a6b830(S_00a6b9a0_Stream*);
    void ReadFromStream(S_00a6b9a0_Stream* s);
};
// Calls FUN_00a6b830, then reads six 4-byte values from the stream into unk10 through unk24.
// @fnv 0x00a6b9a0
void S_00a6b9a0::ReadFromStream(S_00a6b9a0_Stream* pStream)
{
    FUN_00a6b830(pStream);
    pStream->unk250->Read(&unk10, 4);
    pStream->unk250->Read(&unk14, 4);
    pStream->unk250->Read(&unk18, 4);
    pStream->unk250->Read(&unk1c, 4);
    pStream->unk250->Read(&unk20, 4);
    pStream->unk250->Read(&unk24, 4);
}

// Equality of two texture descriptors: equal source objects, same flags, and matching image data.

template <class T> class A9E60Pointer
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

class A9E60Object
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual bool IsEqual(A9E60Object* pkOther);
};

class A9E60Data
{
  public:
    bool IsDifferent(A9E60Data* pkOther);
};

class A9E60Desc
{
  public:
    int unk00;
    unsigned short m_usFlags;
    unsigned short unk06;
    A9E60Pointer<A9E60Object> m_spSource;
    A9E60Pointer<A9E60Data> m_spTransformData;

    bool IsEquivalent(const A9E60Desc& kOther) const;
};

// @fnv 0x00a69e60
bool A9E60Desc::IsEquivalent(const A9E60Desc& kOther) const
{
    if (!m_spSource && kOther.m_spSource)
        return false;
    if (m_spSource && !m_spSource->IsEqual(kOther.m_spSource))
        return false;
    if (m_usFlags != kOther.m_usFlags)
        return false;
    if (m_spTransformData && kOther.m_spTransformData)
    {
        if (m_spTransformData->IsDifferent(kOther.m_spTransformData))
            return false;
    }
    else
    {
        if (!m_spTransformData && kOther.m_spTransformData)
            return false;
        if (m_spTransformData && !kOther.m_spTransformData)
            return false;
    }
    return true;
}

extern int DAT_0109c514;
// Sets the vtable, deletes the texture array elements and the second array, frees the base array and runs the NiProperty destructor.
// @fnv 0x00a6a0b0
void __fastcall NiTexturingPropertyDestructor(NiTexturingProperty* pThis)
{
    *reinterpret_cast<void**>(pThis) = &DAT_0109c514;
    for (unsigned int i = 0; i < pThis->m_kStringArray.m_usSize; ++i)
    {
        delete pThis->m_kStringArray.m_pBase[i];
    }
    if (pThis->m_pShaderMaps)
    {
        for (unsigned int i = 0; i < pThis->m_pShaderMaps->m_usSize; ++i)
        {
            delete pThis->m_pShaderMaps->m_pBase[i];
        }
        delete pThis->m_pShaderMaps;
    }
    *reinterpret_cast<void**>(&pThis->m_kStringArray) = &DAT_0109c394;
    _NiFreeAlias(pThis->m_kStringArray.m_pBase);
    pThis->NiProperty::~NiProperty();
}

struct Sub2c
{
    unsigned int unk00;
    void** m_04;
    unsigned char unk08[2];
    unsigned short m_0a;
};

struct Elem5
{
    bool FUN_00a69ed0(Elem5*);
};

struct FUN_00a6a5f0_cls
{
    unsigned char unk00[0x18];
    unsigned short m_18;
    unsigned char unk1a[6];
    void** m_20;
    unsigned char unk24[2];
    unsigned short m_26;
    unsigned char unk28[4];
    Sub2c* m_2c;
    bool FUN_00a62140(FUN_00a6a5f0_cls*);
    bool Equals(FUN_00a6a5f0_cls* other);
};

// @fnv 0x00a6a5f0
bool FUN_00a6a5f0_cls::Equals(FUN_00a6a5f0_cls* other)
{
    if (!FUN_00a62140(other))
        return false;
    if (m_18 != other->m_18)
        return false;
    unsigned int uiOtherCount = other->m_26;
    unsigned int n = m_26;
    if (n != uiOtherCount)
        return false;
    for (unsigned int i = 0; i < n; ++i)
    {
        void* a = m_20[i];
        void* b = other->m_20[i];
        if (a != 0)
        {
            if (b == 0)
                goto fail;
            if (i == 5)
            {
                if (!reinterpret_cast<Elem5*>(a)->FUN_00a69ed0(reinterpret_cast<Elem5*>(b)))
                    goto fail;
            }
            else if (i == 7)
            {
                if (!reinterpret_cast<S_A69F80*>(a)->MatchesValue(reinterpret_cast<S_A69F80*>(b)))
                    goto fail;
            }
            else
            {
                if (!reinterpret_cast<S8*>(a)->IsEquivalent(reinterpret_cast<S8*>(b)))
                    goto fail;
            }
        }
        else if (b != 0)
        {
            goto fail;
        }
    }
    if (m_2c != 0)
    {
        if (other->m_2c == 0)
            return false;
        unsigned int uiSubCount = m_2c->m_0a;
        if (uiSubCount != other->m_2c->m_0a)
            return false;
        for (unsigned int i = 0; i < uiSubCount; ++i)
        {
            void* x = m_2c->m_04[i];
            void* y = other->m_2c->m_04[i];
            if (x != 0)
            {
                if (y == 0)
                    return false;
                if (!reinterpret_cast<S8*>(x)->FUN_00a69f50(reinterpret_cast<S8*>(y)))
                    return false;
            }
            else if (y != 0)
            {
                return false;
            }
        }
        return true;
    }
    if (other->m_2c == 0)
        return true;
fail:
    return false;
}

void* NiMalloc(unsigned int size);

struct A6A990Base
{
    virtual ~A6A990Base();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    A6A990Base(unsigned int maxSize, unsigned int growBy)
    {
        m_usMaxSize = (unsigned short)maxSize;
        m_usGrowBy = (unsigned short)growBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
        {
            unsigned int uiBytes = m_usMaxSize;
            m_pBase = NiMalloc(sizeof(void*) * uiBytes);
        }
        else
            m_pBase = 0;
    }
};

struct FUN_00a6a990 : A6A990Base
{
    virtual ~FUN_00a6a990();
    virtual void Vfn00();
    FUN_00a6a990(unsigned int size, unsigned int grow);
};

// Constructs the base array object, forwarding the max size and growth increment to the A6A990Base constructor.
// @fnv 0x00a6a990
FUN_00a6a990::FUN_00a6a990(unsigned int uiMaxSize, unsigned int uiGrowBy) : A6A990Base(uiMaxSize, uiGrowBy)
{}

struct NiTPrimitiveArray_unsigned_int_
{
    void AddFirstEmpty(const unsigned int&);
};
struct StrArr
{
    virtual void dummy();
    char** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void AddFirstEmpty(const unsigned int&);
    __forceinline void Append(char*& value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        SetAt(index, value);
    }
    __forceinline void AppendInline(char* value)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        if (index >= m_usSize)
        {
            m_usSize = (unsigned short)(index + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[index])
                ++m_usESize;
        }
        else if (m_pBase[index])
            --m_usESize;
        m_pBase[index] = value;
    }
    __forceinline void Add(char*& value)
    {
        reinterpret_cast<NiTPrimitiveArray_unsigned_int_*>(this)->AddFirstEmpty(
            reinterpret_cast<const unsigned int&>(value));
    }
};

struct GlobalObjectO2_00a7b610
{
    char* m_pcName;
};
extern GlobalObjectO2_00a7b610 g_011f49a4;
int __cdecl NiSprintf(char*, unsigned int, const char*, ...);
char* BuildTextureAddressModeString(const char*, int);
char* BuildFilterModeString(const char*, int);
char* FUN_00a7d330(char*);
char* FUN_00a7d4d0(const char*, int);
char* FUN_00a7d510(const char*, unsigned int);
char* FUN_00a7d550(const char*, float);
char* FUN_00a7d5a0(const char*, void*);
struct FUN_00a62a40_this
{
    void AppendString(StrArr*);
};
struct PropertyViewer : NiTexturingProperty
{
    void AppendPropertyInfo(StrArr*);
};

struct MapEx : NiTexturingProperty::Map
{
    inline NiTexturingProperty::ClampMode GetClampMode() const
    {
        return (NiTexturingProperty::ClampMode)((m_uiObjectFlags >> 12) & 3);
    }
    inline NiTexturingProperty::FilterMode GetFilterMode() const
    {
        return (NiTexturingProperty::FilterMode)((m_uiObjectFlags >> 8) & 15);
    }
    inline unsigned int GetTextureIndex() const
    {
        return m_uiObjectFlags & 0xff;
    }
};

struct ShaderMapEx : NiTexturingProperty::ShaderMap
{
    inline NiTexturingProperty::ClampMode GetClampMode() const
    {
        return (NiTexturingProperty::ClampMode)((m_uiObjectFlags >> 12) & 3);
    }
    inline NiTexturingProperty::FilterMode GetFilterMode() const
    {
        return (NiTexturingProperty::FilterMode)((m_uiObjectFlags >> 8) & 15);
    }
    inline unsigned int GetTextureIndex() const
    {
        return m_uiObjectFlags & 0xff;
    }
};

// Appends the property name, apply mode, and per-map details (texture, clamp/filter mode, coord index) for each texture and shader map to strings.
// @fnv 0x00a6bdd0
void PropertyViewer::AppendPropertyInfo(StrArr* strings)
{
    reinterpret_cast<FUN_00a62a40_this*>(this)->AppendString(strings);
    {
        char* header = FUN_00a7d330(g_011f49a4.m_pcName);
        strings->Append(header);
    }
    unsigned int count = m_kStringArray.m_usSize;
    char prefix[64];
    {
        union
        {
            char* text;
            float scalar;
        };
        char acApplyMode[64];
        char acDecalLabel[64];
        NiSprintf(acApplyMode, 64, "ApplyMode ");
        int mode = (m_uiObjectFlags >> 1) & 7;
        text = FUN_00a7d4d0(acApplyMode, mode);
        strings->Append(text);
        for (unsigned int i = 0; i < count; ++i)
        {
            Map* map = m_kStringArray.m_pBase[i];
            if (!map)
                continue;
            switch (i)
            {
            case 0:
                text = FUN_00a7d510("MultiTexture Base Map", i);
                strings->Add(text);
                break;
            case 1:
                text = FUN_00a7d510("MultiTexture Dark Map", i);
                strings->Add(text);
                break;
            case 2:
                text = FUN_00a7d510("MultiTexture Detail Map", i);
                strings->Add(text);
                break;
            case 3:
                text = FUN_00a7d510("MultiTexture Gloss Map", i);
                strings->Add(text);
                break;
            case 4:
                text = FUN_00a7d510("MultiTexture Glow Map", i);
                strings->Add(text);
                break;
            case 5: {
                text = FUN_00a7d510("MultiTexture Bump Map", i);
                strings->Add(text);
                BumpMap* pBumpMap = static_cast<BumpMap*>(map);
                scalar = pBumpMap->m_fLumaScale;
                text = FUN_00a7d550("m_fLumaScale", scalar);
                strings->Add(text);
                scalar = pBumpMap->m_fLumaOffset;
                text = FUN_00a7d550("m_fLumaOffset", scalar);
                strings->Add(text);
                scalar = pBumpMap->m_fBumpMat00;
                text = FUN_00a7d550("m_fBumpMat00", scalar);
                strings->Add(text);
                scalar = pBumpMap->m_fBumpMat01;
                text = FUN_00a7d550("m_fBumpMat01", scalar);
                strings->Add(text);
                scalar = pBumpMap->m_fBumpMat10;
                text = FUN_00a7d550("m_fBumpMat10", scalar);
                strings->Add(text);
                scalar = pBumpMap->m_fBumpMat11;
                text = FUN_00a7d550("m_fBumpMat11", scalar);
                strings->Add(text);
                break;
            }
            case 6:
                text = FUN_00a7d510("MultiTexture Normal Map", i);
                strings->Add(text);
                break;
            case 7: {
                text = FUN_00a7d510("MultiTexture Parallax Map", i);
                strings->Add(text);
                scalar = static_cast<ParallaxMap*>(map)->m_fParallaxOffset;
                text = FUN_00a7d550("m_fParallaxOffset", scalar);
                strings->Add(text);
                break;
            }
            default: {
                NiSprintf(acDecalLabel, 64, "MultiTexture Decal Map %d", i - 8);
                text = FUN_00a7d510(acDecalLabel, i);
                strings->Append(text);
                break;
            }
            }
            NiSprintf(prefix, 64, "m_spTexture ");
            void* tex = map->m_spTexture.m_pObject;
            text = FUN_00a7d5a0(prefix, tex);
            strings->Append(text);
            NiSprintf(prefix, 64, "Clamp Mode ");
            text = BuildTextureAddressModeString(prefix, static_cast<MapEx*>(map)->GetClampMode());
            strings->Append(text);
            NiSprintf(prefix, 64, "Filter Mode");
            text = BuildFilterModeString(prefix, static_cast<MapEx*>(map)->GetFilterMode());
            strings->Append(text);
            NiSprintf(prefix, 64, "Texture Coord Index ");
            unsigned int uiTexCoordIndex = static_cast<MapEx*>(map)->GetTextureIndex();
            text = FUN_00a7d510(prefix, uiTexCoordIndex);
            strings->Append(text);
        }
    }
    if (m_pShaderMaps)
    {
        count = m_pShaderMaps->m_usSize;
        for (unsigned int j = 0; j < count; ++j)
        {
            ShaderMap* map = m_pShaderMaps->m_pBase[j];
            if (!map)
                continue;
            strings->AppendInline(FUN_00a7d510("Shader Map", j));
            unsigned int uiShaderID = map->m_uiID;
            strings->AppendInline(FUN_00a7d510("m_uiID", uiShaderID));
            NiSprintf(prefix, 64, "m_spTexture ");
            void* pShaderTexture = map->m_spTexture.m_pObject;
            strings->AppendInline(FUN_00a7d5a0(prefix, pShaderTexture));
            NiSprintf(prefix, 64, "Clamp Mode ");
            strings->AppendInline(
                BuildTextureAddressModeString(prefix, static_cast<ShaderMapEx*>(map)->GetClampMode()));
            NiSprintf(prefix, 64, "Filter Mode");
            strings->AppendInline(BuildFilterModeString(prefix, static_cast<ShaderMapEx*>(map)->GetFilterMode()));
            NiSprintf(prefix, 64, "Texture Coord Index ");
            unsigned int uiShaderTexCoordIndex = static_cast<ShaderMapEx*>(map)->GetTextureIndex();
            strings->AppendInline(FUN_00a7d510(prefix, uiShaderTexCoordIndex));
        }
    }
}

struct FUN_00a6a010 : public NiTexturingProperty::Map
{
    float m_fParallaxOffset;
    FUN_00a6a010() throw();
    virtual ~FUN_00a6a010();
};
// Constructs a parallax map, initializing m_fParallaxOffset to 0.5f.
// @fnv 0x00a6a010
FUN_00a6a010::FUN_00a6a010() throw() : m_fParallaxOffset(0.5f)
{}

struct LinkTexture
{
    virtual void Dummy();
    virtual void DeleteThis();
    unsigned int refs;
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&refs))
            DeleteThis();
    }
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&refs);
    }
};
struct LinkMap
{
    int unk00;
    int unk04;
    NiPointer<LinkTexture> texture;
};
struct LinkArray
{
    virtual ~LinkArray();
    LinkMap** data;
    unsigned short capacity, size, used, grow;
    __declspec(noinline) void FUN_0096ae90(unsigned int i, LinkMap*& value)
    {
        if (i >= size)
        {
            size = (unsigned short)(i + 1);
            if (value)
                ++used;
        }
        else if (value)
        {
            if (!data[i])
                ++used;
        }
        else if (data[i])
            --used;
        data[i] = value;
    }
    void SetAt(unsigned int i, LinkMap*& value)
    {
        FUN_0096ae90(i, value);
    }
    void FUN_00a90180(unsigned int n);
    void SetSize(unsigned int n)
    {
        FUN_00a90180(n);
    }
    void SetAtGrow(unsigned int i, LinkMap*& value)
    {
        if (i >= capacity)
            SetSize(i + grow);
        SetAt(i, value);
    }
};
struct LinkStream : NiStream
{
    unsigned int FUN_00a63460();
    LinkTexture* FUN_00a63430();
};
struct LinkProperty
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short flags;
    LinkArray maps;
    LinkArray* shaderMaps;
    void FUN_00a47360(LinkStream&);
    void IncrementCount()
    {
        flags = (flags & 0xf00f) | (((((flags >> 4) & 255) + 1) << 4));
    }
    void LoadFromStream(LinkStream& stream);
};
// Reads texture maps and shader maps from the stream, relocates maps 6 and 7 to slots 8 and 9 for older versions, and updates the flags count.
// @fnv 0x00a6a240
void LinkProperty::LoadFromStream(LinkStream& stream)
{
    FUN_00a47360(stream);
    unsigned int count = stream.FUN_00a63460();
    unsigned int i;
    flags &= 0xf00f;
    for (i = 0; i < count; ++i)
    {
        if (stream.FUN_00a63460())
        {
            LinkMap*& map = maps.data[i];
            map->texture = stream.FUN_00a63430();
            if (i >= 8)
                IncrementCount();
        }
    }
    if (stream.m_uiNifVersion < 0x14020005)
    {
        LinkMap* pFirstMap = 0;
        LinkMap* pSecondMap = 0;
        if (maps.size > 6)
            pFirstMap = maps.data[6];
        if (maps.size > 7)
            pSecondMap = maps.data[7];
        if (pFirstMap || pSecondMap)
        {
            unsigned int added = 0;
            if (pFirstMap)
                added++;
            if (pSecondMap)
                added++;
            if ((flags & 0xff0) > 0 && added != 0)
            {
                for (unsigned int j = maps.size - 1; j >= 8; --j)
                    maps.SetAtGrow(added + j, maps.data[j]);
            }
            if (pFirstMap)
            {
                maps.SetAtGrow(8, pFirstMap);
                LinkMap* empty = 0;
                maps.SetAt(6, empty);
                IncrementCount();
            }
            else
            {
                LinkMap* empty = 0;
                maps.SetAt(8, empty);
            }
            if (pSecondMap)
            {
                maps.SetAtGrow(9, pSecondMap);
                LinkMap* empty = 0;
                maps.SetAt(7, empty);
                IncrementCount();
            }
            else if (added == 2)
            {
                LinkMap* empty = 0;
                maps.SetAt(9, empty);
            }
        }
    }
    if (stream.m_uiNifVersion >= 0x5000011)
    {
        count = stream.FUN_00a63460();
        for (i = 0; i < count; ++i)
        {
            if (stream.FUN_00a63460())
            {
                LinkMap*& map = shaderMaps->data[i];
                map->texture = stream.FUN_00a63430();
            }
        }
    }
}

struct NiStream;
struct NiSkinInstance
{
    virtual void LinkObject(NiStream&);
};
struct BSDismemberSkinInstance : NiSkinInstance
{
    virtual void LinkObject(NiStream&);
};
// @fnv 0x00a6c670
void BSDismemberSkinInstance::LinkObject(NiStream& stream)
{
    NiSkinInstance::LinkObject(stream);
}

// @fnv 0x00e7cd40
int __cdecl FUN_00e7cd40()
{
    return 0;
}

// NiTexturingProperty::Map constructor.
//
// Layout: vtable slot at 0, packed flag word (u16) at 4, texture pointer at
// 8, texture-transform pointer at 0xc.  The flag word is cleared first (the
// base NiFlags ctor), then the vtable is installed and both pointers are
// cleared; finally the default clamp/filter mode bits are installed in the
// flag word: (flags & 0xf100) | 0x3100 == WRAP_S_WRAP_T + FILTER_BILERP.
//
// _ReadWriteBarrier pins the store order (flag zero before the vtable store,
// vtable before the pointer clears, flag read between the two pointer
// clears) and keeps the flag read from folding into the zero store.

extern "C" void _ReadWriteBarrier();

const void* DAT_0109c4c4[];

class FUN_00a69dd0_cls
{
  public:
    const void** m_vtbl;
    unsigned short m_usFlags;
    void* m_spTexture;
    void* m_pTextureTransform;
    FUN_00a69dd0_cls();
};

// Initialises the object: sets m_vtbl, zeroes m_spTexture and m_pTextureTransform, and sets m_usFlags to 0x3100.
// @fnv 0x00a69dd0
FUN_00a69dd0_cls::FUN_00a69dd0_cls() : m_usFlags(0)
{
    _ReadWriteBarrier();
    m_vtbl = DAT_0109c4c4;
    _ReadWriteBarrier();
    m_spTexture = 0;
    _ReadWriteBarrier();
    unsigned short flags = m_usFlags;
    m_pTextureTransform = 0;
    m_usFlags = (unsigned short)((flags & ~0x0eff) | 0x3100);
}

struct S00a6a150_Vt
{
    virtual void vf00(int value);
};

struct S00a6a150_Arr
{
    void* unk00;
    void* unk04;
    unsigned short unk08;
    unsigned short unk0a;
    unsigned short unk0c;
    unsigned short unk0e;
    void FUN_0096ae90(unsigned int index, NiTexturingProperty::Map*& value);
    void FUN_00a90180(unsigned int size);
};

struct S00a6a150_Tex : public NiTexturingProperty
{
    void FUN_00a69b40(NiTexturingProperty::Map* value);
    void FUN_00a6a150(unsigned int index, NiTexturingProperty::Map* map);
};

// @fnv 0x00a6a150
void S00a6a150_Tex::FUN_00a6a150(unsigned int index, NiTexturingProperty::Map* map)
{
    NiTexturingProperty::Map* newMap;
    unsigned int position = index + 8;

    if (position < m_kStringArray.m_usSize)
    {
        NiTexturingProperty::Map* oldMap = m_kStringArray.m_pBase[position];

        if (map != 0)
        {
            if (oldMap == 0)
            {
                unsigned short flags = m_uiObjectFlags;
                unsigned int count = (flags >> 4) & 0xff;
                count += 1;
                m_uiObjectFlags = (unsigned short)((count << 4) | (flags & 0xf00f));
            }
        }
        else if (oldMap != 0)
        {
            unsigned short flags = m_uiObjectFlags;
            unsigned int count = (flags >> 4) & 0xff;
            count -= 1;
            m_uiObjectFlags = (unsigned short)((count << 4) | (flags & 0xf00f));
        }

        newMap = map;
        reinterpret_cast<S00a6a150_Arr*>(&m_kStringArray)->FUN_0096ae90(position, map);

        if (oldMap != 0)
        {
            reinterpret_cast<S00a6a150_Vt*>(oldMap)->vf00(1);
        }
    }
    else
    {
        S00a6a150_Arr* maps = reinterpret_cast<S00a6a150_Arr*>(&m_kStringArray);
        if (position >= m_kStringArray.m_usMaxSize)
        {
            maps->FUN_00a90180(position + maps->unk0e);
        }

        maps->FUN_0096ae90(position, map);
        newMap = map;

        if (newMap != 0)
        {
            unsigned short flags = m_uiObjectFlags;
            unsigned int count = (flags >> 4) & 0xff;
            count += 1;
            m_uiObjectFlags = (unsigned short)((count << 4) | (flags & 0xf00f));
        }
    }

    FUN_00a69b40(newMap);
}

namespace fnv_00a6bb00 {
struct CloneProc;
struct TexMap
{
    virtual ~TexMap();
    unsigned short m_uiObjectFlags;
    void* m_spTexture;
    void* m_pTextureTransform;
    TexMap(const TexMap&);
    static void operator delete(void*, void*);
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
};
struct TexBumpMap : TexMap
{
    float m_fLumaScale, m_fLumaOffset, m_fBumpMat00, m_fBumpMat01, m_fBumpMat10, m_fBumpMat11;
};
struct TexParallaxMap : TexMap
{
    float m_fParallaxOffset;
};
struct TexShaderMap : TexMap
{
    unsigned int m_uiID;
};
struct TexMapArray
{
    virtual ~TexMapArray();
    TexMap** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    void SetSize(unsigned int);
    TexMap*& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
    void SetAt(unsigned int, TexMap* const&);
    void SetAtGrow(unsigned int i, TexMap* const& v)
    {
        if (i >= m_usMaxSize)
            SetSize(i + m_usGrowBy);
        SetAt(i, v);
    }
};
struct TexShaderMapArrayBase
{
    virtual ~TexShaderMapArrayBase();
    TexShaderMap** m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    TexShaderMapArrayBase(unsigned int maxSize, unsigned int growBy)
    {
        m_usMaxSize = (unsigned short)maxSize;
        m_usGrowBy = (unsigned short)growBy;
        m_usSize = 0;
        m_usESize = 0;
        m_pBase = 0;
    }
    void SetSize(unsigned int);
};
struct TexShaderMapArray : TexShaderMapArrayBase
{
    TexShaderMapArray(unsigned int maxSize = 0, unsigned int growBy = 1) : TexShaderMapArrayBase(maxSize, growBy)
    {}
    virtual ~TexShaderMapArray();
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
    void SetAt(unsigned int i, TexShaderMap*& value)
    {
        if (i >= m_usSize)
        {
            m_usSize = (unsigned short)(i + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[i])
                ++m_usESize;
        }
        else if (m_pBase[i])
            --m_usESize;
        m_pBase[i] = value;
    }
    void SetAtGrow(unsigned int i, TexShaderMap*& value)
    {
        if (i >= m_usMaxSize)
            SetSize(i + m_usGrowBy);
        SetAt(i, value);
    }
};
struct TexProp
{
    virtual ~TexProp();
    unsigned int m_uiRefCount;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned short m_uiObjectFlags;
    TexMapArray m_kStringArray;
    TexShaderMapArray* m_pShaderMaps;
    void FUN_00a5d7a0(TexProp* pkDest, CloneProc& kCloning);
    void SetTextureMapAtIndex(unsigned int i, TexMap* pkMap)
    {
        m_kStringArray.SetAtGrow(i, pkMap);
    }
    void SetBumpMap(TexMap* pkMap)
    {
        m_kStringArray.SetAtGrow(5, pkMap);
    }
    void SetParallaxMap(TexMap* pkMap)
    {
        m_kStringArray.SetAtGrow(7, pkMap);
    }
    TexBumpMap* GetBumpMap()
    {
        return (TexBumpMap*)m_kStringArray.m_pBase[5];
    }
    TexParallaxMap* GetParallaxMap()
    {
        return (TexParallaxMap*)m_kStringArray.m_pBase[7];
    }
    void CloneTo(TexProp* pkDest, CloneProc& kCloning);
};
// Copies texture map arrays and shader maps from this TexProp into pkDest, creating new TexMap, TexBumpMap, TexParallaxMap, and TexShaderMap objects.
// @fnv 0x00a6bb00
void TexProp::CloneTo(TexProp* pkDest, CloneProc& kCloning)
{
    FUN_00a5d7a0(pkDest, kCloning);
    pkDest->m_uiObjectFlags = m_uiObjectFlags;
    unsigned int uiSize = m_kStringArray.m_usSize;
    pkDest->m_kStringArray.SetSize(uiSize);
    unsigned int i;
    for (i = 0; i < uiSize; i++)
    {
        if (m_kStringArray.GetAt(i))
        {
            if (i == 5)
                pkDest->SetBumpMap(new TexBumpMap(*GetBumpMap()));
            else if (i == 7)
                pkDest->SetParallaxMap(new TexParallaxMap(*GetParallaxMap()));
            else
                pkDest->SetTextureMapAtIndex(i, new TexMap(*m_kStringArray.GetAt(i)));
        }
    }
    if (m_pShaderMaps)
    {
        if (!pkDest->m_pShaderMaps)
            pkDest->m_pShaderMaps = new TexShaderMapArray;
        uiSize = m_pShaderMaps->m_usSize;
        pkDest->m_pShaderMaps->SetSize(uiSize);
        for (i = 0; i < uiSize; i++)
        {
            if (m_pShaderMaps->m_pBase[i])
            {
                TexShaderMap* pkMap = new TexShaderMap(*m_pShaderMaps->m_pBase[i]);
                pkDest->m_pShaderMaps->SetAtGrow(i, pkMap);
            }
        }
    }
}
}  // namespace fnv_00a6bb00

class NiTextureRef_a6a9f0
{
  public:
    virtual ~NiTextureRef_a6a9f0();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }
};

struct DeallocHelper00aa4060
{
    void FUN_00aa4060(void* p);
};

NiTexturingProperty::Map::~Map()
{
    reinterpret_cast<DeallocHelper00aa4060*>(&g_memoryManager)->FUN_00aa4060(m_pTextureTransform);
    if (m_spTexture.m_pObject)
        reinterpret_cast<NiTextureRef_a6a9f0*>(m_spTexture.m_pObject)->DecRefCount();
}

struct MapScalarDtorCandidate : NiTexturingProperty::Map
{
    void* FUN_00a6a9f0(unsigned int flags);
};

// Calls the base Map destructor, then frees this object via g_memoryManager when flags has bit 0 set, and returns this.
// @fnv 0x00a6a9f0
void* MapScalarDtorCandidate::FUN_00a6a9f0(unsigned int flags)
{
    this->NiTexturingProperty::Map::~Map();
    if (flags & 1)
        reinterpret_cast<DeallocHelper00aa4060*>(&g_memoryManager)->FUN_00aa4060(this);
    return this;
}

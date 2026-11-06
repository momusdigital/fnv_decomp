// fallout_shared/teseffectshader.cpp: TESEffectShader, EffectShaderData, EffectShaderShell, ShaderSettings and more (26 functions)

#include "../teseffectshader.h"
#include "TESFile.h"

// @fnv 0x00506510
void EffectShaderData::Initialize()
{
    cFlags = 0;
    m_eDestinationBlend = static_cast<_D3DBLEND>(5);
    m_eBlendOperation = static_cast<_D3DBLENDOP>(1);
    m_eDepthCompareFunction = static_cast<_NDLZCMPFUNC>(3);
    BlendDepthState = 0;
    BlendDepthParameters = 0.0f;
    DepthCompareParameters = 0.0f;
    IndexedFloatParameters = 0.0f;
    ShaderFloatParameterSet = 0.0f;
    ShaderParameterFormatSet = 0.0f;
    SevenFloatParameterRecord = 1.0f;
    SixFloatAndUnsignedIntegerRecord = 0.0f;
    SixFloatUnsignedIntegerAndFloatRecord = 0.0f;
    ExtendedFloatFlagParameters = 1.0f;
    ShaderFloatParameterBlock = 0;
    SixFloatRecordWithMiddleFlag = 0.0f;
    FloatFlagParameters = 0.0f;
    SixFloatRecordWithLeadingFlag = 0.0f;
    BlendFloatParameters = 0.0f;
    AlphaBlendParameters = 0.0f;
    BlendStateParameters = 1.0f;
    m_eSourceBlend = static_cast<_D3DBLEND>(6);
    BlendFactorState = 1.0f;
    BlendModeConfiguration = 1.0f;
    m_eAlphaSourceBlend = static_cast<_D3DBLEND>(5);
    m_eAlphaDestinationBlend = static_cast<_D3DBLEND>(6);
    m_eAlphaBlendOperation = static_cast<_D3DBLENDOP>(1);
    m_eAlphaDepthCompareFunction = static_cast<_NDLZCMPFUNC>(4);
    AlphaBlendSettings = 0.0f;
    m_fAlphaBlendParameter = 0.0f;
    BlendFactorParameters = 0.0f;
    m_fShaderFloatParameter1 = 1.0f;
    m_fShaderFloatParameter2 = 1.0f;
    m_fShaderFloatParameter3 = 1.0f;
    m_fShaderFloatParameter4 = 0.0f;
    m_fShaderFloatParameter5 = 0.0f;
    m_fShaderFloatParameter6 = 0.0f;
    VelocityState = NiPoint3(0.0f, 0.0f, 0.0f);
    m_kVectorState2 = NiPoint3(0.0f, 0.0f, 0.0f);
    m_fShaderFloatParameter7 = 1.0f;
    m_fShaderFloatParameter8 = 1.0f;
    m_fShaderFloatParameter9 = 0.0f;
    m_fShaderFloatParameter10 = 1.0f;
    m_uiColorParameter1 = 16777215;
    m_uiColorParameter2 = 16777215;
    m_uiColorParameter3 = 16777215;
    m_fShaderFloatParameter11 = 1.0f;
    m_fShaderFloatParameter12 = 1.0f;
    m_fShaderFloatParameter13 = 1.0f;
    m_fShaderFloatParameter14 = 0.0f;
    m_fShaderFloatParameter15 = 0.5f;
    m_fShaderFloatParameter16 = 1.0f;
    m_fShaderFloatParameter17 = 0.0f;
    m_fShaderFloatParameter18 = 0.0f;
    m_fShaderFloatParameter19 = 0.0f;
    m_fShaderFloatParameter20 = 0.0f;
    m_fShaderFloatParameter21 = 0.0f;
    DebrisModelSettings = 0.0f;
    EffectShaderAddonData = 10.0f;
    DebrisColorSettings = 255.0f;
    EffectShaderColorData = 0.0f;
    EffectShaderParameters = 0.0f;
    m_uiBaseColor = 16777215;
    m_fFloatAfterDefaultColor = 0.0f;
    m_uiIntegerParameter1 = 1;
    m_uiIntegerParameter2 = 1;
    m_fFirstValueAfterIntegerFields = 1.0f;
    m_fSecondValueAfterIntegerFields = 1.0f;
    UnsignedIntAndSixFloatData = 1.0f;
    SixFloatValueSet = 1.0f;
    FiveFloatData = 1.0f;
    FourFloatValueSet = 1.0f;
}

// @fnv 0x00505db0
void TESEffectShader::ResetFormData()
{
    GetData()->Initialize();
}

// @fnv 0x00505dd0
void TESEffectShader::InitItem()
{
    if (IsFormInitialized())
        return;
    unsigned int formID = reinterpret_cast<unsigned int>(GetAddonModels());
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        SetAddonModels(dynamic_cast<BGSDebris*>(GetFormByID(formID)));
    }
    SetInitializationState(true);
}

extern "C" void* __cdecl _alloca(unsigned int size);

// @fnv 0x00505e70
bool TESEffectShader::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x4f)
        return false;
    ClearData();
    LoadRecordHeader(file);
    SetInitializationState(false);
    int iChunkID;
    while (iChunkID = file->GetChunkID())
    {
        switch (iChunkID)
        {
        case 0x44494445: {
            char* pChunkBuffer = static_cast<char*>(_alloca(file->GetChunkSize()));
            file->GetChunkData(pChunkBuffer, 0x200);
            SetEditorID_AtRuntime(pChunkBuffer);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4e4f4349:
            TESTextureLoader::ReadTextureData(&m_kFillTexture, file);
            break;
        case 0x324f4349:
            TESTextureLoader::ReadTextureData(&m_kParticleShaderTexture, file);
            break;
        case 0x374d414e:
            TESTextureLoader::ReadTextureData(&m_kHolesTexture, file);
            break;
        case 0x41544144:
            if (file->IsEndianConversionRequired())
                Data.Endian();
            ReadTypedData(file, &Data, sizeof(Data));
            if (file->IsEndianConversionRequired())
                Data.Endian();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (Data.m_fShaderFloatParameter1 <= 1.0 && Data.m_fShaderFloatParameter1 > 0.0)
        Data.m_fShaderFloatParameter1 *= ParticleShader::GetShaderParticleCount();
    if (Data.m_fShaderFloatParameter2 <= 1.0 && Data.m_fShaderFloatParameter2 > 0.0)
        Data.m_fShaderFloatParameter2 *= ParticleShader::GetShaderParticleCount();
    return true;
}

struct FUN_00507040Class
{
    EffectShaderData* GetData();
    bool FUN_00507040(unsigned int mask);
};
// @fnv 0x00507040
bool FUN_00507040Class::FUN_00507040(unsigned int mask)
{
    return *(unsigned char*)GetData() & mask;
}

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_005050b0 : Base5a
{
    ~FUN_005050b0();
};
// @fnv 0x005050b0
FUN_005050b0::~FUN_005050b0()
{}

struct FUN_00506370Class
{
    void* GetFieldAt14C();
};
// @fnv 0x00506370
void* FUN_00506370Class::GetFieldAt14C()
{
    return reinterpret_cast<char*>(this) + 0x14c;
}

struct FUN_00506390Class
{
    char* GetFieldAt158();
};
// @fnv 0x00506390
char* FUN_00506390Class::GetFieldAt158()
{
    return reinterpret_cast<char*>(this) + 0x158;
}

struct FUN_005063b0Class
{
    void* GetFieldAt164();
};

// @fnv 0x005063b0
void* FUN_005063b0Class::GetFieldAt164()
{
    return reinterpret_cast<char*>(this) + 0x164;
}

extern "C" void __cdecl FUN_00ba6290(int a, int b);

struct FUN_00507810Class
{
    void FUN_00507810(int a, int b);
};

// @fnv 0x00507810
void FUN_00507810Class::FUN_00507810(int aiArg1, int aiArg2)
{
    FUN_00ba6290(aiArg1, aiArg2);
}

struct FUN_00507b00Class
{
    float GetField4C();
};
// @fnv 0x00507b00
float FUN_00507b00Class::GetField4C()
{
    return *(float*)((char*)this + 0x4c);
}

struct FUN_00507b20Class
{
    float FUN_00507b20();
};

// @fnv 0x00507b20
float FUN_00507b20Class::FUN_00507b20()
{
    return *(float*)((char*)this + 0x118);
}

extern "C" void __cdecl Deallocate(void*);
struct TESEffectShader;
struct FUN_00505cf0Class
{
    void FUN_00505d20();
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_00505d20, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00505cf0
void* FUN_00505cf0Class::DestroyIfFlagged(unsigned int flags)
{
    FUN_00505d20();
    if (flags & 1)
        Deallocate(this);
    return this;
}

struct NiAVObject;
struct NiSourceTexture;
struct ParticleShaderProperty
{
    void SetParticleTime(float);
};
ParticleShaderProperty* __cdecl FUN_00ba68d0(NiAVObject*, NiAVObject*);
struct FUN_00507060Class
{
    void CopySettingsTo(ParticleShaderProperty*, NiSourceTexture*);
};
struct FUN_005077c0Class
{
    ParticleShaderProperty* FUN_005077c0(NiAVObject* apRootObject, NiAVObject* apTargetObject, NiSourceTexture* apTex,
                                         float afTime);
};
// @fnv 0x005077c0
ParticleShaderProperty* FUN_005077c0Class::FUN_005077c0(NiAVObject* apRootObject, NiAVObject* apTargetObject,
                                                        NiSourceTexture* apTex, float afTime)
{
    ParticleShaderProperty* pProp;
    if (apTex)
    {
        pProp = FUN_00ba68d0(apRootObject, apTargetObject);
        ((FUN_00507060Class*)this)->CopySettingsTo(pProp, apTex);
        pProp->SetParticleTime(afTime);
        return pProp;
    }
    return 0;
}

extern int DAT_0102685c;

struct FUN_00505d20 : Base5a
{
    char pad[0x147];
    TESTexture m1;
    TESTexture m2;
    TESTexture m3;
    ~FUN_00505d20();
};

// @fnv 0x00505d20
FUN_00505d20::~FUN_00505d20()
{}

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
struct FUN_005062a0Class
{
    void CopyFrom(TESForm* apCopy);
};
void __cdecl _memcpy(void* dst, const void* src, unsigned int n);
// Copies a TESEffectShader's data, base component and three textures into this object after a dynamic_cast check.
// @fnv 0x005062a0
void FUN_005062a0Class::CopyFrom(TESForm* apCopy)
{
    TESEffectShader* pcopy = dynamic_cast<TESEffectShader*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_005e78f0_t*)this)->FUN_004851b0(pcopy);
    _memcpy(((TESEffectShader*)this)->GetData(), pcopy->GetData(), 0x134);
    ((TESTexture*)((char*)this + 0x14c))
        ->CopyFromBase((BaseFormComponent*)((FUN_00506370Class*)pcopy)->GetFieldAt14C());
    ((TESTexture*)((char*)this + 0x158))
        ->CopyFromBase((BaseFormComponent*)((FUN_00506390Class*)pcopy)->GetFieldAt158());
    ((TESTexture*)((char*)this + 0x164))
        ->CopyFromBase((BaseFormComponent*)((FUN_005063b0Class*)pcopy)->GetFieldAt164());
}

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm*);
};

int __cdecl _memcmp(const void*, const void*, unsigned int);
struct FUN_005063d0Shell : public TESEffectShader
{
    bool FUN_005063d0(TESForm* apCompare);
};
// Compares this effect shader with apCompare: returns true if apCompare is not a TESEffectShader or any component or the shader data differs.
// @fnv 0x005063d0
bool FUN_005063d0Shell::FUN_005063d0(TESForm* apCompare)
{
    TESEffectShader* pOtherShader = dynamic_cast<TESEffectShader*>(apCompare);
    if (!pOtherShader)
        return true;
    if (((FUN_005e79a0_t*)this)->FUN_00485270(pOtherShader))
        return true;
    if (m_kFillTexture.CompareWithBase((BaseFormComponent*)((FUN_00506370Class*)pOtherShader)->GetFieldAt14C()))
        return true;
    if (m_kParticleShaderTexture.CompareWithBase(
            (BaseFormComponent*)((FUN_00506390Class*)pOtherShader)->GetFieldAt158()))
        return true;
    if (m_kHolesTexture.CompareWithBase((BaseFormComponent*)((FUN_005063b0Class*)pOtherShader)->GetFieldAt164()))
        return true;
    if (_memcmp(&Data, pOtherShader->GetData(), sizeof(EffectShaderData)))
        return true;
    return false;
}

struct FUN_004855a0
{
    void M();
};

struct FUN_00485680
{
    void M();
};

struct FUN_0048e370_obj
{
    void FUN_0048e370(unsigned int);
};

struct FUN_00485e00_shell
{
    void __SaveData(void*, int);
};

struct TESModel
{
    unsigned int GetModelLength();
};

struct FNStub
{
    char* GetFullName();
};

struct FUN_005060f0Class
{
    void FUN_005060f0();
};

void FUN_004856f0(unsigned int, void*, unsigned int);

bool _FUN_00401500();

struct FUN_005060f0Data
{
    char pad[0x10c];
    BGSDebris* mAddon;
};

// @fnv 0x005060f0
void FUN_005060f0Class::FUN_005060f0()
{
    reinterpret_cast<FUN_004855a0*>(this)->M();

    if (reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x14c)->GetModelLength() == 0)
    {
        FUN_004856f0(0x4e4f4349, reinterpret_cast<FNStub*>(reinterpret_cast<char*>(this) + 0x14c)->GetFullName(),
                     reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x14c)->GetModelLength() + 1);
    }
    else
    {
        reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x14c)->FUN_0048e370(0x4e4f4349);
    }

    if (reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x158)->GetModelLength() == 0)
    {
        FUN_004856f0(0x324f4349, reinterpret_cast<FNStub*>(reinterpret_cast<char*>(this) + 0x158)->GetFullName(),
                     reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x158)->GetModelLength() + 1);
    }
    else
    {
        reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x158)->FUN_0048e370(0x324f4349);
    }

    if (reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x164)->GetModelLength() == 0)
    {
        FUN_004856f0(0x374d414e, reinterpret_cast<FNStub*>(reinterpret_cast<char*>(this) + 0x164)->GetFullName(),
                     reinterpret_cast<TESModel*>(reinterpret_cast<char*>(this) + 0x164)->GetModelLength() + 1);
    }
    else
    {
        reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x164)->FUN_0048e370(0x374d414e);
    }

    BGSDebris* psaveAddon = reinterpret_cast<FUN_005060f0Data*>(this)->mAddon;

    reinterpret_cast<FUN_005060f0Data*>(this)->mAddon =
        reinterpret_cast<FUN_005060f0Data*>(this)->mAddon
            ? reinterpret_cast<BGSDebris*>(reinterpret_cast<FUN_005060f0Data*>(this)->mAddon->GetFormID())
            : 0;

    if (_FUN_00401500())
    {
        reinterpret_cast<EffectShaderData*>(reinterpret_cast<char*>(this) + 0x18)->Endian();
    }

    reinterpret_cast<FUN_00485e00_shell*>(this)->__SaveData(reinterpret_cast<char*>(this) + 0x18, 0x134);

    if (_FUN_00401500())
    {
        reinterpret_cast<EffectShaderData*>(reinterpret_cast<char*>(this) + 0x18)->Endian();
    }

    reinterpret_cast<FUN_005060f0Data*>(this)->mAddon = psaveAddon;

    reinterpret_cast<FUN_00485680*>(this)->M();
}

struct BGSPerk;
struct BSSimpleListT
{
    BGSPerk** GetItem();
};
struct FUN_005064d0
{
    FUN_005064d0* Init();
};
// @fnv 0x005064d0
FUN_005064d0* FUN_005064d0::Init()
{
    ((BSSimpleListT*)((char*)this + 0x94))->GetItem();
    ((BSSimpleListT*)((char*)this + 0xa0))->GetItem();
    ((EffectShaderData*)this)->Initialize();
    return this;
}

struct FUN_005074e0_vec4
{
    float x;
    float y;
    float z;
    float w;
};

class FUN_005074e0_cls
{
  public:
    FUN_005074e0_vec4 m_v;
    FUN_005074e0_vec4* DivideByScalar(FUN_005074e0_vec4* out, float s);
};

// Copies m_v into a local vector, divides each of its four components by s, stores the result in out and returns out.
// @fnv 0x005074e0
FUN_005074e0_vec4* FUN_005074e0_cls::DivideByScalar(FUN_005074e0_vec4* out, float s)
{
    FUN_005074e0_vec4 vDivided = m_v;
    vDivided.x = vDivided.x / s;
    vDivided.y = vDivided.y / s;
    vDivided.z = vDivided.z / s;
    vDivided.w = vDivided.w / s;
    *out = vDivided;
    return out;
}

struct NiFixedStr
{
    operator const char*() const;
};

struct ShaderPropStub
{
    void ApplyTexEffect(void* apData);
};

struct NiPropStub
{
    int GetPropType();
    NiFixedStr& GetName();
};

struct NiAVObject;

struct NiNodeStub
{
    unsigned int GetChildCount();
    NiAVObject* GetChildAt(unsigned int auiIndex);
};

struct NiAVObject
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual NiNodeStub* IsSceneNode();
    virtual void V10();
    virtual void V14();
    virtual void* IsGeometry();
    NiPropStub* GetProperty(unsigned int auiType);
};

int FUN_00408b20(const char*, const char*);

struct EffectShaderShell : public TESEffectShader
{
    bool FUN_00507040(unsigned int mask);
    void ApplyShaderToTree(NiAVObject* apObject, void* apData);
};

// @fnv 0x00507b40
void EffectShaderShell::ApplyShaderToTree(NiAVObject* apObject, void* apData)
{
    if (apObject)
    {
        if (apObject->IsGeometry())
        {
            NiPropStub* pProp = apObject->GetProperty(3);
            ShaderPropStub* pShader;
            if ((pShader = (!pProp ? 0 : (pProp->GetPropType() >= 8 && pProp->GetPropType() <= 12))
                               ? (ShaderPropStub*)pProp
                               : 0) != 0)
            {
                bool bApply = true;
                if (FUN_00507040(0x20))
                {
                    NiPropStub* pNameProp = apObject->GetProperty(2);
                    if (!(const char*)pNameProp->GetName() || FUN_00408b20(pNameProp->GetName(), "skin"))
                    {
                        bApply = false;
                    }
                }
                if (bApply)
                {
                    pShader->ApplyTexEffect(apData);
                }
            }
        }
        else
        {
            NiNodeStub* pNode = apObject->IsSceneNode();
            if (pNode)
            {
                for (unsigned int i = 0; i < pNode->GetChildCount(); i++)
                {
                    ApplyShaderToTree(pNode->GetChildAt(i), apData);
                }
            }
        }
    }
}

struct S_00507c90_Ptr;
struct S_00507c90_List;
struct S_00507c90_Item
{
    int FUN_00441110();
    S_00507c90_Ptr* FUN_00507d80();
    void AssignRefObj(S_00507c90_Ptr* p);
};
struct S_00507c90_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00507c90_List* v3();
    virtual void v4();
    virtual void v5();
    virtual S_00507c90_Item* v6();
    S_00507c90_Item* FUN_00a59d30(int n);
};
struct S_00507c90_List
{
    int FUN_0043b480();
    S_00507c90_Obj* FUN_0043b4a0(int i);
};
struct S_00507c90_Cls
{
    void ClearItemRef(S_00507c90_Obj* obj, S_00507c90_Ptr* ref);
};
// Recursively walks obj's list, and for items whose value is 8..12 clears the reference if it equals ref.
// @fnv 0x00507c90
void S_00507c90_Cls::ClearItemRef(S_00507c90_Obj* obj, S_00507c90_Ptr* ref)
{
    if (obj)
    {
        if (obj->v6())
        {
            S_00507c90_Item* t_ = obj->FUN_00a59d30(3);
            S_00507c90_Item* s;
            if ((s = (!t_ ? 0 : (t_->FUN_00441110() >= 8 && t_->FUN_00441110() <= 12)) ? t_ : 0) != 0)
            {
                if (s->FUN_00507d80() == ref)
                    s->AssignRefObj(0);
            }
        }
        else
        {
            S_00507c90_List* list = obj->v3();
            if (list)
            {
                for (unsigned int i2 = 0; i2 < (unsigned int)list->FUN_0043b480(); i2++)
                    ClearItemRef(list->FUN_0043b4a0(i2), ref);
            }
        }
    }
}

struct Color
{
    float r, g, b, a;
    Color(float, float, float, float);
    Color operator/(float);
};
struct Destination
{
    void FUN_00507550(void*);
    void FUN_00584150(float);
    void FUN_00507570(float);
    void FUN_0051b8c0(float);
    void FUN_00810550(float);
    void FUN_006e29d0(float);
    void SetData(NiPoint3);
    void FUN_005075c0(NiPoint3);
    void FUN_005075f0(float);
    void FUN_009314d0(float);
    void FUN_00507610(float);
    void FUN_006e5ee0(float);
    void FUN_00507780(float);
    void SetBoltSmallWidth(float);
    void FUN_005077a0(float);
    void SetPoint(Color);
    void FUN_00507660(Color);
    void FUN_00507690(Color);
    void FUN_006e4ef0(float);
    void FUN_006e4320(float);
    void FUN_005076c0(float);
    void FUN_005076e0(float);
    void FUN_00733fd0(float);
    void SetMaxFarNearRatio(float);
    void FUN_00507720(float);
    void FUN_006d30e0(int);
    void FUN_00505e50(int);
    void FUN_00507740(int);
    void FUN_00507760(int);
};
struct ShaderSettings : TESEffectShader
{
    void CopySettingsTo(Destination*, void*);
};
// Copies the effect shader's Data fields into dest via its setters, converting three packed RGB values into normalized Colors with separate alpha values.
// @fnv 0x00507060
void ShaderSettings::CopySettingsTo(Destination* apDestination, void* apTexture)
{
    apDestination->FUN_00507550(apTexture);
    apDestination->FUN_00584150(Data.m_fShaderFloatParameter3);
    apDestination->FUN_00507570(Data.m_fShaderFloatParameter4);
    apDestination->FUN_0051b8c0(Data.m_fShaderFloatParameter5);
    apDestination->FUN_00810550(Data.m_fShaderFloatParameter6);
    apDestination->FUN_006e29d0(Data.m_fShaderFloatParameter17);
    apDestination->SetData(Data.VelocityState);
    apDestination->FUN_005075c0(Data.m_kVectorState2);
    apDestination->FUN_005075f0(Data.m_fShaderFloatParameter18);
    apDestination->FUN_009314d0(Data.m_fShaderFloatParameter19);
    apDestination->FUN_00507610(Data.m_fShaderFloatParameter20);
    apDestination->FUN_006e5ee0(Data.m_fShaderFloatParameter21);
    apDestination->FUN_00507780(Data.m_uiIntegerParameter1);
    apDestination->SetBoltSmallWidth(Data.m_uiIntegerParameter2);
    apDestination->FUN_005077a0(Data.m_fFloatAfterDefaultColor);
    Color color1 = Color((unsigned char)(Data.m_uiColorParameter1 & 255),
                         (unsigned char)(((unsigned short)Data.m_uiColorParameter1 >> 8) & 255),
                         (unsigned char)((Data.m_uiColorParameter1 >> 16) & 255), 0.0f) /
                   255.0f;
    Color color2 = Color((unsigned char)(Data.m_uiColorParameter2 & 255),
                         (unsigned char)(((unsigned short)Data.m_uiColorParameter2 >> 8) & 255),
                         (unsigned char)((Data.m_uiColorParameter2 >> 16) & 255), 0.0f) /
                   255.0f;
    Color color3 = Color((unsigned char)(Data.m_uiColorParameter3 & 255),
                         (unsigned char)(((unsigned short)Data.m_uiColorParameter3 >> 8) & 255),
                         (unsigned char)((Data.m_uiColorParameter3 >> 16) & 255), 0.0f) /
                   255.0f;
    color1.a = Data.m_fShaderFloatParameter11;
    color2.a = Data.m_fShaderFloatParameter12;
    color3.a = Data.m_fShaderFloatParameter13;
    apDestination->SetPoint(color1);
    apDestination->FUN_00507660(color2);
    apDestination->FUN_00507690(color3);
    apDestination->FUN_006e4ef0(Data.m_fShaderFloatParameter14);
    apDestination->FUN_006e4320(Data.m_fShaderFloatParameter15);
    apDestination->FUN_005076c0(Data.m_fShaderFloatParameter16);
    apDestination->FUN_005076e0(Data.m_fShaderFloatParameter7);
    apDestination->FUN_00733fd0(Data.m_fShaderFloatParameter8);
    apDestination->SetMaxFarNearRatio(Data.m_fShaderFloatParameter9);
    apDestination->FUN_00507720(Data.m_fShaderFloatParameter10);
    apDestination->FUN_006d30e0(Data.m_eAlphaSourceBlend);
    apDestination->FUN_00505e50(Data.m_eAlphaDestinationBlend);
    apDestination->FUN_00507740(Data.m_eAlphaBlendOperation);
    apDestination->FUN_00507760(Data.m_eAlphaDepthCompareFunction);
}

struct ColorValue
{
    float x, y, z, w;
    ColorValue(float, float, float, float);
    ColorValue Normalize(float);
};
struct RefValue
{
    void* value;
    RefValue& operator=(void*);
};
struct EffectData
{
    int unk00, unk04;
    RefValue root;
    int unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    ColorValue fill, edge;
    float unk4c, unk50, scale, diameter;
    unsigned int unk5c, unk60, unk64, unk68;
    RefValue target;
    unsigned int unk70;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    EffectData();
};
struct BoundValue
{
    float Radius();
};
struct SceneValue
{
    BoundValue* Bound();
};
struct ShaderSource
{
    unsigned int Fill();
    unsigned int Edge();
    float Scale();
    unsigned int Mode();
    unsigned int Value60();
    unsigned int Value64();
    unsigned int Value68();
    float Count();
    bool HasFlag(unsigned int);
    EffectData* CreateEffectData(SceneValue*, void*, void*);
};
// @fnv 0x00507830
EffectData* ShaderSource::CreateEffectData(SceneValue* scene, void* root, void* target)
{
    EffectData* data2 = new EffectData;
    unsigned int fill = Fill();
    unsigned int edge = Edge();
    data2->root = 0;
    data2->fill =
        ColorValue((float)(unsigned char)(fill & 255), (float)(unsigned char)((unsigned short)fill >> 8 & 255),
                   (float)(unsigned char)(fill >> 16 & 255), 0.0f)
            .Normalize(255.0f);
    data2->edge =
        ColorValue((float)(unsigned char)(edge & 255), (float)(unsigned char)((unsigned short)edge >> 8 & 255),
                   (float)(unsigned char)(edge >> 16 & 255), 0.0f)
            .Normalize(255.0f);
    data2->unk4c = 0.0f;
    data2->unk50 = 0.0f;
    data2->scale = Scale();
    data2->diameter = scene->Bound()->Radius() * 2.0f;
    data2->unk5c = Mode();
    data2->unk60 = Value60();
    data2->unk64 = Value64();
    data2->unk68 = Value68();
    data2->root = root;
    data2->target = target;
    data2->unk70 = (unsigned int)Count();
    if (HasFlag(16))
    {
        data2->edge.x += -1.0;
        data2->edge.y += -1.0;
        data2->edge.z += -1.0;
    }
    return data2;
}

struct Color4
{
    float x, y, z, w;
};
struct ShaderState
{
    int unk00, unk04, unk08;
    Color4 fill, edge, baseFill, baseEdge;
    float u, v;
    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    unsigned int alpha;
};
float __cdecl FUN_00404010(float, float);
float __cdecl FUN_0040ebd0(float, float);
float __cdecl LinearInterpolate(float, float, float, float, float);
struct ShaderUpdate
{
    float UpdateFill(float, float, float, unsigned char);
    float FillPulse(float);
    float UpdateEdge(float, float, float, unsigned char);
    float EdgePulse(float);
    float USpeed();
    float VSpeed();
    float EndTime();
    float StartTime();
    float EndAlpha();
    float StartAlpha();
    void UpdateShaderState(ShaderState*, float, float, float, unsigned char);
};
// Advances a ShaderState's fill/edge alpha, UV offsets and alpha from delta, duration, time and mode.
// @fnv 0x00507e30
void ShaderUpdate::UpdateShaderState(ShaderState* state, float delta, float duration, float time, unsigned char mode)
{
    if (state)
    {
        state->baseFill.w = UpdateFill(state->baseFill.w, delta, duration, mode);
        state->fill = state->baseFill;
        state->fill.w = FillPulse(time) * state->fill.w + state->fill.w;
        state->fill.w = FUN_0040ebd0(1.0f, FUN_00404010(0.0f, state->fill.w));
        state->baseEdge.w = UpdateEdge(state->baseEdge.w, delta, duration, mode);
        state->edge = state->baseEdge;
        state->edge.w = EdgePulse(time) * state->edge.w + state->edge.w;
        state->edge.w = FUN_0040ebd0(1.0f, FUN_00404010(0.0f, state->edge.w));
        state->u = USpeed() * delta + state->u;
        state->v = VSpeed() * delta + state->v;
        float boundedTime = FUN_0040ebd0(StartTime(), FUN_00404010(EndTime(), time));
        state->alpha = (unsigned int)LinearInterpolate(StartAlpha(), EndAlpha(), EndTime(), StartTime(), boundedTime);
    }
}

struct SwapFlag
{
    bool value;
};
extern "C" void __cdecl FUN_00401080(void* field, bool reverseBytes);
struct EffectShaderDataEndian : EffectShaderData
{
    void FUN_00506850();
};
// @fnv 0x00506850
void EffectShaderDataEndian::FUN_00506850()
{
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_eDestinationBlend, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_eBlendOperation, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_eDepthCompareFunction, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&BlendDepthState, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&BlendDepthParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&DepthCompareParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&IndexedFloatParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&ShaderFloatParameterSet, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&ShaderParameterFormatSet, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&SevenFloatParameterRecord, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&SixFloatAndUnsignedIntegerRecord, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&SixFloatUnsignedIntegerAndFloatRecord, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&ExtendedFloatFlagParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&ShaderFloatParameterBlock, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&SixFloatRecordWithMiddleFlag, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&FloatFlagParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&SixFloatRecordWithLeadingFlag, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&BlendFloatParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&AlphaBlendParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&BlendStateParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&BlendFactorState, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&BlendModeConfiguration, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_eSourceBlend, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_eAlphaSourceBlend, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_eAlphaBlendOperation, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_eAlphaDepthCompareFunction, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_eAlphaDestinationBlend, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&AlphaBlendSettings, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fAlphaBlendParameter, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&BlendFactorParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter1, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter2, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter3, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter4, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter5, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter6, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&VelocityState.x, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&VelocityState.y, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&VelocityState.z, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_kVectorState2.x, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_kVectorState2.y, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_kVectorState2.z, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter7, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter8, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter9, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter10, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_uiColorParameter1, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_uiColorParameter2, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_uiColorParameter3, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter11, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter12, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter13, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter14, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter15, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter16, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter17, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter18, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter19, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter20, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fShaderFloatParameter21, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&DebrisModelSettings, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&EffectShaderAddonData, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&DebrisColorSettings, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&EffectShaderColorData, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&EffectShaderParameters, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_uiBaseColor, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fFloatAfterDefaultColor, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_uiIntegerParameter1, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_uiIntegerParameter2, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fFirstValueAfterIntegerFields, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&m_fSecondValueAfterIntegerFields, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&UnsignedIntAndSixFloatData, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&SixFloatValueSet, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&FiveFloatData, needsEndianSwap.value);
    }
    {
        SwapFlag needsEndianSwap = {};
        FUN_00401080(&FourFloatValueSet, needsEndianSwap.value);
    }
}

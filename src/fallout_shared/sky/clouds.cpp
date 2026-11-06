// fallout_shared/sky/clouds.cpp: Clouds (10 functions)

#include "clouds_decls.h"

// @fnv 0x00634110
void Clouds::Update(Sky* sky, float time)
{
    SkyObject::Update(sky, time);
    TESWeather* m_pWeatherObject = sky->FUN_0044edb0();
    TESWeather* m_pPreviousWeather = sky->FUN_00825c00();
    if (!m_pWeatherObject)
        return;
    for (int i = 0; i < GetOffset58(); ++i)
        if (!m_pCloudLayerGeometry[i])
            return;
    if (sky->FUN_00476c90() == 3 || sky->FUN_00476c90() == 2)
    {
        for (int i = 0; i < GetOffset58(); ++i)
        {
            float speed;
            float delta;
            CloudsColorController* controller =
                (!m_pCloudLayerGeometry[i]->FUN_0050d100()->GetControllers()
                     ? false
                     : m_pCloudLayerGeometry[i]->FUN_0050d100()->GetControllers()->FUN_00441110() == 13)
                    ? (CloudsColorController*)m_pCloudLayerGeometry[i]->FUN_0050d100()->GetControllers()
                    : 0;
            if (controller)
            {
                NiColor color = GetPointAt(i);
                controller->color = RgbaColor(color.r, color.g, color.b, 1.0f);
            }
            speed = m_pWeatherObject->GetCloudLayerSpeed(i, DAT_011cca6c.Float()->f, 0.0f);
            if (m_pPreviousWeather)
            {
                speed *= sky->GetCurrentWeatherPct();
                speed += (1.0f - sky->GetCurrentWeatherPct()) *
                         m_pPreviousWeather->GetCloudLayerSpeed(i, DAT_011cca6c.Float()->f, 0.0f);
            }
            delta = sky->GetFieldCC() * time * speed;
            AddToFloatArray((unsigned short)i, delta);
        }
    }
    if (sky->GetWeatherUpdateFlag() || bForceUpdate)
    {
        bForceUpdate = false;
        if (m_pPreviousWeather)
        {
            for (int i = 0; i < GetOffset58(); ++i)
            {
                BSStringT<char> path;
                SkyShaderProperty* property = (SkyShaderProperty*)m_pCloudLayerGeometry[i]->GetProperty(3);
                TESTexture1024* pkTexture = m_pWeatherObject->GetCloudTexture(i);
                if (pkTexture && pkTexture->GetModelLength())
                {
                    path = pkTexture->vfn_18();
                    path += pkTexture->GetTextureResourceName();
                    sky->GetTextureManager();
                    SkyTextureManager::LoadTextureFromPath(&m_pCloudLayerTexture[i], path);
                }
                else
                    m_pCloudLayerTexture[i] = 0;
            }
        }
        else if (sky->FUN_00476c90() == 3 || sky->FUN_00476c90() == 2)
        {
            for (int i = 0; i < GetOffset58(); ++i)
            {
                BSStringT<char> path;
                SkyShaderProperty* property = (SkyShaderProperty*)m_pCloudLayerGeometry[i]->GetProperty(3);
                TESTexture1024* pkTexture = m_pWeatherObject->GetCloudTexture(i);
                if (pkTexture && pkTexture->GetModelLength())
                {
                    path = pkTexture->vfn_18();
                    path += pkTexture->GetTextureResourceName();
                    NiPointer<NiTexture> loaded = 0;
                    BSShaderManager::GetTexture(path, true, loaded, true, false);
                    NiTexture* raw = loaded;
                    if (raw)
                    {
                        property->SetTexture(raw);
                        property->SetTextureFile(NiFixedString(path));
                        property->FUN_0051b8c0(0.0f);
                    }
                }
            }
        }
    }
    for (int i = 0; i < GetOffset58(); ++i)
    {
        SkyShaderProperty* property;
        NiProperty* baseProperty = m_pCloudLayerGeometry[i]->GetProperty(3);
        property = FUN_00653270(&DAT_012005b8, baseProperty);
        if (m_pCloudLayerTexture[i])
        {
            if (property)
            {
                property->FUN_00bae930(m_pCloudLayerTexture[i]);
                property->FUN_0051b8c0(sky->GetCurrentWeatherPct());
            }
            if (!m_pPreviousWeather)
            {
                property->SetTexture(m_pCloudLayerTexture[i]);
                m_pCloudLayerTexture[i] = 0;
                property->FUN_00bae930(0);
                property->FUN_0051b8c0(0.0f);
            }
        }
        m_pCloudLayerGeometry[i]->FUN_00450f90(!property || !property->FUN_009c8680());
    }
}

// Loads Clouds.nif, attaches its 3D to parent, adds each geometry child to the cloud node, and sets the layer count.
// @fnv 0x00633ed0
void Clouds::Initialize(NiNode* parent)
{
    SkyObject::Initialize(parent);
    BSStream stream;
    if (stream.FUN_00c3a8a0("Meshes\\Sky\\Clouds.nif", false))
    {
        Model kModel("Meshes\\Sky\\Clouds.nif", &stream, false, false);
        struct LayerBuild
        {
            int layers;
            NiNode* root;
            int children;
        } build;
        build.root = kModel.GetObject3D();
        parent->AddObject(m_pRootNode, true);
        build.layers = 0;
        build.children = build.root->FUN_00453470();
        for (int i = 0; i < build.children; ++i)
        {
            if (build.root->FUN_0043b4a0(i)->vfn_18())
            {
                m_pCloudLayerGeometry[i] = (NiGeometry*)build.root->FUN_0043b4a0(i);
                m_pRootNode->AddObject(m_pCloudLayerGeometry[i], true);
                ++build.layers;
            }
        }
        SetCloudCount(build.layers);
    }
}

// @fnv 0x006340e0
void Clouds::SetCloudCount(int count)
{
    if (count > 4)
        count = 4;
    m_usCloudCount = (unsigned short)count;
}

struct FUN_00634870_shell : public Sky
{
    bool GetWeatherUpdateFlag();
};

// @fnv 0x00634870
bool FUN_00634870_shell::GetWeatherUpdateFlag()
{
    return (0 < (*(unsigned int*)((char*)this + 0x118) & 3));
}

struct FUN_00634890_shell : public Sky
{
    SkyTextureManager* GetTextureManager();
};

// @fnv 0x00634890
SkyTextureManager* FUN_00634890_shell::GetTextureManager()
{
    return reinterpret_cast<SkyTextureManager*>(reinterpret_cast<char*>(this) + 0x114);
}

struct FUN_00634900_shell : public SkyShaderProperty
{
    void SetTextureFile(void*);
};

struct NiFixedString_access : public NiFixedString
{
    operator char const*() const;
};

// Assigns the NiFixedString at aFilename to the BSStringT<char> at offset 0x74 of this shader property.
// @fnv 0x00634900
void FUN_00634900_shell::SetTextureFile(void* aFilename)
{
    *(BSStringT<char>*)((char*)this + 0x74) = *(const NiFixedString_access*)aFilename;
}

struct NiTexture;
struct FUN_009c8680_shell : public SkyShaderProperty
{
    NiTexture* FUN_009c8680();
};

// @fnv 0x009c8680
NiTexture* FUN_009c8680_shell::FUN_009c8680()
{
    return (NiTexture*)((BSStringT<char>*)((char*)this + 0x70))->operator const char*();
}

struct P3
{
    void Set(float, float, float);
};

struct FUN_00633e00
{
    P3 m;
    void Init();
};

// Initializes the object's m member by setting it to (0, 0, 0).
// @fnv 0x00633e00
void FUN_00633e00::Init()
{
    m.Set(0.0f, 0.0f, 0.0f);
}

void _Deallocate(void*);
struct S_00633dd0
{
    void FUN_00633e30();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00633e30, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00633dd0
void* S_00633dd0::DestroyIfFlagged(unsigned int flags)
{
    FUN_00633e30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct SkyObjectBase633e30
{
    virtual void Slot00();
    NiNode* m_pTreeNode;
    ~SkyObjectBase633e30();
};

struct FUN_00633e30 : SkyObjectBase633e30
{
    NiPointer<NiGeometry> m_clouds[4];
    NiPointer<NiTexture> m_transitionTextures[4];
    void FUN_00633d90();
    void ClearTransTextures();
    ~FUN_00633e30();
};

// Destructor that calls FUN_00633d90 and ClearTransTextures before returning.
// @fnv 0x00633e30
FUN_00633e30::~FUN_00633e30()
{
    FUN_00633d90();
    ClearTransTextures();
}

// fallout_shared/sky/clouds_decls.h: declares NiFixedString, NiColor, RgbaColor, NiProperty, NiTimeController and more
#ifndef FNV_CLOUDS_DECLS_H
#define FNV_CLOUDS_DECLS_H

class NiNode;
class NiGeometry;
class NiTexture;
class Sky;
class TESWeather;
class NiProperty;
class SkyShaderProperty;
class NiTimeController;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen, sMaxLen;
    BSStringT();
    ~BSStringT();
    BSStringT& operator=(const T*);
    BSStringT& operator+=(const T*);
    operator const T*() const;
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
class NiColor
{
  public:
    float r, g, b;
};
class RgbaColor
{
  public:
    float r, g, b, a;
    RgbaColor(float, float, float, float);
};
class NiProperty
{
};
class NiTimeController
{
  public:
    int FUN_00441110();
};
class NiObjectNET
{
  public:
    NiTimeController* GetControllers() const;
};
class NiAVObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual NiGeometry* vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
};
class NiGeometry : public NiAVObject
{
  public:
    NiObjectNET* FUN_0050d100();
    NiProperty* GetProperty(int);
    void FUN_00450f90(bool);
};
class CloudsColorController : public NiTimeController
{
  public:
    unsigned char layoutPadding[0x60];
    RgbaColor color;
};
class SkyShaderProperty : public NiProperty
{
  public:
    void SetTexture(NiTexture*);
    void SetTextureFile(const NiFixedString&);
    void FUN_0051b8c0(float);
    void FUN_00bae930(NiTexture*);
    NiTexture* FUN_009c8680();
};
class TESTexture1024
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual const char* vfn_18();
    unsigned int GetModelLength() const;
    const char* GetTextureResourceName();
};
class TESWeather
{
  public:
    TESTexture1024* GetCloudTexture(int);
    float GetCloudLayerSpeed(int, float, float);
};
class Sky
{
  public:
    TESWeather* FUN_0044edb0();
    TESWeather* FUN_00825c00();
    int FUN_00476c90();
    float GetCurrentWeatherPct();
    float GetFieldCC();
    bool GetWeatherUpdateFlag();
    void GetTextureManager();
};
class SkyObject
{
  public:
    void** m_ppVirtualMethodTable;
    NiPointer<NiNode> m_pRootNode;
    void Initialize(NiNode*);
    void Update(Sky*, float);
};
class Clouds : public SkyObject
{
  public:
    NiPointer<NiGeometry> m_pCloudLayerGeometry[4];
    NiPointer<NiTexture> m_pCloudLayerTexture[4];
    NiColor pColors[4];
    unsigned short m_usCloudCount;
    bool bForceUpdate;
    void Initialize(NiNode*);
    void Update(Sky*, float);
    int GetOffset58();
    NiColor& GetPointAt(int);
    void SetCloudCount(int);
};
union SETTING_VALUE
{
    float f;
    int i;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT_GameSettingCollection_ DAT_011cca6c;
struct NiRTTI;
extern NiRTTI DAT_012005b8;
SkyShaderProperty* FUN_00653270(const NiRTTI*, NiProperty*);
void AddToFloatArray(unsigned short, float);
class SkyTextureManager
{
  public:
    static void LoadTextureFromPath(NiPointer<NiTexture>*, const char*);
};
class BSShaderManager
{
  public:
    static void GetTexture(const char*, bool, NiPointer<NiTexture>&, bool, bool);
};

class NiNode : public NiAVObject
{
  public:
    virtual void AddObject(NiAVObject*, bool);
    int FUN_00453470();
    NiAVObject* FUN_0043b4a0(int);
};
class NiStream
{
  public:
    virtual ~NiStream();
    unsigned char layoutPadding[0x5c0];
    bool FUN_00c3a8a0(const char*, bool);
};
class BSNodeReferences;
class BSStream : public NiStream
{
  public:
    void* m_pObjectNameMap;
    NiPointer<BSNodeReferences> m_spNodeReferences;
    BSStream();
    virtual ~BSStream();
};
class Model
{
  public:
    char* pFilename;
    int BackgroundTask, m_iActualRefCount;
    NiPointer<NiNode> m_spNode;
    Model(const char*, BSStream*, bool, bool);
    ~Model();
    NiNode* GetObject3D();
};
typedef char clouds_stream_size[(sizeof(BSStream) == 0x5cc) ? 1 : -1];
typedef char clouds_model_size[(sizeof(Model) == 0x10) ? 1 : -1];
#endif

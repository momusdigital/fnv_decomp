// fallout_shared/facegen/bsfacegenmanager_decls.h: declares FaceGenCoordinates, BSFaceGenManager, BGSTextureModel, TESRace, TESForm and more

struct FaceGenCoordinates
{
    char data[0x60];
};
class BSFaceGenModelMap;
template <class T> class BSStringT;
class BSFaceGenManager
{
  public:
    char pad[8];
    FaceGenCoordinates coords;
    char rest[0x1194 - 8 - 0x60];
    BSFaceGenModelMap* cache;
    static BSFaceGenManager* GetFaceGenManager();
    static FaceGenCoordinates* GetFaceGenCoordinates();
    static BSFaceGenModelMap* GetModelMap();
    static void NormalizeFaceGenValues(float*, unsigned int);
    static void InitializeFaceGenCoordinates(FaceGenCoordinates*);
    static char* BuildFaceGenPartPath(char*, int);
    static void ApplyFaceGenValues(float*, unsigned int, bool);
    static const char* BuildFaceGenModelPath(BSStringT<char>&, const char*);
};
extern BSFaceGenManager* DAT_011d59e8;
void InitializeSystem();
extern "C" void* memset(void*, int, unsigned int);
struct BGSTextureModel
{
    char data[24];
};
class TESRace
{
  public:
    char pad[0x3c8];
    BGSTextureModel models[2];
    BGSTextureModel* GetBodyTextureModel(int);
};
enum ENUM_FORM_ID
{
    NPC_FORM = 42
};
enum SEX
{
    SEX_NONE = -1,
    SEX_MALE = 0,
    SEX_FEMALE = 1
};
class TESForm
{
  public:
    ENUM_FORM_ID GetFormType() const;
};
class TESActorBaseData
{
  public:
    char data[0x20];
    bool GetFlag(unsigned int) const;
};
class TESActorBase : public TESForm
{
  public:
    char pad[0x30];
    TESActorBaseData base;
    SEX GetSex() const;
};
class FaceGenCoordArray
{
  public:
    char data[0x20];
    void resize(unsigned int, bool);
};
extern "C" char* __insecure_strcpy(char*, const char*);
char* FUN_00ec6380(char*, const char*);
extern const char* DAT_0119b734[2];
extern float DAT_01016970;
template <class T> class NiPointer
{
  public:
    T* p;
    ~NiPointer();
};
class NiTexture;
class FaceGenPaletteBase
{
  public:
    char pad[0x2c];
    ~FaceGenPaletteBase();
};
class FaceGenPaletteEntry : public FaceGenPaletteBase
{
  public:
    NiPointer<NiTexture> first, second;
    ~FaceGenPaletteEntry();
};

extern const char DAT_0104aad0[];

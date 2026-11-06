// gamebryo2.2/corelibs/nimain/nifixedstring_facegen.h: declares NiMemObject, TESRecipe, NiAVObject, FaceGenImageView, FaceGenColor and more
#ifndef FNV_NIFIXEDSTRING_FACEGEN_H
#define FNV_NIFIXEDSTRING_FACEGEN_H

class NiTexture;
template <class T> class NiPointer
{
  public:
    T* pointer;
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
    NiPointer& operator=(T*);
};
template <class T> class BSStringT
{
  public:
    T* text;
    unsigned short length, capacity;
    const T* String();
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class TESRecipe
{
  public:
    void SetSkill(int);
    void SetSkillLevel(int);
};
class NiNode;
class NiAVObject
{
  public:
    NiNode* GetParent();
};
class FaceGenImage;
struct FaceGenImageView
{
    float* pixels;
    unsigned int stride;
    FaceGenImageView();
    float* FUN_0064dbd0();
};
struct FaceGenColor
{
    float r, g, b, a;
};
struct FaceGenModeParameters
{
    int weight;
    unsigned int stride;
};
struct FaceGenChannelData
{
    int scale;
    const signed char* row;
};
struct FaceGenOutputData
{
    float multiplier;
    float* output;
};
class FaceGenImage : public NiMemObject
{
  public:
    unsigned char data[44];
    FaceGenImage(unsigned int);
    FaceGenImage* GetOrConvertImage();
    void FUN_0064db50(unsigned int, FaceGenColor*);
    FaceGenImageView _Doraise();
};
class NiTexture
{
  public:
    NiTexture* FUN_0064ceb0(float, float, float, void*);
};
struct TextureChannel
{
    unsigned char data[24];
    const signed char* FUN_0065cc70(unsigned int);
};
struct TextureRow
{
    float scale;
    unsigned int width, height, rowPadding;
    TextureChannel rows[3];
};
struct TextureBasis
{
    unsigned char data[24];
    unsigned int FUN_0065cea0();
    TextureRow* FUN_0065cec0(unsigned int);
};
struct FaceGenTextureFile
{
    ~FaceGenTextureFile();
    static void operator delete(void*);
    unsigned int flags;
    TextureBasis basis[2];
};
struct FaceGenCoordinateValue
{
    const float* values;
    unsigned int stride;
    const float* FUN_00629ab0();
};
struct FaceGenCoordinateBasis
{
    unsigned char data[32];
    FaceGenCoordinateValue FUN_0060b370(unsigned int, unsigned int);
};
struct FaceGenCoordinates
{
    unsigned char data[64];
    FaceGenCoordinateBasis basis[2];
};
struct BSFaceGenTexture
{
    BSStringT<char> m_kEGTFileName;
    FaceGenTextureFile* m_pTextureData;
    unsigned int GetCharacterSex();
};
class BSFaceGenModel
{
  public:
    void* vtable;
    unsigned int refCount;
    void* m_pGeometryModel;
    BSFaceGenTexture* m_kTextureSlots;
    bool ApplyTextureCoordinate(FaceGenCoordinates*, NiPointer<NiTexture>&, unsigned int);
    void ClearTextureData();
};
struct BSFaceGenManager
{
    static FaceGenCoordinates* GetFaceGenCoordinates();
};
NiTexture* GetFaceGenManagerValue();
FaceGenTextureFile* FUN_00659780(const char*);
bool LoadEGTData(BSFaceGenModel*);
void LockFaceGenAccess();
void UnlockFaceGenAccess();
int Warning(const char*, ...);
void ReportAssertionViolation(const char*, unsigned int);
extern double DAT_010231d8;
extern float DAT_01065b9c;
extern float DAT_01065b98;
struct NiPoint3StartupTable;
extern NiPoint3StartupTable gNiPoint3StartupSrc;
extern "C" void* __cdecl memset(void*, int, unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete[](void*);
#endif

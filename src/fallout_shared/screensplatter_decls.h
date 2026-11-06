// fallout_shared/screensplatter_decls.h: declares ScreenSplatter, NiNode, ProcessLists, AutoMemContext, GraphicsRenderer and more
#ifndef FNV_SCREENSPLATTER_PRIVATE_H
#define FNV_SCREENSPLATTER_PRIVATE_H


class FUN_00622c80;

class ScreenSplatter
{
  public:
    static void Init();
    static void Clear();
    static FUN_00622c80* Activate(float time, bool enabled);
};

class NiAVObject;
template <class T> class NiPointer;
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* operator->() const;
    NiPointer& operator=(NiAVObject* object);
};

class NiUpdateData;
class NiNode
{
  public:
    void Update(const NiUpdateData& data);
    void RemoveAllChildren();
};

class FUN_00622c80
{
  public:
    unsigned char data[0x3b0];
    static void* operator new(unsigned int size);
    static void operator delete(void*);
    FUN_00622c80(float value, unsigned int id);
};

unsigned int FUN_005dbe10();
float FUN_00622ba0();
float FUN_00622bb0();

extern unsigned char DAT_011c7834;
extern unsigned int DAT_011c7828;
extern NiPointer<NiAVObject> DAT_011c786c;
extern FUN_00622c80* DAT_011cc200;
extern FUN_00622c80* DAT_011cc1fc;

enum MEM_CONTEXT
{
    MEM_CONTEXT_UNKNOWN = 0
};
struct SETTING_VALUE;
class INISettingCollection;
template <class T> class SettingT;
class ProcessLists
{
  public:
    unsigned char* GetLifeStateControlFlag();
};

class AutoMemContext
{
  public:
    unsigned int data;
    AutoMemContext(MEM_CONTEXT context, bool enabled, const char* file, int line);
    ~AutoMemContext();
};

class GraphicsRenderer
{
  public:
    unsigned int GetRenderTargetWidth();
    unsigned int GetRenderTargetHeight();
};
class NiRenderer;
NiRenderer* FUN_0043c4b0();

class NiMemObject
{
  public:
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
};

class FUN_00a712f0 : public NiMemObject
{
  public:
    unsigned char data[0x114];
    FUN_00a712f0();
};

class NiUpdateData
{
  public:
    float value;
    unsigned int first;
    unsigned int second;
    NiUpdateData(float value, bool first, bool second);
};

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float x, float y, float z);
    static const NiPoint3 ZERO;
};

class NiFrustum
{
  public:
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
    NiFrustum(bool enabled);
};

struct ScreenSplatterRawData
{
    float value;
    unsigned int first, second;
};
struct ScreenSplatterRawFrustum
{
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
};
struct ScreenSplatterInitLocals
{
    float aspect;
    ScreenSplatterRawFrustum frustum;
    GraphicsRenderer* renderer;
    ScreenSplatterRawData firstData;
    ScreenSplatterRawData secondData;
};

class NiCamera
{
  public:
    bool AimAt(const NiPoint3& point, const NiPoint3& up);
    void UpdateViewFrustum(const NiFrustum& frustum);
};

class NiAVObject
{
  public:
    void FUN_00440460(const NiPoint3& point);
};

class NiFixedString;
class NiExtraData
{
  public:
    void SetName(const NiFixedString& name);
};

class NiSortAdjustNode : public NiMemObject
{
  public:
    unsigned char data[0xac];
    NiSortAdjustNode(unsigned int copyMembers);
};

class SettingT_GameSettingCollection_
{
  public:
    const char* String();
};

class NiTexture;
class SkyTextureManager
{
  public:
    static void LoadTextureFromPath(NiPointer<NiTexture>* texture, const char* path);
};

extern ProcessLists DAT_011c784c;
extern NiPointer<NiAVObject> DAT_011c7840;
extern NiPointer<NiTexture> DAT_011c7860;
extern NiPointer<NiTexture> DAT_011c7864;
extern NiPointer<NiTexture> DAT_011c7868;
extern unsigned char DAT_011f941e;
extern NiPoint3 DAT_011a9478;
extern char DAT_01022ab8;
extern float DAT_01022960;
extern float DAT_0102295c;
extern float DAT_01022958;
extern float DAT_01016248;
extern double DAT_01011598;
extern const double runtimeInitializationDouble1;
extern float DAT_01189550;
extern float DAT_01189554;
extern unsigned char DAT_011ce918;
extern unsigned char DAT_011ce284;
extern unsigned char DAT_011cede8;

#endif

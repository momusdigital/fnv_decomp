// fallout_shared/screencustomsplatter_decls.h: declares PortalEntry, BSPortal, ScreenCustomSplatter, NiPoint3, NiUpdateData and more
#ifndef SCREENCUSTOMSPLATTER_DECLS_H
#define SCREENCUSTOMSPLATTER_DECLS_H

union SETTING_VALUE;
class PortalEntry
{
  public:
    void FUN_00c5dea0();
};
template <class T> class PortalArray
{
  public:
    T* data;
    unsigned short capacity;
    unsigned short count;
};
class BSPortal
{
  public:
    char pad[0xa0];
    PortalArray<PortalEntry*> entries;
    ~BSPortal();
};
class ScreenCustomSplatter
{
  public:
    static void Clear();
    static void Init();
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float, float, float);
    static const NiPoint3 ZERO;
};
class NiUpdateData
{
  public:
    float time;
    bool a, b;
    unsigned short pad1;
    unsigned int pad2;
    NiUpdateData(float, bool, bool);
};
class NiFrustum
{
  public:
    float left, right, top, bottom, nearPlane, farPlane;
    bool ortho;
    unsigned char pad1;
    unsigned short pad2;
    NiFrustum(bool);
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class NiAVObject : public NiMemObject
{
  public:
    void FUN_00440460(const NiPoint3&);
    void Update(NiUpdateData&);
};
class NiNode : public NiAVObject
{
  public:
    char bytes[0xac];
    NiNode(unsigned short);
    void RemoveAllChildren();
};
class NiCamera : public NiAVObject
{
  public:
    void UpdateViewFrustum(const NiFrustum&);
    bool AimAt(const NiPoint3&, const NiPoint3&);
};
// Unidentified PC camera constructor at 0x00a712f0.
class FUN_00a712f0 : public NiCamera
{
  public:
    char bytes[0x114];
    FUN_00a712f0();
};
class NiTexture;
template <class T> class NiPointer
{
  public:
    T* p;
    T* operator->() const;
    NiPointer<T>& operator=(T*);
};
class SettingT_GameSettingCollection_
{
  public:
    const char* String();
    SETTING_VALUE* Float();
};
class SkyTextureManager
{
  public:
    static void LoadTextureFromPath(NiPointer<NiTexture>*, const char*);
};
extern unsigned int DAT_011c77dc;
extern unsigned char DAT_011c77e8, DAT_011c77e9;
extern float DAT_011c77ec;
extern NiPointer<NiNode> DAT_011c7810;
extern NiPointer<NiTexture> DAT_011c7804, DAT_011c7808, DAT_011c780c;
extern SettingT_GameSettingCollection_ DAT_011ce284, DAT_011ce918, DAT_011cede8;
extern bool DAT_011f941e;

enum MEM_CONTEXT
{
    MEM_CONTEXT_SCREEN = 7
};
class AutoMemContext
{
  public:
    int state;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
union SETTING_VALUE
{
    bool b;
    float f;
};
class INISettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
class NiRenderer;
class GraphicsRenderer
{
  public:
    unsigned int GetRenderTargetWidth();
    unsigned int GetRenderTargetHeight();
};
NiRenderer* FUN_0043c4b0();
extern SettingT<INISettingCollection> DAT_011c77f4;
extern NiPointer<NiNode> DAT_011c781c;
extern SettingT_GameSettingCollection_ DAT_011cfc2c;
extern NiPoint3 DAT_011a9478;
extern float DAT_01022960, DAT_01016248, DAT_0102295c, DAT_01022958, DAT_01189500, DAT_01189504;
extern double DAT_01011598, DAT_01011588;

#endif

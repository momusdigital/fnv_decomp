// fallout_shared/facegen/bsfacegenmodel_decls.h: declares NiPoint3, AutoMemContext, FaceGenMorphTarget, FaceGenMorphData, FaceGenCoordinate and more
#ifndef BSFACEGENMODEL_DECLS_H
#define BSFACEGENMODEL_DECLS_H

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
};
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete[](void*);
enum MEM_CONTEXT
{
    FaceGenMeshContext = 56,
    FaceGenTextureContext = 57
};
class AutoMemContext
{
  public:
    MEM_CONTEXT oldContext;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
enum HAIR_PART
{
    HAIR_PART_NONE = -1,
    HAIR_PART_NORMAL = 0,
    HAIR_PART_HAT = 1
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short size, capacity;
    const T* String();
    unsigned int Length();
    bool Set(const T*, unsigned int);
};
template <class T> class FaceGenIterator
{
  public:
    T* current;
    void* container;
    T& operator*() const;
    FaceGenIterator operator++(int);
};
template <class T> class FaceGenVector
{
  public:
    void* proxy;
    T* first;
    T* last;
    T* end;
    unsigned int allocator;
    unsigned int state;
    unsigned int size() const;
    T& operator[](unsigned int);
    FaceGenIterator<T> begin();
};
template <class T> class ThreeComponentVector
{
  public:
    T x, y, z;
};
class FaceGenMorphTarget
{
  public:
    float scale;
    FaceGenVector<ThreeComponentVector<short> > kVertexPositionLocal;
};
class FaceGenMorphData
{
  public:
    unsigned int state;
    FaceGenVector<FaceGenMorphTarget> modes[2];
    FaceGenMorphData(const char*);
};
class FaceGenCoordinate
{
  public:
    unsigned int data[8];
    FaceGenIterator<float> operator()(unsigned int, int);
};
class GeometryBufferView
{
  public:
    void* data;
    unsigned int stride;
    unsigned int count;
    GeometryBufferView();
    unsigned int* FUN_00717e50();
    void* FUN_00559450();
    void FUN_00534570(unsigned int, NiPoint3&);
    void FUN_0065b390(unsigned int, const NiPoint3&);
};
class NiGeometryData
{
  public:
    bool HasAdditionalGeometryData(unsigned int);
    void FUN_00a67410(GeometryBufferView&);
    unsigned int FUN_00457b80();
    void SetDirtyFlags(unsigned int);
    void FUN_00a673d0();
};
class NiTriBasedGeom;
class NiFixedString
{
  public:
    const char* data;
    operator const char*() const;
};
class NiUpdateData
{
  public:
    float time;
    unsigned int flags;
    bool updateControllers;
    NiUpdateData(float, bool, bool);
};
class TESQuest;
class BGSQuestObjective
{
  public:
    void SetOwnerQuest(TESQuest*);
};
class NiSkinInstance;
class NiAVObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual NiTriBasedGeom* IsTriBasedGeom();
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
    virtual NiAVObject* vfn_94();
    NiFixedString& GetName();
    void UpdateSceneObject();
    void Update(NiUpdateData&);
    void RemoveProperty(unsigned int);
    void ClearAnimationControllers();
    void UpdateModelBound();
};
class NiNode : public NiAVObject
{
  public:
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(int);
};
class NiTriBasedGeom : public NiAVObject
{
  public:
    NiGeometryData* FUN_005495f0();
    unsigned short FUN_00456650();
    void* FUN_0049ec60();
    NiSkinInstance* FUN_0043fad0();
    void FUN_004902f0(bool);
    void FUN_0065a620(bool);
};
class BSFaceGenBaseMorphExtraData
{
  public:
    NiPoint3* FUN_0084e3a0();
    unsigned int GetPointerByFlag(unsigned int);
};
template <class T> class NiPointer
{
  public:
    T* pointer;
    operator T*() const;
    T* operator->() const;
    NiPointer& operator=(T*);
};
class BSFaceGenMorphData
{
  public:
    void* vtable;
    unsigned int refCount;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class FaceGenTriData
{
  public:
    unsigned int data[60];
    FaceGenTriData();
    ~FaceGenTriData();
    unsigned int FUN_0065a5a0();
    unsigned int FUN_0065c700();
    NiPoint3& FUN_0065c720(unsigned int);
};
class BSFaceGenMorphDataHair : public BSFaceGenMorphData
{
  public:
    void* hairMorph;
    BSFaceGenMorphDataHair(FaceGenTriData*);
};
class BSFaceGenMorphDataHead : public BSFaceGenMorphData
{
  public:
    void* expression;
    void* modifier;
    void* phoneme;
    void* custom;
    BSFaceGenMorphDataHead(FaceGenTriData*);
};
class FaceGenGeometryModel
{
  public:
    BSStringT<char> m_kEGMFileName;
    FaceGenMorphData* m_pModelData;
    NiPointer<NiNode> m_spModelRoot;
    NiPointer<NiTriBasedGeom> m_pRenderedNodeEntry;
    NiPoint3* pAdditionalVertices;
    unsigned int m_uiAdditionalVertexCount;
    NiPointer<BSFaceGenMorphData> m_spFaceMorphData;
    int BackgroundTask;
    FaceGenGeometryModel();
};
struct FaceGenTextureFile;
class BSFaceGenTexture
{
  public:
    BSStringT<char> EGTFileName;
    FaceGenTextureFile* m_pTextureData;
    BSFaceGenTexture();
};
class BSFaceGenModel
{
  public:
    void* vtable;
    unsigned int refCount;
    FaceGenGeometryModel* m_pGeometryModel;
    BSFaceGenTexture* m_kTextureSlots;
    bool LoadModelMesh(const char*, const char*, const char*, HAIR_PART, bool);
    bool LoadFaceGenTexture();
    bool LoadFaceGenTexture(const char*);
    static NiAVObject* GetFaceGenModelNode(NiAVObject*);
    bool ApplyFaceGenMorphs(FaceGenCoordinate*, NiTriBasedGeom*, bool);
};
class BSFaceGenManager
{
  public:
    static FaceGenCoordinate* GetFaceGenCoordinates();
};
void FUN_00652140();
void FUN_00652190();
bool FUN_00651f70(BSFaceGenModel*);
BSFaceGenBaseMorphExtraData* GetExtraDataIfPresent(NiTriBasedGeom*);
class CloningProcess
{
  public:
    unsigned int state[7];
    CloningProcess(float);
    ~CloningProcess();
};
class ModelLoader
{
  public:
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
};
class TES
{
  public:
    NiNode* CreateDeepCopySameTextures(NiNode*, CloningProcess&);
};
class NarrowString
{
  public:
    unsigned int text[7];
    NarrowString(const char*);
    ~NarrowString();
};
extern ModelLoader* g_modelLoader;
extern TES* g_TES;
extern const char* DAT_0119b734[];
int __cdecl FUN_00404dc0(const char*, const char*);
int Warning(const char*, ...);
int FUN_004af340();
bool FUN_00ab5ec0(const NarrowString&, FaceGenTriData*);
FaceGenTextureFile* FUN_00659780(const char*);
NiAVObject* GetGeomExtraData(NiAVObject*);
#endif

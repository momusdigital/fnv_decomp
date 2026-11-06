// fallout_shared/modelloader_verified_packet.h: declares QueuedReference, QueuedCharacter, QueuedPlayer, NiRenderer, LocationDescriptor and more
#ifndef FNV_MODELLOADER_VERIFIED_PACKET_H
#define FNV_MODELLOADER_VERIFIED_PACKET_H


class QueuedReference
{
  public:
    void Attach();
    void FUN_00441b80();
    void FUN_004414f0();
};

class QueuedCharacter : public QueuedReference
{
  public:
    void Attach();
};

class QueuedPlayer : public QueuedCharacter
{
  public:
    void Attach();
};

class BSFileEntry;
class Archive;
class TESObjectREFR;
class QueuedFile;
class BGSPerkEntry;
class CountingSemaphore;
class BSStream;
class NiNode;
struct NiPoint3;

class NiRenderer
{
  public:
    static NiRenderer* ms_pRenderer;
    char _pdbpad_1[7];
    char m_spAccum_pad7_pad7[4];
    void* m_pCamera;
    void* m_pActiveRenderTargetGroup;
    char m_acRendererDataB[4];
    char _pdbpad_18[104];
    char m_acRendererDataC[128];
    char m_acRendererDataD[128];
    char m_acRendererDataE[128];
    int m_iRendererState;
    unsigned int m_uiRendererFlags;
    bool m_bRendererFlagA;
    bool m_bRendererFlagB;
    char _pdbpad_20a[118];
};

enum ARCHIVE_TYPE
{
    ARCHIVE_TYPE_DEFAULT = 0
};

enum IO_TASK_PRIORITY
{
    IO_TASK_PRIORITY_DEFAULT = 0
};

class LocationDescriptor
{
  public:
    BSFileEntry* SetLocRef();
};

class ArchiveManager
{
  public:
    unsigned int FindArchiveForFileEntry();
    static Archive* FindArchiveForFileEntry(BSFileEntry*, ARCHIVE_TYPE);
};

class Archive : public ArchiveManager
{
};

class QueuedTexture : public LocationDescriptor
{
  public:
    unsigned char GetFileIndex();
};

class BGSTerrainChunkLoadTask : public LocationDescriptor
{
  public:
    unsigned char GetFileIndex();
};

template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList<T>* GetNext();
    void RemoveHead();
};

class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};

class ModelLoader
{
  public:
    bool EnqueueFile(const char*, IO_TASK_PRIORITY, QueuedFile*);
    void QueueFileList(BSSimpleList<const char*>*, IO_TASK_PRIORITY, QueuedFile*, const char*);
    void ProcessQueuedFile();
    static void UpdateLoadingStatusCallback();
    void UpdateLoadingStatus();
    void DispatchAnimIdle(QueuedFile*);
    void UpdateReferenceNode(TESObjectREFR*, NiNode*);
    void UpdateModelNode(NiNode*);
    void FUN_004431d0();
    void FUN_00443220();
    void FUN_00449940();
    void FUN_004499a0();
};

template <class T> class NiPointer
{
  public:
    NiPointer(T*);
    operator T*() const;
    NiPointer<T>& operator=(T*);
    ~NiPointer();
};

class Model
{
  public:
    void* owned;
    char prefix[8];
    NiPointer<NiNode> node;
    Model(const char*, BSStream*, bool, bool);
    ~Model();
    void LoadModelFromStream(const char*, BSStream*, bool, bool);
};

class CountingSemaphore
{
  public:
    void Signal();
};

struct QueueKFListLocals
{
    void* deletePointer;
    const char* pathToQueue;
    char path[260];
};

extern int __cdecl strcat_s(char*, unsigned int, const char*);
extern void __cdecl operator delete(void*);

class InventoryStackRecord;
class IOTask
{
  public:
    static unsigned char GetPriorityFromKey(__int64& key);
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30(BSSimpleList<InventoryStackRecord*>*);
    void FUN_00c3d440();
    void NotifyParents();
    bool FUN_00449110();
    bool FUN_00449130();
    bool FUN_0043caa0();
    bool FUN_0043caf0();
    IO_TASK_PRIORITY GetIOTaskPriority();
    void AddToPostProcessQueue();
};
class QueuedFile : public IOTask
{
};
class QueuedModel : public QueuedFile
{
  public:
    void GenerateKey();
    void DispatchToManager();
    void OnChildCompletion();
};
class QueuedKF : public QueuedFile
{
  public:
    void DispatchToManager();
};
class QueuedHead : public QueuedFile
{
  public:
    void DispatchToManager();
    void OnChildCompletion();
};
class QueuedAnimIdle : public QueuedFile
{
  public:
    void OnChildCompletion();
    void ProcessLoadedAnimIdle();
};
class IOManager
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
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
    virtual void vfn_48(IOTask*);
};
extern IOManager* DAT_01202d98;
extern ModelLoader* g_modelLoader;
class TESNPC;
class BSFaceGenManager
{
  public:
    static void QueueHeadModelLoad(TESNPC*, IO_TASK_PRIORITY, QueuedFile*);
};
class TESSpellList
{
  public:
    BSSimpleList<InventoryStackRecord*>* GetOffsetC();
};
class SoundPlaybackHandle;
template <class K, class V> class NiTPointerMap
{
  public:
    bool IsEmpty();
};
class KFModel;
class AnimIdle
{
  public:
    void Loaded(KFModel*);
};
class NiFixedString;
class NiExtraData
{
  public:
    bool FUN_00448a40();
};
class NiAVObject
{
  public:
    NiExtraData* GetExtraData(const NiFixedString&);
    NiNode* GetParent();
    NiPoint3& FUN_0043c490();
    int FUN_0043c470();
    NiNode* GetParentNode();
};
class NiNode : public NiAVObject
{
};
class TESObjectREFR
{
  public:
    bool FUN_00448a20();
};
const NiFixedString& FUN_00448a80();
extern NiFixedString* DAT_01202ddc;

#include "modelloader_added_types.h"

#include "modelloader_selector_same_tu_types.h"
#include "modelloader_addon_declarations.h"
#include "modelloader_package_declarations.h"
#include "modelloader_weapon_declarations.h"
#include "modelloader_activator_declarations.h"
#endif

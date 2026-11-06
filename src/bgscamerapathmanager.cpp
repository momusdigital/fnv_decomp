// bgscamerapathmanager.cpp: CameraPathManager (8 functions)

#include "CameraPathManager.h"
void* __cdecl operator new(unsigned int);

// Constructs a NiTPrimitiveArray<BGSCameraPath*> by forwarding maxSize and growBy to the NiTArray base constructor.
// @fnv 0x0058bc30
template <>
NiTPrimitiveArray<BGSCameraPath*>::NiTPrimitiveArray(unsigned int maxSize, unsigned int growBy)
    : NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >(maxSize, growBy)
{}

// @fnv 0x0058b850
void CameraPathManager::InitializeCameraPaths()
{
    if (!ms_pDefaultCameraPath)
    {
        ms_pDefaultCameraPath = dynamic_cast<BGSCameraPath*>(TESForm::GetFormByID(0x16));
        if (!ms_pDefaultCameraPath)
        {
            ms_pDefaultCameraPath = new BGSCameraPath;
            ms_pDefaultCameraPath->SetRefID(0x16, true);
            ms_pDefaultCameraPath->SetEditorID_AtRuntime("DefaultCameraPath");
            m_kCameraPathArray.SetFormAtIndex(m_kCameraPathArray.GetSize(), ms_pDefaultCameraPath);
        }
    }
}

// @fnv 0x0058b960
BGSCameraPath* CameraPathManager::GetTextureResourcePath()
{
    return ms_pDefaultCameraPath;
}

// @fnv 0x0058b970
void CameraPathManager::UpdateCameraPaths()
{
    unsigned int size = m_kCameraPathList.GetSize();
    for (unsigned int i = 0; i < size; ++i)
    {
        BGSCameraPath* path = m_kCameraPathList.GetAt(i);
        if (path && !path->IsFormInitialized())
        {
            path->InitItem();
            if (path->HasMissingPathArray())
            {
                BGSCameraPath* empty = 0;
                m_kCameraPathList.SetAt(i, empty);
            }
        }
        else
        {
            BGSCameraPath* empty = 0;
            m_kCameraPathList.SetAt(i, empty);
        }
    }
    m_kCameraPathList.Compact();
}

struct NiFormArray_008b2010
{
    TESForm* GetFormAt(unsigned int i);
};
struct TESFile
{
    const char* GetName();
};
struct FUN_0058b510_shell
{
    TESFile* GetCameraPathToPlay(unsigned int a, unsigned int b);
};
struct FUN_0058b470_shell
{
    bool IsFlag80Set();
};
bool __fastcall _ref_008256d0(const char* s);
struct FUN_0058bb50_shell : NiFormArray
{
    TESFile* GetCameraPathToPlay(unsigned int arg1, unsigned int arg2);
};
// @fnv 0x0058bb50
TESFile* FUN_0058bb50_shell::GetCameraPathToPlay(unsigned int arg1, unsigned int arg2)
{
    TESFile* pFile = 0;
    if (arg1)
    {
        unsigned int count = reinterpret_cast<TESForm*>(this)->GetFormID();
        for (unsigned int i = 0; i < count; ++i)
        {
            TESForm* form = reinterpret_cast<NiFormArray_008b2010*>(this)->GetFormAt(i);
            if (form)
                pFile = reinterpret_cast<FUN_0058b510_shell*>(form)->GetCameraPathToPlay(arg1, arg2);
            if (pFile)
                break;
        }
    }
    if (pFile)
    {
        if (reinterpret_cast<FUN_0058b470_shell*>(pFile)->IsFlag80Set())
        {
            if (!_ref_008256d0(pFile->GetName()))
                pFile = 0;
        }
    }
    return pFile;
}

extern int DAT_01032748;
struct ActorCombatGroup;
template <> struct NiTMallocInterface<ActorCombatGroup*>
{
    static void __cdecl Deallocate(ActorCombatGroup** p);
};
struct FUN_0058bc00_obj
{
    void* vtbl;
    ActorCombatGroup** data;
};
// Sets the object's vtbl to DAT_01032748 and deallocates its data array via NiTMallocInterface.
// @fnv 0x0058bc00
void __fastcall FUN_0058bc00(FUN_0058bc00_obj* self)
{
    self->vtbl = &DAT_01032748;
    NiTMallocInterface<ActorCombatGroup*>::Deallocate(self->data);
}

struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int index);
};

struct GlobalObject_00869b10
{
    void RemoveAll();
};

struct FUN_00863db0_class
{
    void ClearItems();
};

struct FUN_0058ba40_shell : public CameraPathManager
{
    void DestroyCameraPaths();
};

// @fnv 0x0058ba40
void FUN_0058ba40_shell::DestroyCameraPaths()
{
    unsigned int count = reinterpret_cast<TESForm*>(this)->GetFormID();
    for (unsigned int index = 0; index < count; ++index)
    {
        BGSCameraPath* path =
            dynamic_cast<BGSCameraPath*>(reinterpret_cast<NiFormArray_008b2010*>(this)->GetFormAt(index));
        delete path;
    }

    unsigned int childCount = reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0x18)->GetSize();
    for (unsigned int childIndex = 0; childIndex < childCount; ++childIndex)
    {
        BGSCameraPath* childPath = reinterpret_cast<BGSCameraPath*>(
            *reinterpret_cast<Arr*>(reinterpret_cast<unsigned char*>(this) + 0x18)->GetAt(childIndex));
        delete childPath;
    }

    reinterpret_cast<GlobalObject_00869b10*>(reinterpret_cast<unsigned char*>(this) + 0x18)->RemoveAll();
    CameraPathManager::ms_pDefaultCameraPath = 0;
    reinterpret_cast<FUN_00863db0_class*>(this)->ClearItems();
}

struct SceneNode
{
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual int IsRootCandidate();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    SceneNode(unsigned short childCount);
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int size);
    SceneNode* FUN_009611e0();
    void SetWorldTranslate(void* arg);
};

void* __fastcall FUN_0045bb80(SceneNode* node);

template <class T> struct NodePtr
{
    T* m_pObject;
    NodePtr<T>& operator=(T* object);
    operator T*() const;
};

extern bool DAT_011e07c3;

struct FUN_0058ccf0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    NodePtr<SceneNode> node64;
    int unk68;
    int unk6C;
    NodePtr<SceneNode> node70;
    bool IsFlag2Set() const;
    void SetSceneNode(SceneNode* node);
};

// @fnv 0x0058ccf0
void FUN_0058ccf0_Class::SetSceneNode(SceneNode* node)
{
    if (node == 0)
    {
        node64 = 0;
        node70 = 0;
        return;
    }
    if (IsFlag2Set())
    {
        node64 = node;
    }
    else
    {
        node64 = new SceneNode(0);
        ((SceneNode*)node64)->SetWorldTranslate(FUN_0045bb80(node));
    }
    SceneNode* root = node;
    while (root != 0 && root->IsRootCandidate() == 0)
    {
        root = root->FUN_009611e0();
    }
    if (root != 0)
    {
        node70 = root;
    }
    else
    {
        node70 = node;
    }
    DAT_011e07c3 = true;
}

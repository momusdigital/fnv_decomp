// fallout_shared/bgscamerapath.cpp: BGSCameraPath, CameraPathCompare, CameraPathClone, CameraPath and more (24 functions)

#include "bgscamerapath.h"

// @fnv 0x0058a620
void BGSCameraPath::ResetFormData()
{
    data.cFlags = 0;
    m_pFirstCameraPath = 0;
    m_pSecondCameraPath = 0;
}

// @fnv 0x005f4bb0
void BGSCameraPath::AssignParentPath(BGSCameraPath* parent)
{
    m_pFirstCameraPath = parent;
}

// @fnv 0x0058a650
void BGSCameraPath::ClearData()
{
    GetConditions()->InitializeConditionItems();
    m_kCameraShotList.RemoveAll();
}

// @fnv 0x0058a380
BGSCameraPath::BGSCameraPath()
{
    SetFormType(ENUM_FORM_ID_CPTH_ID);
    m_pPathArray = 0;
    ResetFormData();
}

class BGSCameraShot : public TESForm
{
};
extern int __cdecl Warning(const char* format, ...);
extern "C" const char fnv_MessageWithName[];
extern "C" const char fnv_MessageWithFormID[];

// Initializes conditions and walks the shot list, resolving each form ID to a BGSCameraShot and removing entries that fail to resolve, warning for each.
// @fnv 0x0058ad90
void BGSCameraPath::InitItem()
{
    if (IsFormInitialized())
        return;

    ((TESConditionInit*)GetConditions())->InitItem(this);

    BSSimpleList<BGSCameraShot*>* pShotNode = GetShotList();
    BSSimpleList<BGSCameraShot*>* previous = 0;
    struct InitItemLocals
    {
        BGSCameraShot* cameraShot;
        unsigned int formID;
    } shotEntry;
    while (pShotNode && !pShotNode->IsEmpty())
    {
        shotEntry.formID = (unsigned int)pShotNode->GetItem();
        TESForm::RemapFormIDForFile(shotEntry.formID, GetFile(-1));
        shotEntry.cameraShot = dynamic_cast<BGSCameraShot*>(TESForm::GetFormByID(shotEntry.formID));
        if (!shotEntry.cameraShot)
        {
            if (previous)
            {
                previous->Remove(pShotNode->GetItem());
                pShotNode = previous->GetNext();
            }
            else
                pShotNode->RemoveHead();

            if (HasNameForWarning())
                Warning(fnv_MessageWithName, shotEntry.formID, GetName());
            else
                Warning(fnv_MessageWithFormID, shotEntry.formID, GetFormID());
        }
        else
        {
            pShotNode->SetItem(shotEntry.cameraShot);
            previous = pShotNode;
            pShotNode = pShotNode->GetNext();
        }
    }

    SetInitializationState(true);
}

extern "C" const char fnv_MessageMultipleNext[];

// @fnv 0x0058b190
void BGSCameraPath::SetPathArray(NiFormArray* paths)
{
    if (!paths)
        return;

    struct FixNextLocals
    {
        unsigned int index;
        unsigned int invalidCount;
        unsigned int nextIndex;
        unsigned int currentIndex;
        BGSCameraPath* nextPath;
        unsigned int pathCount;
    } locals;

    locals.invalidCount = 0;
    locals.currentIndex = 0xffffffff;
    locals.pathCount = paths->GetSize();
    locals.nextIndex = 0xffffffff;
    locals.nextPath = 0;
    locals.index = 0;

    for (; locals.index < locals.pathCount; ++locals.index)
    {
        BGSCameraPath* path = dynamic_cast<BGSCameraPath*>(paths->FUN_00877a30(locals.index));
        if (path)
        {
            if (path == this)
                locals.currentIndex = locals.index;
            else if (path->GetPrevPath() == this)
            {
                if (!locals.nextPath)
                {
                    locals.nextPath = path;
                    locals.nextIndex = locals.index;
                }
                else
                {
                    BSStringT<char> name;
                    GetDebugName(&name);
                    Warning(fnv_MessageMultipleNext, name.String());
                }
            }
        }
        else
            ++locals.invalidCount;
    }

    if (locals.currentIndex != 0xffffffff && locals.nextIndex != 0xffffffff &&
        locals.nextIndex != locals.currentIndex + 1)
    {
        unsigned int oldSize = 0;
        paths->SetSize(locals.nextIndex, &oldSize);
        paths->Compact();
        if (locals.nextIndex < locals.currentIndex)
            ++locals.invalidCount;
        locals.currentIndex -= locals.invalidCount;
        paths->SetFormAtIndex(locals.currentIndex + 1, locals.nextPath);
        paths->Compact();
        locals.nextPath->SetPathArray(paths);
    }
}

extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
extern "C" void* __cdecl memset(void*, int, unsigned int);
// @fnv 0x0058a9e0
bool BGSCameraPath::Load(TESFile* file)
{
    int chunk;
    if (((CameraFileFormType*)file)->GetTESForm() != 0x5c)
        return false;
    if (this == GetTextureResourcePath())
    {
        struct
        {
            unsigned int index;
            NiFormArray* paths;
        } removalInfo;
        removalInfo.paths = DAT_011ca700->GetPathArray();
        removalInfo.index = removalInfo.paths->GetIndexOfForm(this);
        if (removalInfo.index != 0xffffffff)
        {
            ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)removalInfo.paths)
                ->RemoveAt(removalInfo.index);
            removalInfo.paths->Compact();
        }
    }
    LoadRecordHeader(file);
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            ((BGSImpactData*)this)->ReadTypedData(file, &data, 1);
            break;
        case 0x41445443:
            ((CameraCondition*)GetConditions())->Load(file);
            break;
        case 0x4d414e53: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            ((BSSimpleList<ScriptVariableInfo*>*)&m_kCameraShotList)->AddTail((ScriptVariableInfo*)formID);
            break;
        }
        case 0x4d414e41: {
            FUN_005a71d0 parentInfo;
            memset(&parentInfo, 0, 8);
            file->GetChunkData(&parentInfo, 8);
            if (file->IsEndianConversionRequired())
                parentInfo.FUN_00462230();
            m_pFirstCameraPath = (BGSCameraPath*)parentInfo.parent;
            m_pSecondCameraPath = (BGSCameraPath*)parentInfo.previous;
            DAT_011ca700->AddCameraPath(this);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

extern "C" const char fnv_MessageMissingParent[];
extern "C" const char fnv_MessageMissingPrevious[];
extern "C" const char fnv_MessageMissingArray[];
// Resolves the parent and previous camera paths by form ID, warns if missing, and inserts this path into the parent's or global path array at the computed index.
// @fnv 0x0058aef0
bool BGSCameraPath::HasMissingPathArray()
{
    struct ParentLocals
    {
        BGSCameraPath* parent;
        unsigned int formID;
        unsigned int index;
        BGSCameraPath* previous;
        NiFormArray* paths;
        char pad0, pad1, pad2;
        bool success;
    } locals;
    locals.success = true;
    locals.parent = 0;
    locals.formID = (unsigned int)m_pFirstCameraPath;
    if (locals.formID)
    {
        TESForm::RemapFormIDForFile(locals.formID, GetFile(-1));
        locals.parent = dynamic_cast<BGSCameraPath*>(TESForm::GetFormByID(locals.formID));
        if (!locals.parent)
        {
            BSStringT<char> name;
            GetDebugName(&name);
            Warning(fnv_MessageMissingParent, locals.formID, name.String());
            locals.success = false;
        }
        AssignParentPath(locals.parent);
    }
    locals.previous = 0;
    locals.formID = (unsigned int)m_pSecondCameraPath;
    if (locals.formID)
    {
        TESForm::RemapFormIDForFile(locals.formID, GetFile(-1));
        locals.previous = dynamic_cast<BGSCameraPath*>(TESForm::GetFormByID(locals.formID));
        if (!locals.previous)
        {
            BSStringT<char> name;
            GetDebugName(&name);
            Warning(fnv_MessageMissingPrevious, locals.formID, name.String());
            locals.success = false;
        }
        ((BGSAcousticSpace*)this)->SetDawnSound((TESSound*)locals.previous);
    }
    locals.index = 0;
    locals.paths = 0;
    if (locals.parent)
        locals.paths = locals.parent->GetEntryObject();
    else
        locals.paths = DAT_011ca700->GetPathArray();
    if (locals.paths)
    {
        if (locals.previous)
        {
            unsigned int previousIndex = locals.paths->GetIndexOfForm(locals.previous);
            if (previousIndex != 0xffffffff)
                ++previousIndex;
            locals.index = previousIndex;
        }
        if (locals.index == 0xffffffff || IsDeleted())
            locals.index = locals.paths->GetSize() + 1;
        locals.paths->SetFormAtIndex(locals.index, this);
        SetPathArray(locals.paths);
    }
    else
    {
        BSStringT<char> name;
        GetDebugName(&name);
        Warning(fnv_MessageMissingArray, name.String());
        locals.success = false;
    }
    return locals.success;
}

extern int DAT_010326fc;
struct NTL
{
    void NiTLargePrimitiveArray(unsigned int, unsigned int);
};
// Calls NiTLargePrimitiveArray(0, 1) on self, stores &DAT_010326fc at self, and returns self.
// @fnv 0x0058b3f0
void* __fastcall FUN_0058b3f0(void* self)
{
    ((NTL*)self)->NiTLargePrimitiveArray(0, 1);
    *(int**)self = &DAT_010326fc;
    return self;
}

struct FUN_0058b600_shell
{
    char pad[0x2c];
    TESForm* m_field_2c;
};

// Returns the form ID of the TESForm stored at m_field_2c, or 0 if it is null.
// @fnv 0x0058b600
unsigned int __fastcall GetStoredFormID(FUN_0058b600_shell* thisPtr)
{
    unsigned int result = 0;
    if (thisPtr->m_field_2c)
        result = thisPtr->m_field_2c->GetFormID();
    return result;
}

struct S_58a420
{
    void FUN_0058a450();
    void* FUN_0058a420(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_0058a450, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0058a420
void* S_58a420::FUN_0058a420(unsigned int flags)
{
    FUN_0058a450();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct Unk58
{
    void FUN_0058b450();
    void* FUN_0058b420(unsigned int);
};
void __cdecl _Deallocate(void*);
// Calls FUN_0058b450, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0058b420
void* Unk58::FUN_0058b420(unsigned int flags)
{
    FUN_0058b450();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_00464f40_shell
{
    void __thiscall FUN_00464f40();
    void __thiscall FUN_0058b450();
};

void __thiscall FUN_00464f40_shell::FUN_00464f40()
{}

// @fnv 0x0058b450
void __thiscall FUN_00464f40_shell::FUN_0058b450()
{
    FUN_00464f40();
}

struct FUN_0058b4f0_shell
{
    bool __thiscall IsFlag2Set();
};
// @fnv 0x0058b4f0
bool __thiscall FUN_0058b4f0_shell::IsFlag2Set()
{
    if (((const unsigned char*)this)[0x28] & 2)
        return true;
    return false;
}

struct FUN_0058b470_shell
{
    unsigned char _pad[0x28];
    unsigned char cFlags;
    bool IsFlag80Set();
};

// Returns true when the cFlags bit 0x80 is set, otherwise false.
// @fnv 0x0058b470
bool FUN_0058b470_shell::IsFlag80Set()
{
    if (cFlags & 0x80)
        return true;
    else
        return false;
}

struct S0058b4a0
{
    unsigned char _pad[0x28];
    unsigned char _flag;
    bool GetZoomDefault();
};
// Returns true when neither bit 0 nor bit 1 of _flag is set, otherwise false.
// @fnv 0x0058b4a0
bool S0058b4a0::GetZoomDefault()
{
    if (_flag & 1 || _flag & 2)
        return false;
    return true;
}

struct FUN_0058b4d0_shell
{
    unsigned char pad[0x28];
    unsigned char flags28;
    bool FUN_0058b4d0();
};

// @fnv 0x0058b4d0
bool FUN_0058b4d0_shell::FUN_0058b4d0()
{
    if (flags28 & 1)
        return true;
    return false;
}

struct IdentifierHistoryEntry
{
    unsigned int m_uiCurrentId;
    unsigned int ipreviousID;
};

struct Script
{
    char* GetData();
};

struct TESConditionSave
{
    void ProcessItems();
};

struct FUN_004855a0
{
    void M();
};

struct FUN_00485680
{
    void M();
};

struct BSSimpleList_shell
{
    void** GetItem();
    BSSimpleList_shell* GetNext();
    bool _ref_008256d0();
};

struct FUN_00485e00_shell
{
    void __thiscall __SaveData(int, int);
};

bool _FUN_00401500();
void _FUN_00485990(unsigned int, void*, unsigned int);
void _FUN_00485910(unsigned int, unsigned int);

struct FUN_0058ac10_shell : public BGSCameraPath
{
    void FUN_0058ac10();
};

// @fnv 0x0058ac10
void FUN_0058ac10_shell::FUN_0058ac10()
{
    BSSimpleList_shell* pShotList;
    IdentifierHistoryEntry ids;

    {
        BGSCameraPath* pprev;
        BGSCameraShot* pshot;
        unsigned int shotFormID;

        reinterpret_cast<FUN_004855a0*>(this)->M();
        reinterpret_cast<TESConditionSave*>(GetConditions())->ProcessItems();

        memset(&ids, 0, 8);

        if (reinterpret_cast<Script*>(this)->GetData())
            ids.m_uiCurrentId = reinterpret_cast<TESForm*>(reinterpret_cast<Script*>(this)->GetData())->GetFormID();

        if (!IsDeleted())
        {
            pprev = GetPrevPath();
            while (pprev && pprev->IsDeleted())
                pprev = pprev->GetPrevPath();

            if (pprev)
                ids.ipreviousID = pprev->GetFormID();
        }

        if (_FUN_00401500())
            reinterpret_cast<FUN_005a71d0*>(&ids)->FUN_00462230();

        _FUN_00485990(0x4d414e41, &ids, 8);

        if (_FUN_00401500())
            reinterpret_cast<FUN_005a71d0*>(&ids)->FUN_00462230();

        if (_FUN_00401500())
            reinterpret_cast<TESForm*>(&data)->TESForm::ClearData();

        reinterpret_cast<FUN_00485e00_shell*>(this)->__SaveData(reinterpret_cast<int>(&data), 1);

        if (_FUN_00401500())
            reinterpret_cast<TESForm*>(&data)->TESForm::ClearData();

        pShotList = reinterpret_cast<BSSimpleList_shell*>(reinterpret_cast<TESForm*>(this)->TESForm::GetName());

        while (pShotList && !pShotList->_ref_008256d0())
        {
            pshot = reinterpret_cast<BGSCameraShot*>(pShotList->GetItem()[0]);
            pShotList = pShotList->GetNext();
            shotFormID = pshot->GetFormID();
            _FUN_00485910(0x4d414e53, shotFormID);
        }
    }

    reinterpret_cast<FUN_00485680*>(this)->M();
}

void* __cdecl __memcpy(void*, const void*, unsigned int);

struct Cond_58a680
{
    void Copy(PerkEntryConditionSet* src, void* arg);
};

struct CameraPath_58a680 : public BGSCameraPath
{
    void CopyCommonData(TESForm* src);
    void CopyFromForm(TESForm* apForm);
};

// Casts apForm to BGSCameraPath, copies common data, conditions, data and the shot list into this camera path.
// @fnv 0x0058a680
void CameraPath_58a680::CopyFromForm(TESForm* apForm)
{
    BGSCameraPath* p = dynamic_cast<BGSCameraPath*>(apForm);
    if (!p)
        return;
    CopyCommonData(p);
    ((Cond_58a680*)GetConditions())->Copy(p->GetConditions(), 0);
    __memcpy(&data, &p->data, sizeof(CameraShotData));
    BSSimpleList<BGSCameraShot*>* h = 0;
    m_kCameraShotList.RemoveAll();
    h = p->GetShotList();
    while (h && !h->IsEmpty())
    {
        BGSCameraShot* e = h->GetItem();
        h = h->GetNext();
        m_kCameraShotList.AddTail(e);
    }
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

struct FormCompareStub
{
    bool IsDifferentForm(BGSCameraPath* pathForm);
};
struct ConditionCompareStub
{
    bool IsDifferent(PerkEntryConditionSet* pathForm);
};

struct CameraPathCompare : BGSCameraPath
{
    bool FUN_0058a750(TESForm* form);
};

// Compares this camera path against another form's camera path: base form, conditions, a data byte, and shot lists; returns true if any differ.
// @fnv 0x0058a750
bool CameraPathCompare::FUN_0058a750(TESForm* form)
{
    BGSCameraPath* pathForm = dynamic_cast<BGSCameraPath*>(form);
    if (!pathForm)
        return true;
    if (((FormCompareStub*)this)->IsDifferentForm(pathForm))
        return true;
    if (((ConditionCompareStub*)GetConditions())->IsDifferent(pathForm->GetConditions()))
        return true;
    if (memcmp(&data, &pathForm->data, 1))
        return true;
    BSSimpleList<BGSCameraShot*>* pShotNode = GetShotList();
    BSSimpleList<BGSCameraShot*>* pOtherShotNode = pathForm->GetShotList();
    while (pOtherShotNode && !pOtherShotNode->IsEmpty())
    {
        if (!pShotNode || pShotNode->GetItem() != pOtherShotNode->GetItem())
            return true;
        pOtherShotNode = pOtherShotNode->GetNext();
        pShotNode = pShotNode->GetNext();
    }
    if (pShotNode && !pShotNode->IsEmpty())
        return true;
    return false;
}

class FUN_0058a450;

class PathFormArray
{
  public:
    virtual ~PathFormArray();
    unsigned int GetIndexOfForm(TESForm* form);
    FUN_0058a450* GetFormAt(unsigned int index);
    TESTopicInfo* RemoveAt(unsigned int index);
    void Compact();
};

class DataHandlerStub
{
  public:
    bool IsLoading();
};
extern DataHandlerStub* g_dataHandler;

class CameraPathFormBase : public TESForm
{
  public:
    virtual ~CameraPathFormBase();
};

class FUN_0058a450 : public CameraPathFormBase
{
  public:
    PerkEntryConditionSet Conditions;
    BSSimpleList<BGSCameraShot*> m_kCameraShotList;
    CameraShotData data;
    unsigned char pad29;
    unsigned char pad2a;
    unsigned char pad2b;
    PathFormArray* m_pPathArray;
    FUN_0058a450* m_pFirstCameraPath;
    FUN_0058a450* m_pSecondCameraPath;

    virtual ~FUN_0058a450();
    virtual void ClearData();
    FUN_0058a450* GetParentPath();
    void RemoveChild(FUN_0058a450* child);
    FUN_0058a450* GetPrevPathStub();
    void SetPrevPathStub(FUN_0058a450* prev);
    unsigned int GetChildCount();
    FUN_0058a450* GetChildAt(unsigned int index);
    void SetParentStub(FUN_0058a450* parent);
};

// Clears data, unlinks the path from its parent or the global path array while not loading, then deletes all children and the child array.
// @fnv 0x0058a450
FUN_0058a450::~FUN_0058a450()
{
    ClearData();
    if (!g_dataHandler->IsLoading())
    {
        if (GetParentPath())
        {
            GetParentPath()->RemoveChild(this);
        }
        else
        {
            PathFormArray* pArray = (PathFormArray*)DAT_011ca700->GetPathArray();
            if (pArray)
            {
                unsigned int uiPathIndex = pArray->GetIndexOfForm(this);
                if (uiPathIndex != -1)
                {
                    FUN_0058a450* pNextPath = pArray->GetFormAt(uiPathIndex + 1);
                    if (pNextPath)
                    {
                        pNextPath->SetPrevPathStub(GetPrevPathStub());
                    }
                    pArray->RemoveAt(uiPathIndex);
                    pArray->Compact();
                }
            }
        }
    }
    if (m_pPathArray)
    {
        unsigned int ItemUpdateArray = GetChildCount();
        if (ItemUpdateArray)
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
            {
                FUN_0058a450* pChildPath = GetChildAt(i);
                pChildPath->SetParentStub(0);
                delete pChildPath;
            }
        }
        delete m_pPathArray;
    }
}

struct CameraPathMap
{
    bool GetAt(BGSCameraPath* key, BGSCameraPath*& value);
};

struct CameraPathArrayResize
{
    void Resize(unsigned int size);
};

struct CameraPathClone : public BGSCameraPath
{
    TESForm* CreateBaseClone(bool abPersist, CameraPathMap* apMap);
    void SetParentPath(BGSCameraPath* apParent);
    void SetPrevPathForm(BGSCameraPath* apPrev);
    TESForm* CreateDuplicateForm(bool abPersist, CameraPathMap* apMap);
};

// Clones the base camera path, remaps its parent and previous paths through apMap, and copies the child form array when present.
// @fnv 0x0058a870
TESForm* CameraPathClone::CreateDuplicateForm(bool abPersist, CameraPathMap* apMap)
{
    CameraPathClone* pClone_ =
        static_cast<CameraPathClone*>(dynamic_cast<BGSCameraPath*>(CreateBaseClone(abPersist, apMap)));
    BGSCameraPath* pFound4 = 0;
    if (!apMap->GetAt(m_pFirstCameraPath, pFound4) || !pFound4)
        pFound4 = m_pFirstCameraPath;
    BGSCameraPath* pParent3 = pFound4;
    pClone_->SetParentPath(pParent3);
    pFound4 = 0;
    if (!apMap->GetAt(m_pSecondCameraPath, pFound4) || !pFound4)
        pFound4 = m_pSecondCameraPath;
    BGSCameraPath* pPrev = pFound4;
    pClone_->SetPrevPathForm(pPrev);
    if (m_pPathArray)
    {
        m_pPathArray->Compact();
        unsigned int uiCount5 = m_pPathArray->GetSize();
        NiFormArray* pArray = pClone_->GetEntryObject();
        ((CameraPathArrayResize*)pArray)->Resize(uiCount5);
        TESForm* pLastVal = 0;
        for (unsigned int i5 = 0; i5 < uiCount5; i5++)
        {
            TESForm* pChildA = m_pPathArray->FUN_00877a30(i5);
            TESForm* pNewChildB1 = pChildA->CreateForm((void*)(int)abPersist, apMap);
            unsigned int uiValueC2 = (unsigned int)pNewChildB1;
            pArray->SetSize(i5, &uiValueC2);
            pLastVal = pNewChildB1;
        }
    }
    return pClone_;
}

struct CameraResponse
{
    bool __thiscall FUN_00680c30();
};
struct CameraFlag
{
    bool __thiscall FUN_008256d0();
};
struct CameraPath : FUN_0058b600_shell
{
    bool __thiscall FUN_00440d80();
    CameraResponse* __thiscall FUN_00500940(unsigned int context, unsigned int flags);
    CameraFlag* __thiscall FUN_00891170();
    CameraPath* __thiscall GetCameraPathAt(unsigned int index);
    CameraPath* __thiscall GetCameraPathToPlay(unsigned int context, unsigned int flags);
};

// @fnv 0x0058b510
CameraPath* CameraPath::GetCameraPathToPlay(unsigned int context, unsigned int flags)
{
    CameraPath* result = 0;
    if (!FUN_00440d80())
    {
        if (FUN_00500940(context, flags)->FUN_00680c30())
        {
            if (reinterpret_cast<FUN_0058b470_shell*>(this)->IsFlag80Set() || !FUN_00891170()->FUN_008256d0())
            {
                result = this;
            }
            unsigned int count = GetStoredFormID(this);
            if (count != 0)
            {
                CameraPath* descendant = 0;
                for (unsigned int i = 0; i < count; ++i)
                {
                    CameraPath* child = GetCameraPathAt(i);
                    if (child != 0)
                        descendant = child->GetCameraPathToPlay(context, flags);
                    if (descendant != 0)
                        break;
                }
                if (descendant != 0)
                    result = descendant;
            }
        }
    }
    return result;
}

namespace fnv_0058b350 {
class FUN_0058b3f0
{
  public:
    FUN_0058b3f0();
    void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    unsigned int unk0, unk4, unk8, unkC, unk10, unk14;
};
class OwnerX
{
  public:
    unsigned int unk[11];
    FUN_0058b3f0* m_pEntryObject;
    FUN_0058b3f0* GetEntryObject();
};
// Returns m_pEntryObject, allocating a new FUN_0058b3f0 and storing it in m_pEntryObject if it was null.
// @fnv 0x0058b350
FUN_0058b3f0* OwnerX::GetEntryObject()
{
    return m_pEntryObject ? m_pEntryObject : (m_pEntryObject = new FUN_0058b3f0);
}
}  // namespace fnv_0058b350

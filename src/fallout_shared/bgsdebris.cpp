// fallout_shared/bgsdebris.cpp: BGSDebris, MagicItemForm, BGSDebris_shell2, BGSDebris_cmp (19 functions)

#include "bgsdebris_decls.h"

// @fnv 0x00409140
BSSimpleList<DebrisModelEntry*>* BGSDebris::GetDataList()
{
    return &DataList;
}

// Iterates DataList, deallocating each entry's path and deleting the entry, then removes the head until the list is empty.
// @fnv 0x004f9e30
void BGSDebris::ClearData()
{
    BSSimpleList<DebrisModelEntry*>* list = &DataList;
    while (!DataList.IsEmpty())
    {
        DebrisModelEntry* data = list->GetItem();
        if (data)
        {
            char* path = data->path;
            Deallocate(path);
            delete data;
        }
        DataList.RemoveHead();
    }
}

// Iterates the debris data list and asks g_modelLoader to load each entry's non-empty path into its model with the given priority and file.
// @fnv 0x004fa970
void BGSDebris::Preload(int priority, void* file)
{
    BSSimpleList<DebrisModelEntry*>* list = GetDataList();
    while (list)
    {
        DebrisModelEntry* data = list->GetItem();
        if (data && data->path && BSStringLength(data->path))
            g_modelLoader->QueueFullWithNullResult(data->path, &data->model, priority, file, 1, 1, 0, 0);
        list = list->GetNext();
    }
}

// @fnv 0x004fa500
DebrisModelEntry* BGSDebris::AddDebrisModel(char chance, const char* path, char flags)
{
    if (!path || !chance)
        return 0;
    unsigned int length = BSStringLength(path);
    if (length)
    {
        DebrisModelEntry* data = new DebrisModelEntry;
        data->chance = chance;
        data->SetFileName(path);
        data->flags = flags;
        InsertDebrisIfValid(data);
        return data;
    }
    return 0;
}

// Reads a BGSDebris record from a TESFile, handling EDID, OBND, DATA and MODL chunks, and returns false if the form type is not 0x52.
// @fnv 0x004f9f10
bool BGSDebris::Load(TESFile* file)
{
    // Local identifiers preserve MSVC9 stack-slot ordering.
    unsigned char v0 = file->GetTESForm();
    if (v0 != 0x52)
        return false;
    ClearData();
    LoadRecordHeader(file);
    SetInitializationState(false);
    DebrisModelEntry* v1 = 0;  // most recently loaded debris entry
    while (int v2 = file->GetChunkID())
    {
        switch (v2)
        {
        case 0x44494445: {
            char* v3 = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(v3, 512);
            SetEditorID_AtRuntime(v3);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144: {
            // v5: chunk size; v6: allocation; v4: parse cursor; v7: end.
            unsigned int v5 = file->GetChunkSize();
            unsigned char* v6 = new unsigned char[v5];
            unsigned char* v4 = v6;
            file->GetChunkData(v4, v5);
            unsigned char* v7 = v4 + v5;
            if (v4 < v7)
            {
                // v10: chance; v9: model path; v8: flags.
                unsigned char v10 = *v4;
                v4++;
                const char* v9 = (const char*)v4;
                v4 += BSStringLength((const char*)v4) + 1;
                unsigned char v8 = 0;
                if (v4 < v7)
                {
                    v8 = *v4;
                    v4++;
                }
                v1 = AddDebrisModel(v10, v9, v8);
            }
            delete[] v6;
            break;
        }
        case 0x54444f4d:
            if (v1)
                v1->model.Load(file, this, v1->path);
            else
            {
                Warning(DAT_01024988, GetName(), GetFormID());
                FileEntryList v11;
                v11.Load(file, this, DAT_01015890);
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

#include "bgsdebris_magic.h"
// Constructs a MagicItemForm object; the body is empty.
// @fnv 0x00409190
MagicItemForm::MagicItemForm()
{}

extern int DAT_01024970;

struct FUN_004f9d90_helper
{
    void* vftable;
    FUN_004f9d90_helper* ctor();
};

// @fnv 0x004f9d90
FUN_004f9d90_helper* FUN_004f9d90_helper::ctor()
{
    reinterpret_cast<BaseFormComponent*>(this)->BaseFormComponent::BaseFormComponent();
    this->vftable = &DAT_01024970;
    return this;
}

int __cdecl FUN_00408b20(char const*, char const*);

struct S_004fa4b0
{
    char c;
    const char* s;
};

// Compares two entries by their char field, returning -1 or 1, and otherwise compares their string fields via FUN_00408b20.
// @fnv 0x004fa4b0
int __cdecl FUN_004fa4b0(const S_004fa4b0* apLeft, const S_004fa4b0* apRight)
{
    if (apLeft->c > apRight->c)
    {
        return -1;
    }
    else if (apLeft->c < apRight->c)
    {
        return 1;
    }
    else
    {
        return FUN_00408b20(apLeft->s, apRight->s);
    }
}

// Initializes the object: sets byte 0 to 10, byte 1 to 0, int at offset 4 to 0, constructs the object at offset 8, and returns pThis.
// @fnv 0x004fa5e0
void* __fastcall FUN_004fa5e0(char* pObject)
{
    pObject[0] = 10;
    pObject[1] = 0;
    *reinterpret_cast<int*>(pObject + 4) = 0;
    reinterpret_cast<FileEntryList*>(pObject + 8)->FileEntryList::FileEntryList();
    return pObject;
}

struct DebrisData
{
    char c;
    char pad[3];
    const char* p;
};
struct DArg
{
    DebrisData* d;
};
struct AEList
{
    void Insert(DebrisData*, int(__cdecl*)(DebrisData*, DebrisData*));
};
int __cdecl FUN_004fa4b0(DebrisData*, DebrisData*);
unsigned int __cdecl BSStringLength(const char*);
// Checks that a.d, its flag, and its string are non-empty, then inserts a.d into the AEList at self+0x1c and returns true; otherwise returns false.
// @fnv 0x004fa610
bool __fastcall InsertDebrisIfValid(char* self, DArg aDebrisArg)
{
    if (!aDebrisArg.d || !aDebrisArg.d->c || !aDebrisArg.d->p || !BSStringLength(aDebrisArg.d->p))
        return false;
    ((AEList*)(self + 0x1c))->Insert(aDebrisArg.d, FUN_004fa4b0);
    return true;
}

struct FUN_004fa670_shell : public DebrisModelEntry
{
    void SetFileName(char*);
};

void* __cdecl operator new(unsigned int);
template <class T> unsigned int __cdecl BSStringLength(T const*);

class TaskQueueInterface
{
  public:
    static void __cdecl CopyStringToBuffer(char*, unsigned int, char const*);
};

// @fnv 0x004fa670
void FUN_004fa670_shell::SetFileName(char* apFileName)
{
    if (*(char**)((char*)this + 4))
    {
        delete *(char**)((char*)this + 4);
    }
    *(char**)((char*)this + 4) = 0;
    if (apFileName)
    {
        int iFilenameLen = BSStringLength<char>(apFileName) + 1;
        *(char**)((char*)this + 4) = new char[iFilenameLen];
        TaskQueueInterface::CopyStringToBuffer(*(char**)((char*)this + 4), iFilenameLen, apFileName);
    }
}

struct SL
{
    SL();
    ~SL();
};
class FUN_004f9cd0 : public TESForm, public BGSPreloadable
{
  public:
    SL DataList;
    FUN_004f9cd0();
    virtual ~FUN_004f9cd0();
};
// Sets the form type to 0x52 and clears the form data.
// @fnv 0x004f9cd0
FUN_004f9cd0::FUN_004f9cd0()
{
    SetFormType(static_cast<ENUM_FORM_ID>(0x52));
    TESForm::ClearData();
}

struct FUN_004fa950_shell
{
    int __thiscall IsFlagSet();
};

// @fnv 0x004fa950
int __thiscall FUN_004fa950_shell::IsFlagSet()
{
    return (*reinterpret_cast<signed char*>(this + 1) & 1);
}

void _Deallocate(void*);
struct S_004f9d60
{
    void FUN_004f9db0();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_004f9db0, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x004f9d60
void* S_004f9d60::DestroyIfFlagged(unsigned int flags)
{
    FUN_004f9db0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};

struct BGSDebris_shell : BGSDebris
{
    void CopyFromDebris(TESForm* source);
};

// @fnv 0x004fa2f0
void BGSDebris_shell::CopyFromDebris(TESForm* source)
{
    BGSDebris* debris2 = dynamic_cast<BGSDebris*>(source);
    if (!debris2)
        return;
    ClearData();
    ((FUN_005e78f0_t*)this)->FUN_004851b0(debris2);
    BSSimpleList<DebrisModelEntry*>* list = debris2->GetDataList();
    while (list)
    {
        DebrisModelEntry* data = list->GetItem();
        if (data)
            AddDebrisModel(data->chance, data->path, data->flags);
        list = list->GetNext();
    }
}

struct Vec3
{
    float x, y, z;
    Vec3();
    void Normalize();
};
struct DNode
{
    void** FUN_006815c0();
    DNode* FUN_00726070();
};
struct DItem
{
    char chance;
    char pad[3];
    void* model;
    unsigned char IsFlagSet();
};
struct DList
{
    DNode* FUN_00409140();
};
void* __cdecl FUN_00aa13e0(unsigned int);
struct DebrisObj
{
    char b[0x24];
    static void* operator new(unsigned int n)
    {
        return FUN_00aa13e0(n);
    }
    static void operator delete(void*, unsigned int);
    DebrisObj(void* a1, float f, void* m, int z, Vec3* pos, Vec3* v1, Vec3* v2, Vec3* v3, float s, int z1, int z2);
};
extern const float DAT_01012054;
extern const float DAT_010249d8;
extern const float DAT_01017b78;
extern const double DAT_01020758;
extern Vec3 DAT_011f426c;
float __cdecl FUN_00476b70(float, float);

void __cdecl FUN_006890b0(void* a1, float f, void* m, Vec3 v1, Vec3 v2, float s, int k, int z);
struct DNode2
{
};
struct BGSDebris_shell2 : BGSDebris
{
    void FUN_004fa6f0(void* a1, Vec3* pos, unsigned int count, float scale);
};

// @fnv 0x004fa6f0
void BGSDebris_shell2::FUN_004fa6f0(void* a1, Vec3* apPosition, unsigned int count, float scale)
{
    if (!a1)
        return;
    unsigned int i8 = 0;
    DNode* node_ = ((DList*)this)->FUN_00409140();
    while (node_)
    {
        DItem* d9 = (DItem*)*node_->FUN_006815c0();
        if (d9 && d9->model && d9->chance)
        {
            unsigned int n = d9->chance * count / 100;
            if (n == 0 && i8 < count)
                n = 1;
            for (unsigned int j3 = 0; j3 < n; j3++)
            {
                Vec3 v4;
                v4.x = FUN_00476b70(DAT_01012054, 1.0f);
                v4.y = FUN_00476b70(DAT_01012054, 1.0f);
                v4.z = FUN_00476b70(DAT_01012054, 1.0f);
                v4.Normalize();
                if (d9->IsFlagSet())
                {
                    Vec3 dir = DAT_011f426c;
                    DebrisObj* o3 =
                        new DebrisObj(a1, DAT_010249d8, d9->model, 0, apPosition, &v4, &dir, &dir, scale, 0, 0);
                    (void)o3;
                }
                else
                {
                    FUN_006890b0(a1, DAT_01017b78, d9->model, v4, *apPosition, (float)(scale * DAT_01020758), 7, 0);
                }
                i8++;
            }
        }
        node_ = node_->FUN_00726070();
    }
}

struct DebrisModel4fa
{
    void FUN_008d0600(int iType, int iValue);
};

struct DebrisEntry4fa
{
    char cChance;
    char cFlags;
    short sPad;
    char* pcPath;
    DebrisModel4fa kModel;
};

int __cdecl strcpy_s(char* pcDest, unsigned int uiSize, const char* pcSrc);
void __cdecl FUN_004856f0(unsigned int uiType, void* pvData, unsigned int uiSize);

struct FUN_004fa1a0_shell
{
    void FUN_004855a0();
    DNode* FUN_00409140();
    void FUN_00485680();
    void WriteDebrisEntries();
};

// @fnv 0x004fa1a0
void FUN_004fa1a0_shell::WriteDebrisEntries()
{
    FUN_004855a0();
    DNode* pkNode = FUN_00409140();
    while (pkNode)
    {
        DebrisEntry4fa* pkData = (DebrisEntry4fa*)*pkNode->FUN_006815c0();
        if (pkData && pkData->pcPath && BSStringLength(pkData->pcPath))
        {
            unsigned int uiSize = BSStringLength(pkData->pcPath) + 3;
            char* pTmpcBuffer = new char[uiSize];
            char* pcCur = pTmpcBuffer;
            *pcCur = pkData->cChance;
            pcCur++;
            strcpy_s(pcCur, uiSize, pkData->pcPath);
            pcCur += BSStringLength(pkData->pcPath) + 1;
            *pcCur = pkData->cFlags;
            pcCur++;
            FUN_004856f0('ATAD', pTmpcBuffer, uiSize);
            delete pTmpcBuffer;
            pkData->kModel.FUN_008d0600('TDOM', (int)pkData->pcPath);
        }
        pkNode = pkNode->FUN_00726070();
    }
    FUN_00485680();
}

int __cdecl FUN_00408b20(char const*, char const*);

struct DebrisListNode
{
    int GetCount();
    DebrisModelEntry** GetItemPtr();
    DebrisListNode* NextNode();
};

struct BGSDebris_cmp : BGSDebris
{
    DebrisListNode* DataListHead();
    bool FUN_004fa390(TESForm* form);
};

// Compares this debris list against another BGSDebris's list, returning true if counts, entries, chance, path or flags differ.
// @fnv 0x004fa390
bool BGSDebris_cmp::FUN_004fa390(TESForm* form)
{
    BGSDebris_cmp* other7 = (BGSDebris_cmp*)dynamic_cast<BGSDebris*>(form);
    if (!other7)
        return true;
    DebrisListNode* otherIter2 = other7->DataListHead();
    if (otherIter2->GetCount() != ((DebrisListNode*)&DataList)->GetCount())
        return true;
    DebrisListNode* iter = (DebrisListNode*)&DataList;
    while (otherIter2)
    {
        DebrisModelEntry* srcData = *otherIter2->GetItemPtr();
        DebrisModelEntry* dstData = *iter->GetItemPtr();
        if ((!srcData && dstData) || (srcData && !dstData))
            return true;
        if (srcData && dstData)
        {
            if (srcData->chance != dstData->chance)
                return true;
            if (FUN_00408b20(srcData->path, dstData->path))
                return true;
            if (srcData->flags != dstData->flags)
                return true;
        }
        iter = iter->NextNode();
        otherIter2 = otherIter2->NextNode();
    }
    return false;
}

struct FUN_004f9db0_Base : public TESForm
{
    virtual ~FUN_004f9db0_Base();
};

struct FUN_004f9db0 : public FUN_004f9db0_Base, public BGSPreloadable
{
    BSSimpleList<DebrisModelEntry*> DataList;
    virtual void ClearData();
    ~FUN_004f9db0();
};

// @fnv 0x004f9db0
FUN_004f9db0::~FUN_004f9db0()
{
    ClearData();
}

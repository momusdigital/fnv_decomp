// fallout_shared/tesmodellist.cpp: TESModelList, ActorValue, FileEntryListCollection, DelStandIn (16 functions)

#include "tesmodellist_types_TESModelList.h"
#include <new>

namespace ActorValue {
enum Index
{
    IndexPlaceholder = 0
};
bool __cdecl GetFlag(Index index, unsigned int flag);
}

class ActorValueOwner
{
  public:
    virtual int GetActorValue(ActorValue::Index index);
};

class TESModelListCopyTarget
{
  public:
    virtual void vfn_00() = 0;
    virtual void vfn_04() = 0;
    virtual void vfn_08() = 0;
    virtual void vfn_0c() = 0;
    virtual unsigned short vfn_10() = 0;
};

// @fnv 0x004753a0
FileEntryListCollection* FileEntryListCollection::ClearData(unsigned int flags)
{
    FUN_00475220();
    if (flags & 1)
        ::operator delete(this);
    return this;
}

// Deletes every filename string in the list at offset 4, then calls ClearAndDeleteArray on the object at offset 12.
// @fnv 0x00489b40
void TESModelList::ClearComponent()
{
    while (!((BSSimpleList<const char*>*)((char*)this + 4))->IsEmpty())
    {
        const char* filenameToDelete;
        const char* filename;
        filenameToDelete = ((BSSimpleList<const char*>*)((char*)this + 4))->GetItem();
        ((BSSimpleList<const char*>*)((char*)this + 4))->RemoveHead();
        filename = filenameToDelete;
        ::operator delete((void*)filename);
    }
    ((FileEntryListCollection*)((char*)this + 12))->ClearAndDeleteArray();
}

// @fnv 0x00489ae0
TESModelList::~TESModelList()
{
    ClearComponent();
}

// @fnv 0x005fa180
unsigned int TESModelList::BaseFormRecord(unsigned int type)
{
    unsigned int result = 0;
    if (ActorValue::GetFlag((ActorValue::Index)type, 0x400))
    {
        result = ((TESModelList*)((char*)this - 0x100))->HasModels();
    }
    else
    {
        switch (type)
        {
        case 0x38:
            result = ((TESModelListCopyTarget*)((char*)this + 0x0c))->vfn_10();
            break;
        default:
            result = ((ActorValueOwner*)this)->ActorValueOwner::GetActorValue((ActorValue::Index)type);
            break;
        }
    }
    return result;
}

struct BGSLoadFormBuffer;
struct BGSMessageIcon;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESForm;
struct TESFullName;
struct TESIcon;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_00478690_shell : public TESModelList
{
    void ClearDataComponent();
};

struct Dummy004753a0
{
    void* Destroy(unsigned int);
};

// Releases the object stored at offset 4 by calling its virtual method with 1, then sets that pointer to null.
// @fnv 0x00478690
void FUN_00478690_shell::ClearDataComponent()
{
    Dummy004753a0* p;
    Dummy004753a0* p2;
    p2 = *(Dummy004753a0**)((char*)this + 4);
    p = p2;
    p ? p->Destroy(1) : 0;
    *(void**)((char*)this + 4) = 0;
}

union SETTING_VALUE
{
    float f;
};

class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};

class GameSettingCollection;
template <class T> class SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting43;

struct TESActorBaseData
{
    bool GetMatchesPCLevel();
    unsigned short FUN_0047ded0();
};

// Returns the byte at pThis+0x12d, adding the scaled level from the actor base data when it matches the PC level.
// @fnv 0x005f8f70
unsigned char __fastcall GetCombatSkill(char* pThis)
{
    unsigned char ucLevel = static_cast<unsigned char>(pThis[0x12d]);
    if (reinterpret_cast<TESActorBaseData*>(pThis + 0x30)->GetMatchesPCLevel())
    {
        short slevel = reinterpret_cast<TESActorBaseData*>(pThis + 0x30)->FUN_0047ded0();
        if (slevel < 1)
            slevel = 1;
        ucLevel =
            ucLevel +
            static_cast<unsigned char>(
                slevel * reinterpret_cast<SettingT_GameSettingCollection_&>(originalRuntimeFloatSetting43).Float()->f);
    }
    return ucLevel;
}

struct FUN_005fa180_cls : public ActorValueOwner
{
    char pad[0xc - 4];
    int FUN_005fa180(ActorValue::Index aeIndex);
};
// @fnv 0x005fa180
int FUN_005fa180_cls::FUN_005fa180(ActorValue::Index aeIndex)
{
    int result = 0;
    if (ActorValue::GetFlag(aeIndex, 0x400))
    {
        result = ((TESModelList*)((char*)this - 0x100))->HasModels();
    }
    else
    {
        switch (aeIndex)
        {
        case 0x38:
            result = ((TESModelListCopyTarget*)((char*)this + 0xc))->vfn_10();
            break;
        default:
            result = ActorValueOwner::GetActorValue(aeIndex);
            break;
        }
    }
    return result;
}

extern unsigned int _data_011c16bc;
struct BFC_s
{
    virtual void v();
    BFC_s();
};
struct SL
{
    char p[8];
    SL();
    ~SL();
};
struct SL2
{
    char p[8];
    SL2();
};
struct FUN_00489a60 : public BFC_s
{
    SL a;
    SL2 b;
    FUN_00489a60();
    virtual void ClearData();
};
// Initializes the object by calling ClearData().
// @fnv 0x00489a60
FUN_00489a60::FUN_00489a60()
{
    ClearData();
}

unsigned int __cdecl BSStringLength(const char*);
struct Sub00489ce0
{
    void LoadFromTESFile(void*, TESFile*);
};
struct S00489ce0
{
    char pad[0xc];
    Sub00489ce0 sub;
    void AddModel(const char*);
    void LoadStringChunk(void* p1, TESFile* apFile);
};
// @fnv 0x00489ce0
void S00489ce0::LoadStringChunk(void* p1, TESFile* apFile)
{
    if (!apFile || !p1)
        return;
    unsigned int id = apFile->GetChunkID();
    switch (id)
    {
    case 0x5a46494e: {
        char* pChunkBuffer = new char[apFile->GetChunkSize()];
        {
            char* pString = pChunkBuffer;
            apFile->GetChunkData(pChunkBuffer, 0);
            while (*pString)
            {
                AddModel(pString);
                pString += BSStringLength(pString) + 1;
            }
        }
        delete pChunkBuffer;
        break;
    }
    case 0x5446494e:
        sub.LoadFromTESFile(p1, apFile);
        break;
    }
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x004753a0
void* DelStandIn::Destroy(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct FUN_0048a010_shell : public FileEntryListCollection
{
    void ClearAndDeleteArray();
};

struct FUN_0048a0a0
{
    ~FUN_0048a0a0();
};
// Deletes each element of the array at this+4, frees the array, nulls the pointer, and resets the count at this+0 to zero.
// @fnv 0x0048a010
void FUN_0048a010_shell::ClearAndDeleteArray()
{
    unsigned int i;
    if (*(FUN_0048a0a0***)((char*)this + 4))
    {
        for (i = 0; i < *(unsigned int*)this; i++)
            delete (*(FUN_0048a0a0***)((char*)this + 4))[i];
        delete *(FUN_0048a0a0***)((char*)this + 4);
        *(FUN_0048a0a0***)((char*)this + 4) = 0;
    }
    *(unsigned int*)this = 0;
}

namespace fnv_00489db0 {
struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryChanges;
struct MagicItemForm;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct PackageList;
struct SpellItem;
struct TESAIForm;
struct TESActorBase;
struct TESActorBaseData;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFaction;
struct TESForm;
struct TESHealthForm;
struct TESLevItem;
struct TESLevSpell;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_00489db0_shell : public TESModelList
{
    void CopyModelListFromComponent(BaseFormComponent*);
};

struct S00489ce0
{
    void AddModel(const char*);
};
struct PathingLocation;
struct PathingRequest
{
    PathingLocation* GetOrigin();
};
struct FUN_0048a2c0_shell
{
    void FUN_0048a2c0(PathingLocation*);
};
// Casts component to TESModelList, copies each filename via AddModel, then copies the origin pathing location.
// @fnv 0x00489db0
void FUN_00489db0_shell::CopyModelListFromComponent(BaseFormComponent* component)
{
    TESModelList* source = dynamic_cast<TESModelList*>(component);
    if (!source)
        return;
    ((TESModelListCopyTarget*)this)->vfn_04();
    BSSimpleList<char const*>* list = &source->m_kModelPaths;
    while (list)
    {
        const char* filename = list->GetItem();
        if (filename)
            ((S00489ce0*)this)->AddModel(filename);
        list = list->GetNext();
    }
    ((FUN_0048a2c0_shell*)((char*)this + 0xc))->FUN_0048a2c0(((PathingRequest*)source)->GetOrigin());
}
}  // namespace fnv_00489db0

namespace fnv_00489fa0 {
struct TaskQueueInterface
{
    static void CopyStringToBuffer(char* dest, unsigned int size, const char* src);
};
struct SoundListView
{
    void AddTail(char* const&);
};
int BSStringLength(const char*);
struct FUN_00489fa0_shell
{
    char pad[4];
    bool ContainsFile(const char*);
    void AddModel(const char*);
};
// If the string is not already present, allocates a copy of it, copies the text into it, and appends it to the list at this+4.
// @fnv 0x00489fa0
void FUN_00489fa0_shell::AddModel(const char* apString)
{
    if (!ContainsFile(apString))
    {
        int size = BSStringLength(apString) + 1;
        char* copy = static_cast<char*>(operator new(size));
        char* dest = copy;
        TaskQueueInterface::CopyStringToBuffer(dest, size, apString);
        ((SoundListView*)((char*)this + 4))->AddTail(dest);
    }
}
}  // namespace fnv_00489fa0

struct FNV_NodeIter
{
    int* GetItem();
    FNV_NodeIter* GetNext();
};

extern char DAT_01183040;
extern char DAT_01186b14;

void* __cdecl FUN_00ec43fb(unsigned int a, unsigned int b, void* c, void* d, unsigned int e);
int __cdecl FUN_00404dc0(int a, int b);

struct FUN_00489e40_cls
{
    char pad[4];
    bool HasAnyMismatchedEntry(unsigned int arg);
};

// Looks up a record via FUN_00ec43fb and walks both node lists, returning true if any pair of entries differs or the lists have different lengths.
// @fnv 0x00489e40
bool FUN_00489e40_cls::HasAnyMismatchedEntry(unsigned int arg)
{
    char* p = (char*)FUN_00ec43fb(arg, 0, &DAT_01183040, &DAT_01186b14, 0);
    if (p == 0)
    {
        return true;
    }
    FNV_NodeIter* a = (FNV_NodeIter*)((char*)this + 4);
    FNV_NodeIter* b = (FNV_NodeIter*)(p + 4);
    int y4;
    int x3;
    while (a != 0 && b != 0)
    {
        x3 = *a->GetItem();
        y4 = *b->GetItem();
        if ((x3 == 0 && y4 != 0) || (x3 != 0 && y4 == 0))
        {
            return true;
        }
        else
        {
            if (x3 != 0 && y4 != 0 && FUN_00404dc0(x3, y4) != 0)
            {
                return true;
            }
        }
        a = a->GetNext();
        b = b->GetNext();
    }
    if (a != 0 || b != 0)
    {
        return true;
    }
    return false;
}

int __cdecl FUN_00404dc0(const char* lhs, const char* rhs);

struct FUN_00489f20_shell : TESModelList
{
    bool ContainsFile(const char* filename);
};

// Returns true if filename is non-null and matches an entry in the model list, otherwise false.
// @fnv 0x00489f20
bool FUN_00489f20_shell::ContainsFile(const char* filename)
{
    if (m_kModelPaths.IsEmpty() || filename == 0)
        return false;

    BSSimpleList<const char*>* entry = &m_kModelPaths;
    while (entry != 0)
    {
        const char* value = entry->GetItem();
        if (value && FUN_00404dc0(value, filename) == 0)
            return true;
        entry = entry->GetNext();
    }

    return false;
}

unsigned int __cdecl FUN_0044a670(const char* text);
void __cdecl FUN_00406d30(char* destination, unsigned int capacity, const char* source);
void __cdecl FUN_004856f0(void* destination, char* source, unsigned int length);

struct FUN_00489ba0_shell : public TESModelList
{
    void CopyModelListToBuffer(void* destination, unsigned int flags);
};

// If the model list is non-empty, concatenates its strings into a new buffer, copies it to destination, frees it, then clears the list data.
// @fnv 0x00489ba0
void FUN_00489ba0_shell::CopyModelListToBuffer(void* destination, unsigned int flags)
{
    if (!m_kModelPaths.IsEmpty())
    {
        unsigned int iStack_8 = 1;
        BSSimpleList<const char*>* iStack7 = &m_kModelPaths;
        const char* piVar4;
        char* allocResult;
        char* puVar4;
        char* puStack_18;
        unsigned int iStack_c;
        const char* iVarTmp;
        unsigned int count9;
        char* freeBuffer_;

        while (iStack7 != 0)
        {
            piVar4 = iStack7->GetItem();
            if (piVar4 != 0)
                iStack_8 = iStack_8 + FUN_0044a670(piVar4) + 1;
            iStack7 = iStack7->GetNext();
        }

        allocResult = (char*)::operator new(iStack_8);
        puVar4 = allocResult;
        puStack_18 = puVar4;
        iStack7 = &m_kModelPaths;
        iStack_c = iStack_8;
        while (iStack7 != 0)
        {
            iVarTmp = iStack7->GetItem();
            if (iVarTmp != 0)
            {
                FUN_00406d30(puStack_18, iStack_c, iVarTmp);
                count9 = FUN_0044a670(iVarTmp) + 1;
                puStack_18 = puStack_18 + count9;
                iStack_c = iStack_c - count9;
            }
            iStack7 = iStack7->GetNext();
        }
        *puStack_18 = 0;
        FUN_004856f0(destination, puVar4, iStack_8);
        freeBuffer_ = puVar4;
        ::operator delete(freeBuffer_);
    }
    m_kModelData.ClearData(flags);
}

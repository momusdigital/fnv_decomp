// fallout_shared/pathfinding/navmeshinfo.cpp: NavMeshInfo, NavMeshInfoSaveShell, NavInfo (15 functions)

class NavMeshInfo;
class TESObjectREFR;
class TESForm;
class TESFile;
class Pathing;
class TES;
class TESObjectWEAP;
class SandboxProcedureData;
class InventoryStackRecord;

int __cdecl Warning(const char* format, ...);

class TESForm
{
  public:
    static TESForm* GetFormByID(unsigned int formID);
    static void RemapFormIDForFile(unsigned int& formID, TESFile* file);
};

class TESFile
{
  public:
    bool IsEndianConversionRequired();
};

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned int* value, EndianSizeTag<4> tag);
extern "C" void* __cdecl memcpy(void* destination, const void* source, unsigned int size);

class Pathing
{
  public:
    NavMeshInfo* FindReferenceByFormId();
};
class TES
{
  public:
    Pathing* GetActiveCell(unsigned int formID);
};
extern TES* g_TES;
class TESObjectWEAP;

template <class T> class NiTNewInterface
{
};
template <class T, class I> class NiTArray
{
  public:
    T& GetAt(unsigned int index);
};

template <class T, unsigned int N> class BSSimpleArray
{
  public:
    void** vtable;
    T* buffer;
    unsigned int size;
    unsigned int reservedSize;
    BSSimpleArray();
    ~BSSimpleArray();
    void Clear(bool freeBuffer);
    void FUN_006b3eb0(unsigned int size, bool freeBuffer);
    unsigned int GetSize();
    void SetSize(unsigned int newSize, bool freeBuffer);
    void Remove(unsigned int index, bool freeBuffer);
    void CopyTo(BSSimpleArray<T, N>* other);
    T& operator[](unsigned int index);
};

struct NavMeshInfoPoint
{
    float x, y, z;
};
class NavMeshBounds
{
  public:
    unsigned char data[56];
    ~NavMeshBounds();
    NavMeshBounds();  // unnamed constructor at 0x0069bcf0
    void CopyTo(NavMeshBounds* other);
};
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

class NavMeshInfo
{
  public:
    unsigned int m_uiNavMeshID;
    unsigned int m_uiParentSpaceID;
    unsigned int uiFlags;
    int m_uiPathingFlags;
    NavMeshInfoPoint m_kNavMeshPosition;
    TESForm* m_pParentSpace;
    float m_fStoredValue;
    BSSimpleArray<NavMeshInfo*, 1024> m_kConnectedNavMeshInfos;
    BSSimpleArray<NavMeshInfo*, 1024> m_kPreferredConnections;
    BSSimpleArray<TESObjectREFR*, 1024> m_kDoorReferences;
    void* m_pLocationNavMesh;
    NavMeshBounds* pBounds;

    ~NavMeshInfo();  // external cleanup routine at 0x006b4790; needed by the native deleting destructor
    void CopyTo(NavMeshInfo* other);
    inline void Delete();
    void ReleaseNavMesh();
    void LoadSerializedData(char* data, TESFile* file, int version);
};

// @fnv 0x0069af10
template <> BSSimpleArray<NavMeshInfo*, 1024>::~BSSimpleArray()
{
    vtable = (void**)0x0106b1a4;
    ((BSSimpleArray<SandboxProcedureData, 1024>*)this)->Clear(true);
}

// @fnv 0x006b5490
void NavMeshInfo::ReleaseNavMesh()
{
    unsigned int ItemUpdateArray = ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kDoorReferences)->GetSize();
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        TESObjectREFR* door =
            ((NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*)&m_kDoorReferences)->GetAt(i);
        ((NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*)&m_kDoorReferences)->GetAt(i) =
            (TESObjectREFR*)TESForm::GetFormByID((unsigned int)door);
        if (!((NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*)&m_kDoorReferences)->GetAt(i))
        {
            Warning("NavMeshInfo %08x, Could not find Door %08x referenced by NavMeshInfo", m_uiNavMeshID,
                    (unsigned int)door);
            ((BSSimpleArray<InventoryStackRecord*, 1024>*)&m_kDoorReferences)->Remove(i, true);
            --ItemUpdateArray;
            --i;
        }
    }
}

// @fnv 0x006b51a0
void NavMeshInfo::LoadSerializedData(char* data, TESFile* file, int version)
{
    unsigned int count = 0;
    memcpy(&count, data, 4);
    if (file->IsEndianConversionRequired())
        BSEndian(&count, EndianSizeTag<4>());
    ((BSSimpleArray<TESObjectWEAP*, 1024>*)&m_kConnectedNavMeshInfos)->SetSize(count, true);
    data += 4;
    for (unsigned int adjacentIndex = 0; adjacentIndex < count; ++adjacentIndex)
    {
        unsigned int adjacentID = *(unsigned int*)data;
        if (file->IsEndianConversionRequired())
            BSEndian(&adjacentID, EndianSizeTag<4>());
        TESForm::RemapFormIDForFile(adjacentID, file);
        if (adjacentID)
        {
            ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kConnectedNavMeshInfos)->operator[](adjacentIndex) =
                g_TES->GetActiveCell(adjacentID)->FindReferenceByFormId();
        }
        else
        {
            ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kConnectedNavMeshInfos)->operator[](adjacentIndex) = 0;
        }
        data += 4;
    }

    if (version >= 11)
    {
        count = 0;
        memcpy(&count, data, 4);
        if (file->IsEndianConversionRequired())
            BSEndian(&count, EndianSizeTag<4>());
        ((BSSimpleArray<TESObjectWEAP*, 1024>*)&m_kPreferredConnections)->SetSize(count, true);
        data += 4;
        for (unsigned int preferredIndex = 0; preferredIndex < count; ++preferredIndex)
        {
            unsigned int preferredID = *(unsigned int*)data;
            if (file->IsEndianConversionRequired())
                BSEndian(&preferredID, EndianSizeTag<4>());
            TESForm::RemapFormIDForFile(preferredID, file);
            if (preferredID)
            {
                ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kPreferredConnections)->operator[](preferredIndex) =
                    g_TES->GetActiveCell(preferredID)->FindReferenceByFormId();
            }
            else
            {
                ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kPreferredConnections)->operator[](preferredIndex) = 0;
            }
            data += 4;
        }
    }

    memcpy(&count, data, 4);
    if (file->IsEndianConversionRequired())
        BSEndian(&count, EndianSizeTag<4>());
    ((BSSimpleArray<TESObjectWEAP*, 1024>*)&m_kDoorReferences)->SetSize(count, true);
    data += 4;
    for (unsigned int doorIndex = 0; doorIndex < count; ++doorIndex)
    {
        unsigned int doorID = *(unsigned int*)data;
        if (file->IsEndianConversionRequired())
            BSEndian(&doorID, EndianSizeTag<4>());
        TESForm::RemapFormIDForFile(doorID, file);
        ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kDoorReferences)->operator[](doorIndex) = (NavMeshInfo*)doorID;
        data += 4;
    }
}

// @fnv 0x006b5ab0
void NavMeshInfo::CopyTo(NavMeshInfo* other)
{
    other->m_uiNavMeshID = m_uiNavMeshID;
    other->m_uiParentSpaceID = m_uiParentSpaceID;
    other->uiFlags = uiFlags;
    other->m_uiPathingFlags = m_uiPathingFlags;
    other->m_kNavMeshPosition = m_kNavMeshPosition;
    other->m_pParentSpace = m_pParentSpace;
    other->m_pLocationNavMesh = m_pLocationNavMesh;
    ((BSSimpleArray<unsigned int, 1024>*)&m_kConnectedNavMeshInfos)
        ->CopyTo((BSSimpleArray<unsigned int, 1024>*)&other->m_kConnectedNavMeshInfos);
    ((BSSimpleArray<unsigned int, 1024>*)&m_kPreferredConnections)
        ->CopyTo((BSSimpleArray<unsigned int, 1024>*)&other->m_kPreferredConnections);
    ((BSSimpleArray<unsigned int, 1024>*)&m_kDoorReferences)
        ->CopyTo((BSSimpleArray<unsigned int, 1024>*)&other->m_kDoorReferences);
    if (pBounds)
    {
        if (!other->pBounds)
            other->pBounds = new NavMeshBounds;
        pBounds->CopyTo(other->pBounds);
    }
    else
    {
        if (other->pBounds)
        {
            delete other->pBounds;
        }
        other->pBounds = 0;
    }
}

// Initializes the array's vtable and calls FUN_006b3eb0 with 0 and false.
// Default constructor for BSSimpleArray<NavMeshInfo*, 1024> that sets the vtable and calls FUN_006b3eb0 with 0 and false.
// @fnv 0x0069aee0
template <> BSSimpleArray<NavMeshInfo*, 1024>::BSSimpleArray()
{
    vtable = (void**)0x0106b1a4;
    FUN_006b3eb0(0, false);
}

// Deletes this NavMeshInfo object by calling delete on itself.
// @fnv 0x006b6390
inline void NavMeshInfo::Delete()
{
    delete this;
}

// Instantiate the compiler's deleting destructor through the native deletion member.
void (NavMeshInfo::*navmeshinfo_delete)() = &NavMeshInfo::Delete;

struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_0069c460_shell
{
    int FUN_0069c460();
};

// Computes a size by summing fixed offsets with flag counts from the ArrSI objects at offsets 0x28 and 0x18 scaled by 0xc and 6.
// @fnv 0x0069c460
int FUN_0069c460_shell::FUN_0069c460()
{
    int result = 0;
    result += 0x18;
    result += 2;
    result += 2;
    result += ((ArrSI*)((char*)this + 0x28))->GetFlags() * 0xc;
    result += ((ArrSI*)((char*)this + 0x18))->GetFlags() * 6;
    return result;
}

namespace fnv_006b4e10 {
struct ArrSI
{
    unsigned int GetFlags();
};

class FUN_006b4e10_shell
{
  public:
    unsigned int FUN_006b4e10();
};

// @fnv 0x006b4e10
unsigned int FUN_006b4e10_shell::FUN_006b4e10()
{
    unsigned int v = 0;
    v += 4;
    v += ((ArrSI*)((char*)this + 0x24))->GetFlags() * 4;
    v += 4;
    v += ((ArrSI*)((char*)this + 0x34))->GetFlags() * 4;
    v += 4;
    v += ((ArrSI*)((char*)this + 0x44))->GetFlags() * 4;
    return v;
}
}  // namespace fnv_006b4e10

namespace fnv_006b5a90 {
struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_006b5a90_shell
{
    unsigned int FUN_006b5a90();
};

// @fnv 0x006b5a90
unsigned int FUN_006b5a90_shell::FUN_006b5a90()
{
    return ((ArrSI*)((char*)this + 0x58))->GetFlags();
}
}  // namespace fnv_006b5a90

struct FUN_006b4850_t : public NavMeshBounds
{
    void FUN_0069bda0();
    void* FUN_006b4850(unsigned int flags);
};
void __cdecl _Deallocate(void*);
// Calls FUN_0069bda0, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x006b4850
void* FUN_006b4850_t::FUN_006b4850(unsigned int flags)
{
    FUN_0069bda0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

bool FUN_00401500();
struct FormIDStub
{
    unsigned int _ref_0084e3a0();
};
struct Flt
{
    operator unsigned int();
};
struct NavMeshPtr
{
    void* m_pObject;
    NavMeshPtr();
    ~NavMeshPtr();
};
struct NavMeshInfoHelper
{
    bool AcquireNavMesh(NavMeshPtr& ptr);
};
struct Arr
{
    unsigned int* GetAt(int index);
};

struct NavMeshInfoSaveShell : NavMeshInfo
{
    void SaveToBuffer(char* apData);
};

// @fnv 0x006b4e80
void NavMeshInfoSaveShell::SaveToBuffer(char* apData)
{
    TESObjectREFR* pRefr;
    {
        NavMeshInfo* pInfo;
        {
            unsigned int ItemUpdateArray;
            {
                unsigned int uiTemp;

                uiTemp = ((ArrSI*)&m_kConnectedNavMeshInfos)->GetFlags();
                if (FUN_00401500())
                    BSEndian(&uiTemp, EndianSizeTag<4>());
                *(unsigned int*)apData = uiTemp;
                apData += 4;
                ItemUpdateArray = ((ArrSI*)&m_kConnectedNavMeshInfos)->GetFlags();
                pInfo = 0;
                for (unsigned int i = 0; i < ItemUpdateArray; i++)
                {
                    pInfo = (NavMeshInfo*)*((Arr*)&m_kConnectedNavMeshInfos)->GetAt(i);
                    NavMeshPtr navMeshPtr;
                    if (((NavMeshInfoHelper*)pInfo)->AcquireNavMesh(navMeshPtr))
                    {
                        uiTemp = ((FormIDStub*)(unsigned int)*(Flt*)&navMeshPtr)->_ref_0084e3a0();
                        if (FUN_00401500())
                            BSEndian(&uiTemp, EndianSizeTag<4>());
                        *(unsigned int*)apData = uiTemp;
                    }
                    apData += 4;
                }

                uiTemp = ((ArrSI*)&m_kPreferredConnections)->GetFlags();
                if (FUN_00401500())
                    BSEndian(&uiTemp, EndianSizeTag<4>());
                *(unsigned int*)apData = uiTemp;
                apData += 4;
                ItemUpdateArray = ((ArrSI*)&m_kPreferredConnections)->GetFlags();
                pInfo = 0;
                for (unsigned int j = 0; j < ItemUpdateArray; j++)
                {
                    pInfo = (NavMeshInfo*)*((Arr*)&m_kPreferredConnections)->GetAt(j);
                    NavMeshPtr navMeshPtr;
                    if (((NavMeshInfoHelper*)pInfo)->AcquireNavMesh(navMeshPtr))
                    {
                        uiTemp = ((FormIDStub*)(unsigned int)*(Flt*)&navMeshPtr)->_ref_0084e3a0();
                        if (FUN_00401500())
                            BSEndian(&uiTemp, EndianSizeTag<4>());
                        *(unsigned int*)apData = uiTemp;
                    }
                    apData += 4;
                }

                uiTemp = ((ArrSI*)&m_kDoorReferences)->GetFlags();
                if (FUN_00401500())
                    BSEndian(&uiTemp, EndianSizeTag<4>());
                *(unsigned int*)apData = uiTemp;
                apData += 4;
                ItemUpdateArray = ((ArrSI*)&m_kDoorReferences)->GetFlags();
                pRefr = 0;
                for (unsigned int k = 0; k < ItemUpdateArray; k++)
                {
                    pRefr = (TESObjectREFR*)*((Arr*)&m_kDoorReferences)->GetAt(k);
                    if (pRefr)
                    {
                        uiTemp = ((FormIDStub*)pRefr)->_ref_0084e3a0();
                        if (FUN_00401500())
                            BSEndian(&uiTemp, EndianSizeTag<4>());
                        *(unsigned int*)apData = uiTemp;
                    }
                    else
                    {
                        *(unsigned int*)apData = 0;
                    }
                    apData += 4;
                }
            }
        }
    }
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct FUN_0069c4c0_shell
{
    void WriteToBuffer(char* buffer);
};

void* __cdecl __memcpy(void* destination, const void* source, unsigned int size);

struct FUN_006b48f0_shell : public NavMeshInfo
{
    void WriteToChunkBuffer(char* apChunkBuffer);
};

// Serializes uiFlags, form IDs, a NiPoint3, optional bounds data and a float into apChunkBuffer, byte-swapping each value when FUN_00401500 is true.
// @fnv 0x006b48f0
void FUN_006b48f0_shell::WriteToChunkBuffer(char* apChunkBuffer)
{
    unsigned int itempint;
    float ftempFloat;
    NiPoint3 temppoint;

    itempint = this->uiFlags;
    if (FUN_00401500())
        BSEndian(&itempint, EndianSizeTag<4>());
    __memcpy(apChunkBuffer, &itempint, 4);
    apChunkBuffer += 4;

    if (this->m_pLocationNavMesh)
    {
        if (reinterpret_cast<FormIDStub*>(this->m_pLocationNavMesh)->_ref_0084e3a0() != this->m_uiNavMeshID)
            this->m_uiNavMeshID = reinterpret_cast<FormIDStub*>(this->m_pLocationNavMesh)->_ref_0084e3a0();
    }

    itempint = this->m_uiNavMeshID;
    if (FUN_00401500())
        BSEndian(&itempint, EndianSizeTag<4>());
    __memcpy(apChunkBuffer, &itempint, 4);
    apChunkBuffer += 4;

    this->m_uiParentSpaceID = reinterpret_cast<FormIDStub*>(this->m_pParentSpace)->_ref_0084e3a0();
    itempint = this->m_uiParentSpaceID;
    if (FUN_00401500())
        BSEndian(&itempint, EndianSizeTag<4>());
    __memcpy(apChunkBuffer, &itempint, 4);
    apChunkBuffer += 4;

    itempint = this->m_uiPathingFlags;
    if (FUN_00401500())
        BSEndian(&itempint, EndianSizeTag<4>());
    __memcpy(apChunkBuffer, &itempint, 4);
    apChunkBuffer += 4;

    temppoint = *reinterpret_cast<const NiPoint3*>(&this->m_kNavMeshPosition);
    if (FUN_00401500())
    {
        BSEndian(reinterpret_cast<unsigned int*>(&temppoint.x), EndianSizeTag<4>());
        BSEndian(reinterpret_cast<unsigned int*>(&temppoint.y), EndianSizeTag<4>());
        BSEndian(reinterpret_cast<unsigned int*>(&temppoint.z), EndianSizeTag<4>());
    }
    __memcpy(apChunkBuffer, &temppoint, 12);
    apChunkBuffer += 12;

    if (this->pBounds)
    {
        reinterpret_cast<FUN_0069c4c0_shell*>(this->pBounds)->WriteToBuffer(apChunkBuffer);
        apChunkBuffer += reinterpret_cast<FUN_0069c460_shell*>(this->pBounds)->FUN_0069c460();
    }

    ftempFloat = this->m_fStoredValue;
    if (FUN_00401500())
        BSEndian(reinterpret_cast<unsigned int*>(&ftempFloat), EndianSizeTag<4>());
    __memcpy(apChunkBuffer, &ftempFloat, 4);
    apChunkBuffer += 4;
}

struct FUN_006b4b50_shell : public NavMeshInfo
{
    void LoadNavMeshInfo(char*, TESFile*, int);
};

void* __cdecl __memcpy(void* destination, const void* source, unsigned int size);
void __cdecl _ref_00485d50(unsigned int* formID, TESFile* file);

struct TESFileAccessor
{
    bool GetChunkData();
};

struct FUN_0069c8f0_shell
{
    void ReadFromBuffer(char* data, TESFile* file, int version);
};

// @fnv 0x006b4b50
void FUN_006b4b50_shell::LoadNavMeshInfo(char* apChunkBuffer, TESFile* apFile, int aiFileVersionNumber)
{
    __memcpy(&this->uiFlags, apChunkBuffer, 4);
    if (((TESFileAccessor*)apFile)->GetChunkData())
    {
        BSEndian(&this->uiFlags, EndianSizeTag<4>());
    }
    apChunkBuffer += 4;

    __memcpy(&this->m_uiNavMeshID, apChunkBuffer, 4);
    if (((TESFileAccessor*)apFile)->GetChunkData())
    {
        BSEndian(&this->m_uiNavMeshID, EndianSizeTag<4>());
    }
    apChunkBuffer += 4;

    _ref_00485d50(&this->m_uiNavMeshID, apFile);

    __memcpy(&this->m_uiParentSpaceID, apChunkBuffer, 4);
    if (((TESFileAccessor*)apFile)->GetChunkData())
    {
        BSEndian(&this->m_uiParentSpaceID, EndianSizeTag<4>());
    }
    apChunkBuffer += 4;

    _ref_00485d50(&this->m_uiParentSpaceID, apFile);

    __memcpy(reinterpret_cast<unsigned int*>(&this->m_uiPathingFlags), apChunkBuffer, 4);
    if (((TESFileAccessor*)apFile)->GetChunkData())
    {
        BSEndian(reinterpret_cast<unsigned int*>(&this->m_uiPathingFlags), EndianSizeTag<4>());
    }
    apChunkBuffer += 4;

    __memcpy(&this->m_kNavMeshPosition, apChunkBuffer, 12);
    if (((TESFileAccessor*)apFile)->GetChunkData())
    {
        BSEndian(reinterpret_cast<unsigned int*>(&this->m_kNavMeshPosition.x), EndianSizeTag<4>());
        BSEndian(reinterpret_cast<unsigned int*>(&this->m_kNavMeshPosition.y), EndianSizeTag<4>());
        BSEndian(reinterpret_cast<unsigned int*>(&this->m_kNavMeshPosition.z), EndianSizeTag<4>());
    }
    apChunkBuffer += 12;

    if ((this->uiFlags & 0x20) != 0)
    {
        if (!this->pBounds)
            this->pBounds = new NavMeshBounds;

        ((FUN_0069c8f0_shell*)this->pBounds)->ReadFromBuffer(apChunkBuffer, apFile, aiFileVersionNumber);
        apChunkBuffer += ((FUN_0069c460_shell*)this->pBounds)->FUN_0069c460();
    }

    if (aiFileVersionNumber >= 10)
    {
        __memcpy(reinterpret_cast<unsigned int*>(&this->m_fStoredValue), apChunkBuffer, 4);
        if (((TESFileAccessor*)apFile)->GetChunkData())
        {
            BSEndian(reinterpret_cast<unsigned int*>(&this->m_fStoredValue), EndianSizeTag<4>());
        }
        apChunkBuffer += 4;
    }
}

// FUN_0069bcf0 - default constructor of a non-polymorphic class.
// Disassembly facts:
//   - __thiscall, no stack args, returns this (mov eax,[ebp-0x10] epilogue)
//   - no vtable store -> non-polymorphic
//   - ctor-call on this+0x00 and this+0x0C with 3 float args each
//     (globals D_01015f5c x3 then D_01016970 x3)
//   - ctor-call on this+0x18 (0x69cd10), no args
//   - EH scope state 0 set right after, covering only the call on
//     this+0x28 (0x49f1c0) -> member at +0x18 has a non-trivial dtor
//     (unwind funclet destroys it), member at +0x28 ctor is last.

extern float D_01015f5c;
extern float D_01016970;

struct FUN_00416870
{
    float unk00;
    float unk04;
    float unk08;
    FUN_00416870(float, float, float);
};

struct FUN_0069cd10
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    FUN_0069cd10();
    ~FUN_0069cd10();
};

struct FUN_0049f1c0
{
    void* unk00;
    FUN_0049f1c0();
};

class FUN_0069bcf0
{
  public:
    FUN_00416870 unk00;
    FUN_00416870 unk0C;
    FUN_0069cd10 unk18;
    FUN_0049f1c0 unk28;

    FUN_0069bcf0();
};

// @fnv 0x0069bcf0
FUN_0069bcf0::FUN_0069bcf0() : unk00(D_01015f5c, D_01015f5c, D_01015f5c), unk0C(D_01016970, D_01016970, D_01016970)
{}

struct MeshParent
{
    unsigned int FUN_0084e3a0();
};
struct MeshCell
{
    int FUN_0054ddd0();
    int FUN_00544c60();
    int FUN_00544c30();
};
struct MeshPoint
{
    float x, y, z;
    void FUN_0063c8a0(const MeshPoint&);
    void ScaleByInverse(float);
};
struct MeshTriangle
{
    bool HasEdgeExtraInfo();
    bool HasFlag40();
    bool IsEdgeFlagSet(int);
    unsigned short FUN_0068f2c0(int);
};
struct NavInfo;
struct NavInfoPointer
{
    NavInfo* pointer;
    bool FUN_0069e090();
};
struct MeshLink
{
    int unk00;
    NavInfoPointer info;
};
struct MeshSource
{
    unsigned int FUN_0084e3a0();
    MeshParent* GetDoorForm();
    bool FUN_00440da0();
    unsigned int FUN_00558200();
    MeshTriangle* FUN_005582f0(unsigned short);
    MeshLink* GetEdge(unsigned short);
    unsigned int FUN_006b5a90();
    NavInfo* const& FUN_0068f6b0(unsigned short);
    MeshCell* FUN_0059bb30();
    unsigned int GetArrFlags();
    const MeshPoint& FUN_0068f0a0(unsigned short);
    bool FUN_00440d80();
};
struct NavMeshReference
{
    int unk00;
    NavMeshReference();
    ~NavMeshReference();
    MeshSource* FUN_00559450();
};
struct MeshArray
{
    int unk00;
    NavInfo** buffer;
    unsigned int size, capacity;
    void FUN_008454f0(bool);
    unsigned int FUN_0044ddc0();
    NavInfo*& FUN_00877a30(unsigned int);
    void FUN_009a4320(unsigned int, bool);
    void FUN_007cb2e0(NavInfo* const&);
};
struct NavInfo
{
    unsigned int id, parentId, flags;
    int cellKey;
    MeshPoint point;
    MeshParent* parent;
    float preferred;
    MeshArray adjacent, preferredAdjacent, doors;
    void* mesh;
    NavMeshBounds* bounds;
    bool FUN_00690860(NavMeshReference&);
    void FUN_00693ef0(bool);
    void FUN_00693d50(float);
    void FUN_004534f0(bool);
    void InitializeFromMeshSource(MeshSource*);
};
extern MeshPoint DAT_011f426c;
int PackShortPair(int, int);
// Resets this NavInfo and rebuilds its id, parent, adjacency, doors, cell key, point and preferred ratio from the given mesh source.
// @fnv 0x006b5560
void NavInfo::InitializeFromMeshSource(MeshSource* source)
{
    id = source->FUN_0084e3a0();
    parent = source->GetDoorForm();
    parentId = source->GetDoorForm()->FUN_0084e3a0();
    adjacent.FUN_008454f0(true);
    preferredAdjacent.FUN_008454f0(true);
    doors.FUN_008454f0(true);
    flags = 0;
    if (bounds)
    {
        delete bounds;
        bounds = 0;
    }
    if (source->FUN_00440da0())
        FUN_00693ef0(true);
    {
        unsigned int count = source->FUN_00558200();
        for (unsigned int i = 0; i < count; ++i)
        {
            MeshTriangle* triangle = source->FUN_005582f0((unsigned short)i);
            if (!triangle->HasEdgeExtraInfo())
                continue;
            bool isPreferred = triangle->HasFlag40();
            for (int edge = 0; edge < 3; ++edge)
            {
                if (!triangle->IsEdgeFlagSet(edge))
                    continue;
                MeshLink* link = source->GetEdge(triangle->FUN_0068f2c0(edge));
                if (link->info.FUN_0069e090())
                {
                    bool add3 = true;
                    NavMeshReference reference;
                    if (link->info.pointer->FUN_00690860(reference))
                    {
                        if (reference.FUN_00559450()->FUN_00440d80())
                            add3 = false;
                        else if (isPreferred)
                        {
                            unsigned int size = adjacent.FUN_0044ddc0();
                            for (unsigned int j = 0; j < size; ++j)
                                if (adjacent.FUN_00877a30(j) == link->info.pointer)
                                {
                                    adjacent.FUN_009a4320(j, true);
                                    break;
                                }
                            size = preferredAdjacent.FUN_0044ddc0();
                            for (unsigned int k = 0; k < size; ++k)
                                if (preferredAdjacent.FUN_00877a30(k) == link->info.pointer)
                                {
                                    add3 = false;
                                    break;
                                }
                        }
                        else
                        {
                            unsigned int sizeOther = adjacent.FUN_0044ddc0();
                            for (unsigned int m = 0; m < sizeOther; ++m)
                                if (adjacent.FUN_00877a30(m) == link->info.pointer)
                                {
                                    add3 = false;
                                    break;
                                }
                        }
                    }
                    else
                        add3 = false;
                    if (add3)
                    {
                        if (isPreferred)
                            preferredAdjacent.FUN_007cb2e0(link->info.pointer);
                        else
                            adjacent.FUN_007cb2e0(link->info.pointer);
                    }
                }
            }
        }
        if (count == 0)
            flags |= 8;
        else
            flags &= ~8;
        count = source->FUN_006b5a90();
        for (unsigned int d = 0; d < count; ++d)
            doors.FUN_007cb2e0(source->FUN_0068f6b0((unsigned short)d));
    }
    if (source->FUN_0059bb30()->FUN_0054ddd0())
        cellKey = PackShortPair(source->FUN_0059bb30()->FUN_00544c30(), source->FUN_0059bb30()->FUN_00544c60());
    else
        cellKey = 0;
    point = DAT_011f426c;
    unsigned int vertices = source->GetArrFlags();
    if (vertices > 0)
    {
        for (unsigned int v = 0; v < vertices; ++v)
            point.FUN_0063c8a0(source->FUN_0068f0a0((unsigned short)v));
        point.ScaleByInverse((float)vertices);
    }
    unsigned int triangles = source->FUN_00558200();
    if (triangles)
    {
        unsigned int preferredCount = 0;
        for (unsigned int t = 0; t < triangles; ++t)
        {
            MeshTriangle* triangle2 = source->FUN_005582f0((unsigned short)t);
            if (triangle2->HasFlag40())
                ++preferredCount;
        }
        FUN_00693d50((float)preferredCount / (float)triangles);
    }
    FUN_004534f0(true);
}

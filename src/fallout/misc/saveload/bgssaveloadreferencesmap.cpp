// fallout/misc/saveload/bgssaveloadreferencesmap.cpp: BGSSaveLoadReferencesMap, BGSCellNumericIDArrayMap (10 functions)

#include "bgssaveloadreferencesmap_decls.h"

// @fnv 0x00852B60
void BGSSaveLoadReferencesMap::Clear()
{
    m_kReferenceIDMap.RemoveAll();
    m_kCellReferences.Clear();
    void* position = m_kWorldspaceCellReferenceMaps.GetFirstPos();
    while (position)
    {
        struct WorldspaceReferences
        {
            BGSCellNumericIDArrayMap* referencesMap;
            unsigned int worldspaceID;
        } entry;
        entry.worldspaceID = 0;
        entry.referencesMap = 0;
        m_kWorldspaceCellReferenceMaps.GetNext(position, entry.worldspaceID, entry.referencesMap);
        delete entry.referencesMap;
    }
    m_kWorldspaceCellReferenceMaps.RemoveAll();
}

// @fnv 0x008528D0
void BGSCellNumericIDArrayMap::Clear()
{
    void* position = GetFirstPos();
    while (position)
    {
        struct CellReferenceIDs
        {
            BSSimpleArray<unsigned int, 1024>* referenceIDs;
            unsigned int cellKey;
        } entry;
        entry.cellKey = 0;
        entry.referenceIDs = 0;
        GetNext(position, entry.cellKey, entry.referenceIDs);
        delete entry.referenceIDs;
    }
    RemoveAll();
}

// @fnv 0x00852D20
void BGSSaveLoadReferencesMap::LoadCellReferences(TESObjectCELL* cell, BGSReconstructFormsInAllFilesMap* forms)
{
    struct CellReferences
    {
        BGSCellNumericIDArrayMap* referencesMap;
        unsigned int cellKey;
    } cellReferences;
    cellReferences.referencesMap = 0;
    cellReferences.cellKey = 0;
    if (cell->IsCellInterior())
    {
        cellReferences.cellKey = cell->GetFormID();
        cellReferences.referencesMap = &m_kCellReferences;
    }
    else
    {
        cellReferences.cellKey = TESWorldSpace::BuildCellKey(cell->GetCellGridX(), cell->GetCellGridY());
        m_kWorldspaceCellReferenceMaps.GetAt(cell->GetParentWorldSpace()->GetFormID(), cellReferences.referencesMap);
    }
    if (cellReferences.referencesMap)
    {
        BSSimpleArray<unsigned int, 1024>* referenceIDs = 0;
        if (cellReferences.referencesMap->GetAt(cellReferences.cellKey, referenceIDs))
        {
            for (unsigned int index = 0; index < referenceIDs->GetSize(); ++index)
                ReconstructFormID(referenceIDs->GetAt(index), forms);
            cellReferences.referencesMap->RemoveAt(cellReferences.cellKey);
            delete referenceIDs;
        }
    }
}

struct OL4A
{
    OL4A(int);
    ~OL4A();
    int d[4];
};
struct OL4B
{
    OL4B();
    ~OL4B();
    int d[4];
};
struct OL4C
{
    OL4C(int);
    ~OL4C();
    int d[4];
};
struct FUN_00852a70
{
    OL4A a;
    OL4B b;
    OL4C c;
    FUN_00852a70();
};
// Initializes members a and c with 0x25 and default-constructs b.
// @fnv 0x00852a70
FUN_00852a70::FUN_00852a70() : a(0x25), c(0x25)
{}

struct FUN_00852870_cls
{
    void FUN_00852870();
};
void _Deallocate(void* obj);

struct FUN_00852840_shell : FUN_00852870_cls
{
    void* FUN_00852840(unsigned int flags);
};

// Calls FUN_00852870, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00852840
void* FUN_00852840_shell::FUN_00852840(unsigned int flags)
{
    FUN_00852870();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct LS3de0
{
    unsigned int Find(unsigned int&, unsigned int, bool(__cdecl*)(int const*, int const*));
    void UpdateEntryValue(unsigned int, unsigned int);
};
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
extern "C" bool __cdecl FUN_009a3830(int const*, int const*);

struct FUN_00852a10_shell : DummyPointerMap
{
    void RemoveReference(unsigned int a1, unsigned int a2);
};

// @fnv 0x00852a10
void FUN_00852a10_shell::RemoveReference(unsigned int auiKey, unsigned int a2)
{
    unsigned int icellKey = 0;
    if (this->GetAt(auiKey, icellKey))
    {
        unsigned int idx = reinterpret_cast<LS3de0*>(icellKey)->Find(a2, 0, FUN_009a3830);
        if (idx != 0xFFFFFFFF)
        {
            reinterpret_cast<LS3de0*>(icellKey)->UpdateEntryValue(idx, 1);
        }
    }
}

struct Base52810
{
    void FUN_00852fa0(int);
};
extern int DAT_0107fef4;
struct Cls52810 : Base52810
{
    void* FUN_00852810();
};
// Calls FUN_00852fa0 with 0x25, stores &DAT_0107fef4 into the object's first field, and returns this.
// @fnv 0x00852810
void* Cls52810::FUN_00852810()
{
    FUN_00852fa0(0x25);
    *(void**)this = (void*)&DAT_0107fef4;
    return this;
}

struct NiPoint3;
struct WsH
{
    static int __cdecl GetKeyForWorldCoord(NiPoint3 const&);
};
struct FUN_00852cd0_shell
{
    void RemoveReferenceFromCell(unsigned int aiCellID, unsigned int aiReferenceID, NiPoint3 const& arPos);
};
// Looks up the numeric ID array for aiCellID and removes the reference keyed by the world coordinate of arPos.
// @fnv 0x00852cd0
void FUN_00852cd0_shell::RemoveReferenceFromCell(unsigned int aiCellID, unsigned int aiReferenceID,
                                                 NiPoint3 const& arPos)
{
    BSSimpleArray<unsigned int, 1024>* pnumericIDArray = 0;
    if (((DummyPointerMap*)((char*)this + 0x20))->GetAt(aiCellID, (unsigned int&)pnumericIDArray))
    {
        unsigned int uiCoordKey;
        uiCoordKey = WsH::GetKeyForWorldCoord(arPos);
        ((FUN_00852a10_shell*)pnumericIDArray)->RemoveReference(uiCoordKey, aiReferenceID);
    }
}

struct S00852950
{
    void GetOrCreateEntryAdd(int, int);
};
struct SetAtHelper
{
    void SetAt(unsigned int, unsigned int);
};
struct FUN_00852c00_shell : FUN_00852840_shell
{
    void AddReferenceToCell(unsigned int aiCellID, unsigned int aiReferenceID, NiPoint3 const& arPos);
};
// Looks up or creates the per-cell OL4B map for aiCellID, then inserts aiReferenceID under the key derived from arPos.
// @fnv 0x00852c00
void FUN_00852c00_shell::AddReferenceToCell(unsigned int aiCellID, unsigned int aiReferenceID, NiPoint3 const& arPos)
{
    OL4B* pNumericIDArray = 0;
    if (!((DummyPointerMap*)((char*)this + 0x20))->GetAt(aiCellID, (unsigned int&)pNumericIDArray))
    {
        pNumericIDArray = new OL4B;
        ((SetAtHelper*)((char*)this + 0x20))->SetAt(aiCellID, (unsigned int)pNumericIDArray);
    }
    int key = WsH::GetKeyForWorldCoord(arPos);
    ((S00852950*)pNumericIDArray)->GetOrCreateEntryAdd(key, aiReferenceID);
}

struct PSM3
{
    PSM3();
    ~PSM3();
    int d[4];
};
struct BSSimpleArrayActor
{
    unsigned int Add(void*&);
};
struct FUN_00852950_shell : DummyPointerMap
{
    void SetAt(unsigned int, unsigned int);
    unsigned int GetOrCreateEntryAdd(unsigned int aiKey, void* apValue);
};
// Looks up aiKey in the map; if absent, allocates a PSM3 and stores it, then adds apValue to the entry and returns the result.
// @fnv 0x00852950
unsigned int FUN_00852950_shell::GetOrCreateEntryAdd(unsigned int aiKey, void* apValue)
{
    void* pEntry = 0;
    if (!GetAt(aiKey, (unsigned int&)pEntry))
    {
        pEntry = new PSM3;
        SetAt(aiKey, (unsigned int)pEntry);
    }
    return ((BSSimpleArrayActor*)pEntry)->Add(apValue);
}

struct B852AE0MapA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~B852AE0MapA();
};

struct B852AE0MapB
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~B852AE0MapB();
};

struct B852AE0Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~B852AE0Base();
};

// BGSSaveLoadReferencesMap destructor
class FUN_00852ae0 : public B852AE0Base
{
  public:
    B852AE0MapA m_kMapA;
    B852AE0MapB m_kMapB;

    void Clear();
    ~FUN_00852ae0();
};

// @fnv 0x00852ae0
FUN_00852ae0::~FUN_00852ae0()
{
    Clear();
}

struct Loader2e40
{
    void* FUN_00559450();
    void* GetAdvancedBuffer();
};
struct Change2e40
{
    int key;
    Loader2e40 loader;
};
struct Changes2e40
{
    Change2e40* FUN_009a4250(unsigned int);
};
struct Host2e40
{
    Changes2e40* FUN_00559450();
    void ApplyUnloadedChanges(TESObjectCELL*);
};
extern Host2e40* DAT_011ddf38;
int __cdecl FUN_0084e730(unsigned int, int, int);
void __cdecl FUN_00845cc0(const char*, ...);
struct Info2e40
{
    int unk00, unk04, cellID, x, y, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    Info2e40();
    bool GetOriginalLocationCellAndWorld(TESObjectCELL**, TESWorldSpace**);
};
void __cdecl FUN_0084e930(void*, int, Info2e40*);
TESObjectCELL* __cdecl ResolveReferenceForm(unsigned int, Info2e40*, bool);
struct Forms2e40
{
    void FUN_00843750(TESObjectCELL*, unsigned int, bool);
    void FUN_008438b0(TESWorldSpace*, int, int, unsigned int, bool);
};
struct Target2e40
{
    void FUN_00852e40(unsigned int, Forms2e40*);
};
// @fnv 0x00852e40
void Target2e40::FUN_00852e40(unsigned int uiRefID, Forms2e40* forms)
{
    Change2e40* change = DAT_011ddf38->FUN_00559450()->FUN_009a4250(uiRefID);
    if (change)
    {
        int iChangeType = FUN_0084e730(uiRefID, 0x3a, change->key);
        if (iChangeType != 5 && iChangeType != 6)
        {
            FUN_00845cc0(
                "SAVELOAD: Ref %08X is in the references map but is neither a created reference or a moved reference",
                uiRefID);
            return;
        }
        if (!change->loader.FUN_00559450())
        {
            FUN_00845cc0(
                "SAVELOAD: Ref %08X is in the references map but there is no unloaded buffer for it in the changes map",
                uiRefID);
            return;
        }
        Info2e40 changeInfo;
        FUN_0084e930(change->loader.GetAdvancedBuffer(), iChangeType, &changeInfo);
        if (iChangeType == 5)
        {
            TESObjectCELL* cell = ResolveReferenceForm(uiRefID, &changeInfo, false);
            if (cell)
                DAT_011ddf38->ApplyUnloadedChanges(cell);
        }
        else
        {
            TESObjectCELL* interior = 0;
            TESWorldSpace* world = 0;
            if (changeInfo.GetOriginalLocationCellAndWorld(&interior, &world))
            {
                if (interior)
                    forms->FUN_00843750(interior, uiRefID, false);
                else
                    forms->FUN_008438b0(world, changeInfo.x, changeInfo.y, uiRefID, false);
            }
            else
            {
                FUN_00845cc0("CELLS: Could not find cell or worldspace %08X for moved reference %08X",
                             changeInfo.cellID, uiRefID);
            }
        }
    }
}

class FUN_008531b0
{
  public:
    virtual ~FUN_008531b0();

    void FUN_008528d0();
};

class FUN_00852870 : public FUN_008531b0
{
  public:
    virtual ~FUN_00852870();
};

// The destructor calls FUN_008528d0.
// @fnv 0x00852870
FUN_00852870::~FUN_00852870()
{
    FUN_008528d0();
}

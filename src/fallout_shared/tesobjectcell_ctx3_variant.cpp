
// tesobjectcell_ctx3_variant.cpp: context variant of src/fallout_shared/tesobjectcell.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "tesobjectcell_packet.h"
void __cdecl operator delete(void* pointer);
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
unsigned int FUN_0054f4c0();
NiAVObject* FUN_0054f4f0();

struct TESForm
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual TESForm* DuplicateForm(bool abCreateEditorID, void* apCopyMap);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50(bool);
};
struct TESObjectLAND
{
    void InitializeForCell(TESObjectCELL*);
};
struct NavMesh
{
};
struct RefH
{
    bool IsDeleted() const;
};
struct Flt
{
    operator unsigned int();
};
struct NavMeshPtr : Flt
{
    NavMesh* m_pObject;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NavMeshPtr&);
};
template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer(const NavMeshPtr&);
    ~NiPointer();
};
struct NavMeshCollection
{
    char data[0x10];
    NavMeshCollection();
    NavMeshPtr GetNavMeshAt(unsigned int);
    void AppendNavMesh(NiPointer<NavMesh>);
};
int __fastcall GetReferenceFlags(void*);
NavMeshPtr __cdecl MakeNavMeshPointer(NavMesh*);
struct S004867a0
{
    TESForm* FUN_004867a0(bool, void*);
};
struct CellX
{
    void SetLandscape(TESObjectLAND*);
    void AddReference(TESObjectREFR*, bool);
    void SetNavMeshArray(NavMeshCollection*);
};
struct CellH
{
    bool IsCellPersistent();
};
struct RefX
{
    bool GetReferencePersistence();
    void SetPersistentFlag(bool);
};
struct TempIsTemp
{
    bool IsTemporary() const;
};
struct SL
{
    void* m_item;
    void* m_next;
    SL();
};
struct ListX : SL
{
    ~ListX();
};
struct List_009e03e0
{
    void RemoveAll();
};
struct G2
{
    void AddHead(int*);
};
struct LNode
{
    bool FUN_008256d0();
    void** FUN_006815c0();
    LNode* GetNext();
};

struct FUN_005436e0_shell : TESObjectCELL
{
    TESForm* CreateDuplicateForm(bool abCreateEditorID, void* apCopyMap);
};

// @fnv 0x005436e0
TESForm* FUN_005436e0_shell::CreateDuplicateForm(bool abCreateEditorID, void* apCopyMap)
{
    TESObjectCELL* pdupcell = 0;
    if (IsCellInterior())
    {
    }
    else
    {
        BSSimpleList<TESObjectREFR*>* pCurrentElementNext;
        pdupcell = dynamic_cast<TESObjectCELL*>(((S004867a0*)this)->FUN_004867a0(false, apCopyMap));
        TESObjectLAND* pland;
        pland = *(TESObjectLAND**)((char*)this + 0x4c);
        if (pland)
        {
            TESObjectLAND* pdupland = dynamic_cast<TESObjectLAND*>(((TESForm*)pland)->DuplicateForm(false, apCopyMap));
            if (pdupland)
            {
                ((CellX*)pdupcell)->SetLandscape(pdupland);
                pdupland->InitializeForCell(pdupcell);
                ((TESForm*)pdupland)->v50(true);
            }
        }
        if (*(NavMeshCollection**)((char*)this + 0x64))
        {
            ((CellX*)pdupcell)->SetNavMeshArray(new NavMeshCollection);
            NavMeshPtr spmesh;
            for (unsigned int i = 0; i < GetReferenceFlags(*(NavMeshCollection**)((char*)this + 0x64)); i++)
            {
                NavMesh* pmesh = (NavMesh*)(unsigned int)(*(NavMeshCollection**)((char*)this + 0x64))->GetNavMeshAt(i);
                if (pmesh && !((RefH*)pmesh)->IsDeleted())
                {
                    NavMesh* pdupMesh = dynamic_cast<NavMesh*>(((TESForm*)pmesh)->DuplicateForm(false, apCopyMap));
                    if (pdupMesh)
                    {
                        *(TESObjectCELL**)((char*)pdupMesh + 0x24) = pdupcell;
                        spmesh = MakeNavMeshPointer(pdupMesh);
                        (*(NavMeshCollection**)((char*)pdupcell + 0x64))->AppendNavMesh(spmesh);
                    }
                }
            }
        }
        CellRefLockEnter();
        ListX templist;
        pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)FUN_009604f0();
        while (pCurrentElementNext && !((LNode*)pCurrentElementNext)->FUN_008256d0())
        {
            TESObjectREFR* pref = (TESObjectREFR*)*((LNode*)pCurrentElementNext)->FUN_006815c0();
            if (!((TempIsTemp*)pref)->IsTemporary())
            {
                if (IsCellInterior() || ((CellH*)this)->IsCellPersistent() || !((RefX*)pref)->GetReferencePersistence())
                    ((G2*)&templist)->AddHead((int*)&pref);
            }
            pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)((LNode*)pCurrentElementNext)->GetNext();
        }
        CellRefLockLeave();
        pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)&templist;
        while (pCurrentElementNext && !((LNode*)pCurrentElementNext)->FUN_008256d0())
        {
            TESObjectREFR* pref = (TESObjectREFR*)*((LNode*)pCurrentElementNext)->FUN_006815c0();
            TESObjectREFR* pdupref = dynamic_cast<TESObjectREFR*>(((TESForm*)pref)->DuplicateForm(false, apCopyMap));
            if (pdupref)
            {
                ((RefX*)pdupref)->SetPersistentFlag(((CellH*)pdupcell)->IsCellPersistent());
                ((CellX*)pdupcell)->AddReference(pdupref, false);
                ((TESForm*)pdupref)->v50(true);
            }
            pCurrentElementNext = (BSSimpleList<TESObjectREFR*>*)((LNode*)pCurrentElementNext)->GetNext();
        }
        ((List_009e03e0*)&templist)->RemoveAll();
    }
    return (TESForm*)pdupcell;
}

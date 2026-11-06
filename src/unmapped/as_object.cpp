
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class TESFile
{
  public:
    bool IsMasterFile();
};
class TESForm
{
  public:
    TESFile* GetFile(int);
    int FNV_GetFormType();
};
class NavMesh;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    ~NiPointer();
    operator T*() const;
    void* FUN_00458b50();
};
struct TESObjectREFR
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    bool GetReferencePersistence();
};
struct TESObjectCELL;
struct S00561ef0
{
    bool FUN_00561ef0(TESObjectCELL*);
};
struct P01ObjA
{
    TESForm* GetNext();
};
struct MobileObject
{
    unsigned int GetCurrentProcessLevel();
};
struct FUN_00881d10
{
    void SetHoursPassed();
};
struct FUN_00452440_shell
{
    bool FUN_00452440();
};
struct BSSimpleList
{
    bool FUN_008256d0();
    TESObjectREFR** FUN_006815c0();
    void FUN_0063f7b0();
    BSSimpleList* FUN_00726070();
    void FUN_00905330(TESObjectREFR* const&);
};
struct CF845
{
    int flags;
    CF845(int);
    CF845(const CF845&);
};
struct BGSSaveLoadGame
{
    bool SetThreadAllowChanges(bool);
    bool FUN_0042ce10();
    void UnloadForm(void*, int);
};
struct Class_0084a700
{
    bool HasChangeForForm(TESObjectREFR*, CF845);
};
struct FUN_008d0370_shell
{
    bool FUN_008d0370(TESObjectREFR*);
};
struct BGSLoadedReferenceCollection
{
    void FUN_005270b0(TESObjectREFR*);
};
struct NavMeshCollection
{
    NiPointer<NavMesh> GetNavMeshAt(unsigned int);
    void RemoveAndCollect(unsigned int);
};
int __fastcall GetReferenceFlags(void*);
void FUN_00867f90(TESObjectREFR*);
struct AutoMemHelper
{
    int m_old;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct TESObjectLAND;
struct FUN_009604f0_shell
{
    BSSimpleList* FUN_009604f0();
};
struct FakeCell
{
    TESObjectLAND* GetLandscape();
};
struct EffectSetting
{
    NavMeshCollection* GetEffectID();
};
struct S00551440
{
    void FUN_00551440(bool);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
extern FUN_008d0370_shell* g_TESSaveLoadGame;
extern BGSLoadedReferenceCollection* DAT_011c95c8;
extern TESObjectREFR* g_thePlayer;
struct TESObjectCELL
{
    void CellRefLockEnter();
    void CellRefLockLeave();
    void SetLandscape(TESObjectLAND*);
    void FUN_005576c0();
    void FUN_00558ba0(TESObjectREFR*);
    void RemoveNonPersistentRefs();
};

// @fnv 0x005508b0
void TESObjectCELL::RemoveNonPersistentRefs()
{
    TESObjectLAND* pLand;
    {
        BSSimpleList* pPrevNode;
        NavMeshCollection* pNavMeshArray;
        CellRefLockEnter();
        *(unsigned short*)((char*)this + 0xa8) = 0;
        *(unsigned short*)((char*)this + 0xaa) = 0;
        {
            BSSimpleList* pNode;
            bool bOldAllow = g_BGSSaveLoadGame->SetThreadAllowChanges(false);
            FUN_005576c0();
            pNode = ((FUN_009604f0_shell*)this)->FUN_009604f0();
            pPrevNode = 0;
            while (pNode && !pNode->FUN_008256d0())
            {
                TESObjectREFR* pRef = *pNode->FUN_006815c0();
                if (!pRef->GetReferencePersistence() &&
                    (!((TESForm*)pRef)->GetFile(-1) || ((TESForm*)pRef)->GetFile(-1)->IsMasterFile()))
                {
                    if (pPrevNode)
                    {
                        pPrevNode->FUN_00905330(pRef);
                        pNode = pPrevNode->FUN_00726070();
                    }
                    else
                    {
                        pNode->FUN_0063f7b0();
                    }
                    DAT_011c95c8->FUN_005270b0(pRef);
                    if (pRef->IsActor())
                    {
                        MobileObject* pActor = (MobileObject*)pRef;
                        if (pActor->GetCurrentProcessLevel() == 0)
                            ((FUN_00881d10*)pActor)->SetHoursPassed();
                    }
                    g_TESSaveLoadGame->FUN_008d0370(pRef);
                    g_BGSSaveLoadGame->UnloadForm(pRef, 0);
                    bool bPrint = true;
                    if (g_BGSSaveLoadGame->FUN_0042ce10() &&
                        ((Class_0084a700*)g_BGSSaveLoadGame)->HasChangeForForm(pRef, CF845(8)) &&
                        ((S00561ef0*)pRef)->FUN_00561ef0(this))
                        bPrint = false;
                    if (((P01ObjA*)pRef)->GetNext() && ((P01ObjA*)pRef)->GetNext()->FNV_GetFormType() == 0x23)
                    {
                        FUN_00452440_shell* pBase = (FUN_00452440_shell*)((P01ObjA*)pRef)->GetNext();
                        if (pBase->FUN_00452440())
                            FUN_00558ba0(pRef);
                    }
                    if (bPrint && pRef != g_thePlayer)
                        FUN_00867f90(pRef);
                }
                else
                {
                    pPrevNode = pNode;
                    pNode = pNode->FUN_00726070();
                }
            }
            g_BGSSaveLoadGame->SetThreadAllowChanges(bOldAllow);
        }
        CellRefLockLeave();
        pLand = ((FakeCell*)this)->GetLandscape();
        if (pLand)
        {
            TESFile* pFile = ((TESForm*)pLand)->GetFile(-1);
            if (!pFile || pFile->IsMasterFile())
            {
                SetLandscape(0);
                pLand = 0;
            }
        }
        pNavMeshArray = ((EffectSetting*)this)->GetEffectID();
        if (pNavMeshArray)
        {
            AutoMemHelper memHelper(
                0x2e, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESObjectCELL.cpp", 0x2769);
            for (unsigned int i = 0; i < GetReferenceFlags(pNavMeshArray); i++)
            {
                TESFile* pNavFile = ((TESForm*)(NavMesh*)pNavMeshArray->GetNavMeshAt(i))->GetFile(-1);
                if (!pNavFile || pNavFile->IsMasterFile())
                {
                    NiPointer<NavMesh> apSearchNavMesh = pNavMeshArray->GetNavMeshAt(i);
                    g_BGSSaveLoadGame->UnloadForm(apSearchNavMesh.FUN_00458b50(), 0);
                    pNavMeshArray->RemoveAndCollect(i);
                    i--;
                }
            }
        }
    }
    ((S00551440*)this)->FUN_00551440(false);
}

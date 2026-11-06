
// fallout_shared/distant terrain system/bgsterrainmanager.cpp
#include "bgsterrainmanager_decls.h"

// Returns null if path is missing or not found, otherwise opens the file and returns the result of ReadAnimationFromStream on it.
// @fnv 0x004d52f0
BGSTerrainManager* LoadBGSTerrainManager(const char* path)
{
    BSFile* file = 0;
    if (!path || !FileFinder::Exist(path, 0, 0, 0xFFFFFFFF))
    {
        return 0;
    }
    file = FileFinder::GetFile(path, NiFile::READ_ONLY, 0x4000, 0x10);
    return ReadAnimationFromStream(file);
}

namespace fnv_006fd130 {
struct BGSDistantTreeBlock;
struct BGSTerrainChunk;
struct BGSTerrainNode;
struct NiCamera;
struct NiNode;
struct NiTexture;
struct TESObjectREFR;
struct TESWorldSpace;
struct BGSTerrainManager
{
    static BGSTerrainManager* GetActiveManager();
    static void SetTreeNode(NiNode*);
    static void DeallocateStaticNodes();
    static void SetEnabled(bool);
    static bool GetEnabled();
    void Update(void*, int);
    void UpdateMorphParameters(void*);
    TESWorldSpace* GetWorld();
    unsigned int GetRootLevel();
    unsigned int GetMaximumLevelWithGeometry();
    unsigned int GetMinimumLevel();
    unsigned int GetBlockLevel();
    static unsigned int GetTreeLevel();
    NiNode* GetLODRoot();
    NiNode* GetLODLandRoot();
    NiNode* GetLODObjectRoot();
    NiNode* GetWaterLODRoot();
    NiNode* GetTreeNode();
    bool GetHasLOD();
    BGSTerrainNode* GetRootTerrainNode();
    bool GetNeedsImmediateUpdate();
    void SetNeedsImmediateUpdate(bool);
    NiTexture* GetDiffuseTextureForPoint(void*);
    NiTexture* GetNormalTextureForPoint(void*);
    BGSTerrainChunk* GetChunkForPoint(void*);
    BGSDistantTreeBlock* GetDistantTreeBlockForPoint(void*);
    void AddTerrainReference(TESObjectREFR*);
    void UpdateTerrainReference(TESObjectREFR*, bool);
    void RemoveTerrainReference(TESObjectREFR*);
    void UpdateMultiBoundResults(NiCamera*);
    void ResetMultiBoundResults();
    void AddMultiBoundDebugLines(NiCamera*);
    void UnloadAll();
    void LoadAll();
    void RefreshTerrain();
    static void ShowMinimumDetail();
    static void ShowNormalDetail();
    static void EnableLODWaterProcessing(bool);
    static void DisableBlockVisibility();
    static void EnableBlockVisibility();
    bool QHasLOD();
    static bool GetCurrentWorldHasLOD();
    static void ClearMultiBoundResults();
    void* __vecDelDtor(unsigned int);
    TESWorldSpace* pWorld;
    BGSTerrainNode* pSortAdjustNode;
    char m_cTerrainHeaderBytes[4];
    char m_cTerrainBytesA[4];
    short m_sTerrainCoordinateA;
    short m_sTerrainCoordinateB;
    short m_sTerrainCoordinateC;
    short m_sTerrainCoordinateD;
    unsigned int m_uiTerrainValueD;
    unsigned int m_uiTerrainValueC;
    unsigned int m_uiTerrainValueA;
    unsigned int m_uiTerrainValueB;
    bool m_bTerrainFlagA;
    bool m_bTerrainFlagB;
    char _pad_2a[2];
    char m_cTerrainBytesB[16];
};
typedef char _sizecheck_BGSTerrainManager[sizeof(BGSTerrainManager) == 60 ? 1 : -1];
struct FUN_006fd130_shell : public BGSTerrainManager
{
    void FUN_006fd130();
};

void __cdecl FUN_006fa860();
void __cdecl FUN_006f5840();

// @fnv 0x006fd130
void FUN_006fd130_shell::FUN_006fd130()
{
    if (pSortAdjustNode)
    {
        FUN_006fa860();
        FUN_006f5840();
    }
}
}  // namespace fnv_006fd130

void __cdecl SetSoundListFlag(bool);

// @fnv 0x006fd1f0
void __cdecl FUN_006fd1f0(bool abEnable)
{
    SetSoundListFlag(abEnable);
}

extern int DAT_011d8598;

// @fnv 0x006fcda0
int __cdecl FUN_006fcda0()
{
    return DAT_011d8598;
}

struct FUN_006fd980_shell
{
    void UnloadDataRecurse(int);
};

struct FUN_006fce00_shell
{
    void FUN_006fce00();
};

// If the pointer at offset 4 is non-null, calls UnloadDataRecurse(7) on it.
// @fnv 0x006fce00
void __thiscall FUN_006fce00_shell::FUN_006fce00()
{
    if (*(int*)((char*)this + 4) != 0)
        (*(FUN_006fd980_shell**)((char*)this + 4))->UnloadDataRecurse(7);
}

struct BGSTerrainChunk
{
    int __thiscall FUN_006fceb0(int);
    int __thiscall FUN_006fabc0(int);
};

struct FUN_006fce30_shell : BGSTerrainChunk
{
    int FUN_006fce30(int abSomething);
};

// Looks up the terrain chunk for the given argument and, if found, returns the result of calling its method with 0; otherwise returns 0.
// @fnv 0x006fce30
int FUN_006fce30_shell::FUN_006fce30(int abSomething)
{
    int result = 0;
    BGSTerrainChunk* obj = (BGSTerrainChunk*)FUN_006fceb0(abSomething);
    if (obj)
    {
        result = obj->FUN_006fabc0(0);
    }
    return result;
}

struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct GlobalObject_00869f00
{
    void Remove(unsigned int, bool);
};
struct TESObjectREFR
{
};
struct FUN_006fcf30_shell
{
    void FUN_006fcf30(TESObjectREFR* apTreeRef);
};

// Scans the array at offset 0x2c for entries equal to apTreeRef and removes each match, decrementing the count.
// @fnv 0x006fcf30
void FUN_006fcf30_shell::FUN_006fcf30(TESObjectREFR* apTreeRef)
{
    unsigned int icount = ((ArrSI*)((char*)this + 0x2c))->GetFlags();
    unsigned int i = 0;
    while (i < icount)
    {
        if (((Arr*)((char*)this + 0x2c))->GetAt(i)[0] == (unsigned int)apTreeRef)
        {
            ((GlobalObject_00869f00*)((char*)this + 0x2c))->Remove(i, true);
            icount--;
        }
        else
        {
            i++;
        }
    }
}

struct BGSTerrainNode
{
    void __thiscall ProcessBlock();
};

struct FUN_006fd060_holder
{
    unsigned int m_00;
    BGSTerrainNode* m_04;
    void __thiscall FUN_006fd060();
};

// @fnv 0x006fd060
void __thiscall FUN_006fd060_holder::FUN_006fd060()
{
    m_04->ProcessBlock();
}

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern unsigned char DAT_0119f188;
extern GlobalObject_0045cf30 g_011d86ac;
struct FUN_006fea70_obj
{
    void SetValue(int);
};
struct Holder006fcdb0
{
    int m00;
    FUN_006fea70_obj* m04;
    void FUN_006fcdb0(int);
};
// If DAT_0119f188 is set, g_011d86ac.Bool() is true and m04 is non-null, forwards a1 to m04->SetValue.
// @fnv 0x006fcdb0
void Holder006fcdb0::FUN_006fcdb0(int a1)
{
    if (DAT_0119f188 && *g_011d86ac.Bool() && m04)
        m04->SetValue(a1);
}

struct FUN_006fce70_shell : BGSTerrainChunk
{
    int FUN_006fce70(int);
};
// @fnv 0x006fce70
int FUN_006fce70_shell::FUN_006fce70(int a1)
{
    int result = 0;
    BGSTerrainChunk* chunk = (BGSTerrainChunk*)FUN_006fceb0(a1);
    if (chunk)
        result = chunk->FUN_006fabc0(1);
    return result;
}

struct Unk006fec90
{
    int __thiscall GetActiveMenu(int);
};
// If the object at offset 4 exists, forwards a1 to its GetActiveMenu and returns the result; otherwise returns 0.
// @fnv 0x006fceb0
int BGSTerrainChunk::FUN_006fceb0(int a1)
{
    int unused = 0;
    if (*(Unk006fec90**)((char*)this + 4))
        return (*(Unk006fec90**)((char*)this + 4))->GetActiveMenu(a1);
    return 0;
}

struct FUN_006fed30_Callee
{
    int __thiscall GetTreeBlockForPoint(int);
};
struct FUN_006fcef0_shell
{
    int m_00;
    FUN_006fed30_Callee* m_04;
    int __thiscall ForwardToCallee(int);
};
// If m_04 is set, forwards a to m_04's GetTreeBlockForPoint and returns its result; otherwise returns 0.
// @fnv 0x006fcef0
int __thiscall FUN_006fcef0_shell::ForwardToCallee(int a)
{
    int unused = 0;
    if (m_04)
        return m_04->GetTreeBlockForPoint(a);
    return 0;
}

namespace fnv_006fd010 {
struct FUN_00485b60
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69();
    virtual int v70();
    virtual int v71();
    virtual int v72();
    virtual int v73();
    virtual int v74();
    virtual int v75();
    virtual int v76();
    virtual int v77();
    virtual int v78();
    virtual int v79();
    virtual int v80();
    virtual int v81();
    virtual int v82();
    virtual int v83();
    virtual int v84();
    virtual int v85();
    virtual int v86();
    virtual int v87();
    virtual int v88();
    virtual int v89();
    virtual int v90();
    virtual int v91();
    virtual int v92();
    virtual int v93();
    virtual int v94();
    virtual int v95();
    virtual int v96();
    virtual int v97();
    virtual int v98();
    virtual int v99();
    virtual int v100();
    virtual int v101();
    virtual int v102();
    virtual int v103();
    virtual int v104();
    virtual int v105();
    virtual int v106();
    virtual int v107();
    virtual int v108();
    virtual int v109();
    virtual int v110();
    virtual int v111();
    virtual int v112();
    virtual int v113();
    virtual int v114();
    virtual int v115();
    virtual int v116();
    virtual int v117();
    virtual int v118();
    virtual int v119();
    virtual int v120();
    virtual int v121();
    virtual int v122();
    virtual int v123();
    virtual int v124();
    virtual int v125();
    unsigned int Go();
};
struct FUN_006f92a0_shell
{
    void ClearInstanceFlag(unsigned int);
};
struct FUN_006fcef0_shell
{
    FUN_006f92a0_shell* ForwardToCallee(int);
};
struct FUN_006fd010_shell
{
    void RunAndDispatch(FUN_00485b60*);
};
// @fnv 0x006fd010
void FUN_006fd010_shell::RunAndDispatch(FUN_00485b60* a1)
{
    unsigned int tmp = a1->Go();
    {
        FUN_006f92a0_shell* p = ((FUN_006fcef0_shell*)this)->ForwardToCallee(a1->v125());
        if (p)
            p->ClearInstanceFlag(tmp);
    }
}
}  // namespace fnv_006fd010

struct S_00587f40_Lock
{
    void FUN_004538a0(int a);
    void FUN_004538c0();
};
extern S_00587f40_Lock DAT_011ca60c;

struct S_00587f40_List
{
    int unk00;
    int unk04;
    void RemoveAll();
    ~S_00587f40_List();
};

struct S_00587f40_Map
{
    void* GetFirstPos();
    void GetNext(void*& pos, unsigned int& key, S_00587f40_List*& val);
    void RemoveAll();
};

struct S_00587f40
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
    S_00587f40_Map m_map;
    int unk54;
    int unk58;
    int unk5C;
    S_00587f40_List m_kNode;
    void ClearAllLists();
};

// @fnv 0x00587f40
void S_00587f40::ClearAllLists()
{
    DAT_011ca60c.FUN_004538a0(0);
    m_kNode.RemoveAll();
    void* pos = m_map.GetFirstPos();
    while (pos)
    {
        unsigned int key = 0;
        S_00587f40_List* list = 0;
        m_map.GetNext(pos, key, list);
        if (list)
        {
            list->RemoveAll();
            delete list;
        }
    }
    m_map.RemoveAll();
    DAT_011ca60c.FUN_004538c0();
}

struct Dfcfa0Ref
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual int GetBlock();
    int __thiscall Go();
};
template <class T, unsigned int N> struct BSSimpleArray
{
    unsigned int Add(const T& value);
};
struct Dfcfa0Manager : FUN_006fcef0_shell
{
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    BSSimpleArray<TESObjectREFR*, 0x400> pending;
    void FUN_006fcfa0(Dfcfa0Ref* ref, bool addIfMissing);
};
struct BGSDistantTreeBlock
{
    void MarkTreeInstance(unsigned int a, bool update);
};
// @fnv 0x006fcfa0
void Dfcfa0Manager::FUN_006fcfa0(Dfcfa0Ref* ref, bool addIfMissing)
{
    unsigned int formId = ref->Go();
    int block = ForwardToCallee(ref->GetBlock());
    if (block)
    {
        ((BGSDistantTreeBlock*)block)->MarkTreeInstance(formId, true);
    }
    else if (addIfMissing)
    {
        pending.Add((TESObjectREFR*&)ref);
    }
}

struct NiPoint3
{
    float x, y, z;
};
struct tagRECT
{
    long left, top, right, bottom;
};
void __cdecl SetRectCenterAndHalfExtents(tagRECT*);

struct TES
{
    void FUN_00451020(tagRECT*, float);
    void FUN_0045cac0();
};
extern TES* g_TES;

struct NiNode
{
    void FUN_00572160();
};
struct NiNodeHolder
{
    operator NiNode*() const;
};
extern NiNodeHolder DAT_011d86bc;
extern GlobalObject_0045cf30 DAT_011d869c;
extern GlobalObject_0045cf30 DAT_011d8680;

struct RefObj
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04C();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09C();
    virtual void vf0A0();
    virtual void vf0A4();
    virtual void vf0A8();
    virtual void vf0AC();
    virtual void vf0B0();
    virtual void vf0B4();
    virtual void vf0B8();
    virtual void vf0BC();
    virtual void vf0C0();
    virtual void vf0C4();
    virtual void vf0C8();
    virtual void vf0CC();
    virtual void vf0D0();
    virtual void vf0D4();
    virtual void vf0D8();
    virtual void vf0DC();
    virtual void vf0E0();
    virtual void vf0E4();
    virtual void vf0E8();
    virtual void vf0EC();
    virtual void vf0F0();
    virtual void vf0F4();
    virtual void vf0F8();
    virtual void vf0FC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14C();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15C();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16C();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17C();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18C();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19C();
    virtual void vf1A0();
    virtual void vf1A4();
    virtual void vf1A8();
    virtual void vf1AC();
    virtual void vf1B0();
    virtual void vf1B4();
    virtual void vf1B8();
    virtual void vf1BC();
    virtual void vf1C0();
    virtual void vf1C4();
    virtual void vf1C8();
    virtual void vf1CC();
    virtual void vf1D0();
    virtual void vf1D4();
    virtual void vf1D8();
    virtual void vf1DC();
    virtual void vf1E0();
    virtual void vf1E4();
    virtual void vf1E8();
    virtual void vf1EC();
    virtual void vf1F0();
    virtual int vf1F4();
    unsigned int FUN_00485b60();
};

struct DistantTreeBlock
{
    void MarkTreeInstance(unsigned int, bool);
};

struct LodNode
{
    void UpdateTerrainNode(const NiPoint3&, bool);
    void UpdateBlock(const NiPoint3&, bool);
    void UpdateTrees(const NiPoint3&);
};

struct RefArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    RefObj*& FUN_00877a30(unsigned int);
    unsigned int FUN_0044ddc0();
    void FUN_008454f0(bool);
    void FUN_006f2290(unsigned int, bool);
    void FUN_0047a110(unsigned int, RefObj* const&);
};

struct LocalRefArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LocalRefArray();
    ~LocalRefArray();
    unsigned int FUN_0044ddc0();
    void FUN_007cb2e0(RefObj* const&);
    RefObj*& FUN_006a7ad0(unsigned int);
};

class BGSTerrainManager
{
  public:
    void* world;
    LodNode* lodNode;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    unsigned char byte28;
    unsigned char byte29;
    unsigned char byte2A;
    unsigned char byte2B;
    RefArray array2C;

    void FUN_006fca90(const NiPoint3& arPos, int aiFlags);
    void FUN_006fce00();
    DistantTreeBlock* ForwardToCallee(int);
};

extern BGSTerrainManager* DAT_011d8670;

// @fnv 0x006fca90
void BGSTerrainManager::FUN_006fca90(const NiPoint3& arPos, int aiFlags)
{
    if (DAT_0119f188 && *g_011d86ac.Bool())
    {
        NiPoint3 pos = arPos;
        aiFlags |= 1;
        tagRECT rect;
        g_TES->FUN_00451020(&rect, 0.0f);
        SetRectCenterAndHalfExtents(&rect);
        if (DAT_011d8670 && DAT_011d8670 != this)
        {
            BGSTerrainManager* pOld = DAT_011d8670;
            DAT_011d8670 = this;
            pOld->FUN_006fce00();
            if (DAT_011d86bc)
            {
                ((NiNode*)DAT_011d86bc)->FUN_00572160();
            }
        }
        DAT_011d8670 = this;
        if (lodNode)
        {
            bool b1 = (aiFlags & 1) != 0;
            bool b2 = (aiFlags & 2) != 0;
            bool b4 = (aiFlags & 4) != 0;
            bool m_bShaderFeatureActive = (aiFlags & 8) != 0;
            if (b1)
            {
                lodNode->UpdateTerrainNode(pos, b4);
                g_TES->FUN_0045cac0();
                if (*DAT_011d869c.Bool())
                {
                    lodNode->UpdateBlock(pos, b2);
                }
            }
            if (m_bShaderFeatureActive && *DAT_011d8680.Bool())
            {
                unsigned int count;
                lodNode->UpdateTrees(pos);
                if (FUN_006fcda0() > 0u && array2C.FUN_0044ddc0() > 0)
                {
                    LocalRefArray kept;
                    count = array2C.FUN_0044ddc0();
                    for (unsigned int i = 0; i < count; i++)
                    {
                        unsigned int val = array2C.FUN_00877a30(i)->FUN_00485b60();
                        DistantTreeBlock* pBlock = ForwardToCallee(array2C.FUN_00877a30(i)->vf1F4());
                        if (pBlock)
                        {
                            pBlock->MarkTreeInstance(val, true);
                        }
                        else
                        {
                            kept.FUN_007cb2e0(array2C.FUN_00877a30(i));
                        }
                    }
                    array2C.FUN_008454f0(true);
                    if (kept.FUN_0044ddc0() > 0)
                    {
                        unsigned int keptCount = kept.FUN_0044ddc0();
                        array2C.FUN_006f2290(keptCount, true);
                        for (unsigned int j = 0; j < keptCount; j++)
                        {
                            array2C.FUN_0047a110(j, kept.FUN_006a7ad0(j));
                        }
                    }
                }
            }
        }
    }
    byte28 = 0;
}

class TerrainRefProxy
{
  public:
    unsigned int GetRawId();
};

class TerrainTempBuffer
{
  public:
    TerrainTempBuffer(int aInit);
    ~TerrainTempBuffer();
    void Push(TerrainRefProxy* apRef);
    void Assign(unsigned int aValue);

    unsigned int m_00, m_04, m_08, m_0C, m_10, m_14, m_18, m_1C, m_20;
    unsigned int m_24, m_28, m_2C, m_30, m_34, m_38, m_3C, m_40, m_44;
    unsigned int m_48, m_4C, m_50, m_54, m_58, m_5C, m_60, m_64, m_68;
    unsigned int m_6C, m_70, m_74, m_78, m_7C, m_80, m_84, m_88;
};

void __cdecl UpdateSceneEntryRadii(TerrainRefProxy* apRef, TerrainTempBuffer* apBuf);
void __cdecl FUN_006f5840();

class TerrainStream
{
  public:
    unsigned int m_00;
    unsigned int* m_04;

    void PushRef(TerrainRefProxy* apRef);
};

// @fnv 0x006fd080
void TerrainStream::PushRef(TerrainRefProxy* apRef)
{
    TerrainTempBuffer tempBuffer(0);
    tempBuffer.Push(apRef);
    tempBuffer.Assign(apRef->GetRawId());
    if (m_04 != 0)
    {
        UpdateSceneEntryRadii(apRef, &tempBuffer);
        FUN_006f5840();
    }
}

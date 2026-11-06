
// fallout_shared/distant terrain system/bgsterrainnode.cpp
// BGSTerrainNode::BGSTerrainNode (0x006fd210).
//
// Recursive distant-terrain quad-tree node constructor: nulls the payload
// pointers, derives the node center/corner radius from the base cell and
// level size, subdivides while above the manager minimum, then derives the
// split/morph distances from the [TerrainManager] INI mults.

#include "bgsterrainnode.h"

const char kBGSTerrainNodeFileLabel[] =
    "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSTerrainNode.cpp";
const int kBGSTerrainNodeCtorLine = 76;
const char kInvalidMorphDistances[] =
    "MODELS: Morph distances are invalid.  Please ensure that fMorphDistanceMult is less than fSplitDistanceMult under [TerrainManager] in the INI (or delete both)";

// Initializes a terrain node: stores manager/parent/level/coords, computes center and distances, and recursively creates four child nodes unless at min level.
// @fnv 0x006fd210
BGSTerrainNode::BGSTerrainNode(BGSTerrainManager* pManagerArg, BGSTerrainNode* pParentArg, short sX, short sY,
                               unsigned int uiSize, bool bPersistentArg)
{
    AutoMemContext fCornerX(MEM_CONTEXT_MEM_CONTEXT_LODMANAGER, true, kBGSTerrainNodeFileLabel,
                            kBGSTerrainNodeCtorLine);
    m_bNodeInitialized = true;
    pChunk = 0;
    pBlock = 0;
    pTrees = 0;
    pManager = pManagerArg;
    pParent = pParentArg;
    iLevel = uiSize;
    m_sX = sX;
    m_sY = sY;
    for (int i = 0; i < 4; i++)
        pChildren[i] = 0;
    if (uiSize <= pManager->GetMaxLevel())
        m_bWithinMaximumLevel = true;
    else
        m_bWithinMaximumLevel = false;
    float fCenterX = (float)(iLevel << 12);
    float fCornerY = m_sX * 4096.0 + fCenterX * 0.5;
    float fZ = m_sY * 4096.0 + fCenterX * 0.5;
    float fMin = m_sX * 4096.0;
    float kCtx = m_sY * 4096.0;
    NiPoint3 corner(fMin, kCtx, 0.0f);
    Center = NiPoint3(fCornerY, fZ, 0.0f);
    m_fNodeRadius = (Center - corner).ComputeMagnitude();
    m_bPersistent = bPersistentArg;
    if (uiSize > pManager->GetMinLevel())
    {
        unsigned int uH = iLevel >> 1;
        short sMX = m_sX + (iLevel >> 1);
        short sMid = m_sY + (iLevel >> 1);
        bool bChildPersistent = false;
        if (bKeepLowDetailTerrain.Bool()->b && uH == pManager->GetMaxLevel())
            bChildPersistent = true;
        pChildren[0] = new BGSTerrainNode(pManager, this, m_sX, m_sY, uH, bChildPersistent);
        pChildren[1] = new BGSTerrainNode(pManager, this, m_sX, sMid, uH, bChildPersistent);
        pChildren[2] = new BGSTerrainNode(pManager, this, sMX, m_sY, uH, bChildPersistent);
        pChildren[3] = new BGSTerrainNode(pManager, this, sMX, sMid, uH, bChildPersistent);
        pChildren[0]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_UPPER_LEFT;
        pChildren[1]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_LOWER_LEFT;
        pChildren[2]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_UPPER_RIGHT;
        pChildren[3]->m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_LOWER_RIGHT;
        m_fSplitDistance = m_fNodeRadius * fSplitDistanceMult.Float()->f;
    }
    else
    {
        memset(pChildren, 0, sizeof(pChildren));
        m_fSplitDistance = 0.0f;
    }
    if (pParent)
    {
        m_fMorphStartDistance = pParent->m_fNodeRadius * fMorphStartDistanceMult.Float()->f;
        m_fMorphEndDistance = pParent->m_fNodeRadius * fMorphEndDistanceMult.Float()->f;
        if (m_fMorphEndDistance > m_fMorphStartDistance)
            Warning(kInvalidMorphDistances);
    }
    else
    {
        m_fMorphStartDistance = FLT_MIN;
        m_fMorphEndDistance = FLT_MAX;
        m_eParentPosition = BGSTerrainNode__PARENT_POSITION_PP_TOPLEVEL;
    }
    m_bNodeStateFlag = false;
}

struct BSSimpleListX
{
    bool IsEmpty();
};
struct FileX
{
    BSSimpleListX* FUN_00464df0();
};
struct FUN_00485b60
{
    unsigned int FUN_00485bc0();
    FileX* GetFile(int);
    unsigned int Go();
};
// Calls FUN_00485bc0, checks whether the first file's list is non-empty, and ORs that flag into bit 24 of the result.
// @fnv 0x00485b60
unsigned int FUN_00485b60::Go()
{
    char flag;
    unsigned int result;
    FileX* file;
    result = FUN_00485bc0();
    flag = 0;
    file = GetFile(0);
    if (!file->FUN_00464df0()->IsEmpty())
        flag = 1;
    result |= flag << 24;
    return result;
}

struct FUN_006fca40
{
    void* Del(unsigned int);
};
struct UnloadData
{
    void Go(int);
};
struct FUN_006fd750
{
    void Unload();
};
// Calls Go(7), then for each of the four pointers at offset 0x20 calls Del(1) on the non-null ones.
// @fnv 0x006fd750
void FUN_006fd750::Unload()
{
    ((UnloadData*)this)->Go(7);
    for (int i = 0; i < 4; i++)
    {
        FUN_006fca40* c = ((FUN_006fca40**)((char*)this + 0x20))[i];
        FUN_006fca40* p = c;
        p ? p->Del(1) : 0;
    }
}

extern int DAT_011d8670;

// @fnv 0x006fd8e0
int __cdecl FUN_006fd8e0()
{
    return DAT_011d8670;
}

void __cdecl operator delete(void*);
struct FUN_006fa420
{
    void Dtor();
};
struct FUN_006fd8f0
{
    void* Del(unsigned int flags);
};
// Calls Dtor on this object, frees it with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006fd8f0
void* FUN_006fd8f0::Del(unsigned int flags)
{
    ((FUN_006fa420*)this)->Dtor();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_006f5370
{
    void Dtor();
};
struct FUN_006fd920
{
    void* Del(unsigned int flags);
};
// Calls Dtor on this object, frees it with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006fd920
void* FUN_006fd920::Del(unsigned int flags)
{
    ((FUN_006f5370*)this)->Dtor();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __cdecl operator delete(void*);
struct FUN_006f76b0
{
    void Dtor();
};
struct FUN_006fd950
{
    void* Del(unsigned int flags);
};
// Calls Dtor on this, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006fd950
void* FUN_006fd950::Del(unsigned int flags)
{
    ((FUN_006f76b0*)this)->Dtor();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FUN_006fd980_shell;
struct Mgr
{
    FUN_006fd980_shell* _ref_00726070();
};
void FUN_006f83f0();
struct FUN_006fd980_shell
{
    Mgr* pManager;
    int f4, f8;
    char fc;
    char m_bNodeStateFlag;
    char fe, ff;
    void* pChunk;
    void* pBlock;
    int f18, f1c;
    FUN_006fd980_shell* pChildren[4];
    void UnloadData(int a);
    void UnloadDataRecurse(int a);
};
// @fnv 0x006fd980
void FUN_006fd980_shell::UnloadDataRecurse(int aiFlags)
{
    if (pChunk || pBlock)
        UnloadData(aiFlags);
    for (int i = 0; i < 4; i++)
    {
        if (pChildren[i])
            pChildren[i]->UnloadDataRecurse(aiFlags);
    }
    m_bNodeStateFlag = 0;
    if (aiFlags & 4)
    {
        if (this == pManager->_ref_00726070())
            FUN_006f83f0();
    }
}

struct NiObj;
struct GO
{
    NiObj* p;
    GO(int p);
    ~GO();
    operator NiObj*() const;
};
struct FUN_006fe280_shell
{
    int f0;
    GO m;
    NiObj* GetNiObj(bool b);
};
// Returns a NiObj pointer: a null-initialized GO when b is true, otherwise the stored m member.
// @fnv 0x006fe280
NiObj* FUN_006fe280_shell::GetNiObj(bool abNull)
{
    return (abNull ? GO(0) : m);
}

struct FUN_006ff0a0
{
    bool Chk(int idx);
};
struct Ent
{
    int a;
    void* b;
    int c;
    int d;
    int e;
};
// Returns true when the Ent at index idx in the array at this+0xc4 has a null b pointer.
// @fnv 0x006ff0a0
bool FUN_006ff0a0::Chk(int aiIndex)
{
    return (*(Ent**)((char*)this + 0xc4))[aiIndex].b == 0;
}

struct NiPoint2
{
    float x, y;
    NiPoint2(float a, float b);
};
struct FUN_006ff210_shell
{
    char pad[0x58];
    int mode;
    NiPoint2 FUN_006ff210();
};
// Returns a NiPoint2 chosen from the mode field: (0.5,0), (0.5,0.5), (0,0) or (0,0.5), defaulting to (0,0).
// @fnv 0x006ff210
NiPoint2 FUN_006ff210_shell::FUN_006ff210()
{
    float x, y;
    switch (mode)
    {
    case 1:
        x = 0.5f;
        y = 0.0f;
        break;
    case 3:
        x = 0.5f;
        y = 0.5f;
        break;
    case 2:
        x = 0.0f;
        y = 0.0f;
        break;
    case 4:
        x = 0.0f;
        y = 0.5f;
        break;
    default:
        x = y = 0.0f;
        break;
    }
    return NiPoint2(x, y);
}

namespace fnv_006ff2c0 {
struct NiNode
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void SetBool(int a, int b, int c) = 0;
    void FUN_006fb940(float a, float b, float c);
};
struct Tile
{
    NiNode* FUN_0056c7f0();
};
struct NiPoint2
{
    float x, y;
};
struct Chunk
{
    int FUN_006fabc0(int i);
};
struct Holder
{
    int f0, f4, f8, fc;
    Chunk* chunk;
};
struct AnimIdle
{
    int GetSection();
};
extern AnimIdle g_timeGlobal;
struct FUN_006ff2c0_shell
{
    char pad[0x10];
    Tile* tile;
    char pad2[0x30 - 0x14];
    Holder* holder;
    char pad3[0x50 - 0x34];
    int section;
    bool flag;
    NiPoint2 FUN_006ff210();
    void UpdateTileFromChunk();
};
// @fnv 0x006ff2c0
void FUN_006ff2c0_shell::UpdateTileFromChunk()
{
    int c;
    NiNode* b;
    int a;
    c = holder->chunk->FUN_006fabc0(0);
    a = holder->chunk->FUN_006fabc0(1);
    b = tile->FUN_0056c7f0();
    if (b)
    {
        b->SetBool(0, 1, c);
        b->SetBool(1, 1, a);
        NiPoint2 pt = FUN_006ff210();
        section = g_timeGlobal.GetSection();
        b->FUN_006fb940(pt.x, pt.y, 0.0f);
        flag = true;
    }
}
}  // namespace fnv_006ff2c0

struct NiNode
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void SetBool(int a, int b, int c) = 0;
    void FUN_006fb940(float a, float b, float c);
};
struct Tile
{
    NiNode* FUN_0056c7f0();
};
struct Tile;
struct FUN_006ff380_shell
{
    int f0, f4, f8, fc;
    Tile* tile;
    int f14, f18, f1c, f20, f24, f28, f2c, f30, f34, f38, f3c, f40, f44, f48, f4c, f50;
    char flag;
    void FUN_006ff380();
};
// @fnv 0x006ff380
void FUN_006ff380_shell::FUN_006ff380()
{
    NiNode* node;
    flag = 0;
    node = tile->FUN_0056c7f0();
    if (node)
    {
        node->FUN_006fb940(0.0f, 0.0f, 1.0f);
        node->SetBool(0, 1, 0);
        node->SetBool(1, 1, 0);
    }
}

namespace fnv_006ff4c0 {
struct Inner
{
    unsigned int Conv() const;
};
struct Mgr
{
    unsigned int GetThreadID();
};
struct Block
{
    void FUN_006f6270(unsigned int a, unsigned int b, unsigned short c, unsigned short d);
};
struct FUN_006ff4c0_shell
{
    Mgr* pManager;
    unsigned int iLevel;
    unsigned short m_sX;
    unsigned short m_sY;
    int fc, f10;
    Block* pBlock;
    int f18, f1c;
    FUN_006ff4c0_shell* pChildren[4];
    unsigned int _ref_00726070();
    Inner* Conv() const;
    void ProcessBlock();
};
// @fnv 0x006ff4c0
void FUN_006ff4c0_shell::ProcessBlock()
{
    if (_ref_00726070() == pManager->GetThreadID() && pBlock)
    {
        pBlock->FUN_006f6270(Conv()->Conv(), iLevel, m_sX, m_sY);
    }
    else if (_ref_00726070() > pManager->GetThreadID())
    {
        for (int i = 0; i < 4; i++)
        {
            if (pChildren[i])
                pChildren[i]->ProcessBlock();
        }
    }
}
}  // namespace fnv_006ff4c0

struct FUN_006fda10_shell
{
    void* pad0[4];
    FUN_006fd8f0* pChunk;  // +0x10
    void* pad14[3];
    FUN_006fda10_shell* pChildren[4];  // +0x20
    char pad30[0x2c];
    bool m_bPersistent;  // +0x5c

    void UnloadPersistentDataRecurse();
};

// @fnv 0x006fda10
void FUN_006fda10_shell::UnloadPersistentDataRecurse()
{
    int i;

    if (pChunk && m_bPersistent)
    {
        FUN_006fd8f0* b = pChunk;
        FUN_006fd8f0* a = b;
        a ? a->Del(1) : 0;
        pChunk = 0;
    }

    for (i = 0; i < 4; i++)
    {
        if (pChildren[i])
            pChildren[i]->UnloadPersistentDataRecurse();
    }
}

struct AnimIdle
{
    int GetSection();
};

struct GameTimerRecord : AnimIdle
{
};
extern GameTimerRecord g_timeGlobal;

struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 g_011d8740;

struct FUN_006ff3f0_shell : FUN_006ff380_shell
{
    void FUN_006ff3f0();
};

// @fnv 0x006ff3f0
void FUN_006ff3f0_shell::FUN_006ff3f0()
{
    unsigned int delta;
    unsigned int section = g_timeGlobal.GetSection();
    delta = section - f50;

    if (!tile || !tile->FUN_0056c7f0())
        return;

    if (delta > (unsigned int)*g_011d8740.Int())
    {
        FUN_006ff380();
    }
    else
    {
        float f = (double)delta / (unsigned int)*g_011d8740.Int();
        NiPoint2 pt = ((FUN_006ff210_shell*)this)->FUN_006ff210();
        tile->FUN_0056c7f0()->FUN_006fb940(pt.x, pt.y, f);
    }
}

struct ClearPartA
{
    int unk00;
    ~ClearPartA();
    void SetAllAppCulled();
};
struct ClearPartB
{
    int unk00;
    ~ClearPartB();
};
struct ClearPartC
{
    int unk00;
    ~ClearPartC();
};
struct ClearFlagHolder
{
    int unk00;
    int unk04;
    int unk08;
    char cUnk0C;
    bool bActive;
};
int __cdecl FUN_006fd8e0();

struct FUN_006fd7b0_Owner
{
    int m_uiClearFlags;
    int unk04;
    int unk08;
    bool bInitialized;
    ClearPartA* pPartA;
    ClearPartB* pPartB;
    ClearPartC* pPartC;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    ClearFlagHolder* pFlagHolder;
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
    bool bCheckOwner;

    void UnloadData(unsigned int auiFlags);
};

// Deletes pPartA/pPartB/pPartC according to auiFlags bits, conditionally keeping pPartA, and clears pFlagHolder->bActive.
// @fnv 0x006fd7b0
void FUN_006fd7b0_Owner::UnloadData(unsigned int auiFlags)
{
    if (bInitialized && pPartA && (auiFlags & 1))
    {
        if (!bCheckOwner || m_uiClearFlags != FUN_006fd8e0() || auiFlags == 7)
        {
            delete pPartA;
            pPartA = 0;
        }
        else
            pPartA->SetAllAppCulled();
    }
    if (pPartB && (auiFlags & 2))
    {
        delete pPartB;
        pPartB = 0;
    }
    if (pPartC && (auiFlags & 4))
    {
        delete pPartC;
        pPartC = 0;
    }
    if (pFlagHolder)
        pFlagHolder->bActive = false;
}

struct TerrainUpdate;
struct SceneUpdate
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual SceneUpdate* CastNode(int) = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void Refresh() = 0;
    void SetTaskFlag2000(bool);
    void FUN_00507700(float);
    void FUN_00450f90(bool);
};
struct WorldUpdate
{
    bool GetParentUseFlag(int);
};
struct TerrainMgrUpdate
{
    unsigned int GetDaysPassed();
};
struct ChunkUpdate
{
    int f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28, f2c;
    ChunkUpdate(TerrainUpdate*, unsigned int, short, short);
    bool FUN_00759d80();
    bool GetInitialized();
    void FUN_006facb0();
    void FUN_006fb760();
    SceneUpdate* GetRoot();
    SceneUpdate* FUN_0056c7f0();
    SceneUpdate* GetMenuRoot();
    SceneUpdate* GetObject3D();
};
struct WorldRefUpdate
{
    WorldUpdate* Get();
    SceneUpdate* GetMenuRoot();
};
struct TESUpdate
{
    WorldUpdate* GetHitSound();
};
extern TESUpdate* g_TES;
struct GlobalObject_0044f440
{
    float* Float();
};
extern GlobalObject_0044f440 g_011d86f8;
struct TerrainUpdate
{
    TerrainMgrUpdate* manager;
    unsigned int level;
    short cellX, cellY;
    bool hasGeometry, childrenLoaded;
    unsigned char f0e, f0f;
    ChunkUpdate* chunk;
    void* block;
    void* trees;
    SceneUpdate* scene;
    TerrainUpdate* children[4];
    TerrainUpdate* parent;
    float x, y, z, radius, split, startMorph, endMorph;
    unsigned int fadeStart;
    bool fading;
    unsigned char f55, f56, f57;
    int position;
    bool persistent, splitNode;
    unsigned char f5e, f5f;
    void UpdateTerrainNode(void*, bool);
    bool FUN_006fe550(void*);
    bool GetByteAtOffset5C();
    bool FUN_006fe920(bool);
    void UpdateTileFromChunk();
    void UnloadData(int);
    void UnloadDataRecurse(int);
    WorldRefUpdate* Get();
    bool FUN_006fede0();
    void UpdateVisibility(SceneUpdate*);
};
// Recursively updates a terrain node: decides split vs geometry state, creates or refreshes its chunk, and updates child nodes and scene objects.
// @fnv 0x006fdaa0
void TerrainUpdate::UpdateTerrainNode(void* arg, bool update)
{
    AutoMemContext context4((MEM_CONTEXT)35, true, kBGSTerrainNodeFileLabel, 284);
    bool below2 = manager->GetDaysPassed() < level;
    bool splitNow2 = FUN_006fe550(arg);
    if (splitNow2 && GetByteAtOffset5C() && chunk && !chunk->FUN_00759d80())
        chunk->FUN_006facb0();
    if (below2 || splitNow2)
    {
        splitNode = true;
        if (GetByteAtOffset5C() && !chunk)
            chunk = new ChunkUpdate(this, level, cellX, cellY);
        for (int childIndex2 = 0; childIndex2 < 4; childIndex2++)
        {
            if (children[childIndex2])
                children[childIndex2]->UpdateTerrainNode(arg, update);
        }
        if (chunk && FUN_006fe920(true))
        {
            for (int loadedIndex2 = 0; loadedIndex2 < 4; loadedIndex2++)
            {
                if (children[loadedIndex2]->chunk && children[loadedIndex2]->chunk->GetInitialized())
                    children[loadedIndex2]->UpdateTileFromChunk();
            }
            UnloadData(1);
        }
        if (FUN_006fe920(true))
            childrenLoaded = true;
    }
    else if (hasGeometry)
    {
        SceneUpdate* oldRoot = chunk ? chunk->GetRoot() : 0;
        splitNode = false;
        if (!chunk)
            chunk = new ChunkUpdate(this, level, cellX, cellY);
        else
        {
            bool unusedState5 = false;
            if (chunk->GetInitialized() && chunk->FUN_00759d80() && GetByteAtOffset5C())
                chunk->FUN_006fb760();
            if (chunk->GetInitialized() && !chunk->FUN_00759d80() && (!parent || parent->FUN_006fe920(true)))
            {
                chunk->FUN_006facb0();
                chunk->FUN_0056c7f0()->FUN_00507700((float)((level / 4.0) * *g_011d86f8.Float()));
                SceneUpdate* root7 = Get()->GetMenuRoot();
                root7->SetTaskFlag2000(false);
                root7->Refresh();
                root7->SetTaskFlag2000(true);
            }
        }
        if (chunk->FUN_00759d80() && childrenLoaded)
        {
            for (int unloadIndex4 = 0; unloadIndex4 < 4; unloadIndex4++)
                if (children[unloadIndex4])
                    children[unloadIndex4]->UnloadDataRecurse(1);
            childrenLoaded = false;
        }
        if (oldRoot && Get()->Get() != g_TES->GetHitSound())
        {
            WorldUpdate* worldVal = g_TES->GetHitSound();
            if (worldVal->GetParentUseFlag(1) && !worldVal->GetParentUseFlag(0) && FUN_006fede0())
                oldRoot->FUN_00450f90(true);
        }
        if (update && chunk)
        {
            SceneUpdate* geometryB = chunk->GetMenuRoot();
            SceneUpdate* objects3 = chunk->GetObject3D();
            if (geometryB)
                UpdateVisibility(geometryB->CastNode(0));
            if (objects3)
                UpdateVisibility(objects3->CastNode(0));
        }
    }
}

extern const char kBGSTerrainNodeFileLabel[];

class BGSDistantTreeBlock
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C,
        unk40, unk44, unk48;
    BGSDistantTreeBlock(BGSTerrainNode* pNode, unsigned int uiTreeBlockIndex, unsigned short sX, unsigned short sY);
    ~BGSDistantTreeBlock();
    bool IsLoaded();
    void Prepare();
    void Attach();
};

struct TerrainSceneX
{
    const char* GetName();
};

unsigned int TerrainTreeLevelX();
bool TerrainTreesEnabledX();
void TerrainTreesInitX(const char* pName);

struct TerrainNodeX : BGSTerrainNode
{
    unsigned int GetLevel();
    TerrainSceneX* GetOwner();
    bool WantsTrees(int iArg);
    void UpdateTrees(int iArg);
};

// @fnv 0x006fe330
void TerrainNodeX::UpdateTrees(int iArg)
{
    AutoMemContext kMemContext((MEM_CONTEXT)0x25, true, kBGSTerrainNodeFileLabel, 0x1ed);
    if (GetLevel() == TerrainTreeLevelX())
    {
        if (!TerrainTreesEnabledX())
        {
            TerrainTreesInitX(GetOwner()->GetName());
        }
        if (WantsTrees(iArg))
        {
            if (pTrees == 0)
            {
                pTrees = new BGSDistantTreeBlock(this, iLevel, m_sX, m_sY);
            }
            else if (pTrees != 0)
            {
                if (pTrees->IsLoaded())
                {
                    pTrees->Prepare();
                    pTrees->Attach();
                }
            }
        }
        else if (pTrees != 0)
        {
            delete pTrees;
            pTrees = 0;
        }
    }
    else if (GetLevel() > TerrainTreeLevelX())
    {
        for (int i = 0; i < 4; i++)
        {
            if (pChildren[i] != 0)
            {
                ((TerrainNodeX*)pChildren[i])->UpdateTrees(iArg);
            }
        }
    }
}

namespace fnv_006ff0d0 {
class TESObjectCELL;

class TESWorldSpaceX
{
  public:
    TESObjectCELL* GetCellAt(int x, int y);
};

class TES
{
  public:
    TESWorldSpaceX* GetParentWorldSpace();
    bool IsCellBuffered(TESObjectCELL* cell, bool b);
};
extern TES* g_TES;

class TerrainVisibility
{
  public:
    unsigned int GetCount();
    bool Chk(int idx);
    void Hide(unsigned int idx);
    void Show(unsigned int idx);
    void Finish();
    void Reset();
};

class TerrainNodeX
{
  public:
    void* pManager;
    unsigned int iLevel;
    short m_sX;
    short m_sY;
    bool IsReady();
    void UpdateVisibility(TerrainVisibility* pVisArg, int unused);
};

// @fnv 0x006ff0d0
void TerrainNodeX::UpdateVisibility(TerrainVisibility* pVisibility, int unused)
{
    TESWorldSpaceX* pWorld = g_TES->GetParentWorldSpace();
    TerrainVisibility* pVis3 = pVisibility;
    if (pVis3)
    {
        if (IsReady())
        {
            for (unsigned int i = 0; i < iLevel; i++)
            {
                for (unsigned int j_ = 0; j_ < iLevel; j_++)
                {
                    if (iLevel * i + j_ < pVis3->GetCount())
                    {
                        int x5 = m_sX + i;
                        int y3 = m_sY + j_;
                        unsigned int idx5 = iLevel * i + j_;
                        TESObjectCELL* pCell4 = pWorld->GetCellAt(x5, y3);
                        if (!pVis3->Chk(idx5) && g_TES->IsCellBuffered(pCell4, true))
                            pVis3->Hide(idx5);
                        else
                            pVis3->Show(idx5);
                    }
                }
            }
            pVis3->Finish();
        }
        else
        {
            pVis3->Reset();
        }
    }
}
}  // namespace fnv_006ff0d0

extern "C" char DAT_0106e4e0;
struct FUN_00404eb0
{
    int x;
    FUN_00404eb0(int, bool, char*, int);
    ~FUN_00404eb0();
};
struct Thread006f
{
    unsigned FUN_0059bb30();
};
struct Ret006f
{
    Ret006f* FUN_00559450();
};
struct Node006f;
struct FUN_006f5160
{
    char data[0x2c];
    FUN_006f5160(Node006f*, int, unsigned short, unsigned short, bool);
    ~FUN_006f5160();
    void* GetNiObj(bool);
    unsigned char FUN_00529ea0();
    void FUN_006f5ca0();
    unsigned char GetByteAtOffset35();
    void ResetAndCreateTask(Ret006f*, int, unsigned short, unsigned short);
    void FUN_006f6540(Ret006f*, int, unsigned short, unsigned short);
    unsigned char GetField24();
    void FUN_006f5af0();
    void* FUN_006fd920(unsigned);
};
struct Node006f
{
    Thread006f* thread;
    int f4;
    unsigned short f8, fa;
    int fc, f10;
    FUN_006f5160* block;
    int f18, f1c;
    Node006f* children[4];
    unsigned FUN_00726070();
    bool FUN_006fe620(int);
    bool FUN_006fe6d0(int);
    void UpdateBlockVisibility(bool);
    Ret006f* FUN_00559450();
    void UpdateBlock(int, bool);
};
// @fnv 0x006fdfc0
void Node006f::UpdateBlock(int a, bool abFlag)
{
    FUN_00404eb0 guard(0x24, true, &DAT_0106e4e0, 0x1ae);
    if (FUN_00726070() == thread->FUN_0059bb30())
    {
        if (FUN_006fe620(a))
        {
            bool flag = FUN_006fe6d0(a);
            if (!block)
            {
                block = new FUN_006f5160(this, f4, f8, fa, flag);
            }
            else if (block && block->GetNiObj(false))
            {
                if (block->FUN_00529ea0())
                    block->FUN_006f5ca0();
                if (abFlag)
                    UpdateBlockVisibility(false);
            }
            if (block)
            {
                if (block->GetByteAtOffset35() && flag)
                    block->ResetAndCreateTask(FUN_00559450()->FUN_00559450(), f4, f8, fa);
                else if (!block->GetByteAtOffset35() && !flag)
                    block->FUN_006f6540(FUN_00559450()->FUN_00559450(), f4, f8, fa);
            }
            if (block->GetField24())
                block->FUN_006f5af0();
        }
        else if (block)
        {
            delete block;
            block = 0;
        }
    }
    else if (FUN_00726070() > thread->FUN_0059bb30())
    {
        for (int i = 0; i < 4; ++i)
        {
            if (children[i])
                children[i]->UpdateBlock(a, abFlag);
        }
    }
}

struct NodeObj
{
    bool FUN_00557d30();
};
struct GridObj
{
    unsigned int GetFlagOrValue();
    bool FUN_006ff0a0(int idx);
    void DisableEntry(int idx);
    void SetEntryActive(int idx);
    void FinalizeEntries();
    void ResetRecordSelection();
};
struct ObjA
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual GridObj* v10();
};
struct GetterObj
{
    NodeObj* FUN_005875a0(int x, int y);
};
struct BlockObj
{
    ObjA* GetNiObj(int a);
    void* GetSelectedValue(int a);
    void* GetSelectedValue(int a, int b, int c, int d);
    void UpdateLodVisibility(void* p);
    void VisitNodeTree(void* p);
};
struct MgrObj
{
    GetterObj* FUN_004fd3e0();
    bool FUN_004511e0(NodeObj* p, int a);
};
extern MgrObj* DAT_011dea10;
struct FeeNode
{
    int f00;
    unsigned int count;
    short baseX;
    short baseY;
    char f0C;
    char f0D;
    short f0E;
    void* pChunk;
    BlockObj* pBlock;
    bool FUN_006fede0();
    void UpdateBlockVisibility(int a);
};
// @fnv 0x006fee90
void FeeNode::UpdateBlockVisibility(int a)
{
    GetterObj* getter5 = DAT_011dea10->FUN_004fd3e0();
    GridObj* grid;
    if (pBlock)
    {
        if (pBlock->GetNiObj(0))
        {
            grid = pBlock->GetNiObj(0)->v10();
            if (FUN_006fede0())
            {
                if (grid)
                {
                    unsigned int i;
                    for (i = 0; i < count; i++)
                    {
                        unsigned int j_;
                        for (j_ = 0; j_ < count; j_++)
                        {
                            if ((unsigned int)(count * i + j_) < grid->GetFlagOrValue())
                            {
                                int x4 = baseX + i;
                                int y3 = baseY + j_;
                                int idx4 = count * i + j_;
                                NodeObj* node = getter5->FUN_005875a0(x4, y3);
                                if (!grid->FUN_006ff0a0(idx4) && DAT_011dea10->FUN_004511e0(node, 1) &&
                                    node->FUN_00557d30())
                                {
                                    grid->DisableEntry(idx4);
                                }
                                else
                                {
                                    grid->SetEntryActive(idx4);
                                }
                            }
                        }
                    }
                    grid->FinalizeEntries();
                }
            }
            else
            {
                if (grid)
                {
                    grid->ResetRecordSelection();
                }
            }
        }
    }
    if (pBlock)
    {
        if (pBlock->GetSelectedValue(1))
        {
            if (FUN_006fede0())
            {
                pBlock->UpdateLodVisibility(
                    pBlock->GetSelectedValue(1, count, (unsigned short)baseX, (unsigned short)baseY));
            }
            else
            {
                pBlock->VisitNodeTree(pBlock->GetSelectedValue(1));
            }
        }
    }
}

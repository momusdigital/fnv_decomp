
// src/fallout_shared/distant terrain system/bgsdistantobjectblock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsdistantobjectblock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

struct TESWorldSpace
{
    virtual ~TESWorldSpace();
    virtual const char* V0()
    {}
    virtual const char* V1()
    {}
    virtual const char* V2()
    {}
    virtual const char* V3()
    {}
    virtual const char* V4()
    {}
    virtual const char* V5()
    {}
    virtual const char* V6()
    {}
    virtual const char* V7()
    {}
    virtual const char* V8()
    {}
    virtual const char* V9()
    {}
    virtual const char* V10()
    {}
    virtual const char* V11()
    {}
    virtual const char* V12()
    {}
    virtual const char* V13()
    {}
    virtual const char* V14()
    {}
    virtual const char* V15()
    {}
    virtual const char* V16()
    {}
    virtual const char* V17()
    {}
    virtual const char* V18()
    {}
    virtual const char* V19()
    {}
    virtual const char* V20()
    {}
    virtual const char* V21()
    {}
    virtual const char* V22()
    {}
    virtual const char* V23()
    {}
    virtual const char* V24()
    {}
    virtual const char* V25()
    {}
    virtual const char* V26()
    {}
    virtual const char* V27()
    {}
    virtual const char* V28()
    {}
    virtual const char* V29()
    {}
    virtual const char* V30()
    {}
    virtual const char* V31()
    {}
    virtual const char* V32()
    {}
    virtual const char* V33()
    {}
    virtual const char* V34()
    {}
    virtual const char* V35()
    {}
    virtual const char* V36()
    {}
    virtual const char* V37()
    {}
    virtual const char* V38()
    {}
    virtual const char* V39()
    {}
    virtual const char* V40()
    {}
    virtual const char* V41()
    {}
    virtual const char* V42()
    {}
    virtual const char* V43()
    {}
    virtual const char* V44()
    {}
    virtual const char* V45()
    {}
    virtual const char* V46()
    {}
    virtual const char* V47()
    {}
    virtual const char* V48()
    {}
    virtual const char* V49()
    {}
    virtual const char* V50()
    {}
    virtual const char* V51()
    {}
    virtual const char* V52()
    {}
    virtual const char* V53()
    {}
    virtual const char* V54()
    {}
    virtual const char* V55()
    {}
    virtual const char* V56()
    {}
    virtual const char* V57()
    {}
    virtual const char* V58()
    {}
    virtual const char* V59()
    {}
    virtual const char* V60()
    {}
    virtual const char* V61()
    {}
    virtual const char* V62()
    {}
    virtual const char* V63()
    {}
    virtual const char* V64()
    {}
    virtual const char* V65()
    {}
    virtual const char* V66()
    {}
    virtual const char* V67()
    {}
    virtual const char* V68()
    {}
    virtual const char* V69()
    {}
    virtual const char* V70()
    {}
    virtual const char* V71()
    {}
    virtual const char* V72()
    {}
    virtual const char* V73()
    {}
    virtual const char* V74()
    {}
    virtual const char* GetStingerBlockFileNameHighPriority();
};

// Formats a NIF path into apOutput from the world's high-priority stinger block file name, level and cell coordinates.
// @fnv 0x006f5730
void __cdecl FormatStingerBlockPath(char* apOutput, TESWorldSpace* apWorld, int aiLevel, short asCellX, short asCellY)
{
    _sprintf_s(apOutput, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Stinger\\%s.Level%i.High.X%i.Y%i.NIF",
               apWorld->GetStingerBlockFileNameHighPriority(), apWorld->GetStingerBlockFileNameHighPriority(), aiLevel,
               asCellX, asCellY);
}

struct FUN_006f6070_shell
{
    unsigned char GetByteAtOffset35();
};

// @fnv 0x006f6070
unsigned char FUN_006f6070_shell::GetByteAtOffset35()
{
    return ((unsigned char*)this)[0x23];
}

struct FUN_006f6520_shell
{
    char GetByteAtOffset();
};

// @fnv 0x006f6520
char FUN_006f6520_shell::GetByteAtOffset()
{
    return ((char*)this)[0xdf2];
}

struct BGSDistantObjectBlockLoadTask
{
    void __thiscall FUN_006f6fe0();
    void* __thiscall FUN_006f6fb0(unsigned int flags);
};

extern void __cdecl _Deallocate(void*);

// Calls FUN_006f6fe0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x006f6fb0
void* BGSDistantObjectBlockLoadTask::FUN_006f6fb0(unsigned int flags)
{
    FUN_006f6fe0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_006f71a0 {
struct BGSDistantObjectBlockLoadTask
{
    void __thiscall FUN_00c3cb70(void* pState, void* pOwner);
    void __thiscall RunOnce(void* apTaskState, void* apTaskOwner);
};

// If the byte at offset 0x50 is unset, sets it to 1 and calls FUN_00c3cb70 with the task state and owner; otherwise does nothing.
// @fnv 0x006f71a0
void BGSDistantObjectBlockLoadTask::RunOnce(void* apTaskState, void* apTaskOwner)
{
    if (*(unsigned char*)((char*)this + 0x50))
    {
    }
    else
    {
        *(unsigned char*)((char*)this + 0x50) = 1;
        this->FUN_00c3cb70(apTaskState, apTaskOwner);
    }
}
}  // namespace fnv_006f71a0

struct FUN_006f73b0_shell
{
    void SetFlag();
};

// @fnv 0x006f73b0
void FUN_006f73b0_shell::SetFlag()
{
    ((char*)this)[0x24] = 1;
}

// Formats a landscape LOD block NIF path from the worldspace's stinger block file name, level and cell coordinates into apOutput.
// @fnv 0x006f55f0
void FormatLODBlockFileName(char* apOutput, TESWorldSpace* apWorld, int aiLevel, short asCellX, short asCellY)
{
    _sprintf_s(apOutput, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Blocks\\%s.Level%i.X%i.Y%i.NIF",
               apWorld->GetStingerBlockFileNameHighPriority(), apWorld->GetStingerBlockFileNameHighPriority(), aiLevel,
               asCellX, asCellY);
}

// Formats a landscape LOD block NIF path from the worldspace's stinger block file name, level, and cell coordinates into apOutput.
// @fnv 0x006f5640
void __cdecl BuildLODBlockFilePath(char* apOutput, TESWorldSpace* apWorld, int aiLevel, short asCellX, short asCellY)
{
    _sprintf_s(apOutput, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Blocks\\%s.Level%i.High.X%i.Y%i.NIF",
               apWorld->GetStingerBlockFileNameHighPriority(), apWorld->GetStingerBlockFileNameHighPriority(), aiLevel,
               asCellX, asCellY);
}

// Formats a landscape LOD block NIF path into apOutput from the worldspace's stinger block file name, level, and cell coordinates.
// @fnv 0x006f5690
void __cdecl BuildLODBlockFileName(char* apOutput, TESWorldSpace* apWorld, int aiLevel, short asCellX, short asCellY)
{
    _sprintf_s(apOutput, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Blocks\\%s.Level%i.X%i.Y%i.PostApocalypse.NIF",
               apWorld->GetStingerBlockFileNameHighPriority(), apWorld->GetStingerBlockFileNameHighPriority(), aiLevel,
               asCellX, asCellY);
}

// @fnv 0x006f57c0
void __cdecl FUN_006f57c0(char* apOutput, TESWorldSpace* apWorld)
{
    _sprintf_s(apOutput, 0x104, "Data\\Textures\\Landscape\\LOD\\%s\\Blocks\\%s.Buildings_n.dds",
               apWorld->GetStingerBlockFileNameHighPriority(), apWorld->GetStingerBlockFileNameHighPriority());
}

struct Flt
{
    operator unsigned int();
};

struct FUN_006f5800_shell
{
    unsigned int __thiscall GetSelectedValue(bool abFlag);
};

// Returns the value at offset 0x10 when abFlag is set, otherwise the value at offset 8.
// @fnv 0x006f5800
unsigned int __thiscall FUN_006f5800_shell::GetSelectedValue(bool abFlag)
{
    Flt* pFlt = abFlag ? (Flt*)((char*)this + 0x10) : (Flt*)((char*)this + 8);
    return *pFlt;
}

// placeholder declarations
struct NiNode
{
};
struct Model
{
    NiNode* GetObject3D(void);
};
struct FUN_00528820_shell
{
    void ClearField(void);
};
struct TESObjectCELL
{
    unsigned char GetField24(void);
    NiNode* __thiscall GetSelectedValue(unsigned int);
};
struct BSFaceGenNiNode
{
    Model* GetAnimationData(void);
};
struct GlobalObject2_0096a2d0
{
    TESObjectCELL** __thiscall _ref_006815c0();
    GlobalObject2_0096a2d0* __thiscall _ref_00726070();
};
extern GlobalObject2_0096a2d0 g_011d8524;

// @fnv 0x006f5840
void __cdecl FUN_006f5840(void)
{
    GlobalObject2_0096a2d0* pEntry = &g_011d8524;
    while (pEntry)
    {
        TESObjectCELL* cell = *pEntry->_ref_006815c0();
        if (cell && !cell->GetField24())
        {
            NiNode* obj = cell->GetSelectedValue(0);
            if (obj)
            {
                ((FUN_00528820_shell*)((BSFaceGenNiNode*)obj)->GetAnimationData()->GetObject3D())->ClearField();
            }
            obj = cell->GetSelectedValue(1);
            if (obj)
            {
                ((FUN_00528820_shell*)((BSFaceGenNiNode*)obj)->GetAnimationData()->GetObject3D())->ClearField();
            }
        }
        pEntry = pEntry->_ref_00726070();
    }
}

namespace fnv_006f6090 {
struct SoundListView
{
    void __thiscall AddTail(char* const&);
};

struct GlobalObject2_0096a2d0
{
    void __thiscall AddTail(char* const&);
};

extern GlobalObject2_0096a2d0 g_011d8524;

struct FUN_006f6090_shell
{
    void AddSelfToGlobalList();
};

// Adds the this pointer to the global list g_011d8524.
// @fnv 0x006f6090
void FUN_006f6090_shell::AddSelfToGlobalList()
{
    char* p = (char*)this;
    g_011d8524.AddTail(p);
}
}  // namespace fnv_006f6090

// Formats a landscape LOD stinger NIF path from the worldspace's stinger block file name, level and cell coordinates into apOutput.
// @fnv 0x006f56e0
void BuildStingerNifPath(char* apOutput, TESWorldSpace* apWorld, int aiLevel, short asCellX, short asCellY)
{
    _sprintf_s(apOutput, 0x104, "Data\\Meshes\\Landscape\\LOD\\%s\\Stinger\\%s.Level%i.X%i.Y%i.NIF",
               apWorld->GetStingerBlockFileNameHighPriority(), apWorld->GetStingerBlockFileNameHighPriority(), aiLevel,
               asCellX, asCellY);
}

// Formats a DDS path for the worldspace's high-priority stinger block buildings LOD texture into apOutput.
// @fnv 0x006f5780
void __cdecl FormatBuildingsLODTexturePath(char* apOutput, TESWorldSpace* apWorld)
{
    _sprintf_s(apOutput, 0x104, "Data\\Textures\\Landscape\\LOD\\%s\\Blocks\\%s.Buildings.dds",
               apWorld->GetStingerBlockFileNameHighPriority(), apWorld->GetStingerBlockFileNameHighPriority());
}

struct FUN_006f60c0_shell
{
    bool IsInCellList();
    void RunLoop();
};
struct _Ref905330_shell
{
    void _ref_00905330(FUN_006f60c0_shell* const&);
};
// Repeatedly calls IsInCellList and, while it returns true, passes this to _ref_00905330 via g_011d8524.
// @fnv 0x006f60c0
void FUN_006f60c0_shell::RunLoop()
{
    while (IsInCellList())
    {
        ((_Ref905330_shell*)&g_011d8524)->_ref_00905330(this);
    }
}

struct FUN_006f6100_shell
{
    bool __thiscall IsInCellList();
};
// Walks the g_011d8524 list and returns true if this object is found among the cells it references.
// @fnv 0x006f6100
bool __thiscall FUN_006f6100_shell::IsInCellList()
{
    GlobalObject2_0096a2d0* iter = &g_011d8524;
    while (iter)
    {
        TESObjectCELL* cell = *iter->_ref_006815c0();
        if (cell && (FUN_006f6100_shell*)cell == this)
            return true;
        iter = iter->_ref_00726070();
    }
    return false;
}

namespace fnv_006f74b0 {
struct BGSDistantObjectBlockLoadTask
{
    unsigned char pad0[0x34];
    int iX;
    int iY;
    int iLevel;
    bool __thiscall GetDescription(char*, unsigned int);
};

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

// Formats the block's X, Y and level into apDescription with _sprintf_s and returns true.
// @fnv 0x006f74b0
bool BGSDistantObjectBlockLoadTask::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    _sprintf_s(apDescription, aiBufferSize, "Object LOD Task for block ( %i, %i ) at level ( %i )", iX, iY, iLevel);
    return true;
}
}  // namespace fnv_006f74b0

struct LodObject;

struct LodNode
{
    unsigned int GetArrayCount();
    LodObject* GetAt(unsigned int i);
};

struct LodObject
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual LodNode* IsSceneNode();
    void SetAppCulled(bool bAppCulled);
};

// Recursively sets the app-culled flag on obj and all child LodObjects to the inverse of bShow.
// @fnv 0x006f58e0
void __cdecl SetObjectVisible(LodObject* obj, bool bShow)
{
    if (obj)
        obj->SetAppCulled(!bShow);
    if (obj->IsSceneNode())
    {
        LodNode* node = obj->IsSceneNode();
        for (unsigned int i = 0; i < node->GetArrayCount(); i++)
            SetObjectVisible(node->GetAt(i), bShow);
    }
}

namespace fnv_006f5970 {
struct LodPoint3
{
    float x;
    float y;
    float z;
};

struct LodCell
{
    unsigned char FUN_00557d30();
};

struct LodWorld
{
    LodCell* FUN_00587550(const LodPoint3& pos);
};

struct LodTES
{
    LodWorld* FUN_004fd3e0();
    bool FUN_004511e0(LodCell* cell, int unk);
};
extern LodTES* g_LodTES;

struct LodObject;

struct LodNode
{
    unsigned int GetArrayCount();
    LodObject* GetAt(unsigned int i);
};

struct LodObject
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual LodNode* IsSceneNode();
    const LodPoint3& GetWorldTranslate();
};

void __cdecl SetObjectVisible(LodObject* obj, int flag);

struct LodVisitor
{
    void UpdateLodVisibility(LodObject* obj, int a, unsigned short b, unsigned short c);
};

// Recursively walks the object's children, or for a leaf finds the cell at its world position and sets its visibility flag based on the cell check.
// @fnv 0x006f5970
void LodVisitor::UpdateLodVisibility(LodObject* obj, int a, unsigned short b, unsigned short c)
{
    if (obj->IsSceneNode())
    {
        LodNode* node = obj->IsSceneNode();
        for (unsigned int i = 0; i < node->GetArrayCount(); i++)
        {
            LodObject* child = node->GetAt(i);
            if (child)
                UpdateLodVisibility(child, a, b, c);
        }
    }
    else
    {
        LodPoint3 pos = obj->GetWorldTranslate();
        LodCell* cell = g_LodTES->FUN_004fd3e0()->FUN_00587550(pos);
        if (g_LodTES->FUN_004511e0(cell, 1) && cell->FUN_00557d30())
            SetObjectVisible(obj, 0);
        else
            SetObjectVisible(obj, 1);
    }
}
}  // namespace fnv_006f5970

struct SceneNode;

struct TileWorkList
{
    unsigned int FUN_00453470();
    SceneNode* FUN_0045bc00(unsigned int auiIndex);
};

struct SceneNode
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual TileWorkList* GetChildren();

    void FUN_00450f90(int aiFlag);
};

struct NodeVisitor
{
    void VisitNodeTree(SceneNode* apNode);
};

// @fnv 0x006f5a70
void NodeVisitor::VisitNodeTree(SceneNode* apNode)
{
    if (apNode != 0)
        apNode->FUN_00450f90(0);

    if (apNode->GetChildren() != 0)
    {
        TileWorkList* pList = apNode->GetChildren();
        for (unsigned int uiIndex = 0; uiIndex < pList->FUN_00453470(); uiIndex++)
            VisitNodeTree(pList->FUN_0045bc00(uiIndex));
    }
}

struct Scene
{
};
struct Node
{
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void Detach(Scene*);
};
struct Parent
{
    Node* FUN_004ea9c0();
};
struct ParentRef
{
    Parent* value;
    Parent* FUN_00559450();
};
struct SceneRef
{
    Scene* value;
    Scene* FUN_00559450();
    void FUN_0066b0d0(Scene*);
};
struct TaskRef
{
    void* value;
    void FUN_006f74f0(void*);
};
extern int DAT_011d8510;
struct Block
{
    ParentRef* parent;
    SceneRef first, second, third, fourth, fifth;
    TaskRef mainTask, secondaryTask;
    int unk20;
    bool active;
    void RunLoop();
    void FUN_006f5af0();
};
// Calls RunLoop, decrements DAT_011d8510 if scenes are set, detaches them from the parent node, clears the scene and task refs, and sets active to false.
// @fnv 0x006f5af0
void Block::FUN_006f5af0()
{
    RunLoop();
    if (second.FUN_00559450() || first.FUN_00559450() || fourth.FUN_00559450())
        --DAT_011d8510;
    if (second.FUN_00559450() || first.FUN_00559450())
    {
        parent->FUN_00559450()->FUN_004ea9c0()->Detach(second.FUN_00559450());
        parent->FUN_00559450()->FUN_004ea9c0()->Detach(first.FUN_00559450());
        parent->FUN_00559450()->FUN_004ea9c0()->Detach(third.FUN_00559450());
        second.FUN_0066b0d0(0);
        first.FUN_0066b0d0(0);
        third.FUN_0066b0d0(0);
        mainTask.FUN_006f74f0(0);
    }
    if (fourth.FUN_00559450())
    {
        parent->FUN_00559450()->FUN_004ea9c0()->Detach(fourth.FUN_00559450());
        fourth.FUN_0066b0d0(0);
        fifth.FUN_0066b0d0(0);
        secondaryTask.FUN_006f74f0(0);
    }
    active = false;
}

struct TargetObject
{
    bool FUN_00449110();
    void AssignValue(void* destination);
    void FUN_006f6250(void* destination);
};
struct SmartRef
{
    void* value;
    TargetObject* FUN_00559450();
    void FUN_006f74f0(int value);
};
struct Owner
{
    int unk00;
    void* firstDestination;
    void* secondDestination;
    int unk0c;
    void* thirdDestination;
    int unk14;
    SmartRef firstReference;
    SmartRef secondReference;
    bool completed;
    void UpdateReferences(bool update);
};
// @fnv 0x006f6150
void Owner::UpdateReferences(bool update)
{
    if (firstReference.FUN_00559450() != 0)
    {
        if (firstReference.FUN_00559450()->FUN_00449110())
        {
            if (update)
            {
                firstReference.FUN_00559450()->AssignValue(&firstDestination);
                firstReference.FUN_00559450()->FUN_006f6250(&secondDestination);
            }
            firstReference.FUN_006f74f0(0);
            if (secondReference.FUN_00559450() == 0)
                completed = true;
        }
    }
    if (secondReference.FUN_00559450() != 0)
    {
        if (secondReference.FUN_00559450()->FUN_00449110())
        {
            if (update)
                secondReference.FUN_00559450()->FUN_006f6250(&thirdDestination);
            secondReference.FUN_006f74f0(0);
            if (firstReference.FUN_00559450() == 0)
                completed = true;
        }
    }
}

struct S_006f6fe0_Base
{
    virtual ~S_006f6fe0_Base();
};

struct S_006f6fe0_Obj;

struct S_006f6fe0_Ptr
{
    S_006f6fe0_Obj* m_pObject;
    ~S_006f6fe0_Ptr();
    S_006f6fe0_Ptr& operator=(S_006f6fe0_Obj* pObject);
};

struct FUN_006f6fe0 : S_006f6fe0_Base
{
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
    S_006f6fe0_Ptr m_spObject48;
    S_006f6fe0_Ptr m_spObject4c;
    FUN_006f6fe0();
    virtual ~FUN_006f6fe0();
};

// Destructor that clears the two smart-pointer members m_spObject48 and m_spObject4c by assigning null.
// @fnv 0x006f6fe0
FUN_006f6fe0::~FUN_006f6fe0()
{
    m_spObject48 = 0;
    m_spObject4c = 0;
}

namespace fnv_006f71e0 {
enum MEM_CONTEXT
{
    MEM_DISTANT_OBJECT = 36
};
class AutoMemContext
{
    int previous;

  public:
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
struct Node
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual Node* AsNode();
    Node* FUN_0045bc00(unsigned int);
};
struct NodePtr
{
    Node* pointer;
    NodePtr& FUN_0066b0d0(Node*);
    Node* FUN_00559450() const;
};
class BSStream
{
  public:
    virtual ~BSStream();
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    char errorMessage[260];
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    unsigned int unk550;
    unsigned int unk554;
    unsigned int unk558;
    unsigned int unk55c;
    unsigned int unk560;
    unsigned int unk564;
    unsigned int unk568;
    unsigned int unk56c;
    unsigned int unk570;
    unsigned int unk574;
    unsigned int unk578;
    unsigned int unk57c;
    unsigned int unk580;
    unsigned int unk584;
    unsigned int unk588;
    unsigned int unk58c;
    unsigned int unk590;
    unsigned int unk594;
    unsigned int unk598;
    unsigned int unk59c;
    unsigned int unk5a0;
    unsigned int unk5a4;
    unsigned int unk5a8;
    unsigned int unk5ac;
    unsigned int unk5b0;
    unsigned int unk5b4;
    unsigned int unk5b8;
    unsigned int unk5bc;
    unsigned int unk5c0;
    unsigned int unk5c4;
    unsigned int unk5c8;
    unsigned int unk5cc;
    BSStream();
    bool FUN_00c3a8a0(const char*);
    Node* GetStringAt(unsigned int);
};
int __cdecl FUN_00456a20(const char*, int, int, int);
struct BlockTask
{
    unsigned char GetByteAtOffset35();
    void SetFlag();
};
struct DistantBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    BlockTask* task;
    unsigned int unk44;
    NodePtr root, scene;
    int FUN_00c3cff0(int, int);
    const char* FUN_0045cd60();
    const char* FUN_0045cd60(int);
    void LoadDistantObjectBlock();
};
// @fnv 0x006f71e0
void DistantBlock::LoadDistantObjectBlock()
{
    AutoMemContext mode(
        MEM_DISTANT_OBJECT, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSDistantObjectBlock.cpp",
        922);
    int memory = FUN_00c3cff0(0, 1);
    int canLoad = 1;
    if (memory == 0 && !FUN_00456a20(FUN_0045cd60(), 0, 6, 1))
        canLoad = 0;
    BSStream stream;
    if (canLoad && stream.FUN_00c3a8a0(FUN_0045cd60(memory)))
    {
        Node* node = stream.GetStringAt(0);
        if (node->AsNode())
        {
            scene.FUN_0066b0d0(stream.GetStringAt(0));
            root.FUN_0066b0d0(scene.FUN_00559450()->FUN_0045bc00(0));
        }
        else
        {
            root.FUN_0066b0d0(stream.GetStringAt(0));
        }
    }
    else
    {
        if (task->GetByteAtOffset35())
            task->SetFlag();
    }
}
}  // namespace fnv_006f71e0

struct VObj
{
    virtual void V00()
    {}
    virtual void V01()
    {}
    virtual void V02()
    {}
    virtual void V03()
    {}
    virtual void V04()
    {}
    virtual void V05()
    {}
    virtual void V06()
    {}
    virtual void V07()
    {}
    virtual void V08()
    {}
    virtual void V09()
    {}
    virtual void V10()
    {}
    virtual void V11()
    {}
    virtual void V12()
    {}
    virtual void V13()
    {}
    virtual void V14()
    {}
    virtual void V15()
    {}
    virtual void V16()
    {}
    virtual void V17()
    {}
    virtual void V18()
    {}
    virtual void V19()
    {}
    virtual void V20()
    {}
    virtual void V21()
    {}
    virtual void V22()
    {}
    virtual void V23()
    {}
    virtual void V24()
    {}
    virtual void V25()
    {}
    virtual void V26()
    {}
    virtual void V27()
    {}
    virtual void V28()
    {}
    virtual void V29()
    {}
    virtual void V30()
    {}
    virtual void V31()
    {}
    virtual void V32()
    {}
    virtual void V33()
    {}
    virtual void V34()
    {}
    virtual void V35()
    {}
    virtual void V36()
    {}
    virtual void V37()
    {}
    virtual void V38()
    {}
    virtual void V39()
    {}
    virtual void V40()
    {}
    virtual void V41()
    {}
    virtual void V42()
    {}
    virtual void V43()
    {}
    virtual void V44()
    {}
    virtual void V45()
    {}
    virtual void V46()
    {}
    virtual void V47()
    {}
    virtual void V48()
    {}
    virtual void V49()
    {}
    virtual void V50()
    {}
    virtual void V51()
    {}
    virtual void V52()
    {}
    virtual void V53()
    {}
    virtual void V54()
    {}
    virtual void V55(void* p, int b)
    {}
    virtual void V56()
    {}
    virtual void V57()
    {}
    virtual void V58(void* p)
    {}
};

struct C_00559450
{
    C_00559450* FUN_00559450();
};
struct C_004ea9c0
{
    VObj* FUN_004ea9c0();
};
struct C_009611e0
{
    void* FUN_009611e0();
};
struct C_0066b0d0
{
    void FUN_0066b0d0(unsigned int v);
};
struct C_006f6090
{
    void AddSelfToGlobalList();
};
struct C_006f66e0
{
    void UpdateMenuNodes();
};

extern int DAT_011d8510;
extern int DAT_011d8514;

struct FUN_006f5ca0_cls
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned char unk20;
    unsigned char m_21;
    void FUN_006f5ca0();
};

// @fnv 0x006f5ca0
void FUN_006f5ca0_cls::FUN_006f5ca0()
{
    if (((C_00559450*)&m_04)->FUN_00559450() == 0 && ((C_00559450*)&m_10)->FUN_00559450() == 0)
        return;
    if (m_21 == 0)
    {
        ((FUN_006f60c0_shell*)this)->RunLoop();
        if (((C_00559450*)&m_0c)->FUN_00559450() != 0)
        {
            if (((C_00559450*)&m_08)->FUN_00559450() != 0)
            {
                ((C_004ea9c0*)((C_00559450*)this)->FUN_00559450()->FUN_00559450())
                    ->FUN_004ea9c0()
                    ->V58(((C_009611e0*)((C_00559450*)&m_0c)->FUN_00559450())->FUN_009611e0());
                ((C_004ea9c0*)((C_00559450*)this)->FUN_00559450()->FUN_00559450())
                    ->FUN_004ea9c0()
                    ->V55(((C_00559450*)&m_08)->FUN_00559450(), 1);
            }
            else
            {
                ((C_004ea9c0*)((C_00559450*)this)->FUN_00559450()->FUN_00559450())
                    ->FUN_004ea9c0()
                    ->V58(((C_00559450*)&m_0c)->FUN_00559450());
                ((C_004ea9c0*)((C_00559450*)this)->FUN_00559450()->FUN_00559450())
                    ->FUN_004ea9c0()
                    ->V55(((C_00559450*)&m_04)->FUN_00559450(), 1);
            }
        }
        else
        {
            if (((C_00559450*)&m_08)->FUN_00559450() != 0)
                ((C_004ea9c0*)((C_00559450*)this)->FUN_00559450()->FUN_00559450())
                    ->FUN_004ea9c0()
                    ->V55(((C_00559450*)&m_08)->FUN_00559450(), 1);
            else if (((C_00559450*)&m_04)->FUN_00559450() != 0)
                ((C_004ea9c0*)((C_00559450*)this)->FUN_00559450()->FUN_00559450())
                    ->FUN_004ea9c0()
                    ->V55(((C_00559450*)&m_04)->FUN_00559450(), 1);
        }
        if (((C_00559450*)&m_14)->FUN_00559450() != 0)
        {
            if (((C_00559450*)&m_10)->FUN_00559450() != 0)
            {
                ((C_004ea9c0*)((C_00559450*)this)->FUN_00559450()->FUN_00559450())
                    ->FUN_004ea9c0()
                    ->V58(((C_00559450*)&m_14)->FUN_00559450());
                ((C_004ea9c0*)((C_00559450*)this)->FUN_00559450()->FUN_00559450())
                    ->FUN_004ea9c0()
                    ->V55(((C_00559450*)&m_10)->FUN_00559450(), 1);
            }
        }
        else if (((C_00559450*)&m_10)->FUN_00559450() != 0)
        {
            ((C_004ea9c0*)((C_00559450*)this)->FUN_00559450()->FUN_00559450())
                ->FUN_004ea9c0()
                ->V55(((C_00559450*)&m_10)->FUN_00559450(), 1);
        }
        if (((FUN_006f6070_shell*)this)->GetByteAtOffset35())
        {
            if (((C_00559450*)&m_0c)->FUN_00559450() != 0 || ((C_00559450*)&m_14)->FUN_00559450() != 0)
                DAT_011d8510 = DAT_011d8510 - 1;
            if (((C_00559450*)&m_04)->FUN_00559450() != 0 || ((C_00559450*)&m_10)->FUN_00559450() != 0)
                DAT_011d8514 = DAT_011d8514 + 1;
        }
        else
        {
            if (((C_00559450*)&m_0c)->FUN_00559450() != 0 || ((C_00559450*)&m_14)->FUN_00559450() != 0)
                DAT_011d8514 = DAT_011d8514 - 1;
            if (((C_00559450*)&m_04)->FUN_00559450() != 0 || ((C_00559450*)&m_10)->FUN_00559450() != 0)
                DAT_011d8510 = DAT_011d8510 + 1;
        }
        ((C_006f66e0*)this)->UpdateMenuNodes();
        if (((C_00559450*)&m_04)->FUN_00559450() != 0 || ((C_00559450*)&m_10)->FUN_00559450() != 0)
        {
            if (!((FUN_006f6100_shell*)this)->IsInCellList())
                ((C_006f6090*)this)->AddSelfToGlobalList();
        }
        ((C_0066b0d0*)&m_0c)->FUN_0066b0d0(0);
        ((C_0066b0d0*)&m_14)->FUN_0066b0d0(0);
        m_21 = 1;
    }
}

// FUN_006f6250: __thiscall (this in ecx), callee pops 4 bytes (1 stack parameter)
struct FUN_006e5cc0_shell
{
    void __thiscall FUN_006e5cc0(void* apObject);
};

struct FUN_006f6250_shell
{
    void FUN_006f6250(FUN_006e5cc0_shell* apObject);
};

// @fnv 0x006f6250
void FUN_006f6250_shell::FUN_006f6250(FUN_006e5cc0_shell* apObject)
{
    apObject->FUN_006e5cc0((void*)((char*)this + 0x4c));
}

namespace fnv_006f6270 {
extern char str_0106da18[];

struct VObj
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
};

struct FUN_006e5cc0_shell
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_006e5cc0(void* p);
};

struct NewObj;
struct FUN_00559450_shell
{
    unsigned int unk00;
    unsigned int unk04;
    VObj* FUN_00559450();
    void FUN_006f74f0(NewObj* p);
};

struct FUN_00404ee0_shell
{
    void FUN_00404eb0(unsigned int a, int b, const char* c, unsigned int d);
    void FUN_00404ee0();
};

struct ScopeLock : FUN_00404ee0_shell
{
    void FUN_00404eb0_unused();
    unsigned int unk00;
    ScopeLock(unsigned int a, int b, const char* c, unsigned int d);
    __forceinline ~ScopeLock()
    {
        FUN_00404ee0();
    }
};

struct FUN_006f6d10_shell
{
    FUN_006f6d10_shell* FUN_006f6d10(void* owner, void* apOutput, int asX, int asY, void* apWorld, int a6, int a7,
                                     int a8);
};
struct NewObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    NewObj(void* owner, void* apOutput, int asX, int asY, void* apWorld, int a6, int a7, int a8);
    static void* operator new(unsigned int sz);
    static void operator delete(void*, unsigned int);
};

struct BlockLoader
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int unk08;
    FUN_006e5cc0_shell m_0c;
    FUN_00559450_shell m_18;
    unsigned char m_20;
    unsigned char m_21;

    void FUN_006f6270(void* apOutput, void* apWorld, short asX, short asY);
};

// @fnv 0x006f6270
void BlockLoader::FUN_006f6270(void* apOutput, void* apWorld, short asX, short asY)
{
    ScopeLock lock(0x24, 1, str_0106da18, 0x240);
    m_0c.FUN_006e5cc0(&m_04);
    m_18.FUN_006f74f0(new NewObj(this, apOutput, asX, asY, apWorld, 1, 1, 0));
    m_18.FUN_00559450()->V8();
    m_20 = 0;
    m_21 = 0;
}
}  // namespace fnv_006f6270

struct S_006f6370_AutoMem
{
    int unk00;
    S_006f6370_AutoMem(int context, bool push, const char* file, int line);
    ~S_006f6370_AutoMem();
};

struct S_006f6370_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
};

struct S_006f6370_Ptr
{
    S_006f6370_Obj* unk00;
    operator S_006f6370_Obj*() const;
    S_006f6370_Obj* operator->() const;
    S_006f6370_Ptr& operator=(const S_006f6370_Ptr& other);
    S_006f6370_Ptr& operator=(S_006f6370_Obj* p);
};

struct S_006f6370_Mgr;

struct S_006f6370_Task : S_006f6370_Obj
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    S_006f6370_Task(S_006f6370_Mgr* mgr, TESWorldSpace* world, int x, int y, int level, unsigned char flag, int a,
                    int b);
};

struct S_006f6370_Streamer
{
    void FUN_0044ac40(S_006f6370_Obj* task, int flag);
};

struct S_006f6370_Player
{
    unsigned char GetByteAtOffset();
};

extern S_006f6370_Streamer* DAT_01202d98;
extern S_006f6370_Player* DAT_011dea3c;

struct S_006f6370_Mgr
{
    int unk00;
    S_006f6370_Ptr unk04;
    int unk08;
    S_006f6370_Ptr unk0c;
    S_006f6370_Ptr unk10;
    S_006f6370_Ptr unk14;
    S_006f6370_Ptr unk18;
    S_006f6370_Ptr unk1c;
    unsigned char unk20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    int unk24;
    int unk28;
    void ResetAndCreateTask(TESWorldSpace* world, int level, short x, short y);
};

// @fnv 0x006f6370
void S_006f6370_Mgr::ResetAndCreateTask(TESWorldSpace* world, int level, short x, short y)
{
    S_006f6370_AutoMem ctx(
        0x24, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Distant Terrain System\\BGSDistantObjectBlock.cpp",
        0x250);
    unk0c = unk04;
    unk14 = unk10;
    if (unk18)
    {
        DAT_01202d98->FUN_0044ac40(unk18, 0);
        unk18 = 0;
    }
    if (unk1c)
    {
        DAT_01202d98->FUN_0044ac40(unk1c, 0);
        unk1c = 0;
    }
    unk18 = new S_006f6370_Task(this, world, x, y, level, DAT_011dea3c->GetByteAtOffset(), 0, 0);
    unk28 = 0;
    unk18->vf20();
    unk20 = 0;
    unk21 = 0;
    unk23 = 0;
    unk22 = 0;
}

namespace fnv_006f6540 {
extern char str_0106da18[];

struct VObj
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
};

struct FUN_006e5cc0_shell
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_006e5cc0(void* p);
};

struct NewObj;
struct FUN_00559450_shell
{
    unsigned int unk00;
    unsigned int unk04;
    VObj* FUN_00559450();
    void FUN_006f74f0(NewObj* p);
};

struct FUN_00404ee0_shell
{
    void FUN_00404eb0(unsigned int a, int b, const char* c, unsigned int d);
    void FUN_00404ee0();
};

struct ScopeLock : FUN_00404ee0_shell
{
    void FUN_00404eb0_unused();
    unsigned int unk00;
    ScopeLock(unsigned int a, int b, const char* c, unsigned int d);
    __forceinline ~ScopeLock()
    {
        FUN_00404ee0();
    }
};

struct NewObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    NewObj(void* owner, void* apOutput, int asX, int asY, void* apWorld, int a6, int a7, int a8);
    static void* operator new(unsigned int sz);
    static void operator delete(void*, unsigned int);
};

struct FUN_006f6d10_shell
{
    FUN_006f6d10_shell* FUN_006f6d10(void* owner, void* apOutput, int asX, int asY, void* apWorld, int a6, int a7,
                                     int a8);
};

struct FUN_0044ac40_owner
{
    void FUN_0044ac40(VObj* a, int b);
};
extern FUN_0044ac40_owner* DAT_01202d98;

struct FUN_006f6540_cls
{
    unsigned int unk00;
    unsigned int m_04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned char m_20;
    unsigned char m_21;
    unsigned char m_22;
    unsigned char m_23;
    unsigned int unk24;
    unsigned int m_28;

    void FUN_006f6540(void* apOutput, void* apWorld, short asX, short asY);
};

// @fnv 0x006f6540
void FUN_006f6540_cls::FUN_006f6540(void* apOutput, void* apWorld, short asX, short asY)
{
    ScopeLock lock(0x24, 1, str_0106da18, 0x272);
    ((FUN_006e5cc0_shell*)&unk0C)->FUN_006e5cc0(&m_04);
    ((FUN_006e5cc0_shell*)&unk14)->FUN_006e5cc0(&unk10);
    if (((FUN_00559450_shell*)&unk18)->FUN_00559450())
    {
        DAT_01202d98->FUN_0044ac40(((FUN_00559450_shell*)&unk18)->FUN_00559450(), 0);
        ((FUN_00559450_shell*)&unk18)->FUN_006f74f0(0);
    }
    if (((FUN_00559450_shell*)&unk1C)->FUN_00559450())
    {
        DAT_01202d98->FUN_0044ac40(((FUN_00559450_shell*)&unk1C)->FUN_00559450(), 0);
        ((FUN_00559450_shell*)&unk1C)->FUN_006f74f0(0);
    }
    ((FUN_00559450_shell*)&unk18)->FUN_006f74f0(new NewObj(this, apOutput, asX, asY, apWorld, 0, 1, 0));
    m_28 = 0;
    ((FUN_00559450_shell*)&unk18)->FUN_00559450()->V8();
    m_20 = 0;
    m_21 = 0;
    m_23 = 1;
    m_22 = 0;
}
}  // namespace fnv_006f6540

void* __cdecl FUN_00aa13e0(unsigned int uiSize);
void __cdecl MmFree(void* pvMem);

struct MmNode;
struct MmProperty;

struct MmTexturing
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

    virtual MmTexturing* Clone(MmNode* pkNode, int a2, int a3);
    void FUN_00441130(int iFlag, int iValue);
    void* FUN_006286d0();
};

struct MmAlpha
{
    MmAlpha();
    static void* operator new(unsigned int uiSize)
    {
        return FUN_00aa13e0(uiSize);
    }
    static void operator delete(void* pvMem, unsigned int)
    {
        MmFree(pvMem);
    }
    int unk00[7];
    void FUN_004393c0(int i);
    void FUN_0049ed90(int i);
    void FUN_0094db80(int i);
    void FUN_004393e0(int i);
};

struct MmWorldBound
{
    void SetByteAtOffset38(int i);
    void FUN_00a67050(int i);
    void FUN_004410f0(int i);
};

struct MmUpdater
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
    virtual void* Register(MmNode* pkNode, MmTexturing* pkTex);
};
struct MmScene
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
    virtual void Add(MmNode* pkNode, int a2, int a3, void* pkData);
    void FUN_00e74120();
};
MmScene* __cdecl FUN_0043c4b0();
int __cdecl FUN_0040df90();
void* __cdecl FUN_00438220();
void* __cdecl FUN_00b55560(void* pkData);

struct MmTransform
{
    int unk00, unk04, unk08;
    MmTransform(float f, int a, int b);
};

struct MmNode
{
    void FUN_00a5b230(int i);
    void FUN_00439410(void* pkProperty);
    MmTexturing* FUN_00a59d30(void* pkType);
    void FUN_00874460(void* pkData);
    void FUN_00a5a040();
    void FUN_00a59c60(MmTransform* pkTransform);
    MmWorldBound* FUN_005495f0();
    MmUpdater* FUN_004030b0();
};

template <class T> struct MmPtr
{
    T* m_pObject;
    T* FUN_00559450() const;
    bool IsNotEqual(const MmPtr& kOther) const;
};

struct MmOwner
{
    void UpdateBlockVisibility(int i);
};

struct MenuModelImpl
{
    MmOwner* m_pkOwnerManager;
    MmPtr<MmNode> m_spNodeA;
    int unk08;
    MmPtr<MmNode> m_spNodeB;
    MmPtr<MmNode> m_spNodeC;
    MmPtr<MmNode> m_spNodeD;
    int unk18[2];
    unsigned short unk20;
    bool m_bValueAt0C;

    void ApplyShaderSetup(MmNode* pkNode);
    void UpdateMenuNodes();
};

// @fnv 0x006f66e0
void MenuModelImpl::UpdateMenuNodes()
{
    bool bRebuildNodeA =
        !m_bValueAt0C || (m_spNodeA.FUN_00559450() && m_spNodeB.FUN_00559450() && m_spNodeA.IsNotEqual(m_spNodeB));
    bool bRebuildNodeC =
        !m_bValueAt0C || (m_spNodeC.FUN_00559450() && m_spNodeD.FUN_00559450() && m_spNodeC.IsNotEqual(m_spNodeD));
    if (bRebuildNodeA && m_spNodeA.FUN_00559450())
    {
        m_spNodeA.FUN_00559450()->FUN_00a5b230(FUN_0040df90());
        MmAlpha* pkAlphaPtr = new MmAlpha;
        pkAlphaPtr->FUN_004393c0(1);
        pkAlphaPtr->FUN_0049ed90(0);
        pkAlphaPtr->FUN_0094db80(0x80);
        pkAlphaPtr->FUN_004393e0(4);
        m_spNodeA.FUN_00559450()->FUN_00439410(pkAlphaPtr);
        MmTexturing* pkTexX = m_spNodeA.FUN_00559450()->FUN_00a59d30(FUN_00438220());
        pkTexX->FUN_00441130(0x22, 1);
        pkTexX->FUN_00441130(0x21, 0);
        pkTexX->FUN_00441130(0, 0);
        MmTexturing* pkCloneTmp2 = pkTexX->Clone(m_spNodeA.FUN_00559450(), 0, 1);
        if (pkCloneTmp2)
        {
            m_spNodeA.FUN_00559450()->FUN_00a5b230(3);
            pkTexX = pkCloneTmp2;
            m_spNodeA.FUN_00559450()->FUN_00439410(pkTexX);
        }
        m_spNodeA.FUN_00559450()->FUN_00874460(FUN_00b55560(pkTexX->FUN_006286d0()));
        MmTransform kTransformTmp(0.0f, 0, 0);
        m_spNodeA.FUN_00559450()->FUN_00a5a040();
        m_spNodeA.FUN_00559450()->FUN_00a59c60(&kTransformTmp);
        m_pkOwnerManager->UpdateBlockVisibility(0);
        m_spNodeA.FUN_00559450()->FUN_005495f0()->SetByteAtOffset38(0);
        m_spNodeA.FUN_00559450()->FUN_005495f0()->FUN_00a67050(0x4000);
        m_spNodeA.FUN_00559450()->FUN_005495f0()->FUN_004410f0(1);
        FUN_0043c4b0()->Add(m_spNodeA.FUN_00559450(), 0, 0,
                            m_spNodeA.FUN_00559450()->FUN_004030b0()->Register(m_spNodeA.FUN_00559450(), pkTexX));
        FUN_0043c4b0()->FUN_00e74120();
        m_bValueAt0C = true;
    }
    if (bRebuildNodeC && m_spNodeC.FUN_00559450())
    {
        ApplyShaderSetup(m_spNodeC.FUN_00559450());
        FUN_0043c4b0()->FUN_00e74120();
        m_bValueAt0C = true;
    }
}

namespace fnv_006f6a90 {
struct GtPoint3
{
    float x, y, z;
    GtPoint3(float fX, int iY, int iZ);
};
struct GtNode;
struct GtGeometry;
struct GtAVObject
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual GtNode* IsSceneNode();
    virtual void v004();
    virtual void v005();
    virtual GtGeometry* IsGeometry();
};
struct GtNode : GtAVObject
{
    unsigned int FUN_00453470();
    GtAVObject* FUN_0045bc00(unsigned int uiIndex);
};
struct GtFlags
{
    void SetByteAtOffset38(int i);
    void FUN_00a67050(int i);
    void FUN_004410f0(int i);
};
struct GtProperty
{
    char pad[0x1c];
    static void* operator new(unsigned int uiSize);
    static void operator delete(void*, unsigned int);
    GtProperty();
    void FUN_004393c0(int i);
    void FUN_0049ed90(int i);
    void FUN_0094db80(int i);
    void FUN_004393e0(int i);
};
struct GtShaderProp
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

    virtual GtShaderProp* FUN_vb0(GtGeometry* pkGeomA, int i, int j);
    void FUN_00441130(int iFlag, int iValue);
    int FUN_006286d0();
};
struct GtGeometry : GtAVObject
{
    GtShaderProp* FUN_00a59d30(int iType);
    void FUN_00a5b230(int iType);
    void FUN_00439410(void* pkPropW);
    void FUN_00874460(int i);
    void FUN_00a5a040();
    void FUN_00a59c60(GtPoint3* pkPt);
    GtFlags* FUN_005495f0();
    struct GtShaderMgr* FUN_004030b0();
};
struct GtShaderMgr
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
    virtual int FUN_v118(GtGeometry* pkGeomA, GtShaderProp* pkPropW);
};
struct GtAccum
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
    virtual void FUN_vec(GtGeometry* pkGeomA, int i, int j, int k);
};
struct GtOwner
{
    void UpdateBlockVisibility(int i);
};
int __cdecl FUN_00438220();
int __cdecl FUN_0040df90();
int __cdecl FUN_00b55560(int i);
GtAccum* __cdecl FUN_0043c4b0();

struct FUN_006f6a90_Owner
{
    GtOwner* m_pkOwnerManager;
    void ApplyShaderSetup(GtAVObject* pkObject);
};

// @fnv 0x006f6a90
void FUN_006f6a90_Owner::ApplyShaderSetup(GtAVObject* pkObject)
{
    if (!pkObject)
        return;
    if (pkObject->IsSceneNode())
    {
        GtNode* pkNode = pkObject->IsSceneNode();
        for (unsigned int i = 0; i < pkNode->FUN_00453470(); i++)
            ApplyShaderSetup(pkNode->FUN_0045bc00(i));
    }
    else
    {
        GtGeometry* pkGeomA = pkObject->IsGeometry();
        GtShaderProp* kPkOld = pkGeomA->FUN_00a59d30(FUN_00438220());
        GtShaderProp* pkShaderZ = pkGeomA->FUN_00a59d30(FUN_00438220());
        pkGeomA->FUN_00a5b230(FUN_0040df90());
        GtProperty* pkPropW = new GtProperty;
        pkPropW->FUN_004393c0(1);
        pkPropW->FUN_0049ed90(0);
        pkPropW->FUN_0094db80(0x80);
        pkPropW->FUN_004393e0(4);
        pkGeomA->FUN_00439410(pkPropW);
        pkShaderZ->FUN_00441130(0x22, 1);
        pkShaderZ->FUN_00441130(0x37, 1);
        GtShaderProp* pkNewVal2 = pkShaderZ->FUN_vb0(pkGeomA, 0, 1);
        if (pkNewVal2)
        {
            pkGeomA->FUN_00a5b230(3);
            pkShaderZ = pkNewVal2;
            pkGeomA->FUN_00439410(pkShaderZ);
        }
        pkGeomA->FUN_00874460(FUN_00b55560(pkShaderZ->FUN_006286d0()));
        GtPoint3 kZeroWork(0.0f, 0, 0);
        pkGeomA->FUN_00a5a040();
        pkGeomA->FUN_00a59c60(&kZeroWork);
        m_pkOwnerManager->UpdateBlockVisibility(0);
        pkGeomA->FUN_005495f0()->SetByteAtOffset38(0);
        pkGeomA->FUN_005495f0()->FUN_00a67050(0x4000);
        pkGeomA->FUN_005495f0()->FUN_004410f0(1);
        FUN_0043c4b0()->FUN_vec(pkGeomA, 0, 0, pkGeomA->FUN_004030b0()->FUN_v118(pkGeomA, pkShaderZ));
    }
}
}  // namespace fnv_006f6a90

struct ArchiveFileManager
{
    virtual void v00();
    int unk04[0x30 / 4 - 1];
    ArchiveFileManager(int iPriority);
    ~ArchiveFileManager();
    void FUN_00c3cee0(const char* pcName);
    void LookupFileEntryByArchive(int i);
};

template <class T> struct TaskPtr
{
    T* m_pObject;
    TaskPtr(T* pObject);
    ~TaskPtr();
};

struct TaskNode;
struct TaskPlayer
{
    bool GetByteAtOffset();
};
extern TaskPlayer* g_thePlayer_011dea3c;

void __cdecl BuildLODBlockFilePath(char* pcPath, int iWorld, int iLevel, unsigned short usX, unsigned short usY);
void __cdecl FormatLODBlockFileName(char* pcPath, int iWorld, int iLevel, unsigned short usX, unsigned short usY);
void __cdecl BuildLODBlockFileName(char* pcPath, int iWorld, int iLevel, unsigned short usX, unsigned short usY);
void __cdecl FormatStingerBlockPath(char* pcPath, int iWorld, int iLevel, unsigned short usX, unsigned short usY);
void __cdecl BuildStingerNifPath(char* pcPath, int iWorld, int iLevel, unsigned short usX, unsigned short usY);
int __cdecl FUN_00456a20(const char* pcPath, int a2, int a3, int a4);

struct FUN_006f6d10 : ArchiveFileManager
{
    unsigned char m_bDone;
    int m_iX;
    int m_iY;
    int m_iZ;
    int m_iParent;
    int m_iWorld;
    TaskPtr<TaskNode> m_spNode;
    TaskPtr<TaskNode> m_spLand;
    unsigned char m_bLoadComplete;
    bool m_bLOD;

    virtual void v01();
    FUN_006f6d10(int iParent, int iWorld, int iX, int iY, int iLevel, bool bForce, bool bAlt, bool abLastFlag);
};

// @fnv 0x006f6d10
FUN_006f6d10::FUN_006f6d10(int iParent, int iWorld, int iX, int iY, int iLevel, bool bForce, bool bAlt, bool abLOD)
    : ArchiveFileManager(3), m_bDone(0), m_iX(iX), m_iY(iY), m_iZ(iLevel), m_iParent(iParent), m_iWorld(iWorld),
      m_spNode(0), m_spLand(0), m_bLoadComplete(0), m_bLOD(abLOD)
{
    char acPath[0x104];
    if (!abLOD)
    {
        if (!bForce && !g_thePlayer_011dea3c->GetByteAtOffset())
        {
            if (bAlt)
                BuildLODBlockFilePath(acPath, m_iWorld, iLevel, (unsigned short)iX, (unsigned short)iY);
            else
                FormatLODBlockFileName(acPath, m_iWorld, iLevel, (unsigned short)iX, (unsigned short)iY);
        }
        else
        {
            if (bAlt)
            {
                BuildLODBlockFilePath(acPath, m_iWorld, iLevel, (unsigned short)iX, (unsigned short)iY);
            }
            else
            {
                BuildLODBlockFileName(acPath, m_iWorld, iLevel, (unsigned short)iX, (unsigned short)iY);
                if (!FUN_00456a20(acPath, 0, 0, -1))
                    FormatLODBlockFileName(acPath, m_iWorld, iLevel, (unsigned short)iX, (unsigned short)iY);
            }
        }
    }
    else
    {
        if (bAlt)
            FormatStingerBlockPath(acPath, m_iWorld, iLevel, (unsigned short)iX, (unsigned short)iY);
        else
            BuildStingerNifPath(acPath, m_iWorld, iLevel, (unsigned short)iX, (unsigned short)iY);
    }
    FUN_00c3cee0(acPath + 5);
    LookupFileEntryByArchive(0);
}

enum F7070Priority
{
    F7070_PRIORITY_DEFAULT
};

struct F7070ModelLoader
{
    void QueueTask(const char* pcPath, F7070Priority ePriority, void* pkTask);
};

extern F7070ModelLoader* g_pModelLoader;

class F7070IOTask
{
  public:
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void vfunc08();
    virtual void vfunc0C();
    virtual void vfunc10();
    virtual void vfunc14();
    virtual void vfunc18();
    virtual void vfunc1C();
    virtual void vfunc20();
    virtual void vfunc24();
    virtual void Finish();

    F7070Priority GetPriority();

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
    bool bFadeQueuedCur;
    char unk31;
    char unk32;
    char unk33;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    TESWorldSpace* m_pContainingWorldspace;
    int unk48;
    int unk4C;
    char unk50;
    bool bSkipLoad;
};

class F7070LODTask : public F7070IOTask
{
  public:
    void QueueLODModelLoads();
};

// @fnv 0x006f7070
void F7070LODTask::QueueLODModelLoads()
{
    char acFirstPath[260];
    char acSecondPath3[260];
    if (!bSkipLoad)
    {
        FormatBuildingsLODTexturePath(acFirstPath, m_pContainingWorldspace);
        g_pModelLoader->QueueTask(acFirstPath, GetPriority(), this);
        FUN_006f57c0(acSecondPath3, m_pContainingWorldspace);
        g_pModelLoader->QueueTask(acSecondPath3, GetPriority(), this);
    }
    bFadeQueuedCur = true;
    Finish();
}

// ---------------------------------------------------------------------------
// UpdateLoadingState - updates the distant object block of one cell.
//
// The task object keeps the block that is currently being loaded (+0x40), the
// two nodes the block refers to (+0x48 / +0x4c), the coordinates of the cell
// (+0x34 / +0x38 / +0x3c) and a flag (+0x50) that tells whether the block was
// already segmented.
//
// While the block is loaded the task asks the block to keep its load state
// (+0x40 -> SetLoading) and marks the segmented object of the block chain as
// segmented.  When the block is not segmented the game complains about it.
// Once the block was segmented both node references are dropped again.
// ---------------------------------------------------------------------------

// A node of the distant object scene graph.  The eleventh virtual function
// tells whether the node has been segmented.
struct FnvDistantNode
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
    virtual int v10();
};

// The object that carries the "segmented" flag at +0x28.
struct FnvDistantSegment
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
    unsigned char unk28;
    void SetSegmented(bool abFlag);
};

// One link of the reference chain of a block.
struct FnvDistantLink
{
    FnvDistantSegment* unk00;
    FnvDistantSegment* Get();
};

// The distant object block of one cell.
struct FnvDistantBlock
{
    FnvDistantLink* unk00;
    FnvDistantLink* Get();
    void SetLoading(bool abFlag);
};

// A reference counted pointer to a node.
template <class T> struct FnvDistantPtr
{
    T* unk00;
    T* Get();
    FnvDistantPtr& operator=(T* apNode);
};

// The task that loads a distant object block.
struct FnvDistantBlockLoadTask
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
    FnvDistantBlock* unk40;
    int unk44;
    FnvDistantPtr<FnvDistantNode> unk48;
    FnvDistantPtr<FnvDistantNode> unk4C;
    unsigned char unk50;
    void UpdateLoadingState();
};

// The game logs a warning with a printf style format string.
void __cdecl FNV_Warning(const char* apFormat, ...);

// @fnv 0x006f73d0
void FnvDistantBlockLoadTask::UpdateLoadingState()
{
    if (unk48.Get() != 0)
    {
        if (unk50 == 0)
        {
            unk40->SetLoading(1);
            unk40->Get()->Get()->SetSegmented(1);

            if (unk48.Get()->v10() == 0)
            {
                FNV_Warning("MODELS: Found a distant object block for %i:%i,%i but it is not segmented.", unk3C, unk34,
                            unk38);
            }
        }
        else
        {
            unk48 = 0;
            unk4C = 0;
        }
    }
    else
    {
        if (unk50 == 0 && unk40 != 0)
        {
            unk40->SetLoading(0);
        }
    }
}

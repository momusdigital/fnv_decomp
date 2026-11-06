
// src/fallout_shared/bgsdecalnode.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/bgsdecalnode.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef struct GlobalObject_00a7b610
{
    int data;
} GlobalObject_00a7b610;

GlobalObject_00a7b610 g_011c7d34;

struct FUN_004ee0d0_shell
{
    GlobalObject_00a7b610* GetGlobalObject();
};

// @fnv 0x004ee0d0
GlobalObject_00a7b610* FUN_004ee0d0_shell::GetGlobalObject()
{
    return &g_011c7d34;
}

struct BGSDecalNode
{
    BGSDecalNode();
    virtual ~BGSDecalNode();
    void FUN_004ee1e0();
    void* DestroyDecalNode(unsigned int);
    static void operator delete(void* p, unsigned int size);
};

// Calls FUN_004ee1e0 on this, frees the node with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x004ee0e0
void* BGSDecalNode::DestroyDecalNode(unsigned int flags)
{
    this->FUN_004ee1e0();
    if (flags & 1)
        BGSDecalNode::operator delete(this, 0xb4);
    return this;
}

namespace fnv_004ee4d0 {
struct NiAVObject;
struct NiNode
{
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
};
struct BGSDecalNode : NiNode
{
    virtual void AttachChild(NiAVObject* apAVObj, bool abFirstAvailableSlot);
};

// @fnv 0x004ee4d0
void BGSDecalNode::AttachChild(NiAVObject* apAVObj, bool abFirstAvailableSlot)
{
    NiNode::AttachChildInAvailableSlot(apAVObj, abFirstAvailableSlot);
}
}  // namespace fnv_004ee4d0

struct GO
{
    void* p;
    GO(int a);
    ~GO();
};
struct FUN_004ee5d0_shell
{
    void CallVirtualAndForward(int a, GO* g);
};
struct FUN_004ee560_shell
{
    void FUN_004ee560(int a);
};
// @fnv 0x004ee560
void FUN_004ee560_shell::FUN_004ee560(int aiValue)
{
    GO g(0);
    ((FUN_004ee5d0_shell*)this)->CallVirtualAndForward(aiValue, &g);
}

struct PropHelper
{
    void* GetProperty(unsigned int);
};
struct EffectSetting
{
    void FUN_004ee4b0(float);
};
struct BSTempEffect
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
    virtual void* v38();
};
struct FUN_004ee450_shell
{
    void FUN_00a5ed10(void* a, bool b);
    void FUN_004ee450(BSTempEffect* apAVObj, bool abFirstAvailableSlot);
};
// @fnv 0x004ee450
void FUN_004ee450_shell::FUN_004ee450(BSTempEffect* apAVObj, bool abFlag)
{
    void* prop = ((PropHelper*)apAVObj->v38())->GetProperty(3);
    if (prop != 0)
    {
        ((EffectSetting*)prop)->FUN_004ee4b0(1.0f);
    }
    FUN_00a5ed10(apAVObj->v38(), abFlag);
}

struct S1
{
    void RemoveEffect(void*);
};
struct S2
{
    void FUN_00a5e780(void*);
};
struct VirtParam
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
    virtual void v16();
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
    virtual void* v38(void*);
};
struct TargetHost
{
    void CallVirtualAndForward(VirtParam*, void*);
};
// Calls RemoveEffect with a, then calls FUN_00a5e780 with the result of a->v38(b).
// @fnv 0x004ee5d0
void TargetHost::CallVirtualAndForward(VirtParam* pVirtParam, void* b)
{
    ((S1*)this)->RemoveEffect(pVirtParam);
    ((S2*)this)->FUN_00a5e780(pVirtParam->v38(b));
}

struct BSSimpleList
{
    void Remove(GO const&);
};
struct DecalNode
{
    BSSimpleList* pList;
    void RemoveEffect(void* apEffect);
};
// Removes the given effect from the list stored at offset 0xac of this node.
// @fnv 0x004ee4f0
void DecalNode::RemoveEffect(void* apEffect)
{
    GO tmp((int)apEffect);
    (*(BSSimpleList**)((char*)this + 0xac))->Remove(tmp);
}

struct NiFixedString
{
};

struct NiAVObject
{
    void SetName(NiFixedString const& name);
};

struct GlobalObject_004ee810
{
    int data[2];
    GlobalObject_004ee810();
};

struct FUN_004ee390_shell : NiAVObject
{
    unsigned char padding[0xac];
    GlobalObject_004ee810* pGlobalForm;
    unsigned char flag;

    void InitNameAndData();
};

NiFixedString const& FUN_004a2c60();
NiFixedString const& FUN_004ee440();

// Allocates a GlobalObject_004ee810 and sets the object's name from one of two fixed strings depending on flag.
// @fnv 0x004ee390
void FUN_004ee390_shell::InitNameAndData()
{
    pGlobalForm = new GlobalObject_004ee810;

    if (flag)
        SetName(FUN_004a2c60());
    else
        SetName(FUN_004ee440());
}

struct NiObject
{
};

struct CloningProcess
{
};

struct A51BF0Base : public NiObject
{
    char storage[0xb4];

    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
};

struct FUN_004ee050 : public A51BF0Base
{
    FUN_004ee050();
};

struct FUN_004ee6f0_shell : public A51BF0Base
{
    NiObject* CreateClone(CloningProcess& arCloneData);
};

extern int _data_011c16bc;

// Allocates and constructs a new FUN_004ee050 object and returns it as a NiObject pointer.
// @fnv 0x004ee6f0
NiObject* FUN_004ee6f0_shell::CreateClone(CloningProcess& arCloneData)
{
    FUN_004ee050* pNewNode = new FUN_004ee050;
    return pNewNode;
}

struct Point3
{
    float x, y, z;
    void FUN_0043d410(float x, int y, int z);
};
struct DecalBase
{
    DecalBase(int);
    virtual ~DecalBase();
};
struct Callback
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(void* object, int enabled);
    void FUN_00a59c60(Point3* offset);
};
struct FUN_004ee120;
struct EffectsList
{
    void FUN_005ae3d0(FUN_004ee120**);
};
extern EffectsList g_011c7d20;
struct FUN_004ee120 : DecalBase
{
    FUN_004ee120(Callback* callback, unsigned char flag);
    virtual ~FUN_004ee120();
    void InitNameAndData();
};
// @fnv 0x004ee120
FUN_004ee120::FUN_004ee120(Callback* callback, unsigned char flag) : DecalBase(0)
{
    reinterpret_cast<unsigned char*>(this)[0xb0] = flag;
    InitNameAndData();
    callback->v55(this, 1);

    Point3 vecOffset;
    vecOffset.FUN_0043d410(0.0f, 0, 0);
    callback->FUN_00a59c60(&vecOffset);
    FUN_004ee120* pSelf = this;
    g_011c7d20.FUN_005ae3d0(&pSelf);
}

struct FUN_004ee610_view
{
    BSTempEffect* FUN_00559450();
    void FUN_00a59e00(int aValue);
};

struct FUN_004ee610_node
{
    FUN_004ee610_view* FUN_006815c0();
    bool FUN_004a4460();
    FUN_004ee610_node* FUN_00726070();
};

struct FUN_004ee610_cls
{
    unsigned char unk00[0xac];
    FUN_004ee610_node* m_ac;

    int FUN_004b2960();
    void OnVisible(int a1);
};

// @fnv 0x004ee610
void FUN_004ee610_cls::OnVisible(int a1)
{
    if (FUN_004b2960())
    {
        FUN_004ee610_node* node = m_ac;
        while (node != 0 && !node->FUN_004a4460())
        {
            {
                GO local((int)node->FUN_006815c0()->FUN_00559450()->v38());
                if (reinterpret_cast<FUN_004ee610_view*>(&local)->FUN_00559450())
                {
                    reinterpret_cast<FUN_004ee610_view*>(reinterpret_cast<FUN_004ee610_view*>(&local)->FUN_00559450())
                        ->FUN_00a59e00(a1);
                }
                node = node->FUN_00726070();
            }
        }
    }
}

struct DecalListNode
{
    void* vtable;
    DecalListNode* next;
    ~DecalListNode();
};
struct DecalListManager
{
    int unk00;
    DecalListNode* head;
    void FUN_006e5cc0(DecalListNode* node);
    void FUN_0066b0d0(int state);
    void PopHead();
};
// Removes the head node from the list, frees it, or calls FUN_0066b0d0(0) when the list is empty.
// @fnv 0x004ee8a0
void DecalListManager::PopHead()
{
    if (head != 0)
    {
        DecalListNode* node = head;
        head = node->next;
        FUN_006e5cc0(node);
        node->next = 0;
        delete node;
    }
    else
    {
        FUN_0066b0d0(0);
    }
}

namespace s4ee050 {

extern "C" const char DAT_01023734[];

class NodeBase
{
  public:
    NodeBase(unsigned short usChildren);
    ~NodeBase();

    const char* m_pVtbl;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unkb0;
};

struct NodeList
{
    void FUN_005ae3d0(NodeBase* const& pkNode);
};

extern NodeList DAT_011c7d20;

class TrackedNode : public NodeBase
{
  public:
    TrackedNode();

    void InitNameAndData();
};

// @fnv 0x004ee050
TrackedNode::TrackedNode() : NodeBase(0)
{
    m_pVtbl = DAT_01023734;
    InitNameAndData();
    DAT_011c7d20.FUN_005ae3d0(this);
}

}

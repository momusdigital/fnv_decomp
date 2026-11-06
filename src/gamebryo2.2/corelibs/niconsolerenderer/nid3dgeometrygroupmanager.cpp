// gamebryo2.2/corelibs/niconsolerenderer/nid3dgeometrygroupmanager.cpp: NiD3DGeometryGroupManager, Holder (12 functions)

#include "nid3dgeometrygroupmanager_decls.h"
// Allocates and initialises a NiD3DGeometryGroupManager, stores the device and buffers, and AddRefs the device.
// @fnv 0x00e88eb0
NiD3DGeometryGroupManager* NiD3DGeometryGroupManager::Create(Direct3DDeviceInterface* device,
                                                             VertexDeclarationLayout* buffers)
{
    NiD3DGeometryGroupManager* p = (NiD3DGeometryGroupManager*)NiMemObject::operator new(28);
    if (p)
    {
        p->FUN_00a7f810();
        p->vtable = DAT_010ef718;
        p->groups.data = 0;
        p->groups.capacity = 0;
        p->groups.count = 0;
        p->device = 0;
        p->buffers = 0;
        p->flag = false;
    }
    else
        p = 0;
    p->device = device;
    device->AddRef();
    p->buffers = buffers;
    return p;
}

struct NiGeometryData;
struct NiSkinInstance;
struct FUN_00e88fa0_shell : public NiD3DGeometryGroupManager
{
    bool FUN_00e88fa0(NiGeometryGroup*, NiGeometryData*, NiSkinInstance*, bool, unsigned int, unsigned int);
};

bool __fastcall ProcessCollector(void*, int, NiGeometryGroup*, NiGeometryData*, NiSkinInstance*, bool, unsigned int,
                                 unsigned int);

struct FUN_00e88dc0_caller
{
    bool call(NiGeometryGroup* a, NiGeometryData* b, NiSkinInstance* c, bool d, unsigned int e, unsigned int f)
    {
        return false;
    }
};

// Forwards the geometry group, data and skin instance to ProcessCollector along with the bool at pThis+0x18 and two zero arguments.
// @fnv 0x00e88fa0
bool __fastcall FUN_00e88fa0(void* pThis, int, NiGeometryGroup* pkGroup, NiGeometryData* pkData,
                             NiSkinInstance* pkSkinInstance)
{
    typedef bool(__thiscall * Fn)(void*, NiGeometryGroup*, NiGeometryData*, NiSkinInstance*, bool, unsigned int,
                                  unsigned int);
    return ((Fn)&ProcessCollector)(pThis, pkGroup, pkData, pkSkinInstance, *((bool*)pThis + 0x18), 0, 0);
}

struct FUN_00e88c90_shell : public NiD3DGeometryGroupManager
{
    bool IsGroupEmpty(NiGeometryGroup*);
};

// @fnv 0x00e88c90
bool FUN_00e88c90_shell::IsGroupEmpty(NiGeometryGroup* pkGroup)
{
    return *(unsigned int*)((char*)pkGroup + 4) == 0;
}

struct FUN_00e88ca0_Data
{
    int _pad[7];
    int m1c;
};
struct FUN_00e88ca0_Group
{
    virtual void f0();
    virtual void f1(FUN_00e88ca0_Data*);
};
struct FUN_00e88ca0_t
{
    bool CheckAndDispatch(FUN_00e88ca0_Group* pkGroup, FUN_00e88ca0_Data* pkData);
};
// Returns false if pkData->m1c is nonzero; otherwise calls pkGroup->f1(pkData) and returns true.
// @fnv 0x00e88ca0
bool FUN_00e88ca0_t::CheckAndDispatch(FUN_00e88ca0_Group* pkGroup, FUN_00e88ca0_Data* pkData)
{
    if (pkData->m1c != 0)
        return false;
    pkGroup->f1(pkData);
    return true;
}

struct NiScreenTexture;
struct FUN_00e88cc0_shell : public NiD3DGeometryGroupManager
{
    bool FUN_00e88cc0(NiScreenTexture*);
};

struct NiGeometryBufferData
{
    void* _f0;
    void* _f1;
    void* m_pkActorGroup;
};
struct GroupVCall
{
    virtual void Unk0();
    virtual void Unk1();
    virtual void Unk2();
    virtual void Unk3(NiScreenTexture*);
};
// @fnv 0x00e88cc0
bool FUN_00e88cc0_shell::FUN_00e88cc0(NiScreenTexture* pkScreenTexture)
{
    NiGeometryGroup* pkGroup;
    NiGeometryBufferData* pkBuffData;
    pkBuffData = *(NiGeometryBufferData**)((char*)pkScreenTexture + 0x1c);
    if (!pkBuffData)
        return false;
    pkGroup = (NiGeometryGroup*)pkBuffData->m_pkActorGroup;
    ((GroupVCall*)pkGroup)->Unk3(pkScreenTexture);
    if (*(unsigned int*)((char*)pkGroup + 4) == 0)
        ((GroupVCall*)pkGroup)->Unk0();
    return true;
}

struct Elem9
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(int);
};
struct Rel3
{
    virtual void __stdcall g0();
    virtual void __stdcall g1();
    virtual void __stdcall g2();
};
struct Holder
{
    void* vf;
    Elem9** arr;
    int _08;
    unsigned int cnt;
    Rel3* p;
    void FUN_00a7f820();
    void FUN_00e88d60();
};
void __cdecl FUN_00e94290();
void __cdecl _NiFreeAlias(void*);
// @fnv 0x00e88d60
void Holder::FUN_00e88d60()
{
    unsigned int n = cnt;
    unsigned int i = 0;
    vf = DAT_010ef718;
    for (; i < n; ++i)
    {
        Elem9* e = arr[i];
        if (e)
            e->f9(1);
    }
    FUN_00e94290();
    if (p)
        p->g2();
    _NiFreeAlias(arr);
    FUN_00a7f820();
}

void __cdecl _delete(void*, unsigned int);
struct FUN_00e88e90_shell
{
    void FUN_00e88d60();
    void* DestroyIfOwned(unsigned int);
};
// Calls FUN_00e88d60, then deletes this with _delete(this, 0x1c) if flags has bit 1 set, and returns this.
// @fnv 0x00e88e90
void* FUN_00e88e90_shell::DestroyIfOwned(unsigned int flags)
{
    FUN_00e88d60();
    if (flags & 1)
        _delete(this, 0x1c);
    return this;
}

struct FUN_Elem;
struct FUN_B
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(FUN_Elem* e);
    int m_04;
};
struct FUN_A
{
    int m_00;
    int m_04;
    FUN_B* m_08;
};
struct FUN_Elem
{
    unsigned char pad[0x28];
    FUN_A* m_28;
};
struct FUN_P
{
    int m_00;
    int m_04;
    unsigned int m_08;
    FUN_Elem* m_0C;
};
// @fnv 0x00e88d00
bool __stdcall FUN_00e88d00(FUN_P* p)
{
    unsigned int cnt = p->m_08;
    FUN_Elem* e = p->m_0C;
    FUN_B* b = e->m_28->m_08;
    bool flag = false;
    if (cnt > 0)
    {
        unsigned int n = cnt;
        do
        {
            FUN_A* a = e->m_28;
            if (a)
            {
                a->m_08->f4(e);
                flag = true;
            }
            ++e;
            --n;
        } while (n != 0);
        if (flag && b->m_04 == 0)
            b->f0();
    }
    return flag;
}

struct FUN_00e88c30_elem
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(int);
};

struct FUN_00e88c30_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3(FUN_00e88c30_elem* p);
    FUN_00e88c30_elem** m_04;
    unsigned int m_08;
    unsigned int m_0c;
    bool RemoveElement(FUN_00e88c30_elem* p);
};

// @fnv 0x00e88c30
bool FUN_00e88c30_cls::RemoveElement(FUN_00e88c30_elem* pElement)
{
    if (pElement != 0 && this->v3(pElement))
    {
        unsigned int uiIndex = 0;
        unsigned int n = m_0c;
        if (n > 0)
        {
            FUN_00e88c30_elem** cur = m_04;
            do
            {
                if (*cur == pElement)
                {
                    goto found;
                }
                ++cur;
                ++uiIndex;
            } while (uiIndex < n);
        }
        uiIndex = 0xffffffff;
    found:

        unsigned int& cnt = m_0c;
        --cnt;
        FUN_00e88c30_elem** arr = m_04;
        arr[uiIndex] = arr[cnt];
        pElement->f9(1);
        return true;
    }
    return false;
}

struct GeomSlotB
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5(void* pOwner);
    virtual void Slot6();
    int m_04;
};

struct GeomSlotA
{
    int m_00;
    int m_04;
    GeomSlotB* m_08;
};

struct GeomOwner
{
    unsigned char pad[0x34];
    GeomSlotA* m_34;
};

struct GeomRef
{
    unsigned char pad[0xc];
    void* m_0C;
};

// Checks pRef's m_0C via FUN_00e88d00, otherwise calls Slot5 on pOwner's m_34->m_08 and Slot0 if m_04 is zero, returning true or false.
// @fnv 0x00e88e40
bool __stdcall FUN_00e88e40(GeomOwner* pGeomOwner, GeomRef* pGeomRef)
{
    if (pGeomRef == 0)
    {
        goto owner;
    }
    if (pGeomRef->m_0C == 0)
    {
        goto owner;
    }
    return FUN_00e88d00(reinterpret_cast<FUN_P*>(pGeomRef->m_0C));
owner:
    if (pGeomOwner->m_34 == 0)
    {
        return false;
    }
    GeomSlotB* pSlotB = pGeomOwner->m_34->m_08;
    pSlotB->Slot5(pGeomOwner);
    if (pSlotB->m_04 == 0)
    {
        pSlotB->Slot0();
    }
    return true;
}

struct IDeviceE88
{
    virtual long __stdcall QueryInterface(const void* riid, void** ppvObj) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

class NiGeometryGroupE88
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    IDeviceE88* m_pD3DDevice;

    void SetDevice(IDeviceE88* pkDevice)
    {
        m_pD3DDevice = pkDevice;
        pkDevice->AddRef();
    }
};

NiGeometryGroupE88* CreateStaticGroupE88();
NiGeometryGroupE88* CreateUnsharedGroupE88();
NiGeometryGroupE88* CreateDynamicGroupE88();

template <class T> class NiTPrimitiveSetE88
{
  public:
    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;

    void Realloc(unsigned int uiNewSize);

    int Find(const T& element) const
    {
        for (unsigned int i = 0; i < m_uiAllocatedCapacity; i++)
        {
            if (m_pBase[i] == element)
                return i;
        }
        return -1;
    }

    void Add(const T& element)
    {
        if (m_uiAllocatedCapacity == m_uiElementCount)
            Realloc(m_uiElementCount > 0 ? 2 * m_uiElementCount : 1);
        m_pBase[m_uiAllocatedCapacity++] = element;
    }
};

class NiGeometryGroupManagerE88
{
  public:
    enum RepackingBehavior
    {
        STATIC,
        UNSHARED,
        DYNAMIC
    };

    void* m_ppVirtualMethodTable;
    NiTPrimitiveSetE88<NiGeometryGroupE88*> m_kObjectGroups;
    IDeviceE88* m_pD3DDevice;

    __forceinline void AddGroup(NiGeometryGroupE88* pkGroup)
    {
        if (m_kObjectGroups.Find(pkGroup) >= 0)
            return;
        m_kObjectGroups.Add(pkGroup);
        pkGroup->SetDevice(m_pD3DDevice);
    }

    NiGeometryGroupE88* CreateGroup(RepackingBehavior eBehavior);
};

// Creates a geometry group for the given repacking behavior, adds it to the manager's set, and returns it (or null for an unknown behavior).
// @fnv 0x00e88f10
NiGeometryGroupE88* NiGeometryGroupManagerE88::CreateGroup(RepackingBehavior eBehavior)
{
    NiGeometryGroupE88* pkGroup = 0;
    switch (eBehavior)
    {
    case STATIC:
        pkGroup = CreateStaticGroupE88();
        break;
    case UNSHARED:
        pkGroup = CreateUnsharedGroupE88();
        break;
    case DYNAMIC:
        pkGroup = CreateDynamicGroupE88();
        break;
    }
    if (pkGroup)
        AddGroup(pkGroup);
    return pkGroup;
}

struct HkElem2c
{
    int unk00;
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
};
struct HkInfo
{
    int unk00;
    int unk04;
    unsigned int unk08;
    HkElem2c* unk0c;
};
struct HkInput
{
    int unk00;
    int unk04;
    int unk08;
    HkInfo* unk0c;
};
struct HkBody
{
    int unk00;
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
};
struct HkCollector
{
    virtual void vf0();
    virtual void vf1();
    virtual void Process(HkBody* body, HkInput* input, HkElem2c* elem);
};

// Processes each element of the info array when enabled; otherwise calls Process once with null if body->unk34 is zero.
// @fnv 0x00e88dc0
bool __stdcall ProcessCollector(HkCollector* collector, HkBody* body, HkInput* input, bool flag, int unused1,
                                int unused2)
{
    if (input && flag && input->unk0c)
    {
        HkInfo* info = input->unk0c;
        HkElem2c* elem = info->unk0c;
        if (elem->unk28 != 0)
            return false;
        unsigned int count = info->unk08;
        for (unsigned int i = 0; i < count; ++i)
        {
            collector->Process(body, input, &elem[i]);
        }
        return true;
    }
    if (body->unk34 != 0)
        return false;
    collector->Process(body, input, 0);
    return true;
}

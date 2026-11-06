
// to their real unit once identified.

// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
#include "niconsolepersistentsrctexturerendererdata_decls.h"
struct NiStream
{
    void ResetStreamState();
};
struct NiObject
{
    void LoadBinary(NiStream&);
};
struct FUN_00c36040_Class
{
    void __thiscall FUN_00c36040(NiStream* stream);
};
struct FUN_00c36220_class
{
    void* __thiscall AppendCameraPathEntries(int);
    void* __thiscall GetViewerStrings(int arg);
};
struct S_00c36290
{
    void FUN_00c35eb0();
    void* FUN_00c36290(unsigned int);
};
void _delete(void*, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct R_00c362c0
{
    virtual void f0();
    virtual void f1();
    volatile long ref;
};
struct S_00c362c0
{
    R_00c362c0* ptr;
    void FUN_00c362c0();
};
extern "C" void* g_01202810;
struct FUN_00c36300_Class
{
    void* __thiscall GetRTTI();
};
struct BSMultiBound
{
    void* b[4];
    BSMultiBound();
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct FUN_00c35f50_class
{
    void __thiscall FUN_00c35fe0(BSMultiBound*, int);
    BSMultiBound* __thiscall CreateClone(int);
};
extern int _data_011c16bc;
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};
BSMultiBound* FUN_00c361a0();

struct Obj
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
    virtual unsigned char v45(int a);
};

struct SP
{
    Obj* m_p;
    operator Obj*() const
    {
        return m_p;
    }
    Obj* operator->() const
    {
        return m_p;
    }
};

struct Cls
{
    void* m_ppVirtualMethodTable;
    unsigned int m_u04;
    unsigned int m_u08;
    SP m_sp;

    unsigned char __thiscall QPointWithin(int arg);
};

// @fnv 0x00c36240
unsigned char Cls::QPointWithin(int arg)
{
    if (m_sp)
        return m_sp->v45(arg);
    return 0;
}

struct NiNode
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
    virtual NiNode* MakeClone(int kCloning);
};

template <class T> class NiPointer
{
  public:
    T* m_p;
    operator T*() const
    {
        return m_p;
    }
    T* operator->() const
    {
        return m_p;
    }
    NiPointer& operator=(T* pObject)
    {
        T* pOld = m_p;
        m_p = pObject;
        for (int i = 0; i < 1; ++i)
        {
            if (pObject)
                pObject->v00();
            if (pOld)
                pOld->v00();
        }
        return *this;
    }
};

class NiObjectCM
{
  public:
    void CopyMembersStream(unsigned int uFlags, void* pvStream);
};

struct BSMbW
{
    void* q0;
    void* q1;
    void* q2;
    NiPointer<NiNode> m_spShape;
};

// @fnv 0x00c35fe0
void FUN_00c35f50_class::FUN_00c35fe0(BSMultiBound* pkDest, int kCloning)
{
    ((NiObjectCM*)this)->CopyMembersStream((unsigned int)pkDest, (void*)kCloning);
    NiNode* pNewInstance = ((BSMbW*)this)->m_spShape->MakeClone(kCloning);
    ((BSMbW*)pkDest)->m_spShape = pNewInstance;
}

struct FUN_00c360a0_target_shell
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
    virtual void f21(void* arg);
};

struct FUN_00c360a0_sp_shell
{
    FUN_00c360a0_target_shell* m_p;
    operator FUN_00c360a0_target_shell*() const
    {
        return m_p;
    }
    FUN_00c360a0_target_shell* operator->() const
    {
        return m_p;
    }
};

struct FUN_00a5d2f0_shell
{
    bool __thiscall FUN_00a5d2f0(void* arg);
};

struct FUN_00c360a0_shell
{
    void* unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_00c360a0_sp_shell m_sp0c;

    bool __thiscall RegisterStreamables(void* arg);
};

// @fnv 0x00c360a0
bool FUN_00c360a0_shell::RegisterStreamables(void* arg)
{
    if (!((FUN_00a5d2f0_shell*)this)->FUN_00a5d2f0(arg))
        return false;
    m_sp0c->f21(arg);
    return true;
}

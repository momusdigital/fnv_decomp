
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

// @fnv 0x00c36040
void __thiscall FUN_00c36040_Class::FUN_00c36040(NiStream* stream)
{
    ((NiObject*)this)->LoadBinary(*stream);
    stream->ResetStreamState();
}

namespace fnv_00c36070 {
class NiStream;
class NiObject
{
  public:
    virtual void LinkObject(class NiStream&);
};
class NiStream
{
  public:
    class NiObject* GetLoadedObject();
};
struct GO
{
    GO& operator=(void*);
};
struct Holder : public NiObject
{
    char _pad[8];
    GO m_go;
    void FUN_00c36070(class NiStream&);
};
// @fnv 0x00c36070
void Holder::FUN_00c36070(class NiStream& stream)
{
    int _u1;
    int _u2;
    NiObject::LinkObject(stream);
    m_go = stream.GetLoadedObject();
}
}  // namespace fnv_00c36070

struct FUN_00c36220_class
{
    void* __thiscall AppendCameraPathEntries(int);
    void* __thiscall GetViewerStrings(int arg);
};

// @fnv 0x00c36220
void* __thiscall FUN_00c36220_class::GetViewerStrings(int arg)
{
    return AppendCameraPathEntries(arg);
}

struct S_00c36290
{
    void FUN_00c35eb0();
    void* FUN_00c36290(unsigned int);
};
void _delete(void*, unsigned int);
// @fnv 0x00c36290
void* S_00c36290::FUN_00c36290(unsigned int flags)
{
    this->FUN_00c35eb0();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

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
// @fnv 0x00c362c0
void S_00c362c0::FUN_00c362c0()
{
    R_00c362c0* p;
    if (ptr)
    {
        p = ptr;
        if (InterlockedDecrement(&p->ref) == 0)
            p->f1();
    }
}

extern "C" void* g_01202810;

struct FUN_00c36300_Class
{
    void* __thiscall GetRTTI();
};

// @fnv 0x00c36300
void* __thiscall FUN_00c36300_Class::GetRTTI()
{
    return &g_01202810;
}

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

// @fnv 0x00c35f50
BSMultiBound* FUN_00c35f50_class::CreateClone(int a)
{
    BSMultiBound* t = new BSMultiBound;
    FUN_00c35fe0(t, a);
    return t;
}

extern int _data_011c16bc;

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

// @fnv 0x00c361a0
BSMultiBound* FUN_00c361a0()
{
    return new BSMultiBound;
}

// @fnv 0x00c36130
struct S_00c36130
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    bool IsSameAs(S_00c36130*);
    bool IsEqual(S_00c36130*);
};
bool S_00c36130::IsEqual(S_00c36130* arg)
{
    bool result = IsSameAs(arg);
    S_00c36130* other = arg;
    {
        int a;
        int b;
        if ((bool)(int)(unk0c == other->unk0c) && ((a = unk08) == (b = other->unk08)))
        {
            result = true;
        }
        else
        {
            result = false;
        }
    }
    return result;
}

struct FUN_00c360f0_StreamVTable
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
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12(int);
};

struct FUN_00c360f0_shell : fnv_00c36070::NiObject
{
    int unk04;
    int unk08;
    int val;
    void SaveBinary(fnv_00c36070::NiStream&);
};

// @fnv 0x00c360f0
void FUN_00c360f0_shell::SaveBinary(fnv_00c36070::NiStream& s)
{
    fnv_00c36070::NiObject::LinkObject(s);
    int tmp = val;
    reinterpret_cast<FUN_00c360f0_StreamVTable&>(s).f12(tmp);
}

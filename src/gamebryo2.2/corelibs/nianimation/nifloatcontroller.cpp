
// src/gamebryo2.2/corelibs/nianimation/nifloatcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nifloatcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiStream
{
    void ResetStreamState();
};

struct NiTimeController
{
    virtual void LoadBinary(NiStream&);
};

struct NiFloatController : NiTimeController
{
    void FUN_00a57970(NiStream&);
};

// @fnv 0x00a57970
void NiFloatController::FUN_00a57970(NiStream& stream)
{
    NiTimeController::LoadBinary(stream);
    stream.ResetStreamState();
}

class CloningProcess;
struct HelperBase00a57a40
{
    void ProcessClone(CloningProcess&);
};
struct HelperData00a57a40
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void ProcessClone(CloningProcess&);
};
struct StandIn00a57a40
{
    void FUN_00a57a40(CloningProcess&);
};
// Calls ProcessClone on this and, if the pointer at offset 0x38 is set, on that object too.
// @fnv 0x00a57a40
void StandIn00a57a40::FUN_00a57a40(CloningProcess& kCloning)
{
    ((HelperBase00a57a40*)this)->ProcessClone(kCloning);
    HelperData00a57a40* pData = *(HelperData00a57a40**)((char*)this + 0x38);
    if (pData)
        pData->ProcessClone(kCloning);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct FakeObj543
{
    virtual void F00();
    virtual void DeleteThis();
    long m_ref;
};
struct StreamHelper543
{
    FakeObj543* GetLoadedObject();
};
struct CtrlHelper543
{
    void LinkObject(NiStream&);
};
struct FUN_00a57a70_shell
{
    void FUN_00a57a70(NiStream&);
};
// Links the object obtained from the stream into the field at offset 0x38, releasing the previous object and incrementing the new one's reference count.
// @fnv 0x00a57a70
void FUN_00a57a70_shell::FUN_00a57a70(NiStream& kStream)
{
    ((CtrlHelper543*)this)->LinkObject(kStream);
    FakeObj543* pkObj = ((StreamHelper543*)&kStream)->GetLoadedObject();
    FakeObj543* pOld = *(FakeObj543**)((char*)this + 0x38);
    if (pOld != pkObj)
    {
        if (pOld)
        {
            if (InterlockedDecrement((long volatile*)&pOld->m_ref) == 0)
                pOld->DeleteThis();
        }
        *(FakeObj543**)((char*)this + 0x38) = pkObj;
        if (pkObj)
            InterlockedIncrement((long volatile*)&pkObj->m_ref);
    }
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
extern char const* const g_011f3f58_arg1;
char* __cdecl _FUN_00a7d330(char const*);
struct FUN_00a57bb0_shell
{
    void FUN_00a6d830(StrArr*);
    void AppendString(StrArr*);
};
// Calls FUN_00a6d830, gets a string via _FUN_00a7d330, grows the array if full, then stores the string at the current size index.
// @fnv 0x00a57bb0
void FUN_00a57bb0_shell::AppendString(StrArr* pStrArr)
{
    FUN_00a6d830(pStrArr);
    char* psz = _FUN_00a7d330(g_011f3f58_arg1);
    unsigned int uiSize = *(unsigned short*)((char*)pStrArr + 0xa);
    unsigned int uiCapacity = *(unsigned short*)((char*)pStrArr + 8);
    if (uiSize >= uiCapacity)
    {
        unsigned int uiGrowBy = *(unsigned short*)((char*)pStrArr + 0xe);
        pStrArr->SetSize(uiSize + uiGrowBy);
    }
    pStrArr->SetAt(uiSize, psz);
}

struct TimedAnimationKey
{
    float m_fTime;
};
struct AnimationKey
{
    enum KeyType
    {
        NO_KEY = 0
    };
};
struct NiFloatData
{
    char _pad[8];
    unsigned int m_uiNumKeys;
    TimedAnimationKey* m_pKeys;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucSize;
};
struct FUN_00a579f0_shell
{
    char _pad[0x38];
    NiFloatData* m_spFloatData;
    TimedAnimationKey* GetFloatKeys(unsigned int&, AnimationKey::KeyType&, unsigned char&);
};
// Reads key count, key type and key size from m_spFloatData into the out parameters and returns its key array, or zeroes them and returns null if absent.
// @fnv 0x00a579f0
TimedAnimationKey* FUN_00a579f0_shell::GetFloatKeys(unsigned int& uiNumKeys, AnimationKey::KeyType& eKeyType,
                                                    unsigned char& ucKeySize)
{
    NiFloatData* pkData = m_spFloatData;
    if (pkData)
    {
        uiNumKeys = pkData->m_uiNumKeys;
        eKeyType = pkData->m_eRequestType;
        ucKeySize = pkData->m_ucSize;
        return pkData->m_pKeys;
    }
    uiNumKeys = 0;
    eKeyType = (AnimationKey::KeyType)0;
    ucKeySize = 0;
    return 0;
}

struct BaseCall
{
    bool FUN_00a6d0f0(NiStream&);
};
struct FloatIface
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual void v09() = 0;
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
    virtual void v21(NiStream&) = 0;
};
struct Holder
{
    char pad[0x38];
    FloatIface* ptr;
    bool RegisterStreamables(NiStream&);
};
// @fnv 0x00a57ad0
bool Holder::RegisterStreamables(NiStream& stream)
{
    if (!((BaseCall*)this)->FUN_00a6d0f0(stream))
        return false;
    ptr->v21(stream);
    return true;
}

struct BaseHack
{
    void __thiscall FUN_00a6d730(NiStream&);
};
struct StreamHack
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void SaveLink(void*);
};
struct FakeController
{
    char _pad[0x38];
    void* m_pData;
    void __thiscall SaveBinary(NiStream&);
};
// @fnv 0x00a57b00
void __thiscall FakeController::SaveBinary(NiStream& stream)
{
    ((BaseHack*)this)->FUN_00a6d730(stream);
    ((StreamHack*)&stream)->SaveLink(m_pData);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct MyInterp
{
    virtual void f00();
    virtual void DeleteThis();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual MyInterp* Clone(void*);
    long m_ref;
};
struct CloneableObj
{
    void FUN_00a6cfe0(CloneableObj*, void*);
    void CopyInterpTo(CloneableObj*, void*);
    char _pad[0x38];
    MyInterp* m_sp;
};
// @fnv 0x00a57b50
void CloneableObj::CopyInterpTo(CloneableObj* pkDest, void* pkProc)
{
    FUN_00a6cfe0(pkDest, pkProc);
    MyInterp* pkSrc = m_sp;
    if (pkSrc)
    {
        MyInterp* pkClone = pkSrc->Clone(pkProc);
        MyInterp* pkOld = pkDest->m_sp;
        if (pkOld != pkClone)
        {
            if (pkOld && InterlockedDecrement(&pkOld->m_ref) == 0)
                pkOld->DeleteThis();
            pkDest->m_sp = pkClone;
            if (pkClone)
                InterlockedIncrement(&pkClone->m_ref);
        }
    }
}

// Destructor: release the held reference explicitly, then let the member and base destructors run.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plValue);

class A57990RefObject
{
  public:
    virtual ~A57990RefObject() throw();
    virtual void DeleteThis() throw();
    unsigned int m_uiRefCount;

    void IncRefCount() throw()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

template <class T> class A57990Pointer
{
  public:
    T* m_pObject;

    ~A57990Pointer() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    A57990Pointer& operator=(T* pObject) throw()
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

class A57990Base
{
  public:
    virtual ~A57990Base() throw();
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
};

class FUN_00a57990 : public A57990Base
{
  public:
    A57990Pointer<A57990RefObject> m_pReferencedObject;

    virtual ~FUN_00a57990() throw();
};

// Destructor that clears the smart pointer member, releasing its referenced object.
// @fnv 0x00a57990
FUN_00a57990::~FUN_00a57990() throw()
{
    m_pReferencedObject = 0;
}

struct Iface57b20
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
    virtual unsigned char v23(void* other);
};

struct FUN_00a57b20_cls
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
    Iface57b20* m_38;
    bool FUN_00a6cc80(FUN_00a57b20_cls* other);
    bool IsEqual(FUN_00a57b20_cls* other);
};

// Checks FUN_00a6cc80(other), then calls v23 on m_38 with other's m_38 and returns whether it is nonzero.
// @fnv 0x00a57b20
bool FUN_00a57b20_cls::IsEqual(FUN_00a57b20_cls* other)
{
    if (!FUN_00a6cc80(other))
    {
        return false;
    }
    Iface57b20* pInterface = m_38;
    void* pOtherInterface = other->m_38;
    unsigned char bResult = pInterface->v23(pOtherInterface);
    if (bResult != 0)
    {
        return true;
    }
    return false;
}

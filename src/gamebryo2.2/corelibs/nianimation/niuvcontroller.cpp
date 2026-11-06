
// src/gamebryo2.2/corelibs/nianimation/niuvcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niuvcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00a45a90_shell
{
    // +0x48
    void* m_pSomePtr;
    int __thiscall GetSomeValues(int* a, int* b, char* c);
};

// Reads fields at offsets 0x20, 0x28, 0x4a and 0x24 from the pointer at this+0x48 into the out params and returns the 0x24 value, or zeros if null.
// @fnv 0x00a45a90
int __thiscall FUN_00a45a90_shell::GetSomeValues(int* piValue1, int* piValue2, char* c)
{
    void* p = *(void**)((char*)this + 0x48);
    if (p)
    {
        *piValue1 = *(int*)((char*)p + 0x20);
        *piValue2 = *(int*)((char*)p + 0x28);
        *c = *(char*)((char*)p + 0x4a);
        return *(int*)((char*)p + 0x24);
    }
    else
    {
        *piValue1 = 0;
        *piValue2 = 0;
        *c = 0;
        return 0;
    }
}

extern int g_011f3f18;

// @fnv 0x00a45b30
int* __cdecl FUN_00a45b30()
{
    return &g_011f3f18;
}

struct FUN_00a459f0_shell
{
    int __thiscall GetDataFromMember(int* a, int* b, char* c);
};

// @fnv 0x00a459f0
int __thiscall FUN_00a459f0_shell::GetDataFromMember(int* piValue1, int* piValue2, char* c)
{
    void* p = *(void**)((char*)this + 0x48);
    if (p)
    {
        char* q = (char*)p;
        *piValue1 = *(int*)(q + 8);
        *piValue2 = *(int*)(q + 0x10);
        *c = q[0x48];
        return *(int*)(q + 0xc);
    }
    else
    {
        *piValue1 = 0;
        *piValue2 = 0;
        *c = 0;
        return 0;
    }
}

struct FUN_00a45ae0_shell
{
    // +0x48
    void* m_pSomePtr;
    int __thiscall GetSomePtrValues(int* a, int* b, char* c);
};

// Reads three ints and a byte from the object at this+0x48 into the out params and returns another int, or zeroes them if that pointer is null.
// @fnv 0x00a45ae0
int __thiscall FUN_00a45ae0_shell::GetSomePtrValues(int* piValue1, int* piValue2, char* c)
{
    void* p = *(void**)((char*)this + 0x48);
    if (p)
    {
        char* pc = (char*)p;
        *piValue1 = *(int*)(pc + 0x2c);
        *piValue2 = *(int*)(pc + 0x34);
        *c = pc[0x4b];
        return *(int*)(pc + 0x30);
    }
    else
    {
        *piValue1 = 0;
        *piValue2 = 0;
        *c = 0;
        return 0;
    }
}

struct FUN_00a45a40_shell
{
    // +0x48
    void* m_pSomePtr;
    int __thiscall GetSomeData(int* a, int* b, char* c);
};

// Reads fields from the object at this+0x48 (offset 0x14) into the three out-params and returns q[1], or zeroes them and returns 0 when that pointer is null.
// @fnv 0x00a45a40
int __thiscall FUN_00a45a40_shell::GetSomeData(int* piFirst, int* piSecond, char* c)
{
    void* p = *(void**)((char*)this + 0x48);
    if (p)
    {
        int* q = (int*)((char*)p + 0x14);
        *piFirst = q[0];
        *piSecond = q[2];
        *c = *(char*)((char*)q + 0x35);
        return q[1];
    }
    else
    {
        *piFirst = 0;
        *piSecond = 0;
        *c = 0;
        return 0;
    }
}

void __cdecl _delete(void* p, unsigned int flags);
struct FUN_00a45b60_shell
{
    int __thiscall FUN_00a45b60();
};
struct FUN_00a46000_shell
{
    int __thiscall FUN_00a45b60();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_00a45b60, then if bit 0 of flags is set deletes this with size 0x50, and returns this.
// @fnv 0x00a46000
void* __thiscall FUN_00a46000_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_00a45b60();
    if (flags & 1)
        _delete(this, 0x50);
    return this;
}

struct MyOstr
{
    int _0;
    int _4;
    void* _8;
    int(__cdecl* _C)(MyOstr*, void*, unsigned int, unsigned int*, unsigned int);
    int Write(void* pBuf, unsigned int uiSize)
    {
        unsigned int ui = uiSize;
        int i = _C(this, pBuf, uiSize, &ui, 1);
        _4 += i;
        return i;
    }
};
struct MyStream
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
    virtual void SaveObject(void* p);
    char _004[0x24C];
    MyOstr* m_pBackingStream;
};
struct Base44
{
    char _0[0x44];
    void FUN_00a6d730(MyStream* kStream);
};
struct MyCtrl : Base44
{
    unsigned short m_usValue;
    void* m_pData;
    void SaveBinary(MyStream* kStream);
};
// @fnv 0x00a46070
void MyCtrl::SaveBinary(MyStream* kStream)
{
    Base44::FUN_00a6d730(kStream);
    kStream->m_pBackingStream->Write(&m_usValue, 2);
    kStream->SaveObject(m_pData);
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct BaseCall
{
    void FUN_00a6d830(StrArr*);
};
char* _FUN_00a7d330(const char*);
struct NiUVController
{
    void GetViewerStrings(StrArr*);
};
// @fnv 0x00a46150
void NiUVController::GetViewerStrings(StrArr* pStrArr)
{
    ((BaseCall*)this)->FUN_00a6d830(pStrArr);
    char* s = _FUN_00a7d330((const char*)g_011f3f18);
    unsigned int a = *(unsigned short*)((char*)pStrArr + 0xA);
    unsigned int b = *(unsigned short*)((char*)pStrArr + 8);
    if (a >= b)
    {
        unsigned int c = *(unsigned short*)((char*)pStrArr + 0xE);
        pStrArr->SetSize(c + a);
    }
    pStrArr->SetAt(a, s);
}

namespace fnv_00a45970 {
struct NiStream
{
    int _x;
};
struct NiUVData
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
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21(NiStream&);
};
struct BasePad
{
    char _pad[0x48];
    bool __thiscall FUN_00a6d0f0(NiStream&);
};
struct NiUVController : BasePad
{
    NiUVData* m_pData;
    bool __thiscall RegisterStreamables(NiStream&);
};
// @fnv 0x00a45970
bool __thiscall NiUVController::RegisterStreamables(NiStream& kStream)
{
    if (!FUN_00a6d0f0(kStream))
        return false;
    NiUVData* pkUVData = m_pData;
    if (pkUVData)
        pkUVData->f21(kStream);
    return true;
}
}  // namespace fnv_00a45970

namespace fnv_00a45cf0 {
struct NiTimeController
{
    bool AdvanceController(float fTime);
};

struct NiUpdateData
{
    float fTime;
};

struct NiUVController
{
    NiTimeController m_TimeController;
    char _pad[0x4B];
    bool m_bUpdateEnabled;
    void Update(NiUpdateData& UpdateData);
};

// @fnv 0x00a45cf0
void NiUVController::Update(NiUpdateData& UpdateData)
{
    if (!m_TimeController.AdvanceController(UpdateData.fTime))
        m_bUpdateEnabled = 1;
}
}  // namespace fnv_00a45cf0

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct RefObj_00a45fa0
{
    virtual void F0();
    virtual void F4();
    volatile long m_lRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_lRefCount))
            F4();
    }
};
struct Holder_00a45fa0
{
    char _pad0[0x34];
    int m34;
    int m38;
    int m3c;
    int m40;
    int _pad1;
    RefObj_00a45fa0* m48;
    int __thiscall FUN_00a45bc0();
    void __thiscall AssignRefObj(RefObj_00a45fa0* p);
};
// Releases the old m48 reference, stores p with an incremented refcount, resets m34/m38/m3c/m40, then calls FUN_00a45bc0.
// @fnv 0x00a45fa0
void __thiscall Holder_00a45fa0::AssignRefObj(RefObj_00a45fa0* apRefObj)
{
    if (m48 != apRefObj)
    {
        if (m48)
            m48->DecRefCount();
        m48 = apRefObj;
        if (apRefObj)
            apRefObj->IncRefCount();
    }
    m34 = 0;
    m3c = 0;
    m38 = 0;
    m40 = 0;
    FUN_00a45bc0();
}

namespace fnv_00a45910 {
struct NiObject;
struct NiStream
{
    NiObject* GetLoadedObject();
};
struct NiObject
{
    virtual void F0()
    {}
    virtual void F1()
    {}
    long m_iObjectReferenceCount;
};
struct NiUVData : NiObject
{
};
template <class T> struct NiPointer
{
    T* m_pObject;
};
struct NiTimeController
{
    virtual void LinkObject(NiStream&);
    char _pad[0x44];
};
struct NiUVController : NiTimeController
{
    NiPointer<NiUVData> m_pData;
    void LinkUVData(NiStream&);
};
// Links the controller to the stream, replacing its UV data pointer with the stream's object and updating reference counts.
// @fnv 0x00a45910
void NiUVController::LinkUVData(NiStream& kStream)
{
    NiTimeController::LinkObject(kStream);
    NiUVData* pkData = (NiUVData*)kStream.GetLoadedObject();
    NiUVData* pOld = m_pData.m_pObject;
    if (pOld != pkData)
    {
        if (pOld)
        {
            if (InterlockedDecrement(&pOld->m_iObjectReferenceCount) == 0)
                pOld->F1();
        }
        m_pData.m_pObject = pkData;
        if (pkData)
            InterlockedIncrement(&pkData->m_iObjectReferenceCount);
    }
}
}  // namespace fnv_00a45910

struct RefObjF
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    float m38;
    float m3c;
    float m40;
    float m44;
};

struct HolderF
{
    int unk00;
    int unk01;
    int unk02;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int unk10;
    int unk11;
    int unk12;
    int unk13;
    int unk14;
    int unk15;
    int unk16;
    int unk17;
    RefObjF* m48;
    void __thiscall ResetRefObject();
    void __thiscall FUN_00a6d450();
};

// @fnv 0x00a45b40
void HolderF::ResetRefObject()
{
    RefObjF* p = m48;
    p->m38 = 0.0f;
    p->m3c = 0.0f;
    p->m40 = 1.0f;
    p->m44 = 1.0f;
    FUN_00a6d450();
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct RefObject
{
    virtual void Acquire();
    virtual void ReleaseObject();
    volatile long refCount;

    void DecRefCount()
    {
        if (InterlockedDecrement(&refCount) == 0)
            ReleaseObject();
    }
};

struct SharedRef
{
    RefObject* ptr;
    ~SharedRef() throw()
    {
        if (ptr)
            ptr->DecRefCount();
    }
    void Reset()
    {
        if (ptr)
        {
            ptr->DecRefCount();
            ptr = 0;
        }
    }
};

struct BaseController
{
    virtual ~BaseController() throw();
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
};

struct FUN_00a45b60 : BaseController
{
    SharedRef owner;
    virtual ~FUN_00a45b60() throw();
};

// Destructor that releases the controller's shared owner reference via SharedRef::Reset.
// @fnv 0x00a45b60
FUN_00a45b60::~FUN_00a45b60() throw()
{
    owner.Reset();
}

void* __cdecl FUN_00aa13e0(unsigned int size) throw();
extern int DAT_01098064;

struct SpawnedObject
{
    void* m_pVTable;
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
    int m34;
    int m38;
    int m3c;
    int m40;
    unsigned short m44;
    unsigned short unk46;
    void* m48;
    unsigned char m4c;

    void InitBase() throw();

    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }

    SpawnedObject() throw()
    {
        InitBase();
        *(void* volatile*)&m_pVTable = (void*)&DAT_01098064;
        *(void* volatile*)&m48 = 0;
        *(unsigned short volatile*)&m44 = 0;
        m34 = 0;
        m3c = 0;
        m38 = 0;
        m40 = 0;
        m4c = 0;
    }
};

// Allocates and default-constructs a SpawnedObject, then returns the new instance.
// @fnv 0x00a45f50
SpawnedObject* __cdecl FUN_00a45f50() throw()
{
    SpawnedObject* p = new SpawnedObject();
    return p;
}

struct OutputWriter
{
    int reserved00;
    int writtenBytes;
    int(__cdecl* writeCallback)(OutputWriter*, void*, unsigned int, unsigned int*, unsigned int);
    int Write(void* bytes, unsigned int count)
    {
        unsigned int written = count;
        int result = writeCallback(this, bytes, count, &written, 1);
        writtenBytes += result;
        return result;
    }
};
struct MyStreamWriter : MyStream
{
    void FUN_00a645b0();
    OutputWriter* Output()
    {
        return *reinterpret_cast<OutputWriter**>(&_004[0x248]);
    }
};
struct MyUVController : MyCtrl
{
    void FUN_00a6d5e0(MyStreamWriter* stream);
    void WriteToStream(MyStreamWriter* stream);
};

// @fnv 0x00a46020
void MyUVController::WriteToStream(MyStreamWriter* stream)
{
    FUN_00a6d5e0(stream);
    stream->Output()->Write(&m_usValue, sizeof(m_usValue));
    stream->FUN_00a645b0();
}

// IsEqual: base comparison, then the type value and the (optional) child object must match.

class A59A0Object
{
  public:
    virtual void Unk00();
    virtual void Unk04();
    virtual void Unk08();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18();
    virtual void Unk1C();
    virtual void Unk20();
    virtual void Unk24();
    virtual void Unk28();
    virtual void Unk2C();
    virtual void Unk30();
    virtual void Unk34();
    virtual void Unk38();
    virtual void Unk3C();
    virtual void Unk40();
    virtual void Unk44();
    virtual void Unk48();
    virtual void Unk4C();
    virtual void Unk50();
    virtual void Unk54();
    virtual void Unk58();
    virtual bool IsEqual(A59A0Object* pkObject);
};

template <class T> class A59A0Pointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    bool operator==(T* pObject) const
    {
        return m_pObject == pObject;
    }

    T* m_pObject;
};

class A59A0Base
{
  public:
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

    bool IsEqual(A59A0Base* pkObject);
};

class A59A0Node : public A59A0Base
{
  public:
    unsigned short m_usType;
    unsigned short unk46;
    A59A0Pointer<A59A0Object> m_spChild;

    bool FUN_00a459a0(A59A0Base* pkObject);
};

// @fnv 0x00a459a0
bool A59A0Node::FUN_00a459a0(A59A0Base* pkObject)
{
    A59A0Node* pkOther = (A59A0Node*)pkObject;
    if (!A59A0Base::IsEqual(pkOther))
        return false;

    if (m_usType != pkOther->m_usType)
        return false;

    if ((m_spChild == 0) != (pkOther->m_spChild == 0))
        return false;

    if (m_spChild && !m_spChild->IsEqual(pkOther->m_spChild))
        return false;

    return true;
}

struct CloneableObj
{
    void* m_pVTable;
    void __thiscall FUN_00a6cfe0(void* pObject);
};

struct Base106
{
    virtual ~Base106();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30;
    Base106() throw();
};
struct Reference106
{
    RefObj_00a45fa0* ptr;
    Reference106() throw() : ptr(0)
    {}
};
struct MyUVData : Base106
{
    int m34, m38, m3C, m40;
    unsigned short m44, unk46;
    Reference106 m48;
    unsigned char m4C;
    virtual ~MyUVData();
    static void* operator new(unsigned int size) throw()
    {
        return FUN_00aa13e0(size);
    }
    MyUVData() throw()
    {
        m44 = 0;
        m34 = 0;
        m3C = 0;
        m38 = 0;
        m40 = 0;
        m4C = 0;
    }
    void FUN_00a2c623(RefObj_00a45fa0*);
};
struct MyNiUVController
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
    int m34;
    int m38;
    int m3C;
    int m40;
    unsigned short m44;
    unsigned short unk46;
    RefObj_00a45fa0* m48;

    void __thiscall FUN_00a6cfe0(void* pObject, unsigned int flags);
    unsigned int* __thiscall CloneUVData(unsigned int flags);
};

void __fastcall FUN_00a6d220(void* pObject);

// Allocates a MyUVData, initialises it via FUN_00a6cfe0, copies m34/m38/m3C/m40/m44 and the m48 reference, and returns it.
// @fnv 0x00a460c0
unsigned int* __thiscall MyNiUVController::CloneUVData(unsigned int flags)
{
    MyUVData* pUVData = new MyUVData;

    FUN_00a6cfe0(pUVData, flags);

    pUVData->m34 = m34;
    pUVData->m3C = m3C;
    pUVData->m38 = m38;
    pUVData->m40 = m40;
    pUVData->m44 = m44;

    if (m48)
    {
        pUVData->FUN_00a2c623(m48);
    }

    return reinterpret_cast<unsigned int*>(pUVData);
}

extern float DAT_01016970;
extern float DAT_01015f5c;

struct ChanObj
{
    int unk00;
    int unk04;
    int cnt0;
    float* data0;
    int unk10;
    int cnt1;
    float* data1;
    int unk1c;
    int cnt2;
    float* data2;
    int unk28;
    int cnt3;
    float* data3;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    unsigned char str0;
    unsigned char str1;
    unsigned char str2;
    unsigned char str3;
};

struct Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float m14;
    float m18;
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
    ChanObj* m48;

    void __thiscall FUN_00a45bc0();
};

// Initialises m14/m18 from two globals, then for each of the four channel arrays in m48 takes the first element as a minimum and the last element as a maximum.
// @fnv 0x00a45bc0
void __thiscall Holder::FUN_00a45bc0()
{
    m14 = DAT_01016970;
    m18 = DAT_01015f5c;
    ChanObj* pChan = m48;
    if (pChan)
    {
        float* pData = pChan->data0;
        int iCount = pChan->cnt0;
        unsigned char s = pChan->str0;
        if (pData)
        {
            if (pData[0] < 3.4028234663852886e+38)
                m14 = pData[0];
            iCount -= 1;
            if (*(float*)((char*)pData + s * iCount) > -3.4028234663852886e+38)
                m18 = *(float*)((char*)pData + s * iCount);
        }
    }
    pChan = m48;
    if (pChan)
    {
        float* pData = pChan->data1;
        int iCount = pChan->cnt1;
        unsigned char s = pChan->str1;
        if (pData)
        {
            if (pData[0] < m14)
                m14 = pData[0];
            iCount -= 1;
            if (*(float*)((char*)pData + s * iCount) > m18)
                m18 = *(float*)((char*)pData + s * iCount);
        }
    }
    pChan = m48;
    if (pChan)
    {
        float* pData = pChan->data2;
        int iCount = pChan->cnt2;
        unsigned char s = pChan->str2;
        if (pData)
        {
            if (pData[0] < m14)
                m14 = pData[0];
            iCount -= 1;
            if (*(float*)((char*)pData + s * iCount) > m18)
                m18 = *(float*)((char*)pData + s * iCount);
        }
    }
    pChan = m48;
    if (pChan)
    {
        int iCount = pChan->cnt3;
        unsigned char s = pChan->str3;
        float* pData = pChan->data3;
        if (pData)
        {
            if (pData[0] < m14)
                m14 = pData[0];
            iCount -= 1;
            if (*(float*)((char*)pData + s * iCount) > m18)
                m18 = *(float*)((char*)pData + s * iCount);
        }
    }
}

struct UVKey;
float __cdecl InterpolateKey(float fTime, UVKey* pkKeys, int eType, unsigned int uiNumKeys, unsigned int* puiLastIdx,
                             unsigned char ucSize);
struct UVPoint
{
    float x;
    float y;
};
struct UVGeomData
{
    int unk00;
    int unk04;
    unsigned short m_usVertices;
    unsigned short unk0a;
    unsigned short m_usTrianglePoints;
    UVPoint* __thiscall FUN_00a66960(unsigned short usSet);
    void __thiscall FUN_00a67090(unsigned short usFlags);
    unsigned short GetTextureSets()
    {
        return m_usTrianglePoints & 1;
    }
};
struct UVCtlData
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
    float m_fOffsetU;
    float m_fOffsetV;
    float m_fTilingU;
    float m_fTilingV;
};
struct UVGeom;
struct UVController
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    float m_fControllerTime;
    UVGeom* m_pkTarget;
    int unk30;
    unsigned int m_uiLastIdx0;
    unsigned int m_uiLastIdx1;
    unsigned int m_uiLastIdx2;
    unsigned int m_uiLastIdx3;
    unsigned short m_usValue;
    unsigned short unk46;
    UVCtlData* m_pData;
    bool m_bChanged;

    UVKey* __thiscall GetDataFromMember(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize);
    UVKey* __thiscall GetSomeData(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize);
    UVKey* __thiscall GetSomeValues(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize);
    UVKey* __thiscall GetSomePtrValues(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize);
    void UpdateUVTransform();
};
struct UVGeom
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
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    UVGeomData* m_spGeometryData;
};

// Applies animated UV offset and tiling to the target geometry's texture coordinates when m_bChanged is set.
// @fnv 0x00a45d10
void UVController::UpdateUVTransform()
{
    if (!m_bChanged)
        return;

    UVGeomData* pkData = m_pkTarget->m_spGeometryData;
    if (m_usValue >= pkData->GetTextureSets())
        return;

    float fAnimOffsetU, fAnimOffsetV, fAnimTilingU, fAnimTilingV;
    {
        unsigned int uiNumKeys;
        int eType;
        unsigned char ucSize;
        UVKey* pkKeys;

        fAnimOffsetU = 0.0f;
        pkKeys = GetDataFromMember(uiNumKeys, eType, ucSize);
        if (pkKeys)
            fAnimOffsetU = InterpolateKey(m_fControllerTime, pkKeys, eType, uiNumKeys, &m_uiLastIdx0, ucSize);

        fAnimOffsetV = 0.0f;
        pkKeys = GetSomeData(uiNumKeys, eType, ucSize);
        if (pkKeys)
            fAnimOffsetV = InterpolateKey(m_fControllerTime, pkKeys, eType, uiNumKeys, &m_uiLastIdx2, ucSize);

        fAnimTilingU = 1.0f;
        pkKeys = GetSomeValues(uiNumKeys, eType, ucSize);
        if (pkKeys)
            fAnimTilingU = InterpolateKey(m_fControllerTime, pkKeys, eType, uiNumKeys, &m_uiLastIdx1, ucSize);

        fAnimTilingV = 1.0f;
        pkKeys = GetSomePtrValues(uiNumKeys, eType, ucSize);
        if (pkKeys)
            fAnimTilingV = InterpolateKey(m_fControllerTime, pkKeys, eType, uiNumKeys, &m_uiLastIdx3, ucSize);
    }

    float fScaleU = fAnimTilingU / m_pData->m_fTilingU;
    float fPrevOffsetU = m_pData->m_fOffsetU;
    float fScaleV = fAnimTilingV / m_pData->m_fTilingV;
    float fPrevOffsetV = m_pData->m_fOffsetV;

    UVPoint* pkTex = pkData->FUN_00a66960(m_usValue);

    float fDeltaU = fAnimOffsetU - fPrevOffsetU * fScaleU;
    float fDeltaV = fAnimOffsetV - fPrevOffsetV * fScaleV;
    UVPoint kTrans;
    kTrans.x = 0.5 * (1.0f - fScaleU) - fDeltaU;
    kTrans.y = 0.5 * (1.0f - fScaleV) + fDeltaV;

    unsigned short usVertexCount = pkData->m_usVertices;
    for (unsigned short i = 0; i < usVertexCount; i++)
    {
        pkTex[i].x = pkTex[i].x * fScaleU + kTrans.x;
        pkTex[i].y = pkTex[i].y * fScaleV + kTrans.y;
    }

    UVCtlData* pkUV = m_pData;
    pkUV->m_fOffsetU = fAnimOffsetU;
    pkUV->m_fOffsetV = fAnimOffsetV;
    pkUV->m_fTilingU = fAnimTilingU;
    pkUV->m_fTilingV = fAnimTilingV;

    pkData->FUN_00a67090(8);
    m_bChanged = false;
}

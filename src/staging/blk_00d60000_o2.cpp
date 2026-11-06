
// src/staging/blk_00d60000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

void __cdecl FUN_00d687c0(void);

struct Registry_00dd9380
{
    void* Register(char const*, void(__cdecl*)(void));
};

extern int DAT_01269cd0;
extern void* DAT_01269008;

// @fnv 0x00d68800
void RegisterContactPointsInactive()
{
    Registry_00dd9380* reg = (Registry_00dd9380*)DAT_01269cd0;
    DAT_01269008 = reg->Register("Contact Points (Inactive)", FUN_00d687c0);
}

namespace fnv_00d688d0 {
void FUN_00d68890();
extern int DAT_0126900c;
struct Registry_00dd9380_StandIn
{
    void* FUN_00dd9380(const char*, void(__cdecl*)());
};
extern Registry_00dd9380_StandIn* DAT_01269cd0;
// @fnv 0x00d688d0
void* RegisterContactPointsActive()
{
    DAT_0126900c = (int)DAT_01269cd0->FUN_00dd9380("Contact Points (Active)", FUN_00d68890);
    return (void*)DAT_0126900c;
}
}  // namespace fnv_00d688d0

// Constructor of the class whose vftables live at 0x010d1fb0 / 0x010d1f90 /
// 0x010d1f80 / 0x010d1f70: it calls the immediate base constructor and then
// installs the derived vftable pointers for the four base sub-objects.
extern int DAT_010d1fb0;
extern int DAT_010d1f90;
extern int DAT_010d1f80;
extern int DAT_010d1f70;

struct FUN_00d68770_cls
{
    int* m_pVtbl00;
    int m_unk04;
    int* m_pVtbl08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int* m_pVtbl20;
    int m_unk24;
    int* m_pVtbl28;

    void BaseConstruct(int aParam, int aFlags);
    FUN_00d68770_cls* Construct(int aParam);
};

// @fnv 0x00d68770
FUN_00d68770_cls* FUN_00d68770_cls::Construct(int aParam)
{
    BaseConstruct(aParam, 0xff008000);
    m_pVtbl00 = &DAT_010d1fb0;
    m_pVtbl08 = &DAT_010d1f90;
    m_pVtbl20 = &DAT_010d1f80;
    m_pVtbl28 = &DAT_010d1f70;
    return this;
}

// @fnv 0x00d687b0
void* __stdcall FUN_00d687b0(char* a1)
{
    return a1 + 0x34;
}

struct FnvCpu_FUN_00d687c0_CpuBlock;
struct FnvCpu_FUN_00d687c0_CpuAllocator
{
    virtual void slot00();
    virtual void* Invoke(unsigned int size);
};
struct FnvCpu_FUN_00d687c0_CpuHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d687c0_CpuAllocator* allocator;
};
void* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d687c0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d687c0_CpuBlock* Construct(unsigned int value);
};
// @fnv 0x00d687c0
void* __cdecl FUN_00d687c0(unsigned int value)
{
    FnvCpu_FUN_00d687c0_CpuHolder* holder = static_cast<FnvCpu_FUN_00d687c0_CpuHolder*>(FUN_00c85750());
    FnvCpu_FUN_00d687c0_CpuBlock* block = static_cast<FnvCpu_FUN_00d687c0_CpuBlock*>(holder->allocator->Invoke(52));
    block->size = 52;
    block = block->Construct(value);
    if (block)
        return reinterpret_cast<char*>(block) + 8;
    return 0;
}

extern "C" int DAT_010d203c;
extern "C" int DAT_010d201c;
extern "C" int DAT_010d200c;
extern "C" int DAT_010d1ffc;

void __stdcall FUN_00de29b0(int a, int b);

struct FUN_00d68840_cls
{
    void* m_p00;
    int m_i04;
    void* m_p08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    int m_i1c;
    void* m_p20;
    int m_i24;
    void* m_p28;

    void* Init(int a);
};

// @fnv 0x00d68840
void* FUN_00d68840_cls::Init(int aiValue)
{
    FUN_00de29b0(aiValue, 0xff0000ff);
    m_p00 = (void*)&DAT_010d203c;
    m_p08 = (void*)&DAT_010d201c;
    m_p20 = (void*)&DAT_010d200c;
    m_p28 = (void*)&DAT_010d1ffc;
    return this;
}

// hkpActiveContactPointViewer (Havok Physics) - virtual at vftable offset 0x0c
// of the primary base (complete-object base offset 0) and at slot 11 of the
// base that lives at complete-object offset +0x08.
//
// The routine ignores `this` entirely and converts its single 4-byte stack
// argument into a pointer to the sub-object that sits 0x28 bytes further up.
//
// Original bytes:
//   00d68880  8b 44 24 04   mov eax, dword ptr [esp+4]
//   00d68884  83 c0 28      add eax, 0x28
//   00d68887  c2 04 00      ret 4

// @fnv 0x00d68880
void* __stdcall FUN_00d68880(void* pObject)
{
    return (void*)((char*)pObject + 0x28);
}

namespace fnv_00d68890 {
struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct ObjAllocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct FNV_Buffer
{
    int unk00;
    unsigned short m_w04;
    unsigned short m_w06;
    int unk08;

    void* Init(int a1);
};

AllocHolder* FUN_00c85750();

// @fnv 0x00d68890
void* __cdecl FUN_00d68890(int aiArg)
{
    AllocHolder* holder = FUN_00c85750();
    ObjAllocator* allocator = (ObjAllocator*)holder->m_pAllocator;
    FNV_Buffer* pBuffer = (FNV_Buffer*)allocator->Alloc(0x34);
    pBuffer->m_w04 = 0x34;
    void* r = pBuffer->Init(aiArg);
    return r != 0 ? (char*)r + 8 : 0;
}
}  // namespace fnv_00d68890

// FUN_00d688f0 : tiny global getter.
// Reads the 4-byte global at DAT_0126900c and returns it in eax.

extern int DAT_0126900c;

// @fnv 0x00d688f0
int __cdecl FUN_00d688f0()
{
    return DAT_0126900c;
}

namespace fnv_00d68910 {
struct D68910Allocator
{
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct D68910MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D68910Allocator* m_pStreamAllocator;

    D68910Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" D68910MemoryRouter& __cdecl FUN_00c85750();

class D68910Object
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    ~D68910Object();
    D68910Object* DestroyAndFree(unsigned int uiFlags);
};

// @fnv 0x00d68910
D68910Object* D68910Object::DestroyAndFree(unsigned int uiFlags)
{
    this->~D68910Object();
    if (uiFlags & 1)
        FUN_00c85750().heap().ReleaseBlock(this, m_usMemSizeAndFlags);
    return this;
}
}  // namespace fnv_00d68910

extern char DAT_0126905c;

// @fnv 0x00d6ade0
void* __cdecl FUN_00d6ade0()
{
    return &DAT_0126905c;
}

struct S_00d6adf0_Obj
{
    virtual void vfn00(int arg);
};
// @fnv 0x00d6adf0
void __cdecl cleanupLoadedObject_hkpConstraintInstance(S_00d6adf0_Obj* obj)
{
    obj->vfn00(0);
}

extern int DAT_0126908c;

// @fnv 0x00d6ae00
int* __cdecl FUN_00d6ae00()
{
    return &DAT_0126908c;
}

struct FUN_00c90e00_Obj
{
    void __thiscall FUN_00c90e00(int value);
};

// @fnv 0x00d6ae90
void __cdecl finishLoadedObject_hkpWorldCinfo(FUN_00c90e00_Obj* pObj, int iValue)
{
    if (pObj != 0)
    {
        pObj->FUN_00c90e00(iValue);
    }
}

// 13-byte cdecl forwarder: loads the object pointer, fetches its vtable and
// calls the first virtual slot with a literal 0 argument.
struct VtblForwarder
{
    virtual int v0(int);
};

// @fnv 0x00d6aeb0
int __cdecl cleanupLoadedObject_hkpWorldCinfo(VtblForwarder* p)
{
    return p->v0(0);
}

extern int DAT_01269104;

// @fnv 0x00d6aee0
void* __cdecl FUN_00d6aee0()
{
    return &DAT_01269104;
}

struct ResultFlag
{
    bool value;
    ResultFlag(bool flag) : value(flag)
    {}
    operator bool() const
    {
        return value;
    }
    ResultFlag& operator=(bool flag)
    {
        value = flag;
        return *this;
    }
};
struct MotionSettings
{
    float value0;
    float value1;
    float value2;
    float value3;
    float value4;
    float value5;
    float value6;
    float value7;
    float value8;
    float value9;
    float value10;
    float value11;
    ResultFlag IsValid();
};
// Checks that value0 through value4 lie in [0,1] and that value5 through value11 are non-negative, returning the combined result.
// @fnv 0x00d6b1c0
ResultFlag MotionSettings::IsValid()
{
    ResultFlag result(true);
    result = result && value0 >= 0.0f && value0 <= 1.0f;
    result = result && value1 >= 0.0f && value1 <= 1.0f;
    result = result && value2 >= 0.0f && value2 <= 1.0f;
    result = result && value3 >= 0.0f && value3 <= 1.0f;
    result = result && value4 >= 0.0f && value4 <= 1.0f;
    result = result && value5 >= 0.0f;
    result = result && value6 >= 0.0f;
    result = result && value7 >= 0.0f;
    result = result && value8 >= 0.0f;
    result = result && value9 >= 0.0f;
    result = result && value10 >= 0.0f;
    result = result && value11 >= 0.0f;
    return result;
}

struct D6C180Command
{
    union
    {
        float m_fValue;
        unsigned char m_ucType;
    };
    unsigned char m_ucFlag;
    unsigned char unk05;
    unsigned char unk06;
    unsigned char unk07;
    int unk08;
    int unk0C;
};

extern const double g_dD6C180Offset;

// @fnv 0x00d6c180
void __fastcall WriteCommand(D6C180Command** ppkCursor, unsigned char ucFlag)
{
    D6C180Command* pkCommand = *ppkCursor;
    pkCommand->m_ucFlag = ucFlag;
    pkCommand->m_fValue = (float)(pkCommand->m_fValue + g_dD6C180Offset);
    pkCommand->m_ucType = 3;
    *ppkCursor = pkCommand + 1;
}

struct Inner
{
    void Tail();
};

struct FUN_00d76f90_cls
{
    int unk00;
    int unk04;
    Inner* m_08;
    void FUN_00d76f90();
};

// @fnv 0x00d76f90
void FUN_00d76f90_cls::FUN_00d76f90()
{
    m_08->Tail();
}

namespace fnv_00d68820 {
extern int DAT_01269008;

// @fnv 0x00d68820
int FUN_00d68820()
{
    return DAT_01269008;
}
}  // namespace fnv_00d68820

inline void* operator new(unsigned int, void* pvMem)
{
    return pvMem;
}

struct hkFinishLoadedObjectFlagD6A
{
    int m_bFinishing;
};

template <class T> class hkSmallArrayD6A
{
  public:
    hkSmallArrayD6A() : m_data(0), m_iElementCount(0), m_iCapacityState(0x8000)
    {}

    T* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
};

class hkMemberD6A
{
  public:
    hkMemberD6A(hkFinishLoadedObjectFlagD6A flag) throw();

    int unk00;
    int unk04;
    int unk08;
};

class hkBaseD6A
{
  public:
    __forceinline hkBaseD6A()
    {}
    virtual ~hkBaseD6A();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
};

class hkDerivedD6A : public hkBaseD6A
{
  public:
    __forceinline hkDerivedD6A(hkFinishLoadedObjectFlagD6A flag) : m_kMemberDescriptor(flag)
    {
        m_iType = -16;
    }
    virtual ~hkDerivedD6A();

    hkSmallArrayD6A<int> m_ppData;
    hkMemberD6A m_kMemberDescriptor;
    int m_iType;
};

// Placement-constructs an hkDerivedD6A at pvObject with a finish-loaded flag built from iFinishing, if pvObject is non-null.
// @fnv 0x00d6ae10
void __cdecl ConstructHkDerived(void* pvObject, int iFinishFlag)
{
    if (pvObject)
    {
        hkFinishLoadedObjectFlagD6A flag;
        flag.m_bFinishing = iFinishFlag;
        new (pvObject) hkDerivedD6A(flag);
    }
}

struct hkFinishLoadedObjectFlagD605
{
    int m_bFinishing;
};

class hkReferencedObjectD605
{
  public:
    hkReferencedObjectD605(hkFinishLoadedObjectFlagD605 flag)
    {}
    virtual ~hkReferencedObjectD605();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00d60540 : public hkReferencedObjectD605
{
  public:
    FUN_00d60540(hkFinishLoadedObjectFlagD605 flag);
    virtual ~FUN_00d60540();
};

// @fnv 0x00d60540
FUN_00d60540::FUN_00d60540(hkFinishLoadedObjectFlagD605 flag) : hkReferencedObjectD605(flag)
{}

extern int DAT_010d14f8;
extern int DAT_0102e388;

struct D60590Callback
{
    void FUN_00c905b0();
};

struct D60590Object
{
    int* vtable;
    int unk04;
    D60590Callback* callback;

    void FUN_00d60590();
};

// @fnv 0x00d60590
void D60590Object::FUN_00d60590()
{
    vtable = &DAT_010d14f8;
    callback->FUN_00c905b0();
    vtable = &DAT_0102e388;
}

namespace fnv_00d60860 {
struct HKMemoryManager
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(int);
};
extern HKMemoryManager* DAT_01268364;
extern char DAT_010d14f8;
struct FUN_00d60860
{
    char* m_pVtbl;
    unsigned char m_uc04;
    unsigned short m_usSize;
    void* m_pData;
    unsigned char m_ucType;
    FUN_00d60860(void* pData, unsigned char ucType);
};
// Sets the vtable, size to 1 and type, and stores the result of DAT_01268364->v4(pData) in m_pData.
// @fnv 0x00d60860
FUN_00d60860::FUN_00d60860(void* pData, unsigned char ucType)
{
    m_usSize = 1;
    m_pVtbl = &DAT_010d14f8;
    m_ucType = ucType;
    m_pData = DAT_01268364->v4((int)pData);
}
}  // namespace fnv_00d60860

void __stdcall WriteSwapped(char**, int, int);

// @fnv 0x00d60900
void __stdcall FUN_00d60900(char* p)
{
    WriteSwapped(&p, 2, 1);
}

struct FUN_00d60600_class
{
    void __thiscall WriteSwapped(int a, int b, int c);
    void __thiscall FUN_00d60b20(int a, int b);
};

// @fnv 0x00d60b20
void __thiscall FUN_00d60600_class::FUN_00d60b20(int a, int aiValue)
{
    WriteSwapped(a, 8, aiValue);
}

struct FUN_00d61470_Class
{
    void* FUN_00d61470();
};

// @fnv 0x00d61470
void* FUN_00d61470_Class::FUN_00d61470()
{
    return this;
}

char* __cdecl FUN_00cb1130(char* pcHaystack, const char* pcNeedle);

class hkStringBufD614
{
  public:
    char* m_data;

    int FindSubstring(const char* pcNeedle, int iStartIndex, int iEndIndex) throw();
};

// Searches m_data from iStartIndex for pcNeedle and returns its offset, or -1 if not found.
// @fnv 0x00d61480
int hkStringBufD614::FindSubstring(const char* pcNeedle, int iStartIndex, int iEndIndex) throw()
{
    char* pData = m_data;
    char* p = FUN_00cb1130(pData + iStartIndex, pcNeedle);
    if (p)
        return static_cast<int>(p - m_data);
    return -1;
}

inline char toLowerD614(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

struct hkStringD614
{
    const char* m_kStringBuffer;

    int FindCaseInsensitive(const char* needle) const;
};

// Returns the index of the first case-insensitive occurrence of needle in the string, or -1 if not found.
// @fnv 0x00d614b0
int hkStringD614::FindCaseInsensitive(const char* needle) const
{
    const char* str = m_kStringBuffer;
    for (int i = 0; str[i] != 0; ++i)
    {
        int j;
        for (j = 0; needle[j] != 0; ++j)
        {
            if (toLowerD614(str[i + j]) != toLowerD614(needle[j]))
                break;
        }
        if (needle[j] == 0)
            return i;
    }
    return -1;
}

int __cdecl FUN_00cb1130(int a1, int a2);
struct FUN_00d61520_cls
{
    int unk00;
    int FindOffset(int a, int b, int c);
};
// @fnv 0x00d61520
int FUN_00d61520_cls::FindOffset(int aiValue, int aiUnused1, int aiUnused2)
{
    int esi = -1;
    int r = FUN_00cb1130(unk00, aiValue);
    if (r != 0)
    {
        do
        {
            esi = r - unk00;
            r = FUN_00cb1130(r + 1, aiValue);
        } while (r != 0);
    }
    return esi;
}

struct FnvString
{
    const char* text;
    int FUN_00d61560(const char* other);
};

// @fnv 0x00d61560
int FnvString::FUN_00d61560(const char* other)
{
    unsigned int i = 0;
    while (text[i] != 0)
    {
        if (other[i] == 0)
            break;
        if (text[i] != other[i])
            return 0;
        ++i;
    }
    return other[i] == 0;
}

inline char toLowerD615(char c)
{
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

struct hkStringD615
{
    const char* m_kStringBuffer;

    int FUN_00d615a0(const char* other) const;
};

// @fnv 0x00d615a0
int hkStringD615::FUN_00d615a0(const char* other) const
{
    for (int i = 0; m_kStringBuffer[i] != 0; ++i)
    {
        if (other[i] == 0)
            return 1;
        if (toLowerD615(m_kStringBuffer[i]) != toLowerD615(other[i]))
            return 0;
    }
    return 1;
}

struct FNV_00d61600_Buffer
{
    unsigned char* data;
    int length;
    int FindCharacter(unsigned char character, int start, int limit);
};
// Scans data from start up to limit (clamped to length-1) and returns the index of the first byte equal to character, or -1 if none is found.
// @fnv 0x00d61600
int FNV_00d61600_Buffer::FindCharacter(unsigned char character, int start, int limit)
{
    int end = limit;
    int last = length - 1;
    if (end >= last)
        end = last;
    for (int index = start; index < end; ++index)
    {
        if (data[index] == character)
            return index;
    }
    return -1;
}

struct FUN_00d61640_cls
{
    char* m_data;
    int m_fRestLength;

    int FindLastCharInRange(char c, int startIndex, int endIndex);
};

// Searches m_data backwards from endIndex-1 down to startIndex for character c and returns its index, or -1 if not found.
// @fnv 0x00d61640
int FUN_00d61640_cls::FindLastCharInRange(char c, int startIndex, int endIndex)
{
    if (endIndex > m_fRestLength - 1)
        endIndex = m_fRestLength - 1;

    for (int i = endIndex - 1; i >= startIndex; --i)
    {
        if (m_data[i] == c)
            return i;
    }
    return -1;
}

struct FUN_00d61680_Obj
{
    int unk00;
    void __thiscall FUN_00d61680(unsigned int param);
};

int __cdecl FUN_00cb0fa0(int, int);

// @fnv 0x00d61680
void __thiscall FUN_00d61680_Obj::FUN_00d61680(unsigned int uiValue)
{
    FUN_00cb0fa0(unk00, uiValue);
}

void __cdecl CompareStringsCaseInsensitive(void* pvOwner, int iValue);

struct FUN_00d616a0_cls
{
    void* m_pOwnerObject;

    void FUN_00d616a0(int iValue);
};

// @fnv 0x00d616a0
void FUN_00d616a0_cls::FUN_00d616a0(int iValue)
{
    CompareStringsCaseInsensitive(m_pOwnerObject, iValue);
}

int __stdcall FUN_00d61680(unsigned int value);

// @fnv 0x00d616e0
int __stdcall FUN_00d616e0(unsigned int value)
{
    return FUN_00d61680(value) == 0;
}

int __cdecl FUN_00cb10d0(int s);
struct FUN_00d61700_cls
{
    char* m_00;
    int m_04;
    int EndsWith(char* s);
};
// @fnv 0x00d61700
int FUN_00d61700_cls::EndsWith(char* aString)
{
    int len = FUN_00cb10d0((int)aString);
    if (len > m_04 - 1)
    {
        return 0;
    }
    int start = m_04 - len - 1;
    for (int i = 0; i < len; ++i)
    {
        if (m_00[start + i] != aString[i])
        {
            return 0;
        }
    }
    return 1;
}

int __cdecl FUN_00cb10d0(const char* str);

static inline int tolower_custom(char c)
{
    if ((unsigned char)(c - 'A') <= 25)
        return c + 0x20;
    return c;
}

struct FUN_00d61750_cls
{
    char* m_data;
    int m_fRestLength;

    int EndsWithIgnoreCase(const char* suffix);
};

// Case-insensitively compares the tail of m_data with suffix, returning 1 if it matches and fits within the buffer length.
// @fnv 0x00d61750
int FUN_00d61750_cls::EndsWithIgnoreCase(const char* suffix)
{
    int len = FUN_00cb10d0(suffix);
    if (len > m_fRestLength - 1)
        return 0;

    int offset = m_fRestLength - len - 1;
    for (int i = 0; i < len; ++i)
    {
        char c1 = tolower_custom(m_data[offset + i]);
        char c2 = tolower_custom(suffix[i]);
        if (c1 != c2)
            return 0;
    }
    return 1;
}

struct FUN_00d617d0_cls
{
    char* m_p00;
    int m_i04;
    void RemoveFront(int count);
};
// Removes count bytes from the front of the buffer by shifting the remaining bytes down and reducing m_i04.
// @fnv 0x00d617d0
void FUN_00d617d0_cls::RemoveFront(int count)
{
    if (count > 0)
    {
        m_i04 -= count;
        int remaining = m_i04;
        char* destination = m_p00;
        char* source = destination + count;
        if (remaining > 0)
        {
            for (int i = 0; i < remaining; ++i)
            {
                destination[i] = source[i];
            }
        }
    }
}

struct hkMathD618
{
    static int max2(int x, int y)
    {
        return x > y ? x : y;
    }
};

class hkStringBufD618
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int FindLastCharInRange(char c, int iStartIndex, int iEndIndex) const;
    void RemoveFront(int n);
    void TrimToFileName();
};

// Finds the last '\\' or '/' in the buffer and, if found, truncates the string to start just after it.
// @fnv 0x00d61800
void hkStringBufD618::TrimToFileName()
{
    int iLastSeparator =
        hkMathD618::max2(FindLastCharInRange('\\', 0, 0x7fffffff), FindLastCharInRange('/', 0, 0x7fffffff));
    if (iLastSeparator >= 0)
        RemoveFront(iLastSeparator + 1);
}

struct hkStringD618
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getLength() const
    {
        return m_iElementCount - 1;
    }

    int ReplaceChar(char from, char to, int replaceType);
};

// @fnv 0x00d61840
int hkStringD618::ReplaceChar(char from, char to, int replaceType)
{
    int replaced = 0;
    for (int i = 0; i < getLength(); i++)
    {
        if (m_data[i] == from)
        {
            m_data[i] = to;
            replaced = 1;
            if (replaceType == 0)
                break;
        }
    }
    return replaced;
}

namespace fnv_00d61890 {
struct hkStringD618
{
    static int toLower(char c)
    {
        return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
    }
};

template <class T> class hkArrayD618
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkStringBufD618
{
  public:
    hkArrayD618<char> m_kStringBuffer;

    void ToLower();
};

// Converts every character of the string buffer except the last to lowercase in place.
// @fnv 0x00d61890
void hkStringBufD618::ToLower()
{
    for (int i = 0; i < m_kStringBuffer.GetLogicalSize() - 1; i++)
        m_kStringBuffer[i] = hkStringD618::toLower(m_kStringBuffer[i]);
}
}  // namespace fnv_00d61890

class hkMemoryAllocatorD61B;

struct hkMemoryRouterD61B
{
    int m_00;
    int m_04;
    int m_08;
    hkMemoryAllocatorD61B* m_pTemp;
    hkMemoryAllocatorD61B* m_pStreamAllocator;
    hkMemoryAllocatorD61B& temp()
    {
        return *m_pTemp;
    }
};
void __cdecl FUN_00c908c0(hkMemoryAllocatorD61B& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();

template <class T, int N> class hkInplaceArrayD61B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];

    hkInplaceArrayD61B() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(N | 0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    T* begin()
    {
        return m_data;
    }
    __forceinline void reserve(hkMemoryAllocatorD61B& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(static_cast<hkMemoryRouterD61B*>(FUN_00c85750())->temp(), n);
        m_iElementCount = n;
    }
};

class FUN_00d61b10
{
  public:
    hkInplaceArrayD61B<char, 128> m_kStringBuffer;

    FUN_00d61b10(const char* pcString, int iLength) throw();
};

// Resizes the inline char array to iLength+1, null-terminates it, and copies iLength bytes from pcString into it.
// @fnv 0x00d61b10
FUN_00d61b10::FUN_00d61b10(const char* pcString, int iLength) throw()
{
    m_kStringBuffer.SetSizeAndGrow(iLength + 1);
    m_kStringBuffer[iLength] = 0;
    FUN_00cb1260(m_kStringBuffer.begin(), pcString, iLength);
}

int __cdecl FUN_00cb10d0(int);
void* __cdecl FUN_00c85750();
struct FUN_00d62630_Obj
{
    void FUN_00d62630(int a1, int a2, int a3, int a4);
};
struct FUN_00d61df0_cls
{
    int unk00;
    int unk04;
    FUN_00d61df0_cls* FUN_00d61df0(int arg);
};
// Computes a value from arg, reads a record via FUN_00c85750, and calls FUN_00d62630 with rec[3], unk04-1, arg and that value; returns this.
// @fnv 0x00d61df0
FUN_00d61df0_cls* FUN_00d61df0_cls::FUN_00d61df0(int arg)
{
    int ebx = FUN_00cb10d0(arg);
    int ebp = unk04;
    int* rec = reinterpret_cast<int*>(FUN_00c85750());
    reinterpret_cast<FUN_00d62630_Obj*>(this)->FUN_00d62630(rec[3], ebp - 1, arg, ebx);
    return this;
}

class hkMemoryAllocatorD61E;

struct hkMemoryRouterD61E
{
    int m_00;
    int m_04;
    int m_08;
    hkMemoryAllocatorD61E* m_pTemp;
    hkMemoryAllocatorD61E& temp()
    {
        return *m_pTemp;
    }
};

int __cdecl FUN_00cb10d0(const char* pcString) throw();
void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();
void __cdecl FUN_00c908c0(hkMemoryAllocatorD61E& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

class hkStringBufD61E
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getLength() const
    {
        return m_iElementCount - 1;
    }
    void SetSizeAndGrow(int n)
    {
        hkMemoryAllocatorD61E& kAlloc = static_cast<hkMemoryRouterD61E*>(FUN_00c85750())->temp();
        int iCap = m_iCapacityState & 0x3fffffff;
        if (iCap < n)
        {
            int iNewCap = 2 * iCap;
            FUN_00c908c0(kAlloc, this, n < iNewCap ? iNewCap : n, 1);
        }
        m_iElementCount = n;
    }

    void AppendStrings(const char* s0, const char* s1, const char* s2, const char* s3, const char* s4,
                       const char* s5) throw();
};

// Appends up to six C strings to the buffer, resizing it to fit the combined length plus a terminator.
// @fnv 0x00d61e30
void hkStringBufD61E::AppendStrings(const char* pcString0, const char* pcString1, const char* pcString2,
                                    const char* pcString3, const char* pcString4, const char* pcString5) throw()
{
    int aiLengths[6] = {};
    const char* apcStrings[] = {pcString0, pcString1, pcString2, pcString3, pcString4, pcString5, 0};
    int iOrigLen = getLength();
    int iTotalLen = iOrigLen;
    int i;
    for (i = 0; apcStrings[i] != 0; i++)
    {
        aiLengths[i] = FUN_00cb10d0(apcStrings[i]);
        iTotalLen += aiLengths[i];
    }
    SetSizeAndGrow(iTotalLen + 1);
    m_data[iTotalLen] = 0;
    int iDstOffset = iOrigLen;
    for (i = 0; apcStrings[i] != 0; i++)
    {
        FUN_00cb1260(m_data + iDstOffset, apcStrings[i], aiLengths[i]);
        iDstOffset += aiLengths[i];
    }
}

class hkMemoryAllocatorD620;

struct hkMemoryRouterD620
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD620* m_pTemp;
    hkMemoryAllocatorD620* m_pStreamAllocator;
    hkMemoryAllocatorD620& temp()
    {
        return *m_pTemp;
    }
};

namespace hkRouterD620 {
extern "C" hkMemoryRouterD620& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorD620& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl FUN_00d2caa0(void* pvDst, void* pvSrc, unsigned int uiNumBytes);

class hkStringBufD620
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD620& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(char));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterD620::FUN_00c85750().temp(), n);
        m_iElementCount = n;
    }

    void Assign(void* src, int len);
};

// Reserves len+1 bytes, null-terminates the buffer at index len, then copies len bytes from src into m_data.
// @fnv 0x00d62020
void hkStringBufD620::Assign(void* src, int len)
{
    SetSizeAndGrow(len + 1);
    m_data[len] = 0;
    FUN_00d2caa0(m_data, src, len);
}

int __cdecl FUN_00cb10d0(int value);
void* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(int value1, int value2, int value3, int value4);
void __cdecl FUN_00d2caa0(void* value1, unsigned int value2, unsigned int value3);

struct D62080_Audio
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct D62080_Object
{
    unsigned char* m_data;
    int m_uiItemCount;
    unsigned int m_pRayCursor;

    void __thiscall FUN_00d62080(int param2, int param3);
};

// @fnv 0x00d62080
void __thiscall D62080_Object::FUN_00d62080(int aData, int param3)
{
    if (param3 < 0)
        param3 = FUN_00cb10d0(aData);

    int oldCount = m_uiItemCount;
    oldCount--;

    int index = oldCount + param3;
    int newCount = index + 1;

    D62080_Audio* audio = (D62080_Audio*)FUN_00c85750();
    int audioValue = audio->unk0c;

    int capacity = (int)(m_pRayCursor & 0x3fffffff);
    if (capacity < newCount)
    {
        capacity *= 2;
        if (newCount >= capacity)
            capacity = newCount;

        FUN_00c908c0(audioValue, (int)this, capacity, 1);
    }

    m_uiItemCount = newCount;
    m_data[index] = 0;

    FUN_00d2caa0(m_data + oldCount, aData, param3);
}

extern int __cdecl FUN_00cb10d0(int value);
struct Router_d62100
{
    int unk00;
    int unk04;
    int unk08;
    int m_iValueAtOffset0C;
};
struct FUN_00d62100_Class
{
    int __thiscall FUN_00d62630(int context, int first, int second, int third);
    int __thiscall FUN_00d62100(int first, int second, int third);
};
// @fnv 0x00d62100
int FUN_00d62100_Class::FUN_00d62100(int first, int second, int third)
{
    if (third < 0)
        third = FUN_00cb10d0(second);
    Router_d62100* router = static_cast<Router_d62100*>(FUN_00c85750());
    return FUN_00d62630(router->m_iValueAtOffset0C, first, second, third);
}

struct SearchBase
{
    int FUN_00d61cc0();
};
struct SearchController : SearchBase
{
    int FindLastCharInRange(int token, int start, int limit);
    int FUN_00d61fc0(int start, int position);
    int FUN_00d62140();
};

// @fnv 0x00d62140
int SearchController::FUN_00d62140()
{
    int first = FindLastCharInRange(0x2f, 0, 0x7fffffff);
    int second = FindLastCharInRange(0x5c, 0, 0x7fffffff);
    if (second <= first)
        second = first;
    if (second >= 0)
        return FUN_00d61fc0(0, second);
    return FUN_00d61cc0();
}

struct hkStringPtr
{
    const char* m_stringAndFlags;
    const char* cString() const
    {
        return (const char*)((unsigned int)m_stringAndFlags & ~1);
    }
};

struct FUN_00d623a0
{
    char* m_data;
    int m_iElementCount;
    unsigned int m_iCapacityState;
    char m_kStorage;

    void FUN_00d61c10(const char* str);

    FUN_00d623a0(const hkStringPtr& str);
};

// @fnv 0x00d623a0
FUN_00d623a0::FUN_00d623a0(const hkStringPtr& str)
{
    m_data = &m_kStorage;
    m_iElementCount = 0;
    m_iCapacityState = 0x80000080;
    FUN_00d61c10(str.cString());
}

struct FUN_00d623d0
{
    void* m_p00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    void* m_p1c;
    int m_i20;
    void* m_p24;

    void AppendStrings(int a, int b, int c, int d, int e, int f);
    FUN_00d623d0(int a, int b, int c, int d, int e, int f);
};

// Sets up the object's internal pointer and counters, then forwards the six arguments to AppendStrings.
// @fnv 0x00d623d0
FUN_00d623d0::FUN_00d623d0(int a, int b, int c, int d, int e, int f)
{
    m_p00 = (void*)&m_i0c;
    m_i04 = 0;
    m_i08 = 0x80000080;
    ((char*)m_p00)[0] = 0;
    ++m_i04;
    AppendStrings(a, b, c, d, e, f);
}

struct FUN_00d62100_Obj
{
    int FUN_00d62100(int a, int b, int c);
};
struct FUN_00d62580_Cls
{
    int FUN_00d62580(int a, int b);
};
// @fnv 0x00d62580
int FUN_00d62580_Cls::FUN_00d62580(int a, int b)
{
    return reinterpret_cast<FUN_00d62100_Obj*>(this)->FUN_00d62100(0, a, b);
}

class hkObjectD626
{
  public:
    int ReplaceRange(int a, int b, int c, int d, int e);
    int FUN_00d62630(int a, int b, int d, int e);
};

// @fnv 0x00d62630
int hkObjectD626::FUN_00d62630(int a, int b, int d, int e)
{
    return ReplaceRange(a, b, 0, d, e);
}

struct FUN_00ddccb0_Obj
{
    void FUN_00ddccb0(int a1);
};

struct FUN_00d62ef0_cls
{
    int* unk00;
    int unk04;
    int* unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int* unk20;
    int unk24;
    unsigned char unk28;

    FUN_00d62ef0_cls* FUN_00d62ef0(int aParam, unsigned char aValue);
};

extern int DAT_010d1720;
extern int DAT_010d1700;
extern int DAT_010d16f0;

// Calls FUN_00ddccb0 with aParam, then stores three global addresses and aValue into the object's fields and returns this.
// @fnv 0x00d62ef0
FUN_00d62ef0_cls* __thiscall FUN_00d62ef0_cls::FUN_00d62ef0(int aParam, unsigned char aValue)
{
    ((FUN_00ddccb0_Obj*)this)->FUN_00ddccb0(aParam);
    unk00 = &DAT_010d1720;
    unk08 = &DAT_010d1700;
    unk20 = &DAT_010d16f0;
    unk28 = aValue;
    return this;
}

struct HeapAllocator
{
    virtual void* GetStats();
    virtual void* Allocate(unsigned int bytes);
};
struct MemorySystem
{
    void* unknown00;
    void* unknown04;
    void* unknown08;
    void* unknown0c;
    HeapAllocator* heap;
};
struct HeapBlockMetadata
{
    unsigned int flags;
    unsigned short size;
    unsigned short reserved;
    HeapBlockMetadata* FUN_00d62ef0(void* data, unsigned int enabled);
};
// @fnv 0x00d62f60
void* __cdecl AllocateRecordWithData(void* data)
{
    MemorySystem* memory = static_cast<MemorySystem*>(FUN_00c85750());
    HeapBlockMetadata* record = static_cast<HeapBlockMetadata*>(memory->heap->Allocate(44));
    record->size = 44;
    HeapBlockMetadata* result = record->FUN_00d62ef0(data, 1);
    return result ? reinterpret_cast<char*>(result) + 8 : 0;
}

struct Allocator_d632c0
{
    virtual void slot00();
    virtual void* Allocate(unsigned int size);
};

struct Holder_d632c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Allocator_d632c0* allocator;
};

struct Base1_d632c0
{
    virtual void vfn1();
    unsigned short size;
    unsigned short ref;
};

struct Base2_d632c0
{
    virtual void vfn2();
};

struct Obj_d632c0 : Base1_d632c0, Base2_d632c0
{
    Obj_d632c0* FUN_00d63280(int a, int b);
};

// @fnv 0x00d632c0
Base2_d632c0* FUN_00d632c0(int aiValue)
{
    Holder_d632c0* holder = (Holder_d632c0*)FUN_00c85750();
    Obj_d632c0* obj = (Obj_d632c0*)holder->allocator->Allocate(0x54);
    obj->size = 0x54;
    obj = obj->FUN_00d63280(0, aiValue);
    return obj;
}

struct hkContainerD633
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    void** m_items;
    int m_uiItemCount;
};

struct hkListenerD633
{
    virtual void v00(void* p);
    virtual void v04(void* p);
};

struct hkObjD633
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkListenerD633 m_kListener;
    hkContainerD633* m_container;

    void FUN_00d63300();
};

// Iterates the container's items and passes each to the listener's v04 callback when m_container is set.
// @fnv 0x00d63300
void hkObjD633::FUN_00d63300()
{
    if (m_container)
    {
        for (int i = 0; i < m_container->m_uiItemCount; i++)
            m_kListener.v04(m_container->m_items[i]);
    }
}

class FUN_00ddf050_cls
{
  public:
    virtual ~FUN_00ddf050_cls() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addObject(const char* pcName, const void* pvObject, int iFlags) throw();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    char* m_data;
    int m_iElementCount;

    void ClearContainer() throw();
    void FUN_00ddf030(int i) throw();
    void FUN_00ddf040() throw();

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    bool hasData() const
    {
        return m_iElementCount > 0 && m_data;
    }
    char* getData() const
    {
        return m_iElementCount > 0 ? m_data : 0;
    }
};

class hkDisplayHandlerD633
{
  public:
    virtual void V00() throw();
    virtual void V04() throw();
    virtual void V08() throw();
    virtual void V0C() throw();
    virtual void V10() throw();
    virtual void V14() throw();
    virtual void V18() throw();
    virtual void V1C() throw();
    virtual void V20() throw();
    virtual void V24() throw();
    virtual void V28() throw();
    virtual void V2C() throw();
    virtual void V30() throw();
    virtual void V34() throw();
    virtual void V38() throw();
    virtual void V3C() throw();
    virtual void WriteOutput(const char* pcData, int iLength) throw();
};

class hkpWorldD633;

class hkpPhysicsContextD633
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
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    hkpWorldD633** m_ppWorlds;
    int m_numWorlds;
};

class FUN_00d63370_class
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkDisplayHandlerD633* m_pDisplayHandler;
    int unk14;
    int unk18;
    hkpPhysicsContextD633* m_iValueAtOffset0C;
    FUN_00ddf050_cls m_pStreamWriter;

    void UpdatePhysicsDebugDisplay(float fFrameTime) throw();
};

// Rebuilds the debug display buffer with each physics world, then passes the buffer and its length to the display handler.
// @fnv 0x00d63370
void FUN_00d63370_class::UpdatePhysicsDebugDisplay(float fFrameTime) throw()
{
    m_pStreamWriter.ClearContainer();
    m_pStreamWriter.FUN_00ddf030(0);
    for (int i = 0; i < m_iValueAtOffset0C->m_numWorlds; i++)
        m_pStreamWriter.addObject("World", m_iValueAtOffset0C->m_ppWorlds[i], 0);
    m_pStreamWriter.FUN_00ddf040();
    if (m_pStreamWriter.hasData())
        m_pDisplayHandler->WriteOutput(m_pStreamWriter.getData(), m_pStreamWriter.GetLogicalSize());
}

namespace fnv_00d63400 {
class FUN_00dd9380_class
{
  public:
    void* FUN_00dd9380(const char* pcName, void* pvCreateFunc);
};

void __cdecl FUN_00d632c0();

extern void* DAT_01268fc8;

// @fnv 0x00d63400
void __cdecl InitWorldMemory()
{
    DAT_01268fc8 =
        reinterpret_cast<FUN_00dd9380_class*>(DAT_01269cd0)->FUN_00dd9380("World Memory", (void*)FUN_00d632c0);
}
}  // namespace fnv_00d63400

extern int DAT_01268fc8;
// @fnv 0x00d63420
int __cdecl FUN_00d63420()
{
    return DAT_01268fc8;
}

class hkMemoryAllocatorD634
{
  public:
    virtual ~hkMemoryAllocatorD634() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD634
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD634* m_pStreamAllocator;
    hkMemoryAllocatorD634& heap()
    {
        return *m_pStreamAllocator;
    }
};
void* __cdecl FUN_00c85750();

class FUN_00d63340
{
  public:
    virtual ~FUN_00d63340() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        ((hkMemoryRouterD634*)FUN_00c85750())
            ->heap()
            .ReleaseBlock(p, static_cast<FUN_00d63340*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d63340* Destroy(unsigned int uiFlags) throw();
};

// Calls the destructor, and if bit 0 of uiFlags is set, frees the object through operator delete; returns this.
// @fnv 0x00d63450
FUN_00d63340* FUN_00d63340::Destroy(unsigned int uiFlags) throw()
{
    this->FUN_00d63340::~FUN_00d63340();
    if (uiFlags & 1)
        FUN_00d63340::operator delete(this);
    return this;
}

class hkPart0D642
{
  public:
    virtual ~hkPart0D642() throw();
    int unk04;
};

class hkPart8D642
{
  public:
    virtual void p8() = 0;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class hkPart20D642
{
  public:
    virtual void p20() = 0;
    int unk24;
};

class hkBaseD642 : public hkPart0D642, public hkPart8D642, public hkPart20D642
{
};

class FUN_00ddccb0 : public hkBaseD642
{
  public:
    FUN_00ddccb0(void* p) throw();
};

class hkIfaceAD642
{
  public:
    virtual void a0() = 0;
};

class hkIfaceBD642
{
  public:
    virtual void b0() = 0;
};

template <class T> struct hkArrayD642
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayD642() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class FUN_00d64260 : public FUN_00ddccb0, public hkIfaceAD642, public hkIfaceBD642
{
  public:
    hkArrayD642<void*> m_ppData;

    FUN_00d64260(void* p) throw();
    virtual ~FUN_00d64260() throw();
    virtual void p8();
    virtual void p20();
    virtual void a0();
    virtual void b0();
};

// Constructs the object by forwarding p to the base constructor and default-initializing the void* array member.
// @fnv 0x00d64260
FUN_00d64260::FUN_00d64260(void* p) throw() : FUN_00ddccb0(p)
{}

struct FnvCpu_FUN_00d645f0_CpuBlock;
struct FnvCpu_FUN_00d645f0_CpuAllocator
{
    virtual void slot00();
    virtual void* Invoke(unsigned int size);
};
struct FnvCpu_FUN_00d645f0_CpuHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d645f0_CpuAllocator* allocator;
};
void* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d645f0_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00d645f0_CpuBlock* FUN_00d64260(unsigned int value);
};
// @fnv 0x00d645f0
void* __cdecl FUN_00d645f0(unsigned int value)
{
    FnvCpu_FUN_00d645f0_CpuHolder* holder = static_cast<FnvCpu_FUN_00d645f0_CpuHolder*>(FUN_00c85750());
    FnvCpu_FUN_00d645f0_CpuBlock* block = static_cast<FnvCpu_FUN_00d645f0_CpuBlock*>(holder->allocator->Invoke(60));
    block->size = 60;
    block = block->FUN_00d64260(value);
    if (block)
        return reinterpret_cast<char*>(block) + 8;
    return 0;
}

namespace fnv_00d64630 {
class FUN_00dd9380_class
{
  public:
    void* FUN_00dd9380(const char* pcName, void* pvCreateFunc);
};

extern void* DAT_01268fd0;
void __cdecl FUN_00d645f0();

// @fnv 0x00d64630
void __cdecl RegisterSweptTransformsTask()
{
    DAT_01268fd0 =
        reinterpret_cast<FUN_00dd9380_class*>(DAT_01269cd0)->FUN_00dd9380("Swept Transforms", (void*)FUN_00d645f0);
}
}  // namespace fnv_00d64630

struct FUN_00d65250_cls
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    unsigned char unk60;
    unsigned char unk61;

    void __thiscall FUN_00d65250(unsigned char value);
};

// @fnv 0x00d65250
void __thiscall FUN_00d65250_cls::FUN_00d65250(unsigned char value)
{
    unk61 = value;
}

struct FnvCpu_FUN_00d65260_CpuObject
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned char unk64;
    unsigned char value;
    void FUN_00d65260(unsigned char arg0);
};
// @fnv 0x00d65260
void FnvCpu_FUN_00d65260_CpuObject::FUN_00d65260(unsigned char arg0)
{
    value = arg0;
}

struct FnvCpu_FUN_00d65270_CpuObject
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned char unk60;
    unsigned char unk61;
    unsigned char value;
    void FUN_00d65270(unsigned char arg0);
};
// @fnv 0x00d65270
void FnvCpu_FUN_00d65270_CpuObject::FUN_00d65270(unsigned char arg0)
{
    value = arg0;
}

struct FUN_00d65280_cls
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    char unk60;
    char unk61;
    char unk62;
    bool m_63;

    void FUN_00d65280(bool bValue);
};

// @fnv 0x00d65280
void FUN_00d65280_cls::FUN_00d65280(bool bValue)
{
    m_63 = bValue;
}

struct FnvCpu_FUN_00d65290_CpuObject
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
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned char value;
    void FUN_00d65290(unsigned char arg0);
};
// @fnv 0x00d65290
void FnvCpu_FUN_00d65290_CpuObject::FUN_00d65290(unsigned char arg0)
{
    value = arg0;
}

// @fnv 0x00d6add0
void __cdecl FUN_00d6add0()
{}

extern "C" void __cdecl FUN_00d72e90();
// @fnv 0x00d73380
void __cdecl FUN_00d73380()
{
    FUN_00d72e90();
}

class FUN_00d733e0
{
  public:
    FUN_00d733e0();

    int m_iFirst;
    int m_iSecond;
    bool m_bEnableState;
};

// @fnv 0x00d733e0
FUN_00d733e0::FUN_00d733e0()
{
    m_iFirst = 0;
    m_iSecond = 0;
    m_bEnableState = true;
}

struct FUN_00d73400_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    void FUN_00d73400();
};

// @fnv 0x00d73400
void FUN_00d73400_cls::FUN_00d73400()
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 0;
    unk0C = 0;
}

class hkOstreamD734
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;

    void FUN_00cb1600(void* pvBuffer, int iSize) throw();
    void FUN_00cc00e0() throw();
    hkOstreamD734& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamD734& WriteInt(int i) throw();

    hkOstreamD734(void* pvBuffer, int iSize)
    {
        FUN_00cb1600(pvBuffer, iSize);
    }
    ~hkOstreamD734()
    {
        FUN_00cc00e0();
    }
};

class hkErrorD734
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
};
extern hkErrorD734* DAT_01268360;

struct hkpTransformCollapseUtilResultsD734
{
    int m_iFirstResult;
    int m_iSecondResult;
    int m_iThirdResult;
    int m_iFourthResult;

    void PrintResults() throw();
};

// Logs four counters (collapsed shapes, removed identity transforms, specialized shapes, propagated transforms) via hkErrorD734::message.
// @fnv 0x00d73430
void hkpTransformCollapseUtilResultsD734::PrintResults() throw()
{
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        kStream.FUN_00cc01c0("Number of collapsed shapes :").WriteInt(m_iFirstResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 57);
    }
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        kStream.FUN_00cc01c0("Number of identity transforms removed : ").WriteInt(m_iSecondResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 58);
    }
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        kStream.FUN_00cc01c0("Number of specialized transform shapes : ").WriteInt(m_iThirdResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 59);
    }
    {
        unsigned int auiBuf[128];
        hkOstreamD734 kStream(auiBuf, sizeof(auiBuf));
        kStream.FUN_00cc01c0("Number of propagated transforms to lists : ").WriteInt(m_iFourthResult);
        DAT_01268360->message(0, -1, (const char*)auiBuf,
                              ".\\Collide\\ShapeUtils\\CollapseTransform\\hkpTransformCollapseUtil.cpp", 60);
    }
}

struct FnvCpu_FUN_00d76d80_CpuTarget
{
    void FUN_00d81340();
};
struct FnvCpu_FUN_00d76d80_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    FnvCpu_FUN_00d76d80_CpuTarget* target;
    void FUN_00d76d80();
};
// @fnv 0x00d76d80
void FnvCpu_FUN_00d76d80_CpuOwner::FUN_00d76d80()
{
    target->FUN_00d81340();
}

extern int DAT_010d14f8;
struct hkBoolD608
{
    unsigned char value;
    hkBoolD608(bool enabled = false) : value(enabled)
    {}
    hkBoolD608(const hkBoolD608& other) : value(other.value)
    {}
};
struct hkAllocatorD608
{
    virtual void vf00();
    virtual void* Allocate(int bytes);
};
struct hkRouterD608
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    hkAllocatorD608* allocator;
};
struct FUN_00d274c0
{
    void* unk00;
    unsigned short allocatedSize;
    FUN_00d274c0(int first, int second, hkBoolD608 enabled);
};
struct FUN_00d608a0
{
    void* vptr;
    unsigned short unk04;
    unsigned short count;
    FUN_00d274c0* child;
    unsigned char mode;
    FUN_00d608a0(int first, int second, unsigned char mode);
};
// Initializes count, vptr, and mode, then allocates and constructs a FUN_00d274c0 child node via the router allocator.
// @fnv 0x00d608a0
FUN_00d608a0::FUN_00d608a0(int first, int second, unsigned char mode)
{
    count = 1;
    vptr = &DAT_010d14f8;
    this->mode = mode;
    hkRouterD608* router = static_cast<hkRouterD608*>(FUN_00c85750());
    FUN_00d274c0* next = static_cast<FUN_00d274c0*>(router->allocator->Allocate(28));
    next->allocatedSize = 28;
    child = new (next) FUN_00d274c0(first, second, hkBoolD608());
}

int __cdecl FUN_00cb0fa0(int, int);
struct R
{
    volatile char value;
    R(bool b) : value(b)
    {}
};
struct S
{
    int value;
    R IsLessThan(int other) const;
};
// @fnv 0x00d616c0
R S::IsLessThan(int other) const
{
    return FUN_00cb0fa0(value, other) < 0;
}

class hkMemoryAllocatorD619;

struct hkMemoryRouterD619
{
    int unk00, unk04, unk08;
    hkMemoryAllocatorD619* m_pStreamAllocator;

    hkMemoryAllocatorD619& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD619 {
extern "C" hkMemoryRouterD619& __cdecl FUN_00c85750() throw();
}

void __cdecl ResizeAudioStream(hkMemoryAllocatorD619& kAlloc, void* pArray, int iElemSize);

template <class T> __forceinline void constructWithCopyD619(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayD619
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void _pushBack(hkMemoryAllocatorD619& kAlloc, T t)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(kAlloc, this, sizeof(T));
        constructWithCopyD619(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    void AddBack(T t)
    {
        _pushBack(hkRouterD619::FUN_00c85750().heap(), t);
    }
};

class hkStringD619
{
  public:
    char* m_kStringBuffer;

    int FindCharacter(int c, int iStart, int iEnd) const;
    int SplitString(int c, hkArrayD619<const char*>& kBits);
};

// Splits m_kStringBuffer in place at each c found from index 1 by writing nulls, appends each piece pointer to kBits, and returns kBits's size.
// @fnv 0x00d61910
int hkStringD619::SplitString(int c, hkArrayD619<const char*>& kBits)
{
    kBits.AddBack(m_kStringBuffer);
    int iNumBits = kBits.GetLogicalSize();
    int iCur = FindCharacter(c, 1, 0x7fffffff);
    while (iCur >= 0)
    {
        m_kStringBuffer[iCur] = 0;
        int iStart = iCur + 1;
        kBits.AddBack(m_kStringBuffer + iStart);
        iNumBits = kBits.GetLogicalSize();
        iCur = FindCharacter(c, iStart, 0x7fffffff);
    }
    return iNumBits;
}

class hkMemoryAllocatorD61
{
  public:
    virtual ~hkMemoryAllocatorD61();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct hkMemoryRouterD61
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD61* m_alloc;
};

template <class T> inline void hkArrayCopyD61(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

class FUN_00d619d0
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    FUN_00d619d0& operator=(const FUN_00d619d0& a);
};

// Copies the source array, growing the buffer via the memory router if the source size exceeds the current capacity.
// @fnv 0x00d619d0
FUN_00d619d0& FUN_00d619d0::operator=(const FUN_00d619d0& aSource)
{
    hkMemoryAllocatorD61& alloc = *static_cast<hkMemoryRouterD61*>(FUN_00c85750())->m_alloc;
    if ((m_iCapacityState & 0x3fffffff) < aSource.m_iElementCount)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff));
        int n = aSource.m_iElementCount;
        m_data = (char*)alloc.AllocateBufferWithSize(n);
        m_iCapacityState = n;
    }
    m_iElementCount = aSource.m_iElementCount;
    hkArrayCopyD61(m_data, aSource.m_data, m_iElementCount);
    return *this;
}

struct FUN_00d61a50_cls
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int* FUN_00d61a50(int value);
};

namespace fnvc_adapt {
char* __cdecl FUN_00cb10d0(int value);
}
void __cdecl FUN_00c908c0(int allocator, FUN_00d61a50_cls* array, int capacity, int value);
void __cdecl FUN_00cb1260(int* data, int value, char* source);

// Initializes the string buffer, grows capacity if needed, copies value into m_data, and returns this.
// @fnv 0x00d61a50
int* FUN_00d61a50_cls::FUN_00d61a50(int value)
{
    m_data = (int*)((char*)this + 0x0C);
    m_iElementCount = 0;
    m_iCapacityState = 0x80000080;

    if (value != 0)
    {
        char* source = fnvc_adapt::FUN_00cb10d0(value);
        int count = (int)source + 1;

        void* audio = FUN_00c85750();
        int allocator = *(int*)((char*)audio + 0x0C);
        int capacity = m_iCapacityState & 0x3FFFFFFF;

        if (capacity < count)
        {
            capacity = capacity * 2;
            if (count >= capacity)
                capacity = count;
            FUN_00c908c0(allocator, this, capacity, 1);
        }

        m_iElementCount = count;
        *(char*)(source + (int)m_data) = 0;
        FUN_00cb1260(m_data, value, source);
    }
    else
    {
        void* audio = FUN_00c85750();
        int allocator = *(int*)((char*)audio + 0x0C);
        int capacity = m_iCapacityState & 0x3FFFFFFF;

        if (capacity < 1)
        {
            capacity = capacity * 2;
            if (capacity <= 1)
                capacity = 1;
            FUN_00c908c0(allocator, this, capacity, 1);
        }

        m_iElementCount = 1;
        *(char*)m_data = 0;
    }

    return (int*)this;
}

class hkMemoryAllocatorD61B8
{
  public:
    virtual ~hkMemoryAllocatorD61B8() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD61B8
{
    int m_00;
    int m_04;
    int m_08;
    hkMemoryAllocatorD61B8* m_pTemp;
    hkMemoryAllocatorD61B8* m_pStreamAllocator;
    hkMemoryAllocatorD61B8& temp()
    {
        return *m_pTemp;
    }
};

template <class T> __forceinline void hkArrayCopyD61B8(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; ++i)
        pDst[i] = pSrc[i];
}

template <class T, int N> class hkInplaceArrayD61B8
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T m_kStorage[N];

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline hkInplaceArrayD61B8(const hkInplaceArrayD61B8& kOther) throw()
        : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(N | 0x80000000)
    {
        hkMemoryAllocatorD61B8& kAlloc = static_cast<hkMemoryRouterD61B8*>(FUN_00c85750())->temp();
        if (getCapacity() < kOther.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kAlloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
            int n = kOther.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kAlloc.AllocateBufferWithSize(n));
            m_iCapacityState = n / sizeof(T);
        }
        m_iElementCount = kOther.m_iElementCount;
        hkArrayCopyD61B8(m_data, kOther.m_data, m_iElementCount);
    }
};

class FUN_00d61b80
{
  public:
    hkInplaceArrayD61B8<char, 128> m_kStringBuffer;

    FUN_00d61b80(const FUN_00d61b80& kOther) throw();
};

// Copy-constructs a FUN_00d61b80 by delegating to the hkInplaceArrayD61B8 copy constructor for m_kStringBuffer.
// @fnv 0x00d61b80
FUN_00d61b80::FUN_00d61b80(const FUN_00d61b80& kOther) throw() : m_kStringBuffer(kOther.m_kStringBuffer)
{}

struct C6DF60Router;
C6DF60Router* __cdecl _FNV_e03300_arena();
struct C6DF60Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct C540BC0Allocator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
};
struct FUN_00d61cc0_t
{
    char* m_pBuffer;
    int m_iFadeIndex;
    int m_iState2;
    void FUN_00d61cc0();
};
void __cdecl ArrayReserveImpl(void*, void*, int, int);
// If the capacity bits of m_iState2 are below 1, reserves via ArrayReserveImpl, then sets m_iFadeIndex to 1 and writes a null at m_pBuffer.
// @fnv 0x00d61cc0
void FUN_00d61cc0_t::FUN_00d61cc0()
{
    C6DF60Router* router = _FNV_e03300_arena();
    C540BC0Allocator* allocator = (C540BC0Allocator*)(void*)router->unk0c;
    int state = m_iState2 & 0x3fffffff;
    if (state < 1)
    {
        int count = state << 1;
        if (count <= 1)
            count = 1;
        ArrayReserveImpl(allocator, this, count, 1);
    }
    m_iFadeIndex = 1;
    *m_pBuffer = 0;
}

class hkMemoryAllocatorD61F;

struct hkMemoryRouterD61F
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD61F* m_pTemp;
    hkMemoryAllocatorD61F* m_pStreamAllocator;
    hkMemoryAllocatorD61F& temp()
    {
        return *m_pTemp;
    }
};

namespace hkRouterD61F {
extern "C" hkMemoryRouterD61F& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorD61F& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayD61F
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD61F& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterD61F::FUN_00c85750().temp(), n);
        m_iElementCount = n;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

class hkStringBufD61F
{
  public:
    hkArrayD61F<char> m_kStringBuffer;

    void FUN_00d61f70(int n);
};

// If n > 0, removes the last n characters by resizing the buffer to its size minus n and null-terminating it.
// @fnv 0x00d61f70
void hkStringBufD61F::FUN_00d61f70(int n)
{
    if (n > 0)
    {
        int iLen = m_kStringBuffer.GetLogicalSize() - n - 1;
        m_kStringBuffer.SetSizeAndGrow(iLen + 1);
        m_kStringBuffer[iLen] = 0;
    }
}

namespace fnv_00d61fc0 {
class hkMemoryAllocatorD61F;

struct hkMemoryRouterD61F
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD61F* m_pTemp;
    hkMemoryAllocatorD61F* m_pStreamAllocator;
    hkMemoryAllocatorD61F& temp()
    {
        return *m_pTemp;
    }
};

namespace hkRouterD61F {
extern "C" hkMemoryRouterD61F& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorD61F& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void FUN_00d2cc70(void* pvDst, void* pvSrc, unsigned int uiNumBytes);

class hkStringBufD61F
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void FUN_00d61fc0(int iOffset, int iLength);
};

// @fnv 0x00d61fc0
void hkStringBufD61F::FUN_00d61fc0(int iOffset, int iLength)
{
    if (iOffset)
        FUN_00d2cc70(m_data, m_data + iOffset, iLength);
    int n = iLength + 1;
    hkMemoryAllocatorD61F& kAlloc = hkRouterD61F::FUN_00c85750().temp();
    const int iCap = getCapacity();
    if (iCap < n)
    {
        int iCap2 = 2 * iCap;
        int iNewCap = (n < iCap2) ? iCap2 : n;
        FUN_00c908c0(kAlloc, this, iNewCap, sizeof(char));
    }
    m_iElementCount = n;
    m_data[iLength] = 0;
}
}  // namespace fnv_00d61fc0

class hkMemoryAllocatorD62
{
  public:
    virtual ~hkMemoryAllocatorD62() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD62
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD62* m_pStreamAllocator;

    hkMemoryAllocatorD62& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD62 {
extern "C" hkMemoryRouterD62& __cdecl FUN_00c85750() throw();
}

class hkReferencedObjectD62
{
  public:
    virtual ~hkReferencedObjectD62();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        hkReferencedObjectD62* b =
            static_cast<hkReferencedObjectD62*>(hkRouterD62::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class hkpCollisionAgentD62
{
  public:
    virtual void cleanup();
};

class FUN_00d62ef0 : public hkReferencedObjectD62, public hkpCollisionAgentD62
{
  public:
    FUN_00d62ef0(void* contactMgr, int flags) throw();

    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
};

// Allocates a FUN_00d62ef0 object via the hkReferencedObjectD62 operator new, passing contactMgr and 0 as flags, and returns it as hkpCollisionAgentD62*.
// @fnv 0x00d62f20
hkpCollisionAgentD62* __cdecl FUN_00d62f20(void* contactMgr)
{
    return new FUN_00d62ef0(contactMgr, 0);
}

// @fnv 0x00d6c1a0
__declspec(noinline) static void FUN_00d6c1a0(int* piValue)
{
    *piValue -= 16;
}

void E6C1A0Adjust(int* piValue)
{
    FUN_00d6c1a0(piValue);
}

// FUN_00d73400's body must be in-TU so VC9 knows it clobbers only eax:
// that is what lets the ctor keep `this` live in ECX across the call
// (matches orig: xor eax,eax; mov [ecx..0xc],eax; call; mov eax,ecx; ret).
class FUN_00d73410;

struct Z0
{
    int m_iUnk00;
    int m_iUnk04;
    int m_iUnk08;
    int m_iUnk0C;
    void FUN_00d73400();
};

__declspec(noinline) void Z0::FUN_00d73400()
{
    m_iUnk00 = 0;
    m_iUnk04 = 0;
    m_iUnk08 = 0;
    m_iUnk0C = 0;
}

class FUN_00d73410
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    int m_iUnk08;
    int m_iUnk0C;
    FUN_00d73410();
};

// @fnv 0x00d73410
FUN_00d73410::FUN_00d73410()
{
    m_iUnk00 = 0;
    m_iUnk04 = 0;
    m_iUnk08 = 0;
    m_iUnk0C = 0;
    ((Z0*)this)->FUN_00d73400();
}

struct Node
{
    unsigned unk00, unk04, unk08, unk0c;
    void* active;
    Node* left;
    Node* right;
    unsigned unk1c, unk20, unk24, unk28, flags;
};
// For each node whose left and right children are both active, rewrites their flags with seed and 5-bit ids from a running counter or the other child.
// @fnv 0x00d74b70
void __cdecl AssignNodeFlags(Node** nodes, int count, unsigned auSeed)
{
    unsigned nextId = 0;
    int index = 0;
    if (count > 0)
    {
        do
        {
            Node* item = nodes[index];
            Node* left = item->left;
            Node* right = item->right;
            if (left && left->active && right && right->active)
            {
                unsigned leftPacked = left->flags;
                unsigned rightPacked = right->flags;
                unsigned midLeft = (leftPacked >> 5) & 31;
                unsigned midRight = (rightPacked >> 5) & 31;
                unsigned highLeft = (leftPacked >> 10) & 31;
                unsigned highRight = (rightPacked >> 10) & 31;
                unsigned lowLeft = leftPacked & 31;
                unsigned lowRight = rightPacked & 31;
                if (!midLeft)
                    midLeft = nextId++;
                if (!midRight)
                    midRight = nextId++;
                if (!highLeft)
                    highLeft = midRight;
                else
                    highRight = midLeft;
                left->flags = ((((auSeed << 6) | highLeft) << 5) | midLeft) << 5 | lowLeft;
                right->flags = ((((auSeed << 6) | highRight) << 5) | midRight) << 5 | lowRight;
            }
            ++index;
        } while (index < count);
    }
}

struct FUN_00d7e740_cls
{
    int FUN_00d7e740(int iArg0, int iArg1, bool iFlag, int iArg2);
};

struct FUN_00d76c20_cls
{
    int m_00;
    int m_04;
    FUN_00d7e740_cls* m_target;

    int ForwardToTarget(int iSelector, int iArg0, int iArg1, int iArg2);
};

// Forwards a call to m_target->FUN_00d7e740, passing iSelector == 0 as the third argument.
// @fnv 0x00d76c20
int FUN_00d76c20_cls::ForwardToTarget(int iSelector, int iArg0, int iArg1, int iArg2)
{
    return m_target->FUN_00d7e740(iArg0, iArg1, iSelector == 0, iArg2);
}

struct hkResultD794
{
    int m_bHasHit;
};

void __cdecl FUN_00d79250(void* a, void* b, hkResultD794* out, int flags, float f);

// Calls FUN_00d79250 with flags 0 and returns whether out->m_bHasHit is set.
// @fnv 0x00d794e0
bool __cdecl FUN_00d794e0(void* a, void* b, hkResultD794* apResult, float f)
{
    FUN_00d79250(a, b, apResult, 0, f);
    return apResult->m_bHasHit != 0;
}

// @fnv 0x00d61430
static __declspec(noinline) int ToLowerCase(char c)
{
    return ((unsigned char)(c - 'A') <= 25) ? c + 0x20 : c;
}

volatile char g_d61430_c;
char g_d61430_sink;

void d61430_caller()
{
    g_d61430_sink = (char)ToLowerCase(g_d61430_c);
}

// @fnv 0x00d61450
static __declspec(noinline) int FUN_00d61450(char c)
{
    return ((unsigned char)(c - 'a') <= 25) ? c - 0x20 : c;
}

volatile char g_d61450_c;
char g_d61450_sink;

void d61450_caller()
{
    g_d61450_sink = (char)FUN_00d61450(g_d61450_c);
}

struct D6C1B0Owner
{
    int unk00;
    void(__cdecl* unk04)(int, int, D6C180Command**);
    int unk08;
};

extern "C" D6C180Command** d6c1b0_cursor_src(void);
volatile int g_d6c1b0_a1;
D6C1B0Owner* volatile g_d6c1b0_owner;

// @fnv 0x00d6c1b0
static __declspec(noinline) void FUN_00d6c1b0(D6C180Command** ppkCursor, D6C1B0Owner* pOwner, int a1)
{
    *ppkCursor -= 1;
    pOwner->unk04(pOwner->unk08, a1, ppkCursor);
}

void d6c1b0_caller(void)
{
    FUN_00d6c1b0(d6c1b0_cursor_src(), g_d6c1b0_owner, g_d6c1b0_a1);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};

extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, int imm);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

extern "C" __m128 g_d6c1d0_src[4];
extern "C" __m128 g_d6c1d0_mat[4];
extern "C" __m128 g_d6c1d0_out[4];

// For i=0..3 sets out[i] to b[i].x*a[0] + b[i].y*a[1] + b[i].z*a[2], then adds a[3] to out[3].
// @fnv 0x00d6c1d0
static __declspec(noinline) void FUN_00d6c1d0(__m128* __restrict out, const __m128* __restrict a,
                                              const __m128* __restrict b)
{
    const __m128& c1 = a[1];
    const __m128& c0 = a[0];
    const __m128& c2 = a[2];
    for (int i = 3; i >= 0; i--)
    {
        const __m128& v = b[i];
        out[i] =
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0), c0), _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), c1)),
                       _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c2));
    }
    out[3] = _mm_add_ps(a[3], out[3]);
}

void fnv_probe_d6c1d0()
{
    FUN_00d6c1d0(g_d6c1d0_out, g_d6c1d0_mat, g_d6c1d0_src);
}

extern float DAT_011b6924;
extern float DAT_011b6928;
extern float DAT_010c8440;
struct IntegratorD720
{
    float unk00;
    float offset;
    float unk08;
    float unk0c;
    float state;
};
// @fnv 0x00d720a0
static __declspec(noinline) float FUN_00d720a0(IntegratorD720* self, float input, float step)
{
    float value = self->state;
    float delta = input - value;
    float error = -self->offset - delta;
    float limit = DAT_011b6924 * step;
    float proposed = -DAT_011b6928 * value;
    float change = proposed < limit ? proposed : limit;
    value += change;
    delta -= change;
    if (error > limit + 2.0f * change)
    {
        value -= error;
        delta += error;
    }
    self->state = DAT_010c8440 > value ? value : DAT_010c8440;
    return delta;
}

IntegratorD720* volatile integratorD720;
volatile float inputD720, stepD720, resultD720;
void invokeD720()
{
    resultD720 = FUN_00d720a0(integratorD720, inputD720, stepD720);
}

struct FUN_00d74dc0_cls
{
    void* FUN_00d74dc0();
};

// @fnv 0x00d74dc0
void* FUN_00d74dc0_cls::FUN_00d74dc0()
{
    return (char*)this + 0x10;
}

#include <stdarg.h>
struct hkAllocatorD624
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD624
{
    void* m_apvUnk00[3];
    hkAllocatorD624* m_pkHeap;
    hkAllocatorD624& heap()
    {
        return *m_pkHeap;
    }
};
void* __cdecl FUN_00c85750();
inline hkMemoryRouterD624* getRouterD624()
{
    return (hkMemoryRouterD624*)FUN_00c85750();
}

void __cdecl FUN_00c908c0(hkAllocatorD624& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
int __cdecl FUN_00cb0f50(char* pcBuf, int iBufSize, const char* pcFormat, va_list kArgs) throw();

template <typename T> struct hkArrayD624
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T* begin()
    {
        return m_data;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void GrowArrayCapacity(hkAllocatorD624& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        GrowArrayCapacity(getRouterD624()->heap(), n);
        m_iElementCount = n;
    }
    __forceinline ~hkArrayD624()
    {
        hkAllocatorD624& kAlloc = getRouterD624()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, m_iCapacityState & 0x3fffffff);
    }
};

class hkStringBufD624
{
  public:
    hkArrayD624<char> m_kStringBuffer;
    unsigned int m_kStorage[32];

    void InitBuffer() throw();
    hkStringBufD624()
    {
        InitBuffer();
    }

    const char* cString() const
    {
        return m_kStringBuffer.m_data;
    }
    __forceinline void setLength(int iLength)
    {
        m_kStringBuffer.SetSizeAndGrow(iLength + 1);
        m_kStringBuffer[iLength] = 0;
    }
};

class hkOstreamD624
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    void* m_pStreamWriter;

    void FUN_00d62080(const char* pcBuf, int iNumBytes) throw();
    void WriteFormatted(const char* pcFormat, ...) throw();
};

// Formats pcFormat and varargs into a growable buffer via FUN_00cb0f50, resizing and retrying until it fits, then passes it to FUN_00d62080 with length -1.
// @fnv 0x00d62420
void hkOstreamD624::WriteFormatted(const char* pcFormat, ...) throw()
{
    hkStringBufD624 kBuf;
    while (1)
    {
        int iSize = kBuf.m_kStringBuffer.getCapacity();
        va_list kArgs;
        va_start(kArgs, pcFormat);
        int iNumChars = FUN_00cb0f50(kBuf.m_kStringBuffer.begin(), iSize, pcFormat, kArgs);
        va_end(kArgs);
        if (iNumChars >= 0 && iNumChars < iSize)
        {
            kBuf.setLength(iNumChars);
            break;
        }
        else if (iNumChars < 0)
        {
            kBuf.setLength((2 * iSize > 255) ? 2 * iSize : 255);
        }
        else
        {
            kBuf.setLength(iNumChars);
        }
    }
    FUN_00d62080(kBuf.cString(), -1);
}

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00d68830();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d68830();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68830
    virtual void FUN_00d68830();
};

Derived::Derived()
{}

namespace fnv_00d68900 {
// sub ecx,0x20; jmp target  ==  MSVC adjustor thunk (second base's vtable entry).
// PrimaryBase is 0x20 bytes: vptr + seven ints.
struct PrimaryBase
{
    virtual void FUN_00d68900();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct SecondaryBase
{
    virtual void FUN_00d68900();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d68900
    virtual void FUN_00d68900();
};

Derived::Derived()
{}
}  // namespace fnv_00d68900

struct Node_d6c580
{
    unsigned short m_type;
    char pad[0x12];
    Node_d6c580* m_parent;
};

// @fnv 0x00d6c580
static __declspec(noinline) Node_d6c580* FUN_00d6c580(Node_d6c580* n)
{
    do
    {
        n = n->m_parent;
    } while (n->m_type >= 0x17);
    return n;
}

Node_d6c580* zz_probe_d6c580(Node_d6c580* n)
{
    return FUN_00d6c580(n);
}

// @fnv 0x00d6c590
static __declspec(noinline) void FUN_00d6c590(int* p)
{
    *p -= 0x10;
}

void zz_probe_d6c590(int* p)
{
    FUN_00d6c590(p);
}

namespace fnv_00d61c10 {
class hkMemoryAllocatorD61C;

struct hkMemoryRouterD61C
{
    int unk00, unk04, unk08;
    hkMemoryAllocatorD61C* m_pTemp;
    hkMemoryAllocatorD61C* m_pStreamAllocator;
    hkMemoryAllocatorD61C& temp()
    {
        return *m_pTemp;
    }
};

namespace hkRouterD61C {
extern "C" hkMemoryRouterD61C& __cdecl FUN_00c85750() throw();
}
extern "C" int __cdecl FUN_00cb10d0(const char* pcString) throw();
void __cdecl FUN_00c908c0(hkMemoryAllocatorD61C& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();

template <class T> class hkArrayD61C
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD61C& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterD61C::FUN_00c85750().temp(), n);
        m_iElementCount = n;
    }
    T* begin()
    {
        return m_data;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};

class hkStringBufD61C
{
  public:
    hkArrayD61C<char> m_kStringBuffer;

    hkStringBufD61C& FUN_00d61c10(const char* s);
};

// Copies a null-terminated string into the internal buffer, growing it as needed, or clears it to an empty string when the input is null.
// @fnv 0x00d61c10
hkStringBufD61C& hkStringBufD61C::FUN_00d61c10(const char* apcString)
{
    if (apcString)
    {
        int len = FUN_00cb10d0(apcString);
        m_kStringBuffer.SetSizeAndGrow(len + 1);
        m_kStringBuffer[len] = 0;
        FUN_00cb1260(m_kStringBuffer.begin(), apcString, len);
    }
    else
    {
        m_kStringBuffer.SetSizeAndGrow(1);
        m_kStringBuffer[0] = 0;
    }
    return *this;
}
}  // namespace fnv_00d61c10

namespace fnv_00d63340 {
namespace FUN_00ddcc60 {
class hkpWorldViewerBase
{
  public:
    virtual ~hkpWorldViewerBase();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
}

class hkpWorldDeletionListenerD633
{
  public:
    virtual void WorldDeletedCallback(void* pkWorld) = 0;
    int unk04, unk08, unk0C, unk10, unk14;
};

class hkpActionListenerD633
{
  public:
    virtual void ActionAddedCallback(void* pkAction) = 0;
};

namespace FUN_00ddf240 {
class hkArrayD633
{
  public:
    ~hkArrayD633() throw();
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
}

namespace FUN_00d63340 {
class hkpWorldMemoryViewer : public FUN_00ddcc60::hkpWorldViewerBase,
                             public hkpWorldDeletionListenerD633,
                             public hkpActionListenerD633
{
  public:
    virtual ~hkpWorldMemoryViewer();
    virtual void WorldDeletedCallback(void* pkWorld);
    virtual void ActionAddedCallback(void* pkAction);

    int unk24;
    FUN_00ddf240::hkArrayD633 m_kArray;
};

// @fnv 0x00d63340
hkpWorldMemoryViewer::~hkpWorldMemoryViewer()
{}
}
}  // namespace fnv_00d63340

class RotationColumns;

class QuadDirection
{
  public:
    __forceinline QuadDirection()
    {}
    __forceinline QuadDirection(const QuadDirection& other)
    {
        value = other.value;
    }
    __forceinline void operator=(const QuadDirection& other)
    {
        value = other.value;
    }
    __forceinline void multiply(const RotationColumns& rotation, const QuadDirection& input);
    __m128 value;
};

class RotationColumns
{
  public:
    __forceinline RotationColumns()
    {}
    __forceinline RotationColumns(const RotationColumns& other)
    {
        columns[0] = other.columns[0];
        columns[1] = other.columns[1];
        columns[2] = other.columns[2];
    }
    __forceinline QuadDirection& column(int i)
    {
        return columns[i];
    }
    __forceinline const QuadDirection& column(int i) const
    {
        return columns[i];
    }
    QuadDirection columns[3];
};

__forceinline void QuadDirection::multiply(const RotationColumns& rotation, const QuadDirection& input)
{
    const __m128 componentX = _mm_shuffle_ps(input.value, input.value, 0);
    const __m128 termX = _mm_mul_ps(rotation.column(0).value, componentX);
    const __m128 componentY = _mm_shuffle_ps(input.value, input.value, 0x55);
    const __m128 termY = _mm_mul_ps(rotation.column(1).value, componentY);
    const __m128 componentZ = _mm_shuffle_ps(input.value, input.value, 0xaa);
    const __m128 termZ = _mm_mul_ps(rotation.column(2).value, componentZ);
    value = _mm_add_ps(_mm_add_ps(termX, termY), termZ);
}

class Orientation : public RotationColumns
{
};

class RigidTransform
{
  public:
    __forceinline Orientation& rotation()
    {
        return orientation;
    }
    __forceinline const Orientation& rotation() const
    {
        return orientation;
    }
    Orientation orientation;
    QuadDirection translation;
};

template <class T> class QueryValue
{
  public:
    __forceinline T get() const
    {
        return value;
    }
    T value;
};

struct ConstraintQuery
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    QueryValue<const RigidTransform*> transformA;
    QueryValue<const RigidTransform*> transformB;
};

struct LocalOrientations
{
    int unk00, unk04, unk08, unk0c;
    Orientation localA;
    Orientation localB;
};

static __forceinline void RotateDirections(const RotationColumns& rotation, const QuadDirection* source, int count,
                                           QuadDirection* destination)
{
    RotationColumns saved = rotation;
    int i = count - 1;
    do
    {
        destination[i].multiply(saved, source[i]);
    } while (--i >= 0);
}

// Rotates four vectors from local.localA and local.localB by the rotations of input.transformA and transformB, storing them in outputA and outputB.
// @fnv 0x00d6c3c0
static __declspec(noinline) void FUN_00d6c3c0(const LocalOrientations& local, const ConstraintQuery& input,
                                              RigidTransform& outputA, RigidTransform& outputB)
{
    RotateDirections(input.transformA.get()->rotation(), &local.localA.column(0), 4, &outputA.rotation().column(0));
    RotateDirections(input.transformB.get()->rotation(), &local.localB.column(0), 4, &outputB.rotation().column(0));
}

void RotateLocalFrames(const LocalOrientations& local, const ConstraintQuery& input, RigidTransform& outputA,
                       RigidTransform& outputB)
{
    FUN_00d6c3c0(local, input, outputA, outputB);
}

extern "C" __m128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ps(float* p, __m128 a);

extern __m128 DAT_01267e30;

struct D73390Source
{
    float value0[4];
    float value1[4];
    float value2[4];
};

struct D73390Data
{
    float value0[4];
    float value1[4];
    float value2[4];
    float value3[4];

    void FUN_00de8f10();
};

// Copies three float arrays from source into data, loads a fourth from DAT_01267e30, calls FUN_00de8f10, then calls FUN_00d73380 with data and count.
// @fnv 0x00d73390
void __cdecl FUN_00d73390(D73390Source* source, int count)
{
    D73390Data data;

    _mm_store_ps(data.value0, _mm_load_ps(source->value0));
    _mm_store_ps(data.value1, _mm_load_ps(source->value1));
    _mm_store_ps(data.value2, _mm_load_ps(source->value2));
    _mm_store_ps(data.value3, _mm_load_ps((const float*)&DAT_01267e30));

    data.FUN_00de8f10();
    ((void(__cdecl*)(int*, int))FUN_00d73380)((int*)&data, count);
}

inline char hkToUpperD618(char c)
{
    return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c;
}

class UpperCaseBufferD618 : public hkStringBufD618
{
  public:
    int getLength() const
    {
        return m_iElementCount - 1;
    }
    void FUN_00d618d0();
};

// Converts every character in the buffer to its uppercase equivalent using hkToUpperD618.
// @fnv 0x00d618d0
void UpperCaseBufferD618::FUN_00d618d0()
{
    for (int i = 0; i < getLength(); i++)
    {
        m_data[i] = hkToUpperD618(m_data[i]);
    }
}

extern "C" __m128 _mm_load_ps(const float*);
struct TransformContext
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
    const __m128* m_pM1;
    const __m128* m_pM2;
};

struct TransformPair
{
    __m128 m_row[4];
};

// Transforms four src vectors by the rows at ctx->m_pM1 into dest->m_row and four more by ctx->m_pM2 into out, adding the fourth row of each as an offset.
// @fnv 0x00d6c240
static __declspec(noinline) void FUN_00d6c240(TransformPair* dest, const __m128* src, const TransformContext* ctx,
                                              __m128* out)
{
    const __m128* pMatrix = ctx->m_pM1;
    __m128 a = pMatrix[0];
    __m128 b = pMatrix[1];
    __m128 c = pMatrix[2];
    for (int n = 3; n >= 0; --n)
    {
        __m128 v = src[n + 1];
        __m128 r = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(src[n + 1].m128_f32), _mm_load_ps(src[n + 1].m128_f32), 0), a),
            _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), b));
        dest->m_row[n] = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c));
    }
    dest->m_row[3] = _mm_add_ps(dest->m_row[3], pMatrix[3]);

    pMatrix = ctx->m_pM2;
    a = pMatrix[0];
    b = pMatrix[1];
    c = pMatrix[2];
    for (int n = 3; n >= 0; --n)
    {
        __m128 v = src[n + 5];
        __m128 r = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(_mm_load_ps(src[n + 5].m128_f32), _mm_load_ps(src[n + 5].m128_f32), 0), a),
            _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), b));
        out[n] = _mm_add_ps(r, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), c));
    }
    out[3] = _mm_add_ps(out[3], pMatrix[3]);
}

TransformPair* volatile inputDest;
const __m128* volatile inputSource;
const TransformContext* volatile inputContext;
__m128* volatile inputOut;
void invokeTransform()
{
    FUN_00d6c240(inputDest, inputSource, inputContext, inputOut);
}

inline void SetTransformedPositionC320(QuadDirection& output, const RigidTransform& frame, const QuadDirection& input)
{
    const __m128 v = input.value;
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), frame.orientation.column(1).value);
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), frame.orientation.column(0).value);
    __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), frame.orientation.column(2).value);
    output.value = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, frame.translation.value));
}

struct PivotsC320
{
    QuadDirection m_unk00;
    QuadDirection m_kPivotA;
    QuadDirection m_kPivotB;
};

struct TransformOutputC320
{
    RigidTransform* p;
    TransformOutputC320(RigidTransform* value) : p(value)
    {}
};

// Applies the rigid transforms of two bodies to their respective pivot points, writing the resulting translations into the output transforms.
// @fnv 0x00d6c320
static __declspec(noinline) void __cdecl FUN_00d6c320(const PivotsC320* pivots, const ConstraintQuery* bodies,
                                                      TransformOutputC320 outA, TransformOutputC320 outB)
{
    SetTransformedPositionC320(outA.p->translation, *bodies->transformA.get(), pivots->m_kPivotA);
    SetTransformedPositionC320(outB.p->translation, *bodies->transformB.get(), pivots->m_kPivotB);
}

const ConstraintQuery* volatile bodiesSourceC320;
const PivotsC320* volatile pivotsSourceC320;
RigidTransform* volatile outASourceC320;
RigidTransform* volatile outBSourceC320;
void InvokeTransformC320()
{
    const ConstraintQuery* bodies = bodiesSourceC320;
    const PivotsC320* pivots = pivotsSourceC320;
    RigidTransform* a = outASourceC320;
    RigidTransform* b = outBSourceC320;
    FUN_00d6c320(pivots, bodies, a, b);
}


// src/havok/common/serialize/version/hkversionutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/version/hkversionutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl VisitObjectList(int, int);

struct FUN_00db7a80_Class
{
    int __pad0;
    int __pad1;
    int __pad2;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void EnsureInitialized();
};

// @fnv 0x00db7a80
void FUN_00db7a80_Class::EnsureInitialized()
{
    if (!m_iFourthElementInteger)
    {
        VisitObjectList(m_kPointB, m_iThirdValue);
        m_iFourthElementInteger = 1;
    }
}

struct MemoryManager
{
    virtual void FUN_00e00000() = 0;
    virtual void FUN_00e00004() = 0;
    virtual void FUN_00e00008(void*, unsigned short) = 0;
};

struct MemoryRouter
{
    void* m_p00;
    void* m_p04;
    void* m_p08;
    void* m_p0C;
    MemoryManager* m_pMemoryManager;
};

MemoryRouter* _D1A0E0GetMemoryRouter();

struct Object
{
    void FUN_00e03160();
};

struct FUN_00e049d0_Class : Object
{
    unsigned int m_auiShapeKeys;
    unsigned short m_type;

    FUN_00e049d0_Class* FUN_00e049d0(int flags);
};

// @fnv 0x00e049d0
FUN_00e049d0_Class* FUN_00e049d0_Class::FUN_00e049d0(int flags)
{
    Object::FUN_00e03160();

    if (flags & 1)
    {
        MemoryRouter* router = _D1A0E0GetMemoryRouter();
        unsigned short type = m_type;
        router->m_pMemoryManager->FUN_00e00008(this, type);
    }

    return this;
}

extern "C" char str_010cf830[];

// @fnv 0x00dc0fb0
void* __cdecl FUN_00dc0fb0()
{
    return &str_010cf830;
}

struct FUN_00d86980_Class
{
    int FUN_00d86980();
};

struct FUN_00d871a0
{
    int m_00;
    int m_04;

    FUN_00d871a0(void*, int);
    bool& FUN_00d871e0(bool&);
    void* FUN_00d871f0();
    FUN_00d86980_Class* FUN_00d87370();
};

extern "C" void* __cdecl FUN_00cb1260(void*, const void*, unsigned int);

// @fnv 0x00dc0fc0
void __cdecl FUN_00dc0fc0(void* a1, int a2, void* a3, int a4)
{
    FUN_00d871a0 obj1(a1, a2);
    FUN_00d871a0 obj2(a3, a4);
    bool b;
    if (obj1.FUN_00d871e0(b) && obj2.FUN_00d871e0(b))
    {
        FUN_00cb1260(obj2.FUN_00d871f0(), obj1.FUN_00d871f0(), obj2.FUN_00d87370()->FUN_00d86980());
    }
}

struct FUN_00d46d40_s
{
    const char* FUN_00d46d40() const throw();
};

class GlobalObjectO2_00d472a0 : public FUN_00d46d40_s
{
  public:
    int m_00;
};
extern GlobalObjectO2_00d472a0 g_01268748;

int __cdecl FUN_00cb0fa0(const char* pcA, const char* pcB) throw();

class hkClassMemberDC11
{
  public:
    enum Type
    {
        TYPE_POINTER = 0x14,
        TYPE_ARRAY = 0x16,
        TYPE_STRUCT = 0x19,
        TYPE_SIMPLEARRAY = 0x1a,
        TYPE_VARIANT = 0x1c,
        TYPE_CSTRING = 0x1d,
        TYPE_STRINGPTR = 0x21
    };

    const char* m_name;
    const void* m_class;
    const void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;

    int FUN_00d86920() const throw();
    const FUN_00d46d40_s& FUN_00d86910() const throw();
};

class hkVersionCheckDC11
{
  public:
    int areMembersCompatible(const hkClassMemberDC11* pkOld, const hkClassMemberDC11* pkNew) throw();
    int IsMemberCompatible(const hkClassMemberDC11* pkOld, const hkClassMemberDC11* pkNew) throw();
};

// Returns 1 if the old class member is compatible with the new one by type/subtype, cstring-to-stringptr, or variant-to-pointer conversion; otherwise 0.
// @fnv 0x00dc1100
int hkVersionCheckDC11::IsMemberCompatible(const hkClassMemberDC11* pkOld, const hkClassMemberDC11* pkNew) throw()
{
    bool bTypeCompatible = (pkOld->m_type == pkNew->m_type) || (pkOld->m_type == hkClassMemberDC11::TYPE_SIMPLEARRAY &&
                                                                pkNew->m_type == hkClassMemberDC11::TYPE_ARRAY);
    bool bCStringToStringPtr =
        (pkOld->m_type == hkClassMemberDC11::TYPE_CSTRING && pkNew->m_type == hkClassMemberDC11::TYPE_STRINGPTR);
    bool bVariantToPtr =
        (pkOld->m_type == hkClassMemberDC11::TYPE_VARIANT && pkNew->m_type == hkClassMemberDC11::TYPE_POINTER &&
         pkNew->m_eSubtype == hkClassMemberDC11::TYPE_STRUCT && pkNew->FUN_00d86920() &&
         FUN_00cb0fa0(g_01268748.FUN_00d46d40(), pkNew->FUN_00d86910().FUN_00d46d40()) == 0);
    bool bSubTypeCompatible =
        (pkOld->m_eSubtype == pkNew->m_eSubtype) || (pkOld->m_eSubtype == hkClassMemberDC11::TYPE_CSTRING &&
                                                     pkNew->m_eSubtype == hkClassMemberDC11::TYPE_STRINGPTR);
    bool bSubVariantToPtr =
        (pkOld->m_eSubtype == hkClassMemberDC11::TYPE_VARIANT && pkNew->m_eSubtype == hkClassMemberDC11::TYPE_POINTER &&
         pkNew->FUN_00d86920() && FUN_00cb0fa0(g_01268748.FUN_00d46d40(), pkNew->FUN_00d86910().FUN_00d46d40()) == 0);

    if (areMembersCompatible(pkOld, pkNew) || bCStringToStringPtr || bVariantToPtr ||
        (bTypeCompatible && (bSubTypeCompatible || bSubVariantToPtr)))
        return 1;
    return 0;
}

class hkMemoryAllocatorDC12;

struct hkMemoryRouterDC12
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDC12* m_pStreamAllocator;
    hkMemoryAllocatorDC12& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDC12& __cdecl FUN_00c85750();

void __cdecl ProcessObjectArray(void* const* ppvList, int iFlags) throw();

class hkPointerMapDC12
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    hkPointerMapDC12() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~hkPointerMapDC12() throw()
    {
        FUN_00a29680();
    }

    void EnsureCapacity(hkMemoryAllocatorDC12& kAlloc, int iNumElems) throw();
    void ProcessArgument(hkMemoryAllocatorDC12& kAlloc) throw();
    void FUN_00a29680() throw();
};

class hkVisitorDC12
{
  public:
    int unk00;

    hkVisitorDC12() throw()
    {
        FUN_00dc1670();
    }
    void FUN_00dc1670() throw();
    void FUN_00dc1bb0(void* pvObject, hkPointerMapDC12& kDone, int iFlags) throw();
};

// @fnv 0x00dc1230
extern "C" void __cdecl VisitObjectList(int apvList, int iFlags)
{
    void* const* ppvList = reinterpret_cast<void* const*>(apvList);
    ProcessObjectArray(ppvList, iFlags);
    hkVisitorDC12 kVisitor;
    hkPointerMapDC12 kDone;
    kDone.EnsureCapacity(FUN_00c85750().heap(), 0);
    for (int i = 0; ppvList[i]; i++)
        kVisitor.FUN_00dc1bb0(ppvList[i], kDone, 1);
    kDone.ProcessArgument(FUN_00c85750().heap());
}

class hkBoolDC10
{
  public:
    hkBoolDC10(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    char m_cBooleanValue;
};

class FUN_00d27520
{
  public:
    void FUN_00d27520_dtor() throw();
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_offset;
    char* m_buf;
    int m_curSize;
    int m_iCapacity;
    char m_overflowed;
};

class FUN_00d274c0 : public FUN_00d27520
{
  public:
    FUN_00d274c0(void* pvMem, int m_uiSizeAndFlags, hkBoolDC10 bMemoryIsString) throw();
    int FUN_00d27380(int offset, int whence) throw();
};

struct EntryDC10
{
    int m_key;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short m_offset;
};

class SetDC10
{
  public:
    int FUN_00d46fe0(int key) throw();
};

class SectionsDC10
{
  public:
    int FUN_00d470d0() throw();
    int FUN_00d46f00() throw();
    EntryDC10* FUN_00d46f20(int i) throw();
    void InvokeTarget(int i, FUN_00d27520* pkWriter) throw();
};

// Writes entries from pkSections whose key is not in pkSet to pvBuf via a FUN_00d274c0 writer.
// @fnv 0x00dc1070
void __cdecl FUN_00dc1070(void* apvBuffer, SetDC10* pkSet, SectionsDC10* pkSections)
{
    FUN_00d274c0 kWriter(apvBuffer, pkSections->FUN_00d470d0(), false);
    for (int i = 0; i < pkSections->FUN_00d46f00(); i++)
    {
        EntryDC10* pkEntry = pkSections->FUN_00d46f20(i);
        int key = pkEntry->m_key;
        if (!pkSet->FUN_00d46fe0(key))
        {
            int iOffset = pkEntry->m_offset;
            kWriter.FUN_00d27380(iOffset, 0);
            pkSections->InvokeTarget(i, &kWriter);
        }
    }
    kWriter.FUN_00d27520_dtor();
}

struct S00dc15a0_Buffer
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(int* indices, unsigned int size);
};

struct S00dc15a0_AudioSystem
{
    int unk00;
    int unk04;
    int unk08;
    S00dc15a0_Buffer* unk0C;
};

struct S00dc15a0_Params
{
    void* unk00;
    int unk04;
};

struct S00dc15a0_Array
{
    int* m_data;
    int m_iElementCount;
    int m_capFlags;
};

namespace fnvc_adapt {
extern "C" S00dc15a0_AudioSystem* __cdecl FUN_00c85750();
}
extern "C" void __cdecl FUN_00c908c0(S00dc15a0_Buffer* buffer, int** indices, int size, int elementSize);

static __declspec(noinline) int FUN_00dc12c0(S00dc15a0_Params* params, int value, int flags, S00dc15a0_Array* arr)
{
    arr->m_iElementCount = (int)&params + (int)&value + (int)&flags;
    return arr->m_capFlags;
}

// Builds an array containing 0..count-1, passes it to FUN_00dc12c0, and returns that call's result.
// @fnv 0x00dc15a0
int __cdecl FUN_00dc15a0(S00dc15a0_Params* params, int value, int flags)
{
    S00dc15a0_Array arr;
    int count = params->unk04;
    arr.m_data = 0;
    arr.m_iElementCount = 0;
    arr.m_capFlags = 0x80000000;

    S00dc15a0_AudioSystem* pAudioSystem = fnvc_adapt::FUN_00c85750();
    S00dc15a0_Buffer* heap = pAudioSystem->unk0C;
    int iCurrentCap = arr.m_capFlags & 0x3fffffff;
    if (iCurrentCap < count)
    {
        int newCap = iCurrentCap + iCurrentCap;
        if (count >= newCap)
            newCap = count;
        FUN_00c908c0(heap, &arr.m_data, newCap, 4);
    }

    int index = 0;
    arr.m_iElementCount = count;
    if (params->unk04 > 0)
    {
        do
        {
            arr.m_data[index] = index;
            ++index;
        } while (index < params->unk04);
    }

    int result = FUN_00dc12c0(params, value, flags, &arr);

    pAudioSystem = fnvc_adapt::FUN_00c85750();
    S00dc15a0_Buffer* heap2 = pAudioSystem->unk0C;
    arr.m_iElementCount = 0;
    if ((arr.m_capFlags & 0x80000000) == 0)
    {
        heap2->vf10(arr.m_data, (arr.m_capFlags & 0x3fffffff) * 4);
    }

    return result;
}

struct hkStructureLayoutDC10
{
    char m_ucBytesInPointer;
    char m_bLittleEndian;
    char m_bReusePaddingOptimization;
    char m_bEmptyBaseClassOptimization;
};

struct hkFlagsDC10
{
    int m_kStorage;
    hkFlagsDC10(int i) : m_kStorage(i)
    {}
};

namespace FUN_00e03120 {
class hkObjectCopier
{
  public:
    hkObjectCopier(const hkStructureLayoutDC10& kSrc, const hkStructureLayoutDC10& kDst, hkFlagsDC10 kFlags);
    virtual void CopyContents();
    int unk04, unk08, unk0C;
};
}

namespace FUN_00dc1040 {
class PackfileObjectCopier : public FUN_00e03120::hkObjectCopier
{
  public:
    PackfileObjectCopier(const hkStructureLayoutDC10& kSrc, const hkStructureLayoutDC10& kDst);
    virtual void CopyContents();
};

// @fnv 0x00dc1040
PackfileObjectCopier::PackfileObjectCopier(const hkStructureLayoutDC10& kSrc, const hkStructureLayoutDC10& kDst)
    : FUN_00e03120::hkObjectCopier(kSrc, kDst, 0)
{}
}

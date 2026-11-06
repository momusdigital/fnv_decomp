
// src/gamebryo2.2/corelibs/nimain/niavobject_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niavobject.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// src/gamebryo2.2/corelibs/nimain/niavobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niavobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct NiAVObject
{
    void __thiscall UpdateTimeControllers(NiUpdateData&, bool);
};
struct FUN_00a5a030_shell : NiAVObject
{
    void __thiscall UpdateControllers(NiUpdateData& data);
};
extern char const* const g_011f4428_arg1;
char const* const* __cdecl FUN_00a5a420();
extern const void* DAT_011f9140;
const void* __cdecl FUN_00b4e1d0();
struct MemoryManager
{
    void* __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00a59dc0_shell
{
    void __thiscall SetBoundObject(void* apBound);
};

// @fnv 0x00438220
int __cdecl FUN_00438220()
{
    return 3;
}

struct Flt
{
    operator unsigned int() const;
};
struct TESActorBaseData
{
    unsigned short GetFatigue() const;
};
struct FUN_00456650_shell
{
    unsigned short FUN_00456650() const;
};
// @fnv 0x00456650
unsigned short FUN_00456650_shell::FUN_00456650() const
{
    return ((TESActorBaseData*)((const Flt*)((const char*)this + 0xb8))->operator unsigned int())->GetFatigue();
}

struct FUN_004a51b0_shell
{
    const float* __thiscall FUN_004a51b0(int i) const;
};

// @fnv 0x004a51b0
const float* __thiscall FUN_004a51b0_shell::FUN_004a51b0(int i) const
{
    const float* base = (const float*)this;
    return base + i;
}

struct FUN_0094db80_shell
{
    void __thiscall FUN_0094db80(unsigned char ucRef);
};
// @fnv 0x0094db80
void __thiscall FUN_0094db80_shell::FUN_0094db80(unsigned char ucRef)
{
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x1a) = ucRef;
}

struct NiObjectStub;

struct ObjPtr
{
    NiObjectStub* m_pObject;
    ObjPtr(NiObjectStub* pObject);
    ~ObjPtr();
    bool operator!=(const ObjPtr& ptr) const;
    ObjPtr& operator=(const ObjPtr& ptr);
};

ObjPtr* __cdecl FUN_005e0ba0(unsigned int auiCount);
void __cdecl FUN_004b0220(ObjPtr* pArray);

struct ObjPtrArray
{
    virtual ~ObjPtrArray();
    ObjPtr* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void FUN_004afc80();
};

// @fnv 0x004afc80
void ObjPtrArray::FUN_004afc80()
{
    if (m_usESize == m_usSize)
        return;

    if (m_usESize)
    {
        for (unsigned short i = 0, j = 0; i < m_usSize; i++)
        {
            if (m_pBase[i] != ObjPtr(0))
            {
                if (m_pBase[j] != m_pBase[i])
                    m_pBase[j] = m_pBase[i];
                j++;
            }
        }
    }

    ObjPtr* pSaveBase = m_pBase;
    m_usMaxSize = m_usSize = m_usESize;
    if (m_usMaxSize > 0)
    {
        m_pBase = FUN_005e0ba0(m_usMaxSize);
        for (unsigned short i = 0; i < m_usSize; i++)
            m_pBase[i] = pSaveBase[i];
    }
    else
    {
        m_pBase = 0;
    }
    FUN_004b0220(pSaveBase);
}

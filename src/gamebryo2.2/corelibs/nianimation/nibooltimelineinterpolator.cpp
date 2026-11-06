
// src/gamebryo2.2/corelibs/nianimation/nibooltimelineinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibooltimelineinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f4044;

// @fnv 0x00a52d70
void* __cdecl FUN_00a52d70()
{
    return &g_011f4044;
}

struct NiStream
{
};
struct NiBoolInterpolator
{
    NiStream* LinkObject(NiStream*);
};
struct NiBoolInterpController
{
    NiBoolInterpolator* LinkObject(NiStream*);
};

extern int DAT_01099fb4;

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

// Allocates a 0x20-byte NiBoolInterpolator, initialises its vtable, clears the field at offset 0x18 and the byte at 0x1c, and returns it (or null).
// @fnv 0x00a52fe0
NiBoolInterpolator* __cdecl CreateBoolInterpolator()
{
    NiBoolInterpolator* p = static_cast<NiBoolInterpolator*>(BSFadeNode::operator new(0x20));
    if (p)
    {
        p->LinkObject(0);
        *reinterpret_cast<void**>(p) = reinterpret_cast<void*>(&DAT_01099fb4);
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x18) = 0;
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(p) + 0x1c) = 0;
        return p;
    }
    return 0;
}

struct RefObj
{
    virtual void F0();
    virtual void F1();
    long m_ref;
};
struct FUN_00a3ca30_shell
{
    void FUN_00a3ca30();
};
struct FUN_00a52f30_shell
{
    char _pad[16];
    RefObj* m_ptr;
    char _pad2[12];
    void* ReleaseRef(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
// Decrements the reference count of m_ptr and calls F1 when it reaches zero, then calls FUN_00a3ca30 and frees this if flag bit 0 is set.
// @fnv 0x00a52f30
void* FUN_00a52f30_shell::ReleaseRef(unsigned int auiFlags)
{
    RefObj* p = m_ptr;
    if (p)
    {
        if (InterlockedDecrement(&p->m_ref) == 0)
            p->F1();
    }
    ((FUN_00a3ca30_shell*)this)->FUN_00a3ca30();
    if (auiFlags & 1)
        _delete(this, 0x20);
    return this;
}

struct StrArr
{
    void* m_pData;
    unsigned int m_ui4;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usPad;
    unsigned short m_usGrowSize;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct Proxy536d0
{
    void GetViewerStrings(StrArr*);
};
char* __cdecl _FUN_00a7d330(const char*);
struct NiBoolTimelineInterpolator : NiBoolInterpolator
{
    void AppendString(StrArr*);
};
// Appends the string returned by _FUN_00a7d330(g_011f4044) to pkStrings, growing it via SetSize when full, after calling GetViewerStrings.
// @fnv 0x00a53020
void NiBoolTimelineInterpolator::AppendString(StrArr* pkStrings)
{
    ((Proxy536d0*)this)->GetViewerStrings(pkStrings);
    char* pszStr = _FUN_00a7d330((const char*)g_011f4044);
    unsigned int uiSize = pkStrings->m_usSize;
    if (uiSize >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiSize + pkStrings->m_usGrowSize);
    pkStrings->SetAt(uiSize, pszStr);
}

struct NiKeyBasedInterpolator
{
    NiKeyBasedInterpolator();
};
extern unsigned int DAT_0109a0b4;
extern unsigned char DAT_0109a914;
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// Allocates a 0x18-byte NiKeyBasedInterpolator, constructs it, sets its vtable and fields, and returns the pointer or 0.
// @fnv 0x00a53500
void* CreateNiKeyBasedInterpolator()
{
    void* p = BSFadeNode::operator new(0x18);
    if (p)
    {
        new (p) NiKeyBasedInterpolator();
        *(unsigned int*)p = (unsigned int)&DAT_0109a0b4;
        *(unsigned char*)((char*)p + 0xc) = DAT_0109a914;
        *(unsigned int*)((char*)p + 0x10) = 0;
        *(unsigned int*)((char*)p + 0x14) = 0;
        return p;
    }
    return 0;
}

struct NiBoolData : NiStream
{
};
struct FUN_00a52f00 : NiBoolInterpolator
{
    char _pad[24];
    unsigned int m_uiLastIndex;
    bool m_bBoolValue;
    FUN_00a52f00(NiBoolData* pkBoolData);
};
// Constructs the object, links it to the given NiBoolData stream, zeroes two fields and sets the vtable.
// @fnv 0x00a52f00
FUN_00a52f00::FUN_00a52f00(NiBoolData* pkBoolData)
{
    NiBoolInterpolator::LinkObject((NiStream*)pkBoolData);
    m_uiLastIndex = 0;
    m_bBoolValue = 0;
    *(int**)this = &DAT_01099fb4;
}

struct BoolKey
{
    float time;
    unsigned char opposite;
};
unsigned char __cdecl InterpolateBooleanKey(float, BoolKey*, unsigned int, unsigned int, unsigned int&, unsigned char);
struct BoolData
{
    int unk00, unk04;
    unsigned int count;
    BoolKey* keys;
    unsigned int type;
    unsigned char stride;
    BoolKey* Get(unsigned int& n, unsigned int& t, unsigned char& s)
    {
        n = count;
        t = type;
        s = stride;
        return keys;
    }
};
struct Timeline
{
    int unk00, unk04;
    float lastTime;
    unsigned char cached;
    BoolData* data;
    unsigned int index, previousIndex;
    unsigned char previousValue;
    bool EvaluateBoolAtTime(float, void*, bool&);
};
// Evaluates the boolean key timeline at time, updating index, cached and previousValue, and returns whether a value is available via out.
// @fnv 0x00a52d80
bool Timeline::EvaluateBoolAtTime(float time, void*, bool& out)
{
    if (lastTime == time)
    {
        if (cached == DAT_0109a914)
        {
            out = false;
            return false;
        }
        out = cached != 0;
        return true;
    }
    if (data)
    {
        unsigned int type = data->type;
        unsigned char stride = data->stride;
        BoolKey* keys = data->keys;
        unsigned int count = data->count;
        if (count > 0)
        {
            previousIndex = index;
            unsigned char opposite = InterpolateBooleanKey(time, keys, type, count, index, stride);
            unsigned int current = index;
            unsigned char result = opposite;
            unsigned char value;
            if (opposite == previousValue)
            {
                value = !opposite;
                if (previousIndex != current && previousIndex + 1 > current)
                {
                    for (unsigned int uiIndex = previousIndex + 1; uiIndex < count; uiIndex++)
                    {
                        if (((BoolKey*)((char*)keys + stride * uiIndex))->opposite == value)
                        {
                            goto changed;
                        }
                    }
                    if (opposite != value)
                    {
                        for (unsigned int uiIndex2 = 0; uiIndex2 < current; uiIndex2++)
                        {
                            if (((BoolKey*)((char*)keys + stride * uiIndex2))->opposite == value)
                            {
                                goto changed;
                            }
                        }
                    }
                }
                else
                {
                    for (unsigned int uiIndex3 = previousIndex + 1; uiIndex3 < current && uiIndex3 < count; uiIndex3++)
                    {
                        if (((BoolKey*)((char*)keys + stride * uiIndex3))->opposite == value)
                        {
                            goto changed;
                        }
                    }
                }
            }
            goto ready;
        changed:
            result = value;
        ready:
            cached = result != 0;
            previousValue = opposite;
        }
    }
    if (cached == DAT_0109a914)
    {
        out = false;
        return false;
    }
    out = cached != 0;
    lastTime = time;
    return true;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* plAddend);

class A53480RefObject
{
  public:
    virtual ~A53480RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

template <class T> class A53480Pointer
{
  public:
    T* m_pObject;

    A53480Pointer& operator=(const A53480Pointer& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

class A53480CloningProcess;

class A53480Base
{
  public:
    int unk00;
    int unk04;
    int unk08;

    void FUN_00aa0ab0(A53480Base* pkDest, A53480CloningProcess& kCloning);
};

class A53480Object : public A53480Base
{
  public:
    bool m_bFlag;
    A53480Pointer<A53480RefObject> m_spTransformData;
    unsigned int m_uiCurrentValue;

    void CloneTo(A53480Object* pkDest, A53480CloningProcess& kCloning);
};

// @fnv 0x00a53480
void A53480Object::CloneTo(A53480Object* pkDest, A53480CloningProcess& kCloning)
{
    FUN_00aa0ab0(pkDest, kCloning);
    pkDest->m_bFlag = m_bFlag;
    pkDest->m_spTransformData = m_spTransformData;
    pkDest->m_uiCurrentValue = m_uiCurrentValue;
}

void __cdecl FUN_00a43330();
// @fnv 0x00a514d0
void __cdecl FUN_00a514d0()
{
    FUN_00a43330();
}

void __cdecl SaveToStream();

// @fnv 0x00a52d00
void __cdecl FUN_00a52d00()
{
    SaveToStream();
}

extern void FUN_00a53600();

// @fnv 0x00a52ce0
void FUN_00a52ce0()
{
    FUN_00a53600();
}

extern void FUN_00a3c5b0();

// @fnv 0x00a52cf0
void FUN_00a52cf0()
{
    FUN_00a3c5b0();
}

struct BoolInterpolator
{
    bool FUN_00a53220();
    bool IsEqual();
};
// @fnv 0x00a52d10
bool BoolInterpolator::IsEqual()
{
    return FUN_00a53220();
}

class CloningProcessA52F;

class FUN_00a53280
{
  public:
    FUN_00a53280(int flags) throw();
    virtual ~FUN_00a53280() throw();
    int unk04[5];
};

class InterpA52F : public FUN_00a53280
{
  public:
    InterpA52F() throw() : FUN_00a53280(0)
    {
        m_uiLastIndex = 0;
        m_bBoolValue = false;
    }
    virtual ~InterpA52F() throw();

    static void* operator new(unsigned int n)
    {
        return BSFadeNode::operator new(n);
    }

    unsigned int m_uiLastIndex;
    bool m_bBoolValue;

    void CloneTo(InterpA52F* dest, CloningProcessA52F& cloning);
    InterpA52F* CreateClone(CloningProcessA52F& cloning);
};

// Allocates a new InterpA52F, copies state into it via CloneTo, and returns the clone.
// @fnv 0x00a52f80
InterpA52F* InterpA52F::CreateClone(CloningProcessA52F& cloning)
{
    InterpA52F* p = new InterpA52F;
    CloneTo(p, cloning);
    return p;
}


// src/gamebryo2.2/corelibs/nimain/nifogproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nifogproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Obj00a9a120
{
    virtual void f0();
    virtual void f1();
    volatile long m_ref;
};
extern Obj00a9a120* DAT_011f5f3c;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
// If the global object exists, decrements its reference count, calls its virtual f1 when the count reaches zero, and clears the global pointer.
// @fnv 0x00a9a120
void FUN_00a9a120()
{
    if (DAT_011f5f3c)
    {
        Obj00a9a120* p = DAT_011f5f3c;
        if (!InterlockedDecrement(&DAT_011f5f3c->m_ref))
            p->f1();
        DAT_011f5f3c = 0;
    }
}

struct NiProperty
{
    virtual void Dummy()
    {}
    char _pad[20];
    NiProperty();
};
struct NiColor
{
    float r;
    float g;
    float b;
    NiColor()
    {
        b = g = r = 0.0f;
    }
};
extern NiColor DAT_011f4998;
extern int DAT_011f499c;
extern int DAT_011f49a0;
struct FUN_00a99ed0 : NiProperty
{
    unsigned short m_uiObjectFlags;
    float m_fFogDepth;
    NiColor m_kFogTint;
    FUN_00a99ed0();
};
// @fnv 0x00a99ed0
FUN_00a99ed0::FUN_00a99ed0()
{
    m_uiObjectFlags = 0;
    m_fFogDepth = 1.0f;
    m_kFogTint = DAT_011f4998;
}

enum FogFunction
{
    FOG_Z_LINEAR = 0,
    FOG_RANGE_SQ = 1,
    FOG_VERTEX_ALPHA = 2
};

extern "C" unsigned int __cdecl strlen(const char*);
void* __cdecl NiMalloc(unsigned int);
char* __cdecl NiSprintf(char*, unsigned int, const char*, ...);

// Allocates a string of strlen(pcPrefix)+20 bytes and formats pcPrefix with the name of the given fog function.
// @fnv 0x00a99e50
char* FormatFogFunction(const char* pcPrefix, FogFunction eFunc)
{
    char* pcString;
    unsigned int uiLen = strlen(pcPrefix);

    pcString = static_cast<char*>(NiMalloc(uiLen + 20));

    switch (eFunc)
    {
    case FOG_Z_LINEAR:
        NiSprintf(pcString, uiLen + 20, "%s = FOG_Z_LINEAR", pcPrefix);
        break;

    case FOG_RANGE_SQ:
        NiSprintf(pcString, uiLen + 20, "%s = FOG_RANGE_SQ", pcPrefix);
        break;

    case FOG_VERTEX_ALPHA:
        NiSprintf(pcString, uiLen + 20, "%s = FOG_VERTEX_ALPHA", pcPrefix);
        break;
    }

    return pcString;
}

struct MyClass
{
    char _pad0[0xc];
    int m_0c;
    char _pad1[0x8];
    unsigned short m_18;
    char _pad2[2];
    float m_1c;
    NiColor m_20;

    void* CreateClone(int arg);
};

struct CalleeA5d7a0
{
    void FUN_00a5d7a0(void* prop, int arg);
};

void* __cdecl FUN_00aa13e0(unsigned int);
void __stdcall CreateVertexBufferSet(void*, int);

void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

// @fnv 0x00a99f60
void* MyClass::CreateClone(int arg)
{
    if (this->m_0c != 0)
    {
        void* raw = FUN_00aa13e0(0x2c);
        FUN_00a99ed0* esi;
        if (raw)
        {
            esi = new (raw) FUN_00a99ed0();
        }
        else
        {
            esi = 0;
        }
        ((CalleeA5d7a0*)this)->FUN_00a5d7a0(esi, arg);
        unsigned short cx = this->m_18;
        esi->m_uiObjectFlags = cx;
        esi->m_fFogDepth = this->m_1c;
        esi->m_kFogTint = this->m_20;
        return esi;
    }
    else
    {
        CreateVertexBufferSet(this, arg);
        return this;
    }
}

void* __cdecl FUN_00aa13e0(unsigned int bytes);

struct NiFogProperty : NiProperty
{
    unsigned short m_uiObjectFlags;
    float m_fFogDepth;
    NiColor m_kFogTint;

    static void* operator new(unsigned int, void* memory)
    {
        return memory;
    }

    __forceinline NiFogProperty()
    {
        m_uiObjectFlags = 0;
        m_fFogDepth = 1.0f;
        m_kFogTint = DAT_011f4998;
    }
};

// Allocates memory for a NiFogProperty and constructs it in place, returning the new object or null on allocation failure.
// @fnv 0x00a99fd0
NiFogProperty* __cdecl CreateNiFogProperty()
{
    void* memory = FUN_00aa13e0(sizeof(NiFogProperty));
    if (memory != 0)
        return new (memory) NiFogProperty;
    return 0;
}

class NiObject;

struct EqBase
{
    bool __thiscall FUN_00a62140(NiObject* object);
};

struct NiPlane
{
    float x;
    float y;
    float z;

    bool __thiscall FUN_00439090(const NiPlane* other);
};

struct A9a030Fog : FUN_00a99ed0
{
    bool __thiscall IsEqual(FUN_00a99ed0* other);
};

// @fnv 0x00a9a030
bool __thiscall A9a030Fog::IsEqual(FUN_00a99ed0* other)
{
    EqBase* base = reinterpret_cast<EqBase*>(this);

    if (base->FUN_00a62140(reinterpret_cast<NiObject*>(other)))
    {
        volatile unsigned char* ownFlags = reinterpret_cast<volatile unsigned char*>(&m_uiObjectFlags);
        unsigned char* otherFlags = reinterpret_cast<unsigned char*>(&other->m_uiObjectFlags);

        if (((*ownFlags ^ *otherFlags) & 1) == 0)
        {
            if (m_fFogDepth == other->m_fFogDepth)
            {
                if (((*ownFlags ^ *otherFlags) & 6) == 0)
                {
                    NiPlane* color = reinterpret_cast<NiPlane*>(&m_kFogTint);
                    const NiPlane* otherColor = reinterpret_cast<const NiPlane*>(&other->m_kFogTint);

                    if (!color->FUN_00439090(otherColor))
                        return true;
                }
            }
        }
    }

    return false;
}

struct PropertyFlagWord
{
    unsigned short value;
    void Merge(unsigned bits)
    {
        unsigned short retained = value;
        retained &= 0xfff9;
        retained |= (unsigned short)(bits * 2);
        value = retained;
    }
};
struct Reader
{
    unsigned unk00;
    unsigned position;
    typedef int(__cdecl* ReadFn)(Reader*, void*, unsigned, unsigned*, unsigned);
    ReadFn read;
};
struct LoadStream
{
    unsigned version() const
    {
        return *(const unsigned*)((const char*)this + 0xd8);
    }
    unsigned short legacyFlags() const
    {
        return *(const unsigned short*)((const char*)this + 0x288);
    }
    Reader* reader() const
    {
        return *(Reader* const*)((const char*)this + 0x24c);
    }
};
void __stdcall FUN_00a5d7f0(LoadStream*);
struct SubObject
{
    void FUN_00a59be0(LoadStream*);
};
struct NiPropertyData
{
    unsigned short& flags()
    {
        return *(unsigned short*)((char*)this + 0x18);
    }
    unsigned& extra()
    {
        return *(unsigned*)((char*)this + 0x1c);
    }
    void LoadPropertyData(LoadStream*);
};
// Loads property flags and extra data from the stream based on version, then loads the sub-object at offset 0x20.
// @fnv 0x00a9a150
void NiPropertyData::LoadPropertyData(LoadStream* stream)
{
    LoadStream* original = stream;
    FUN_00a5d7f0(original);
    if (original->version() < 0x0a000102)
    {
        unsigned raw = original->legacyFlags();
        flags() = (unsigned short)raw;
        if (original->version() < 0x05000016)
        {
            unsigned char bit = (unsigned char)raw;
            bit >>= 1;
            bit &= 1;
            raw >>= 3;
            raw &= 3;
            flags() = 0;
            if (bit)
                flags() = 1;
            else
                flags() = 0;
            ((PropertyFlagWord*)((char*)this + 0x18))->Merge(raw);
        }
        else
        {
            flags() = (unsigned short)(raw & 7);
        }
    }
    else
    {
        Reader* pReader = original->reader();
        Reader::ReadFn pReadFn = pReader->read;
        unsigned& amount = *(unsigned*)&stream;
        amount = 2;
        int count = pReadFn(pReader, &flags(), 2, &amount, 1);
        pReader->position += count;
    }
    Reader* pReader = original->reader();
    Reader::ReadFn pReadFn = pReader->read;
    unsigned& amount = *(unsigned*)&stream;
    amount = 4;
    int count = pReadFn(pReader, &extra(), 4, &amount, 1);
    pReader->position += count;
    ((SubObject*)((char*)this + 0x20))->FUN_00a59be0(original);
}

struct ViewerStrings
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& element);
    unsigned int Add(char* const& element)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, (char*&)element);
        return uiIndex;
    }
};

struct RTTIStub
{
    const char* m_pcName;
};
extern RTTIStub g_fogRTTI;

char* MakeViewerString(const char* pcText);
char* MakeViewerString(const char* pcPrefix, bool bValue);
char* MakeViewerString(const char* pcPrefix, float fValue);

struct ColorStub
{
    float r, g, b;
    char* FormatToBuffer(const char* pcPrefix) const;
};

struct PropertyBase
{
    void GetViewerStringsBase(ViewerStrings* apViewerStrings);
};

struct FogViewer : PropertyBase
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned short m_uiObjectFlags;
    unsigned short unk1a;
    float m_fFogDepth;
    ColorStub m_kFogTint;

    FogFunction GetFogFunction() const
    {
        return (FogFunction)((m_uiObjectFlags >> 1) & 3);
    }
    bool GetFog() const
    {
        return (m_uiObjectFlags & 1) != 0;
    }
    void GetViewerStrings(ViewerStrings* apViewerStrings);
};

// @fnv 0x00a9a2a0
void FogViewer::GetViewerStrings(ViewerStrings* pViewerStrings)
{
    GetViewerStringsBase(pViewerStrings);
    pViewerStrings->Add(MakeViewerString(g_fogRTTI.m_pcName));
    pViewerStrings->Add(MakeViewerString("Enable", GetFog()));
    pViewerStrings->Add(MakeViewerString("Depth", m_fFogDepth));
    pViewerStrings->Add(FormatFogFunction("Function", GetFogFunction()));
    pViewerStrings->Add(m_kFogTint.FormatToBuffer("Color"));
}

class NiBinaryStreamA9A2
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_READFN)(NiBinaryStreamA9A2* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                  unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    virtual ~NiBinaryStreamA9A2();

    unsigned int m_uiStreamFlags;
    void* m_pfnWrite;
    NIBINARYSTREAM_READFN m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class NiStreamA9A2
{
  public:
    virtual ~NiStreamA9A2();

    unsigned char m_auPad[0x24c];
    NiBinaryStreamA9A2* m_pUnderlyingStream;
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStreamA9A2& is, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    is.BinaryRead(pValue, sizeof(T) * uiNumEls, &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStreamA9A2& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}

class FUN_00a5d7b0_helper
{
  public:
    void FUN_00a5d7b0(NiStreamA9A2& kStream);
};

class NiColorA9A2
{
  public:
    float r, g, b;
    void FUN_00a69780(NiStreamA9A2& kStream);
};

class SaverA9A2 : public FUN_00a5d7b0_helper
{
  public:
    int m_unk00[6];
    unsigned short m_us18;
    unsigned short unk1A;
    float m_f1C;
    NiColorA9A2 m_kFogTint;

    void SaveBinary(NiStreamA9A2& kStream);
};

// Calls FUN_00a5d7b0, reads m_us18 and m_f1C, then calls m_kFogTint.FUN_00a69780 with kStream.
// @fnv 0x00a9a230
void SaverA9A2::SaveBinary(NiStreamA9A2& kStream)
{
    FUN_00a5d7b0(kStream);
    ReadBinaryValue(kStream, m_us18);
    ReadBinaryValue(kStream, m_f1C);
    m_kFogTint.FUN_00a69780(kStream);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct RefObj : Obj00a9a120
{
    void IncRefCount()
    {
        InterlockedIncrement(&m_ref);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_ref) == 0)
            f1();
    }
};
template <class T> struct PtrRef
{
    T*& m_pObject;
    PtrRef(T*& r) : m_pObject(r)
    {}
    void operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                ((RefObj*)m_pObject)->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                ((RefObj*)m_pObject)->IncRefCount();
        }
    }
};
// Allocates a NiFogProperty and assigns it to DAT_011f5f3c through a reference-counting smart pointer.
// @fnv 0x00a9a090
void FUN_00a9a090()
{
    PtrRef<Obj00a9a120> r(DAT_011f5f3c);
    r = (Obj00a9a120*)new (FUN_00aa13e0(sizeof(NiFogProperty))) NiFogProperty;
}


// src/gamebryo2.2/corelibs/nianimation/bsanimnote.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/bsanimnote.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f00;

// @fnv 0x00a44920
void* __cdecl FUN_00a44920()
{
    return &g_011f3f00;
}

struct TimedTextEntry
{
    float m_fTime;
};

struct BSAnimNote
{
    unsigned char m_b0[12];
    float fTime;
    bool __thiscall FUN_00a44930(const TimedTextEntry* apTextKey);
};

// @fnv 0x00a44930
bool __thiscall BSAnimNote::FUN_00a44930(const TimedTextEntry* apTextKey)
{
    fTime = apTextKey->m_fTime;
    return true;
}

extern int DAT_01097dd4;

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int size);
};

struct _Call_a5d3a0
{
    void __thiscall Init();
};

// Allocates a 0x10-byte BSFadeNode, calls Init on it, sets its vtable to DAT_01097dd4, and returns the pointer or 0.
// @fnv 0x00a44940
void* __cdecl FUN_00a44940()
{
    void* p = BSFadeNode::operator new(0x10);
    if (p)
    {
        _Call_a5d3a0* pFadeNode = (_Call_a5d3a0*)p;
        pFadeNode->Init();
        *(void**)(p) = &DAT_01097dd4;
        return p;
    }
    return 0;
}

struct NiObject;
bool __stdcall IsSameAs(NiObject*);
struct TmpNote
{
    int _a[2];
    int eType;
    float fTime;
    bool __thiscall Matches(NiObject* apObject);
};
// Returns true if apObject passes IsSameAs and its eType and fTime equal this object's eType and fTime.
// @fnv 0x00a44880
bool __thiscall TmpNote::Matches(NiObject* apObject)
{
    if (IsSameAs(apObject))
    {
        if (eType == ((TmpNote*)apObject)->eType)
        {
            if (fTime == ((TmpNote*)apObject)->fTime)
                return true;
        }
    }
    return false;
}

struct NiStream
{
};
struct NiObject
{
    int m_ref;
    virtual void D00()
    {}
    virtual void D01()
    {}
    virtual void D02()
    {}
    virtual void D03()
    {}
    virtual void D04()
    {}
    virtual void D05()
    {}
    virtual void D06()
    {}
    virtual void D07()
    {}
    virtual void D08()
    {}
    virtual void D09()
    {}
    virtual void D10()
    {}
    virtual void D11()
    {}
    virtual void D12()
    {}
    virtual void D13()
    {}
    virtual void D14()
    {}
    virtual void D15()
    {}
    virtual void D16()
    {}
    virtual void D17()
    {}
    virtual void D18()
    {}
    virtual void D19()
    {}
    virtual void D20()
    {}
    virtual bool RegisterStreamables(NiStream&);
};
struct BSAnimNotes : NiObject
{
    NiObject** m_ppNotes;
    unsigned short m_usNumAnimNotes;
    bool __thiscall FUN_00a448c0(NiStream&);
};
// @fnv 0x00a448c0
bool __thiscall BSAnimNotes::FUN_00a448c0(NiStream& arStream)
{
    bool bret = true;
    int i;
    if (!NiObject::RegisterStreamables(arStream))
        bret = false;
    for (i = 0; i < m_usNumAnimNotes && bret; i++)
        bret = m_ppNotes[i]->RegisterStreamables(arStream);
    return bret;
}

struct NiRefObject
{
    virtual ~NiRefObject();
};
struct MemoryManager
{
    void __thiscall Deallocate(void* p);
};
extern MemoryManager g_memoryManager;
struct Holder44970
{
    void* m_00;
    int m_04;
    NiRefObject** m_08;
    unsigned short m_0c;
    void Destroy();
};
// Releases the stored object array: deletes each NiRefObject element, deallocates the array, then destroys the base NiRefObject.
// @fnv 0x00a44970
void Holder44970::Destroy()
{
    m_00 = (void*)&DAT_01097dd4;
    for (unsigned int i = 0; i < m_0c; ++i)
    {
        NiRefObject* p = m_08[i];
        if (p)
            delete p;
    }
    g_memoryManager.Deallocate(m_08);
    ((NiRefObject*)this)->NiRefObject::~NiRefObject();
}

namespace fnv_00a44a10 {
struct BSAnimNotes
{
    unsigned char _pad[16];
    void Destroy();
    void* DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);
// Calls Destroy, then deletes this with size 0x10 when bit 0 of a1 is set, and returns this.
// @fnv 0x00a44a10
void* BSAnimNotes::DestroyIfFlagged(unsigned int auiFlags)
{
    Destroy();
    if (auiFlags & 1)
        _delete(this, 0x10);
    return this;
}
}  // namespace fnv_00a44a10

// FUN_00a84c70 - forwards its single argument to the helper and reports the
// helper's byte sized result as a bool.
//
// Original body (18 bytes):
//   mov eax, dword ptr [esp + 4]
//   push eax
//   call  <helper>
//   test al, al
//   setne al
//   ret 4
//
// The helper is declared here with a byte sized result because the original
// only inspects AL.

extern "C" unsigned char __stdcall MyHelper00a5d2f0(void* pObject);

// @fnv 0x00a84c70
bool __stdcall FUN_00a84c70(void* pObject)
{
    return MyHelper00a5d2f0(pObject);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* plAddend);

class CA449C0Object;

class CA449C0Stream
{
  public:
    CA449C0Object* GetLoadedObject();
};

class CA449C0Object
{
  public:
    virtual ~CA449C0Object();

    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }

    volatile long m_lRefCount;
};

class CA449C0Base
{
  public:
    void LinkObject(CA449C0Stream& kStream);

    int unk00;
    int unk04;
};

class CA449C0Container : public CA449C0Base
{
  public:
    void LinkObjects(CA449C0Stream& kStream);

    CA449C0Object** m_ppkObjects;
    unsigned short m_usNumObjects;
};

// Links the base object from the stream, then fills m_ppkObjects with objects from the stream and increments each one's ref count.
// @fnv 0x00a449c0
void CA449C0Container::LinkObjects(CA449C0Stream& kStream)
{
    CA449C0Base::LinkObject(kStream);
    for (int i = 0; i < m_usNumObjects; i++)
    {
        m_ppkObjects[i] = kStream.GetLoadedObject();
        m_ppkObjects[i]->IncRefCount();
    }
}

// LoadBinary: read the child count, allocate the child pointer array, and read one link id per child.

class A4AF0MemoryManager
{
  public:
    void* Allocate(unsigned int uiSize);
};
extern A4AF0MemoryManager g_kA4AF0MemoryManager;

inline void* __cdecl operator new[](unsigned int uiSize)
{
    return g_kA4AF0MemoryManager.Allocate(uiSize);
}

class A4AF0BinaryStream
{
  public:
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A4AF0BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T> inline void A4AF0LoadBinary(A4AF0BinaryStream& kStream, T& rValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&rValue, sizeof(T), &uiSize, 1);
}

class A4AF0Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    A4AF0BinaryStream* m_pUnderlyingStream;

    void ResetStreamState();
};

class A4AF0Object
{
  public:
    void LoadBinary(A4AF0Stream& kStream);
};

class A4AF0Node : public A4AF0Object
{
  public:
    int unk00;
    int unk04;
    A4AF0Object** m_ppkChildren;
    unsigned short m_usChildCount;

    void FUN_00a44af0(A4AF0Stream& kStream);
};

// @fnv 0x00a44af0
void A4AF0Node::FUN_00a44af0(A4AF0Stream& kStream)
{
    A4AF0Object::LoadBinary(kStream);

    A4AF0LoadBinary(*kStream.m_pUnderlyingStream, m_usChildCount);
    if (m_usChildCount > 0)
        m_ppkChildren = new A4AF0Object*[m_usChildCount];

    for (int i = 0; i < m_usChildCount; i++)
        kStream.ResetStreamState();
}

// GetViewerStrings for an animation note: base strings, the time, and the note type.

class C4BF0StringArray
{
  public:
    virtual ~C4BF0StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

char* __cdecl C4BF0GetViewerString(const char* pcPrefix, float fValue);
char* __cdecl C4BF0GetViewerString(const char* pcPrefix, const char* pcValue);

class C4BF0AnimNote
{
  public:
    int unk00;
    int unk04;
    int m_eRequestType;
    float m_fTime;

    void BaseGetViewerStrings(C4BF0StringArray* pkStrings);
    void FUN_00a44bf0(C4BF0StringArray* pkStrings);
};

// @fnv 0x00a44bf0
void C4BF0AnimNote::FUN_00a44bf0(C4BF0StringArray* pkStrings)
{
    BaseGetViewerStrings(pkStrings);
    pkStrings->Add(C4BF0GetViewerString("Time", m_fTime));
    switch (m_eRequestType)
    {
    case 1:
        pkStrings->Add(C4BF0GetViewerString("Type", "GrabIK"));
        break;
    }
    pkStrings->Add(C4BF0GetViewerString("Type", "AnimNote"));
}

void __cdecl AppendCameraPathEntries();

// @fnv 0x00a44910
void __cdecl FUN_00a44910()
{
    AppendCameraPathEntries();
}

class NiBinaryStreamA44
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_READFN)(NiBinaryStreamA44* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                  unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    virtual ~NiBinaryStreamA44();

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

class NiStreamA44
{
  public:
    virtual ~NiStreamA44();

    unsigned char m_auPad[0x24c];
    NiBinaryStreamA44* m_pUnderlyingStream;
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStreamA44& is, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    is.BinaryRead(pValue, sizeof(T) * uiNumEls, &uiSize, 1);
}

template <class T> inline void ReadBinaryValue(NiStreamA44& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}

class FUN_00a89af0_helper
{
  public:
    void FUN_00a89af0(NiStreamA44& kStream);
};

class LoaderA44 : public FUN_00a89af0_helper
{
  public:
    int m_unk00[2];
    int m_08;
    int m_0C;

    void FUN_00a44a90(NiStreamA44& kStream);
};

// Calls the base class load routine, then reads m_08 and m_0C from the stream.
// @fnv 0x00a44a90
void LoaderA44::FUN_00a44a90(NiStreamA44& kStream)
{
    FUN_00a89af0(kStream);
    ReadBinaryValue(kStream, m_08);
    ReadBinaryValue(kStream, m_0C);
}

class B80BinaryStream
{
  public:
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(B80BinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    unsigned int(__cdecl* m_pfnWrite)(B80BinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                      unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
template <class T> inline void B80SaveBinary(B80BinaryStream& kStream, const T& rValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&rValue, sizeof(T), &uiSize, 1);
}
class B80Stream
{
  public:
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void SaveLinkID(const NiObject* pkObject);
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    B80BinaryStream* m_pBackingStream;
};
class B80Object
{
  public:
    void FUN_00a89af0(B80Stream& kStream);
};
class B80Notes : public B80Object
{
  public:
    int unk00;
    int unk04;
    NiObject** m_ppkNotes;
    unsigned short m_usNumNotes;

    void SaveBinary(B80Stream& kStream);
};
// Saves the B80Notes object by calling the base B80Object save, writing m_usNumNotes, and saving each NiObject link ID in m_ppkNotes.
// @fnv 0x00a44b80
void B80Notes::SaveBinary(B80Stream& kStream)
{
    B80Object::FUN_00a89af0(kStream);
    B80SaveBinary(*kStream.m_pBackingStream, m_usNumNotes);
    for (unsigned int i = 0; i < m_usNumNotes; i++)
        kStream.SaveLinkID(m_ppkNotes[i]);
}

struct BinStream
{
    void* vtable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BinStream* self, void* buffer, unsigned int size, unsigned int* sizes,
                                     unsigned int count);
    unsigned int BinaryRead(void* b, unsigned int sz, unsigned int* sizes, unsigned int n)
    {
        return m_pfnRead(this, b, sz, sizes, n);
    }
};
struct LoadStream
{
    BinStream* GetIstr()
    {
        return *(BinStream**)((char*)this + 0x24c);
    }
};
template <class T> inline void StreamLoadBinary(BinStream& bs, T& val)
{
    unsigned int uiSize = sizeof(T);
    bs.m_uiStreamFlags += bs.BinaryRead(&val, sizeof(T), &uiSize, 1);
}
class LoadObj
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void ReadGroup(LoadStream* s);
    void ReadBinaryFields(LoadStream* s);
};
// Reads a group from the load stream, then binary-reads two unsigned int fields (unk08, unk0C) into the object.
// @fnv 0x00a44a30
void LoadObj::ReadBinaryFields(LoadStream* apLoadStream)
{
    ReadGroup(apLoadStream);
    StreamLoadBinary(*apLoadStream->GetIstr(), unk08);
    StreamLoadBinary(*apLoadStream->GetIstr(), unk0C);
}


// src/havok/common/visualize/hkvisualdebugger.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkvisualdebugger.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cd12b0_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    unsigned int* m_10;
    int m_14;
    void RemovePair(int);
    void FUN_00cd12b0();
};

// Scans the entries from the last index down to 0 and calls RemovePair for each entry whose first word is zero.
// @fnv 0x00cd12b0
void FUN_00cd12b0_cls::FUN_00cd12b0()
{
    for (int i = m_14 - 1; i >= 0; --i)
        if (*(unsigned int*)(&m_10[i * 2]) == 0)
            RemovePair(i);
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int size);
    BSFadeNode();
    ~BSFadeNode();
};
struct FUN_00ccf890_t : BSFadeNode
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00ccf890_t();
    ~FUN_00ccf890_t();
};
// Allocates and constructs a FUN_00ccf890_t object and returns it as a BSFadeNode pointer.
// @fnv 0x00ccf890
BSFadeNode* CreateObject()
{
    return new FUN_00ccf890_t;
}

class hkVisualDebugger;

struct FUN_00cd1e40_target
{
    virtual void FUN_00cd1e40_virtual0() = 0;
    virtual void FUN_00cd1e40_virtual1() = 0;
    virtual void FUN_00cd1e40_virtual2(hkVisualDebugger*, unsigned short) = 0;
};

struct FUN_00cd1e40_router
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    FUN_00cd1e40_target* m_10;
};

FUN_00cd1e40_router* _D1A0E0GetMemoryRouter();

struct hkVisualDebugger
{
    unsigned int m_iWordAt00;
    unsigned short m_iWordAt04;

    void FUN_00cd1970();
    hkVisualDebugger* FUN_00cd1e40(unsigned int flags);
};

// @fnv 0x00cd1e40
hkVisualDebugger* hkVisualDebugger::FUN_00cd1e40(unsigned int flags)
{
    FUN_00cd1970();

    if (flags & 1)
    {
        FUN_00cd1e40_router* router = _D1A0E0GetMemoryRouter();
        router->m_10->FUN_00cd1e40_virtual2(this, m_iWordAt04);
    }

    return this;
}

struct hkErrorCD0D
{
    virtual ~hkErrorCD0D();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void BeginSection(int aiSoundId, const char* pcSectionName) throw();
    virtual void EndSection() throw();
};
extern hkErrorCD0D* DAT_01268360;

struct hkSocketCD0D
{
    virtual ~hkSocketCD0D();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int listen(int iPort);
};
extern hkSocketCD0D*(__cdecl* DAT_011b3df0)();

struct hkOstreamCD0D
{
    int m_iUnk00;
    char* m_pString;
    int m_uiLogicalSize;
    void FUN_00cc00e0() throw();
    hkOstreamCD0D& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamCD0D& WriteInt(int iValue) throw();
};

struct FUN_00cb1600 : hkOstreamCD0D
{
    FUN_00cb1600(char* pcBuffer, int iSize) throw();
};

struct hkVisualDebuggerCD0D : hkVisualDebugger
{
    hkSocketCD0D* m_pkServer;
    void CreateServer(int iListenPort);
};

// Creates the debugger's socket server if absent, listens on iListenPort, and reports the outcome via DAT_01268360->message.
// @fnv 0x00cd0d00
void hkVisualDebuggerCD0D::CreateServer(int iListenPort)
{
    DAT_01268360->BeginSection(0x1293ade8, "Serving");
    if (!m_pkServer)
    {
        m_pkServer = DAT_011b3df0();
        if (m_pkServer)
        {
            m_pkServer->listen(iListenPort);
            unsigned int auiReportBuf[0x80];
            FUN_00cb1600 kReportStream((char*)auiReportBuf, sizeof(auiReportBuf));
            kReportStream.FUN_00cc01c0("Server created and will poll for new client(s) on port ")
                .WriteInt(iListenPort)
                .FUN_00cc01c0(" every frame");
            DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 103);
            kReportStream.FUN_00cc00e0();
        }
        else
        {
            unsigned int auiReportBuf[0x80];
            FUN_00cb1600 kReportStream((char*)auiReportBuf, sizeof(auiReportBuf));
            kReportStream.FUN_00cc01c0(
                "Server could not be created, please check that you platform supports sockets with the hkBase library");
            DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 107);
            kReportStream.FUN_00cc00e0();
        }
    }
    else
    {
        unsigned int auiReportBuf[0x80];
        FUN_00cb1600 kReportStream((char*)auiReportBuf, sizeof(auiReportBuf));
        kReportStream.FUN_00cc01c0(
            "Server has already been created, only one server allowed per visual debugger instance");
        DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 112);
        kReportStream.FUN_00cc00e0();
    }
    DAT_01268360->EndSection();
}

class hkStateCD0E
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual bool isActive();
};

class hkTargetCD0E
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void activate();
};

class hkControllerCD0E
{
  public:
    void FUN_00d60960(int mode);
    void FUN_00d605d0(unsigned int flags);
    void HashUInt(float t);
    hkTargetCD0E* FUN_00d60800();
};

class hkItemCD0E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStateCD0E m_uiContentCount;
    int unk10;
    int unk14;
    hkControllerCD0E* m_controller;
};

struct hkEntryCD0E
{
    int m_key;
    hkItemCD0E* m_item;
};

class hkOwnerCD0E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkEntryCD0E* m_entries;

    void ActivateEntry(int i, float t);
};

// @fnv 0x00cd0e00
void hkOwnerCD0E::ActivateEntry(int aiIndex, float t)
{
    hkEntryCD0E& e = m_entries[aiIndex];
    if (e.m_item->m_uiContentCount.isActive())
    {
        hkControllerCD0E* c = e.m_item->m_controller;
        c->FUN_00d60960(5);
        c->FUN_00d605d0(0);
        c->HashUInt(t);
        c->FUN_00d60800()->activate();
    }
}

template <class T> class hkArrayCD11
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int iIndex)
    {
        m_iElementCount--;
        if (m_iElementCount != iIndex)
            m_data[iIndex] = m_data[m_iElementCount];
    }
};

class hkpEntityCD11;

class hkpEntityTrackerCD11
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
    hkArrayCD11<hkpEntityCD11*> m_kActorEntries;
    hkArrayCD11<void*> m_entityData;

    void FUN_00cd1140(hkpEntityCD11* pkEntity);
};

// Finds pkEntity in the entity array and, if present, removes it and the matching entry from m_entityData.
// @fnv 0x00cd1140
void hkpEntityTrackerCD11::FUN_00cd1140(hkpEntityCD11* pkEntity)
{
    int iIndex = m_kActorEntries.indexOf(pkEntity);
    if (iIndex >= 0)
    {
        m_kActorEntries.removeAt(iIndex);
        m_entityData.removeAt(iIndex);
    }
}

namespace fnv_00cd11a0 {
struct hkErrorCD11
{
    virtual ~hkErrorCD11();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void BeginSection(int aiSoundId, const char* pcSectionName) throw();
    virtual void EndSection() throw();
};
extern hkErrorCD11* DAT_01268360;

struct hkSocketCD11
{
    virtual ~hkSocketCD11();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int listen(int iPort);
};
extern hkSocketCD11*(__cdecl* DAT_011b3df0)();

struct hkOstreamCD11
{
    int m_iUnk00;
    char* m_pString;
    int m_uiLogicalSize;
    void FUN_00cc00e0() throw();
    hkOstreamCD11& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamCD11& WriteInt(int iValue) throw();
};

struct FUN_00cb1600 : hkOstreamCD11
{
    FUN_00cb1600(char* pcBuffer, int iSize) throw();
};

struct hkVisualDebuggerCD11 : hkVisualDebugger
{
    hkSocketCD11* m_pkServer;
    int m_iUnk0c;
    void** m_ppClients;
    int m_iNumClients;
    void ActivateEntry(int iClient, float fUnused);
    void RemovePair(int iClient);
    void FUN_00cd11a0();
};

// @fnv 0x00cd11a0
void hkVisualDebuggerCD11::FUN_00cd11a0()
{
    DAT_01268360->BeginSection(0x1293adef, "Shuting down Visual Debugger..");
    for (int i = m_iNumClients - 1; i >= 0; --i)
    {
        ActivateEntry(i, 0.0f);
        RemovePair(i);
        unsigned int auiReportBuf[0x80];
        FUN_00cb1600 kReportStream((char*)auiReportBuf, sizeof(auiReportBuf));
        kReportStream.FUN_00cc01c0("Client deleted.");
        DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 81);
        kReportStream.FUN_00cc00e0();
    }
    if (m_pkServer)
    {
        delete m_pkServer;
        m_pkServer = 0;
        unsigned int auiReportBuf[0x80];
        FUN_00cb1600 kReportStream((char*)auiReportBuf, sizeof(auiReportBuf));
        kReportStream.FUN_00cc01c0("Server deleted.");
        DAT_01268360->message(0, -1, (char*)auiReportBuf, ".\\hkVisualDebugger.cpp", 88);
        kReportStream.FUN_00cc00e0();
    }
    DAT_01268360->EndSection();
}
}  // namespace fnv_00cd11a0

struct FUN_00cd12e0_element
{
    unsigned int value;
    void FUN_00cb0a60();
    void FUN_00cb0c10();
};
struct FUN_00cd12e0_array
{
    FUN_00cd12e0_element* data;
    unsigned int size;
    unsigned int capacityFlags;
};
struct FUN_00cd12e0_router
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    void* heap;
};
FUN_00cd12e0_router* FUN_00c85750();
void __cdecl ResizeAudioStream(void*, FUN_00cd12e0_array*, int);
struct FUN_00cd12e0_owner
{
    void FUN_00cd12e0();
};
// @fnv 0x00cd12e0
void FUN_00cd12e0_owner::FUN_00cd12e0()
{
    FUN_00cd12e0_array* array = reinterpret_cast<FUN_00cd12e0_array*>(reinterpret_cast<char*>(this) + 0x50);
    FUN_00cd12e0_router* router = FUN_00c85750();
    if (array->size == (array->capacityFlags & 0x3fffffff))
    {
        ResizeAudioStream(router->heap, array, 4);
    }
    FUN_00cd12e0_element* item = array->data + array->size;
    if (item != 0)
    {
        item->FUN_00cb0a60();
    }
    item = array->data + array->size++;
    item->FUN_00cb0c10();
}

namespace fnv_00cd1330 {
void* FUN_00c85750();
void ResizeAudioStream(void*, void*, int);

struct Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;
};

struct Elem
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    T& AllocatePair()
    {
        void* heap = ((Router*)FUN_00c85750())->m_10;
        if (m_iElementCount == (m_iCapacityState & 0x3FFFFFFF))
        {
            ResizeAudioStream(heap, this, sizeof(T));
        }
        return m_data[m_iElementCount++];
    }

    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkBool
{
  public:
    inline hkBool()
    {}
    inline hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }

  private:
    char m_cBooleanValue;
};

typedef void (*CallbackFn)(int, int, hkBool, int, void*);

struct FUN_00cd1330_cls
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

    hkArray<Elem> m_ppData;
    hkArray<CallbackFn> m_kCallbackFunctions;
    hkArray<void*> m_kCallbackUserHandles;

    void AddElementAndNotify(int a1, int a2, int a3, int a4);
};

// @fnv 0x00cd1330
void FUN_00cd1330_cls::AddElementAndNotify(int a1, int a2, int a3, int a4)
{
    Elem& e = m_ppData.AllocatePair();
    e.m_iWordAt00 = a1;
    e.m_iWordAt04 = a2;
    e.m_8 = a4;

    for (int i = 0; i < m_kCallbackFunctions.m_iElementCount; ++i)
    {
        m_kCallbackFunctions[i](a1, a2, true, a4, m_kCallbackUserHandles[i]);
    }
}
}  // namespace fnv_00cd1330

template <int SIZE> __forceinline void memCpyOneAlignedXcd13c0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXcd13c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXcd13c0 {
extern "C" hkMemoryRouterXcd13c0& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayXcd13c0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXcd13c0& router = hkRouterXcd13c0::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXcd13c0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkOwnerXcd13c0
{
  public:
    int unk00[13];
    hkArrayXcd13c0<void*> m_listA;
    hkArrayXcd13c0<void*> m_listB;

    void FUN_00cd13c0(void* a, void* b);
};

// Appends two pointers to the owner's two parallel arrays m_listA and m_listB.
// @fnv 0x00cd13c0
void hkOwnerXcd13c0::FUN_00cd13c0(void* apFirst, void* apSecond)
{
    m_listA.AddBack(apFirst);
    m_listB.AddBack(apSecond);
}

class hkMemoryAllocatorCD17;

struct hkMemoryRouterCD17
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorCD17* m_pStreamAllocator;
    hkMemoryAllocatorCD17& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterCD17& __cdecl FUN_00c85750() throw();
}

struct ItemCD17
{
    char unk00[0x38];
    int m_i38;
    int m_i3C;
};

struct EntryCD17
{
    int unk00;
    ItemCD17* m_pInventoryEntryData;
};

class SinkCD17
{
  public:
    int unk00;
    int m_i04;
    void Search(hkMemoryAllocatorCD17& kAlloc, int iValue, int iA, int iB);
};

class FUN_00cd1710_C
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    EntryCD17* m_pEntries;
    int m_iNumEntries;

    void FUN_00cd1710(SinkCD17* pkSink);
};

// For each entry with inventory data, calls pkSink->Search using m_i04, m_i38, and m_i3C.
// @fnv 0x00cd1710
void FUN_00cd1710_C::FUN_00cd1710(SinkCD17* pkSink)
{
    int iEntryIndex = m_iNumEntries;
    for (int i = 0; i < iEntryIndex; i++)
    {
        EntryCD17& kEntry = m_pEntries[i];
        if (kEntry.m_pInventoryEntryData)
        {
            ItemCD17* pItem = kEntry.m_pInventoryEntryData;
            int iB = pItem->m_i3C;
            int iA = pItem->m_i38;
            int iValue = pkSink->m_i04;
            pkSink->Search(fnvc_adapt::FUN_00c85750().heap(), iValue, iA, iB);
        }
    }
}

class hkMemoryAllocatorC19
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterC19
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorC19* m_pTemp;
    hkMemoryAllocatorC19* m_pStreamAllocator;
    hkMemoryAllocatorC19& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterC19& __cdecl GetMemoryRouterC19() throw();

template <typename T> __forceinline void DestructC19(T* pArr, int n) throw()
{
    for (int i = 0; i < n; i++)
        pArr[i].~T();
}

template <typename T> struct hkArrayC19
{
    __forceinline ~hkArrayC19() throw()
    {
        hkMemoryAllocatorC19& kAlloc = GetMemoryRouterC19().heap();
        DestructC19(m_data, m_iElementCount);
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void clear() throw()
    {
        DestructC19(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkStringPtrC19
{
  public:
    ~hkStringPtrC19() throw();
    const char* m_pcText;
};

class hkReferencedObjectC19
{
  public:
    virtual ~hkReferencedObjectC19() throw()
    {}
    void removeReference() const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkVisualDebuggerC19;
class hkProcessContextC19
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void SetOwnerPointer(hkVisualDebuggerC19* pkOwner) throw();
};

struct hkVisualDebuggerClientC19
{
    void* m_pSocket;
    void* m_pProcessHandler;
};
struct hkVisualDebuggerTrackedObjectC19
{
    void* m_ptr;
    void* m_class;
    unsigned int m_ucOperationType;
};

class FUN_00cd1970 : public hkReferencedObjectC19
{
  public:
    virtual ~FUN_00cd1970() throw();
    void shutdown() throw();

    void* m_pServer;
    unsigned int unk0c;
    hkArrayC19<hkVisualDebuggerClientC19> m_kClients;
    hkArrayC19<hkProcessContextC19*> m_kProcessContexts;
    hkArrayC19<hkVisualDebuggerTrackedObjectC19> m_kTrackedObjects;
    hkArrayC19<void*> m_kTrackCallbacks;
    hkArrayC19<void*> m_kTrackCallbackHandles;
    hkReferencedObjectC19* m_pReferencedObject;
    hkArrayC19<hkStringPtrC19> m_defaultViewers;
};

// Destroys the visual debugger server by shutting it down, detaching process contexts, clearing default viewers, and releasing the referenced object.
// @fnv 0x00cd1970
FUN_00cd1970::~FUN_00cd1970() throw()
{
    shutdown();
    for (int i = 0; i < m_kProcessContexts.GetLogicalSize(); i++)
    {
        m_kProcessContexts[i]->SetOwnerPointer(0);
    }
    m_defaultViewers.clear();
    if (m_pReferencedObject)
    {
        m_pReferencedObject->removeReference();
    }
}

class hkMemoryAllocatorCD1
{
  public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};
struct hkMemoryRouterCD1
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorCD1* m_pTemp;
    hkMemoryAllocatorCD1* m_pStreamAllocator;
    hkMemoryAllocatorCD1& temp()
    {
        return *m_pTemp;
    }
};
hkMemoryRouterCD1& __cdecl GetMemoryRouterCD1() throw();

class hkOstreamCD1
{
  public:
    hkOstreamCD1(void* pvBuffer, int iSize) throw();
    ~hkOstreamCD1() throw();
    hkOstreamCD1& operator<<(const char* pcString) throw();
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};

class hkErrorCD1
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int eType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void BeginSection(int aiSoundId, const char* pcSectionName) throw();
    virtual void EndSection() throw();
};
extern hkErrorCD1* g_pkErrorCD1;

class hkStringBufCD1
{
  public:
    hkStringBufCD1() throw();
    __forceinline ~hkStringBufCD1() throw()
    {
        hkMemoryAllocatorCD1& kAlloc = GetMemoryRouterCD1().temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, m_iCapacityState & 0x3fffffff);
    }
    hkStringBufCD1& operator=(const char* pcString) throw();
    hkStringBufCD1& operator+=(const char* pcString) throw();
    hkStringBufCD1& appendJoin(const char* a, const char* b = 0, const char* c = 0, const char* d = 0,
                               const char* e = 0, const char* f = 0) throw();
    const char* cString() const
    {
        return m_data;
    }
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned int m_kStorage[32];
};

class hkBoolCD1
{
  public:
    hkBoolCD1(bool b) throw()
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    operator bool() const throw()
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkStreamWriterCD1
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual hkBoolCD1 IsStreamValid() const throw();
    void removeReference() const throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkFileSystemCD1
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual hkStreamWriterCD1* OpenWriter(const char* pcName) throw();
};
extern hkFileSystemCD1* g_pkFileSystemCD1;

class hkProcessHandlerCD1
{
  public:
    virtual void v00();
    virtual void v04();
    virtual int getProcessId(const char* pcName) throw();
    virtual void v0c();
    virtual void v10();
    virtual void selectProcess(int aiAllocationTag) throw();
};
class hkServerProcessHandlerCD1
{
  public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkProcessHandlerCD1 m_kProcessHandler;
    int getProcessId(const char* pcName) throw()
    {
        return m_kProcessHandler.getProcessId(pcName);
    }
    void selectProcess(int aiAllocationTag) throw()
    {
        m_kProcessHandler.selectProcess(aiAllocationTag);
    }
};

struct hkVisualDebuggerClientCD1
{
    void* m_pSocket;
    hkServerProcessHandlerCD1* m_pProcessHandler;
};

struct hkStringPtrCD1
{
    const char* cString() const
    {
        return reinterpret_cast<const char*>(reinterpret_cast<unsigned long>(m_pcText) & ~1);
    }
    const char* m_pcText;
};

template <typename T> struct hkArrayCD1
{
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkVisualDebuggerCD1
{
  public:
    virtual void v00();
    void CaptureSimulationState(const char* pcCaptureFilename) throw();
    void AddClient(void* pkSocket, void* pkReader, hkStreamWriterCD1* pkWriter) throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int unk08;
    unsigned int unk0c;
    hkArrayCD1<hkVisualDebuggerClientCD1> m_kClients;
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
    hkArrayCD1<hkStringPtrCD1> m_defaultViewers;
};

// Opens a file writer for pcCaptureFilename, adds it as a client, selects default viewers, and logs the capture status via g_pkErrorCD1.
// @fnv 0x00cd1b20
void hkVisualDebuggerCD1::CaptureSimulationState(const char* pcCaptureFilename) throw()
{
    g_pkErrorCD1->BeginSection(0x1293ade7, "Capturing");

    hkStreamWriterCD1* pkWriter = g_pkFileSystemCD1->OpenWriter(pcCaptureFilename);
    if (pkWriter && pkWriter->IsStreamValid())
    {
        {
            unsigned int reportBuf[128];
            hkOstreamCD1 ostr(reportBuf, sizeof(reportBuf));
            ostr << "Capturing simulation state to '" << pcCaptureFilename << "'";
            g_pkErrorCD1->message(0, -1, (const char*)reportBuf, ".\\hkVisualDebugger.cpp", 125);
        }
        AddClient(0, 0, pkWriter);
        pkWriter->removeReference();

        hkVisualDebuggerClientCD1& kClient = m_kClients[m_kClients.GetLogicalSize() - 1];
        hkStringBufCD1 kViewerNames;
        kViewerNames = "Turning on the following viewers: [";
        for (int i = 0; i < m_defaultViewers.GetLogicalSize(); i++)
        {
            int aiAllocationTag = kClient.m_pProcessHandler->getProcessId(m_defaultViewers[i].cString());
            if (aiAllocationTag >= 0)
            {
                kViewerNames.appendJoin(" ", m_defaultViewers[i].cString());
                kClient.m_pProcessHandler->selectProcess(aiAllocationTag);
            }
        }
        kViewerNames += "]";
        {
            unsigned int reportBuf[128];
            hkOstreamCD1 ostr(reportBuf, sizeof(reportBuf));
            ostr << kViewerNames.cString();
            g_pkErrorCD1->message(0, -1, (const char*)reportBuf, ".\\hkVisualDebugger.cpp", 147);
        }
    }
    else
    {
        unsigned int reportBuf[128];
        hkOstreamCD1 ostr(reportBuf, sizeof(reportBuf));
        ostr << "Capture file '" << pcCaptureFilename << "' could not be opened for writing";
        g_pkErrorCD1->message(0, -1, (const char*)reportBuf, ".\\hkVisualDebugger.cpp", 151);
    }

    g_pkErrorCD1->EndSection();
}

struct hkReferencedObject_cd0e
{
    void removeReference();
};

struct Pair_cd0e
{
    hkReferencedObject_cd0e* m_kPointA;
    hkReferencedObject_cd0e* m_kPointB;
};

inline void memCpy4_cd0e(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_cd0e
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_cd0e(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct Owner_cd0e
{
    int unk00, unk04, unk08, unk0C;
    hkArray_cd0e<Pair_cd0e> m_pairs;
    void RemovePair(int index);
};

// Releases both nonnull references in the indexed pair, then removes that array entry.
// @fnv 0x00cd0e60
void Owner_cd0e::RemovePair(int index)
{
    Pair_cd0e& pair = m_pairs[index];
    if (pair.m_kPointB)
        pair.m_kPointB->removeReference();
    if (pair.m_kPointA)
        pair.m_kPointA->removeReference();
    m_pairs.removeAt(index);
}

struct hkBool836
{
    bool value;
    hkBool836(bool b) : value(b)
    {}
    hkBool836(const hkBool836& b) : value(b.value)
    {}
};
struct Tracked836
{
    void* object;
    const void* pClassInfo;
    unsigned long tag;
};
typedef void(__cdecl* Callback836)(void*, const void*, hkBool836, unsigned long, void*);

inline void memCpy4_836(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray836
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_836(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct Debugger836
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    hkArray836<Tracked836> m_tracked;
    hkArray836<Callback836> m_kCallbackFunctions;
    hkArray836<void*> m_callbackData;
    void UntrackObject(void* object);
};

// Removes object from m_tracked and invokes each callback in m_kCallbackFunctions with a false hkBool836 flag.
// @fnv 0x00cd10a0
void Debugger836::UntrackObject(void* object)
{
    for (int i = 0; i < m_tracked.GetLogicalSize(); i++)
    {
        if (m_tracked[i].object == object)
        {
            m_tracked.removeAt(i);
            for (int j = 0; j < m_kCallbackFunctions.GetLogicalSize(); j++)
                m_kCallbackFunctions[j](object, 0, hkBool836(false), 0, m_callbackData[j]);
            return;
        }
    }
}

struct Heap_cd14
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int nbytes) throw();
};
struct Router_cd14
{
    int unk00, unk04, unk08, unk0C;
    Heap_cd14* m_pStreamAllocator;
    Heap_cd14& heap()
    {
        return *m_pStreamAllocator;
    }
    static Router_cd14& __cdecl FUN_00c85750() throw();
};
void __cdecl FUN_00c908c0(Heap_cd14* heap, void* array, int numElements, int sizeOfElement) throw();
void __cdecl WriteCompilerInfo(void* p) throw();

template <class T> struct hkArray_cd14
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline T& AllocatePair() throw()
    {
        Heap_cd14& heap = Router_cd14::FUN_00c85750().heap();
        int n = m_iElementCount;
        int newSize = n + 1;
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < newSize)
        {
            int cap2 = 2 * cap;
            FUN_00c908c0(&heap, this, newSize < cap2 ? cap2 : newSize, sizeof(T));
        }
        m_iElementCount++;
        return m_data[n];
    }
};

struct Viewer_cd14
{
    virtual void v00();
    virtual void v04();
    virtual int GetValueForType(int type);
    virtual void v0C();
    virtual void enable(int id);
};

struct Process_cd14
{
    int* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    Viewer_cd14 m_viewer;
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
    static void* operator new(unsigned int nbytes) throw()
    {
        Process_cd14* p = (Process_cd14*)Router_cd14::FUN_00c85750().heap().AllocateMemoryBlock(nbytes);
        p->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return p;
    }
    Process_cd14* FUN_00d60f30(void* owner, void* a, void* b) throw();
    void VisitEntryNames() throw();
};

struct Entry_cd14
{
    const char* m_name;
    Process_cd14* m_process;
};

struct Server_cd14
{
    int unk00, unk04, unk08, unk0C;
    hkArray_cd14<Entry_cd14> m_entries;
    int m_pOwnerObject;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int* m_types;
    int m_numTypes;
    void ActivateEntry(int i, float t);
    void AddEntry(const char* name, void* a, void* b);
};

// Allocates a new entry in m_entries, initializes its process with owner and parameters, enables matching viewer types, and activates the entry.
// @fnv 0x00cd1440
void Server_cd14::AddEntry(const char* name, void* a, void* apCompilerInfo)
{
    if (apCompilerInfo)
        WriteCompilerInfo(apCompilerInfo);
    Entry_cd14& e = m_entries.AllocatePair();
    e.m_name = name;
    e.m_process = ((Process_cd14*)Process_cd14::operator new(sizeof(Process_cd14)))
                      ->FUN_00d60f30(&m_pOwnerObject, a, apCompilerInfo);
    e.m_process->VisitEntryNames();
    for (int i = 0; i < m_numTypes; i++)
    {
        int type = m_types[i] & ~1;
        int id = e.m_process->m_viewer.GetValueForType(type);
        if (id >= 0)
            e.m_process->m_viewer.enable(id);
    }
    ActivateEntry(m_entries.m_iElementCount - 1, 0.0f);
}

unsigned __int64 __cdecl FUN_00d60570();

extern const char DAT_010cafd8[];
extern const char DAT_010cae1c[];

struct hkStopwatchCD15
{
    unsigned __int64 m_uiStartTicks;
    unsigned __int64 m_uiTotalElapsedTicks;
    unsigned __int64 m_uiSplitStartTicks;
    unsigned __int64 m_uiSplitElapsedTicks;
    bool m_bIsRunning;
    int m_iStopCount;

    void start()
    {
        m_bIsRunning = true;
        m_uiStartTicks = FUN_00d60570();
        m_uiSplitStartTicks = m_uiStartTicks;
    }
    void stop()
    {
        if (m_bIsRunning)
        {
            m_bIsRunning = false;
            unsigned __int64 ticks_now = FUN_00d60570();
            m_uiTotalElapsedTicks += ticks_now - m_uiStartTicks;
            m_uiSplitElapsedTicks += ticks_now - m_uiSplitStartTicks;
            ++m_iStopCount;
        }
    }
};

struct hkProcessContextCD15
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual char* v28();
};

struct hkVisualDebuggerCD15
{
    int unk00;
    int unk04;
    hkProcessContextCD15* m_iValueAtOffset0C;
    bool m_shutdown;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    bool m_bTimingFrame;
    hkStopwatchCD15 m_kFrameTimer;

    void AddEntry(char* a, char* b, char* c);
    void pollForNewClients();
};

// Stops the timer, reports a message and client data when available, then restarts the timer if frame timing is enabled.
// @fnv 0x00cd1520
void hkVisualDebuggerCD15::pollForNewClients()
{
    if (m_shutdown)
        return;

    if (m_bTimingFrame)
    {
        m_kFrameTimer.stop();
    }

    if (m_iValueAtOffset0C)
    {
        char* client = m_iValueAtOffset0C->v28();
        if (client)
        {
            int szBuffer[0x80];
            FUN_00cb1600 ostr((char*)szBuffer, sizeof(szBuffer));
            ostr.FUN_00cc01c0(DAT_010cafd8);
            DAT_01268360->message(0, -1, (char*)szBuffer, DAT_010cae1c, 0xe8);
            ostr.FUN_00cc00e0();
            AddEntry(client, client + 8, client + 0x14);
        }
    }

    if (m_bTimingFrame)
    {
        m_kFrameTimer.start();
    }
}

class hkMemoryAllocatorC17
{
  public:
    virtual void v00() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
    template <typename T> __forceinline T* _bufAlloc(int& n) throw()
    {
        int iNumBytes = n * sizeof(T);
        void* p = AllocateBufferWithSize(iNumBytes);
        n = iNumBytes / (int)sizeof(T);
        return static_cast<T*>(p);
    }
    template <typename T> __forceinline void _bufFree(void* p, int n) throw()
    {
        ReturnMemory(p, n * sizeof(T));
    }
};
struct hkMemoryRouterC17
{
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorC17* m_pTemp;
    hkMemoryAllocatorC17* m_pStreamAllocator;
    hkMemoryAllocatorC17& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterC17& __cdecl GetMemoryRouterC17() throw();

template <class T> __forceinline void copyC17(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}
template <class T> class hkArrayC17
{
  public:
    hkArrayC17() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrayC17() throw();
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void _copyFromArray(hkMemoryAllocatorC17& alloc, const hkArrayC17& a) throw()
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                alloc._bufFree<T>(m_data, getCapacity());
            int n = a.GetLogicalSize();
            m_data = alloc._bufAlloc<T>(n);
            m_iCapacityState = n;
        }
        m_iElementCount = a.GetLogicalSize();
        copyC17(m_data, a.m_data, m_iElementCount);
    }
    __forceinline hkArrayC17& operator=(const hkArrayC17& a) throw()
    {
        _copyFromArray(GetMemoryRouterC17().heap(), a);
        return *this;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkOstreamC17
{
  public:
    hkOstreamC17(void* pvBuffer, int iSize) throw();
    ~hkOstreamC17() throw();
    hkOstreamC17& operator<<(const char* pcString) throw();
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};
class hkErrorC17
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual int message(int eType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void BeginSection(int aiSoundId, const char* pcSectionName) throw();
    virtual void EndSection() throw();
};
extern hkErrorC17* g_pkErrorC17;

class hkReferencedObjectC17
{
  public:
    hkReferencedObjectC17() throw()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectC17() throw();
    void RetainReference() const;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00cd1780;
class hkProcessContextC17
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void SetOwnerPointer(FUN_00cd1780* pkOwner) throw();
};
class hkVtableClassRegistryC17 : public hkReferencedObjectC17
{
};
struct hkVisualDebuggerClientC17
{
    void* m_pSocket;
    void* m_pProcessHandler;
};
struct hkVisualDebuggerTrackedObjectC17
{
    void* m_ptr;
    void* m_class;
    unsigned int m_ucOperationType;
};
struct hkStringPtrC17
{
    ~hkStringPtrC17() throw();
    const char* m_pcText;
};
class hkStopwatchC17
{
  public:
    hkStopwatchC17(const char* pcName = 0) : m_name(pcName)
    {
        reset();
    }
    void reset()
    {
        m_uiStartTicks = 0;
        m_uiTotalElapsedTicks = 0;
        m_uiSplitStartTicks = 0;
        m_uiSplitElapsedTicks = 0;
        m_bIsRunning = false;
        m_iStopCount = 0;
    }
    unsigned __int64 m_uiStartTicks;
    unsigned __int64 m_uiTotalElapsedTicks;
    unsigned __int64 m_uiSplitStartTicks;
    unsigned __int64 m_uiSplitElapsedTicks;
    bool m_bIsRunning;
    int m_iStopCount;
    const char* m_name;
};

void __cdecl hkVisualDebuggerInitFactoryC17() throw();

class FUN_00cd1780 : public hkReferencedObjectC17
{
  public:
    FUN_00cd1780(const hkArrayC17<hkProcessContextC17*>& kContexts, const hkVtableClassRegistryC17* pkClassReg) throw();
    virtual ~FUN_00cd1780() throw();
    void addDefaultProcess(const char* pcName) throw();

    void* m_pServer;
    bool m_bTimingFrame;
    hkArrayC17<hkVisualDebuggerClientC17> m_kClients;
    hkArrayC17<hkProcessContextC17*> m_kProcessContexts;
    hkArrayC17<hkVisualDebuggerTrackedObjectC17> m_kTrackedObjects;
    hkArrayC17<void*> m_kTrackCallbacks;
    hkArrayC17<void*> m_kTrackCallbackHandles;
    const hkVtableClassRegistryC17* m_pReferencedObject;
    hkArrayC17<hkStringPtrC17> m_defaultViewers;
    bool m_overrideFrameTimeIfZero;
    hkStopwatchC17 m_kFrameTimer;
};

// @fnv 0x00cd1780
FUN_00cd1780::FUN_00cd1780(const hkArrayC17<hkProcessContextC17*>& kContexts,
                           const hkVtableClassRegistryC17* pkClassReg) throw()
    : m_pServer(0), m_bTimingFrame(false), m_pReferencedObject(pkClassReg), m_overrideFrameTimeIfZero(false),
      m_kFrameTimer("Frame Timer")
{
    m_kProcessContexts = kContexts;
    for (int i = 0; i < m_kProcessContexts.GetLogicalSize(); i++)
        m_kProcessContexts[i]->SetOwnerPointer(this);

    g_pkErrorC17->BeginSection(0x1293adef, "Visual Debugger");
    {
        unsigned int reportBuf[128];
        hkOstreamC17 ostr(reportBuf, sizeof(reportBuf));
        ostr << "VDB Server instance has been created";
        g_pkErrorC17->message(0, -1, (const char*)reportBuf, ".\\hkVisualDebugger.cpp", 0x28);
    }
    hkVisualDebuggerInitFactoryC17();
    addDefaultProcess("Debug Display");
    addDefaultProcess("Shapes");
    addDefaultProcess("MousePicking");
    if (m_pReferencedObject)
        m_pReferencedObject->RetainReference();
    g_pkErrorC17->EndSection();
}

namespace fnv_00cd1610 {
struct DefaultProcessSlot
{
    unsigned int taggedPtr;
    void FUN_00cb0c00();
};
extern "C" int __cdecl FUN_00cb0fa0(unsigned int taggedObject, unsigned int wanted);
struct ErrorMessage
{
    void* m_pHeadNode;
    void* m_iSecondInteger;
    unsigned int m_fRestLength;
    unsigned int storage[128];
    void FUN_00cb1600(char* destination, unsigned int capacity);
    ErrorMessage* FUN_00cc01c0(const char* text);
    void FUN_00cc00e0();
};
struct ErrorService
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03(int category, int severity, const char* message, const char* filename, int line);
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07(unsigned int key, const char* tag);
    virtual void V08();
};
extern "C" ErrorService* DAT_01268360;
struct FUN_00cd1610_cls
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
    DefaultProcessSlot* m_processes;
    int m_uiItemCount;
    void FUN_00cd1610(unsigned int wanted);
};
// Removes the process slot matching wanted from m_processes, or logs an error via DAT_01268360 if it is not found.
// @fnv 0x00cd1610
void FUN_00cd1610_cls::FUN_00cd1610(unsigned int wanted)
{
    for (int i = 0; i < m_uiItemCount; ++i)
    {
        unsigned int current = m_processes[i].taggedPtr;
        if (FUN_00cb0fa0(current & ~1u, wanted) == 0)
        {
            m_processes[i].FUN_00cb0c00();
            --m_uiItemCount;
            if (m_uiItemCount != i)
            {
                DefaultProcessSlot& slotLast = m_processes[m_uiItemCount];
                m_processes[i] = slotLast;
            }
            return;
        }
    }
    DAT_01268360->V07(0x76565454, "removeDefaultProcess");
    ErrorMessage message;
    message.FUN_00cb1600((char*)message.storage, 512);
    message.FUN_00cc01c0("The default Process'")
        ->FUN_00cc01c0((const char*)wanted)
        ->FUN_00cc01c0("', cannot not be removed from the default process list as it cannot be found!");
    DAT_01268360->V03(0, -1, (char*)message.storage, ".\\hkVisualDebugger.cpp", 318);
    message.FUN_00cc00e0();
    DAT_01268360->V08();
}
}  // namespace fnv_00cd1610

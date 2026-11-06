
// src/havok/common/visualize/hkvisualdebugger_decl_variant_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/visualize/hkvisualdebugger_decl_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/visualize/hkvisualdebugger_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00cd0ec0: the skeleton of src/havok/common/visualize/hkvisualdebugger.cpp
// with declarations corrected to what the original code does (unit: extern hkErrorCD0D* DAT_01268360; -> ; unit: struct FUN_00cb1600 : hkOstreamCD0D { FUN_00cb1600(char* -> ). Move the function to its real unit once
// that unit declares it this way.
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
BSFadeNode* CreateObject();
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
struct hkVisualDebuggerCD0D : hkVisualDebugger
{
    hkSocketCD0D* m_pkServer;
    void CreateServer(int iListenPort);
};
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

#include <math.h>
typedef unsigned __int64 TickCount;
TickCount __cdecl FUN_00d60570();
TickCount __cdecl FUN_00d60580();
double __cdecl DivideInt64ToFloat(TickCount, TickCount);
extern float DAT_0104da4c;
extern const char DAT_010caf8c[];
extern const char DAT_010caf48[];
extern const char DAT_010cae1c[];
struct DebugReport
{
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void report(int, int, const char*, const char*, int);
    virtual void unknown10();
    virtual void unknown14();
    virtual void unknown18();
    virtual void begin(unsigned int, const char*);
    virtual void end();
};
extern DebugReport* DAT_01268360;
// ABI aliases: hkOstream has a nontrivial virtual destructor; hkErrStream
// constructs its buffer writer and inherits that destruction contract.
struct FUN_00cc00e0
{
    virtual ~FUN_00cc00e0();
    unsigned short memorySize, referenceCount;
    void* writer;
};
struct FUN_00cb1600 : FUN_00cc00e0
{
    FUN_00cb1600(void*, int);
    void FUN_00cc01c0(const char*);
};
struct ClientProcess
{
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual bool alive();
    virtual void unknown14();
    virtual void step(float);
};
struct ClientHandler
{
    unsigned int unk00, unk04, unk08;
    ClientProcess process;
};
struct DebugClient
{
    void* connection;
    ClientHandler* handler;
};
struct DebuggerReference523
{
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual void unknown0c();
    virtual void prepareStep();
    unsigned short memorySize, referenceCount;
};
struct VisualDebugger523 : DebuggerReference523
{
    unsigned int unk08, unk0c;
    DebugClient* clients;
    int numClients;
    unsigned int unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58;
    bool timingEnabled;
    unsigned char unk5d, unk5e, unk5f;
    TickCount startTime, totalTime, frameStart, frameTotal;
    bool running;
    unsigned char unk81, unk82, unk83;
    int numFrames;
    void ActivateEntry(int, float);
    void RemovePair(int);
    void FUN_00cd0ec0(float timeStep);
};
// @fnv 0x00cd0ec0
void VisualDebugger523::FUN_00cd0ec0(float timeStep)
{
    float stepTime = 16.0f;
    if (timingEnabled)
    {
        TickCount elapsed = totalTime;
        if (running)
            elapsed += FUN_00d60570() - startTime;
        stepTime = (float)(DivideInt64ToFloat(elapsed, FUN_00d60580()) * 1000.0);
        running = false;
        TickCount now = FUN_00d60570();
        totalTime += now - startTime;
        frameTotal += now - frameStart;
        ++numFrames;
    }
    timingEnabled = true;
    float magnitude = (float)fabs(timeStep);
    if (magnitude > 1.1920928955078125e-7f)
        stepTime = timeStep;
    prepareStep();
    for (int index = numClients - 1; index >= 0; --index)
    {
        DebugClient* client = &clients[index];
        if (client->handler->process.alive())
        {
            client->handler->process.step(stepTime);
            ActivateEntry(index, stepTime);
        }
        ClientHandler* handler = client->handler;
        if (!handler->process.alive())
        {
            DAT_01268360->begin(0x76e3a642, DAT_010caf8c);
            {
                char buffer[512];
                FUN_00cb1600 stream(buffer, 512);
                stream.FUN_00cc01c0(DAT_010caf48);
                DAT_01268360->report(0, -1, buffer, DAT_010cae1c, 0x120);
            }
            DAT_01268360->end();
            RemovePair(index);
        }
    }
    if (timingEnabled)
    {
        startTime = 0;
        totalTime = 0;
        frameStart = 0;
        frameTotal = 0;
        numFrames = 0;
        running = true;
        TickCount now = FUN_00d60570();
        startTime = now;
        frameStart = startTime;
    }
}

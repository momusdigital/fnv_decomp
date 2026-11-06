
// src/havok/common/base/system/io/socket/bsd/hkbsdsocket_gs_nogs_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/common/base/system/io/socket/bsd/hkbsdsocket.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/system/io/socket/bsd/hkbsdsocket.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/socket/bsd/hkbsdsocket.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __stdcall closesocket(int);
struct FUN_00da2dc0_class
{
    int m_kPointA;                // +0x00
    int m_kPointB;                // +0x04
    int m_iThirdValue;                // +0x08
    int m_iFourthElementInteger;                // +0x0c
    int m_usTrailingValue;  // +0x10
    int m_f;                // +0x14
    int m_g;                // +0x18
    int m_h;                // +0x1c
    int m_pSocket;          // +0x20
    void CloseSocket();
};
extern int DAT_0102e388;
extern int DAT_010d5030;
struct hkBsdSocket
{
    void __thiscall CloseSocket();
    void __thiscall Destroy();
};
extern "C" void __cdecl FUN_00d2b850(void);
extern "C" void __cdecl FUN_00da2de0(void*);
extern int DAT_010d5030;
struct FUN_00da30a0_cls
{
    void* m_vft;
    char m_auiShapeKeys[28];
    int m_field_0x20;
    void FUN_00da2de0();
    void* __thiscall InitWithParam(int param);
};
struct FUN_00da2db0_cls
{
    char m_auiShapeKeys[0x20];
    int m_pSocket;
    bool* __thiscall FUN_00da2db0(bool* pOut);
};
extern "C" int __stdcall FUN_00ee6d5c(int, int, int, int);
extern "C" int __cdecl FUN_00ee6d50(void);
struct FUN_00da2e60_cls
{
    void* m_vft;  // +0x00
    char m_auiShapeKeys[0x1c];
    int m_pSocket;  // +0x20
    int write(int, int);
};
int __stdcall FUN_00ee6d4a(int, int, int);
struct FUN_00da2de0_class
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();

    char m_auiShapeKeys[0x1c];
    int m_pSocket;

    int FUN_00da2de0();
};
struct FUN_00da2f90_cls
{
    char m_auiShapeKeys[0x20];
    int m_pSocket;
    bool asyncSelect(int a, int b, int c);
};
extern "C" int __stdcall FUN_00ee6d7a(int, int, int, int);
// FUN_00ee6d9e: 6-byte 'jmp [IAT]' forwarder to WSOCK32 ordinal 21 (setsockopt, stdcall, 5 args).
extern "C" __declspec(dllimport) int __stdcall setsockopt(unsigned int s, int level, int optname, const char* optval,
                                                          int optlen);
int __stdcall FUN_00ee6d9e(unsigned int s, int level, int optname, const char* optval, int optlen);
extern "C" int __stdcall FUN_00ee6d56(int, void*, int, int);
extern "C" int __cdecl FUN_00ee6d50(void);
struct FUN_00da2e10_cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_pSocket;

    int Read(void* buf, int len);
};
struct FUN_00cbbd40_router
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int, int);
};
struct FUN_00cbbd40_holder
{
    int unk0;
    int unk4;
    int unk8;
    FUN_00cbbd40_router* unkC;
};
extern "C" FUN_00cbbd40_holder* __cdecl FUN_00c85750(void);
struct FUN_00cbbd40_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void FUN_00cbbd40();
};
extern "C" int __stdcall FUN_00ee6d80(unsigned int s, long lCmd, unsigned long* pulArg);
class SocketDA2F
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
    unsigned int m_uiSocket;

    bool __thiscall SetNonBlocking(bool m_bCombatItemSearchActive);
};
extern char DAT_01269acc;
extern const char str_010d5004[];
extern const char str_010d4fdc[];
int __stdcall FUN_00ee6d86(unsigned short, void*);
struct S00da2ff0_Msg
{
    int unk00;
    int unk04;
    int unk08;
    void __thiscall Init(void*, int);
    void __thiscall Done();
    void __thiscall Add(const char*);
};
struct S00da2ff0_Err
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int, int, void*, const char*, int);
};
extern S00da2ff0_Err* DAT_01268360;
void InitWinsock();

namespace fnv_00da3230 {
struct fd_setD32
{
    unsigned int fd_count;
    unsigned int fd_array[64];
};
struct timevalD32
{
    long tv_sec;
    long tv_usec;
};
struct sockaddr_inD32
{
    short sin_family;
    unsigned short sin_port;
    unsigned int sin_addr;
    char sin_zero[8];
};

extern "C" int __stdcall FUN_00ee6dbc(int nfds, fd_setD32* pRead, fd_setD32* pWrite, fd_setD32* pExcept,
                                      const timevalD32* pTimeout);
extern "C" int __stdcall FUN_00ee6db6(unsigned int s, fd_setD32* pSet);
extern "C" unsigned int __stdcall FUN_00ee6db0(unsigned int s, sockaddr_inD32* pAddr, int* pAddrLen);
extern "C" unsigned short __stdcall FUN_00ee6daa(unsigned short usNet);
extern "C" char* __stdcall FUN_00ee6da4(unsigned int uiAddr);

struct StrBufD32
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    char m_kStorage[0x80];

    void InitBuffer();
    void FUN_00cbbd40();
};
void __cdecl FUN_00d61d00(StrBufD32* pBuf, const char* pcFmt, ...);

struct OstreamD32
{
    int unk00;
    int unk04;
    int unk08;

    void FUN_00cb1600(char* pcBuf, int iSize);
    OstreamD32& InvokeFromRequest(const StrBufD32& kStr);
    void FUN_00cc00e0();
};

struct ErrorD32
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual int message(int eType, int aiSoundId, const char* pcDesc, const char* pcFile, int iLine);
};
extern ErrorD32* DAT_01268360;

struct AllocD32
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
};
struct RouterD32
{
    int unk00, unk04, unk08, unk0C;
    AllocD32* m_pStreamAllocator;

    AllocD32& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD32 {
extern "C" RouterD32& __cdecl FUN_00c85750() throw();
}

struct SockD32
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    unsigned int m_pSocket;

    void* pollForNewClient();
};

// @fnv 0x00da3230
void* SockD32::pollForNewClient()
{
    if (m_pSocket != -1)
    {
        fd_setD32 readFds;
        (((fd_setD32*)(&readFds))->fd_count = 0);
        do
        {
            unsigned int __i;
            for (__i = 0; __i < ((fd_setD32*)(&readFds))->fd_count; __i++)
            {
                if (((fd_setD32*)(&readFds))->fd_array[__i] == (m_pSocket))
                {
                    break;
                }
            }
            if (__i == ((fd_setD32*)(&readFds))->fd_count)
            {
                if (((fd_setD32*)(&readFds))->fd_count < 64)
                {
                    ((fd_setD32*)(&readFds))->fd_array[__i] = (m_pSocket);
                    ((fd_setD32*)(&readFds))->fd_count++;
                }
            }
        } while (0, 0);
        fd_setD32 exceptFds;
        (((fd_setD32*)(&exceptFds))->fd_count = 0);
        do
        {
            unsigned int __i;
            for (__i = 0; __i < ((fd_setD32*)(&exceptFds))->fd_count; __i++)
            {
                if (((fd_setD32*)(&exceptFds))->fd_array[__i] == (m_pSocket))
                {
                    break;
                }
            }
            if (__i == ((fd_setD32*)(&exceptFds))->fd_count)
            {
                if (((fd_setD32*)(&exceptFds))->fd_count < 64)
                {
                    ((fd_setD32*)(&exceptFds))->fd_array[__i] = (m_pSocket);
                    ((fd_setD32*)(&exceptFds))->fd_count++;
                }
            }
        } while (0, 0);
        timevalD32 t;
        t.tv_sec = 0;
        t.tv_usec = 0;
        int nfds = int(m_pSocket);
        nfds++;
        int numHits = FUN_00ee6dbc(nfds, &readFds, 0, &exceptFds, &t);
        if ((numHits > 0) && FUN_00ee6db6(m_pSocket, &readFds))
        {
            sockaddr_inD32 from;
            int iFromLen = sizeof(from);
            unsigned int s = FUN_00ee6db0(m_pSocket, &from, &iFromLen);
            StrBufD32 kMsg;
            kMsg.InitBuffer();
            FUN_00d61d00(&kMsg, "Socket got connection from [%s:%d]\n", FUN_00ee6da4(from.sin_addr),
                         FUN_00ee6daa(from.sin_port));
            {
                char acBuf[512];
                OstreamD32 kOstr;
                kOstr.FUN_00cb1600(acBuf, sizeof(acBuf));
                kOstr.InvokeFromRequest(kMsg);
                DAT_01268360->message(0, -1, acBuf, ".\\System\\Io\\Socket\\Bsd\\hkBsdSocket.cpp", 0x193);
                kOstr.FUN_00cc00e0();
            }
            if (s == -1)
            {
                kMsg.FUN_00cbbd40();
                return 0;
            }
            int iNoDelay = 1;
            FUN_00ee6d9e(s, 6, 1, (const char*)&iNoDelay, 4);
            void* p = hkRouterD32::FUN_00c85750().heap().AllocateMemoryBlock(0x24);
            ((unsigned short*)p)[2] = 0x24;
            void* pkSocket = ((FUN_00da30a0_cls*)p)->InitWithParam(s);
            kMsg.FUN_00cbbd40();
            return pkSocket;
        }
    }
    return 0;
}
}  // namespace fnv_00da3230

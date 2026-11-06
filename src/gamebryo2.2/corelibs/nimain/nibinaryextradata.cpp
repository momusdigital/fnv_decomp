
// src/gamebryo2.2/corelibs/nimain/nibinaryextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nibinaryextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiExtraData
{
    void FUN_00a7b2e0();
};

struct BSFadeNode
{
    static void* operator new(unsigned int size);
};

extern int DAT_0102e394;

// @fnv 0x00a7f8e0
void* __cdecl FUN_00a7f8e0()
{
    void* p = BSFadeNode::operator new(0x14);
    if (p)
    {
        ((NiExtraData*)p)->FUN_00a7b2e0();
        *reinterpret_cast<void**>(p) = &DAT_0102e394;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0x10) = 0;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(p) + 0xc) = 0;
        return p;
    }
    return 0;
}

class NiStream;

struct NiBinaryStreamStandIn
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(NiBinaryStreamStandIn* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    unsigned int BinaryRead(void* buffer, unsigned int totalBytes, unsigned int* componentSizes,
                            unsigned int componentCount)
    {
        unsigned int bytesRead = read(this, buffer, totalBytes, componentSizes, componentCount);
        absolutePosition += bytesRead;
        return bytesRead;
    }
    template <class T> unsigned int Read(T* value)
    {
        unsigned int size = sizeof(T);
        return BinaryRead(value, sizeof(T), &size, 1);
    }
    template <class T> unsigned int Read(T* array, unsigned int count)
    {
        unsigned int size = sizeof(T);
        return BinaryRead(array, sizeof(T) * count, &size, 1);
    }
};

class NiStream
{
  public:
    char pad[0x24c];
    NiBinaryStreamStandIn* istr;
};

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.istr->Read(&value);
}

template <class T> inline void ReadBinaryValue(NiStream& stream, T* array, unsigned int count)
{
    stream.istr->Read(array, count);
}

void* NiMalloc(unsigned int size);

struct NiBinaryExtraData : NiExtraData
{
    int unk00;
    int unk04;
    int unk08;
    char* m_pData;
    unsigned int m_uiSize;
    void FUN_00a7b4a0(NiStream& stream);
    void LoadBinary(NiStream& stream);
};

// Calls FUN_00a7b4a0, reads m_uiSize from the stream, and if nonzero allocates m_pData and reads m_uiSize bytes into it.
// @fnv 0x00a7f9a0
void NiBinaryExtraData::LoadBinary(NiStream& stream)
{
    FUN_00a7b4a0(stream);
    ReadBinaryValue(stream, m_uiSize);
    if (m_uiSize <= 0)
        return;
    m_pData = (char*)NiMalloc(m_uiSize);
    ReadBinaryValue(stream, m_pData, m_uiSize);
}

namespace fnv_00a7fa20 {
// FUN_00a7fa20 - NiBinaryExtraData::SaveBinary (vtable slot 22 of
// NiBinaryExtraData, overriding NiExtraData::SaveBinary).
//
//   this  : the extra-data object
//          +0x0c : the payload pointer
//          +0x10 : the payload size
//   param : the stream; the node list pointer lives at +0x250 of it
//
// The node exposes a callback at +0x0c.  It is called twice: once to
// register the object (4 bytes) and once - when the size at +0x10 of the
// extra-data object is non-zero - to write the payload.  Both calls take
// a pointer to an out-flag that is set to 4 and to 1 respectively; the
// flag lives in the (dead) incoming argument slot of this frame.

struct FadeNode
{
    int unk00;
    int unk04;  // accumulated callback result
    int unk08;
    int (*unk0c)(FadeNode* node, void* arg2, unsigned int arg3, int* arg4, int arg5);
};

struct NiStreamLike
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    FadeNode* unk250;  // the node list
};

struct NiBinaryExtraData
{
    void* unk00;  // vptr
    int unk04;
    void* unk08;
    void* unk0c;         // the payload pointer
    unsigned int unk10;  // the payload size
    void FUN_00a7b2c0(NiStreamLike* s);
    void FUN_00a7fa20(NiStreamLike* s);
};

// @fnv 0x00a7fa20
void NiBinaryExtraData::FUN_00a7fa20(NiStreamLike* apStream)
{
    this->FUN_00a7b2c0(apStream);
    FadeNode* node = apStream->unk250;
    {
        int flag = 4;
        node->unk04 += node->unk0c(node, &this->unk10, 4, &flag, 1);
    }
    unsigned int count = this->unk10;
    if (count > 0)
    {
        FadeNode* node = apStream->unk250;
        void* data = this->unk0c;
        {
            int flag = 1;
            node->unk04 += node->unk0c(node, data, count, &flag, 1);
        }
    }
}
}  // namespace fnv_00a7fa20

struct FUN_00a7fa90_obj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_w08;
    unsigned short m_w0A;
    unsigned short unk0C;
    unsigned short m_w0E;
    void FUN_0096ad30(unsigned int a);
    void FUN_0096ae90(unsigned int a, void** out);
};

struct FUN_00a7fa90_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    void* m_p10;
    void FUN_00a7b580(FUN_00a7fa90_obj* s);
    void GetViewerStrings(FUN_00a7fa90_obj* s);
};

extern unsigned int DAT_011f4ab8;
extern char str_0109df4c[];
void* __cdecl FUN_00a7d330(unsigned int v);
void* __cdecl FUN_00a7d510(const char* fmt, void* v);

// @fnv 0x00a7fa90
void FUN_00a7fa90_cls::GetViewerStrings(FUN_00a7fa90_obj* pObj)
{
    FUN_00a7b580(pObj);
    void* r = FUN_00a7d330(DAT_011f4ab8);
    unsigned int a = pObj->m_w0A;
    if (a >= pObj->m_w08)
    {
        pObj->FUN_0096ad30(a + pObj->m_w0E);
    }
    pObj->FUN_0096ae90(a, &r);
    r = FUN_00a7d510(str_0109df4c, m_p10);
    a = pObj->m_w0A;
    if (a >= pObj->m_w08)
    {
        pObj->FUN_0096ad30(a + pObj->m_w0E);
    }
    pObj->FUN_0096ae90(a, &r);
}

struct FUN_00cb9c70_cls
{
    bool Check(int);
};
struct FUN_00a89ae0_shell
{
    bool FUN_00a89ae0(int);
};
// @fnv 0x00a89ae0
bool FUN_00a89ae0_shell::FUN_00a89ae0(int a)
{
    return ((FUN_00cb9c70_cls*)this)->Check(a);
}

extern void __cdecl FUN_00a7b3b0();
// @fnv 0x00a9af00
void __cdecl FUN_00a9af00()
{
    FUN_00a7b3b0();
}

#include <string.h>
struct A7F870BinaryData
{
    int unk00;
    int unk04;
    int unk08;
    char* m_pByteBuffer;
    unsigned int m_uiSize;

    bool IsEqual(const A7F870BinaryData* pkOther) const;
};

// Returns true when pkOther is non-null, has the same m_uiSize, and its m_pByteBuffer matches this one via memcmp.
// @fnv 0x00a7f870
bool A7F870BinaryData::IsEqual(const A7F870BinaryData* pkOther) const
{
    if (!pkOther)
        return false;
    if (m_uiSize != pkOther->m_uiSize)
        return false;
    if (memcmp(m_pByteBuffer, pkOther->m_pByteBuffer, m_uiSize) != 0)
        return false;
    return true;
}

struct CloningProcess;

extern void* __cdecl NiMalloc(unsigned int stSize);

class A7F920ExtraData
{
  public:
    static void* operator new(unsigned int stSize);
    static void operator delete(void* p);

    __declspec(nothrow) A7F920ExtraData();
    virtual void vfunc00();

    void CopyMemberData(A7F920ExtraData* pkDest, CloningProcess& kCloning);

    int m_uiRefCount;
    int m_kName;
};

class A7F920BinaryExtraData : public A7F920ExtraData
{
  public:
    A7F920BinaryExtraData()
    {
        m_uiSize = 0;
        m_pByteBuffer = 0;
    }
    virtual void vfunc00();

    A7F920ExtraData* CreateClone(CloningProcess& kCloning);

    char* m_pByteBuffer;
    unsigned int m_uiSize;
};

// Creates a new A7F920BinaryExtraData, copies member data, and duplicates the byte buffer when m_uiSize is non-zero.
// @fnv 0x00a7f920
A7F920ExtraData* A7F920BinaryExtraData::CreateClone(CloningProcess& kCloning)
{
    A7F920BinaryExtraData* pkClone = new A7F920BinaryExtraData;
    CopyMemberData(pkClone, kCloning);
    if (m_uiSize > 0)
    {
        pkClone->m_pByteBuffer = (char*)NiMalloc(m_uiSize);
        memmove(pkClone->m_pByteBuffer, m_pByteBuffer, m_uiSize);
        pkClone->m_uiSize = m_uiSize;
    }
    else
    {
        pkClone->m_uiSize = 0;
        pkClone->m_pByteBuffer = 0;
    }
    return pkClone;
}


// src/gamebryo2.2/corelibs/nimain/nistringextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nistringextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class NiStream
{
  public:
    void SerializeString(const char* str);
};

class NiExtraData
{
  public:
    void SaveBinary(NiStream& stream);
};

class NiStringExtraData : public NiExtraData
{
  public:
    char m_kStringBuffer[1];
    void FUN_00a74200(NiStream& stream);
};

// @fnv 0x00a74200
void NiStringExtraData::FUN_00a74200(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    stream.SerializeString(m_kStringBuffer + 0xc);
}

extern "C" void* DAT_011f4a38;

// Returns the address of the global DAT_011f4a38.
// @fnv 0x00a74220
void* __cdecl FUN_00a74220()
{
    return &DAT_011f4a38;
}

struct NiExtraDataHelper
{
    void FUN_00a7b2e0();
};
struct BSFadeNode
{
    void* operator new(unsigned int);
};
extern "C" int EmptyFS;
extern "C" void* DAT_0109d39c;
// @fnv 0x00a74230
void* __cdecl FUN_00a74230()
{
    void* p = BSFadeNode::operator new(0x10);
    if (p)
    {
        ((NiExtraDataHelper*)p)->FUN_00a7b2e0();
        *(void**)p = &DAT_0109d39c;
        *(int*)((char*)p + 0xc) = EmptyFS;
        return p;
    }
    return 0;
}

namespace fnv_00a74260 {
struct NiFixedString
{
    char m_kStringBuffer[1];
};
struct NiStreamHelper
{
    void ReadFixedString(NiFixedString&);
    void ReadStringTableEntry(NiFixedString&);
};
struct NiExtraDataHelper
{
    void LoadBinary(NiStream&);
};
struct NiStringExtraDataShell : NiStringExtraData
{
    void FUN_00a74260(NiStream& stream);
};
// @fnv 0x00a74260
void NiStringExtraDataShell::FUN_00a74260(NiStream& stream)
{
    ((NiExtraDataHelper*)this)->LoadBinary(stream);
    if (*(unsigned int*)((char*)&stream + 0xd8) < 0x14010001)
        ((NiStreamHelper*)&stream)->ReadFixedString(*(NiFixedString*)((char*)this + 0xc));
    else
        ((NiStreamHelper*)&stream)->ReadStringTableEntry(*(NiFixedString*)((char*)this + 0xc));
}
}  // namespace fnv_00a74260

struct FUN_00a7b290_shell
{
    bool FUN_00a7b290(NiStream&);
};
struct VHack
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(const char*);
};
struct FUN_00a741d0_shell : NiStringExtraData
{
    bool LoadStringExtraData(NiStream&);
};
// @fnv 0x00a741d0
bool FUN_00a741d0_shell::LoadStringExtraData(NiStream& stream)
{
    if (!((FUN_00a7b290_shell*)this)->FUN_00a7b290(stream))
        return false;
    ((VHack*)&stream)->v8((char*)this + 12);
    return true;
}

struct S_00a742a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    unsigned char Equals(S_00a742a0* pOther);
};

// @fnv 0x00a742a0
unsigned char S_00a742a0::Equals(S_00a742a0* pOther)
{
    if (pOther == 0)
    {
        return 0;
    }

    return this->unk0c == pOther->unk0c;
}

extern "C" void* DAT_0109d39c;
extern "C" void* DAT_0109b220;
extern "C" __declspec(dllimport) void __stdcall FUN_00fdf1c4_import(void* apMemory);
void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00a742c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    char* m_pData;

    void FUN_00a7b300();

    FUN_00a742c0_cls* Destroy(unsigned int acFlags);
};

// Resets the vtable pointer, frees the data buffer if it is not the default, calls FUN_00a7b300, and optionally deallocates the object.
// @fnv 0x00a742c0
FUN_00a742c0_cls* FUN_00a742c0_cls::Destroy(unsigned int acFlags)
{
    *(volatile int*)&unk00 = (int)&DAT_0109d39c;
    char* pData = *(char* volatile*)&m_pData;
    if (pData != (char*)DAT_0109b220)
    {
        FUN_00fdf1c4_import(pData - 8);
    }
    FUN_00a7b300();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x10);
    }
    return this;
}

namespace fnv_00a74300 {
extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
extern "C" char* DAT_0109b220;
extern "C" void* DAT_0109d39c;
extern "C" void(__stdcall* DAT_00fdf1c0)(void*);
extern "C" void(__stdcall* DAT_00fdf1c4)(void*);

struct FUN_00a74300_cls
{
    void* vptr;
    int unk04;
    int unk08;
    char* m_0c;

    void* CreateCopy(int arg);
    void FUN_00a7b330(FUN_00a74300_cls* obj, int arg);
};

// @fnv 0x00a74300
void* FUN_00a74300_cls::CreateCopy(int arg)
{
    FUN_00a74300_cls* esi = (FUN_00a74300_cls*)FUN_00aa13e0(0x10);
    if (esi != 0)
    {
        reinterpret_cast<NiExtraDataHelper*>(esi)->FUN_00a7b2e0();
        esi->vptr = (void*)&DAT_0109d39c;
        esi->m_0c = DAT_0109b220;
    }
    else
    {
        esi = 0;
    }
    FUN_00a7b330(esi, arg);
    char* edi = m_0c;
    if (esi->m_0c != edi)
    {
        if (edi != DAT_0109b220)
        {
            DAT_00fdf1c0(edi - 8);
        }
        if (esi->m_0c != DAT_0109b220)
        {
            DAT_00fdf1c4(esi->m_0c - 8);
        }
        esi->m_0c = edi;
    }
    return esi;
}
}  // namespace fnv_00a74300

struct NiStrTable
{
    int unk00;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void SetSize(unsigned int n);
    void SetAt(unsigned int i, char*& v);
    void Add(char* v)
    {
        unsigned int n = unk0A;
        if (n >= unk08)
        {
            SetSize(n + unk0E);
        }
        SetAt(n, v);
    }
};

extern "C" char* __cdecl FUN_00a7d330(char* s);
extern "C" char* __cdecl FUN_00a7d5e0(const char* key, char* value);

struct FUN_00a74380_shell : NiStringExtraData
{
    void FUN_00a7b580(NiStream& stream);
    void GetViewerStrings(NiStream& stream);
};

// @fnv 0x00a74380
void FUN_00a74380_shell::GetViewerStrings(NiStream& stream)
{
    FUN_00a7b580(stream);
    reinterpret_cast<NiStrTable&>(stream).Add(FUN_00a7d330((char*)DAT_011f4a38));
    char* s = *(char**)((char*)this + 0x0c);
    reinterpret_cast<NiStrTable&>(stream).Add(FUN_00a7d5e0("m_kString", s));
}

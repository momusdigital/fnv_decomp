
// src/gamebryo2.2/corelibs/nianimation/nistringpalette.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nistringpalette.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f30;

// Returns the address of the global g_011f3f30.
// @fnv 0x00a47140
void* __cdecl FUN_00a47140()
{
    return &g_011f3f30;
}

struct NiRefObject
{
    virtual ~NiRefObject();
    int m_ref;
};
void __cdecl _NiFreeAlias(void*);
void __cdecl _delete(void*, unsigned int);
extern int DAT_0109832c;
struct S_00a47190 : NiRefObject
{
    void* m_08;
    int m_0C;
    int m_10;
    void* DestroyAndFree(unsigned int);
};
// Frees m_08, destroys the NiRefObject base, and deletes this with size 0x14 when flag bit 0 is set.
// @fnv 0x00a47190
void* S_00a47190::DestroyAndFree(unsigned int auiFlags)
{
    void* p = m_08;
    *(void**)this = (void*)&DAT_0109832c;
    _NiFreeAlias(p);
    this->NiRefObject::~NiRefObject();
    if (auiFlags & 1)
        _delete(this, 0x14);
    return this;
}

struct FUN_00a471d0_Input
{
    int _0;
    int position;
    int(__cdecl* read)(FUN_00a471d0_Input*, unsigned char*, unsigned int, unsigned int*, int);
};
struct FUN_00a471d0_Stream
{
    char _pad[0x24c];
    FUN_00a471d0_Input* input;
};
// Reads uiNumEls bytes into pValue through the stream's input reader and advances the input position by the bytes read.
// @fnv 0x00a471d0
void FUN_00a471d0(FUN_00a471d0_Stream* kStream, unsigned char* pBuffer, unsigned int uiNumEls)
{
    FUN_00a471d0_Input* __restrict input = kStream->input;
    unsigned int size = 1;
    input->position += input->read(input, pBuffer, uiNumEls, &size, 1);
}

struct NiBinaryStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Write(const void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSize, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnWrite(this, pvBuffer, uiBytes, puiComponentSize, uiNumComponents);
    }
};
struct NiStream : FUN_00a471d0_Stream
{
    NiBinaryStream* m_pBackingStream;
};
template <class T> inline void WriteBinaryArray(NiBinaryStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    unsigned int uiSize = sizeof(T);
    kStream.Write(pkValue, uiNumEls * sizeof(T), &uiSize, 1);
}
template <class T> inline void SerializeValue(NiStream& kStream, const T& kValue)
{
    WriteBinaryArray(*kStream.m_pBackingStream, &kValue, 1);
}
template <class T> inline void SerializeValue(NiStream& kStream, const T* pkValue, unsigned int uiNumEls)
{
    WriteBinaryArray(*kStream.m_pBackingStream, pkValue, uiNumEls);
}
struct NiObject : NiRefObject
{
    void LinkObject(NiStream& kStream);
};
struct S_00a47210 : NiObject
{
    char* m_pcData;
    int unk0C;
    unsigned int m_uiSize;
    void WriteToStream(NiStream& kStream);
};
// Links the object to the stream, writes m_uiSize, then writes m_pcData bytes if the size is nonzero, and writes m_uiSize again.
// @fnv 0x00a47210
void S_00a47210::WriteToStream(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    unsigned int uiSize = m_uiSize;
    SerializeValue(kStream, uiSize);
    if (uiSize > 0)
        SerializeValue(kStream, m_pcData, uiSize);
    SerializeValue(kStream, m_uiSize);
}

struct S_00a470c0 : S_00a47190
{
    bool IsSameAs(S_00a470c0* other);
    bool IsEqual(S_00a470c0* other);
};

// Compares this object with another: checks the base comparison, matching m_0C and m_10, then byte-compares m_0C bytes at m_08; returns true if all match.
// @fnv 0x00a470c0
bool S_00a470c0::IsEqual(S_00a470c0* other)
{
    if (IsSameAs(other) && other->m_0C == m_0C && other->m_10 == m_10)
    {
        unsigned int size = (unsigned int)m_0C;
        if (size <= 0)
            goto pass;
        unsigned char* p1 = (unsigned char*)m_08;
        unsigned char* p2 = (unsigned char*)other->m_08;
        while (size >= 4)
        {
            if (*(unsigned int*)p2 != *(unsigned int*)p1)
                goto fail;
            size -= 4;
            p1 += 4;
            p2 += 4;
        }
        if (size == 0)
            goto pass;
        if (*p1 != *p2)
            goto fail;
        if (size <= 1)
            goto pass;
        if (p1[1] != p2[1])
            goto fail;
        if (size <= 2)
            goto pass;
        if (p1[2] != p2[2])
            goto fail;
    pass:
        return true;
    }
fail:
    return false;
}

struct S_00a47150_Base
{
    int m_ref;
    S_00a47150_Base() throw();
    virtual ~S_00a47150_Base() throw();
};
struct S_00a47150_Obj : S_00a47150_Base
{
    void* m_08;
    int m_0C;
    int m_10;
    static void* operator new(unsigned int n);
    S_00a47150_Obj() throw()
    {
        m_08 = 0;
        m_0C = 0;
        m_10 = 0;
    }
    virtual ~S_00a47150_Obj() throw();
};
// Allocates and constructs a new S_00a47150_Obj via its operator new and returns the pointer.
// @fnv 0x00a47150
S_00a47150_Obj* __cdecl FUN_00a47150()
{
    return new S_00a47150_Obj;
}

void* __cdecl FUN_00aa1070(unsigned int size);
struct A472Input
{
    int unk00;
    int position;
    unsigned int(__cdecl* read)(A472Input*, unsigned char*, unsigned int, unsigned int*, unsigned int);
    __forceinline void Read(void* data, unsigned int byteCount, unsigned int componentSize)
    {
        unsigned int elementSize = componentSize;
        position += read(this, (unsigned char*)data, byteCount, &elementSize, 1);
    }
};
struct A472Stream
{
    char unk00[0x24c];
    A472Input* input;
};
class FUN_00a472b0_cls
{
  public:
    int unk00, unk04;
    void* m_pBuf08;
    unsigned int m_uiCount0C, m_uiExtra10;
    void ReadGroup(A472Stream* stream);
    void ReadFromStream(A472Stream* stream);
};
// Reads a count and extra value from the stream, allocates a buffer of that count and reads it in.
// @fnv 0x00a472b0
void FUN_00a472b0_cls::ReadFromStream(A472Stream* stream)
{
    ReadGroup(stream);
    stream->input->Read(&m_uiCount0C, 4, 4);
    if (m_uiCount0C > 0)
    {
        m_pBuf08 = FUN_00aa1070(m_uiCount0C);
        stream->input->Read(m_pBuf08, m_uiCount0C, 1);
    }
    stream->input->Read(&m_uiExtra10, 4, 4);
}

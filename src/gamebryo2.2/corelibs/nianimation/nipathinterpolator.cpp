
// src/gamebryo2.2/corelibs/nianimation/nipathinterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nipathinterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f3f68;

// @fnv 0x00a3dab0
void* __cdecl FUN_00a3dab0()
{
    return &g_011f3f68;
}

struct FUN_00a3dae0_shell
{
    void* __thiscall GetKeyCount(short idx);
};

// Returns the pointer stored at offset 8 of the object at this+0x18 for idx 0 or this+0x1c for idx 1, or null if absent.
// @fnv 0x00a3dae0
void* __thiscall FUN_00a3dae0_shell::GetKeyCount(short idx)
{
    if (idx == 0)
    {
        void* p = *(void**)((char*)this + 0x18);
        if (p)
            return *(void**)((char*)p + 8);
    }
    else if (idx == 1)
    {
        void* p = *(void**)((char*)this + 0x1c);
        if (p)
            return *(void**)((char*)p + 8);
    }
    return 0;
}

struct FUN_00a3db10_shell
{
    int __thiscall GetValueByIndex(short arg);
};

// Returns the int at offset 0x10 of the pointer stored at this+0x18 for arg 0 or this+0x1c for arg 1, or 0 if that pointer is null or arg is other.
// @fnv 0x00a3db10
int __thiscall FUN_00a3db10_shell::GetValueByIndex(short aiIndex)
{
    unsigned char* b = reinterpret_cast<unsigned char*>(this);
    if (aiIndex == 0)
    {
        int* p = *reinterpret_cast<int**>(b + 0x18);
        if (p)
            return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(p) + 0x10);
    }
    else if (aiIndex == 1)
    {
        int* p = *reinterpret_cast<int**>(b + 0x1c);
        if (p)
            return *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(p) + 0x10);
    }
    return 0;
}

struct FUN_00a3db40_shell
{
    int __thiscall FUN_00a3db40(short arg);
};

// Returns the int at offset 0xC of the object stored at this+0x18 when arg is 0, or at this+0x1C when arg is 1; otherwise returns 0.
// @fnv 0x00a3db40
int __thiscall FUN_00a3db40_shell::FUN_00a3db40(short aiSlot)
{
    if (aiSlot == 0)
    {
        int* p = *(int**)(this + 0x18);
        if (p)
            return *(p + 3);
    }
    else if (aiSlot == 1)
    {
        int* p = *(int**)(this + 0x1c);
        if (p)
            return *(p + 3);
    }
    return 0;
}

struct FUN_00a3db70_shell
{
    char __thiscall FUN_00a3db70(unsigned short arg);
};

// Returns byte at offset 0x14 of the object stored at this+0x18 for arg 0 or this+0x1c for arg 1, otherwise 0.
// @fnv 0x00a3db70
char __thiscall FUN_00a3db70_shell::FUN_00a3db70(unsigned short ausIndex)
{
    if (ausIndex == 0)
    {
        void* p = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x18);
        if (p)
            return *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(p) + 0x14);
    }
    else if (ausIndex == 1)
    {
        void* p = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x1c);
        if (p)
            return *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(p) + 0x14);
    }
    return 0;
}

extern "C" void* g_011f3e48;

// @fnv 0x00a3dde0
void* __cdecl FUN_00a3dde0()
{
    return &g_011f3e48;
}

struct FloatDataHelper
{
    void __thiscall FUN_00a3cc40(float m_fStartTime, float m_fMaximumDistance);
};

struct NiPathInterpolator
{
    void* m_pPathInterp;
    void __thiscall FUN_00a3dc50(float m_fStartTime, float m_fMaximumDistance);
};

// Forwards the two float arguments to the FloatDataHelper stored at offset 0x1c, if that pointer is non-null.
// @fnv 0x00a3dc50
void __thiscall NiPathInterpolator::FUN_00a3dc50(float m_fStartTime, float m_fMaximumDistance)
{
    FloatDataHelper* p = (FloatDataHelper*)(*(void**)((char*)this + 0x1c));
    if (p)
    {
        p->FUN_00a3cc40(m_fStartTime, m_fMaximumDistance);
    }
}

// Maps channel 0 to 1, channel 1 to 0, and any other channel to 6.
// @fnv 0x00a3da80
int __stdcall GetChannelIndex(unsigned short usChannel)
{
    if (usChannel == 0)
        return 1;
    return usChannel == 1 ? 0 : 6;
}

extern "C" void __cdecl FUN_00a48fb0();
extern "C" void __cdecl _delete(void*, unsigned int);

struct FUN_00a3dac0_shell
{
    void* __thiscall DestroyIfOdd(short idx);
};

// Calls FUN_00a48fb0, then deletes this with size 24 when idx has bit 0 set, and returns this.
// @fnv 0x00a3dac0
void* __thiscall FUN_00a3dac0_shell::DestroyIfOdd(short idx)
{
    FUN_00a48fb0();
    if (idx & 1)
        _delete(this, 24);
    return this;
}

struct FUN_00a3ddf0_shell
{
    void* __thiscall FUN_00a3ddf0(void* pData, int i1, int i2, float fTime);
};
extern void* DAT_011f3ca8[];
// Reads a type index, element size and base pointer from this+0x18, then calls the DAT_011f3ca8 entry for that type with two element pointers and pData.
// @fnv 0x00a3ddf0
void* FUN_00a3ddf0_shell::FUN_00a3ddf0(void* pData, int aiIndexA, int aiIndexB, float fTime)
{
    char* pcElementBase = 0;
    int iType;
    unsigned char ucSize;
    void* pkObj = *(void**)((char*)this + 0x18);
    if (pkObj)
    {
        iType = *(int*)((char*)pkObj + 0x10);
        ucSize = *(unsigned char*)((char*)pkObj + 0x14);
        pcElementBase = *(char**)((char*)pkObj + 0xC);
    }
    else
    {
        iType = 0;
        ucSize = 0;
    }
    ((void(__cdecl*)(float, void const*, void const*, void*))DAT_011f3ca8[iType])(
        fTime, pcElementBase + ucSize * aiIndexA, pcElementBase + ucSize * aiIndexB, pData);
    return pData;
}

void __cdecl FUN_00a3dd40();
void __cdecl operator delete(void*, unsigned int);

struct FUN_00a3e980_shell
{
    void* __thiscall Destroy(unsigned int flags);
};

// @fnv 0x00a3e980
void* __thiscall FUN_00a3e980_shell::Destroy(unsigned int flags)
{
    FUN_00a3dd40();
    if (flags & 1)
        operator delete(this, 0x5c);
    return this;
}

struct StrArr
{
    void* m_pData;
    int _04;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short _0C;
    unsigned short m_usGrowBy;
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};
struct FUN_00a3cbf0_shell
{
    void __thiscall GetViewerStrings(StrArr*);
};
char* __cdecl _FUN_00a7d330(const char*);
extern const char* _g_011f3e48;
struct TargetHolder : FUN_00a3cbf0_shell
{
    void __thiscall AppendString(StrArr*);
};
// Appends the string returned by _FUN_00a7d330(_g_011f3e48) to pkStrings, growing the array if the size limit is reached.
// @fnv 0x00a3f4d0
void __thiscall TargetHolder::AppendString(StrArr* pkStrings)
{
    GetViewerStrings(pkStrings);
    char* pcString = _FUN_00a7d330(_g_011f3e48);
    unsigned int uiIndex = pkStrings->m_usSize;
    if (uiIndex >= pkStrings->m_usMaxSize)
        pkStrings->SetSize(uiIndex + pkStrings->m_usGrowBy);
    pkStrings->SetAt(uiIndex, pcString);
}

class CloningProcess
{
  public:
    void* m_pCloneMap;
};
struct NiObject
{
    virtual void __thiscall _v00();
    virtual void __thiscall _v01();
    virtual void __thiscall _v02();
    virtual void __thiscall _v03();
    virtual void __thiscall _v04();
    virtual void __thiscall _v05();
    virtual void __thiscall _v06();
    virtual void __thiscall _v07();
    virtual void __thiscall _v08();
    virtual void __thiscall _v09();
    virtual void __thiscall _v10();
    virtual void __thiscall _v11();
    virtual void __thiscall _v12();
    virtual void __thiscall _v13();
    virtual void __thiscall _v14();
    virtual void __thiscall _v15();
    virtual void __thiscall _v16();
    virtual void __thiscall _v17();
    virtual void __thiscall _v18();
    virtual void __thiscall _v19();
    virtual void __thiscall _v20();
    virtual void __thiscall _v21();
    virtual void __thiscall _v22();
    virtual void __thiscall _v23();
    virtual void __thiscall _v24();
    virtual void __thiscall _v25();
    virtual void __thiscall ProcessClone(CloningProcess&);
};
struct PathPtr
{
    NiObject* m_pObject;
};
struct PctPtr
{
    NiObject* m_pObject;
};
struct FUN_00a3dc80_shell
{
    char _pad[0x18];
    PathPtr m_pPathObject;
    PctPtr m_pPathInterp;
    void __thiscall FUN_00a3dc80(CloningProcess&);
};
// Calls ProcessClone on this object and on the path and percentage objects if they are set.
// @fnv 0x00a3dc80
void __thiscall FUN_00a3dc80_shell::FUN_00a3dc80(CloningProcess& kCloning)
{
    ((NiObject*)this)->NiObject::ProcessClone(kCloning);
    NiObject* pkPath = m_pPathObject.m_pObject;
    if (pkPath)
        pkPath->ProcessClone(kCloning);
    NiObject* pkPct = m_pPathInterp.m_pObject;
    if (pkPct)
        pkPct->ProcessClone(kCloning);
}

struct HC1Base
{
    bool __thiscall FUN_00aa0ad0(void*);
};
struct FUN_00a3dcc0_Reg
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual bool RegisterStreamables(void*);
};
struct FUN_00a3dcc0_cls
{
    char _pad[0x18];
    FUN_00a3dcc0_Reg* m_path;
    FUN_00a3dcc0_Reg* m_pct;
    bool __thiscall FUN_00a3dcc0(void*);
};
// @fnv 0x00a3dcc0
bool FUN_00a3dcc0_cls::FUN_00a3dcc0(void* pkStream)
{
    if (!((HC1Base*)this)->FUN_00aa0ad0(pkStream))
        return false;
    FUN_00a3dcc0_Reg* pPath = m_path;
    if (pPath)
        pPath->RegisterStreamables(pkStream);
    FUN_00a3dcc0_Reg* pPct = m_pct;
    if (pPct)
        pPct->RegisterStreamables(pkStream);
    return true;
}

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00a3f060_shell
{
    void* __thiscall FUN_00a3f060(short, short);
};

// @fnv 0x00a3f4b0
void* __cdecl CreateA51BF0Base()
{
    void* p = A51BF0Base::operator new(0x5c);
    if (p)
        return ((FUN_00a3f060_shell*)p)->FUN_00a3f060(0, 0);
    return 0;
}

extern float DAT_01097170;
extern float DAT_01015f5c;
extern double DAT_010231b0;
extern double DAT_010241b0;

struct FUN_00a3dba0_Class
{
    virtual void vf00()
    {}
    virtual void vf04()
    {}
    virtual void vf08()
    {}
    virtual void vf0C()
    {}
    virtual void vf10()
    {}
    virtual void vf14()
    {}
    virtual void vf18()
    {}
    virtual void vf1C()
    {}
    virtual void vf20()
    {}
    virtual void vf24()
    {}
    virtual void vf28()
    {}
    virtual void vf2C()
    {}
    virtual void vf30()
    {}
    virtual void vf34()
    {}
    virtual void vf38()
    {}
    virtual void vf3C()
    {}
    virtual void vf40()
    {}
    virtual void vf44()
    {}
    virtual void vf48()
    {}
    virtual void vf4C()
    {}
    virtual void vf50()
    {}
    virtual void vf54()
    {}
    virtual void vf58()
    {}
    virtual void vf5C()
    {}
    virtual void vf60()
    {}
    virtual void vf64()
    {}
    virtual void vf68()
    {}
    virtual void vf6C()
    {}
    virtual void vf70()
    {}
    virtual void vf74()
    {}
    virtual void vf78()
    {}
    virtual void vf7C()
    {}
    virtual void vf80()
    {}
    virtual void vf84()
    {}
    virtual void vf88()
    {}
    virtual void vf8C()
    {}
    virtual void vf90()
    {}
    virtual void vf94()
    {}
    virtual void vf98()
    {}
    virtual void vf9C()
    {}
    virtual void vfA0()
    {}
    virtual void vfA4()
    {}
    virtual void vfA8()
    {}
    virtual void vfAC()
    {}
    virtual void vfB0()
    {}
    virtual void vfB4()
    {}
    virtual void vfB8()
    {}
    virtual void vfBC()
    {}

    virtual void __thiscall GetRange(float* fTargetUpperBound, float* fMinimumInputValue);

    virtual void vfC4()
    {}
    virtual void vfC8()
    {}
    virtual void vfCC()
    {}
    virtual void vfD0()
    {}
    virtual void vfD4()
    {}
    virtual void vfD8()
    {}
    virtual void vfDC()
    {}

    float* __thiscall FUN_00a3ca80(int index, int mode);
    float* __thiscall FUN_00a3ca80(int index);
};

struct FUN_00a3dba0_Class1 : FUN_00a3dba0_Class
{
    virtual unsigned int __thiscall vfE0(unsigned int index);
};

struct FUN_00a3dba0_Class2 : FUN_00a3dba0_Class
{
    virtual unsigned int __thiscall vfE0(unsigned int index, unsigned int mode);
};

// @fnv 0x00a3dba0
void __thiscall FUN_00a3dba0_Class::GetRange(float* pfMin, float* pfMax)
{
    *pfMin = DAT_01097170;
    *pfMax = DAT_01015f5c;

    unsigned int count = reinterpret_cast<FUN_00a3dba0_Class1*>(this)->vfE0(1);

    if (count > 0)
    {
        float* first = this->FUN_00a3ca80(0, 1);
        unsigned int index = reinterpret_cast<FUN_00a3dba0_Class2*>(this)->vfE0(1, 1) - 1;
        float* last = this->FUN_00a3ca80(index);

        if (first != 0 && last != 0)
        {
            if (*first < *pfMin)
                *pfMin = *first;

            if (*last > *pfMax)
                *pfMax = *last;
        }
    }

    if ((double)*pfMin == DAT_010231b0 && (double)*pfMax == DAT_010241b0)
    {
        *pfMin = 0.0f;
        *pfMax = 0.0f;
    }
}

struct Stream
{
    unsigned int flags, bytesRead;
    int(__cdecl* readProc)(Stream*, void*, unsigned int, unsigned int*, int);
    __forceinline int Read(void* dst, unsigned int count)
    {
        unsigned int actual = count;
        return readProc(this, dst, count, &actual, 1);
    }
};
struct Source
{
    Stream* stream()
    {
        return *reinterpret_cast<Stream**>(reinterpret_cast<char*>(this) + 0x24c);
    }
    void __thiscall FUN_00a645b0();
};
void __stdcall FUN_00aa0ac0(Source*);
struct PathData
{
    unsigned int unk00, unk04, unk08;
    unsigned short channel, unk0e;
    unsigned int unk10, unk14, unk18, unk1c, unk20, unk24;
    unsigned int value28, value2c;
    unsigned short channel30, unk32;
    unsigned int unk34, value38;
    void __thiscall ReadFromStream(Source*);
};
// Reads channel, value38, value28, value2c and channel30 from the source's stream, accumulating bytesRead, then calls FUN_00a645b0 twice.
// @fnv 0x00a3ed90
void PathData::ReadFromStream(Source* source)
{
    FUN_00aa0ac0(source);
    Stream* stream = source->stream();
    stream->bytesRead += stream->Read(&channel, 2);
    unsigned int value;
    stream = source->stream();
    stream->bytesRead += stream->Read(&value, 4);
    value38 = value;
    stream = source->stream();
    stream->bytesRead += stream->Read(&value28, 4);
    stream = source->stream();
    stream->bytesRead += stream->Read(&value2c, 4);
    stream = source->stream();
    stream->bytesRead += stream->Read(&channel30, 2);
    source->FUN_00a645b0();
    source->FUN_00a645b0();
}

struct FNV_WriteStream;
typedef int(__cdecl* FNV_WriteFn)(FNV_WriteStream* stream, void* data, int size, int* written, int flag);

struct FNV_NiStreamPad
{
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
};

struct FNV_NiStream
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12(int value);
    FNV_NiStreamPad pad;
    FNV_WriteStream* m_pWriter;
};

struct FNV_WriteStream
{
    int unk00;
    int m_uiItemCount;
    void* unk08;
    FNV_WriteFn m_pfn;
};

struct FNV_Writer
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short unk0c;
    unsigned short unk0e;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    float unk24;
    int unk28;
    int unk2c;
    unsigned short unk30;
    unsigned short unk32;
    float unk34;
    int unk38;
    void __thiscall FUN_00a95ca0(FNV_NiStream* pStream);
    void __thiscall WriteToStream(FNV_NiStream* pStream);
};

// The single write the record layout performs: hand the payload and its size
// to the stream's callback and accumulate the byte count it returns.
static __forceinline void FNV_WriteField(FNV_WriteStream* pWriter, void* pData, int nSize)
{
    int n = nSize;
    int r = pWriter->m_pfn(pWriter, pData, n, &n, 1);
    pWriter->m_uiItemCount += r;
}

// Writes unk0c, unk38, unk28, unk2c and unk30 to the stream's writer, then calls f12 with unk18 and unk1c after FUN_00a95ca0.
// @fnv 0x00a3ef70
void FNV_Writer::WriteToStream(FNV_NiStream* pStream)
{
    FUN_00a95ca0(pStream);
    FNV_WriteField(pStream->m_pWriter, &unk0c, 2);
    FNV_WriteField(pStream->m_pWriter, &unk38, 4);
    FNV_WriteField(pStream->m_pWriter, &unk28, 4);
    FNV_WriteField(pStream->m_pWriter, &unk2c, 4);
    FNV_WriteField(pStream->m_pWriter, &unk30, 2);
    pStream->f12(unk18);
    pStream->f12(unk1c);
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long* p);
__declspec(dllimport) long __stdcall InterlockedDecrement(long* p);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void* __cdecl NiMalloc(unsigned int);

class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

class NiObj2 : public NiRefObject
{
  public:
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual NiObj2* CreateSharedClone(CloningProcess& kCloning);
};

class NiPosData : public NiObj2
{
  public:
    unsigned int m_uiNumKeys;
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    NiPointer& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

class NiInterpolatorBase : public NiObj2
{
  public:
    void CopyMemberData(NiInterpolatorBase* pDest, CloningProcess& kCloning);
    float m_fLastTime;
    unsigned short m_uiObjectFlags;
    void SetBit(bool bVal, unsigned short uMask)
    {
        if (bVal)
            m_uiObjectFlags |= uMask;
        else
            m_uiObjectFlags &= ~uMask;
    }
    bool GetBit(unsigned short uMask) const
    {
        return (m_uiObjectFlags & uMask) != 0;
    }
};

class NiPathInterp : public NiInterpolatorBase
{
  public:
    int unk10;
    int unk14;
    NiPointer<NiPosData> m_pPathObject;
    NiPointer<NiPosData> m_pPathInterp;
    float* m_pfPathLengths;
    float m_fTotalPathLength;
    float m_fPreviousTime;
    float m_fLastPercent;
    short m_sLastPathIndex;
    short unk32;
    int unk34;
    int m_iPathPointCount;

    float CalcTotalLength();
    void SetConstVelocity(bool b)
    {
        SetBit(b, 0x10);
        if (b && GetBit(1))
        {
            m_fTotalPathLength = CalcTotalLength();
            SetBit(false, 1);
        }
    }
    void FUN_00a3f2f0(NiPathInterp* pDest, CloningProcess& kCloning);
};

// @fnv 0x00a3f2f0
void NiPathInterp::FUN_00a3f2f0(NiPathInterp* pDest, CloningProcess& kCloning)
{
    NiInterpolatorBase::CopyMemberData(pDest, kCloning);
    pDest->m_uiObjectFlags = m_uiObjectFlags;
    if (m_pPathObject)
        pDest->m_pPathObject = (NiPosData*)m_pPathObject->CreateSharedClone(kCloning);
    if (m_pPathInterp)
        pDest->m_pPathInterp = (NiPosData*)m_pPathInterp->CreateSharedClone(kCloning);
    pDest->SetBit(GetBit(4), 4);
    pDest->SetBit(GetBit(8), 8);
    pDest->m_iPathPointCount = m_iPathPointCount;
    pDest->SetConstVelocity(GetBit(0x10));
    pDest->SetBit(GetBit(0x20), 0x20);
    pDest->m_fPreviousTime = m_fPreviousTime;
    pDest->m_fLastPercent = m_fLastPercent;
    pDest->m_sLastPathIndex = m_sLastPathIndex;
    pDest->SetBit(GetBit(0x40), 0x40);
    pDest->SetBit(GetBit(2), 2);
    if (m_pfPathLengths)
    {
        unsigned int uiNumKeys = m_pPathObject ? m_pPathObject->m_uiNumKeys : 0;
        unsigned int uiSize = uiNumKeys * sizeof(float);
        pDest->m_pfPathLengths = (float*)NiMalloc(uiSize);
        memcpy(pDest->m_pfPathLengths, m_pfPathLengths, uiSize);
    }
    pDest->m_fTotalPathLength = m_fTotalPathLength;
}

class NiObjectA3F
{
  public:
    NiObjectA3F(void* pvFirst, void* pvSecond) throw();
    virtual ~NiObjectA3F();

    static void* operator new(unsigned int uiSize);

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
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
};

class NiCloningProcessA3F;

class NiOwnerA3F
{
  public:
    void CopyMemberData(NiObjectA3F* pkDest, NiCloningProcessA3F& kCloning);
    NiObjectA3F* CloneObject(NiCloningProcessA3F& kCloning);
};

// @fnv 0x00a3f520
NiObjectA3F* NiOwnerA3F::CloneObject(NiCloningProcessA3F& kCloning)
{
    NiObjectA3F* pkClone = new NiObjectA3F(0, 0);
    CopyMemberData(pkClone, kCloning);
    return pkClone;
}

struct MyPosKey
{
    float m_fTime;
};

struct MyPosData : public NiPosData
{
    MyPosKey* m_pKeyArray;
    int unk10;
    unsigned char m_ucKeyDataSize;
};

static __forceinline MyPosKey* GetKey(MyPosKey* pkKeys, unsigned int uiIndex, unsigned char ucKeySize)
{
    return (MyPosKey*)((const char*)pkKeys + uiIndex * ucKeySize);
}

struct PathInterpExt : public NiPathInterp
{
    void __thiscall FUN_00a3ea60(float fTime, unsigned int& ruiKey0, unsigned int& ruiKey1, float& rfNormTime);
    void FindKeyPair(float fTime, unsigned int& ruiKey0, unsigned int& ruiKey1, float& rfNormTime);
};

// @fnv 0x00a3ec30
void PathInterpExt::FindKeyPair(float fTime, unsigned int& ruiKey0, unsigned int& ruiKey1, float& rfNormTime)
{
    if (GetBit(0x10))
    {
        FUN_00a3ea60(fTime, ruiKey0, ruiKey1, rfNormTime);
        unk10 = ruiKey0;
        return;
    }

    MyPosData* pkPathData = (MyPosData*)m_pPathObject.m_pObject;
    unsigned int uiNumKeys;
    unsigned char ucKeySize;
    MyPosKey* pkKeys = 0;
    if (pkPathData)
    {
        uiNumKeys = pkPathData->m_uiNumKeys;
        ucKeySize = pkPathData->m_ucKeyDataSize;
        pkKeys = pkPathData->m_pKeyArray;
    }
    else
    {
        uiNumKeys = 0;
        ucKeySize = 0;
    }

    if (fTime <= pkKeys->m_fTime)
    {
        ruiKey0 = 0;
        ruiKey1 = 1;
        rfNormTime = 0.0f;
        return;
    }

    MyPosKey* pkLastKey = GetKey(pkKeys, uiNumKeys - 1, ucKeySize);
    if (fTime >= pkLastKey->m_fTime)
    {
        ruiKey0 = uiNumKeys - 2;
        ruiKey1 = uiNumKeys - 1;
        rfNormTime = 1.0f;
        return;
    }

    unsigned int uiKey = unk10;
    unsigned int uiNextKey = 0;
    bool m_bIsBest = true;
    while (uiKey < uiNumKeys - 1)
    {
        if (fTime == GetKey(pkKeys, uiKey, ucKeySize)->m_fTime)
        {
            unk10 = uiKey;
            uiNextKey = uiKey + 1;
            break;
        }

        MyPosKey* pkKey = GetKey(pkKeys, uiKey, ucKeySize);
        if (pkKey->m_fTime < fTime && GetKey(pkKeys, uiKey + 1, ucKeySize)->m_fTime > fTime)
        {
            unk10 = uiKey;
            uiNextKey = uiKey + 1;
            break;
        }

        if (uiKey == uiNumKeys - 2 && m_bIsBest)
        {
            uiKey = 0;
            m_bIsBest = false;
        }
        else
        {
            uiKey++;
        }
    }

    MyPosKey* pkKey0 = GetKey(pkKeys, uiKey, ucKeySize);
    MyPosKey* pkKey1 = GetKey(pkKeys, uiNextKey, ucKeySize);
    rfNormTime = (fTime - pkKey0->m_fTime) / (pkKey1->m_fTime - pkKey0->m_fTime);
    ruiKey0 = uiKey;
    ruiKey1 = uiNextKey;
}

static const float kNegMax = -3.402823466e+38f;
class NiPoint3
{
  public:
    float x, y, z;
};
class NiQuaternion
{
  public:
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
};
extern const NiPoint3 DAT_011a9424;
extern NiQuaternion DAT_011f4208;

class NiFloatData : public NiObj2
{
};
template <class T> class NiPtrAB
{
  public:
    NiPtrAB(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    T* m_pObject;
};
class NiKeyBasedInterpolator
{
  public:
    NiKeyBasedInterpolator();
    virtual void v00();
    long m_uiRefCount;
    float m_fLastTime;
    unsigned short m_uiObjectFlags;
};
class FUN_00a3f060 : public NiKeyBasedInterpolator
{
  public:
    FUN_00a3f060(NiPosData* pkPathData, NiFloatData* pkPctData);
    unsigned int m_uiPathKeyCount;
    unsigned int m_uiPercentKeyCount;
    NiPtrAB<NiPosData> m_pPathObject;
    NiPtrAB<NiFloatData> m_pPathInterp;
    float* m_pfPathLengths;
    float m_fTotalPathLength;
    float m_fPreviousTime;
    float m_fLastPercent;
    short m_sLastPathIndex;
    float m_fPathLength;
    int m_iPathPointCount;
    NiQuaternion m_kRotationMatrix;
    NiPoint3 m_kPathOffset;
    float m_fLast;
};
// @fnv 0x00a3f060
FUN_00a3f060::FUN_00a3f060(NiPosData* pkPathData, NiFloatData* pkPctData)
    : m_pPathObject(pkPathData), m_pPathInterp(pkPctData), m_kRotationMatrix(DAT_011f4208), m_kPathOffset(DAT_011a9424)
{
    m_fPreviousTime = 0.0f;
    m_fLastPercent = 0.0f;
    m_fPathLength = 0.0f;
    m_fTotalPathLength = -1.0f;
    m_fLast = kNegMax;
    m_uiPathKeyCount = 0;
    m_uiPercentKeyCount = 0;
    m_iPathPointCount = 1;
    m_sLastPathIndex = 0;
    m_pfPathLengths = 0;
    m_uiObjectFlags = 3;
}

#include <math.h>
extern double DAT_01032980;

struct PathKeyData
{
    int unk00;
    int unk04;
    unsigned int m_uiNumKeys;
};

struct FUN_00a3e680_shell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    PathKeyData* m_pPathObject;
    int unk1c;
    float* m_pfPathLengths;
    float m_fTotalPathLength;
    float FUN_00a3e680(int i1, int i2, float t);
    float SampleLength(int i1, int i2, float t);
    void FUN_00a3ea60(float fTime, unsigned int& i1, unsigned int& i2, float& fNormTime);
};

// Normalizes fTime to [0,1], locates the path key segment containing the target distance, and refines the local parameter via Newton iteration.
// @fnv 0x00a3ea60
void FUN_00a3e680_shell::FUN_00a3ea60(float fTime, unsigned int& ri1, unsigned int& ri2, float& rfLocalTime)
{
    unsigned int uiNumKeys = m_pPathObject ? m_pPathObject->m_uiNumKeys : 0;
    if (fTime == 0.0f)
    {
        ri1 = 0;
        ri2 = 1;
        rfLocalTime = 0.0f;
        return;
    }
    if (fTime < 0.0f)
        fTime = (float)fmod(fTime, 1.0f) + 1.0f;
    if (fTime == 1.0f)
    {
        ri1 = uiNumKeys - 2;
        ri2 = uiNumKeys - 1;
        rfLocalTime = 1.0f;
        return;
    }
    if (fTime > 1.0f)
        fTime = (float)fmod(fTime, 1.0f);

    float fTargetDistance = fTime * m_fTotalPathLength;
    float fAccumulatedDistance = 0.0f;
    float fLocalTime = 0.0f;
    unsigned int i1 = 0, i2 = 1;
    for (; i1 < uiNumKeys - 1; i1++, i2++)
    {
        if (fTargetDistance <= m_pfPathLengths[i2])
        {
            fAccumulatedDistance = fTargetDistance - m_pfPathLengths[i1];
            fLocalTime = fAccumulatedDistance / (m_pfPathLengths[i2] - m_pfPathLengths[i1]);
            break;
        }
    }
    for (int it = 0; it < 32; it++)
    {
        float fError = FUN_00a3e680(i1, i2, fLocalTime) - fAccumulatedDistance;
        if ((float)fabs(fError) <= DAT_01032980)
            break;
        fLocalTime = (float)(fLocalTime - fError / SampleLength(i1, i2, fLocalTime));
    }
    ri1 = i1;
    ri2 = i2;
    rfLocalTime = fLocalTime;
}

struct AnimInfo
{
    unsigned int count;
    int type;
    MyPosKey* keys;
};
static __forceinline AnimInfo ComputePositionAtTime(const MyPosData* data)
{
    AnimInfo info;
    info.count = data->m_uiNumKeys;
    info.type = data->unk10;
    info.keys = data->m_pKeyArray;
    return info;
}
class NiStream
{
  public:
    NiObj2* FUN_00a63430();
};
typedef float (*CurvatureFunction)(MyPosKey*, unsigned int);
extern CurvatureFunction DAT_011f3d38[];
struct PathInterpLink : public NiPathInterp
{
    unsigned short GetField(unsigned short mask, unsigned short pos) const
    {
        return (m_uiObjectFlags & mask) >> pos;
    }
    bool GetConstVelocity() const
    {
        return (GetField(0x10, 4) & 1) != 0;
    }
    bool GetCVDataNeedsUpdate() const
    {
        return GetBit(1);
    }
    void SetCVDataNeedsUpdate(bool x)
    {
        SetBit(x, 1);
    }
    void FUN_00a95ca0(NiStream&);
    float GetAccumulatedValue();
    void LinkObject(NiStream&);
};
// Reads path data from a stream, updates constant-velocity state, and computes curvature from the path object's position keys.
// @fnv 0x00a3ee80
void PathInterpLink::LinkObject(NiStream& stream)
{
    FUN_00a95ca0(stream);
    m_pPathObject = (NiPosData*)stream.FUN_00a63430();
    m_pPathInterp = (NiPosData*)stream.FUN_00a63430();
    SetCVDataNeedsUpdate(true);
    if (GetConstVelocity() && GetCVDataNeedsUpdate())
    {
        m_fTotalPathLength = GetAccumulatedValue();
        SetCVDataNeedsUpdate(false);
    }
    if (m_pPathObject)
    {
        AnimInfo info = ComputePositionAtTime((MyPosData*)(NiPosData*)m_pPathObject);
        unsigned int count = info.count;
        int type = info.type;
        MyPosKey* keys = info.keys;
        if (count > 0)
        {
            CurvatureFunction curvature = DAT_011f3d38[type];
            *(float*)&unk34 = curvature(keys, count);
        }
    }
}

static const float kInvalidValue = -3.4028234663852886e+38F;
class NiMatrix3Q
{
  public:
    float m_afEntries[3][3];
};

class NiQuatQ
{
  public:
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    void FUN_00a6df40(const NiMatrix3Q& kRot);
};

inline bool PointEquals(const NiPoint3& a, const NiPoint3& b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

class NiQuatTransformQ
{
  public:
    NiPoint3 m_kTranslate;
    NiQuatQ m_kRotate;
    float m_fScale;

    void GetTransformScale(const NiPoint3& kTrans)
    {
        m_kTranslate = kTrans;
    }
    __forceinline void SetLocalRotation(const NiQuatQ& kRot)
    {
        m_kRotate = kRot;
    }
    void MakeInvalid()
    {
        m_fScale = m_kRotate.m_fVectorY = m_kTranslate.x = kInvalidValue;
    }
};

class NiFloatDataQ : public NiObj2
{
  public:
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;

    void* ComputePositionAtTime(unsigned int& uiNumKeys, int& eType, unsigned char& ucSize) const
    {
        uiNumKeys = m_uiNumKeys;
        eType = m_eRequestType;
        ucSize = m_ucKeyDataSize;
        return m_pKeyArray;
    }
};

class NiPosDataQ : public NiObj2
{
  public:
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
};

float InterpolateKey(float fTime, void* pkKeys, int eType, unsigned int uiNumKeys, unsigned int& uiLastIdx,
                     unsigned char ucSize);

class NiObjectNETQ;

class NiPathInterpQ
{
  public:
    virtual void v00();
    long m_uiRefCount;
    float m_fLastTime;
    unsigned short m_uiObjectFlags;
    unsigned int m_uiPathKeyCount;
    unsigned int m_uiPercentKeyCount;
    NiPointer<NiPosDataQ> m_pPathObject;
    NiPointer<NiFloatDataQ> m_pPathInterp;
    float* m_pfPathLengths;
    float m_fTotalPathLength;
    float m_fPreviousTime;
    float m_fLastPercent;
    short m_sLastPathIndex;
    float m_fPathLength;
    int m_iPathPointCount;
    NiQuatQ m_kRotationMatrix;
    NiPoint3 m_kPathOffset;
    float m_fZValue;

    bool TimeHasChanged(float fTime) const
    {
        return m_fLastTime != fTime;
    }
    unsigned short GetField(unsigned short uMask, unsigned short uPos) const
    {
        return (m_uiObjectFlags & uMask) >> uPos;
    }
    bool GetFollow() const
    {
        return (bool)GetField(0x20, 5);
    }

    __declspec(noalias) void FindKeyPair(float fTime, int& iI1, int& iI2, float& fNormTime);
    void EvaluateBasis(int iI1, int iI2, float fTime, NiMatrix3Q& kRot);
    NiPoint3 FUN_00a3ddf0(int iI1, int iI2, float fTime);

    bool UpdateTransform(float fTime, NiObjectNETQ* pkTarget, NiQuatTransformQ& kValue);
};

// Computes the path position and optional rotation at fTime, writes them into kValue, and returns whether the transform was updated.
// @fnv 0x00a3f120
bool NiPathInterpQ::UpdateTransform(float fTime, NiObjectNETQ* pkTarget, NiQuatTransformQ& kValue)
{
    if (!TimeHasChanged(fTime))
    {
        if (PointEquals(m_kPathOffset, DAT_011a9424))
        {
            kValue.MakeInvalid();
            return false;
        }
        kValue.GetTransformScale(m_kPathOffset);
        if (GetFollow())
            kValue.SetLocalRotation(m_kRotationMatrix);
        return true;
    }

    unsigned int uiNumKeys;
    int eType;
    unsigned char ucSize;
    void* pkKeys = 0;
    if (m_pPathInterp)
        pkKeys = m_pPathInterp->ComputePositionAtTime(uiNumKeys, eType, ucSize);
    if (!pkKeys)
        return false;
    void* pkPathKeys = 0;
    if (m_pPathObject)
        pkPathKeys = m_pPathObject->m_pKeyArray;
    if (!pkPathKeys)
        return false;
    float fPct = InterpolateKey(fTime, pkKeys, eType, uiNumKeys, m_uiPercentKeyCount, ucSize);

    int iI1, iI2;
    FindKeyPair(fPct, iI1, iI2, fPct);

    if (GetFollow())
    {
        NiMatrix3Q kRot;
        EvaluateBasis(iI1, iI2, fPct, kRot);
        m_kRotationMatrix.FUN_00a6df40(kRot);
    }

    m_kPathOffset = FUN_00a3ddf0(iI1, iI2, fPct);

    kValue.GetTransformScale(m_kPathOffset);
    if (GetFollow())
        kValue.SetLocalRotation(m_kRotationMatrix);

    m_fZValue = fTime;
    return true;
}

#include <string.h>
struct NiObjectStub
{
    virtual void _v00();
    virtual void _v01();
    virtual void _v02();
    virtual void _v03();
    virtual void _v04();
    virtual void _v05();
    virtual void _v06();
    virtual void _v07();
    virtual void _v08();
    virtual void _v09();
    virtual void _v10();
    virtual void _v11();
    virtual void _v12();
    virtual void _v13();
    virtual void _v14();
    virtual void _v15();
    virtual void _v16();
    virtual void _v17();
    virtual void _v18();
    virtual void _v19();
    virtual void _v20();
    virtual void _v21();
    virtual void _v22();
    virtual bool IsEqual(NiObjectStub* pkObject);
};

template <class T> struct NiPointerStub
{
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct NiKeyBasedInterpolatorStub : NiObjectStub
{
    int unk04;
    int unk08;
    unsigned short m_uiObjectFlags;
    unsigned short unk0E;
    int unk10;
    int unk14;
    virtual bool IsEqual(NiObjectStub* pkObject);
};

struct NiPathInterpolatorStub : NiKeyBasedInterpolatorStub
{
    NiPointerStub<NiObjectStub> m_pPathObject;
    NiPointerStub<NiObjectStub> m_pPathInterp;
    float* m_pfPathLengths;
    float m_fTotalPathLength;
    float m_fPreviousTime;
    float m_fLastPercent;
    short m_sLastPathIndex;
    short unk32;
    int unk34;
    int m_iPathPointCount;

    int GetPathKeys(int& uiNumKeys, int& eType, char& ucSize);
    bool GetBit(unsigned short mask) const
    {
        return (m_uiObjectFlags & mask) != 0;
    }
    __forceinline bool PartialLengthsEqual(NiPathInterpolatorStub* pkPath)
    {
        int uiNumKeys;
        int eType;
        char ucSize;
        GetPathKeys(uiNumKeys, eType, ucSize);
        return memcmp(m_pfPathLengths, pkPath->m_pfPathLengths, uiNumKeys * sizeof(float)) == 0;
    }
    bool FUN_00a3e7b0(NiObjectStub* pkObject);
};

// Compares base equality, path objects and interpolator, path lengths, total length, point count, flags, and timing state.
// @fnv 0x00a3e7b0
bool NiPathInterpolatorStub::FUN_00a3e7b0(NiObjectStub* pkObject)
{
    if (!NiKeyBasedInterpolatorStub::IsEqual(pkObject))
        return false;

    NiPathInterpolatorStub* pkPath = (NiPathInterpolatorStub*)pkObject;

    if ((m_pPathObject && !pkPath->m_pPathObject) || (!m_pPathObject && pkPath->m_pPathObject) ||
        (m_pPathObject && !m_pPathObject->IsEqual(pkPath->m_pPathObject)))
        return false;

    if ((m_pPathInterp && !pkPath->m_pPathInterp) || (!m_pPathInterp && pkPath->m_pPathInterp) ||
        (m_pPathInterp && !m_pPathInterp->IsEqual(pkPath->m_pPathInterp)))
        return false;

    int uiNumKeys;
    int eType;
    char ucSize;
    float* pfPartialLength = m_pfPathLengths;
    if ((m_pfPathLengths && !pkPath->m_pfPathLengths) || (!m_pfPathLengths && pkPath->m_pfPathLengths) ||
        (m_pfPathLengths && (GetPathKeys(uiNumKeys, eType, ucSize),
                             memcmp(pfPartialLength, pkPath->m_pfPathLengths, uiNumKeys * sizeof(float)) != 0)))
        return false;

    if (m_fTotalPathLength != pkPath->m_fTotalPathLength || GetBit(1) != pkPath->GetBit(1) ||
        GetBit(2) != pkPath->GetBit(2) || m_iPathPointCount != pkPath->m_iPathPointCount ||
        GetBit(4) != pkPath->GetBit(4) || GetBit(8) != pkPath->GetBit(8) || GetBit(16) != pkPath->GetBit(16) ||
        GetBit(32) != pkPath->GetBit(32) || m_fPreviousTime != pkPath->m_fPreviousTime ||
        m_fLastPercent != pkPath->m_fLastPercent || m_sLastPathIndex != pkPath->m_sLastPathIndex ||
        GetBit(64) != pkPath->GetBit(64))
        return false;

    return true;
}

#include <math.h>
namespace fnv_00a3de50 {
struct NiObjectStub
{
    virtual void _v00();
    virtual void _v01();
    virtual void _v02();
    virtual void _v03();
    virtual void _v04();
    virtual void _v05();
    virtual void _v06();
    virtual void _v07();
    virtual void _v08();
    virtual void _v09();
    virtual void _v10();
    virtual void _v11();
    virtual void _v12();
    virtual void _v13();
    virtual void _v14();
    virtual void _v15();
    virtual void _v16();
    virtual void _v17();
    virtual void _v18();
    virtual void _v19();
    virtual void _v20();
    virtual void _v21();
    virtual void _v22();
    virtual bool IsEqual(NiObjectStub* pkObject);
};

template <class T> struct NiPointerStub
{
    T* m_pObject;
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct NiKeyBasedInterpolatorStub : NiObjectStub
{
    int unk04;
    int unk08;
    unsigned short m_uiObjectFlags;
    unsigned short unk0E;
    int unk10;
    int unk14;
    virtual bool IsEqual(NiObjectStub* pkObject);
};

struct FV3
{
    float x, y, z;
    FV3()
    {}
    FV3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    FV3 operator-() const
    {
        FV3 v;
        v.x = -x;
        v.y = -y;
        v.z = -z;
        return v;
    }
    void __thiscall FUN_004a0c10();
    FV3 __thiscall FUN_004b3800(const FV3&) const;
    FV3 __thiscall FUN_00439e90(const FV3&) const;
};
struct FM3
{
    float values[3][3];
    FM3()
    {}
    void __thiscall FUN_004168a0(float, float, float, float);
    FM3 __thiscall FUN_0043f8d0(const FM3&) const;
    void SetCol(int c, const FV3& v)
    {
        values[0][c] = v.x;
        values[1][c] = v.y;
        values[2][c] = v.z;
    }
    void GetCol(int c, FV3& result) const
    {
        result.x = values[0][c];
        result.y = values[1][c];
        result.z = values[2][c];
    }
};
struct PathKeyBlock
{
    void* vtable;
    unsigned int refCount;
    unsigned int numKeys;
    MyPosKey* keyData;
    unsigned int keyType;
    unsigned char keyStride;
};
struct PathBasis
{
    float x, y, z;
    FV3 __thiscall FUN_0053d1a0(const FV3&) const;
};
struct PathBlend
{
    FV3* __thiscall FUN_00439e90(FV3*, const FV3*);
};
extern char DAT_011a9448;
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
extern PathBasis DAT_011a9484;
extern float DAT_011f3e40;
extern unsigned int DAT_011f3e44;
extern float DAT_01097304;
extern "C" double __cdecl atan(double);
extern void __cdecl ComputeFrenetFrame(float, MyPosKey*, MyPosKey*, unsigned int, FV3*, FV3*, FV3*, float*);
extern FV3 __cdecl FUN_004a3760(float, const FV3&);
struct PathMotion : NiKeyBasedInterpolatorStub
{
    PathKeyBlock* pathData;
    void* percentData;
    float* partialLengths;
    float totalLength;
    float maxBankAngle;
    float smoothing;
    short followAxis;
    short unk32;
    float maxCurvature;
    int bankDirection;
    bool GetBit(unsigned short mask) const
    {
        return (m_uiObjectFlags & mask) != 0;
    }
    MyPosKey* GetPathKeys(unsigned int& count, unsigned int& type, unsigned char& stride) const
    {
        PathKeyBlock* data = pathData;
        if (data)
        {
            count = data->numKeys;
            type = data->keyType;
            stride = data->keyStride;
            return data->keyData;
        }
        count = 0;
        type = 0;
        stride = 0;
        return 0;
    }
    void __thiscall EvaluateBasis(unsigned int first, unsigned int second, float time, FM3* out);
};

extern "C" double __cdecl sqrt(double);
extern double DAT_01017cf8;
__declspec(noinline) FV3 PathBasis::FUN_0053d1a0(const FV3& v) const
{
    FV3 cross(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    float length = float(sqrt(cross.x * cross.x + cross.y * cross.y + cross.z * cross.z));
    if (length > DAT_01017cf8)
    {
        float inv = 1.0f / length;
        return FV3(cross.x * inv, cross.y * inv, cross.z * inv);
    }
    return FV3(0.0f, 0.0f, 0.0f);
}

// Computes the path basis matrix at a given time by interpolating position, tangent, and curvature, applying smoothing, axis, and bank adjustments.
// @fnv 0x00a3de50
void __thiscall PathMotion::EvaluateBasis(unsigned int aiFirstKey, unsigned int aiSecondKey, float time, FM3* out)
{
    FM3 transform;
    memcpy(&transform, &DAT_011a9448, 36);
    unsigned int count, type;
    unsigned char stride;
    MyPosKey* pKeys = GetPathKeys(count, type, stride);
    if (count < 2)
    {
        *out = transform;
        return;
    }
    {
        FV3 vPosition, vTangent, normal;
        float curvature, otherCurvature;
        if (GetBit(4))
        {
            ComputeFrenetFrame(time, GetKey(pKeys, aiFirstKey, stride), GetKey(pKeys, aiSecondKey, stride), type,
                               &vPosition, &vTangent, &normal, &curvature);
            if (smoothing != 0.0f)
            {
                float firstWeight, secondWeight;
                unsigned int index;
                if (time >= 1.0f - smoothing)
                {
                    if (!GetBit(2) && aiSecondKey == count - 1)
                        index = 0;
                    else
                        index = aiSecondKey;
                    if (index < count - 1)
                    {
                        FV3 vOtherPos, vOtherTangent;
                        firstWeight = (smoothing + (1.0f - time)) / (2.0f * smoothing);
                        secondWeight = 1.0f - firstWeight;
                        ComputeFrenetFrame(1.0f - smoothing, GetKey(pKeys, aiFirstKey, stride),
                                           GetKey(pKeys, aiSecondKey, stride), type, &vOtherPos, &vTangent, &normal,
                                           &curvature);
                        ComputeFrenetFrame(smoothing, GetKey(pKeys, index, stride), GetKey(pKeys, index + 1, stride),
                                           type, &vOtherPos, &vOtherTangent, &normal, &otherCurvature);
                        vTangent =
                            FUN_004a3760(firstWeight, vTangent).FUN_00439e90(FUN_004a3760(secondWeight, vOtherTangent));
                        vTangent.FUN_004a0c10();
                        curvature = firstWeight * curvature + secondWeight * otherCurvature;
                        normal = vPosition.FUN_004b3800(vTangent);
                    }
                }
                else if (time <= smoothing)
                {
                    if (!GetBit(2) && aiFirstKey == 0)
                        index = count - 1;
                    else
                        index = aiFirstKey;
                    if (index >= 1)
                    {
                        FV3 vOtherPos, vOtherTangent;
                        secondWeight = (smoothing - time) / (2.0f * smoothing);
                        firstWeight = 1.0f - secondWeight;
                        ComputeFrenetFrame(smoothing, GetKey(pKeys, aiFirstKey, stride),
                                           GetKey(pKeys, aiSecondKey, stride), type, &vOtherPos, &vTangent, &normal,
                                           &curvature);
                        ComputeFrenetFrame(1.0f - smoothing, GetKey(pKeys, index - 1, stride),
                                           GetKey(pKeys, index, stride), type, &vOtherPos, &vOtherTangent, &normal,
                                           &otherCurvature);
                        vTangent =
                            FUN_004a3760(firstWeight, vTangent).FUN_00439e90(FUN_004a3760(secondWeight, vOtherTangent));
                        vTangent.FUN_004a0c10();
                        curvature = firstWeight * curvature + secondWeight * otherCurvature;
                        normal = vPosition.FUN_004b3800(vTangent);
                    }
                }
            }
            transform.SetCol(0, vPosition);
            transform.SetCol(1, -vTangent);
            transform.SetCol(2, -normal);
        }
        else
        {
            ComputeFrenetFrame(time, GetKey(pKeys, aiFirstKey, stride), GetKey(pKeys, aiSecondKey, stride), type,
                               &vPosition, &vTangent, &normal, &curvature);
            transform.SetCol(0, vPosition);
            FV3 vBasis = DAT_011a9484.FUN_0053d1a0(vPosition);
            transform.SetCol(1, vBasis);
            FV3 vBinormal;
            float fCrossPosY = vPosition.y;
            float fCrossPosX = vPosition.x;
            float fCrossBasisX = vBasis.x;
            vBinormal.x = fCrossPosY * vBasis.z - vPosition.z * vBasis.y;
            vBinormal.y = fCrossBasisX * vPosition.z - fCrossPosX * vBasis.z;
            vBinormal.z = vBasis.y * fCrossPosX - fCrossBasisX * fCrossPosY;
            transform.SetCol(2, vBinormal);
        }
        if (GetBit(64))
        {
            FV3 vCol;
            transform.GetCol(0, vCol);
            transform.SetCol(0, -vCol);
            transform.GetCol(1, vCol);
            transform.SetCol(1, -vCol);
        }
        FV3 vOld;
        switch (followAxis)
        {
        case 1: {
            FV3 vCol;
            transform.GetCol(0, vOld);
            transform.GetCol(1, vCol);
            transform.SetCol(0, -vCol);
            transform.SetCol(1, vOld);
            break;
        }
        case 2: {
            FV3 vCol;
            transform.GetCol(0, vOld);
            transform.GetCol(2, vCol);
            transform.SetCol(0, -vCol);
            transform.SetCol(2, vOld);
            break;
        }
        }
        if (GetBit(8))
        {
            static const float bankFactor = DAT_01097304;
            otherCurvature = float(bankDirection) * maxBankAngle;
            if (curvature < maxCurvature)
            {
                float ratio = curvature / maxCurvature;
                otherCurvature *= bankFactor * float(atan(ratio));
            }
            FM3 rotation;
            rotation.FUN_004168a0(otherCurvature, vPosition.x, vPosition.y, vPosition.z);
            transform = rotation.FUN_0043f8d0(transform);
        }
    }
    *out = transform;
}
}  // namespace fnv_00a3de50

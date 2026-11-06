// gamebryo2.2/corelibs/nianimation/nicolordata.cpp: NiColorData, NiColorDataHack, NiColorDataA3D (9 functions)

#include "nicolordata_decls.h"

// @fnv 0x00a3d210
void NiColorData::SetColorKeys(ColorAnimationKey* keys, unsigned int count, AnimationKey::KeyType type)
{
    if (m_pKeyArray)
        DAT_011f38e8[m_eRequestType](m_pKeyArray);
    if (keys && count)
    {
        m_ucKeyDataSize = DAT_011f376a[type];
        m_pKeyArray = keys;
        m_uiNumKeys = count;
        m_eRequestType = type;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = AnimationKey::NOINTERP;
        m_ucKeyDataSize = 0;
    }
}

struct FUN_00a3d120_shell : public NiColorData
{
    void DestroyColorData();
};

extern void(__cdecl* DAT_011f38e8[])(ColorAnimationKey*);
extern const void* vftable_NiColorData;

// @fnv 0x00a3d120
void FUN_00a3d120_shell::DestroyColorData()
{
    *(const void**)this = &vftable_NiColorData;
    if (m_pKeyArray)
    {
        DAT_011f38e8[m_eRequestType](m_pKeyArray);
    }
    this->NiObject::~NiObject();
}

void __cdecl UpdateSlotStates(int, int, void*, unsigned int*, float, float);
struct NiColorDataHack
{
    char _pad[8];
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    void FUN_00a3d0e0(float m_fStartTime, float m_fMaximumDistance);
};
// @fnv 0x00a3d0e0
void NiColorDataHack::FUN_00a3d0e0(float afValue1, float afValue2)
{
    void* pkKeys = m_pKeyArray;
    UpdateSlotStates(3, m_eRequestType, &pkKeys, &m_uiNumKeys, afValue1, afValue2);
    m_pKeyArray = pkKeys;
}

namespace fnv_00a3d150 {
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00a5d3a0_standin
{
    void FUN_00a5d3a0();
};

extern int vftable_NiColorData;

// Allocates a 0x18-byte object, runs its constructor, installs the NiColorData vtable and zeroes three int fields at offsets 8, 0xc and 0x10.
// @fnv 0x00a3d150
void* CreateNiColorData()
{
    char* p = (char*)A51BF0Base::operator new(0x18);
    if (p)
    {
        ((FUN_00a5d3a0_standin*)p)->FUN_00a5d3a0();
        *(void**)p = (void*)&vftable_NiColorData;
        *(int*)(p + 8) = 0;
        *(int*)(p + 0xc) = 0;
        *(int*)(p + 0x10) = 0;
        return p;
    }
    return 0;
}
}  // namespace fnv_00a3d150

extern bool __stdcall IsSameAs(NiObject*);
extern bool(__cdecl* DAT_011f3b28[])(ColorAnimationKey*, ColorAnimationKey*);

struct FUN_00a3d190_shell : public NiColorData
{
    bool IsEqual(NiColorData* other);
};

// @fnv 0x00a3d190
bool FUN_00a3d190_shell::IsEqual(NiColorData* other)
{
    if (!IsSameAs(other))
        return false;
    if (m_uiNumKeys != other->m_uiNumKeys)
        return false;
    if (m_eRequestType != other->m_eRequestType)
        return false;
    if (m_ucKeyDataSize != other->m_ucKeyDataSize)
        return false;
    bool(__cdecl * pfnKeyCompare)(ColorAnimationKey*, ColorAnimationKey*) = DAT_011f3b28[m_eRequestType];
    for (unsigned int i = 0; i < m_uiNumKeys; ++i)
    {
        ColorAnimationKey* kOther = (ColorAnimationKey*)((char*)other->m_pKeyArray + m_ucKeyDataSize * i);
        ColorAnimationKey* kThis = (ColorAnimationKey*)((char*)m_pKeyArray + m_ucKeyDataSize * i);
        if (!pfnKeyCompare(kThis, kOther))
            return false;
    }
    return true;
}

class A3D370BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A3D370BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class A3D370Stream
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
    unsigned int m_uiFileVersion;
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
    A3D370BinaryStream* m_pUnderlyingStream;
};

template <class T> inline void A3D370BinaryStreamLoad(A3D370BinaryStream& kIstr, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kIstr.BinaryRead(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A3D370LoadBinary(A3D370Stream& kStream, T& value)
{
    A3D370BinaryStreamLoad(*kStream.m_pUnderlyingStream, &value);
}

template <class T> inline void A3D370LoadEnum(A3D370Stream& kStream, T& eValue)
{
    unsigned int uiValue;
    A3D370LoadBinary(kStream, uiValue);
    eValue = (T)uiValue;
}

class NiColorKeyA3D;

enum KeyTypeA3D
{
    NOINTERP_A3D,
    LINKEY_A3D,
    BEZKEY_A3D
};

typedef NiColorKeyA3D*(__cdecl* CreateFunctionA3D)(A3D370Stream& kStream, unsigned int uiNumKeys);
extern CreateFunctionA3D g_apfnColorKeyCreateA3D[];

class NiObjectA3D
{
  public:
    void LoadBinary(A3D370Stream& kStream);
};

class NiColorDataA3D : public NiObjectA3D
{
  public:
    void SetColorKeys(NiColorKeyA3D* pkKeys, unsigned int uiNumKeys, KeyTypeA3D eType);
    void FUN_00a3d370(A3D370Stream& kStream);
};

// Loads the base object, reads the key count, and if nonzero reads the key type and creates and stores the color keys via the matching create function.
// @fnv 0x00a3d370
void NiColorDataA3D::FUN_00a3d370(A3D370Stream& kStream)
{
    NiObjectA3D::LoadBinary(kStream);

    unsigned int uiNumKeys;
    A3D370LoadBinary(kStream, uiNumKeys);
    if (uiNumKeys > 0)
    {
        KeyTypeA3D eType;
        A3D370LoadEnum(kStream, eType);
        CreateFunctionA3D cf = g_apfnColorKeyCreateA3D[eType];
        NiColorKeyA3D* pkKeys = cf(kStream, uiNumKeys);
        SetColorKeys(pkKeys, uiNumKeys, eType);
    }
}

struct S_a3d410_Istr
{
    int unk0;
    int unk4;
    int unk8;
    unsigned(__cdecl* unkc)(S_a3d410_Istr*, void*, unsigned, unsigned*, unsigned);
};
struct S_a3d410_Stream
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    S_a3d410_Istr* unk250;
};
struct S_a3d410_Base
{
    void FUN_00a89af0(S_a3d410_Stream* s);
};
extern void(__cdecl* DAT_011f3a98[])(S_a3d410_Stream*, int, unsigned);
inline void S_a3d410_BinLoad(S_a3d410_Istr* i, void* dst, unsigned bytes)
{
    unsigned comp = bytes;
    i->unk4 += i->unkc(i, dst, bytes, &comp, 1);
}
template <class T> inline void S_a3d410_Load(S_a3d410_Stream* s, T& v)
{
    S_a3d410_BinLoad(s->unk250, &v, sizeof(T));
}
struct FUN_00a3d410_cls : S_a3d410_Base
{
    int unk0;
    int unk4;
    unsigned unk8;
    int unkc;
    unsigned unk10;
    void LoadFromStream(S_a3d410_Stream* s);
};
// Calls the base loader, reads a count into unk8, and if positive reads unk10 and dispatches DAT_011f3a98[unk10] with unkc and the count.
// @fnv 0x00a3d410
void FUN_00a3d410_cls::LoadFromStream(S_a3d410_Stream* pStream)
{
    FUN_00a89af0(pStream);
    unsigned& n = unk8;
    S_a3d410_Load(pStream, n);
    if (n > 0)
    {
        S_a3d410_Load(pStream, unk10);
        DAT_011f3a98[unk10](pStream, unkc, n);
    }
}

extern void* DAT_011f3750;

void* __cdecl FUN_00a7d330(void* p);
void* __cdecl FUN_00a7d510(const char* s, void* p);

struct FUN_00a3d490_arr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_usCap;           // +0x8
    unsigned short m_usElementCount;  // +0xa
    unsigned short unk0c;             // +0xc
    unsigned short m_usGrow;          // +0xe
    void FUN_0096ad30(unsigned int newCap);
    void FUN_0096ae90(unsigned int index, void** item);
};

class FUN_00a3d490_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    void* m_p08;  // +0x8
    void AppendCameraPathEntries(FUN_00a3d490_arr* a);
    void GetViewerStrings(FUN_00a3d490_arr* arr);
};

// @fnv 0x00a3d490
void FUN_00a3d490_cls::GetViewerStrings(FUN_00a3d490_arr* arr)
{
    AppendCameraPathEntries(arr);
    void* item = FUN_00a7d330(DAT_011f3750);
    unsigned int index = arr->m_usElementCount;
    if (index >= arr->m_usCap)
    {
        arr->FUN_0096ad30(index + arr->m_usGrow);
    }
    arr->FUN_0096ae90(index, &item);

    item = FUN_00a7d510("m_uiNumKeys", m_p08);
    index = arr->m_usElementCount;
    if (index >= arr->m_usCap)
    {
        arr->FUN_0096ad30(index + arr->m_usGrow);
    }
    arr->FUN_0096ae90(index, &item);
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* plAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* plAddend);

class NiRefObjectD27
{
  public:
    virtual ~NiRefObjectD27() throw();
    virtual void DeleteThis() throw();

    void IncRefCount() throw()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount() throw()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};

template <class T> class NiPointerD27
{
  public:
    NiPointerD27(T* pObject = 0) throw() : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    NiPointerD27(const NiPointerD27& ptr) throw() : m_pObject(ptr.m_pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerD27() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    NiPointerD27& operator=(const NiPointerD27& ptr) throw()
    {
        if (m_pObject != ptr.m_pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = ptr.m_pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }

    T* operator->() const throw()
    {
        return m_pObject;
    }

    T* m_pObject;
};

class NiDataD27 : public NiRefObjectD27
{
  public:
    void SetData(int iFirst, int iSecond, int iCount) throw();
};

void __cdecl BuildDataD27(int iType, int iCount, void* pvSource, unsigned int uiElementCount, float fFirst,
                          float fSecond, int* piFirst, int* piSecond) throw();

class FUN_00a3d270_cls
{
  public:
    void* m_ppVirtualMethodTable;
    int unk04;
    unsigned int m_uiNum;
    void* m_pvSource;
    int m_iArrayLength;

    void CreateData(NiPointerD27<NiDataD27>& spScreenData) throw();
    void BuildAndSetData(float fFirst, float fSecond, NiPointerD27<NiDataD27>& spResult);
};

// Creates a NiDataD27, fills it via BuildDataD27 when m_uiNum > 0, sets its data, and assigns it to spResult.
// @fnv 0x00a3d270
void FUN_00a3d270_cls::BuildAndSetData(float fFirst, float fSecond, NiPointerD27<NiDataD27>& spResult)
{
    NiPointerD27<NiDataD27> spCreated;
    CreateData(spCreated);
    NiPointerD27<NiDataD27> spScreenData = spCreated;
    if (m_uiNum > 0)
    {
        int iFirst = 0;
        int iSecond = 0;
        BuildDataD27(3, m_iArrayLength, m_pvSource, m_uiNum, fFirst, fSecond, &iFirst, &iSecond);
        spScreenData->SetData(iFirst, iSecond, m_iArrayLength);
    }
    spResult = spScreenData;
}

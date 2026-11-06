// gamebryo2.2/corelibs/nianimation/niposdata.cpp: NiPosData, MyPosData, Holder, PosKeyData (10 functions)

#include "niposdata_decls.h"
// @fnv 0x00a490e0
void NiPosData::SetColorKeys(PositionKeyInterpolator* keys, unsigned int count, AnimationKey::KeyType eKeyType)
{
    if (m_pKeyArray)
        DAT_011f38b8[m_eRequestType](m_pKeyArray);
    if (keys && count)
    {
        m_ucKeyDataSize = GetPosKeySize(eKeyType);
        m_pKeyArray = keys;
        m_uiNumKeys = count;
        m_eRequestType = eKeyType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = AnimationKey::NOINTERP;
        m_ucKeyDataSize = 0;
    }
}

// @fnv 0x00a49240
void NiPosData::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    unsigned int count;
    stream.input->Read(&count, 4);
    if (count > 0)
    {
        AnimationKey::KeyType type = stream.ReadType();
        m_ucKeyDataSize = GetPosKeySize(type);
        PositionKeyInterpolator* keys = GetCreatePosKeys(type)(stream, count);
        GetFillPosKeys(type)(keys, count, m_ucKeyDataSize);
        SetColorKeys(keys, count, type);
    }
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
extern int DAT_0109717c;
struct BaseUnk
{
    void _Call_a5d3a0();
    void* vtable;
    int _04;
};
struct Derived : BaseUnk
{
    int m08;
    int m0C;
    int m10;
    char m14;
};
// @fnv 0x00a49020
Derived* FUN_00a49020()
{
    Derived* p = (Derived*)BSFadeNode::operator new(sizeof(Derived));
    if (p)
    {
        p->_Call_a5d3a0();
        p->m08 = 0;
        p->m0C = 0;
        p->m10 = 0;
        p->m14 = 0;
        p->vtable = (void*)&DAT_0109717c;
        return p;
    }
    return 0;
}

void __cdecl UpdateSlotStates(int, int, void*, void*, float, float);
struct MyPosData
{
    void* vtable;
    int _04;
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    void FUN_00a48f70(float, float);
};
// Calls UpdateSlotStates with the key count and key pointer, then stores the updated key pointer back.
// @fnv 0x00a48f70
void MyPosData::FUN_00a48f70(float afArg1, float afArg2)
{
    void* pkKeys = m_pKeyArray;
    UpdateSlotStates(1, m_eRequestType, &pkKeys, &m_uiNumKeys, afArg1, afArg2);
    m_pKeyArray = pkKeys;
}

struct NiRefObject
{
    virtual ~NiRefObject();
    int _04;
};
struct Holder : NiRefObject
{
    int _08;
    PositionKeyInterpolator* _0C;
    int _10;
    void FUN_00a48fb0();
};
// Restores the vtable, calls the stored callback on the pointer at _0C if set, then destroys the NiRefObject base.
// @fnv 0x00a48fb0
void Holder::FUN_00a48fb0()
{
    PositionKeyInterpolator* p = _0C;
    *(int*)this = (int)&DAT_0109717c;
    if (p)
        DAT_011f38b8[_10](p);
    this->NiRefObject::~NiRefObject();
}

extern unsigned char DAT_011f375e[];
struct S_00a48fe0
{
    int _00;
    int _04;
    unsigned int _08;
    void* _0c;
    int _10;
    unsigned char _14;
    void FUN_00a48fe0(void* keys, unsigned int numKeys, int type);
};
// Stores the key array, key count and type, setting a byte from DAT_011f375e indexed by type; clears all fields when keys or numKeys is null/zero.
// @fnv 0x00a48fe0
void S_00a48fe0::FUN_00a48fe0(void* keys, unsigned int numKeys, int type)
{
    if (keys && numKeys)
    {
        _14 = DAT_011f375e[type];
        _0c = keys;
        _08 = numKeys;
        _10 = type;
    }
    else
    {
        _08 = 0;
        _0c = 0;
        _14 = 0;
        _10 = 0;
    }
}

struct PosKeyData
{
    void* vtable;
    int refs;
    unsigned int m_uiNumKeys;
    unsigned char* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    bool IsSameAs(const PosKeyData* other);
    bool Equals(const PosKeyData* other);
};
typedef bool(__cdecl* KeyEqual)(const void*, const void*);
extern KeyEqual DAT_011f3af8[];

// @fnv 0x00a49060
bool PosKeyData::Equals(const PosKeyData* other)
{
    if (!IsSameAs(other))
        return false;

    if (m_uiNumKeys != other->m_uiNumKeys || m_eRequestType != other->m_eRequestType ||
        m_ucKeyDataSize != other->m_ucKeyDataSize)
        return false;

    KeyEqual pfnEqualKeys = DAT_011f3af8[m_eRequestType];
    for (unsigned int i = 0; i < m_uiNumKeys; ++i)
    {
        unsigned int offset = i * m_ucKeyDataSize;
        const unsigned char* otherKey = other->m_pKeyArray + offset;
        const unsigned char* currentKey = m_pKeyArray + offset;
        if (!pfnEqualKeys(currentKey, otherKey))
            return false;
    }
    return true;
}

class A49300BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A49300BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A49300BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n)
    {
        unsigned int size = n;
        return BinaryWrite(p, n, &size, 1);
    }
};

class A49300Stream
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
    int unk24C;
    A49300BinaryStream* m_pBackingStream;
};

typedef void (*A49300SaveFunc)(A49300Stream& kStream, void* pvData, unsigned int ItemUpdateArray);
extern A49300SaveFunc g_apfnA49300Save[];

class A49300Base
{
  public:
    int unk00;
    int unk04;

    void FUN_00a89af0(A49300Stream& kStream);
};

class A49300Data : public A49300Base
{
  public:
    unsigned int m_uiCount;
    void* m_pResource;
    unsigned int m_uiType;

    void SaveToStream(A49300Stream& kStream);
};

// SaveBinary
// @fnv 0x00a49300
void A49300Data::SaveToStream(A49300Stream& kStream)
{
    FUN_00a89af0(kStream);
    kStream.m_pBackingStream->Write(&m_uiCount, 4);
    if (m_uiCount > 0)
    {
        kStream.m_pBackingStream->Write(&m_uiType, 4);
        g_apfnA49300Save[m_uiType](kStream, m_pResource, m_uiCount);
    }
}

extern char str_01097164[];
extern int DAT_011f3f68;
extern int __cdecl FUN_00a7d330(int);
extern int __cdecl FUN_00a7d510(char*, int);

struct FUN_0096ad30_param
{
    void* vtable;
    int unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    void FUN_0096ad30(unsigned int);
    void FUN_0096ae90(unsigned int, unsigned int*);
};

struct Owner_00a49380
{
    void* vtable;
    int unk04;
    int unk08;
    void AppendCameraPathEntries(FUN_0096ad30_param*);
    void GetViewerStrings(FUN_0096ad30_param*);
};

// @fnv 0x00a49380
void Owner_00a49380::GetViewerStrings(FUN_0096ad30_param* param)
{
    unsigned int value;
    unsigned int index;

    AppendCameraPathEntries(param);
    value = FUN_00a7d330(DAT_011f3f68);
    index = param->unk0A;
    if (index >= (unsigned int)param->unk08)
    {
        param->FUN_0096ad30((unsigned int)param->unk0E + index);
    }
    param->FUN_0096ae90(index, &value);
    value = FUN_00a7d510(str_01097164, unk08);
    index = param->unk0A;
    if (index >= (unsigned int)param->unk08)
    {
        param->FUN_0096ad30((unsigned int)param->unk0E + index);
    }
    param->FUN_0096ae90(index, &value);
}

#include <windows.h>
class RefCountedObj
{
  public:
    virtual ~RefCountedObj();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    void FUN_00a490e0(int a, unsigned int b, unsigned int c);
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((volatile long*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

void FUN_00a3d630(int, int, int, int, float, float, unsigned int*, unsigned int*);

class FUN_00a49140_cls
{
  public:
    int unk00;
    int unk04;
    unsigned int m_08;
    RefCountedObj* m_0C;
    int m_10;

    void FUN_00a5d510(RefCountedObj** out);
    void FUN_00a49140(float a1, float a2, RefCountedObj** out);
};

// @fnv 0x00a49140
void FUN_00a49140_cls::FUN_00a49140(float a1, float a2, RefCountedObj** apObj)
{
    RefCountedObj* tmp;
    unsigned int uiOut2;
    unsigned int uiOut1;
    tmp = 0;
    FUN_00a5d510(&tmp);
    RefCountedObj* p = tmp;
    if (p != 0)
    {
        p->IncRefCount();
    }
    if (m_08 > 0)
    {
        uiOut1 = 0;
        uiOut2 = 0;
        FUN_00a3d630(1, m_10, (int)m_0C, (int)m_08, a1, a2, &uiOut1, &uiOut2);
        p->FUN_00a490e0(uiOut1, uiOut2, m_10);
    }
    RefCountedObj* old = *apObj;
    if (old != p)
    {
        if (old != 0)
        {
            old->DecRefCount();
        }
        *apObj = p;
        if (p != 0)
        {
            p->IncRefCount();
        }
    }
    if (p != 0)
    {
        p->DecRefCount();
    }
    if (tmp != 0)
    {
        tmp->DecRefCount();
    }
}

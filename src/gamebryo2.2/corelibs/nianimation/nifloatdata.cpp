// gamebryo2.2/corelibs/nianimation/nifloatdata.cpp: NiFloatData (10 functions)

#include "nifloatdata_decls.h"

// @fnv 0x00a3cdc0
void NiFloatData::SetColorKeys(TimedAnimationKey* keys, unsigned int count, AnimationKey::KeyType eKeyType)
{
    if (m_pKeyArray)
        DAT_011f38a0[m_eRequestType](m_pKeyArray);
    if (keys && count && eKeyType)
    {
        m_ucKeyDataSize = DAT_011f3758[eKeyType];
        m_pKeyArray = keys;
        m_uiNumKeys = count;
        m_eRequestType = eKeyType;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_ucKeyDataSize = 0;
        m_eRequestType = AnimationKey::NiAnimationKey__KeyType_NOINTERP;
    }
}

struct FUN_00a3cc80_shell : public NiFloatData
{
    void FUN_00a3cc80();
};

extern void(__cdecl* DAT_011f38a0[])(TimedAnimationKey*);
extern const void* vftable_NiFloatData[];
void __fastcall FUN_00a5d3d0(NiObject*);

// @fnv 0x00a3cc80
void FUN_00a3cc80_shell::FUN_00a3cc80()
{
    *(const void***)this = vftable_NiFloatData;
    if (m_pKeyArray)
    {
        DAT_011f38a0[m_eRequestType](m_pKeyArray);
    }
    FUN_00a5d3d0(this);
}

void __cdecl UpdateSlotStates(int, int, void*, void*, float, float);
struct S00a3cc40
{
    char _0[8];
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    void FUN_00a3cc40(float m_fStartTime, float m_fMaximumDistance);
};
// Calls UpdateSlotStates with the key count, key pointer and two floats, then stores the updated key pointer back.
// @fnv 0x00a3cc40
void S00a3cc40::FUN_00a3cc40(float m_fStartTime, float m_fMaximumDistance)
{
    void* pkKeys = m_pKeyArray;
    UpdateSlotStates(0, m_eRequestType, &pkKeys, &m_uiNumKeys, m_fStartTime, m_fMaximumDistance);
    m_pKeyArray = pkKeys;
}

extern unsigned char DAT_41890871[];
struct FUN_00a3ccb0_Cls
{
    char _pad0[8];
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void FUN_00a3ccb0(void* keys, unsigned int numKeys, int type);
};
// Stores the keys pointer, key count and type, caching DAT_41890871[type] as a byte; clears all fields when any argument is null or zero.
// @fnv 0x00a3ccb0
void FUN_00a3ccb0_Cls::FUN_00a3ccb0(void* keys, unsigned int numKeys, int type)
{
    if (keys && numKeys && type)
    {
        m_ucKeyDataSize = DAT_41890871[type];
        m_pKeyArray = keys;
        m_uiNumKeys = numKeys;
        m_eRequestType = type;
    }
    else
    {
        m_uiNumKeys = 0;
        m_pKeyArray = 0;
        m_eRequestType = 0;
        m_ucKeyDataSize = 0;
    }
}

namespace fnv_00a3cd00 {
struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int size);
};

void __fastcall _Call_a5d3a0(void* object);

extern const char vftable_NiFloatData[];

// @fnv 0x00a3cd00
NiFloatData* CreateNiFloatData()
{
    NiFloatData* object = static_cast<NiFloatData*>(A51BF0Base::operator new(0x18));

    if (object)
    {
        _Call_a5d3a0(object);

        object->m_uiNumKeys = 0;
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(object) + 0x0c) = 0;
        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(object) + 0x10) = 0;
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(object) + 0x14) = 0;

        *reinterpret_cast<void**>(object) = const_cast<void*>(static_cast<const void*>(vftable_NiFloatData));
        return object;
    }

    return 0;
}
}  // namespace fnv_00a3cd00

struct StrArr
{
    void* m_pvtable;
    unsigned int m_uiRefCount;
    unsigned short m_uiCapacity;
    unsigned short m_uiNumSlots;
    unsigned short m_uiValue5;
    unsigned short m_uiGrowSize;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct GlobalObjectO2_00a7b610
{
};

struct FUN_00a3d050_shell
{
    void* m_pvtable;
    unsigned int m_uiReserved;
    unsigned int m_uiNumKeys;

    void GetViewerStrings(StrArr* strings);
};

extern GlobalObjectO2_00a7b610* g_011f3748;

void __stdcall AppendCameraPathEntries(StrArr* strings);
char* __cdecl _FUN_00a7d330(GlobalObjectO2_00a7b610* object);
char* __cdecl FUN_00a7d510(char const* name, unsigned int value);

// @fnv 0x00a3d050
void FUN_00a3d050_shell::GetViewerStrings(StrArr* strings)
{
    AppendCameraPathEntries(strings);

    char* value = _FUN_00a7d330(g_011f3748);
    unsigned int index = strings->m_uiNumSlots;
    unsigned int capacity = strings->m_uiCapacity;

    if (index >= capacity)
        strings->SetSize(index + strings->m_uiGrowSize);

    strings->SetAt(index, value);

    value = FUN_00a7d510("m_uiNumKeys", m_uiNumKeys);
    index = strings->m_uiNumSlots;
    capacity = strings->m_uiCapacity;

    if (index >= capacity)
        strings->SetSize(index + strings->m_uiGrowSize);

    strings->SetAt(index, value);
}

struct WriteStream
{
    void* data00;
    unsigned int position04;
    unsigned int unk08;
    unsigned int(__cdecl* write0c)(WriteStream*, const void*, unsigned int, unsigned int*, int);
    __forceinline void Write(const void* data)
    {
        unsigned int size = 4;
        position04 += write0c(this, data, 4, &size, 1);
    }
};
struct NiStream
{
    WriteStream* GetWriter()
    {
        return *reinterpret_cast<WriteStream**>((char*)this + 0x250);
    }
};
struct NiObject_Ext : NiObject
{
    void FUN_00a89af0(NiStream*);
};
struct FUN_00a3cfd0_shell : NiFloatData
{
    void WriteToStream(NiStream*);
};
extern void(__cdecl* DAT_011f3a50[])(NiStream*, TimedAnimationKey*, unsigned int);
// @fnv 0x00a3cfd0
void FUN_00a3cfd0_shell::WriteToStream(NiStream* stream)
{
    reinterpret_cast<NiObject_Ext*>(this)->FUN_00a89af0(stream);
    stream->GetWriter()->Write(&m_uiNumKeys);
    if (m_uiNumKeys > 0)
    {
        stream->GetWriter()->Write(&m_eRequestType);
        DAT_011f3a50[m_eRequestType](stream, m_pKeyArray, m_uiNumKeys);
    }
}

struct FUN_00a3ce20_shell : public NiFloatData
{
    void FUN_00a3ce20(float m_fStartTime, float m_fMaximumDistance, NiFloatData** ppResult);
    void FUN_00a5d510(NiFloatData** ppOut);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* Addend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* Addend);

struct NiRefShell : public NiObject
{
    virtual void ReleaseObject();
    void AcquireReference()
    {
        InterlockedIncrement((volatile long*)&refCount);
    }
    void DecRef()
    {
        if (InterlockedDecrement((volatile long*)&refCount) == 0)
            ReleaseObject();
    }
};

extern void __cdecl FUN_00a3d630(int, int, TimedAnimationKey*, unsigned int, float, float, TimedAnimationKey**,
                                 unsigned int*);

// @fnv 0x00a3ce20
void FUN_00a3ce20_shell::FUN_00a3ce20(float m_fStartTime, float m_fMaximumDistance, NiFloatData** ppResult)
{
    NiFloatData* pData = 0;
    FUN_00a5d510(&pData);
    NiFloatData* pCur = pData;
    if (pCur != 0)
        ((NiRefShell*)pCur)->AcquireReference();
    if (m_uiNumKeys > 0)
    {
        TimedAnimationKey* pKeys = 0;
        unsigned int uiNumKeys = 0;
        FUN_00a3d630(0, (int)m_eRequestType, m_pKeyArray, m_uiNumKeys, m_fStartTime, m_fMaximumDistance, &pKeys,
                     &uiNumKeys);
        pCur->SetColorKeys(pKeys, uiNumKeys, m_eRequestType);
    }
    NiFloatData* pOld = *ppResult;
    if (pOld != pCur)
    {
        if (pOld != 0)
            ((NiRefShell*)pOld)->DecRef();
        *ppResult = pCur;
        if (pCur != 0)
            ((NiRefShell*)pCur)->AcquireReference();
    }
    if (pCur != 0)
        ((NiRefShell*)pCur)->DecRef();
    if (pData != 0)
        ((NiRefShell*)pData)->DecRef();
}

typedef bool(__cdecl* FUN_00a3cd40_KeyCmp)(void*, void*);
extern FUN_00a3cd40_KeyCmp DAT_011f3ae0[];

struct FUN_00a3cd40_cls : public NiFloatData
{
    bool IsSameAs(NiFloatData* other);
    bool IsEqual(NiFloatData* other);
};

// Compares this NiFloatData with another by checking key count, request type, key data size, and each key via a type-specific comparator.
// @fnv 0x00a3cd40
bool FUN_00a3cd40_cls::IsEqual(NiFloatData* other)
{
    if (!IsSameAs(other))
    {
        return false;
    }
    if (m_uiNumKeys != other->m_uiNumKeys)
    {
        return false;
    }
    if (m_eRequestType != other->m_eRequestType)
    {
        return false;
    }
    if (m_ucKeyDataSize != other->m_ucKeyDataSize)
    {
        return false;
    }
    FUN_00a3cd40_KeyCmp cmp = DAT_011f3ae0[m_eRequestType];
    unsigned int iKeyIndex = 0;
    if (m_uiNumKeys > 0)
    {
        do
        {
            void* a = (char*)other->m_pKeyArray + (unsigned int)m_ucKeyDataSize * iKeyIndex;
            void* n = (char*)m_pKeyArray + (unsigned int)m_ucKeyDataSize * iKeyIndex;
            if (!cmp(n, a))
            {
                return false;
            }
            ++iKeyIndex;
        } while (iKeyIndex < m_uiNumKeys);
    }
    return true;
}

typedef TimedAnimationKey*(__cdecl* CreateFn_cf)(NiStream&, unsigned int);
typedef void(__cdecl* FillFn_cf)(TimedAnimationKey*, unsigned int, unsigned char);
extern CreateFn_cf DAT_011f3db0[];
extern FillFn_cf DAT_011f3780[];

struct StreamStand_cf
{
    void* vtable;
    unsigned int refCount;
    void LoadStream(NiStream& stream);
};

struct KeyOwnerStand_cf
{
    void* vtable;
    unsigned int refCount;
    unsigned int m_uiNumKeys;
    void* m_pKeyArray;
    int m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void SetKeyData(TimedAnimationKey* keys, unsigned int numKeys, int type);
};

struct StreamBinView_cf
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int(__cdecl* read)(StreamBinView_cf* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

template <class T> inline void LoadEnum(StreamBinView_cf* istr, T& v)
{
    unsigned int u;
    istr->Load(&u);
    v = (T)u;
}

struct StreamView_cf
{
    void* vtable;
    unsigned int version;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    void* unkB0;
    void* unkB4;
    void* unkB8;
    void* unkBC;
    void* unkC0;
    void* unkC4;
    void* unkC8;
    void* unkCC;
    void* unkD0;
    void* unkD4;
    void* unkD8;
    void* unkDC;
    void* unkE0;
    void* unkE4;
    void* unkE8;
    void* unkEC;
    void* unkF0;
    void* unkF4;
    void* unkF8;
    void* unkFC;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10C;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11C;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12C;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13C;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14C;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15C;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16C;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17C;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18C;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19C;
    void* unk1A0;
    void* unk1A4;
    void* unk1A8;
    void* unk1AC;
    void* unk1B0;
    void* unk1B4;
    void* unk1B8;
    void* unk1BC;
    void* unk1C0;
    void* unk1C4;
    void* unk1C8;
    void* unk1CC;
    void* unk1D0;
    void* unk1D4;
    void* unk1D8;
    void* unk1DC;
    void* unk1E0;
    void* unk1E4;
    void* unk1E8;
    void* unk1EC;
    void* unk1F0;
    void* unk1F4;
    void* unk1F8;
    void* unk1FC;
    void* unk200;
    void* unk204;
    void* unk208;
    void* unk20C;
    void* unk210;
    void* unk214;
    void* unk218;
    void* unk21C;
    void* unk220;
    void* unk224;
    void* unk228;
    void* unk22C;
    void* unk230;
    void* unk234;
    void* unk238;
    void* unk23C;
    void* unk240;
    void* unk244;
    void* unk248;
    StreamBinView_cf* m_pUnderlyingStream;
};

struct FUN_00a3cf10_cls : public NiFloatData
{
    void FUN_00a3cf10(NiStream& stream);
};

// Loads animation key data from a NiStream, reading key count, type, and key values, then stores them via SetKeyData.
// @fnv 0x00a3cf10
void FUN_00a3cf10_cls::FUN_00a3cf10(NiStream& stream)
{
    reinterpret_cast<StreamStand_cf*>(this)->LoadStream(stream);
    StreamView_cf* pStreamView = reinterpret_cast<StreamView_cf*>(&stream);
    unsigned int numKeys;

    pStreamView->m_pUnderlyingStream->Load(&numKeys);
    if (numKeys > 0)
    {
        AnimationKey::KeyType keyType;
        LoadEnum(pStreamView->m_pUnderlyingStream, keyType);
        m_ucKeyDataSize = DAT_011f3758[keyType];
        CreateFn_cf pCreateFn = DAT_011f3db0[keyType];
        TimedAnimationKey* keys = pCreateFn(stream, numKeys);
        FillFn_cf pFillFn = DAT_011f3780[keyType];
        pFillFn(keys, numKeys, m_ucKeyDataSize);
        reinterpret_cast<KeyOwnerStand_cf*>(this)->SetKeyData(keys, numKeys, keyType);
    }
}


// gamebryo2.2/corelibs/nimain/nitextureeffect.cpp
// NiTextureEffect: static texture-type string table init.
#include "nitextureeffect.h"

NiFixedString NiTextureEffect::ms_kTextureEffectNames[4];

// Initializes the four NiFixedString entries with the strings ProjectedLight, ProjectedShadow, EnvironmentMap and FogMap, releasing the previous handles.
// @fnv 0x00a927e0
void NiTextureEffect::InitializePoint3()
{
    char* pcOld = ms_kTextureEffectNames[0].m_kHandle;
    if (pcOld != "ProjectedLight")
    {
        ms_kTextureEffectNames[0].m_kHandle = NiGlobalStringTable::AddString("ProjectedLight");
        if (pcOld != EmptyFS.m_kHandle)
            InterlockedDecrement((LONG*)(pcOld - 8));
    }

    pcOld = ms_kTextureEffectNames[1].m_kHandle;
    if (pcOld != "ProjectedShadow")
    {
        ms_kTextureEffectNames[1].m_kHandle = NiGlobalStringTable::AddString("ProjectedShadow");
        if (pcOld != EmptyFS.m_kHandle)
            InterlockedDecrement((LONG*)(pcOld - 8));
    }

    pcOld = ms_kTextureEffectNames[2].m_kHandle;
    if (pcOld != "EnvironmentMap")
    {
        ms_kTextureEffectNames[2].m_kHandle = NiGlobalStringTable::AddString("EnvironmentMap");
        if (pcOld != EmptyFS.m_kHandle)
            InterlockedDecrement((LONG*)(pcOld - 8));
    }

    pcOld = ms_kTextureEffectNames[3].m_kHandle;
    if (pcOld != "FogMap")
    {
        ms_kTextureEffectNames[3].m_kHandle = NiGlobalStringTable::AddString("FogMap");
        if (pcOld != EmptyFS.m_kHandle)
            InterlockedDecrement((LONG*)(pcOld - 8));
    }
}

extern int g_011f5e94;

// @fnv 0x00a927d0
int* __cdecl FUN_00a927d0()
{
    return &g_011f5e94;
}

extern long DAT_011f5ea0;
extern long DAT_011f5ea4;
extern long DAT_011f5ea8;

struct FUN_00a928b0_shell : NiTextureEffect
{
    void ClearFixedStrings();
};

// @fnv 0x00a928b0
void FUN_00a928b0_shell::ClearFixedStrings()
{
    NiFixedString* arr = ms_kTextureEffectNames;
    char* pOldHandle = arr[0].m_kHandle;
    if (pOldHandle != 0)
    {
        arr[0].m_kHandle = NiGlobalStringTable::AddString(0);
        if (pOldHandle != EmptyFS.m_kHandle)
            InterlockedDecrement((long*)(pOldHandle - 8));
    }
    pOldHandle = (char*)DAT_011f5ea0;
    if (pOldHandle != 0)
    {
        DAT_011f5ea0 = (long)NiGlobalStringTable::AddString(0);
        if (pOldHandle != EmptyFS.m_kHandle)
            InterlockedDecrement((long*)(pOldHandle - 8));
    }
    pOldHandle = (char*)DAT_011f5ea4;
    if (pOldHandle != 0)
    {
        DAT_011f5ea4 = (long)NiGlobalStringTable::AddString(0);
        if (pOldHandle != EmptyFS.m_kHandle)
            InterlockedDecrement((long*)(pOldHandle - 8));
    }
    pOldHandle = (char*)DAT_011f5ea8;
    if (pOldHandle != 0)
    {
        DAT_011f5ea8 = (long)NiGlobalStringTable::AddString(0);
        if (pOldHandle != EmptyFS.m_kHandle)
            InterlockedDecrement((long*)(pOldHandle - 8));
    }
}

class NiStream;
struct FUN_00a6ff10_holder
{
    bool FUN_00a6ff10(NiStream&);
};
struct RegHolder54
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
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
    virtual bool RegFunc(NiStream&);
};
struct FUN_00a92a30_shell : NiTextureEffect
{
    bool RegisterStreamables(NiStream&);
};
// @fnv 0x00a92a30
bool FUN_00a92a30_shell::RegisterStreamables(NiStream& kStream)
{
    if (!((FUN_00a6ff10_holder*)this)->FUN_00a6ff10(kStream))
        return false;
    RegHolder54* pkObj = *(RegHolder54**)((char*)this + 0x124);
    if (pkObj)
        pkObj->RegFunc(kStream);
    return true;
}

namespace fnv_00a929d0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct NiObject
{
    volatile long m_iObjectReferenceCount;
    virtual void _f0();
    virtual void _f1();
};
struct NiStream
{
    NiObject* GetLoadedObject();
};
struct NiDynamicEffect
{
    virtual void LinkObject(NiStream&);
};
struct FUN_00a929d0_Holder : NiDynamicEffect
{
    char _pad[0x120];
    NiObject* m_pObject;
    void FUN_00a929d0(NiStream&);
};
// Links the stream's object to m_pObject, releasing the previous object and incrementing the new one's reference count.
// @fnv 0x00a929d0
void FUN_00a929d0_Holder::FUN_00a929d0(NiStream& kStream)
{
    NiDynamicEffect::LinkObject(kStream);
    NiObject* pkObj = kStream.GetLoadedObject();
    NiObject* pOld = m_pObject;
    if (pOld != pkObj)
    {
        if (pOld && InterlockedDecrement(&pOld->m_iObjectReferenceCount) == 0)
            pOld->_f1();
        m_pObject = pkObj;
        if (pkObj)
            InterlockedIncrement(&pkObj->m_iObjectReferenceCount);
    }
}
}  // namespace fnv_00a929d0

extern int DAT_0109fd0c;
extern float DAT_011a9448[32];
extern float DAT_011a946c;

struct FUN_00a92710_base
{
    void Init();
};

struct Mat3x3
{
    float m[9];
};

struct Sub16
{
    float m[4];
    void Init(float*, float);
};

struct FUN_00a92710_cls : FUN_00a92710_base
{
    int m_vptr00;
    unsigned char m_unk04[0x99];
    unsigned char m_9d;
    unsigned char m_unk9e[0x26];
    Mat3x3 m_mat1;
    float m_e8;
    float m_ec;
    float m_f0;
    Mat3x3 m_mat2;
    float m_118;
    float m_11c;
    float m_120;
    int m_124;
    int m_128;
    int m_12c;
    int m_130;
    int m_134;
    unsigned char m_138;
    unsigned char m_auiShapeKeys[3];
    Sub16 m_sub1;
    Sub16 m_sub2;

    void* FUN_00a92710();
};

// Calls the base Init, sets the vtable pointer, copies a matrix into m_mat1 and m_mat2, zeroes several floats and ints, and initialises m_sub1 and m_sub2.
// @fnv 0x00a92710
void* FUN_00a92710_cls::FUN_00a92710()
{
    FUN_00a92710_base* base = reinterpret_cast<FUN_00a92710_base*>(this);
    base->Init();
    m_vptr00 = (int)&DAT_0109fd0c;
    m_mat1 = *(Mat3x3*)&DAT_011a9448[0];
    m_e8 = 0.0f;
    m_ec = 0.0f;
    m_f0 = 0.0f;
    m_mat2 = *(Mat3x3*)&DAT_011a9448[0];
    m_118 = 0.0f;
    m_11c = 0.0f;
    m_120 = 0.0f;
    m_124 = 0;
    m_sub1.Init(&DAT_011a946c, 0.0f);
    m_sub2.Init(&DAT_011a946c, 0.0f);
    m_128 = 0;
    m_130 = 0;
    m_134 = 0;
    m_138 = 0;
    m_9d = 5;
    m_12c = 3;
    return this;
}

int __cdecl FUN_00aa1360(const char*, const char*);

struct TexTypeAccess : NiTextureEffect
{
    static const NiFixedString& Str(unsigned int ui)
    {
        return ms_kTextureEffectNames[ui];
    }
};

bool FixedSame(const char* pcTable, const char* pcKey)
{
    if (pcTable == pcKey)
        return true;
    if (pcKey != 0 && pcTable != 0)
        return FUN_00aa1360(pcTable, pcKey) == 0;
    return false;
}

// Searches the four texture-effect type strings for one matching kType and, on a match, stores its index in uiType and returns true.
// @fnv 0x00a92960
bool FindTexTypeIndex(const NiFixedString& kType, unsigned int& uiType)
{
    for (unsigned int ui = 0; ui < 4; ui++)
    {
        if (FixedSame(TexTypeAccess::Str(ui).m_kHandle, kType.m_kHandle))
        {
            uiType = ui;
            return true;
        }
    }
    return false;
}

namespace fnv_00a92bd0 {
extern "C" void* DAT_0109fd0c;

struct RegistrationManager
{
    void** vtable;
    void Deregister(void* object)
    {
        typedef void(__thiscall * Function)(RegistrationManager*, void*);
        Function callback = reinterpret_cast<Function>(vtable[62]);
        callback(this, object);
    }
};
extern RegistrationManager* DAT_011f4748;

struct RefCounted
{
    void** vtable;
    volatile long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            typedef void(__thiscall * DeleteFunction)(RefCounted*);
            reinterpret_cast<DeleteFunction>(vtable[1])(this);
        }
    }
};

void __cdecl FUN_00aa1460(void* object, unsigned int size);

struct TextureEffectMatch
{
    void** m_ppVirtualMethodTable;
    void DestroyDynamicEffect();
    TextureEffectMatch* FUN_00a92bd0(unsigned int flags);
};

// @fnv 0x00a92bd0
TextureEffectMatch* TextureEffectMatch::FUN_00a92bd0(unsigned int flags)
{
    m_ppVirtualMethodTable = reinterpret_cast<void**>(&DAT_0109fd0c);
    if (DAT_011f4748)
        DAT_011f4748->Deregister(this);
    RefCounted* resource = *reinterpret_cast<RefCounted**>(reinterpret_cast<char*>(this) + 0x124);
    if (resource)
        resource->DecRefCount();
    DestroyDynamicEffect();
    if (flags & 1)
        FUN_00aa1460(this, 0x15c);
    return this;
}
}  // namespace fnv_00a92bd0

struct CallTarget_00a68c60
{
    int FUN_00a68c60(int);
};
struct CallTarget_00a92c40
{
    int UpdateWorldProjection();
};
struct SearchObject
{
    int UpdateWorldData(unsigned int arg0);
};
// @fnv 0x00a92ef0
int SearchObject::UpdateWorldData(unsigned int arg0)
{
    unsigned int callResult0 = (unsigned int)((CallTarget_00a68c60*)this)->FUN_00a68c60((int)arg0);
    unsigned int callResult1 = (unsigned int)((CallTarget_00a92c40*)this)->UpdateWorldProjection();
    return (int)callResult1;
}

class SubCmpA
{
  public:
    bool Equal(void* other);
};
class SubCmpB
{
  public:
    bool Equal(void* other);
};
class SubCmpC
{
  public:
    bool Equal(void* other);
};
class FUN_00a93040_cls
{
  public:
    bool IsEqual(FUN_00a93040_cls* other);
    bool FUN_00a93040(FUN_00a93040_cls* other);
    unsigned int unk_000;
    unsigned int unk_004;
    unsigned int unk_008;
    unsigned int unk_00c;
    unsigned int unk_010;
    unsigned int unk_014;
    unsigned int unk_018;
    unsigned int unk_01c;
    unsigned int unk_020;
    unsigned int unk_024;
    unsigned int unk_028;
    unsigned int unk_02c;
    unsigned int unk_030;
    unsigned int unk_034;
    unsigned int unk_038;
    unsigned int unk_03c;
    unsigned int unk_040;
    unsigned int unk_044;
    unsigned int unk_048;
    unsigned int unk_04c;
    unsigned int unk_050;
    unsigned int unk_054;
    unsigned int unk_058;
    unsigned int unk_05c;
    unsigned int unk_060;
    unsigned int unk_064;
    unsigned int unk_068;
    unsigned int unk_06c;
    unsigned int unk_070;
    unsigned int unk_074;
    unsigned int unk_078;
    unsigned int unk_07c;
    unsigned int unk_080;
    unsigned int unk_084;
    unsigned int unk_088;
    unsigned int unk_08c;
    unsigned int unk_090;
    unsigned int unk_094;
    unsigned int unk_098;
    unsigned int unk_09c;
    unsigned int unk_0a0;
    unsigned int unk_0a4;
    unsigned int unk_0a8;
    unsigned int unk_0ac;
    unsigned int unk_0b0;
    unsigned int unk_0b4;
    unsigned int unk_0b8;
    unsigned int unk_0bc;
    unsigned int unk_0c0;
    unsigned int unk_0c4;
    unsigned int unk_0c8;
    unsigned int unk_0cc;
    unsigned int unk_0d0;
    unsigned int unk_0d4;
    unsigned int unk_0d8;
    unsigned int unk_0dc;
    unsigned int unk_0e0;
    unsigned int unk_0e4;
    unsigned int unk_0e8;
    unsigned int unk_0ec;
    unsigned int unk_0f0;
    unsigned int unk_0f4;
    unsigned int unk_0f8;
    unsigned int unk_0fc;
    unsigned int unk_100;
    unsigned int unk_104;
    unsigned int unk_108;
    unsigned int unk_10c;
    unsigned int unk_110;
    unsigned int unk_114;
    unsigned int unk_118;
    unsigned int unk_11c;
    unsigned int unk_120;
    unsigned int unk_124;
    unsigned int m_128;
    unsigned int m_12c;
    unsigned int m_130;
    unsigned int m_134;
    unsigned char m_138;
    unsigned char unk_139;
    unsigned short unk_13a;
    unsigned int unk_13c;
};
// Returns true when IsEqual succeeds, the unk_0c4 subobjects match, the unk_0e8 and unk_13c subobjects differ, and m_128 through m_138 are equal.
// @fnv 0x00a93040
bool FUN_00a93040_cls::FUN_00a93040(FUN_00a93040_cls* other)
{
    if (IsEqual(other) != 0 && reinterpret_cast<SubCmpA*>(&other->unk_0c4)->Equal(&unk_0c4) != 0 &&
        reinterpret_cast<SubCmpB*>(&other->unk_0e8)->Equal(&unk_0e8) == 0 && other->m_128 == m_128 &&
        other->m_12c == m_12c && other->m_130 == m_130 && other->m_134 == m_134 && other->m_138 == m_138 &&
        reinterpret_cast<SubCmpC*>(&other->unk_13c)->Equal(&unk_13c) == 0)
        return true;
    return false;
}

class NiStream;
struct NiObjectStub;

struct NiBinaryStreamStub
{
    typedef unsigned int (*WriteFn)(NiBinaryStreamStub*, const void*, unsigned int, unsigned int*, unsigned int);
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    WriteFn m_pfnWrite;
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};

template <class T> inline void StreamSaveBinary(NiBinaryStreamStub& kStream, const T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&kValue, sizeof(T), &uiSize, 1);
}

class NiStream
{
  public:
    virtual void v00();
    virtual void v01();
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
    virtual void SaveLinkID(NiObjectStub* pkObject);
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
    NiBinaryStreamStub* m_pBackingStream;
};

struct NiMatrix3Stub
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    void SaveBinary(NiStream& kStream);
};
struct NiPoint3Stub
{
    float x, y, z;
    void SaveBinary(NiStream& kStream);
};
struct NiPlaneStub
{
    float x, y, z, d;
    void SaveBinary(NiStream& kStream);
};

struct NiDynamicEffectStub
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
    void SaveBinary(NiStream& kStream);
};

struct TexEffectSaver : NiDynamicEffectStub
{
    NiMatrix3Stub m_kModelProjMat;
    NiPoint3Stub m_kModelProjTrans;
    NiMatrix3Stub m_kWorldProjMat;
    NiPoint3Stub m_kWorldProjTrans;

    NiObjectStub* m_spSourceTexture;
    int m_eTextureFiltering;
    int m_eTextureClamping;
    int m_eTextureType;
    int m_eCoordGenType;
    bool m_bClippingPlaneEnable;
    NiPlaneStub m_kModelPlane;
    void FUN_00a932f0(NiStream& kStream);
};

// Saves the dynamic effect base, model projection matrix and translation, texture settings, source texture link, clipping flag and model plane to the stream.
// @fnv 0x00a932f0
void TexEffectSaver::FUN_00a932f0(NiStream& kStream)
{
    NiDynamicEffectStub::SaveBinary(kStream);
    m_kModelProjMat.SaveBinary(kStream);
    m_kModelProjTrans.SaveBinary(kStream);
    StreamSaveBinary(*kStream.m_pBackingStream, m_eTextureFiltering);
    StreamSaveBinary(*kStream.m_pBackingStream, m_eTextureClamping);
    StreamSaveBinary(*kStream.m_pBackingStream, m_eTextureType);
    StreamSaveBinary(*kStream.m_pBackingStream, m_eCoordGenType);
    kStream.SaveLinkID(m_spSourceTexture);
    bool bClip = m_bClippingPlaneEnable;
    StreamSaveBinary(*kStream.m_pBackingStream, bClip);
    m_kModelPlane.SaveBinary(kStream);
}

struct NiMemObject
{
    static void* __cdecl operator new(unsigned int size);
};
// @fnv 0x00a929b0
void* __cdecl FUN_00a929b0()
{
    FUN_00a92710_cls* obj = (FUN_00a92710_cls*)NiMemObject::operator new(0x15c);
    if (obj)
        return obj->FUN_00a92710();
    return 0;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct TextureRef
{
    virtual void Destroy();
    virtual void DeleteThis();
    volatile long references;
};
struct Matrix33
{
    float elements[3][3];
};
struct Vector3
{
    float x, y, z;
};
struct Plane4
{
    float x, y, z, w;
};
struct TextureEffectCandidate
{
    unsigned field_000;
    unsigned field_004;
    unsigned field_008;
    unsigned field_00c;
    unsigned field_010;
    unsigned field_014;
    unsigned field_018;
    unsigned field_01c;
    unsigned field_020;
    unsigned field_024;
    unsigned field_028;
    unsigned field_02c;
    unsigned field_030;
    unsigned field_034;
    unsigned field_038;
    unsigned field_03c;
    unsigned field_040;
    unsigned field_044;
    unsigned field_048;
    unsigned field_04c;
    unsigned field_050;
    unsigned field_054;
    unsigned field_058;
    unsigned field_05c;
    unsigned field_060;
    unsigned field_064;
    unsigned field_068;
    unsigned field_06c;
    unsigned field_070;
    unsigned field_074;
    unsigned field_078;
    unsigned field_07c;
    unsigned field_080;
    unsigned field_084;
    unsigned field_088;
    unsigned field_08c;
    unsigned field_090;
    unsigned field_094;
    unsigned field_098;
    unsigned field_09c;
    unsigned field_0a0;
    unsigned field_0a4;
    unsigned field_0a8;
    unsigned field_0ac;
    unsigned field_0b0;
    unsigned field_0b4;
    unsigned field_0b8;
    unsigned field_0bc;
    unsigned field_0c0;
    Matrix33 matrix_c4;
    Vector3 vector_e8;
    unsigned field_0f4;
    unsigned field_0f8;
    unsigned field_0fc;
    unsigned field_100;
    unsigned field_104;
    unsigned field_108;
    unsigned field_10c;
    unsigned field_110;
    unsigned field_114;
    unsigned field_118;
    unsigned field_11c;
    unsigned field_120;
    TextureRef* texture_124;
    unsigned field_128, field_12c, field_130, field_134;
    bool field_138;
    unsigned field_13c, field_140, field_144, field_148;
    Plane4 vector_14c;
    void FUN_00a68d40(TextureEffectCandidate*, void*);
    void CopyTo(TextureEffectCandidate*, void*);
};
// Copies this candidate into dest via FUN_00a68d40, then copies the texture reference (with refcount add/release), matrix, vectors and trailing fields.
// @fnv 0x00a92f10
void TextureEffectCandidate::CopyTo(TextureEffectCandidate* dest, void* context)
{
    FUN_00a68d40(dest, context);
    TextureRef* oldTexture = dest->texture_124;
    if (oldTexture != texture_124)
    {
        if (oldTexture && !InterlockedDecrement(&oldTexture->references))
            oldTexture->DeleteThis();
        dest->texture_124 = texture_124;
        if (dest->texture_124)
            InterlockedIncrement(&dest->texture_124->references);
    }
    dest->matrix_c4 = matrix_c4;
    dest->vector_e8 = vector_e8;
    dest->field_128 = field_128;
    dest->field_12c = field_12c;
    dest->field_130 = field_130;
    dest->field_134 = field_134;
    dest->field_138 = field_138;
    dest->field_13c = field_13c;
    dest->field_140 = field_140;
    dest->field_144 = field_144;
    dest->field_148 = field_148;
    dest->vector_14c = vector_14c;
}

struct StrArr
{
    void* vtable;
    char** data;
    unsigned short capacity;
    unsigned short size;
    unsigned short count;
    unsigned short growBy;
    void SetSize(unsigned int newSize);
    void SetAt(unsigned int index, char*& value);
    void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + growBy);
        SetAt(index, value);
    }
};
struct DynamicEffectViewer : NiDynamicEffectStub
{
    void GetViewerStrings(StrArr& strings);
};
struct MatrixViewer : NiMatrix3Stub
{
    char* ToString(const char* name);
};
struct PointViewer : NiPoint3Stub
{
    char* FUN_00a59af0(const char* name);
};
struct PlaneViewer : NiPlaneStub
{
    char* FUN_00a69a60(const char* name);
};
char* __cdecl FUN_00a7d330(const char* name);
char* __cdecl FUN_00a92a60(const char* name, int value);
char* __cdecl BuildFilterModeString(const char* name, int value);
char* __cdecl BuildTextureAddressModeString(const char* name, int value);
char* __cdecl BuildProjectionModeString(const char* name, int value);
char* __cdecl FUN_00a7d370(const char* name, bool value);
struct TextureEffectViewer : DynamicEffectViewer
{
    MatrixViewer modelProjMat;
    PointViewer modelProjTrans;
    NiMatrix3Stub worldProjMat;
    NiPoint3Stub worldProjTrans;
    NiObjectStub* sourceTexture;
    int filter;
    int clamp;
    int textureMode;
    int coordMode;
    bool planeEnable;
    PlaneViewer modelPlane;
    void AppendToStrings(StrArr& strings);
};
// @fnv 0x00a93400
void TextureEffectViewer::AppendToStrings(StrArr& strings)
{
    GetViewerStrings(strings);
    strings.Add(FUN_00a7d330(reinterpret_cast<const char*>(g_011f5e94)));
    strings.Add(modelProjMat.ToString("m_kModelProjMat"));
    strings.Add(modelProjTrans.FUN_00a59af0("m_kModelProjTrans"));
    strings.Add(FUN_00a92a60("m_eTextureMode", textureMode));
    strings.Add(BuildFilterModeString("m_eFilter", filter));
    strings.Add(BuildTextureAddressModeString("m_eClamp", clamp));
    strings.Add(FUN_00a92a60("m_eTextureMode", textureMode));
    strings.Add(BuildProjectionModeString("m_eCoordMode", coordMode));
    strings.Add(FUN_00a7d370("m_bPlaneEnable", planeEnable));
    strings.Add(modelPlane.FUN_00a69a60("m_kModelPlane"));
}

struct ProjectionPoint
{
    float x, y, z;
    ProjectionPoint()
    {}
    ProjectionPoint(float a, float b, float c) : x(a), y(b), z(c)
    {}
    ProjectionPoint operator-(const ProjectionPoint& p) const
    {
        ProjectionPoint r;
        r.x = x - p.x;
        r.y = y - p.y;
        r.z = z - p.z;
        return r;
    }
    float Dot(const ProjectionPoint& p) const
    {
        return y * p.y + x * p.x + z * p.z;
    }
};

struct ProjectionMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    ProjectionMatrix FUN_004768c0() const;
    ProjectionMatrix FUN_0043f8d0(const ProjectionMatrix&) const;
    ProjectionMatrix FUN_00a85520(float) const;
    ProjectionPoint FUN_004b4500(const ProjectionPoint*) const;
    ProjectionPoint operator*(const ProjectionPoint& p) const
    {
        return ProjectionPoint(m01 * p.y + m00 * p.x + m02 * p.z, m11 * p.y + m10 * p.x + m12 * p.z,
                               m21 * p.y + m20 * p.x + m22 * p.z);
    }
};

struct TextureProjection
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064;
    ProjectionMatrix worldRotation;
    ProjectionPoint worldTranslation;
    float worldScale;
    unsigned int unk09c, unk0a0, unk0a4, revision;
    unsigned int unk0ac, unk0b0, unk0b4, unk0b8, unk0bc, unk0c0;
    ProjectionMatrix modelProjection;
    ProjectionPoint modelTranslation;
    ProjectionMatrix worldProjection;
    ProjectionPoint projectionTranslation;
    unsigned int sourceTexture, filtering, clamping, textureType, coordGenType;
    bool clippingEnabled;
    ProjectionPoint modelPlaneNormal;
    float modelPlaneConstant;
    ProjectionPoint worldPlaneNormal;
    float worldPlaneConstant;
    void UpdateWorldProjection();
};

// Builds worldProjection and projectionTranslation from coordGenType, computes the world plane normal and constant, and increments revision.
// @fnv 0x00a92c40
void TextureProjection::UpdateWorldProjection()
{
    float y;
    float* p = &y;
    if (coordGenType == 2)
    {
        projectionTranslation.x = projectionTranslation.y = 0.5f;
        projectionTranslation.z = 0.0f;
        *p = worldRotation.m01;
        worldProjection.m00 = 0.5 * worldRotation.m02;
        worldProjection.m10 = -0.5 * (*p);
        worldProjection.m20 = 0.0f;
        *p = worldRotation.m11;
        worldProjection.m01 = 0.5 * worldRotation.m12;
        worldProjection.m11 = -0.5 * (*p);
        worldProjection.m21 = 0.0f;
        *p = worldRotation.m21;
        worldProjection.m02 = 0.5 * worldRotation.m22;
        worldProjection.m12 = -0.5 * (*p);
        worldProjection.m22 = 0.0f;
    }
    else if (coordGenType == 3 || coordGenType == 4)
    {
        projectionTranslation.x = projectionTranslation.y = projectionTranslation.z = 0.0f;
        worldProjection = modelProjection.FUN_0043f8d0(worldRotation.FUN_004768c0());
    }
    else
    {
        worldProjection = modelProjection.FUN_0043f8d0(worldRotation.FUN_004768c0()).FUN_00a85520(1.0f / worldScale);
        projectionTranslation = modelTranslation - worldProjection.FUN_004b4500(&worldTranslation);
    }
    ProjectionPoint worldNormal;
    worldNormal = worldRotation * modelPlaneNormal;
    float fUnusedDot =
        worldTranslation.x * worldNormal.x + worldTranslation.y * worldNormal.y + worldTranslation.z * worldNormal.z;
    float fPlaneDist = worldTranslation.Dot(worldNormal);
    *p = fPlaneDist + modelPlaneConstant * worldScale;
    worldPlaneNormal = worldNormal;
    revision += 1;
    worldPlaneConstant = *p;
}

struct NiBinaryStreamL
{
    typedef unsigned int (*ReadFn)(NiBinaryStreamL*, void*, unsigned int, unsigned int*, unsigned int);
    void* m_vtbl;
    unsigned int m_uiStreamFlags;
    ReadFn m_pfnRead;
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytes = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytes;
        return uiBytes;
    }
};
template <class T> inline void StreamLoadBinary(NiBinaryStreamL& kStream, T& kValue)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryRead(&kValue, sizeof(T), &uiSize, 1);
}
template <class T> inline void StreamLoadEnum(NiBinaryStreamL& kStream, T& eValue)
{
    unsigned int uiValue;
    StreamLoadBinary(kStream, uiValue);
    eValue = (T)uiValue;
}
struct NiStreamL
{
    int unk000[0x36];
    unsigned int m_uiNifVersion;
    int unk0dc[0x5c];
    NiBinaryStreamL* m_pUnderlyingStream;
    unsigned int ResetStreamState();
};
struct NiMatrix3L
{
    float m[9];
    void LoadBinary(NiStreamL& kStream);
};
struct NiPoint3L
{
    float x, y, z;
    void LoadBinary(NiStreamL& kStream);
};
struct NiPlaneL
{
    float x, y, z, d;
    void LoadBinary(NiStreamL& kStream);
};
struct NiDynamicEffectL
{
    int unk00[0x31];
    void LoadBinary(NiStreamL& kStream);
};
struct TexEffectLoader : NiDynamicEffectL
{
    NiMatrix3L m_kModelProjMat;
    NiPoint3L m_kModelProjTrans;
    NiMatrix3L m_kWorldProjMat;
    NiPoint3L m_kWorldProjTrans;
    void* m_spSourceTexture;
    int m_eTextureFiltering;
    int m_eTextureClamping;
    int m_eTextureType;
    int m_eCoordGenType;
    bool m_bClippingPlaneEnable;
    NiPlaneL m_kModelPlane;
    void FUN_00a93140(NiStreamL& kStream);
};
// @fnv 0x00a93140
void TexEffectLoader::FUN_00a93140(NiStreamL& kStream)
{
    NiDynamicEffectL::LoadBinary(kStream);
    m_kModelProjMat.LoadBinary(kStream);
    m_kModelProjTrans.LoadBinary(kStream);
    StreamLoadEnum(*kStream.m_pUnderlyingStream, m_eTextureFiltering);
    StreamLoadEnum(*kStream.m_pUnderlyingStream, m_eTextureClamping);
    StreamLoadEnum(*kStream.m_pUnderlyingStream, m_eTextureType);
    StreamLoadEnum(*kStream.m_pUnderlyingStream, m_eCoordGenType);
    kStream.ResetStreamState();
    char bClip;
    StreamLoadBinary(*kStream.m_pUnderlyingStream, bClip);
    m_bClippingPlaneEnable = bClip != 0;
    m_kModelPlane.LoadBinary(kStream);
    if (kStream.m_uiNifVersion < 0x0a030004)
    {
        short sPS2;
        StreamLoadBinary(*kStream.m_pUnderlyingStream, sPS2);
        StreamLoadBinary(*kStream.m_pUnderlyingStream, sPS2);
    }
    if (kStream.m_uiNifVersion < 0x04010010)
    {
        short sTemp;
        StreamLoadBinary(*kStream.m_pUnderlyingStream, sTemp);
    }
}

class TESObjectDoorController
{
  public:
    static void* operator new(unsigned int n);
};
class NiCloningProcessA93;
namespace a93 {
class FUN_00a92710
{
  public:
    FUN_00a92710() throw();
    static void* operator new(unsigned int n)
    {
        return TESObjectDoorController::operator new(n);
    }
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
};
}
class NiTextureEffectA93
{
  public:
    void CopyTo(a93::FUN_00a92710* pkClone, NiCloningProcessA93& kCloning);
    a93::FUN_00a92710* Clone(NiCloningProcessA93& kCloning);
};
// Allocates a new a93::FUN_00a92710 object, copies this NiTextureEffectA93 into it via CopyTo, and returns the new object.
// @fnv 0x00a930f0
a93::FUN_00a92710* NiTextureEffectA93::Clone(NiCloningProcessA93& kCloning)
{
    a93::FUN_00a92710* pkObject = new a93::FUN_00a92710;
    CopyTo(pkObject, kCloning);
    return pkObject;
}

#include <string.h>
extern "C" void* __cdecl _NiMalloc(unsigned int);
int __cdecl NiSprintf(char*, unsigned int, const char*, ...);

// @fnv 0x00a92a60
char* __cdecl FUN_00a92a60(const char* pPrefix, unsigned int eMode)
{
    unsigned int uiLen = strlen(pPrefix) + 0x19;
    char* pString = static_cast<char*>(_NiMalloc(uiLen));
    switch (eMode)
    {
    case 0:
        NiSprintf(pString, uiLen, "%s = PROJECTED_LIGHT", pPrefix);
        break;
    case 1:
        NiSprintf(pString, uiLen, "%s = PROJECTED_SHADOW", pPrefix);
        break;
    case 2:
        NiSprintf(pString, uiLen, "%s = ENVIRONMENT_MAP", pPrefix);
        break;
    case 3:
        NiSprintf(pString, uiLen, "%s = FOG_MAP", pPrefix);
        break;
    }
    return pString;
}

namespace fnv_00a92b00 {
extern "C"
{
    void* __cdecl NiMalloc(unsigned int);
    int __cdecl NiSprintf(char*, unsigned int, const char*, ...);
}
// Allocates a buffer and formats pPrefix with a projection mode name selected by eMode into it.
// @fnv 0x00a92b00
char* __cdecl BuildProjectionModeString(const char* pPrefix, int eMode)
{
    unsigned int uiLen = strlen(pPrefix) + 25;
    char* pString = (char*)NiMalloc(uiLen);
    switch (eMode)
    {
    case 0:
        NiSprintf(pString, uiLen, "%s = WORLD_PARALLEL", pPrefix);
        return pString;
    case 1:
        NiSprintf(pString, uiLen, "%s = WORLD_PERSPECTIVE", pPrefix);
        return pString;
    case 2:
        NiSprintf(pString, uiLen, "%s = SPHERE_MAP", pPrefix);
        return pString;
    case 3:
        NiSprintf(pString, uiLen, "%s = SPECULAR_CUBE_MAP", pPrefix);
        return pString;
    case 4:
        NiSprintf(pString, uiLen, "%s = DIFFUSE_CUBE_MAP", pPrefix);
        return pString;
    default:
        NiSprintf(pString, uiLen, "%s = UNKNOWN!!!", pPrefix);
        return pString;
    }
}
}  // namespace fnv_00a92b00

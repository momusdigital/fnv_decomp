
// src/staging/blk_00d40000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct D51Allocator;
struct D51MemHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    D51Allocator* m_pThreadAllocator;
};
void* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* alloc, void* array, int elemSize);

struct D51Vector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const D51Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

template <class T> __forceinline void D51ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <class T> struct D51Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& t)
    {
        D51MemHolder* mem = (D51MemHolder*)FUN_00c85750();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(mem->m_pThreadAllocator, this, sizeof(T));
        }
        D51ConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

struct D51Stream
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    D51Array<D51Vector4> m_kShapeVectorData;
    D51Array<int> m_commands;
};

struct D51Input
{
    D51Vector4 m_kPointA;
    D51Vector4 m_kPointB;
    D51Vector4 m_iThirdValue;
};

struct D51Writer
{
    int unk00;
    D51Stream* m_stream;
    int unk08;
    int unk0c;
    int unk10;
    short unk14;
    bool m_bValueAt0C;

    int FUN_00d51c30(const D51Input& input);
};

// @fnv 0x00d51c30
int D51Writer::FUN_00d51c30(const D51Input& input)
{
    m_stream->m_commands.AddBack(8);
    int index = m_stream->m_kShapeVectorData.GetLogicalSize();
    m_stream->m_kShapeVectorData.AddBack(input.m_kPointA);
    m_stream->m_kShapeVectorData.AddBack(input.m_kPointB);
    m_stream->m_kShapeVectorData.AddBack(input.m_iThirdValue);
    m_bValueAt0C = true;
    return index;
}

namespace fnv_00d52640 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
}

struct hkMemoryAllocator;

struct hkThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

extern "C" hkThreadMemory* FUN_00c85750();
void ResizeAudioStream(void* allocator, void* array, int elemSize);

struct hkVector4
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkReferencedObject
{
    void FUN_00c90510() const;
};

template <typename T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = t;
    }
}

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(const T& t)
    {
        hkMemoryAllocator& allocator = FUN_00c85750()->heap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ResizeAudioStream(&allocator, this, sizeof(T));
        }
        hkConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

struct S00d52640_Writer
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkArray<hkVector4> m_kShapeVectorData;
    hkArray<int> m_commands;
    int unk28;
    int unk2c;
    int unk30;
    hkArray<const hkReferencedObject*> m_kTrackedObjects;
};

struct FUN_00d52640_c
{
    int unk00;
    S00d52640_Writer* m_pStreamWriter;
    int FUN_00d52640(bool flag, const hkReferencedObject* object);
};

// @fnv 0x00d52640
int FUN_00d52640_c::FUN_00d52640(bool flag, const hkReferencedObject* object)
{
    m_pStreamWriter->m_commands.AddBack(0xe);
    m_pStreamWriter->m_commands.AddBack(flag);

    int index = m_pStreamWriter->m_kShapeVectorData.m_iElementCount;
    hkVector4 v;
    v.set((float)m_pStreamWriter->m_kTrackedObjects.m_iElementCount, 0.0f, 0.0f, 0.0f);
    object->FUN_00c90510();
    m_pStreamWriter->m_kShapeVectorData.AddBack(v);
    m_pStreamWriter->m_kTrackedObjects.AddBack(object);

    S00d52640_Writer* writer = m_pStreamWriter;
    writer->unk08 += 1;
    writer->unk04 += 0x40;
    writer->unk0c += 3;
    return index;
}
}  // namespace fnv_00d52640

namespace fnv_00d56470 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_cmple_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" int _mm_movemask_ps(__m128 a);

extern const __m128 DAT_01017d10;
static const float DAT_01017d00 = 0.001f;

struct hkVector4D564
{
    __m128 m_vComponents;

    bool equals3(const hkVector4D564& v, float fEpsilon) const
    {
        const __m128 kDiff = _mm_and_ps(_mm_sub_ps(m_vComponents, v.m_vComponents), DAT_01017d10);
        const __m128 kEps = _mm_load_ps1(&fEpsilon);
        return (_mm_movemask_ps(_mm_cmple_ps(kDiff, kEps)) & 7) == 7;
    }
};

extern hkVector4D564 DAT_01267e30;

struct hkQuaternionD564
{
    hkVector4D564 m_vec;

    float GetAngle() const;
};

struct FUN_00d56470_cls
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkQuaternionD564 m_rotation;
    hkVector4D564 m_vTranslation;

    FUN_00d56470_cls* FUN_00d56470(int bCompute);
};

// @fnv 0x00d56470
FUN_00d56470_cls* FUN_00d56470_cls::FUN_00d56470(int bCompute)
{
    if (bCompute)
    {
        const int iTranslated = !m_vTranslation.equals3(DAT_01267e30, DAT_01017d00);
        const int iRotated = (m_rotation.GetAngle() < DAT_01017d00) ? 0 : 2;
        reinterpret_cast<int*>(&m_vTranslation)[3] = iRotated | iTranslated | 0x3f000000;
    }
    return this;
}
}  // namespace fnv_00d56470

struct __declspec(align(16)) hkpAgent3FuncsD40
{
    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};

class hkpCollisionDispatcherD40
{
  public:
    void AddEntry(const hkpAgent3FuncsD40& kFuncs, int a, int b);
};

void __cdecl FUN_00d400f0(void* buf);

// @fnv 0x00d40130
void __cdecl FUN_00d40130(hkpCollisionDispatcherD40* self)
{
    hkpAgent3FuncsD40 kFuncs;
    kFuncs.m_bIsPredictive = false;
    kFuncs.m_bAgentFlag1 = false;
    kFuncs.m_bAgentFlag2 = false;
    kFuncs.m_pAgentFunction7 = 0;
    kFuncs.m_pAgentFunction8 = 0;
    kFuncs.m_pUpdateFilterFunc = 0;
    kFuncs.m_pAgentFunction10 = 0;
    kFuncs.m_pAgentFunction11 = 0;
    FUN_00d400f0(&kFuncs);
    self->AddEntry(kFuncs, 4, 4);
}

struct Handle_d49550
{
    int m_v;
};
struct __declspec(align(16)) FUN_00c9ce00
{
    FUN_00c9ce00(Handle_d49550 kHandle);
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
};
extern int DAT_010c7888;
// @fnv 0x00d49550
int* __cdecl FUN_00d49550()
{
    Handle_d49550 kHandle = {0};
    FUN_00c9ce00 kObject(kHandle);
    return &DAT_010c7888;
}

struct FinishingFlag
{
    int m_bFinishing;
};

class __declspec(align(16)) S00d4b1a0_Object
{
  public:
    S00d4b1a0_Object(FinishingFlag flag);  // FUN_00d4a170
    void* m_ppVirtualMethodTable;
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
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00d4b1a0
const void* __cdecl FUN_00d4b1a0()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4b1a0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}

struct W_00d49c40
{
    int x;
};

struct __declspec(align(16)) S_00d49c40
{
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

    void FUN_00d49c40(W_00d49c40 w);
};

// @fnv 0x00d4b200
int FUN_00d4b200()
{
    S_00d49c40 obj;
    obj.FUN_00d49c40(W_00d49c40());
    return obj.unk00;
}

struct W_d4a180
{
    int x;
};

struct __declspec(align(16)) SpawnedObject
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108;
    void FUN_00d4a180(W_d4a180 w);
};

// @fnv 0x00d4b260
int getVtable_hkpStorageExtendedMeshShape()
{
    SpawnedObject obj;
    obj.FUN_00d4a180(W_d4a180());
    return obj.unk000;
}

struct ZeroD4B
{
    int v;
};

struct __declspec(align(16)) HolderD4B
{
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
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;

    void FUN_00d56f10(ZeroD4B arg);
};

// @fnv 0x00d4b330
int getVtable_hkpExtendedMeshShape()
{
    HolderD4B holder;
    ZeroD4B z = {0};
    holder.FUN_00d56f10(z);
    return *(int*)&holder.unk00;
}

namespace fnv_00d4be60 {
struct FinishingFlag
{
    int m_bFinishing;
};

class __declspec(align(16)) S00d4be60_Object
{
  public:
    S00d4be60_Object(FinishingFlag flag);  // FUN_00d4b3b0
    virtual void vf00();
    int m_kNextStreamField[19];
};

// @fnv 0x00d4be60
const void* __cdecl FUN_00d4be60()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4be60_Object kObject(flag);
    return *reinterpret_cast<const void**>(&kObject);
}
}  // namespace fnv_00d4be60

namespace fnv_00d4bec0 {
struct FinishingFlag
{
    int m_bFinishing;
};

class __declspec(align(16)) S00d4bec0_Object
{
  public:
    S00d4bec0_Object(FinishingFlag flag);  // FUN_00d4ba30
    void* m_ppVirtualMethodTable;
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
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00d4bec0
const void* __cdecl getVtable_hkpStorageMeshShape()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4bec0_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}
}  // namespace fnv_00d4bec0

namespace fnv_00d4bf40 {
struct FinishingFlag
{
    int m_bFinishing;
};

class __declspec(align(16)) S00d4bf40_Object
{
  public:
    S00d4bf40_Object(FinishingFlag flag);  // FUN_00dcd380
    void* m_ppVirtualMethodTable;
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
    int unk5C;
};

// Havok getVtable helper: build the object with the finish-loading flag and read its vtable pointer.
// @fnv 0x00d4bf40
const void* __cdecl getVtable_hkpMeshShape()
{
    FinishingFlag flag;
    flag.m_bFinishing = 0;
    S00d4bf40_Object kObject(flag);
    return kObject.m_ppVirtualMethodTable;
}
}  // namespace fnv_00d4bf40

struct FnvCpu_FUN_00d4f7f0_CpuData0
{
    __m128 field00;
    __m128 field10;
    __m128 field20;
};
struct FnvCpu_FUN_00d4f7f0_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    __m128 field20;
    __m128 field30;
    __m128 field40;
    void FUN_00d4f7f0(FnvCpu_FUN_00d4f7f0_CpuData0* input0);
};
// @fnv 0x00d4f7f0
void FnvCpu_FUN_00d4f7f0_CpuObject::FUN_00d4f7f0(FnvCpu_FUN_00d4f7f0_CpuData0* input0)
{
    input0->field00 = this->field20;
    input0->field10 = this->field30;
    input0->field20 = this->field40;
}

struct FnvCpu_FUN_00d4f820_CpuData0
{
    __m128 field00;
    __m128 field10;
    __m128 field20;
};
struct FnvCpu_FUN_00d4f820_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    __m128 field50;
    __m128 field60;
    __m128 field70;
    void FUN_00d4f820(FnvCpu_FUN_00d4f820_CpuData0* input0);
};
// @fnv 0x00d4f820
void FnvCpu_FUN_00d4f820_CpuObject::FUN_00d4f820(FnvCpu_FUN_00d4f820_CpuData0* input0)
{
    input0->field00 = this->field50;
    input0->field10 = this->field60;
    input0->field20 = this->field70;
}

namespace fnv_00d51890 {
struct HkRouterD51
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};
void* FUN_00c85750();
void ResizeAudioStream(void* alloc, void* array, int elemSize);

struct HkVecD51
{
    __m128 m_vComponents;
    void operator=(const HkVecD51& o)
    {
        m_vComponents = o.m_vComponents;
    }
};

template <typename T> inline void D51ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct HkArrD51
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void AddBack(const T& t)
    {
        HkRouterD51* r = (HkRouterD51*)FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(r->m_pStreamAllocator, this, sizeof(T));
        D51ConstructWithCopy<T>(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

struct HkCoreD51
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HkArrD51<HkVecD51> m_vecs;
    HkArrD51<int> m_auiHeaderValues;
};

struct HkOwnerD51
{
    int unk00;
    HkCoreD51* m_core;
    int unk08;
    int unk0C;
    unsigned char m_flags[4];

    int FUN_00d51890(const HkVecD51& v, int index);
};

// @fnv 0x00d51890
int HkOwnerD51::FUN_00d51890(const HkVecD51& v, int index)
{
    m_core->m_auiHeaderValues.AddBack(3);
    m_core->m_auiHeaderValues.AddBack(index);
    int result = m_core->m_vecs.m_iElementCount;
    m_core->m_vecs.AddBack(v);
    m_flags[index] = 1;
    return result;
}
}  // namespace fnv_00d51890

namespace fnv_00d51d40 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
struct HeapContext
{
    void* manager;
    void* archive;
    void* allocations;
    void* scratch;
    void* allocator;
};
HeapContext* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, void* array, unsigned int stride);
template <typename T> inline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct VectorArray
{
    __m128* elements;
    unsigned int count;
    unsigned int capacityFlags;
};
struct IndexArray
{
    unsigned int* elements;
    unsigned int count;
    unsigned int capacityFlags;
};
struct GeometryArrays
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    VectorArray vertices;
    IndexArray indices;
};
struct GeometryBuilder
{
    unsigned int unknown00;
    GeometryArrays* arrays;
    unsigned int state08;
    unsigned int state0c;
    unsigned int state10;
    unsigned char status14;
    unsigned char status15;
    unsigned char status16;
    bool updated;
    unsigned int FUN_00d51d40(const __m128* vectors);
};
// @fnv 0x00d51d40
unsigned int GeometryBuilder::FUN_00d51d40(const __m128* vectors)
{
    IndexArray* indexBuffer = &arrays->indices;
    HeapContext* heap = FUN_00c85750();
    if (indexBuffer->count == (indexBuffer->capacityFlags & 0x3fffffff))
        ResizeAudioStream(heap->allocator, indexBuffer, 4);
    hkConstructWithCopy(indexBuffer->elements + indexBuffer->count, 1, 9u);
    ++indexBuffer->count;

    unsigned int previousCount = arrays->vertices.count;
    VectorArray* positions = &arrays->vertices;
    heap = FUN_00c85750();
    if (positions->count == (positions->capacityFlags & 0x3fffffff))
        ResizeAudioStream(heap->allocator, positions, 16);
    positions->elements[positions->count] = vectors[0];
    ++positions->count;

    positions = &arrays->vertices;
    heap = FUN_00c85750();
    if (positions->count == (positions->capacityFlags & 0x3fffffff))
        ResizeAudioStream(heap->allocator, positions, 16);
    positions->elements[positions->count] = vectors[1];
    ++positions->count;

    positions = &arrays->vertices;
    heap = FUN_00c85750();
    if (positions->count == (positions->capacityFlags & 0x3fffffff))
        ResizeAudioStream(heap->allocator, positions, 16);
    positions->elements[positions->count] = vectors[2];
    ++positions->count;

    updated = true;
    return previousCount;
}
}  // namespace fnv_00d51d40

namespace fnv_00d52000 {
struct RouterD52
{
    int unk00, unk04, unk08, unk0c;
    void* m_pStreamAllocator;
};
RouterD52& FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, void* array, int elementSize);
template <typename T> inline void D52ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
struct VecD52
{
    __m128 m_vComponents;
    VecD52& operator=(const VecD52& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};
template <typename T> struct ArrayD52
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void AddBack(const T& val)
    {
        RouterD52& router = FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        D52ConstructWithCopy<T>(m_data + m_iElementCount, 1, val);
        m_iElementCount++;
    }
};
struct OwnerD52
{
    int unk00, unk04, unk08, unk0c;
    ArrayD52<VecD52> m_vecs;
    ArrayD52<int> m_auiHeaderValues;
};
struct D52Class
{
    int unk00;
    OwnerD52* m_pOwnerObject;
    int unk08, unk0c, unk10, unk14;
    bool m_dirty;
    int FUN_00d52000(const VecD52& v);
};
// @fnv 0x00d52000
int D52Class::FUN_00d52000(const VecD52& v)
{
    m_pOwnerObject->m_auiHeaderValues.AddBack(1);
    int index = m_pOwnerObject->m_vecs.GetLogicalSize();
    m_pOwnerObject->m_vecs.AddBack(v);
    m_dirty = true;
    return index;
}
}  // namespace fnv_00d52000

extern "C" __m128 _mm_setr_ps(float e0, float e1, float e2, float e3);
static const float DAT_01011d78 = 0.0f;
struct D529E0_Heap;
struct D529E0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D529E0_Heap* m_pStreamAllocator;
};
void __cdecl ResizeAudioStream(D529E0_Heap* heap, void* array, int elementSize);
template <typename T> inline void D529E0_ConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}
template <typename T> struct D529E0_Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void AddBack(const T& value)
    {
        D529E0_Router* router = (D529E0_Router*)FUN_00c85750();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(router->m_pStreamAllocator, this, sizeof(T));
        D529E0_ConstructWithCopy<T>(m_data + m_iElementCount, 1, value);
        m_iElementCount++;
    }
};
struct D529E0_Batch
{
    int unk00;
    int m_04;
    int m_08;
    int m_0C;
    D529E0_Array<__m128> m_kShapeVectorData;
    D529E0_Array<int> m_commands;
};
struct D529E0_Builder
{
    int unk00;
    D529E0_Batch* m_batch;
    int FUN_00d529e0(unsigned char a1, float a2);
};
// @fnv 0x00d529e0
int D529E0_Builder::FUN_00d529e0(unsigned char a1, float a2)
{
    m_batch->m_commands.AddBack(0x15);
    m_batch->m_commands.AddBack(a1);
    __m128 v = _mm_setr_ps(a2, DAT_01011d78, DAT_01011d78, DAT_01011d78);
    int index = m_batch->m_kShapeVectorData.m_iElementCount;
    m_batch->m_kShapeVectorData.AddBack(v);
    D529E0_Batch* batch = m_batch;
    batch->m_04 += 0x40;
    batch->m_08 += 1;
    batch->m_0C += 2;
    return index;
}

extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
}
struct __declspec(align(16)) Vec
{
    __m128 quad;
    __forceinline void copy(const Vec& other)
    {
        quad = other.quad;
    }
    __forceinline __m128 get() const
    {
        return quad;
    }
    __forceinline void set(__m128 result)
    {
        quad = result;
    }
    __forceinline void normalize()
    {
        __m128 vector = quad;
        __m128 squared = _mm_mul_ps(vector, vector);
        __m128 length = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0x55), squared);
        length = _mm_add_ss(_mm_shuffle_ps(squared, squared, 0xaa), length);
        __m128 estimate = _mm_rsqrt_ss(length);
        __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(length, estimate), estimate));
        __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction);
        inverse = _mm_andnot_ps(_mm_cmpeq_ss(length, _mm_set_ss(0.0f)), inverse);
        __m128 result = _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), vector);

        quad = result;
    }
    __forceinline void setCross(const Vec& l, const Vec& r)
    {
        __m128 left = l.quad, right = r.quad;
        quad = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(left, left, 0xc9), _mm_shuffle_ps(right, right, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(left, left, 0xd2), _mm_shuffle_ps(right, right, 0xc9)));
    }
    static __forceinline __m128 cross(__m128 left, __m128 right)
    {
        return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(left, left, 0xc9), _mm_shuffle_ps(right, right, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(left, left, 0xd2), _mm_shuffle_ps(right, right, 0xc9)));
    }
};
struct BasisPair
{
    Vec unk00;
    Vec unk10;
    Vec axisA;
    Vec axisB;
    Vec normalA;
    Vec axisC;
    Vec axisD;
    Vec normalB;
    const Vec* FUN_00d52ce0(const Vec* a, const Vec* c, const Vec* b, const Vec* d);
};
// @fnv 0x00d52ce0
const Vec* BasisPair::FUN_00d52ce0(const Vec* a, const Vec* c, const Vec* b, const Vec* d)
{
    axisA.copy(*a);
    axisA.normalize();
    axisB.copy(*b);
    axisB.normalize();
    normalA.setCross(*a, *b);
    axisC.copy(*c);
    axisC.normalize();
    axisD.copy(*d);
    axisD.normalize();
    normalB.set(Vec::cross(c->get(), d->get()));
    return c;
}

extern "C"
{
    double __cdecl fabs(double);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_setzero_ps();
    __m128 _mm_sub_ps(__m128, __m128);
}

struct Vector172
{
    union
    {
        __m128 quad;
        float element[4];
    };
};
struct Row172
{
    float x, y, z, w;
    void FUN_004b4ab0(int index, const Vector172* value);
};
struct Frame172
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    Row172 row20, row30, row40, row50, row60, row70;
    void FUN_00d53060(int first, int second, const Vector172* direction);
};
static __forceinline float Absolute172(float value)
{
    volatile float result = static_cast<float>(fabs(static_cast<double>(value)));
    return result;
}
static __forceinline __m128 Normalize172(__m128 vector)
{
    __m128 squares = _mm_mul_ps(vector, vector);
    __m128 sum = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0x55), squares);
    __m128 length2 = _mm_add_ss(_mm_shuffle_ps(squares, squares, 0xaa), sum);
    __m128 estimate = _mm_rsqrt_ss(length2);
    __m128 error = _mm_mul_ss(_mm_mul_ss(length2, estimate), estimate);
    __m128 correction = _mm_sub_ss(_mm_set_ss(3.0f), error);
    __m128 inverse = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), estimate), correction);
    __m128 zeroMask = _mm_cmpeq_ss(length2, _mm_set_ss(0.0f));
    inverse = _mm_andnot_ps(zeroMask, inverse);
    return _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), vector);
}
// @fnv 0x00d53060
void Frame172::FUN_00d53060(int first, int second, const Vector172* direction)
{
    float ax = Absolute172(direction->element[0]);
    float ay = Absolute172(direction->element[1]);
    float az = Absolute172(direction->element[2]);
    int other = 0;
    int i = other + 1, j = other + 2;
    if (ay < ax)
    {
        ax = ay;
        i = 0;
        other = 1;
    }
    if (az < ax)
        j = other;
    Vector172 perpendicular;
    perpendicular.quad = _mm_setzero_ps();
    perpendicular.element[i] = direction->element[j];
    perpendicular.element[j] = -direction->element[i];
    perpendicular.quad = Normalize172(perpendicular.quad);
    __m128 p = perpendicular.quad;
    __m128 d = direction->quad;
    Vector172 cross;
    __m128 left = _mm_mul_ps(_mm_shuffle_ps(d, d, 0xc9), _mm_shuffle_ps(p, p, 0xd2));
    __m128 right = _mm_mul_ps(_mm_shuffle_ps(d, d, 0xd2), _mm_shuffle_ps(p, p, 0xc9));
    cross.quad = _mm_sub_ps(left, right);
    row20.FUN_004b4ab0(first, direction);
    row30.FUN_004b4ab0(first, &perpendicular);
    row40.FUN_004b4ab0(first, &cross);
    row50.FUN_004b4ab0(second, direction);
    row60.FUN_004b4ab0(second, &perpendicular);
    row70.FUN_004b4ab0(second, &cross);
}

__forceinline __m128 normalize3(const __m128& v)
{
    __m128 square = _mm_mul_ps(v, v);
    __m128 y = _mm_shuffle_ps(square, square, 0x55);
    y = _mm_add_ss(y, square);
    square = _mm_shuffle_ps(square, square, 0xaa);
    square = _mm_add_ss(square, y);
    __m128 reciprocal = _mm_rsqrt_ss(square);
    __m128 correction = _mm_mul_ss(square, reciprocal);
    correction = _mm_mul_ss(correction, reciprocal);
    correction = _mm_sub_ss(_mm_set_ss(3.0f), correction);
    __m128 factor = _mm_mul_ss(_mm_set_ss(0.5f), reciprocal);
    factor = _mm_mul_ss(factor, correction);
    __m128 mask = _mm_cmpeq_ss(square, _mm_set_ss(0.0f));
    factor = _mm_andnot_ps(mask, factor);
    factor = _mm_shuffle_ps(factor, factor, 0);
    return _mm_mul_ps(factor, v);
}
__forceinline __m128 cross3(const __m128& b, const __m128& a)
{
    return _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)),
                      _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9)));
}
// Reuse the current source's vector layout and basis storage without redefining either.
struct BasisPairSetup : BasisPair
{
    const __m128& FUN_00d4f5d0(const __m128&, const __m128&, const __m128&, const __m128&);
};
// @fnv 0x00d4f5d0
const __m128& BasisPairSetup::FUN_00d4f5d0(const __m128& referenceA, const __m128& referenceB, const __m128& inputAxisA,
                                           const __m128& inputAxisB)
{
    axisA.quad = normalize3(inputAxisA);
    axisB.quad = referenceA;
    axisB.quad = normalize3(axisB.quad);
    normalA.quad = cross3(axisB.quad, axisA.quad);
    axisC.quad = normalize3(inputAxisB);
    axisD.quad = referenceB;
    axisD.quad = normalize3(axisD.quad);
    normalB.quad = cross3(axisD.quad, axisC.quad);
    return inputAxisB;
}

namespace WorldLinearDof {

struct Writer
{
    unsigned int unk00;
    D51Stream* m_stream;
    unsigned int unk08, unk0c;
    unsigned char m_specifiedA[3];
    unsigned char m_specifiedB[3];

    int FUN_00d51a50(const D51Vector4& direction, int axis);
};

// @fnv 0x00d51a50
int Writer::FUN_00d51a50(const D51Vector4& direction, int axis)
{
    m_stream->m_commands.AddBack(5);
    m_stream->m_commands.AddBack(axis);
    int index = m_stream->m_kShapeVectorData.GetLogicalSize();
    m_stream->m_kShapeVectorData.AddBack(direction);
    m_specifiedA[axis] = 1;
    m_specifiedB[axis] = 1;
    return index;
}

}

struct PivotBWriter
{
    int unk00;
    D51Stream* m_stream;
    int unk08, unk0c, unk10, unk14;
    unsigned char m_pivotASet;
    bool m_pivotBSet;

    int FUN_00d520a0(const D51Vector4& pivot);
};

// @fnv 0x00d520a0
int PivotBWriter::FUN_00d520a0(const D51Vector4& pivot)
{
    m_stream->m_commands.AddBack(2);
    int index = m_stream->m_kShapeVectorData.GetLogicalSize();
    m_stream->m_kShapeVectorData.AddBack(pivot);
    m_pivotBSet = true;
    return index;
}

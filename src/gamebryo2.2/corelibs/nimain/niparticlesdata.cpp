// gamebryo2.2/corelibs/nimain/niparticlesdata.cpp: NiParticlesData, Candidate, ParticleViewData, ParticlesEquality and more (14 functions)

#include "MemoryManager.h"
#include "niparticlesdata_local.h"

extern MemoryManager g_memoryManager;

// @fnv 0x00a968a0
void NiParticlesData::SetRotations(NiQuaternion* pkRotations)
{
    g_memoryManager.Deallocate(m_pkRotations);
    m_pkRotations = pkRotations;
}

void __cdecl _NiFreeAlias(void* p);

// Clamps param_3 to 0x10, frees the pointer at this_ptr+0x68, stores the clamped byte at +0x6c and param_2 at +0x68.
// @fnv 0x00a968e0
void __fastcall FUN_00a968e0(char* this_ptr, int, void* param_2, unsigned char param_3)
{
    if (param_3 >= 0x10)
    {
        param_3 = 0x10;
    }
    _NiFreeAlias(*(void**)(this_ptr + 0x68));
    *(unsigned char*)(this_ptr + 0x6c) = param_3;
    *(void**)(this_ptr + 0x68) = param_2;
}

extern const char* const g_011f5f0c_arg1;

// @fnv 0x00a967d0
const char* const* __cdecl FUN_00a967d0()
{
    return &g_011f5f0c_arg1;
}

struct FUN_00a968c0_shell
{
    void __thiscall SetPointer(void* p);
};

// @fnv 0x00a968c0
void __thiscall FUN_00a968c0_shell::SetPointer(void* apPointer)
{
    g_memoryManager.Deallocate(*(void**)(this + 0x60));
    *(void**)(this + 0x60) = apPointer;
}

void __fastcall FUN_00a67c00(void* object);

struct NiGeometryData_SetConsistency_View
{
    void SetDataConsistency(int consistency);
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int uiSize);
};

extern char DAT_010a05e4[];

struct FUN_00a96600_data : NiGeometryData_SetConsistency_View
{
    void* vtable;
    char field_4[0x38];
    unsigned char field_3c;
    char field_3d[3];
    unsigned char field_40;
    char field_41[0xB];
    unsigned int field_4c;
    unsigned short field_50;
    char field_52[2];
    unsigned int field_54[6];
    unsigned char field_6c;
};

// @fnv 0x00a96600
void* FUN_00a96600()
{
    FUN_00a96600_data* p = (FUN_00a96600_data*)BSFadeNode::operator new(sizeof(FUN_00a96600_data));
    if (p)
    {
        FUN_00a67c00(p);
        p->vtable = DAT_010a05e4;
        p->field_4c = 0;
        p->field_50 = 0;
        p->field_54[0] = 0;
        p->field_54[1] = 0;
        p->field_54[2] = 0;
        p->field_54[3] = 0;
        p->field_54[4] = 0;
        p->field_54[5] = 0;
        p->field_6c = 0;
        p->field_40 = 0;
        p->SetDataConsistency(0);
        p->field_3c = 0;
        return p;
    }
    return 0;
}

void __cdecl _delete(void*, unsigned int);
void __cdecl FUN_00a96800();
struct FUN_00a96a10_shell
{
    void* __thiscall FUN_00a96a10(unsigned int flags);
};
// Calls FUN_00a96800, then deletes this with size 0x70 if flags has bit 0 set, and returns this.
// @fnv 0x00a96a10
void* __thiscall FUN_00a96a10_shell::FUN_00a96a10(unsigned int flags)
{
    FUN_00a96800();
    if (flags & 1)
        _delete(this, 0x70);
    return this;
}

class RgbaColor
{
  public:
    float r, g, b, a;
};
class NiQuaternion
{
  public:
    float w, x, y, z;
};
struct Candidate : NiParticlesData
{
    void RemoveParticle(unsigned short index);
};
// Copies the last active particle's vertex, color, normal, radii, sizes, rotation and texture data into the given slot, then decrements m_usActive.
// @fnv 0x00a964c0
void Candidate::RemoveParticle(unsigned short index)
{
    unsigned short last = m_usActive - 1;
    if (index != last)
    {
        m_pkVertex[index] = m_pkVertex[last];
        if (m_pkColor)
            m_pkColor[index] = m_pkColor[last];
        if (m_pkNormal)
            m_pkNormal[index] = m_pkNormal[last];
        if (m_pfRadii)
            m_pfRadii[index] = m_pfRadii[last];
        if (m_pfSizes)
            m_pfSizes[index] = m_pfSizes[last];
        if (m_pkRotations)
            m_pkRotations[index] = m_pkRotations[last];
        if (m_pfRotationAngles)
            m_pfRotationAngles[index] = m_pfRotationAngles[last];
        if (m_pkRotationAxes)
            m_pkRotationAxes[index] = m_pkRotationAxes[last];
        if (m_pucTextureIndices)
            m_pucTextureIndices[index] = m_pucTextureIndices[last];
    }
    --m_usActive;
}

struct ParticleViewFrame
{
    unsigned int unk_00;
    unsigned int unk_04;
    unsigned int unk_08;
    unsigned int unk_0c;
    unsigned int unk_10;
    unsigned int unk_14;
    unsigned int unk_18;
    unsigned int unk_1c;
    unsigned int unk_20;
    unsigned int unk_24;
    unsigned int unk_28;
    unsigned int unk_2c;
    unsigned int unk_30;
    unsigned int unk_34;
    unsigned int unk_38;
    unsigned int unk_3c;
    unsigned int unk_40;
    unsigned int unk_44;
    unsigned int unk_48;
    unsigned int unk_4c;
    unsigned int unk_50;
    unsigned int unk_54;
    unsigned int unk_58;
    unsigned int unk_5c;
    unsigned int unk_60;
    NiPoint3 axisX, axisY, axisZ;
};
extern MemoryManager g_memoryManager;
inline void* operator new[](unsigned int bytes, MemoryManager& manager)
{
    return manager.Allocate(bytes);
}
struct ParticleViewData : NiParticlesData
{
    void FUN_00a966c0(int, int);
    void FUN_00a96910(ParticleViewFrame*);
};
// @fnv 0x00a96910
void ParticleViewData::FUN_00a96910(ParticleViewFrame* pViewFrame)
{
    if (!m_pusParticleIndices)
    {
        m_pusParticleIndices = new (g_memoryManager) unsigned short[m_usVertices];
        m_pfSortValues = new (g_memoryManager) float[m_usVertices];
    }
    for (unsigned short i = 0; i < m_usActive; ++i)
        m_pusParticleIndices[i] = i;
    if (m_usActive > 1)
    {
        NiPoint3 viewDirection = {pViewFrame->axisX.y, pViewFrame->axisY.y, pViewFrame->axisZ.y};
        for (unsigned short i = 0; i < m_usActive; ++i)
        {
            const NiPoint3& p = m_pkVertex[i];
            m_pfSortValues[i] = p.Dot(viewDirection);
        }
        FUN_00a966c0(0, m_usActive - 1);
    }
}

void* __cdecl FUN_00aa13e0(unsigned int uiSize);
inline void* __cdecl operator new(unsigned int, void* pv) throw()
{
    return pv;
}

struct Obj_a96
{
    void* m_vf;
    char pad[0x3c - 4];
    unsigned char m_3c;
    char pad3d[3];
    unsigned char m_40;
    char padCur[0x4c - 0x41];
    int m_4c;
    unsigned short m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    unsigned char m_6c;
    void FUN_00a67050(int i) throw();
    Obj_a96() throw()
    {
        FUN_00a67c00(this);
        m_vf = DAT_010a05e4;
        m_4c = 0;
        m_50 = 0;
        m_54 = 0;
        m_58 = 0;
        m_5c = 0;
        m_60 = 0;
        m_64 = 0;
        m_68 = 0;
        m_6c = 0;
        m_40 = 0;
        FUN_00a67050(0);
        m_3c = 0;
    }
};

// Allocates a 0x70-byte Obj_a96, constructs it, sets m_40 to 1, and returns it.
// @fnv 0x00a96660
Obj_a96* __cdecl CreateObj_a96()
{
    Obj_a96* pkObj = new (FUN_00aa13e0(0x70)) Obj_a96;
    pkObj->m_40 = 1;
    return pkObj;
}

inline bool EqualParticleRotation(const NiQuaternion& left, const NiQuaternion& right)
{
    return left.w == right.w && left.x == right.x && left.y == right.y && left.z == right.z;
}
inline bool EqualParticleAxis(const NiPoint3& left, const NiPoint3& right)
{
    return left.x == right.x && left.y == right.y && left.z == right.z;
}
inline bool EqualParticleOffset(const RgbaColor& left, const RgbaColor& right)
{
    return left.r == right.r && left.g == right.g && left.b == right.b && left.a == right.a;
}
struct GeometryEquality : NiGeometryData
{
    bool FUN_00a67840(NiObject* other);
};
struct ParticlesEquality : NiParticlesData
{
    bool FUN_00a96a30(NiObject* object);
};

// @fnv 0x00a96a30
bool ParticlesEquality::FUN_00a96a30(NiObject* apOther)
{
    if (!static_cast<GeometryEquality*>(static_cast<NiGeometryData*>(this))->FUN_00a67840(apOther))
        return false;
    NiParticlesData* other = static_cast<NiParticlesData*>(apOther);
    if ((m_pfRadii && !other->m_pfRadii) || (!m_pfRadii && other->m_pfRadii))
        return false;
    if (m_pfRadii)
    {
        for (unsigned short i = 0; i < m_usVertices; ++i)
            if (m_pfRadii[i] != other->m_pfRadii[i])
                return false;
    }
    if (m_usActive != other->m_usActive)
        return false;
    if ((m_pfSizes && !other->m_pfSizes) || (!m_pfSizes && other->m_pfSizes))
        return false;
    if (m_pfSizes)
    {
        for (unsigned short i = 0; i < m_usActive; ++i)
            if (m_pfSizes[i] != other->m_pfSizes[i])
                return false;
    }
    if ((m_pkRotations && !other->m_pkRotations) || (!m_pkRotations && other->m_pkRotations))
        return false;
    if (m_pkRotations)
    {
        for (unsigned int i = 0; i < m_usActive; ++i)
        {
            if (!EqualParticleRotation(m_pkRotations[i], other->m_pkRotations[i]))
                return false;
        }
    }
    if (m_pfRotationAngles)
    {
        for (unsigned int i = 0; i < m_usActive; ++i)
            if (m_pfRotationAngles[i] != other->m_pfRotationAngles[i])
                return false;
    }
    if (m_pkRotationAxes)
    {
        for (unsigned int i = 0; i < m_usActive; ++i)
        {
            if (!EqualParticleAxis(m_pkRotationAxes[i], other->m_pkRotationAxes[i]))
                return false;
        }
    }
    if (m_pucTextureIndices)
    {
        for (unsigned int i = 0; i < m_usActive; ++i)
            if (m_pucTextureIndices[i] != other->m_pucTextureIndices[i])
                return false;
    }
    if (m_pkSubTextureOffsets)
    {
        for (unsigned int i = 0; i < m_ucSubTextureOffsetCount; ++i)
        {
            if (!EqualParticleOffset(m_pkSubTextureOffsets[i], other->m_pkSubTextureOffsets[i]))
                return false;
        }
    }
    return true;
}

struct NiStream;
struct BinaryStream
{
    unsigned int unk00, position, unk08;
    unsigned int(__cdecl* writer)(BinaryStream*, const void*, unsigned int, const unsigned int*, unsigned int);
    void Write(const void* data, unsigned int size)
    {
        unsigned int component = size;
        position += writer(this, data, size, &component, 1);
    }
};
struct NiStream
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    BinaryStream* output;
};
struct GeoSave
{
    void FUN_00a68520(NiStream&);
};
struct NiColorA_SaveHelper
{
    float r, g, b, a;
    void SaveBinary(NiStream&);
};
struct FUN_00a97290_holder : NiParticlesData
{
    void FUN_00a97290(NiStream&);
};
// Writes presence flags for radii, sizes, rotations, angles, axes and texture indices, then the sub-texture offset count and each offset to the stream.
// @fnv 0x00a97290
void FUN_00a97290_holder::FUN_00a97290(NiStream& stream)
{
    ((GeoSave*)this)->FUN_00a68520(stream);
    bool hasRadii = m_pfRadii != 0;
    stream.output->Write(&hasRadii, 1);
    stream.output->Write(&m_usActive, 2);
    bool hasSizes = m_pfSizes != 0;
    stream.output->Write(&hasSizes, 1);
    bool hasRotations = m_pkRotations != 0;
    stream.output->Write(&hasRotations, 1);
    bool hasAngles = m_pfRotationAngles != 0;
    stream.output->Write(&hasAngles, 1);
    bool hasAxes = m_pkRotationAxes != 0;
    stream.output->Write(&hasAxes, 1);
    bool hasIndices = m_pucTextureIndices != 0;
    stream.output->Write(&hasIndices, 1);
    stream.output->Write(&m_ucSubTextureOffsetCount, 1);
    for (unsigned int i = 0; i < m_ucSubTextureOffsetCount; i++)
        ((NiColorA_SaveHelper*)m_pkSubTextureOffsets)[i].SaveBinary(stream);
}

template <class T> class NiTViewerArray
{
  public:
    virtual void v0();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (element != T(0))
                m_usESize++;
        }
        else
        {
            if (element != T(0))
            {
                if (m_pBase[uiIndex] == T(0))
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != T(0))
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = element;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, const T& element)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, element);
        return uiIndex;
    }
    unsigned int Add(const T& element)
    {
        return SetAtGrow(m_usSize, element);
    }
    unsigned int GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
};
typedef NiTViewerArray<char*> NiViewerStringsArray;

char* CreateDebugString(const char* pcName);
char* CreateDebugString(const char* pcName, unsigned short usValue);
char* CreateDebugString(const char* pcName, unsigned int uiValue);
char* CreateDebugString(const char* pcName, int iValue);
char* CreateDebugString(const char* pcName, const char* pcValue);
char* CreateDebugString(const char* pcName, void* pvValue);
char* CreateDebugString(const char* pcName, unsigned char ucValue);

extern const char* g_pcParticlesDataName;

class NiGeometryDataViewer
{
  public:
    virtual void v0();
    void GetViewerStrings(NiViewerStringsArray* pkStrings);
};

class NiParticlesDataViewer : public NiGeometryDataViewer
{
  public:
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
    float* m_pfRadii;
    unsigned short m_usActive;
    float* m_pfSizes;
    void* m_pkRotations;
    float* m_pfRotationAngles;
    void* m_pkRotationAxes;
    unsigned char* m_pucTextureIndices;
    void* m_pkSubTextureOffsets;
    unsigned char m_ucSubTextureOffsetCount;

    void FUN_00a97420(NiViewerStringsArray* pkStrings);
};

// Appends the base geometry viewer strings plus the particle radii, sizes, rotations, texture indices and sub-texture offsets to pkStrings.
// @fnv 0x00a97420
void NiParticlesDataViewer::FUN_00a97420(NiViewerStringsArray* pkStrings)
{
    NiGeometryDataViewer::GetViewerStrings(pkStrings);

    pkStrings->Add(CreateDebugString(g_pcParticlesDataName));
    pkStrings->Add(CreateDebugString("m_pfRadii", (void*)m_pfRadii));
    pkStrings->Add(CreateDebugString("m_usActive", m_usActive));
    pkStrings->Add(CreateDebugString("m_pfSizes", (void*)m_pfSizes));
    pkStrings->Add(CreateDebugString("m_pkRotations", m_pkRotations));
    pkStrings->Add(CreateDebugString("m_pfRotationAngles", (void*)m_pfRotationAngles));
    pkStrings->Add(CreateDebugString("m_pkRotationAxes", m_pkRotationAxes));
    pkStrings->Add(CreateDebugString("m_pucTextureIndices", (void*)m_pucTextureIndices));
    pkStrings->Add(CreateDebugString("m_ucSubTextureOffsetCount", m_ucSubTextureOffsetCount));
    pkStrings->Add(CreateDebugString("m_pkSubTextureOffsets", m_pkSubTextureOffsets));
}

class RenderOrderSorter
{
  public:
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
    unsigned short* m_pusParticleIndices;
    float* m_pfSortValues;
    void FUN_00a966c0(int left, int right);
};
// Partitions m_pusParticleIndices between left and right around a pivot value from m_pfSortValues, then recurses on both sub-ranges.
// @fnv 0x00a966c0
void RenderOrderSorter::FUN_00a966c0(int left, int right)
{
    int iLeft = left;
    int iRight = right;
    unsigned short usValue = m_pusParticleIndices[left];
    float fPivotValue = m_pfSortValues[m_pusParticleIndices[left]];
    while (left < right)
    {
        while ((m_pfSortValues[m_pusParticleIndices[right]] <= fPivotValue) && (left < right))
            right--;
        if (left != right)
        {
            m_pusParticleIndices[left] = m_pusParticleIndices[right];
            left++;
        }
        while ((m_pfSortValues[m_pusParticleIndices[left]] >= fPivotValue) && (left < right))
            left++;
        if (left != right)
        {
            m_pusParticleIndices[right] = m_pusParticleIndices[left];
            right--;
        }
    }
    m_pusParticleIndices[left] = usValue;
    int pivot = left;
    left = iLeft;
    right = iRight;
    if (left < pivot)
        FUN_00a966c0(left, pivot - 1);
    if (right > pivot)
        FUN_00a966c0(pivot + 1, right);
}

struct BinStream
{
    int unk0;
    int pos;
    int(__cdecl* readFn)(BinStream*, void*, int, void*, int);
    int Read(void* dest, int bytes, unsigned int elem)
    {
        unsigned int count = elem;
        int readBytes = readFn(this, dest, bytes, &count, 1);
        pos += readBytes;
        return readBytes;
    }
};
struct StreamIn
{
    int unk0;
    unsigned int ver4;
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
    unsigned int verD8;
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
    unsigned int unk_128;
    unsigned int unk_12c;
    unsigned int unk_130;
    unsigned int unk_134;
    unsigned int unk_138;
    unsigned int unk_13c;
    unsigned int unk_140;
    unsigned int unk_144;
    unsigned int unk_148;
    unsigned int unk_14c;
    unsigned int unk_150;
    unsigned int unk_154;
    unsigned int unk_158;
    unsigned int unk_15c;
    unsigned int unk_160;
    unsigned int unk_164;
    unsigned int unk_168;
    unsigned int unk_16c;
    unsigned int unk_170;
    unsigned int unk_174;
    unsigned int unk_178;
    unsigned int unk_17c;
    unsigned int unk_180;
    unsigned int unk_184;
    unsigned int unk_188;
    unsigned int unk_18c;
    unsigned int unk_190;
    unsigned int unk_194;
    unsigned int unk_198;
    unsigned int unk_19c;
    unsigned int unk_1a0;
    unsigned int unk_1a4;
    unsigned int unk_1a8;
    unsigned int unk_1ac;
    unsigned int unk_1b0;
    unsigned int unk_1b4;
    unsigned int unk_1b8;
    unsigned int unk_1bc;
    unsigned int unk_1c0;
    unsigned int unk_1c4;
    unsigned int unk_1c8;
    unsigned int unk_1cc;
    unsigned int unk_1d0;
    unsigned int unk_1d4;
    unsigned int unk_1d8;
    unsigned int unk_1dc;
    unsigned int unk_1e0;
    unsigned int unk_1e4;
    unsigned int unk_1e8;
    unsigned int unk_1ec;
    unsigned int unk_1f0;
    unsigned int unk_1f4;
    unsigned int unk_1f8;
    unsigned int unk_1fc;
    unsigned int unk_200;
    unsigned int unk_204;
    unsigned int unk_208;
    unsigned int unk_20c;
    unsigned int unk_210;
    unsigned int unk_214;
    unsigned int unk_218;
    unsigned int unk_21c;
    unsigned int unk_220;
    unsigned int unk_224;
    unsigned int unk_228;
    unsigned int unk_22c;
    unsigned int unk_230;
    unsigned int unk_234;
    unsigned int unk_238;
    unsigned int unk_23c;
    unsigned int unk_240;
    unsigned int unk_244;
    unsigned int unk_248;
    BinStream* kReadStream;
};
void* __cdecl FUN_00aa1070(unsigned int size);
void __cdecl ReadElements(StreamIn* stream, float* arr, unsigned int count);
void __cdecl FUN_00ec61c0(void* p, int val, unsigned int n);
struct A67EA0_shell
{
    void __thiscall ReadBinary(StreamIn* stream);
};
struct AllocSvc
{
    void* __thiscall FUN_00aa3e40(unsigned int n);
    void __thiscall FUN_00aa4060(void* p);
};
extern AllocSvc DAT_011f6238;
struct ArrNew
{
    static void* operator new[](unsigned int n)
    {
        return DAT_011f6238.FUN_00aa3e40(n);
    }
};
struct Rot16 : ArrNew
{
    float qx;
    float qy;
    float qz;
    float qw;
    void __thiscall FUN_00a69800(StreamIn* stream);
};
extern float DAT_011a9ea4;
extern float DAT_011a9ea8;
extern float DAT_011a9eac;
extern float DAT_011a9eb0;
extern char DAT_011f5f0c;
struct Axis12 : ArrNew
{
    float ax;
    float ay;
    float az;
    void __thiscall FUN_00a59be0(StreamIn* stream);
};
struct RTTILink
{
    const char* name;
    RTTILink* base;
};
struct RTTIView
{
    virtual void s0();
    virtual void s1();
    virtual RTTILink* GetRTTIChain();
};
template <class T> inline T* NewArray(unsigned short count)
{
    unsigned int elements = count;
    return new T[elements];
}
class ParticlesLoadView : public NiGeometryData
{
  public:
    bool m_bHasRadii;
    unsigned char unk41, unk42, unk43;
    unsigned short* m_pusParticleIndices;
    float* m_pfSortValues;
    float* m_pfRadii;
    unsigned short m_usActive;
    unsigned short unk52;
    float* m_pfSizes;
    Rot16* m_pkRotations;
    float* m_pfRotationAngles;
    Axis12* m_pkRotationAxes;
    unsigned char* m_pucTextureIndices;
    Rot16* m_pkSubTextureOffsets;
    unsigned char m_ucSubTextureOffsetCount;
    unsigned char unk6d, unk6e, unk6f;
    void __thiscall LoadBinary(StreamIn* stream);
};

// Reads particle-related values and flags from the stream, allocates arrays, and fills several arrays with defaults depending on version.
// @fnv 0x00a96cf0
void __thiscall ParticlesLoadView::LoadBinary(StreamIn* stream)
{
    union ReadValue
    {
        float radius;
        unsigned char flag;
    } value;
    ((A67EA0_shell*)this)->ReadBinary(stream);
    if (stream->verD8 < 0x4010007)
    {
        BinStream* kReadStream = stream->kReadStream;
        kReadStream->Read(&value.radius, 2, 2);
    }
    m_pfRadii = (float*)FUN_00aa1070((unsigned int)m_usVertices * 4);
    if (stream->verD8 < 0xa00010d)
    {
        BinStream* kReadStream = stream->kReadStream;
        kReadStream->Read(&value.radius, 4, 4);
        for (unsigned short i = 0; i < m_usVertices; i++)
        {
            m_pfRadii[i] = value.radius;
        }
    }
    else
    {
        unsigned char flag;
        BinStream* kReadStream = stream->kReadStream;
        kReadStream->Read(&flag, 1, 1);
        if (flag != 0 && stream->ver4 < 0x13)
        {
            ReadElements(stream, m_pfRadii, (unsigned int)m_usVertices);
        }
        else
        {
            for (unsigned short i = 0; i < m_usVertices; i++)
            {
                m_pfRadii[i] = 1.0f;
            }
        }
    }
    {
        BinStream* kReadStream = stream->kReadStream;
        kReadStream->Read(&m_usActive, 2, 2);
    }
    unsigned char sizeFlag;
    if (stream->verD8 < 0x4010007)
    {
        BinStream* kReadStream = stream->kReadStream;
        kReadStream->Read(&m_pfSizes, 4, 4);
        sizeFlag = (m_pfSizes != 0);
    }
    else
    {
        BinStream* kReadStream = stream->kReadStream;
        kReadStream->Read(&sizeFlag, 1, 1);
    }
    m_pfSizes = (float*)FUN_00aa1070((unsigned int)m_usVertices * 4);
    if (sizeFlag != 0 && stream->ver4 < 0x13)
    {
        BinStream* kReadStream = stream->kReadStream;
        kReadStream->Read(m_pfSizes, (unsigned int)m_usVertices * 4, 4);
    }
    else
    {
        for (unsigned short i = 0; i < m_usVertices; i++)
        {
            m_pfSizes[i] = 1.0f;
        }
    }
    if (m_bHasRadii)
    {
        unsigned char flag;
        if (stream->verD8 < 0x4010000)
        {
            BinStream* kReadStream = stream->kReadStream;
            kReadStream->Read(&m_pkRotations, 4, 4);
            flag = (m_pkRotations != 0);
        }
        else
        {
            BinStream* kReadStream = stream->kReadStream;
            kReadStream->Read(&flag, 1, 1);
        }
        m_pkRotations = NewArray<Rot16>(m_usVertices);
        if (flag != 0)
        {
            for (unsigned int i = 0; i < m_usVertices; i++)
            {
                m_pkRotations[i].FUN_00a69800(stream);
            }
        }
        else
        {
            for (unsigned int i = 0; i < m_usVertices; i++)
            {
                m_pkRotations[i] = *(Rot16*)&DAT_011a9ea4;
            }
        }
    }
    else if (stream->verD8 >= 0x5000008)
    {
        unsigned char flag;
        BinStream* kReadStream = stream->kReadStream;
        kReadStream->Read(&flag, 1, 1);
        if (flag != 0)
        {
            m_pkRotations = NewArray<Rot16>(m_usVertices);
            if (stream->ver4 < 0x13)
            {
                for (unsigned short i = 0; i < m_usVertices; i++)
                {
                    m_pkRotations[i].FUN_00a69800(stream);
                }
            }
            if (stream->verD8 <= 0xa000100)
            {
                RTTILink* pRttiChain = ((RTTIView*)this)->GetRTTIChain();
                while (pRttiChain != 0)
                {
                    if (pRttiChain == (void*)&DAT_011f5f0c)
                    {
                        goto keepRot;
                    }
                    pRttiChain = pRttiChain->base;
                }
                DAT_011f6238.FUN_00aa4060(m_pkRotations);
                m_pkRotations = 0;
            keepRot:;
            }
        }
    }
    if (stream->verD8 >= 0xa030005)
    {
        {
            unsigned char flag;
            BinStream* kReadStream = stream->kReadStream;
            kReadStream->Read(&flag, 1, 1);
            if (flag != 0)
            {
                m_pfRotationAngles = (float*)FUN_00aa1070((unsigned int)m_usVertices * 4);
                if (stream->ver4 < 0x13)
                {
                    for (unsigned short i = 0; i < m_usVertices; i++)
                    {
                        BinStream* s2 = stream->kReadStream;
                        s2->Read(&m_pfRotationAngles[i], 4, 4);
                    }
                }
            }
        }
        {
            BinStream* kReadStream = stream->kReadStream;
            kReadStream->Read(&value.flag, 1, 1);
            if (value.flag != 0)
            {
                m_pkRotationAxes = NewArray<Axis12>(m_usVertices);
                if (stream->ver4 < 0x13)
                {
                    for (unsigned short i = 0; i < m_usVertices; i++)
                    {
                        ((Axis12*)&m_pkRotationAxes[i])->FUN_00a59be0(stream);
                    }
                }
            }
        }
    }
    if (stream->ver4 > 0x11)
    {
        BinStream* kReadStream = stream->kReadStream;
        kReadStream->Read(&value.flag, 1, 1);
        if (value.flag != 0)
        {
            m_pucTextureIndices = (unsigned char*)FUN_00aa1070((unsigned int)m_usVertices);
            FUN_00ec61c0(m_pucTextureIndices, 0, (unsigned int)m_usVertices);
        }
        kReadStream = stream->kReadStream;
        kReadStream->Read(&m_ucSubTextureOffsetCount, 1, 1);
        if (m_ucSubTextureOffsetCount > 0)
        {
            m_pkSubTextureOffsets = (Rot16*)FUN_00aa1070((unsigned int)m_ucSubTextureOffsetCount * 16);
            for (unsigned short i = 0; i < m_ucSubTextureOffsetCount; i++)
            {
                m_pkSubTextureOffsets[i].FUN_00a69800(stream);
            }
        }
    }
}

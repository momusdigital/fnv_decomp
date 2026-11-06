// gamebryo2.2/corelibs/nimain/niskindata.cpp: NiSkinData, FakeSkin, SkinDataLike, SkinDataBounds and more (11 functions)

#include "niskindata_packet.h"
// Checks whether the root bone or any bone name is present in context.map, returning true on the first hit.
// @fnv 0x00a862d0
bool NiSkinData::MapSkinData(SkinMapContext& context)
{
    ShaderBufferRecord* result;
    if (context.map->GetAt(root, result))
        return true;
    unsigned int count = bones->count;
    for (unsigned int i = 0; i < count; ++i)
        if (context.map->GetAt(names[i], result))
            return true;
    return false;
}

struct FUN_00a632e0_shell
{
    void FUN_00a632e0(int value);
};

// @fnv 0x00a632e0
void FUN_00a632e0_shell::FUN_00a632e0(int value)
{
    *(int*)((char*)this + 0x3b8) = value;
}

extern int g_011f5b24;

// Returns the address of the global variable g_011f5b24.
// @fnv 0x00a84d20
int __cdecl GetGlobalAddress()
{
    return (int)&g_011f5b24;
}

struct NiStream;
struct NiObject
{
    virtual void LinkObject(NiStream&);
    int _04;
};
struct NiStream
{
    NiObject* GetLoadedObject();
    unsigned char _00[0xD8];
    unsigned int m_uiNifVersion;
};
struct GO
{
    void* p;
    GO& operator=(void*);
};
struct FakeSkin : NiObject
{
    GO m_sp;
    void FUN_00a84ce0(NiStream&);
};
// @fnv 0x00a84ce0
void FakeSkin::FUN_00a84ce0(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    if (kStream.m_uiNifVersion >= 0x4000001 && kStream.m_uiNifVersion < 0xa010065)
        m_sp = kStream.GetLoadedObject();
}

struct _Call_a5d3a0
{
    _Call_a5d3a0();
};
struct BSFadeNode : _Call_a5d3a0
{
    void* operator new(unsigned int size);
};
extern int DAT_0109e574;
// @fnv 0x00a84d30
void* __cdecl FUN_00a84d30()
{
    void* p = BSFadeNode::operator new(0x48);
    if (p)
    {
        ((BSFadeNode*)p)->_Call_a5d3a0::_Call_a5d3a0();
        *(int*)p = (int)&DAT_0109e574;
        *(int*)((char*)p + 8) = 0;
        *(int*)((char*)p + 0x40) = 0;
        return p;
    }
    return 0;
}

struct SkinCompareEntry
{
    unsigned short key;
    unsigned short unk02;
    float value;
};

struct SkinCompareOps
{
    bool CompareSub(void* other);
    bool CompareTail(void* other);
    bool CompareRoot(void* other);
    char unk00[0x10];
};

struct SkinShape
{
    char unk00[0x34];
    SkinCompareOps m_34;
    SkinCompareEntry* m_44;
    unsigned short m_48;
    unsigned short unk4a;
};

struct FUN_00a84d70_cls
{
    char unk00[0x0c];
    char unk0c[0x28];
    char unk34[0x0c];
    SkinShape* m_40;
    unsigned int m_44;
    bool Equals(FUN_00a84d70_cls* other);
};

// Compares this object with another: root, sub-block, count, then each shape's ops, tail, count and entry keys/values; returns true if all match.
// @fnv 0x00a84d70
bool FUN_00a84d70_cls::Equals(FUN_00a84d70_cls* other)
{
    if (!reinterpret_cast<SkinCompareOps*>(this)->CompareRoot(other))
    {
        return false;
    }
    if (reinterpret_cast<SkinCompareOps*>(&unk0c)->CompareSub(&other->unk0c))
    {
        return false;
    }
    if (m_44 != other->m_44)
    {
        return false;
    }
    for (unsigned int i = 0; i < m_44; ++i)
    {
        SkinShape* pShape = m_40 + i;
        SkinShape* pOtherShape = other->m_40 + i;
        if (reinterpret_cast<SkinCompareOps*>(pShape)->CompareSub(pOtherShape))
        {
            return false;
        }
        if (pShape->m_34.CompareTail(&pOtherShape->m_34))
        {
            return false;
        }
        if (pShape->m_48 != pOtherShape->m_48)
        {
            return false;
        }
        for (unsigned int j = 0; j < pShape->m_48; ++j)
        {
            if (pShape->m_44[j].key != pOtherShape->m_44[j].key)
            {
                return false;
            }
            if (pShape->m_44[j].value != pOtherShape->m_44[j].value)
            {
                return false;
            }
        }
    }
    return true;
}

struct S_00a84e70_Pool
{
    void* FUN_00aa3e40(unsigned int size);
    void FUN_00aa4060(void* p);
};
extern S_00a84e70_Pool DAT_011f6238;

struct S_00a84e70_Elem
{
    int unk00;
    int unk04;
    int unk08;
    static void* operator new[](unsigned int size)
    {
        return DAT_011f6238.FUN_00aa3e40(size);
    }
};

struct S_00a84e70_Array
{
    S_00a84e70_Elem* m_data;
    unsigned int m_pRayCursor;
    unsigned int m_uiItemCount;
    void Reserve(unsigned int newCapacity);
};

// @fnv 0x00a84e70
void S_00a84e70_Array::Reserve(unsigned int newCapacity)
{
    if (newCapacity == m_pRayCursor)
    {
        return;
    }
    S_00a84e70_Elem* newData;
    if (newCapacity > 0)
    {
        newData = new S_00a84e70_Elem[newCapacity];
        for (unsigned int i = 0; i < m_uiItemCount; i++)
        {
            newData[i] = m_data[i];
        }
    }
    else
    {
        newData = 0;
    }
    DAT_011f6238.FUN_00aa4060(m_data);
    m_data = newData;
    m_pRayCursor = newCapacity;
}

struct NiBinaryStream;
typedef unsigned int (*NiBinaryStreamWriteFn)(NiBinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                              unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    NiBinaryStreamWriteFn m_pfnWrite;
    void Write(const void* pv, unsigned int uiBytes, unsigned int uiComponentSize)
    {
        m_uiStreamFlags += m_pfnWrite(this, pv, uiBytes, &uiComponentSize, 1);
    }
};

struct SkinStream
{
    void* vtbl;
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
    NiBinaryStream* m_pBackingStream;
};

template <class T> inline void SkinSaveBinary(SkinStream& kStream, T& val)
{
    NiBinaryStream* pkBS = kStream.m_pBackingStream;
    pkBS->Write(&val, sizeof(T), sizeof(T));
}

struct SkinTransform
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    float tx, ty, tz;
    float scale;
    void SaveBinary(SkinStream& kStream);
};

struct NiSphere
{
    float x, y, z, r;
    void SaveBinary(SkinStream& kStream);
};

struct SkinBoneVertData
{
    unsigned short m_usBoneIndex;
    float m_fWeight;
};

struct SkinBoneData
{
    SkinTransform m_kSkinToBoneTransform;
    NiSphere m_kBound;
    SkinBoneVertData* m_pkVertexWeights;
    unsigned short m_usVertexWeightCount;
};

struct SkinObjectBase
{
    void* vtbl;
    int unk04;
    int unk08;
    void SaveBinary(SkinStream& kStream);
};

struct SkinDataLike : SkinObjectBase
{
    SkinTransform m_kSkinTransform;
    SkinBoneData* m_pBoneData;
    unsigned int m_uiBoneCount;
    void FUN_00a85250(SkinStream& kStream);
};

// Saves the skin object base, transform, bone count, vertex-weight flag and each bone's transform, bound, vertex count and optional vertex weights to the stream.
// @fnv 0x00a85250
void SkinDataLike::FUN_00a85250(SkinStream& kStream)
{
    SkinObjectBase::SaveBinary(kStream);
    m_kSkinTransform.SaveBinary(kStream);
    SkinSaveBinary(kStream, m_uiBoneCount);
    bool bHasVertexWeights = m_pBoneData->m_pkVertexWeights != 0;
    SkinSaveBinary(kStream, bHasVertexWeights);

    for (unsigned int i = 0; i < m_uiBoneCount; i++)
    {
        SkinBoneData* pkBoneData = &m_pBoneData[i];
        pkBoneData->m_kSkinToBoneTransform.SaveBinary(kStream);
        pkBoneData->m_kBound.SaveBinary(kStream);
        SkinSaveBinary(kStream, pkBoneData->m_usVertexWeightCount);
        if (bHasVertexWeights)
        {
            for (unsigned int j = 0; j < pkBoneData->m_usVertexWeightCount; j++)
            {
                SkinBoneVertData* pkVert = &pkBoneData->m_pkVertexWeights[j];
                SkinSaveBinary(kStream, pkVert->m_usBoneIndex);
                SkinSaveBinary(kStream, pkVert->m_fWeight);
            }
        }
    }
}

struct Point3
{
    float x, y, z;
};
struct PoolBounds
{
    void FUN_00aa4060(void* p) throw();
};
struct PointList
{
    Point3* m_data;
    unsigned int m_pRayCursor;
    unsigned int m_uiItemCount;
    PointList() throw() : m_data(0), m_pRayCursor(0), m_uiItemCount(0)
    {}
    ~PointList() throw()
    {
        reinterpret_cast<PoolBounds*>(&DAT_011f6238)->FUN_00aa4060(m_data);
    }
    __declspec(noalias) void Reserve(unsigned int capacity) throw();
    void Append(const Point3& p) throw()
    {
        if (m_uiItemCount == m_pRayCursor)
            Reserve(m_pRayCursor > 0 ? 2 * m_pRayCursor : 1);
        m_data[m_uiItemCount] = p;
        ++m_uiItemCount;
    }
};
struct BoundBuilder
{
    void ComputeBoundingSphere(unsigned int count, Point3* points) throw();
    void FUN_00a7fdd0(const NiSphere& bound, const SkinTransform& transform) throw();
};

struct SkinDataBounds : SkinObjectBase
{
    SkinTransform m_kSkinTransform;
    SkinBoneData* m_pBoneData;
    unsigned int m_uiBoneCount;
    void FUN_00a853c0(Point3* vertices);
};

// For each bone, collects vertex positions from its weighted vertices, computes their bounding sphere, and transforms it into bone space.
// @fnv 0x00a853c0
void SkinDataBounds::FUN_00a853c0(Point3* vertices)
{
    PointList points;
    for (unsigned int i = 0; i < m_uiBoneCount; ++i)
    {
        for (unsigned int j = 0; j < m_pBoneData[i].m_usVertexWeightCount; ++j)
        {
            Point3* pVertex = vertices + m_pBoneData[i].m_pkVertexWeights[j].m_usBoneIndex;
            points.Append(*pVertex);
        }
        reinterpret_cast<BoundBuilder*>(&m_pBoneData[i].m_kBound)
            ->ComputeBoundingSphere(points.m_uiItemCount, points.m_data);
        reinterpret_cast<BoundBuilder*>(&m_pBoneData[i].m_kBound)
            ->FUN_00a7fdd0(m_pBoneData[i].m_kBound, m_pBoneData[i].m_kSkinToBoneTransform);
        points.m_uiItemCount = 0;
    }
}

#include <windows.h>
extern int DAT_0109e574;

struct a84ef0_Counted
{
    virtual void v00();
    virtual void Release();
    int refCount;
};

struct a84ef0_Mgr
{
    void FUN_00aa4060(unsigned int value);
};

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00a84ef0_cls
{
    int m_vptr;
    int unk04;
    a84ef0_Counted* m_pCounted;
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
    unsigned int m_uValue;

    void BaseCleanupA();
    void BaseCleanupB();
    FUN_00a84ef0_cls* FUN_00a84ef0(unsigned char acFlags);
};

// @fnv 0x00a84ef0
FUN_00a84ef0_cls* FUN_00a84ef0_cls::FUN_00a84ef0(unsigned char acFlags)
{
    m_vptr = (int)&DAT_0109e574;
    BaseCleanupA();
    ((a84ef0_Mgr*)&DAT_011f6238)->FUN_00aa4060(m_uValue);
    a84ef0_Counted* pCounted = m_pCounted;
    if (pCounted != 0)
    {
        if (InterlockedDecrement((long volatile*)&pCounted->refCount) == 0)
        {
            pCounted->Release();
        }
    }
    BaseCleanupB();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x48);
    }
    return this;
}

namespace SkinDataText {
extern "C" const char DAT_0109e644[];
extern "C" const char DAT_0109e60c[];
extern "C" const char DAT_0109e600[];
}
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern int __cdecl FUN_00aa1360(const char*, const char*);
extern void(__cdecl* DAT_011ac2ac)(const char*, const char*, int);
struct SkinLoadStream : SkinStream
{
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    void FUN_00a645b0();
};
struct SkinLoadError
{
    void SetError(int value);
};
struct SkinLoadBase
{
    void ReadGroup(SkinLoadStream&);
};
struct SkinLoadTransform
{
    void FUN_00a86c80(SkinLoadStream&);
};
struct SkinLoadSphere
{
    void FUN_00a69ac0(SkinLoadStream&);
};
struct SkinLoadBinaryStream
{
    void* vtbl;
    unsigned int position;
    unsigned int(__cdecl* read)(SkinLoadBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* value, unsigned int bytes, unsigned int component)
    {
        position += read(this, value, bytes, &component, 1);
    }
};
template <class T> inline void SkinLoadBinary(SkinLoadStream& stream, T& value)
{
    SkinLoadBinaryStream* input = (SkinLoadBinaryStream*)stream.unk24c;
    input->Read(&value, sizeof(T), sizeof(T));
}
struct SkinLoadWeight
{
    unsigned short vertex;
    float weight;
    SkinLoadWeight() : vertex(0)
    {}
    static void* operator new[](unsigned int size)
    {
        return DAT_011f6238.FUN_00aa3e40(size);
    }
};
struct ResetFields
{
    SkinTransform transform;
    NiSphere bound;
    SkinLoadWeight* weights;
    unsigned short vertices;
    ResetFields() throw();
    static void* operator new[](unsigned int size)
    {
        return DAT_011f6238.FUN_00aa3e40(size);
    }
};
struct SkinLoadData : SkinObjectBase
{
    SkinTransform rootParentToSkin;
    ResetFields* bones;
    unsigned int boneCount;
    void LoadBinary(SkinLoadStream& stream);
};
// Reads skin data from a stream: base, transform, bone count, per-bone transforms/bounds/weights, and an optional trailing flag.
// @fnv 0x00a84f50
void SkinLoadData::LoadBinary(SkinLoadStream& stream)
{
    ((SkinLoadBase*)this)->ReadGroup(stream);
    ((SkinLoadTransform*)&rootParentToSkin)->FUN_00a86c80(stream);
    SkinLoadBinary(stream, boneCount);
    bones = new ResetFields[boneCount];
    if ((unsigned int)stream.unk0d8 >= 0x04000001 && (unsigned int)stream.unk0d8 < 0x0a010065)
        stream.FUN_00a645b0();
    bool hasWeights;
    if ((unsigned int)stream.unk0d8 >= 0x0401000d)
        SkinLoadBinary(stream, hasWeights);
    else
        hasWeights = true;
    char message[0x200];
    if ((unsigned int)stream.unk0dc < 11 && stream.unk3b8 == 0 && boneCount != 0 &&
        FUN_00aa1360((const char*)&stream.unk0e0, "Meshes\\Creatures\\Rat\\mange.NIF"))
    {
        ((SkinLoadError*)&stream)->SetError(3);
        if (*(const char*)&stream.unk008)
            sprintf(message, SkinDataText::DAT_0109e644, (const char*)&stream.unk008, (const char*)&stream.unk0e0);
        else
            sprintf(message, SkinDataText::DAT_0109e60c, (const char*)&stream.unk0e0);
        if (DAT_011ac2ac)
            DAT_011ac2ac(message, SkinDataText::DAT_0109e600, 0);
    }
    for (unsigned int i = 0; i < boneCount; ++i)
    {
        ResetFields& bone = bones[i];
        ((SkinLoadTransform*)&bone.transform)->FUN_00a86c80(stream);
        ((SkinLoadSphere*)&bone.bound)->FUN_00a69ac0(stream);
        SkinLoadBinary(stream, bone.vertices);
        if (hasWeights)
        {
            bone.weights = new SkinLoadWeight[bone.vertices];
            for (unsigned int j = 0; j < bone.vertices; ++j)
            {
                SkinLoadWeight& weight = bone.weights[j];
                SkinLoadBinary(stream, weight.vertex);
                SkinLoadBinary(stream, weight.weight);
            }
        }
        else
        {
            bone.weights = 0;
        }
    }
    if ((unsigned int)stream.unk0d8 == 0x04010009)
    {
        bool unused;
        SkinLoadBinary(stream, unused);
    }
}

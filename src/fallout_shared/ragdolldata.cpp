// fallout_shared/ragdolldata.cpp: RagDollData, RagDollDataEx, RagDollRefUpdater, RagDollWalker and more (17 functions)

#include "ragdolldata_decls.h"

// Returns the negation of operator== for this matrix compared with another matrix.
// @fnv 0x004d9ab0
bool ThreeByThreeMatrix::operator!=(const ThreeByThreeMatrix& matrix) const
{
    return !(*this == matrix);
}

// Recursively applies stored bone translation and rotation to node and its children, advancing index while bones remain.
// @fnv 0x004d9dc0
bool RagDollData::FindBoneIndex(NiNode* node, unsigned int& ruiIndex)
{
    bool result = true;
    if (node && ruiIndex < count)
    {
        bhkCollisionObject* collision = FUN_004a8b00(node);
        if (collision)
        {
            {
                int id = collision->FUN_006fa820()->FUN_0043b4f0().FUN_004d9da0();
                if (bones[ruiIndex].id != id)
                    return false;
            }
            node->FUN_00440460(bones[ruiIndex].translate);
            ThreeByThreeMatrix rotation;
            rotation.FUN_00a59540(bones[ruiIndex].rotate.x, bones[ruiIndex].rotate.y, bones[ruiIndex].rotate.z);
            node->FUN_0043fa80(&rotation);
            collision->FUN_004d9fa0(true);
            collision->vfn_b0(1, 0, 0);
            ++ruiIndex;
        }
        NiUpdateData update(0.0f, false, false);
        node->UpdateWorldData(update);
        unsigned int children = node->FUN_0043b480();
        for (unsigned int i = 0; i < children; ++i)
        {
            NiNode* childNode;
            {
                NiAVObject* child = node->FUN_0043b4a0(i);
                childNode = child ? child->IsSceneNode() : 0;
            }
            if (childNode && !FindBoneIndex(childNode, ruiIndex))
                result = false;
            if (ruiIndex >= count)
                break;
        }
    }
    return result;
}

struct CFilter
{
    bool QLinkedGroup();
    void SetLinkedGroup(bool);
    bool QNoCollision();
    void SetCollisionDisabled(bool);
    bool QMoppScaled();
    void SetMoppScaled(bool);
    bool QBipLayer();
    int GetLayer();
    void SetLayer(int);
    int GetBipedPart();
    unsigned int GetPart();
    void SetPart(unsigned int);
    unsigned int GetGroup();
    void SetGroup(unsigned int);
    void Init(int, unsigned int, int);
    void MakeSubShapeFilter();
    void GetViewerStrings(void*);
    void __dflt_ctor_closure();
    unsigned int iFilter;
};
typedef char _sizecheck_CFilter[sizeof(CFilter) == 4 ? 1 : -1];
struct FUN_004d9da0_shell : public CFilter
{
    unsigned int FUN_004d9da0();
};

// @fnv 0x004d9da0
unsigned int FUN_004d9da0_shell::FUN_004d9da0()
{
    return (iFilter >> 8) & 0x1f;
}

struct _dummy_4d9fa0
{
    void FUN_004d9fc0(bool, unsigned short);
    void FUN_004d9fa0(bool abTF);
};

// @fnv 0x004d9fa0
void _dummy_4d9fa0::FUN_004d9fa0(bool abTF)
{
    FUN_004d9fc0(abTF, 0x40);
}

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int* p, EndianSizeTag<4>);

struct FUN_004d9280
{
    void __thiscall EndianSwap();
};

// Byte-swaps the six 4-byte words following the object's first word via BSEndian.
// @fnv 0x004d9280
void __thiscall FUN_004d9280::EndianSwap()
{
    BSEndian((int*)this + 1, EndianSizeTag<4>());
    BSEndian((int*)this + 2, EndianSizeTag<4>());
    BSEndian((int*)this + 3, EndianSizeTag<4>());
    BSEndian((int*)this + 4, EndianSizeTag<4>());
    BSEndian((int*)this + 5, EndianSizeTag<4>());
    BSEndian((int*)this + 6, EndianSizeTag<4>());
}

struct FUN_004d9fc0_shell
{
    unsigned short m_flags;  // +0xc
    void FUN_004d9fc0(bool abSet, unsigned short uFlags);
};

// Sets or clears the given flag bits in the 16-bit flags field at offset 0xc of this object.
// @fnv 0x004d9fc0
void FUN_004d9fc0_shell::FUN_004d9fc0(bool abSet, unsigned short uFlags)
{
    if (abSet)
        ((unsigned short*)((char*)this + 0xc))[0] |= uFlags;
    else
        ((unsigned short*)((char*)this + 0xc))[0] &= ~uFlags;
}

// Recursively counts node and its descendants for which FUN_004a8b00 returns true, returning the total count.
// @fnv 0x004da180
unsigned char CountRagDollBones(NiNode* node)
{
    unsigned char count = 0;
    if (node)
    {
        if (FUN_004a8b00(node))
            ++count;
        unsigned int total = node->FUN_0043b480();
        for (unsigned int i = 0; i < total; ++i)
        {
            NiAVObject* object = node->FUN_0043b4a0(i);
            NiNode* child = object ? object->IsSceneNode() : 0;
            if (child)
                count += CountRagDollBones(child);
        }
    }
    return count;
}

namespace fnv_004d94a0 {
struct FUN_004d94a0_shell : public RagDollData
{
    bool LoadRagdollChunk(TESFile*);
};

void* __cdecl operator new(unsigned int);
template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<1>);
struct FUN_004d9280
{
    void EndianSwap();
};
struct FUN_0055a400 : FUN_004d9280
{
    char pad[0x1c];
    FUN_0055a400();
};
struct TESFileAccessor
{
    bool GetChunkData();
};
// @fnv 0x004d94a0
bool FUN_004d94a0_shell::LoadRagdollChunk(TESFile* apFile)
{
    bool bretval = false;
    if (apFile->GetChunkID() == 0x44475258)
    {
        unsigned int isize = apFile->GetChunkSize();
        *(unsigned char*)this = isize / sizeof(FUN_0055a400);
        if (isize % *(unsigned char*)this == 0)
        {
            *(FUN_0055a400**)((char*)this + 4) = new FUN_0055a400[*(unsigned char*)this];
            apFile->GetChunkData(*(FUN_0055a400**)((char*)this + 4), isize);
            if (((TESFileAccessor*)apFile)->GetChunkData())
            {
                for (unsigned int I = 0; I < *(unsigned char*)this; I++)
                    (*(FUN_0055a400**)((char*)this + 4))[I].EndianSwap();
            }
            bretval = true;
        }
        else
            *(unsigned char*)this = 0;
    }
    if (apFile->GetChunkID() == 0x42475258)
    {
        apFile->GetChunkData((char*)this + 8, 0xc);
        if (((TESFileAccessor*)apFile)->GetChunkData())
        {
            BSEndian((unsigned char*)this + 8, EndianSizeTag<1>());
            BSEndian((unsigned char*)this + 0xc, EndianSizeTag<1>());
            BSEndian((unsigned char*)this + 0x10, EndianSizeTag<1>());
        }
        bretval = true;
    }
    return bretval;
}
}  // namespace fnv_004d94a0

struct Call_439090
{
    bool operator==(const Call_439090& a) const;
};

int _memcmp(const void*, const void*, unsigned int);

struct FUN_004d9780_shell
{
    unsigned char m_ucValue;
    TransformEntry* m_pTransformEntry;
    bool FUN_004d9780(FUN_004d9780_shell* apCompare);
};

// @fnv 0x004d9780
bool FUN_004d9780_shell::FUN_004d9780(FUN_004d9780_shell* apCompare)
{
    if (!apCompare)
        return true;
    if (m_ucValue != apCompare->m_ucValue)
        return true;
    if (*(Call_439090*)((char*)this + 8) == *(Call_439090*)((char*)apCompare + 8))
        return true;
    if (m_ucValue && _memcmp(m_pTransformEntry, apCompare->m_pTransformEntry, m_ucValue * 0x1c))
        return true;
    return false;
}

extern void __cdecl _Deallocate(void*);
extern void* __cdecl __memcpy(void*, const void*, unsigned int);
extern unsigned int _data_011c16bc;

struct DoorTeleportLoadData
{
    unsigned int data[7];

    DoorTeleportLoadData();
};

struct FUN_004d9670_shell
{
    struct Data
    {
        unsigned int value0;
        unsigned int value1;
        unsigned int value2;
    };

    unsigned char count;
    DoorTeleportLoadData* items;
    Data data;

    void FUN_004d9670(const FUN_004d9670_shell* source);
};

// Copies count, data and the items array from source into this object, reallocating the items buffer.
// @fnv 0x004d9670
void FUN_004d9670_shell::FUN_004d9670(const FUN_004d9670_shell* source)
{
    if (source)
    {
        DoorTeleportLoadData* oldItems = items;
        _Deallocate(oldItems);

        count = source->count;
        data = source->data;

        items = new DoorTeleportLoadData[count];

        __memcpy(items, source->items, count * sizeof(DoorTeleportLoadData));
    }
}

struct FUN_004d93c0_bone
{
    signed char unk00;
    float translate[3];
    float rotate[3];
    void EndianSwap();
};

struct FUN_004d93c0_name
{
    unsigned int m_00;
    unsigned int m_04;
    bool Matches(const char* name);
};

struct FUN_004d93c0_cls
{
    unsigned char m_uiItemCount;
    FUN_004d93c0_bone* m_kBones;
    FUN_004d93c0_name m_name;
    void FUN_004d93c0();
};

bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int tag, void* p, unsigned int size);
void __cdecl FUN_00485710(unsigned int tag, void* p, unsigned int n);
extern char DAT_011f426c[];

// @fnv 0x004d93c0
void FUN_004d93c0_cls::FUN_004d93c0()
{
    if (m_uiItemCount != 0)
    {
        if (FUN_00401500())
        {
            for (unsigned int i = 0; i < m_uiItemCount; i++)
            {
                m_kBones[i].EndianSwap();
            }
        }
        AppendChunk(0x44475258, m_kBones, m_uiItemCount * 28);
        if (FUN_00401500())
        {
            for (unsigned int uiSwapIndex = 0; uiSwapIndex < m_uiItemCount; uiSwapIndex++)
            {
                m_kBones[uiSwapIndex].EndianSwap();
            }
        }
    }
    if (m_name.Matches(DAT_011f426c))
    {
        FUN_00485710(0x42475258, &m_name, 3);
    }
}

class RagDollRefStandIn
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual bool IsActor();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiAVObject* Get3D();
};

class RagDollDataEx : public RagDollData
{
  public:
    void ReadFromActor(RagDollRefStandIn* apRef);
    void ReadFromRef(RagDollRefStandIn* apRef);
    bool ApplyToAnimationData(NiNode* apNode, unsigned int& auiIndex, unsigned int auiDepth);
    bool UpdateDataFromReference(RagDollRefStandIn* apRef);
};

// @fnv 0x004d9800
bool RagDollDataEx::UpdateDataFromReference(RagDollRefStandIn* apRef)
{
    unsigned int uiIndex = 0;
    bool bResultTmp = true;
    if (apRef && apRef->Get3D())
    {
        NiAVObject* p3D = apRef->Get3D();
        NiNode* pNode2 = p3D ? p3D->IsSceneNode() : 0;
        if (apRef->IsActor())
            ReadFromActor(apRef);
        if (!count)
            ReadFromRef(apRef);
        if (count)
            bResultTmp = ApplyToAnimationData(pNode2, uiIndex, 0);
        if (!bResultTmp)
            ReadFromRef(apRef);
    }
    return uiIndex == count && bResultTmp;
}

class TESObjectREFR
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual bool IsDynamicHavok();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual NiPoint3* GetPos();
    NiAVObject* Get3DSimple();
    ThreeByThreeMatrix GetRotation();
};

class NiAVObjectEx : public NiAVObject
{
  public:
    NiPoint3& GetLocalTranslate();
    ThreeByThreeMatrix& GetLocalRotate();
    void SetLocalRotate(const ThreeByThreeMatrix&);
    void Update(NiUpdateData&);
};

struct NiPoint3Cmp
{
    bool NotEqual(const NiPoint3& pt) const;
};

struct NiMatrix3Cmp
{
    bool NotEqual(const ThreeByThreeMatrix& m) const;
};

void __cdecl FUN_00c6bd00(NiAVObject* apObject, bool abFlag);
void __cdecl FUN_00c6a350(NiNode* apNode, int aiVal, bool ab1, bool ab2, bool ab3);

struct RagDollRefUpdater
{
    bool bEnabled;
    void SyncRef(TESObjectREFR* apRef);
    bool ApplyToAnimationData(NiNode* apNode, unsigned int& auiCount);
    bool FUN_004d9910(TESObjectREFR* apRef);
};

// @fnv 0x004d9910
bool RagDollRefUpdater::FUN_004d9910(TESObjectREFR* apRef)
{
    unsigned int ItemUpdateArray = 0;
    bool bResult = true;
    if (apRef && apRef->Get3DSimple() && bEnabled)
    {
        NiAVObjectEx* p3D2 = (NiAVObjectEx*)apRef->Get3DSimple();
        NiNode* pNode4 = p3D2 ? p3D2->IsSceneNode() : 0;
        if (apRef->IsDynamicHavok())
            SyncRef(apRef);
        bResult = ApplyToAnimationData(pNode4, ItemUpdateArray);
        if (p3D2)
        {
            if (((NiPoint3Cmp&)p3D2->GetLocalTranslate()).NotEqual(*apRef->GetPos()) ||
                ((NiMatrix3Cmp&)p3D2->GetLocalRotate()).NotEqual(apRef->GetRotation()))
            {
                p3D2->FUN_00440460(*apRef->GetPos());
                p3D2->SetLocalRotate(apRef->GetRotation());
                FUN_00c6bd00(p3D2, true);
                NiUpdateData kData6(0.0f, false, false);
                p3D2->Update(kData6);
            }
        }
        if (!bResult)
            FUN_00c6a350(pNode4, 1, 1, 0, 1);
    }
    return ItemUpdateArray == bEnabled && bResult;
}

struct EulerMatrix
{
    void ExtractEulerAnglesXYZ(float& x, float& y, float& z);
};
struct AVObjectLocal
{
    NiPoint3& GetLocalTranslate();
    EulerMatrix* GetLocalRotate();
};

struct RagDollWalker
{
    unsigned char count;
    TransformEntry* bones;
    bool CollectBoneTransforms(NiNode* apNode, unsigned int& arIndex, bool abSet);
};

// @fnv 0x004d9bd0
bool RagDollWalker::CollectBoneTransforms(NiNode* apNode, unsigned int& arIndex, bool abSet)
{
    bool bResult2 = true;
    if (apNode && arIndex < count)
    {
        bhkCollisionObject* pCollision = FUN_004a8b00(apNode);
        if (pCollision)
        {
            if (abSet)
            {
                bones[arIndex].id = pCollision->FUN_006fa820()->FUN_0043b4f0().FUN_004d9da0();
            }
            else if (bones[arIndex].id != pCollision->FUN_006fa820()->FUN_0043b4f0().FUN_004d9da0())
            {
                return false;
            }
            bones[arIndex].translate = ((AVObjectLocal*)apNode)->GetLocalTranslate();
            ((AVObjectLocal*)apNode)
                ->GetLocalRotate()
                ->ExtractEulerAnglesXYZ(bones[arIndex].rotate.x, bones[arIndex].rotate.y, bones[arIndex].rotate.z);
            arIndex++;
        }
        unsigned int uiCount5 = apNode->FUN_0043b480();
        for (unsigned int i3 = 0; i3 < uiCount5; i3++)
        {
            NiAVObject* pChild2 = apNode->FUN_0043b4a0(i3);
            NiNode* pChildNode = pChild2 ? pChild2->IsSceneNode() : 0;
            if (pChildNode)
            {
                if (!CollectBoneTransforms(pChildNode, arIndex, abSet))
                {
                    bResult2 = false;
                }
            }
            if (arIndex >= count)
            {
                break;
            }
        }
    }
    return bResult2;
}

struct VisualNode;
struct VisualObject
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual VisualNode* IsSceneNode();
};
struct SceneInput
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual bool FUN_0100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual struct VisualObject* FUN_01d0();
};
struct NamedLink;
struct VisualNode
{
    NamedLink* FUN_0045bc00(int mode);
};
struct Controller;
struct NamedLink
{
    Controller* FUN_006a9540(int* x, int* y, int* z);
};
struct Controller
{
    void DecomposeToEulerAngles();
};
struct LocalRagdollTransform
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    void FUN_004da340(SceneInput* source);
};
// @fnv 0x004da340
void LocalRagdollTransform::FUN_004da340(SceneInput* source)
{
    VisualObject* pObject = source && source->FUN_0100() ? source->FUN_01d0() : 0;
    VisualNode* node = pObject ? pObject->IsSceneNode() : 0;
    if (node != 0)
    {
        NamedLink* link = node->FUN_0045bc00(0);
        if (link != 0)
        {
            link->FUN_006a9540(&field08, &field0c, &field10)->DecomposeToEulerAngles();
        }
    }
}

extern NiPoint3 _NiPoint3_ZERO;

struct FUN_004da230_node : public NiNode
{
    NiNode* FUN_0045bc00(unsigned int);
};

struct FUN_004da230_intermediate
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual FUN_004da230_node* GetNode();
};

struct FUN_004da230_param
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual void vfn_45();
    virtual void vfn_46();
    virtual void vfn_47();
    virtual void vfn_48();
    virtual void vfn_49();
    virtual void vfn_50();
    virtual void vfn_51();
    virtual void vfn_52();
    virtual void vfn_53();
    virtual void vfn_54();
    virtual void vfn_55();
    virtual void vfn_56();
    virtual void vfn_57();
    virtual void vfn_58();
    virtual void vfn_59();
    virtual void vfn_60();
    virtual void vfn_61();
    virtual void vfn_62();
    virtual void vfn_63();
    virtual bool IsReady();
    virtual void vfn_65();
    virtual void vfn_66();
    virtual void vfn_67();
    virtual void vfn_68();
    virtual void vfn_69();
    virtual void vfn_70();
    virtual void vfn_71();
    virtual void vfn_72();
    virtual void vfn_73();
    virtual void vfn_74();
    virtual void vfn_75();
    virtual void vfn_76();
    virtual void vfn_77();
    virtual void vfn_78();
    virtual void vfn_79();
    virtual void vfn_80();
    virtual void vfn_81();
    virtual void vfn_82();
    virtual void vfn_83();
    virtual void vfn_84();
    virtual void vfn_85();
    virtual void vfn_86();
    virtual void vfn_87();
    virtual void vfn_88();
    virtual void vfn_89();
    virtual void vfn_90();
    virtual void vfn_91();
    virtual void vfn_92();
    virtual void vfn_93();
    virtual void vfn_94();
    virtual void vfn_95();
    virtual void vfn_96();
    virtual void vfn_97();
    virtual void vfn_98();
    virtual void vfn_99();
    virtual void vfn_100();
    virtual void vfn_101();
    virtual void vfn_102();
    virtual void vfn_103();
    virtual void vfn_104();
    virtual void vfn_105();
    virtual void vfn_106();
    virtual void vfn_107();
    virtual void vfn_108();
    virtual void vfn_109();
    virtual void vfn_110();
    virtual void vfn_111();
    virtual void vfn_112();
    virtual void vfn_113();
    virtual void vfn_114();
    virtual void vfn_115();
    virtual FUN_004da230_intermediate* GetContainer();
};

struct FUN_004da230_shell
{
    unsigned int unk00;
    unsigned int unk04;
    NiPoint3 position;
    void UpdateNodeFromPosition(FUN_004da230_param* object);
};

// @fnv 0x004da230
void FUN_004da230_shell::UpdateNodeFromPosition(FUN_004da230_param* object)
{
    if (reinterpret_cast<Call_439090&>(position) == reinterpret_cast<Call_439090&>(_NiPoint3_ZERO))
    {
        FUN_004da230_intermediate* pContainer;
        FUN_004da230_node* pNode;

        pContainer = (object != 0 && object->IsReady()) ? object->GetContainer() : 0;
        pNode = (pContainer != 0) ? pContainer->GetNode() : 0;

        if (pNode != 0)
        {
            NiNode* node = pNode->FUN_0045bc00(0);
            if (node != 0)
            {
                ThreeByThreeMatrix rotation;
                rotation.FUN_00a59540(position.x, position.y, position.z);
                node->FUN_0043fa80(&rotation);
                NiUpdateData update(0.0f, false, false);
                node->UpdateWorldData(update);
            }
        }
    }
}

unsigned char CountRagDollBones(NiNode* node);
void FNV_Warning(const char* fmt, ...);

struct RagDollBoneInit : public TransformEntry
{
    RagDollBoneInit();
};

class RagDollDataInit : public RagDollData
{
  public:
    void InitFromRef(RagDollRefStandIn* apRef);
};

// Initializes ragdoll bone data from a reference's 3D node, collecting bone transforms and warning on failure.
// @fnv 0x004da010
void RagDollDataInit::InitFromRef(RagDollRefStandIn* apRef)
{
    count = 0;
    delete[] bones;
    if (apRef && apRef->Get3D())
    {
        NiAVObject* pObj = apRef->Get3D();
        NiNode* pNode = pObj ? pObj->IsSceneNode() : 0;
        count = CountRagDollBones(pNode);
        if (count)
        {
            bones = new RagDollBoneInit[count];
            unsigned int uiIndex = 0;
            if (!((RagDollWalker*)this)->CollectBoneTransforms(pNode, uiIndex, true))
                FNV_Warning("HAVOK: Failed to initialize RagDollData.");
        }
    }
}

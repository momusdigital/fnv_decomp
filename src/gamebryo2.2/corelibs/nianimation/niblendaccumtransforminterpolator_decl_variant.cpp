
// src/gamebryo2.2/corelibs/nianimation/niblendaccumtransforminterpolator_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00a393c0: the skeleton of src/gamebryo2.2/corelibs/nianimation/niblendaccumtransforminterpolator.cpp
// that unit declares it this way.

#include "niblendaccumtransforminterpolator_decls_decl_niblendaccumtransforminterpolator.h"
struct Q
{
    float w, x, y, z;
    bool FUN_00a92660(const Q&) const;
};
struct T
{
    float tx, ty, tz;
    Q rot;
    float scale;
    bool Equals(const T& o) const;
};
extern int DAT_01096784;
extern int DAT_011a8404, DAT_011a8408, DAT_011f3708, DAT_011f370c, DAT_011f3710;
void __fastcall FUN_00a36890(void*);
struct Obj
{
    void* vt;
    char base[0x2c];
    int a, b, c, d, e, f, g;
    float h;
    int i;
    char j;
};
Obj* __fastcall FUN_00a39230(Obj* o);
struct MemoryManager
{
    void Deallocate(void* p);
};
extern MemoryManager g_memoryManager;
extern int DAT_01096784;
void __fastcall DestroyInterpolatorArray(void*);
void __fastcall FUN_00a39290(void* p, int unused);
struct QT
{
    float t[3];
    float r[4];
    float s;
    QT CombineTransforms(const QT&) const;
};
struct Item
{
    int h;
    QT a;
    char rest[0x44];
};
struct Self
{
    char d0[0xe];
    unsigned char count;
    unsigned char idx;
    char d1[0x20];
    QT acc;
    Item* items;
    bool FUN_00a394b0(QT* kValue);
};
extern double _DAT_010241b0;
struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a39720_shell : public NiBlendAccumTransformInterpolator
{
    void SaveBinary(NiStream*);
};
struct FUN_00a37ec0_tgt
{
    void FUN_00a37ec0(NiStream*);
};
struct FUN_00a38b60_tgt
{
    void FUN_00a38b60(NiStream*);
};
struct FUN_00a59a90_tgt
{
    void ReadMatrixFromStream(NiStream*);
};
struct NiObject;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_00a39780_shell : public NiBlendAccumTransformInterpolator
{
    bool IsEqual(NiObject*);
};
struct STUB_6FD0
{
    bool FUN_00a36fd0(NiObject*);
};
struct STUB_91C0
{
    char Equals(void*);
};
void _fnv_CopyFilePath(char*, unsigned int, const char*, unsigned int);
char* CopyFilePath(char* dst, unsigned int a, const char* b, unsigned int c);
struct Transform395
{
    float tx, ty, tz, qw, qx, qy, qz, scale;
    Transform395();
    void TransformBy(Transform395&);
    Transform395 CombineTransforms(const Transform395&) const;
    bool IsInvalid() const
    {
        return scale == -3.4028234663852886e38 && qx == -3.4028234663852886e38 && tx == -3.4028234663852886e38;
    }
};
struct Interpolator395
{
    virtual void unk000();
    virtual void unk004();
    virtual void unk008();
    virtual void unk00c();
    virtual void unk010();
    virtual void unk014();
    virtual void unk018();
    virtual void unk01c();
    virtual void unk020();
    virtual void unk024();
    virtual void unk028();
    virtual void unk02c();
    virtual void unk030();
    virtual void unk034();
    virtual void unk038();
    virtual void unk03c();
    virtual void unk040();
    virtual void unk044();
    virtual void unk048();
    virtual void unk04c();
    virtual void unk050();
    virtual void unk054();
    virtual void unk058();
    virtual void unk05c();
    virtual void unk060();
    virtual void unk064();
    virtual void unk068();
    virtual void unk06c();
    virtual void unk070();
    virtual void unk074();
    virtual void unk078();
    virtual void unk07c();
    virtual void unk080();
    virtual void unk084();
    virtual void unk088();
    virtual void Update(float, void*, Transform395&);
    virtual void unk090();
    virtual void unk094();
    virtual void unk098();
    virtual void unk09c();
    virtual void unk0a0();
    virtual void unk0a4();
    virtual void unk0a8();
    virtual void unk0ac();
    virtual void unk0b0();
    virtual void unk0b4();
    virtual void unk0b8();
    virtual void unk0bc();
    virtual void Range(float&, float&);
};
struct Entry395
{
    Interpolator395* object;
    int unk04, unk08, unk0c, unk10, unk14;
};
struct Item395
{
    float time;
    Transform395 value, accum;
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct Target395
{
    int unk00, unk04, unk08;
    unsigned char flags, size, count, index;
    int unk10;
    Entry395* entries;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    Transform395 accumulated;
    Item395* items;
    void UpdateInterpolator(float, void*);
};

extern const AccumRotationMatrix DAT_011a9448;
struct FUN_00a393c0_cls : NiBlendAccumTransformInterpolator
{
    void FUN_00a36a90(unsigned char);
    void RemoveInterpInfo(unsigned char idx);
};
// @fnv 0x00a393c0
void FUN_00a393c0_cls::RemoveInterpInfo(unsigned char idx)
{
    if (m_ucInterpCount == 1 && idx == m_ucSingleIdx && !m_kAccumulatedTransform.IsMarkedInvalid())
    {
        NiQuatTransform* value = &m_pAccumulationData[m_ucSingleIdx].value;
        if (!value->IsInvalid())
            m_kAccumulatedTransform = m_kAccumulatedTransform.CombineTransforms(*value);
    }
    bool active = m_pInterpArray[idx].interpolator != 0;
    FUN_00a36a90(idx);
    if (m_ucInterpCount == 1 && active)
    {
        AccumItem* item = &m_pAccumulationData[m_ucSingleIdx];
        m_bHasAccumulation = true;
        item->time = -3.4028234663852886e38f;
        item->value.m_kTranslate.x = -3.4028234663852886e38f;
        item->value.m_kRotate.x = -3.4028234663852886e38f;
        item->value.m_fScale = -3.4028234663852886e38f;
        item->accum.m_kTranslate.x = -3.4028234663852886e38f;
        item->accum.m_kRotate.x = -3.4028234663852886e38f;
        item->accum.m_fScale = -3.4028234663852886e38f;
        item->rotation = DAT_011a9448;
    }
}

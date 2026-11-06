
#include "niblendaccumtransforminterpolator_decls.h"
// @fnv 0x00a397b0
bool NiBlendAccumTransformInterpolator::UpdateAccumulatedTransform(float time, NiObjectNET* target,
                                                                   NiQuatTransform& result)
{
    if (m_uiObjectFlags & 1)
        time = m_fSingleInterpolatorTime;
    if (time == DAT_0109696c)
        return false;
    UpdateAccumulation(time, target);
    if (m_bHasAccumulation || m_kAccumulatedTransform.IsMarkedInvalid())
    {
        NiQuatTransform inverse;
        inverse.m_kTranslate = DAT_011a8400;
        inverse.m_kRotate = DAT_011f3704;
        inverse.m_fScale = DAT_01096b8c;
        m_pAccumulationData[m_ucSingleIdx].value.TransformBy(inverse);
        if (m_kAccumulatedTransform.IsMarkedInvalid())
            m_kAccumulatedTransform = inverse;
        else
            m_kAccumulatedTransform = m_kAccumulatedTransform.CombineTransforms(inverse);
        m_bHasAccumulation = false;
    }
    if (m_kAccumulatedTransform.IsMarkedInvalid())
        return false;
    result = m_kAccumulatedTransform.CombineTransforms(m_pAccumulationData[m_ucSingleIdx].value);
    return true;
}

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
// @fnv 0x00a391c0
bool T::Equals(const T& aOther) const
{
    return tx == aOther.tx && ty == aOther.ty && tz == aOther.tz && rot.FUN_00a92660(aOther.rot) &&
           scale == aOther.scale;
}

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
// Calls FUN_00a36890, sets the vtable pointer and initialises fields a-j from global data and constants, then returns o.
// @fnv 0x00a39230
Obj* __fastcall FUN_00a39230(Obj* pObj)
{
    FUN_00a36890(pObj);
    pObj->vt = &DAT_01096784;
    pObj->a = *(int*)&DAT_011a8400;
    pObj->b = DAT_011a8404;
    pObj->c = DAT_011a8408;
    pObj->d = *(int*)&DAT_011f3704;
    pObj->e = DAT_011f3708;
    pObj->f = DAT_011f370c;
    pObj->g = DAT_011f3710;
    pObj->h = DAT_01096b8c;
    pObj->i = 0;
    pObj->j = 0;
    return pObj;
}

struct MemoryManager
{
    void Deallocate(void* p);
};
extern MemoryManager g_memoryManager;
extern int DAT_01096784;
void __fastcall DestroyInterpolatorArray(void*);
// @fnv 0x00a39290
void __fastcall FUN_00a39290(void* apObject, int unused)
{
    ((void**)apObject)[0] = &DAT_01096784;
    g_memoryManager.Deallocate(((void**)apObject)[0x14]);
    DestroyInterpolatorArray(apObject);
}

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
// @fnv 0x00a394b0
bool Self::FUN_00a394b0(QT* kValue)
{
    const QT* pAcc = &acc;
    if (pAcc->s == _DAT_010241b0 && pAcc->r[1] == _DAT_010241b0 && pAcc->t[0] == _DAT_010241b0)
        return false;
    if (count == 1)
    {
        *kValue = acc.CombineTransforms(items[idx].a);
        return true;
    }
    *kValue = *pAcc;
    return true;
}

namespace fnv_00a39700 {
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

struct Obj
{
    void* __thiscall FUN_00a39230();
};

// @fnv 0x00a39700
void* __cdecl FUN_00a39700()
{
    void* p = BSFadeNode::operator new(0x58);
    if (p)
    {
        Obj* o = (Obj*)p;
        return o->FUN_00a39230();
    }
    return 0;
}
}  // namespace fnv_00a39700

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

// @fnv 0x00a39720
void FUN_00a39720_shell::SaveBinary(NiStream* kStream)
{
    ((FUN_00a37ec0_tgt*)this)->FUN_00a37ec0(kStream);
    unsigned char uc;
    for (uc = 0; uc < *((unsigned char*)this + 0xd); uc++)
    {
        char* p = *(char**)((char*)this + 0x50) + uc * 0x68;
        ((FUN_00a38b60_tgt*)(p + 4))->FUN_00a38b60(kStream);
        ((FUN_00a38b60_tgt*)(p + 0x24))->FUN_00a38b60(kStream);
        ((FUN_00a59a90_tgt*)(p + 0x44))->ReadMatrixFromStream(kStream);
    }
    ((FUN_00a38b60_tgt*)((char*)this + 0x30))->FUN_00a38b60(kStream);
}

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

// @fnv 0x00a39780
bool FUN_00a39780_shell::IsEqual(NiObject* pkObject)
{
    if (!((STUB_6FD0*)this)->FUN_00a36fd0(pkObject))
        return false;
    return ((STUB_91C0*)((char*)this + 0x30))->Equals((char*)pkObject + 0x30);
}

namespace fnv_00a39ec0 {
struct MemoryManager
{
    void* Allocate(unsigned int);
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct Item
{
    char d[0x68];
    Item() throw();
    static void* operator new[](unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
};
struct Base
{
    char d[0xd];
    unsigned char count;
    char e[2];
    bool FUN_00a37690();
};
struct Self : Base
{
    char pad[0x40];
    Item* items;
    bool ResizeItems();
};
// Calls FUN_00a37690; if it succeeds, allocates a new Item array of size count, copies the old items over, frees the old array and stores the new one.
// @fnv 0x00a39ec0
bool Self::ResizeItems()
{
    unsigned char ucOldCount = count;
    bool bResized = FUN_00a37690();
    if (bResized)
    {
        Item* pkNewAccumArray = new Item[count];
        for (unsigned char uc = 0; uc < ucOldCount; uc++)
            pkNewAccumArray[uc] = items[uc];
        g_memoryManager.Deallocate(items);
        items = pkNewAccumArray;
    }
    return bResized;
}
}  // namespace fnv_00a39ec0

namespace fnv_00a3a450 {
struct MemoryManager
{
    void* Allocate(unsigned int);
};
extern MemoryManager g_memoryManager;
struct QT
{
    char d[0x20];
};
struct Item
{
    char d[0x68];
    Item() throw();
    static void* operator new[](unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
};
struct Base
{
    char d[0xd];
    unsigned char count;
    char e[2];
    void FUN_00a37510(void*, void*);
};
struct Self : Base
{
    char pad[0x20];
    QT acc;
    Item* items;
    void FUN_00a3a450(Self* dest, void* arg);
};
// Calls FUN_00a37510, allocates a new Item array of count elements, copies items into dest, and copies acc.
// @fnv 0x00a3a450
void Self::FUN_00a3a450(Self* dest, void* arg)
{
    FUN_00a37510(dest, arg);
    dest->items = new Item[count];
    for (unsigned char i = 0; i < count; i++)
        dest->items[i] = items[i];
    dest->acc = acc;
}
}  // namespace fnv_00a3a450

namespace fnv_00a3a4f0 {
struct NiStream;
struct MemoryManager
{
    void* Allocate(unsigned int);
};
extern MemoryManager g_memoryManager;
struct QT
{
    char d[0x20];
    void LoadBinary(NiStream&);
};
struct ThreeByThreeMatrix
{
    char d[0x24];
    void LoadBinary(NiStream&);
};
struct Item
{
    char h[4];
    QT a;
    QT b;
    ThreeByThreeMatrix m;
    Item() throw();
    static void* operator new[](unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
};
struct NiBlendInterpolator
{
    virtual void LoadBinary(NiStream&);
    char d[0x9];
    unsigned char count;
    char e[2];
};
struct FUN_00a3a4f0 : NiBlendInterpolator
{
    char pad[0x20];
    QT acc;
    Item* items;
    virtual void LoadBinary(NiStream& s);
};
// Calls the base LoadBinary, allocates an Item array sized by count, loads each item's a, b and m, then loads acc.
// @fnv 0x00a3a4f0
void FUN_00a3a4f0::LoadBinary(NiStream& s)
{
    NiBlendInterpolator::LoadBinary(s);
    items = new Item[count];
    for (unsigned char i = 0; i < count; i++)
    {
        Item* p = &items[i];
        p->a.LoadBinary(s);
        p->b.LoadBinary(s);
        p->m.LoadBinary(s);
    }
    acc.LoadBinary(s);
}
}  // namespace fnv_00a3a4f0

namespace fnv_00a3a580 {
struct NiObjectNET;
struct NiQuatTransform;
extern float DAT_0109696c;
struct Item
{
    void* interp;
    int a;
    float weight;
    int b;
    int c;
    float time;
};
struct Self
{
    void* vt;
    int pad4;
    float lastTime;
    unsigned char flags, count, interpCount, x;
    int y;
    Item* items;
    int z[8];
    void NormalizeWeights();
    bool UpdateAccumulatedTransform(float, NiObjectNET*, NiQuatTransform&);
    void FUN_00a39f60(unsigned char, float, NiObjectNET*);
    bool FUN_00a39960(float, NiObjectNET*, NiQuatTransform&);
    bool UpdateInterpolators(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue);
};
// @fnv 0x00a3a580
bool Self::UpdateInterpolators(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue)
{
    bool bResult = false;
    unsigned char uc;
    float fUpdateTime;
    if (interpCount == 1)
    {
        bResult = UpdateAccumulatedTransform(fTime, pkInterpTarget, kValue);
    }
    else if (interpCount > 0)
    {
        NormalizeWeights();
        for (uc = 0; uc < count; uc++)
        {
            fUpdateTime = fTime;
            Item* pItem = &items[uc];
            if (pItem->interp && pItem->weight != 0.0f)
            {
                if (flags & 1)
                    fUpdateTime = pItem->time;
                if (fUpdateTime != DAT_0109696c)
                    FUN_00a39f60(uc, fUpdateTime, pkInterpTarget);
            }
        }
        bResult = FUN_00a39960(fTime, pkInterpTarget, kValue);
    }
    lastTime = fTime;
    return bResult;
}
}  // namespace fnv_00a3a580

namespace fnv_00a3a660 {
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct FUN_00a39230 : BSFadeNode
{
    FUN_00a39230() throw();
    int members[22];
};
struct Holder
{
    void FUN_00a3a450(FUN_00a39230*, void*);
};
// Allocates a FUN_00a39230, passes it with p to Holder::FUN_00a3a450, and returns the new object.
// @fnv 0x00a3a660
FUN_00a39230* __fastcall CreateClone(Holder* self, int unused, void* p)
{
    FUN_00a39230* o = new FUN_00a39230;
    self->FUN_00a3a450(o, p);
    return o;
}
}  // namespace fnv_00a3a660

namespace fnv_00a3a6b0 {
struct Arr
{
    void* vt;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct Sub
{
    void FUN_00a38cb0(Arr*);
};
struct Base
{
    void FUN_00a38080(Arr*);
};
struct Self : Base
{
    char pad[0x30];
    Sub sub;
};
extern int g_011f371c;
char* FUN_00a7d330(int);
// Calls FUN_00a38080, appends the string from FUN_00a7d330(g_011f371c) to strs (growing if full), then calls sub.FUN_00a38cb0.
// @fnv 0x00a3a6b0
void __fastcall GetViewerStrings(Self* self, int unused, Arr* strs)
{
    self->FUN_00a38080(strs);
    char* s = FUN_00a7d330(g_011f371c);
    unsigned int n = strs->m_usSize;
    if (n >= strs->m_usMaxSize)
        strs->SetSize(n + strs->m_usGrowBy);
    strs->SetAt(n, s);
    self->sub.FUN_00a38cb0(strs);
}
}  // namespace fnv_00a3a6b0

void _fnv_CopyFilePath(char*, unsigned int, const char*, unsigned int);
// Copies a file path from the source buffer into the destination buffer using the given sizes and returns the destination pointer.
// @fnv 0x00a574b0
char* CopyFilePath(char* pcDestination, unsigned int uiDestinationSize, const char* pcSource, unsigned int uiSourceSize)
{
    _fnv_CopyFilePath(pcDestination, uiDestinationSize, pcSource, uiSourceSize);
    return pcDestination;
}

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
// Updates the interpolator at the current index with the given time and object, accumulating a cycle transform when time moves backwards.
// @fnv 0x00a39530
void Target395::UpdateInterpolator(float time, void* object)
{
    Interpolator395* interp = entries[index].object;
    Item395& item = items[index];
    if (item.time != time)
    {
        if (item.time > time)
        {
            Transform395& cycle = item.accum;
            if (cycle.IsInvalid())
            {
                float begin, end;
                interp->Range(begin, end);
                Transform395 first;
                interp->Update(begin, object, first);
                Transform395 last;
                interp->Update(end, object, last);
                Transform395 inverse;
                first.TransformBy(inverse);
                cycle = last.CombineTransforms(inverse);
            }
            if (!accumulated.IsInvalid())
                accumulated = accumulated.CombineTransforms(cycle);
        }
        interp->Update(time, object, item.value);
    }
    item.time = time;
}

#include <string.h>
class NiInterpolator;
extern unsigned char DAT_01096968;
extern float g_011a9448[9];

extern const float DAT_01015f5c;
__forceinline void InvalidateAccumulatedValue(AccumItem& item)
{
    item.accum.m_fScale = item.accum.m_kRotate.x = item.accum.m_kTranslate.x = item.value.m_fScale =
        item.value.m_kRotate.x = item.value.m_kTranslate.x = item.time = -3.4028234663852886e38f;
    memcpy(item.rotation, g_011a9448, sizeof(item.rotation));
}

struct AccumulationQuery : NiBlendAccumTransformInterpolator
{
    unsigned char FUN_00a36970(NiInterpolator*, float, unsigned char, float);
    unsigned char AddInterpInfo(NiInterpolator*, float, unsigned char, float);
};

// Invalidates the selected slot and, with two interpolators, may combine and invalidate the old slot.
// @fnv 0x00a392b0
unsigned char AccumulationQuery::AddInterpInfo(NiInterpolator* interpolator, float weight, unsigned char priority,
                                              float ease)
{
    unsigned char oldIndex = m_ucSingleIdx;
    unsigned char newIndex = FUN_00a36970(interpolator, weight, priority, ease);
    if (newIndex != DAT_01096968)
    {
        InvalidateAccumulatedValue(m_pAccumulationData[newIndex]);
        if (m_ucInterpCount == 1)
        {
            m_bHasAccumulation = true;
        }
        else if (m_ucInterpCount == 2)
        {
            if (!m_kAccumulatedTransform.IsMarkedInvalid() && !m_pAccumulationData[oldIndex].value.IsMarkedInvalid())
            {
                m_kAccumulatedTransform =
                    m_kAccumulatedTransform.CombineTransforms(m_pAccumulationData[oldIndex].value);
            }
            InvalidateAccumulatedValue(m_pAccumulationData[oldIndex]);
        }
    }
    return newIndex;
}

struct MatrixAccum;
struct QQuatOps
{
    float w, x, y, z;
    QQuatOps FUN_00a2bcf0(const QQuatOps&) const;
    void ToRotation(MatrixAccum*);
};
extern QQuatOps DAT_011a9ea4;
extern NiPoint3 DAT_011f426c;
QQuatOps* __cdecl FUN_00a6dc00(QQuatOps*, const QQuatOps&);
struct MatrixAccum
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    NiPoint3 FUN_004b4500(const NiPoint3*);
};
struct QXform
{
    NiPoint3 translate;
    QQuatOps rotate;
    float scale;
    bool FUN_00a39180() const;
    void InvertTransform(QXform&);
    QXform FUN_00a38a00(const QXform&) const;
    void SetTR()
    {
        translate = DAT_011f426c;
        rotate = DAT_011a9ea4;
    }
};
void __fastcall FUN_00494260(QXform*);
struct AccumInterpolator
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual bool Update(float, NiObjectNET*, QXform&);
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void Range(float&, float&);
};
struct AccumEntry
{
    AccumInterpolator* object;
    float weight, normalizedWeight;
    int priority;
    float ease, updateTime;
};
struct AccumState
{
    float time;
    QXform value, delta;
    MatrixAccum rotation;
};
struct AccumTarget
{
    int unk00, unk04, unk08;
    unsigned char flags, arraySize, count, singleIndex;
    float threshold;
    AccumEntry* entries;
    float highWeight, secondWeight, highSum, nextSum, highEase, singleTime;
    QXform accumulated;
    AccumState* states;
    bool reset;
    void FUN_00a39f60(unsigned char, float, NiObjectNET*);
};
// Updates the indexed state from the interpolator at time, computing transform deltas and rotation data when needed.
// @fnv 0x00a39f60
void AccumTarget::FUN_00a39f60(unsigned char index, float time, NiObjectNET* target)
{
    AccumInterpolator* interpolator = entries[index].object;
    AccumState* state = states + index;
    if (!interpolator || state->time == time)
    {
        state->delta.SetTR();
        state->delta.scale = 1.0f;
        state->time = time;
        return;
    }
    if (reset || state->value.FUN_00a39180())
    {
        interpolator->Update(time, target, state->value);
        QQuatOps firstRotation = DAT_011a9ea4;
        if (accumulated.rotate.x != -3.4028234663852886e38)
            firstRotation = accumulated.rotate;
        QQuatOps secondRotation = DAT_011a9ea4;
        if (state->value.rotate.x != -3.4028234663852886e38)
        {
            QQuatOps result;
            QQuatOps* __restrict source = FUN_00a6dc00(&result, state->value.rotate);
            secondRotation = *source;
        }
        QQuatOps productRotation = firstRotation.FUN_00a2bcf0(secondRotation);
        productRotation.ToRotation(&state->rotation);
    }
    if (time < state->time && !reset)
    {
        float begin, end;
        interpolator->Range(begin, end);
        QXform last;
        FUN_00494260(&last);
        interpolator->Update(end, target, last);
        QXform first;
        FUN_00494260(&first);
        interpolator->Update(begin, target, first);
        QXform current;
        FUN_00494260(&current);
        interpolator->Update(time, target, current);
        QXform inverse;
        FUN_00494260(&inverse);
        state->value.InvertTransform(inverse);
        state->delta = inverse.FUN_00a38a00(last);
        if (state->delta.translate.x != -3.4028234663852886e38)
            state->delta.translate = state->rotation.FUN_004b4500(&state->delta.translate);
        {
            QQuatOps secondRotation = DAT_011a9ea4;
            if (accumulated.rotate.x != -3.4028234663852886e38)
                secondRotation = accumulated.rotate;
            QQuatOps firstRotation = DAT_011a9ea4;
            if (first.rotate.x != -3.4028234663852886e38)
            {
                QQuatOps result;
                QQuatOps* __restrict source = FUN_00a6dc00(&result, first.rotate);
                firstRotation = *source;
            }
            QQuatOps productRotation = secondRotation.FUN_00a2bcf0(firstRotation);
            productRotation.ToRotation(&state->rotation);
        }
        first.InvertTransform(inverse);
        state->value = inverse.FUN_00a38a00(current);
        if (state->value.translate.x != -3.4028234663852886e38)
            state->value.translate = state->rotation.FUN_004b4500(&state->value.translate);
        state->delta = state->delta.FUN_00a38a00(state->value);
        state->value = current;
    }
    else
    {
        QXform current;
        FUN_00494260(&current);
        interpolator->Update(time, target, current);
        QXform inverse;
        FUN_00494260(&inverse);
        state->value.InvertTransform(inverse);
        state->delta = inverse.FUN_00a38a00(current);
        if (state->delta.translate.x != -3.4028234663852886e38)
            state->delta.translate = state->rotation.FUN_004b4500(&state->delta.translate);
        state->value = current;
    }
    reset = false;
    state->time = time;
}

#include <math.h>
struct Inner_00a6db50
{
    float w, x, y, z;
    void Set(float w, float x, float y, float z);
    Inner_00a6db50 Negate() const;
    Inner_00a6db50 FUN_00a39120(float factor) const;
    Inner_00a6db50& operator+=(const Inner_00a6db50& other)
    {
        w = other.w + w;
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }
};
struct PositionOps
{
    float x, y, z;
    PositionOps operator*(float f) const
    {
        PositionOps result;
        result.x = x * f;
        result.y = y * f;
        result.z = z * f;
        return result;
    }
    PositionOps& operator+=(const PositionOps& other)
    {
        x = x + other.x;
        y = y + other.y;
        z = z + other.z;
        return *this;
    }
};
extern NiPoint3 DAT_011f426c;
struct InterpItem
{
    void* m_pkInterpolator;
    float m_fNormalizedWeight;
    float m_fWeight;
    float m_fLastEvaluationTime;
    float m_fEaseSpinner;
    int m_iValueAt14;
};
struct BlendAccumState
{
    int unk00, unk04, unk08;
    unsigned char m_uiObjectFlags, m_ucArraySize, m_ucInterpCount, m_ucSingleIdx;
    int unk10;
    InterpItem* m_pInterpArray;
    int unk18, unk1c;
    float m_fSingleInterpolatorTime;
    int unk24, unk28, unk2c;
    NiQuatTransform m_kAccumulatedTransform;
    AccumItem* m_pAccumulationData;
    bool m_bHasAccumulation;
    bool FUN_00a39960(float time, void* target, NiQuatTransform& output);
};
// Combines available accumulated transform components, copies the result to output, and returns false if none are available or the result is invalid.
// @fnv 0x00a39960
bool BlendAccumState::FUN_00a39960(float time, void* target, NiQuatTransform& output)
{
    float positionWeight = 1.0f;
    float current = 1.0f;
    Inner_00a6db50 firstRotation;
    PositionOps kAccumulatedPosition = *reinterpret_cast<const PositionOps*>(&DAT_011f426c);
    firstRotation.Set(0.0f, 0.0f, 0.0f, 0.0f);
    bool rot = false;
    bool hasRotation = false;
    float z = 0.0f;
    bool item = false;
    bool j = m_kAccumulatedTransform.IsMarkedInvalid();
    if (j)
    {
        m_kAccumulatedTransform.m_kTranslate = DAT_011f426c;
        NiQuaternion& positionSum = m_kAccumulatedTransform.m_kRotate;
        positionSum = *reinterpret_cast<const NiQuaternion*>(&DAT_011a9ea4);
        m_kAccumulatedTransform.m_fScale = 1.0f;
    }
    bool bFirstRotation = true;
    for (unsigned char i = 0; i < m_ucArraySize; ++i)
    {
        InterpItem& kInterpItem = m_pInterpArray[i];
        AccumItem& b = m_pAccumulationData[i];
        if (!kInterpItem.m_pkInterpolator || !(kInterpItem.m_fWeight > 0.00001f))
            continue;
        NiQuatTransform kSourceTransform;
        const float& temp = kInterpItem.m_fWeight;
        if (j)
            kSourceTransform = b.value;
        else
            kSourceTransform = b.accum;
        if (kSourceTransform.m_kTranslate.x != -3.4028234663852886e38)
        {
            rot = true;
            PositionOps kWeightedPosition = *reinterpret_cast<PositionOps*>(&kSourceTransform.m_kTranslate) * temp;
            kAccumulatedPosition.x = kAccumulatedPosition.x + kWeightedPosition.x;
            kAccumulatedPosition.y += kWeightedPosition.y;
            kAccumulatedPosition.z += kWeightedPosition.z;
        }
        else
        {
            positionWeight -= temp;
        }
        if (kSourceTransform.m_kRotate.x != -3.4028234663852886e38)
        {
            Inner_00a6db50 kSourceRotation;
            kSourceRotation = *reinterpret_cast<Inner_00a6db50*>(&kSourceTransform.m_kRotate);
            if (!bFirstRotation)
            {
                double x = kSourceRotation.x * firstRotation.x;
                float r = firstRotation.w * kSourceRotation.w + x + kSourceRotation.y * firstRotation.y +
                          kSourceRotation.z * firstRotation.z;
                if (r < 0.0f)
                    kSourceRotation = kSourceRotation.Negate();
            }
            else
            {
                bFirstRotation = false;
            }
            kSourceRotation = kSourceRotation.FUN_00a39120(temp);
            firstRotation += kSourceRotation;
            hasRotation = true;
        }
        if (kSourceTransform.m_fScale != -3.4028234663852886e38)
        {
            item = true;
            z += temp * kSourceTransform.m_fScale;
        }
        else
        {
            current -= temp;
        }
    }
    if (rot || hasRotation || item)
    {
        NiQuatTransform kIter;
        kIter.m_fScale = DAT_01096b8c;
        kIter.m_kTranslate = DAT_011a8400;
        kIter.m_kRotate = DAT_011f3704;
        if (rot)
        {
            const float fInvPositionWeight = 1.0f / positionWeight;
            kAccumulatedPosition.x = fInvPositionWeight * kAccumulatedPosition.x;
            const double inv = fInvPositionWeight;
            kAccumulatedPosition.y = inv * kAccumulatedPosition.y;
            kAccumulatedPosition.z = inv * kAccumulatedPosition.z;
            kIter.m_kTranslate = *reinterpret_cast<NiPoint3*>(&kAccumulatedPosition);
        }
        if (hasRotation)
        {
            double scaleWeight = firstRotation.x;
            float fRotationLength =
                (float)sqrt((float)(firstRotation.w * firstRotation.w + scaleWeight * scaleWeight +
                                    firstRotation.y * firstRotation.y + firstRotation.z * firstRotation.z));
            const float invW = (float)(1.0f / fRotationLength);
            firstRotation.w = invW * firstRotation.w;
            const double inv = invW;
            firstRotation.x = inv * firstRotation.x;
            firstRotation.y = firstRotation.y * inv;
            firstRotation.z = firstRotation.z * inv;
            kIter.m_kRotate = *reinterpret_cast<NiQuaternion*>(&firstRotation);
        }
        if (item)
        {
            if (current > 0.00001f)
                kIter.m_fScale = (1.0f / current) * z;
        }
        *reinterpret_cast<QXform*>(&m_kAccumulatedTransform) =
            reinterpret_cast<const QXform*>(&m_kAccumulatedTransform)
                ->FUN_00a38a00(*reinterpret_cast<const QXform*>(&kIter));
        if (m_kAccumulatedTransform.IsMarkedInvalid())
            return false;
        output = m_kAccumulatedTransform;
        return true;
    }
    return false;
}

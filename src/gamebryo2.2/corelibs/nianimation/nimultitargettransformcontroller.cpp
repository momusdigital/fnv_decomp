
class NiInterpolator;
class NiAVObject;
class ThreeByThreeMatrix
{
  public:
    float m[9];
};
class NiQuaternion
{
  public:
    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    void FromRotationMatrix(const ThreeByThreeMatrix&) throw();
};
class NiPoint3
{
  public:
    float x;
    float y;
    float z;
};
class NiQuatTransform
{
  public:
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
};
class NiMemObject
{
  public:
    static void* operator new(unsigned int) throw();
};
class NiTransformInterpolator : public NiMemObject
{
  public:
    char m_data[0x48];
    NiTransformInterpolator(NiQuatTransform) throw();
};
class NiMultiTargetTransformController
{
  public:
    virtual NiInterpolator* GetInterpolatorAtIndex(unsigned short);
    char m_ucUnknownByte[0x30];
    void* m_pkBlendInterpolators;
    NiAVObject** m_ppTargetObjects;
};

struct NiMultiTargetTransformController__PoseSource
{
    unsigned char m_ucUnknownByte[0x34];
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
};

// @fnv 0x00a2ffe0
NiInterpolator* NiMultiTargetTransformController::GetInterpolatorAtIndex(unsigned short index)
{
    NiMultiTargetTransformController__PoseSource* source =
        (NiMultiTargetTransformController__PoseSource*)m_ppTargetObjects[index];
    NiQuaternion rotate;
    NiQuatTransform transform;
    rotate.FromRotationMatrix(source->m_kOrientation);
    transform.m_kTranslate = source->m_kTranslation;
    transform.m_kRotate = rotate;
    transform.m_fScale = source->m_fScale;
    return (NiInterpolator*)new NiTransformInterpolator(transform);
}

struct FUN_00a2fd40_shell : public NiMultiTargetTransformController
{
    char* GetInterpolatorID(unsigned short);
};

// @fnv 0x00a2fd40
char* FUN_00a2fd40_shell::GetInterpolatorID(unsigned short usIndex)
{
    return *((char**)m_ppTargetObjects[usIndex] + 2);
}

void __fastcall DestroyInterpolatorArray(void* pThis);
void __cdecl FUN_00aa1460(void* ptr, unsigned int size);
void __cdecl FUN_00aa1490(void* ptr, unsigned int size);

// @fnv 0x00a2ff70
void* __fastcall FUN_00a2ff70(char* pThis, int, unsigned int flags)
{
    if (flags & 2)
    {
        int count = *(int*)(pThis - 4);
        char* base = pThis - 4;
        char* cur = pThis + count * 0x30;
        while (--count >= 0)
        {
            cur -= 0x30;
            DestroyInterpolatorArray(cur);
        }
        if (flags & 1)
        {
            FUN_00aa1490(base, 0x30);
        }
        return base;
    }
    DestroyInterpolatorArray(pThis);
    if (flags & 1)
    {
        FUN_00aa1460(pThis, 0x30);
    }
    return pThis;
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a30070_shell : public NiMultiTargetTransformController
{
    void CloneTo(NiMultiTargetTransformController*, CloningProcess*);
};

class NiTransformController
{
  public:
    void FUN_00a2f8a0(NiTransformController*, CloningProcess&);
};

struct Helper1
{
    void FUN_00a2feb0(unsigned short);
};

struct Helper2
{
    char pad[0x30];
    void FUN_00a40aa0(Helper2*, CloningProcess*);
};

// @fnv 0x00a30070
void FUN_00a30070_shell::CloneTo(NiMultiTargetTransformController* pkDest, CloningProcess* kCloning)
{
    ((NiTransformController*)this)->FUN_00a2f8a0((NiTransformController*)pkDest, *kCloning);
    ((Helper1*)pkDest)->FUN_00a2feb0(*(unsigned short*)((char*)this + 0x3c));
    for (unsigned short us = 0; us < *(unsigned short*)((char*)this + 0x3c); ++us)
    {
        ((Helper2*)this->m_pkBlendInterpolators)[us].FUN_00a40aa0(&((Helper2*)pkDest->m_pkBlendInterpolators)[us],
                                                                  kCloning);
    }
}

namespace fnv_00a300d0 {
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a300d0_shell : public NiMultiTargetTransformController
{
    void FUN_00a300d0(CloningProcess*);
};

class ShaderBufferRecord;

template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char*, T&);
};

class NiTimeController
{
  public:
    virtual void ProcessClone(CloningProcess&);
};

struct NiBlendTransformInterpolator_Stub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void ProcessClone(CloningProcess&);
    char m_auiShapeKeys[0x2C];
};

// Calls the base ProcessClone, then clones each target transform interpolator and remaps its target object through the cloning process's pointer map.
// @fnv 0x00a300d0
void FUN_00a300d0_shell::FUN_00a300d0(CloningProcess* kCloning)
{
    ((NiTimeController*)this)->NiTimeController::ProcessClone(*kCloning);

    ShaderBufferRecord* pkClone = 0;
    ((NiTStringPointerMap<ShaderBufferRecord*>*)kCloning->m_pCloneMap)->GetAt((const char*)this, pkClone);
    NiMultiTargetTransformController* pkDest = (NiMultiTargetTransformController*)pkClone;

    unsigned short m_usPassCountLocal = *(unsigned short*)((char*)this + 0x3C);
    for (unsigned short us = 0; us < m_usPassCountLocal; us++)
    {
        ((NiBlendTransformInterpolator_Stub*)m_pkBlendInterpolators)[us].ProcessClone(*kCloning);
        if (m_ppTargetObjects[us] != 0)
        {
            bool bFound = ((NiTStringPointerMap<ShaderBufferRecord*>*)kCloning->m_pCloneMap)
                              ->GetAt((const char*)m_ppTargetObjects[us], pkClone);
            pkDest->m_ppTargetObjects[us] = bFound ? (NiAVObject*)pkClone : 0;
        }
        m_usPassCountLocal = *(unsigned short*)((char*)this + 0x3C);
    }
}
}  // namespace fnv_00a300d0

void __fastcall FUN_00a2fb70(void* pThis);

struct NiMemObject_Del : public NiMemObject
{
    static void operator delete(void*, unsigned int) throw();
};

// Calls FUN_00a2fb70 on pThis, then deletes pThis with size 0x40 when flags has bit 1 set, and returns pThis.
// @fnv 0x00a30280
void* __fastcall FUN_00a30280(void* pThis, int, unsigned int flags)
{
    FUN_00a2fb70(pThis);
    if (flags & 1)
    {
        NiMemObject_Del::operator delete(pThis, 0x40);
    }
    return pThis;
}

struct Blend34
{
    char pad[0x34];
    char* p;
};
// @fnv 0x00a2fa30
char* __fastcall FUN_00a2fa30(Blend34* self, int, unsigned short ausIndex)
{
    return self->p + ausIndex * 0x30;
}

namespace fnv_00a2fa50 {
struct Blend34
{
    char pad[0x34];
    char* p;
};
// @fnv 0x00a2fa50
char* __fastcall CreateBlendInterpolator(Blend34* self, int, unsigned short ausIndex, bool a, bool b, float c, unsigned char d)
{
    return self->p + ausIndex * 0x30;
}
}  // namespace fnv_00a2fa50

struct Blend
{
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void SetActiveTimeRange(float, float);
    char pad[0x2c];
};
struct Ctl
{
    char pad[0x34];
    Blend* blends;
    char pad2[4];
    unsigned short num;
};
// @fnv 0x00a2fa70
void __fastcall GuaranteeTimeRange(Ctl* self, int, float afValueA, float afValueB)
{
    for (unsigned short us = 0; us < self->num; us++)
        self->blends[us].SetActiveTimeRange(afValueA, afValueB);
}

extern int DAT_011f36bc;
// @fnv 0x00a2fbd0
int* __cdecl FUN_00a2fbd0()
{
    return &DAT_011f36bc;
}

namespace fnv_00a30240 {
struct NiFixedString
{
    const char* s;
};
struct NiInterpController
{
    static const unsigned short INVALID_INDEX;
};
struct Interp
{
    char pad[8];
    const char* name;
};
struct Ctl
{
    char pad[0x38];
    Interp** targets;
    unsigned short num;
};
// @fnv 0x00a30240
unsigned short __fastcall FindTargetIndex(Ctl* self, int, const NiFixedString* arName)
{
    unsigned short us;
    for (us = 0; us < self->num; us++)
    {
        if (self->targets[us] && self->targets[us]->name == arName->s)
            return us;
    }
    return NiInterpController::INVALID_INDEX;
}
}  // namespace fnv_00a30240

namespace fnv_00a302a0 {
struct Rtti
{
    const char* name;
    const Rtti* base;
};
extern const Rtti g_011f4428_arg1;
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual const Rtti* GetRTTI();
};
struct Ctl
{
    char pad[0x2c];
    Obj* target;
};
// Walks the RTTI chain of self->target and returns true if it reaches g_011f4428_arg1, otherwise false.
// @fnv 0x00a302a0
bool __fastcall IsTargetOfType(Ctl* pCtl)
{
    Obj* t = pCtl->target;
    if (t)
    {
        const Rtti* r = t->GetRTTI();
        while (r)
        {
            if (r == &g_011f4428_arg1)
                return true;
            r = r->base;
        }
    }
    return false;
}
}  // namespace fnv_00a302a0

namespace fnv_00a302d0 {
struct NiObject;
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a302d0_shell : public NiMultiTargetTransformController
{
    NiObject* CreateClone(CloningProcess*);
};

struct FUN_00a30070_shell
{
    void CloneTo(NiMultiTargetTransformController*, CloningProcess*);
};
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
void* __fastcall FUN_00a2f8c0(void*) throw();
struct __declspec(novtable) CloneBase : BSFadeNode
{
    virtual void v0();
    char pad[0x30];
    CloneBase() throw()
    {
        FUN_00a2f8c0(this);
    }
};
struct CloneCtl : CloneBase
{
    void* a;
    void* b;
    unsigned short us;
    CloneCtl() throw() : a(0), b(0), us(0)
    {}
    virtual void v0();
};
// Allocates a CloneCtl, passes it with kCloning to CloneTo, and returns it as a NiObject.
// @fnv 0x00a302d0
NiObject* FUN_00a302d0_shell::CreateClone(CloningProcess* kCloning)
{
    CloneCtl* pkObject = new CloneCtl;
    reinterpret_cast<FUN_00a30070_shell*>(this)->CloneTo(reinterpret_cast<NiMultiTargetTransformController*>(pkObject),
                                                         kCloning);
    return reinterpret_cast<NiObject*>(pkObject);
}
}  // namespace fnv_00a302d0

namespace fnv_00a30330 {
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
void* __fastcall FUN_00a2f8c0(void*) throw();
struct __declspec(novtable) Base : BSFadeNode
{
    virtual void v0();
    char pad[0x30];
    Base() throw()
    {
        FUN_00a2f8c0(this);
    }
};
struct Ctl : Base
{
    void* a;
    void* b;
    unsigned short us;
    Ctl() throw() : a(0), b(0), us(0)
    {}
    virtual void v0();
};
// Allocates and constructs a new Ctl object, returning the pointer.
// @fnv 0x00a30330
Ctl* __cdecl CreateCtl()
{
    return new Ctl;
}
}  // namespace fnv_00a30330

struct BinStream
{
    void* vt;
    unsigned int pos;
    unsigned int(__cdecl* write)(BinStream*, const void*, unsigned int, void*, unsigned int);
};
struct Stream
{
    char pad[0x24c];
    BinStream* ostr;
};
// Writes 2 bytes from data through the stream's BinStream write callback and advances its position by the bytes written.
// @fnv 0x00a30370
void __cdecl FUN_00a30370(Stream* apStream, const void* data)
{
    BinStream* o = apStream->ostr;
    unsigned int(__cdecl * fn)(BinStream*, const void*, unsigned int, void*, unsigned int) = o->write;
    *reinterpret_cast<unsigned int*>(&apStream) = 2;
    o->pos += fn(o, data, 2, &apStream, 1);
}

namespace fnv_00a303a0 {
struct BinStream
{
    void* vt;
    unsigned int pos;
    void* r;
    unsigned int(__cdecl* write)(BinStream*, const void*, unsigned int, void*, unsigned int);
};
struct Stream
{
    char pad[0x250];
    BinStream* ostr;
};
// Writes 2 bytes from data through the stream's write callback and advances the stream position by the bytes written.
// @fnv 0x00a303a0
void __cdecl FUN_00a303a0(Stream* apStream, const void* data)
{
    BinStream* o = apStream->ostr;
    unsigned int(__cdecl * fn)(BinStream*, const void*, unsigned int, void*, unsigned int) = o->write;
    *reinterpret_cast<unsigned int*>(&apStream) = 2;
    o->pos += fn(o, data, 2, &apStream, 1);
}
}  // namespace fnv_00a303a0

struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct FUN_00a2fbe0_shell : public NiMultiTargetTransformController
{
    void UpdateTargets(NiUpdateData*);
};

extern "C" double __cdecl fabs(double);

struct QuatHelper_a2fbe0
{
    void ToRotationMatrix(ThreeByThreeMatrix&);
};
struct Blend_a2fbe0
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual bool Update(float, NiAVObject*, NiQuatTransform&);
    unsigned int m_uiRefCount;
    float m_fLastTime;
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    char m_cHighPriority;
    char m_cNextHighPriority;
    void* m_pInterpArray;
    NiInterpolator* m_pSingleInterpolator;
    float m_fWeightThreshold;
    float m_fSingleInterpolatorTime;
    float m_fHighSumOfWeights;
    float m_fNextHighSumOfWeights;
    float m_fTrailingValue;
};
struct Target_a2fbe0
{
    void* unk00;
    unsigned int m_uiRefCount;
    const char* m_kName;
    void* m_pControllers;
    void* m_ppExtraData;
    unsigned short m_usExtraDataCount;
    unsigned short m_usMaxSize;
    void* m_pParentNode;
    void* m_spCollisionObject;
    void* m_kWorldBound;
    void* m_pkPropertyHead;
    void* m_pkPropertyTail;
    unsigned int m_uiPropertyCount;
    unsigned int m_uiObjectFlags;
    ThreeByThreeMatrix m_kRotate;
    NiPoint3 m_kTranslate;
    float m_fScale;
    bool GetSelectiveUpdate() const
    {
        return (m_uiObjectFlags >> 1) & 1;
    }
};
struct CtlFlags_a2fbe0
{
    void* unk00;
    unsigned int m_uiRefCount;
    unsigned short m_uiObjectFlags;
    bool GetActive() const
    {
        return (m_uiObjectFlags >> 3) & 1;
    }
};
extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
extern float DAT_01096b8c;

// If active, iterates targets with selective update, blends each via Update, and applies non-sentinel translate, rotate and scale values.
// @fnv 0x00a2fbe0
void FUN_00a2fbe0_shell::UpdateTargets(NiUpdateData* UpdateData)
{
    if (((CtlFlags_a2fbe0*)this)->GetActive())
    {
        NiQuatTransform kTransform;
        kTransform.m_kTranslate = DAT_011a8400;
        kTransform.m_kRotate = DAT_011f3704;
        kTransform.m_fScale = DAT_01096b8c;
        for (int us = 0; us < *(unsigned short*)((char*)this + 0x3c); us++)
        {
            if (((Target_a2fbe0**)m_ppTargetObjects)[us] &&
                ((Target_a2fbe0**)m_ppTargetObjects)[us]->GetSelectiveUpdate())
            {
                if (((Blend_a2fbe0*)m_pkBlendInterpolators)[us].Update(
                        UpdateData->fTime, (NiAVObject*)((Target_a2fbe0**)m_ppTargetObjects)[us], kTransform))
                {
                    if (kTransform.m_kTranslate.x != -3.4028234663852886e+38)
                        ((Target_a2fbe0**)m_ppTargetObjects)[us]->m_kTranslate = kTransform.m_kTranslate;
                    if (kTransform.m_kRotate.m_fVectorY != -3.4028234663852886e+38)
                        ((QuatHelper_a2fbe0*)&kTransform.m_kRotate)
                            ->ToRotationMatrix(((Target_a2fbe0**)m_ppTargetObjects)[us]->m_kRotate);
                    if (kTransform.m_fScale != -3.4028234663852886e+38)
                        ((Target_a2fbe0**)m_ppTargetObjects)[us]->m_fScale = (float)fabs(kTransform.m_fScale);
                }
            }
        }
    }
}

struct FUN_00a2fae0_elem
{
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool V23(FUN_00a2fae0_elem*);
};

struct FUN_00a2fae0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    FUN_00a2fae0_elem** m_ppElems;
    unsigned short m_uiItemCount;
    bool Equals(FUN_00a2fae0_cls* other);
    unsigned char FUN_00c283f0(void* p);
};

// @fnv 0x00a2fae0
bool FUN_00a2fae0_cls::Equals(FUN_00a2fae0_cls* other)
{
    if (!this->FUN_00c283f0(other))
    {
        return false;
    }
    if (other->m_uiItemCount != m_uiItemCount)
    {
        return false;
    }
    for (unsigned short usIndex = 0; usIndex < m_uiItemCount; usIndex++)
    {
        if (m_ppElems[usIndex] && !other->m_ppElems[usIndex])
        {
            return false;
        }
        if (!m_ppElems[usIndex] && other->m_ppElems[usIndex])
        {
            return false;
        }
        if (m_ppElems[usIndex] && !other->m_ppElems[usIndex]->V23(m_ppElems[usIndex]))
        {
            return false;
        }
    }
    return true;
}

extern float DAT_0109643c;
extern float DAT_01015f5c;
extern double DAT_010231b0;
extern double DAT_010241b0;
struct NiBlendInterpolator
{
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void GetTimeRange(float* minTime, float* maxTime);
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
};
struct TimeFlags
{
    unsigned char m_unused : 5;
    unsigned char m_bManagerControlled : 1;
    unsigned char m_reserved : 2;
};
struct NiMultiTargetTimeShell : public NiMultiTargetTransformController
{
    unsigned short m_usNumTargets;
    bool GetManagerControlled() const
    {
        return (reinterpret_cast<const unsigned short*>(m_ucUnknownByte + 4)[0] >> 5) & 1;
    }
    float& LoKeyTime()
    {
        return *reinterpret_cast<float*>(m_ucUnknownByte + 0x10);
    }
    float& HiKeyTime()
    {
        return *reinterpret_cast<float*>(m_ucUnknownByte + 0x14);
    }
    void ResetIfFlagClear();
    void UpdateTimeRange();
};
// @fnv 0x00a2fde0
void NiMultiTargetTimeShell::UpdateTimeRange()
{
    if (!GetManagerControlled())
    {
        LoKeyTime() = DAT_0109643c;
        HiKeyTime() = DAT_01015f5c;
        for (unsigned short index = 0; index < m_usNumTargets; ++index)
        {
            float endTime = DAT_01015f5c;
            float startTime = DAT_0109643c;
            static_cast<NiBlendInterpolator*>(m_pkBlendInterpolators)[index].GetTimeRange(&startTime, &endTime);
            if (startTime < LoKeyTime())
                LoKeyTime() = startTime;
            if (endTime > HiKeyTime())
                HiKeyTime() = endTime;
        }
        if (LoKeyTime() == DAT_010231b0 && HiKeyTime() == DAT_010241b0)
            ResetIfFlagClear();
    }
}

class A30440BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A30440BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A30440BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
};

class A30440Object;

class A30440Stream
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void SaveLinkID(A30440Object* pkObject);

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
    A30440BinaryStream* m_pBackingStream;
};

template <class T>
inline void A30440BinaryStreamSave(A30440BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A30440SaveBinary(A30440Stream& kStream, const T& value)
{
    A30440BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

class A30440Controller
{
  public:
    void SaveBinary(A30440Stream& kStream);

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
};

class A30440MultiTarget : public A30440Controller
{
  public:
    A30440Object** m_ppTargetObjects;
    unsigned short m_usTargetCount;

    void FUN_00a30440(A30440Stream& kStream);
};

// SaveBinary
// Saves the base controller, the target count, then each target's link ID to the stream.
// @fnv 0x00a30440
void A30440MultiTarget::FUN_00a30440(A30440Stream& kStream)
{
    A30440Controller::SaveBinary(kStream);
    A30440SaveBinary(kStream, m_usTargetCount);
    for (unsigned short us = 0; us < m_usTargetCount; us++)
        kStream.SaveLinkID(m_ppTargetObjects[us]);
}

struct FUN_00a304b0_arr
{
    char pad00[8];
    unsigned short m_usCapacity;
    unsigned short m_usElementCount;
    unsigned short m_usPad0c;
    unsigned short m_usGrow;

    void FUN_0096ad30(unsigned int ItemUpdateArray);
    void FUN_0096ae90(unsigned int uiIndex, void** ppItem);
};

struct FUN_00a304b0_cls
{
    char pad00[0x3c];
    unsigned short m_usNumInterps;

    void WriteManagerControlledFlag(FUN_00a304b0_arr* pArr);
    void GetViewerStrings(FUN_00a304b0_arr* pArr);
};

void* __cdecl FUN_00a7d330(int);
void* __cdecl FUN_00a7d490(const char*, unsigned short);
extern int DAT_011f36bc;

// @fnv 0x00a304b0
void FUN_00a304b0_cls::GetViewerStrings(FUN_00a304b0_arr* pArr)
{
    WriteManagerControlledFlag(pArr);
    void* pItem = FUN_00a7d330(DAT_011f36bc);
    unsigned int usIndex = pArr->m_usElementCount;
    if (usIndex >= pArr->m_usCapacity)
    {
        pArr->FUN_0096ad30(usIndex + pArr->m_usGrow);
    }
    pArr->FUN_0096ae90(usIndex, &pItem);

    pItem = FUN_00a7d490("m_usNumInterps", m_usNumInterps);
    usIndex = pArr->m_usElementCount;
    if (usIndex >= pArr->m_usCapacity)
    {
        pArr->FUN_0096ad30(usIndex + pArr->m_usGrow);
    }
    pArr->FUN_0096ae90(usIndex, &pItem);
}

extern "C" int __cdecl strcmp(const char* pcA, const char* pcB);

struct BA2FD60Item
{
    int unk00;
    int unk04;
    const char* m_pcName;
};

class BA2FD60Controller
{
  public:
    unsigned short FindItemIndexByName(const char* pcName) const;

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
    BA2FD60Item** m_ppGeometries;
    unsigned short m_usElementCount;

    static const unsigned short INVALID_INDEX;
};

// Returns the index of the first item whose m_pcName matches pcName, or INVALID_INDEX if pcName is null or no match is found.
// @fnv 0x00a2fd60
unsigned short BA2FD60Controller::FindItemIndexByName(const char* pcName) const
{
    if (!pcName)
        return INVALID_INDEX;
    for (unsigned short us = 0; us < m_usElementCount; us++)
    {
        if (m_ppGeometries[us] && strcmp(m_ppGeometries[us]->m_pcName, pcName) == 0)
            return us;
    }
    return INVALID_INDEX;
}

struct NiMultiTargetTransformControllerStandIn : public NiMultiTargetTransformController
{
    unsigned short __thiscall GetInterpolatorCount();
};

// @fnv 0x00a2fa20
unsigned short __thiscall NiMultiTargetTransformControllerStandIn::GetInterpolatorCount()
{
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<unsigned char*>(this) + 0x3C);
}

class NiBinaryStream
{
  public:
    typedef unsigned int(__cdecl* ReadFunc)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                            unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    virtual ~NiBinaryStream();
    unsigned int m_uiStreamFlags;
    ReadFunc m_pfnRead;
    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};
class NiStream
{
  public:
    int unk000;
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
    NiBinaryStream* m_pUnderlyingStream;
    NiAVObject* FUN_00a64620();
};
template <class T> inline void NiBinaryStreamLoad(NiBinaryStream* pkStream, T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiComponentSize = sizeof(T);
    pkStream->BinaryRead(pValue, uiNumEls * uiComponentSize, &uiComponentSize, 1);
}
inline void ReadBinaryValue(NiStream& kStream, unsigned short& usValue)
{
    NiBinaryStreamLoad(kStream.m_pUnderlyingStream, &usValue, 1);
}
class NiMultiTargetTransformControllerA30 : public NiMultiTargetTransformController
{
  public:
    unsigned short m_usNumInterps;
    void FUN_00a2f910(NiStream& kStream);
    void FUN_00a2feb0(unsigned short ausNumInterps);
    void LoadBinary(NiStream& kStream);
};
// Calls FUN_00a2f910, reads m_usNumInterps, passes it to FUN_00a2feb0, then assigns returned pointers to m_ppTargetObjects.
// @fnv 0x00a303d0
void NiMultiTargetTransformControllerA30::LoadBinary(NiStream& kStream)
{
    FUN_00a2f910(kStream);
    ReadBinaryValue(kStream, m_usNumInterps);
    FUN_00a2feb0(m_usNumInterps);
    for (unsigned short us = 0; us < m_usNumInterps; us++)
        m_ppTargetObjects[us] = kStream.FUN_00a64620();
}

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
void NiFree(void*);
inline void operator delete(void* p)
{
    g_memoryManager.Deallocate(p);
}
struct ControllerBlendCleanup
{
    virtual ~ControllerBlendCleanup() throw();
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
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
    static void operator delete[](void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct NiRefBase_a2fb70
{
    virtual ~NiRefBase_a2fb70() throw();
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
};
struct FUN_00a2fb70 : NiRefBase_a2fb70
{
    ControllerBlendCleanup* blends;
    void** targets;
    virtual ~FUN_00a2fb70() throw();
};
// Destroys the blends array and frees the targets pointer.
// @fnv 0x00a2fb70
FUN_00a2fb70::~FUN_00a2fb70() throw()
{
    delete[] blends;
    NiFree(targets);
}

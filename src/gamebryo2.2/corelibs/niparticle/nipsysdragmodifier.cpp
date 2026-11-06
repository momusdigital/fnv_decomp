// gamebryo2.2/corelibs/niparticle/nipsysdragmodifier.cpp: NiPSysDragModifier, NiPSysDragShell (7 functions)

#include "nipsysdragmodifier_decls.h"

// @fnv 0x00C2C450
void NiPSysDragModifier::LoadBinary(NiStream& kStream)
{
    NiPSysModifier::LoadBinary(kStream);
    kStream.ResetStreamState();
    reinterpret_cast<NiColor*>(&m_kDragDirection)->LoadBinary(kStream);
    ReadBinaryValue(kStream, m_fDragStrength);
    ReadBinaryValue(kStream, m_fFirstLightParameter);
    ReadBinaryValue(kStream, m_fSecondLightParameter);
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

void* __fastcall FUN_00c2c030(void*);

// @fnv 0x00c2c080
void* __cdecl FUN_00c2c080()
{
    void* p = BSFadeNode::operator new(0x34);
    if (p)
        return FUN_00c2c030(p);
    return 0;
}

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_01202768;
// @fnv 0x00c2c0a0
void* __cdecl FUN_00c2c0a0()
{
    return &g_01202768;
}

namespace fnv_00c2c0b0 {
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
struct FUN_00c2c0b0_shell : public NiPSysDragModifier
{
    NiObject* CloneDragModifier(CloningProcess*);
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct DragCtorStub
{
    DragCtorStub* FUN_00c2c030();
};
struct CopyStub
{
    void CopyMemberData(NiPSysModifier*, CloningProcess&);
};
struct DragData
{
    char pad[0x1c];
    int a;
    int b;
    int c;
    float d;
    float e;
    float f;
};
// @fnv 0x00c2c0b0
NiObject* FUN_00c2c0b0_shell::CloneDragModifier(CloningProcess* kCloning)
{
    DragCtorStub* pAlloc = (DragCtorStub*)BSFadeNode::operator new(0x34);
    DragData* pkObject = pAlloc ? (DragData*)pAlloc->FUN_00c2c030() : 0;
    ((CopyStub*)this)->CopyMemberData((NiPSysModifier*)pkObject, *kCloning);
    DragData* pSource = (DragData*)this;
    pkObject->a = pSource->a;
    pkObject->b = pSource->b;
    pkObject->c = pSource->c;
    pkObject->d = pSource->d;
    pkObject->e = pSource->e;
    pkObject->f = pSource->f;
    return (NiObject*)pkObject;
}
}  // namespace fnv_00c2c0b0

extern const NiPoint3 g_UNIT_X;
static const float s_fInfinity = 3.402823466e+38F;

struct NiPSysModifierStub
{
    virtual void Unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;

    NiPSysModifierStub();
};

struct FUN_00c2c030 : NiPSysModifierStub
{
    virtual void Unk00();

    void* m_pParent;
    NiPoint3 m_kDragDirection;
    float m_fDragStrength;
    float m_fFirstLightParameter;
    float m_fSecondLightParameter;

    FUN_00c2c030();
};

// Initializes the modifier stub fields: null pointer, unit vector, 0.05, and two infinity values.
// @fnv 0x00c2c030
FUN_00c2c030::FUN_00c2c030()
    : m_pParent(0), m_kDragDirection(g_UNIT_X), m_fDragStrength(0.05f), m_fFirstLightParameter(s_fInfinity),
      m_fSecondLightParameter(s_fInfinity)
{}

struct DragBinaryStreamView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(DragBinaryStreamView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct DragStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    DragBinaryStreamView* m_pUnderlyingStream;
};

struct NiPSysModifierStand
{
    void* vtable;
    char unk04[0x14];
    void LoadStream(NiStream& stream);
};

struct NiPoint3Stand
{
    float x;
    float y;
    float z;
    void LoadStream(NiStream& stream);
};

struct FUN_00c2c4f0_cls : NiPSysDragModifier
{
    void FUN_00c2c4f0(NiStream& stream);
};

// @fnv 0x00c2c4f0
void FUN_00c2c4f0_cls::FUN_00c2c4f0(NiStream& stream)
{
    reinterpret_cast<NiPSysModifierStand*>(this)->LoadStream(stream);
    void** vt = *reinterpret_cast<void***>(&stream);
    reinterpret_cast<void(__thiscall*)(NiStream*, NiAVObject*)>(vt[12])(&stream, m_pParent);
    reinterpret_cast<NiPoint3Stand*>(&m_kDragDirection)->LoadStream(stream);
    DragStreamView* s = reinterpret_cast<DragStreamView*>(&stream);
    s->m_pUnderlyingStream->Load(&m_fDragStrength);
    s->m_pUnderlyingStream->Load(&m_fFirstLightParameter);
    s->m_pUnderlyingStream->Load(&m_fSecondLightParameter);
}

struct S_00c2c590_Poly
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4C();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual bool unk5C(S_00c2c590_Poly* other);
};
struct S_00c2c590_Vec
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bool FUN_00439090(S_00c2c590_Vec* other);
};
struct S_00c2c590_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    bool FUN_00c31830(S_00c2c590_Base* other);
};
struct S_00c2c590 : S_00c2c590_Base
{
    S_00c2c590_Poly* unk18;
    int unk1C;
    int unk20;
    int unk24;
    float unk28;
    float unk2C;
    float unk30;
    bool FUN_00c2c590(S_00c2c590* other);
};
// Compares this object with other: base comparison, unk18 pointer presence and unk5C match, then unk1C vector and unk28/unk2C/unk30 floats.
// @fnv 0x00c2c590
bool S_00c2c590::FUN_00c2c590(S_00c2c590* other)
{
    if (FUN_00c31830(other))
    {
        if (unk18 && !other->unk18)
            return false;
        if (!unk18 && other->unk18)
            return false;
        if (unk18 && other->unk18 && !unk18->unk5C(other->unk18))
            return false;
        if (!((S_00c2c590_Vec*)&other->unk1C)->FUN_00439090((S_00c2c590_Vec*)&unk1C) && other->unk28 == unk28 &&
            other->unk2C == unk2C && other->unk30 == unk30)
            return true;
    }
    return false;
}

// Reconstructed NiPSysDragModifier binary-loading routine.
struct DragObject
{
    void* unk00;
    void* unk04;
    const char* objectName;
};
struct Point3Serializer
{
    float x, y, z;
    void* FUN_00a59af0(const void* typeName);
};
struct StreamArray
{
    void** vtable;
    void* elements;
    unsigned short capacity;
    unsigned short size;
    unsigned short activeSize;
    unsigned short growBy;
    void FUN_0096ad30(unsigned int newCapacity);
    void FUN_0096ae90(unsigned int index, void* const* value);
    __forceinline void Append(void* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            FUN_0096ad30(index + growBy);
        FUN_0096ae90(index, &value);
    }
};
struct NiPSysDragShell : NiPSysModifier
{
    DragObject* dragObject;
    Point3Serializer dragAxis;
    float percentage;
    float range;
    float falloff;
    void GetViewerStrings(NiStream& stream);
};
extern char DAT_0102909c;
extern char DAT_010bff18;
extern char DAT_010bff0c;
extern char DAT_010bff00;
extern char DAT_01062600;
extern char DAT_010bfef0;
void* __cdecl FUN_00a7d330(void* object);
void* __cdecl FUN_00a7d5e0(const void* typeName, const void* value);
void* __cdecl FUN_00a7d550(const void* typeName, float value);
// Saves the modifier via NiPSysModifier::SaveBinary, then appends the drag object name, drag axis, percentage, range and falloff to the stream array.
// @fnv 0x00c2c620
void NiPSysDragShell::GetViewerStrings(NiStream& stream)
{
    NiPSysModifier::SaveBinary(stream);
    StreamArray& array = *reinterpret_cast<StreamArray*>(&stream);
    array.Append(FUN_00a7d330(*reinterpret_cast<void**>(&g_01202768)));
    const char* name = dragObject ? dragObject->objectName : &DAT_0102909c;
    array.Append(FUN_00a7d5e0(&DAT_010bff18, name));
    array.Append(dragAxis.FUN_00a59af0(&DAT_010bff0c));
    array.Append(FUN_00a7d550(&DAT_010bff00, percentage));
    array.Append(FUN_00a7d550(&DAT_01062600, range));
    array.Append(FUN_00a7d550(&DAT_010bfef0, falloff));
}

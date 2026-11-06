// gamebryo2.2/corelibs/niparticle/nipsysboxemitter.cpp: NiPSysEmitter, NiPSysBoxEmitter, EmitterHack, BoxViewer and more (13 functions)

#include "nipsysboxemitter_decls.h"
// Constructs a NiPSysEmitter, initializing speed, declination, planar angle, color, radius, lifespan and unknown to their defaults.
// @fnv 0x00c21f00
NiPSysEmitter::NiPSysEmitter()
    : speed(0.0f), speedVar(0.0f), declination(0.0f), declinationVar(0.0f), planarAngle(0.0f), planarAngleVar(0.0f),
      color(DAT_011a9be0), radius(1.0f), radiusVar(0.0f), lifespan(0.0f), lifespanVar(0.0f), unknown(1.0f)
{}
// Loads the box emitter's width, height and depth floats from the stream after the base volume emitter data.
// @fnv 0x00c203b0
void NiPSysBoxEmitter::LoadBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::LoadBinary(stream);
    stream.input->ReadFloat(width);
    stream.input->ReadFloat(height);
    stream.input->ReadFloat(depth);
}

struct GlobalObjectO2_00a7b618
{
};
extern GlobalObjectO2_00a7b618 g_01202518;

// @fnv 0x00c201c0
GlobalObjectO2_00a7b618* __cdecl GetRTTI()
{
    return &g_01202518;
}

extern int DAT_010bda2c;
struct BSFadeNode
{
    void* operator new(unsigned int);
    void FUN_00c31af0();
};
// Allocates a 100-byte BSFadeNode, runs its constructor, zeroes the floats at offsets 0x58-0x60, sets its vtable, and returns it (or null).
// @fnv 0x00c20350
BSFadeNode* __cdecl FUN_00c20350()
{
    BSFadeNode* node = (BSFadeNode*)BSFadeNode::operator new(100);
    if (node)
    {
        node->FUN_00c31af0();
        *(float*)((char*)node + 0x58) = 0.0f;
        *(void**)((char*)node + 0) = &DAT_010bda2c;
        *(float*)((char*)node + 0x5c) = 0.0f;
        *(float*)((char*)node + 0x60) = 0.0f;
        return node;
    }
    return 0;
}

void __cdecl FUN_00c31750();
void __cdecl _delete(void*, unsigned int);
struct S
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
// @fnv 0x00c20390
void* __thiscall S::DestroyIfFlagged(unsigned int uiFlags)
{
    FUN_00c31750();
    if (uiFlags & 1)
        _delete(this, 0x64);
    return this;
}

struct NiObject;
struct BaseHack
{
    bool FUN_00c31b80(NiObject*);
};
struct EmitterHack
{
    char _pad[0x58];
    float m_fValueAtOffset58;
    float m_fCylinderHeight;
    float m_fValueAtOffset60;
    bool IsEqual(NiObject* pkObject);
};
// Calls FUN_00c31b80 on pkObject and returns true only if that succeeds and the three floats at offsets 0x58, 0x5c and 0x60 match the other object's.
// @fnv 0x00c20170
bool EmitterHack::IsEqual(NiObject* pkObject)
{
    EmitterHack* pkDest = (EmitterHack*)pkObject;
    if (((BaseHack*)this)->FUN_00c31b80(pkObject) && m_fValueAtOffset58 == pkDest->m_fValueAtOffset58 &&
        m_fCylinderHeight == pkDest->m_fCylinderHeight && m_fValueAtOffset60 == pkDest->m_fValueAtOffset60)
        return true;
    return false;
}

struct NiObject
{
};

struct CloningProcess
{
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
};

struct FUN_00c1ffa0_s
{
    void* __thiscall FUN_00c31b10(BSFadeNode*, void*);
};

struct NiPSysBoxEmitter_shell
{
    char _pad[0x58];
    float m_fValueAtOffset58;
    float m_fCylinderHeight;
    float m_fValueAtOffset60;
    NiObject* __thiscall Clone(CloningProcess& kCloning);
};

// @fnv 0x00c202f0
NiObject* NiPSysBoxEmitter_shell::Clone(CloningProcess& kCloning)
{
    BSFadeNode* pkObject = (BSFadeNode*)A51BF0Base::operator new(0x64);
    if (pkObject)
    {
        pkObject->FUN_00c31af0();
        *(float*)((char*)pkObject + 0x58) = 0.0f;
        *(void**)pkObject = (void*)&DAT_010bda2c;
        *(float*)((char*)pkObject + 0x5c) = 0.0f;
        *(float*)((char*)pkObject + 0x60) = 0.0f;
    }
    else
    {
        pkObject = 0;
    }
    ((FUN_00c1ffa0_s*)this)->FUN_00c31b10(pkObject, &kCloning);
    *(float*)((char*)pkObject + 0x58) = m_fValueAtOffset58;
    *(float*)((char*)pkObject + 0x5c) = m_fCylinderHeight;
    *(float*)((char*)pkObject + 0x60) = m_fValueAtOffset60;
    return (NiObject*)pkObject;
}

struct BoxEmitterBinaryStreamView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(BoxEmitterBinaryStreamView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct BoxEmitterStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    BoxEmitterBinaryStreamView* m_pUnderlyingStream;
};

struct NiPSysVolumeEmitterStand
{
    void* vtable;
    char unk04[0x50];
    void LoadStream(NiStream& stream);
};

struct FUN_00c20440_cls : NiPSysBoxEmitter
{
    void SaveBinary(NiStream& stream);
};

// Loads the volume emitter base stream, then reads width, height and depth from the stream.
// @fnv 0x00c20440
void FUN_00c20440_cls::SaveBinary(NiStream& stream)
{
    reinterpret_cast<NiPSysVolumeEmitterStand*>(this)->LoadStream(stream);
    BoxEmitterStreamView* s = reinterpret_cast<BoxEmitterStreamView*>(&stream);
    s->m_pUnderlyingStream->Load(&width);
    s->m_pUnderlyingStream->Load(&height);
    s->m_pUnderlyingStream->Load(&depth);
}

struct StrArr
{
    void* vtable;
    char** data;
    unsigned short capacity, size, used, grow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* value)
    {
        unsigned int index = size;
        if (index >= capacity)
            SetSize(index + grow);
        SetAt(index, value);
    }
};
extern const char* DAT_01202518;
extern const char DAT_0109dc8c[];
extern const char DAT_0109dc84[];
extern const char DAT_010a0eb4[];
char* __cdecl FUN_00a7d330(const char*);
char* __cdecl FUN_00a7d550(const char*, float);
struct VolumeViewer : NiPSysVolumeEmitter
{
    void FUN_00c31db0(StrArr*);
};
struct BoxViewer : NiPSysBoxEmitter
{
    void GetViewerStrings(StrArr*);
};
// Appends the base volume emitter's debug strings, then the box emitter's width, height and depth values to the string array.
// @fnv 0x00c204d0
void BoxViewer::GetViewerStrings(StrArr* strings)
{
    ((VolumeViewer*)this)->FUN_00c31db0(strings);
    strings->Add(FUN_00a7d330(DAT_01202518));
    strings->Add(FUN_00a7d550(DAT_0109dc8c, width));
    strings->Add(FUN_00a7d550(DAT_0109dc84, height));
    strings->Add(FUN_00a7d550(DAT_010a0eb4, depth));
}

struct FUN_00c61f60_class
{
    void FUN_00c2f4f0(int);
};
struct FUN_00c1fdd0
{
    void FUN_00c2f4f0(int);
};
// @fnv 0x00c1fdd0
void FUN_00c1fdd0::FUN_00c2f4f0(int a)
{
    ((FUN_00c61f60_class*)this)->FUN_00c2f4f0(a);
}

void __cdecl FUN_00c31c90();
// @fnv 0x00c20150
void __cdecl FUN_00c20150()
{
    FUN_00c31c90();
}

extern void __cdecl FUN_00c31b40();

// @fnv 0x00c20160
void __cdecl FUN_00c20160()
{
    FUN_00c31b40();
}

namespace fnv_00c201d0 {
int __cdecl rand();
extern double DAT_01029790;

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    float Dot(const NiPoint3& p) const
    {
        return x * p.x + y * p.y + z * p.z;
    }
    NiPoint3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
};

struct ThreeByThreeMatrix
{
    NiPoint3 m_aRows[3];
    NiPoint3 operator*(const NiPoint3& pt) const;
};

struct BoxEmitterInit : NiPSysBoxEmitter
{
    void ComputeVolumeInitialPositionAndVelocity(const ThreeByThreeMatrix& kRot, NiPoint3& kPos, NiPoint3& kWorldPosition);
};

// Generates a random point from the box dimensions, rotates it with kRot, and computes row dot products of kRot with kWorldPosition.
// @fnv 0x00c201d0
void BoxEmitterInit::ComputeVolumeInitialPositionAndVelocity(const ThreeByThreeMatrix& kRot, NiPoint3& kPos, NiPoint3& kWorldPosition)
{
    float fX = rand() / DAT_01029790;
    float fY = rand() / DAT_01029790;
    float fZ = rand() / DAT_01029790;
    kPos = NiPoint3((fZ - 0.5f) * width, (fY - 0.5f) * height, (fX - 0.5f) * depth);
    kPos = kRot * kPos;
    kWorldPosition = NiPoint3(kRot.m_aRows[0].Dot(kWorldPosition),
                              kRot.m_aRows[1].x * kWorldPosition.x + kRot.m_aRows[1].y * kWorldPosition.y +
                                  kRot.m_aRows[1].z * kWorldPosition.z,
                              kRot.m_aRows[2].Dot(kWorldPosition));
}
}  // namespace fnv_00c201d0

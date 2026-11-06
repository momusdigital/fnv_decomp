// gamebryo2.2/corelibs/niparticle/nipsyscylinderemitter.cpp: NiPSysCylinderEmitter, NiPSysCylinderEmitterX (7 functions)

#include "nipsyscylinderemitter_decls.h"

// @fnv 0x00c1fc40
void NiPSysCylinderEmitter::LoadBinary(NiStream& stream)
{
    NiPSysVolumeEmitter::LoadBinary(stream);
    stream.m_pUnderlyingStream->ReadFloat(m_fCylinderRadius);
    stream.m_pUnderlyingStream->ReadFloat(m_fCylinderHeight);
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
    void __thiscall FUN_00c31af0();
};

extern void* DAT_010bd8b4;

// @fnv 0x00c1fbf0
void* __cdecl FUN_00c1fbf0()
{
    BSFadeNode* pFadeNode = (BSFadeNode*)BSFadeNode::operator new(0x60);
    if (pFadeNode)
    {
        pFadeNode->FUN_00c31af0();
        *(float*)((char*)pFadeNode + 0x58) = 0.0f;
        *(void**)pFadeNode = &DAT_010bd8b4;
        *(float*)((char*)pFadeNode + 0x5c) = 0.0f;
        return pFadeNode;
    }
    return 0;
}

void __cdecl FUN_00c31750();
void __cdecl _delete(void*, unsigned int);
struct S00c1fc20
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00c31750, frees this with _delete when bit 0 of a1 is set, and returns this.
// @fnv 0x00c1fc20
void* S00c1fc20::DestroyIfFlagged(unsigned int auiFlags)
{
    FUN_00c31750();
    if (auiFlags & 1)
        _delete(this, 0x60);
    return this;
}

struct CloningProcess
{
    void* m_pCloneMap;
};
struct FUN_00c1fba0_shell : BSFadeNode
{
    BSFadeNode* CloneFadeNode(CloningProcess&);
    void FUN_00c31b10(BSFadeNode*, CloningProcess*);
};
// @fnv 0x00c1fba0
BSFadeNode* FUN_00c1fba0_shell::CloneFadeNode(CloningProcess& kCloning)
{
    BSFadeNode* pkObject = (BSFadeNode*)BSFadeNode::operator new(0x60);
    if (pkObject)
    {
        pkObject->FUN_00c31af0();
        *(float*)((char*)pkObject + 0x58) = 0.0f;
        *(void**)((char*)pkObject) = &DAT_010bd8b4;
        *(float*)((char*)pkObject + 0x5c) = 0.0f;
    }
    else
    {
        pkObject = 0;
    }
    FUN_00c31b10(pkObject, &kCloning);
    *(float*)((char*)pkObject + 0x58) = *(float*)((char*)this + 0x58);
    *(float*)((char*)pkObject + 0x5c) = *(float*)((char*)this + 0x5c);
    return pkObject;
}

struct StrArr
{
    unsigned char _padding[8];
    unsigned short _capacity;
    unsigned short _size;
    unsigned short _reserved;
    unsigned short _growth;

    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};

extern void* g_01202508;

void __stdcall FUN_00c31db0(StrArr*);
char* __cdecl _FUN_00a7d330(void*);
char* __cdecl FUN_00a7d550(char const*, float);

struct FUN_00c1fd00_shell
{
    unsigned char _padding[0x58];
    float m_fCylinderRadius;
    float m_fCylinderHeight;

    void __thiscall AppendShapeParams(StrArr*);
};

// @fnv 0x00c1fd00
void FUN_00c1fd00_shell::AppendShapeParams(StrArr* pkStrings)
{
    FUN_00c31db0(pkStrings);

    char* string = _FUN_00a7d330(g_01202508);
    unsigned int index = pkStrings->_size;
    if (!(index < pkStrings->_capacity))
        pkStrings->SetSize(index + pkStrings->_growth);
    pkStrings->SetAt(index, string);

    string = FUN_00a7d550("Radius", m_fCylinderRadius);
    index = pkStrings->_size;
    if (!(index < pkStrings->_capacity))
        pkStrings->SetSize(index + pkStrings->_growth);
    pkStrings->SetAt(index, string);

    string = FUN_00a7d550("Height", m_fCylinderHeight);
    index = pkStrings->_size;
    if (!(index < pkStrings->_capacity))
        pkStrings->SetSize(index + pkStrings->_growth);
    pkStrings->SetAt(index, string);
}

struct CylinderEmitterBinaryStreamView
{
    void* vtable;
    unsigned int absolutePosition;
    unsigned int unk08;
    unsigned int(__cdecl* read)(CylinderEmitterBinaryStreamView* stream, void* buffer, unsigned int totalBytes,
                                unsigned int* componentSizes, unsigned int componentCount);

    template <class T> void Load(T* value)
    {
        unsigned int size = sizeof(T);
        absolutePosition += read(this, value, sizeof(T), &size, 1);
    }
};

struct CylinderEmitterStreamView
{
    void* vtable;
    unsigned int version;
    char unk08[0x248];
    CylinderEmitterBinaryStreamView* m_pUnderlyingStream;
};

struct NiPSysVolumeEmitterStand
{
    void* vtable;
    char unk04[0x54];
    void LoadStream(NiStream& stream);
};

struct FUN_00c1fca0_cls : NiPSysCylinderEmitter
{
    void LoadCylinderEmitter(NiStream& stream);
};

// Loads the volume emitter base stream, then reads two values from the stream into the cylinder emitter.
// @fnv 0x00c1fca0
void FUN_00c1fca0_cls::LoadCylinderEmitter(NiStream& stream)
{
    reinterpret_cast<NiPSysVolumeEmitterStand*>(this)->LoadStream(stream);
    CylinderEmitterStreamView* s = reinterpret_cast<CylinderEmitterStreamView*>(&stream);
    s->m_pUnderlyingStream->Load(&m_fCylinderRadius);
    s->m_pUnderlyingStream->Load(&m_fCylinderHeight);
}

namespace fnv_00c1fa50 {
extern "C" int __cdecl rand(void);

extern float NI_TWO_PI_F;
extern float g_afSinTable[512];
extern float g_afCosTable[512];

struct NiPoint3
{
    float x, y, z;
};

struct ThreeByThreeMatrix
{
    float m_afEntries[3][3];
    NiPoint3 operator*(const NiPoint3& p) const;
};

inline float RandomFloat0To1()
{
    return (float)(rand() / 32767.0);
}

inline void NiSinCos(float fAngleDifference, float& fSin, float& fCos)
{
    int i = (int)(fAngleDifference * (512.0 / NI_TWO_PI_F)) & 0x1ff;
    fSin = g_afSinTable[i];
    fCos = g_afCosTable[i];
}

class NiPSysCylinderEmitterX
{
  public:
    void* m_ppVirtualMethodTable;
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
    float m_fCylinderRadius;
    float m_fCylinderHeight;

    void ComputeVolumeInitialPositionAndVelocity(ThreeByThreeMatrix& kRotate, NiPoint3& kPosition, NiPoint3& kMotionVelocity);
};

// Fills kPosition with a random point inside the cylinder and rotates both kPosition and kMotionVelocity by kRotate.
// @fnv 0x00c1fa50
void NiPSysCylinderEmitterX::ComputeVolumeInitialPositionAndVelocity(ThreeByThreeMatrix& kRotate, NiPoint3& kPosition, NiPoint3& kMotionVelocity)
{
    float fRadius = m_fCylinderRadius * RandomFloat0To1();
    float fAngleDifference = NI_TWO_PI_F * RandomFloat0To1();
    float fSin, fCos;
    NiSinCos(fAngleDifference, fSin, fCos);
    kPosition.x = fRadius * fCos;
    kPosition.y = fRadius * fSin;
    kPosition.z = (RandomFloat0To1() - 0.5) * m_fCylinderHeight;
    kPosition = kRotate * kPosition;
    NiPoint3 kResult;
    kResult.x = kRotate.m_afEntries[0][0] * kMotionVelocity.x + kRotate.m_afEntries[0][1] * kMotionVelocity.y +
                kRotate.m_afEntries[0][2] * kMotionVelocity.z;
    kResult.y = kRotate.m_afEntries[1][0] * kMotionVelocity.x + kRotate.m_afEntries[1][1] * kMotionVelocity.y +
                kRotate.m_afEntries[1][2] * kMotionVelocity.z;
    kResult.z = kRotate.m_afEntries[2][0] * kMotionVelocity.x + kRotate.m_afEntries[2][1] * kMotionVelocity.y +
                kRotate.m_afEntries[2][2] * kMotionVelocity.z;
    kMotionVelocity = kResult;
}
}  // namespace fnv_00c1fa50

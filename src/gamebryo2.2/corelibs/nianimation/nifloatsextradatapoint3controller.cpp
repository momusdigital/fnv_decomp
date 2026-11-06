
// src/gamebryo2.2/corelibs/nianimation/nifloatsextradatapoint3controller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nifloatsextradatapoint3controller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BSFadeNode {
    static void* __cdecl operator new(unsigned int);
};

int* __fastcall InitTimeController(int*);

extern int DAT_0109917c;
extern int EmptyFS;

// @fnv 0x00a4ecd0
int* __cdecl FUN_00a4ecd0()
{
    int* p = (int*)BSFadeNode::operator new(0x48);
    if (p)
    {
        InitTimeController(p);
        p[0] = (int)&DAT_0109917c;
        p[0x40 / 4] = -1;
        p[0x44 / 4] = EmptyFS;
        return p;
    }
    return 0;
}

struct NiPSysModifierCtlr {
    void CopyMemberData(NiPSysModifierCtlr* src, void* proc);
};
struct NiFloatsExtraDataPoint3Controller : NiPSysModifierCtlr {
    int* __fastcall InitTimeController();
    int* m_pvt;
    char pad[0x3c];
    int m_iFloatsExtraDataIndex;
    int m_kCtlrID;
    NiFloatsExtraDataPoint3Controller* CreateClone(void* proc);
};
// @fnv 0x00a4ec80
NiFloatsExtraDataPoint3Controller* NiFloatsExtraDataPoint3Controller::CreateClone(void* proc)
{
    NiFloatsExtraDataPoint3Controller* p = (NiFloatsExtraDataPoint3Controller*)BSFadeNode::operator new(0x48);
    if (p) {
        p->InitTimeController();
        p->m_pvt = &DAT_0109917c;
        p->m_iFloatsExtraDataIndex = -1;
        p->m_kCtlrID = EmptyFS;
    } else {
        p = 0;
    }
    CopyMemberData(p, proc);
    p->m_iFloatsExtraDataIndex = m_iFloatsExtraDataIndex;
    return p;
}

namespace fnv_00a4ee90 {
struct NiBinaryStream {
    int _unk0;
    unsigned int position;
    int (__cdecl *read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream {
    unsigned char _pad[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};
struct NiPSysModifierCtlr {
    void LoadBinary(NiStream&);
};
struct NiFloatsExtraDataPoint3Controller : NiPSysModifierCtlr {
    char _pad[0x40];
    float m_fPoint3Value;
    void FUN_00a4ee90(NiStream&);
};
// @fnv 0x00a4ee90
void NiFloatsExtraDataPoint3Controller::FUN_00a4ee90(NiStream& stream)
{
    NiPSysModifierCtlr::LoadBinary(stream);
    NiBinaryStream* __restrict input = stream.m_pUnderlyingStream;
    unsigned int size = 4;
    input->position += input->read(input, &m_fPoint3Value, 4, &size, 1);
}
}  // namespace fnv_00a4ee90

struct NiRTTI;
struct NiObject {
    NiObject* DynamicCast(const NiRTTI*);
};
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3f70;
struct ExtraStub {
    float GetValueAt(int);
};
struct Vec12 {
    float x, y, z;
};
struct Holder00 {
    void FUN_00a494b0(Vec12);
};
struct FUN_00a4ed50_shell : NiFloatsExtraDataPoint3Controller {
    void SetInterpolatorPoint3(NiObject* pkInterp, unsigned short usIndex);
};
// @fnv 0x00a4ed50
void FUN_00a4ed50_shell::SetInterpolatorPoint3(NiObject* pkInterp, unsigned short usIndex)
{
    NiObject* pkFloatInterp;
    ExtraStub* pkFloatsED;
    Vec12 kPt;
    if (!pkInterp) {
        pkFloatInterp = 0;
    } else {
        pkFloatInterp = pkInterp->DynamicCast((const NiRTTI*)&g_011f3f70);
    }
    pkFloatsED = (ExtraStub*)*(int*)((char*)this + 0x3c);
    kPt.x = pkFloatsED->GetValueAt(m_iFloatsExtraDataIndex);
    kPt.y = pkFloatsED->GetValueAt(m_iFloatsExtraDataIndex + 1);
    kPt.z = pkFloatsED->GetValueAt(m_iFloatsExtraDataIndex + 2);
    ((Holder00*)pkFloatInterp)->FUN_00a494b0(kPt);
}

struct StrArr {
    void* m_data;
    void* m_reserved;
    unsigned short m_pRayCursor;
    unsigned short m_iElementCount;
    unsigned short m_ucUnknownByte;
    unsigned short m_growth;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct Base57420 {
    unsigned char pad[0x3d];
    void FUN_00a57420(StrArr* strings);
};

extern void* g_011f3fc4;

char* __cdecl _FUN_00a7d330(void* value);
char* __cdecl FUN_00a7d4d0(char const* name, int value);

struct FUN_00a4eed0_shell : Base57420 {
    int m_iFloatsExtraDataIndex;

    void GetViewerStrings(StrArr* strings);
};

// @fnv 0x00a4eed0
void FUN_00a4eed0_shell::GetViewerStrings(StrArr* strings)
{
    Base57420::FUN_00a57420(strings);

    {
        char* value = _FUN_00a7d330(g_011f3fc4);
        unsigned int index = strings->m_iElementCount;
        unsigned int capacity = strings->m_pRayCursor;
        if (index >= capacity)
            strings->SetSize(index + strings->m_growth);
        strings->SetAt(index, value);
    }

    {
        char* value = FUN_00a7d4d0("m_iFloatsExtraDataIndex",
                                    m_iFloatsExtraDataIndex);
        unsigned int index = strings->m_iElementCount;
        unsigned int capacity = strings->m_pRayCursor;
        if (index >= capacity)
            strings->SetSize(index + strings->m_growth);
        strings->SetAt(index, value);
    }
}

int* __fastcall InitTimeController(int*);
extern int DAT_0109917c;
extern int EmptyFS;
int* __cdecl FUN_00a4ecd0();


struct NiRTTI;

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3f70;






extern void* g_011f3fc4;
char* __cdecl _FUN_00a7d330(void* value);
char* __cdecl FUN_00a7d4d0(char const* name, int value);


void* __cdecl FUN_00aa13e0(unsigned int);

struct Vec12Sink {
    int FUN_00a49650(Vec12 v);
};

struct FUN_00a4eb50_cls {
    char unk00[0x3c];
    ExtraStub* m_3c;
    int m_40;

    int BuildAndDispatchVec12(int unused);
};

// Reads three values from the stub at m_40, packs them into a Vec12, allocates a 0x20-byte sink and passes the vector to it.
// @fnv 0x00a4eb50
int FUN_00a4eb50_cls::BuildAndDispatchVec12(int unused)
{
    ExtraStub* stub = m_3c;
    Vec12 v;
    v.x = stub->GetValueAt(m_40);
    v.y = stub->GetValueAt(m_40 + 1);
    v.z = stub->GetValueAt(m_40 + 2);
    Vec12Sink* p = (Vec12Sink*)FUN_00aa13e0(0x20);
    if (p != 0) {
        return p->FUN_00a49650(v);
    }
    return 0;
}

extern "C" int DAT_0109917c;
extern "C" char* DAT_0109b220;
extern "C" void (__stdcall* DAT_00fdf1c4)(void*);
void __cdecl FUN_00aa1460(void* ptr, unsigned int size);

struct FUN_00a4ed10_cls {
    void* vptr;
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
    char* m_44;

    void FUN_00a572d0();
    FUN_00a4ed10_cls* Destroy(unsigned char acFlags);
};

// @fnv 0x00a4ed10
FUN_00a4ed10_cls* FUN_00a4ed10_cls::Destroy(unsigned char acFlags)
{
    *(void* volatile*)this = (void*)&DAT_0109917c;
    char* volatile* pm44 = (char* volatile*)&m_44;
    char* p = *pm44;
    if (p != DAT_0109b220) {
        DAT_00fdf1c4(p - 8);
    }
    FUN_00a572d0();
    if (acFlags & 1) {
        FUN_00aa1460(this, 0x48);
    }
    return this;
}

extern const float DAT_01096324;
struct Pt4edd { float x, y, z; };
class NiFloatsExtraData { public: bool SetValue(unsigned int, float); };
class Interp4edd {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b();
    virtual void v1c(); virtual void v1d(); virtual void v1e(); virtual void v1f();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24();
    virtual bool Update(float fTime, void* pkTarget, Pt4edd& kValue);
    virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v2a(); virtual void v2b();
    virtual void v2c(); virtual void v2d(); virtual void v2e(); virtual void v2f();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34();
    virtual bool AlwaysUpdate();
};
struct FUN_00a36250_t { bool FUN_00a36250(float); };

class Ctlr4edd {
public:
    void* m_pvt;
    int m_iRefCount;
    unsigned short m_uiObjectFlags;
    unsigned char GetMC() const { return (m_uiObjectFlags >> 5) & 1; }
    char _pad0a[0x1e];
    float m_fControllerTime;
    void* m_pkTarget;
    int m_30;
    Interp4edd* m_spControllerInterpolator;
    int m_38;
    NiFloatsExtraData* m_pkFloatsData;
    int m_iFloatsExtraDataIndex;
    bool FUN_00a36250(float);
    void UpdateController(const float& fTime);
};

// @fnv 0x00a4edd0
void Ctlr4edd::UpdateController(const float& fTime)
{
    if (GetMC())
        m_fControllerTime = DAT_01096324;
    else if (FUN_00a36250(fTime)
        && (!m_spControllerInterpolator || !m_spControllerInterpolator->AlwaysUpdate()))
        return;

    if (m_spControllerInterpolator) {
        Pt4edd kValue;
        if (m_spControllerInterpolator->Update(m_fControllerTime, m_pkTarget, kValue)) {
            NiFloatsExtraData* pkData = m_pkFloatsData;
            if (pkData) {
                pkData->SetValue(m_iFloatsExtraDataIndex, kValue.x);
                pkData->SetValue(m_iFloatsExtraDataIndex + 1, kValue.y);
                pkData->SetValue(m_iFloatsExtraDataIndex + 2, kValue.z);
            }
        }
    }
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

#include <windows.h>
extern "C" double __cdecl fabs(double);
struct D3DVERTEXBUFFER_DESC { unsigned Format, Type, Usage, Pool, Size, FVF; };
struct IDirect3DVertexBuffer9 {
    virtual void __stdcall v00(); virtual void __stdcall v04(); virtual void __stdcall v08();
    virtual void __stdcall v0c(); virtual void __stdcall v10(); virtual void __stdcall v14();
    virtual void __stdcall v18(); virtual void __stdcall v1c(); virtual void __stdcall v20();
    virtual void __stdcall v24(); virtual void __stdcall v28(); virtual void __stdcall v2c();
    virtual int __stdcall Unlock();
    virtual int __stdcall GetDesc(D3DVERTEXBUFFER_DESC*);
};

extern unsigned int DAT_011bf558;
extern const float DAT_010718c0;
extern const double DAT_0101e568;
extern const char DAT_010efe14[];

struct RenderBuffer {
    unsigned unk00, unk04, unk08, unk0c;
    unsigned unk10, unk14, unk18, unk1c;
    unsigned count;
    unsigned* firstEntry;
    void** entries;
    void FUN_00e8f010(unsigned count);
};

struct Point3 { float x, y, z; };
struct Color4 { float r, g, b, a; };
struct TwoComponentVector { float x, y; TwoComponentVector& operator=(const TwoComponentVector& p) { *(unsigned*)&x=*(const unsigned*)&p.x; *(unsigned*)&y=*(const unsigned*)&p.y; return *this; } };

struct VertexSource {
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned short flags;
    unsigned short unk0e;
    unsigned unk10, unk14, unk18, unk1c;
    Point3* positions;
    Point3* normals;
    Color4* colors;
    Point3* GetPositions() const { return positions; }
    Point3* GetNormals() const { return normals; }
    Color4* GetColors() const { return colors; }
    TwoComponentVector* FUN_00a66960(unsigned index);
};

struct VertexData {
    unsigned unk00;
    unsigned unk04;
    float* attributes;
    unsigned short* indices;
    unsigned unk10, unk14, unk18;
    unsigned short vertexCount;
    unsigned short unk1e;
    unsigned short componentCount;
    unsigned short unk22;
    unsigned unk24;
    RenderBuffer* buffer;
};

struct VertexBufferLockInfo {
    unsigned unk00;
    unsigned unk04;
    IDirect3DVertexBuffer9* buffer;
    unsigned lockArg0;
    unsigned lockArg1;
    unsigned lockArg2;
    unsigned GetBuffer() const { return (unsigned)buffer; }
    unsigned GetOffset() const { return lockArg0; }
    unsigned GetFlags() const { return lockArg2; }
    IDirect3DVertexBuffer9* GetSize() const { return (IDirect3DVertexBuffer9*)lockArg1; }
};

extern int __cdecl FUN_00a305b0(char*, unsigned, const char*, ...);
extern void __cdecl FUN_00ec44d0(void*, unsigned, unsigned);

struct VertexRenderer {
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned lockArg;
    unsigned unk44;
    void* lockedPtr;
    unsigned lockedState;
    unsigned unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    unsigned unk70, unk74, unk78, unk7c;
    CRITICAL_SECTION lock;

    __declspec(noalias) void FUN_00e8c120(VertexSource*, VertexData*, unsigned*, unsigned*, unsigned*, unsigned*, unsigned*, unsigned*, unsigned*);
    bool FUN_00e8bfa0(RenderBuffer*, unsigned);
    void* FUN_00e8bff0(unsigned, unsigned, unsigned, IDirect3DVertexBuffer9*);
    VertexBufferLockInfo* FUN_00e8c820(VertexSource*, unsigned, VertexData*, unsigned, VertexBufferLockInfo*, char*);
};

// @fnv 0x00e8c820
VertexBufferLockInfo* VertexRenderer::FUN_00e8c820(VertexSource* source, unsigned unused, VertexData* data, unsigned flags, VertexBufferLockInfo* existing, char* option)
{
    unsigned vertexCount;
    unsigned dataFlags;
    unsigned texOffset;
    unsigned normalOffset;
    unsigned attributeOffset;
    unsigned positionOffset;
    unsigned stride;
    Point3* positions = source->GetPositions();
    Point3* normals = source->GetNormals();
    unsigned textureSetCount = source->flags & 1;
    Color4* colors = source->GetColors();
    if (textureSetCount > DAT_011bf558)
        textureSetCount = DAT_011bf558;

    unsigned componentCount = data->componentCount;
    unsigned numVertices = data->vertexCount;
    unsigned short* indices = data->indices;
    vertexCount = 0;
    stride = 0;
    FUN_00e8c120(source, data, &vertexCount, &stride, &positionOffset, &attributeOffset,
                  &normalOffset, &dataFlags, &texOffset);

    RenderBuffer* buffer = data->buffer;
    buffer->FUN_00e8f010(vertexCount);
    if (buffer->count > 0)
        *buffer->firstEntry = stride;

    VertexBufferLockInfo* resource;
    bool needsUnlock = true;
    if (option != 0) {
        resource = existing;
        needsUnlock = false;
    } else {
        bool valid = false;
        IDirect3DVertexBuffer9* existingBuffer;
        if (existing && (existingBuffer = existing->buffer)) {
            D3DVERTEXBUFFER_DESC desc;
            existingBuffer->GetDesc(&desc);
            if ((int)desc.Format == 100 && desc.FVF == vertexCount &&
                desc.Size >= unsigned((unsigned short)numVertices) * stride) {
                resource = existing;
                valid = true;
            }
        }
        if (!valid) {
            if (!FUN_00e8bfa0(buffer, 0))
                return 0;
            if (buffer->count > 0)
                resource = *(VertexBufferLockInfo**)buffer->entries;
            else
                resource = 0;
            flags = 0xfff;
        }
        option = (char*)FUN_00e8bff0(resource->GetBuffer(), resource->GetOffset(),
                                        resource->GetFlags(), resource->GetSize());
    }

    char* dst = (char*)(option + positionOffset);
    if (positions && (flags & 1)) {
        for (unsigned i = 0; i < (unsigned short)numVertices; ++i) {
            unsigned k = indices[i];
            *(Point3*)dst = positions[k];
            dst += stride;
        }

        float* attrib = data->attributes;
        char* target = (char*)(option + attributeOffset);
        for (unsigned i = 0; i < (unsigned short)numVertices; ++i) {
            float sum = 1.0f;
            for (unsigned j = 0; j < (unsigned short)componentCount; ++j)
                sum -= attrib[j];

            float magnitude = (float)fabs(sum);
            if (magnitude > 1e-5f) {
                char message[256];
                FUN_00a305b0(message, 256, "ILLEGAL WEIGHTS! Vertex %4d - Weight Sum %8.5f  (%8.5f)\n", i, 1.0 - (double)sum, (double)sum);
            }

            unsigned short c = 0;
            int limit = (unsigned short)componentCount - 1;
            for (; (int)c < limit; ++c)
                *(float*)(target + c * 4) = attrib[c];
            if ((unsigned short)componentCount == 3 || (unsigned short)componentCount == 1)
                *(float*)(target + c * 4) = attrib[c];

            target += stride;
            attrib += (unsigned short)componentCount;
        }
    }

    if (normals && (flags & 2)) {
        dst = (char*)(option + normalOffset);
        for (unsigned i = 0; i < (unsigned short)numVertices; ++i) {
            unsigned k = indices[i];
            *(Point3*)dst = normals[k];
            dst += stride;
        }
    }

    if (colors && (flags & 4)) {
        dst = (char*)(option + dataFlags);
        for (unsigned i = 0; i < (unsigned short)numVertices; ++i) {
            *(unsigned*)dst = (((fnv_FloatToInt(colors[indices[i]].a * 255.0) << 8) | fnv_FloatToInt(colors[indices[i]].r * 255.0)) << 8 | fnv_FloatToInt(colors[indices[i]].g * 255.0)) << 8 | fnv_FloatToInt(colors[indices[i]].b * 255.0);
            dst += stride;
        }
    }

    if (flags & 8) {
        unsigned i = 0;
        if (i < textureSetCount) {
        TwoComponentVector* dest = (TwoComponentVector*)(option + texOffset);
        do {
            TwoComponentVector* out = dest;
            TwoComponentVector* uv = source->FUN_00a66960(i);
            for (unsigned j = 0; j < (unsigned short)numVertices; ++j) {
                unsigned k = indices[j];
                *out = uv[k];
                out = (TwoComponentVector*)((char*)out + stride);
            }
            ++i;
            ++dest;
        } while (i < textureSetCount);
        }
    }
    if (needsUnlock) {
        IDirect3DVertexBuffer9* hardwareBuffer = resource->buffer;
        FUN_00ec44d0(lockedPtr, lockArg, lockedState);
        lockedPtr = 0;
        lockedState = 0;
        LeaveCriticalSection(&lock);
        if (hardwareBuffer->Unlock() < 0)
            return 0;
    }
    return resource;
}

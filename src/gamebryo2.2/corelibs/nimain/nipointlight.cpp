
// src/gamebryo2.2/corelibs/nimain/nipointlight.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nipointlight.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiObject
{
    virtual ~NiObject();
};

struct NiPointLight : NiObject
{
    NiPointLight();
    ~NiPointLight();
    bool IsEqual(NiObject* pObject);
    bool FUN_00a7d730(NiObject* pObject);
};

// @fnv 0x00a7d730
bool NiPointLight::FUN_00a7d730(NiObject* pObject)
{
    NiPointLight* pOtherLight = static_cast<NiPointLight*>(pObject);
    if (IsEqual(pOtherLight))
    {
        if (reinterpret_cast<float*>(this)[0x3C] == reinterpret_cast<float*>(pOtherLight)[0x3C] &&
            reinterpret_cast<float*>(this)[0x3D] == reinterpret_cast<float*>(pOtherLight)[0x3D] &&
            reinterpret_cast<float*>(this)[0x3E] == reinterpret_cast<float*>(pOtherLight)[0x3E])
            return true;
    }
    return false;
}

extern const char* const g_011f5ec4_arg1;

// @fnv 0x00a7d790
const char* const* __cdecl FUN_00a7d790()
{
    return &g_011f5ec4_arg1;
}

namespace fnv_00a7d7a0 {
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

struct NiAVObject
{
    void UpdateWorldData(NiUpdateData& update);
};

struct NiPointLight : NiAVObject
{
    void FUN_00a7d7a0(NiUpdateData& update);
};

// @fnv 0x00a7d7a0
void NiPointLight::FUN_00a7d7a0(NiUpdateData& update)
{
    NiAVObject::UpdateWorldData(update);
    ((int*)this)[0xa8 / 4]++;
}
}  // namespace fnv_00a7d7a0

extern const void* g_011f5f6c;

// @fnv 0x00a9b390
const void* __cdecl FUN_00a9b390()
{
    return &g_011f5f6c;
}

struct NiMemObject
{
    static void* operator new(unsigned int size);
};
extern void __fastcall FUN_00a71f60(void* object);
struct FUN_00a71ec0_helper
{
    void FUN_00a71ec0(void* clone, void* process);
};
extern const unsigned int DAT_0109dd0c;
struct NiPointLightLayout
{
    unsigned int vtable;
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    unsigned char unk9c;
    unsigned char unk9d;
    unsigned short unk9e;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    float unkF0;
    float unkF4;
    float unkF8;
};
struct FUN_00a7d7c0_Class
{
    void* ClonePointLight(void* process);
};
// @fnv 0x00a7d7c0
void* FUN_00a7d7c0_Class::ClonePointLight(void* process)
{
    NiPointLightLayout* clone;
    void* allocation = NiMemObject::operator new(0xfc);
    if (allocation)
    {
        clone = (NiPointLightLayout*)allocation;
        FUN_00a71f60(clone);
        float zero = 0.0f;
        clone->unkF0 = zero;
        clone->vtable = (unsigned int)&DAT_0109dd0c;
        clone->unk9d = 2;
        float one = 1.0f;
        clone->unkF4 = one;
        clone->unkF8 = zero;
    }
    else
    {
        clone = 0;
    }
    ((FUN_00a71ec0_helper*)this)->FUN_00a71ec0(clone, process);
    clone->unkF0 = ((NiPointLightLayout*)this)->unkF0;
    clone->unkF4 = ((NiPointLightLayout*)this)->unkF4;
    clone->unkF8 = ((NiPointLightLayout*)this)->unkF8;
    return clone;
}

// NiPointLight::SaveToStream (NiPointLight vtable slot 20)
//
// The base class stores the light first; afterwards the three light radii
// (unkF0 / unkF4 / unkF8) are handed to the stream buffer that the stream
// keeps at offset 0x24c.  The buffer counts the values it receives, so the
// result of every call is added to the buffer's counter at offset 4.
//
// The callback is called with the buffer itself as its first argument, then
// the radius, the radius size (4), a pointer to an int that is preset to 4
// and a flag of 1.

// The stream buffer: a vtable pointer, a counter and the callback that the
// buffer passes to itself as its first argument.
typedef int (*NiBufferReadFn)(void* buffer, float* data, int size, int* out, int flag);

struct NiStreamBuf
{
    void* unk00;
    int unk04;
    NiBufferReadFn unk08;
};

// The stream; the light data is handed to the buffer it keeps at 0x24c.
struct NiStream
{
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    NiStreamBuf* unk24C;
};

struct NiPointLightSave : NiPointLightLayout
{
    void FUN_00a72080(NiStream* stream);
    void SaveToStream(NiStream* stream);
};

// @fnv 0x00a7d840
void NiPointLightSave::SaveToStream(NiStream* stream)
{
    this->FUN_00a72080(stream);

    // One block per light radius.  The out value of the callback lives in an
    // inner scope: that is what makes the compiler keep the callback in EDX
    // and hoist its load to the top of the block, exactly like the original.
    {
        NiStreamBuf* buffer = stream->unk24C;
        {
            int count = 4;
            buffer->unk04 += buffer->unk08(buffer, &this->unkF0, 4, &count, 1);
        }
    }

    {
        NiStreamBuf* buffer = stream->unk24C;
        {
            int count = 4;
            buffer->unk04 += buffer->unk08(buffer, &this->unkF4, 4, &count, 1);
        }
    }

    {
        NiStreamBuf* buffer = stream->unk24C;
        {
            int count = 4;
            buffer->unk04 += buffer->unk08(buffer, &this->unkF8, 4, &count, 1);
        }
    }
}

namespace fnv_00a7d8d0 {
// NiPointLight::SavePointLight (NiPointLight vtable slot 22)
//
// The base class stores the light first; afterwards the three light radii
// (unkF0 / unkF4 / unkF8) are handed to the render target that the stream
// keeps at offset 0x250.  The target counts the values it receives, so the
// result of every call is added to the target's counter at offset 4.
//
// The callback is called with the target itself as its first argument, then
// the radius, the radius size (4), a pointer to an int that is preset to 4
// and a flag of 1.

// The render target: a vtable pointer, a counter and the callback that the
// target passes to itself as its first argument.
typedef int (*NiRenderSaveFn)(void* target, float* data, int size, int* out, int flag);

struct NiRenderTarget
{
    void* unk00;
    int unk04;
    void* unk08;
    NiRenderSaveFn unk0C;
};

// The stream; the light data is handed to the render target it keeps at 0x250.
struct NiStream
{
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    NiRenderTarget* unk250;
};

struct NiPointLightSave : NiPointLightLayout
{
    void FUN_00a720f0(NiStream* stream);
    void SavePointLight(NiStream* stream);
};

// Calls FUN_00a720f0 then writes the three 4-byte values at unkF0, unkF4 and unkF8 to stream->unk250, accumulating the byte counts into its unk04.
// @fnv 0x00a7d8d0
void NiPointLightSave::SavePointLight(NiStream* stream)
{
    this->FUN_00a720f0(stream);

    // One block per light radius.  The out value of the callback lives in an
    // inner scope: that is what makes the compiler keep the callback in EDX
    // and hoist its load to the top of the block, exactly like the original.
    {
        NiRenderTarget* target = stream->unk250;
        {
            int count = 4;
            target->unk04 += target->unk0C(target, &this->unkF0, 4, &count, 1);
        }
    }

    {
        NiRenderTarget* target = stream->unk250;
        {
            int count = 4;
            target->unk04 += target->unk0C(target, &this->unkF4, 4, &count, 1);
        }
    }

    {
        NiRenderTarget* target = stream->unk250;
        {
            int count = 4;
            target->unk04 += target->unk0C(target, &this->unkF8, 4, &count, 1);
        }
    }
}
}  // namespace fnv_00a7d8d0

struct S_00a7d960_arg
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned short m_08;
    unsigned short m_0a;
    unsigned short unk0c;
    unsigned short m_0e;
    void FUN_0096ad30(unsigned int n);
    void FUN_0096ae90(unsigned int idx, char* const& v);
};

extern unsigned int DAT_011f4a98;
extern const char str_0109de00[];
extern const char str_0109ddf4[];
extern const char str_0109dde8[];
char* __cdecl FUN_00a7d330(unsigned int v);
char* __cdecl FUN_00a7d550(const char* fmt, float v);

inline void S_Push(S_00a7d960_arg* p, char* s)
{
    unsigned int n = p->m_0a;
    if (n >= p->m_08)
    {
        p->FUN_0096ad30(n + p->m_0e);
    }
    p->FUN_0096ae90(n, s);
}

struct S_00a7d960_base : NiPointLightLayout
{
    void AppendEffectProperties(S_00a7d960_arg* p);
};

struct FUN_00a7d960_cls : S_00a7d960_base
{
    void GetViewerStrings(S_00a7d960_arg* p);
};

// @fnv 0x00a7d960
void FUN_00a7d960_cls::GetViewerStrings(S_00a7d960_arg* pBuffer)
{
    AppendEffectProperties(pBuffer);
    S_Push(pBuffer, FUN_00a7d330(DAT_011f4a98));
    S_Push(pBuffer, FUN_00a7d550(str_0109de00, unkF0));
    S_Push(pBuffer, FUN_00a7d550(str_0109ddf4, unkF4));
    S_Push(pBuffer, FUN_00a7d550(str_0109dde8, unkF8));
}

void __cdecl FUN_00a71f50();

// @fnv 0x00a9b360
void __cdecl FUN_00a9b360()
{
    FUN_00a71f50();
}

void __cdecl FUN_00a720f0(int param1, int param2);

// @fnv 0x00a9b370
void __cdecl FUN_00a9b370(int param1, int param2)
{
    FUN_00a720f0(param1, param2);
}

extern void __cdecl FUN_00a72160();

// @fnv 0x00a9b380
void __cdecl FUN_00a9b380()
{
    FUN_00a72160();
}

// src/havok/physics/collide/agent/compoundagent/list/hkplistagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/compoundagent/list/hkplistagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/compoundagent/list/hkplistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/list/hkplistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl FUN_00da3510(void*, void*);
struct hkAgent1nMachine
{
    void __thiscall InvalidateTim(void*);
};
struct hkpListAgent
{
    char m0[0x10];
    void __thiscall FUN_00d36850(void* arg);
};
extern "C" void __cdecl FUN_00d36990(int, int, int, int);
void __stdcall FUN_00d36b00(int aiArg1, int aiArg2, int aiArg3, int aiArg4);
extern "C" void __cdecl FUN_00da35f0(void*, float, float, int);
struct Owner
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00d36870(float a1, float a2, int a3);
};
void __cdecl FUN_00d36920(void* a, void* b, void* c, void* d);
void __stdcall FUN_00d36940(void* apArg1, void* apArg2, void* apArg3, void* apArg4);
void __cdecl FUN_00d36930(int a1, int a2, int a3, int a4, int a5);
void __stdcall FUN_00d36960(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5);
extern "C" void __cdecl FUN_00da42b0(void* a, int b, int c, int d);
struct FUN_00d36820_cls
{
    virtual void v00(int a);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00d36820(int a1);
};
struct S_00d368a0_Arg
{
    int unk00;
    int unk04;
    int m_field08;
};
void __cdecl FUN_00d97250(void* sub, int field08, S_00d368a0_Arg* arg);
struct S_00d368a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_sub10;

    void FUN_00d368a0(S_00d368a0_Arg* a, int unused);
};
extern "C" void __cdecl FUN_00da48e0(void*, void*);
struct VirtTarget
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    virtual int v10();
};
struct CallArgs
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct FUN_00d368c0_cls
{
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    int unk10;
    void FUN_00d368c0(void* a1, void* a2, void* a3, void* a4);
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);

extern "C" void _ReadWriteBarrier();
struct S00d369a0_ShapeBase
{
    virtual void v00();
    int unk04, unk08, unk0C;
};
struct S00d369a0_Container
{
    virtual void v00();
};
struct S00d369a0_Bits : S00d369a0_ShapeBase, S00d369a0_Container
{
    int unk14;
    int unk18;
    int m1C;
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
    unsigned int m50[8];
    inline int enabled(unsigned k, unsigned int& m) const
    {
        if (k < 256)
        {
            return m50[k >> 5] & m;
        }
        return 1;
    }
};

struct S00d369a0_Motion
{
    __m128 c0, c1, c2, translation;
    __m128 v40;
    union
    {
        __m128 v50;
        struct
        {
            float x50, y54, z58, f5c;
        };
    };
    __m128 v60, v70, v80;
    union
    {
        __m128 v90;
        struct
        {
            float x90, y94, z98, f9c;
        };
    };
    float fa0;
};
struct S00d369a0_Body
{
    S00d369a0_Bits* m00;
    int unk04;
    S00d369a0_Motion* m08;
    int unk0C;
};
struct S00d369a0_Config
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40, unk44, unk48, unk4C, unk50, unk54;
    float f58;
};

struct S00d369a0_Transform
{
    __m128 c0, c1, c2, translation;
    void __thiscall FUN_00cb22f0(S00d369a0_Motion* a, S00d369a0_Motion* b);
};
struct S00d369a0_ProcessInput
{
    S00d369a0_Body* a;
    S00d369a0_Body* b;
    int zero;
    S00d369a0_Config* config;
    void* cache;
    int unk14, unk18, unk1C;
    S00d369a0_Transform transform;
    __m128 unk60;
    __m128 tim;
};
extern "C" void* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00da4aa0(void* a, S00d369a0_ProcessInput* b, S00d369a0_Container* c, void* d, int e);
extern "C" unsigned int _rotl(unsigned int, int);
extern "C" void _ReadWriteBarrier();
struct S00d369a0_ListAgent
{
    int unk00, unk04;
    void* m08;
    int unk0C, track10;
    void processCollision(S00d369a0_Body* a1, S00d369a0_Body* a2, S00d369a0_Config* a3, int a4);
};
// @fnv 0x00d369a0
void S00d369a0_ListAgent::processCollision(S00d369a0_Body* a1, S00d369a0_Body* a2, S00d369a0_Config* a3, int a4)
{
    S00d369a0_ProcessInput input;
    S00d369a0_Bits* bits = a2->m00;
    input.b = a2;
    input.zero = 0;
    input.a = a1;
    float dt = a3->f58;
    input.config = a3;
    input.cache = this->m08;
    S00d369a0_Motion* o = a1->m08;
    S00d369a0_Motion* p = a2->m08;
    __m128 d0 = _mm_sub_ps(o->v40, o->v50);
    __m128 d1 = _mm_sub_ps(p->v50, p->v40);
    float f0 = dt * o->f5c;
    float f1 = dt * p->f5c;
    input.tim = _mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&f0), _mm_load_ss(&f0), 0), d0);
    input.tim = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(_mm_load_ss(&f1), _mm_load_ss(&f1), 0), d1), input.tim);
    input.tim.m128_f32[3] = (f0 * o->f9c) * o->fa0 + (f1 * p->f9c) * p->fa0;
    input.transform.FUN_00cb22f0(o, p);
    int count = bits->m1C;
    unsigned int* out = (unsigned int*)FUN_00c85750();
    unsigned int* dst = (unsigned int*)*out;
    *out = (unsigned int)dst + ((count * 4 + 0x83) & 0xffffff80);
    int n = 0;
    unsigned int mask = 1;
    for (int i = 0; i < count; ++i, *(volatile unsigned int*)& mask = _rotl(*(volatile unsigned int*)&mask, 1))
    {
        if (bits->enabled(i, mask))
            dst[n++] = i;
    }
    dst[n] = 0xffffffff;
    FUN_00da4aa0(&this->track10, &input, bits, dst, a4);
    *(unsigned int*)FUN_00c85750() = (unsigned int)dst;
}

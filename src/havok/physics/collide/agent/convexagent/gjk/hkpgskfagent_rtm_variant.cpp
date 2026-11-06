// src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void __cdecl FUN_00dacc00();
void __cdecl TestGsk();
void __cdecl FUN_00dac450();
void __cdecl FUN_00daf8e0();
struct FUN_00dacc70_vt
{
    void (*m_pVirtualFunction0)();
    void (*m_pVirtualFunction1)();
    void (*m_pVirtualFunction2)();
    void (*m_pVirtualFunction3)();
    unsigned char b0;
    unsigned char b1;
};
void __cdecl InitVtable(FUN_00dacc70_vt* p);
void __cdecl ReleaseAllEntries(void*, void*, void*);
struct FUN_00dacaf0_vt
{
    void(__thiscall* dtor)(void*, int);
};
struct FUN_00dacaf0
{
    FUN_00dacaf0_vt* vt;  // +0x00
    void* field4;         // +0x04
    void* field8;         // +0x08
    char pad[0x24];       // +0x0c..0x2f
    char field30[0x10];   // +0x30
    void cleanup(void* arg);
};
void __cdecl FUN_00dae340(void*, int);
struct hkpGskfAgent
{
    void removePoint(unsigned short id);
};
struct FUN_00dacb60_class
{
    unsigned char m_pad00[0x32];
    unsigned char m_uiItemCount;
    unsigned char m_pad01[3];

    struct Potential
    {
        unsigned short m_uiFilterValue;
        unsigned char m_auiShapeKeys[6];
    };

    Potential m_potentials[256];

    void __thiscall AddPotential(unsigned short value);
};
extern int DAT_010d5224;
struct FUN_00dabf10
{
    void* m_pVtbl;
    char m_b0[44];
    int m_i0;
    FUN_00dabf10(int, int, int);
    ~FUN_00dabf10();
};
struct FUN_00dacbd0 : FUN_00dabf10
{
    FUN_00dacbd0(int a, int b, int c);
    ~FUN_00dacbd0();
};
struct hkSlotDACB
{
    unsigned char m_00;
    unsigned char m_01;
    short m_iOwnerObjectOffset;
    int m_04;
};
class hkObjDACB
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    short unk30;
    unsigned char m_numSlots;
    unsigned char unk33;
    hkSlotDACB m_slots[8];

    void ClearSlotById(short id);
};
struct Dvec4
{
    float x, y, z, w;
};
struct __declspec(align(16)) Dsub
{
    Dvec4 v0, v1, v2, v3;
    Dvec4 unk40, unk50;
    void FUN_00cb22f0(Dvec4* pts, Dvec4* other);
};
struct Dtask
{
    void* f00;
    void* f04;
    int f08;
    void* f0c;
    int f10;
    int unk14;
    int unk18;
    int unk1c;
    Dsub sub;
};
struct Dctx
{
    int f0;
    int f1;
    int f2;
    int f3;
};
struct Dsrc
{
    int unk00;
    int unk04;
    Dvec4* f08;
};
struct Drecv
{
    int unk00;
    int unk04;
    int f08;
    int f0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int f20;
    int unk24;
    int unk28;
    int unk2c;
    int f30;

    void FUN_00daccd0(Dsrc* a1, Dsrc* a2, Dsrc* a3, int a4);
};
void ProcessCollision(Dtask* task, int* ctx1, int* ctx2, int* node, int* a5, int* a6, int a7);

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_load_ss(const float*);
    float _mm_cvtss_f32(__m128);
    unsigned __int64 __rdtsc();
    void _ReadWriteBarrier();
    void _mm_store_ss(float*, __m128);
}

typedef unsigned long DWORD;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(DWORD);

extern DWORD DAT_0126835c;
extern const char str_010ceca0[];

struct hkMonitorStreamS
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static hkMonitorStreamS& GetMonitorStream()
    {
        return *(hkMonitorStreamS*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    char* GetStreamEnd()
    {
        return m_kRayEnd;
    }
    void setEnd(char* e)
    {
        m_kRayEnd = e;
    }
};
struct SweepFactors
{
    union
    {
        volatile unsigned int ticks;
        float a;
    };
    union
    {
        volatile unsigned int laterTicks;
        float b;
    };
};
struct CommandTimingEntry
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        m_uiStartTicks = t;
    }
};
struct TimedNameRecord : CommandTimingEntry
{
    const char* m_pFirst;
};

struct hkVector4S
{
    __m128 m_vComponents;
    __forceinline void setSub4(const hkVector4S& a, const hkVector4S& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(float r)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, _mm_set_ps1(r));
    }
    __forceinline void add4(const hkVector4S& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    float& operator()(int i)
    {
        return ((float*)&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return ((const float*)&m_vComponents)[i];
    }
    __forceinline void setMul4(float r, const hkVector4S& a)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, _mm_set_ps1(r));
    }
    __forceinline void addMul4(float r, const hkVector4S& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, _mm_set_ps1(r)));
    }
};

struct hkMotionStateS
{
    __m128 unk00;
    __m128 unk10;
    __m128 unk20;
    __m128 unk30;
    hkVector4S m_vCenterOfMass0;
    hkVector4S m_vCenterOfMass1;
    __m128 unk60;
    __m128 unk70;
    __m128 unk80;
    hkVector4S m_kDeltaAngle;
    float m_fObjectRadius;
};

struct hkCdBodyS
{
    int unk00;
    int unk04;
    hkMotionStateS* m_pMotionState;
};

struct hkInputS
{
    int unk00;
    int unk04;
    float m_fScalar;
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
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

static __forceinline void calcTimInfo(const hkMotionStateS& ms0, const hkMotionStateS& ms1, float deltaTime,
                                      hkVector4S& timInfo, SweepFactors& work)
{
    work.b = deltaTime;
    work.a = work.b * (*(const volatile float*)&(ms0.m_vCenterOfMass1(3)));
    work.b *= ms1.m_vCenterOfMass1(3);
    __m128 r0 = _mm_load_ss(&work.a);
    __m128 s0 = _mm_shuffle_ps(r0, r0, 0);
    timInfo.m_vComponents = (_mm_add_ps(
        (_mm_mul_ps((_mm_sub_ps((ms0.m_vCenterOfMass0.m_vComponents), (ms0.m_vCenterOfMass1.m_vComponents))), s0)),
        (_mm_mul_ps((_mm_shuffle_ps((_mm_load_ss(&work.b)), (_mm_load_ss(&work.b)), 0)),
                    (_mm_sub_ps((ms1.m_vCenterOfMass1.m_vComponents), (ms1.m_vCenterOfMass0.m_vComponents)))))));
    timInfo(3) =
        (*(const volatile float*)&(ms0.m_kDeltaAngle(3))) * work.a * (*(const volatile float*)&(ms0.m_fObjectRadius)) +
        (*(const volatile float*)&(ms1.m_kDeltaAngle(3))) * work.b * (*(const volatile float*)&(ms1.m_fObjectRadius));
}

struct hkGskAgentS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float m_fFloatValue;
    int unk1c;
    hkVector4S m_vSeparatingNormal;
    void __thiscall FUN_00daccd0(const hkCdBodyS& a, const hkCdBodyS& b, const hkInputS& input, void* result);
    void __thiscall FUN_00dacd50(const hkCdBodyS& a, const hkCdBodyS& b, const hkInputS& input, void* result);
};

// @fnv 0x00dacd50
void __thiscall hkGskAgentS::FUN_00dacd50(const hkCdBodyS& a, const hkCdBodyS& b, const hkInputS& input, void* result)
{
    SweepFactors work;
    {
        hkMonitorStreamS& s = hkMonitorStreamS::GetMonitorStream();
        if (s.memoryAvailable())
        {
            TimedNameRecord* h = (TimedNameRecord*)s.GetStreamEnd();
            h->m_pCommandName = "LtGskAgent";
            h->m_pFirst = "StTim";
            _ReadWriteBarrier();
            work.ticks = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            h->m_uiStartTicks = work.ticks;
            s.setEnd((char*)(h + 1));
        }
    }
    if (m_fFloatValue != input.m_uiStartTime)
    {
        hkVector4S timInfo;
        calcTimInfo(*a.m_pMotionState, *b.m_pMotionState, input.m_fTimeStep, timInfo, work);
        if (m_vSeparatingNormal(3) > input.m_fScalar)
        {
            __m128 p = _mm_mul_ps(m_vSeparatingNormal.m_vComponents, timInfo.m_vComponents);
            __m128 w = _mm_shuffle_ps(timInfo.m_vComponents, timInfo.m_vComponents, 0xff);
            __m128 z = _mm_shuffle_ps(p, p, 0xaa);
            __m128 y = _mm_shuffle_ps(p, p, 0x55);
            __m128 d = _mm_add_ps(_mm_add_ss(z, w), _mm_add_ss(y, p));
            _mm_store_ss(&work.b, d);
            m_vSeparatingNormal(3) -= work.b;
            if (m_vSeparatingNormal(3) > input.m_fScalar)
                goto END;
        }
    }
    {
        hkMonitorStreamS& s = hkMonitorStreamS::GetMonitorStream();
        if (s.memoryAvailable())
        {
            CommandTimingEntry* h = (CommandTimingEntry*)s.GetStreamEnd();
            h->m_pCommandName = str_010ceca0;
            _ReadWriteBarrier();
            work.laterTicks = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            h->m_uiStartTicks = work.laterTicks;
            s.setEnd((char*)(h + 1));
        }
    }
    m_fFloatValue = input.m_fEndTime;
    FUN_00daccd0(a, b, input, result);
END: {
    hkMonitorStreamS& s = hkMonitorStreamS::GetMonitorStream();
    if (s.memoryAvailable())
    {
        CommandTimingEntry* h = (CommandTimingEntry*)s.GetStreamEnd();
        h->m_pCommandName = "lt";
        _ReadWriteBarrier();
        work.laterTicks = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_uiStartTicks = work.laterTicks;
        s.setEnd((char*)(h + 1));
    }
}
}

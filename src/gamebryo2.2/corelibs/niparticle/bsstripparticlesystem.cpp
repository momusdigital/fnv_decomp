
// src/gamebryo2.2/corelibs/niparticle/bsstripparticlesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/bsstripparticlesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void* g_01202560;

// @fnv 0x00c257c0
void* __cdecl FUN_00c257c0()
{
    return &g_01202560;
}

struct NiRenderer
{
    void* _vt;
    char _pad0[508];
    int m_iRendererState;
    char _pad1[4];
    bool m_bRendererFlagA;
};
struct FUN_00a80610_shell
{
    void __thiscall FUN_00a80610(NiRenderer*);
    void __thiscall RenderImmediate(NiRenderer*);
};
// @fnv 0x00c25730
void __thiscall FUN_00a80610_shell::RenderImmediate(NiRenderer* apkRenderer)
{
    this->FUN_00a80610(apkRenderer);
    NiRenderer* pkRenderer = apkRenderer;
    if ((pkRenderer->m_iRendererState == 1 || pkRenderer->m_iRendererState == 2) && pkRenderer->m_bRendererFlagA == 1)
        ((void(__thiscall*)(NiRenderer*, FUN_00a80610_shell*))(*(void***)pkRenderer)[112])(pkRenderer, this);
}

struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
char* __cdecl _FUN_00a7d330(void*);
struct BSStripParticleSystem
{
    void WriteParticleSystemInfo(StrArr*);
    void AppendString(StrArr*);
};
// Calls WriteParticleSystemInfo, gets a string from g_01202560, grows pkStrings if its count reached capacity, then stores the string at the current count.
// @fnv 0x00c25770
void BSStripParticleSystem::AppendString(StrArr* pkStrings)
{
    WriteParticleSystemInfo(pkStrings);
    char* s = _FUN_00a7d330(g_01202560);
    unsigned int n = *(unsigned short*)((char*)pkStrings + 0xa);
    if (n >= *(unsigned short*)((char*)pkStrings + 8))
        pkStrings->SetSize(n + *(unsigned short*)((char*)pkStrings + 0xe));
    pkStrings->SetAt(n, s);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);
extern unsigned int UNK_010be35c;
struct ParticleSystem
{
    unsigned int* vtable;
    void __thiscall FUN_00c1b5c0();
};
struct ParticleOwner
{
    void __thiscall FUN_00c1b6f0(ParticleSystem* object, unsigned int flags);
    ParticleSystem* __thiscall CreateParticleSystem(unsigned int flags);
};
// Allocates a 0x110-byte ParticleSystem, initialises it and its vtable, passes it to FUN_00c1b6f0 with flags, and returns it.
// @fnv 0x00c257d0
ParticleSystem* ParticleOwner::CreateParticleSystem(unsigned int flags)
{
    ParticleSystem* object = static_cast<ParticleSystem*>(FUN_00aa13e0(0x110));
    if (object)
    {
        object->FUN_00c1b5c0();
        object->vtable = &UNK_010be35c;
    }
    else
    {
        object = 0;
    }
    this->FUN_00c1b6f0(object, flags);
    return object;
}

void __cdecl RegisterStreamables();
// @fnv 0x00c21940
void __cdecl FUN_00c21940()
{
    RegisterStreamables();
}

struct NiCullingProcess
{
    void* p;
};
struct NiGeometry
{
    void __thiscall OnVisible(NiCullingProcess&);
};
struct FUN_00c256f0_cls : NiGeometry
{
    void __thiscall FUN_00c256f0(NiCullingProcess&);
};
// @fnv 0x00c256f0
void __thiscall FUN_00c256f0_cls::FUN_00c256f0(NiCullingProcess& a)
{
    NiGeometry::OnVisible(a);
}

void __cdecl LoadBinary();
// @fnv 0x00c25700
void __cdecl FUN_00c25700()
{
    LoadBinary();
}

extern "C" void __cdecl LoadModifiers();
// @fnv 0x00c25710
void __cdecl FUN_00c25710()
{
    LoadModifiers();
}

void __cdecl FUN_00c1b400();
// @fnv 0x00c25720
void __cdecl FUN_00c25720()
{
    FUN_00c1b400();
}

extern void FUN_00c1b1d0();

// @fnv 0x00c21950
void FUN_00c21950()
{
    FUN_00c1b1d0();
}


// src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlr_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/niparticle/nipsysemitterctlr.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "nipsysemitterctlr_types_NiPSysEmitterCtlr.h"
#include "nipsysemitterctlr_types_NiStream.h"
#include "nipsysemitterctlr_external.h"
#include <new>
struct NiSingleInterpControllerBase
{
    char pad[0x30];
    NiSingleInterpControllerBase() throw();
    virtual void f();
};
struct FUN_00a38e00 : NiSingleInterpControllerBase
{
    int m34;
    FUN_00a38e00();
};
struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f4054;
void* __cdecl FUN_00a537e0();
struct NiTimeControllerStop
{
    void ResetTiming();
};
struct FUN_00c1ba30 : NiTimeControllerStop
{
    char pad[0x48 - 1];
    float m48;
};
void __fastcall FUN_00c1ba30(FUN_00c1ba30* self, int unused);
extern const char* const g_01203340_arg1;
const char* const* __cdecl FUN_00c1c2f0();
extern int DAT_011ae754;
extern int DAT_011ae758;
const char* const* __stdcall GetInterpolatorID(unsigned short usIndex);
struct NiPSysEmitterCtlr_shell : NiPSysEmitterCtlr
{
    void FUN_00c1bcc0(NiInterpolator* pkInterpolator, unsigned short usIndex);
};

struct GO
{
    operator unsigned int() const;
};

struct NiBlendBoolInterpolator : NiBoolInterpolator
{
    unsigned char FindHighestWeightIndex();
    NiBoolInterpolator* GetValueForIndex(unsigned char index);
};

struct NiPSysEmitterCtlr_StandIn
{
    char pad[0x34];
    GO m34;
    NiBoolInterpolator* FUN_00639b60();
};

void* __cdecl _UseSaveGameBlocks(void* table, unsigned int key);
extern unsigned char DAT_01096968;
extern int g_011f3738;
extern GlobalObjectO2_00a7b610 g_011f3e58;

// @fnv 0x00639b60
NiBoolInterpolator* NiPSysEmitterCtlr_StandIn::FUN_00639b60()
{
    NiBoolInterpolator* pkBoolInterp;
    NiBlendBoolInterpolator* pkBlendInterp;

    pkBoolInterp = reinterpret_cast<NiBoolInterpolator*>(_UseSaveGameBlocks(&g_011f3738, m34.operator unsigned int()));

    if (pkBoolInterp)
        return pkBoolInterp;

    pkBlendInterp =
        reinterpret_cast<NiBlendBoolInterpolator*>(_UseSaveGameBlocks(&g_011f3e58, m34.operator unsigned int()));

    if (pkBlendInterp)
    {
        unsigned char m_ucClipIdentifier = pkBlendInterp->FindHighestWeightIndex();
        if (m_ucClipIdentifier != DAT_01096968)
            return pkBlendInterp->GetValueForIndex(m_ucClipIdentifier);
    }

    return 0;
}

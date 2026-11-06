
// src/gamebryo2.2/corelibs/nimain/nitristripsdata_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/gamebryo2.2/corelibs/nimain/nitristripsdata.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include "nitristripsdata_types_NiTriStripsData.h"
extern "C" const NiRTTI DAT_011f4a70;
extern "C" void* NiMalloc(unsigned int, const char* = 0, int = 0, const char* = 0);
#include "nitristripsdata_forwarders.h"

// @fnv 0x00a75f30
extern "C" const NiRTTI* __cdecl FUN_00a75f30()
{
    return &DAT_011f4a70;
}

class NiTriStripsDataWork : public NiTriStripsData
{
  public:
    void GetStripData(unsigned short& rNumStrips, const unsigned short*& rStripLengths,
                      const unsigned short*& rStripLists, unsigned int& rNumIndices);
};

// @fnv 0x00a75f40
void NiTriStripsDataWork::GetStripData(unsigned short& rNumStrips, const unsigned short*& rStripLengths,
                                       const unsigned short*& rStripLists, unsigned int& rNumIndices)
{
    rNumStrips = m_usStrips;
    rStripLengths = m_pusStripLengths;
    rStripLists = m_pusStripLists;
    rNumIndices = (unsigned int)(unsigned short)(m_usStrips * 2 + m_usTriangles);
}

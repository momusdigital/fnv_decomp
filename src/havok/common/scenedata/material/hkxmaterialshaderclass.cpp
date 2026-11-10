// src/havok/common/scenedata/material/hkxmaterialshaderclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/material/hkxmaterialshaderclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../include/hkMemoryAllocator.h"
#include "../../../../../include/hkMemoryRouter.h"

hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct hkxMaterialShader
{
    unsigned short m_u04;
    unsigned short m_u06;
    hkxMaterialShader();
    virtual ~hkxMaterialShader();
    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        unsigned int uiSize = ((hkxMaterialShader*)apMemory)->m_u04;
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        typedef void (__thiscall* FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
        (*(FreeFunction**)pAllocator)[2](pAllocator, apMemory, uiSize);
    }
};

// Initializes m_u04 and m_u06 to zero.
// @fnv 0x00e02230
// src: EXE 0x00e02230
hkxMaterialShader::hkxMaterialShader()
{
    m_u04 = 0;
    m_u06 = 0;
}

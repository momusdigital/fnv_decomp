// src/havok/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollideclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/raycast/hkpvehicleraycastwheelcollideclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "../../../../../../include/hkMemoryAllocator.h"
#include "../../../../../../include/hkMemoryRouter.h"


hkMemoryRouter* __cdecl hkMemoryRouter_getInstance();

struct hkpVehicleRayCastWheelCollide
{
    unsigned short m_u04;
    unsigned short m_u06;
    hkpVehicleRayCastWheelCollide();
    virtual ~hkpVehicleRayCastWheelCollide();
    static void operator delete(void* apMemory)
    {
        hkMemoryRouter* pHolder = hkMemoryRouter_getInstance();
        unsigned int uiSize = ((hkpVehicleRayCastWheelCollide*)apMemory)->m_u04;
        hkMemoryAllocator* pAllocator = reinterpret_cast<hkMemoryAllocator*>(pHolder->m_heap);
        typedef void (__thiscall *FreeFunction)(hkMemoryAllocator*, void*, unsigned int);
        (*reinterpret_cast<FreeFunction**>(pAllocator))[2](pAllocator, apMemory, uiSize);
    }
};

// Initialises m_u04 and m_u06 to zero for a hkpVehicleRayCastWheelCollide instance.
// @fnv 0x00dfeb10
// src: EXE 0x00dfeb10
hkpVehicleRayCastWheelCollide::hkpVehicleRayCastWheelCollide()
{
    m_u04 = 0;
    m_u06 = 0;
}

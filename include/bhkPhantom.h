#pragma once

#include "bhkWorldObject.h"

class NiTransform;

class bhkPhantom : public bhkWorldObject
{
public:
    virtual ~bhkPhantom();

    void bhkShapePhantom_SetTransform(const NiTransform&); // 0x0056df20
    void bhkShapePhantom_GetPenetrations(void*); // 0x00623150
    void* FUN_00c9f3b0();
    void* ScalarDeletingDestructor(unsigned int flags);
};

#pragma once

#include "BSExtraData.h"

class TrespassPackage;

class ExtraTresPassPackage : public BSExtraData
{
public:
    ExtraTresPassPackage(TrespassPackage* pack);
    virtual ~ExtraTresPassPackage();

    void FUN_00432900();
    void* ScalarDeletingDestructor(unsigned int flags);

    union
    {
        TrespassPackage* package;
        TrespassPackage* pTargetPackage;
    };
};

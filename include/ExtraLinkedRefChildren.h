#pragma once

#include "BSExtraData.h"

class ExtraLinkedRefChildren : public BSExtraData
{
public:
    struct ListX
    {
        ~ListX();
        void RemoveAll();
    };

    virtual ~ExtraLinkedRefChildren();

    void FUN_004335d0();
    void* __thiscall ScalarDeletingDestructor(unsigned int flags);

    ListX items;
};

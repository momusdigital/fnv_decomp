#pragma once

#include "BSExtraData.h"

class ExtraEnableStateChildren : public BSExtraData
{
public:
    struct ChildrenList
    {
        ~ChildrenList();
        void RemoveAll();
    };

    virtual ~ExtraEnableStateChildren();

    void* ScalarDeletingDestructor(unsigned int flags);
    void FUN_00433440();

    ChildrenList list;
};

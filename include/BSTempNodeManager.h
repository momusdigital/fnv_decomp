#pragma once

#include "NiNode.h"

class BSTempNodeManager : public NiNode
{
public:
    virtual ~BSTempNodeManager();
    void* ScalarDeletingDestructor(unsigned int flags);
};

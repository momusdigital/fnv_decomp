#pragma once

#include "IOTask.h"

class AttachDistant3DTask : public IOTask
{
public:
    virtual ~AttachDistant3DTask();

    void* ScalarDeletingDestructor(unsigned int flags);
    void FUN_004406b0();
};

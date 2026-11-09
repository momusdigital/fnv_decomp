#pragma once

#include "BSExtraData.h"
#include "BSAnimNoteReceiver.h"

class ExtraAnimNoteReceiver : public BSExtraData
{
public:
    virtual ~ExtraAnimNoteReceiver();

    ExtraAnimNoteReceiver(void* receiver);
    void FUN_0057a8d0();
    void* ScalarDeletingDestructor(unsigned int flags);

    BSAnimNoteReceiver* m_pReceiver;
};

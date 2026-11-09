#pragma once

#include "BSExtraData.h"

class MediaLocation;

class ExtraAudioMarker : public BSExtraData
{
public:
    virtual ~ExtraAudioMarker();
    virtual bool Compare(BSExtraData*);

    void __local_vftable_ctor_closure();
    void FUN_00431520();
    void* ScalarDeletingDestructor(unsigned int flags);

    union
    {
        int unk0C;
        MediaLocation* pAudioData;
    };
};

#pragma once

#include "BSExtraData.h"
#include "LitWaterRefList.h"

class BSExtraDataEx;
class TESForm;

class ExtraLitWaterRefs : public BSExtraData
{
public:
    virtual ~ExtraLitWaterRefs();
    virtual bool Compare(BSExtraData* apCompare);

    ExtraLitWaterRefs();
    void Copy(BSExtraDataEx* apSource);
    void InitItem_00434050(TESForm* apOwner);
    bool Compare_00434e30(BSExtraData* apCompare);
    void* ScalarDeletingDestructor(unsigned int flags);
    void FUN_00434dc0();

    LitWaterRefList kRefs;
};

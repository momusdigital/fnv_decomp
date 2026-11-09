#pragma once

class BSExtraData
{
public:
    virtual ~BSExtraData();
    virtual bool Compare(BSExtraData* extra);

    BSExtraData(unsigned char type);
    void* __thiscall ScalarDeletingDestructor(unsigned int flags);

    unsigned char type;
    unsigned char unknown05;
    unsigned char unknown06;
    unsigned char unknown07;
    BSExtraData* next;
};

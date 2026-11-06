
// src/havok/physics/dynamics/constraint/chain/hkpconstraintchaininstanceaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/chain/hkpconstraintchaininstanceaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConstraintChainInstanceAction.h"

struct FnvCpu_FUN_00e063e0_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00e063e0_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    FnvCpu_FUN_00e063e0_CpuInterface* target;
    void FUN_00e063e0(int arg0);
};
// @fnv 0x00e063e0
void FnvCpu_FUN_00e063e0_CpuOwner::FUN_00e063e0(int arg0)
{
    target->Invoke(arg0);
}

// @fnv 0x00e063c0
void __stdcall applyAction(int)
{}

// @fnv 0x00e063d0
int __stdcall FUN_00e063d0(int arg0, int arg1)
{
    return 0;
}

struct FnvAllocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* AllocateMemoryBlock(int* bytes);
    virtual void ReleaseBlock(void* ptr, int bytes);
};
struct FnvMemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    FnvAllocator* allocator;
};
extern "C" FnvMemoryRouter* __cdecl FUN_00c85750();
struct FnvEntityArray
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct hkpConstraintChainInstance
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    FnvEntityArray entities;
};
// @fnv 0x00e063f0
void __fastcall CopyEntityArray(hkpConstraintChainInstanceAction* self, void* unusedEdx, FnvEntityArray* output)
{
    FnvEntityArray* source = &self->m_pConstraintChainInstance->entities;
    FnvAllocator* allocator = FUN_00c85750()->allocator;
    int capacity = output->m_iCapacityState & 0x3fffffff;
    if (capacity < source->m_iElementCount)
    {
        if (!(output->m_iCapacityState & 0x80000000))
            allocator->ReleaseBlock(output->m_data, capacity * 4);
        int bytes = source->m_iElementCount * 4;
        output->m_data = (void**)allocator->AllocateMemoryBlock(&bytes);
        output->m_iCapacityState = bytes / 4;
    }
    int count = source->m_iElementCount;
    output->m_iElementCount = count;
    void** dest = output->m_data;
    void** from = source->m_data;
    for (int i = 0; i < count; ++i)
        dest[i] = from[i];
}


// src/fallout_shared/pathfinding/pathingrequestsafestraightline.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestsafestraightline.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct PathingRequestSafeStraightLine
{
    virtual ~PathingRequestSafeStraightLine();
    void* FUN_006e5fd0(unsigned int flags);
};

extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);

// @fnv 0x006e5fd0
void* PathingRequestSafeStraightLine::FUN_006e5fd0(unsigned int flags)
{
    this->PathingRequestSafeStraightLine::~PathingRequestSafeStraightLine();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0xbc);
    return this;
}

struct FUN_006e60c0_shell
{
    void __thiscall FUN_006e60c0(int);
};

// @fnv 0x006e60c0
void __thiscall FUN_006e60c0_shell::FUN_006e60c0(int a1)
{
    *(int*)((char*)this + 0xb8) = *(int*)((char*)this + 0xb8);
}

struct BGSSaveFormBuffer
{
    void SerializeFormData(void*, int);
};
struct Host_006e60e0
{
    void __thiscall FUN_006e5f00(BGSSaveFormBuffer*);
    void __thiscall SaveToBuffer(BGSSaveFormBuffer*);
};
// @fnv 0x006e60e0
void __thiscall Host_006e60e0::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    FUN_006e5f00(apSaveGameBuffer);
    apSaveGameBuffer->SerializeFormData(*(void**)((char*)this + 0xb8), 0);
}

struct BGSLoadFormBuffer
{
    bool ReadFormIdentifier(void*);
};
struct FUN_006e5f50_shell
{
    void __thiscall FUN_006e5f50(BGSLoadFormBuffer*);
};
struct FUN_006e6110_shell : public PathingRequestSafeStraightLine
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};
// Calls the base load routine on buffer, then loads the field at offset 0xb8 from the buffer.
// @fnv 0x006e6110
void FUN_006e6110_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<FUN_006e5f50_shell*>(this)->FUN_006e5f50(buffer);
    buffer->ReadFormIdentifier((char*)this + 0xb8);
}

struct PathingRequest
{
    void CopyTo(PathingRequest*);
};
struct FUN_006e6080_cls
{
    char _pad[0xB8];
    int pTarget;
    void __thiscall FUN_006e6080(PathingRequest* apDest);
};
// @fnv 0x006e6080
void __thiscall FUN_006e6080_cls::FUN_006e6080(PathingRequest* apDest)
{
    PathingRequestSafeStraightLine* pdest = (PathingRequestSafeStraightLine*)apDest;
    ((PathingRequest*)this)->CopyTo((PathingRequest*)pdest);
    ((FUN_006e60c0_shell*)pdest)->FUN_006e60c0(this->pTarget);
}

struct S_004036b0
{
    int FUN_004036b0();
};
struct FUN_006e3fb0_base
{
    FUN_006e3fb0_base(int);
    virtual ~FUN_006e3fb0_base();
};
struct FUN_006e6010 : FUN_006e3fb0_base
{
    char _pad[0xB4];
    int pTarget;
    FUN_006e6010(int ai);
    ~FUN_006e6010();
};
// Constructs the base with ai and stores the result of FUN_004036b0 called on ai into pTarget.
// @fnv 0x006e6010
FUN_006e6010::FUN_006e6010(int ai) : FUN_006e3fb0_base(ai)
{
    pTarget = ((S_004036b0*)(void*)ai)->FUN_004036b0();
}

struct TESForm
{
    virtual ~TESForm();
    static TESForm* GetFormByID(unsigned int);
};
struct TESObjectREFR : TESForm
{
};
struct Holder_006e6140
{
    void __thiscall ResolveReference(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x006e6140
void __thiscall Holder_006e6140::ResolveReference(BGSLoadFormBuffer* apLoadGameBuffer)
{
    *(TESObjectREFR**)((char*)this + 0xb8) = (*(TESObjectREFR**)((char*)this + 0xb8))
                                                 ? dynamic_cast<TESObjectREFR*>(TESForm::GetFormByID(
                                                       (unsigned int)*(TESObjectREFR**)((char*)this + 0xb8)))
                                                 : 0;
}

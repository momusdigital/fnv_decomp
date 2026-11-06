// fallout_shared/bgsmessageicon.cpp: BGSMessageIcon, TESModelTextureSwap, ThisStandIn (11 functions)

#include "bgsmessageicon_decls.h"
// @fnv 0x0047a220
void BGSMessageIcon::ClearComponent()
{
    Icon.Free();
}

// @fnv 0x0048a3d0
TESModelTextureSwap::TESModelTextureSwap()
{
    InitializeComponent();
}

struct FUN_0047a130 : public BaseFormComponent
{
    FUN_0047a130();
    void InitIcon();
    TESIcon Icon;
};
// Constructs the component and calls InitIcon to initialize it.
// @fnv 0x0047a130
FUN_0047a130::FUN_0047a130()
{
    InitIcon();
}

struct TESFile;
struct NiPoint3Stub
{
    float x, y, z;
};
struct TeleportableReference
{
    const NiPoint3Stub& GetPosition();
};
struct TexHelper
{
    static void ReadTextureData(TESTexture*, TESFile*);
};
// @fnv 0x0047a290
void __cdecl FUN_0047a290(TeleportableReference* pObject, TESFile* pFile)
{
    TexHelper::ReadTextureData((TESTexture*)&pObject->GetPosition(), pFile);
}

struct FUN_0047a380_shell : public BGSMessageIcon
{
    void SetMessageIconTextureName(char*);
};

class TESFullName
{
  public:
    void SetFullName(const char*);
};

// @fnv 0x0047a380
void FUN_0047a380_shell::SetMessageIconTextureName(char* apTexture)
{
    reinterpret_cast<TESFullName*>(reinterpret_cast<char*>(this) + 4)->SetFullName(apTexture);
}

struct FUN_0047a1a0 : BaseFormComponent
{
    TESIcon Icon;
    ~FUN_0047a1a0();
};
// @fnv 0x0047a1a0
FUN_0047a1a0::~FUN_0047a1a0()
{
    ((BGSMessageIcon*)this)->ClearComponent();
}

struct FNStub
{
    char const* GetFullName() const;
};
struct BGSTESTexture
{
    unsigned int GetModelLength() const;
};
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};
// @fnv 0x0047a240
void FUN_0047a240_shell::FUN_0047a240(unsigned int a1)
{
    if (((BGSTESTexture*)((char*)this + 4))->GetModelLength())
        FUN_004856f0(a1, (void*)((FNStub*)((char*)this + 4))->GetFullName(),
                     ((BGSTESTexture*)((char*)this + 4))->GetModelLength() + 1);
}

namespace fnv_0047a2b0 {
struct FUN_0047a300_shell
{
    char* GetMessageIconTextureName();
};
struct FUN_0047a380_shell
{
    void SetMessageIconTextureName(char*);
};
struct FUN_0047a2b0_shell
{
    void CopyComponent(BaseFormComponent*);
};
// @fnv 0x0047a2b0
void FUN_0047a2b0_shell::CopyComponent(BaseFormComponent* component)
{
    BGSMessageIcon* msgIcon = dynamic_cast<BGSMessageIcon*>(component);
    if (!msgIcon)
        return;
    ((FUN_0047a380_shell*)this)->SetMessageIconTextureName(((FUN_0047a300_shell*)msgIcon)->GetMessageIconTextureName());
}
}  // namespace fnv_0047a2b0

int _stricmp(const char*, const char*);
struct Caller300
{
    const char* GetMessageIconTextureName();
};
struct ThisStandIn
{
    bool CompareComponent(BaseFormComponent*);
};
// @fnv 0x0047a320
bool ThisStandIn::CompareComponent(BaseFormComponent* apComponent)
{
    BGSMessageIcon* icon = dynamic_cast<BGSMessageIcon*>(apComponent);
    if (!icon)
        return true;
    if (_stricmp(((Caller300*)this)->GetMessageIconTextureName(), ((Caller300*)icon)->GetMessageIconTextureName()))
        return true;
    return false;
}

namespace fnv_0047a300 {
struct FNStub
{
    const char* GetFullName();
};

struct FUN_0047a300_shell : FNStub
{
    const char* GetMessageIconTextureName();
};

// @fnv 0x0047a300
const char* FUN_0047a300_shell::GetMessageIconTextureName()
{
    return reinterpret_cast<FNStub*>(reinterpret_cast<char*>(this) + 4)->GetFullName();
}
}  // namespace fnv_0047a300

// InitIcon - /Od module.
//
// The owning class is FUN_0047a130 : public BaseFormComponent, and BaseFormComponent
// is a 4-byte polymorphic base (its vptr sits at offset 0).  FUN_0047a130 therefore
// holds its TESIcon member at offset 4.
//
// The original body is a virtual call on that member, dispatched through slot 0 of
// the member's vtable, with the member address (this + 4) passed as the callee's
// 'this' pointer in ECX:
//
//   mov  ecx, [ebp-4]      ; this
//   add  ecx, 4            ; &this->Icon
//   mov  eax, [ebp-4]      ; this
//   mov  edx, [eax+4]      ; the member's vptr
//   mov  eax, [edx]        ; vtable slot 0
//   call eax
// @fnv 0x0047a200
void FUN_0047a130::InitIcon()
{
    Icon.Init();
}

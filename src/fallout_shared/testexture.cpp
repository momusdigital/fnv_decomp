// fallout_shared/testexture.cpp: TESTexture, TESEyes, TESSkill (21 functions)

#include "testexture_decls.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

// @fnv 0x0048e340
void TESTexture::InitializeComponent()
{
    if (FullNameComponent.String())
        FullNameComponent.Set(0, 0);
}

// @fnv 0x0048e6c0
void TESTexture::ConvertTexturePath(const char* path, char* output)
{
    TaskQueueInterface::CopyStringToBuffer(output, 0x104, path);
    char* extension = FUN_0040ab30(output, '.');
    if (extension)
    {
        unsigned int prefixLength = extension - output;
        TaskQueueInterface::CopyStringToBuffer(extension, 0x104 - prefixLength, "_sk.dds");
    }
}

// @fnv 0x0048e270
TESTexture::TESTexture() : BaseFormComponent(), FullNameComponent()
{
    InitializeComponent();
}

// Reads the chunk data into a stack buffer, strips a leading backslash, and sets the texture's full name (or clears it when the chunk is empty).
// @fnv 0x0048e3d0
void TESTexture::ReadTextureData(TESTexture* texture, TESFile* file)
{
    if (!file || !texture)
        return;
    if (file->GetChunkSize())
    {
        char* buffer = static_cast<char*>(_alloca(file->GetChunkSize()));
        file->GetChunkData(buffer, 0);
        if (strlen(buffer) && buffer[0] == '\\')
        {
            unsigned int index = 0;
            for (; index < strlen(buffer); ++index)
                buffer[index] = buffer[index + 1];
        }
        reinterpret_cast<TESFullName*>(texture)->SetFullName(buffer);
    }
    else
    {
        reinterpret_cast<TESFullName*>(texture)->SetFullName(0);
    }
}

// Builds the normal-map path by replacing the extension of path with "_n.dds", stores it in result and returns the string.
// @fnv 0x0048e5b0
const char* TESTexture::NormalizeTextureFilePath(BSStringT<char>& result, const char* path)
{
    char* extension = 0;
    {
        char normalPath[260];
        char sourcePath[260];
        if (!path)
            return 0;
        TaskQueueInterface::CopyStringToBuffer(sourcePath, 260, path);
        extension = FUN_0040ab30(sourcePath, '.');
        if (!extension)
            return 0;
        *extension = 0;
        sprintf_s(normalPath, 260, "%s_n.dds", sourcePath);
        result.Set(normalPath, 0);
        return result.String();
    }
}

struct BSS
{
    ~BSS();
};
struct TFH
{
    void InitializeComponent();
};
struct FUN_0048e2e0
{
    virtual void v();
    BSS m;
    ~FUN_0048e2e0();
};
// @fnv 0x0048e2e0
FUN_0048e2e0::~FUN_0048e2e0()
{
    ((TFH*)this)->InitializeComponent();
}

// @fnv 0x0048e3b0
bool __cdecl IsChunkTypeIcon(int aChunk)
{
    if (aChunk == 0x4e4f4349)
        return true;
    return false;
}

// @fnv 0x0048e660
void __cdecl AppendNormalMapSuffix(const char* source, char* dest)
{
    TaskQueueInterface::CopyStringToBuffer(dest, 0x104, source);
    char* dot = FUN_0040ab30(dest, '.');
    if (dot != 0)
    {
        int offset = dot - dest;
        TaskQueueInterface::CopyStringToBuffer(dot, 0x104 - offset, "_n.dds");
    }
}

struct FUN_00487400_shell
{
    const char* __thiscall GetDefaultPath();
};

// @fnv 0x00487400
const char* __thiscall FUN_00487400_shell::GetDefaultPath()
{
    return "Textures";
}

struct FNStub
{
    const char* GetFullName();
};

struct FUN_0048e580_shell : FNStub
{
    const char* __thiscall GetNormalMap(BSStringT<char>& result);
};

// @fnv 0x0048e580
const char* __thiscall FUN_0048e580_shell::GetNormalMap(BSStringT<char>& result)
{
    return TESTexture::NormalizeTextureFilePath(result, this->GetFullName());
}

struct TESTexture_shell
{
    const char* GetDefaultPath();
};
// @fnv 0x0048e720
const char* TESTexture_shell::GetDefaultPath()
{
    return "Textures\\";
}

struct TESEyes
{
    void InitializeData();
};
// @fnv 0x005fc1b0
void TESEyes::InitializeData()
{
    ((char*)this)[0x30] = 0;
}

struct FUN_005fdc30_shell
{
    void InitializeData();
};

// @fnv 0x005fdc30
void FUN_005fdc30_shell::InitializeData()
{
    ((char*)this)[0x48] = 0;
}

struct TESSkill
{
    void ResetData();
    void InitializeData();
};

// @fnv 0x00617e80
void TESSkill::InitializeData()
{
    ResetData();
}

struct FUN_005eac70_shell
{
    void InitializeData();
};

// Clears the bytes at offsets 0x38, 0x39 and 0x3C of this and sets the bytes at 0x3A and 0x3B to 1.
// @fnv 0x005eac70
void FUN_005eac70_shell::InitializeData()
{
    *(unsigned char*)((char*)this + 0x38) = 0;
    *(unsigned char*)((char*)this + 0x39) = 0;
    *(unsigned char*)((char*)this + 0x3A) = 1;
    *(unsigned char*)((char*)this + 0x3B) = 1;
    *(unsigned char*)((char*)this + 0x3C) = 0;
}

struct FUN_00402c40_shell : public TESTexture
{
    void DestroyTexture();
};

// @fnv 0x00402c40
void FUN_00402c40_shell::DestroyTexture()
{
    TESTexture::~TESTexture();
}

struct FUN_00487410_shell
{
    const char* GetLeafTexturePath();
};

// @fnv 0x00487410
const char* FUN_00487410_shell::GetLeafTexturePath()
{
    return "Data\\Textures\\Trees\\Leaves\\";
}

namespace fnv_0048e370 {
struct TESModel
{
    unsigned int GetModelLength() const;
};
struct FNStub
{
    char const* GetFullName();
};
void __cdecl FUN_004856f0(unsigned int, void*, unsigned int);
struct FUN_0048e370_shell
{
    void FUN_0048e370(unsigned int);
};
// If the model length is non-zero, calls FUN_004856f0 with the texture ID, the full name, and the model length plus one.
// @fnv 0x0048e370
void FUN_0048e370_shell::FUN_0048e370(unsigned int aeTextureID)
{
    if (((TESModel*)this)->GetModelLength())
        FUN_004856f0(aeTextureID, (void*)((FNStub*)this)->GetFullName(), ((TESModel*)this)->GetModelLength() + 1);
}
}  // namespace fnv_0048e370

namespace fnv_0048e4a0 {
struct BSStr
{
    bool Set(char const*, unsigned int);
};
struct FNStub
{
    char const* GetFullName(void);
};
struct FUN_0048e4a0_shell
{
    void CopyTextureName(BaseFormComponent* apCopyFC);
};
// Casts apCopyFC to TESTexture; if valid, stores its full name into the BSStr at offset 4 of this.
// @fnv 0x0048e4a0
void FUN_0048e4a0_shell::CopyTextureName(BaseFormComponent* apCopyFC)
{
    TESTexture* pcopy = dynamic_cast<TESTexture*>(apCopyFC);
    if (!pcopy)
        return;
    ((BSStr*)((char*)this + 4))->Set(((FNStub*)pcopy)->GetFullName(), 0);
}
}  // namespace fnv_0048e4a0

namespace fnv_0048e4f0 {
struct FNStub
{
    char* GetFullName();
};
struct TESModel
{
    unsigned int GetModelLength();
};
int __cdecl FUN_00404dc0(const char*, const char*);
struct FUN_0048e4f0_shell : TESModel
{
    bool CompareComponent(BaseFormComponent* apCompareFC);
};
// @fnv 0x0048e4f0
bool FUN_0048e4f0_shell::CompareComponent(BaseFormComponent* apCompareFC)
{
    TESTexture* pcompare = dynamic_cast<TESTexture*>(apCompareFC);
    if (!pcompare)
        return true;
    if (GetModelLength() || ((TESModel*)pcompare)->GetModelLength())
    {
        if (GetModelLength() != ((TESModel*)pcompare)->GetModelLength())
            return true;
        else if (FUN_00404dc0(((FNStub*)this)->GetFullName(), ((FNStub*)pcompare)->GetFullName()))
            return true;
    }
    return false;
}
}  // namespace fnv_0048e4f0

extern char DAT_01183028[];
extern char DAT_01183978[];

struct FUN_00480ef0_obj;

int __cdecl FUN_00ec43fb(FUN_00480ef0_obj* owner, int zero, char* name, char* table, int flags);

struct FUN_00480ef0_sub
{
    int FUN_00408da0();
};

struct FUN_00480ef0_obj
{
    int FUN_00401170();
    int FUN_005f0cc0();
    int FUN_00481230(int value);
    FUN_00480ef0_obj* FUN_00567790();
};

// @fnv 0x00480ef0
int __cdecl GetIcon(FUN_00480ef0_obj* pOwner, int param)
{
    FUN_00480ef0_obj* found = (FUN_00480ef0_obj*)FUN_00ec43fb(pOwner, 0, DAT_01183028, DAT_01183978, 0);
    if (found == 0)
    {
        return 0;
    }
    if (param == 0)
    {
        return ((FUN_00480ef0_sub*)((char*)found + 0x8c))->FUN_00408da0();
    }
    FUN_00480ef0_obj* ref = ((FUN_00480ef0_obj*)param)->FUN_00567790();
    int valueX = 0;
    if (ref != 0 && ref->FUN_00401170() == 0x2a)
    {
        valueX = ref->FUN_005f0cc0();
    }
    return found->FUN_00481230(valueX);
}

// fallout_shared/tescombatstyle.cpp: TESCombatStyle (10 functions)

#include "tescombatstyle_decls.h"
// @fnv 0x00505010
TESCombatStyle::TESCombatStyle()
{
    SetFormType((ENUM_FORM_ID)0x4a);
    ResetFormData();
}
// Copies 0x5c, 0x54 and 0x40 bytes from the combat style returned by GetDefaultCombatStyle into Data and two other members, or zeroes them if none.
// @fnv 0x005050d0
void TESCombatStyle::ResetFormData()
{
    TESCombatStyle* style = GetDefaultCombatStyle();
    if (style)
    {
        memcpy(&Data, &((NiAVObject*)style)->FUN_0043c490(), 0x5c);
        memcpy(&m_kUInt32ChunkData, ((CombatStyleAccess*)style)->FUN_006ab360(), 0x54);
        memcpy(&m_kUnsignedIntArray16, ((BGSHungerStage*)style)->FUN_00500940(), 0x40);
    }
    else
    {
        memset(&Data, 0, 0x5c);
        memset(&m_kUInt32ChunkData, 0, 0x54);
        memset(&m_kUnsignedIntArray16, 0, 0x40);
    }
}
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
// Reads a combat style record from the file, loading its editor ID, OBND, and CSDT/CSAD/CSSD chunks, then applies version-dependent defaults.
// @fnv 0x00505180
bool TESCombatStyle::Load(TESFile* file)
{
    unsigned char type = file->GetTESForm();
    if (type != 0x4a)
        return false;
    ClearData();
    LoadRecordHeader(file);
    SetInitializationState(false);
    int chunk;
    while (chunk = file->GetChunkID())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* name = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(name, 0x200);
            SetEditorID_AtRuntime(name);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x44545343:
            file->GetChunkData(&Data, 0x5c);
            if (((TESFileExtra*)file)->FUN_00401680())
                Data.SwapEndianFields();
            break;
        case 0x44415343:
            file->GetChunkData(&m_kUInt32ChunkData, 0x54);
            if (((TESFileExtra*)file)->FUN_00401680())
                m_kUInt32ChunkData.FUN_005057a0();
            break;
        case 0x44535343:
            file->GetChunkData(&m_kUnsignedIntArray16, 0x40);
            if (((TESFileExtra*)file)->FUN_00401680())
            {
                UnsignedIntArray16 saved;
                unsigned int size = file->GetChunkSize();
                if (size < 0x40)
                    memcpy(&saved, &m_kUnsignedIntArray16, 0x40);
                m_kUnsignedIntArray16.FUN_00505610();
                if (size < 0x40)
                    memcpy((char*)&m_kUnsignedIntArray16 + size, (char*)&saved + size, 0x40 - size);
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (((TESFileFormVersion*)file)->GetFormVersion() < 12)
    {
        ((float*)&m_kUnsignedIntArray16)[8] = 1.0f;
        ((float*)&m_kUnsignedIntArray16)[11] = 1.0f;
    }
    return true;
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

class TESForm;
class TESCombatStyle;

struct FUN_00505550_shell
{
    bool FUN_00485270(TESCombatStyle*);
    bool IsCombatStyleDifferent(TESForm* apCompare);
};

// @fnv 0x00505550
bool FUN_00505550_shell::IsCombatStyleDifferent(TESForm* apCompare)
{
    TESCombatStyle* pcomp = dynamic_cast<TESCombatStyle*>(apCompare);
    if (!pcomp)
        return true;
    if (FUN_00485270(pcomp))
        return true;
    if (memcmp(&((NiAVObject*)this)->FUN_0043c490(), &((NiAVObject*)pcomp)->FUN_0043c490(), 0x5c))
        return true;
    if (memcmp(((CombatStyleAccess*)this)->FUN_006ab360(), ((CombatStyleAccess*)pcomp)->FUN_006ab360(), 0x54))
        return true;
    if (memcmp(((BGSHungerStage*)this)->FUN_00500940(), ((BGSHungerStage*)pcomp)->FUN_00500940(), 0x40))
        return true;
    return false;
}

struct FUN_00505080_shell
{
    void FUN_005050b0();
    void* FUN_00505080(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_005050b0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00505080
void* FUN_00505080_shell::FUN_00505080(unsigned int flags)
{
    FUN_005050b0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

bool __cdecl FUN_00401500();
struct FUN_00485680_shell
{
    void M();
};
void __cdecl AppendChunk(unsigned int, void*, unsigned int);

struct FUN_004855a0_shell
{
    void M();
};

struct FUN_005053c0_shell : FUN_004855a0_shell
{
    void FUN_005053c0();
};

// @fnv 0x005053c0
void __thiscall FUN_005053c0_shell::FUN_005053c0()
{
    M();
    if (FUN_00401500())
        ((StatsChunkData*)((char*)this + 0x58))->SwapEndianFields();
    AppendChunk(0x44545343, (char*)this + 0x58, 0x5c);
    if (FUN_00401500())
        ((StatsChunkData*)((char*)this + 0x58))->SwapEndianFields();
    if (FUN_00401500())
        ((UInt32ChunkData*)((char*)this + 0xb4))->FUN_005057a0();
    AppendChunk(0x44415343, (char*)this + 0xb4, 0x54);
    if (FUN_00401500())
        ((UInt32ChunkData*)((char*)this + 0xb4))->FUN_005057a0();
    if (FUN_00401500())
        ((UnsignedIntArray16*)((char*)this + 0x18))->FUN_00505610();
    AppendChunk(0x44535343, (char*)this + 0x18, 0x40);
    if (FUN_00401500())
        ((UnsignedIntArray16*)((char*)this + 0x18))->FUN_00505610();
    ((FUN_00485680_shell*)this)->M();
}

void __memcpy(void* __dst, const void* __src, unsigned int __n);

struct FUN_005054b0_shell : public NiAVObject
{
    void FUN_004851b0(TESForm* apCopy);
    void CopyFromCombatStyle(TESForm* apCopy);
};

// Casts apCopy to TESCombatStyle, calls FUN_004851b0, then memcpy's three sub-objects (0x5c, 0x54, 0x40 bytes) from the copy into this.
// @fnv 0x005054b0
void FUN_005054b0_shell::CopyFromCombatStyle(TESForm* apCopy)
{
    TESForm* pcopy = dynamic_cast<TESForm*>(dynamic_cast<TESCombatStyle*>(apCopy));
    if (!pcopy)
        return;
    FUN_004851b0(pcopy);
    __memcpy(&FUN_0043c490(), &reinterpret_cast<NiAVObject*>(pcopy)->FUN_0043c490(), 0x5c);
    __memcpy(reinterpret_cast<CombatStyleAccess*>(this)->FUN_006ab360(),
             reinterpret_cast<CombatStyleAccess*>(pcopy)->FUN_006ab360(), 0x54);
    __memcpy(reinterpret_cast<BGSHungerStage*>(this)->FUN_00500940(),
             reinterpret_cast<BGSHungerStage*>(pcopy)->FUN_00500940(), 0x40);
}

template <int N> struct EndianSizeTag
{
};

typedef EndianSizeTag<0> BSIntToType0;

void __cdecl BSEndian(unsigned char*, BSIntToType0);

struct FUN_005057a0_shell
{
    void FUN_005057a0();
};

// @fnv 0x005057a0
void FUN_005057a0_shell::FUN_005057a0()
{
    BSEndian((unsigned char*)this + 0x00, BSIntToType0());
    BSEndian((unsigned char*)this + 0x04, BSIntToType0());
    BSEndian((unsigned char*)this + 0x08, BSIntToType0());
    BSEndian((unsigned char*)this + 0x0C, BSIntToType0());
    BSEndian((unsigned char*)this + 0x10, BSIntToType0());
    BSEndian((unsigned char*)this + 0x14, BSIntToType0());
    BSEndian((unsigned char*)this + 0x18, BSIntToType0());
    BSEndian((unsigned char*)this + 0x1C, BSIntToType0());
    BSEndian((unsigned char*)this + 0x20, BSIntToType0());
    BSEndian((unsigned char*)this + 0x24, BSIntToType0());
    BSEndian((unsigned char*)this + 0x28, BSIntToType0());
    BSEndian((unsigned char*)this + 0x2C, BSIntToType0());
    BSEndian((unsigned char*)this + 0x30, BSIntToType0());
    BSEndian((unsigned char*)this + 0x34, BSIntToType0());
    BSEndian((unsigned char*)this + 0x38, BSIntToType0());
    BSEndian((unsigned char*)this + 0x3C, BSIntToType0());
    BSEndian((unsigned char*)this + 0x40, BSIntToType0());
    BSEndian((unsigned char*)this + 0x48, BSIntToType0());
    BSEndian((unsigned char*)this + 0x44, BSIntToType0());
    BSEndian((unsigned char*)this + 0x4C, BSIntToType0());
    BSEndian((unsigned char*)this + 0x50, BSIntToType0());
}

namespace fnv_005059c0 {
template <int N> struct EndianSizeTag
{
    unsigned char value;
};

void __cdecl BSEndian(unsigned char*, EndianSizeTag<9>);

struct FUN_005059c0_shell
{
    void* vptr;

    void SwapEndianFields();
};

// @fnv 0x005059c0
void FUN_005059c0_shell::SwapEndianFields()
{
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x04, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x08, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x0c, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x10, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x14, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x18, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x1c, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x20, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x28, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x2c, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x30, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x38, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x3c, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x48, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x4c, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x58, EndianSizeTag<9>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 0x50, EndianSizeTag<9>());
}
}  // namespace fnv_005059c0

void __cdecl BSEndianUInt(unsigned int* apData, BSIntToType0);

// Byte-swaps each of the 15 data words in place via BSEndianUInt.
// @fnv 0x00505610
void UnsignedIntArray16::FUN_00505610()
{
    BSEndianUInt(&data[0], BSIntToType0());
    BSEndianUInt(&data[1], BSIntToType0());
    BSEndianUInt(&data[2], BSIntToType0());
    BSEndianUInt(&data[3], BSIntToType0());
    BSEndianUInt(&data[4], BSIntToType0());
    BSEndianUInt(&data[5], BSIntToType0());
    BSEndianUInt(&data[6], BSIntToType0());
    BSEndianUInt(&data[7], BSIntToType0());
    BSEndianUInt(&data[8], BSIntToType0());
    BSEndianUInt(&data[11], BSIntToType0());
    BSEndianUInt(&data[9], BSIntToType0());
    BSEndianUInt(&data[12], BSIntToType0());
    BSEndianUInt(&data[13], BSIntToType0());
    BSEndianUInt(&data[14], BSIntToType0());
    BSEndianUInt(&data[15], BSIntToType0());
}

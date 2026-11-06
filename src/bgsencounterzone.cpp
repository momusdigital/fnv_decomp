// bgsencounterzone.cpp: BGSEncounterZone, TESObjectREFR, ZoneComparison, EncounterZoneCopy (24 functions)

#include "bgsencounterzone_decls.h"
extern "C" void* __cdecl memset(void*, int, unsigned int);

// Sets the form type to 0x61 and then runs the constructor's initialization routine.
// @fnv 0x00525c40
BGSEncounterZone::BGSEncounterZone()
{
    SetFormType((ENUM_FORM_ID)0x61);
    ResetFormData();
}

// Clears the Data and GameData members by zeroing their memory.
// @fnv 0x00525d00
void BGSEncounterZone::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
    memset(&GameData, 0, sizeof(GameData));
}

#include "bgsencounterzone_TESFile.h"
#include <malloc.h>
void* __cdecl operator new(unsigned int);
class DataHandler
{
  public:
    bool DoAddForm(TESForm*);
};
extern DataHandler* g_dataHandler;
int __cdecl Warning(const char*, ...);

// Creates the NoZoneZone BGSEncounterZone once, sets its ref ID and editor ID, and adds it to the data handler.
// @fnv 0x00526340
void BGSEncounterZone::CreateDefaultEncounterZone()
{
    if (!ms_pDefaultEncounterZone)
    {
        ms_pDefaultEncounterZone = new BGSEncounterZone;
        ms_pDefaultEncounterZone->SetRefID(0x1e, true);
        ms_pDefaultEncounterZone->SetEditorID_AtRuntime("NoZoneZone");
        g_dataHandler->DoAddForm(ms_pDefaultEncounterZone);
    }
}

// Reads an encounter zone record from file: checks form type 0x61, loads the header, then handles EDID, OBND and DATA chunks.
// @fnv 0x00525d40
bool BGSEncounterZone::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x61)
        return false;
    LoadRecordHeader(file);
    SetInitializationState(false);
    unsigned int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            file->GetChunkData(&Data, sizeof(Data));
            if (file->GetChunkData())
                Data.Endian();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Resolves the encounter zone's owner form ID to a TESForm pointer, warns if it is missing, then marks the zone initialized.
// @fnv 0x00525f00
void BGSEncounterZone::InitItem()
{
    if (GetInitialized())
        return;
    if (Data.m_pOwnerForm)
    {
        struct OwnerResolution
        {
            unsigned int formID;
            TESForm* owner;
        } ownerResolution;
        ownerResolution.formID = (unsigned int)Data.m_pOwnerForm;
        RemapFormIDForFile(ownerResolution.formID, GetFile(-1));
        ownerResolution.owner = GetFormByID(ownerResolution.formID);
        if (!ownerResolution.owner)
            Warning("Unable to find owner form (%08X) on encounter zone '%s' (%08X).", ownerResolution.formID,
                    GetName(), GetFormID());
        Data.m_pOwnerForm = ownerResolution.owner;
    }
    SetInitializationState(true);
}

// API-only declarations: layouts are not used by this member.
class ExtraDataList
{
  public:
    BGSEncounterZone* FindEncounterZone() const;
};
class TESWorldSpace
{
  public:
    BGSEncounterZone* FindEncounterZone() const;
};
class TESObjectREFR
{
  public:
    ExtraDataList* GetExtraData();
    TESObjectCELL* GetParentCell();
    TESWorldSpace* GetParentWorldSpace();
    BGSEncounterZone* FindEncounterZone();
};

// Returns the encounter zone from the extra data list, falling back to the parent cell's and then the worldspace's encounter zone.
// @fnv 0x00567d20
BGSEncounterZone* TESObjectREFR::FindEncounterZone()
{
    BGSEncounterZone* zone = GetExtraData()->FindEncounterZone();
    if (!zone)
    {
        if (GetParentCell())
            zone = GetParentCell()->FindEncounterZone();
        if (!zone)
        {
            if (GetParentWorldSpace())
                zone = GetParentWorldSpace()->FindEncounterZone();
        }
    }
    return zone;
}

class Actor
{
  public:
    unsigned short GetLevel();
};
class PlayerCharacter : public Actor
{
};
extern PlayerCharacter* g_thePlayer;
union SETTING_VALUE
{
    float f;
};
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting36;

// @fnv 0x00526190
unsigned short BGSEncounterZone::GetCalculatedLevel()
{
    unsigned short level = g_thePlayer->GetLevel();
    if (level < GetByteAt1D())
    {
        if (!QMatchPCBelowMin())
            level = GetByteAt1D();
    }
    else
    {
        level = (unsigned short)(GetByteAt1D() + (level - GetByteAt1D()) * originalRuntimeFloatSetting36.Float()->f);
    }
    return level;
}

// @fnv 0x00526250
bool BGSEncounterZone::QMatchPCBelowMin()
{
    return (bool)(Data.cFlags & 2);
}

struct FUN_00525cb0_shell
{
    void FUN_00525ce0();
    FUN_00525cb0_shell* Destroy(unsigned int flags);
};
// Calls FUN_00525ce0, deletes this when bit 0 of flags is set, and returns this.
// @fnv 0x00525cb0
FUN_00525cb0_shell* FUN_00525cb0_shell::Destroy(unsigned int flags)
{
    FUN_00525ce0();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_00525ce0 : Base5a
{
    virtual ~FUN_00525ce0();
};
// @fnv 0x00525ce0
FUN_00525ce0::~FUN_00525ce0()
{}

struct S004855a0
{
    void FUN_004855a0();
};
struct S00485680
{
    void FUN_00485680();
};
bool __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int, void*, unsigned int);
struct FUN_00525e70 : BGSEncounterZone
{
    void Save();
};
// @fnv 0x00525e70
void FUN_00525e70::Save()
{
    TESForm* powner;
    reinterpret_cast<S004855a0*>(this)->FUN_004855a0();
    powner = *(TESForm**)((char*)this + 0x18);
    if (powner)
    {
        *(unsigned int*)((char*)this + 0x18) = powner->GetFormID();
    }
    if (FUN_00401500())
        Data.Endian();
    AppendChunk(0x41544144, &Data, 8);
    if (FUN_00401500())
        Data.Endian();
    *(TESForm**)((char*)this + 0x18) = powner;
    reinterpret_cast<S00485680*>(this)->FUN_00485680();
}

struct FUN_00526070_shell
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned int f);
    void SetDetachTime(unsigned int arg);
};
// @fnv 0x00526070
void FUN_00526070_shell::SetDetachTime(unsigned int arg)
{
    *(unsigned int*)((char*)this + 0x20) = arg;
    v18(0x80000000);
}

unsigned int __cdecl GetHoursToRespawnCell();
struct FUN_005260a0_shell
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned int f);
    void SetAttachTime(unsigned int arg);
};
// @fnv 0x005260a0
void FUN_005260a0_shell::SetAttachTime(unsigned int uiValue)
{
    *(unsigned int*)((char*)this + 0x24) = uiValue;
    if (*(unsigned int*)((char*)this + 0x20) != 0)
    {
        if (*(unsigned int*)((char*)this + 0x24) - *(unsigned int*)((char*)this + 0x20) > GetHoursToRespawnCell())
            *(unsigned int*)((char*)this + 0x28) = uiValue;
    }
    v18(0x80000000);
}

namespace fnv_00526100 {
struct GlobalObject2_0040c150
{
    int* Int();
};

GlobalObject2_0040c150 g_011ca160;

// @fnv 0x00526100
int __cdecl GetHoursToRespawnCell()
{
    return *g_011ca160.Int();
}
}  // namespace fnv_00526100

struct FUN_00546af0_shell
{
    unsigned int FUN_00546af0();
};
struct FUN_00526120_shell
{
    bool FUN_00526120(FUN_00546af0_shell* other);
};
// Returns false if the value at offset 0x28 is zero, otherwise returns whether other's FUN_00546af0() result is below that value.
// @fnv 0x00526120
bool FUN_00526120_shell::FUN_00526120(FUN_00546af0_shell* other)
{
    if (*(unsigned int*)((char*)this + 0x28) == 0)
        return false;
    unsigned int v = other->FUN_00546af0();
    if (v < *(unsigned int*)((char*)this + 0x28))
        return true;
    return false;
}

struct FUN_00526160_shell
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned int f);
    void SetZoneLevel(unsigned short arg);
};
// @fnv 0x00526160
void FUN_00526160_shell::SetZoneLevel(unsigned short arg)
{
    *(unsigned short*)((char*)this + 0x2c) = arg;
    v18(0x80000000);
}

struct FUN_00526160_s
{
    void SetZoneLevel(unsigned short a);
};
struct FUN_00526270_shell : BGSEncounterZone
{
    void DetermineLevel();
};
// @fnv 0x00526270
void FUN_00526270_shell::DetermineLevel()
{
    if (*(unsigned short*)((char*)this + 0x2c) == 0)
        reinterpret_cast<FUN_00526160_s*>(this)->SetZoneLevel(GetCalculatedLevel());
}

struct Zone81
{
    bool QNeverReset();
};
struct TESObject
{
    unsigned int GetNext();
};
struct Calendar
{
    unsigned int GetGameHoursPassed();
};
extern Calendar g_calendar;
unsigned int __cdecl GetHoursToRespawnCell();
// @fnv 0x005262a0
bool __fastcall ShouldReset(BGSEncounterZone* apZone)
{
    bool result = true;
    if (apZone != BGSEncounterZone::ms_pDefaultEncounterZone && *(unsigned short*)((char*)apZone + 0x2c))
    {
        if (reinterpret_cast<Zone81*>(apZone)->QNeverReset())
        {
            result = false;
        }
        else
        {
            unsigned int next = reinterpret_cast<TESObject*>(apZone)->GetNext();
            if (next)
            {
                unsigned int now = g_calendar.GetGameHoursPassed();
                if (now - next <= GetHoursToRespawnCell())
                    result = false;
            }
            else
            {
                result = false;
            }
        }
    }
    return result;
}

struct FUN_00526320_shell
{
    bool QNeverReset();
};
// @fnv 0x00526320
bool FUN_00526320_shell::QNeverReset()
{
    return (*(signed char*)((char*)this + 0x1e) & 1) ? true : false;
}

struct FormChangeMask
{
    unsigned int f;
    FormChangeMask();
    operator bool() const;
};
struct BGSSaveFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
    void FUN_00865e50(void*, unsigned int, int);
};
struct S00484d60
{
    void SaveIfChanged(BGSSaveFormBuffer*);
};
struct FUN_00526410 : BGSEncounterZone
{
    void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
};
// @fnv 0x00526410
void FUN_00526410::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned char ctempFlags;
    reinterpret_cast<S00484d60*>(this)->SaveIfChanged(apSaveGameBuffer);
    if (apSaveGameBuffer->GetChangeFlags(2))
    {
        ctempFlags = *(signed char*)((char*)this + 0x1e) & 1;
        apSaveGameBuffer->FUN_00865e50(&ctempFlags, 1, 0);
    }
    if (apSaveGameBuffer->GetChangeFlags(0x80000000))
    {
        apSaveGameBuffer->FUN_00865e50((char*)this + 0x20, 0x10, 0);
    }
}

namespace fnv_00526570 {
struct FormChangeMask
{
    unsigned int flags;
    FormChangeMask();
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetOldChangeFlags(unsigned int f);
};
struct FUN_00526570_shell : BGSEncounterZone
{
    void RevertAndClearIfChanged(BGSLoadFormBuffer* buf);
};
// @fnv 0x00526570
void FUN_00526570_shell::RevertAndClearIfChanged(BGSLoadFormBuffer* pLoadBuffer)
{
    TESForm::Revert(reinterpret_cast<unsigned int>(pLoadBuffer));
    if (pLoadBuffer->GetOldChangeFlags(0x80000000))
        memset((char*)this + 0x20, 0, 0x10);
}
}  // namespace fnv_00526570

struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
    FormChangeMask GetChangeFlags(unsigned int);
    void ReadTypedData(void*, unsigned int);
};

struct FUN_005264a0_shell : public BGSEncounterZone
{
    void FUN_005264a0(BGSLoadFormBuffer* apLoadGameBuffer);
};

// Loads the encounter zone from the buffer, reading a flag byte and, for version 8+, a 16-byte field at offset 0x20.
// @fnv 0x005264a0
void FUN_005264a0_shell::FUN_005264a0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned char ctempFlags;

    TESForm::LoadGame(apLoadGameBuffer);

    if (apLoadGameBuffer->GetChangeFlags(2))
    {
        ctempFlags = 0;
        apLoadGameBuffer->ReadTypedData(&ctempFlags, 1);
        *(char*)((char*)this + 0x1e) = (*(char*)((char*)this + 0x1e) & ~1) | (*(char*)((char*)this + 0x1e) & 1);
    }

    if (apLoadGameBuffer->GetChangeFlags(0x80000000))
    {
        if (apLoadGameBuffer->GetVersion() >= 8)
        {
            apLoadGameBuffer->ReadTypedData((char*)this + 0x20, 0x10);
        }
        else
        {
            char acTempData[8];
            apLoadGameBuffer->ReadTypedData(acTempData, 8);
        }
    }
}

extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
struct ZoneBaseComparison
{
    bool FUN_00485270(TESForm*);
};
struct ZoneComparison : BGSEncounterZone
{
    bool FUN_00526000(TESForm* other);
};
// Returns true when other is not a BGSEncounterZone, the base comparison returns true, or the Data bytes differ.
// @fnv 0x00526000
bool ZoneComparison::FUN_00526000(TESForm* other)
{
    BGSEncounterZone* zone = dynamic_cast<BGSEncounterZone*>(other);
    if (!zone)
        return true;
    if (reinterpret_cast<ZoneBaseComparison*>(this)->FUN_00485270(zone))
        return true;
    if (memcmp(&Data, &zone->Data, sizeof(Data)))
        return true;
    return false;
}

void* __cdecl _memcpy(void*, const void*, unsigned int);

struct FormComponentCopy
{
    void FUN_004851b0(TESForm* source);
};

struct EncounterZoneCopy : BGSEncounterZone
{
    void FUN_00525fa0(TESForm* source);
};

// Copies encounter zone data from another BGSEncounterZone into this instance via FormComponentCopy and a raw memcpy of Data.
// @fnv 0x00525fa0
void EncounterZoneCopy::FUN_00525fa0(TESForm* source)
{
    BGSEncounterZone* other = dynamic_cast<BGSEncounterZone*>(source);
    if (!other)
        return;
    reinterpret_cast<FormComponentCopy*>(this)->FUN_004851b0(other);
    _memcpy(&Data, &other->Data, sizeof(Data));
}

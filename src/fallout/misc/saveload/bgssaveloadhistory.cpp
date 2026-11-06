// fallout/misc/saveload/bgssaveloadhistory.cpp: SaveLoadChangeHistory (12 functions)

#include "bgssaveloadhistory_types_BGSSaveLoadHistory.h"
#include "bgssaveloadhistory_types_CombatTargetMap.h"
#include "bgssaveloadhistory_types_TaskQueueInterface.h"
#include "bgssaveloadhistory_decls.h"
#include <stdarg.h>
#include <new>

// Calls FUN_009a4250 on the map stored at this object's first pointer with history and returns whether it succeeded.
// @fnv 0x0084aad0
bool SaveLoadChangeHistory::MatchesHistory(SaveLoadChangeHistory* history)
{
    if (reinterpret_cast<BGSSaveLoadChangesMap*>(*reinterpret_cast<void**>(this))
            ->FUN_009a4250(reinterpret_cast<unsigned int>(history)))
        return true;
    return false;
}

// @fnv 0x0084dff0
void SaveLoadChangeHistory::AddNote(const char* format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    AddNoteWithArguments(format, arguments);
    va_end(arguments);
}

// Clears the field at offset 0xd68 and removes all entries from the BSSimpleList at offset 0x5fc.
// @fnv 0x00848e10
void SaveLoadChangeHistory::Init()
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xd68) = 0;
    reinterpret_cast<BSSimpleList<ActorCause*>*>(reinterpret_cast<char*>(this) + 0x5fc)->RemoveAll();
}

// Calls LoadSavedFormRange twice, with (0, 12) and (1000, 1001), passing flags through to each call.
// @fnv 0x0084c270
void BGSSaveLoadHistory_Destroy(unsigned char flags)
{
    LoadSavedFormRange(0, 12, flags);
    LoadSavedFormRange(1000, 1001, flags);
}

// @fnv 0x0084e020
void SaveLoadChangeHistory::AddNoteWithArguments(const char* format, char* arguments)
{
    BGSSaveLoadHistoryNoteLocals locals;
    int length;
    if (!*reinterpret_cast<unsigned char*>(reinterpret_cast<SettingT<INISettingCollection>*>(0x11de0a4)->Bool()))
        return;
    length = FUN_00407000(locals.buffer, format, arguments);
    if (length > 0)
    {
        locals.allocation = static_cast<char*>(::operator new(length + 1));
        locals.note = locals.allocation;
        TaskQueueInterface::CopyStringToBuffer(locals.note, length + 1, locals.buffer);
        reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&Notes)->Add(reinterpret_cast<NavMeshInfo*&>(locals.note));
    }
}

// Reads a count and that many strings from a BGSLoadGameBuffer and appends each to the Notes array.
// @fnv 0x0084e190
void SaveLoadChangeHistory::Load(SaveLoadFile* file)
{
    BGSLoadGameBuffer buffer;
    buffer.ReadAndVerifySize(file);
    {
        BGSLoadGameBuffer* pBuffer = &buffer;
        {
            unsigned int count = 0;
            pBuffer->ReadTypedData(&count, 4);
            for (unsigned int i = 0; i < count; i++)
            {
                char* note = pBuffer->LoadString(0);
                reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&Notes)->Add(
                    reinterpret_cast<NavMeshInfo*&>(note));
            }
        }
    }
}

struct HArr
{
    HArr();
    ~HArr();
    void GrowCapacity(unsigned int);
};
struct FUN_0084ded0 : public HArr
{
    FUN_0084ded0();
};
// @fnv 0x0084ded0
FUN_0084ded0::FUN_0084ded0()
{
    GrowCapacity(0x40);
}

struct FUN_0084e2c0_shell : public SaveLoadChangeHistory
{
    void AddAllNotes(SaveLoadChangeHistory*);
};

struct HH84
{
    unsigned int GetReferenceFlags();
    const char* GetArrayElement(unsigned int);
};
// Iterates over the history's entry count, retrieves each string by index and passes it to AddNote.
// @fnv 0x0084e2c0
void FUN_0084e2c0_shell::AddAllNotes(SaveLoadChangeHistory* apHistory)
{
    unsigned int icount = reinterpret_cast<HH84*>(apHistory)->GetReferenceFlags();
    for (unsigned int i = 0; i < icount; i++)
    {
        const char* pNote = reinterpret_cast<HH84*>(apHistory)->GetArrayElement(i);
        AddNote(pNote);
    }
}

extern int _data_011c16bc;
struct FUN_00822630
{
    ~FUN_00822630();
};
struct FUN_0084df30 : FUN_00822630
{
    void DeleteAllElements();
    ~FUN_0084df30();
};
// @fnv 0x0084df30
FUN_0084df30::~FUN_0084df30()
{
    DeleteAllElements();
}

struct ArrSI
{
    unsigned int GetFlags();
};
struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};
struct FUN_0084df90_shell : ArrSI
{
    unsigned int& GetAt(int);
    void DeleteAllElements();
};
// Deletes each element returned by GetAt up to GetFlags, then resets the container size to 0.
// @fnv 0x0084df90
void FUN_0084df90_shell::DeleteAllElements()
{
    for (unsigned int i = 0; i < GetFlags(); i++)
        delete reinterpret_cast<void*>(GetAt(i));
    reinterpret_cast<_Mem_20a4*>(this)->SetSize(0, false);
}

struct FUN_0084e250_shell
{
    int GetReferenceFlags();
    unsigned int& GetAt(int);
    void UpdateEntryValue(unsigned int, unsigned int);
    void DeleteItemsFrom(unsigned int count);
};

void __cdecl operator delete(void*);

// @fnv 0x0084e250
void FUN_0084e250_shell::DeleteItemsFrom(unsigned int uiStartIndex)
{
    int size = GetReferenceFlags();
    if (uiStartIndex >= (unsigned int)size)
        return;
    for (unsigned int i = uiStartIndex; i < (unsigned int)size; ++i)
    {
        void* item = (void*)GetAt(i);
        operator delete(item);
    }
    UpdateEntryValue(uiStartIndex, (unsigned int)size - uiStartIndex);
}

class NavMeshInfo84E;
class SaveTarget84E;

class BGSSaveGameBuffer84E
{
  public:
    BGSSaveGameBuffer84E();
    ~BGSSaveGameBuffer84E();
    void SaveData(void* pvData, int iSize, int iUnk);
    void SaveNavMeshInfo(NavMeshInfo84E* pkInfo, int iUnk);
    void WriteTo(SaveTarget84E* pkTarget);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class NavMeshInfoArray84E
{
  public:
    unsigned int GetSize();
    NavMeshInfo84E*& GetAt(int iIndex);
    void SaveTo(SaveTarget84E* pkTarget);
};

// Saves the array size and each NavMeshInfo element into a BGSSaveGameBuffer, then writes the buffer to pkTarget.
// @fnv 0x0084e0d0
void NavMeshInfoArray84E::SaveTo(SaveTarget84E* pkTarget)
{
    BGSSaveGameBuffer84E kBuffer;
    BGSSaveGameBuffer84E* pkBuffer6 = &kBuffer;

    unsigned int ItemUpdateArray = GetSize();
    pkBuffer6->SaveData(&ItemUpdateArray, 4, 0);
    for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; uiIndex++)
    {
        NavMeshInfo84E* pkInfo = GetAt(uiIndex);
        pkBuffer6->SaveNavMeshInfo(pkInfo, 0);
    }

    kBuffer.WriteTo(pkTarget);
}

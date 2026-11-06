// fallout/misc/saveload/bgssaveloadhistory_decls.h: declares BGSSaveLoadHistoryNoteLocals, BGSSaveLoadChangesMap, BGSLoadFormBuffer, BGSLoadGameBuffer
#ifndef BGSSAVELOADHISTORY_DECLS_H
#define BGSSAVELOADHISTORY_DECLS_H


void LoadSavedFormRange(unsigned int first, unsigned int second, unsigned char flags);
int FUN_00407000(char* buffer, const char* format, char* arguments);

class INISettingCollection;
template <> class SettingT<INISettingCollection>
{
  public:
    SETTING_VALUE* Bool();
};

class NavMeshInfo;
template <> class BSSimpleArray<NavMeshInfo*, 1024>
{
  public:
    unsigned int Add(NavMeshInfo*& item);
};

struct BGSSaveLoadHistoryNoteLocals
{
    char* allocation;
    char* note;
    char buffer[1024];
};

class InventoryStackRecord;
template <class T> class BSSimpleList;
template <> class BSSimpleList<InventoryStackRecord*>
{
  public:
    void RemoveAll();
};

class FormChangeRecord;
class BGSSaveLoadChangesMap
{
  public:
    FormChangeRecord* FUN_009a4250(unsigned int);
};
class ActorCause;
template <> class BSSimpleList<ActorCause*>
{
  public:
    void RemoveAll();
};
class BGSLoadFormBuffer
{
  public:
    void ReadTypedData(void*, unsigned int);
};
class BGSLoadGameBuffer : public BGSLoadFormBuffer
{
  public:
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();
    void ReadAndVerifySize(SaveLoadFile*);
    char* LoadString(char*);
    void** vtable;
    char* data;
    unsigned int size;
    unsigned int position;
};
#endif

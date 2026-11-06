// fallout_shared/bgsdebris_decls.h: declares FileEntryList, DebrisModelEntry, ModelLoader
#ifndef BGSDEBRIS_DECLS_H
#define BGSDEBRIS_DECLS_H

#include "bgsdebris_types_BGSDebris.h"
class FileEntryList
{
  public:
    unsigned int fields[2];
    FileEntryList();
    ~FileEntryList();
    void Load(TESFile*, TESForm*, const char*);
};
extern const char DAT_01015890[];
extern const char DAT_01024988[];
int Warning(const char*, ...);
extern "C" void* _alloca(unsigned int);
class DebrisModelEntry
{
  public:
    char chance, flags;
    short pad;
    char* path;
    FileEntryList model;
    DebrisModelEntry();
    ~DebrisModelEntry();
    void SetFileName(const char*);
};
void Deallocate(void*);
void* Allocate(unsigned int);
template <class T> unsigned int BSStringLength(const T*);
class ModelLoader
{
  public:
    void QueueFullWithNullResult(const char*, void*, int, void*, int, int, int, int);
};
extern ModelLoader* g_modelLoader;
#endif

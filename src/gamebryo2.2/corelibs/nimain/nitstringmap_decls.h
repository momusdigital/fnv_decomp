#ifndef FNV_NITSTRINGMAP_DECLS_H
#define FNV_NITSTRINGMAP_DECLS_H


extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl strcpy_s(char*, unsigned int, const char*);
void* __cdecl _NiMalloc(unsigned int);
class NiShader;

template <class T_Key, class T_Value> class NiTMapItem
{
  public:
    NiTMapItem<T_Key, T_Value>* m_pkNext;
    T_Key m_key;
    T_Value m_uiFilterValue;
};

template <class T> class NiTPointerAllocator
{
};

template <class T_Allocator, class T_Item> class NiTPointerListBase
{
  public:
    unsigned int m_uiCount;
    void* AddHead();
};

template <class T_Key, class T_Value> class NiTPointerMap
{
  public:
    virtual ~NiTPointerMap();
    unsigned int m_uiHashSize;
    NiTMapItem<T_Key, T_Value>** m_ppkHashTable;
    NiTPointerListBase<NiTPointerAllocator<unsigned int>, char*> m_kList;
};

template <class T_Map, class T_Value> class NiTStringTemplateMap : public T_Map
{
  public:
    virtual ~NiTStringTemplateMap();
    virtual unsigned int KeyToHashIndex(const char* key);
    virtual bool IsKeysEqual(const char* left, const char* right);
    virtual void SetValue(NiTMapItem<const char*, T_Value>* item, const char* key, T_Value value);
    bool m_bCopy;

    void SetAt(const char* key, T_Value value);
};

class ShaderBufferRecord;
void __cdecl NiFree(void*);
int NiStricmp(const char* a, const char* b);
bool __stdcall EqualStringsCaseInsensitive(const char* left, const char* right);
template <> class NiTPointerMap<const char*, ShaderBufferRecord*>
{
  public:
    virtual void slot0();
    virtual unsigned int KeyToHashIndex(const char*);
    virtual bool IsKeysEqual(const char*, const char*);
    virtual void SetValue(NiTMapItem<const char*, ShaderBufferRecord*>*, const char*, ShaderBufferRecord*);
    ~NiTPointerMap();
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, ShaderBufferRecord*>** m_ppkHashTable;
    unsigned int m_uiCount;
};
template <class T> class NiTStringPointerMap : public NiTPointerMap<const char*, T>
{
  public:
    ~NiTStringPointerMap();
    virtual unsigned int KeyToHashIndex(const char*);
    virtual bool IsKeysEqual(const char*, const char*);
    virtual void SetValue(NiTMapItem<const char*, T>*, const char*, T);
    bool m_bCopy;
};
#endif

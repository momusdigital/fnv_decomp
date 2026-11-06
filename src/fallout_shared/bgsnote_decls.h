// fallout_shared/bgsnote_decls.h: declares TESDescription, TESTexture, TESForm, TESBoundObject, TESModel and more
#ifndef FNV_BGSNOTE_DECLS_H
#define FNV_BGSNOTE_DECLS_H

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class TESFile;
class TESDescription
{
  public:
    char data[8];
    TESDescription();
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};
class TESTexture
{
  public:
    virtual void vfn_0();
    char data[8];
    TESTexture();
    ~TESTexture();
    void AssignTextureName(const char*);
    static void ReadTextureData(TESTexture*, TESFile*);
};
enum NOTE_TYPE
{
    NoteSound,
    NoteText,
    NoteTexture
};
enum ENUM_FORM_ID
{
    kNote = 0x31
};
class TESForm
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void LoadBounds(TESFile*);
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual const char* GetEditorID();
    virtual void SetEditorID(const char*);
    char data[0x2c];
    void SetFormType(ENUM_FORM_ID);
    void LoadRecordHeader(TESFile*);
    bool GetInitialized() const;
    TESFile* GetFile(int);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
    static TESForm* GetFormByID(unsigned int);
    unsigned int GetFormID();
    void SetInitializationState(bool);
};
class TESBoundObject : public TESForm
{
  public:
    TESBoundObject();
    ~TESBoundObject();
};
class TESModel
{
  public:
    virtual void vfn_0();
    char data[0x14];
    TESModel();
    ~TESModel();
    static void LoadModelData(TESModel*, TESFile*);
};
class TESFullName
{
  public:
    virtual void vfn_0();
    char data[8];
    TESFullName();
    ~TESFullName();
};
class TESIcon : public TESTexture
{
  public:
    TESIcon();
    ~TESIcon();
};
class BGSPickupPutdownSounds
{
  public:
    virtual void vfn_0();
    char data[8];
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    void InitItem(TESForm*);
    void SetPickupSound(class TESSound*);
    void SetPutdownSound(class TESSound*);
};
class TESQuest : public TESForm
{
};
class TESSound : public TESForm
{
};
class TESTopic : public TESForm
{
};
class TESActorBase : public TESForm
{
};
int Warning(const char*, ...);
template <class T> struct BGSNoteReference
{
    unsigned int id;
    T* form;
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    BSSimpleList();
    ~BSSimpleList();
    bool IsEmpty();
    T& GetItem();
    void SetItem(const T&);
    BSSimpleList* GetNext();
    void Remove(const T&);
    void RemoveHead();
    void AddHead(const T&);
};
class BGSNote : public TESBoundObject,
                public TESModel,
                public TESFullName,
                public TESIcon,
                public BGSPickupPutdownSounds
{
  public:
    void* m_pText;
    void* m_pDialogueSpeaker;
    BSSimpleList<TESQuest*> ownerQuests;
    signed char cType;
    bool m_bIsRead;
    char padding7e[2];
    BGSNote();
    void ChangeNoteType(NOTE_TYPE);
    void InitItem();
    bool Load(TESFile*);
    TESTexture* GetNoteTexture();
    TESSound* GetNoteSound();
    void SetNoteSound(TESSound*);
    TESTopic* GetNoteTopic();
    void SetNoteTopic(TESTopic*);
    TESActorBase* GetNoteSpeaker();
    void SetNoteSpeaker(TESActorBase*);
    void ResetFormData();
    int GetNoteType();
    TESDescription* GetNoteDescription();
};
class TESFile
{
  public:
    ENUM_FORM_ID GetTESForm();
    int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(unsigned int*);
    bool GetChunkData(void*, unsigned int);
    bool NextChunk();
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
bool __cdecl IsChunkTypeIcon(int);
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)
#endif

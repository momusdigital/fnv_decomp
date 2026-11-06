// fallout_shared/bsanimgroupsequence.cpp: BSAnimGroupSequence, TaskQueueInterface, TargetClass, SoundPlaybackManager (20 functions)

#include "bsanimgroupsequence_decls.h"

// Scans the sequence's tag array for a matching object name and returns its priority byte, writing the matching index to indexOut when given.
// @fnv 0x004ef9a0
unsigned char BSAnimGroupSequence::GetPriority(const char* objectName, unsigned int* indexOut)
{
    for (unsigned int i = 0; i < m_uiNumControlledBlocks; ++i)
    {
        const char* name =
            reinterpret_cast<NiFixedString*>(&reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(&m_pkIDTags[i])->GetItem())
                ->
                operator const char*();
        if (!name)
            Warning("NULL object name found in tag array for sequence '%s'.",
                    reinterpret_cast<NiFixedString*>(reinterpret_cast<TESTopicInfoData*>(this)->GetLinkToList())
                        ->
                        operator const char*());
        if (name && !FUN_00404dc0(name, objectName))
        {
            if (indexOut)
                *indexOut = i;
            return m_pInterpArray[i].m_ucArrayItemID;
        }
    }
    return 0;
}

// @fnv 0x004efdc0
bool BSAnimGroupSequence::Deactivate(float easeOutTime, bool transition)
{
    if (m_pkAccumulationRoot)
    {
        switch (static_cast<int>(reinterpret_cast<TESAnimGroup*>(m_spAnimGroup.operator->())->GetType()))
        {
        case 23:
        case 24:
        case 25: {
            NiTimeController* controller =
                m_pkAccumulationRoot->GetController(reinterpret_cast<const NiRTTI*>(&g_012031b8));
            if (controller)
            {
                BGSCameraPath* state = reinterpret_cast<BGSCameraPath*>(controller);
                if (state->GetPrevPath())
                {
                    controller = m_pkAccumulationRoot->GetParent()->GetController(&DAT_011f36bc);
                    if (controller)
                        reinterpret_cast<AnimationInterpolatorNode*>(controller)
                            ->UpdateInterpolatorsAtTime(m_fLastTime, true);
                }
            }
        }
        break;
        }
    }
    return NiControllerSequence::Deactivate(easeOutTime, transition);
}

struct NP
{
    ~NP();
};
struct BaseH
{
    virtual void v();
    ~BaseH();
};
struct FUN_004eeb00 : BaseH
{
    int pad[0x1c];
    NP m;
    ~FUN_004eeb00();
};
// Destructor of FUN_004eeb00 that destroys its NP member and the BaseH base.
// @fnv 0x004eeb00
FUN_004eeb00::~FUN_004eeb00()
{}

struct FUN_004eec60_shell : public BSAnimGroupSequence
{
    float FUN_004eec60(float);
};

struct FUN_00a30970_helper
{
    float FUN_00a30970(float afTime, bool bClamp);
};

// Returns 0.0f unless the sequence's state at offset 0x44 is 1-3, otherwise evaluates the helper at afTime plus the offset at 0x48 with clamping.
// @fnv 0x004eec60
float FUN_004eec60_shell::FUN_004eec60(float afTime)
{
    switch (*(int*)((char*)this + 0x44))
    {
    case 1:
    case 2:
    case 3:
        break;
    default:
        return 0.0f;
    }
    return ((FUN_00a30970_helper*)this)->FUN_00a30970(afTime + *(float*)((char*)this + 0x48), true);
}

struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};
struct HY
{
    float FUN_004eec60(float);
};
struct HX
{
    char pad[0x34];
    int i34;
    int i38;
    char p1[8];
    int i44;
    float f48;
    float f4c;
    float f50;
    int i54;
    void FUN_004efd10(BGSLoadFormBuffer*, float);
};
// Reads a time, a byte, and three ints from the buffer, stores fTime minus fBase into f48, sets f4c and f50 to -DAT_01023850, then calls FUN_004eec60 with fBase.
// @fnv 0x004efd10
void HX::FUN_004efd10(BGSLoadFormBuffer* pBuffer, float fBaseTime)
{
    float fTime = 0.0f;
    pBuffer->ReadTypedData(&fTime, 4);
    f48 = fTime - fBaseTime;
    unsigned char ucByte = 0;
    pBuffer->ReadTypedData(&ucByte, 1);
    i44 = ucByte;
    pBuffer->ReadTypedData(&i34, 4);
    pBuffer->ReadTypedData(&i38, 4);
    pBuffer->ReadTypedData(&i54, 4);
    f4c = -DAT_01023850;
    f50 = -DAT_01023850;
    ((HY*)this)->FUN_004eec60(fBaseTime);
}

extern NiFixedString* DAT_011c61c8;

// @fnv 0x004ef990
const NiFixedString& __cdecl FUN_004ef990()
{
    return *DAT_011c61c8;
}

struct CloningProcess;
struct NiObject;

struct FUN_00a344f0_shell
{
    NiObject* __thiscall FUN_00a344f0(CloningProcess*);
};

struct FUN_004eec20_shell
{
    NiObject* __thiscall FUN_004eec20(CloningProcess* arCloneData);
};

// @fnv 0x004eec20
NiObject* __thiscall FUN_004eec20_shell::FUN_004eec20(CloningProcess* arCloneData)
{
    return ((FUN_00a344f0_shell*)this)->FUN_00a344f0(arCloneData);
}

struct NiTPrimitiveArray_char_ptr;
struct BSAnimGroupSequence;

struct FUN_00a34540_shell : BSAnimGroupSequence
{
    void FUN_00a34540(NiTPrimitiveArray_char_ptr* pkStrings);
};

void FUN_00a34540_shell::FUN_00a34540(NiTPrimitiveArray_char_ptr* pkStrings)
{}

struct FUN_004eec40_shell : BSAnimGroupSequence
{
    void FUN_004eec40(NiTPrimitiveArray_char_ptr* pkStrings);
};

// @fnv 0x004eec40
void FUN_004eec40_shell::FUN_004eec40(NiTPrimitiveArray_char_ptr* pkStrings)
{
    ((FUN_00a34540_shell*)this)->FUN_00a34540(pkStrings);
}

struct TaskQueueInterface
{
    void __thiscall SetTaskFlagDWord(bool, unsigned int);
    void __thiscall FUN_004ef970(bool);
};

// @fnv 0x004ef970
void TaskQueueInterface::FUN_004ef970(bool enabled)
{
    SetTaskFlagDWord(enabled, 0x20000);
}

struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

// @fnv 0x004efaa0
unsigned short FUN_004efaa0()
{
    unsigned short v = 0;
    v += 4;
    v += 4;
    if (g_TESSaveLoadGame->FUN_008df040() < 0x71)
        v += 4;
    v += 4;
    v += 4;
    v += 4;
    return v;
}

namespace fnv_004efb20 {
// Stand-ins for types not in scope
struct TESSaveLoadGame
{
    unsigned char FUN_008df040(void);
    void SaveGameDataOLD(void* data, unsigned int size);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_004efb20_shell
{
    void FUN_004efb20(float afTime);
};

// @fnv 0x004efb20
void FUN_004efb20_shell::FUN_004efb20(float afTime)
{
    float foffset = ((float*)((char*)this + 0x48))[0] + afTime;
    g_TESSaveLoadGame->SaveGameDataOLD(&foffset, 4);
    g_TESSaveLoadGame->SaveGameDataOLD((void*)((char*)this + 0x44), 4);
    if (g_TESSaveLoadGame->FUN_008df040() < 0x71)
    {
        g_TESSaveLoadGame->SaveGameDataOLD(&foffset, 4);
    }
    g_TESSaveLoadGame->SaveGameDataOLD((void*)((char*)this + 0x34), 4);
    g_TESSaveLoadGame->SaveGameDataOLD((void*)((char*)this + 0x38), 4);
    g_TESSaveLoadGame->SaveGameDataOLD((void*)((char*)this + 0x54), 4);
}
}  // namespace fnv_004efb20

struct NiControllerManager
{
    int GetStringAtOffset(int);
};
struct TargetClass
{
    char _pad[0x40];
    NiControllerManager* field40;
    int FUN_00a31910(int, int);
    int FUN_004eedd0(int, int);
};
// Returns the result of FUN_00a31910 with a1 and the value GetStringAtOffset returns for a2 on field40.
// @fnv 0x004eedd0
int TargetClass::FUN_004eedd0(int a1, int a2)
{
    return FUN_00a31910(a1, field40->GetStringAtOffset(a2));
}

unsigned short __cdecl FUN_004efaa0();

struct FUN_004efb10_shell
{
    unsigned short __thiscall FUN_004efb10();
};

// @fnv 0x004efb10
unsigned short __thiscall FUN_004efb10_shell::FUN_004efb10()
{
    return FUN_004efaa0();
}

struct FUN_004efa50_Holder
{
    char _pad[20];
    struct Item
    {
        int f0;
        int f1;
        int f2;
        int f3;
    }* arr;
    void ClearItemField2();
};
// Iterates up to GetFormID() and sets f2 to 0 on each element of arr.
// @fnv 0x004efa50
void FUN_004efa50_Holder::ClearItemField2()
{
    int i;
    for (i = 0; i < ((TESForm*)this)->GetFormID(); ++i)
        arr[i].f2 = 0;
}

struct BGSSaveFormBuffer
{
    void SaveData(void* data, int size, int type);
};

struct FUN_004efc90_shell
{
    char pad_0x00[0x34];
    char m_0x34[4];
    char m_0x38[4];
    char pad_0x3c[0x44 - 0x3c];
    unsigned char m_0x44;
    char pad_0x45[0x48 - 0x45];
    float m_0x48;
    char pad_0x4c[0x54 - 0x4c];
    char m_0x54[4];
    void FUN_004efc90(BGSSaveFormBuffer* buffer, float value);
};

// Adds value to m_0x48 and saves the sum, m_0x44, m_0x34, m_0x38 and m_0x54 into the save buffer.
// @fnv 0x004efc90
void __thiscall FUN_004efc90_shell::FUN_004efc90(BGSSaveFormBuffer* buffer, float value)
{
    float temp = this->m_0x48 + value;
    buffer->SaveData(&temp, 4, 0);
    unsigned char byte2 = this->m_0x44;
    buffer->SaveData(&byte2, 1, 0);
    buffer->SaveData(this->m_0x34, 4, 0);
    buffer->SaveData(this->m_0x38, 4, 0);
    buffer->SaveData(this->m_0x54, 4, 0);
}

struct GO
{
    int data;

    GO(int);
    ~GO();
    operator unsigned int() const;
    void operator=(void*);
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct FUN_004ee9f0 : A51BF0Base
{
    unsigned char data[0x78];

    FUN_004ee9f0(int, unsigned int);
};

void __cdecl FUN_00a35700(int, int, GO*);

// Constructs a GO from 0, passes arg1 and arg2 to FUN_00a35700, then assigns a new FUN_004ee9f0 built from the GO's value to target.
// @fnv 0x004eeb60
void __cdecl AssignNewObjectFromValue(int arg1, int arg2, GO* target)
{
    {
        GO value(0);

        FUN_00a35700(arg1, arg2, &value);

        target->operator=(new FUN_004ee9f0(0, static_cast<unsigned int>(value)));
    }
}

namespace fnv_004efbc0 {
class TESSaveLoadGame
{
  public:
    void ReadTypedData(void* data, unsigned int size);
};

struct SaveManager : public TESSaveLoadGame
{
  public:
    unsigned char FUN_008df040();
};

extern SaveManager* DAT_011de45c;

class HY
{
  public:
    float FUN_004eec60(float value);
    void FUN_004efbc0(float value);
};

// @fnv 0x004efbc0
void HY::FUN_004efbc0(float value)
{
    float loadedValue;

    DAT_011de45c->ReadTypedData(&loadedValue, 4);
    DAT_011de45c->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x44), 4);

    if (DAT_011de45c->FUN_008df040() < 0x71)
        DAT_011de45c->ReadTypedData(&loadedValue, 4);

    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x48) = loadedValue - value;

    DAT_011de45c->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x34), 4);
    DAT_011de45c->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x38), 4);
    DAT_011de45c->ReadTypedData(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x54), 4);

    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x4c) = -DAT_01023850;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x50) = -DAT_01023850;

    this->FUN_004eec60(value);
}
}  // namespace fnv_004efbc0

struct NameECB
{
    void* GetItem();
};
struct CollectionECB;
struct RootECB
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual RootECB* v08C(const NiFixedString&);
    virtual void v090(NameECB*, bool);
    virtual void v094();
    virtual CollectionECB* v098();
    NiFixedString& GetName();
};
struct CollectionECB
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void* v09C(NameECB*);
};
struct ManagerECB
{
    RootECB* GetStringAtOffset();
};
struct TagECB
{
    int unk00, unk04, unk08, unk0C, unk10;
    NameECB* FUN_006815c0();
};
struct PointerECB
{
    void* object;
    PointerECB& operator=(void*);
};
struct ItemECB
{
    int unk00;
    PointerECB pointer;
    void* unk08;
    unsigned char priority;
    unsigned char unk0D, unk0E, unk0F;
};
extern unsigned char DAT_01096968;
struct FUN_004eecb0_Class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int count;
    int unk10;
    ItemECB* items;
    TagECB* tags;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    ManagerECB* manager;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    RootECB* accumulation;
    void FUN_004eecb0();
};
// @fnv 0x004eecb0
void FUN_004eecb0_Class::FUN_004eecb0()
{
    if (!manager)
        return;
    RootECB* root = manager->GetStringAtOffset();
    RootECB* object = root;
    if (accumulation)
        accumulation = root->v08C(accumulation->GetName());
    for (unsigned int index = 0; index < count; index++)
    {
        TagECB* tag = &tags[index];
        if (!object->v098()->v09C(tag->FUN_006815c0()))
        {
            root->v090(tag->FUN_006815c0(), false);
            items[index].pointer = 0;
            items[index].unk08 = 0;
            items[index].priority = DAT_01096968;
        }
    }
}

struct S004eee_Controller
{
    virtual void slot_00();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0c();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1c();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2c();
    virtual void slot_30();
    virtual void slot_34();
    virtual void slot_38();
    virtual void slot_3c();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_4c();
    virtual void slot_50();
    virtual void slot_54();
    virtual void slot_58();
    virtual void slot_5c();
    virtual void slot_60();
    virtual void slot_64();
    virtual void slot_68();
    virtual void slot_6c();
    virtual void slot_70();
    virtual void slot_74();
    virtual void slot_78();
    virtual void slot_7c();
    virtual void slot_80();
    virtual void slot_84();
    virtual void slot_88();
    virtual int Find(const void* key);
};
struct S004eee_Factory
{
    S004eee_Controller* GetStringAtOffset();
};
struct S004eee_Anim
{
    int FUN_0043b1b0();
};
struct S004eee_Entry20
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    S004eee_Anim* FUN_006815c0();
};
struct S004eee_Entry16Sub
{
    unsigned int unk00;
    void FUN_0066b0d0(int);
};
struct S004eee_Entry16
{
    unsigned int unk00;
    S004eee_Entry16Sub m_sub04;
    unsigned int unk08;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
};
extern unsigned char DAT_01096968;
struct S004eee_Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiItemCount;
    unsigned int unk10;
    S004eee_Entry16* m_dest;
    S004eee_Entry20* m_pObservedSource;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    S004eee_Factory* m_factory;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int m_priorHandle;
    unsigned int m_handle;
    void UpdateEntryStates();
};
// @fnv 0x004eee00
void S004eee_Owner::UpdateEntryStates()
{
    S004eee_Controller* manager = m_factory->GetStringAtOffset();
    S004eee_Controller* cachedManager = manager;
    if (m_handle != 0)
        m_handle = manager->Find(&m_priorHandle);
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
    {
        S004eee_Entry20* entry = &m_pObservedSource[i];
        int active = entry->FUN_006815c0()->FUN_0043b1b0();
        if (active == 0 || cachedManager->Find(entry->FUN_006815c0()) == 0)
        {
            m_dest[i].m_sub04.FUN_0066b0d0(0);
            m_dest[i].unk08 = 0;
            m_dest[i].unk0c = DAT_01096968;
        }
    }
}

struct SeqSound : NiControllerSequence
{
    int GetState();
    float GetScale();
    unsigned int GetThreadID();
};
struct KeySound : TimedTextEntry
{
    NiFixedString& Text();
    float Time();
};
void CopySoundText(char*, const char*);
char* FindSoundChar(char*, int);
// @fnv 0x004eef00
bool __cdecl PlaySequenceSounds(SeqSound* sequence, TESObjectREFR* reference)
{
    bool result2 = false;
    if (sequence && sequence->GetState() == 1)
    {
        float previous = sequence->GetField4C();
        float current4 = sequence->GetScale();
        if (previous != -DAT_01023850 && current4 != -DAT_01023850 && previous != current4)
        {
            bool wrapped5 = false;
            if (current4 < previous)
                wrapped5 = true;
            unsigned int count8 = 0;
            KeySound* keys2 = 0;
            if (sequence->FUN_00700300())
                keys2 = (KeySound*)sequence->FUN_00700300()->FUN_00495f30(&count8);
            for (unsigned int index = 0; index < count8; index++)
            {
                char* text_2 = (char*)(const char*)keys2[index].Text();
                if (!text_2)
                    continue;
                float time5 = keys2[index].Time();
                bool play3 = false;
                NiAVObject* node9 = 0;
                if (wrapped5 && (time5 > previous || time5 <= current4))
                    play3 = true;
                else if (time5 >= previous && time5 < current4)
                    play3 = true;
                if (play3 && _strnicmp("Sound: ", text_2, 7))
                {
                    play3 = false;
                    if (!_strnicmp("Enum: StopSounds ", text_2, 17))
                    {
                        char* suffix6 = 0;
                        char nodeName5[32];
                        nodeName5[0] = 0;
                        char* stopNewline4 = FindSoundChar(text_2, 13);
                        if (stopNewline4)
                            *stopNewline4 = 0;
                        suffix6 = text_2 + 16;
                        if (*suffix6 && suffix6[1])
                            CopySoundText(nodeName5, suffix6 + 1);
                        if (stopNewline4)
                            *stopNewline4 = 13;
                        if (reference->GetNiNode_v())
                        {
                            if (nodeName5[0])
                                node9 = reference->GetNiNode_v()->GetObjectByName(NiFixedString(nodeName5));
                            else
                                node9 = reference->GetNiNode_v()->GetObjectByName(FUN_004ef990());
                            if (!node9)
                                node9 = reference->GetNiNode_v();
                        }
                        if (node9)
                            BSAudio::GetSingleton()->FUN_00ad8570(node9, 1.0f, 0x40000000);
                    }
                    else if (!_strnicmp("Enum: HitShader", text_2, 15))
                        g_thePlayer->ApplyHitShaderToReference(reference);
                }
                TESSound* sound2 = 0;
                char* space8 = 0;
                char objectName3[32];
                objectName3[0] = 0;
                if (play3)
                {
                    char* newline = FindSoundChar(text_2, 13);
                    if (newline)
                        *newline = 0;
                    space8 = FindSoundChar(text_2 + 7, 32);
                    if (space8)
                    {
                        CopySoundText(objectName3, space8 + 1);
                        *space8 = 0;
                    }
                    sound2 = g_dataHandler->GetSoundByEditorID(text_2 + 7);
                    if (newline)
                        *newline = 13;
                }
                if (sound2)
                {
                    SoundPlaybackHandle handle;
                    NiPoint3 position4 = NiPoint3::ZERO;
                    unsigned int flags2 = TESSound::GetPlaybackFlags(sound2->CopyBig().iFlags);
                    bool special2 = (sound2->CopyBig().iFlags & 0x40) && !(sound2->CopyBig().iFlags & 0x800);
                    bool looping5 = (flags2 & 0x10) != 0;
                    flags2 |= reference == g_thePlayer ? 0x200000 : 0;
                    if (reference && reference->GetNiNode_v())
                    {
                        if (objectName3[0])
                            node9 = reference->GetNiNode_v()->GetObjectByName(NiFixedString(objectName3));
                        else
                            node9 = reference->GetNiNode_v()->GetObjectByName(FUN_004ef990());
                        if (looping5 && !node9)
                            node9 = reference->GetNiNode_v();
                        if (node9)
                            node9->FUN_004ef970(true);
                        reference->GetNiNode_v()->FUN_004ef970(true);
                        if (node9)
                            position4 = node9->FUN_0045bb80();
                        else
                            position4 = reference->GetNiNode_v()->FUN_0045bb80();
                    }
                    if (reference &&
                        (looping5 || special2 || SoundPlaybackManager::CanPlaySoundAt(sound2, position4, 1.0f)))
                    {
                        if (looping5)
                            handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                     flags2 | 0x40002002);
                        else
                        {
                            if (sound2->CopyBig().iFlags & 0x40)
                                handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                         flags2 | 0x40002101);
                            else
                                handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                         flags2 | 0x40002102);
                        }
                    }
                    else if (!reference)
                    {
                        if (looping5)
                            handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                     flags2 | 0x40000022);
                        else
                        {
                            if (sound2->CopyBig().iFlags & 0x40)
                                handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                         flags2 | 0x40000121);
                            else
                                handle = BSAudio::GetSingleton()->GetSoundHandleByFormID(sound2->GetFormID(),
                                                                                         flags2 | 0x40000122);
                        }
                    }
                    if (node9)
                        handle.SetObjectToFollow(node9);
                    handle.SetPosition(position4.x, position4.y, position4.z);
                    handle.Play(looping5);
                }
                if (space8)
                    *space8 = 32;
            }
        }
        if (sequence->GetThreadID())
        {
            result2 = true;
            if (sequence->FUN_00639aa0() == -DAT_01023850)
                result2 = false;
            else if (sequence->GetScale() < sequence->FUN_00508100())
                result2 = false;
        }
    }
    return result2;
}

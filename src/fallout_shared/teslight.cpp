// fallout_shared/teslight.cpp: TESObjectLIGH, TESFullName, Owner, LightLoader and more (29 functions)

#include "teslight_TESFullName.h"
#include "teslight_TESForm.h"
#include "teslight_TESScriptableForm.h"

class TESSound : public TESForm
{
};
#include "teslight_r2d_types_TESObjectLIGH.h"
#include "teslight_scene.h"

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern "C" const char DAT_01029064[];
extern int __cdecl Warning(const char* format, ...);
extern float DAT_010249d8;

// Returns the reference's model node, or a new NiSortAdjustNode when the model name is empty or the node has no children.
// @fnv 0x0050d4c0
NiAVObject* TESObjectLIGH::Get3DObject(TESObjectREFR* reference)
{
    NiAVObject* result = 0;
    if (BSStringLength(GetModelName()))
        result = TESBoundObject::Get3DObject(reference);
    else
        result = new NiSortAdjustNode(0);

    if (result && !result->IsSceneNode())
    {
        NiSortAdjustNode* node = new NiSortAdjustNode(0);
        node->vfn_00dc(result, true);
        result = node;
    }
    return result;
}

// Recursively searches a NiNode's children for the first NiAVObject matching DAT_011f4a28 and returns it as a NiLight, or null.
// @fnv 0x0050d6d0
NiLight* FindLightInNode(NiNode* node)
{
    NiLight* result = 0;
    if (!node)
        return result;

    for (unsigned int index = 0; index < node->FUN_0043b480(); ++index)
    {
        NiPointer<NiAVObject> child(node->FUN_0043b4a0(index));
        if (child)
        {
            if (static_cast<NiAVObject*>(child)->IsSceneNode())
            {
                result = FindLightInNode(static_cast<NiNode*>(static_cast<NiAVObject*>(child)));
                if (result)
                    return result;
            }
            else if (FUN_0043b300(&DAT_011f4a28, static_cast<NiAVObject*>(child)))
            {
                return static_cast<NiLight*>(static_cast<NiAVObject*>(child));
            }
        }
    }
    return result;
}

// @fnv 0x00489100
void TESFullName::SetFullName(const char* name)
{
    m_kName.Set(name, 0);
}

// @fnv 0x0050c990
void TESObjectLIGH::ResetFormData()
{
    FUN_0050c9e0(0);
    memset(&data, 0, 0x18);
    fFadeAmount = 1.0f;
    data.fFOV = DAT_010249d8;
}

// @fnv 0x0050ca00
void TESObjectLIGH::InitItem()
{
    if (reinterpret_cast<const TESFormInitFlag*>(this)->IsFormInitialized())
        return;

    TESScriptableForm::InitItem(static_cast<TESForm*>(this));
    BGSDestructibleObjectForm::InitItem(static_cast<TESForm*>(this));
    TESModelTextureSwap::InitItem(static_cast<TESForm*>(this));

    if (m_pGameSound)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(m_pGameSound);
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        m_pGameSound = dynamic_cast<TESSound*>(TESForm::GetFormByID(formID));
        if (!m_pGameSound)
            Warning(DAT_01029064, formID, GetName());
    }
    SetInitializationState(true);
}

// @fnv 0x0050c9e0
void TESObjectLIGH::SetSound(TESSound* sound)
{
    m_pGameSound = sound;
}

class NiDynamicEffect
{
  public:
    void IncRevisionID();
};

struct FUN_0050c630_helper : public NiDynamicEffect
{
    void FUN_0050c630(float fC);
};

// Stores fC at offset 0xf0 of this object and calls IncRevisionID to mark the effect as changed.
// @fnv 0x0050c630
void FUN_0050c630_helper::FUN_0050c630(float fC)
{
    *(float*)((char*)this + 0xf0) = fC;
    IncRevisionID();
}

namespace fnv_0050c660 {
struct NiDynamicEffect
{
    void IncRevisionID();
};

struct FUN_0050c660_shell
{
    void FUN_0050c660(float fL);
};

// Stores fL at offset 0xf4 of this and calls IncRevisionID on the object as a NiDynamicEffect.
// @fnv 0x0050c660
void FUN_0050c660_shell::FUN_0050c660(float fL)
{
    *(float*)((char*)this + 0xf4) = fL;
    ((NiDynamicEffect*)this)->IncRevisionID();
}
}  // namespace fnv_0050c660

struct FUN_0050d4a0_shell : public TESForm
{
    bool FUN_0050d4a0();
};

// @fnv 0x0050d4a0
bool FUN_0050d4a0_shell::FUN_0050d4a0()
{
    return (m_uiFormFlags & 0x10) ? true : false;
}

struct FUN_0050dd90_shell : public TESObjectLIGH
{
    bool FUN_0050dd90();
};

// @fnv 0x0050dd90
bool FUN_0050dd90_shell::FUN_0050dd90()
{
    return (*(unsigned int*)((char*)this + 0xa8) & 1) ? true : false;
}

// Stores fQ at offset 0xf8 of the object and increments its revision ID.
// @fnv 0x0050c690
void __fastcall FUN_0050c690(NiDynamicEffect* this_ptr, float fQ)
{
    *(float*)((char*)this_ptr + 0xf8) = fQ;
    this_ptr->IncRevisionID();
}

struct FUN_0050dd50_color
{
    float r;
    float g;
    float b;
};
struct FUN_0050dd50_arg
{
    FUN_0050dd50_color* c;
};
// Copies the color from a.c into the effect's field at offset 0xe0 and bumps the revision ID.
// @fnv 0x0050dd50
void __fastcall FUN_0050dd50(NiDynamicEffect* this_ptr, FUN_0050dd50_arg aColorArg)
{
    *(FUN_0050dd50_color*)((char*)this_ptr + 0xe0) = *aColorArg.c;
    this_ptr->IncRevisionID();
}

struct FUN_0050c820_shell : TESObjectLIGH
{
    NiColor* GetLightColor();
};

// @fnv 0x0050c820
NiColor* FUN_0050c820_shell::GetLightColor()
{
    return reinterpret_cast<NiColor*>(reinterpret_cast<char*>(this) + 0xBC);
}

struct FUN_0050d100_shell
{
    void* FUN_0050d100();
};

// @fnv 0x0050d100
void* FUN_0050d100_shell::FUN_0050d100()
{
    return reinterpret_cast<char*>(this) + 0x9C;
}

struct FUN_00484bf0_stub
{
    unsigned short __thiscall FUN_00484bf0(unsigned int flags);
};
struct FUN_0048e9b0_stub
{
    unsigned short __thiscall FUN_0048e9b0(unsigned int flags);
};

struct FUN_0050e4f0_shell
{
    unsigned short __thiscall GetSize(unsigned int aiFlags);
};

// Returns the sum of the sizes reported by FUN_00484bf0 on this and FUN_0048e9b0 on the object at offset 0x8c, both called with aiFlags.
// @fnv 0x0050e4f0
unsigned short __thiscall FUN_0050e4f0_shell::GetSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += ((FUN_00484bf0_stub*)this)->FUN_00484bf0(aiFlags);
    isize += ((FUN_0048e9b0_stub*)((char*)this + 0x8c))->FUN_0048e9b0(aiFlags);
    return isize;
}

struct FUN_0051b070_shell
{
    void FUN_00484c20(unsigned int);
    void FUN_0048e9e0(unsigned int);
};

struct FUN_0050e550_shell
{
    void FUN_0050e550(unsigned int);
};

// Forwards aiFlags to FUN_00484c20 on this and to FUN_0048e9e0 on the object at offset 0x8c.
// @fnv 0x0050e550
void FUN_0050e550_shell::FUN_0050e550(unsigned int aiFlags)
{
    reinterpret_cast<FUN_0051b070_shell*>(this)->FUN_00484c20(aiFlags);
    reinterpret_cast<FUN_0051b070_shell*>(reinterpret_cast<char*>(this) + 0x8c)->FUN_0048e9e0(aiFlags);
}

struct TESFormStub
{
    void FUN_00484c50(unsigned int, unsigned int);
};
struct TESValueFormStub
{
    void FUN_0048ea10(unsigned int, unsigned int);
};

struct FUN_0050e580_shell
{
    void FUN_0050e580(unsigned int a1, unsigned int a2);
};

// @fnv 0x0050e580
void FUN_0050e580_shell::FUN_0050e580(unsigned int a1, unsigned int a2)
{
    ((TESFormStub*)this)->FUN_00484c50(a1, a2);
    ((TESValueFormStub*)((char*)this + 0x8c))->FUN_0048ea10(a1, a2);
}

struct FUN_00484d60_holder
{
    void SaveIfChanged(unsigned int);
};
struct FUN_0048ea40_holder
{
    void FUN_0048ea40(unsigned int);
};

struct FUN_0050e5c0_shell
{
    void AppendSaveLoadFormBuffer(unsigned int aiFlags);
};

// @fnv 0x0050e5c0
void FUN_0050e5c0_shell::AppendSaveLoadFormBuffer(unsigned int aiFlags)
{
    reinterpret_cast<FUN_00484d60_holder*>(this)->SaveIfChanged(aiFlags);
    reinterpret_cast<FUN_0048ea40_holder*>(reinterpret_cast<char*>(this) + 0x8c)->FUN_0048ea40(aiFlags);
}

class BGSLoadFormBuffer;

struct TESValueFormLoadGame
{
    void LoadGame(BGSLoadFormBuffer* arg);
};

struct FUN_0050e5f0_shell
{
    void LoadGame(BGSLoadFormBuffer* arg);
};

// Loads the TESForm base and the TESValueFormLoadGame subobject at offset 0x8c from the buffer.
// @fnv 0x0050e5f0
void FUN_0050e5f0_shell::LoadGame(BGSLoadFormBuffer* pBuffer)
{
    reinterpret_cast<TESForm*>(this)->TESForm::LoadGame(pBuffer);
    reinterpret_cast<TESValueFormLoadGame*>(reinterpret_cast<char*>(this) + 0x8c)->LoadGame(pBuffer);
}

struct Owner
{
    void FUN_0050c870();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_0050c870, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0050c840
void* Owner::DestroyIfFlagged(unsigned int flags)
{
    FUN_0050c870();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace stand {
struct TESBoundAnimObject
{
    TESBoundAnimObject();
    ~TESBoundAnimObject();
    virtual void v0();
    char pad[0x2c];
};
struct TESFullName
{
    TESFullName();
    ~TESFullName();
    virtual void v0();
    char pad[0x8];
};
struct TESModelTextureSwap
{
    TESModelTextureSwap();
    ~TESModelTextureSwap();
    virtual void v0();
    char pad[0x1c];
};
struct TESIcon
{
    TESIcon();
    ~TESIcon();
    virtual void v0();
    char pad[0x8];
};
struct BGSMessageIcon
{
    BGSMessageIcon();
    ~BGSMessageIcon();
    virtual void v0();
    char pad[0xc];
};
struct TESScriptableForm
{
    TESScriptableForm();
    virtual void v0();
    char pad[0x8];
};
struct TESWeightForm
{
    TESWeightForm();
    ~TESWeightForm();
    virtual void v0();
    char pad[0x4];
};
struct TESValueForm
{
    TESValueForm();
    ~TESValueForm();
    virtual void v0();
    char pad[0x4];
};
struct BGSDestructibleObjectForm
{
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
    virtual void v0();
    char pad[0x4];
};
struct NiPoint3
{
    NiPoint3(float, float, float);
    float x, y, z;
};
}

struct FUN_0050c6c0 : public stand::TESBoundAnimObject,
                      public stand::TESFullName,
                      public stand::TESModelTextureSwap,
                      public stand::TESIcon,
                      public stand::BGSMessageIcon,
                      public stand::TESScriptableForm,
                      public stand::TESWeightForm,
                      public stand::TESValueForm,
                      public stand::BGSDestructibleObjectForm
{
    char data[0x18];
    float fFadeAmount;
    void* m_pGameSound;
    stand::NiPoint3 m_kDiffuseColor;
    FUN_0050c6c0();
};

// @fnv 0x0050c6c0
FUN_0050c6c0::FUN_0050c6c0() : m_kDiffuseColor(0.0f, 0.0f, 0.0f)
{
    ((TESForm*)this)->SetFormType((ENUM_FORM_ID)0x1e);
    ((TESObjectLIGH*)this)->ResetFormData();
}

struct TESObjectLIGH;
struct TESLevItem;
struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};
struct RegionPointList
{
    void SetDistanceInsideAtMax(unsigned int);
};
struct TESActorBaseData
{
    void FUN_0050f9a0(TESLevItem*);
};
struct CGBase
{
    void SetProcedureType(int);
};
struct GetNextObj
{
    unsigned int GetNext();
};
struct FUN_00510130_shell
{
    void RemoveNode(NiNode* pNode);
};
// @fnv 0x00510130
void FUN_00510130_shell::RemoveNode(NiNode* pNode)
{
    if (pNode == *(NiNode**)((char*)this + 4))
    {
        *(NiNode**)((char*)this + 4) = (NiNode*)((GetNextObj*)(*(NiNode**)((char*)this + 4)))->GetNext();
    }
    if (pNode == *(NiNode**)((char*)this + 8))
    {
        *(NiNode**)((char*)this + 8) = (NiNode*)((BGSTerrainManager*)(*(NiNode**)((char*)this + 8)))->GetMinLevel();
    }
    unsigned int n = ((BGSTerrainManager*)pNode)->GetMinLevel();
    if (n)
    {
        ((RegionPointList*)n)->SetDistanceInsideAtMax((unsigned int)((GetNextObj*)pNode)->GetNext());
    }
    n = (unsigned int)((GetNextObj*)pNode)->GetNext();
    if (n)
    {
        ((TESActorBaseData*)n)->FUN_0050f9a0((TESLevItem*)((BGSTerrainManager*)pNode)->GetMinLevel());
    }
    ((CGBase*)pNode)->SetProcedureType(0);
    *(unsigned int*)this -= 1;
}

namespace fnv_0050d060 {
struct S_004036b0
{
    int FUN_004036b0();
};

struct SetterB
{
    void FUN_006e5ee0(float value);
};

struct FUN_0050d100_shell
{
    void* FUN_0050d100();
};

struct FUN_005e78f0_t
{
    struct Data
    {
        unsigned int value0;
        unsigned int value1;
        unsigned int value2;
        unsigned int value3;
        unsigned int value4;
        unsigned int value5;
    };

    unsigned char padding[0x9c];
    Data data;

    void FUN_004851b0(TESForm* form);
    void CopyFromLight(TESForm* form);
};

float __fastcall GetFieldB4Float(char* value);

// Copies light data from apCopy after casting it to TESObjectLIGH, then sets a float value and the sound from the source light.
// @fnv 0x0050d060
void FUN_005e78f0_t::CopyFromLight(TESForm* apCopy)
{
    TESObjectLIGH* ligh = dynamic_cast<TESObjectLIGH*>(apCopy);

    if (!ligh)
        return;

    FUN_004851b0(apCopy);

    data = *reinterpret_cast<Data*>(reinterpret_cast<FUN_0050d100_shell*>(ligh)->FUN_0050d100());

    reinterpret_cast<SetterB*>(this)->FUN_006e5ee0(GetFieldB4Float(reinterpret_cast<char*>(ligh)));

    reinterpret_cast<TESObjectLIGH*>(this)->SetSound(
        reinterpret_cast<TESSound*>(reinterpret_cast<S_004036b0*>(ligh)->FUN_004036b0()));
}
}  // namespace fnv_0050d060

struct FUN_004855a0
{
    void M();
};

struct FUN_00485680
{
    void M();
};

struct DoorPart3c
{
    void ProcessAndFreeData(unsigned int, unsigned int, unsigned int);
};

struct DoorPart5c
{
    void FUN_0048cca0();
};

struct DoorPart68
{
    void FUN_00477f20();
};

struct DoorPart30
{
    void FUN_00487010();
};

struct FUN_0048e370_obj
{
    void FUN_0048e370(unsigned int);
};

struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};

struct FUN_00485e00_shell
{
    void __SaveData(int, int);
};

bool _FUN_00401500();
void _FUN_00485910(unsigned int, float);
void _FUN_00485910(unsigned int, unsigned int);
void __fastcall SwapEndian(void*);

struct FUN_0050cf20_shell
{
    unsigned char pad_0000[0x9c];
    unsigned int value_009c;
    unsigned char pad_00a0[8];
    unsigned int flags_00a8;
    unsigned char pad_00ac[8];
    float fade_00b4;
    TESForm* sound_00b8;

    void FUN_0050cf20();
};

// @fnv 0x0050cf20
void FUN_0050cf20_shell::FUN_0050cf20()
{
    reinterpret_cast<FUN_004855a0*>(this)->M();

    reinterpret_cast<DoorPart3c*>(reinterpret_cast<char*>(this) + 0x3c)
        ->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<DoorPart5c*>(reinterpret_cast<char*>(this) + 0x78)->FUN_0048cca0();
    reinterpret_cast<DoorPart68*>(reinterpret_cast<char*>(this) + 0x94)->FUN_00477f20();

    if (flags_00a8 & 2)
    {
        reinterpret_cast<DoorPart30*>(reinterpret_cast<char*>(this) + 0x30)->FUN_00487010();
        reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x5c)->FUN_0048e370(0x4e4f4349);
        reinterpret_cast<FUN_0047a240_shell*>(reinterpret_cast<char*>(this) + 0x68)->FUN_0047a240(0x4f43494d);
    }
    else
    {
        flags_00a8 &= 0xffffffdf;
        value_009c = 0xffffffff;
    }

    if (_FUN_00401500())
        SwapEndian(&value_009c);

    reinterpret_cast<FUN_00485e00_shell*>(this)->__SaveData(reinterpret_cast<int>(&value_009c), 0x18);

    if (_FUN_00401500())
        SwapEndian(&value_009c);

    _FUN_00485910(0x4d414e46, fade_00b4);

    if (sound_00b8)
    {
        unsigned int formID = sound_00b8->GetFormID();
        _FUN_00485910(0x4d414e53, formID);
    }

    reinterpret_cast<FUN_00485680*>(this)->M();
}

struct FUN_0050c870 : stand::TESBoundAnimObject,
                      stand::TESFullName,
                      stand::TESModelTextureSwap,
                      stand::TESIcon,
                      stand::BGSMessageIcon,
                      stand::TESScriptableForm,
                      stand::TESWeightForm,
                      stand::TESValueForm,
                      stand::BGSDestructibleObjectForm
{
    virtual ~FUN_0050c870();
};

// @fnv 0x0050c870
FUN_0050c870::~FUN_0050c870()
{}

struct NextFile
{
    bool GetNextChunk();
};

struct LightFileExtra
{
    unsigned short FUN_00403570();
    bool FUN_00401680();
};
struct ModelLoad : TESModelTextureSwap
{
    bool LoadTextureSwapList(void*, unsigned int, unsigned int);
};
struct ComponentID : TESScriptableForm
{
    void FUN_006ecd40(unsigned int);
};
struct LightLoader : TESBoundAnimObject,
                     TESFullName,
                     ModelLoad,
                     TESIcon,
                     BGSMessageIcon,
                     ComponentID,
                     TESWeightForm,
                     TESValueForm,
                     BGSDestructibleObjectForm
{
    LightSourceData data;
    float fFadeAmount;
    TESSound* m_pGameSound;
    void FUN_00484ab0(int);
    void LoadData(TESFile*, void*, unsigned short);
    bool LoadLight(TESFile*);
};
void FUN_004892d0(TESModelTextureSwap*, TESFile*);
void FUN_0048e3d0(TESIcon*, TESFile*);
void FUN_0047a290(BGSMessageIcon*, TESFile*);
void FUN_004781e0(BGSDestructibleObjectForm*, TESFile*);
struct LightData
{
    void SwapEndian();
};
// @fnv 0x0050caf0
bool LightLoader::LoadLight(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 30)
        return false;
    LoadRecordHeader(file);
    FUN_00484ab0(0);
    data.fFOV = 0.0f;
    data.m_fLightFalloff = 0.0f;
    int chunk;
    while ((chunk = file->GetChunkID()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            TESFullNameLoader::LoadFullNameChunk(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44534f4d:
        case 0x44444f4d:
            FUN_004892d0(this, file);
            break;
        case 0x53444f4d: {
            unsigned int dataSize = file->GetChunkSize();
            void* swapData = _alloca(dataSize);
            file->GetChunkData(swapData, dataSize);
            ModelLoad::LoadTextureSwapList(swapData, dataSize, ((LightFileExtra*)file)->FUN_00403570());
            break;
        }
        case 0x4e4f4349:
            FUN_0048e3d0(this, file);
            break;
        case 0x4f43494d:
            FUN_0047a290(this, file);
            break;
        case 0x49524353: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            ComponentID::FUN_006ecd40(scriptID);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            FUN_004781e0(this, file);
            break;
        case 0x41544144:
            LoadData(file, &data, 24);
            break;
        case 0x4d414e46:
            file->GetChunkData((unsigned int*)&fFadeAmount);
            break;
        case 0x4d414e53: {
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            m_pGameSound = (TESSound*)soundID;
            break;
        }
        }
        if (chunk == 0x41544144)
        {
            if (((LightFileExtra*)file)->FUN_00401680())
                ((LightData*)&data)->SwapEndian();
            if (data.fFOV == 0.0)
                data.fFOV = DAT_010249d8;
            if (data.m_fLightFalloff == 0.0)
                data.m_fLightFalloff = 1.0f;
        }
        if (!((NextFile*)file)->GetNextChunk())
            break;
    }
    return true;
}

namespace LightCreation {
struct Color
{
    float r, g, b;
    Color(float, float, float);
    Color FUN_004a0bd0();
};
struct FixedString
{
    const char* text;
    FixedString(const char*);
    ~FixedString();
};
struct FUN_00a7d670
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;

    FUN_00a7d670();
    static __forceinline void* operator new(unsigned int size);
    static __forceinline void operator delete(void*, unsigned int)
    {}
    void AssignFixedString(const FixedString&);
    void FUN_004bc280(const Color&);
    void FUN_0050dd50(const Color&);
    void SetEffectColor(const Color&);
    void FUN_0050dd20(float);
};
typedef FUN_00a7d670 Light;
void* __cdecl FUN_00aa13e0(unsigned int);
__forceinline void* FUN_00a7d670::operator new(unsigned int size)
{
    return FUN_00aa13e0(size);
}
struct Parent;
struct Scene;
struct Extra
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual Scene* GetScene();
};
struct Scene
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual Extra* GetExtra(const char*);
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void Attach(Light*, bool);
    Parent* FUN_0043b230();
};
struct Parent
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual bool IsSpecial();
    Parent* FUN_004a8a90();
};
struct BaseForm
{
    int FUN_00401170();
};
struct Position
{
    float x, y, z;
};
struct EntryListNode
{
    bool FUN_008256d0();
};
struct ObjectPointerProvider
{
    EntryListNode* FUN_0041f810();
};
struct Reference
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual bool IsPersistent();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual Position* GetPosition();
    BaseForm* FUN_007af430();
    int FUN_008d6f30();
    float FUN_0057b0a0();
    void FUN_00484a70(bool);
    void FUN_00572610(Light*);
    float FUN_00568cb0();
    ObjectPointerProvider* FUN_005d43c0();
};
struct Manager
{
    void FUN_00b5c940(Light*, bool);
};
Manager* __cdecl FUN_00450b80(int);
bool __cdecl FUN_00578400(Scene*);
void __cdecl ProcessListItems(Scene*);
const char* __cdecl FUN_0050de10();
Light* __cdecl FUN_0050d6d0(Scene*);
void __cdecl FUN_00406d00(char*, unsigned int, const char*, ...);
void __cdecl ConfigurePointLight(Light*, unsigned int);
extern const char DAT_010290a4[];
extern const Color DAT_011f4998;
extern const double DAT_0101e568;
struct LightForm
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual const char* Name();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int radius;
    unsigned int color;
    unsigned int flags;
    unsigned int unkac, unkb0;
    float fade;
    void FUN_0050ddb0(bool);
    bool FUN_0050dd90();
    Light* FUN_0050d810(Reference*, Scene*, bool);
};
// @fnv 0x0050d810
Light* LightForm::FUN_0050d810(Reference* reference, Scene* pScene, bool force)
{
    if (!pScene)
        return 0;
    BaseForm* base;
    if (reference)
    {
        base = reference->FUN_007af430();
        if ((flags & 0x20) || (reference->FUN_008d6f30() && reference->GetPosition()->z < reference->FUN_0057b0a0()))
        {
            if (base->FUN_00401170() == 30 && FUN_00578400(pScene))
            {
                reference->FUN_00484a70(true);
                ProcessListItems(pScene);
            }
            if (!reference->IsPersistent() && (flags & 0x20))
                return 0;
        }
    }
    Light* lightSlot12 = 0;
    Color tintSlot1(0.0f, 0.0f, 0.0f);
    tintSlot1.r = (unsigned char)(color & 0xff) / DAT_0101e568;
    tintSlot1.g = (unsigned char)(((unsigned short)color >> 8) & 0xff) / DAT_0101e568;
    tintSlot1.b = (unsigned char)((color >> 16) & 0xff) / DAT_0101e568;
    if (flags & 4)
        tintSlot1 = tintSlot1.FUN_004a0bd0();
    Scene* rootSlot19 = 0;
    Extra* extra = pScene->GetExtra(FUN_0050de10());
    if (extra)
        rootSlot19 = extra->GetScene();
    if (!rootSlot19)
        rootSlot19 = pScene;
    lightSlot12 = FUN_0050d6d0(rootSlot19);
    if (!lightSlot12)
    {
        char name[260];
        FUN_00406d00(name, 260, DAT_010290a4, Name());
        lightSlot12 = new Light;
        lightSlot12->AssignFixedString(FixedString(name));
        rootSlot19->Attach(lightSlot12, true);
    }
    if (reference)
        reference->FUN_00572610(lightSlot12);
    lightSlot12->FUN_004bc280(DAT_011f4998);
    lightSlot12->FUN_0050dd50(DAT_011f4998);
    float radiusValueSlot21 = (float)radius;
    if (reference)
        radiusValueSlot21 = reference->FUN_00568cb0();
    lightSlot12->FUN_0050dd50(Color(radiusValueSlot21, radiusValueSlot21, radiusValueSlot21));
    lightSlot12->SetEffectColor(tintSlot1);
    Parent* parentSlot6;
    for (parentSlot6 = pScene->FUN_0043b230(); parentSlot6; parentSlot6 = parentSlot6->FUN_004a8a90())
    {
        if (parentSlot6->IsSpecial())
        {
            FUN_0050ddb0(true);
            break;
        }
    }
    if (!(reference && reference->FUN_005d43c0()->FUN_0041f810()) ||
        (reference && reference->FUN_005d43c0()->FUN_0041f810() &&
         reference->FUN_005d43c0()->FUN_0041f810()->FUN_008256d0()))
        FUN_00450b80(0)->FUN_00b5c940(lightSlot12, force ? true : FUN_0050dd90());
    if (lightSlot12)
    {
        ConfigurePointLight(lightSlot12, (unsigned int)radiusValueSlot21);
        lightSlot12->FUN_0050dd20(fade);
    }
    return lightSlot12;
}
}

// 0x0050c350  unit_0e65a86e7dd7.cpp  /MT /Od /Oy- /GS /EHsc /Gy
class NiRTTI
{
  public:
    int m;
};
class TESObjectCELL;

class NiPointLight
{
  public:
    void FUN_0050c630(float f);
    void FUN_0050c660(float f);
    void FUN_0050c690(float f);
};

class GlobalObject_0044f440
{
  public:
    float* Float();
    float FUN_00450410();
};
class GlobalObject_0045cfe0
{
  public:
    int* Int();
};
class GlobalObject_0045cf30
{
  public:
    bool FUN_0050e620(bool b);
};

extern GlobalObject_0044f440 g_011c8fb0;
extern GlobalObject_0044f440 g_011c9000;
extern GlobalObject_0044f440 g_011c9040;
extern GlobalObject_0044f440 g_011c906c;
extern GlobalObject_0044f440 g_011c908c;
extern GlobalObject_0045cfe0 g_011c9054;
extern GlobalObject_0045cfe0 g_011c907c;
extern GlobalObject_0045cf30 g_011c8fc0;
extern unsigned char DAT_011c8fa0;
extern NiRTTI DAT_011f4a98;

class TES
{
  public:
    TESObjectCELL* GetPrevPath();
};
extern TES* g_TES;

NiAVObject* NiDynamicCast(const NiRTTI* type, NiAVObject* object);

// @fnv 0x0050c350
void ConfigurePointLight(NiAVObject* object, unsigned int count)
{
    NiPointLight* light = (NiPointLight*)NiDynamicCast(&DAT_011f4a98, object);
    if (light)
    {
        light->FUN_0050c630((DAT_011c8fa0 & 1) ? *g_011c9000.Float() : 0.0f);
        light->FUN_0050c660(0.0f);
        light->FUN_0050c690(0.0f);

        if ((DAT_011c8fa0 & 2) || (g_TES->GetPrevPath() != 0 && g_011c8fc0.FUN_0050e620(true)))
        {
            float a = (double)count * *g_011c8fb0.Float();
            switch (*g_011c9054.Int())
            {
            case 0:
                light->FUN_0050c660(*g_011c908c.Float());
                break;
            default:
                light->FUN_0050c660((a != 0.0) ? ((1.0 / a) * *g_011c908c.Float()) : 0.01f);
                break;
            case 2:
                light->FUN_0050c660((a != 0.0) ? (*g_011c908c.Float() / (a * a)) : 0.01f);
                break;
            }
        }

        if ((DAT_011c8fa0 & 4) || (g_TES->GetPrevPath() == 0 && g_011c8fc0.FUN_0050e620(true)))
        {
            float b = (double)count * *g_011c906c.Float();
            switch (*g_011c907c.Int())
            {
            case 0:
                light->FUN_0050c690(*g_011c9040.Float());
                break;
            case 1:
                light->FUN_0050c690((b != 0.0) ? ((1.0 / (double)count) * g_011c9040.FUN_00450410()) : 0.01f);
                break;
            default:
                light->FUN_0050c690((b != 0.0) ? (g_011c9040.FUN_00450410() / (b * b)) : 0.01f);
                break;
            }
        }
    }
}

struct LightSoundAccess
{
    TESSound* FUN_004036b0();
};
struct LightComponentComparison
{
    bool FUN_00485270(TESForm*);
};
struct LightDataAccess
{
    LightSourceData* FUN_0050d100();
};
extern "C" int __cdecl _memcmp(const void*, const void*, unsigned int);
extern float __fastcall GetFieldB4Float(char*);

struct LightComparison : TESObjectLIGH
{
    bool FUN_0050d120(TESForm* form);
};

// Returns true if this light fails the component, sound, data, or computed-value comparisons.
// @fnv 0x0050d120
bool LightComparison::FUN_0050d120(TESForm* form)
{
    TESObjectLIGH* pOtherLight = dynamic_cast<TESObjectLIGH*>(form);
    if (!pOtherLight)
        return true;
    if (reinterpret_cast<LightComponentComparison*>(this)->FUN_00485270(pOtherLight))
        return true;
    if (m_pGameSound != reinterpret_cast<LightSoundAccess*>(pOtherLight)->FUN_004036b0())
        return true;
    if (_memcmp(&data, reinterpret_cast<LightDataAccess*>(pOtherLight)->FUN_0050d100(), sizeof(data)))
        return true;
    if (GetFieldB4Float(reinterpret_cast<char*>(this)) != GetFieldB4Float(reinterpret_cast<char*>(pOtherLight)))
        return true;
    return false;
}

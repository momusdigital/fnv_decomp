// fallout_shared/bgsdestructibleobjectform.cpp: BGSDestructibleObjectForm, TESObjectREFR, ActorValueOwner, TargetLocation (35 functions)

#include "bgsdestructibleobjectform_decls.h"

// @fnv 0x007038b0
void BGSDestructibleObjectForm::UpdateTargetHealthBar(TESObjectREFR* reference)
{
    HUDMainMenu::UpdateTargetActor(reinterpret_cast<Actor*>(reference));
}

// Returns the model path from GetTESModel(), or null if the reference has no model.
// @fnv 0x005715d0
const char* TESObjectREFR::GetModelFilePath()
{
    TESModel* model = GetTESModel();
    if (model)
        return model->GetPath();
    return 0;
}

// Returns the bound size of the object reference, or 0.0 if there is no object reference.
// @fnv 0x00571600
float TESObjectREFR::GetBoundingRadius()
{
    if (GetObjectReference())
        return GetObjectReference()->GetBoundSize();
    return 0.0f;
}

// Iterates all references in the reconstruct map and applies time-scaled damage to each non-disabled, non-deleted form, either directly or via the task queue.
// @fnv 0x004772f0
void BGSDestructibleObjectForm::UpdateDestructionMap()
{
    void* pIterPos;
    float fTime = g_timeGlobal.FUN_0084d030();
    pIterPos = ((BGSReconstructFormsInAllFilesMap*)&g_011c4104)->GetFirstPos();
    while (pIterPos)
    {
        TESForm* ref = 0;
        unsigned int value = 0;
        ((BGSReconstructFormsInAllFilesMap*)&g_011c4104)
            ->GetNext(pIterPos, (TESFile*&)ref, (BGSReconstructFormsInFileMap*&)value);
        if (ref && !ref->GetDisabled() && !ref->IsDeleted())
        {
            float damage = value * fTime;
            if (((SettingT_GameSettingCollection_*)&g_011c3ea4)->Int()->i == 1)
            {
                if (ref->IsActor())
                {
                    Actor* actor = (Actor*)ref;
                    actor->DamageHealthAndFatigue(damage, 0.0f, 0);
                }
                else
                    ref->UpdateDestructibleObject(damage, true);
            }
            else
                TaskQueueInterface::GetSingleton()->QueueReferenceFloatTask(ref, damage, true);
        }
    }
}

// @fnv 0x00571630
TESModel* TESObjectREFR::GetTESModel()
{
    TESModel* model = GetExtraData()->FUN_0042e250();
    if (!model && GetObjectReference())
    {
        if (GetObjectReference()->GetFormType() == 40)
        {
            TESObjectWEAP* weapon = (TESObjectWEAP*)GetObjectReference();
            if (GetExtraData()->GetWeaponModIndex())
                model = weapon->GetModTESModel(GetExtraData()->GetWeaponModIndex(), false);
            else
                model = weapon->GetWeaponModel();
        }
        else
            model = dynamic_cast<TESModel*>(GetObjectReference());
    }
    if (!model)
    {
        TESBipedModelForm* biped = TESBipedModelForm::GetFormAsBipedModel(GetObjectReference());
        if (biped)
        {
            TESForm* pActor;
            int uiSex = kMale;
            pActor = GetOwner();
            if (pActor && pActor->GetFormType() == 42)
                uiSex = ((TESActorBase*)pActor)->GetSex();
            model = biped->GetWeaponModel((SEX)uiSex);
        }
    }
    return model;
}

// Queues the model, explosion model and debris model of every stage in data for loading at the given priority.
// @fnv 0x00477640
void BGSDestructibleObjectForm::QueueResourceLoad(TESBoundObject* object, IO_TASK_PRIORITY priority, QueuedFile* file)
{
    if (!data)
        return;
    for (unsigned int i = 0; i < data->count; i++)
    {
        if (data->stages[i]->model)
            g_modelLoader->ProcessModelRequest(data->stages[i]->model, priority, file,
                                               TES::GetModelResourceType((TESObject*)object), true, false, false);
        if (data->stages[i]->explosion)
            data->stages[i]->explosion->model.QueueResourceLoad(priority, file);
        if (data->stages[i]->debris)
            data->stages[i]->debris->model.QueueResourceLoad(priority, file);
    }
}

// Returns an actor value by dispatching on the ActorValue::Index to the matching getter on the containing object.
// @fnv 0x005f0fb0
int ActorValueOwner::GetActorValue(ActorValue::Index value)
{
    int result = 0;
    switch (value)
    {
    case 5:
        result = ((TESAttributes*)((char*)this - 0x48))->GetAttributeValue5();
        break;
    case 6:
        result = ((TESAttributes*)((char*)this - 0x48))->FUN_005f1210();
        break;
    case 7:
        result = ((TESAttributes*)((char*)this - 0x48))->GetAttributeValue7();
        break;
    case 8:
        result = ((TESAttributes*)((char*)this - 0x48))->FUN_005f1250();
        break;
    case 9:
        result = ((TESAttributes*)((char*)this - 0x48))->FUN_005f1270();
        break;
    case 10:
        result = ((TESAttributes*)((char*)this - 0x48))->GetAttributeValue10();
        break;
    case 11:
        result = ((TESAttributes*)((char*)this - 0x48))->FUN_005f12b0();
        break;
    case 16:
        result = ((TESActorBase*)((char*)this - 0x100))->GetHealth();
        break;
    case 22:
        result = ((TESActorBaseData*)((char*)this - 0xd0))->vfn_060();
        break;
    case 0:
        result = ((PatrolActorPackageData*)((char*)this - 0x70))->IsPatrolling();
        break;
    case 57:
        result = ((TESAIForm*)((char*)this - 0x70))->GetAssistance();
        break;
    case 1:
        result = ((TESAIForm*)((char*)this - 0x70))->FUN_004f6de0();
        break;
    case 2:
        result = ((BSAudio*)((char*)this - 0x70))->FUN_005bb4d0();
        break;
    case 3:
        result = ((TESAIForm*)((char*)this - 0x70))->GetResponsibility();
        break;
    case 4:
        result = ((TESAIForm*)((char*)this - 0x70))->GetMood();
        break;
    case 21:
        result = ((TESActorBaseData*)((char*)this - 0xd0))->GetShortAtOffset12();
        break;
    case 23:
        result = (int)((TESActorBaseData*)((char*)this - 0xd0))->vfn_064();
        break;
    }
    return result;
}

// @fnv 0x00478be0
void BGSDestructibleObjectForm::InitItem(TESForm* owner)
{
    if (data)
    {
        for (unsigned int i = 0; i < data->count; i++)
        {
            if (data->stages[i]->explosion)
            {
                unsigned int explosionID = (unsigned int)data->stages[i]->explosion;
                TESForm::RemapFormIDForFile(explosionID, owner->GetFile(-1));
                data->stages[i]->explosion = dynamic_cast<BGSExplosion*>(TESForm::GetFormByID(explosionID));
                if (!data->stages[i]->explosion)
                {
                    if (owner)
                    {
                        if (((BGSCameraPath*)owner)->HasNameForWarning())
                            Warning("MASTERFILE: Unable to find stage %i explosion (%08X) on owner object \"%s\".", i,
                                    explosionID, owner->GetEditorID());
                        else
                            Warning("MASTERFILE: Unable to find stage %i explosion (%08X) on owner object (%08X).", i,
                                    explosionID, owner->GetFormID());
                    }
                    else
                        Warning("MASTERFILE: Unable to find stage %i explosion (%08X) on unknown owner.", i,
                                explosionID);
                }
            }
            if (data->stages[i]->debris)
            {
                unsigned int debrisID = (unsigned int)data->stages[i]->debris;
                TESForm::RemapFormIDForFile(debrisID, owner->GetFile(-1));
                data->stages[i]->debris = dynamic_cast<BGSDebris*>(TESForm::GetFormByID(debrisID));
                if (!data->stages[i]->debris)
                {
                    if (owner)
                    {
                        if (((BGSCameraPath*)owner)->HasNameForWarning())
                            Warning("MASTERFILE: Unable to find stage %i debris (%08X) on owner object \"%s\".", i,
                                    debrisID, owner->GetEditorID());
                        else
                            Warning("MASTERFILE: Unable to find stage %i debris (%08X) on owner object (%08X).", i,
                                    debrisID, owner->GetFormID());
                    }
                    else
                        Warning("MASTERFILE: Unable to find stage %i debris (%08X) on unknown owner.", i, debrisID);
                }
            }
            if (data->stages[i]->model)
                ((TESModelTextureSwap*)data->stages[i]->model)->InitItem(owner);
        }
        switch (owner->GetFormType())
        {
        case 42:
        case 43: {
            TESActorBase* actor = (TESActorBase*)owner;
            data->health = actor->GetHealth();
            break;
        }
        }
    }
}

// @fnv 0x0045bb80
int __fastcall FUN_0045bb80(int param_1)
{
    return param_1 + 0x8C;
}

// @fnv 0x00461130
int __fastcall FUN_00461130(int pThis)
{
    return pThis + 0x68;
}

class BaseFormComponent
{
  public:
    BaseFormComponent();
};

extern int DAT_0101a4c4;
void __fastcall FUN_008c6060(void* pThis);

// Initialises the BaseFormComponent at pThis, sets its vtable to DAT_0101a4c4, calls FUN_008c6060, and returns pThis.
// @fnv 0x00475350
void* __fastcall FUN_00475350(void* pThis)
{
    ((BaseFormComponent*)pThis)->BaseFormComponent::BaseFormComponent();
    *(int**)pThis = &DAT_0101a4c4;
    FUN_008c6060(pThis);
    return pThis;
}

struct FUN_00475380_shell : public BGSDestructibleObjectForm
{
    void FUN_00475380();
};

extern int DAT_0101a6a0;
void __fastcall ClearDataComponent(void* pThis);

// @fnv 0x00475380
void FUN_00475380_shell::FUN_00475380()
{
    *reinterpret_cast<int**>(this) = &DAT_0101a6a0;
    ClearDataComponent(this);
}

struct DestructionStageData
{
    void CreateReplacementModel();
    void Copy(DestructionStageData*);
    void CheckReplacementModel();
    bool GetCapDamage();
    void SetCapDamage(bool);
    bool GetDisableObject();
    void SetDisableObject(bool);
    bool GetDestroyObject();
    void SetDestroyObject(bool);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucHealthPercentage;
    unsigned char m_ucStageIndex;
    unsigned char cFlags;
    char _pad_3[1];
    unsigned int m_uiSelfDamagePerSecond;
    BGSExplosion* m_pDebrisObject;
    BGSDebris* m_pDebris;
    unsigned int m_uiDebrisCount;
    TESModelTextureSwap* m_pReplacementModel;
};
typedef char _sizecheck_DestructibleObjectStage[sizeof(DestructionStageData) == 24 ? 1 : -1];
struct FUN_00475a00_shell : public BGSDestructibleObjectForm
{
    bool FUN_00475a00();
};

struct DestructibleObjectData_local
{
    unsigned int m_uiHealthValue;
    unsigned char m_ucStageCount;
    unsigned char cFlags;
    char _pad[2];
    DestructionStageData** pStageArray;
};

bool __fastcall IsFlag2Set(DestructionStageData*);

// Returns true if any stage of the destructible object data has a model texture swap, explosion, debris, or passes IsFlag2Set.
// @fnv 0x00475a00
bool FUN_00475a00_shell::FUN_00475a00()
{
    if (!*(DestructibleObjectData_local**)((char*)this + 4))
    {
        return false;
    }
    for (unsigned int i = 0; i < (*(DestructibleObjectData_local**)((char*)this + 4))->m_ucStageCount; ++i)
    {
        DestructionStageData* pstage = (*(DestructibleObjectData_local**)((char*)this + 4))->pStageArray[i];
        if (pstage)
        {
            if (pstage->m_pReplacementModel || pstage->m_pDebrisObject || pstage->m_pDebris || IsFlag2Set(pstage))
            {
                return true;
            }
        }
    }
    return false;
}

struct FUN_00476980_S
{
    void FUN_004769c0(int, int);
    FUN_00476980_S* FUN_00476980(int a, int b, int c);
};
// @fnv 0x00476980
FUN_00476980_S* FUN_00476980_S::FUN_00476980(int aiValue0, int aiValue1, int aiValue2)
{
    FUN_004769c0(0, aiValue0);
    FUN_004769c0(1, aiValue1);
    FUN_004769c0(2, aiValue2);
    return this;
}

void __fastcall _ref_006815c0(void*);

struct _dummy_476a80
{
    char pad[0x24];
    _dummy_476a80* FUN_00476a80();
};

// @fnv 0x00476a80
_dummy_476a80* _dummy_476a80::FUN_00476a80()
{
    _ref_006815c0(this);
    _ref_006815c0((char*)this + 0x24);
    return this;
}

struct BSFadeNode_Dummy
{
    char pad[0xb4];
    float f1;
    float f2;
};

void __cdecl FUN_00476ae0();

// Sets the fade node's two float fields to 1.0 and calls FUN_00476ae0 with true.
// @fnv 0x00476ab0
void __fastcall FUN_00476ab0(BSFadeNode_Dummy* pThis)
{
    pThis->f2 = 1.0f;
    pThis->f1 = 1.0f;
    typedef void(__thiscall * Fn)(BSFadeNode_Dummy*, bool);
    ((Fn)&FUN_00476ae0)(pThis, true);
}

struct MersenneTwister
{
    void Init(unsigned int);
    void Seed(unsigned int);
    void Kill();
    unsigned int GetRandomUInt(unsigned int, unsigned int);
    unsigned int GetRandomUInt();
    unsigned int GetRandomUInt(unsigned int);
    int Int(int, int);
    int Int();
    float Float(float, float);
    float Float0To1();
    float FloatNeg1To1();
    float FloatTwoPi();
    float FloatNegPiToPi();
    bool Bool(float);
    static MersenneTwister* GetRandomGenerator();
    unsigned int m_uiSeed;
    unsigned int m_uiLastValue;
    char mt[2496];
    unsigned int mti;
};
typedef char _sizecheck_BSRandom[sizeof(MersenneTwister) == 2508 ? 1 : -1];
struct FUN_00476b90_shell : public MersenneTwister
{
    float FUN_00476b90(float, float);
};

// @fnv 0x00476b90
float FUN_00476b90_shell::FUN_00476b90(float afMin, float afMax)
{
    unsigned int r = GetRandomUInt();
    return (float)(r * (afMax - afMin) / 4294967296.0 + afMin);
}

struct FUN_00477ba0_shell : public TESForm
{
    bool FUN_00477ba0();
};

// @fnv 0x00477ba0
bool FUN_00477ba0_shell::FUN_00477ba0()
{
    return (*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 8) & 0x800000) ? true : false;
}

struct FUN_005df560_S
{
    void GetRowFloats(unsigned int row, float* a, float* b, float* c);
};
// Reads three consecutive floats at offset row*12 from this and writes them to the three output pointers.
// @fnv 0x005df560
void FUN_005df560_S::GetRowFloats(unsigned int row, float* pfOut0, float* pfOut1, float* pfOut2)
{
    *pfOut0 = *(float*)((char*)this + row * 12);
    *pfOut1 = *(float*)((char*)this + row * 12 + 4);
    *pfOut2 = *(float*)((char*)this + row * 12 + 8);
}

namespace fnv_004753d0 {
extern "C" void* __cdecl FUN_00475400(void*);

struct FUN_00475a00_shell
{
    bool FUN_00475a00(void);
};

// Looks up the destructible wrapper for apForm via FUN_00475400 and returns its FUN_00475a00 result, or false if no wrapper exists.
// @fnv 0x004753d0
bool FUN_004753d0(void* apForm)
{
    FUN_00475a00_shell* pWrapper = (FUN_00475a00_shell*)FUN_00475400(apForm);
    if (!pWrapper)
    {
        return false;
    }
    return pWrapper->FUN_00475a00();
}
}  // namespace fnv_004753d0

struct MapH
{
    bool RemoveAt(unsigned int);
};

// @fnv 0x00477410
void FUN_00477410(unsigned int index)
{
    ((MapH*)&g_011c4104)->RemoveAt(index);
}

namespace fnv_00477ce0 {
struct MapH
{
    bool RemoveAt(unsigned int);
};

struct DummyPointerMap
{
    void SetAt(unsigned int, unsigned int);
};

// If a2 is zero, removes the entry for a1 from g_011c4104; otherwise sets a1 to a2 in that map.
// @fnv 0x00477ce0
void __cdecl SetOrRemoveMapEntry(unsigned int uiKey, unsigned int uiValue)
{
    if (uiValue == 0)
    {
        ((MapH*)&g_011c4104)->RemoveAt(uiKey);
    }
    else
    {
        ((DummyPointerMap*)&g_011c4104)->SetAt(uiKey, uiValue);
    }
}
}  // namespace fnv_00477ce0

struct FUN_004759a0_Elem
{
    char _pad[20];
    int value;
};
struct FUN_004759a0_Mid
{
    char _pad0[4];
    unsigned char cnt;
    FUN_004759a0_Elem** arr;
};
struct FUN_004759a0_First
{
    FUN_004759a0_Mid* _ref_00726070();
};
FUN_004759a0_First* __cdecl FUN_00475400(void*);
// @fnv 0x004759a0
int __cdecl GetElementValue(void* a, int aiIndex)
{
    FUN_004759a0_First* pFirst = FUN_00475400(a);
    if (!pFirst || aiIndex == -1)
        return 0;
    {
        FUN_004759a0_Mid* q = pFirst->_ref_00726070();
        if (!q)
            return 0;
        if (aiIndex < q->cnt)
            return q->arr[aiIndex]->value;
        return 0;
    }
}

int __cdecl FinishScriptRunLock(void*);
struct Flt
{
    operator unsigned int() const;
};
struct QIdle;
struct QIdlePtr
{
    QIdlePtr& operator=(QIdle*);
};
struct FUN_004778a0_Mid
{
    char pad[12];
    int lock;
    union
    {
        Flt f;
        QIdlePtr q;
    };
};
struct FUN_004778a0_cls
{
    int _0;
    FUN_004778a0_Mid* _4;
    void ReleaseScriptRunLock();
};
// @fnv 0x004778a0
void FUN_004778a0_cls::ReleaseScriptRunLock()
{
    if (!_4)
        return;
    if ((unsigned int)(_4->f))
    {
        FinishScriptRunLock(&(_4->lock));
        if (_4->lock <= 0)
            _4->q = 0;
    }
}

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting818;
struct Standin77900
{
    bool HasAnyFlags(int);
    float GetRadiusBSUnits();
};
// Returns the float at offset 0x7c, multiplied by originalRuntimeFloatSetting818.Float() when HasAnyFlags(1) is false.
// @fnv 0x00477900
float Standin77900::GetRadiusBSUnits()
{
    return (float)(HasAnyFlags(1) ? (double)*(float*)((char*)this + 0x7c)
                                  : (double)(*(float*)((char*)this + 0x7c) * *originalRuntimeFloatSetting818.Float()));
}

struct NiAVObject;
struct bhkWorldObject;

struct NiNode
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int index);
};

struct H0043b4d0
{
    int value;
    int FUN_0043b4d0();
};

struct W_0043b4f0
{
    H0043b4d0 FUN_0043b4f0();
};

struct bhkCollisionObject
{
    static bhkCollisionObject* __cdecl GetFromNiAVObject(NiAVObject* object);
    bhkWorldObject* FUN_006fa820();
};

struct LodObject
{
    void SetAppCulled(bool culled);
};

struct NiAVObjectAccess
{
    virtual void FUN_00477560_dummy1() = 0;
    virtual void FUN_00477560_dummy2() = 0;
    virtual void FUN_00477560_dummy3() = 0;
    virtual NiNode* FUN_00477560_GetNode() = 0;
};

// If object has a collision object whose world object type is 19, sets it app-culled and returns true; otherwise recurses into child nodes.
// @fnv 0x00477560
bool __cdecl FUN_00477560(NiAVObject* object)
{
    bool result = false;

    if (object)
    {
        bool bIsLodObject = false;
        bhkCollisionObject* collisionObject = bhkCollisionObject::GetFromNiAVObject(object);

        if (collisionObject)
        {
            bhkWorldObject* worldObject = collisionObject->FUN_006fa820();

            if (worldObject)
            {
                if (reinterpret_cast<W_0043b4f0*>(worldObject)->FUN_0043b4f0().FUN_0043b4d0() == 19)
                    bIsLodObject = true;
            }
        }

        if (bIsLodObject)
        {
            result = true;
            reinterpret_cast<LodObject*>(object)->SetAppCulled(true);
        }
        else
        {
            NiNode* node = reinterpret_cast<NiAVObjectAccess*>(object)->FUN_00477560_GetNode();

            if (node)
            {
                unsigned int count = node->GetNumChildren();

                for (unsigned int index = 0; index < count; ++index)
                {
                    if (FUN_00477560(node->GetAt(index)))
                        result = true;
                }
            }
        }
    }

    return result;
}

class FUN_00475ab0_emb
{
  public:
    virtual void v0();
    virtual float v1(int);
};

struct FUN_00475ab0_ref
{
    char _pad0[0xa4];
    FUN_00475ab0_emb m_a4;
};

struct FUN_00475ab0_data
{
    unsigned int health;
};

class FUN_00475ab0_cls
{
  public:
    void* vtable;
    FUN_00475ab0_data* data;
    unsigned int GetMaxHealth(TESForm* a1);
};

// @fnv 0x00475ab0
unsigned int FUN_00475ab0_cls::GetMaxHealth(TESForm* pForm)
{
    if (pForm->IsActor())
    {
        FUN_00475ab0_ref* ref = reinterpret_cast<FUN_00475ab0_ref*>(pForm);
        return (unsigned int)ref->m_a4.v1(0x10);
    }
    return data->health;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
    static const NiPoint3 ZERO;
};

struct NiBound
{
    const NiPoint3& GetNavMeshData() const;
};

struct NiAVObject
{
    const NiBound& GetBoundingVolume() const;
};

struct BSStringT
{
    int unk00;
    operator const char*() const;
};

struct NamedTarget
{
    NiPoint3 GetTargetPos(void* pArg);
};

NamedTarget* __fastcall LookupNamedTarget(const char* pName);

struct PosRef
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
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
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual NiAVObject* Get3D();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual const NiPoint3* GetPos();
};

struct TargetLocation
{
    PosRef* pRef;
    BSStringT kName;
    int unk08;
    NiPoint3 GetTargetPosition();
};

// Returns the target position from the named target if kName is set, otherwise from pRef's 3D bound or its GetPos.
// @fnv 0x009c5f30
NiPoint3 TargetLocation::GetTargetPosition()
{
    NiPoint3 kPos = NiPoint3::ZERO;
    if ((const char*)kName)
    {
        kPos = LookupNamedTarget(kName)->GetTargetPos(&unk08);
    }
    else if (pRef)
    {
        if (pRef->Get3D())
        {
            kPos = pRef->Get3D()->GetBoundingVolume().GetNavMeshData();
        }
        else
        {
            kPos = *pRef->GetPos();
        }
    }
    return kPos;
}

struct Fields_c
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
struct Fields_54
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
};
struct Fields_58
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
};
struct Fields_64
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
};
struct Fields_68
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
};
struct Fields_74
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
};
struct Fields_7c
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
};
struct Fields_84
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
};
struct Fields_88
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
};
struct Fields_94
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
};
struct Fields_9c
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
};
struct Fields_a4
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
};
struct Fields_b4
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
};
struct Fields_104
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
    unsigned int unkfc;
    unsigned int unk100;
};
struct Fields_144
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
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
};
struct Fields_14c
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
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
};
struct Form1d : Fields_94, BGSDestructibleObjectForm
{
};
struct Form2f : Fields_a4, BGSDestructibleObjectForm
{
};
struct Form28 : Fields_b4, BGSDestructibleObjectForm
{
};
struct Form1f : Fields_84, BGSDestructibleObjectForm
{
};
struct Form1b : Fields_7c, BGSDestructibleObjectForm
{
};
struct Form1a : Fields_144, BGSDestructibleObjectForm
{
};
struct Form19 : Fields_9c, BGSDestructibleObjectForm
{
};
struct Form18 : Fields_14c, BGSDestructibleObjectForm
{
};
struct Form1e : Fields_94, BGSDestructibleObjectForm
{
};
struct Form27 : Fields_68, BGSDestructibleObjectForm
{
};
struct Form29 : Fields_88, BGSDestructibleObjectForm
{
};
struct Form15 : Fields_68, BGSDestructibleObjectForm
{
};
struct Input22
{
    unsigned int unk00;
};
struct Form22 : Fields_c, BGSDestructibleObjectForm, Input22
{
};
struct Form25 : Fields_54, BGSDestructibleObjectForm
{
};
struct Input26
{
    unsigned int unk00;
};
struct Form26 : Fields_c, Input26, Fields_64, BGSDestructibleObjectForm
{
};
struct Form1c : Fields_68, BGSDestructibleObjectForm
{
};
struct Form16 : Fields_68, BGSDestructibleObjectForm
{
};
struct Form17 : Fields_68, BGSDestructibleObjectForm
{
};
struct Form33 : Fields_58, BGSDestructibleObjectForm
{
};
struct Form2a : Fields_104, BGSDestructibleObjectForm
{
};
struct Form2b : Fields_104, BGSDestructibleObjectForm
{
};
// Returns the form cast to BGSDestructibleObjectForm for supported form types, or null if the form is null or unsupported.
// @fnv 0x00475400
FUN_004759a0_First* __cdecl FUN_00475400(void* form)
{
    BGSDestructibleObjectForm* result = 0;
    if (form)
    {
        switch (static_cast<TESForm*>(form)->GetFormType())
        {
        case 0x1d: {
            Form1d* object = static_cast<Form1d*>(form);
            result = object;
            break;
        }
        case 0x2f: {
            Form2f* object = static_cast<Form2f*>(form);
            result = object;
            break;
        }
        case 0x28: {
            Form28* object = static_cast<Form28*>(form);
            result = object;
            break;
        }
        case 0x1f:
        case 0x2e:
        case 0x32:
        case 0x67: {
            Form1f* object = static_cast<Form1f*>(form);
            result = object;
            break;
        }
        case 0x1b: {
            Form1b* object = static_cast<Form1b*>(form);
            result = object;
            break;
        }
        case 0x1a: {
            Form1a* object = static_cast<Form1a*>(form);
            result = object;
            break;
        }
        case 0x19: {
            Form19* object = static_cast<Form19*>(form);
            result = object;
            break;
        }
        case 0x18: {
            Form18* object = static_cast<Form18*>(form);
            result = object;
            break;
        }
        case 0x1e: {
            Form1e* object = static_cast<Form1e*>(form);
            result = object;
            break;
        }
        case 0x27: {
            Form27* object = static_cast<Form27*>(form);
            result = object;
            break;
        }
        case 0x29: {
            Form29* object = static_cast<Form29*>(form);
            result = object;
            break;
        }
        case 0x15: {
            Form15* object = static_cast<Form15*>(form);
            result = object;
            break;
        }
        case 0x22: {
            Form22* object = static_cast<Form22*>(static_cast<Input22*>(form));
            result = object;
            break;
        }
        case 0x25: {
            Form25* object = static_cast<Form25*>(form);
            result = object;
            break;
        }
        case 0x26: {
            Form26* object = static_cast<Form26*>(static_cast<Input26*>(form));
            result = object;
            break;
        }
        case 0x1c: {
            Form1c* object = static_cast<Form1c*>(form);
            result = object;
            break;
        }
        case 0x16: {
            Form16* object = static_cast<Form16*>(form);
            result = object;
            break;
        }
        case 0x17: {
            Form17* object = static_cast<Form17*>(form);
            result = object;
            break;
        }
        case 0x33: {
            Form33* object = static_cast<Form33*>(form);
            result = object;
            break;
        }
        case 0x2a: {
            Form2a* object = static_cast<Form2a*>(form);
            result = object;
            break;
        }
        case 0x2b: {
            Form2b* object = static_cast<Form2b*>(form);
            result = object;
            break;
        }
        }
    }
    return reinterpret_cast<FUN_004759a0_First*>(result);
}

// Looks up a1's owner, scans its list for an entry whose value equals a2, and returns its index or -1 if not found.
// @fnv 0x00475920
int FindIndexByValue(void* a1, unsigned int aiValue)
{
    FUN_004759a0_First* pOwner = FUN_00475400(a1);
    if (pOwner == 0)
    {
        return -1;
    }
    FUN_004759a0_Mid* pList = pOwner->_ref_00726070();
    if (pList == 0)
    {
        return -1;
    }
    for (unsigned int i = 0; i < pList->cnt; i++)
    {
        if (pList->arr[i]->value == (int)aiValue)
        {
            return i;
        }
    }
    return -1;
}

struct FUN_0041b6b0_shell
{
    float FUN_0041b6b0();
};
float __cdecl FUN_00476b20(float);

// @fnv 0x00477430
int __cdecl CalcDestructionStage(TESObjectREFR* ref)
{
    int iStage = -1;
    if (ref)
    {
        FUN_004759a0_First* pForm = FUN_00475400(ref->GetObjectReference());
        FUN_004759a0_Mid* pData = pForm ? pForm->_ref_00726070() : 0;
        if (pData)
        {
            float fExtraValue = ((FUN_0041b6b0_shell*)ref->GetExtraData())->FUN_0041b6b0();
            if (fExtraValue != -1.0)
            {
                unsigned char cPct = (unsigned char)FUN_00476b20(
                    (float)(fExtraValue * 100.0 / ((FUN_00475ab0_cls*)pForm)->GetMaxHealth((TESForm*)ref)));
                iStage = pData->cnt;
                for (int i = 0; i < pData->cnt; i++)
                {
                    if (((DestructionStageData*)pData->arr[i])->m_ucStageIndex < cPct)
                    {
                        iStage = i;
                        break;
                    }
                }
            }
        }
    }
    return iStage;
}

struct FadeNodeView
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual BSFadeNode_Dummy* AsFadeNode();
};
struct SceneObjectView
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual FadeNodeView* AsNode();
};
struct ReferenceView
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
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
    virtual void Reset3D(int, bool);
    virtual SceneObjectView* Get3D();
    bool FUN_00452370() const;
    ExtraDataList* FUN_005d43c0();
    void FUN_00573f40();
};
struct ExtraHealthView
{
    float FUN_0041b6b0();
    void RemoveExtraType86();
    void RemoveExtra5B();
};
struct SaveLoadView
{
    bool FUN_004623f0(bool);
};
struct WorldView
{
    void FUN_00451ef0(ReferenceView*, void*, int, int);
};
struct GlobalView
{
    void RemoveKey(ReferenceView*);
};
struct FinalView
{
    void RemoveEntryForRef();
};
struct ManagerView
{
    FinalView* FUN_00825c00(ReferenceView*);
};
extern SaveLoadView* DAT_011ddf38;
extern WorldView* DAT_011dea10;
extern ManagerView* DAT_011f1958;
void __cdecl FUN_00c6a270(SceneObjectView*, bool, bool, int);
void __cdecl FUN_00476ec0(NiAVObject*, int);

struct ParentCellView
{
    void* FUN_008d6f30();
};
struct Simple3DView
{
    NiAVObject* FUN_0043fcd0();
};
struct FormView
{
    void FUN_00484650(bool);
};

// @fnv 0x00477d10
void __cdecl ClearDestruction(ReferenceView* reference)
{
    if (!reference->FUN_00452370())
        return;
    FUN_004759a0_First* destructible = FUN_00475400(reinterpret_cast<TESObjectREFR*>(reference)->GetObjectReference());
    float health = reinterpret_cast<ExtraHealthView*>(reference->FUN_005d43c0())->FUN_0041b6b0();
    if (health == -1.0)
        return;
    reinterpret_cast<ExtraHealthView*>(reference->FUN_005d43c0())->RemoveExtraType86();
    if (reinterpret_cast<FUN_00477ba0_shell*>(reference)->FUN_00477ba0())
        reinterpret_cast<FormView*>(reference)->FUN_00484650(false);
    if (reference->FUN_005d43c0()->FUN_0042e250())
    {
        reinterpret_cast<ExtraHealthView*>(reference->FUN_005d43c0())->RemoveExtra5B();
        if (reference->Get3D())
        {
            bool allowChanges = DAT_011ddf38->FUN_004623f0(false);
            reference->Reset3D(0, true);
            DAT_011ddf38->FUN_004623f0(allowChanges);
            DAT_011dea10->FUN_00451ef0(reference, reinterpret_cast<ParentCellView*>(reference)->FUN_008d6f30(), 0, 0);
            if (reference->Get3D())
            {
                SceneObjectView* object = reference->Get3D();
                FadeNodeView* fade = object ? object->AsNode() : 0;
                BSFadeNode_Dummy* node = fade ? fade->AsFadeNode() : 0;
                if (node)
                    FUN_00476ab0(node);
                FUN_00c6a270(object, true, true, 0);
            }
        }
    }
    else if (reference->Get3D())
    {
        FUN_00476ec0(reinterpret_cast<Simple3DView*>(reference)->FUN_0043fcd0(), 0);
    }
    if (reinterpret_cast<TESForm*>(reference)->GetDisabled())
        reference->FUN_00573f40();
    reinterpret_cast<GlobalView*>(&g_011c4104)->RemoveKey(reference);
    DAT_011f1958->FUN_00825c00(reference)->RemoveEntryForRef();
}

unsigned char __cdecl FUN_00401500();
void __cdecl AppendChunk(unsigned int auiType, char* apData, unsigned int auiSize);
void __cdecl FUN_00403d30(void* apDst, int aiValue, unsigned int auiSize);
void __cdecl FUN_004856d0(int aiType);

struct FUN_0084e3a0_sound
{
    unsigned int FUN_0084e3a0();
};

struct FUN_0048a520_obj
{
    void ProcessAndFreeData(unsigned int a1, unsigned int a2, unsigned int a3);
};

struct FUN_00477f20_src
{
    unsigned char ucByte0;
    unsigned char ucByte1;
    unsigned char ucByte2;
    unsigned char ucByte3;
    unsigned int uiValue4;
    FUN_0084e3a0_sound* pSound8;
    FUN_0084e3a0_sound* pSoundC;
    unsigned int uiValue10;
    FUN_0048a520_obj* pObj14;
};

struct FUN_00477f20_data
{
    unsigned int uiValue;
    unsigned char ucCount;
    unsigned char ucFlag;
    FUN_00477f20_src** ppEntries;
};

struct FUN_004781b0
{
    unsigned int uiValue;
    unsigned char ucCount;
    unsigned char ucFlag;
    FUN_004781b0();
    void FUN_00503210();
};

struct FUN_00478130_entry
{
    unsigned char ucByte0;
    unsigned char m_ucClipIdentifier;
    unsigned char ucByte2;
    unsigned char ucByte3;
    unsigned int uiValue4;
    unsigned int uiSound8;
    unsigned int uiSoundC;
    unsigned int uiValue10;
    void Endian();
};

struct FUN_00477f20_shell
{
    int iUnk0;
    FUN_00477f20_data* pData;
    void FUN_00477f20();
};

// @fnv 0x00477f20
void FUN_00477f20_shell::FUN_00477f20()
{
    if (pData)
    {
        FUN_004781b0 kHeader;
        kHeader.uiValue = pData->uiValue;
        kHeader.ucCount = pData->ucCount;
        kHeader.ucFlag = pData->ucFlag;
        if (FUN_00401500())
            kHeader.FUN_00503210();
        AppendChunk(0x54534544, (char*)&kHeader, 8);
        if (FUN_00401500())
            kHeader.FUN_00503210();

        for (unsigned int i = 0; i < pData->ucCount; i++)
        {
            FUN_00478130_entry kEntry;
            FUN_00403d30(&kEntry, 0, 0x14);
            kEntry.m_ucClipIdentifier = i;
            kEntry.ucByte0 = pData->ppEntries[i]->ucByte1;
            kEntry.uiValue4 = pData->ppEntries[i]->uiValue4;
            kEntry.ucByte2 = pData->ppEntries[i]->ucByte0;
            kEntry.ucByte3 = pData->ppEntries[i]->ucByte2;
            kEntry.uiValue10 = pData->ppEntries[i]->uiValue10;
            if (pData->ppEntries[i]->pSound8)
                kEntry.uiSound8 = pData->ppEntries[i]->pSound8->FUN_0084e3a0();
            if (pData->ppEntries[i]->pSoundC)
                kEntry.uiSoundC = pData->ppEntries[i]->pSoundC->FUN_0084e3a0();
            if (FUN_00401500())
                kEntry.Endian();
            AppendChunk(0x44545344, (char*)&kEntry, 0x14);
            if (FUN_00401500())
                kEntry.Endian();
            if (pData->ppEntries[i]->pObj14)
                pData->ppEntries[i]->pObj14->ProcessAndFreeData(0x4c444d44, 0x54444d44, 0x53444d44);
            FUN_004856d0(0x46545344);
        }
    }
}

extern double DAT_01012060;
extern double DAT_01017a40;

struct MyDestructionStage
{
    unsigned char stage;
    unsigned char healthPercentage;
    unsigned char unk02;
    unsigned char unk03;
    unsigned int selfDamagePerSecond;
    BGSExplosion* explosion;
    BGSDebris* debris;
    unsigned int count;
    TESModel* model;
};

struct MyDestructibleData
{
    unsigned int health;
    unsigned char count;
    unsigned char flags;
    unsigned short pad;
    MyDestructionStage** stages;
};

struct DestructibleFormStandin
{
    MyDestructibleData* GetDestructibleData();
    unsigned int GetHealth(TESObjectREFR* refr);
};

extern "C" DestructibleFormStandin* __cdecl FUN_00475400(TESBoundObject*);
float __cdecl FUN_00476b20(float);

// @fnv 0x00477bc0
unsigned int __cdecl GetDestructionStageSelfDamage(TESObjectREFR* refr, float damage)
{
    if (refr == 0 || damage == DAT_01012060)
        return 0;

    DestructibleFormStandin* aActorData = FUN_00475400(refr->GetObjectReference());
    if (aActorData == 0)
        return 0;

    MyDestructibleData* data = aActorData->GetDestructibleData();
    if (data == 0)
        return 0;

    unsigned int health = aActorData->GetHealth(refr);
    unsigned char aAPGeom = (unsigned char)FUN_00476b20((damage * DAT_01017a40) / (float)health);

    unsigned int aActorMesh = 0;
    unsigned int aAOriginal = 0;
    for (unsigned int i = 0; i < data->count; ++i)
    {
        MyDestructionStage* stage = data->stages[i];
        if (stage->healthPercentage >= aAPGeom)
        {
            aActorMesh = stage->selfDamagePerSecond;
        }
        else
        {
            break;
        }
    }
    return aActorMesh;
}

// A 40-byte allocation view for the queued-file constructor call.

struct GO
{
    operator unsigned int() const;
    int GetObjectFlags();
};

struct QIdlePtrSV : public GO
{
    QIdlePtrSV& operator=(void*);
};

struct FUN_00c3c590_QueuedFile
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;

    FUN_00c3c590_QueuedFile(int);
};

int __cdecl InitScriptRunLock(void*);
void* __cdecl operator new(unsigned int);

struct FUN_00477780_shell : public ::BGSDestructibleObjectForm
{
    void FUN_00477780(::TESBoundObject*);
};

// @fnv 0x00477780
void FUN_00477780_shell::FUN_00477780(::TESBoundObject* apBoundObject)
{
    if (!data)
        return;

    if (!reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(data) + 0x10)->GO::operator unsigned int())
    {
        reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(data) + 0x10)
            ->
            operator=(new FUN_00c3c590_QueuedFile(5));

        QueueResourceLoad(apBoundObject, static_cast< ::IO_TASK_PRIORITY>(5),
                          reinterpret_cast< ::QueuedFile*>(
                              reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(data) + 0x10)
                                  ->GO::operator unsigned int()));

        if (!reinterpret_cast<GO*>(reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(data) + 0x10)
                                       ->GO::operator unsigned int())
                 ->GetObjectFlags())
        {
            reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(data) + 0x10)->operator=(0);
        }
    }

    if (reinterpret_cast<QIdlePtrSV*>(reinterpret_cast<unsigned char*>(data) + 0x10)->GO::operator unsigned int())
    {
        InitScriptRunLock(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(data) + 0xc));
    }
}

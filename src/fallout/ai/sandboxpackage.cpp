
// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/sandboxpackage.cpp
#include "sandboxpackage_idle.h"

// If the location has a valid timestamp that has passed, follows its linked reference and stores it as the new location, resetting the timestamp.
// @fnv 0x009f3c10
bool SandBoxActorPackageData::IsLocationCheckDue()
{
    if (pLocation != NULL && m_uiLastProcedureCheckDay != 0xFFFFFFFF)
    {
        unsigned int uiNow = g_timeGlobal.GetTimeStamp();
        if (uiNow > m_uiLastProcedureCheckDay)
        {
            TESObjectREFR* pNext = ((ExtraDataListHelper*)pLocation->GetExtraData())->GetLinkedRef();
            if (pNext != NULL && pNext != pLocation)
            {
                pLocation = pNext;
                m_uiLastProcedureCheckDay = 0xFFFFFFFF;
                return true;
            }
        }
    }
    return false;
}

// Checks whether the sandbox activity is currently active by comparing the current day and hour against the activity's start day/hour and computed end day/hour.
// @fnv 0x009f3d50
bool SandBoxActorPackageData::IsActivityTime()
{
    float fEndHour;
    {
        unsigned int uiDay = g_calendar.GetDaysPassed();
        {
            float fHour = g_calendar.GetGameTime();
            {
                bool bLastDay = false;
                if (m_eSandboxActivity == SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_NONE)
                    return true;
                {
                    unsigned int uiEndDay;
                    uiEndDay = m_uiActivityEndDay;
                    fEndHour = m_fActivityStartHour + m_fActivityEndHour;
                    while (fEndHour >= 24.0)
                    {
                        fEndHour -= 24.0;
                        uiEndDay++;
                    }
                    if (uiDay < m_uiActivityEndDay || uiDay > uiEndDay)
                        return false;
                    if (uiDay == m_uiActivityEndDay && fHour < m_fActivityStartHour)
                        return false;
                    if (uiDay == uiEndDay && fHour >= fEndHour)
                        return false;
                }
                return true;
            }
        }
    }
}

// @fnv 0x009f40c0
void SandBoxActorPackageData::SetReferenceTarget(TESObjectREFR* apDeletedRef)
{
    if (apDeletedRef == NULL)
        return;
    {
        int iCount;
        {
            int iIndex;
            {
                bool bReset = false;
                if (pLocation == apDeletedRef)
                    pLocation = NULL;
                if (m_pCurrentFurniture == apDeletedRef)
                    m_pCurrentFurniture = NULL;
                if (m_pCurrentTarget == apDeletedRef)
                    bReset = true;
                iCount = m_kProcedureList.GetSize();
                iIndex = 0;
                while (iIndex < iCount)
                {
                    if (m_kProcedureList.GetAt(iIndex).GetTarget() == apDeletedRef)
                    {
                        bReset = true;
                        ((SandboxChoiceArray*)&m_kProcedureList)->RemoveAt(iIndex, 1);
                        iCount--;
                    }
                    else
                    {
                        iIndex++;
                    }
                }
                if (bReset)
                {
                    eProcedure = SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_NONE;
                    m_fProcedureTime = 0.0F;
                    m_pCurrentTarget = NULL;
                    m_pCurrentFurniture = NULL;
                    m_ucProcedureIndex = 0x7F;
                    m_bNeedsSandboxUpdate = true;
                    m_uiProcedureIndex = 0;
                }
            }
        }
    }
}

// Checks the current sandbox target and markers, clears stale flags, and returns whether a new target should be picked based on timers, state and hour difference.
// @fnv 0x009f43c0
bool SandBoxActorPackageData::HasProcessTarget(Actor* apActor)
{
    {
        SandboxTargetInfo* pTargetInfo = ((ActorTargetSource*)apActor)->GetProcessTarget();
        {
            float fValue;
            {
                bool bPickNew;
                if (pTargetInfo != NULL)
                {
                    {
                        bool bChanged = false;
                        if (m_bHasBedMarker && !pTargetInfo->CheckBedMarker())
                        {
                            m_bHasBedMarker = false;
                            bChanged = true;
                        }
                        if (m_bHasFoodMarker && !pTargetInfo->CheckFoodMarker())
                        {
                            m_bHasFoodMarker = false;
                            bChanged = true;
                        }
                        if (m_bHasChairMarker && !pTargetInfo->CheckChairMarker())
                        {
                            m_bHasChairMarker = false;
                            bChanged = true;
                        }
                        if (bChanged)
                        {
                            m_uiProcedureIndex = g_timeGlobal.GetTimeStamp();
                            return true;
                        }
                    }
                }
                if (pLocation != NULL && eProcedure != SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_USE_IDLE_MARKER &&
                    m_uiLastProcedureCheckDay != 0xFFFFFFFF)
                {
                    if (g_timeGlobal.GetTimeStamp() > m_uiLastProcedureCheckDay)
                        return true;
                }
                if (!IsActorWithinLocationRadius(apActor, true))
                    return false;
                if (m_bNeedsSandboxUpdate)
                    return true;
                if (eProcedure == SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_NONE || m_fProcedureTime <= 0.0)
                    return true;
                if (m_fNextProcedureCheckHour == 0.0)
                    return true;
                if (eState != SandBoxActorPackageData__SANDBOX_STATE_SANDBOX_STATE_DOINGSTUFF &&
                    m_pCurrentTarget != NULL)
                {
                    if (((TESObjectREFRHelper*)m_pCurrentTarget)->IsMarkerAvailable(m_ucProcedureIndex, true))
                        return true;
                }
                if (HasActivityEnded(NULL))
                    return true;
                if (IsActivityTime() && IsActivityProcedure())
                    return eProcedure != g_procedureForActivity[m_eSandboxActivity];
                bPickNew = false;
                fValue = GetHourDifference(m_fLastProcedureCheckHour, g_calendar.GetGameTime());
                if (fValue > m_fProcedureTime)
                    bPickNew = true;
                return bPickNew;
            }
        }
    }
}

// Reads the sandbox actor package data fields from the load buffer, adjusts the timestamp against g_timeGlobal, and loads the choice array entries.
// @fnv 0x009f5ca0
void SandBoxActorPackageData::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    int iSavedTimeStamp;
    unsigned int ItemUpdateArray;
    apBuffer->ReadTypedData(&eState, 4);
    apBuffer->ReadTypedData(&eProcedure, 4);
    apBuffer->ReadTypedData(&m_fProcedureTime, 4);
    apBuffer->ReadTypedData(&m_fLastProcedureCheckHour, 4);
    apBuffer->ReadTypedData(&m_fNextProcedureCheckHour, 4);
    apBuffer->ReadTypedData(&m_uiLastProcedureCheckDay, 4);
    apBuffer->ReadTypedData(&m_fProcedureTime, 4);
    apBuffer->ReadTypedData(&m_uiProcedureIndex, 4);
    apBuffer->ReadTypedData(&m_bNeedsSandboxUpdate, 1);
    apBuffer->ReadTypedData(&m_bHasFoodMarker, 1);
    apBuffer->ReadTypedData(&m_bHasChairMarker, 1);
    apBuffer->ReadTypedData(&m_bHasBedMarker, 1);
    apBuffer->ReadTypedData(&m_iSerializedValue, 4);
    apBuffer->ReadTypedData(&m_ucProcedureIndex, 1);
    iSavedTimeStamp = 0;
    apBuffer->ReadTypedData(&iSavedTimeStamp, 4);
    m_uiActivityStartDay = g_timeGlobal.GetTimeStamp() - iSavedTimeStamp;
    apBuffer->ReadTypedData(&m_uiActivityEndDay, 4);
    apBuffer->ReadTypedData(&m_fActivityStartHour, 4);
    apBuffer->ReadTypedData(&m_fActivityEndHour, 4);
    apBuffer->ReadTypedData(&m_eSandboxActivity, 4);
    apBuffer->ReadTypedData(m_ucProcedureFlags, 6);
    apBuffer->ReadFormIdentifier(&pLocation);
    apBuffer->ReadFormIdentifier(&m_pCurrentTarget);
    apBuffer->ReadFormIdentifier(&m_pCurrentFurniture);
    ItemUpdateArray = apBuffer->ReadElementCount();
    ((SandboxChoiceArray*)&m_kProcedureList)->SetSize(ItemUpdateArray, true);
    for (unsigned int uiIndex = 0; uiIndex < ItemUpdateArray; uiIndex++)
    {
        SandboxProcedureData* pItem = &m_kProcedureList.GetAt(uiIndex);
        pItem->LoadGame(apBuffer);
    }
}

// @fnv 0x009f5ea0
void SandBoxActorPackageData::InitLoadGame(BGSLoadFormBuffer* apBuffer)
{
    pLocation = pLocation ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)pLocation)) : NULL;
    m_pCurrentTarget =
        m_pCurrentTarget ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)m_pCurrentTarget)) : NULL;
    if (m_pCurrentTarget != NULL)
        ((TESObjectREFRHelper*)m_pCurrentTarget)->SetTargetingState(true);
    m_pCurrentFurniture = m_pCurrentFurniture
                              ? dynamic_cast<TESObjectREFR*>(GetFormByID((unsigned int)m_pCurrentFurniture))
                              : NULL;
    if (m_pCurrentFurniture != NULL)
        ((TESObjectREFRHelper*)m_pCurrentFurniture)->SetTargetingState(true);
    {
        int iCount;
        {
            int iIndex;
            {
                bool bResetState;
                {
                    unsigned int uiNumTargets;
                    {
                        unsigned int uiTargetIndex;
                        uiNumTargets = m_kProcedureList.GetSize();
                        for (uiTargetIndex = 0; uiTargetIndex < uiNumTargets; uiTargetIndex++)
                        {
                            {
                                SandboxProcedureData* pItem = &m_kProcedureList.GetAt(uiTargetIndex);
                                pItem->InitLoadGame(apBuffer);
                            }
                        }
                        iCount = m_kProcedureList.GetSize();
                        iIndex = 0;
                        bResetState = false;
                        while (iIndex < iCount)
                        {
                            {
                                SandboxProcedureData* pChoice = &m_kProcedureList.GetAt(iIndex);
                                if (pChoice->GetTarget() == NULL && IsValidSandboxProcedure(pChoice->GetProcedure()))
                                {
                                    ((SandboxChoiceArray*)&m_kProcedureList)->RemoveAt(iIndex, 1);
                                    iCount--;
                                    bResetState = true;
                                }
                                else
                                {
                                    iIndex++;
                                }
                            }
                        }
                        if (m_pCurrentTarget != NULL)
                        {
                            if (((TESObjectREFRHelper*)m_pCurrentTarget)->IsReferenceActive(false))
                                ((TESObjectREFRHelper*)m_pCurrentTarget)->SetMarkerState(m_ucProcedureIndex, true);
                            else
                                bResetState = true;
                        }
                        if (bResetState || m_pCurrentTarget == NULL)
                        {
                            eProcedure = SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_NONE;
                            m_fProcedureTime = 0.0F;
                            m_pCurrentTarget = NULL;
                            m_ucProcedureIndex = 0x7F;
                            m_bNeedsSandboxUpdate = true;
                            m_uiProcedureIndex = 0;
                        }
                        if (pLocation != NULL && m_uiLastProcedureCheckDay == 0)
                        {
                            m_uiLastProcedureCheckDay = 0xFFFFFFFF;
                            if (((ExtraDataListHelper*)pLocation->GetExtraData())->GetLinkedRef() != NULL)
                            {
                                m_uiLastProcedureCheckDay = 0;
                                {
                                    RegionPoint* pPatrolRefData =
                                        ((ExtraDataListHelper*)pLocation->GetExtraData())->GetStartingPositionData();
                                    if (pPatrolRefData != NULL)
                                    {
                                        m_uiLastProcedureCheckDay = g_timeGlobal.GetTimeStamp() +
                                                                    (unsigned int)(pPatrolRefData->GetX() * 1000.0);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// @fnv 0x009f4300
bool SandBoxActorPackageData::IsActorWithinLocationRadius(Actor* actor, bool update)
{
    // Idle animation context: process, sequence, animation and group state.
    struct IdleState
    {
        BaseProcess* process;
        BSAnimGroupSequence* sequence;
        Animation* animation;
        int unused;
    } idle;
    if (eProcedure == 0 || eProcedure == 4)
    {
        {
            switch (((PlayerCharacter*)actor)->GetAnimAction())
            {
            case 12:
            case 13:
                return false;
            }
        }
        idle.animation = ((SandboxActorVirtual*)actor)->GetAnimData();
        idle.unused = -1;
        if (idle.animation)
        {
            if (!idle.animation->IsSequenceActive())
                return false;
            if (update)
            {
                idle.sequence = idle.animation->GetPlayingSequence();
                if (idle.sequence && (int)((LowProcess*)idle.sequence)->GetActiveCombatTarget() != 3)
                {
                    idle.process = actor->GetProcess();
                    ((SandboxProcessVirtual*)idle.process)->UpdateIdle(actor);
                }
            }
        }
    }
    return true;
}

// @fnv 0x009f56b0
bool SandBoxActorPackageData::IsObjectWithinLocationRadius(MobileObject* object, float afRadius)
{
    // Keep the related location query results and radius policy together.
    struct LocationState
    {
        void* helper;
        RegionPoint* patrol;
        float adjustment;
        Actor* locationActor;
        TESPackage* package;
        Actor* actor;
        char pad20, pad21, pad22;
        bool same;
        float radius;
        TESObjectCELL* objectCell;
        TESObjectCELL* locationCell;
        TESWorldSpace* locationWorld;
        NiPoint3* position;
        TESWorldSpace* objectWorld;
        char pad5, pad6, pad7;
        bool special;
    } state;
    if (!object)
        return false;
    state.actor = 0;
    if (((SandboxMobileVirtual*)object)->IsActor())
        state.actor = (Actor*)object;
    if (!pLocation)
    {
        if (state.actor)
        {
            state.package = state.actor->GetCurrentPackage();
            if (state.package)
                return ((SandboxPackageVirtual*)state.package)->IsAtLocation(state.actor, 0, -1.0f, false);
        }
        return false;
    }
    state.locationWorld = pLocation->GetParentWorldSpace();
    state.locationCell = pLocation->GetParentCell();
    if (state.locationCell && !state.locationCell->IsCellInterior())
        state.locationCell = 0;
    state.objectWorld = object->GetParentWorldSpace();
    state.objectCell = object->GetParentCell();
    if (state.objectCell && !state.objectCell->IsCellInterior())
        state.objectCell = 0;
    state.same = false;
    if (state.objectCell || state.locationCell)
    {
        if (state.objectCell == state.locationCell)
            state.same = true;
    }
    else
    {
        if (state.objectWorld == state.locationWorld)
            state.same = true;
    }
    if (!state.same)
        return false;
    state.radius = afRadius;
    state.special = false;
    state.position = ((SandboxMobileVirtual*)pLocation)->GetPos();
    if (state.radius == 0.0)
    {
        if (pLocation->GetObjectReference() == DAT_011ca248 || pLocation->GetObjectReference() == DAT_011ca244)
        {
            state.radius = runtimeFloatSettingDefault94;
        }
        else if (((SandboxMobileVirtual*)pLocation)->IsActor())
        {
            state.locationActor = (Actor*)pLocation;
            if (((SandboxMobileVirtual*)state.locationActor)->GetSitSleepState() == 9)
            {
                state.radius = DAT_010249d8;
                state.special = true;
            }
            else
            {
                state.radius = pLocation->GetBoundingRadius() + 20.0;
            }
        }
        else
        {
            state.adjustment = runtimeFloatSettingDefault94;
            switch (((TESForm*)pLocation->GetObjectReference())->GetFormType())
            {
            case 21:
            case 27:
            case 32:
            case 33:
                state.adjustment = 0.0f;
                break;
            }
            state.radius = pLocation->GetBoundingRadius() + state.adjustment;
            if (state.radius < 0.0)
                state.radius = 0.0f;
        }
    }
    if (state.radius == 0.0)
        state.radius = (float)((SettingT_GameSettingCollection_*)&g_011cde98)->Int()->i;
    if (((SandboxMobileVirtual*)object)->IsAtLocation(state.position, state.radius, !state.special, true))
    {
        if (m_uiLastProcedureCheckDay == 0xffffffff && pLocation->GetExtraData() &&
            ((ExtraDataListHelper*)pLocation->GetExtraData())->GetLinkedRef())
        {
            m_uiLastProcedureCheckDay = 0;
            state.patrol = ((ExtraDataListHelper*)pLocation->GetExtraData())->GetStartingPositionData();
            if (state.patrol)
                m_uiLastProcedureCheckDay = g_timeGlobal.GetTimeStamp() + (unsigned int)(state.patrol->GetX() * 1000.0);
            if (eProcedure > -1 && eProcedure < 6)
            {
                state.helper = state.actor->FUN_0087f990();
                m_fProcedureTime = FUN_006435c0(state.helper, eProcedure);
            }
        }
        return true;
    }
    return false;
}

struct FUN_009f41c0_shell
{
    void __thiscall ResetReference();
    void __thiscall FUN_009f41c0();
};

// Calls ResetReference, then sets the byte at offset 0x34 and the int at offset 4 to 1.
// @fnv 0x009f41c0
void __thiscall FUN_009f41c0_shell::FUN_009f41c0()
{
    ResetReference();
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x34) = 1;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4) = 1;
}

namespace fnv_009f4700 {
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting255;
extern Setting_S originalRuntimeFloatSetting256;
extern int g_011cdb3c;
extern int g_011cd0a4;
extern int g_011cdf60;
int& __fastcall FUN_0043d4d0(int*);
unsigned int GetRandomNumberInRange(int, int);
int FUN_00647b70(int, int);
int GetRandomNumber();

struct NiPoint3POD
{
    float x;
    float y;
    float z;
};
struct DurationData
{
    int FUN_00726070();
};
struct TESPackage
{
    DurationData* FUN_0041d8a0();
    TESObjectCELL* GetPackageLocationCell(MobileObject*);
    const NiPoint3 GetPackageLocationPosition(MobileObject*);
    unsigned int FUN_00676280(MobileObject*);
};
struct BaseProcessVT
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual float vfn_b8();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual bool vfn_204(Actor*, Actor*);
};
struct ActorS : public TESObjectREFR
{
    TESWorldSpace* GetParentWorldSpace();
    TESObjectCELL* GetParentCell();
    BaseProcess* GetCurrentProcess() const;
};
struct Actor_ext : public Actor
{
    TESPackage* GetCurrentPackage();
    bool IsHostileToActor(Actor*, int, int*, bool);
    int FUN_0087f990();
};
struct TESObjectCELL_Ext : public TESObjectCELL
{
    bool IsInterior();
    TESWorldSpace* GetParentWorldSpace();
};
struct NiPoint3_ext : public NiPoint3
{
    NiPoint3 operator-(const NiPoint3&) const;
    float FUN_004a7290() const;
};
struct SandBoxChoiceListItem_ext : public SandboxProcedureData
{
    void FUN_0041fd00(int);
    unsigned int FUN_0084e3a0();
    unsigned int FUN_0044ddc0();
};
struct FUN_005682c0_caller
{
    int FUN_005682c0(bool);
};
struct SandBoxActorPackageData_ext : public SandBoxActorPackageData
{
    void SelectActivity();
    void ResetReference();
    void ScanSandboxTargets(Actor*);
    void SelectSandboxActivity(Actor*, TESPackage*);
};

// Scores sandbox choice list items by procedure probability and distance, picks one by weighted random, and stores the chosen procedure, target and energy.
// @fnv 0x009f4700
void SandBoxActorPackageData_ext::SelectSandboxActivity(Actor* apActor, TESPackage* apOriginalPackage)
{
    int isandboxProceduresProbabilities[6];
    int inumTargets;
    float fsearchDialogueDistSqr;
    TESWorldSpace* ppackageWorldSpace;
    TESObjectCELL* ppackageCell;
    float fsearchDistSqr;
    BaseProcess* process;
    float fsearchDist;
    bool bcanPerformActivity;
    int i;
    NiPoint3POD packageLoc;
    int itotalProb;
    TESPackage* ppack;

    m_bNeedsSandboxUpdate = false;
    SelectActivity();
    if (m_fNextProcedureCheckHour == 0.0)
    {
        if (apOriginalPackage && apOriginalPackage->FUN_0041d8a0())
            m_fNextProcedureCheckHour = (float)apOriginalPackage->FUN_0041d8a0()->FUN_00726070();
        if (m_fNextProcedureCheckHour == 0.0)
            m_fNextProcedureCheckHour = 24.0f;
    }
    if (m_pCurrentTarget && m_pCurrentFurniture != m_pCurrentTarget)
    {
        m_uiActivityStartDay = g_timeGlobal.GetTimeStamp() + FUN_0043d4d0(&g_011cdb3c) * 1000;
        m_pCurrentFurniture = m_pCurrentTarget;
    }
    if (m_pCurrentFurniture && g_timeGlobal.GetTimeStamp() > m_uiActivityStartDay)
        m_pCurrentFurniture = 0;
    if (m_pCurrentTarget)
        static_cast<TESObjectREFRHelper*>(m_pCurrentTarget)->SetMarkerState(m_ucProcedureIndex, false);
    m_pCurrentTarget = 0;
    m_ucProcedureIndex = 127;
    eProcedure = SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_NONE;
    m_fProcedureTime = 0.0f;
    if (g_timeGlobal.GetTimeStamp() >= m_uiProcedureIndex)
    {
        ResetReference();
        ScanSandboxTargets(apActor);
        m_uiProcedureIndex = g_timeGlobal.GetTimeStamp() +
                             GetRandomNumberInRange(FUN_0043d4d0(&g_011cd0a4) * 1000, FUN_0043d4d0(&g_011cdf60) * 1000);
    }
    bcanPerformActivity = IsActivityTime() && IsActivityProcedure();
    if (bcanPerformActivity)
    {
        for (i = 0; i < 6; i++)
            isandboxProceduresProbabilities[i] = 0;
        isandboxProceduresProbabilities[g_procedureForActivity[m_eSandboxActivity]] = 10;
    }
    else
    {
        for (i = 0; i < 6; i++)
            isandboxProceduresProbabilities[i] = m_ucProcedureFlags[i];
        isandboxProceduresProbabilities[SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_SLEEP] = 0;
        if (m_bHasFoodMarker)
            isandboxProceduresProbabilities[SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_EAT] += 20;
        if (!m_bHasChairMarker)
            isandboxProceduresProbabilities[SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_EAT] -= 15;
        if (static_cast<ActorS*>(static_cast<TESObjectREFR*>(apActor))->GetCurrentProcess() &&
            reinterpret_cast<BaseProcessVT*>(
                static_cast<ActorS*>(static_cast<TESObjectREFR*>(apActor))->GetCurrentProcess())
                    ->vfn_b8() > 0.0)
            isandboxProceduresProbabilities[SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_DIALOGUE] = 0;
    }
    itotalProb = 0;
    inumTargets = reinterpret_cast<SandBoxChoiceListItem_ext*>(&m_kProcedureList)->FUN_0044ddc0();
    process = static_cast<ActorS*>(static_cast<TESObjectREFR*>(apActor))->GetCurrentProcess();
    fsearchDist = *originalRuntimeFloatSetting255.Float();
    packageLoc = *reinterpret_cast<NiPoint3POD*>(apActor->GetPos());
    ppackageCell = static_cast<ActorS*>(static_cast<TESObjectREFR*>(apActor))->GetParentCell();
    ppack = static_cast<Actor_ext*>(apActor)->GetCurrentPackage();
    if (ppack)
    {
        int ipackageLocRadius;
        packageLoc = *reinterpret_cast<const NiPoint3POD*>(&ppack->GetPackageLocationPosition(apActor));
        ppackageCell = ppack->GetPackageLocationCell(apActor);
        ipackageLocRadius = ppack->FUN_00676280(apActor);
        fsearchDist = ipackageLocRadius > 0 ? (float)ipackageLocRadius : fsearchDist;
    }
    if (pLocation)
    {
        packageLoc = *reinterpret_cast<NiPoint3POD*>(pLocation->GetPos());
        ppackageCell = static_cast<ActorS*>(pLocation)->GetParentCell();
    }
    ppackageWorldSpace = ppackageCell ? static_cast<TESObjectCELL_Ext*>(ppackageCell)->GetParentWorldSpace()
                                      : static_cast<ActorS*>(static_cast<TESObjectREFR*>(apActor))->GetParentWorldSpace();
    fsearchDialogueDistSqr = fsearchDist + *originalRuntimeFloatSetting256.Float();
    fsearchDistSqr = fsearchDist * fsearchDist;
    fsearchDialogueDistSqr = fsearchDialogueDistSqr * fsearchDialogueDistSqr;
    for (i = 0; i < inumTargets; i++)
    {
        SandBoxChoiceListItem_ext* item;
        TESObjectREFR* ptargObject;
        int score;
        TESPackage* ppack;
        item = static_cast<SandBoxChoiceListItem_ext*>(&m_kProcedureList.GetAt(i));
        score = item->FUN_0044ddc0() * isandboxProceduresProbabilities[item->GetProcedure()];
        score = FUN_00647b70(score, 0);
        ppack = static_cast<Actor_ext*>(apActor)->GetCurrentPackage();
        ptargObject = item->GetTarget();
        if (ptargObject)
        {
            float fmaxDistSqr;
            TESObjectCELL* ptargetCell;
            bool bisDialogue;
            bool binterior;
            if (ptargObject == m_pCurrentFurniture)
            {
                item->FUN_0041fd00(0);
                continue;
            }
            binterior = false;
            ptargetCell = static_cast<ActorS*>(ptargObject)->GetParentCell();
            if (ppackageCell && ptargetCell &&
                (static_cast<TESObjectCELL_Ext*>(ppackageCell)->IsInterior() ||
                 static_cast<TESObjectCELL_Ext*>(ptargetCell)->IsInterior()))
            {
                binterior = true;
                if (ppackageCell != ptargetCell)
                    continue;
            }
            if (!binterior)
            {
                TESWorldSpace* ptargetWorldSpace = ptargetCell
                                                       ? static_cast<TESObjectCELL_Ext*>(ptargetCell)->GetParentWorldSpace()
                                                       : static_cast<ActorS*>(ptargObject)->GetParentWorldSpace();
                if (ppackageWorldSpace != ptargetWorldSpace)
                    continue;
            }
            bisDialogue = item->GetProcedure() == SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_DIALOGUE;
            fmaxDistSqr = bisDialogue ? fsearchDialogueDistSqr : fsearchDistSqr;
            if (fmaxDistSqr <
                static_cast<const NiPoint3_ext&>(static_cast<NiPoint3_ext*>(ptargObject->GetPos())
                                                     ->
                                                     operator-(reinterpret_cast<const NiPoint3&>(packageLoc)))
                    .FUN_004a7290())
            {
                item->FUN_0041fd00(0);
                continue;
            }
            if (!static_cast<TESObjectREFRHelper*>(ptargObject)->IsReferenceActive(false))
            {
                item->FUN_0041fd00(0);
                continue;
            }
            if (bisDialogue)
            {
                Actor* ptargetActor = static_cast<Actor*>(ptargObject);
                int ereaction;
                if (!static_cast<ActorS*>(static_cast<TESObjectREFR*>(apActor))->GetCurrentProcess() ||
                    !reinterpret_cast<BaseProcessVT*>(
                         static_cast<ActorS*>(static_cast<TESObjectREFR*>(apActor))->GetCurrentProcess())
                         ->vfn_204(apActor, ptargetActor))
                {
                    item->FUN_0041fd00(0);
                    continue;
                }
                ereaction = 0;
                if (static_cast<Actor_ext*>(apActor)->IsHostileToActor(ptargetActor, 0, &ereaction, false) ||
                    static_cast<Actor_ext*>(ptargetActor)->IsHostileToActor(apActor, 0, &ereaction, false))
                {
                    item->FUN_0041fd00(0);
                    continue;
                }
            }
        }
        item->FUN_0041fd00(score);
        itotalProb += score;
    }
    if (itotalProb > 0)
    {
        int irandom;
        int iIndex;
        SandboxProcedureData ritem;
        int iactorEnergy;
        irandom = GetRandomNumber() % itotalProb;
        for (i = 0; i < inumTargets; i++)
        {
            SandBoxChoiceListItem_ext* item = static_cast<SandBoxChoiceListItem_ext*>(&m_kProcedureList.GetAt(i));
            if ((irandom -= item->FUN_0084e3a0()) < 0)
                break;
        }
        ritem = m_kProcedureList.GetAt(i);
        eProcedure = ritem.GetProcedure();
        m_pCurrentTarget = ritem.GetTarget();
        iIndex = m_pCurrentTarget ? reinterpret_cast<FUN_005682c0_caller*>(m_pCurrentTarget)->FUN_005682c0(false) : -1;
        m_ucProcedureIndex = iIndex < 0 ? 0 : (unsigned char)iIndex;
        iactorEnergy = static_cast<Actor_ext*>(apActor)->FUN_0087f990();
        m_fProcedureTime = FUN_006435c0((void*)iactorEnergy, eProcedure);
        for (i = 0; i < 6; i++)
        {
            unsigned char cweight = m_ucProcedureFlags[i];
            cweight = cweight < 255 ? cweight + 1 : cweight;
            m_ucProcedureFlags[i] = cweight;
        }
        m_ucProcedureFlags[eProcedure] = 1;
        if (m_pCurrentTarget)
            static_cast<TESObjectREFRHelper*>(m_pCurrentTarget)->SetMarkerState(m_ucProcedureIndex, true);
    }
    else
    {
        eProcedure = SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_NONE;
        m_fProcedureTime = 0.0f;
        m_pCurrentTarget = 0;
        m_ucProcedureIndex = 127;
    }
    m_fLastProcedureCheckHour = g_calendar.GetGameTime();
}
}  // namespace fnv_009f4700

struct FUN_009f3800
{
    TESObjectREFRHelper* f0;
    int f1;
    int f2;
    int f3;
    FUN_009f3800(TESObjectREFRHelper* a, int b, int c);
};
// Stores the helper pointer and two ints, zeroes the third field, and if the helper is non-null calls its method with true.
// @fnv 0x009f3800
FUN_009f3800::FUN_009f3800(TESObjectREFRHelper* pHelper, int b, int c)
{
    f0 = pHelper;
    f1 = b;
    f2 = c;
    f3 = 0;
    if (f0 != 0)
        f0->SetTargetingState(true);
}

void __cdecl _Deallocate(void*);
struct FUN_009f3a40_t
{
    void __thiscall FUN_009f3a70();
    void* __thiscall FUN_009f3a40(unsigned int);
};
// @fnv 0x009f3a40
void* __thiscall FUN_009f3a40_t::FUN_009f3a40(unsigned int flags)
{
    FUN_009f3a70();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct DH
{
    bool FUN_004226e0();
};
extern DH* g_dataHandler;
// @fnv 0x009f4060
void FUN_009f41c0_shell::ResetReference()
{
    if (g_dataHandler == 0 || !g_dataHandler->FUN_004226e0())
    {
        if (*(TESObjectREFRHelper**)((char*)this + 0x3c) != 0)
        {
            (*(TESObjectREFRHelper**)((char*)this + 0x3c))
                ->SetMarkerState(*(unsigned char*)((char*)this + 0x40), false);
        }
    }
    *(TESObjectREFRHelper**)((char*)this + 0x3c) = 0;
    *(unsigned char*)((char*)this + 0x40) = 0x7f;
}

struct TESObjectREFR_GetFlags_Helper
{
    unsigned int __thiscall CallGetFlags();
};
extern int DAT_010935dc[];
struct FUN_009f4640_holder
{
    int __thiscall GetFlagsMappedValue();
};
// @fnv 0x009f4640
int __thiscall FUN_009f4640_holder::GetFlagsMappedValue()
{
    return ((TESObjectREFR_GetFlags_Helper*)this)->CallGetFlags() == 0xffffffff
               ? -1
               : DAT_010935dc[((TESObjectREFR_GetFlags_Helper*)this)->CallGetFlags()];
}

struct Arr16
{
    unsigned int FUN_006f31f0();
};
struct Elem9f6340
{
    int f0;
    int f4;
    int f8;
    int fC;
};
struct Host9f6340
{
    int f00;
    Elem9f6340* f04;
    void __thiscall FUN_009f6460(Elem9f6340* p, int v);
    unsigned int __thiscall AppendElement(Elem9f6340* p);
};
// @fnv 0x009f6340
unsigned int __thiscall Host9f6340::AppendElement(Elem9f6340* apElement)
{
    unsigned int uiIndex = ((Arr16*)this)->FUN_006f31f0();
    FUN_009f6460(f04 + uiIndex, 1);
    f04[uiIndex] = *apElement;
    return uiIndex;
}

struct FUN_009f45e0_shell
{
    bool __thiscall IsFlagBit0Clear();
};
// @fnv 0x009f45e0
bool __thiscall FUN_009f45e0_shell::IsFlagBit0Clear()
{
    return !(*(unsigned short*)((char*)this + 0x24) & 1) ? true : false;
}

struct FUN_009f4620_shell
{
    bool __thiscall FUN_009f4620();
};
// @fnv 0x009f4620
bool __thiscall FUN_009f4620_shell::FUN_009f4620()
{
    return !(reinterpret_cast<unsigned short*>(this)[0x24 / sizeof(unsigned short)] & 0x10) ? true : false;
}

struct FUN_009f4680_shell
{
    void __thiscall SelectSandboxActivity(void* b, void* c);
    void __thiscall ClearTargetReferences(void* b, void* c);
};
// @fnv 0x009f4680
void __thiscall FUN_009f4680_shell::ClearTargetReferences(void* apArg1, void* apArg2)
{
    if (((unsigned int*)this)[15])
    {
        int count = ((TESObjectREFR_GetFlags_Helper*)((char*)this + 0x20))->CallGetFlags();
        for (int i = 0; i < count; ++i)
        {
            SandboxProcedureData* item =
                &(((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)this + 0x20))->GetAt(i));
            if (item->GetTarget() == ((TESObjectREFR**)((char*)this + 0x3c))[0])
                item->m_iActivityState = 0;
        }
    }
    SelectSandboxActivity(apArg1, apArg2);
}

struct FUN_009f54b0_shell
{
    bool __thiscall IsFlag8Clear();
};
// @fnv 0x009f54b0
bool __thiscall FUN_009f54b0_shell::IsFlag8Clear()
{
    return (((unsigned short*)((char*)this + 0x24))[0] & 8) ? false : true;
}

struct S006949d0
{
    void* __thiscall GetAt(int);
};
struct FUN_009f6190_shell : S006949d0
{
    void* __thiscall FUN_009f6190(int a);
};
// @fnv 0x009f6190
void* __thiscall FUN_009f6190_shell::FUN_009f6190(int aiIndex)
{
    return GetAt(aiIndex);
}

struct EdgeArr
{
    char* FUN_006a1440(unsigned int);
};

struct FUN_00693d30_shell
{
    char pad[0x48];
    EdgeArr m_kEdges;
    char* GetEdge(unsigned short index);
};

// @fnv 0x00693d30
char* FUN_00693d30_shell::GetEdge(unsigned short index)
{
    return m_kEdges.FUN_006a1440(index);
}

struct FUN_009f3e20_shell
{
    unsigned char _pad0[0x35];
    bool m_bHasFoodMarker;
    unsigned char _pad1;
    bool m_bHasBedMarker;
    unsigned char _pad2[0x58 - 0x38];
    int m_eSandboxActivity;
    bool __thiscall FUN_009f3e20();
};
// @fnv 0x009f3e20
bool __thiscall FUN_009f3e20_shell::FUN_009f3e20()
{
    switch (m_eSandboxActivity)
    {
    case -1:
        return false;
    case 1:
    case 2:
    case 3:
        return m_bHasFoodMarker;
    case 0:
        return m_bHasBedMarker;
    default:
        return true;
    }
}

unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);
struct FUN_0072ba80_shell
{
    void __thiscall FUN_0072ba80(void*, unsigned int);
};
struct FUN_006c8bd0_Class
{
    void __thiscall FUN_006c8bd0(const char*, const char*, unsigned int);
};
struct FUN_009f63a0_shell
{
    char* f00;
    char* f04;
    unsigned int f08;
    void __thiscall FUN_009f63a0(char* apSrcAddr, unsigned int aiCount);
};
// @fnv 0x009f63a0
void __thiscall FUN_009f63a0_shell::FUN_009f63a0(char* apSrcAddr, unsigned int aiCount)
{
    unsigned int i = FUN_0042f5a0(f08 - (unsigned int)apSrcAddr - aiCount, aiCount);
    ((FUN_0072ba80_shell*)this)->FUN_0072ba80(f04 + (unsigned int)apSrcAddr * 16, aiCount);
    ((FUN_006c8bd0_Class*)this)->FUN_006c8bd0(f04 + (unsigned int)apSrcAddr * 16, f04 + f08 * 16 - i * 16, i);
    f08 -= aiCount;
}

struct SaveFormIDHelper
{
    void __thiscall SerializeFormData(void*, int);
};

struct BGSSaveGameBuffer
{
    void __thiscall FUN_00865f60(unsigned int);
};

struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void*, int, int);
};

struct Crime : public BSSimpleArray<class SandboxProcedureData, 1024>
{
    TESObjectREFR* __thiscall GetTarget();
};

struct FUN_009f3850_shell
{
    void __thiscall FUN_009f3850(BGSSaveFormBuffer*);
};

struct FUN_009f5a60_shell
{
    void __thiscall SaveCrimeData(BGSSaveFormBuffer*);
};

// Serializes the crime record's fields, target references and per-crime entries into the save buffer.
// @fnv 0x009f5a60
void __thiscall FUN_009f5a60_shell::SaveCrimeData(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int i;
    int iprevTargetDelta3;
    unsigned int isaveGameCount_2;
    SandboxProcedureData* potentialTarget;

    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x04), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x08), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x0C), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x14), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x18), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x1C), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x0C), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x30), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x34), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x35), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x36), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x37), 1, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x38), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x40), 1, 0);

    iprevTargetDelta3 =
        g_timeGlobal.GetTimeStamp() - *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x48);

    apSaveGameBuffer->SaveData(&iprevTargetDelta3, 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x4C), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x50), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x54), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x58), 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<void*>(reinterpret_cast<unsigned char*>(this) + 0x5C), 6, 0);

    reinterpret_cast<SaveFormIDHelper*>(apSaveGameBuffer)
        ->SerializeFormData(*reinterpret_cast<TESObjectREFR**>(reinterpret_cast<unsigned char*>(this) + 0x10), 0);
    reinterpret_cast<SaveFormIDHelper*>(apSaveGameBuffer)
        ->SerializeFormData(*reinterpret_cast<TESObjectREFR**>(reinterpret_cast<unsigned char*>(this) + 0x3C), 0);
    reinterpret_cast<SaveFormIDHelper*>(apSaveGameBuffer)
        ->SerializeFormData(*reinterpret_cast<TESObjectREFR**>(reinterpret_cast<unsigned char*>(this) + 0x44), 0);

    isaveGameCount_2 =
        reinterpret_cast<Crime*>(reinterpret_cast<unsigned char*>(this) + 0x20)
            ? (unsigned int)reinterpret_cast<Crime*>(reinterpret_cast<unsigned char*>(this) + 0x20)->GetTarget()
            : 0;

    reinterpret_cast<BGSSaveGameBuffer*>(apSaveGameBuffer)->FUN_00865f60(isaveGameCount_2);

    for (i = 0; i < isaveGameCount_2; ++i)
    {
        potentialTarget = &reinterpret_cast<Crime*>(reinterpret_cast<unsigned char*>(this) + 0x20)->GetAt(i);
        reinterpret_cast<FUN_009f3850_shell*>(potentialTarget)->FUN_009f3850(apSaveGameBuffer);
    }
}

struct Vec3
{
    float x, y, z;
    void __thiscall FUN_00416870(float, float, float);
};
struct ActionSource
{
    Vec3* __thiscall FUN_00439e90();
};
struct ObjectPart
{
    ActionSource* __thiscall FUN_005c3420(Vec3*, Vec3*, Vec3*);
    void* __thiscall FUN_006dd4f0();
};
struct Object
{
    float __thiscall GetFieldB4Float();
    float __thiscall GetFloatAtOffsetB0();
    ObjectPart* __thiscall GetOffsetC();
};
struct ElevationProvider
{
    bool __thiscall FUN_005547c0(Vec3*, float*);
};
extern bool __cdecl FUN_006d34d0(Object*, Vec3*);
extern float __cdecl FUN_004a4240();
extern float __cdecl FUN_00476b70(float, float);
extern float __cdecl FUN_004e44d0(float);
extern float __cdecl FUN_004e4490(float);
// Computes a position from the object's parts and elevation provider, writing it into result and overriding z with the provider's height.
// @fnv 0x006d33c0
void __cdecl GetObjectPosition(Object* object, Vec3* result)
{
    if (FUN_006d34d0(object, result))
        return;
    float a = FUN_004a4240();
    float g;
    float b = FUN_00476b70(object->GetFloatAtOffsetB0(), object->GetFieldB4Float());
    Vec3 f;
    f.FUN_00416870(FUN_004e4490(a) * b, FUN_004e44d0(a) * b, 0.0f);
    Vec3 c;
    Vec3 e;
    *result = *object->GetOffsetC()->FUN_005c3420(&c, &e, &f)->FUN_00439e90();
    ElevationProvider* d = static_cast<ElevationProvider*>(object->GetOffsetC()->FUN_006dd4f0());
    if (!d)
        return;
    if (!d->FUN_005547c0(result, &g))
        return;
    result->z = g;
}

struct FalloffPair
{
    float first;
    float second;
    void __thiscall FUN_006815c0();
};

struct FalloffController
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    bool active;
    unsigned char state29;
    unsigned short state2a;
    float startTime;
    float firstDuration;
    float secondDuration;
    float firstStrength;
    float secondStrength;
    float firstRate;
    float secondRate;
    float firstOutput;
    float secondOutput;

    void __thiscall UpdateFalloff(float currentTime);
};

float __cdecl FUN_004e44d0(float value);
void __cdecl FUN_007f7a50(float first, float second);

// @fnv 0x007f7970
void __thiscall FalloffController::UpdateFalloff(float currentTime)
{
    float elapsed = currentTime - startTime;
    if (elapsed > firstDuration && elapsed > secondDuration)
    {
        active = false;
        FUN_007f7a50(0.0f, 0.0f);
    }
    else
    {
        FalloffPair falloffPair;
        falloffPair.FUN_006815c0();
        falloffPair.first = 1.0f - elapsed / firstDuration;
        falloffPair.second = 1.0f - elapsed / secondDuration;
        firstOutput = FUN_004e44d0(elapsed * firstRate) * firstStrength * falloffPair.first;
        secondOutput = FUN_004e44d0(elapsed * secondRate) * secondStrength * falloffPair.second;
    }
}

// CheckTimerState: __thiscall, one out-param (unsigned char*), returns bool
struct SandboxTimerGlobal
{
    int GetCount();
    float GetLimit();
};
extern SandboxTimerGlobal g_sandboxTimerGlobal;

struct FUN_009f3c90_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int m_cnt4c;
    float m_f50;
    float m_f54;
    int m_flag58;
    bool CheckTimerState(unsigned char* out);
};

extern const double DAT_010356d8;

// @fnv 0x009f3c90
bool FUN_009f3c90_cls::CheckTimerState(unsigned char* pucOut)
{
    float count;
    unsigned int ratio;
    ratio = (unsigned int)g_sandboxTimerGlobal.GetCount();
    count = g_sandboxTimerGlobal.GetLimit();
    unsigned char rem = 0;
    if (m_flag58 == -1)
    {
        return true;
    }
    unsigned int k = m_cnt4c;
    float lim = m_f50 + m_f54;
    while (lim >= DAT_010356d8)
    {
        lim -= DAT_010356d8;
        k++;
    }
    if (ratio == k)
    {
        if (count < lim)
        {
            return false;
        }
        rem = 1;
    }
    else if (ratio < k)
    {
        return false;
    }
    if (pucOut != 0)
    {
        *pucOut = rem;
    }
    return true;
}

struct FUN_009f4600_cls
{
    char m_pad00[0x24];
    unsigned short m_usFlags;
    bool __thiscall IsFlag2Clear();
};
// @fnv 0x009f4600
bool FUN_009f4600_cls::IsFlag2Clear()
{
    return (this->m_usFlags & 2) ? false : true;
}

struct FUN_009f5690_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned short m_24;

    unsigned char IsFlag20Clear();
};

// @fnv 0x009f5690
unsigned char FUN_009f5690_cls::IsFlag20Clear()
{
    return (unsigned char)((m_24 & 0x20) == 0);
}

struct SBTarget;
struct SBPatrolData
{
    float GetIdleTime();
};
struct SBExtraList
{
    SBTarget* GetLinkedRef();
    SBPatrolData* GetPatrolData();
};
struct SBTarget
{
    SBExtraList* GetExtraList();
};
struct SBProcess
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual void vf27c();
    virtual void vf280();
    virtual void vf284();
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294();
    virtual void vf298();
    virtual void vf29c();
    virtual void vf2a0();
    virtual void vf2a4();
    virtual void vf2a8();
    virtual void vf2ac();
    virtual void vf2b0();
    virtual void vf2b4();
    virtual void vf2b8();
    virtual void vf2bc();
    virtual void vf2c0();
    virtual void vf2c4();
    virtual void vf2c8();
    virtual void vf2cc();
    virtual void vf2d0();
    virtual void vf2d4();
    virtual void vf2d8();
    virtual void vf2dc();
    virtual void vf2e0();
    virtual void vf2e4();
    virtual void vf2e8();
    virtual void vf2ec();
    virtual void vf2f0();
    virtual void vf2f4();
    virtual void vf2f8();
    virtual void vf2fc();
    virtual void vf300();
    virtual void vf304();
    virtual void vf308();
    virtual void vf30c();
    virtual void vf310();
    virtual void vf314();
    virtual void vf318();
    virtual void vf31c();
    virtual void vf320();
    virtual void vf324();
    virtual void vf328();
    virtual void vf32c();
    virtual void vf330();
    virtual void vf334();
    virtual void vf338();
    virtual void vf33c();
    virtual void vf340();
    virtual void vf344();
    virtual void vf348();
    virtual void vf34c();
    virtual void vf350();
    virtual void vf354();
    virtual void vf358();
    virtual void vf35c();
    virtual void vf360();
    virtual void vf364();
    virtual void vf368();
    virtual void vf36c();
    virtual void vf370();
    virtual void vf374();
    virtual void vf378();
    virtual void vf37c();
    virtual void vf380();
    virtual void vf384();
    virtual void vf388();
    virtual void vf38c();
    virtual void vf390();
    virtual void vf394();
    virtual void vf398();
    virtual void vf39c();
    virtual void vf3a0();
    virtual void vf3a4();
    virtual void vf3a8();
    virtual void vf3ac();
    virtual void vf3b0();
    virtual void vf3b4();
    virtual void vf3b8();
    virtual void vf3bc();
    virtual void vf3c0();
    virtual void vf3c4();
    virtual void vf3c8();
    virtual void vf3cc();
    virtual void vf3d0();
    virtual void vf3d4();
    virtual void vf3d8();
    virtual void vf3dc();
    virtual void vf3e0();
    virtual void vf3e4();
    virtual void vf3e8();
    virtual void vf3ec();
    virtual void vf3f0();
    virtual void vf3f4();
    virtual void vf3f8();
    virtual void vf3fc();
    virtual void vf400();
    virtual void vf404();
    virtual void vf408();
    virtual void vf40c();
    virtual void vf410();
    virtual void vf414();
    virtual void vf418();
    virtual void vf41c();
    virtual void vf420();
    virtual void vf424();
    virtual void vf428();
    virtual void vf42c();
    virtual void vf430();
    virtual void vf434();
    virtual void vf438();
    virtual void vf43c();
    virtual void vf440();
    virtual void vf444();
    virtual void vf448();
    virtual void vf44c();
    virtual void vf450();
    virtual void vf454();
    virtual void vf458();
    virtual void vf45c();
    virtual void vf460();
    virtual void vf464();
    virtual void vf468();
    virtual void vf46c();
    virtual void vf470();
    virtual void vf474();
    virtual void vf478();
    virtual void vf47c();
    virtual void vf480();
    virtual void vf484();
    virtual void vf488();
    virtual void vf48c();
    virtual void vf490();
    virtual void vf494();
    virtual void vf498();
    virtual void vf49c();
    virtual void vf4a0();
    virtual void vf4a4();
    virtual void vf4a8();
    virtual void vf4ac();
    virtual void vf4b0();
    virtual void vf4b4();
    virtual void vf4b8();
    virtual void vf4bc();
    virtual void vf4c0();
    virtual void vf4c4();
    virtual void vf4c8();
    virtual void vf4cc();
    virtual void vf4d0();
    virtual void vf4d4();
    virtual void vf4d8();
    virtual void vf4dc();
    virtual void vf4e0();
    virtual void vf4e4();
    virtual void vf4e8();
    virtual void vf4ec();
    virtual void vf4f0();
    virtual void vf4f4();
    virtual void vf4f8();
    virtual void vf4fc();
    virtual void vf500();
    virtual void vf504();
    virtual void vf508();
    virtual void vf50c();
    virtual void vf510();
    virtual SBTarget* GetPackageTargetRef();
};
struct SBActor
{
    SBProcess* GetProcess();
    SBTarget* GetLinkedRef();
};
struct SBPackage
{
    int GetActionRefHandle();
    SBTarget* GetTargetRef();
};

struct SandboxTargetData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SBTarget* pTarget;
    int unk14;
    int unk18;
    unsigned int uiTimeStamp;
    void FUN_009f3af0(SBActor* apActor, SBPackage* apPackage);
};

// @fnv 0x009f3af0
void SandboxTargetData::FUN_009f3af0(SBActor* apActor, SBPackage* apPackage)
{
    switch (apPackage->GetActionRefHandle())
    {
    case 0:
        pTarget = apPackage->GetTargetRef();
        break;
    case 4:
    case 5: {
        SBProcess* pProcess = apActor->GetProcess();
        if (pProcess)
            pTarget = pProcess->GetPackageTargetRef();
        break;
    }
    case 6:
        pTarget = apActor->GetLinkedRef();
        break;
    default:
        pTarget = 0;
        break;
    }
    if (pTarget && pTarget->GetExtraList()->GetLinkedRef())
    {
        uiTimeStamp = 0;
        SBPatrolData* pPatrol = pTarget->GetExtraList()->GetPatrolData();
        if (pPatrol)
            uiTimeStamp = g_timeGlobal.GetTimeStamp() + (unsigned int)(pPatrol->GetIdleTime() * 1000.0);
    }
}

void __cdecl GetSettingPairValues(int activity, float* start, float* duration);
struct ActivitySelector : SandBoxActorPackageData
{
    void SelectActivity();
};
// Picks the next sandbox activity by comparing each activity's start window against the current day, storing the chosen activity, hour, day and duration.
// @fnv 0x009f3e80
void ActivitySelector::SelectActivity()
{
    bool start = false;
    if (!HasActivityEnded(&start))
        return;
    float endedToday;
    unsigned int bestDuration = g_calendar.GetDaysPassed();
    endedToday = g_calendar.GetGameTime();
    float bestActivity = 3.402823466e+38F;
    float currentHour = 3.402823466e+38F;
    int currentDay;
    float bestDay = 3.402823466e+38F;
    float found = 3.402823466e+38F;
    float bestStart = 3.402823466e+38F;
    currentDay = -2;
    unsigned int duration = 0;
    bool bestDifference = false;
    for (int activity = 0; activity < 4; ++activity)
    {
        GetSettingPairValues(activity, &found, &bestStart);
        bool alreadyStarted;
        bool tomorrow;
        alreadyStarted = endedToday >= found + bestStart;
        if (start && !alreadyStarted && activity == m_eSandboxActivity)
            continue;
        {
            float nextStart = alreadyStarted ? found + 24.0 : found;
            float difference = nextStart - endedToday;
            tomorrow = difference <= 0.0;
            if (tomorrow || difference < bestActivity)
            {
                bestActivity = difference;
                currentDay = activity;
                currentHour = found;
                duration = alreadyStarted ? bestDuration + 1 : bestDuration;
                bestDay = bestStart;
                bestDifference = true;
                if (tomorrow)
                    break;
            }
        }
    }
    if (bestDifference)
    {
        m_eSandboxActivity = (SANDBOX_ACTIVITY)currentDay;
        m_fActivityStartHour = currentHour;
        m_uiActivityEndDay = duration;
        m_fActivityEndHour = bestDay;
    }
}

struct SbPoint3
{
    float x, y, z;
};
class SbCell;
class SbRef
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc();
    virtual void vfe0();
    virtual void vfe4();
    virtual void vfe8();
    virtual void vfec();
    virtual void vff0();
    virtual void vff4();
    virtual void vff8();
    virtual void vffc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual SbPoint3* GetPos();
    SbCell* GetParentCell();
    unsigned int GetFlags();
};
class SbPackage;
class SbActor : public SbRef
{
  public:
    SbRef* GetUsedRef();
    SbPackage* GetCurrentPackage();
};
class SbPackage
{
  public:
    SbPoint3 GetLocationPos(SbActor* apActor);
    int GetPackageDefaultFloat(SbActor* apActor);
    bool HasFoodTarget();
    bool HasBedTarget();
};
class SbRefHelper;
template <class C> class SettingT
{
  public:
    float* Float();
};
class GameSettingCollection;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting255;
struct SandboxTarget
{
    SbRefHelper* pRef;
    int eProcedure;
    int iBase;
    int iScore;
    SandboxTarget(SbRefHelper* apRef, int aeProc, int aiBase);
};
struct SandboxTargetArray
{
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAlloc;
    unsigned int uiUnk0C;
    void Clear(bool abFree);
    unsigned int Append(const SandboxTarget& arItem);
};
class SbActorPackageData;
struct SandboxScanContext
{
    SbActor* pActor;
    SbActorPackageData* pData;
    SandboxScanContext(SbActor* apActor, SbActorPackageData* apData);
};
typedef bool(__cdecl* SandboxScanFunc)(SbRef*, void*);
bool __cdecl SandboxScanCallback(SbRef* apRef, void* apContext);
class SbDataHandler
{
  public:
    void ForEachRefInRange(SbCell* apCell, SbPoint3* apPos1, float afRadius1, SbPoint3* apPos2, float afRadius2,
                           SandboxScanFunc apFunc, void* apContext);
};
class SbActorPackageData
{
  public:
    void** m_ppVirtualMethodTable;
    int eState;
    int eProcedure;
    float m_fProcedureTime;
    SbRef* pLocation;
    float m_fLastProcedureCheckHour;
    float m_fNextProcedureCheckHour;
    unsigned int m_uiLastProcedureCheckDay;
    SandboxTargetArray m_kProcedureList;
    unsigned int m_uiProcedureIndex;
    bool m_bNeedsSandboxUpdate;
    bool m_bHasFoodMarker;
    bool m_bHasChairMarker;
    bool m_bHasBedMarker;
    void ScanSandboxTargets(SbActor* apActor);
};

// Clears the target array and flags, then scans refs in range around the package or location position and appends food and bed targets.
// @fnv 0x009f54d0
void SbActorPackageData::ScanSandboxTargets(SbActor* apActor)
{
    m_kProcedureList.Clear(true);
    m_bHasBedMarker = false;
    m_bHasChairMarker = false;
    m_bHasFoodMarker = false;
    float fRadius = *originalRuntimeFloatSetting255.Float();
    SbCell* pCell = apActor->GetParentCell();
    SbPoint3 kPos7 = *apActor->GetPos();
    SbPackage* pPackage9 = apActor->GetCurrentPackage();
    if (pPackage9)
    {
        kPos7 = pPackage9->GetLocationPos(apActor);
        int iRadius4 = pPackage9->GetPackageDefaultFloat(apActor);
        fRadius = (iRadius4 > 0) ? (float)iRadius4 : fRadius;
    }
    if (pLocation)
    {
        kPos7 = *pLocation->GetPos();
        pCell = pLocation->GetParentCell();
    }
    SandboxScanContext kContext(apActor, this);
    ((SbDataHandler*)g_dataHandler)
        ->ForEachRefInRange(pCell, &kPos7, fRadius, &kPos7, fRadius, SandboxScanCallback, &kContext);
    if (pPackage9->HasFoodTarget())
    {
        SbRef* pUsed = apActor->GetUsedRef();
        if (pUsed && pUsed->GetFlags())
        {
            m_kProcedureList.Append(SandboxTarget(0, 2, 1));
            m_bHasFoodMarker = true;
        }
    }
    if (pPackage9->HasBedTarget())
    {
        m_kProcedureList.Append(SandboxTarget(0, 3, 1));
    }
}

extern double DAT_01012638;
int __cdecl FUN_00ec7d40(int);

struct FUN_009f41f0_owner
{
    float __thiscall FUN_009f41f0(float f1, float f2);
};

// @fnv 0x009f41f0
float __thiscall FUN_009f41f0_owner::FUN_009f41f0(float f1, float f2)
{
    char cA;
    char c2;
    char cG;
    char cK;
    char cW;
    char c6;
    float fres;

    cA = (char)f1;
    c2 = (char)((f1 - cA) * DAT_01012638);
    cG = (char)(((f1 - cA) * DAT_01012638 - (float)c2) * DAT_01012638);
    cK = (char)f2;
    cW = (char)((f2 - cA) * DAT_01012638);
    c6 = (char)(((f2 - cA) * DAT_01012638 - (float)c2) * DAT_01012638);
    fres = (float)FUN_00ec7d40((int)cK - (int)cA);
    if (cW > c2)
    {
        fres += (int)cW - (int)c2;
    }
    else
    {
        fres -= (int)c2 - (int)cW;
    }
    return fres;
}

struct ChoiceTargetRef;
struct ChoiceBaseForm;
struct ChoicePlannerView;
struct ChoicePermissions;
struct ChoiceFurniture;
struct ChoiceTargetRef
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
    virtual bool IsActorSlot();
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
    virtual bool CanActivateSlot(int);
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
    virtual void* GetFurnitureSlot();
    bool FUN_00440d80();
    bool FUN_004077c0();
    bool FUN_00440da0();
    bool FUN_008859e0(ChoiceTargetRef*);
    bool FUN_0057b500();
    ChoiceBaseForm* FUN_007af430();
    ChoicePermissions* FUN_009344a0();
    void* FUN_00567790();
    bool FUN_005785e0(ChoiceTargetRef*, int);
};
struct ChoicePermissions
{
    bool IsFlag8Clear();
    bool IsFlag4Clear();
    bool IsFlag2Clear();
    bool FUN_009f4620();
    bool IsFlagBit0Clear();
};
struct ChoiceMarkerData
{
    unsigned GetByte5();
    unsigned FUN_00479e80();
    bool HasIdleForActor(ChoiceTargetRef*, ChoiceTargetRef*);
};
struct ChoiceBaseForm
{
    unsigned unknown00;
    unsigned unknown04;
    unsigned unknown08;
    unsigned unknown0c;
    unsigned unknown10;
    unsigned unknown14;
    unsigned unknown18;
    unsigned unknown1c;
    unsigned unknown20;
    unsigned unknown24;
    unsigned unknown28;
    unsigned unknown2c;
    ChoiceMarkerData markers;
    unsigned FUN_00401170();
    bool FUN_00509420();
    bool FUN_005093f0();
};
struct ChoiceFurniture
{
    void* FUN_00509490();
};
ChoiceFurniture* __cdecl FUN_00c54400(void*);
struct ChoiceCollection
{
    unsigned AppendElement(const FUN_009f3800&);
};
struct ChoicePlannerView
{
    unsigned unknown00;
    unsigned unknown04;
    unsigned unknown08;
    unsigned unknown0c;
    unsigned unknown10;
    unsigned unknown14;
    unsigned unknown18;
    unsigned unknown1c;
    ChoiceCollection choices;
    unsigned unknown24, unknown28, unknown2c, unknown30;
    unsigned char unknown34;
    bool flag35, flag36, flag37;
};
struct ChoiceContext
{
    ChoicePlannerView* FUN_00726070();
    ChoiceTargetRef* FUN_00559450();
};
extern ChoiceTargetRef* DAT_011dea3c;
// Validates the target and actor, then adds a planner choice based on the target's form type and permission checks; always returns false.
// @fnv 0x009f5070
bool __cdecl AddActivationChoice(ChoiceTargetRef* target, ChoiceContext* pContext)
{
    ChoiceContext* context = pContext;
    ChoicePlannerView* planner = context->FUN_00726070();
    ChoiceTargetRef* actor = context->FUN_00559450();
    if (!planner)
        return false;
    if (!actor || !actor->FUN_007af430())
        return false;
    if (!target || target->FUN_00440d80() || target->FUN_004077c0() || target->FUN_00440da0() ||
        (actor->CanActivateSlot(0) && !actor->FUN_008859e0(target)))
        return false;
    ChoicePermissions* permissions = actor->FUN_009344a0();
    if (!permissions)
        return false;
    if (target->FUN_0057b500())
        return false;
    switch (target->FUN_007af430()->FUN_00401170())
    {
    case 48:
        if (permissions->IsFlag8Clear() && (!target->FUN_00567790() || target->FUN_005785e0(actor, 1)))
        {
            ChoiceBaseForm* markerBase = target->FUN_007af430();
            unsigned markerCount2 = markerBase->markers.GetByte5();
            unsigned markerFlags = markerBase->markers.FUN_00479e80();
            bool markerUsed = false;
            if (markerBase->markers.HasIdleForActor(actor, target))
                planner->choices.AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 4, 1));
        }
        break;
    case 42:
    case 43:
        if (permissions->IsFlag4Clear() && target->IsActorSlot() && target != DAT_011dea3c && target != actor)
            planner->choices.AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 5, 1));
        break;
    case 39: {
        void* object8 = target->GetFurnitureSlot();
        if (!object8)
            return false;
        ChoiceFurniture* furniture = FUN_00c54400(object8);
        if (!furniture)
            return false;
        void* data = furniture->FUN_00509490();
        if (!data)
            return false;
        ChoiceBaseForm* furnitureBase2 = target->FUN_007af430();
        if (permissions->IsFlag2Clear() && furnitureBase2->FUN_00509420() &&
            (!target->FUN_00567790() || target->FUN_005785e0(actor, 1)))
        {
            planner->choices.AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 1, 1));
            planner->flag37 = true;
        }
        else if (permissions->FUN_009f4620() && furnitureBase2->FUN_005093f0() &&
                 (!target->FUN_00567790() || target->FUN_005785e0(actor, 1)))
        {
            planner->choices.AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 0, 1));
            planner->flag36 = true;
        }
        else if (permissions->FUN_009f4620() && !furnitureBase2->FUN_005093f0() && !furnitureBase2->FUN_00509420() &&
                 (!target->FUN_00567790() || target->FUN_005785e0(actor, 1)))
        {
            planner->choices.AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 0, 1));
            planner->flag36 = true;
        }
        break;
    }
    case 29:
    case 47:
        if (permissions->IsFlagBit0Clear() && (!target->FUN_00567790() || target->FUN_005785e0(actor, 1)))
        {
            planner->choices.AppendElement(FUN_009f3800(reinterpret_cast<TESObjectREFRHelper*>(target), 2, 1));
            planner->flag35 = true;
        }
        break;
    }
    return false;
}

class SandboxListBase
{
  public:
    virtual ~SandboxListBase();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class SandboxChoiceList
{
  public:
    int unk00;
    void Clear(int abFree);
    ~SandboxChoiceList();
};

class FUN_009f3a70 : public SandboxListBase
{
  public:
    SandboxChoiceList m_choices;
    virtual ~FUN_009f3a70();
    void Shutdown();
};

// Destructor that calls Shutdown and then clears the m_choices list with abFree set to 1.
// @fnv 0x009f3a70
FUN_009f3a70::~FUN_009f3a70()
{
    Shutdown();
    m_choices.Clear(1);
}

// fallout/ai/patrolpackage.cpp: PatrolActorPackageData, DelStandIn, PatrolData, PatrolData2 (13 functions)

class TESObjectREFR;
class Actor;
class TESPackage;
class TESPatrolPackageData;
class NiPoint3;
class BGSLoadFormBuffer;
class TESForm;
class TESObjectWEAP;
class NavMeshInfo;

class BSSimpleArray_TESObjectWEAP___1024_
{
  public:
    void SetSize(unsigned int, bool);
};
class BSSimpleArray_NavMeshInfo___1024_
{
  public:
    NavMeshInfo*& GetAt(int);
};

class LocationDescriptor
{
  public:
    void SetLocRef(TESObjectREFR*);
    TESObjectREFR* GetLocationReference();
};

class TESObjectREFR
{
  public:
    virtual ~TESObjectREFR();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    TESObjectREFR* GetLinkedRef();
};

class ArchiveManager
{
  public:
    void CopyArchiveName(char*, unsigned int);
};

class TESPackage
{
  public:
    virtual ~TESPackage();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    const TESPatrolPackageData* GetPackagePatrolData();
};

class BGSLoadGameBuffer
{
  public:
    void ReadDataBlock(void*, unsigned int);
    unsigned int ReadFormIdentifier();
};

class BGSLoadFormBuffer
{
  public:
    bool ReadFormIdentifier(void*);
    int ReadElementCount();
};

class TESForm
{
  public:
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    static TESForm* GetFormByID(unsigned int);
};

class PatrolActorPackageData
{
  public:
    void* vtable;
    bool flag;

    bool IsPatrolling();
    TESObjectREFR* GetPatrolReference(Actor*, TESPackage*);
    bool Init(Actor*, TESPackage*);
    void SetPatrolPosition(const NiPoint3&);
    void LoadGame(BGSLoadFormBuffer*);
};

// @fnv 0x004f1540
bool PatrolActorPackageData::IsPatrolling()
{
    return flag;
}

extern int DAT_010933c8;

class EscortActorPackageData
{
  public:
    void FUN_0067d920();
};

// Calls FUN_0067d920, installs the vtable at DAT_010933c8, and zeroes fields at offsets 0x4 through 0x10 before returning thisPtr.
// @fnv 0x009f27a0
void* __fastcall InitEscortPackageData(void* thisPtr)
{
    reinterpret_cast<EscortActorPackageData*>(thisPtr)->FUN_0067d920();
    *reinterpret_cast<void**>(thisPtr) = &DAT_010933c8;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(thisPtr) + 0x8) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(thisPtr) + 0xc) = 0;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(thisPtr) + 0x10) = 0.0f;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(thisPtr) + 0x4) = 0;
    return thisPtr;
}

struct FUN_009f2a30_shell : public PatrolActorPackageData
{
    int GetPackageType();
};

// @fnv 0x009f2a30
int FUN_009f2a30_shell::GetPackageType()
{
    return 0xd;
}

struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_009f2ba0_shell : public PatrolActorPackageData
{
    bool InitPatrolPackage(Actor*, TESPackage*);
};

// Stores the actor and package, resets counters, and if the package is valid and has patrol data, initializes the patrol from the actor's position.
// @fnv 0x009f2ba0
bool FUN_009f2ba0_shell::InitPatrolPackage(Actor* apActor, TESPackage* apPackage)
{
    *(Actor**)((char*)this + 0x10) = apActor;
    *(TESPackage**)((char*)this + 0x14) = apPackage;
    *(const TESPatrolPackageData**)((char*)this + 0x18) = apPackage->GetPackagePatrolData();
    *(int*)((char*)this + 0x34) = 0;
    *(bool*)((char*)this + 0x0c) = true;
    *(int*)((char*)this + 0x30) = 0;
    bool bvalid = (((ArchiveManager*)this)->*(bool(ArchiveManager::*)()) & ArchiveManager::CopyArchiveName)();
    if (bvalid)
    {
        if ((*(PatrolActorPackageData**)((char*)this + 0x18))->IsPatrolling())
        {
            SetPatrolPosition((*(const NiPoint3&(__thiscall**)(Actor*))(*(int*)apActor + 0x1f4))(apActor));
        }
    }
    return bvalid;
}

class BGSMessageInitAccess
{
  public:
    unsigned int GetIconFormID();
};

// Returns the reference from the pack's icon form if it resolves to one, otherwise falls back to the actor's linked reference.
// @fnv 0x009f2d40
TESObjectREFR* __cdecl FUN_009f2d40(TESObjectREFR* apActor, BGSMessageInitAccess* apPack)
{
    LocationDescriptor* ploc;
    TESObjectREFR* pinitialReference = 0;

    ploc = reinterpret_cast<LocationDescriptor*>(apPack->GetIconFormID());
    if (ploc)
    {
        TESObjectREFR* plocRef = ploc->GetLocationReference();
        if (plocRef)
        {
            pinitialReference = plocRef;
        }
    }

    if (!pinitialReference)
    {
        TESObjectREFR* plinkedRef = apActor->GetLinkedRef();
        if (plinkedRef)
        {
            pinitialReference = plinkedRef;
        }
    }

    return pinitialReference;
}

namespace fnv_009f30d0 {
struct Actor;
struct ActorCause;
struct ActorPackageData;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSMusicType;
struct BGSPrimitive;
struct BGSSaveFormBuffer;
struct BGSTalkingActivator;
struct BSExtraData;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BSOcclusionPlane;
struct BSPortal;
struct SoundPlaybackHandle;
struct BaseExtraList;
struct BipedAnim;
struct CellMopp;
struct CollisionData;
struct Crime;
struct TeleportableReference;
struct ExtraAction;
struct ExtraActorCause;
struct ExtraAmmo;
struct ExtraAnim;
struct ExtraAshPileReference;
struct ExtraAudioBuoyMarker;
struct ExtraAudioMarker;
struct ExtraCannotWearData;
struct ExtraDataList;
struct ExtraDismemberedLimbs;
struct ExtraFactionChanges;
struct ExtraFollower;
struct ExtraFollowerSwimBreadcrumbs;
struct ExtraLeveledItem;
struct ExtraLight;
struct ExtraLock;
struct ExtraMapMarker;
struct ExtraNavMeshPortal;
struct ExtraRefractionProperty;
struct ExtraSayToTopicInfo;
struct ExtraSayTopicInfoOnceADay;
struct ExtraStartingPosition;
struct ExtraTalkingActor;
struct ExtraTeleport;
struct PositionRotation;
struct ImpactSwap;
struct InventoryChanges;
struct MapMarkerData;
struct MenuTopic;
struct Point3Offset;
struct NiNode;
struct NiPoint3;
struct NiRenderedTexture;
struct PatrolReferenceData;
struct PatrolRefData;
struct LinkedReferencePair;
struct RadioReferenceData;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceFloatEntry;
struct RagDollData;
struct PointerFlagNode;
struct TopicInfoVisitRecord;
struct Script;
struct ScriptLocals;
struct SeenData;
struct TESActorBase;
struct TESAmmo;
struct TESClimate;
struct TESCombatStyle;
struct TESFaction;
struct TESFile;
struct TESGlobal;
struct TESImageSpace;
struct TESModel;
struct TESNPC;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TrespassPackage;
struct WorldLocation;
struct WaterZone;
struct _D3DLOCKED_RECT;
struct bhkWorld;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_009f30d0_shell : public PatrolActorPackageData
{
    bool SetPatrolRefIndex(unsigned int);
};

struct NavMeshEdgeSegment;
template <class T, int N> struct BSSimpleArray
{
    bool FUN_0076b610() const;
    unsigned int& GetAt(unsigned int);
};
struct ArrFlagsHelper
{
    unsigned int GetFlags();
};
struct RefExtraHelper
{
    const ExtraDataList* GetExtra() const;
};
struct ExtraHelper
{
    bool FUN_0042f3d0(void*);
    void FUN_0042f300(void*);
};
struct PatrolHelper
{
    void FUN_009f2b30();
};
void __cdecl ClampInt(unsigned int*, int, int);

// @fnv 0x009f30d0
bool FUN_009f30d0_shell::SetPatrolRefIndex(unsigned int aiRefIndex)
{
    if (((BSSimpleArray<NavMeshEdgeSegment, 1024>*)((char*)this + 0x1c))->FUN_0076b610() ||
        !*(unsigned char*)((char*)this + 0x2c))
    {
        *(unsigned int*)((char*)this + 0x34) = aiRefIndex;
        return true;
    }
    unsigned int aiclampedRefIndex = aiRefIndex;
    int isize = ((ArrFlagsHelper*)((char*)this + 0x1c))->GetFlags() - 1;
    ClampInt(&aiclampedRefIndex, 0, isize);
    bool bsuccess = true;
    TESObjectREFR* pnewRef =
        (TESObjectREFR*)((BSSimpleArray<unsigned int, 1024>*)((char*)this + 0x1c))->GetAt(aiclampedRefIndex);
    ExtraDataList* pnewExtra = pnewRef ? (ExtraDataList*)((RefExtraHelper*)pnewRef)->GetExtra() : 0;
    if (pnewExtra)
    {
        if (((ExtraHelper*)pnewExtra)->FUN_0042f3d0(*(void**)((char*)this + 0x10)))
        {
            ((PatrolHelper*)this)->FUN_009f2b30();
            ((ExtraHelper*)pnewExtra)->FUN_0042f300(*(void**)((char*)this + 0x10));
            *(unsigned int*)((char*)this + 0x34) = aiclampedRefIndex;
        }
        else
        {
            bsuccess = false;
        }
    }
    return bsuccess;
}
}  // namespace fnv_009f30d0

struct FUN_009f3390_shell : public PatrolActorPackageData
{
    TESObjectREFR* FUN_009f3390();
};

template <class T, unsigned int N> class BSSimpleArray;
class NavMeshEdgeSegment;

template <> class BSSimpleArray<NavMeshEdgeSegment, 1024>
{
  public:
    bool FUN_0076b610() const;
};

template <> class BSSimpleArray<unsigned int, 1024>
{
  public:
    unsigned int& GetAt(unsigned int);
};

// @fnv 0x009f3390
TESObjectREFR* FUN_009f3390_shell::FUN_009f3390()
{
    if (!((BSSimpleArray<NavMeshEdgeSegment, 1024>*)((char*)this + 0x1c))->FUN_0076b610())
    {
        return (TESObjectREFR*)((BSSimpleArray<unsigned int, 1024>*)((char*)this + 0x1c))
            ->GetAt(*(unsigned int*)((char*)this + 0x34));
    }
    else
    {
        return 0;
    }
}

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_009f2a40(unsigned int flags);
};
// Runs the destructor, then frees this object when flags has bit 0 set, and returns this.
// @fnv 0x009f2a40
void* DelStandIn::FUN_009f2a40(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        Deallocate(this);
    return this;
}
}

struct DH
{
    bool FUN_004226e0();
};
extern DH* g_dataHandler;
struct _Mem_20a4
{
    ~_Mem_20a4();
    void SetSize(unsigned int, bool);
};
struct P_009f2b30
{
    void FUN_009f2b30();
};
struct FUN_0067d970
{
    int mode;
    int pad[2];
    virtual ~FUN_0067d970();
};
struct FUN_009f2a70 : public FUN_0067d970
{
    int a;
    int b;
    int c;
    _Mem_20a4 arr;
    ~FUN_009f2a70();
};
// @fnv 0x009f2a70
FUN_009f2a70::~FUN_009f2a70()
{
    if (!g_dataHandler->FUN_004226e0())
        ((P_009f2b30*)this)->FUN_009f2b30();
    arr.SetSize(0, true);
    mode = 4;
    a = 0;
    b = 0;
    c = 0;
}

namespace fnv_009f33d0 {
struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
    void SerializeFormData(void*, int);
    void FUN_00865f60(unsigned int);
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct BSSimpleArray
{
    unsigned int& GetAt(int);
};
struct FUN_009f33d0_shell
{
    void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x009f33d0
void FUN_009f33d0_shell::SaveGame(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData((char*)this + 0x4, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x8, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x34, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0xc, 1, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x2c, 1, 0);
    apSaveGameBuffer->SaveData((char*)this + 0x30, 4, 0);
    apSaveGameBuffer->SerializeFormData(*(void**)((char*)this + 0x14), 0);
    unsigned int isaveGameCount = (ArrSI*)((char*)this + 0x1c) ? ((ArrSI*)((char*)this + 0x1c))->GetFlags() : 0;
    apSaveGameBuffer->FUN_00865f60(isaveGameCount);
    for (unsigned int i = 0; i < isaveGameCount; ++i)
    {
        TESObjectREFR** ppRefr = (TESObjectREFR**)&((BSSimpleArray*)((char*)this + 0x1c))->GetAt(i);
        apSaveGameBuffer->SerializeFormData(*ppRefr, 0);
    }
}
}  // namespace fnv_009f33d0

struct PatrolTarget
{
    bool FUN_0042f3d0(void* p);
};
struct PatrolRef
{
    PatrolTarget* FUN_005d43c0();
};
struct PatrolRefArray
{
    PatrolRef*& GetAt(unsigned int i);
    unsigned int GetSize();
};
struct PatrolPackage
{
    bool FUN_004f1540();
};

class PatrolData
{
  public:
    void* vtable;
    int unk04;
    int unk08;
    bool bForward;
    void* unk10;
    int unk14;
    PatrolPackage* unk18;
    PatrolRefArray refs;
    int unk20;
    int unk24;
    int unk28;
    bool bRepeat;
    int unk30;
    int iCurrent;

    bool SetPatrolRefIndex(int aiIndex);
    bool AdvancePatrolIndex(bool abApply);
};

// Computes the next patrol index from iCurrent and bForward, wrapping or reversing at the ends, and applies it via SetPatrolRefIndex when abApply is set.
// @fnv 0x009f2ea0
bool PatrolData::AdvancePatrolIndex(bool abApply)
{
    int idx = iCurrent;
    bool bResult = true;
    bool bLoop = unk18 ? unk18->FUN_004f1540() : false;
    if (bForward)
    {
        idx++;
        if (idx == refs.GetSize())
        {
            if (bLoop)
            {
                if (bRepeat)
                {
                    idx = unk30;
                }
                else
                {
                    if (refs.GetSize() == 1)
                        idx = 0;
                    else
                        idx -= 2;
                    bForward = !bForward;
                }
            }
            else
            {
                idx = 0;
                bResult = false;
            }
        }
    }
    else
    {
        idx--;
        if (idx == -1)
        {
            if (bLoop)
            {
                if (bRepeat)
                {
                    idx = 0;
                    bResult = false;
                }
                else
                {
                    if (refs.GetSize() == 1)
                        idx = 0;
                    else
                        idx = 1;
                    bForward = !bForward;
                }
            }
            else
            {
                idx = 0;
                bResult = false;
            }
        }
    }
    if (abApply)
    {
        if (idx != iCurrent)
        {
            bool bOk = SetPatrolRefIndex(idx);
            if (!bOk)
            {
                unsigned int numRefs = refs.GetSize();
                unsigned int uiValid = numRefs - 1;
                for (unsigned int i = 0; i < numRefs; i++)
                {
                    PatrolRef* pRef = refs.GetAt(i);
                    PatrolTarget* pTarget = pRef ? pRef->FUN_005d43c0() : 0;
                    if (i == iCurrent)
                        continue;
                    if (!pTarget || !pTarget->FUN_0042f3d0(unk10))
                        uiValid--;
                }
                if (uiValid <= 0)
                    return AdvancePatrolIndex(false);
            }
        }
    }
    else
    {
        iCurrent = idx;
    }
    return bResult;
}

namespace fnv_009f31c0 {
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3 operator-(const NiPoint3& rhs) const;
    float GetSquaredXYLength() const;
};
struct PatrolRefStub
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
    virtual void v046();
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
    virtual NiPoint3* GetPos();
    PatrolTarget* GetTarget();
};
struct PatrolData2 : public PatrolData
{
    PatrolRefStub* GetCurRef();
    void SelectClosestPatrolPoint(const NiPoint3& arPoint);
};
extern float DAT_01016970;

// @fnv 0x009f31c0
void PatrolData2::SelectClosestPatrolPoint(const NiPoint3& arPoint)
{
    if (!unk10)
        return;
    int BackgroundTask = refs.GetSize();
    SetPatrolRefIndex(0);
    bForward = true;
    PatrolRefStub* pOld = 0;
    NiPoint3* pOrigPos = 0;
    int iPrevIdx = 0;
    bool bOldForward = true;
    PatrolRefStub* pR = GetCurRef();
    if (!pR)
        return;
    NiPoint3* pPt = pR->GetPos();
    float afThirdFloatArgument = DAT_01016970;
    int iWinner = 0;
    bool bBest = true;
    bool bSuccess = false;
    for (int i = 0; i < BackgroundTask; i++)
    {
        iPrevIdx = iCurrent;
        bOldForward = bForward;
        pOld = pR;
        pOrigPos = pPt;
        AdvancePatrolIndex(false);
        PatrolRefStub* pNext = GetCurRef();
        PatrolTarget* pData = pNext ? pNext->GetTarget() : 0;
        if (!pData || pData->FUN_0042f3d0(unk10))
        {
            pR = GetCurRef();
            if (!pR)
                break;
            pPt = pR->GetPos();
            NiPoint3 kDelta = *pOrigPos - arPoint;
            NiPoint3 kLine = *pPt - *pOrigPos;
            float fDistance = kDelta.GetSquaredXYLength();
            if (fDistance < afThirdFloatArgument)
            {
                afThirdFloatArgument = fDistance;
                iWinner = iPrevIdx;
                bBest = bOldForward;
                bSuccess = true;
            }
        }
    }
    if (bSuccess)
    {
        SetPatrolRefIndex(iWinner);
        bForward = bBest;
    }
    bForward = true;
}
}  // namespace fnv_009f31c0

struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct PatrolReference
{
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual const NiPoint3& GetPos();
};
struct ReferenceArray
{
    void* vtable;
    void* entries;
    unsigned int capacity, used, elementSize, growth;
    unsigned int FUN_0044ddc0();
    int* FUN_00877a30(unsigned int);
    void FUN_006bf8f0(unsigned int, bool);
};
struct FUN_009f2c30_Class
{
    void* vtable;
    int state;
    int unk08;
    int unk0c;
    PatrolReference* activeReference;
    int unk14, unk18;
    ReferenceArray references;
    unsigned int referenceIndex;
    void FUN_009f2b30();
    bool SetPatrolRefIndex(unsigned int);
    void SelectClosestPatrolPoint(const NiPoint3&);
    void RemoveReference(PatrolReference*);
};
// Removes a patrol reference: if it is the active one, resets state; otherwise erases it from the array and adjusts the active index.
// @fnv 0x009f2c30
void FUN_009f2c30_Class::RemoveReference(PatrolReference* reference)
{
    if (reference == activeReference)
    {
        FUN_009f2b30();
        state = 3;
        activeReference = 0;
        unk14 = 0;
        unk18 = 0;
    }
    else
    {
        unsigned int index;
        for (index = 0; index < references.FUN_0044ddc0(); index++)
        {
            if (*references.FUN_00877a30(index) == (int)reference)
            {
                references.FUN_006bf8f0(index, true);
                if (referenceIndex >= index)
                    referenceIndex--;
                index--;
            }
        }
        if (activeReference && !g_BGSSaveLoadGame->FUN_0042ce10())
        {
            if (!SetPatrolRefIndex(referenceIndex))
            {
                SelectClosestPatrolPoint(activeReference->GetPos());
            }
        }
    }
}

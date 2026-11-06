
// extradatalist_ctx_variant.cpp: context variant of src/fallout_shared/extradatalist.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include "extradatalist_packet.h"
#include "ExtraDataList.h"
#include "ExtraContainerChanges.h"
#include "InventoryChanges.h"
#include "game_constants.h"

void* memcpy(void* apDest, const void* apSrc, unsigned int auiSize);

class BGSPortal;
class BGSPrimitive;
class BGSAcousticSpace;
class BGSEncounterZone;
class BGSMusicType;
class TESClimate;
class TESImageSpace;
class TESGlobal;
class TESFaction;
class TESWaterForm;
class Script;
class ScriptLocals;
class NiNode;
class NiTexture;
class TESWorldSpace : public TESForm
{
};
class TESTopicInfo;
class BSMultiBound;
class BSMultiBoundRoom;
class BSOcclusionShape;
class BSPortal;
class CanopyShadowMaskData;
class RagDollData;
class LevCreaModifierData;
class RadioData;
class DistantData;
class FollowerSwimBreadcrumb;

int Warning(const char* format, ...);

class NiRefCounted
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class NiCell3DNode : public NiRefCounted
{
};
class NiCanopyTexture : public NiRefCounted
{
};
class BSMultiBoundNode : public NiRefCounted
{
};
class BSRoomNode : public NiRefCounted
{
};
class BSOcclusionShapeNode : public NiRefCounted
{
};
class BSPortalNode : public NiRefCounted
{
};

class BSExtraDataEx : public BSExtraData
{
  public:
    unsigned char GetType();
};

struct LockExtraData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    LockExtraData();
};

struct TeleportableReference
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    TeleportableReference();
    void Copy(TeleportableReference* apSource);
};

struct MapMarkerData
{
    int unk00, unk04, unk08, unk0C, unk10;
    MapMarkerData();
    void Copy(MapMarkerData* apSource);
};

struct MediaLocation
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    MediaLocation();
    void Copy(MediaLocation* apSource);
};

struct TwoIntegerValues
{
    int unk00, unk04;
    TwoIntegerValues();
    void Copy(TwoIntegerValues* apSource);
};

struct ImpactSwap
{
    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C, unk020, unk024, unk028, unk02C, unk030, unk034,
        unk038, unk03C, unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C, unk060, unk064, unk068, unk06C,
        unk070, unk074, unk078, unk07C, unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C, unk0A0, unk0A4,
        unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC, unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC,
        unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC, unk100, unk104, unk108, unk10C, unk110, unk114,
        unk118, unk11C, unk120, unk124, unk128, unk12C, unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C,
        unk150, unk154, unk158;
    ImpactSwap();
    void Copy(ImpactSwap* apSource);
};

struct Point3Offset
{
    int unk00, unk04, unk08;
    Point3Offset();
    void Copy(Point3Offset* apSource);
};

struct PatrolRefData
{
    int unk00, unk04, unk08, unk0C, unk10;
    PatrolRefData();
    void Copy(PatrolRefData* apSource);
};

struct PatrolReferenceData
{
    TESObjectREFR* m_pPatrolReferences[4];
    PatrolReferenceData();
};

struct PortalRefData
{
    TESObjectREFR* pRooms[2];
};

struct RoomRefData
{
    int unk00;
    int unk04;
    BSSimpleList<TESObjectREFR*> kLinkedRooms;
    unsigned char bIsMaster;
};

struct CollisionData
{
    unsigned int GetCollisionLayer() const;
    void SetCollisionLayer(unsigned int auiLayer);
    unsigned int uiCollisionLayer;
    CollisionData();
};

struct PackageReference
{
    TESPackage* pPackage;
    unsigned char bPickResultFound;
};

struct FactionRankData
{
    TESFaction* pFaction;
    char m_ucRank;
};

struct CanopyShadowMaskData
{
    int unk00;
    int unk04;
};

class BGSPrimitive
{
  public:
    static BGSPrimitive* __cdecl Copy(BGSPrimitive* apSource);
};

class ExtraFactionChanges
{
  public:
    void AddToFaction(TESFaction* apFaction, int aiRank);
};

class ExtraEditorRefMoveData : public BSExtraDataEx
{
  public:
    NiPoint3 kRealLocation;
    NiPoint3 kRealAngle;
    NiPoint3 kOldLocation;
    ExtraEditorRefMoveData(TESObjectREFR* apRef);
};

class ExtraAction : public BSExtraDataEx
{
  public:
    unsigned char cFlags;
};
class ExtraOwnership : public BSExtraDataEx
{
  public:
    TESForm* pOwner;
};
class ExtraGlobal : public BSExtraDataEx
{
  public:
    TESGlobal* pGlobalForm;
};
class ExtraRank : public BSExtraDataEx
{
  public:
    int m_iRank;
};
class ExtraCount : public BSExtraDataEx
{
  public:
    unsigned short m_sCount;
};
class ExtraAmmo : public BSExtraDataEx
{
  public:
    TESForm* pAmmo;
    int iCount;
};
class ExtraHotkey : public BSExtraDataEx
{
  public:
    unsigned char cKey;
};
class ExtraSeed : public BSExtraDataEx
{
  public:
    unsigned char cSeed;
};
class ExtraLeveledItem : public BSExtraDataEx
{
  public:
    int iLevelItem;
    unsigned char bFlag;
};
class ExtraHealth : public BSExtraDataEx
{
  public:
    float fHealthPercent;
};
class ExtraHealthPerc : public BSExtraDataEx
{
  public:
    float m_fHealthPercentage;
};
class ExtraUses : public BSExtraDataEx
{
  public:
    unsigned char m_ucUses;
};
class ExtraTimeLeft : public BSExtraDataEx
{
  public:
    float fTimeLeft;
};
class ExtraCharge : public BSExtraDataEx
{
  public:
    float m_fCharge;
};
class ExtraScript : public BSExtraDataEx
{
  public:
    Script* pScript;
    ScriptLocals* pLocals;
};
class ExtraScale : public BSExtraDataEx
{
  public:
    float fScale;
};
class ExtraLock : public BSExtraDataEx
{
  public:
    LockExtraData* pLock;
};
class ExtraRadioData : public BSExtraDataEx
{
  public:
    int kRadioData;
};
class ExtraTeleport : public BSExtraDataEx
{
  public:
    TeleportableReference* pData;
};
class ExtraMapMarker : public BSExtraDataEx
{
  public:
    MapMarkerData* pData;
};
class ExtraAudioMarker : public BSExtraDataEx
{
  public:
    MediaLocation* pData;
};
class ExtraAudioBuoyMarker : public BSExtraDataEx
{
  public:
    TwoIntegerValues* pData;
};
class ExtraPackageStartLocation : public BSExtraDataEx
{
  public:
    TESForm* pLocation;
    NiPoint3 kPos;
    float fAngleDifference;
};
class ExtraRagDollData : public BSExtraDataEx
{
  public:
    RagDollData* pData;
};
class ExtraDistantData : public BSExtraDataEx
{
  public:
    int kDistantData;
};
class ExtraFollower : public BSExtraDataEx
{
  public:
    BSSimpleList<Actor*>* pFollowers;
};
class ExtraHeadTrackTarget : public BSExtraDataEx
{
  public:
    TESObjectREFR* pTarget;
};
class ExtraPoison : public BSExtraDataEx
{
  public:
    TESForm* m_pPoisonItem;
};
class ExtraCell3D : public BSExtraDataEx
{
  public:
    NiPointer<NiCell3DNode> m_pController;
};
class ExtraWaterType : public BSExtraDataEx
{
  public:
    TESWaterForm* m_pWaterForm;
};
class ExtraMusicType : public BSExtraDataEx
{
  public:
    BGSMusicType* pMusic;
};
class ExtraAcousticSpace : public BSExtraDataEx
{
  public:
    BGSAcousticSpace* m_pPathingCell;
};
class ExtraCanopyShadowMask : public BSExtraDataEx
{
  public:
    int iMask;
    NiPointer<NiCanopyTexture> spTexture;
    int unk14;
    int unk18;
};
class ExtraClimate : public BSExtraDataEx
{
  public:
    TESClimate* pClimateData;
};
class ExtraImageSpace : public BSExtraDataEx
{
  public:
    TESImageSpace* m_pImageSpace;
};
class ExtraImpactSwap : public BSExtraDataEx
{
  public:
    ImpactSwap* pSwap;
};
class ExtraReferencePointer : public BSExtraDataEx
{
  public:
    TESObjectREFR* pRef;
};
class ExtraPackage : public BSExtraDataEx
{
  public:
    TESPackage* pPackage;
    int iPackageFlags;
    int m_iPackageData;
    unsigned char cA;
    unsigned char m_ucPackageByte;
    unsigned char cC;
};
class ExtraTresPassPackage : public BSExtraDataEx
{
  public:
    TESPackage* pPackage;
};
class ExtraRunOncePacks : public BSExtraDataEx
{
  public:
    BSSimpleList<PackageReference*>* pPackages;
};
class ExtraOriginalReference : public BSExtraDataEx
{
  public:
    TESObjectREFR* pRef;
};
class ExtraEnableStateParent : public BSExtraDataEx
{
  public:
    TESObjectREFR* pParent;
    unsigned char cFlags;
};
class ExtraRandomTeleportMarker : public BSExtraDataEx
{
  public:
    TESObjectREFR* pTeleportMarker;
};
class ExtraLinkedRef : public BSExtraDataEx
{
  public:
    TESObjectREFR* m_pLinkedReference;
};
class ExtraActivateRef : public BSExtraDataEx
{
  public:
    int unk0C, unk10, unk14, unk18, unk1C;
    ExtraActivateRef();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraDecalRefs : public BSExtraDataEx
{
  public:
    int unk0C, unk10;
    ExtraDecalRefs();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraReflectedRefs : public BSExtraDataEx
{
  public:
    int unk0C, unk10;
    ExtraReflectedRefs();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraReflectorRefs : public BSExtraDataEx
{
  public:
    int unk0C, unk10;
    ExtraReflectorRefs();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraLitWaterRefs : public BSExtraDataEx
{
  public:
    int unk0C, unk10;
    ExtraLitWaterRefs();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraWaterLightRefs : public BSExtraDataEx
{
  public:
    int unk0C, unk10;
    ExtraWaterLightRefs();
    void Copy(BSExtraDataEx* apSource);
};
class ExtraMerchantContainer : public BSExtraDataEx
{
  public:
    TESObjectREFR* pContainer;
};
class ExtraXTarget : public BSExtraDataEx
{
  public:
    TESObjectREFR* pTarget;
};
class ExtraEncounterZone : public BSExtraDataEx
{
  public:
    BGSEncounterZone* m_pEncounterZone;
};
class ExtraEmittanceSource : public BSExtraDataEx
{
  public:
    TESForm* pSource;
};
class ExtraMultiBoundRef : public BSExtraDataEx
{
  public:
    TESObjectREFR* pRef;
};
class ExtraMultiBoundMarkerData : public BSExtraDataEx
{
  public:
    Point3Offset* pData;
};
class ExtraLevCreaModifier : public BSExtraDataEx
{
  public:
    int iModifier;
};
class ExtraRefractionProperty : public BSExtraDataEx
{
  public:
    float fRefraction;
};
class ExtraRadius : public BSExtraDataEx
{
  public:
    float fRadius;
};
class ExtraRadiation : public BSExtraDataEx
{
  public:
    float m_fRadiation;
};
class ExtraFactionChangesData : public BSExtraDataEx
{
  public:
    BSSimpleList<FactionRankData*>* pFactions;
};
class ExtraPrimitive : public BSExtraDataEx
{
  public:
    BGSPrimitive* m_pPrimitive;
};
class ExtraMultiBound : public BSExtraDataEx
{
  public:
    NiPointer<BSMultiBoundNode> m_kMultiBoundNode;
};
class ExtraRoom : public BSExtraDataEx
{
  public:
    NiPointer<BSRoomNode> m_pRoomNode;
};
class ExtraPatrolRefData : public BSExtraDataEx
{
  public:
    PatrolRefData* pData;
};
class ExtraOcclusionShape : public BSExtraDataEx
{
  public:
    NiPointer<BSOcclusionShapeNode> pShape;
};
class ExtraOcclusionPlaneRefData : public BSExtraDataEx
{
  public:
    PatrolReferenceData* pData;
};
class ExtraPortalRefData : public BSExtraDataEx
{
  public:
    PortalRefData* pData;
};
class ExtraRoomRefData : public BSExtraDataEx
{
  public:
    RoomRefData* pData;
};
class ExtraCollisionData : public BSExtraDataEx
{
  public:
    CollisionData* pData;
};
class ExtraSayTopicInfoOnceADay : public BSExtraDataEx
{
  public:
    BSSimpleList<TESTopicInfo*>* m_pTopicInfoList;
};
class ExtraPortal : public BSExtraDataEx
{
  public:
    NiPointer<BSPortalNode> m_pPortalNode;
};
class ExtraFollowerSwimBreadcrumbs : public BSExtraDataEx
{
  public:
    int iCount;
    NiPoint3 kLastPos;
    int iLastCell;
    BSSimpleList<FollowerSwimBreadcrumb*> kBreadcrumbs;
};
class ExtraWeaponModFlags : public BSExtraDataEx
{
  public:
    bool IsModActive(unsigned char acSlot);
};

class ExtraSpecialRenderFlags
{
  public:
    unsigned char cType;
    BSExtraData* pNext;
    int iFlags;
    int unk10;
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void CopyFrom(BSExtraDataEx* apSource);
    ExtraSpecialRenderFlags();
};

class ExtraDataListEx : public ExtraDataList
{
  public:
    bool AttachExtraData(BSExtraDataEx* apExtra);
    void GetLocalData(unsigned int auiFlags);
    void SetOwnership(TESForm* apOwner);
    void SetGlobalForm(TESGlobal* apGlobal);
    void SetRank(int aiRank);
    void SetCount(short asCount);
    void SetAmmoExtra(TESForm* apAmmo, int aiCount);
    void SetEquippedState(bool abWorn, bool abLeft);
    void SetHotKey(unsigned char acKey);
    void SetSeedIndex(unsigned char acSeed);
    void SetLeveledItem(int aiLevelItem);
    void SetLevelItemExtraFlag(unsigned char acFlag);
    void SetHealth(float afHealth);
    void SetHealthPerc(float afHealthPerc);
    void SetUses(unsigned char acUses);
    void SetTimeLeft(float afTimeLeft);
    void SetCharge(float afCharge);
    void SetScript(Script* apScript);
    void AssignScriptLocals(ScriptLocals* apLocals);
    void SetScale(float afScale);
    void SetLockData(LockExtraData* apLock);
    void SetRadioData(int* apRadioData);
    void SetTeleportData(TeleportableReference* apData);
    void SetMapMarkerPtr(MapMarkerData* apData);
    void SetAudioMarkerPtr(MediaLocation* apData);
    void SetAudioBuoyMarkerPtr(TwoIntegerValues* apData);
    void RelocateTo(TESWorldSpace* apWorld, TESObjectCELL* apCell, NiPoint3* apPos, float afAngle);
    void SetRagDollDataFromCopy(RagDollData* apData);
    void SetWeaponModFlags(int* apData);
    void SetCombatOpponent(Actor* apFollower);
    void SetHeadTrackTargetExtra(TESObjectREFR* apTarget);
    void SetPoison(TESForm* apPoison);
    void SetCell3D(NiCell3DNode* apNode);
    void SetWaterType(TESWaterForm* apWater);
    void SetMusicType(BGSMusicType* apMusic);
    void SetAcousticSpace(BGSAcousticSpace* apSpace);
    void SetCanopyShadowMaskData(int aiMask, NiCanopyTexture* apTexture, CanopyShadowMaskData** appData);
    void SetClimate(TESClimate* apClimate);
    void SetImageSpace(TESImageSpace* apImageSpace);
    void SetImpactSwapData(ImpactSwap* apSwap);
    void SetActivateRef(TESObjectREFR* apRef);
    void SetPackageOverride(TESPackage* apPackage, int aiFlags, int aiTime, unsigned char acA, unsigned char acB,
                            unsigned char acC);
    void SetActivePackage(TESPackage* apPackage);
    void SetPackageDoneState(TESPackage* apPackage, unsigned char acDone);
    void SetEnableStateChildren(TESObjectREFR* apRef);
    void SetEnableStateParentRef(TESObjectREFR* apParent);
    void SetEnableStateParentFlags(unsigned char acFlags);
    void SetRandomTeleportMarker(TESObjectREFR* apMarker);
    void SetLinkedRef(TESObjectREFR* apRef);
    void SetMerchantContainer(TESObjectREFR* apContainer);
    void SetXTarget(TESObjectREFR* apTarget);
    void SetEncounterZone(BGSEncounterZone* apZone);
    void SetEmittanceSource(TESForm* apSource);
    void SetMultiBoundRef(TESObjectREFR* apRef);
    void SetExtraRecord(Point3Offset* apData);
    void SetLevCreaModifier(int aiModifier);
    void SetRefractionAmount(bool abSet, float afRefraction);
    void SetCannotWear(bool abCanNotWear);
    void SetRadius(float afRadius);
    void SetRadiation(float afRadiation);
    void UpdateExtraDataListExtension();
    ExtraFactionChanges* GetFactionChangesExtra();
    void SetPortalRefData(BSExtraDataEx* apPortal);
    void AddPrimitive(BGSPrimitive* apPrimitive);
    void SetMultiBound(BSMultiBoundNode* apMultiBound);
    void SetRoomNode(BSRoomNode* apRoom);
    void SetPatrolRefData(PatrolRefData* apData);
    void SetOcclusionShape(BSOcclusionShapeNode* apShape);
    void SetRoomRefData(PatrolReferenceData* apData);
    void SetRoomLinkedRoomRef(int aiIndex, TESObjectREFR* apRoom);
    void AddRoomLinkedRoomRef(TESObjectREFR* apRoom);
    void SetRoomIsMaster(bool abMaster);
    void SetCollisionData(CollisionData* apData);
    void SetExtraSayTopicInfoOnceADayExtra(TESTopicInfo* apInfo);
    void SetPortalNode(BSPortalNode* apPortal);
    void SetIgnoredBySandbox(bool abIgnored);
    ExtraFollowerSwimBreadcrumbs* GetFollowerSwimBreadcrumbsExtra();
    void RemoveExtraByType(unsigned char acSlot);
    void CopyExtra(BSExtraDataEx* apExtra);
};

// @fnv 0x004103d0
void ExtraDataListEx::CopyExtra(BSExtraDataEx* apExtra)
{
    if (!apExtra || !AttachExtraData(apExtra))
        return;

    BSSimpleList<PackageReference*>* pIter = 0;
    switch (apExtra->GetType())
    {
    case 0x4C: {
        ExtraEditorRefMoveData* pMoveData = (ExtraEditorRefMoveData*)GetExtraData(0x4C);
        if (!pMoveData)
        {
            pMoveData = new ExtraEditorRefMoveData(0);
            AddExtra(pMoveData);
        }
        ExtraEditorRefMoveData* pSource = (ExtraEditorRefMoveData*)apExtra;
        pMoveData->kOldLocation = pSource->kOldLocation;
        pMoveData->kRealLocation = pSource->kRealLocation;
        pMoveData->kRealAngle = pSource->kRealAngle;
        break;
    }
    case 0x0E:
        GetLocalData(((ExtraAction*)apExtra)->cFlags);
        break;
    case 0x21:
        SetOwnership(((ExtraOwnership*)apExtra)->pOwner);
        break;
    case 0x22:
        SetGlobalForm(((ExtraGlobal*)apExtra)->pGlobalForm);
        break;
    case 0x23:
        SetRank(((ExtraRank*)apExtra)->m_iRank);
        break;
    case 0x24:
        SetCount(((ExtraCount*)apExtra)->m_sCount);
        break;
    case 0x6E: {
        ExtraAmmo* pAmmo = (ExtraAmmo*)apExtra;
        SetAmmoExtra(pAmmo->pAmmo, pAmmo->iCount);
        break;
    }
    case 0x16:
        SetEquippedState(true, false);
        break;
    case 0x4A:
        SetHotKey(((ExtraHotkey*)apExtra)->cKey);
        break;
    case 0x17:
        SetEquippedState(true, true);
        break;
    case 0x31:
        SetSeedIndex(((ExtraSeed*)apExtra)->cSeed);
        break;
    case 0x2F:
        SetLeveledItem(((ExtraLeveledItem*)apExtra)->iLevelItem);
        SetLevelItemExtraFlag(((ExtraLeveledItem*)apExtra)->bFlag);
        break;
    case 0x25:
        SetHealth((((ExtraHealth*)apExtra)->fHealthPercent));
        break;
    case 0x7A:
        SetHealthPerc((((ExtraHealthPerc*)apExtra)->m_fHealthPercentage));
        break;
    case 0x26:
        SetUses(((ExtraUses*)apExtra)->m_ucUses);
        break;
    case 0x27:
        SetTimeLeft((((ExtraTimeLeft*)apExtra)->fTimeLeft));
        break;
    case 0x28:
        SetCharge((((ExtraCharge*)apExtra)->m_fCharge));
        break;
    case 0x0D:
        SetScript(((ExtraScript*)apExtra)->pScript);
        AssignScriptLocals(((ExtraScript*)apExtra)->pLocals);
        break;
    case 0x30:
        SetScale(((ExtraScale*)apExtra)->fScale);
        break;
    case 0x2A: {
        LockExtraData* pLock = new LockExtraData;
        memcpy(pLock, ((ExtraLock*)apExtra)->pLock, sizeof(LockExtraData));
        SetLockData(pLock);
        break;
    }
    case 0x68:
        SetRadioData(&((ExtraRadioData*)apExtra)->kRadioData);
        break;
    case 0x2B: {
        TeleportableReference* pTeleport = new TeleportableReference;
        pTeleport->Copy(((ExtraTeleport*)apExtra)->pData);
        SetTeleportData(pTeleport);
        break;
    }
    case 0x2C: {
        MapMarkerData* pTeleportMarker = new MapMarkerData;
        pTeleportMarker->Copy(((ExtraMapMarker*)apExtra)->pData);
        SetMapMarkerPtr(pTeleportMarker);
        break;
    }
    case 0x90: {
        MediaLocation* pAudio = new MediaLocation;
        pAudio->Copy(((ExtraAudioMarker*)apExtra)->pData);
        SetAudioMarkerPtr(pAudio);
        break;
    }
    case 0x91: {
        TwoIntegerValues* pBuoy = new TwoIntegerValues;
        pBuoy->Copy(((ExtraAudioBuoyMarker*)apExtra)->pData);
        SetAudioBuoyMarkerPtr(pBuoy);
        break;
    }
    case 0x18: {
        TESWorldSpace* pWorld = dynamic_cast<TESWorldSpace*>(((ExtraPackageStartLocation*)apExtra)->pLocation);
        TESObjectCELL* m_pOwningCell = dynamic_cast<TESObjectCELL*>(((ExtraPackageStartLocation*)apExtra)->pLocation);
        RelocateTo(pWorld, m_pOwningCell, &((ExtraPackageStartLocation*)apExtra)->kPos,
                   ((ExtraPackageStartLocation*)apExtra)->fAngleDifference);
        break;
    }
    case 0x14:
        SetRagDollDataFromCopy(((ExtraRagDollData*)apExtra)->pData);
        break;
    case 0x13:
        SetWeaponModFlags(&((ExtraDistantData*)apExtra)->kDistantData);
        break;
    case 0x1D: {
        BSSimpleList<Actor*>* pFollowerIter = ((ExtraFollower*)apExtra)->pFollowers;
        while (pFollowerIter && pFollowerIter->GetItem())
        {
            Actor* pFollower = pFollowerIter->GetItem();
            SetCombatOpponent(pFollower);
            pFollowerIter = pFollowerIter->GetNext();
        }
        break;
    }
    case 0x46:
        SetHeadTrackTargetExtra(((ExtraHeadTrackTarget*)apExtra)->pTarget);
        break;
    case 0x3F:
        SetPoison(((ExtraPoison*)apExtra)->m_pPoisonItem);
        break;
    case 0x02:
        SetCell3D(((ExtraCell3D*)apExtra)->m_pController);
        break;
    case 0x03:
        SetWaterType(((ExtraWaterType*)apExtra)->m_pWaterForm);
        break;
    case 0x07:
        SetMusicType(((ExtraMusicType*)apExtra)->pMusic);
        break;
    case 0x81:
        SetAcousticSpace(((ExtraAcousticSpace*)apExtra)->m_pPathingCell);
        break;
    case 0x0A: {
        CanopyShadowMaskData* pMaskData;
        SetCanopyShadowMaskData(((ExtraCanopyShadowMask*)apExtra)->iMask, ((ExtraCanopyShadowMask*)apExtra)->spTexture,
                                &pMaskData);
        pMaskData->unk04 = ((ExtraCanopyShadowMask*)apExtra)->unk18;
        pMaskData->unk00 = ((ExtraCanopyShadowMask*)apExtra)->unk14;
        break;
    }
    case 0x08:
        SetClimate(((ExtraClimate*)apExtra)->pClimateData);
        break;
    case 0x59:
        SetImageSpace(((ExtraImageSpace*)apExtra)->m_pImageSpace);
        break;
    case 0x8C: {
        ImpactSwap* pSwap = new ImpactSwap;
        pSwap->Copy(((ExtraImpactSwap*)apExtra)->pSwap);
        SetImpactSwapData(pSwap);
        break;
    }
    case 0x1C:
        SetActivateRef(((ExtraReferencePointer*)apExtra)->pRef);
        break;
    case 0x19:
        SetPackageOverride(((ExtraPackage*)apExtra)->pPackage, ((ExtraPackage*)apExtra)->iPackageFlags,
                           ((ExtraPackage*)apExtra)->m_iPackageData, ((ExtraPackage*)apExtra)->cA,
                           ((ExtraPackage*)apExtra)->m_ucPackageByte, ((ExtraPackage*)apExtra)->cC);
        break;
    case 0x1A:
        SetActivePackage(((ExtraTresPassPackage*)apExtra)->pPackage);
        break;
    case 0x1B:
        pIter = ((ExtraRunOncePacks*)apExtra)->pPackages;
        while (pIter)
        {
            PackageReference* pRunOnce = pIter->GetItem();
            if (pRunOnce)
            {
                TESPackage* pPackage = pRunOnce->pPackage;
                unsigned char bPickResultFound = pRunOnce->bPickResultFound;
                SetPackageDoneState(pPackage, bPickResultFound);
            }
            pIter = pIter->GetNext();
        }
        break;
    case 0x20:
        SetEnableStateChildren(((ExtraOriginalReference*)apExtra)->pRef);
        break;
    case 0x37:
        SetEnableStateParentRef(((ExtraEnableStateParent*)apExtra)->pParent);
        SetEnableStateParentFlags(((ExtraEnableStateParent*)apExtra)->cFlags);
        break;
    case 0x3B:
        SetRandomTeleportMarker(((ExtraRandomTeleportMarker*)apExtra)->pTeleportMarker);
        break;
    case 0x51:
        SetLinkedRef(((ExtraLinkedRef*)apExtra)->m_pLinkedReference);
        break;
    case 0x53: {
        ExtraActivateRef* m_pFourthReference = (ExtraActivateRef*)GetExtraData(0x53);
        if (!m_pFourthReference)
        {
            m_pFourthReference = new ExtraActivateRef;
            AddExtra(m_pFourthReference);
        }
        m_pFourthReference->Copy(apExtra);
        break;
    }
    case 0x57: {
        ExtraDecalRefs* pDecalRefs = (ExtraDecalRefs*)GetExtraData(0x57);
        if (!pDecalRefs)
        {
            pDecalRefs = new ExtraDecalRefs;
            AddExtra(pDecalRefs);
        }
        pDecalRefs->Copy(apExtra);
        break;
    }
    case 0x65: {
        ExtraReflectedRefs* pReflectedRefs = (ExtraReflectedRefs*)GetExtraData(0x65);
        if (!pReflectedRefs)
        {
            pReflectedRefs = new ExtraReflectedRefs;
            AddExtra(pReflectedRefs);
        }
        pReflectedRefs->Copy(apExtra);
        break;
    }
    case 0x66: {
        ExtraReflectorRefs* pReflectorRefs = (ExtraReflectorRefs*)GetExtraData(0x66);
        if (!pReflectorRefs)
        {
            pReflectorRefs = new ExtraReflectorRefs;
            AddExtra(pReflectorRefs);
        }
        pReflectorRefs->Copy(apExtra);
        break;
    }
    case 0x85: {
        ExtraLitWaterRefs* pLitWaterRefs = (ExtraLitWaterRefs*)GetExtraData(0x85);
        if (!pLitWaterRefs)
        {
            pLitWaterRefs = new ExtraLitWaterRefs;
            AddExtra(pLitWaterRefs);
        }
        pLitWaterRefs->Copy(apExtra);
        break;
    }
    case 0x84: {
        ExtraWaterLightRefs* pWaterLightRefs = (ExtraWaterLightRefs*)GetExtraData(0x84);
        if (!pWaterLightRefs)
        {
            pWaterLightRefs = new ExtraWaterLightRefs;
            AddExtra(pWaterLightRefs);
        }
        pWaterLightRefs->Copy(apExtra);
        break;
    }
    case 0x3C:
        SetMerchantContainer(((ExtraMerchantContainer*)apExtra)->pContainer);
        break;
    case 0x44:
        SetXTarget(((ExtraXTarget*)apExtra)->pTarget);
        break;
    case 0x74:
        SetEncounterZone(((ExtraEncounterZone*)apExtra)->m_pEncounterZone);
        break;
    case 0x67:
        SetEmittanceSource(((ExtraEmittanceSource*)apExtra)->pSource);
        break;
    case 0x63:
        SetMultiBoundRef(((ExtraMultiBoundRef*)apExtra)->pRef);
        break;
    case 0x62: {
        Point3Offset* pNewData = 0;
        Point3Offset* pSrcData = ((ExtraMultiBoundMarkerData*)apExtra)->pData;
        if (pSrcData)
        {
            pNewData = new Point3Offset;
            pNewData->Copy(pSrcData);
        }
        SetExtraRecord(pNewData);
        break;
    }
    case 0x1E:
        SetLevCreaModifier(((ExtraLevCreaModifier*)apExtra)->iModifier);
        break;
    case 0x48:
        SetRefractionAmount(true, ((ExtraRefractionProperty*)apExtra)->fRefraction);
        break;
    case 0x3E:
        SetCannotWear(true);
        break;
    case 0x55:
        break;
    case 0x5C:
        SetRadius(((ExtraRadius*)apExtra)->fRadius);
        break;
    case 0x5D:
        SetRadiation(((ExtraRadiation*)apExtra)->m_fRadiation);
        break;
    case 0x5E: {
        UpdateExtraDataListExtension();
        ExtraFactionChanges* pChanges = GetFactionChangesExtra();
        BSSimpleList<FactionRankData*>* pRankIter = ((ExtraFactionChangesData*)apExtra)->pFactions;
        while (pRankIter && pRankIter->GetItem())
        {
            FactionRankData* pRank = pRankIter->GetItem();
            if (pRank)
                pChanges->AddToFaction(pRank->pFaction, pRank->m_ucRank);
            pRankIter = pRankIter->GetNext();
        }
        break;
    }
    case 0x5A:
        SetPortalRefData(apExtra);
        break;
    case 0x6B: {
        BGSPrimitive* pSrcPrimitive = ((ExtraPrimitive*)apExtra)->m_pPrimitive;
        BGSPrimitive* pNewPrimitive = BGSPrimitive::Copy(pSrcPrimitive);
        AddPrimitive(pNewPrimitive);
        break;
    }
    case 0x61:
        SetMultiBound(((ExtraMultiBound*)apExtra)->m_kMultiBoundNode);
        break;
    case 0x79:
        SetRoomNode(((ExtraRoom*)apExtra)->m_pRoomNode);
        break;
    case 0x6F: {
        PatrolRefData* pPatrol = new PatrolRefData;
        pPatrol->Copy(((ExtraPatrolRefData*)apExtra)->pData);
        SetPatrolRefData(pPatrol);
        break;
    }
    case 0x71:
        SetOcclusionShape(((ExtraOcclusionShape*)apExtra)->pShape);
        break;
    case 0x76: {
        PatrolReferenceData* pPlaneData = new PatrolReferenceData;
        ExtraOcclusionPlaneRefData* pOcclusionExtra = (ExtraOcclusionPlaneRefData*)apExtra;
        PatrolReferenceData* pSrcLinkedRefs = pOcclusionExtra->pData;
        for (int i = 0; i < 4; i++)
            pPlaneData->m_pPatrolReferences[i] = pSrcLinkedRefs->m_pPatrolReferences[i];
        SetRoomRefData(pPlaneData);
        break;
    }
    case 0x77: {
        ExtraPortalRefData* pPortalRefExtra = (ExtraPortalRefData*)apExtra;
        PortalRefData* pPortalRefData = pPortalRefExtra->pData;
        for (int j = 0; j < 2; j++)
            SetRoomLinkedRoomRef(j, pPortalRefData->pRooms[j]);
        break;
    }
    case 0x7B: {
        ExtraRoomRefData* pRefExtra = (ExtraRoomRefData*)apExtra;
        RoomRefData* pRoomRefData = pRefExtra->pData;
        BSSimpleList<TESObjectREFR*>* pRoomLinkIter = &pRoomRefData->kLinkedRooms;
        while (pRoomLinkIter && pRoomLinkIter->GetItem())
        {
            AddRoomLinkedRoomRef(pRoomLinkIter->GetItem());
            pRoomLinkIter = pRoomLinkIter->GetNext();
        }
        SetRoomIsMaster(pRoomRefData->bIsMaster != 0);
        break;
    }
    case 0x72: {
        CollisionData* pCollision = new CollisionData;
        pCollision->SetCollisionLayer(((ExtraCollisionData*)apExtra)->pData->GetCollisionLayer());
        SetCollisionData(pCollision);
        break;
    }
    case 0x73: {
        BSSimpleList<TESTopicInfo*>* pInfoIter = ((ExtraSayTopicInfoOnceADay*)apExtra)->m_pTopicInfoList;
        while (pInfoIter && pInfoIter->GetItem())
        {
            SetExtraSayTopicInfoOnceADayExtra(pInfoIter->GetItem());
            pInfoIter->GetNext();
        }
        break;
    }
    case 0x78: {
        BSPortalNode* pPortalNode = apExtra ? ((ExtraPortal*)apExtra)->m_pPortalNode : NiPointer<BSPortalNode>(0);
        SetPortalNode(pPortalNode);
        break;
    }
    case 0x80:
        SetIgnoredBySandbox(true);
        break;
    case 0x8B: {
        ExtraFollowerSwimBreadcrumbs* pDstBreadcrumbs = GetFollowerSwimBreadcrumbsExtra();
        ExtraFollowerSwimBreadcrumbs* pSrcBreadcrumbs = (ExtraFollowerSwimBreadcrumbs*)apExtra;
        pDstBreadcrumbs->kLastPos = pSrcBreadcrumbs->kLastPos;
        pDstBreadcrumbs->iLastCell = pSrcBreadcrumbs->iLastCell;
        pDstBreadcrumbs->iCount = pSrcBreadcrumbs->iCount;
        pDstBreadcrumbs->kBreadcrumbs.RemoveAll();
        for (BSSimpleList<FollowerSwimBreadcrumb*>* pCrumbIter = &pSrcBreadcrumbs->kBreadcrumbs; pCrumbIter;
             pCrumbIter = pCrumbIter->GetNext())
        {
            if (pCrumbIter->GetItem())
                pDstBreadcrumbs->kBreadcrumbs.AddTail(pCrumbIter->GetItem());
        }
        break;
    }
    case 0x8D:
        if (((ExtraWeaponModFlags*)apExtra)->IsModActive(1))
            RemoveExtraByType(1);
        if (((ExtraWeaponModFlags*)apExtra)->IsModActive(2))
            RemoveExtraByType(2);
        if (((ExtraWeaponModFlags*)apExtra)->IsModActive(4))
            RemoveExtraByType(4);
        break;
    case 0x92: {
        ExtraSpecialRenderFlags* pRenderFlags = (ExtraSpecialRenderFlags*)GetExtraData(0x92);
        if (!pRenderFlags)
        {
            pRenderFlags = new ExtraSpecialRenderFlags;
            AddExtra((BSExtraData*)pRenderFlags);
        }
        pRenderFlags->CopyFrom(apExtra);
        break;
    }
    default:
        Warning("AI: No Copy function available for Extra Data type %i.", apExtra->GetType());
        break;
    }
}

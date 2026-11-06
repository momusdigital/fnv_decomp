// fallout_shared/bgsprojectile.cpp: BGSProjectile, BGSProjectileFloatNode, ProjShell, ProjectileSave (22 functions)

#include "bgsprojectile_decls.h"

// @fnv 0x004fd090
void BGSProjectile::ClearData()
{
    m_kProjectileModel.Free();
}

// @fnv 0x004fd050
void BGSProjectile::ResetFormData()
{
    reinterpret_cast<ProjectileProperties*>(reinterpret_cast<TESDataHandler*>(this)->GetTESRaceList())
        ->InitializeDefaults();
    reinterpret_cast<TESModelVTable*>(&m_kProjectileModel)->Slot0();
    m_eSoundLevel = 1;
}

// If newValue is nonzero, sets value, or copies this node into a new node inserted after it and sets value.
// @fnv 0x004ff980
void BGSProjectileFloatNode::AddHead(const float& newValue)
{
    if (newValue == 0.0)
        return;
    {
        if (value != 0.0)
        {
            BGSProjectileFloatNode* inserted = new BGSProjectileFloatNode(*this);
            inserted->next = next;
            next = inserted;
            value = newValue;
        }
        else
        {
            value = newValue;
        }
    }
}
// @fnv 0x004fce60
BGSProjectile::BGSProjectile()
{
    SetFormType(ENUM_FORM_ID_PROJ_ID);
    ResetFormData();
}
// @fnv 0x004fd0c0
void BGSProjectile::InitItem()
{
    if (GetInitialized())
        return;
    BGSDestructibleObjectForm::InitItem(this);
    unsigned int formID;
    formID = (unsigned int)reinterpret_cast<EffectSetting*>(this)->GetLight();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetLight(
            dynamic_cast<TESObjectLIGH*>(TESForm::GetFormByID(formID)));
    }
    formID = (unsigned int)reinterpret_cast<TESChallenge*>(this)->GetFormOne();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<TESObjectACTI*>(this)->SetLoopingSound(
            reinterpret_cast<TESSound*>(dynamic_cast<TESObjectLIGH*>(TESForm::GetFormByID(formID))));
    }
    formID = (unsigned int)reinterpret_cast<EffectSetting*>(this)->GetBoltSound();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetBoltSound(
            reinterpret_cast<TESSound*>(dynamic_cast<BGSExplosion*>(TESForm::GetFormByID(formID))));
    }
    formID = (unsigned int)reinterpret_cast<EffectSetting*>(this)->GetHitSound();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetHitSound(
            dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
    }
    formID = (unsigned int)reinterpret_cast<EffectSetting*>(this)->GetArchetype();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetEffectID(
            (int)dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
    }
    formID = (unsigned int)reinterpret_cast<InterfaceManager*>(this)->FUN_00586150();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<EffectSetting*>(this)->SetAssociatedActorValue(
            (int)dynamic_cast<TESSound*>(TESForm::GetFormByID(formID)));
    }
    formID = (unsigned int)reinterpret_cast<InterfaceManager*>(this)->FUN_004fd400();
    if (formID)
    {
        TESForm::RemapFormIDForFile(formID, GetFile(-1));
        reinterpret_cast<InterfaceManager*>(this)->FUN_00500a20(
            reinterpret_cast<Tile*>(dynamic_cast<TESObjectWEAP*>(TESForm::GetFormByID(formID))));
    }
    if (!GetHasExplosion())
        reinterpret_cast<EffectSetting*>(this)->SetBoltSound(0);
    SetInitializationState(true);
}
// @fnv 0x004fd6f0
bool BGSProjectile::Load(TESFile* file)
{
    unsigned char formType = file->GetTESForm();
    if (formType != 0x33)
        return false;

    reinterpret_cast<BGSProjectileVTable*>(this)->Slot6();
    reinterpret_cast<TESForm*>(this)->LoadRecordHeader(file);
    reinterpret_cast<TESForm*>(this)->SetInitializationState(false);

    int chunkID;
    while ((chunkID = file->GetChunkID()) != 0)
    {

        switch (chunkID)
        {
        case 0x44494445: {
            char* buffer = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(buffer, 0x200);
            reinterpret_cast<BGSProjectileVTable*>(this)->SetEditorID(buffer);
            break;
        }
        case 0x444E424F:
            reinterpret_cast<BGSProjectileVTable*>(this)->LoadBoundChunk(file);
            break;
        case 0x4C4C5546:
            TESFullNameLoader::LoadFullNameChunk(static_cast<TESFullName*>(this), file);
            break;
        case 0x4C444F4D:
        case 0x54444F4D: {
            TESModel::LoadModelData(static_cast<TESModel*>(this), file);
            break;
        }
        case 0x44545344:
        case 0x54534544: {
            BGSDestructibleObjectForm::LoadDestructibleData(static_cast<BGSDestructibleObjectForm*>(this), file);
            break;
        }
        case 0x41544144:
            reinterpret_cast<BGSImpactData*>(this)->ReadTypedData(file, &Data, 0x54);
            break;
        case 0x314D414E: {
            if (file->GetChunkSize())
            {
                char* buffer = (char*)_alloca(file->GetChunkSize());
                file->GetChunkData(buffer, 0);
                reinterpret_cast<TESModelVTable*>(&m_kProjectileModel)->LoadRawChunk(buffer);
            }
            break;
        }
        case 0x324D414E:
            if (file->GetChunkSize())
                TESModel::LoadTextureSwapData(&m_kProjectileModel, file);
            break;
        case 0x4D414E56: {
            unsigned int soundLevel;
            file->GetChunkData(&soundLevel);
            if (soundLevel > 3)
                m_eSoundLevel = 1;
            else
                m_eSoundLevel = soundLevel;
            break;
        }
        }

        if (chunkID == 0x41544144 && file->IsEndianConversionRequired())
            Data.Endian();
        if (!file->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x004fcc00
ProjectileProperties* __fastcall FUN_004fcc00(ProjectileProperties* pThis)
{
    pThis->InitializeDefaults();
    return pThis;
}

struct FUN_004fcc20_shell : public ProjectileProperties
{
    void InitializeDefaults();
};

extern float DAT_01022958;

// @fnv 0x004fcc20
void FUN_004fcc20_shell::InitializeDefaults()
{
    *(int*)((char*)this + 0x00) = 0x10000;
    *(float*)((char*)this + 0x04) = 0.0f;
    *(float*)((char*)this + 0x08) = 1000.0f;
    *(float*)((char*)this + 0x0c) = DAT_01022958;
    *(float*)((char*)this + 0x18) = 0.0f;
    *(float*)((char*)this + 0x1c) = 0.0f;
    *(float*)((char*)this + 0x20) = 0.0f;
    *(int*)((char*)this + 0x10) = 0;
    *(int*)((char*)this + 0x14) = 0;
    *(int*)((char*)this + 0x24) = 0;
    *(int*)((char*)this + 0x28) = 0;
    *(float*)((char*)this + 0x2c) = 0.0f;
    *(float*)((char*)this + 0x30) = 0.5f;
    *(float*)((char*)this + 0x34) = 0.0f;
    *(int*)((char*)this + 0x38) = 0;
    *(int*)((char*)this + 0x3c) = 0;
    *(int*)((char*)this + 0x40) = 0;
    *(float*)((char*)this + 0x44) = 0.0f;
    *(float*)((char*)this + 0x48) = 0.0f;
    *(float*)((char*)this + 0x4c) = 0.0f;
    *(float*)((char*)this + 0x50) = 1.0f;
}

struct BGSProjectile_GetFlag_Helper : public BGSProjectile
{
    bool GetFlag(unsigned int) const;
};

// @fnv 0x004fd360
bool BGSProjectile::GetHasExplosion()
{
    return ((const BGSProjectile_GetFlag_Helper*)this)->GetFlag(2);
}

struct FUN_004fd420_shell : public BGSProjectile
{
    bool FUN_004fd420(int);
};

// @fnv 0x004fd420
bool FUN_004fd420_shell::FUN_004fd420(int aeFlag)
{
    return (*(int*)((TESDataHandler*)this)->GetTESRaceList() & aeFlag) ? true : false;
}

struct FUN_00821640_shell : public TESObjectWEAP
{
    float FUN_00821640();
};

// @fnv 0x00821640
float FUN_00821640_shell::FUN_00821640()
{
    return *(float*)((char*)this + 0x134);
}

void _Deallocate(void*);
struct FUN_004fcf50_shell
{
    void FUN_004fcf80();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_004fcf80, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x004fcf50
void* FUN_004fcf50_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_004fcf80();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_004fe080 {
struct FUN_004fd4f0_Class
{
    int FUN_004fd4f0();
};
struct TESCreature
{
    float FUN_00821640();
};
int __cdecl MinInt(int, int);
struct TESObjectWEAP_Ext : TESObjectWEAP
{
    int GetClipRounds(bool);
    unsigned char GetDamageForActor(bool, bool, Actor*);
};
struct BGSProjectile_GetFlag_Helper
{
    bool GetFlag(unsigned int) const;
};
struct FUN_004fe080_shell : BGSProjectile
{
    int GetProjectileCloneCount(TESObjectWEAP* apSourceWeapon);
};

// @fnv 0x004fe080
int FUN_004fe080_shell::GetProjectileCloneCount(TESObjectWEAP* apSourceWeapon)
{
    int icloneCount = 5;
    if (((FUN_004fd4f0_Class*)this)->FUN_004fd4f0() == 0x40000 ||
        ((FUN_004fd4f0_Class*)this)->FUN_004fd4f0() == 0x100000 ||
        ((FUN_004fd4f0_Class*)this)->FUN_004fd4f0() == 0x80000)
    {
        icloneCount = 0;
    }
    else if (apSourceWeapon)
    {
        int iprojectiles = (int)((TESCreature*)apSourceWeapon)->FUN_00821640() *
                           ((TESObjectWEAP_Ext*)apSourceWeapon)->GetDamageForActor(false, false, 0);
        int iprojectilesPerSecond7 = iprojectiles * 3;
        if (((FUN_004fd4f0_Class*)this)->FUN_004fd4f0() != 0x20000)
            iprojectilesPerSecond7 =
                MinInt(iprojectilesPerSecond7, ((TESObjectWEAP_Ext*)apSourceWeapon)->GetClipRounds(false));
        if (((BGSProjectile_GetFlag_Helper*)this)->GetFlag(0x100))
            iprojectilesPerSecond7 *= 4;
        icloneCount = iprojectilesPerSecond7;
    }
    return icloneCount;
}
}  // namespace fnv_004fe080

template <int N> struct EndianSizeTag
{
    unsigned char value;
};

void BSEndian(unsigned char*, EndianSizeTag<0>);

struct FUN_004fccf0_shell
{
    void SwapEndianFields();
};

// @fnv 0x004fccf0
void FUN_004fccf0_shell::SwapEndianFields()
{
    BSEndian(reinterpret_cast<unsigned char*>(this), EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 4, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 8, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 12, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 24, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 28, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 32, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 44, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 48, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 52, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 68, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 72, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 76, EndianSizeTag<0>());
    BSEndian(reinterpret_cast<unsigned char*>(this) + 80, EndianSizeTag<0>());
}

void* __memcpy(void*, const void*, unsigned int);

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};

struct FUN_004fdcf0_subobject
{
    virtual void FUN_004fdcf0_dummy1();
    virtual void FUN_004fdcf0_dummy2();
    virtual void FUN_004fdcf0_copy(FUN_004fdcf0_subobject*);
};

struct FUN_004fdcf0_shell : BGSProjectile
{
    void CopyFromProjectile(TESForm*);
};

// @fnv 0x004fdcf0
void FUN_004fdcf0_shell::CopyFromProjectile(TESForm* apCopy)
{
    BGSProjectile* pcopy;

    pcopy = dynamic_cast<BGSProjectile*>(apCopy);
    if (!pcopy)
        return;

    ((FUN_005e78f0_t*)this)->FUN_004851b0(pcopy);

    ((FUN_004fdcf0_subobject*)((char*)this + 0xB4))->FUN_004fdcf0_copy((FUN_004fdcf0_subobject*)((char*)pcopy + 0xB4));

    *(unsigned int*)((char*)this + 0xCC) = *(unsigned int*)((char*)pcopy + 0xCC);

    __memcpy(((TESDataHandler*)this)->GetTESRaceList(), ((TESDataHandler*)pcopy)->GetTESRaceList(), 0x54);
}

struct FUN_005e79a0_t
{
  public:
    bool FUN_00485270(TESForm* pForm);
};

struct BSFadeNode
{
  public:
    unsigned int FUN_009ad610();
};

struct FUN_004fdd80_field
{
  public:
    virtual void FUN_004fdd80_v1();
    virtual void FUN_004fdd80_v2();
    virtual void FUN_004fdd80_v3();
    virtual bool FUN_004fdd80_v4(void* pObject);
};

int _memcmp(const void* pLeft, const void* pRight, unsigned int nCount);

struct FUN_004fdd80_shell : public BGSProjectile
{
  public:
    bool IsNotEqual(TESForm* apCompare);
};

// Compares this projectile against apCompare: returns true if the cast fails or any of several fields differ, false if all match.
// @fnv 0x004fdd80
bool FUN_004fdd80_shell::IsNotEqual(TESForm* apCompare)
{
    BGSProjectile* pcomp = dynamic_cast<BGSProjectile*>(apCompare);

    if (!pcomp)
        return true;

    if (reinterpret_cast<FUN_005e79a0_t*>(this)->FUN_00485270(pcomp))
        return true;

    if (_memcmp(reinterpret_cast<const void*>(reinterpret_cast<char*>(this) + 0x60),
                reinterpret_cast<TESDataHandler*>(pcomp)->GetTESRaceList(), 0x54) != 0)
        return true;

    if (reinterpret_cast<FUN_004fdd80_field*>(reinterpret_cast<char*>(this) + 0xb4)
            ->FUN_004fdd80_v4(reinterpret_cast<char*>(pcomp) + 0xb4))
        return true;

    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0xcc) !=
        reinterpret_cast<BSFadeNode*>(pcomp)->FUN_009ad610())
        return true;

    return false;
}

struct FUN_004fcf80_Primary
{
    virtual ~FUN_004fcf80_Primary();
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
};

struct FUN_004fcf80_Base30
{
    virtual ~FUN_004fcf80_Base30();
    int unk04;
    int unk08;
};

struct FUN_004fcf80_Base3c
{
    virtual ~FUN_004fcf80_Base3c();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct FUN_004fcf80_Base54
{
    virtual void unk00();
};

struct FUN_004fcf80_Base58
{
    virtual ~FUN_004fcf80_Base58();
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
};

struct FUN_004fcf80_Member
{
    ~FUN_004fcf80_Member();
    int unk00;
};

struct FUN_004fcf80 : FUN_004fcf80_Primary,
                      FUN_004fcf80_Base30,
                      FUN_004fcf80_Base3c,
                      FUN_004fcf80_Base54,
                      FUN_004fcf80_Base58
{
    FUN_004fcf80_Member m_b4;
    void Shutdown();
    virtual ~FUN_004fcf80();
};

// @fnv 0x004fcf80
FUN_004fcf80::~FUN_004fcf80()
{
    Shutdown();
}

struct CloningProcess
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    float fScale;
    CloningProcess(float afScale);
    ~CloningProcess();
};

struct ProjNiObject
{
    void* Clone(CloningProcess* apCloning);
};

struct ProjFlagHolder
{
    void SetFlag(bool abVal);
};

struct ProjResult
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual ProjFlagHolder* v10();
};

struct ProjBase;

struct ProjRef
{
    struct ProjBaseHolder* GetBase();
    unsigned int GetID();
};

struct ProjBase
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
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual ProjNiObject* Get3D(ProjRef* apRef);
};

struct ProjBaseHolder
{
    ProjBase* GetBaseObj();
};

struct ProjDataHandler
{
    bool IsValid(unsigned int aID);
};
extern ProjDataHandler* g_dataHandler;

struct ProjSaveLoad
{
    bool IsLoading();
};
extern ProjSaveLoad* g_BGSSaveLoadGame;

struct ProjCache
{
    ProjResult* Make(ProjNiObject* apObj);
};
ProjCache* GetProjCache(bool abCreate);

struct ProjShell : ProjBase
{
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    unsigned int uiFlags;
    unsigned int GetType();
    ProjResult* Create(ProjRef* apRef, bool abVal);
    void Release(ProjRef* apRef);
    ProjResult* CreateOrClone(ProjRef* apRef, bool abVal);
};

// Creates or clones a ProjResult for apRef depending on the object type and reference state, then sets a flag on the result if present.
// @fnv 0x004fd510
ProjResult* ProjShell::CreateOrClone(ProjRef* apRef, bool abVal)
{
    ProjResult* pResult4 = 0;
    if (apRef)
    {
        switch (GetType())
        {
        case 0x40000:
        case 0x100000:
            pResult4 = Create(apRef, true);
            break;
        default: {
            ProjRef* pRef8 = apRef;
            if (pRef8 && pRef8->GetBase() && pRef8->GetBase()->GetBaseObj())
            {
                ProjNiObject* pNodeVal = pRef8->GetBase()->GetBaseObj()->Get3D(0);
                CloningProcess kCloningA(1.0f);
                if (pNodeVal)
                    pResult4 = (ProjResult*)pNodeVal->Clone(&kCloningA);
            }
            else
            {
                ProjNiObject* p3D = Get3D(apRef);
                if (p3D && g_dataHandler->IsValid(apRef->GetID()) && !g_BGSSaveLoadGame->IsLoading())
                {
                    pResult4 = GetProjCache(true)->Make(p3D);
                }
                if (!pResult4)
                {
                    pResult4 = Create(apRef, abVal);
                    if (p3D)
                        Release(apRef);
                }
            }
        }
        }
    }
    if (pResult4 && pResult4->v10())
        pResult4->v10()->SetFlag(true);
    return pResult4;
}

struct S_004fdfb0_Model : TESModel
{
    int FUN_0048cee0();
};
struct S_004fdfb0_Sub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int a, int b);
};
struct S_004fdfb0_Obj
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
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    S_004fdfb0_Sub sub64;
};
struct S_004fdfb0_Mgr
{
    void FUN_00443d30(TESModel* model, int a, int b, int c, int d, int e, int f);
};
extern S_004fdfb0_Mgr* DAT_011c3b3c;
struct S_004fdfb0_Preload
{
    virtual void PreloadModels(int a, int b);
};
struct S_004fdfb0_Proj : TESBoundObject, TESFullName, S_004fdfb0_Model, S_004fdfb0_Preload, BGSDestructibleObjectForm
{
    ProjectileProperties Data;
    S_004fdfb0_Model m_kProjectileModel;
    int m_eSoundLevel;
    virtual void PreloadModels(int a, int b);
    S_004fdfb0_Obj* FUN_004fd3c0();
};
int __cdecl FUN_0045c6b0(S_004fdfb0_Proj* proj);

// @fnv 0x004fdfb0
void S_004fdfb0_Proj::PreloadModels(int a, int b)
{
    if (FUN_0048cee0())
    {
        DAT_011c3b3c->FUN_00443d30(this, a, b, FUN_0045c6b0(this), 1, 0, 0);
    }
    if (m_kProjectileModel.FUN_0048cee0())
    {
        DAT_011c3b3c->FUN_00443d30(&m_kProjectileModel, a, b, 3, 1, 0, 0);
    }
    if (FUN_004fd3c0())
    {
        FUN_004fd3c0()->sub64.v4(a, b);
    }
}

struct FUN_004fe160_sub
{
    int FUN_00401170();
};

struct FUN_004fe160_cls
{
    float GetEffectValue(int, int);
    int GetFlaggedValue(unsigned char flag);
};

// Returns the value from the sub-object at offset 0xac, adding the result of GetEffectValue(2, 0) when flag is set.
// @fnv 0x004fe160
int FUN_004fe160_cls::GetFlaggedValue(unsigned char abAddExtra)
{
    if (abAddExtra)
    {
        return (unsigned char)GetEffectValue(2, 0) +
               reinterpret_cast<FUN_004fe160_sub*>(reinterpret_cast<char*>(this) + 0xac)->FUN_00401170();
    }
    else
    {
        return reinterpret_cast<FUN_004fe160_sub*>(reinterpret_cast<char*>(this) + 0xac)->FUN_00401170();
    }
}

struct FUN_004fe1d0_cls
{
    int GetKind();
    int GetKindCode();
};

// Maps the value returned by GetKind() to a code (0x3d-0x40, 0x69), returning 0 for any other kind.
// @fnv 0x004fe1d0
int FUN_004fe1d0_cls::GetKindCode()
{
    switch (GetKind())
    {
    case 0x10000:
        return 0x3d;
    case 0x20000:
        return 0x3e;
    case 0x40000:
        return 0x3f;
    case 0x80000:
        return 0x40;
    case 0x100000:
        return 0x69;
    default:
        return 0;
    }
}

struct SaveRef
{
    SaveRef* Resolve();
};
struct SaveComponent
{
    void Name();
    void Model(unsigned int, unsigned int);
    void Destructible();
    void Endian();
    int Length();
};
struct SaveModel
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* Text();
};
bool IsEndian();
void WriteChunk(unsigned int, void*, unsigned int);
void WriteValue(unsigned int, int);
struct ProjectileSave
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
    int field64;
    int field68;
    int field6c;
    SaveRef* field70;
    SaveRef* field74;
    int field78;
    int field7c;
    int field80;
    SaveRef* field84;
    SaveRef* field88;
    int field8c;
    int field90;
    int field94;
    SaveRef* field98;
    SaveRef* field9c;
    SaveRef* fielda0;
    int fielda4;
    int fielda8;
    int fieldac;
    int fieldb0;
    int fieldb4;
    int fieldb8;
    int fieldbc;
    int fieldc0;
    int fieldc4;
    int fieldc8;
    int fieldcc;
    void Begin();
    void WriteData(void*, int);
    void Finish();
    void WriteProjectileSave();
};
// @fnv 0x004fda00
void ProjectileSave::WriteProjectileSave()
{
    Begin();
    ((SaveComponent*)&field30)->Name();
    ((SaveComponent*)&field3c)->Model(0x4c444f4d, 0x54444f4d);
    ((SaveComponent*)&field58)->Destructible();
    SaveRef* saved70 = field70;
    field70 = field70 ? field70->Resolve() : 0;
    SaveRef* saved74 = field74;
    field74 = field74 ? field74->Resolve() : 0;
    SaveRef* saved84 = field84;
    field84 = field84 ? field84->Resolve() : 0;
    SaveRef* savedVal = field88;
    field88 = field88 ? field88->Resolve() : 0;
    SaveRef* saved4 = field98;
    field98 = field98 ? field98->Resolve() : 0;
    SaveRef* saved9c5 = field9c;
    field9c = field9c ? field9c->Resolve() : 0;
    SaveRef* saveda7 = fielda0;
    fielda0 = fielda0 ? fielda0->Resolve() : 0;
    if (IsEndian())
        ((SaveComponent*)&field60)->Endian();
    WriteData(&field60, 0x54);
    if (IsEndian())
        ((SaveComponent*)&field60)->Endian();
    field70 = saved70;
    field74 = saved74;
    field84 = saved84;
    field88 = savedVal;
    field98 = saved4;
    field9c = saved9c5;
    fielda0 = saveda7;
    if (!((SaveComponent*)&fieldb4)->Length())
    {
        WriteChunk(0x314d414e, ((SaveModel*)&fieldb4)->Text(), ((SaveComponent*)&fieldb4)->Length() + 1);
    }
    else
    {
        ((SaveComponent*)&fieldb4)->Model(0x314d414e, 0x324d414e);
    }
    WriteValue(0x4d414e56, fieldcc);
    Finish();
}

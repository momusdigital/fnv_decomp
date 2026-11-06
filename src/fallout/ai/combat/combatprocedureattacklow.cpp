
// src/fallout/ai/combat/combatprocedureattacklow.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureattacklow.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct BGSSaveGameBuffer
{
    virtual ~BGSSaveGameBuffer();
};
struct BGSSaveFormBuffer : BGSSaveGameBuffer
{
    virtual ~BGSSaveFormBuffer();
    void SaveData(void* pData, int aSize, int aFlags);
    void SerializeFormData(void* pObj, int aFlags);
};
struct CombatProcedure
{
    virtual ~CombatProcedure();
    void SaveGame(BGSSaveFormBuffer* apBuffer);
};
struct TESObjectWEAP
{
    virtual ~TESObjectWEAP();
};
struct CombatProcedureAttackLow : CombatProcedure
{
    int m_10;
    int m_14;
    int m_18;
    TESObjectWEAP* pWeapon;
    void FUN_009cbfd0(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x009cbfd0
void CombatProcedureAttackLow::FUN_009cbfd0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    CombatProcedure::SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SaveData(reinterpret_cast<char*>(this) + 0x10, 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<char*>(this) + 0x14, 4, 0);
    apSaveGameBuffer->SaveData(reinterpret_cast<char*>(this) + 0x18, 4, 0);
    apSaveGameBuffer->SerializeFormData(*reinterpret_cast<TESObjectWEAP**>(reinterpret_cast<char*>(this) + 0x1c), 0);
}

struct FUN_009ca6c0_shell
{
    void FUN_009ca6c0();
};

void FUN_009ca6c0_shell::FUN_009ca6c0()
{}

extern int DAT_01090aec;

struct FUN_009cbb50_shell
{
    void FUN_009cbb50();
};

// @fnv 0x009cbb50
void FUN_009cbb50_shell::FUN_009cbb50()
{
    *(int*)this = (int)&DAT_01090aec;
    reinterpret_cast<FUN_009ca6c0_shell*>(this)->FUN_009ca6c0();
}

struct FUN_009cbb20_shell
{
    void FUN_009cbb50();
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls FUN_009cbb50, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x009cbb20
void* FUN_009cbb20_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_009cbb50();
    if (flags & 1)
        operator delete(this);
    return this;
}

struct FNStub
{
    char* GetFullName();
};

typedef int DEBUGTEXT_LOCATION;
typedef int DEBUGTEXT_JUSTIFY;

struct IDebugText
{
    virtual void FUN_009cbf10_0();
    virtual void FUN_009cbf10_1();
    virtual void FUN_009cbf10_2();
    virtual void FUN_009cbf10_3();
    virtual void FUN_009cbf10_4();
    virtual void DisplayText(DEBUGTEXT_LOCATION location, DEBUGTEXT_JUSTIFY justify, const char* text, ...);
};

extern const char $SG2706[];
extern const char str_01090a98[];
extern const char str_010676a0[];
extern const char str_01090b50[];

struct FUN_009cbf10_shell : CombatProcedureAttackLow
{
    void DisplayAttackDebugText(IDebugText* apDebugText, DEBUGTEXT_LOCATION aeLocation, DEBUGTEXT_JUSTIFY aeJustify);
};

// Displays debug text for the combat procedure's state at offset 0x10, showing weapon full name and a float value when the state is 1.
// @fnv 0x009cbf10
void FUN_009cbf10_shell::DisplayAttackDebugText(IDebugText* apDebugText, DEBUGTEXT_LOCATION aeLocation,
                                                DEBUGTEXT_JUSTIFY aeJustify)
{
    switch (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10))
    {
    case 0:
        apDebugText->DisplayText(aeLocation, aeJustify, $SG2706);
        break;

    case 1:
        apDebugText->DisplayText(aeLocation, aeJustify, str_01090a98);

        apDebugText->DisplayText(
            aeLocation, aeJustify, str_01090b50,
            *reinterpret_cast<TESObjectWEAP**>(reinterpret_cast<char*>(this) + 0x1c)
                ? reinterpret_cast<FNStub*>(reinterpret_cast<char*>(*reinterpret_cast<TESObjectWEAP**>(
                                                reinterpret_cast<char*>(this) + 0x1c)) +
                                            0x30)
                      ->GetFullName()
                : str_010676a0,
            *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x14));
        break;
    }
}

struct BGSLoadFormBuffer
{
    unsigned int ReadFormIdentifier();
    void ReadTypedData(void* pData, unsigned int size);
};

struct CombatProcedure_Helper
{
    void LoadGame(BGSLoadFormBuffer* apBuffer);
};

struct TESForm
{
    virtual ~TESForm();
};

extern void* _DAT_01183028;

TESForm* __cdecl _ref_004839c0(unsigned int formID);

struct FUN_009cc040_shell
{
    char padding[0x10];
    int m_10;
    int m_14;
    int m_18;
    TESObjectWEAP* pWeapon;

    void FUN_009cc040(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x009cc040
void FUN_009cc040_shell::FUN_009cc040(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<CombatProcedure_Helper*>(this)->LoadGame(apLoadGameBuffer);

    apLoadGameBuffer->ReadTypedData(&m_10, 4);
    apLoadGameBuffer->ReadTypedData(&m_14, 4);
    apLoadGameBuffer->ReadTypedData(&m_18, 4);

    pWeapon = dynamic_cast<TESObjectWEAP*>(_ref_004839c0(apLoadGameBuffer->ReadFormIdentifier()));
}

template <class T> class NiPointer
{
  public:
    operator T*() const;
    T* m_pObject;
};
class AnimIdle;

struct FUN_009b4d90
{
    FUN_009b4d90();
    char pad[0x64];
};

struct FUN_008c1c60 : NiPointer<AnimIdle>
{
    ~FUN_008c1c60();
};

struct FUN_008c1c30 : FUN_008c1c60
{
    FUN_008c1c30(FUN_009b4d90* apPackage);
};

struct FUN_004459e0
{
    ~FUN_004459e0();
    float FUN_004bcdb0(int aiFlag);
};

struct FUN_00525980_weap
{
    int FUN_00522c80();
    void* FUN_00525980(void* apActor);
};

struct FUN_00645d00_base
{
    int iDummy;
};

struct FUN_009cbb70_actorbase
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
    virtual void v095(void* apAmmo, int a2, int aiCount, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
    char pad[0xa4 - 4];
};

struct FUN_009cbb70_actor : FUN_009cbb70_actorbase, FUN_00645d00_base
{
    int FUN_00575ca0();
    FUN_004459e0* FUN_00576260(FUN_00525980_weap* apWeapon, int aiFlag);
    bool FUN_008a6650(int aiFlag);
    void FUN_0089a760(AnimIdle* apPackage, int aiFlag);
    bool FUN_008a8dd0(FUN_00525980_weap* apWeapon);
    int FUN_00575610(void* apAmmo);
};

struct FUN_0099a2d0_state
{
    FUN_00525980_weap* GetBestWeapon();
    float FUN_0097ac90(int aiType);
    void SetAttacker(bool abFlag);
    FUN_00525980_weap* FUN_0097c150(int aiType);
};

struct FUN_00586150_ctrl
{
    FUN_0099a2d0_state* FUN_00586150();
};

float& __fastcall FUN_00403e20(float* apSetting);
float RandomFloat(float afMin, float afMax);
void __cdecl FUN_009b5720(AnimIdle* apPackage, FUN_009cbb70_actor* apActor, FUN_009cbb70_actor* apTarget, float afTime);
float __cdecl FUN_00645d00(FUN_00645d00_base* apActor, FUN_00525980_weap* apWeapon, int aiFlag);
int FUN_00647b70(int a, int b);
int MinInt(int a, int b);
extern float DAT_011ce230;
extern float DAT_011cfbb4;
extern const char DAT_01090b30[];

struct FUN_009cbb70_shell
{
    virtual ~FUN_009cbb70_shell();
    FUN_00586150_ctrl* pController;
    char padCur[8];
    int iState;
    float fTime;
    float fTimeCur;
    FUN_00525980_weap* pWeapon;
    FUN_009cbb70_actor* FUN_00996de0();
    FUN_009cbb70_actor* FUN_00996e00();
    void FUN_009caac0(const char* apReason);
    void Update();
};

// @fnv 0x009cbb70
void FUN_009cbb70_shell::Update()
{
    FUN_009cbb70_actor* kActor = FUN_00996de0();
    FUN_009cbb70_actor* pTarget = FUN_00996e00();
    FUN_0099a2d0_state* pState2 = pController->FUN_00586150();
    if (!pTarget || pTarget->FUN_00575ca0() != kActor->FUN_00575ca0())
    {
        FUN_009caac0(DAT_01090b30);
        return;
    }

    if (iState == 0)
    {
        pWeapon = pState2->GetBestWeapon();
        int aIType = pWeapon ? pWeapon->FUN_00522c80() : 6;
        fTime = pState2->FUN_0097ac90(aIType);
        if (pWeapon)
        {
            FUN_004459e0* pItem = kActor->FUN_00576260(pWeapon, 0);
            if (!pItem)
            {
                pState2->SetAttacker(true);
                return;
            }
            fTimeCur = pItem->FUN_004bcdb0(1);
            delete pItem;
        }
        iState = 1;
    }

    int iType = pWeapon ? pWeapon->FUN_00522c80() : 6;
    if (pWeapon && pWeapon != pState2->FUN_0097c150(iType))
    {
        pState2->SetAttacker(true);
        iState = 0;
        return;
    }

    float fChance3 = pTarget->FUN_008a6650(0) ? FUN_00403e20(&DAT_011ce230) : FUN_00403e20(&DAT_011cfbb4);
    if (RandomFloat(0.0f, 1.0f) < fChance3)
    {
        FUN_008c1c30 spPackage(new FUN_009b4d90);
        FUN_009b5720(spPackage, kActor, pTarget, fTime);
        pTarget->FUN_0089a760(spPackage, 0);
    }

    if (pWeapon && pWeapon->FUN_00525980(kActor) && kActor->FUN_008a8dd0(pWeapon))
    {
        void* pAmmoA = pWeapon->FUN_00525980(kActor);
        int iCountCur = kActor->FUN_00575610(pAmmoA);
        int iClip = FUN_00645d00(kActor, pWeapon, 0);
        iClip = FUN_00647b70(iClip, 1);
        iClip = MinInt(iClip, iCountCur);
        kActor->v095(pAmmoA, 0, iClip, 0, 0, 0, 0, 0, 1, 0);
        if (iClip == iCountCur)
        {
            pState2->SetAttacker(true);
            iState = 0;
        }
    }
}

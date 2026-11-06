
// src/fallout/magic/lighteffect_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x0080ee50: the skeleton of src/fallout/magic/lighteffect.cpp
// with declarations corrected to what the original code does (unit: struct MagicTarget { Actor* FUN_00822b40(); }; -> struct MagicTarget;; unit: struct EffectSetting { TESObjectLIGH* GetLight(); }; -> struct EffectSetting { TESObjectLIGH* GetLight(); in; unit: virtual void vf20(); }; struct LightEffectStandIn : ActiveE -> virtual void vf20(); EffectSetting* Ge). Move the function to its real unit once
// that unit declares it this way.

// src/fallout/magic/lighteffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/lighteffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_0080ed20_shell
{
    float f0;
    float f1;
    float f2;
    FUN_0080ed20_shell* DivideByScalar(float divisor);
};
struct Actor
{
};
struct TESForm
{
    void Revert(Actor* apActor);
};
struct LightEffect : TESForm
{
    void FUN_0080f030(Actor* apActor);
    void FUN_0080ed60();
    float GetFloatAtOffset1C();
    void AttachLightEffect();
};
struct FUN_0080e6d0_shell
{
    void FUN_0080e6d0();
};
void* __cdecl Deallocate(void* p);
struct FUN_0080e6a0_shell : LightEffect
{
    void* DestroyLightEffect(unsigned int flags);
};
struct GO
{
    ~GO();
};
struct FUN_00803ed0
{
    char _pad[0x48];
    ~FUN_00803ed0();
};
struct FUN_0080e6d0
{
    FUN_00803ed0 _m0;
    GO _m1;
    ~FUN_0080e6d0();
};
struct Flt
{
    operator unsigned int();
};
struct NiLight;
struct ShadowSceneLight;
struct ShadowSceneNode
{
    ShadowSceneLight* GetShadowSceneLight(NiLight*, bool);
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* __cdecl GetShadowSceneNodeForIndex(int);
};
struct FUN_00b5b4a0_holder
{
    int __thiscall FUN_00b5b4a0(unsigned int);
};
struct FUN_0080e8a0_holder
{
    void Update(float afSecondsElapsed);
};
struct FUN_00805760_shell
{
    void FinishInitLoadGame(Actor*);
};
struct FUN_0080efd0_shell
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    void FinishInitLoadGame(Actor* apActor);
};
class BGSLoadFormBuffer;
struct EffectSetting;
struct ActiveEffect
{
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer*);
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    EffectSetting* GetEffectSetting();
    bool IsDone();
};
struct LightEffectStandIn : ActiveEffect
{
    void FUN_0080f000(BGSLoadFormBuffer* apLoadGameBuffer);
};
struct FUN_0080e610 : ActiveEffect
{
    char _pad[0x48];
    FUN_0080e610(void*, void*, void*);
};
struct FUN_0080e730_shell
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(ActiveEffect*);

    ActiveEffect* CreateActiveEffect();
};
struct CopiedState
{
    void FUN_006e5cc0(CopiedState* other);
};
struct FUN_0080e7e0_Class : ActiveEffect
{
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    CopiedState state48;
    void FUN_00804090(ActiveEffect* other);
    void CopyData(ActiveEffect* other);
};
struct Effect
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
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int field94;
};
struct Source
{
    Effect* FUN_00822b40();
};
struct Host
{
    Source* FUN_0059bb30();
    void Start();
};
void __cdecl FUN_0080ee50(int* value);
struct FUN_0080e900_inner
{
    void* FUN_00822b40();
};
struct FUN_0080e900_cls
{
    void FUN_0080ed60();
    FUN_0080e900_inner* FUN_0059bb30();
    void FUN_0080e900();
};
void __cdecl FUN_0080ee50(char* p);
extern int DAT_011dc304;
struct EdCallee
{
    void* FUN_0059bb30();
    void* FUN_00822b40();
    void* FUN_00559450();
    void* FUN_009611e0();
    void FUN_00b5eed0(void* apArg);
    void FUN_00572a50(int aiArg);
    void FUN_0066b0d0(int aiArg);
};
void* __cdecl FUN_00450b80(int aiArg);
typedef void(__thiscall* EdVirtual)(void* self, void* apArg);
struct NiPointLight;
class NiNode;
class PlayerCharacter;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* p = 0);
    ~NiPointer();
    NiPointer& operator=(T* p);
    operator T*() const;
    T* operator->() const;
    T* get() const;
};
struct FUN_004bc1f0_S
{
    void FUN_004bc1f0(float x, float y, float z);
};
struct NiPoint3_POD : FUN_0080ed20_shell
{
};
class NiPoint3 : public NiPoint3_POD
{
  public:
    NiPoint3();
    NiPoint3(float x, float y, float z);
};
class NiPointLight : public FUN_004bc1f0_S
{
  public:
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
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    static void* operator new(unsigned int size);
    static void operator delete(void* p);
    NiPointLight();
    void SetEffectColor(const NiPoint3&);
    void FUN_0050dd50(const NiPoint3&);
    void FUN_0050dd20(float);
};
class NiNode
{
  public:
    virtual void vf_00();
    virtual void vf_01();
    virtual void vf_02();
    virtual void vf_03();
    virtual void vf_04();
    virtual void vf_05();
    virtual void vf_06();
    virtual void vf_07();
    virtual void vf_08();
    virtual void vf_09();
    virtual void vf_0a();
    virtual void vf_0b();
    virtual void vf_0c();
    virtual void vf_0d();
    virtual void vf_0e();
    virtual void vf_0f();
    virtual void vf_10();
    virtual void vf_11();
    virtual void vf_12();
    virtual void vf_13();
    virtual void vf_14();
    virtual void vf_15();
    virtual void vf_16();
    virtual void vf_17();
    virtual void vf_18();
    virtual void vf_19();
    virtual void vf_1a();
    virtual void vf_1b();
    virtual void vf_1c();
    virtual void vf_1d();
    virtual void vf_1e();
    virtual void vf_1f();
    virtual void vf_20();
    virtual void vf_21();
    virtual void vf_22();
    virtual void vf_23();
    virtual void vf_24();
    virtual void vf_25();
    virtual void vf_26();
    virtual void vf_27();
    virtual void vf_28();
    virtual void vf_29();
    virtual void vf_2a();
    virtual void vf_2b();
    virtual void vf_2c();
    virtual void vf_2d();
    virtual void vf_2e();
    virtual void vf_2f();
    virtual void vf_30();
    virtual void vf_31();
    virtual void vf_32();
    virtual void vf_33();
    virtual void vf_34();
    virtual void vf_35();
    virtual void vf_36();
    virtual void AttachChildInAvailableSlot(NiPointLight*, bool);
};
struct ActorStandIn
{
    virtual void vf_00();
    virtual void vf_01();
    virtual void vf_02();
    virtual void vf_03();
    virtual void vf_04();
    virtual void vf_05();
    virtual void vf_06();
    virtual void vf_07();
    virtual void vf_08();
    virtual void vf_09();
    virtual void vf_0a();
    virtual void vf_0b();
    virtual void vf_0c();
    virtual void vf_0d();
    virtual void vf_0e();
    virtual void vf_0f();
    virtual void vf_10();
    virtual void vf_11();
    virtual void vf_12();
    virtual void vf_13();
    virtual void vf_14();
    virtual void vf_15();
    virtual void vf_16();
    virtual void vf_17();
    virtual void vf_18();
    virtual void vf_19();
    virtual void vf_1a();
    virtual void vf_1b();
    virtual void vf_1c();
    virtual void vf_1d();
    virtual void vf_1e();
    virtual void vf_1f();
    virtual void vf_20();
    virtual void vf_21();
    virtual void vf_22();
    virtual void vf_23();
    virtual void vf_24();
    virtual void vf_25();
    virtual void vf_26();
    virtual void vf_27();
    virtual void vf_28();
    virtual void vf_29();
    virtual void vf_2a();
    virtual void vf_2b();
    virtual void vf_2c();
    virtual void vf_2d();
    virtual void vf_2e();
    virtual void vf_2f();
    virtual void vf_30();
    virtual void vf_31();
    virtual void vf_32();
    virtual void vf_33();
    virtual void vf_34();
    virtual void vf_35();
    virtual void vf_36();
    virtual void vf_37();
    virtual void vf_38();
    virtual void vf_39();
    virtual void vf_3a();
    virtual void vf_3b();
    virtual void vf_3c();
    virtual void vf_3d();
    virtual void vf_3e();
    virtual void vf_3f();
    virtual void vf_40();
    virtual void vf_41();
    virtual void vf_42();
    virtual void vf_43();
    virtual void vf_44();
    virtual void vf_45();
    virtual void vf_46();
    virtual void vf_47();
    virtual void vf_48();
    virtual void vf_49();
    virtual void vf_4a();
    virtual void vf_4b();
    virtual void vf_4c();
    virtual void vf_4d();
    virtual void vf_4e();
    virtual void vf_4f();
    virtual void vf_50();
    virtual void vf_51();
    virtual void vf_52();
    virtual void vf_53();
    virtual void vf_54();
    virtual void vf_55();
    virtual void vf_56();
    virtual void vf_57();
    virtual void vf_58();
    virtual void vf_59();
    virtual void vf_5a();
    virtual void vf_5b();
    virtual void vf_5c();
    virtual void vf_5d();
    virtual void vf_5e();
    virtual void vf_5f();
    virtual void vf_60();
    virtual void vf_61();
    virtual void vf_62();
    virtual void vf_63();
    virtual void vf_64();
    virtual void vf_65();
    virtual void vf_66();
    virtual void vf_67();
    virtual void vf_68();
    virtual void vf_69();
    virtual void vf_6a();
    virtual void vf_6b();
    virtual void vf_6c();
    virtual void vf_6d();
    virtual void vf_6e();
    virtual void vf_6f();
    virtual void vf_70();
    virtual void vf_71();
    virtual void vf_72();
    virtual void vf_73();
    virtual NiNode* Get3D();
    virtual void vf_1d4();
    virtual void vf_1d8();
    virtual NiPoint3 GetPos();
};
struct ActorV_S
{
    float GetScale();
    float GetActorHeight() const;
};
struct ActorCalls
{
    int FUN_00572750();
    void FUN_00572770(NiPointLight*);
};
class PlayerCharacter
{
  public:
    NiNode* GetNode(bool);
};
extern PlayerCharacter* _g_thePlayer;
class GlobalObject2_0040c150
{
  public:
    int* Int();
};
extern GlobalObject2_0040c150 g_011d1d18;
class GlobalObject_0040e0b0
{
  public:
    float* Float();
};
extern GlobalObject_0040e0b0 g_011d1980;
extern GlobalObject_0040e0b0 g_011d1a30;
union SETTING_VALUE
{
    float f;
};
class GameSettingCollection
{
};
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1112;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1166;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1167;
void FNV_Warning(const char* fmt, ...);
class TESObjectLIGH
{
};
struct FUN_005e3fc0_shell
{
    unsigned int Get();
};
struct PathingRequest
{
    float GetFieldB4Float();
};
struct EffectSetting
{
    TESObjectLIGH* GetLight();
    int GetArchetype();
};
struct FUN_0082ccb0_Cls
{
    EffectSetting* GetEffectSetting();
};
struct MagicTarget;
struct LightEffectDerived : ActiveEffect
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    NiPointer<NiPointLight> m_spLight;  // offset 0x48

    MagicTarget* FUN_0059bb30();
    float GetFloatAtOffset1C();

    void AttachLightEffect();
};

template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    bool IsEmpty();
    T& GetItem();
    BSSimpleList* GetNext();
};
class TESObjectREFR;
class MagicTarget
{
  public:
    virtual ~MagicTarget();
    virtual TESObjectREFR* GetMagicTargetReference();
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
};
// @fnv 0x0080ee50
void FUN_0080ee50(MagicTarget* target)
{
    if (!target)
        return;
    LightEffect* strongest = 0;
    BSSimpleList<ActiveEffect*>* node = target->GetActiveEffectList();
    while (node && !node->IsEmpty())
    {
        ActiveEffect* effect = node->GetItem();
        if (effect && effect->GetEffectSetting()->GetArchetype() == 13 && !effect->IsDone())
        {
            LightEffect* light = dynamic_cast<LightEffect*>(effect);
            if (!strongest || strongest->GetFloatAtOffset1C() < light->GetFloatAtOffset1C())
            {
                if (strongest)
                    strongest->FUN_0080ed60();
                strongest = light;
            }
            else
            {
                light->FUN_0080ed60();
            }
        }
        node = node->GetNext();
    }
    if (strongest)
        strongest->AttachLightEffect();
}
